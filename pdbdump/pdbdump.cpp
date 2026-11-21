// pdbdump.cpp - dump a PDB's functions, params, locals, UDTs, fields, vfuncs, enums, globals and publics
// to UTF-8 TSV files using DIA (msdia140.dll loaded without registration).
//
// usage: pdbdump <file.pdb> <outdir> [image.exe]
//
// C++ only because DIA is COM; the code is kept C-style. Output is streamed per symbol; only the
// publics RVA->name index, the UDT/enum dedupe sets and a type-string cache are held in memory.

#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <dbghelp.h>
#include "dia2.h"
#include "diacreate.h"
extern "C" {
#include "peinfo.h"
}

#ifndef DIA_DLL
#define DIA_DLL L"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\DIA SDK\\bin\\amd64\\msdia140.dll"
#endif

static IDiaSession *g_sess;
static IDiaSymbol *g_global;

// ---------------------------------------------------------------- strings

static std::string w2u(const wchar_t *w)
{
    std::string s;
    if (!w || !*w) return s;
    int n = WideCharToMultiByte(CP_UTF8, 0, w, -1, NULL, 0, NULL, NULL);
    if (n <= 1) return s;
    s.resize(n - 1);
    WideCharToMultiByte(CP_UTF8, 0, w, -1, &s[0], n, NULL, NULL);
    for (size_t i = 0; i < s.size(); i++)
        if (s[i] == '\t' || s[i] == '\n' || s[i] == '\r') s[i] = ' ';
    return s;
}

static std::string take(BSTR b)
{
    std::string s = w2u(b);
    if (b) SysFreeString(b);
    return s;
}

static std::string sym_name(IDiaSymbol *s)
{
    BSTR b = NULL;
    if (!s || s->get_name(&b) != S_OK) return std::string();
    return take(b);
}

static std::string basename_of(const std::string &p)
{
    size_t k = p.find_last_of("\\/");
    return k == std::string::npos ? p : p.substr(k + 1);
}

static void rel(IDiaSymbol *s) { if (s) s->Release(); }

// Iterate children of `parent` with `tag`, calling f(IDiaSymbol*). Symbols are released after f.
template <class F> static void each_child(IDiaSymbol *parent, enum SymTagEnum tag, F f)
{
    IDiaEnumSymbols *e = NULL;
    if (!parent || parent->findChildren(tag, NULL, nsNone, &e) != S_OK || !e) return;
    // Bound the walk by get_Count: some DIA enumerators wrap around to the start after the last
    // partial batch instead of returning 0.
    IDiaSymbol *arr[512];
    LONG total = 0, done = 0;
    if (e->get_Count(&total) != S_OK) total = 0x7fffffff;
    while (done < total) {
        ULONG got = 0, want = (ULONG)min(512L, total - done);
        HRESULT hr = e->Next(want, arr, &got);
        if (FAILED(hr) || got == 0) break;
        for (ULONG i = 0; i < got; i++) { f(arr[i]); arr[i]->Release(); }
        done += (LONG)got;
        if (hr != S_OK) break;
    }
    e->Release();
}

static FILE *open_out(const char *dir, const char *name, const char *header)
{
    char path[MAX_PATH];
    _snprintf(path, sizeof path, "%s\\%s", dir, name);
    FILE *f = fopen(path, "wb");
    if (!f) { fprintf(stderr, "cannot write %s\n", path); exit(1); }
    setvbuf(f, NULL, _IOFBF, 1 << 20);
    fputs(header, f);
    fputc('\n', f);
    return f;
}

// ---------------------------------------------------------------- type strings

static std::unordered_map<DWORD, std::string> g_tcache;
static std::string type_str(IDiaSymbol *t, int depth);

static const char *cc_name(DWORD cc)
{
    switch (cc) {
    case CV_CALL_NEAR_C: return "__cdecl";
    case CV_CALL_NEAR_FAST: return "__fastcall";
    case CV_CALL_NEAR_STD: return "__stdcall";
    case CV_CALL_NEAR_SYS: return "__syscall";
    case CV_CALL_THISCALL: return "__thiscall";
    case CV_CALL_PPCCALL: return "__ppccall";
    case CV_CALL_CLRCALL: return "__clrcall";
    case CV_CALL_NEAR_VECTOR: return "__vectorcall";
    case CV_CALL_INLINE: return "__inline";
    default: return "__cc?";
    }
}

static std::string base_type_str(DWORD bt, ULONGLONG len)
{
    switch (bt) {
    case btNoType: return "<notype>";
    case btVoid: return "void";
    case btChar: return "char";
    case btWChar: return "wchar_t";
    case btInt:
        return len == 1 ? "signed char" : len == 2 ? "short" : len == 8 ? "__int64" : len == 16 ? "__int128" : "int";
    case btUInt:
        return len == 1 ? "unsigned char" : len == 2 ? "unsigned short" : len == 8 ? "unsigned __int64"
             : len == 16 ? "unsigned __int128" : "unsigned int";
    case btFloat: return len == 4 ? "float" : len == 8 ? "double" : len == 2 ? "half" : "long double";
    case btBCD: return "BCD";
    case btBool: return "bool";
    case btLong: return "long";
    case btULong: return "unsigned long";
    case btCurrency: return "CURRENCY";
    case btDate: return "DATE";
    case btVariant: return "VARIANT";
    case btComplex: return "complex";
    case btBit: return "bit";
    case btBSTR: return "BSTR";
    case btHresult: return "HRESULT";
    case btChar16: return "char16_t";
    case btChar32: return "char32_t";
    case btChar8: return "char8_t";
    default: { char b[32]; sprintf(b, "<bt%u:%u>", (unsigned)bt, (unsigned)len); return b; }
    }
}

static std::string cv_prefix(IDiaSymbol *t)
{
    BOOL c = FALSE, v = FALSE;
    t->get_constType(&c);
    t->get_volatileType(&v);
    std::string s;
    if (c) s += "const ";
    if (v) s += "volatile ";
    return s;
}

// Argument list "(a, b)" of a function type.
static std::string func_args(IDiaSymbol *ft, int depth)
{
    std::string a = "(";
    int n = 0;
    each_child(ft, SymTagFunctionArgType, [&](IDiaSymbol *arg) {
        IDiaSymbol *at = NULL;
        arg->get_type(&at);
        if (n++) a += ", ";
        a += type_str(at, depth + 1);
        rel(at);
    });
    a += ")";
    return a;
}

static bool func_is_const(IDiaSymbol *ft)
{
    IDiaSymbol *op = NULL, *pt = NULL;
    BOOL c = FALSE;
    if (ft->get_objectPointerType(&op) == S_OK && op) {
        if (op->get_type(&pt) == S_OK && pt) pt->get_constType(&c);
    }
    rel(pt); rel(op);
    return c != FALSE;
}

// "ret cc (args)" or, with ptrop, "ret (cc *)(args)".
static std::string func_type_str(IDiaSymbol *ft, const char *ptrop, int depth)
{
    IDiaSymbol *r = NULL;
    DWORD cc = 0;
    ft->get_type(&r);
    ft->get_callingConvention(&cc);
    std::string ret = r ? type_str(r, depth + 1) : "?";
    rel(r);
    std::string s;
    if (ptrop) s = ret + " (" + cc_name(cc) + ptrop + ")" + func_args(ft, depth);
    else s = ret + " " + cc_name(cc) + func_args(ft, depth);
    if (func_is_const(ft)) s += " const";
    return s;
}

static std::string type_str(IDiaSymbol *t, int depth)
{
    if (!t) return std::string();
    if (depth > 24) return "...";
    DWORD id = 0, tag = 0;
    t->get_symIndexId(&id);
    std::unordered_map<DWORD, std::string>::iterator it = g_tcache.find(id);
    if (it != g_tcache.end()) return it->second;
    t->get_symTag(&tag);
    std::string s;
    switch (tag) {
    case SymTagBaseType: {
        DWORD bt = 0; ULONGLONG len = 0;
        t->get_baseType(&bt); t->get_length(&len);
        s = cv_prefix(t) + base_type_str(bt, len);
        break;
    }
    case SymTagUDT: case SymTagEnum: case SymTagTypedef:
        s = cv_prefix(t) + sym_name(t);
        break;
    case SymTagPointerType: {
        IDiaSymbol *p = NULL;
        BOOL ref = FALSE, rref = FALSE, c = FALSE, v = FALSE;
        DWORD ptag = 0;
        t->get_type(&p);
        t->get_reference(&ref);
        t->get_RValueReference(&rref);
        t->get_constType(&c);
        t->get_volatileType(&v);
        const char *op = rref ? "&&" : ref ? "&" : "*";
        if (p) p->get_symTag(&ptag);
        if (ptag == SymTagFunctionType) s = func_type_str(p, op, depth + 1);
        else s = type_str(p, depth + 1) + op;
        if (c) s += " const";
        if (v) s += " volatile";
        rel(p);
        break;
    }
    case SymTagArrayType: {
        IDiaSymbol *e = NULL;
        DWORD cnt = 0, etag = 0;
        t->get_type(&e);
        t->get_count(&cnt);
        if (e) e->get_symTag(&etag);
        std::string es = type_str(e, depth + 1);
        char dim[32];
        sprintf(dim, "[%u]", (unsigned)cnt);
        size_t k = etag == SymTagArrayType ? es.find('[') : std::string::npos;
        if (k != std::string::npos) es.insert(k, dim); else es += dim;
        s = es;
        rel(e);
        break;
    }
    case SymTagFunctionType:
        s = func_type_str(t, NULL, depth + 1);
        break;
    case SymTagFunctionArgType: {
        IDiaSymbol *a = NULL;
        t->get_type(&a);
        s = type_str(a, depth + 1);
        rel(a);
        break;
    }
    case SymTagVTableShape: s = "<vtshape>"; break;
    case SymTagVTable: s = "<vtable>"; break;
    default: {
        s = sym_name(t);
        if (s.empty()) { char b[32]; sprintf(b, "<tag%u>", (unsigned)tag); s = b; }
    }
    }
    g_tcache[id] = s;
    return s;
}

static std::string sym_type_str(IDiaSymbol *s)
{
    IDiaSymbol *t = NULL;
    if (s->get_type(&t) != S_OK || !t) return std::string();
    std::string r = type_str(t, 0);
    t->Release();
    return r;
}

// ---------------------------------------------------------------- virtual slot resolution
//
// CodeView stores a vtable offset only on the method that introduces a slot (MTintro). An override
// reports 0, so its slot is found by walking the base classes for the introducing method with the
// same name (any destructor for a destructor) and, preferably, the same signature.

static bool vto_search(IDiaSymbol *udt, const std::string &name, const std::string *sig, DWORD *vto,
                       std::string *intro, int depth)
{
    if (depth > 16) return false;
    bool found = false, dtor = !name.empty() && name[0] == '~';
    each_child(udt, SymTagFunction, [&](IDiaSymbol *m) {
        if (found) return;
        BOOL virt = FALSE, in = FALSE;
        m->get_virtual(&virt);
        if (!virt) return;
        std::string n = sym_name(m);
        if (dtor ? (n.empty() || n[0] != '~') : n != name) return;
        m->get_intro(&in);
        if (!in) return;
        if (sig && !dtor && sym_type_str(m) != *sig) return;
        m->get_virtualBaseOffset(vto);
        *intro = sym_name(udt);
        found = true;
    });
    if (found) return true;
    each_child(udt, SymTagBaseClass, [&](IDiaSymbol *b) {
        if (found) return;
        IDiaSymbol *bt = NULL;
        if (b->get_type(&bt) == S_OK && bt) {
            found = vto_search(bt, name, sig, vto, intro, depth + 1);
            bt->Release();
        }
    });
    return found;
}

struct VSlot { DWORD vto; std::string intro; };
static std::unordered_map<std::string, VSlot> g_vcache;

// For a virtual method `m` of class `cls`: slot offset and the class that introduced the slot.
static DWORD virtual_slot(IDiaSymbol *m, IDiaSymbol *cls, std::string *intro)
{
    BOOL in = FALSE;
    DWORD vto = 0;
    m->get_intro(&in);
    if (in || !cls) {
        m->get_virtualBaseOffset(&vto);
        *intro = in ? sym_name(cls) : std::string();
        return vto;
    }
    std::string name = sym_name(m), sig = sym_type_str(m), cname = sym_name(cls);
    std::string key = cname + "::" + name + "|" + sig;
    std::unordered_map<std::string, VSlot>::iterator it = g_vcache.find(key);
    if (it != g_vcache.end()) { *intro = it->second.intro; return it->second.vto; }
    VSlot s;
    s.vto = 0;
    bool ok = false;
    each_child(cls, SymTagBaseClass, [&](IDiaSymbol *b) {
        IDiaSymbol *bt = NULL;
        if (ok || b->get_type(&bt) != S_OK || !bt) return;
        ok = vto_search(bt, name, &sig, &s.vto, &s.intro, 0);
        bt->Release();
    });
    if (!ok) {
        each_child(cls, SymTagBaseClass, [&](IDiaSymbol *b) {
            IDiaSymbol *bt = NULL;
            if (ok || b->get_type(&bt) != S_OK || !bt) return;
            ok = vto_search(bt, name, NULL, &s.vto, &s.intro, 0);
            bt->Release();
        });
    }
    if (!ok) { s.vto = 0; s.intro = "?"; }
    g_vcache[key] = s;
    *intro = s.intro;
    return s.vto;
}

// ---------------------------------------------------------------- publics index

struct PubRec { DWORD rva; std::string name; };
static std::vector<PubRec> g_pubs;  // sorted by rva, first name per rva kept

// The public whose undecorated name equals `name` among the publics at `rva` (identical-COMDAT
// folding puts several functions at one RVA); the only public there if none matches by name.
static const char *pub_at(DWORD rva, const std::string &name)
{
    size_t lo = 0, hi = g_pubs.size();
    while (lo < hi) {
        size_t mid = (lo + hi) / 2;
        if (g_pubs[mid].rva < rva) lo = mid + 1; else hi = mid;
    }
    size_t first = lo, n = 0;
    char und[4096];
    for (; lo < g_pubs.size() && g_pubs[lo].rva == rva; lo++, n++) {
        const std::string &d = g_pubs[lo].name;
        if (d == name || (d.size() == name.size() + 1 && d[0] == '_' && d.compare(1, std::string::npos, name) == 0))
            return d.c_str();
        if (d[0] == '?' && UnDecorateSymbolName(d.c_str(), und, sizeof und, UNDNAME_NAME_ONLY) && name == und)
            return d.c_str();
    }
    if (n == 1) return g_pubs[first].name.c_str();
    return "";
}

static size_t dump_publics(const char *dir)
{
    FILE *f = open_out(dir, "publics.tsv", "rva\tdecorated\tundecorated\tis_function");
    size_t n = 0;
    each_child(g_global, SymTagPublicSymbol, [&](IDiaSymbol *s) {
        DWORD rva = 0;
        BOOL fn = FALSE;
        BSTR und = NULL;
        s->get_relativeVirtualAddress(&rva);
        s->get_function(&fn);
        std::string name = sym_name(s);
        std::string u;
        if (s->get_undecoratedName(&und) == S_OK) u = take(und);
        fprintf(f, "0x%X\t%s\t%s\t%d\n", (unsigned)rva, name.c_str(), u.c_str(), fn ? 1 : 0);
        PubRec r; r.rva = rva; r.name = name;
        g_pubs.push_back(r);
        n++;
    });
    fclose(f);
    std::stable_sort(g_pubs.begin(), g_pubs.end(), [](const PubRec &a, const PubRec &b) { return a.rva < b.rva; });
    return n;
}

// ---------------------------------------------------------------- globals

static const char *data_kind_name(DWORD k)
{
    switch (k) {
    case DataIsLocal: return "local";
    case DataIsStaticLocal: return "static_local";
    case DataIsParam: return "param";
    case DataIsObjectPtr: return "this";
    case DataIsFileStatic: return "file_static";
    case DataIsGlobal: return "global";
    case DataIsMember: return "member";
    case DataIsStaticMember: return "static_member";
    case DataIsConstant: return "constant";
    default: return "unknown";
    }
}

static size_t dump_globals(const char *dir)
{
    FILE *f = open_out(dir, "globals.tsv", "rva\tname\ttype\tdecorated\tkind");
    size_t n = 0;
    each_child(g_global, SymTagData, [&](IDiaSymbol *s) {
        DWORD rva = 0, loc = 0, kind = 0;
        s->get_locationType(&loc);
        s->get_dataKind(&kind);
        if (loc != LocIsStatic && loc != LocIsTLS) return;
        s->get_relativeVirtualAddress(&rva);
        std::string name = sym_name(s), type = sym_type_str(s);
        fprintf(f, "0x%X\t%s\t%s\t%s\t%s\n", (unsigned)rva, name.c_str(), type.c_str(), pub_at(rva, name), data_kind_name(kind));
        n++;
    });
    fclose(f);
    return n;
}

// ---------------------------------------------------------------- functions, params, locals

struct Counts { size_t funcs, params, locals; };

static void walk_locals(IDiaSymbol *scope, DWORD frva, const std::string &fname, FILE *fl, Counts *c, int depth)
{
    each_child(scope, SymTagNull, [&](IDiaSymbol *s) {
        DWORD tag = 0;
        s->get_symTag(&tag);
        if (tag == SymTagBlock) { walk_locals(s, frva, fname, fl, c, depth + 1); return; }
        if (tag != SymTagData) return;
        DWORD kind = 0;
        s->get_dataKind(&kind);
        if (kind != DataIsLocal && kind != DataIsStaticLocal) return;
        std::string name = sym_name(s), type = sym_type_str(s);
        fprintf(fl, "0x%X\t%s\t%s\t%s\t%d\t%s\n", (unsigned)frva, name.c_str(), type.c_str(),
                kind == DataIsStaticLocal ? "static" : "local", depth, fname.c_str());
        c->locals++;
    });
}

static void dump_function(IDiaSymbol *fn, DWORD cuid, const std::string &objpath, const std::string &lib,
                          FILE *ff, FILE *fp, FILE *fl, Counts *c)
{
    DWORD rva = 0, vto = 0;
    ULONGLONG len = 0;
    BOOL virt = FALSE;
    fn->get_relativeVirtualAddress(&rva);
    fn->get_length(&len);
    fn->get_virtual(&virt);
    std::string name = sym_name(fn);

    std::string cls, intro;
    IDiaSymbol *cp = NULL;
    if (fn->get_classParent(&cp) != S_OK) cp = NULL;
    if (cp) cls = sym_name(cp);
    if (virt) vto = virtual_slot(fn, cp, &intro);
    rel(cp);

    std::string src;
    DWORD line = 0;
    // First line record of this function's own compiland: under identical-COMDAT folding the code
    // at `rva` may belong to another module's function, whose lines must not be reported here.
    IDiaEnumLineNumbers *el = NULL;
    if (len && g_sess->findLinesByRVA(rva, (DWORD)len, &el) == S_OK && el) {
        IDiaLineNumber *ln = NULL;
        ULONG got = 0;
        while (el->Next(1, &ln, &got) == S_OK && got == 1) {
            DWORD cid = 0;
            ln->get_compilandId(&cid);
            if (cid != cuid) { ln->Release(); continue; }
            IDiaSourceFile *sf = NULL;
            ln->get_lineNumber(&line);
            if (ln->get_sourceFile(&sf) == S_OK && sf) {
                BSTR b = NULL;
                if (sf->get_fileName(&b) == S_OK) src = take(b);
                sf->Release();
            }
            ln->Release();
            break;
        }
        el->Release();
    }

    std::string sig = sym_type_str(fn);
    char vbuf[24] = "";
    if (virt) sprintf(vbuf, "0x%X", (unsigned)vto);
    fprintf(ff, "0x%X\t0x%llX\t%s\t%s\t%s\t%s\t%u\t%d\t%s\t%s\t%s\t%s\t%s\t%s\n", (unsigned)rva, len, name.c_str(),
            pub_at(rva, name), basename_of(objpath).c_str(), src.c_str(), (unsigned)line, virt ? 1 : 0, vbuf, cls.c_str(),
            sig.c_str(), objpath.c_str(), lib.c_str(), intro.c_str());
    c->funcs++;

    int idx = 0;
    each_child(fn, SymTagData, [&](IDiaSymbol *s) {
        DWORD kind = 0;
        s->get_dataKind(&kind);
        if (kind != DataIsParam) return;
        std::string pn = sym_name(s);
        if (pn == "this") return;
        std::string pt = sym_type_str(s);
        fprintf(fp, "0x%X\t%d\t%s\t%s\t%s\n", (unsigned)rva, idx++, pn.c_str(), pt.c_str(), name.c_str());
        c->params++;
    });
    walk_locals(fn, rva, name, fl, c, 0);
}

static Counts dump_functions(const char *dir, size_t *ncomp)
{
    FILE *ff = open_out(dir, "functions.tsv",
                        "rva\tsize\tname\tdecorated\tobject\tsource_file\tfirst_line\tis_virtual\tvtable_offset\tclass\tsignature\tobject_path\tlib\tvtable_intro");
    FILE *fp = open_out(dir, "params.tsv", "function_rva\tindex\tname\ttype\tfunction");
    FILE *fl = open_out(dir, "locals.tsv", "function_rva\tname\ttype\tkind\tblock_depth\tfunction");
    Counts c = { 0, 0, 0 };
    *ncomp = 0;
    each_child(g_global, SymTagCompiland, [&](IDiaSymbol *cu) {
        std::string objpath = sym_name(cu), lib;
        BSTR b = NULL;
        if (cu->get_libraryName(&b) == S_OK) lib = take(b);
        DWORD cuid = 0;
        cu->get_symIndexId(&cuid);
        (*ncomp)++;
        each_child(cu, SymTagFunction, [&](IDiaSymbol *fn) { dump_function(fn, cuid, objpath, lib, ff, fp, fl, &c); });
    });
    fclose(ff); fclose(fp); fclose(fl);
    return c;
}

// ---------------------------------------------------------------- UDTs, fields, vfuncs, enums

struct UdtCounts { size_t udts, fields, vfuncs, enums, enumvals; };

static const char *udt_kind_name(DWORD k)
{
    switch (k) { case UdtStruct: return "struct"; case UdtClass: return "class"; case UdtUnion: return "union";
    case UdtInterface: return "interface"; default: return "udt?"; }
}

static UdtCounts dump_udts(const char *dir)
{
    FILE *fu = open_out(dir, "udts.tsv", "name\tkind\tsize\tbases\thas_vtable\tnfields");
    FILE *fd = open_out(dir, "fields.tsv", "udt\toffset\tname\ttype\tbit_position\tbit_length\tis_static");
    FILE *fv = open_out(dir, "vfuncs.tsv", "udt\tvtable_offset\tfunction\tsignature\tis_pure\tis_intro\tvtable_intro");
    FILE *fe = open_out(dir, "enums.tsv", "enum\tname\tvalue");
    UdtCounts c = { 0, 0, 0, 0, 0 };
    std::unordered_set<std::string> seen;

    each_child(g_global, SymTagUDT, [&](IDiaSymbol *u) {
        std::string name = sym_name(u);
        ULONGLONG size = 0;
        DWORD kind = 0;
        u->get_length(&size);
        u->get_udtKind(&kind);
        char key[32];
        sprintf(key, "|%llu", size);
        if (!seen.insert(name + key).second) return;

        std::string bases;
        bool vt = false;
        int nfields = 0;
        std::string fieldrows, vfrows;
        each_child(u, SymTagNull, [&](IDiaSymbol *m) {
            DWORD tag = 0;
            m->get_symTag(&tag);
            if (tag == SymTagBaseClass) {
                BOOL vb = FALSE;
                LONG off = 0;
                char b[48];
                m->get_virtualBaseClass(&vb);
                m->get_offset(&off);
                if (!bases.empty()) bases += ";";
                if (vb) bases += sym_name(m) + "@virtual";
                else { sprintf(b, "@0x%X", (unsigned)off); bases += sym_name(m) + b; }
            } else if (tag == SymTagVTable) {
                vt = true;
            } else if (tag == SymTagData) {
                DWORD dk = 0, loc = 0, bitpos = 0;
                LONG off = 0;
                ULONGLONG blen = 0;
                m->get_dataKind(&dk);
                m->get_locationType(&loc);
                bool st = dk == DataIsStaticMember || dk == DataIsGlobal;
                std::string fname = sym_name(m), ftype = sym_type_str(m);
                char offs[24] = "", bits[48] = "\t";
                if (!st) {
                    m->get_offset(&off);
                    sprintf(offs, "0x%X", (unsigned)off);
                    if (loc == LocIsBitField) {
                        m->get_bitPosition(&bitpos);
                        m->get_length(&blen);
                        sprintf(bits, "%u\t%llu", (unsigned)bitpos, blen);
                    }
                    nfields++;
                }
                // udt, offset, name, type, bit_position, bit_length, is_static
                fieldrows += name + "\t" + offs + "\t" + fname + "\t" + ftype + "\t" + bits + "\t" + (st ? "1" : "0") + "\n";
                c.fields++;
            } else if (tag == SymTagFunction) {
                BOOL virt = FALSE, pure = FALSE, in = FALSE;
                m->get_virtual(&virt);
                if (!virt) return;
                m->get_pure(&pure);
                m->get_intro(&in);
                std::string intro;
                DWORD vto = virtual_slot(m, u, &intro);
                vt = true;
                char b[24];
                sprintf(b, "\t0x%X\t", (unsigned)vto);
                vfrows += name + b + sym_name(m) + "\t" + sym_type_str(m) + "\t" + (pure ? "1" : "0") + "\t" +
                          (in ? "1" : "0") + "\t" + intro + "\n";
                c.vfuncs++;
            }
        });
        fprintf(fu, "%s\t%s\t%llu\t%s\t%d\t%d\n", name.c_str(), udt_kind_name(kind), size, bases.c_str(), vt ? 1 : 0, nfields);
        fputs(fieldrows.c_str(), fd);
        fputs(vfrows.c_str(), fv);
        c.udts++;
    });

    std::unordered_set<std::string> eseen;
    each_child(g_global, SymTagEnum, [&](IDiaSymbol *e) {
        std::string name = sym_name(e);
        if (!eseen.insert(name).second) return;
        c.enums++;
        each_child(e, SymTagData, [&](IDiaSymbol *m) {
            VARIANT v;
            VariantInit(&v);
            long long val = 0;
            if (m->get_value(&v) == S_OK) {
                switch (v.vt) {
                case VT_I1: val = v.cVal; break; case VT_UI1: val = v.bVal; break;
                case VT_I2: val = v.iVal; break; case VT_UI2: val = v.uiVal; break;
                case VT_I4: val = v.lVal; break; case VT_UI4: val = v.ulVal; break;
                case VT_INT: val = v.intVal; break; case VT_UINT: val = v.uintVal; break;
                case VT_I8: val = v.llVal; break; case VT_UI8: val = (long long)v.ullVal; break;
                default: break;
                }
            }
            VariantClear(&v);
            fprintf(fe, "%s\t%s\t%lld\n", name.c_str(), sym_name(m).c_str(), val);
            c.enumvals++;
        });
    });
    fclose(fu); fclose(fd); fclose(fv); fclose(fe);
    return c;
}

// ---------------------------------------------------------------- main

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "usage: pdbdump <file.pdb> <outdir> [image.exe]\n");
        return 2;
    }
    const char *pdb = argv[1], *dir = argv[2];
    CreateDirectoryA(dir, NULL);

    CoInitialize(NULL);
    IDiaDataSource *src = NULL;
    HRESULT hr = NoRegCoCreate(DIA_DLL, __uuidof(DiaSource), __uuidof(IDiaDataSource), (void **)&src);
    if (FAILED(hr)) { fprintf(stderr, "NoRegCoCreate(msdia140) failed: 0x%08X\n", (unsigned)hr); return 1; }
    wchar_t wpdb[MAX_PATH];
    MultiByteToWideChar(CP_UTF8, 0, pdb, -1, wpdb, MAX_PATH);
    hr = src->loadDataFromPdb(wpdb);
    if (FAILED(hr)) { fprintf(stderr, "loadDataFromPdb(%s) failed: 0x%08X\n", pdb, (unsigned)hr); return 1; }
    hr = src->openSession(&g_sess);
    if (FAILED(hr)) { fprintf(stderr, "openSession failed: 0x%08X\n", (unsigned)hr); return 1; }
    g_sess->get_globalScope(&g_global);

    // image.txt: PDB identity, then the PE header of the matching image
    {
        char path[MAX_PATH];
        _snprintf(path, sizeof path, "%s\\image.txt", dir);
        FILE *f = fopen(path, "wb");
        GUID g;
        DWORD age = 0, sig = 0, mach = 0;
        memset(&g, 0, sizeof g);
        g_global->get_guid(&g);
        g_global->get_age(&age);
        g_global->get_signature(&sig);
        g_global->get_machineType(&mach);
        fprintf(f, "pdb: %s\n", pdb);
        fprintf(f, "pdb_guid: {%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}\n", (unsigned)g.Data1, g.Data2, g.Data3,
                g.Data4[0], g.Data4[1], g.Data4[2], g.Data4[3], g.Data4[4], g.Data4[5], g.Data4[6], g.Data4[7]);
        fprintf(f, "pdb_age: %u\n", (unsigned)age);
        fprintf(f, "pdb_signature: 0x%08X\n", (unsigned)sig);
        fprintf(f, "pdb_machine: 0x%04X %s\n", (unsigned)mach, pe_machine_name(mach));
        if (argc > 3) pe_write_info(f, argv[3]);
        fclose(f);
    }

    size_t npub = dump_publics(dir);
    printf("publics.tsv   %zu\n", npub); fflush(stdout);
    size_t nglob = dump_globals(dir);
    printf("globals.tsv   %zu\n", nglob); fflush(stdout);
    size_t ncomp = 0;
    Counts c = dump_functions(dir, &ncomp);
    printf("compilands    %zu\nfunctions.tsv %zu\nparams.tsv    %zu\nlocals.tsv    %zu\n", ncomp, c.funcs, c.params, c.locals);
    fflush(stdout);
    UdtCounts u = dump_udts(dir);
    printf("udts.tsv      %zu\nfields.tsv    %zu\nvfuncs.tsv    %zu\nenums.tsv     %zu (%zu enums)\n", u.udts, u.fields, u.vfuncs,
           u.enumvals, u.enums);

    g_global->Release();
    g_sess->Release();
    src->Release();
    CoUninitialize();
    return 0;
}

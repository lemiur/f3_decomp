/* f3resync: after a unit's source was restructured (stand-in types replaced by the shared classes, functions moved to
   their real class), carry its build/units.json entry over to the new decorated names, with the base tree's object as
   the oracle. No byte of the game is read: only the two compiled objects are compared.

   f3resync HEAD_REPO BASE_REPO TEXT [--write] [--prune]
   f3resync --roundtrip UNITS_JSON     (self-test: parse and print it back; must equal the file)

   For every unit of HEAD_REPO/build/units.json whose source contains TEXT (and the unit at the same position among
   the units with that source in BASE_REPO/build/units.json):
   1. compile it in both trees, as tools/build_and_match.py does (cl with the unit's flags, /I<repo>/include, in the
      repo), with the compiler under F3_MSVC_ROOT;
   2. rename: a recipe function whose symbol is not in the head object takes the head function whose code, with every
      relocation field masked, equals the base function's code over the recipe size (if several, the ones with the
      same method name; still several: reported, nothing changed). Unit symbol keys derived from the old name
      (__ehhandler$, __unwindfunclet$, __sehtable$, __catch$) get the new name too;
   3. bind: a relocation in a head function whose target the entry does not resolve gets bound to the address the
      base object's relocation at the same offset resolves to (same addend; string and float literals and the
      object's own static symbols are left alone);
   4. --prune: drop the unit's symbol keys that no symbol of the head object names.
   --write writes build/units.json back in its own format (json.dumps(indent=1), LF). Without it nothing is written.

   Build: build.cmd (VS2022 x64). */
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
#include <io.h>

/* ------------------------------------------------------------------------------------------------- basics */

static void die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fputs("f3resync: ", stderr);
    vfprintf(stderr, fmt, ap);
    fputc('\n', stderr);
    va_end(ap);
    exit(2);
}

static void *xmalloc(size_t n)
{
    void *p = malloc(n ? n : 1);
    if (!p) die("out of memory");
    return p;
}

static void *xrealloc(void *p, size_t n)
{
    p = realloc(p, n ? n : 1);
    if (!p) die("out of memory");
    return p;
}

static char *xstrdup(const char *s)
{
    size_t n = strlen(s);
    char *r = xmalloc(n + 1);
    memcpy(r, s, n + 1);
    return r;
}

static char *read_file(const char *path, size_t *len)
{
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    long n = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *b = xmalloc((size_t)n + 1);
    if (fread(b, 1, (size_t)n, f) != (size_t)n) die("cannot read %s", path);
    b[n] = 0;
    fclose(f);
    if (len) *len = (size_t)n;
    return b;
}

typedef struct {
    char *p;
    size_t n, cap;
} Buf;

static void bput(Buf *b, const char *s, size_t n)
{
    if (b->n + n + 1 > b->cap) {
        b->cap = (b->n + n + 1) * 2;
        b->p = xrealloc(b->p, b->cap);
    }
    memcpy(b->p + b->n, s, n);
    b->n += n;
    b->p[b->n] = 0;
}

static void bputs(Buf *b, const char *s) { bput(b, s, strlen(s)); }

/* ------------------------------------------------------------------------------------------------- JSON */

enum { J_NULL, J_FALSE, J_TRUE, J_NUM, J_STR, J_ARR, J_OBJ };

typedef struct JV {
    int t;
    char *s;  /* J_STR: the decoded string; J_NUM: the number as written */
    int n, cap;
    struct JV **v;
    char **k; /* J_OBJ: decoded keys */
} JV;

static const char *jp;

static void jws(void)
{
    while (*jp == ' ' || *jp == '\n' || *jp == '\r' || *jp == '\t') jp++;
}

static char *jstr(void)
{
    Buf b = {0};
    if (*jp != '"') die("json: string expected");
    jp++;
    while (*jp != '"') {
        if (!*jp) die("json: unterminated string");
        if (*jp == '\\') {
            jp++;
            char c = *jp++;
            switch (c) {
            case 'n': bput(&b, "\n", 1); break;
            case 't': bput(&b, "\t", 1); break;
            case 'r': bput(&b, "\r", 1); break;
            case 'b': bput(&b, "\b", 1); break;
            case 'f': bput(&b, "\f", 1); break;
            case 'u': {
                char hex[5] = {jp[0], jp[1], jp[2], jp[3], 0};
                unsigned u = (unsigned)strtoul(hex, NULL, 16);
                jp += 4;
                if (u > 0x7f) die("json: non-ASCII escape not supported");
                char ch = (char)u;
                bput(&b, &ch, 1);
                break;
            }
            default: bput(&b, &c, 1);
            }
        } else
            bput(&b, jp++, 1);
    }
    jp++;
    if (!b.p) return xstrdup("");
    return b.p;
}

static void jpush(JV *a, char *key, JV *val)
{
    if (a->n == a->cap) {
        a->cap = a->cap ? a->cap * 2 : 8;
        a->v = xrealloc(a->v, sizeof(JV *) * a->cap);
        if (a->t == J_OBJ) a->k = xrealloc(a->k, sizeof(char *) * a->cap);
    }
    a->v[a->n] = val;
    if (a->t == J_OBJ) a->k[a->n] = key;
    a->n++;
}

static JV *jnew(int t)
{
    JV *v = xmalloc(sizeof(JV));
    memset(v, 0, sizeof *v);
    v->t = t;
    return v;
}

static JV *jparse(void)
{
    jws();
    JV *v;
    if (*jp == '{') {
        v = jnew(J_OBJ);
        jp++;
        jws();
        if (*jp == '}') { jp++; return v; }
        for (;;) {
            jws();
            char *k = jstr();
            jws();
            if (*jp++ != ':') die("json: ':' expected");
            jpush(v, k, jparse());
            jws();
            if (*jp == ',') { jp++; continue; }
            if (*jp++ != '}') die("json: '}' expected");
            return v;
        }
    }
    if (*jp == '[') {
        v = jnew(J_ARR);
        jp++;
        jws();
        if (*jp == ']') { jp++; return v; }
        for (;;) {
            jpush(v, NULL, jparse());
            jws();
            if (*jp == ',') { jp++; continue; }
            if (*jp++ != ']') die("json: ']' expected");
            return v;
        }
    }
    if (*jp == '"') {
        v = jnew(J_STR);
        v->s = jstr();
        return v;
    }
    if (!strncmp(jp, "true", 4)) { jp += 4; return jnew(J_TRUE); }
    if (!strncmp(jp, "false", 5)) { jp += 5; return jnew(J_FALSE); }
    if (!strncmp(jp, "null", 4)) { jp += 4; return jnew(J_NULL); }
    {
        const char *s = jp;
        while (*jp == '-' || *jp == '+' || *jp == '.' || *jp == 'e' || *jp == 'E' || (*jp >= '0' && *jp <= '9')) jp++;
        if (jp == s) die("json: unexpected character '%c'", *jp);
        v = jnew(J_NUM);
        v->s = xmalloc((size_t)(jp - s) + 1);
        memcpy(v->s, s, (size_t)(jp - s));
        v->s[jp - s] = 0;
        return v;
    }
}

static void jout_str(Buf *b, const char *s)
{
    bput(b, "\"", 1);
    for (; *s; s++) {
        unsigned char c = (unsigned char)*s;
        char tmp[8];
        switch (c) {
        case '"': bputs(b, "\\\""); break;
        case '\\': bputs(b, "\\\\"); break;
        case '\n': bputs(b, "\\n"); break;
        case '\r': bputs(b, "\\r"); break;
        case '\t': bputs(b, "\\t"); break;
        case '\b': bputs(b, "\\b"); break;
        case '\f': bputs(b, "\\f"); break;
        default:
            if (c < 0x20 || c >= 0x7f) {
                sprintf(tmp, "\\u%04x", c);
                bputs(b, tmp);
            } else
                bput(b, (const char *)&c, 1);
        }
    }
    bput(b, "\"", 1);
}

static void jindent(Buf *b, int level)
{
    for (int i = 0; i < level; i++) bput(b, " ", 1);
}

/* Python's json.dumps(value, indent=1) */
static void jout(Buf *b, const JV *v, int level)
{
    switch (v->t) {
    case J_NULL: bputs(b, "null"); return;
    case J_TRUE: bputs(b, "true"); return;
    case J_FALSE: bputs(b, "false"); return;
    case J_NUM: bputs(b, v->s); return;
    case J_STR: jout_str(b, v->s); return;
    }
    if (v->n == 0) {
        bputs(b, v->t == J_OBJ ? "{}" : "[]");
        return;
    }
    bputs(b, v->t == J_OBJ ? "{\n" : "[\n");
    for (int i = 0; i < v->n; i++) {
        jindent(b, level + 1);
        if (v->t == J_OBJ) {
            jout_str(b, v->k[i]);
            bputs(b, ": ");
        }
        jout(b, v->v[i], level + 1);
        if (i + 1 < v->n) bput(b, ",", 1);
        bput(b, "\n", 1);
    }
    jindent(b, level);
    bputs(b, v->t == J_OBJ ? "}" : "]");
}

static JV *jget(const JV *o, const char *key)
{
    if (!o || o->t != J_OBJ) return NULL;
    for (int i = 0; i < o->n; i++)
        if (!strcmp(o->k[i], key)) return o->v[i];
    return NULL;
}

static void jdel(JV *o, int i)
{
    memmove(o->v + i, o->v + i + 1, sizeof(JV *) * (size_t)(o->n - i - 1));
    memmove(o->k + i, o->k + i + 1, sizeof(char *) * (size_t)(o->n - i - 1));
    o->n--;
}

static JV *jload(const char *path)
{
    char *text = read_file(path, NULL);
    if (!text) die("cannot read %s", path);
    jp = text;
    return jparse();
}

/* ------------------------------------------------------------------------------------------------- COFF */

typedef struct {
    char name[9];
    uint8_t *data;
    uint32_t size, flags;
    uint32_t nrel;
    uint8_t *rel; /* 10-byte records: offset, symbol index, type */
} Sect;

typedef struct {
    char *name;
    uint32_t value;
    int16_t sect;
    uint16_t type;
    uint8_t storage;
} Sym;

typedef struct {
    uint8_t *file;
    Sect *sec; /* 1-based */
    int nsec;
    Sym *sym;  /* by raw index; aux records have name NULL */
    int nsym;
} Coff;

static uint16_t rd16(const uint8_t *p) { return (uint16_t)(p[0] | p[1] << 8); }
static uint32_t rd32(const uint8_t *p) { return (uint32_t)p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24; }

static int coff_load(const char *path, Coff *c)
{
    size_t len;
    uint8_t *d = (uint8_t *)read_file(path, &len);
    if (!d) return 0;
    memset(c, 0, sizeof *c);
    c->file = d;
    if (rd16(d) != 0x14c) die("%s: not an i386 object", path);
    c->nsec = rd16(d + 2);
    uint32_t symptr = rd32(d + 8), nsym = rd32(d + 12);
    uint16_t opt = rd16(d + 16);
    c->sec = xmalloc(sizeof(Sect) * (size_t)(c->nsec + 1));
    memset(c->sec, 0, sizeof(Sect) * (size_t)(c->nsec + 1));
    for (int i = 1; i <= c->nsec; i++) {
        const uint8_t *h = d + 20 + opt + (i - 1) * 40;
        Sect *s = &c->sec[i];
        memcpy(s->name, h, 8);
        s->size = rd32(h + 16);
        uint32_t raw = rd32(h + 20), relptr = rd32(h + 24);
        s->nrel = rd16(h + 32);
        s->flags = rd32(h + 36);
        if (s->flags & 0x1000000) die("%s: extended relocation counts are unsupported", path);
        if (raw == 0) {
            s->data = xmalloc(s->size);
            memset(s->data, 0, s->size);
        } else
            s->data = d + raw;
        s->rel = d + relptr;
    }
    const uint8_t *strs = d + symptr + nsym * 18;
    c->nsym = (int)nsym;
    c->sym = xmalloc(sizeof(Sym) * (nsym + 1));
    memset(c->sym, 0, sizeof(Sym) * (nsym + 1));
    for (uint32_t i = 0; i < nsym; i++) {
        const uint8_t *r = d + symptr + i * 18;
        Sym *s = &c->sym[i];
        if (rd32(r) == 0)
            s->name = xstrdup((const char *)strs + rd32(r + 4));
        else {
            char tmp[9];
            memcpy(tmp, r, 8);
            tmp[8] = 0;
            s->name = xstrdup(tmp);
        }
        s->value = rd32(r + 8);
        s->sect = (int16_t)rd16(r + 12);
        s->type = rd16(r + 14);
        s->storage = r[16];
        uint8_t aux = r[17];
        i += aux;
    }
    return 1;
}

typedef struct {
    char *name;
    int sect;
    uint32_t start, end;
} Fn;

typedef struct {
    Fn *v;
    int n;
} Fns;

/* every defined function symbol (external or static), its extent: up to the next function symbol in its section */
static void coff_funcs(const Coff *c, Fns *out)
{
    out->v = NULL;
    out->n = 0;
    int cap = 0;
    for (int i = 0; i < c->nsym; i++) {
        const Sym *s = &c->sym[i];
        if (!s->name || s->sect <= 0 || !(s->type & 0x20) || (s->storage != 2 && s->storage != 3)) continue;
        int dup = 0;
        for (int k = 0; k < out->n; k++)
            if (!strcmp(out->v[k].name, s->name)) { dup = 1; break; }
        if (dup) continue;
        uint32_t end = c->sec[s->sect].size;
        for (int j = 0; j < c->nsym; j++) {
            const Sym *t = &c->sym[j];
            if (!t->name || t->sect != s->sect || !(t->type & 0x20) || t->value <= s->value) continue;
            if (!strncmp(t->name, "__catch$", 8)) continue;
            if (t->value < end) end = t->value;
        }
        if (out->n == cap) {
            cap = cap ? cap * 2 : 64;
            out->v = xrealloc(out->v, sizeof(Fn) * (size_t)cap);
        }
        out->v[out->n].name = s->name;
        out->v[out->n].sect = s->sect;
        out->v[out->n].start = s->value;
        out->v[out->n].end = end;
        out->n++;
    }
}

static const Fn *fn_find(const Fns *f, const char *name)
{
    for (int i = 0; i < f->n; i++)
        if (!strcmp(f->v[i].name, name)) return &f->v[i];
    return NULL;
}

typedef struct {
    uint32_t off;
    uint16_t type;
    const Sym *sym;
    int32_t addend;
} Rel;

/* the code over size bytes with relocation fields cleared, and the relocations inside it */
static uint8_t *fn_body(const Coff *c, const Fn *f, uint32_t size, Rel **rels, int *nrels)
{
    const Sect *s = &c->sec[f->sect];
    uint8_t *b = xmalloc(size);
    uint32_t avail = f->start + size <= s->size ? size : s->size - f->start;
    memset(b, 0, size);
    memcpy(b, s->data + f->start, avail);
    int n = 0;
    Rel *r = rels ? xmalloc(sizeof(Rel) * (s->nrel + 1)) : NULL;
    for (uint32_t i = 0; i < s->nrel; i++) {
        const uint8_t *rr = s->rel + i * 10;
        uint32_t o = rd32(rr);
        if (o < f->start || o >= f->start + size) continue;
        uint32_t rel = o - f->start;
        int32_t addend = 0;
        if (o + 4 <= s->size) addend = (int32_t)rd32(s->data + o);
        for (uint32_t k = 0; k < 4 && rel + k < size; k++) b[rel + k] = 0;
        if (r) {
            r[n].off = rel;
            r[n].type = rd16(rr + 8);
            r[n].sym = &c->sym[rd32(rr + 4)];
            r[n].addend = addend;
            n++;
        }
    }
    if (rels) {
        *rels = r;
        *nrels = n;
    }
    return b;
}

/* ------------------------------------------------------------------------------------------------- resolution */

typedef struct {
    const Coff *c;
    const Fns *fns;
    JV *unit;
} Ctx;

static int addr_of(const char *s, uint32_t *out)
{
    if (!s) return 0;
    *out = (uint32_t)strtoul(s, NULL, 0);
    return 1;
}

/* the original address a relocation to sym + addend stands for, as compare.py resolves it; 0 when unresolved */
static int resolve(const Ctx *x, const Sym *sym, int32_t addend, uint32_t *out)
{
    JV *syms = jget(x->unit, "symbols");
    JV *v = jget(syms, sym->name);
    if (v && v->t == J_STR) {
        *out = (uint32_t)strtoul(v->s, NULL, 0) + (uint32_t)addend;
        return 1;
    }
    JV *funcs = jget(x->unit, "functions");
    for (int i = 0; funcs && i < funcs->n; i++) {
        JV *fsym = jget(funcs->v[i], "symbol");
        if (fsym && !strcmp(fsym->s, sym->name)) {
            uint32_t a;
            addr_of(jget(funcs->v[i], "address")->s, &a);
            *out = a + (uint32_t)addend;
            return 1;
        }
    }
    if (sym->sect > 0) {
        uint32_t p = sym->value + (uint32_t)addend;
        int hits = 0;
        uint32_t res = 0;
        for (int i = 0; funcs && i < funcs->n; i++) {
            const Fn *f = fn_find(x->fns, jget(funcs->v[i], "symbol")->s);
            if (!f || f->sect != sym->sect) continue;
            uint32_t size = (uint32_t)strtoul(jget(funcs->v[i], "size")->s, NULL, 10);
            if (p >= f->start && p < f->start + size) {
                uint32_t a;
                addr_of(jget(funcs->v[i], "address")->s, &a);
                res = a + p - f->start;
                hits++;
            }
        }
        if (hits == 1) {
            *out = res;
            return 1;
        }
        return 0;
    }
    if (sym->sect == -1) {
        *out = sym->value + (uint32_t)addend;
        return 1;
    }
    return 0;
}

static const char *method_of(const char *name, char *buf, size_t n)
{
    while (*name == '?') name++;
    size_t i = 0;
    while (name[i] && name[i] != '@' && i + 1 < n) {
        buf[i] = name[i];
        i++;
    }
    buf[i] = 0;
    return buf;
}

/* ------------------------------------------------------------------------------------------------- compiling */

static char g_tmp[MAX_PATH];

static int compile(const char *repo, JV *unit, const char *obj)
{
    Buf cmd = {0};
    const char *root = getenv("F3_MSVC_ROOT");
    bputs(&cmd, "\"");
    bputs(&cmd, root);
    bputs(&cmd, "/VC/bin/cl.exe\" /c /nologo");
    JV *flags = jget(unit, "flags");
    for (int i = 0; flags && i < flags->n; i++) {
        bputs(&cmd, " ");
        bputs(&cmd, flags->v[i]->s);
    }
    bputs(&cmd, " \"/I");
    bputs(&cmd, repo);
    bputs(&cmd, "/include\" \"");
    bputs(&cmd, repo);
    bputs(&cmd, "/");
    bputs(&cmd, jget(unit, "source")->s);
    bputs(&cmd, "\" \"/Fo");
    bputs(&cmd, obj);
    bputs(&cmd, "\"");
    char log[MAX_PATH];
    snprintf(log, sizeof log, "%s.log", obj);
    SECURITY_ATTRIBUTES sa = {sizeof sa, NULL, TRUE};
    HANDLE h = CreateFileA(log, GENERIC_WRITE, FILE_SHARE_READ, &sa, CREATE_ALWAYS, 0, NULL);
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    memset(&si, 0, sizeof si);
    si.cb = sizeof si;
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdOutput = h;
    si.hStdError = h;
    si.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
    DeleteFileA(obj);
    if (!CreateProcessA(NULL, cmd.p, NULL, NULL, TRUE, 0, NULL, repo, &si, &pi)) die("cannot run cl.exe");
    WaitForSingleObject(pi.hProcess, INFINITE);
    DWORD code = 1;
    GetExitCodeProcess(pi.hProcess, &code);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    CloseHandle(h);
    free(cmd.p);
    if (code != 0 || GetFileAttributesA(obj) == INVALID_FILE_ATTRIBUTES) {
        char *text = read_file(log, NULL);
        if (text) {
            size_t n = strlen(text);
            fputs(n > 3000 ? text + n - 3000 : text, stdout);
        }
        return 0;
    }
    return 1;
}

static void setup_env(void)
{
    const char *root = getenv("F3_MSVC_ROOT");
    if (!root) die("set F3_MSVC_ROOT to the folder holding VC/ and SDK/");
    char buf[8192];
    snprintf(buf, sizeof buf, "%s/VC/include;%s/SDK/Include", root, root);
    SetEnvironmentVariableA("INCLUDE", buf);
    snprintf(buf, sizeof buf, "%s/VC/lib;%s/SDK/Lib", root, root);
    SetEnvironmentVariableA("LIB", buf);
    char path[32767];
    DWORD n = GetEnvironmentVariableA("PATH", path, sizeof path);
    if (n >= sizeof path) n = 0;
    path[n] = 0;
    char *np = xmalloc(strlen(path) + strlen(root) + 32);
    sprintf(np, "%s\\VC\\bin;%s", root, path);
    SetEnvironmentVariableA("PATH", np);
    free(np);
    DWORD t = GetTempPathA(sizeof g_tmp, g_tmp);
    if (!t) die("no temp folder");
    char sub[64];
    snprintf(sub, sizeof sub, "f3resync_%lu", (unsigned long)GetCurrentProcessId());
    strcat(g_tmp, sub);
    CreateDirectoryA(g_tmp, NULL);
}

/* ------------------------------------------------------------------------------------------------- main */

static int is_literal(const char *n)
{
    return !strncmp(n, "$SG", 3) || !strncmp(n, "??_C@", 5) || !strncmp(n, "__real@", 7) || !strncmp(n, "__xmm@", 6);
}

static int g_changed;

static void set_symbol(JV *unit, const char *key, uint32_t addr)
{
    JV *syms = jget(unit, "symbols");
    if (!syms) {
        syms = jnew(J_OBJ);
        jpush(unit, xstrdup("symbols"), syms);
    }
    JV *v = jnew(J_STR);
    char tmp[16];
    sprintf(tmp, "0x%08x", addr);
    v->s = xstrdup(tmp);
    jpush(syms, xstrdup(key), v);
    g_changed = 1;
}

static void process(const char *head, const char *base, JV *hunit, JV *bunit, int idx, int prune)
{
    char hobj[MAX_PATH], bobj[MAX_PATH];
    snprintf(hobj, sizeof hobj, "%s/h%d.obj", g_tmp, idx);
    snprintf(bobj, sizeof bobj, "%s/b%d.obj", g_tmp, idx);
    const char *src = jget(hunit, "source")->s;
    if (!compile(base, bunit, bobj)) {
        printf("base compile failed %s\n", src);
        return;
    }
    if (!compile(head, hunit, hobj)) {
        printf("HEAD COMPILE FAILED %s\n", src);
        return;
    }
    Coff bc, hc;
    coff_load(bobj, &bc);
    coff_load(hobj, &hc);
    Fns bf, hf;
    coff_funcs(&bc, &bf);
    coff_funcs(&hc, &hf);
    Ctx bx = {&bc, &bf, bunit};
    JV *hfuncs = jget(hunit, "functions"), *bfuncs = jget(bunit, "functions");
    int renames = 0, binds = 0, pruned = 0;
    char *used = xmalloc((size_t)hf.n + 1);
    memset(used, 0, (size_t)hf.n + 1);
    for (int i = 0; i < hfuncs->n; i++) {
        const Fn *f = fn_find(&hf, jget(hfuncs->v[i], "symbol")->s);
        if (f) used[f - hf.v] = 1;
    }
    /* 2. renames */
    for (int i = 0; i < hfuncs->n; i++) {
        JV *fn = hfuncs->v[i];
        JV *sym = jget(fn, "symbol");
        if (fn_find(&hf, sym->s)) continue;
        const char *addr = jget(fn, "address")->s;
        uint32_t size = (uint32_t)strtoul(jget(fn, "size")->s, NULL, 10);
        JV *bfn = NULL;
        for (int k = 0; k < bfuncs->n; k++)
            if (!strcmp(jget(bfuncs->v[k], "address")->s, addr)) bfn = bfuncs->v[k];
        const Fn *bfp = bfn ? fn_find(&bf, jget(bfn, "symbol")->s) : NULL;
        if (!bfp) {
            printf("  no base for %s\n", addr);
            continue;
        }
        uint8_t *bb = fn_body(&bc, bfp, size, NULL, NULL);
        int cand[64], nc = 0;
        for (int k = 0; k < hf.n && nc < 64; k++) {
            if (used[k] || hf.v[k].end - hf.v[k].start < size) continue;
            uint8_t *hb = fn_body(&hc, &hf.v[k], size, NULL, NULL);
            if (!memcmp(hb, bb, size)) cand[nc++] = k;
            free(hb);
        }
        free(bb);
        if (nc > 1) {
            char m0[256], m1[256];
            method_of(sym->s, m0, sizeof m0);
            int keep[64], nk = 0;
            for (int k = 0; k < nc; k++)
                if (!strcmp(method_of(hf.v[cand[k]].name, m1, sizeof m1), m0)) keep[nk++] = cand[k];
            if (nk) {
                memcpy(cand, keep, sizeof(int) * (size_t)nk);
                nc = nk;
            }
        }
        if (nc != 1) {
            printf("  %s %s %s\n", nc ? "AMBIGUOUS" : "NOT FOUND", addr, sym->s);
            for (int k = 0; k < nc && k < 4; k++) printf("      candidate %s\n", hf.v[cand[k]].name);
            continue;
        }
        const char *nn = hf.v[cand[0]].name;
        printf("  rename %s %s -> %s\n", addr, sym->s, nn);
        JV *syms = jget(hunit, "symbols");
        static const char *pre[] = {"__ehhandler$", "__unwindfunclet$", "__sehtable$", "__catch$", NULL};
        for (int k = 0; syms && k < syms->n; k++) {
            for (int p = 0; pre[p]; p++) {
                const char *key = syms->k[k];
                if (strncmp(key, pre[p], strlen(pre[p])) || !strstr(key, sym->s)) continue;
                const char *at = strstr(key, sym->s);
                Buf nk = {0};
                bput(&nk, key, (size_t)(at - key));
                bputs(&nk, nn);
                bputs(&nk, at + strlen(sym->s));
                if (!jget(syms, nk.p)) {
                    uint32_t a;
                    addr_of(syms->v[k]->s, &a);
                    set_symbol(hunit, nk.p, a);
                    printf("  bind (eh) %s\n", nk.p);
                }
                free(nk.p);
            }
        }
        sym->s = xstrdup(nn);
        used[cand[0]] = 1;
        renames++;
        g_changed = 1;
    }
    /* 3. bindings */
    Ctx hx = {&hc, &hf, hunit};
    for (int i = 0; i < hfuncs->n; i++) {
        JV *fn = hfuncs->v[i];
        const Fn *f = fn_find(&hf, jget(fn, "symbol")->s);
        if (!f) continue;
        const char *addr = jget(fn, "address")->s;
        uint32_t size = (uint32_t)strtoul(jget(fn, "size")->s, NULL, 10);
        JV *bfn = NULL;
        for (int k = 0; k < bfuncs->n; k++)
            if (!strcmp(jget(bfuncs->v[k], "address")->s, addr)) bfn = bfuncs->v[k];
        const Fn *bfp = bfn ? fn_find(&bf, jget(bfn, "symbol")->s) : NULL;
        if (!bfp) continue;
        Rel *br, *hr;
        int nbr, nhr;
        free(fn_body(&bc, bfp, size, &br, &nbr));
        free(fn_body(&hc, f, size, &hr, &nhr));
        for (int r = 0; r < nhr; r++) {
            uint32_t t;
            if (resolve(&hx, hr[r].sym, hr[r].addend, &t)) continue;
            const Rel *b = NULL;
            for (int q = 0; q < nbr; q++)
                if (br[q].off == hr[r].off) b = &br[q];
            if (!b) {
                printf("  reloc only in head %s +0x%x %s\n", addr, hr[r].off, hr[r].sym->name);
                continue;
            }
            if (!resolve(&bx, b->sym, b->addend, &t)) {
                printf("  base unresolved too %s +0x%x %s\n", addr, hr[r].off, b->sym->name);
                continue;
            }
            if (is_literal(hr[r].sym->name) || (hr[r].sym->sect > 0 && hr[r].sym->storage != 2)) continue;
            if (hr[r].addend != b->addend) {
                printf("  addend differs %s\n", hr[r].sym->name);
                continue;
            }
            uint32_t want = t - (uint32_t)hr[r].addend, prev;
            JV *pv = jget(jget(hunit, "symbols"), hr[r].sym->name);
            if (pv && addr_of(pv->s, &prev)) {
                if (prev != want) printf("  CONFLICT %s %s 0x%08x\n", hr[r].sym->name, pv->s, want);
                continue;
            }
            set_symbol(hunit, hr[r].sym->name, want);
            printf("  bind %s -> 0x%08x\n", hr[r].sym->name, want);
            binds++;
        }
        free(br);
        free(hr);
    }
    /* 4. prune */
    if (prune) {
        JV *syms = jget(hunit, "symbols");
        for (int k = 0; syms && k < syms->n;) {
            int present = 0;
            for (int s = 0; s < hc.nsym && !present; s++)
                if (hc.sym[s].name && !strcmp(hc.sym[s].name, syms->k[k])) present = 1;
            if (!present) {
                jdel(syms, k);
                pruned++;
                g_changed = 1;
            } else
                k++;
        }
    }
    printf("%s: %d renamed, %d bound, %d pruned\n", src, renames, binds, pruned);
    DeleteFileA(hobj);
    DeleteFileA(bobj);
}

int main(int argc, char **argv)
{
    if (argc == 3 && !strcmp(argv[1], "--roundtrip")) { /* self-test: parse and write back */
        JV *r = jload(argv[2]);
        Buf out = {0};
        jout(&out, r, 0);
        bput(&out, "\n", 1);
        _setmode(_fileno(stdout), 0x8000); /* _O_BINARY */
        fwrite(out.p, 1, out.n, stdout);
        return 0;
    }
    if (argc < 4) {
        fprintf(stderr, "usage: f3resync HEAD_REPO BASE_REPO TEXT [--write] [--prune]\n");
        return 2;
    }
    const char *head = argv[1], *base = argv[2], *text = argv[3];
    int write = 0, prune = 0;
    for (int i = 4; i < argc; i++) {
        if (!strcmp(argv[i], "--write")) write = 1;
        else if (!strcmp(argv[i], "--prune")) prune = 1;
        else die("unknown option %s", argv[i]);
    }
    setup_env();
    char hp[MAX_PATH], bp[MAX_PATH];
    snprintf(hp, sizeof hp, "%s/build/units.json", head);
    snprintf(bp, sizeof bp, "%s/build/units.json", base);
    JV *hroot = jload(hp), *broot = jload(bp);
    JV *hu = jget(hroot, "units"), *bu = jget(broot, "units");
    for (int i = 0; i < hu->n; i++) {
        const char *src = jget(hu->v[i], "source")->s;
        if (!strstr(src, text)) continue;
        int pos = 0, j, seen = 0;
        for (j = 0; j < i; j++)
            if (!strcmp(jget(hu->v[j], "source")->s, src)) pos++;
        JV *bunit = NULL;
        for (j = 0; j < bu->n; j++)
            if (!strcmp(jget(bu->v[j], "source")->s, src) && seen++ == pos) bunit = bu->v[j];
        if (!bunit) {
            printf("no base unit for %s\n", src);
            continue;
        }
        process(head, base, hu->v[i], bunit, i, prune);
    }
    RemoveDirectoryA(g_tmp);
    if (write && g_changed) {
        Buf out = {0};
        jout(&out, hroot, 0);
        bput(&out, "\n", 1);
        FILE *f = fopen(hp, "wb");
        if (!f || fwrite(out.p, 1, out.n, f) != out.n) die("cannot write %s", hp);
        fclose(f);
        printf("written\n");
    }
    return 0;
}

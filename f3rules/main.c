/* f3rules - the [match] / advisory rule checker for the f3_decomp source, per recipe function.

   usage: f3rules <repo> <outdir> [--jobs N] [--msvc-root DIR] [--mspdb-dir DIR] [--obj-dir DIR]
                  [--keep-objs] [--reuse-objs] [--only TEXT]

   1. Compiles every unit of build/units.json with its own flags plus /Z7 (for locating only; never compared) and
      reads the object's CodeView procs and line tables: decorated name -> file, lines.
   2. Indexes declarations over src/ and include/ (type definitions, placeholder virtuals, volatile declarations,
      file-scope externs, #includes).
   3. Checks each recipe function's signature and body for the [match] rules R1 R2 R4 R13 R17 R18 and the advisory
      rules R7 R33 R37, and lists the definitions in each unit's own source that no recipe entry verifies.
   Writes functions.tsv, findings.tsv, unchecked.tsv and summary.md to <outdir>. */
#include "model.h"
#include "json.h"
#include "coff.h"

SrcFile *g_files;
int g_nfiles;
StrMap g_file_by_key;
Func *g_funcs;
int g_nfuncs;
Unit *g_units;
int g_nunits;
FileIdx *g_fidx;
char g_repo[MAX_PATH];
StrMap g_r1_keys, g_r1_names, g_virt_by_class, g_virt_names, g_vol_globals, g_vol_members;

static char g_msvc[MAX_PATH] = "E:\\f3-campaign\\vs2005";
static char g_mspdb[MAX_PATH] = "C:\\Program Files (x86)\\Microsoft Visual Studio 8\\Common7\\IDE";
static char g_objdir[MAX_PATH];
static char g_out[MAX_PATH];
static int g_jobs = 16, g_keep = 0, g_reuse = 0;
static const char *g_only = NULL;
static char *g_envblock;
static char g_repo_lower[MAX_PATH]; /* lowercase, forward slashes, trailing '/' */

/* ------------------------------------------------------------------ files */

int file_lookup_rel(const char *rel_lower)
{
    void *v = smap_get(&g_file_by_key, rel_lower);
    return v ? (int)(intptr_t)v - 1 : -1;
}

static int ends_with_ci(const char *s, const char *suf)
{
    size_t n = strlen(s), m = strlen(suf);
    return n >= m && _stricmp(s + n - m, suf) == 0;
}

typedef VEC(SrcFile) FileVec;

static void scan_dir(const char *rel, FileVec *out)
{
    char pat[MAX_PATH * 2];
    snprintf(pat, sizeof pat, "%s\\%s\\*", g_repo, rel);
    for (char *p = pat; *p; p++)
        if (*p == '/') *p = '\\';
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pat, &fd);
    if (h == INVALID_HANDLE_VALUE) return;
    /* collect names first, sorted, for determinism */
    VEC(char *) names = {0};
    do {
        if (strcmp(fd.cFileName, ".") == 0 || strcmp(fd.cFileName, "..") == 0) continue;
        char *n = xmalloc(strlen(fd.cFileName) + 2);
        n[0] = (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ? 'd' : 'f';
        strcpy(n + 1, fd.cFileName);
        VPUSH(names, n);
    } while (FindNextFileA(h, &fd));
    FindClose(h);
    for (int i = 1; i < names.n; i++)
        for (int j = i; j > 0 && strcmp(names.v[j - 1] + 1, names.v[j] + 1) > 0; j--) {
            char *t = names.v[j];
            names.v[j] = names.v[j - 1];
            names.v[j - 1] = t;
        }
    for (int i = 0; i < names.n; i++) {
        char sub[MAX_PATH * 2];
        snprintf(sub, sizeof sub, "%s/%s", rel, names.v[i] + 1);
        if (names.v[i][0] == 'd') {
            scan_dir(sub, out);
        } else {
            const char *nm = names.v[i] + 1;
            int hdr = ends_with_ci(nm, ".h") || ends_with_ci(nm, ".hpp") || ends_with_ci(nm, ".inl");
            int cpp = ends_with_ci(nm, ".cpp") || ends_with_ci(nm, ".c") || ends_with_ci(nm, ".cxx") || ends_with_ci(nm, ".cc");
            if (!hdr && !cpp) {
                free(names.v[i]);
                continue;
            }
            SrcFile sf;
            memset(&sf, 0, sizeof sf);
            sf.rel = xstrdup(sub);
            char abs[MAX_PATH * 2];
            snprintf(abs, sizeof abs, "%s\\%s", g_repo, sub);
            for (char *p = abs; *p; p++)
                if (*p == '/') *p = '\\';
            sf.abs = xstrdup(abs);
            char dk[MAX_PATH * 2];
            snprintf(dk, sizeof dk, "%s/", rel);
            lower_inplace(dk);
            sf.dir_key = xstrdup(dk);
            sf.is_header = hdr;
            sf.is_cpp = cpp;
            sf.under_src = strncmp(sub, "src/", 4) == 0;
            if (sf.under_src) {
                const char *slash = strchr(sub + 4, '/');
                if (slash) {
                    char m[MAX_PATH];
                    snprintf(m, sizeof m, "%.*s/", (int)(slash - sub), sub);
                    sf.module = xstrdup(m);
                } else
                    sf.module = xstrdup("src/");
            } else
                sf.module = xstrdup("include/");
            VPUSH(*out, sf);
        }
        free(names.v[i]);
    }
    free(names.v);
}

/* repo-relative lowercase key of an absolute path recorded in an object, or NULL */
static int obj_path_to_file(const char *recorded)
{
    char buf[1024];
    snprintf(buf, sizeof buf, "%s", recorded);
    slash_inplace(buf);
    lower_inplace(buf);
    /* resolve ".." */
    char out[1024];
    int k = 0;
    for (char *p = buf; *p;) {
        if (strncmp(p, "../", 3) == 0 && k > 0) {
            /* drop the last component */
            if (k > 0 && out[k - 1] == '/') k--;
            while (k > 0 && out[k - 1] != '/') k--;
            p += 3;
            continue;
        }
        if (strncmp(p, "./", 2) == 0 && (k == 0 || out[k - 1] == '/')) {
            p += 2;
            continue;
        }
        out[k++] = *p++;
        if (k >= 1023) break;
    }
    out[k] = 0;
    size_t rl = strlen(g_repo_lower);
    if (strncmp(out, g_repo_lower, rl) != 0) return -1;
    return file_lookup_rel(out + rl);
}

/* ------------------------------------------------------------------ parallel runner */

typedef struct {
    volatile LONG next;
    int n;
    void (*fn)(int);
    volatile LONG done;
    const char *label;
} Pool;

static DWORD WINAPI pool_thread(LPVOID arg)
{
    Pool *p = arg;
    for (;;) {
        LONG i = InterlockedIncrement(&p->next) - 1;
        if (i >= p->n) break;
        p->fn((int)i);
        LONG d = InterlockedIncrement(&p->done);
        if (p->label && (d % 200 == 0 || d == p->n)) fprintf(stderr, "f3rules: %s %ld/%d\n", p->label, d, p->n);
    }
    return 0;
}

static void run_parallel(int n, void (*fn)(int), const char *label)
{
    Pool p = {0, n, fn, 0, label};
    int t = g_jobs < 1 ? 1 : g_jobs;
    HANDLE *hs = xmalloc(sizeof(HANDLE) * (size_t)t);
    for (int i = 0; i < t; i++) hs[i] = CreateThread(NULL, 8 << 20, pool_thread, &p, 0, NULL);
    for (int i = 0; i < t; i += 64) WaitForMultipleObjects((DWORD)(t - i < 64 ? t - i : 64), hs + i, TRUE, INFINITE);
    for (int i = 0; i < t; i++) CloseHandle(hs[i]);
    free(hs);
}

/* ------------------------------------------------------------------ pass 1: compile and read objects */

static void build_env(void)
{
    StrBuf b = {0};
    char *env = GetEnvironmentStringsA();
    for (char *p = env; *p; p += strlen(p) + 1) {
        if (_strnicmp(p, "PATH=", 5) == 0 || _strnicmp(p, "INCLUDE=", 8) == 0 || _strnicmp(p, "LIB=", 4) == 0) continue;
        sb_add(&b, p, strlen(p) + 1);
    }
    char *path = getenv("PATH");
    char tmp[8192];
    snprintf(tmp, sizeof tmp, "PATH=%s;%s\\VC\\bin;%s", g_mspdb, g_msvc, path ? path : "");
    sb_add(&b, tmp, strlen(tmp) + 1);
    snprintf(tmp, sizeof tmp, "INCLUDE=%s\\VC\\include;%s\\SDK\\Include", g_msvc, g_msvc);
    sb_add(&b, tmp, strlen(tmp) + 1);
    snprintf(tmp, sizeof tmp, "LIB=%s\\VC\\lib;%s\\SDK\\Lib", g_msvc, g_msvc);
    sb_add(&b, tmp, strlen(tmp) + 1);
    sb_add(&b, "\0", 1);
    FreeEnvironmentStringsA(env);
    g_envblock = b.s;
}

static int run_cl(int u, const char *obj, const char *log)
{
    Unit *un = &g_units[u];
    StrBuf cmd = {0};
    sb_printf(&cmd, "\"%s\\VC\\bin\\cl.exe\" /c /nologo", g_msvc);
    for (int i = 0; i < un->nflags; i++) sb_printf(&cmd, " %s", un->flags[i]);
    char src[MAX_PATH * 2];
    snprintf(src, sizeof src, "%s\\%s", g_repo, un->source);
    for (char *p = src; *p; p++)
        if (*p == '/') *p = '\\';
    sb_printf(&cmd, " /Z7 \"/I%s\\include\" \"%s\" \"/Fo%s\"", g_repo, src, obj);

    SECURITY_ATTRIBUTES sa = {sizeof sa, NULL, TRUE};
    HANDLE hlog = CreateFileA(log, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, &sa, CREATE_ALWAYS,
                              FILE_ATTRIBUTE_NORMAL, NULL);
    if (hlog == INVALID_HANDLE_VALUE) {
        free(cmd.s);
        return -1;
    }
    SIZE_T asz = 0;
    InitializeProcThreadAttributeList(NULL, 1, 0, &asz);
    LPPROC_THREAD_ATTRIBUTE_LIST attr = xmalloc(asz);
    InitializeProcThreadAttributeList(attr, 1, 0, &asz);
    HANDLE hl[1] = {hlog};
    UpdateProcThreadAttribute(attr, 0, PROC_THREAD_ATTRIBUTE_HANDLE_LIST, hl, sizeof hl, NULL, NULL);
    STARTUPINFOEXA si;
    memset(&si, 0, sizeof si);
    si.StartupInfo.cb = sizeof si;
    si.StartupInfo.dwFlags = STARTF_USESTDHANDLES;
    si.StartupInfo.hStdInput = hlog;
    si.StartupInfo.hStdOutput = hlog;
    si.StartupInfo.hStdError = hlog;
    si.lpAttributeList = attr;
    PROCESS_INFORMATION pi;
    DWORD code = 1;
    if (CreateProcessA(NULL, cmd.s, NULL, NULL, TRUE, EXTENDED_STARTUPINFO_PRESENT | CREATE_NO_WINDOW, g_envblock, g_repo,
                       &si.StartupInfo, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        GetExitCodeProcess(pi.hProcess, &code);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    } else {
        char msg[128];
        snprintf(msg, sizeof msg, "CreateProcess failed (%lu)\r\n", GetLastError());
        DWORD w;
        WriteFile(hlog, msg, (DWORD)strlen(msg), &w, NULL);
    }
    DeleteProcThreadAttributeList(attr);
    free(attr);
    CloseHandle(hlog);
    free(cmd.s);
    return (int)code;
}

static int is_generated_name(const char *s)
{
    if (strncmp(s, "??_", 3) == 0 && s[3] != 'U' && s[3] != 'V') return 1; /* vftables, deleting dtors, ... */
    if (strncmp(s, "??__", 4) == 0) return 1;                             /* dynamic initializers / atexit */
    if (s[0] != '?' && strchr(s, '$')) return 1;                           /* __ehhandler$, __unwindfunclet$ */
    if (strncmp(s, "__ehhandler$", 12) == 0 || strncmp(s, "__unwindfunclet$", 16) == 0) return 1;
    return 0;
}

static void pass1_unit(int u)
{
    Unit *un = &g_units[u];
    if (g_only && !strstr(un->source, g_only)) return;
    char obj[MAX_PATH], log[MAX_PATH];
    snprintf(obj, sizeof obj, "%s\\u%04d.obj", g_objdir, u);
    snprintf(log, sizeof log, "%s\\u%04d.log", g_objdir, u);
    int have = 0;
    if (g_reuse) {
        DWORD a = GetFileAttributesA(obj);
        have = a != INVALID_FILE_ATTRIBUTES;
    }
    if (!have) {
        DeleteFileA(obj);
        int code = run_cl(u, obj, log);
        if (code != 0 || GetFileAttributesA(obj) == INVALID_FILE_ATTRIBUTES) {
            un->compile_ok = 0;
            size_t n;
            char *txt = read_file(log, &n);
            snprintf(un->compile_err, sizeof un->compile_err, "cl exit %d", code);
            if (txt) {
                char *e = strstr(txt, "error");
                if (e) {
                    char *ls = e;
                    while (ls > txt && ls[-1] != '\n') ls--;
                    int k = 0;
                    while (ls[k] && ls[k] != '\r' && ls[k] != '\n' && k < 200) k++;
                    snprintf(un->compile_err, sizeof un->compile_err, "%.*s", k, ls);
                }
                free(txt);
            }
            return;
        }
    }
    ObjInfo oi;
    char err[256];
    if (coff_read(obj, &oi, err, sizeof err) != 0) {
        un->compile_ok = 0;
        snprintf(un->compile_err, sizeof un->compile_err, "%s", err);
        return;
    }
    un->compile_ok = 1;
    StrMap recipe;
    smap_init(&recipe, (size_t)un->nf * 2 + 8);
    for (int k = 0; k < un->nf; k++) {
        Func *fn = &g_funcs[un->f0 + k];
        smap_put(&recipe, fn->symbol, (void *)1);
        for (int a = 0; a < fn->naliases; a++) smap_put(&recipe, fn->aliases[a], (void *)1);
    }
    StrMap refd;
    smap_init(&refd, 64);
    for (int i = 0; i < oi.n; i++)
        if (smap_has(&recipe, oi.funcs[i].name))
            for (int r = 0; r < oi.funcs[i].nrefs; r++) smap_put(&refd, oi.funcs[i].refs[r], (void *)1);
    un->objf = xcalloc((size_t)oi.n + 1, sizeof(UnitObjFunc));
    for (int i = 0; i < oi.n; i++) {
        ObjFunc *of = &oi.funcs[i];
        UnitObjFunc *uf = &un->objf[un->nobjf++];
        uf->name = xstrdup(of->name);
        uf->size = of->code_size;
        uf->is_recipe = smap_has(&recipe, of->name);
        uf->ref_by_checked = !uf->is_recipe && smap_has(&refd, of->name);
        uf->file = -1;
        if (of->file) {
            uf->has_lines = 1;
            uf->min_line = of->min_line;
            uf->max_line = of->max_line;
            uf->first_line = of->first_line;
            uf->file = obj_path_to_file(of->file);
            if (uf->file < 0) uf->extfile = xstrdup(of->file);
        }
    }
    smap_free(&recipe);
    smap_free(&refd);
    coff_free(&oi);
    if (!g_keep) {
        DeleteFileA(obj);
        DeleteFileA(log);
    }
}

/* ------------------------------------------------------------------ pass 2 / 3 drivers */

static void pass2_file(int f) { index_file(f); }

static IntVec *g_funcs_by_file;
static FindingVec *g_file_findings;
static int *g_check_files;
static int g_ncheck_files;

static void pass3_file(int k)
{
    int f = g_check_files[k];
    check_file(f, g_funcs_by_file[f].v, g_funcs_by_file[f].n, &g_file_findings[f]);
}

/* ------------------------------------------------------------------ units.json */

static void load_units(void)
{
    char path[MAX_PATH * 2];
    snprintf(path, sizeof path, "%s\\build\\units.json", g_repo);
    size_t n;
    char *txt = read_file(path, &n);
    if (!txt) die("cannot read %s", path);
    char err[128];
    JVal *root = json_parse(txt, err, sizeof err);
    if (!root) die("units.json: %s", err);
    JVal *units = json_get(root, "units");
    if (!units || units->type != J_ARR) die("units.json: no units[]");
    g_nunits = units->n;
    g_units = xcalloc((size_t)g_nunits, sizeof(Unit));
    int total = 0;
    for (int u = 0; u < units->n; u++) {
        JVal *fs = json_get(units->items[u], "functions");
        total += fs ? fs->n : 0;
    }
    g_funcs = xcalloc((size_t)total + 1, sizeof(Func));
    for (int u = 0; u < units->n; u++) {
        JVal *ju = units->items[u];
        Unit *un = &g_units[u];
        JVal *s = json_get(ju, "source");
        un->source = xstrdup(s && s->type == J_STR ? s->str : "");
        JVal *fl = json_get(ju, "flags");
        if (fl && fl->type == J_ARR) {
            un->flags = xcalloc((size_t)fl->n + 1, sizeof(char *));
            for (int k = 0; k < fl->n; k++) un->flags[un->nflags++] = xstrdup(fl->items[k]->str);
        }
        char key[MAX_PATH];
        snprintf(key, sizeof key, "%s", un->source);
        slash_inplace(key);
        lower_inplace(key);
        un->src_file = file_lookup_rel(key);
        un->f0 = g_nfuncs;
        JVal *fs = json_get(ju, "functions");
        for (int k = 0; fs && k < fs->n; k++) {
            JVal *jf = fs->items[k];
            Func *fn = &g_funcs[g_nfuncs++];
            JVal *a = json_get(jf, "address"), *sy = json_get(jf, "symbol"), *sz = json_get(jf, "size");
            fn->addr = a && a->type == J_STR ? (uint32_t)strtoul(a->str, NULL, 16) : 0;
            fn->symbol = xstrdup(sy && sy->type == J_STR ? sy->str : "");
            fn->size = sz ? (int)sz->num : 0;
            fn->unit = u;
            fn->file = -1;
            JVal *al = json_get(jf, "fold_aliases");
            if (al && al->type == J_ARR && al->n) {
                fn->aliases = xcalloc((size_t)al->n, sizeof(char *));
                for (int m = 0; m < al->n; m++)
                    if (al->items[m]->type == J_STR) fn->aliases[fn->naliases++] = xstrdup(al->items[m]->str);
            }
        }
        un->nf = g_nfuncs - un->f0;
    }
    free(txt); /* the JSON tree is left; it is small next to the rest */
}

/* ------------------------------------------------------------------ outputs */

static FILE *open_out(const char *name)
{
    char p[MAX_PATH * 2];
    snprintf(p, sizeof p, "%s\\%s", g_out, name);
    FILE *f = fopen(p, "wb");
    if (!f) die("cannot write %s", p);
    return f;
}

static const char *func_file(const Func *fn)
{
    if (fn->file >= 0) return g_files[fn->file].rel;
    if (fn->extfile) return fn->extfile;
    return "";
}

static int cmp_func_idx(const void *a, const void *b)
{
    const Func *x = &g_funcs[*(const int *)a], *y = &g_funcs[*(const int *)b];
    if (x->addr != y->addr) return x->addr < y->addr ? -1 : 1;
    if (x->unit != y->unit) return x->unit - y->unit;
    return *(const int *)a - *(const int *)b;
}

static int cmp_finding(const void *a, const void *b)
{
    const Finding *x = a, *y = b;
    const Func *fx = &g_funcs[x->func], *fy = &g_funcs[y->func];
    if (fx->addr != fy->addr) return fx->addr < fy->addr ? -1 : 1;
    if (x->func != y->func) return x->func - y->func;
    if (x->line != y->line) return x->line - y->line;
    int r = strcmp(x->rule, y->rule);
    if (r) return r;
    if (x->kind != y->kind) return x->kind - y->kind;
    return strcmp(x->excerpt, y->excerpt);
}

typedef struct {
    int unit;
    int file;
    int line;
    char *name;
    uint32_t size;
    int ref;
} Unchecked;

static Unchecked *g_unch;
static int g_nunch;
static IntVec *g_unch_by_file;

static void unchecked_sig_file(int k)
{
    int f = g_check_files[k];
    Lexed L;
    if (lex_file(g_files[f].abs, &L) != 0) return;
    for (int i = 0; i < g_unch_by_file[f].n; i++) {
        Unchecked *x = &g_unch[g_unch_by_file[f].v[i]];
        x->line = signature_line(&L, x->name, x->line);
    }
    lex_free(&L);
}

static int cmp_unchecked(const void *a, const void *b)
{
    const Unchecked *x = a, *y = b;
    if (x->unit != y->unit) return x->unit - y->unit;
    if (x->file != y->file) return strcmp(g_files[x->file].rel, g_files[y->file].rel);
    if (x->line != y->line) return x->line - y->line;
    return strcmp(x->name, y->name);
}

/* 0 adjustor thunk, 1 deleting destructor, 2 destructor, 3 other */
static int unlocated_kind(const char *s)
{
    if (strncmp(s, "??_G", 4) == 0 || strncmp(s, "??_E", 4) == 0) return 1;
    if (strncmp(s, "??1", 3) == 0) return 2;
    const char *p = strstr(s, "@@");
    if (p && (p[2] == 'W' || p[2] == 'G' || p[2] == 'O')) return 0; /* public/private/protected adjustor thunk */
    return 3;
}

static const char *kind_name(int k) { return k == 0 ? "match" : k == 1 ? "advisory" : "exception"; }

static const char *unit_module(const Unit *u)
{
    static char buf[64][MAX_PATH];
    static int slot = 0;
    char *b = buf[slot++ & 63];
    const char *s = u->source;
    if (strncmp(s, "src/", 4) != 0) {
        snprintf(b, MAX_PATH, "(other)");
        return b;
    }
    const char *slash = strchr(s + 4, '/');
    if (!slash)
        snprintf(b, MAX_PATH, "src/");
    else
        snprintf(b, MAX_PATH, "%.*s/", (int)(slash - s), s);
    return b;
}

typedef struct {
    char *name;
    long long fns, bytes, mfns, mbytes, pfns, pbytes, ufns, ubytes;
    long long unchecked, unchecked_bytes, unchecked_ref;
} ModRow;

typedef VEC(ModRow) ModVec;

static ModRow *mod_row(ModVec *rows, const char *name)
{
    for (int i = 0; i < rows->n; i++)
        if (strcmp(rows->v[i].name, name) == 0) return &rows->v[i];
    ModRow r;
    memset(&r, 0, sizeof r);
    r.name = xstrdup(name);
    VPUSH(*rows, r);
    return &rows->v[rows->n - 1];
}

static int cmp_mod(const void *a, const void *b) { return strcmp(((const ModRow *)a)->name, ((const ModRow *)b)->name); }

/* ------------------------------------------------------------------ main */

static void usage(void)
{
    fprintf(stderr, "usage: f3rules <repo> <outdir> [--jobs N] [--msvc-root DIR] [--mspdb-dir DIR] [--obj-dir DIR]\n"
                    "               [--keep-objs] [--reuse-objs] [--only TEXT]\n");
    exit(2);
}

static void to_backslash_abs(const char *in, char *out)
{
    char tmp[MAX_PATH];
    snprintf(tmp, sizeof tmp, "%s", in);
    for (char *p = tmp; *p; p++)
        if (*p == '/') *p = '\\';
    if (!GetFullPathNameA(tmp, MAX_PATH, out, NULL)) snprintf(out, MAX_PATH, "%s", tmp);
    size_t n = strlen(out);
    while (n > 3 && out[n - 1] == '\\') out[--n] = 0;
}

int main(int argc, char **argv)
{
    const char *pos[2] = {NULL, NULL};
    int npos = 0;
    char objdir_arg[MAX_PATH] = "";
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--jobs") == 0 && i + 1 < argc) g_jobs = atoi(argv[++i]);
        else if (strcmp(argv[i], "--msvc-root") == 0 && i + 1 < argc) to_backslash_abs(argv[++i], g_msvc);
        else if (strcmp(argv[i], "--mspdb-dir") == 0 && i + 1 < argc) to_backslash_abs(argv[++i], g_mspdb);
        else if (strcmp(argv[i], "--obj-dir") == 0 && i + 1 < argc) snprintf(objdir_arg, sizeof objdir_arg, "%s", argv[++i]);
        else if (strcmp(argv[i], "--keep-objs") == 0) g_keep = 1;
        else if (strcmp(argv[i], "--reuse-objs") == 0) g_reuse = g_keep = 1;
        else if (strcmp(argv[i], "--only") == 0 && i + 1 < argc) g_only = argv[++i];
        else if (argv[i][0] == '-') usage();
        else if (npos < 2) pos[npos++] = argv[i];
        else usage();
    }
    if (npos != 2) usage();
    DWORD t_start = GetTickCount();
    to_backslash_abs(pos[0], g_repo);
    to_backslash_abs(pos[1], g_out);
    CreateDirectoryA(g_out, NULL);
    if (objdir_arg[0])
        to_backslash_abs(objdir_arg, g_objdir);
    else
        snprintf(g_objdir, sizeof g_objdir, "%s\\obj", g_out);
    CreateDirectoryA(g_objdir, NULL);
    snprintf(g_repo_lower, sizeof g_repo_lower, "%s/", g_repo);
    slash_inplace(g_repo_lower);
    lower_inplace(g_repo_lower);

    /* files */
    FileVec files = {0};
    scan_dir("include", &files);
    scan_dir("src", &files);
    g_files = files.v;
    g_nfiles = files.n;
    smap_init(&g_file_by_key, (size_t)g_nfiles * 2);
    for (int i = 0; i < g_nfiles; i++) {
        char k[MAX_PATH * 2];
        snprintf(k, sizeof k, "%s", g_files[i].rel);
        lower_inplace(k);
        smap_put(&g_file_by_key, k, (void *)(intptr_t)(i + 1));
    }
    load_units();
    fprintf(stderr, "f3rules: %d units, %d functions, %d source files\n", g_nunits, g_nfuncs, g_nfiles);

    /* pass 1 */
    build_env();
    run_parallel(g_nunits, pass1_unit, "compiled");
    DWORD t1 = GetTickCount();

    /* pass 2 */
    g_fidx = xcalloc((size_t)g_nfiles, sizeof(FileIdx));
    run_parallel(g_nfiles, pass2_file, NULL);
    build_global_indexes();
    build_closures();
    DWORD t2 = GetTickCount();

    /* resolve recipe functions */
    int n_compile_fail = 0;
    for (int u = 0; u < g_nunits; u++) {
        Unit *un = &g_units[u];
        if (g_only && !strstr(un->source, g_only)) continue;
        if (!un->compile_ok) n_compile_fail++;
        StrMap m;
        smap_init(&m, (size_t)un->nobjf + 8);
        for (int i = 0; i < un->nobjf; i++)
            if (!smap_get(&m, un->objf[i].name)) smap_put(&m, un->objf[i].name, &un->objf[i]);
        for (int k = 0; k < un->nf; k++) {
            Func *fn = &g_funcs[un->f0 + k];
            if (!un->compile_ok) {
                fn->unloc = UL_COMPILE;
                continue;
            }
            UnitObjFunc *uf = smap_get(&m, fn->symbol);
            for (int a = 0; !uf && a < fn->naliases; a++) uf = smap_get(&m, fn->aliases[a]);
            if (!uf) {
                fn->unloc = UL_NOSYM;
                continue;
            }
            if (!uf->has_lines) {
                fn->unloc = UL_NOLINES;
                continue;
            }
            if (uf->file < 0) {
                fn->unloc = UL_EXTERNAL;
                fn->extfile = uf->extfile;
                fn->min_line = uf->min_line;
                fn->max_line = uf->max_line;
                continue;
            }
            fn->file = uf->file;
            fn->min_line = uf->min_line;
            fn->max_line = uf->max_line;
            fn->first_entry = uf->first_line;
        }
        smap_free(&m);
    }

    /* pass 3 */
    g_funcs_by_file = xcalloc((size_t)g_nfiles, sizeof(IntVec));
    g_file_findings = xcalloc((size_t)g_nfiles, sizeof(FindingVec));
    for (int i = 0; i < g_nfuncs; i++)
        if (g_funcs[i].file >= 0) VPUSH(g_funcs_by_file[g_funcs[i].file], i);
    g_check_files = xmalloc(sizeof(int) * (size_t)g_nfiles);
    for (int f = 0; f < g_nfiles; f++)
        if (g_funcs_by_file[f].n) g_check_files[g_ncheck_files++] = f;
    run_parallel(g_ncheck_files, pass3_file, NULL);
    DWORD t3 = GetTickCount();

    /* findings */
    FindingVec all = {0};
    for (int f = 0; f < g_nfiles; f++)
        for (int k = 0; k < g_file_findings[f].n; k++) VPUSH(all, g_file_findings[f].v[k]);
    qsort(all.v, (size_t)all.n, sizeof(Finding), cmp_finding);

    /* unchecked definitions */
    StrMap checked;
    smap_init(&checked, (size_t)g_nfuncs * 2);
    char key[2048];
    for (int u = 0; u < g_nunits; u++)
        for (int i = 0; i < g_units[u].nobjf; i++) {
            UnitObjFunc *uf = &g_units[u].objf[i];
            if (!uf->is_recipe || uf->file < 0) continue;
            snprintf(key, sizeof key, "%d|%s", uf->file, uf->name);
            smap_put(&checked, key, (void *)1);
        }
    VEC(Unchecked) unch = {0};
    StrMap seen;
    smap_init(&seen, 4096);
    for (int u = 0; u < g_nunits; u++) {
        Unit *un = &g_units[u];
        for (int i = 0; i < un->nobjf; i++) {
            UnitObjFunc *uf = &un->objf[i];
            if (uf->is_recipe || uf->file < 0 || is_generated_name(uf->name)) continue;
            SrcFile *sf = &g_files[uf->file];
            if (!sf->under_src) continue;
            if (uf->file != un->src_file && !sf->is_cpp) continue;
            snprintf(key, sizeof key, "%d|%s", uf->file, uf->name);
            if (smap_has(&checked, key)) continue;
            void **slot = smap_slot(&seen, key);
            if (*slot) {
                Unchecked *x = &unch.v[(intptr_t)*slot - 1];
                if (uf->ref_by_checked) x->ref = 1;
                continue;
            }
            Unchecked x = {u, uf->file, uf->min_line, uf->name, uf->size, uf->ref_by_checked};
            VPUSH(unch, x);
            *slot = (void *)(intptr_t)unch.n;
        }
    }
    smap_free(&seen);
    g_unch = unch.v;
    g_nunch = unch.n;
    g_unch_by_file = xcalloc((size_t)g_nfiles, sizeof(IntVec));
    for (int k = 0; k < unch.n; k++) VPUSH(g_unch_by_file[unch.v[k].file], k);
    g_ncheck_files = 0;
    for (int f = 0; f < g_nfiles; f++)
        if (g_unch_by_file[f].n) g_check_files[g_ncheck_files++] = f;
    run_parallel(g_ncheck_files, unchecked_sig_file, NULL);
    qsort(unch.v, (size_t)unch.n, sizeof(Unchecked), cmp_unchecked);

    /* functions.tsv */
    int *order = xmalloc(sizeof(int) * (size_t)(g_nfuncs + 1));
    int norder = 0;
    for (int i = 0; i < g_nfuncs; i++)
        if (!g_only || strstr(g_units[g_funcs[i].unit].source, g_only)) order[norder++] = i;
    qsort(order, (size_t)norder, sizeof(int), cmp_func_idx);
    FILE *fo = open_out("functions.tsv");
    fprintf(fo, "address\tunit\tunit_source\tsymbol\tsize\tfile\tfirst_line\tlast_line\tstatus\tmatch_rules\tadvisory_rules\n");
    for (int k = 0; k < norder; k++) {
        Func *fn = &g_funcs[order[k]];
        const char *st = fn->status == ST_MATCHED ? "MATCHED" : fn->status == ST_PENDING ? "MATCH-PENDING" : "UNLOCATED";
        fprintf(fo, "0x%08x\t%d\t%s\t%s\t%d\t%s\t%d\t%d\t%s\t%s\t%s\n", fn->addr, fn->unit, g_units[fn->unit].source,
                fn->symbol, fn->size, func_file(fn), fn->status ? fn->sig_line : fn->min_line,
                fn->status ? fn->last_line : fn->max_line, st, fn->match_rules, fn->adv_rules);
    }
    fclose(fo);

    fo = open_out("findings.tsv");
    fprintf(fo, "address\tsymbol\tfile\tline\trule\tkind\texcerpt\n");
    for (int k = 0; k < all.n; k++) {
        Finding *f = &all.v[k];
        Func *fn = &g_funcs[f->func];
        fprintf(fo, "0x%08x\t%s\t%s\t%d\t%s\t%s\t%s\n", fn->addr, fn->symbol, func_file(fn), f->line, f->rule,
                kind_name(f->kind), f->excerpt);
    }
    fclose(fo);

    fo = open_out("unchecked.tsv");
    fprintf(fo, "unit\tfile\tline\tdecorated\tsize\treferenced_by_checked\n");
    for (int k = 0; k < unch.n; k++) {
        Unchecked *x = &unch.v[k];
        fprintf(fo, "%d\t%s\t%d\t%s\t%u\t%d\n", x->unit, g_files[x->file].rel, x->line, x->name, x->size, x->ref);
    }
    fclose(fo);

    /* ---- summary ---- */
    static const char *match_rules[] = {"R1", "R2", "R4", "R13", "R17", "R18", NULL};
    static const char *adv_rules[] = {"R7", "R33", "R37", NULL};
    long long tot_f = 0, tot_b = 0, m_f = 0, m_b = 0, p_f = 0, p_b = 0, u_f = 0, u_b = 0;
    long long unloc_reason[5] = {0}, unloc_kind[5] = {0};
    ModVec mods = {0};
    VEC(int) pend_by_unit = {0};
    for (int u = 0; u < g_nunits; u++) VPUSH(pend_by_unit, 0);
    for (int k = 0; k < norder; k++) {
        Func *fn = &g_funcs[order[k]];
        ModRow *r = mod_row(&mods, unit_module(&g_units[fn->unit]));
        tot_f++;
        tot_b += fn->size;
        r->fns++;
        r->bytes += fn->size;
        if (fn->status == ST_MATCHED) {
            m_f++;
            m_b += fn->size;
            r->mfns++;
            r->mbytes += fn->size;
        } else if (fn->status == ST_PENDING) {
            p_f++;
            p_b += fn->size;
            r->pfns++;
            r->pbytes += fn->size;
            pend_by_unit.v[fn->unit]++;
        } else {
            u_f++;
            u_b += fn->size;
            r->ufns++;
            r->ubytes += fn->size;
            unloc_reason[fn->unloc < 5 ? fn->unloc : 0]++;
            unloc_kind[unlocated_kind(fn->symbol)]++;
        }
    }
    for (int k = 0; k < unch.n; k++) {
        ModRow *r = mod_row(&mods, g_files[unch.v[k].file].module);
        r->unchecked++;
        r->unchecked_bytes += unch.v[k].size;
        r->unchecked_ref += unch.v[k].ref;
    }
    qsort(mods.v, (size_t)mods.n, sizeof(ModRow), cmp_mod);

    StrBuf s = {0};
    sb_printf(&s, "# f3rules summary\n\n");
    sb_printf(&s, "Recipe: `build/units.json`, %d units, %d functions. Source: `%s`.\n\n", g_nunits, g_nfuncs, g_repo);
    sb_printf(&s, "| measure | functions | bytes |\n|---|---:|---:|\n");
    sb_printf(&s, "| bytes matched (all recipe functions; the baseline is byte exact) | %lld | %lld |\n", tot_f, tot_b);
    sb_printf(&s, "| **matched under the rules** (no [match] finding) | **%lld** | **%lld** |\n", m_f, m_b);
    sb_printf(&s, "| MATCH-PENDING (a [match] finding) | %lld | %lld |\n", p_f, p_b);
    sb_printf(&s, "| UNLOCATED (no source lines found) | %lld | %lld |\n\n", u_f, u_b);
    sb_printf(&s, "Matched under the rules: %.2f%% of functions, %.2f%% of bytes.\n\n", tot_f ? 100.0 * m_f / tot_f : 0,
              tot_b ? 100.0 * m_b / tot_b : 0);
    if (u_f) {
        sb_printf(&s, "UNLOCATED by reason: compile failed %lld, symbol not in the /Z7 object %lld, no line info %lld, "
                      "lines outside the repo %lld.\n\n",
                  unloc_reason[UL_COMPILE], unloc_reason[UL_NOSYM], unloc_reason[UL_NOLINES], unloc_reason[UL_EXTERNAL]);
        sb_printf(&s, "UNLOCATED by kind of function: adjustor thunks %lld, scalar/vector deleting destructors %lld, "
                      "destructors %lld, other %lld. The compiler generates these; the object has no source lines for "
                      "them.\n\n",
                  unloc_kind[0], unloc_kind[1], unloc_kind[2], unloc_kind[3]);
    }
    if (n_compile_fail) {
        sb_printf(&s, "Units that did not compile with /Z7: %d\n\n", n_compile_fail);
        for (int u = 0; u < g_nunits; u++)
            if (!g_units[u].compile_ok && (!g_only || strstr(g_units[u].source, g_only)))
                sb_printf(&s, "- unit %d `%s`: %s\n", u, g_units[u].source, g_units[u].compile_err);
        sb_printf(&s, "\n");
    }
    sb_printf(&s, "## Per rule\n\n| rule | kind | functions flagged | findings | exceptions |\n|---|---|---:|---:|---:|\n");
    for (int pass = 0; pass < 2; pass++) {
        const char **rules = pass ? adv_rules : match_rules;
        for (int r = 0; rules[r]; r++) {
            long long fns = 0, nf = 0, ne = 0, only = 0;
            int last = -1;
            for (int k = 0; k < all.n; k++) {
                if (strcmp(all.v[k].rule, rules[r]) != 0) continue;
                if (all.v[k].kind == 2) {
                    ne++;
                    continue;
                }
                nf++;
                if (all.v[k].func != last) {
                    fns++;
                    last = all.v[k].func;
                }
            }
            if (!pass)
                for (int k = 0; k < norder; k++) {
                    Func *fn = &g_funcs[order[k]];
                    if (fn->status == ST_PENDING && strcmp(fn->match_rules, rules[r]) == 0) only++;
                }
            if (!pass)
                sb_printf(&s, "| %s | match | %lld (only rule: %lld) | %lld | %lld |\n", rules[r], fns, only, nf, ne);
            else
                sb_printf(&s, "| %s | advisory | %lld | %lld | %lld |\n", rules[r], fns, nf, ne);
        }
    }
    sb_printf(&s, "\n## Per module (unit source `src/<dir>/`)\n\n"
                  "| module | functions | bytes | matched under rules | bytes | MATCH-PENDING | UNLOCATED | unchecked defs | "
                  "unchecked bytes | unchecked referenced |\n|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|\n");
    for (int i = 0; i < mods.n; i++) {
        ModRow *r = &mods.v[i];
        sb_printf(&s, "| `%s` | %lld | %lld | %lld | %lld | %lld | %lld | %lld | %lld | %lld |\n", r->name, r->fns,
                  r->bytes, r->mfns, r->mbytes, r->pfns, r->ufns, r->unchecked, r->unchecked_bytes, r->unchecked_ref);
    }
    long long ur = 0, ub = 0;
    for (int k = 0; k < unch.n; k++) {
        ur += unch.v[k].ref;
        ub += unch.v[k].size;
    }
    sb_printf(&s, "\nUnchecked definitions (functions with line info in a unit's own source under `src/` that no recipe "
                  "entry verifies): %d, %lld bytes of code in the /Z7 build; %lld referenced by a checked function in "
                  "the same unit.\n\n",
              unch.n, ub, ur);
    sb_printf(&s, "## Units with the most MATCH-PENDING functions\n\n| unit | source | functions | MATCH-PENDING |\n"
                  "|---:|---|---:|---:|\n");
    for (int t = 0; t < 20; t++) {
        int best = -1;
        for (int u = 0; u < g_nunits; u++)
            if (pend_by_unit.v[u] > 0 && (best < 0 || pend_by_unit.v[u] > pend_by_unit.v[best])) best = u;
        if (best < 0) break;
        sb_printf(&s, "| %d | `%s` | %d | %d |\n", best, g_units[best].source, g_units[best].nf, pend_by_unit.v[best]);
        pend_by_unit.v[best] = -1;
    }
    sb_printf(&s, "\n## Locating diagnostics\n\n- signature line not found by name (range starts at the first line entry): %ld\n"
                  "- no brace-matched body (range is the line-table range): %ld\n"
                  "- line entries past the body's closing brace (inlined later definitions): %ld\n"
                  "- functions naming a conflicted type that, in their unit, resolves to one shared include/ "
                  "definition, another namespace's type, or no visible definition (R1 not raised): %ld\n",
              g_diag_no_sig, g_diag_no_body, g_diag_past_brace, g_diag_r1_shared_only);
    fo = open_out("summary.md");
    fwrite(s.s, 1, s.n, fo);
    fclose(fo);

    if (!g_keep) RemoveDirectoryA(g_objdir); /* only succeeds when empty */
    DWORD t_end = GetTickCount();
    fprintf(stderr, "f3rules: compile+read %.1fs, index %.1fs, check %.1fs, total %.1fs\n", (t1 - t_start) / 1000.0,
            (t2 - t1) / 1000.0, (t3 - t2) / 1000.0, (t_end - t_start) / 1000.0);
    fprintf(stderr, "f3rules: %lld functions: %lld matched under the rules, %lld MATCH-PENDING, %lld UNLOCATED; %d unchecked\n",
            tot_f, m_f, p_f, u_f, unch.n);
    return 0;
}

/* f3prune - remove unchecked definitions from f3_decomp source.

   usage: f3prune defs <repo> <unchecked.tsv> <objdir> <out.tsv> --functions <functions.tsv>
                       [--only PREFIX]... [--exclude FILE] [--dry]
          f3prune decls <repo> <files.txt> <out.tsv> [--dry]
          f3prune objrefs <repo> <obj>        (debugging: each function of an object and what it relocates to)

   defs: removes the out-of-line function definitions that f3rules lists as unchecked (unchecked.tsv and
   functions.tsv of one run made with --keep-objs, so <objdir> holds u<NNNN>.obj per unit and the objects record
   <repo>'s paths) when nothing kept depends on them:
     - never a referenced_by_checked = 1 row, never a definition inside a class body, a header, or one whose text
       can't be delimited with certainty (a preprocessor line inside, a macro head, something else on its lines);
     - never a definition whose source range holds a function the objects emit that is not itself a candidate
       (a recipe function, another instantiation);
     - kept, transitively, when a kept function's code relocates to it (the /Z7 objects), and when its name
       appears in code checked functions may inline (the bodies of the definitions holding them, of every kept
       operator, constructor and destructor, and of every kept definition such code names, transitively, plus
       file-scope initializers) in the same translation-unit group (the .cpp files joined by #include "x.cpp");
     - kept: operators (called implicitly); a constructor or destructor of a class defined in a header, or named
       in kept code outside its own definition; the targets of recipe adjustor thunks; constructors, destructors
       and any body naming a class (or a class derived from one) whose deleting destructor or thunk the recipe
       checks (they emit its vftable); callers, by relocation or by name, of a recipe function emitted only when
       referenced (static, inline, in-class, template).
   Each removal takes the signature through the closing brace and the comment lines attached directly above
   (unless the definition is followed directly by kept code), leaves one blank line at the seam, and lowers a
   first-line "(N functions)" banner. <out.tsv> gets one row per unchecked row: status and reason.
   --exclude FILE: lines "file<TAB>decorated" (or just decorated) kept as they are.

   decls: second pass over the .cpp files listed in files.txt: removes file-scope extern declarations,
   prototypes and class/struct definitions (namespace scope, not in a header) whose declared name no longer
   appears anywhere else in the file or in the .cpp/.c files of its #include group. */
#include "../f3rules/util.h"
#include "../f3rules/coff.h"
#include "lexp.h"
#include "parse.h"

static char g_repo[MAX_PATH], g_repo_lower[MAX_PATH];
static int g_dry = 0;
static int g_no_banner = 0; /* decls: never touch a banner */

/* ------------------------------------------------------------------ files and include groups */

typedef struct {
    char *rel;    /* lower case, forward slashes, relative to the repo */
    char *abs;
    int group;    /* union-find parent */
    int loaded;
    PLex L;
    Parsed P;
    char *drop;   /* per line, 1 = delete (defs mode) */
    int removed_defs;
    int removed_tags;
} File;

static VEC(File) g_files;
static StrMap g_file_by_rel;

static int find_root(int f)
{
    while (g_files.v[f].group != f) {
        g_files.v[f].group = g_files.v[g_files.v[f].group].group;
        f = g_files.v[f].group;
    }
    return f;
}

static void unite(int a, int b)
{
    a = find_root(a);
    b = find_root(b);
    if (a != b) g_files.v[b].group = a;
}

static int ends_with(const char *s, const char *suf)
{
    size_t a = strlen(s), b = strlen(suf);
    return a >= b && strcmp(s + a - b, suf) == 0;
}

static int is_cfile(const char *rel) { return ends_with(rel, ".cpp") || ends_with(rel, ".c"); }

static void norm_path(const char *in, char *out, size_t cap)
{
    char buf[1024];
    snprintf(buf, sizeof buf, "%s", in);
    slash_inplace(buf);
    lower_inplace(buf);
    size_t k = 0;
    for (char *p = buf; *p && k + 1 < cap;) {
        if (strncmp(p, "../", 3) == 0 && k > 0) {
            if (out[k - 1] == '/') k--;
            while (k > 0 && out[k - 1] != '/') k--;
            p += 3;
            continue;
        }
        if (strncmp(p, "./", 2) == 0 && (k == 0 || out[k - 1] == '/')) {
            p += 2;
            continue;
        }
        out[k++] = *p++;
    }
    out[k] = 0;
}

static int add_file(const char *rel)
{
    void **slot = smap_slot(&g_file_by_rel, rel);
    if (*slot) return (int)(intptr_t)*slot - 1;
    File f;
    memset(&f, 0, sizeof f);
    f.rel = xstrdup(rel);
    char abs[MAX_PATH];
    snprintf(abs, sizeof abs, "%s/%s", g_repo, rel);
    f.abs = xstrdup(abs);
    f.group = g_files.n;
    VPUSH(g_files, f);
    *slot = (void *)(intptr_t)g_files.n;
    return g_files.n - 1;
}

static void scan_dir(const char *rel_dir)
{
    char pat[MAX_PATH];
    snprintf(pat, sizeof pat, "%s/%s/*", g_repo, rel_dir);
    WIN32_FIND_DATAA fd;
    HANDLE h = FindFirstFileA(pat, &fd);
    if (h == INVALID_HANDLE_VALUE) return;
    do {
        if (fd.cFileName[0] == '.') continue;
        char rel[MAX_PATH];
        snprintf(rel, sizeof rel, "%s/%s", rel_dir, fd.cFileName);
        lower_inplace(rel);
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            scan_dir(rel);
        else if (is_cfile(rel))
            add_file(rel);
    } while (FindNextFileA(h, &fd));
    FindClose(h);
}

/* joins each .cpp/.c with the .cpp/.c files it includes */
static void build_groups(void)
{
    scan_dir("src");
    int n = g_files.n;
    for (int f = 0; f < n; f++) {
        size_t len;
        char *t = read_file(g_files.v[f].abs, &len);
        if (!t) continue;
        char dir[MAX_PATH];
        snprintf(dir, sizeof dir, "%s", g_files.v[f].rel);
        char *sl = strrchr(dir, '/');
        if (sl) *sl = 0;
        for (char *p = t; (p = strstr(p, "#include")) != NULL; p += 8) {
            char *q = p + 8;
            while (*q == ' ' || *q == '\t') q++;
            if (*q != '"') continue;
            char *e = strchr(q + 1, '"');
            if (!e || e - q > 400) continue;
            char inc[512];
            snprintf(inc, sizeof inc, "%.*s", (int)(e - q - 1), q + 1);
            lower_inplace(inc);
            if (!is_cfile(inc)) continue;
            char joined[1024], rel[1024];
            snprintf(joined, sizeof joined, "%s/%s", dir, inc);
            norm_path(joined, rel, sizeof rel);
            void *v = smap_get(&g_file_by_rel, rel);
            if (v) unite(f, (int)(intptr_t)v - 1);
        }
        free(t);
    }
}

static File *load(int f)
{
    File *F = &g_files.v[f];
    if (!F->loaded) {
        F->loaded = 1;
        if (plex_file(F->abs, &F->L) == 0) {
            parse_file(&F->L, &F->P);
        } else {
            F->loaded = 2;
        }
    }
    return F;
}

/* ------------------------------------------------------------------ decorated names */

enum { EX_NAME, EX_CTOR, EX_DTOR, EX_OP, EX_C };

static int expect_name(const char *dec, char *name, size_t cap)
{
    if (dec[0] == '?') {
        const char *p = dec + 1;
        int kind = EX_NAME;
        if (p[0] == '?') {
            if (p[1] == '$') {
                p += 2;
            } else if (p[1] == '0') {
                kind = EX_CTOR;
                p += 2;
            } else if (p[1] == '1') {
                kind = EX_DTOR;
                p += 2;
            } else {
                snprintf(name, cap, "operator");
                return EX_OP;
            }
        } else if (p[0] == '$') {
            p += 1;
        }
        if (p[0] == '?' && p[1] == '$') p += 2; /* a class template's name */
        const char *e = strchr(p, '@');
        if (!e) e = p + strlen(p);
        snprintf(name, cap, "%.*s", (int)(e - p), p);
        return kind;
    }
    const char *p = dec;
    if (*p == '_' || *p == '@') p++;
    const char *e = strchr(p, '@');
    if (!e) e = p + strlen(p);
    snprintf(name, cap, "%.*s", (int)(e - p), p);
    return EX_C;
}

static int name_matches(const Def *d, const char *dec)
{
    char nm[256];
    int k = expect_name(dec, nm, sizeof nm);
    switch (k) {
    case EX_OP: return d->is_operator;
    case EX_DTOR: return d->is_dtor && !d->is_operator && strcmp(d->name_s, nm) == 0;
    case EX_CTOR:
    case EX_NAME: return !d->is_dtor && !d->is_operator && strcmp(d->name_s, nm) == 0;
    default: return !d->is_dtor && !d->is_operator && (strcmp(d->name_s, nm) == 0 || strcmp(d->name_s, dec) == 0);
    }
}

static int is_generated_name(const char *s)
{
    if (strncmp(s, "??_", 3) == 0 && s[3] != 'U' && s[3] != 'V') return 1;
    if (strncmp(s, "??__", 4) == 0) return 1;
    if (s[0] != '?' && strchr(s, '$')) return 1;
    if (strncmp(s, "__ehhandler$", 12) == 0 || strncmp(s, "__unwindfunclet$", 16) == 0) return 1;
    return 0;
}

/* a function that is no class member: its definition may be its only declaration */
/* the end of a decorated name's qualified name: the "@@" (or "@<digit>@", a back-reference closing the scope list)
   followed by its access/type code; returns the code's position or NULL */
static const char *dec_scope_end(const char *dec, int *termlen)
{
    for (const char *p = dec + 1; *p; p++) {
        if (p[0] == '@' && p[1] == '@' && isupper((unsigned char)p[2])) {
            *termlen = 2;
            return p;
        }
        if (p[0] == '@' && isdigit((unsigned char)p[1]) && p[2] == '@' && isupper((unsigned char)p[3])) {
            *termlen = 3;
            return p;
        }
    }
    return NULL;
}

static int is_free_function(const char *dec)
{
    if (dec[0] != '?') return 1;
    int tl;
    const char *p = dec_scope_end(dec, &tl);
    return p && (p[tl] == 'Y' || p[tl] == 'Z');
}

/* the decorated name up to and including the terminator before its access/type code; *code gets that code */
static int dec_prefix(const char *dec, char *out, size_t cap, char *code)
{
    int tl;
    const char *p = dec_scope_end(dec, &tl);
    if (!p) return 0;
    snprintf(out, cap, "%.*s", (int)(p - dec + tl), dec);
    if (code) *code = p[tl];
    return 1;
}

/* ------------------------------------------------------------------ candidates */

enum {
    ST_REMOVE = 0,
    ST_REF_CHECKED,     /* referenced_by_checked = 1 */
    ST_REF_KEPT,        /* a kept function's code refers to it (objects) */
    ST_NAMED_KEPT,      /* its name appears in a kept body or initializer of its include group */
    ST_HOLDS_KEPT,      /* its definition also emits a function that is kept */
    ST_IN_CLASS,        /* inside a class body (or a function) */
    ST_NO_DEF,          /* no definition at the line (macro-produced or not delimited) */
    ST_NAME_MISMATCH,   /* the definition at the line has another name */
    ST_BAD_DIRECTIVE,
    ST_BAD_PREFIX,
    ST_BAD_LINE,
    ST_BAD_FILE,        /* unbalanced braces or #if in the file */
    ST_OUTSIDE,         /* not in this batch (--only) */
    ST_EXCLUDED,        /* --exclude */
    ST_NOT_CFILE,
    ST_OPERATOR,        /* an operator: called implicitly, so no name check can see its uses */
    ST_THUNK_TARGET,    /* a recipe adjustor thunk jumps to it */
    ST_VTABLE_CLASS,    /* ctor/dtor of a class whose deleting destructor or adjustor thunk the recipe checks */
    ST_CLASS_USED,      /* ctor/dtor of a class kept code names outside the class's own definition */
    ST_VTABLE_USER,     /* names a class whose vftable code the recipe checks (it may be what emits it) */
    ST_KEEPS_ALIVE,     /* calls a checked function that is only emitted when referenced (static, inline, header) */
    ST_CLASS_IN_HEADER, /* ctor/dtor of a class defined in a header: header code may construct it implicitly */
    ST_TEMPLATE_USED,   /* a template whose name kept code (a specialization, a use) still spells */
    ST_N
};

static const char *st_name[ST_N] = {
    "removed", "kept:referenced_by_checked", "kept:referenced_by_kept_code", "kept:named_in_kept_code",
    "kept:definition_holds_kept_function", "skip:in_class_body", "skip:no_definition_at_line",
    "skip:name_mismatch", "skip:preprocessor_inside", "skip:macro_or_unusual_head", "skip:shares_a_line",
    "skip:file_unbalanced", "skip:outside_batch", "skip:excluded", "skip:not_a_cpp_file",
    "kept:operator_implicit_use", "kept:target_of_checked_thunk", "kept:ctor_dtor_of_class_with_checked_vtable_code", "kept:ctor_dtor_of_class_named_in_kept_code", "kept:names_class_with_checked_vtable_code", "kept:caller_of_checked_internal_function", "kept:ctor_dtor_of_class_defined_in_a_header",
    "kept:template_named_in_kept_code"};

typedef struct {
    int unit;
    int file;
    int line;
    char *dec;
    uint32_t size;
    int ref;
    int def;      /* index into the file's defs, -1 */
    int status;
} Cand;

static VEC(Cand) g_c;
static StrMap g_recipe; /* "unit|decorated" of every recipe function */
static StrMap *g_NR;     /* per group: names of recipe functions emitted only when referenced (static, inline) */
static StrMap g_cand_by_key; /* "file|decorated" -> index+1 */

typedef struct {
    int state;    /* ST_REMOVE while removable, else the keep/skip reason */
    int ncand;
    char seed;    /* holds a kept function the objects emit (a recipe function, a referenced row) */
    char in_s, in_a;
} DefInfo;

static DefInfo **g_definfo; /* per file, per def */

static DefInfo *definfo(int f, int d)
{
    if (!g_definfo[f]) {
        File *F = load(f);
        g_definfo[f] = xcalloc((size_t)F->P.ndefs + 1, sizeof(DefInfo));
        for (int i = 0; i < F->P.ndefs; i++) g_definfo[f][i].state = -1; /* not a candidate definition */
    }
    return &g_definfo[f][d];
}

/* innermost definition whose span holds the line */
static int def_at(File *F, int line)
{
    int best = -1;
    for (int i = 0; i < F->P.ndefs; i++) {
        Def *d = &F->P.defs[i];
        if (d->first_line <= line && line <= d->last_line) {
            if (best < 0 || d->depth > F->P.defs[best].depth) best = i;
        }
    }
    return best;
}

/* ------------------------------------------------------------------ identifiers in kept code, per group */

/* per group root: S, identifiers of the code kept functions may inline (bodies of the definitions that hold a
   kept function the objects emit, and of every kept definition S names, transitively, and file-scope
   initializers); A, identifiers of every kept body (a free function named there needs its declaration) */
static StrMap *g_S, *g_A;

static void add_idents(StrMap *m, File *F, int a, int b)
{
    if (!m->cap) smap_init(m, 1024);
    char buf[512];
    for (int j = a; j <= b && j < F->L.ntoks; j++) {
        PTok *t = &F->L.toks[j];
        if (t->type != P_IDENT || t->len >= 200) continue;
        memcpy(buf, F->L.text + t->off, (size_t)t->len);
        buf[t->len] = 0;
        smap_put(m, buf, (void *)1);
    }
}

/* S keys: "name" for an unqualified mention or a member access, "Q::name" and "::name" for a qualified one */
static void add_mentions(StrMap *m, File *F, int a, int b)
{
    if (!m->cap) smap_init(m, 1024);
    char buf[512];
    for (int j = a; j <= b && j < F->L.ntoks; j++) {
        PTok *t = &F->L.toks[j];
        if (t->type != P_IDENT || t->len >= 200) continue;
        int k = j - 1;
        if (k >= a && ptk_eq(&F->L, k, "~")) k--;
        if (k >= a && ptk_eq(&F->L, k, "::") && k - 1 >= a && F->L.toks[k - 1].type == P_IDENT && F->L.toks[k - 1].len < 200) {
            PTok *q = &F->L.toks[k - 1];
            snprintf(buf, sizeof buf, "%.*s::%.*s", q->len, F->L.text + q->off, t->len, F->L.text + t->off);
            smap_put(m, buf, (void *)1);
            snprintf(buf, sizeof buf, "::%.*s", t->len, F->L.text + t->off);
            smap_put(m, buf, (void *)1);
            continue;
        }
        memcpy(buf, F->L.text + t->off, (size_t)t->len);
        buf[t->len] = 0;
        smap_put(m, buf, (void *)1);
    }
}

static void count_idents(StrMap *m, File *F, int a, int b, int sign)
{
    if (!m->cap) smap_init(m, 1024);
    char buf[256];
    for (int j = a; j <= b && j < F->L.ntoks; j++) {
        PTok *t = &F->L.toks[j];
        if (t->type != P_IDENT || t->len >= 200) continue;
        memcpy(buf, F->L.text + t->off, (size_t)t->len);
        buf[t->len] = 0;
        void **v = smap_slot(m, buf);
        *v = (void *)((intptr_t)*v + sign);
    }
}

static intptr_t count_of(StrMap *m, const char *k)
{
    if (!m->cap) return 0;
    return (intptr_t)smap_get(m, k);
}

/* the name a class statement defines: the identifier after class/struct/union (skipping __declspec(...)) */
static int class_stmt_name(File *F, Stmt *sm, char *out, size_t cap)
{
    PLex *L = &F->L;
    for (int j = sm->first; j < sm->class_body; j++) {
        if (ptk_eq(L, j, "class") || ptk_eq(L, j, "struct") || ptk_eq(L, j, "union")) {
            int k = j + 1;
            while (k < sm->class_body) {
                if (ptk_eq(L, k, "__declspec") && ptk_eq(L, k + 1, "(")) {
                    int d = 0;
                    for (; k < sm->class_body; k++) {
                        if (ptk_eq(L, k, "(")) d++;
                        else if (ptk_eq(L, k, ")") && --d == 0) break;
                    }
                    k++;
                    continue;
                }
                break;
            }
            if (k < sm->class_body && L->toks[k].type == P_IDENT) {
                snprintf(out, cap, "%.*s", L->toks[k].len, L->text + L->toks[k].off);
                return 1;
            }
            return 0;
        }
    }
    return 0;
}

/* the scope component after the name in a decorated name ("Class" in ?Name@Class@@...), or "" */
static void dec_qualifier(const char *dec, char *out, size_t cap)
{
    out[0] = 0;
    if (dec[0] != '?') return;
    const char *p = dec + 1;
    if (p[0] == '?') p += (p[1] == '$') ? 2 : 2;
    else if (p[0] == '$') p++;
    if (p[0] == '?' && p[1] == '$') p += 2;
    const char *e = strchr(p, '@');
    if (!e || e[1] == '@') return;
    p = e + 1;
    if (p[0] == '?' && p[1] == '$') p += 2;
    e = strchr(p, '@');
    if (!e) return;
    snprintf(out, cap, "%.*s", (int)(e - p), p);
}

static int s_names(StrMap *m, const char *name)
{
    if (!m->cap) return 0;
    char k[600];
    if (smap_has(m, name)) return 1;
    snprintf(k, sizeof k, "::%s", name);
    return smap_has(m, k);
}

static int s_names_cand(StrMap *m, const char *name, const char *qual)
{
    if (!m->cap) return 0;
    if (smap_has(m, name)) return 1;
    if (!qual[0]) return 0;
    char k[600];
    snprintf(k, sizeof k, "%s::%s", qual, name);
    return smap_has(m, k);
}

static int def_check_name(const Def *d, char *out, size_t cap)
{
    if (d->is_operator) return 0;
    snprintf(out, cap, "%s", d->name_s);
    return 1;
}

/* ------------------------------------------------------------------ writing */

static int is_tag_line(const char *s, int len)
{
    char buf[256];
    snprintf(buf, sizeof buf, "%.*s", len < 255 ? len : 255, s);
    const char *p = buf;
    while (*p == ' ' || *p == '\t') p++;
    if (p[0] != '/' || p[1] != '/') return 0;
    return strstr(p, "@fnv 0x") || strstr(p, "@f3 0x");
}

/* writes the file without its dropped lines. At a seam (where lines were dropped) a blank line that follows a blank
   line already written is not written; a seam at the end of the file takes the blank lines before it. A first-line
   banner "(N functions)" counts the @fnv/@f3 tags, so it loses the tags dropped. */
static void write_file(File *F)
{
    PLex *L = &F->L;
    int n = L->nlines;
    int tags = 0;
    for (int l = 1; l <= n; l++)
        if (F->drop[l] && is_tag_line(L->text + L->line_off[l - 1], L->line_off[l] - L->line_off[l - 1])) tags++;
    if (g_no_banner) tags = 0;
    F->removed_tags = tags;
    if (g_dry) return;
    StrBuf out = {0};
    int seam = 0, last_blank = 0;
    size_t before_trailing_blanks = 0; /* output length before the trailing run of blank lines */
    for (int l = 1; l <= n; l++) {
        if (F->drop[l]) {
            seam = 1;
            continue;
        }
        const char *s = L->text + L->line_off[l - 1];
        int len = L->line_off[l] - L->line_off[l - 1];
        int blank = line_blank(L, l);
        if (seam && blank && last_blank) continue;
        if (!blank) seam = 0;
        if (l == 1 && tags) {
            char line1[4096];
            snprintf(line1, sizeof line1, "%.*s", len < 4000 ? len : 4000, s);
            char *p = strstr(line1, " functions)");
            if (!p) p = strstr(line1, " function)");
            if (p && line1[0] == '/' && line1[1] == '/') {
                char *q = p;
                while (q > line1 && isdigit((unsigned char)q[-1])) q--;
                if (q < p && q > line1 && q[-1] == '(') {
                    int cnt = atoi(q) - tags;
                    if (cnt < 0) cnt = 0;
                    char nb[4200];
                    const char *rest = strchr(p, ')');
                    snprintf(nb, sizeof nb, "%.*s%d %s%s", (int)(q - line1), line1, cnt,
                             cnt == 1 ? "function" : "functions", rest);
                    if (!blank) before_trailing_blanks = out.n + strlen(nb);
                    sb_adds(&out, nb);
                    last_blank = 0;
                    continue;
                }
            }
        }
        sb_add(&out, s, (size_t)len);
        if (!blank) before_trailing_blanks = out.n;
        last_blank = blank;
    }
    if (seam) {
        /* the file ended in a seam: drop the blank lines before it, keep the final newline */
        out.n = before_trailing_blanks;
    }
    FILE *fo = fopen(F->abs, "wb");
    if (!fo) die("cannot write %s", F->abs);
    fwrite(out.s, 1, out.n, fo);
    fclose(fo);
    free(out.s);
}

/* ------------------------------------------------------------------ defs mode */

static int is_comment_only(const PLex *L, int line) { return L->line_comment[line] && !L->line_code[line]; }

static int cmd_defs(int argc, char **argv)
{
    if (argc < 6) die("usage: f3prune defs <repo> <unchecked.tsv> <objdir> <out.tsv> [--only P]... [--exclude F] [--dry]");
    const char *tsv = argv[3], *objdir = argv[4], *outp = argv[5];
    VEC(char *) only = {0};
    const char *functions_tsv = NULL;
    StrMap excl;
    smap_init(&excl, 64);
    for (int i = 6; i < argc; i++) {
        if (strcmp(argv[i], "--only") == 0 && i + 1 < argc) {
            char *s = xstrdup(argv[++i]);
            lower_inplace(s);
            VPUSH(only, s);
        } else if (strcmp(argv[i], "--exclude") == 0 && i + 1 < argc) {
            size_t n;
            char *t = read_file(argv[++i], &n);
            if (!t) die("cannot read %s", argv[i]);
            for (char *ln = strtok(t, "\r\n"); ln; ln = strtok(NULL, "\r\n")) {
                if (!*ln || *ln == '#') continue;
                char *tab = strchr(ln, '\t');
                char key[2048];
                if (tab) {
                    *tab = 0;
                    char r[1024];
                    snprintf(r, sizeof r, "%s", ln);
                    lower_inplace(r);
                    snprintf(key, sizeof key, "%s|%s", r, tab + 1);
                } else
                    snprintf(key, sizeof key, "*|%s", ln);
                smap_put(&excl, key, (void *)1);
            }
        } else if (strcmp(argv[i], "--functions") == 0 && i + 1 < argc) {
            functions_tsv = argv[++i];
        } else if (strcmp(argv[i], "--dry") == 0)
            g_dry = 1;
        else
            die("unknown option %s", argv[i]);
    }
    /* recipe adjustor thunks and deleting destructors (f3rules functions.tsv): their targets must stay */
    StrMap thunk_pref, vt_class;
    smap_init(&thunk_pref, 1024);
    smap_init(&vt_class, 1024);
    smap_init(&g_recipe, 1 << 17);
    if (!functions_tsv) die("--functions <functions.tsv> is required");
    {
        size_t n;
        char *ft = read_file(functions_tsv, &n);
        if (!ft) die("cannot read %s", functions_tsv);
        char *sv = NULL;
        for (char *ln = strtok_s(ft, "\n", &sv); ln; ln = strtok_s(NULL, "\n", &sv)) {
            char *c = ln;
            char *unit_col = NULL;
            for (int k = 0; k < 3 && c; k++) {
                c = strchr(c, '\t');
                if (c) c++;
                if (k == 0) unit_col = c;
            }
            if (!c) continue;
            char *e = strchr(c, '\t');
            if (e) *e = 0;
            {
                char rk[2048];
                snprintf(rk, sizeof rk, "%d|%s", unit_col ? atoi(unit_col) : -1, c);
                smap_put(&g_recipe, rk, (void *)1);
            }
            char pre[2048], code = 0;
            if (strncmp(c, "??_G", 4) == 0 || strncmp(c, "??_E", 4) == 0) {
                if (dec_prefix(c + 4, pre, sizeof pre, &code)) smap_put(&vt_class, pre, (void *)1);
                else {
                    const char *at = strchr(c + 4, '@');
                    if (at) {
                        snprintf(pre, sizeof pre, "%.*s@@", (int)(at - (c + 4)), c + 4);
                        smap_put(&vt_class, pre, (void *)1);
                    }
                }
            } else if (c[0] == '?' && c[1] != '?' && dec_prefix(c, pre, sizeof pre, &code) && strchr("GHOPWX", code)) {
                smap_put(&thunk_pref, pre, (void *)1);
                /* the thunk is emitted with its class's vftable: "?Name@Class@@" -> "Class@@" */
                const char *at = strchr(pre + 1, '@');
                if (at && at[1] != '@') smap_put(&vt_class, at + 1, (void *)1);
            }
        }
        free(ft);
    }
    StrMap vt_names; /* innermost class names of vt_class */
    smap_init(&vt_names, 1024);
    for (size_t k = 0; k < vt_class.cap; k++) {
        if (!vt_class.hashes[k]) continue;
        const char *key = vt_class.keys[k];
        if (key[0] == '?' && key[1] == '$') key += 2;
        const char *e = strchr(key, '@');
        char nm[512];
        snprintf(nm, sizeof nm, "%.*s", e ? (int)(e - key) : (int)strlen(key), key);
        smap_put(&vt_names, nm, (void *)1);
    }
    smap_init(&g_file_by_rel, 8192);
    build_groups();

    /* candidates */
    size_t tn;
    char *t = read_file(tsv, &tn);
    if (!t) die("cannot read %s", tsv);
    smap_init(&g_cand_by_key, 200000);
    char *save = NULL;
    int first = 1;
    for (char *ln = strtok_s(t, "\n", &save); ln; ln = strtok_s(NULL, "\n", &save)) {
        if (first) {
            first = 0;
            continue;
        }
        char *col[6];
        int nc = 0;
        char *p = ln;
        col[nc++] = p;
        while (*p && nc < 6) {
            if (*p == '\t') {
                *p = 0;
                col[nc++] = p + 1;
            }
            p++;
        }
        if (nc < 6) continue;
        char *cr = strchr(col[5], '\r');
        if (cr) *cr = 0;
        char rel[1024];
        snprintf(rel, sizeof rel, "%s", col[1]);
        lower_inplace(rel);
        Cand c;
        c.unit = atoi(col[0]);
        c.file = add_file(rel);
        c.line = atoi(col[2]);
        c.dec = xstrdup(col[3]);
        c.size = (uint32_t)strtoul(col[4], NULL, 10);
        c.ref = atoi(col[5]);
        c.def = -1;
        c.status = ST_REMOVE;
        VPUSH(g_c, c);
        char key[2048];
        snprintf(key, sizeof key, "%s|%s", rel, c.dec);
        smap_put(&g_cand_by_key, key, (void *)(intptr_t)g_c.n);
    }
    free(t);
    g_definfo = xcalloc((size_t)g_files.n + 1, sizeof(DefInfo *));
    g_S = xcalloc((size_t)g_files.n + 1, sizeof(StrMap));
    g_A = xcalloc((size_t)g_files.n + 1, sizeof(StrMap));

    /* classes derived (transitively) from a class with checked vftable code: building one emits that code too */
    for (int i = 0; i < g_c.n; i++) load(g_c.v[i].file);
    for (int round = 0, grew = 1; grew && round < 50; round++) {
        grew = 0;
        for (int f = 0; f < g_files.n; f++) {
            File *F = &g_files.v[f];
            if (F->loaded != 1) continue;
            for (int k = 0; k < F->P.nstmts; k++) {
                Stmt *sm = &F->P.stmts[k];
                char nm[256];
                if (sm->class_body < 0 || !class_stmt_name(F, sm, nm, sizeof nm) || smap_has(&vt_names, nm)) continue;
                int colon = -1;
                for (int j = sm->first; j < sm->class_body; j++)
                    if (ptk_eq(&F->L, j, ":")) {
                        colon = j;
                        break;
                    }
                if (colon < 0) continue;
                for (int j = colon + 1; j < sm->class_body; j++) {
                    PTok *tk = &F->L.toks[j];
                    if (tk->type != P_IDENT || tk->len > 200) continue;
                    char b[256];
                    snprintf(b, sizeof b, "%.*s", tk->len, F->L.text + tk->off);
                    if (smap_has(&vt_names, b)) {
                        smap_put(&vt_names, nm, (void *)1);
                        grew = 1;
                        break;
                    }
                }
            }
        }
    }

    /* first classification: by row and by definition */
    for (int i = 0; i < g_c.n; i++) {
        Cand *c = &g_c.v[i];
        File *F = &g_files.v[c->file];
        char key[2048];
        if (c->ref) {
            c->status = ST_REF_CHECKED;
        } else if (!is_cfile(F->rel)) {
            c->status = ST_NOT_CFILE;
        } else {
            int in = only.n == 0;
            for (int k = 0; k < only.n && !in; k++)
                if (strncmp(F->rel, only.v[k], strlen(only.v[k])) == 0) in = 1;
            snprintf(key, sizeof key, "%s|%s", F->rel, c->dec);
            char key2[2048];
            snprintf(key2, sizeof key2, "*|%s", c->dec);
            if (!in) c->status = ST_OUTSIDE;
            else if (smap_has(&excl, key) || smap_has(&excl, key2)) c->status = ST_EXCLUDED;
        }
        load(c->file);
        if (F->loaded != 1) {
            if (c->status == ST_REMOVE) c->status = ST_BAD_FILE;
            continue;
        }
        int d = def_at(F, c->line);
        c->def = d;
        if (c->status != ST_REMOVE) continue;
        if (F->P.unbalanced) {
            c->status = ST_BAD_FILE;
            continue;
        }
        if (d < 0) {
            c->status = ST_NO_DEF;
            continue;
        }
        Def *df = &F->P.defs[d];
        if (df->parent != SK_TOP && df->parent != SK_NS && df->parent != SK_EXTC) c->status = ST_IN_CLASS;
        else if (!name_matches(df, c->dec)) c->status = ST_NAME_MISMATCH;
        else if (df->bad == DB_DIRECTIVE) c->status = ST_BAD_DIRECTIVE;
        else if (df->bad == DB_PREFIX || df->bad == DB_TRY) c->status = ST_BAD_PREFIX;
        else if (df->bad) c->status = ST_BAD_LINE;
        else if (df->is_operator) c->status = ST_OPERATOR;
        else {
            char pre[2048], code = 0;
            if (c->dec[0] == '?' && c->dec[1] != '?' && dec_prefix(c->dec, pre, sizeof pre, &code) && smap_has(&thunk_pref, pre))
                c->status = ST_THUNK_TARGET;
            else if ((strncmp(c->dec, "??0", 3) == 0 || strncmp(c->dec, "??1", 3) == 0) &&
                     ((dec_prefix(c->dec + 3, pre, sizeof pre, &code) && smap_has(&vt_class, pre)) ||
                      smap_has(&vt_names, df->name_s)))
                c->status = ST_VTABLE_CLASS;
            else {
                /* a body that names such a class may be what instantiates its vftable */
                for (int j = df->head; j <= df->endtok; j++) {
                    PTok *tk = &F->L.toks[j];
                    if (tk->type != P_IDENT || tk->len > 200) continue;
                    char nm[256];
                    snprintf(nm, sizeof nm, "%.*s", tk->len, F->L.text + tk->off);
                    if (smap_has(&vt_names, nm)) {
                        c->status = ST_VTABLE_USER;
                        break;
                    }
                }
            }
        }
    }
    /* a definition is removable only if every row mapped to it is */
    for (int i = 0; i < g_c.n; i++) {
        Cand *c = &g_c.v[i];
        if (c->def < 0) continue;
        DefInfo *di = definfo(c->file, c->def);
        if (di->state == -1) di->state = ST_REMOVE;
        di->ncand++;
        if (c->status != ST_REMOVE && di->state == ST_REMOVE) di->state = c->status;
    }

    /* objects: roots, edges, functions defined inside candidate definitions */
    VEC(int) efrom = {0};
    VEC(int) eto = {0};
    char *rootref = xcalloc((size_t)g_c.n + 1, 1);
    char *keepalive = xcalloc((size_t)g_c.n + 1, 1);
    g_NR = xcalloc((size_t)g_files.n + 1, sizeof(StrMap));
    for (int u = 0; u < 10000; u++) {
        char obj[MAX_PATH];
        snprintf(obj, sizeof obj, "%s/u%04d.obj", objdir, u);
        if (GetFileAttributesA(obj) == INVALID_FILE_ATTRIBUTES) continue;
        ObjInfo oi;
        char err[256];
        if (coff_read(obj, &oi, err, sizeof err) != 0) {
            fprintf(stderr, "f3prune: %s: %s\n", obj, err);
            continue;
        }
        StrMap local;
        smap_init(&local, (size_t)oi.n * 2 + 8);
        int *role = xcalloc((size_t)oi.n + 1, sizeof(int)); /* cand index+1, 0 root, -1 ignore */
        char *needref = xcalloc((size_t)oi.n + 1, 1);       /* a recipe function emitted only when referenced */
        for (int i = 0; i < oi.n; i++) {
            ObjFunc *of = &oi.funcs[i];
            smap_put(&local, of->name, (void *)(intptr_t)(i + 1));
            role[i] = 0;
            int fidx = -1;
            if (of->file) {
                char np[1024];
                norm_path(of->file, np, sizeof np);
                size_t rl = strlen(g_repo_lower);
                if (strncmp(np, g_repo_lower, rl) == 0 && np[rl] == '/') {
                    void *v = smap_get(&g_file_by_rel, np + rl + 1);
                    if (v) fidx = (int)(intptr_t)v - 1;
                }
            }
            if (fidx >= 0) {
                char key[2048];
                snprintf(key, sizeof key, "%s|%s", g_files.v[fidx].rel, of->name);
                void *v = smap_get(&g_cand_by_key, key);
                if (v && !g_c.v[(intptr_t)v - 1].ref) {
                    role[i] = (int)(intptr_t)v;
                    continue;
                }
            }
            if (is_generated_name(of->name)) {
                role[i] = -1;
                continue;
            }
            char rk[2048];
            snprintf(rk, sizeof rk, "%d|%s", u, of->name);
            int is_recipe = smap_has(&g_recipe, rk);
            if (is_recipe) needref[i] = 1; /* until its definition shows external linkage */
            /* a kept function: mark the candidate definition that holds its first line */
            if (fidx >= 0 && g_definfo && is_cfile(g_files.v[fidx].rel)) {
                File *F = load(fidx);
                if (F->loaded == 1) {
                    int d = def_at(F, of->min_line);
                    if (d >= 0) {
                        DefInfo *di = definfo(fidx, d);
                        if (di->state == ST_REMOVE) di->state = ST_HOLDS_KEPT;
                        di->seed = 1;
                        Def *df = &F->P.defs[d];
                        if (is_recipe && !df->is_static && !df->is_inline && !df->is_template &&
                            (df->parent == SK_TOP || df->parent == SK_NS || df->parent == SK_EXTC))
                            needref[i] = 0;
                        if (needref[i] && !df->is_operator) {
                            int grp = find_root(fidx);
                            if (!g_NR[grp].cap) smap_init(&g_NR[grp], 64);
                            smap_put(&g_NR[grp], df->name_s, (void *)1);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < oi.n; i++) {
            if (role[i] < 0) continue;
            ObjFunc *of = &oi.funcs[i];
            for (int r = 0; r < of->nrefs; r++) {
                void *v = smap_get(&local, of->refs[r]);
                if (!v) continue;
                int j = (int)(intptr_t)v - 1;
                if (role[j] == 0 && needref[j] && role[i] > 0) keepalive[role[i] - 1] = 1;
                if (role[j] <= 0) continue;
                int to = role[j] - 1;
                if (role[i] == 0)
                    rootref[to] = 1;
                else if (role[i] - 1 != to) {
                    VPUSH(efrom, role[i] - 1);
                    VPUSH(eto, to);
                }
            }
        }
        free(role);
        free(needref);
        smap_free(&local);
        coff_free(&oi);
    }

    /* propagation: a kept candidate keeps what it refers to; a kept definition keeps all its rows;
       names in kept code keep the definitions they name */
    char *kept = xcalloc((size_t)g_c.n + 1, 1);
    for (int i = 0; i < g_c.n; i++) {
        Cand *c = &g_c.v[i];
        if (c->ref) continue;
        if (rootref[i] && c->status == ST_REMOVE) c->status = ST_REF_KEPT;
        if (keepalive[i] && c->status == ST_REMOVE) c->status = ST_KEEPS_ALIVE;
        /* a caller that inlined such a function still keeps it emitted: names count, not just relocations */
        if (c->status == ST_REMOVE && c->def >= 0) {
            File *F = &g_files.v[c->file];
            StrMap *nr = &g_NR[find_root(c->file)];
            Def *df = &F->P.defs[c->def];
            if (nr->cap)
                for (int j = df->body_from; j <= df->endtok; j++) {
                    PTok *tk = &F->L.toks[j];
                    if (tk->type != P_IDENT || tk->len > 200) continue;
                    char nm[256];
                    snprintf(nm, sizeof nm, "%.*s", tk->len, F->L.text + tk->off);
                    if (smap_has(nr, nm)) {
                        c->status = ST_KEEPS_ALIVE;
                        break;
                    }
                }
        }
    }
    /* adjacency */
    int *adj_start = xcalloc((size_t)g_c.n + 2, sizeof(int));
    for (int k = 0; k < efrom.n; k++) adj_start[efrom.v[k] + 1]++;
    for (int i = 0; i < g_c.n; i++) adj_start[i + 1] += adj_start[i];
    int *adj = xmalloc(sizeof(int) * ((size_t)efrom.n + 1));
    int *fill = xcalloc((size_t)g_c.n + 1, sizeof(int));
    for (int k = 0; k < efrom.n; k++) adj[adj_start[efrom.v[k]] + fill[efrom.v[k]]++] = eto.v[k];

    /* load every file of a group that holds a candidate */
    {
        char *need = xcalloc((size_t)g_files.n + 1, 1);
        for (int i = 0; i < g_c.n; i++) need[find_root(g_c.v[i].file)] = 1;
        for (int f = 0; f < g_files.n; f++)
            if (need[find_root(f)] && is_cfile(g_files.v[f].rel)) load(f);
        free(need);
    }
    int changed = 1, rounds = 0;
    char **added = xcalloc((size_t)g_files.n + 1, sizeof(char *));
    char *nr_added = xcalloc((size_t)g_c.n + 1, 1);
    int nr_grew = 0;
    while (changed) {
        changed = 0;
        rounds++;
        /* kept rows make their definitions kept; kept definitions make their rows kept */
        int again = 1;
        while (again) {
            again = 0;
            for (int i = 0; i < g_c.n; i++) {
                Cand *c = &g_c.v[i];
                if (c->def < 0) continue;
                DefInfo *di = definfo(c->file, c->def);
                if (c->status != ST_REMOVE && di->state == ST_REMOVE) {
                    di->state = c->status;
                    again = changed = 1;
                }
                if (c->status == ST_REMOVE && di->state != ST_REMOVE) {
                    c->status = di->state;
                    again = changed = 1;
                }
            }
            for (int i = 0; i < g_c.n; i++) {
                Cand *c = &g_c.v[i];
                if (c->ref || c->status == ST_REMOVE || kept[i]) continue;
                kept[i] = 1;
                for (int k = adj_start[i]; k < adj_start[i + 1]; k++) {
                    Cand *o = &g_c.v[adj[k]];
                    if (o->status == ST_REMOVE) {
                        o->status = ST_REF_KEPT;
                        again = changed = 1;
                    }
                }
            }
            for (int i = 0; i < g_c.n; i++)
                if (g_c.v[i].ref) kept[i] = 1;
            /* a definition kept so that a checked function stays emitted is itself emitted only when referenced
               if it has internal linkage: its callers (by relocation or by name) stay too */
            for (int i = 0; i < g_c.n; i++) {
                Cand *c = &g_c.v[i];
                if (c->status != ST_KEEPS_ALIVE || c->def < 0 || nr_added[i]) continue;
                Def *df = &g_files.v[c->file].P.defs[c->def];
                if (!(df->is_static || df->is_inline || df->is_template || df->parent == SK_CLASS)) continue;
                nr_added[i] = 1;
                if (df->is_operator) continue;
                StrMap *nr = &g_NR[find_root(c->file)];
                if (!nr->cap) smap_init(nr, 64);
                smap_put(nr, df->name_s, (void *)1);
                nr_grew = 1;
            }
            for (int k = 0; k < efrom.n; k++) {
                Cand *to = &g_c.v[eto.v[k]], *from = &g_c.v[efrom.v[k]];
                if (to->status == ST_KEEPS_ALIVE && nr_added[eto.v[k]] && from->status == ST_REMOVE) {
                    from->status = ST_KEEPS_ALIVE;
                    again = changed = 1;
                }
            }
            if (nr_grew) {
                nr_grew = 0;
                for (int i = 0; i < g_c.n; i++) {
                    Cand *c = &g_c.v[i];
                    if (c->status != ST_REMOVE || c->def < 0) continue;
                    File *F = &g_files.v[c->file];
                    StrMap *nr = &g_NR[find_root(c->file)];
                    Def *df = &F->P.defs[c->def];
                    if (!nr->cap) continue;
                    for (int j = df->body_from; j <= df->endtok; j++) {
                        PTok *tk = &F->L.toks[j];
                        if (tk->type != P_IDENT || tk->len > 200) continue;
                        char nm[256];
                        snprintf(nm, sizeof nm, "%.*s", tk->len, F->L.text + tk->off);
                        if (smap_has(nr, nm)) {
                            c->status = ST_KEEPS_ALIVE;
                            again = changed = 1;
                            break;
                        }
                    }
                }
            }
        }
        /* identifiers */
        for (int f = 0; f < g_files.n; f++) {
            File *F = &g_files.v[f];
            if (F->loaded != 1 || F->P.ndefs == 0) continue;
            int grp = find_root(f);
            if (!added[f]) {
                added[f] = (char *)1;
                definfo(f, 0);
                for (int s = 0; s < F->P.nstmts; s++) {
                    Stmt *sm = &F->P.stmts[s];
                    if (sm->has_eq) {
                        add_mentions(&g_S[grp], F, sm->eq, sm->last);
                        add_idents(&g_A[grp], F, sm->eq, sm->last);
                    }
                }
            }
            for (int d = 0; d < F->P.ndefs; d++) {
                DefInfo *di = &g_definfo[f][d];
                if (di->state == ST_REMOVE) continue;
                Def *df = &F->P.defs[d];
                if (!di->in_a) {
                    di->in_a = 1;
                    add_idents(&g_A[grp], F, df->body_from, df->rbrace);
                }
                /* operators, constructors and destructors run without being named: their bodies always count */
                if (!di->in_s && (di->seed || df->is_operator || df->is_ctor_like || df->is_dtor ||
                                  s_names(&g_S[grp], df->name_s))) {
                    di->in_s = 1;
                    add_mentions(&g_S[grp], F, df->body_from, df->rbrace);
                    changed = 1;
                }
            }
        }
        for (int i = 0; i < g_c.n; i++) {
            Cand *c = &g_c.v[i];
            if (c->status != ST_REMOVE || c->def < 0) continue;
            File *F = &g_files.v[c->file];
            Def *df = &F->P.defs[c->def];
            char nm[256];
            if (!def_check_name(df, nm, sizeof nm)) continue;
            int grp = find_root(c->file);
            char q[256];
            dec_qualifier(c->dec, q, sizeof q);
            int hit = s_names_cand(&g_S[grp], nm, q);
            if (!hit && is_free_function(c->dec) && !getenv("F3PRUNE_NO_A")) hit = g_A[grp].cap && smap_has(&g_A[grp], nm);
            if (hit) {
                c->status = ST_NAMED_KEPT;
                changed = 1;
            }
        }
        /* ctors and dtors run implicitly (bases, members, locals going out of scope): keep one whose class kept
           code names anywhere outside the class's own definition */
        {
            static StrMap *T = NULL, *O = NULL, *CD = NULL;
            if (!T) {
                T = xcalloc((size_t)g_files.n + 1, sizeof(StrMap));
                O = xcalloc((size_t)g_files.n + 1, sizeof(StrMap));
                CD = xcalloc((size_t)g_files.n + 1, sizeof(StrMap));
                for (int f = 0; f < g_files.n; f++) {
                    File *F = &g_files.v[f];
                    if (F->loaded != 1) continue;
                    int grp = find_root(f);
                    count_idents(&T[grp], F, 0, F->L.ntoks - 1, 1);
                    for (int k = 0; k < F->P.nstmts; k++) {
                        Stmt *sm = &F->P.stmts[k];
                        char nm[256];
                        if (sm->class_body < 0 || !class_stmt_name(F, sm, nm, sizeof nm)) continue;
                        if (!CD[grp].cap) smap_init(&CD[grp], 256);
                        smap_put(&CD[grp], nm, (void *)1);
                        /* occurrences of the class's own name inside its own definition */
                        int cnt = 0;
                        for (int j = sm->first; j <= sm->last; j++)
                            if (F->L.toks[j].type == P_IDENT && F->L.toks[j].len == (int)strlen(nm) &&
                                memcmp(F->L.text + F->L.toks[j].off, nm, strlen(nm)) == 0)
                                cnt++;
                        if (!O[grp].cap) smap_init(&O[grp], 256);
                        void **v = smap_slot(&O[grp], nm);
                        *v = (void *)((intptr_t)*v + cnt);
                    }
                }
            }
            StrMap *R = xcalloc((size_t)g_files.n + 1, sizeof(StrMap));
            for (int f = 0; f < g_files.n; f++) {
                File *F = &g_files.v[f];
                if (F->loaded != 1 || !g_definfo[f]) continue;
                int grp = find_root(f);
                for (int d = 0; d < F->P.ndefs; d++)
                    if (g_definfo[f][d].state == ST_REMOVE) count_idents(&R[grp], F, F->P.defs[d].head, F->P.defs[d].endtok, 1);
            }
            for (int i = 0; i < g_c.n; i++) {
                Cand *c = &g_c.v[i];
                if (c->status != ST_REMOVE || c->def < 0) continue;
                Def *df = &g_files.v[c->file].P.defs[c->def];
                int grp = find_root(c->file);
                if (df->is_template && !df->is_operator) {
                    /* a template: a kept specialization or use anywhere (heads included) needs it */
                    if (count_of(&T[grp], df->name_s) - count_of(&R[grp], df->name_s) > 0) {
                        c->status = ST_TEMPLATE_USED;
                        changed = 1;
                        continue;
                    }
                }
                if (strncmp(c->dec, "??0", 3) != 0 && strncmp(c->dec, "??1", 3) != 0) continue;
                if (!CD[grp].cap || !smap_has(&CD[grp], df->name_s)) {
                    c->status = ST_CLASS_IN_HEADER;
                    changed = 1;
                    continue;
                }
                intptr_t rest = count_of(&T[grp], df->name_s) - count_of(&R[grp], df->name_s) - count_of(&O[grp], df->name_s);
                if (rest > 0) {
                    c->status = ST_CLASS_USED;
                    changed = 1;
                }
            }
            for (int f = 0; f < g_files.n; f++)
                if (R[f].cap) smap_free(&R[f]);
            free(R);
        }
    }

    /* removal ranges */
    int nfiles_edit = 0;
    long long removed_rows = 0, removed_bytes = 0;
    int removed_defs_total = 0;
    for (int f = 0; f < g_files.n; f++) {
        File *F = &g_files.v[f];
        if (F->loaded != 1 || !g_definfo[f]) continue;
        int any = 0;
        for (int d = 0; d < F->P.ndefs; d++)
            if (g_definfo[f][d].state == ST_REMOVE) any = 1;
        if (!any) continue;
        F->drop = xcalloc((size_t)F->L.nlines + 2, 1);
        /* definitions in order of position */
        for (int d = 0; d < F->P.ndefs; d++) {
            if (g_definfo[f][d].state != ST_REMOVE) continue;
            Def *df = &F->P.defs[d];
            int s = df->first_line, e = F->L.toks[df->endtok].end_line;
            for (int l = s; l <= e; l++) F->drop[l] = 1;
            F->removed_defs++;
            removed_defs_total++;
        }
        /* attached comments: above each deleted run, unless kept code follows the run directly */
        for (int l = 1; l <= F->L.nlines; l++) {
            if (!F->drop[l] || (l > 1 && F->drop[l - 1])) continue;
            int e = l;
            while (e + 1 <= F->L.nlines && F->drop[e + 1]) e++;
            int next = e + 1;
            int follows = 0;
            if (next <= F->L.nlines && !line_blank(&F->L, next)) {
                const char *s = F->L.text + F->L.line_off[next - 1];
                while (*s == ' ' || *s == '	') s++;
                follows = !(*s == '}' || *s == '#');
            }
            if (follows) continue;
            int c = l - 1;
            while (c >= 1 && is_comment_only(&F->L, c) && !F->drop[c]) c--;
            /* a comment block that starts the file is the file's banner: keep it */
            if (c == 0) continue;
            for (int k = c + 1; k < l; k++) F->drop[k] = 1;
        }
        nfiles_edit++;
        write_file(F);
    }

    /* report */
    FILE *fo = fopen(outp, "wb");
    if (!fo) die("cannot write %s", outp);
    fprintf(fo, "file\tline\tdecorated\tsize\tstatus\n");
    long long cnt[ST_N] = {0}, bytes[ST_N] = {0};
    for (int i = 0; i < g_c.n; i++) {
        Cand *c = &g_c.v[i];
        fprintf(fo, "%s\t%d\t%s\t%u\t%s\n", g_files.v[c->file].rel, c->line, c->dec, c->size, st_name[c->status]);
        cnt[c->status]++;
        bytes[c->status] += c->size;
        if (c->status == ST_REMOVE) {
            removed_rows++;
            removed_bytes += c->size;
        }
    }
    fclose(fo);
    printf("f3prune defs: %d unchecked rows, %lld removed (%lld bytes) as %d definitions in %d files; %d rounds\n",
           g_c.n, removed_rows, removed_bytes, removed_defs_total, nfiles_edit, rounds);
    for (int s = 0; s < ST_N; s++)
        if (cnt[s]) printf("  %-40s %7lld rows %9lld bytes\n", st_name[s], cnt[s], bytes[s]);
    return 0;
}

/* ------------------------------------------------------------------ decls mode */

static int cmd_decls(int argc, char **argv);
int objrefs_main(const char *obj);

int main(int argc, char **argv)
{
    if (argc < 3) die("usage: f3prune defs|decls <repo> ...");
    snprintf(g_repo, sizeof g_repo, "%s", argv[2]);
    slash_inplace(g_repo);
    size_t rl = strlen(g_repo);
    while (rl && g_repo[rl - 1] == '/') g_repo[--rl] = 0;
    norm_path(g_repo, g_repo_lower, sizeof g_repo_lower);
    if (strcmp(argv[1], "defs") == 0) return cmd_defs(argc, argv);
    if (strcmp(argv[1], "decls") == 0) return cmd_decls(argc, argv);
    if (strcmp(argv[1], "objrefs") == 0 && argc > 3) return objrefs_main(argv[3]);
    die("unknown command %s", argv[1]);
    return 2;
}

/* the second pass shares this file's statics */
#include "decls.inc"

/* debugging aid: f3prune objrefs <repo> <obj> lists each function of an object with its file, lines and references */
int objrefs_main(const char *obj)
{
    ObjInfo oi;
    char err[256];
    if (coff_read(obj, &oi, err, sizeof err) != 0) die("%s: %s", obj, err);
    for (int i = 0; i < oi.n; i++) {
        ObjFunc *of = &oi.funcs[i];
        printf("%s\t%s\t%d-%d\t%u\n", of->name, of->file ? of->file : "-", of->min_line, of->max_line, of->code_size);
        for (int r = 0; r < of->nrefs; r++) printf("    -> %s\n", of->refs[r]);
    }
    return 0;
}

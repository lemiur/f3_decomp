/* f3rename: apply evidence-backed names to the f3_decomp source tree (src/, include/) and its build recipe
 * (build/units.json) without changing a single compiled byte.
 *
 *   f3rename apply  --root TREE --renames LIST.tsv [--locations LOC.tsv] [--report OUT.tsv] [--dry-run]
 *                   [--sdk DIR]... [--no-sdk]
 *   f3rename bisect --root TREE --renames LIST.tsv --applied REPORT.tsv --compare FILE... --out REDUCED.tsv
 *                   [--dropped DROPPED.tsv]
 *
 * Rename list (TSV, header row optional): kind (function|global|type), address (hex), old, new, comment, marker.
 *   comment: one line placed directly above each definition (functions: every definition site, variants included;
 *            globals: non-extern declarations; types: struct/class/enum definitions and typedefs).
 *   marker:  appended to the end of every declaration line of a renamed global or type.
 * Location list (TSV, optional): address, file, first_line (1-based) of a function definition; where given and the
 *   new name appears within 15 lines past blank/comment lines, the comment goes there instead of the syntactic site.
 * Report (TSV): kind address old new status reason files units comments markers
 *   status: applied | ambiguous | collision | not-found; files: every file touched (';'), build/units.json included;
 *   units: the units whose recipe entry changed.
 *
 * Rules per rename:
 *   ownership  every decorated name in build/units.json (functions, fold_aliases, symbols keys, and the
 *              __ehhandler$/__unwindfunclet$/__sehtable$/__imp_ names derived from them) whose own name is `old`
 *              binds the given address (derived names: through their embedded name). Types: no address check, but
 *              `old` must be placeholder-like and name no function or global. Else `ambiguous`; no owner: `not-found`.
 *   collision  `new` is a valid identifier, not a keyword or reserved name, not in code under src/ or include/, not
 *              a macro of the compiler's headers (nor one of their identifiers for a global-scope name), not in any
 *              recipe name, not listed twice, and `new@` is not already a fragment of an affected decorated name.
 *   apply      `old` -> `new` as a whole token in code and comments (never in string/char literals or #include
 *              paths); recipe names rewritten fragment by fragment in place (the file keeps its exact bytes
 *              elsewhere). A fragment after a type-code letter or digit (PAVname@@, W4name@@) whose longer spelling
 *              is also a known identifier is refused as ambiguous.
 * Bisect: a rename is dropped when a file it touched is in the include closure of a unit the compare results name
 *   (shard result JSON: status != identical; report markdown: "- `source`" lines), or it changed that unit's entry.
 */
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

/* ---------------------------------------------------------------------------------------------------------------- */
/* basics */

static __declspec(noreturn) void die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fputs("f3rename: ", stderr);
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

static void *xcalloc(size_t n, size_t m)
{
    void *p = calloc(n ? n : 1, m ? m : 1);
    if (!p) die("out of memory");
    return p;
}

static void *xrealloc(void *p, size_t n)
{
    p = realloc(p, n ? n : 1);
    if (!p) die("out of memory");
    return p;
}

static char *xstrndup(const char *s, size_t n)
{
    char *p = (char *)xmalloc(n + 1);
    memcpy(p, s, n);
    p[n] = 0;
    return p;
}

static char *xstrdup(const char *s) { return xstrndup(s, strlen(s)); }

typedef struct { char *p; size_t n, cap; } Buf;

static void buf_reserve(Buf *b, size_t extra)
{
    if (b->n + extra + 1 > b->cap) {
        size_t c = b->cap ? b->cap : 256;
        while (c < b->n + extra + 1) c *= 2;
        b->p = (char *)xrealloc(b->p, c);
        b->cap = c;
    }
}

static void buf_put(Buf *b, const void *s, size_t n)
{
    buf_reserve(b, n);
    memcpy(b->p + b->n, s, n);
    b->n += n;
    b->p[b->n] = 0;
}

static void buf_puts(Buf *b, const char *s) { buf_put(b, s, strlen(s)); }
static void buf_putc(Buf *b, char c) { buf_put(b, &c, 1); }

static void buf_printf(Buf *b, const char *fmt, ...)
{
    va_list ap;
    int n;
    va_start(ap, fmt);
    n = _vscprintf(fmt, ap);
    va_end(ap);
    if (n < 0) return;
    buf_reserve(b, (size_t)n);
    va_start(ap, fmt);
    vsnprintf(b->p + b->n, (size_t)n + 1, fmt, ap);
    va_end(ap);
    b->n += (size_t)n;
}

#define VEC(T) struct { T *a; size_t n, cap; }
#define VPUSH(v, x) do { if ((v).n == (v).cap) { (v).cap = (v).cap ? (v).cap * 2 : 8; \
    (v).a = xrealloc((v).a, (v).cap * sizeof(*(v).a)); } (v).a[(v).n++] = (x); } while (0)

typedef VEC(int) IntVec;

static int ivec_has(const IntVec *v, int x)
{
    size_t i;
    for (i = 0; i < v->n; i++) if (v->a[i] == x) return 1;
    return 0;
}

static char *read_all(const char *path, size_t *len)
{
    FILE *f = fopen(path, "rb");
    long n;
    char *p;
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    p = (char *)xmalloc((size_t)n + 1);
    if (n > 0 && fread(p, 1, (size_t)n, f) != (size_t)n) { fclose(f); free(p); return NULL; }
    fclose(f);
    p[n] = 0;
    *len = (size_t)n;
    return p;
}

static void write_all(const char *path, const char *p, size_t n)
{
    FILE *f = fopen(path, "wb");
    if (!f) die("cannot write %s", path);
    if (n && fwrite(p, 1, n, f) != n) die("cannot write %s", path);
    fclose(f);
}

static double now_s(void) { return (double)GetTickCount64() / 1000.0; }

/* ---------------------------------------------------------------------------------------------------------------- */
/* hash map: bytes -> int */

static uint64_t hash_bytes(const char *s, size_t n)
{
    uint64_t h = 1469598103934665603ULL;
    size_t i;
    for (i = 0; i < n; i++) { h ^= (unsigned char)s[i]; h *= 1099511628211ULL; }
    return h;
}

typedef struct { const char *k; uint32_t len; int32_t v; uint64_t h; } MapSlot;
typedef struct { MapSlot *s; size_t cap, count; } Map;

static void map_init(Map *m, size_t cap)
{
    size_t c = 64;
    while (c < cap * 2) c *= 2;
    m->s = (MapSlot *)xcalloc(c, sizeof(MapSlot));
    m->cap = c;
    m->count = 0;
}

static void map_grow(Map *m)
{
    MapSlot *old = m->s;
    size_t oc = m->cap, i;
    m->cap *= 2;
    m->s = (MapSlot *)xcalloc(m->cap, sizeof(MapSlot));
    for (i = 0; i < oc; i++) {
        if (old[i].k) {
            size_t j = (size_t)old[i].h & (m->cap - 1);
            while (m->s[j].k) j = (j + 1) & (m->cap - 1);
            m->s[j] = old[i];
        }
    }
    free(old);
}

/* returns the slot's value pointer; creates it (value -1) when create is set, else NULL if absent */
static int32_t *map_at(Map *m, const char *k, size_t len, int create)
{
    uint64_t h = hash_bytes(k, len);
    size_t j;
    if (create && (m->count + 1) * 10 > m->cap * 7) map_grow(m);
    j = (size_t)h & (m->cap - 1);
    while (m->s[j].k) {
        if (m->s[j].h == h && m->s[j].len == len && !memcmp(m->s[j].k, k, len)) return &m->s[j].v;
        j = (j + 1) & (m->cap - 1);
    }
    if (!create) return NULL;
    m->s[j].k = k;
    m->s[j].len = (uint32_t)len;
    m->s[j].h = h;
    m->s[j].v = -1;
    m->count++;
    return &m->s[j].v;
}

static int map_get(Map *m, const char *k, size_t len)
{
    int32_t *v = map_at(m, k, len, 0);
    return v ? *v : -1;
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* identifiers */

static int is_id_start(int c) { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_' || c == '$'; }
static int is_digit(int c) { return c >= '0' && c <= '9'; }
static int is_id_char(int c) { return is_id_start(c) || is_digit(c); }
/* inside a decorated name '$' is a code, never part of a name fragment */
static int is_mid(int c) { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_' || is_digit(c); }
static int is_mid_start(int c) { return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_'; }

static const char *KEYWORDS[] = {
    "asm", "auto", "bool", "break", "case", "catch", "char", "class", "const", "const_cast", "continue", "default",
    "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for",
    "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", "operator", "private",
    "protected", "public", "register", "reinterpret_cast", "return", "short", "signed", "sizeof", "static",
    "static_cast", "struct", "switch", "template", "this", "throw", "true", "try", "typedef", "typeid", "typename",
    "union", "unsigned", "using", "virtual", "void", "volatile", "wchar_t", "while", "and", "and_eq", "bitand",
    "bitor", "compl", "not", "not_eq", "or", "or_eq", "xor", "xor_eq", "abstract", "sealed", "override", "final",
    "interface", "nullptr", "alignof", "alignas", "constexpr", "decltype", "noexcept", "static_assert",
    "thread_local", "char16_t", "char32_t", "property", "event", "delegate", "generic", "gcnew", "array",
    "main", "wmain", "WinMain", "DllMain", NULL
};

static int is_keyword(const char *s)
{
    int i;
    for (i = 0; KEYWORDS[i]; i++) if (!strcmp(KEYWORDS[i], s)) return 1;
    return 0;
}

/* why a new name is not a usable identifier, or NULL */
static const char *bad_identifier(const char *s)
{
    size_t i, n = strlen(s);
    if (!n) return "empty name";
    if (!is_mid_start((unsigned char)s[0])) return "not a C++ identifier";
    for (i = 1; i < n; i++) if (!is_mid((unsigned char)s[i])) return "not a C++ identifier";
    if (is_keyword(s)) return "a C++ keyword (or reserved by MSVC)";
    if (s[0] == '_' && (s[1] == '_' || (s[1] >= 'A' && s[1] <= 'Z'))) return "a reserved identifier (_X or __x)";
    if (n > 200) return "longer than 200 characters";
    return NULL;
}

/* a placeholder-like type name: an 8-hex-digit run bounded by '_' or the ends, or a stand-in prefix */
static int placeholder_type(const char *s)
{
    size_t n = strlen(s), i;
    static const char *pre[] = { "FUN_", "DAT_", "Unk", "UNK_", "unk_", "Unknown", "Stub", "Fnv", "f3m_", NULL };
    for (i = 0; pre[i]; i++) if (!strncmp(s, pre[i], strlen(pre[i]))) return 1;
    for (i = 0; i + 8 <= n; i++) {
        size_t k;
        if (i > 0 && s[i - 1] != '_') continue;
        for (k = 0; k < 8; k++) {
            char c = s[i + k];
            if (!(is_digit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) break;
        }
        if (k == 8 && (i + 8 == n || s[i + 8] == '_')) return 1;
    }
    if (n > 6 && !strcmp(s + n - 6, "_shell")) return 1;
    return 0;
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* the identifier lexer: every identifier in code and comments, never inside string/char literals or #include paths.
 * The same lexer builds the index and does the replacement, so both always agree. */

typedef void (*IdentFn)(void *ctx, size_t pos, size_t len, int in_comment);

static size_t skip_number(const char *s, size_t i, size_t n)
{
    size_t j = i + 1;
    while (j < n) {
        char c = s[j];
        if ((c == 'e' || c == 'E' || c == 'p' || c == 'P') && j + 1 < n && (s[j + 1] == '+' || s[j + 1] == '-')) j += 2;
        else if (is_id_char((unsigned char)c) || c == '.') j++;
        else break;
    }
    return j;
}

static void lex_comment(const char *s, size_t a, size_t b, IdentFn fn, void *ctx)
{
    size_t i = a;
    while (i < b) {
        unsigned char c = (unsigned char)s[i];
        if (is_digit(c)) { i = skip_number(s, i, b); continue; }
        if (is_id_start(c)) {
            size_t j = i + 1;
            while (j < b && is_id_char((unsigned char)s[j])) j++;
            fn(ctx, i, j - i, 1);
            i = j;
            continue;
        }
        i++;
    }
}

static void lex_idents(const char *s, size_t n, IdentFn fn, void *ctx)
{
    size_t i = 0;
    int bol = 1;
    while (i < n) {
        unsigned char c = (unsigned char)s[i];
        if (c == '\n') { bol = 1; i++; continue; }
        if (c == ' ' || c == '\t' || c == '\r' || c == '\f' || c == '\v') { i++; continue; }
        if (c == '#' && bol) {
            size_t j = i + 1;
            bol = 0;
            while (j < n && (s[j] == ' ' || s[j] == '\t')) j++;
            if ((n - j >= 7 && !memcmp(s + j, "include", 7) && (j + 7 >= n || !is_id_char((unsigned char)s[j + 7]))) ||
                (n - j >= 6 && !memcmp(s + j, "import", 6) && (j + 6 >= n || !is_id_char((unsigned char)s[j + 6])))) {
                /* the path is never renamed; a comment after it still is */
                size_t k = j;
                while (k < n && s[k] != '\n' && s[k] != '<' && s[k] != '"') k++;
                if (k < n && (s[k] == '<' || s[k] == '"')) {
                    char close = s[k] == '<' ? '>' : '"';
                    k++;
                    while (k < n && s[k] != close && s[k] != '\n') k++;
                    if (k < n && s[k] == close) k++;
                }
                i = k;
                continue;
            }
            i++;
            continue;
        }
        bol = 0;
        if (c == '/' && i + 1 < n && s[i + 1] == '/') {
            size_t j = i + 2;
            while (j < n && s[j] != '\n') j++;
            lex_comment(s, i + 2, j, fn, ctx);
            i = j;
            continue;
        }
        if (c == '/' && i + 1 < n && s[i + 1] == '*') {
            size_t j = i + 2;
            while (j + 1 < n && !(s[j] == '*' && s[j + 1] == '/')) j++;
            if (j + 1 >= n) j = n;
            lex_comment(s, i + 2, j, fn, ctx);
            i = j + 2 > n ? n : j + 2;
            continue;
        }
        if (c == '"' || c == '\'') {
            size_t j = i + 1;
            while (j < n && s[j] != (char)c && s[j] != '\n') j += (s[j] == '\\' && j + 1 < n) ? 2 : 1;
            i = (j < n && s[j] == (char)c) ? j + 1 : j;
            continue;
        }
        if (is_digit(c) || (c == '.' && i + 1 < n && is_digit((unsigned char)s[i + 1]))) { i = skip_number(s, i, n); continue; }
        if (is_id_start(c)) {
            size_t j = i + 1;
            while (j < n && is_id_char((unsigned char)s[j])) j++;
            fn(ctx, i, j - i, 0);
            i = j;
            continue;
        }
        i++;
    }
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* the structural lexer: tokens of code only (comments, preprocessor lines dropped), with line numbers */

enum { T_ID = 'i', T_NUM = 'n', T_STR = 's', T_SCOPE = 'Q', T_ARROW = 'A' };
typedef struct { uint32_t s, len, line; char t; } Tok;
typedef VEC(Tok) TokVec;

static void lex_tokens(const char *s, size_t n, TokVec *out)
{
    size_t i = 0;
    uint32_t line = 0;
    int bol = 1;
    out->n = 0;
    while (i < n) {
        unsigned char c = (unsigned char)s[i];
        Tok t;
        if (c == '\n') { line++; bol = 1; i++; continue; }
        if (c == ' ' || c == '\t' || c == '\r' || c == '\f' || c == '\v') { i++; continue; }
        if (c == '\\' && i + 1 < n && (s[i + 1] == '\n' || s[i + 1] == '\r')) { i++; continue; }
        if (c == '#' && bol) {   /* a directive, with its continuations */
            while (i < n && s[i] != '\n') {
                if (s[i] == '\\' && i + 1 < n && s[i + 1] == '\n') { line++; i += 2; continue; }
                if (s[i] == '\\' && i + 2 < n && s[i + 1] == '\r' && s[i + 2] == '\n') { line++; i += 3; continue; }
                if (s[i] == '/' && i + 1 < n && s[i + 1] == '*') {
                    i += 2;
                    while (i + 1 < n && !(s[i] == '*' && s[i + 1] == '/')) { if (s[i] == '\n') line++; i++; }
                    i += 2;
                    continue;
                }
                i++;
            }
            continue;
        }
        bol = 0;
        if (c == '/' && i + 1 < n && s[i + 1] == '/') { while (i < n && s[i] != '\n') i++; continue; }
        if (c == '/' && i + 1 < n && s[i + 1] == '*') {
            i += 2;
            while (i + 1 < n && !(s[i] == '*' && s[i + 1] == '/')) { if (s[i] == '\n') line++; i++; }
            i = i + 2 > n ? n : i + 2;
            continue;
        }
        t.s = (uint32_t)i;
        t.line = line;
        if (c == '"' || c == '\'') {
            size_t j = i + 1;
            while (j < n && s[j] != (char)c && s[j] != '\n') j += (s[j] == '\\' && j + 1 < n) ? 2 : 1;
            i = (j < n && s[j] == (char)c) ? j + 1 : j;
            t.t = T_STR;
        } else if (is_digit(c) || (c == '.' && i + 1 < n && is_digit((unsigned char)s[i + 1]))) {
            i = skip_number(s, i, n);
            t.t = T_NUM;
        } else if (is_id_start(c)) {
            size_t j = i + 1;
            while (j < n && is_id_char((unsigned char)s[j])) j++;
            i = j;
            t.t = T_ID;
        } else if (c == ':' && i + 1 < n && s[i + 1] == ':') {
            i += 2;
            t.t = T_SCOPE;
        } else if (c == '-' && i + 1 < n && s[i + 1] == '>') {
            i += 2;
            t.t = T_ARROW;
        } else {
            i++;
            t.t = (char)c;
        }
        t.len = (uint32_t)(i - t.s);
        VPUSH(*out, t);
    }
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* the tree */

typedef struct {
    char *rel;        /* path relative to the root, with '/' */
    char *data;
    size_t len;
    char *out;        /* new content (NULL: unchanged) */
    size_t outlen;
} SrcFile;

static VEC(SrcFile) g_files;
static char *g_root;

static void walk(const char *rel)
{
    char pat[MAX_PATH * 2];
    WIN32_FIND_DATAA fd;
    HANDLE h;
    snprintf(pat, sizeof pat, "%s/%s/*", g_root, rel);
    h = FindFirstFileA(pat, &fd);
    if (h == INVALID_HANDLE_VALUE) return;
    do {
        char sub[MAX_PATH * 2];
        if (!strcmp(fd.cFileName, ".") || !strcmp(fd.cFileName, "..") || !strcmp(fd.cFileName, ".git")) continue;
        snprintf(sub, sizeof sub, "%s/%s", rel, fd.cFileName);
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            walk(sub);
        } else {
            SrcFile f;
            memset(&f, 0, sizeof f);
            f.rel = xstrdup(sub);
            VPUSH(g_files, f);
        }
    } while (FindNextFileA(h, &fd));
    FindClose(h);
}

static int cmp_files(const void *a, const void *b) { return strcmp(((const SrcFile *)a)->rel, ((const SrcFile *)b)->rel); }

static void load_tree(void)
{
    size_t i;
    walk("src");
    walk("include");
    if (!g_files.n) die("%s: no files under src/ or include/", g_root);
    qsort(g_files.a, g_files.n, sizeof(SrcFile), cmp_files);
    for (i = 0; i < g_files.n; i++) {
        char path[MAX_PATH * 2];
        snprintf(path, sizeof path, "%s/%s", g_root, g_files.a[i].rel);
        g_files.a[i].data = read_all(path, &g_files.a[i].len);
        if (!g_files.a[i].data) die("cannot read %s", path);
    }
}

static int find_file(const char *rel)
{
    size_t lo = 0, hi = g_files.n;
    while (lo < hi) {
        size_t mid = (lo + hi) / 2;
        int c = strcmp(g_files.a[mid].rel, rel);
        if (!c) return (int)mid;
        if (c < 0) lo = mid + 1; else hi = mid;
    }
    return -1;
}

/* the --root argument: '/' separators, no trailing '/' */
static char *root_arg(const char *p)
{
    char *s = xstrdup(p), *q;
    size_t n;
    for (q = s; *q; q++) if (*q == '\\') *q = '/';
    n = strlen(s);
    while (n > 1 && s[n - 1] == '/') s[--n] = 0;
    return s;
}

/* normalise a path from an input file to the tree's relative form */
static char *rel_path(const char *p)
{
    char *s = xstrdup(p), *q;
    size_t rl = strlen(g_root);
    for (q = s; *q; q++) if (*q == '\\') *q = '/';
    if (!_strnicmp(s, g_root, rl) && s[rl] == '/') memmove(s, s + rl + 1, strlen(s + rl + 1) + 1);
    while (s[0] == '.' && s[1] == '/') memmove(s, s + 2, strlen(s + 2) + 1);
    return s;
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* the identifier index: token -> files (with whether it occurs in code or only in comments) */

typedef struct { uint32_t file, next; uint8_t code; } INode;
static VEC(INode) g_inodes;
static VEC(uint32_t) g_tok_first;   /* per token: first node + 1 (0 = none) */
static VEC(uint32_t) g_tok_last;    /* per token: last node */
static Map g_tokens;

typedef struct { uint32_t file; } IndexCtx;

static void index_ident(void *vctx, size_t pos, size_t len, int in_comment)
{
    IndexCtx *ctx = (IndexCtx *)vctx;
    const char *s = g_files.a[ctx->file].data + pos;
    int32_t *v = map_at(&g_tokens, s, len, 1);
    if (*v < 0) {
        uint32_t z = 0;
        *v = (int32_t)g_tok_first.n;
        VPUSH(g_tok_first, z);
        VPUSH(g_tok_last, z);
    }
    if (!g_tok_first.a[*v] || g_inodes.a[g_tok_last.a[*v]].file != ctx->file) {
        INode nd;
        nd.file = ctx->file;
        nd.next = 0;
        nd.code = (uint8_t)!in_comment;
        VPUSH(g_inodes, nd);
        if (g_tok_first.a[*v]) g_inodes.a[g_tok_last.a[*v]].next = (uint32_t)g_inodes.n;   /* next = index + 1 */
        else g_tok_first.a[*v] = (uint32_t)g_inodes.n;
        g_tok_last.a[*v] = (uint32_t)g_inodes.n - 1;
    } else if (!in_comment) {
        g_inodes.a[g_tok_last.a[*v]].code = 1;
    }
}

static void build_index(void)
{
    size_t i;
    IndexCtx ctx;
    map_init(&g_tokens, 1 << 20);
    for (i = 0; i < g_files.n; i++) {
        ctx.file = (uint32_t)i;
        lex_idents(g_files.a[i].data, g_files.a[i].len, index_ident, &ctx);
    }
}

/* files holding a token: fills v, returns count; *code_files gets how many hold it in code */
static int token_files(const char *s, size_t len, IntVec *v, int *code_files)
{
    int t = map_get(&g_tokens, s, len);
    uint32_t nd;
    int cf = 0;
    if (v) v->n = 0;
    if (t < 0) { if (code_files) *code_files = 0; return 0; }
    for (nd = g_tok_first.a[t]; nd; nd = g_inodes.a[nd - 1].next) {
        if (v) VPUSH(*v, (int)g_inodes.a[nd - 1].file);
        if (g_inodes.a[nd - 1].code) cf++;
    }
    if (code_files) *code_files = cf;
    return t < 0 ? 0 : 1;
}

static int token_in_code(const char *s, size_t len)
{
    int cf = 0;
    token_files(s, len, NULL, &cf);
    return cf > 0;
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* the compiler's own headers: every identifier, and every macro name (a new name that is a macro would be replaced) */

static Map g_sdk_tokens, g_sdk_macros;


typedef struct { const char *data; } SdkCtx;

static void sdk_ident(void *vctx, size_t pos, size_t len, int in_comment)
{
    SdkCtx *ctx = (SdkCtx *)vctx;
    if (in_comment) return;
    if (map_get(&g_sdk_tokens, ctx->data + pos, len) < 0) {
        char *k = xstrndup(ctx->data + pos, len);
        *map_at(&g_sdk_tokens, k, len, 1) = 1;
    }
}

static size_t g_sdk_files;

static void sdk_walk(const char *dir)
{
    char pat[MAX_PATH * 2];
    WIN32_FIND_DATAA fd;
    HANDLE h;
    snprintf(pat, sizeof pat, "%s/*", dir);
    h = FindFirstFileA(pat, &fd);
    if (h == INVALID_HANDLE_VALUE) return;
    do {
        char sub[MAX_PATH * 2];
        if (!strcmp(fd.cFileName, ".") || !strcmp(fd.cFileName, "..")) continue;
        snprintf(sub, sizeof sub, "%s/%s", dir, fd.cFileName);
        if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            sdk_walk(sub);
        } else {
            size_t len, i;
            char *data = read_all(sub, &len);
            SdkCtx ctx;
            if (!data) continue;
            g_sdk_files++;
            ctx.data = data;
            lex_idents(data, len, sdk_ident, &ctx);
            /* macro names: #define NAME */
            for (i = 0; i < len; i++) {
                if (data[i] == '#' && (i == 0 || data[i - 1] == '\n' || data[i - 1] == ' ' || data[i - 1] == '\t')) {
                    size_t j = i + 1, k;
                    while (j < len && (data[j] == ' ' || data[j] == '\t')) j++;
                    if (len - j > 6 && !memcmp(data + j, "define", 6) && (data[j + 6] == ' ' || data[j + 6] == '\t')) {
                        j += 6;
                        while (j < len && (data[j] == ' ' || data[j] == '\t')) j++;
                        k = j;
                        while (k < len && is_id_char((unsigned char)data[k])) k++;
                        if (k > j && map_get(&g_sdk_macros, data + j, k - j) < 0)
                            *map_at(&g_sdk_macros, xstrndup(data + j, k - j), k - j, 1) = 1;
                    }
                }
            }
            free(data);
        }
    } while (FindNextFileA(h, &fd));
    FindClose(h);
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* build/units.json: a minimal JSON reader that keeps every string's byte span, so names are rewritten in place and
 * the file keeps its exact formatting */

enum { J_STR = 's', J_OBJ = 'o', J_ARR = 'a', J_LIT = 'l' };
typedef struct { char t; uint8_t esc; uint32_t s, e; int32_t first, next; } JNode;
static VEC(JNode) g_jn;
static const char *J;
static size_t JL, JP;

static void jws(void) { while (JP < JL && (J[JP] == ' ' || J[JP] == '\t' || J[JP] == '\r' || J[JP] == '\n')) JP++; }

static int jvalue(void)
{
    JNode nd;
    int id;
    jws();
    if (JP >= JL) die("units.json: unexpected end");
    memset(&nd, 0, sizeof nd);
    nd.first = nd.next = -1;
    id = (int)g_jn.n;
    if (J[JP] == '"') {
        size_t i = JP + 1;
        nd.t = J_STR;
        nd.s = (uint32_t)i;
        while (i < JL && J[i] != '"') { if (J[i] == '\\') { nd.esc = 1; i++; } i++; }
        if (i >= JL) die("units.json: unterminated string");
        nd.e = (uint32_t)i;
        JP = i + 1;
        VPUSH(g_jn, nd);
        return id;
    }
    if (J[JP] == '{' || J[JP] == '[') {
        char close = J[JP] == '{' ? '}' : ']';
        int last = -1;
        nd.t = J[JP] == '{' ? J_OBJ : J_ARR;
        nd.s = (uint32_t)JP;
        VPUSH(g_jn, nd);
        JP++;
        jws();
        if (JP < JL && J[JP] == close) { JP++; g_jn.a[id].e = (uint32_t)JP; return id; }
        for (;;) {
            int k;
            if (nd.t == J_OBJ) {
                k = jvalue();
                if (g_jn.a[k].t != J_STR) die("units.json: object key is not a string");
                if (last < 0) g_jn.a[id].first = k; else g_jn.a[last].next = k;
                last = k;
                jws();
                if (JP >= JL || J[JP] != ':') die("units.json: expected ':' at byte %zu", JP);
                JP++;
            }
            k = jvalue();
            if (last < 0) g_jn.a[id].first = k; else g_jn.a[last].next = k;
            last = k;
            jws();
            if (JP < JL && J[JP] == ',') { JP++; continue; }
            if (JP < JL && J[JP] == close) { JP++; break; }
            die("units.json: expected ',' or '%c' at byte %zu", close, JP);
        }
        g_jn.a[id].e = (uint32_t)JP;
        return id;
    }
    nd.t = J_LIT;
    nd.s = (uint32_t)JP;
    while (JP < JL && J[JP] != ',' && J[JP] != '}' && J[JP] != ']' && J[JP] != ' ' && J[JP] != '\r' && J[JP] != '\n') JP++;
    nd.e = (uint32_t)JP;
    VPUSH(g_jn, nd);
    return id;
}

static int jkey_is(int k, const char *s)
{
    size_t n = strlen(s);
    return g_jn.a[k].t == J_STR && g_jn.a[k].e - g_jn.a[k].s == n && !memcmp(J + g_jn.a[k].s, s, n);
}

/* value of key in object o, or -1 */
static int jget(int o, const char *key)
{
    int k;
    if (o < 0 || g_jn.a[o].t != J_OBJ) return -1;
    for (k = g_jn.a[o].first; k >= 0; k = g_jn.a[g_jn.a[k].next].next)
        if (jkey_is(k, key)) return g_jn.a[k].next;
    return -1;
}

static uint32_t jaddr(int v)
{
    char tmp[32];
    size_t n;
    if (v < 0) return 0;
    n = g_jn.a[v].e - g_jn.a[v].s;
    if (n > 30) n = 30;
    memcpy(tmp, J + g_jn.a[v].s, n);
    tmp[n] = 0;
    return (uint32_t)strtoul(tmp, NULL, 0);
}

enum { R_SYMBOL = 1, R_ALIAS, R_SYMKEY, R_FORBIDDEN };
typedef struct { uint32_t off, len; int unit; char role; uint32_t addr; int32_t first_ren; } Name;
static VEC(Name) g_names;
typedef struct { uint32_t off, len; } Span;
static VEC(Span) g_unit_src;
static char *g_json;
static size_t g_json_len;
static Map g_bind;                   /* decorated name -> index into g_bind_addr */
static VEC(int64_t) g_bind_addr;     /* -1: bound to two addresses */

static void add_name(int unit, char role, int strnode, uint32_t addr)
{
    Name nm;
    int32_t *v;
    if (g_jn.a[strnode].esc) role = R_FORBIDDEN;   /* never rewrite a string with escapes */
    nm.off = g_jn.a[strnode].s;
    nm.len = g_jn.a[strnode].e - g_jn.a[strnode].s;
    nm.unit = unit;
    nm.role = role;
    nm.addr = addr;
    nm.first_ren = -1;
    VPUSH(g_names, nm);
    if (role == R_FORBIDDEN) return;
    v = map_at(&g_bind, g_json + nm.off, nm.len, 1);
    if (*v < 0) {
        *v = (int32_t)g_bind_addr.n;
        VPUSH(g_bind_addr, (int64_t)addr);
    } else if (g_bind_addr.a[*v] != (int64_t)addr) {
        g_bind_addr.a[*v] = -1;
    }
}

static void collect_strings(int unit, int node, char role)
{
    int k;
    if (node < 0) return;
    if (g_jn.a[node].t == J_STR) { add_name(unit, role, node, 0); return; }
    for (k = g_jn.a[node].first; k >= 0; k = g_jn.a[k].next) collect_strings(unit, k, role);
}

static void load_recipe(void)
{
    char path[MAX_PATH * 2];
    int root, units, u, ui = 0;
    snprintf(path, sizeof path, "%s/build/units.json", g_root);
    g_json = read_all(path, &g_json_len);
    if (!g_json) die("cannot read %s", path);
    J = g_json; JL = g_json_len; JP = 0;
    root = jvalue();
    units = jget(root, "units");
    if (units < 0 || g_jn.a[units].t != J_ARR) die("units.json: no units[]");
    map_init(&g_bind, 1 << 19);
    for (u = g_jn.a[units].first; u >= 0; u = g_jn.a[u].next, ui++) {
        int src = jget(u, "source"), fns = jget(u, "functions"), syms = jget(u, "symbols"), f, k;
        Span sp;
        sp.off = src >= 0 ? g_jn.a[src].s : 0;
        sp.len = src >= 0 ? g_jn.a[src].e - g_jn.a[src].s : 0;
        VPUSH(g_unit_src, sp);
        if (fns >= 0)
            for (f = g_jn.a[fns].first; f >= 0; f = g_jn.a[f].next) {
                uint32_t a = jaddr(jget(f, "address"));
                int sym = jget(f, "symbol"), al = jget(f, "fold_aliases");
                if (sym >= 0 && g_jn.a[sym].t == J_STR) add_name(ui, R_SYMBOL, sym, a);
                if (al >= 0 && g_jn.a[al].t == J_ARR)
                    for (k = g_jn.a[al].first; k >= 0; k = g_jn.a[k].next)
                        if (g_jn.a[k].t == J_STR) add_name(ui, R_ALIAS, k, a);
            }
        if (syms >= 0 && g_jn.a[syms].t == J_OBJ)
            for (k = g_jn.a[syms].first; k >= 0; k = g_jn.a[g_jn.a[k].next].next)
                add_name(ui, R_SYMKEY, k, jaddr(g_jn.a[k].next));
        collect_strings(ui, jget(u, "eh_tails"), R_FORBIDDEN);
    }
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* decorated names */

/* offset of the embedded decorated name in a derived name (__ehhandler$?f@@..., __unwindfunclet$?f@@...$0,
 * __sehtable$_f, __imp__f@4), else 0 */
static int derived_prefix(const char *s, int n)
{
    int k;
    if (n < 3 || s[0] != '_' || s[1] != '_') return 0;
    if (n > 6 && !memcmp(s, "__imp_", 6)) return 6;
    for (k = 2; k < n && is_mid((unsigned char)s[k]); k++) {}
    if (k > 2 && k + 1 < n && s[k] == '$' && (s[k + 1] == '?' || s[k + 1] == '_' || s[k + 1] == '@')) return k + 1;
    return 0;
}

/* names that carry no identifier of ours: string literals, hashed names, labels, float constants */
static int opaque_name(const char *e, int m)
{
    return (m >= 5 && !memcmp(e, "??_C@", 5)) || (m >= 3 && !memcmp(e, "??@", 3)) || e[0] == '$' ||
           (m >= 7 && (!memcmp(e, "__real@", 7) || !memcmp(e, "__xmm@", 6) || !memcmp(e, "__mask@", 7)));
}

/* the name's own identifier (first ?Name@ fragment, or _Name/@Name/Name for C): offset and length, or 0 */
static int own_name(const char *s, int n, int *o, int *l, int *cpp)
{
    int b = derived_prefix(s, n), m = n - b, st, end;
    const char *e = s + b;
    *cpp = 0;
    if (m <= 0 || opaque_name(e, m)) return 0;
    if (e[0] == '?') {
        *cpp = 1;
        if (m > 1 && e[1] == '?') {
            if (m > 2 && e[2] == '$') st = 3;   /* ??$templatefunc@ */
            else return 0;                       /* ctor, dtor, operator, vftable, RTTI */
        } else if (m > 1 && e[1] == '$') {
            return 0;
        } else {
            st = 1;
        }
        for (end = st; end < m && e[end] != '@'; end++) {}
        if (end >= m || end == st) return 0;
        *o = b + st;
        *l = end - st;
        return 1;
    }
    st = (e[0] == '_' || e[0] == '@') ? 1 : 0;
    for (end = st; end < m && e[end] != '@' && e[end] != '$'; end++) {}
    if (end == st) return 0;
    *o = b + st;
    *l = end - st;
    return 1;
}

static int known_identifier(const char *s, size_t n)
{
    return map_get(&g_tokens, s, n) >= 0 || (g_sdk_tokens.s && map_get(&g_sdk_tokens, s, n) >= 0);
}

typedef struct { int count, ambiguous; char why[160]; } RewriteResult;

/* rewrite every name fragment equal to `old` in decorated name s; out gets the result */
static void rewrite_name(const char *s, int n, const char *old, int ol, const char *nw, int nl, Buf *out,
                         RewriteResult *r)
{
    int b = derived_prefix(s, n), m = n - b, p, last = 0;
    const char *e = s + b;
    memset(r, 0, sizeof *r);
    out->n = 0;
    if (m <= 0 || opaque_name(e, m)) { buf_put(out, s, (size_t)n); return; }
    if (e[0] != '?') {                       /* C name: _name, _name@N, @name@N, name, with a $n funclet tail */
        int st = (e[0] == '_' || e[0] == '@') ? 1 : 0;
        if (m - st >= ol && !memcmp(e + st, old, (size_t)ol) && (st + ol == m || e[st + ol] == '@' || e[st + ol] == '$')) {
            buf_put(out, s, (size_t)(b + st));
            buf_put(out, nw, (size_t)nl);
            buf_put(out, e + st + ol, (size_t)(m - st - ol));
            r->count = 1;
        } else {
            buf_put(out, s, (size_t)n);
        }
        return;
    }
    for (p = b + 1; p + ol < n; p++) {
        char prev;
        if (s[p + ol] != '@' || memcmp(s + p, old, (size_t)ol)) continue;
        prev = s[p - 1];
        if (prev == '?' || prev == '@' || (prev == '$' && p >= 2 && s[p - 2] == '?') || !is_mid((unsigned char)prev)) {
            /* a fragment boundary */
        } else if (prev == '_') {
            continue;                         /* inside a longer identifier: no type code ends in '_' */
        } else {
            /* a type code letter or digit (PAVname@@, W4name@@, ??_7name@@), or the tail of a longer identifier:
             * refuse when any longer spelling is an identifier the tree or the SDK knows */
            int r0 = p, k;
            while (r0 > b && is_mid((unsigned char)s[r0 - 1])) r0--;
            for (k = r0; k < p; k++) {
                if (is_mid_start((unsigned char)s[k]) && known_identifier(s + k, (size_t)(p + ol - k))) {
                    r->ambiguous = 1;
                    snprintf(r->why, sizeof r->why, "fragment boundary unclear: '%.*s' is also an identifier",
                             (int)(p + ol - k), s + k);
                    break;
                }
            }
            if (r->ambiguous) break;
        }
        buf_put(out, s + last, (size_t)(p - last));
        buf_put(out, nw, (size_t)nl);
        last = p + ol;
        r->count++;
        p += ol - 1;
    }
    buf_put(out, s + last, (size_t)(n - last));
}

/* does `f@` occur anywhere in s (conservative: any spelling of the new name followed by '@')? */
static int contains_fragment(const char *s, int n, const char *f, int fl)
{
    int p;
    for (p = 0; p + fl < n; p++)
        if (s[p + fl] == '@' && !memcmp(s + p, f, (size_t)fl)) return 1;
    return 0;
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* the rename list */

enum { K_FUNCTION = 1, K_GLOBAL, K_TYPE };
enum { S_PENDING = 0, S_APPLIED, S_AMBIGUOUS, S_COLLISION, S_NOTFOUND };
static const char *STATUS[] = { "pending", "applied", "ambiguous", "collision", "not-found" };
static const char *KIND[] = { "", "function", "global", "type" };

typedef struct {
    int kind;
    uint32_t addr;
    char *kind_s, *addr_s, *old, *nw, *comment, *marker;
    int ol, nl;
    int status;
    Buf reason;
    IntVec cands;      /* names that contain old (or a longer identifier ending with it) */
    IntVec files;      /* files touched */
    IntVec units;      /* units whose entry changed */
    int json_names, comments, markers;
} Rename;

static VEC(Rename) g_ren;

static char *dup_field(const char *s, size_t n)
{
    while (n && (s[n - 1] == '\r' || s[n - 1] == '\n')) n--;
    return xstrndup(s, n);
}

/* split a line into tab-separated fields */
static int split_tabs(char *line, char **f, int max)
{
    int n = 0;
    char *p = line;
    while (n < max) {
        char *t = strchr(p, '\t');
        f[n++] = p;
        if (!t) break;
        *t = 0;
        p = t + 1;
    }
    if (n) {
        char *q = f[n - 1] + strlen(f[n - 1]);
        while (q > f[n - 1] && (q[-1] == '\r' || q[-1] == '\n')) *--q = 0;
    }
    return n;
}

static void load_renames(const char *path)
{
    size_t len;
    char *data = read_all(path, &len), *p, *line;
    int lineno = 0;
    if (!data) die("cannot read %s", path);
    for (p = data; p && *p; ) {
        char *nl = strchr(p, '\n'), *f[8];
        int nf;
        Rename r;
        line = p;
        if (nl) *nl = 0;
        p = nl ? nl + 1 : NULL;
        lineno++;
        if (!*line || *line == '#' || *line == '\r') continue;
        nf = split_tabs(line, f, 8);
        if (!strcmp(f[0], "kind")) continue;   /* header */
        memset(&r, 0, sizeof r);
        r.kind_s = xstrdup(f[0]);
        r.kind = !strcmp(f[0], "function") ? K_FUNCTION : !strcmp(f[0], "global") ? K_GLOBAL :
                 !strcmp(f[0], "type") ? K_TYPE : 0;
        r.addr_s = xstrdup(nf > 1 ? f[1] : "");
        r.addr = (uint32_t)strtoul(r.addr_s, NULL, 16);
        r.old = xstrdup(nf > 2 ? f[2] : "");
        r.nw = xstrdup(nf > 3 ? f[3] : "");
        r.comment = dup_field(nf > 4 ? f[4] : "", nf > 4 ? strlen(f[4]) : 0);
        r.marker = dup_field(nf > 5 ? f[5] : "", nf > 5 ? strlen(f[5]) : 0);
        r.ol = (int)strlen(r.old);
        r.nl = (int)strlen(r.nw);
        if (!r.kind) { r.status = S_AMBIGUOUS; buf_printf(&r.reason, "line %d: unknown kind '%s'", lineno, f[0]); }
        else if (nf < 4) { r.status = S_AMBIGUOUS; buf_printf(&r.reason, "line %d: fewer than 4 columns", lineno); }
        VPUSH(g_ren, r);
    }
    free(data);
}

/* function locations: address -> (file, first line) */
typedef struct { uint32_t addr; int file; int line; } Loc;
static VEC(Loc) g_locs;

static void load_locations(const char *path)
{
    size_t len;
    char *data = read_all(path, &len), *p;
    int bad = 0;
    if (!data) die("cannot read %s", path);
    for (p = data; p && *p; ) {
        char *nl = strchr(p, '\n'), *f[8], *line = p, *rel;
        int nf;
        Loc l;
        if (nl) *nl = 0;
        p = nl ? nl + 1 : NULL;
        if (!*line || *line == '#') continue;
        nf = split_tabs(line, f, 8);
        if (nf < 3 || !strcmp(f[0], "address")) continue;
        l.addr = (uint32_t)strtoul(f[0], NULL, 16);
        rel = rel_path(f[1]);
        l.file = find_file(rel);
        l.line = atoi(f[2]);
        free(rel);
        if (l.file < 0 || l.line <= 0) { bad++; continue; }
        VPUSH(g_locs, l);
    }
    free(data);
    if (bad) fprintf(stderr, "f3rename: %d location rows name no file of the tree\n", bad);
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* finding the names each rename affects: every identifier run in every decorated name is checked, suffix by suffix,
 * against the set of old and new names */

static Map g_olds, g_news;   /* name -> rename index (first) */

typedef struct { uint64_t h; uint32_t len; int32_t ren; uint8_t is_new; } RevSlot;
static RevSlot *g_rev;
static size_t g_rev_cap;

static uint64_t rev_step(uint64_t h, unsigned char c) { return (h ^ c) * 1099511628211ULL; }

static void rev_add(const char *s, int n, int ren, int is_new)
{
    uint64_t h = 1469598103934665603ULL;
    size_t j;
    int i;
    for (i = n - 1; i >= 0; i--) h = rev_step(h, (unsigned char)s[i]);
    j = (size_t)h & (g_rev_cap - 1);
    while (g_rev[j].len) j = (j + 1) & (g_rev_cap - 1);
    g_rev[j].h = h;
    g_rev[j].len = (uint32_t)n;
    g_rev[j].ren = ren;
    g_rev[j].is_new = (uint8_t)is_new;
}

static void find_candidates(void)
{
    size_t i, c = 64;
    while (c < g_ren.n * 4 + 16) c *= 2;
    g_rev_cap = c;
    g_rev = (RevSlot *)xcalloc(c, sizeof(RevSlot));
    for (i = 0; i < g_ren.n; i++) {
        Rename *r = &g_ren.a[i];
        if (r->ol) rev_add(r->old, r->ol, (int)i, 0);
        if (r->nl) rev_add(r->nw, r->nl, (int)i, 1);
    }
    for (i = 0; i < g_names.n; i++) {
        const char *s = g_json + g_names.a[i].off;
        int n = (int)g_names.a[i].len, q = 0;
        while (q <= n) {
            int end, k;
            uint64_t h;
            while (q < n && !is_mid((unsigned char)s[q])) q++;
            if (q >= n) break;
            end = q;
            while (end < n && is_mid((unsigned char)s[end])) end++;
            h = 1469598103934665603ULL;
            for (k = end - 1; k >= q; k--) {
                h = rev_step(h, (unsigned char)s[k]);
                if (is_mid_start((unsigned char)s[k])) {
                    size_t j = (size_t)h & (g_rev_cap - 1);
                    while (g_rev[j].len) {
                        if (g_rev[j].h == h && g_rev[j].len == (uint32_t)(end - k)) {
                            Rename *r = &g_ren.a[g_rev[j].ren];
                            const char *w = g_rev[j].is_new ? r->nw : r->old;
                            if (!memcmp(w, s + k, g_rev[j].len)) {
                                if (g_rev[j].is_new) {
                                    if (!r->json_names) r->json_names = -1 - (int)i;   /* new already in the recipe */
                                } else if (!r->cands.n || r->cands.a[r->cands.n - 1] != (int)i) {
                                    VPUSH(r->cands, (int)i);
                                }
                            }
                        }
                        j = (j + 1) & (g_rev_cap - 1);
                    }
                }
            }
            q = end;
        }
    }
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* deciding */

static void refuse(Rename *r, int status, const char *fmt, ...)
{
    va_list ap;
    int n;
    if (r->status != S_PENDING) return;
    r->status = status;
    va_start(ap, fmt);
    n = _vscprintf(fmt, ap);
    va_end(ap);
    buf_reserve(&r->reason, (size_t)n);
    va_start(ap, fmt);
    vsnprintf(r->reason.p + r->reason.n, (size_t)n + 1, fmt, ap);
    va_end(ap);
    r->reason.n += (size_t)n;
}

static void decide(Rename *r, int idx)
{
    const char *why;
    int code_files = 0, owned = 0, at_addr = 0;
    size_t i;
    IntVec files = { 0 };
    Buf out = { 0 };
    int32_t *slot;

    if (r->status != S_PENDING) return;
    if (!r->ol || !is_id_start((unsigned char)r->old[0])) {
        refuse(r, S_NOTFOUND, "old is not an identifier");
        return;
    }
    slot = map_at(&g_olds, r->old, (size_t)r->ol, 1);
    if (*slot >= 0) { refuse(r, S_AMBIGUOUS, "old listed twice (line of %s->%s)", r->old, g_ren.a[*slot].nw); return; }
    *slot = idx;
    if ((why = bad_identifier(r->nw)) != NULL) { refuse(r, S_COLLISION, "new: %s", why); return; }
    if (!strcmp(r->old, r->nw)) { refuse(r, S_COLLISION, "new equals old"); return; }
    if (!token_files(r->old, (size_t)r->ol, &files, &code_files) || !code_files) {
        refuse(r, S_NOTFOUND, "old does not occur in code under src/ or include/");
        free(files.a);
        return;
    }
    if (token_in_code(r->nw, (size_t)r->nl)) { refuse(r, S_COLLISION, "new already occurs in src/ or include/"); free(files.a); return; }
    if (g_sdk_macros.s && map_get(&g_sdk_macros, r->nw, (size_t)r->nl) >= 0) {
        refuse(r, S_COLLISION, "new is a macro in the compiler's headers");
        free(files.a);
        return;
    }
    if (map_get(&g_news, r->nw, (size_t)r->nl) >= 0) { refuse(r, S_COLLISION, "new listed twice"); free(files.a); return; }
    if (r->json_names < 0) {
        refuse(r, S_COLLISION, "new already occurs in build/units.json (%.*s)", (int)g_names.a[-1 - r->json_names].len,
               g_json + g_names.a[-1 - r->json_names].off);
        free(files.a);
        return;
    }
    r->json_names = 0;
    if (r->kind == K_TYPE && !placeholder_type(r->old)) {
        refuse(r, S_AMBIGUOUS, "type '%s' is not a placeholder-like name", r->old);
        free(files.a);
        return;
    }
    for (i = 0; i < r->cands.n && r->status == S_PENDING; i++) {
        Name *nm = &g_names.a[r->cands.a[i]];
        const char *s = g_json + nm->off;
        int n = (int)nm->len, o, l, cpp;
        RewriteResult rr;
        rewrite_name(s, n, r->old, r->ol, r->nw, r->nl, &out, &rr);
        if (rr.ambiguous) { refuse(r, S_AMBIGUOUS, "%s in %.*s", rr.why, n, s); break; }
        if (!rr.count) continue;
        if (nm->role == R_FORBIDDEN) { refuse(r, S_AMBIGUOUS, "occurs in eh_tails or an escaped string (%.*s)", n, s); break; }
        if (contains_fragment(s, n, r->nw, r->nl)) {
            refuse(r, S_COLLISION, "new equals another fragment of %.*s (back-references would change)", n, s);
            break;
        }
        r->json_names++;
        if (!ivec_has(&r->units, nm->unit)) VPUSH(r->units, nm->unit);
        if (own_name(s, n, &o, &l, &cpp) && l == r->ol && !memcmp(s + o, r->old, (size_t)l)) {
            int64_t bound;
            int b = derived_prefix(s, n);
            owned++;
            if (r->kind == K_TYPE) {
                refuse(r, S_AMBIGUOUS, "type token also names a function or global: %.*s", n, s);
                break;
            }
            if (b) {   /* a derived name stands for its embedded name */
                int v = map_get(&g_bind, s + b, (size_t)(n - b));
                bound = v >= 0 ? g_bind_addr.a[v] : (int64_t)r->addr;
                if (v < 0 && b == 6) bound = r->addr;
            } else {
                bound = nm->addr;
            }
            if (bound != (int64_t)r->addr) {
                refuse(r, S_AMBIGUOUS, "%.*s is bound to 0x%08llx, not 0x%08x", n, s,
                       (unsigned long long)(bound < 0 ? 0 : bound), r->addr);
                break;
            }
            at_addr++;
            /* a global-scope name must not meet an SDK identifier (overloads, redeclarations) */
            if (g_sdk_tokens.s && map_get(&g_sdk_tokens, r->nw, (size_t)r->nl) >= 0 &&
                (!cpp || (o + l + 1 < n && s[o + l] == '@' && s[o + l + 1] == '@'))) {
                refuse(r, S_COLLISION, "new is an identifier of the compiler's headers and %.*s is at global scope", n, s);
                break;
            }
        } else if (r->kind == K_TYPE && nm->addr == r->addr) {
            at_addr++;
        }
    }
    free(out.p);
    if (r->status != S_PENDING) { free(files.a); return; }
    if (r->kind != K_TYPE && !owned) {
        refuse(r, S_NOTFOUND, "no decorated name in build/units.json has '%s' as its own name", r->old);
        free(files.a);
        return;
    }
    if (r->kind == K_TYPE && !at_addr) buf_printf(&r->reason, "note: no recipe name of the type binds 0x%08x; ", r->addr);
    r->status = S_APPLIED;
    *map_at(&g_news, r->nw, (size_t)r->nl, 1) = idx;
    for (i = 0; i < files.n; i++) VPUSH(r->files, files.a[i]);
    free(files.a);
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* applying: tokens */

static Map g_apply;   /* old -> rename index, applied renames only */

typedef struct { const char *data; Buf *out; size_t last; int changed; } ReplCtx;

static void repl_ident(void *vctx, size_t pos, size_t len, int in_comment)
{
    ReplCtx *c = (ReplCtx *)vctx;
    int r = map_get(&g_apply, c->data + pos, len);
    (void)in_comment;
    if (r < 0) return;
    buf_put(c->out, c->data + c->last, pos - c->last);
    buf_put(c->out, g_ren.a[r].nw, (size_t)g_ren.a[r].nl);
    c->last = pos + len;
    c->changed = 1;
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* applying: comments above definitions, markers at the end of declaration lines */

typedef struct { int line; int type; int ren; const char *text; } LineOp;   /* type 0: insert above, 1: append */
typedef VEC(LineOp) OpVec;

static int line_starts(const char *s, size_t n, IntVec *ls)
{
    size_t i;
    ls->n = 0;
    VPUSH(*ls, 0);
    for (i = 0; i < n; i++) if (s[i] == '\n') VPUSH(*ls, (int)(i + 1));
    return (int)ls->n;
}

static int is_kw(const char *d, const Tok *t, const char *kw)
{
    size_t n = strlen(kw);
    return t->t == T_ID && t->len == n && !memcmp(d + t->s, kw, n);
}

typedef struct { char kind; } Scope;   /* 'n' namespace-like, 'c' class body, 'e' enum, 'b' block, 'i' initializer */

/* the kind of block a '{' at token i opens; tokens [st, i) are its statement so far */
static char block_kind(const char *d, const Tok *t, int st, int i)
{
    int k, depth = 0, classkey = -1;
    if (st >= i) return 'b';
    if (is_kw(d, &t[st], "__if_exists") || is_kw(d, &t[st], "__if_not_exists")) return 'n';
    if (is_kw(d, &t[st], "extern") && st + 1 < i && t[st + 1].t == T_STR) return 'n';
    for (k = st; k < i; k++) if (is_kw(d, &t[k], "namespace")) return 'n';
    for (k = st; k < i; k++) {
        if (t[k].t == '(') depth++;
        else if (t[k].t == ')') depth--;
        else if (t[k].t == '=' && depth == 0) return 'i';
    }
    k = st;
    if (is_kw(d, &t[k], "template") && k + 1 < i && t[k + 1].t == '<') {   /* skip template<...> */
        int a = 0;
        for (k = k + 1; k < i; k++) {
            if (t[k].t == '<') a++;
            else if (t[k].t == '>') { if (--a == 0) { k++; break; } }
        }
    }
    if (k < i && (is_kw(d, &t[k], "typedef") || is_kw(d, &t[k], "friend"))) k++;
    if (k < i && (is_kw(d, &t[k], "struct") || is_kw(d, &t[k], "class") || is_kw(d, &t[k], "union") ||
                  is_kw(d, &t[k], "__interface"))) classkey = k;
    if (k < i && is_kw(d, &t[k], "enum")) return 'e';
    if (classkey >= 0) {
        /* struct [__declspec(...)] name [: bases] { -- no parameter list after the name */
        depth = 0;
        for (k = classkey + 1; k < i; k++) {
            if (is_kw(d, &t[k], "__declspec") && k + 1 < i && t[k + 1].t == '(') {
                int a = 0;
                for (k = k + 1; k < i; k++) {
                    if (t[k].t == '(') a++;
                    else if (t[k].t == ')' && --a == 0) break;
                }
                continue;
            }
            if (t[k].t == '<') depth++;
            else if (t[k].t == '>') depth--;
            else if (t[k].t == '(' && depth <= 0) return 'b';
        }
        return 'c';
    }
    return 'b';
}

typedef struct {
    int file;
    const char *d;
    size_t n;
    TokVec toks;
    IntVec ls;
    OpVec ops;
} FileWork;

/* statement start for a declaration at token i */
static int sig_line(FileWork *w, int st) { return (int)w->toks.a[st].line; }

static int line_is_blank_or_comment(const char *d, size_t n, const IntVec *ls, int line, int *in_block)
{
    size_t a = (size_t)ls->a[line], b = line + 1 < (int)ls->n ? (size_t)ls->a[line + 1] : n, i = a;
    int seen = 0;
    while (i < b) {
        char c = d[i];
        if (*in_block) {
            if (c == '*' && i + 1 < b && d[i + 1] == '/') { *in_block = 0; i += 2; continue; }
            i++;
            continue;
        }
        if (c == ' ' || c == '\t' || c == '\r' || c == '\n') { i++; continue; }
        if (c == '/' && i + 1 < b && d[i + 1] == '/') break;
        if (c == '/' && i + 1 < b && d[i + 1] == '*') { *in_block = 1; i += 2; continue; }
        seen = 1;
        break;
    }
    return !seen;
}

static void add_op(FileWork *w, int line, int type, int ren, const char *text)
{
    LineOp op;
    size_t i;
    for (i = 0; i < w->ops.n; i++)
        if (w->ops.a[i].line == line && w->ops.a[i].type == type && w->ops.a[i].ren == ren) return;
    op.line = line;
    op.type = type;
    op.ren = ren;
    op.text = text;
    VPUSH(w->ops, op);
}

static int line_has(FileWork *w, int line, const char *text)
{
    size_t a, b, tl = strlen(text), i;
    if (line < 0 || line >= (int)w->ls.n) return 0;
    a = (size_t)w->ls.a[line];
    b = line + 1 < (int)w->ls.n ? (size_t)w->ls.a[line + 1] : w->n;
    for (i = a; i + tl <= b; i++) if (!memcmp(w->d + i, text, tl)) return 1;
    return 0;
}

/* is the line above `line` (skipping nothing) exactly the comment? */
static int comment_above(FileWork *w, int line, const char *text)
{
    size_t a, b, tl = strlen(text);
    if (line <= 0) return 0;
    a = (size_t)w->ls.a[line - 1];
    b = (size_t)w->ls.a[line];
    while (a < b && (w->d[a] == ' ' || w->d[a] == '\t')) a++;
    while (b > a && (w->d[b - 1] == '\n' || w->d[b - 1] == '\r' || w->d[b - 1] == ' ' || w->d[b - 1] == '\t')) b--;
    return b - a == tl && !memcmp(w->d + a, text, tl);
}

static Map g_want;   /* new -> rename index, for renames with a comment or a marker */
static int stack_all_ns(const char *stack, int sp);

static void scan_file(FileWork *w, int use_locs_for_comments)
{
    const char *d = w->d;
    Tok *t;
    int i, nt, sp = 0, st = 0;
    char stack[512];
    lex_tokens(d, w->n, &w->toks);
    line_starts(d, w->n, &w->ls);
    t = w->toks.a;
    nt = (int)w->toks.n;
    for (i = 0; i < nt; i++) {
        char c = t[i].t;
        if (c == '{') {
            char k = block_kind(d, t, st, i);
            if (sp < (int)sizeof stack) stack[sp] = k;
            sp++;
            st = i + 1;
            continue;
        }
        if (c == '}') {
            char k = sp > 0 && sp <= (int)sizeof stack ? stack[sp - 1] : 'b';
            if (sp > 0) sp--;
            if (k == 'n' || k == 'b') st = i + 1;
            continue;
        }
        if (c == ';') { st = i + 1; continue; }
        if (c == ':' && i > st && i - 1 == st &&
            (is_kw(d, &t[st], "public") || is_kw(d, &t[st], "private") || is_kw(d, &t[st], "protected"))) {
            st = i + 1;
            continue;
        }
        if (c == T_ID) {
            int r, j, declscope = 1, k;
            Rename *R;
            for (j = 0; j < sp && j < (int)sizeof stack; j++) if (stack[j] != 'n' && stack[j] != 'c') declscope = 0;
            if (!declscope) continue;
            r = map_get(&g_want, d + t[i].s, t[i].len);
            if (r < 0) continue;
            R = &g_ren.a[r];
            if (i > 0 && (t[i - 1].t == '.' || t[i - 1].t == T_ARROW)) continue;
            if (R->kind == K_FUNCTION) {
                int depth = 0;
                if (!R->comment[0] || use_locs_for_comments) continue;
                if (i + 1 >= nt || t[i + 1].t != '(') continue;
                if (i > 0 && t[i - 1].t == '~') continue;
                for (k = i + 1; k < nt; k++) {
                    if (t[k].t == '(') depth++;
                    else if (t[k].t == ')' && --depth == 0) break;
                }
                for (k = k + 1; k < nt; k++) {
                    if (is_kw(d, &t[k], "const") || is_kw(d, &t[k], "volatile") || is_kw(d, &t[k], "__restrict")) continue;
                    if (is_kw(d, &t[k], "throw") && k + 1 < nt && t[k + 1].t == '(') {
                        int a = 0;
                        for (k = k + 1; k < nt; k++) {
                            if (t[k].t == '(') a++;
                            else if (t[k].t == ')' && --a == 0) break;
                        }
                        continue;
                    }
                    break;
                }
                if (k < nt && (t[k].t == '{' || t[k].t == ':' || is_kw(d, &t[k], "try"))) {
                    int line = sig_line(w, st);
                    if (!comment_above(w, line, R->comment)) add_op(w, line, 0, r, R->comment);
                }
            } else {
                int is_decl = 0, is_def = 0, depth = 0, eq = 0, ext = 0, td = 0;
                for (k = st; k < i; k++) {
                    if (t[k].t == '(' || t[k].t == '[' || t[k].t == '<') depth++;
                    else if (t[k].t == ')' || t[k].t == ']' || t[k].t == '>') depth--;
                    else if (t[k].t == '=' && depth == 0) eq = 1;
                    else if (is_kw(d, &t[k], "extern")) ext = 1;
                    else if (is_kw(d, &t[k], "typedef")) td = 1;
                }
                if (R->kind == K_GLOBAL) {
                    /* a declarator in parentheses: (__stdcall *name)(...), (*name)[4] */
                    int grouped = depth > 0 && i + 1 < nt && t[i + 1].t == ')';
                    if (grouped) {
                        int a = 0, stars = 0;
                        for (k = st; k < i; k++) {   /* only parentheses open: not inside a parameter list */
                            if (t[k].t == '(') a++;
                            else if (t[k].t == ')') a--;
                        }
                        if (a != 1) grouped = 0;
                        for (k = i - 1; grouped && k >= st && t[k].t != '('; k--) {
                            if (t[k].t == '*') stars++;
                            else if (t[k].t != T_ID) grouped = 0;   /* const, __stdcall, ... */
                        }
                        if (!stars) grouped = 0;
                    }
                    if ((depth == 0 || grouped) && !eq && !td && i > st &&
                        (i + 1 >= nt || (t[i + 1].t != '(' && t[i + 1].t != T_SCOPE))) {
                        is_decl = 1;
                        is_def = !ext && stack_all_ns(stack, sp);
                    }
                } else {
                    int p = i - 1;
                    /* struct [__declspec(...)] new { | : | ; */
                    if (p >= st && t[p].t == ')') {
                        int a = 0;
                        for (; p >= st; p--) {
                            if (t[p].t == ')') a++;
                            else if (t[p].t == '(' && --a == 0) break;
                        }
                        p--;
                        if (p >= st && is_kw(d, &t[p], "__declspec")) p--;
                    }
                    if (p >= st && (is_kw(d, &t[p], "struct") || is_kw(d, &t[p], "class") || is_kw(d, &t[p], "union") ||
                                    is_kw(d, &t[p], "enum") || is_kw(d, &t[p], "__interface")) &&
                        i + 1 < nt && depth == 0 && !is_kw(d, &t[st], "friend")) {
                        char nx = t[i + 1].t;
                        if (nx == '{' || nx == ':') is_decl = is_def = 1;
                        else if (nx == ';' && (p == st || is_kw(d, &t[st], "template"))) is_decl = 1;
                    } else if (td && depth == 0 && i + 1 < nt && (t[i + 1].t == ';' || t[i + 1].t == ',')) {
                        is_decl = is_def = 1;
                    }
                }
                if (is_decl && R->marker[0] && !line_has(w, (int)t[i].line, R->marker))
                    add_op(w, (int)t[i].line, 1, r, R->marker);
                if (is_def && R->comment[0]) {
                    int line = sig_line(w, st);
                    if (!comment_above(w, line, R->comment)) add_op(w, line, 0, r, R->comment);
                }
            }
        }
    }
}

/* helper used above (declared after use for readability) */
static int stack_all_ns(const char *stack, int sp)
{
    int j;
    for (j = 0; j < sp && j < 512; j++) if (stack[j] != 'n') return 0;
    return 1;
}

static int cmp_ops(const void *a, const void *b)
{
    const LineOp *x = (const LineOp *)a, *y = (const LineOp *)b;
    if (x->line != y->line) return x->line - y->line;
    if (x->type != y->type) return x->type - y->type;
    return x->ren - y->ren;
}

/* build the file with its line operations */
static void apply_ops(FileWork *w, Buf *out)
{
    size_t i = 0;
    int line, crlf = 0;
    const char *nlp = memchr(w->d, '\n', w->n);
    if (nlp && nlp > w->d && nlp[-1] == '\r') crlf = 1;
    qsort(w->ops.a, w->ops.n, sizeof(LineOp), cmp_ops);
    out->n = 0;
    for (line = 0; line < (int)w->ls.n; line++) {
        size_t a = (size_t)w->ls.a[line], b = line + 1 < (int)w->ls.n ? (size_t)w->ls.a[line + 1] : w->n, e = b;
        size_t ind = a;
        while (ind < b && (w->d[ind] == ' ' || w->d[ind] == '\t')) ind++;
        while (i < w->ops.n && w->ops.a[i].line == line && w->ops.a[i].type == 0) {
            buf_put(out, w->d + a, ind - a);
            buf_puts(out, w->ops.a[i].text);
            buf_puts(out, crlf ? "\r\n" : "\n");
            g_ren.a[w->ops.a[i].ren].comments++;
            i++;
        }
        if (e > a && w->d[e - 1] == '\n') e--;
        if (e > a && w->d[e - 1] == '\r') e--;
        buf_put(out, w->d + a, e - a);
        while (i < w->ops.n && w->ops.a[i].line == line && w->ops.a[i].type == 1) {
            if (!(e > a && w->d[e - 1] == '\\')) {
                size_t z = e;
                while (z > a && (w->d[z - 1] == ' ' || w->d[z - 1] == '\t')) z--;
                if (z < e) out->n -= e - z;   /* trailing blanks go: one space before the marker */
                buf_putc(out, ' ');
                buf_puts(out, w->ops.a[i].text);
                g_ren.a[w->ops.a[i].ren].markers++;
            }
            i++;
        }
        buf_put(out, w->d + e, b - e);
    }
}

/* comments at the locations the rule checker reports: first_line, past blank and comment lines, must reach a line
 * holding the new name within 15 lines */
static int place_by_locations(FileWork *w, int r)
{
    Rename *R = &g_ren.a[r];
    size_t i;
    int placed = 0;
    for (i = 0; i < g_locs.n; i++) {
        Loc *l = &g_locs.a[i];
        int line, inb = 0, k, ok = 0;
        if (l->addr != R->addr || l->file != w->file) continue;
        line = l->line - 1;
        if (line >= (int)w->ls.n) continue;
        while (line < (int)w->ls.n && line_is_blank_or_comment(w->d, w->n, &w->ls, line, &inb)) line++;
        for (k = line; k < line + 15 && k < (int)w->ls.n; k++) {
            size_t a = (size_t)w->ls.a[k], b = k + 1 < (int)w->ls.n ? (size_t)w->ls.a[k + 1] : w->n, p;
            for (p = a; p + R->nl <= b; p++)
                if (!memcmp(w->d + p, R->nw, (size_t)R->nl) && (p == 0 || !is_id_char((unsigned char)w->d[p - 1])) &&
                    (p + R->nl >= w->n || !is_id_char((unsigned char)w->d[p + R->nl]))) { ok = 1; break; }
            if (ok) break;
        }
        if (!ok) continue;
        placed = 1;
        if (!comment_above(w, line, R->comment)) add_op(w, line, 0, r, R->comment);
    }
    return placed;
}

/* fallback for a function without a syntactic definition: the line after its // @f3 0x<address> annotation that
 * holds the new name */
static void place_by_annotation(FileWork *w, int r)
{
    Rename *R = &g_ren.a[r];
    char ann[32];
    size_t al, p;
    snprintf(ann, sizeof ann, "@f3 0x%08x", R->addr);
    al = strlen(ann);
    for (p = 0; p + al <= w->n; p++) {
        if (memcmp(w->d + p, ann, al)) continue;
        {
            int line = 0, k;
            while (line + 1 < (int)w->ls.n && (size_t)w->ls.a[line + 1] <= p) line++;
            for (k = line + 1; k < (int)w->ls.n && k < line + 40; k++) {
                size_t a = (size_t)w->ls.a[k], b = k + 1 < (int)w->ls.n ? (size_t)w->ls.a[k + 1] : w->n, q;
                int hit = 0;
                for (q = a; q + R->nl <= b; q++)
                    if (!memcmp(w->d + q, R->nw, (size_t)R->nl) && (q == 0 || !is_id_char((unsigned char)w->d[q - 1])) &&
                        !is_id_char((unsigned char)w->d[q + R->nl])) { hit = 1; break; }
                if (hit) {
                    if (!comment_above(w, k, R->comment)) add_op(w, k, 0, r, R->comment);
                    return;
                }
            }
        }
    }
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* apply */

static __declspec(noreturn) void usage(void)
{
    fputs("usage:\n"
          "  f3rename apply  --root TREE --renames LIST.tsv [--locations LOC.tsv] [--report OUT.tsv] [--dry-run]\n"
          "                  [--sdk DIR]... [--no-sdk]\n"
          "  f3rename bisect --root TREE --renames LIST.tsv --applied REPORT.tsv --compare FILE... --out REDUCED.tsv\n"
          "                  [--dropped DROPPED.tsv]\n", stderr);
    exit(2);
}

static void tsv_field(Buf *b, const char *s)
{
    for (; *s; s++) buf_putc(b, (*s == '\t' || *s == '\n' || *s == '\r') ? ' ' : *s);
}

static int cmp_int(const void *a, const void *b) { int x = *(const int *)a, y = *(const int *)b; return x < y ? -1 : x > y; }

static int cmd_apply(int argc, char **argv)
{
    const char *renames = NULL, *locations = NULL, *report = NULL;
    VEC(const char *) sdk = { 0 };
    int dry = 0, nosdk = 0, i, written = 0;
    size_t k;
    double t0 = now_s(), t;
    int counts[5] = { 0 };
    Buf rep = { 0 };

    for (i = 0; i < argc; i++) {
        if (!strcmp(argv[i], "--root") && i + 1 < argc) g_root = root_arg(argv[++i]);
        else if (!strcmp(argv[i], "--renames") && i + 1 < argc) renames = argv[++i];
        else if (!strcmp(argv[i], "--locations") && i + 1 < argc) locations = argv[++i];
        else if (!strcmp(argv[i], "--report") && i + 1 < argc) report = argv[++i];
        else if (!strcmp(argv[i], "--sdk") && i + 1 < argc) VPUSH(sdk, argv[++i]);
        else if (!strcmp(argv[i], "--no-sdk")) nosdk = 1;
        else if (!strcmp(argv[i], "--dry-run")) dry = 1;
        else usage();
    }
    if (!g_root || !renames) usage();
    { size_t rl = strlen(g_root); while (rl > 1 && g_root[rl - 1] == '/') g_root[--rl] = 0; }
    if (!nosdk && !sdk.n) {
        const char *m = getenv("F3_MSVC_ROOT");
        if (m && *m) {
            char *a = (char *)xmalloc(strlen(m) + 16), *b = (char *)xmalloc(strlen(m) + 16);
            sprintf(a, "%s/VC/include", m);
            sprintf(b, "%s/SDK/Include", m);
            VPUSH(sdk, a);
            VPUSH(sdk, b);
        } else {
            fprintf(stderr, "f3rename: F3_MSVC_ROOT not set and no --sdk: the compiler's headers are not checked\n");
        }
    }

    load_renames(renames);
    load_tree();
    build_index();
    t = now_s();
    fprintf(stderr, "f3rename: %zu files, %zu identifiers indexed (%.1fs)\n", g_files.n, g_tokens.count, t - t0);
    if (sdk.n) {
        map_init(&g_sdk_tokens, 1 << 18);
        map_init(&g_sdk_macros, 1 << 16);
        for (k = 0; k < sdk.n; k++) sdk_walk(sdk.a[k]);
        fprintf(stderr, "f3rename: compiler headers: %zu files, %zu identifiers, %zu macros (%.1fs)\n", g_sdk_files,
                g_sdk_tokens.count, g_sdk_macros.count, now_s() - t);
    }
    if (locations) load_locations(locations);
    load_recipe();
    fprintf(stderr, "f3rename: build/units.json: %zu units, %zu names\n", g_unit_src.n, g_names.n);
    map_init(&g_olds, g_ren.n + 16);
    map_init(&g_news, g_ren.n + 16);
    find_candidates();
    for (k = 0; k < g_ren.n; k++) decide(&g_ren.a[k], (int)k);

    /* tokens */
    map_init(&g_apply, g_ren.n + 16);
    map_init(&g_want, g_ren.n + 16);
    for (k = 0; k < g_ren.n; k++) {
        Rename *r = &g_ren.a[k];
        if (r->status != S_APPLIED) continue;
        *map_at(&g_apply, r->old, (size_t)r->ol, 1) = (int)k;
        if (r->comment[0] || r->marker[0]) *map_at(&g_want, r->nw, (size_t)r->nl, 1) = (int)k;
    }
    {
        char *touched = (char *)xcalloc(g_files.n, 1);
        for (k = 0; k < g_ren.n; k++) {
            size_t j;
            if (g_ren.a[k].status != S_APPLIED) continue;
            for (j = 0; j < g_ren.a[k].files.n; j++) touched[g_ren.a[k].files.a[j]] = 1;
        }
        for (k = 0; k < g_files.n; k++) {
            SrcFile *f = &g_files.a[k];
            Buf out = { 0 };
            ReplCtx c;
            if (!touched[k]) continue;
            c.data = f->data; c.out = &out; c.last = 0; c.changed = 0;
            lex_idents(f->data, f->len, repl_ident, &c);
            buf_put(&out, f->data + c.last, f->len - c.last);
            if (c.changed) { f->out = out.p; f->outlen = out.n; } else free(out.p);
        }
        /* comments and markers */
        for (k = 0; k < g_files.n; k++) {
            SrcFile *f = &g_files.a[k];
            FileWork w;
            size_t j;
            if (!touched[k] || !f->out || !g_want.count) continue;
            memset(&w, 0, sizeof w);
            w.file = (int)k;
            w.d = f->out;
            w.n = f->outlen;
            scan_file(&w, 0);
            /* functions with rule-checker locations in this file use them instead of the syntactic sites */
            if (g_locs.n) {
                for (j = 0; j < g_ren.n; j++) {
                    Rename *r = &g_ren.a[j];
                    size_t q;
                    if (r->status != S_APPLIED || r->kind != K_FUNCTION || !r->comment[0]) continue;
                    if (!ivec_has(&r->files, (int)k)) continue;
                    if (place_by_locations(&w, (int)j)) {
                        /* drop syntactic sites of this rename in this file that the location already covers */
                        size_t o = 0;
                        for (q = 0; q < w.ops.n; q++) {
                            LineOp *op = &w.ops.a[q];
                            int keep = 1;
                            if (op->ren == (int)j && op->type == 0) {
                                size_t z;
                                int from_loc = 0;
                                for (z = 0; z < g_locs.n; z++)
                                    if (g_locs.a[z].addr == r->addr && g_locs.a[z].file == (int)k) {
                                        int ln = g_locs.a[z].line - 1, inb = 0;
                                        while (ln < (int)w.ls.n && line_is_blank_or_comment(w.d, w.n, &w.ls, ln, &inb)) ln++;
                                        if (ln == op->line) from_loc = 1;
                                    }
                                keep = from_loc;
                            }
                            if (keep) w.ops.a[o++] = *op;
                        }
                        w.ops.n = o;
                    }
                }
            }
            if (w.ops.n) {
                Buf out = { 0 };
                apply_ops(&w, &out);
                free(f->out);
                f->out = out.p;
                f->outlen = out.n;
            }
            free(w.toks.a); free(w.ls.a); free(w.ops.a);
        }
        /* annotation fallback for functions with a comment and no definition found anywhere */
        for (k = 0; k < g_ren.n; k++) {
            Rename *r = &g_ren.a[k];
            size_t j;
            if (r->status != S_APPLIED || r->kind != K_FUNCTION || !r->comment[0] || r->comments) continue;
            for (j = 0; j < r->files.n; j++) {
                SrcFile *f = &g_files.a[r->files.a[j]];
                FileWork w;
                if (!f->out) continue;
                memset(&w, 0, sizeof w);
                w.file = r->files.a[j];
                w.d = f->out;
                w.n = f->outlen;
                line_starts(w.d, w.n, &w.ls);
                place_by_annotation(&w, (int)k);
                if (w.ops.n) {
                    Buf out = { 0 };
                    apply_ops(&w, &out);
                    free(f->out);
                    f->out = out.p;
                    f->outlen = out.n;
                }
                free(w.ls.a); free(w.ops.a);
            }
            if (!r->comments) buf_puts(&r->reason, "comment not placed (no definition found); ");
        }
        free(touched);
    }

    /* build/units.json: each touched name gets every applied rename that names it, in list order */
    {
        Buf out = { 0 }, tmp = { 0 }, cur = { 0 };
        size_t last = 0, nchanged = 0, a;
        int32_t *head = (int32_t *)xmalloc(sizeof(int32_t) * (g_names.n + 1));
        VEC(int32_t) link_next = { 0 };
        VEC(int32_t) link_ren = { 0 };
        IntVec touched_names = { 0 };
        for (a = 0; a < g_names.n; a++) head[a] = -1;
        for (k = g_ren.n; k-- > 0; ) {   /* backwards, so each list is in list order */
            Rename *r = &g_ren.a[k];
            size_t j;
            if (r->status != S_APPLIED) continue;
            for (j = 0; j < r->cands.n; j++) {
                int nmi = r->cands.a[j];
                if (head[nmi] < 0) VPUSH(touched_names, nmi);
                VPUSH(link_next, head[nmi]);
                VPUSH(link_ren, (int32_t)k);
                head[nmi] = (int32_t)link_ren.n - 1;
            }
        }
        qsort(touched_names.a, touched_names.n, sizeof(int), cmp_int);   /* names are in file order */
        for (a = 0; a < touched_names.n; a++) {
            Name *nm = &g_names.a[touched_names.a[a]];
            int32_t l;
            cur.n = 0;
            buf_put(&cur, g_json + nm->off, nm->len);
            for (l = head[touched_names.a[a]]; l >= 0; l = link_next.a[l]) {
                Rename *r = &g_ren.a[link_ren.a[l]];
                RewriteResult rr;
                rewrite_name(cur.p, (int)cur.n, r->old, r->ol, r->nw, r->nl, &tmp, &rr);
                if (rr.count && !rr.ambiguous) { cur.n = 0; buf_put(&cur, tmp.p, tmp.n); }
            }
            if (cur.n != nm->len || memcmp(cur.p, g_json + nm->off, nm->len)) {
                buf_put(&out, g_json + last, nm->off - last);
                buf_put(&out, cur.p, cur.n);
                last = nm->off + nm->len;
                nchanged++;
            }
        }
        buf_put(&out, g_json + last, g_json_len - last);
        if (nchanged && !dry) {
            char path[MAX_PATH * 2];
            snprintf(path, sizeof path, "%s/build/units.json", g_root);
            write_all(path, out.p, out.n);
        }
        fprintf(stderr, "f3rename: build/units.json: %zu names rewritten\n", nchanged);
        free(out.p); free(tmp.p); free(cur.p); free(head); free(link_next.a); free(link_ren.a); free(touched_names.a);
    }

    /* write the tree */
    for (k = 0; k < g_files.n; k++) {
        SrcFile *f = &g_files.a[k];
        if (!f->out || (f->outlen == f->len && !memcmp(f->out, f->data, f->len))) continue;
        written++;
        if (!dry) {
            char path[MAX_PATH * 2];
            snprintf(path, sizeof path, "%s/%s", g_root, f->rel);
            write_all(path, f->out, f->outlen);
        }
    }

    /* report */
    buf_puts(&rep, "kind\taddress\told\tnew\tstatus\treason\tfiles\tunits\tcomments\tmarkers\n");
    for (k = 0; k < g_ren.n; k++) {
        Rename *r = &g_ren.a[k];
        size_t j;
        counts[r->status]++;
        tsv_field(&rep, r->kind_s); buf_putc(&rep, '\t');
        tsv_field(&rep, r->addr_s); buf_putc(&rep, '\t');
        tsv_field(&rep, r->old); buf_putc(&rep, '\t');
        tsv_field(&rep, r->nw); buf_putc(&rep, '\t');
        buf_puts(&rep, STATUS[r->status]); buf_putc(&rep, '\t');
        while (r->reason.n && (r->reason.p[r->reason.n - 1] == ' ' || r->reason.p[r->reason.n - 1] == ';')) r->reason.p[--r->reason.n] = 0;
        tsv_field(&rep, r->reason.p ? r->reason.p : ""); buf_putc(&rep, '\t');
        if (r->status == S_APPLIED) {
            for (j = 0; j < r->files.n; j++) {
                if (j) buf_putc(&rep, ';');
                buf_puts(&rep, g_files.a[r->files.a[j]].rel);
            }
            if (r->json_names) buf_puts(&rep, r->files.n ? ";build/units.json" : "build/units.json");
            buf_putc(&rep, '\t');
            for (j = 0; j < r->units.n; j++) {
                Span sp = g_unit_src.a[r->units.a[j]];
                if (j) buf_putc(&rep, ';');
                buf_put(&rep, g_json + sp.off, sp.len);
            }
            buf_printf(&rep, "\t%d\t%d\n", r->comments, r->markers);
        } else {
            buf_puts(&rep, "\t\t0\t0\n");
        }
    }
    if (report) write_all(report, rep.p, rep.n);
    else fwrite(rep.p, 1, rep.n, stdout);
    fprintf(stderr, "f3rename: %zu renames: applied %d, ambiguous %d, collision %d, not-found %d; %d files %s (%.1fs)\n",
            g_ren.n, counts[S_APPLIED], counts[S_AMBIGUOUS], counts[S_COLLISION], counts[S_NOTFOUND], written,
            dry ? "would change (dry run)" : "changed", now_s() - t0);
    (void)KIND;
    return 0;
}

/* ---------------------------------------------------------------------------------------------------------------- */
/* bisect: drop the renames that touched units a compare_builds report names */

static Map g_tail;                 /* lower-case path tail -> index into g_tail_files */
static VEC(IntVec) g_tail_files;

static char *lower_dup(const char *s, size_t n)
{
    char *p = xstrndup(s, n), *q;
    for (q = p; *q; q++) { if (*q >= 'A' && *q <= 'Z') *q = (char)(*q - 'A' + 'a'); if (*q == '\\') *q = '/'; }
    return p;
}

static void build_tails(void)
{
    size_t i;
    map_init(&g_tail, g_files.n * 4);
    for (i = 0; i < g_files.n; i++) {
        char *low = lower_dup(g_files.a[i].rel, strlen(g_files.a[i].rel));
        size_t n = strlen(low);
        int p;
        for (p = (int)n; p >= 0; p--) {
            if (p == 0 || low[p - 1] == '/') {
                int32_t *v = map_at(&g_tail, low + p, n - (size_t)p, 1);
                if (*v < 0) {
                    IntVec e = { 0 };
                    *v = (int32_t)g_tail_files.n;
                    VPUSH(g_tail_files, e);
                }
                VPUSH(g_tail_files.a[*v], (int)i);
            }
        }
    }
}

/* the files a file may include (as compare_builds.py resolves includes: every file whose path ends with the name) */
static void includes_of(int f, IntVec *out)
{
    const char *s = g_files.a[f].data;
    size_t n = g_files.a[f].len, i = 0;
    out->n = 0;
    while (i < n) {
        size_t j = i, e;
        while (j < n && (s[j] == ' ' || s[j] == '\t')) j++;
        e = j;
        while (e < n && s[e] != '\n') e++;
        if (j < n && s[j] == '#') {
            size_t k = j + 1;
            while (k < e && (s[k] == ' ' || s[k] == '\t')) k++;
            if (e - k > 7 && !memcmp(s + k, "include", 7)) {
                k += 7;
                while (k < e && (s[k] == ' ' || s[k] == '\t')) k++;
                if (k < e && (s[k] == '"' || s[k] == '<')) {
                    char close = s[k] == '<' ? '>' : '"';
                    size_t a = k + 1, b = a;
                    while (b < e && s[b] != close) b++;
                    if (b < e) {
                        char *low = lower_dup(s + a, b - a), *key = (char *)xmalloc(strlen(low) + 1), *q, *tok;
                        int v;
                        key[0] = 0;
                        for (tok = strtok(low, "/"); tok; tok = strtok(NULL, "/")) {
                            if (!strcmp(tok, ".")) continue;
                            if (key[0]) strcat(key, "/");
                            strcat(key, tok);
                        }
                        q = key;
                        while (!strncmp(q, "../", 3)) q += 3;
                        v = map_get(&g_tail, q, strlen(q));
                        if (v >= 0) {
                            size_t z;
                            for (z = 0; z < g_tail_files.a[v].n; z++) VPUSH(*out, g_tail_files.a[v].a[z]);
                        }
                        free(low);
                        free(key);
                    }
                }
            }
        }
        i = e + 1;
    }
}

static void closure_of(int f, char *seen)
{
    IntVec todo = { 0 }, inc = { 0 };
    VPUSH(todo, f);
    seen[f] = 1;
    while (todo.n) {
        int x = todo.a[--todo.n];
        size_t j;
        includes_of(x, &inc);
        for (j = 0; j < inc.n; j++) if (!seen[inc.a[j]]) { seen[inc.a[j]] = 1; VPUSH(todo, inc.a[j]); }
    }
    free(todo.a);
    free(inc.a);
}

typedef VEC(char *) StrVec;

static void add_unique(StrVec *v, const char *s, size_t n)
{
    size_t i;
    for (i = 0; i < v->n; i++) if (strlen(v->a[i]) == n && !memcmp(v->a[i], s, n)) return;
    VPUSH(*v, xstrndup(s, n));
}

/* units a compare_builds report or shard result names as not identical */
static void bad_units(const char *path, StrVec *bad)
{
    size_t len, i = 0;
    char *d = read_all(path, &len);
    if (!d) die("cannot read %s", path);
    while (i < len && (d[i] == ' ' || d[i] == '\r' || d[i] == '\n' || d[i] == '\t')) i++;
    if (i < len && d[i] == '{') {   /* a shard result: units[] rows with source and status */
        int root, units, u;
        size_t save_n = g_jn.n;
        const char *sj = J;
        size_t sl = JL, sp = JP;
        J = d; JL = len; JP = 0;
        root = jvalue();
        units = jget(root, "units");
        if (units >= 0)
            for (u = g_jn.a[units].first; u >= 0; u = g_jn.a[u].next) {
                int src = jget(u, "source"), st = jget(u, "status");
                if (src < 0 || st < 0) continue;
                if (g_jn.a[st].e - g_jn.a[st].s == 9 && !memcmp(d + g_jn.a[st].s, "identical", 9)) continue;
                add_unique(bad, d + g_jn.a[src].s, g_jn.a[src].e - g_jn.a[src].s);
            }
        g_jn.n = save_n;
        J = sj; JL = sl; JP = sp;
    } else {                        /* the report's text: "- `source`..." lines */
        char *p = d;
        while (p && *p) {
            char *nl = strchr(p, '\n');
            if (!strncmp(p, "- `", 3)) {
                char *e = strchr(p + 3, '`');
                if (e && (!nl || e < nl)) add_unique(bad, p + 3, (size_t)(e - p - 3));
            }
            p = nl ? nl + 1 : NULL;
        }
    }
    free(d);
}

static int cmd_bisect(int argc, char **argv)
{
    const char *renames = NULL, *applied = NULL, *out = NULL, *dropped = NULL;
    StrVec compares = { 0 }, bad = { 0 }, drop_keys = { 0 };
    int i, kept = 0, ndrop = 0;
    size_t k, len;
    char *seen, *d, *p;
    Buf o = { 0 }, dr = { 0 };

    for (i = 0; i < argc; i++) {
        if (!strcmp(argv[i], "--root") && i + 1 < argc) g_root = root_arg(argv[++i]);
        else if (!strcmp(argv[i], "--renames") && i + 1 < argc) renames = argv[++i];
        else if (!strcmp(argv[i], "--applied") && i + 1 < argc) applied = argv[++i];
        else if (!strcmp(argv[i], "--compare") && i + 1 < argc) VPUSH(compares, argv[++i]);
        else if (!strcmp(argv[i], "--out") && i + 1 < argc) out = argv[++i];
        else if (!strcmp(argv[i], "--dropped") && i + 1 < argc) dropped = argv[++i];
        else if (argv[i][0] != '-' && compares.n) VPUSH(compares, argv[i]);
        else usage();
    }
    if (!g_root || !renames || !applied || !out || !compares.n) usage();
    load_tree();
    build_tails();
    for (k = 0; k < compares.n; k++) bad_units(compares.a[k], &bad);
    fprintf(stderr, "f3rename: %zu units not identical in the compare results\n", bad.n);
    seen = (char *)xcalloc(g_files.n, 1);
    for (k = 0; k < bad.n; k++) {
        int f = find_file(bad.a[k]);
        if (f >= 0) closure_of(f, seen);
        else fprintf(stderr, "f3rename: %s: not in the tree\n", bad.a[k]);
    }
    /* the applied report: a rename is dropped when a file it touched is in a bad unit's include closure, or it
     * changed a bad unit's recipe entry */
    d = read_all(applied, &len);
    if (!d) die("cannot read %s", applied);
    for (p = d; p && *p; ) {
        char *nl = strchr(p, '\n'), *f[12], *line = p;
        int nf, hit = 0;
        if (nl) *nl = 0;
        p = nl ? nl + 1 : NULL;
        nf = split_tabs(line, f, 12);
        if (nf < 8 || !strcmp(f[0], "kind") || strcmp(f[4], "applied")) continue;
        {
            char *files = xstrdup(f[6]), *tok;
            for (tok = strtok(files, ";"); tok && !hit; tok = strtok(NULL, ";")) {
                int fi = find_file(tok);
                if (fi >= 0 && seen[fi]) hit = 1;
            }
            free(files);
        }
        if (!hit) {
            char *units = xstrdup(f[7]), *tok;
            for (tok = strtok(units, ";"); tok && !hit; tok = strtok(NULL, ";"))
                for (k = 0; k < bad.n; k++) if (!strcmp(bad.a[k], tok)) hit = 1;
            free(units);
        }
        if (hit) {
            Buf key = { 0 };
            buf_printf(&key, "%s\t%s\t%s\t%s", f[0], f[1], f[2], f[3]);
            VPUSH(drop_keys, key.p);
        }
    }
    free(d);
    d = read_all(renames, &len);
    if (!d) die("cannot read %s", renames);
    for (p = d; p && *p; ) {
        char *nl = strchr(p, '\n'), *line = p, *copy, *f[8];
        int nf, drop = 0;
        size_t ll;
        if (nl) *nl = 0;
        p = nl ? nl + 1 : NULL;
        ll = strlen(line);
        copy = xstrdup(line);
        nf = split_tabs(copy, f, 8);
        if (nf >= 4 && strcmp(f[0], "kind")) {
            Buf key = { 0 };
            buf_printf(&key, "%s\t%s\t%s\t%s", f[0], f[1], f[2], f[3]);
            for (k = 0; k < drop_keys.n; k++) if (!strcmp(drop_keys.a[k], key.p)) drop = 1;
            free(key.p);
        }
        free(copy);
        if (!ll && !p) break;
        if (drop) { buf_put(&dr, line, ll); buf_putc(&dr, '\n'); ndrop++; }
        else { buf_put(&o, line, ll); buf_putc(&o, '\n'); if (nf >= 4 && strncmp(line, "kind\t", 5)) kept++; }
    }
    free(d);
    write_all(out, o.p, o.n);
    if (dropped) write_all(dropped, dr.p ? dr.p : "", dr.n);
    fprintf(stderr, "f3rename: %d renames dropped, %d kept -> %s\n", ndrop, kept, out);
    for (k = 0; k < bad.n; k++) fprintf(stderr, "  bad unit: %s\n", bad.a[k]);
    return 0;
}

int main(int argc, char **argv)
{

    if (argc < 2) usage();
    if (!strcmp(argv[1], "apply")) return cmd_apply(argc - 2, argv + 2);
    if (!strcmp(argv[1], "bisect")) return cmd_bisect(argc - 2, argv + 2);
    usage();

}

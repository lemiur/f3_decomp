/* lex.c - see lex.h. Preprocessor directives are not tokens; tokens inside "#if 0" (or "#elif 0") branches are
   dropped, every other branch is kept. Each token records its #if branch so two definitions in exclusive branches
   can be told apart. */
#include "util.h"
#include "lex.h"

static const char *puncts3[] = {">>=", "<<=", "...", "->*", NULL};
static const char *puncts2[] = {"->", "++", "--", "<<", ">>", "<=", ">=", "==", "!=", "&&", "||", "+=", "-=", "*=",
                                "/=", "%=", "&=", "|=", "^=", "::", ".*", "##", NULL};

typedef struct {
    int group, branch, parent_node, active;
} Frame;

static int is_ident_start(int c) { return isalpha(c) || c == '_' || c == '$'; }
static int is_ident_char(int c) { return isalnum(c) || c == '_' || c == '$'; }

static int cond_is_zero(const char *s, int n)
{
    /* trims spaces and a trailing comment; accepts "0" and "(0)" */
    char buf[64];
    int k = 0;
    for (int i = 0; i < n && k < 63; i++) {
        if (s[i] == '/' && i + 1 < n && (s[i + 1] == '/' || s[i + 1] == '*')) break;
        if (!isspace((unsigned char)s[i])) buf[k++] = s[i];
    }
    buf[k] = 0;
    return strcmp(buf, "0") == 0 || strcmp(buf, "(0)") == 0;
}

int lex_file(const char *path, Lexed *L)
{
    memset(L, 0, sizeof *L);
    size_t sz;
    char *t = read_file(path, &sz);
    if (!t) return -1;
    L->text = t;
    L->size = (int)sz;
    VEC(int) lo = {0};
    VPUSH(lo, 0);
    for (int i = 0; i < L->size; i++)
        if (t[i] == '\n') VPUSH(lo, i + 1);
    L->line_off = lo.v;
    L->nlines = lo.n;

    VEC(Tok) toks = {0};
    VEC(Comment) coms = {0};
    VEC(CondNode) conds = {0};
    VEC(int) if0 = {0};
    VEC(char *) incs = {0};
    VEC(Frame) st = {0};
    CondNode root = {-1, 0, 0};
    VPUSH(conds, root);
    int cur_node = 0, ngroups = 0, active = 1;

    int p = 0, line = 1, bol = 1, n = L->size;
    while (p < n) {
        int c = (unsigned char)t[p];
        if (c == '\n') {
            line++;
            p++;
            bol = 1;
            continue;
        }
        if (c == ' ' || c == '\t' || c == '\r' || c == '\f' || c == '\v') {
            p++;
            continue;
        }
        if (c == '\\' && (p + 1 < n) && (t[p + 1] == '\n' || (t[p + 1] == '\r' && p + 2 < n && t[p + 2] == '\n'))) {
            p += (t[p + 1] == '\n') ? 2 : 3;
            line++;
            continue;
        }
        if (bol && c == '#') {
            /* directive */
            int dline = line;
            p++;
            while (p < n && (t[p] == ' ' || t[p] == '\t')) p++;
            int ws = p;
            while (p < n && is_ident_char((unsigned char)t[p])) p++;
            int wl = p - ws;
            int rs = p;
            /* find end of directive (honour continuations and block comments) */
            while (p < n && t[p] != '\n') {
                if (t[p] == '\\' && p + 1 < n && t[p + 1] == '\n') {
                    p += 2;
                    line++;
                    continue;
                }
                if (t[p] == '\\' && p + 2 < n && t[p + 1] == '\r' && t[p + 2] == '\n') {
                    p += 3;
                    line++;
                    continue;
                }
                if (t[p] == '/' && p + 1 < n && t[p + 1] == '*') {
                    int cs = p, cl = line;
                    p += 2;
                    while (p < n && !(t[p] == '*' && p + 1 < n && t[p + 1] == '/')) {
                        if (t[p] == '\n') line++;
                        p++;
                    }
                    p = p + 2 <= n ? p + 2 : n;
                    Comment cm = {cl, line, cs, p - cs};
                    VPUSH(coms, cm);
                    continue;
                }
                if (t[p] == '/' && p + 1 < n && t[p + 1] == '/') {
                    int cs = p;
                    while (p < n && t[p] != '\n') p++;
                    Comment cm = {line, line, cs, p - cs};
                    VPUSH(coms, cm);
                    break;
                }
                p++;
            }
            int re = p;
            const char *w = t + ws;
#define DIR(s) (wl == (int)strlen(s) && strncmp(w, s, wl) == 0)
            if (DIR("if") || DIR("ifdef") || DIR("ifndef")) {
                Frame f;
                f.group = ++ngroups;
                f.branch = 0;
                f.parent_node = cur_node;
                f.active = !(DIR("if") && cond_is_zero(t + rs, re - rs));
                if (DIR("if") && !f.active) VPUSH(if0, dline);
                VPUSH(st, f);
                CondNode cn = {f.parent_node, f.group, 0};
                VPUSH(conds, cn);
                cur_node = conds.n - 1;
            } else if ((DIR("elif") || DIR("else")) && st.n) {
                Frame *f = &st.v[st.n - 1];
                f->branch++;
                f->active = !(DIR("elif") && cond_is_zero(t + rs, re - rs));
                if (DIR("elif") && !f->active) VPUSH(if0, dline);
                CondNode cn = {f->parent_node, f->group, f->branch};
                VPUSH(conds, cn);
                cur_node = conds.n - 1;
            } else if (DIR("endif") && st.n) {
                cur_node = st.v[st.n - 1].parent_node;
                st.n--;
            } else if (DIR("include") && active) {
                int q = rs;
                while (q < re && (t[q] == ' ' || t[q] == '\t')) q++;
                if (q < re && (t[q] == '"' || t[q] == '<')) {
                    char close = t[q] == '"' ? '"' : '>';
                    int e = q + 1;
                    while (e < re && t[e] != close) e++;
                    VPUSH(incs, xstrndup(t + q, (size_t)(e - q)));
                }
            }
#undef DIR
            active = 1;
            for (int k = 0; k < st.n; k++)
                if (!st.v[k].active) active = 0;
            bol = 1;
            continue;
        }
        bol = 0;
        if (c == '/' && p + 1 < n && t[p + 1] == '/') {
            int cs = p;
            while (p < n && t[p] != '\n') p++;
            Comment cm = {line, line, cs, p - cs};
            VPUSH(coms, cm);
            continue;
        }
        if (c == '/' && p + 1 < n && t[p + 1] == '*') {
            int cs = p, cl = line;
            p += 2;
            while (p < n && !(t[p] == '*' && p + 1 < n && t[p + 1] == '/')) {
                if (t[p] == '\n') line++;
                p++;
            }
            p = p + 2 <= n ? p + 2 : n;
            Comment cm = {cl, line, cs, p - cs};
            VPUSH(coms, cm);
            continue;
        }
        Tok tk;
        tk.line = line;
        tk.off = p;
        tk.cond = cur_node;
        if (is_ident_start(c) && !(c == 'L' && p + 1 < n && (t[p + 1] == '"' || t[p + 1] == '\''))) {
            while (p < n && is_ident_char((unsigned char)t[p])) p++;
            tk.type = T_IDENT;
        } else if (isdigit(c) || (c == '.' && p + 1 < n && isdigit((unsigned char)t[p + 1]))) {
            p++;
            while (p < n) {
                int d = (unsigned char)t[p];
                if ((d == '+' || d == '-') && (t[p - 1] == 'e' || t[p - 1] == 'E' || t[p - 1] == 'p' || t[p - 1] == 'P') &&
                    !(t[tk.off] == '0' && (t[tk.off + 1] == 'x' || t[tk.off + 1] == 'X'))) {
                    p++;
                    continue;
                }
                if (is_ident_char(d) || d == '.') {
                    p++;
                    continue;
                }
                break;
            }
            tk.type = T_NUM;
        } else if (c == '"' || c == '\'' || c == 'L') {
            if (c == 'L') p++;
            char q = t[p];
            p++;
            while (p < n && t[p] != q && t[p] != '\n') {
                if (t[p] == '\\' && p + 1 < n) {
                    if (t[p + 1] == '\n') line++;
                    p++;
                }
                p++;
            }
            if (p < n && t[p] == q) p++;
            tk.type = q == '"' ? T_STR : T_CHR;
        } else {
            int len = 1;
            for (int k = 0; puncts3[k]; k++)
                if (p + 3 <= n && strncmp(t + p, puncts3[k], 3) == 0) {
                    len = 3;
                    break;
                }
            if (len == 1)
                for (int k = 0; puncts2[k]; k++)
                    if (p + 2 <= n && strncmp(t + p, puncts2[k], 2) == 0) {
                        len = 2;
                        break;
                    }
            p += len;
            tk.type = T_PUNCT;
        }
        tk.len = p - tk.off;
        if (active) VPUSH(toks, tk);
    }
    L->toks = toks.v;
    L->ntoks = toks.n;
    L->coms = coms.v;
    L->ncoms = coms.n;
    L->conds = conds.v;
    L->nconds = conds.n;
    L->if0_lines = if0.v;
    L->nif0 = if0.n;
    L->includes = incs.v;
    L->nincludes = incs.n;
    free(st.v);
    return 0;
}

void lex_free(Lexed *L)
{
    free(L->text);
    free(L->line_off);
    free(L->toks);
    free(L->coms);
    free(L->conds);
    free(L->if0_lines);
    for (int i = 0; i < L->nincludes; i++) free(L->includes[i]);
    free(L->includes);
    memset(L, 0, sizeof *L);
}

int tk_eq(const Lexed *L, int i, const char *s)
{
    if (i < 0 || i >= L->ntoks) return 0;
    const Tok *t = &L->toks[i];
    size_t n = strlen(s);
    return (size_t)t->len == n && memcmp(L->text + t->off, s, n) == 0;
}

const char *tk_ptr(const Lexed *L, int i) { return L->text + L->toks[i].off; }

const char *line_start(const Lexed *L, int line, int *len)
{
    if (line < 1 || line > L->nlines) {
        *len = 0;
        return "";
    }
    int s = L->line_off[line - 1];
    int e = line < L->nlines ? L->line_off[line] - 1 : L->size;
    while (e > s && (L->text[e - 1] == '\r' || L->text[e - 1] == '\n')) e--;
    *len = e - s;
    return L->text + s;
}

void line_text(const Lexed *L, int line, char *buf, int cap)
{
    int len;
    const char *s = line_start(L, line, &len);
    while (len > 0 && (*s == ' ' || *s == '\t')) {
        s++;
        len--;
    }
    while (len > 0 && (s[len - 1] == ' ' || s[len - 1] == '\t')) len--;
    int k = 0;
    for (int i = 0; i < len && k < cap - 1; i++) buf[k++] = (s[i] == '\t') ? ' ' : s[i];
    buf[k] = 0;
}

int cond_exclusive(const Lexed *L, int a, int b)
{
    for (int x = a; x > 0; x = L->conds[x].parent)
        for (int y = b; y > 0; y = L->conds[y].parent)
            if (L->conds[x].group == L->conds[y].group && L->conds[x].branch != L->conds[y].branch) return 1;
    return 0;
}

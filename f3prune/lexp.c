/* lexp.c - see lexp.h */
#include "../f3rules/util.h"
#include "lexp.h"

static const char *puncts3[] = {">>=", "<<=", "...", "->*", NULL};
static const char *puncts2[] = {"->", "++", "--", "<<", ">>", "<=", ">=", "==", "!=", "&&", "||", "+=", "-=", "*=",
                                "/=", "%=", "&=", "|=", "^=", "::", ".*", "##", NULL};

static int is_ident_start(int c) { return isalpha(c) || c == '_' || c == '$'; }
static int is_ident_char(int c) { return isalnum(c) || c == '_' || c == '$'; }

static int cond_is_zero(const char *s, int n)
{
    char buf[64];
    int k = 0;
    for (int i = 0; i < n && k < 63; i++) {
        if (s[i] == '/' && i + 1 < n && (s[i + 1] == '/' || s[i + 1] == '*')) break;
        if (!isspace((unsigned char)s[i])) buf[k++] = s[i];
    }
    buf[k] = 0;
    return strcmp(buf, "0") == 0 || strcmp(buf, "(0)") == 0;
}

typedef struct {
    int cur, any;
} CFrame;

int line_blank(const PLex *L, int line)
{
    if (line < 1 || line > L->nlines) return 1;
    const char *s = L->text + L->line_off[line - 1];
    const char *e = L->text + L->line_off[line];
    for (; s < e; s++)
        if (!isspace((unsigned char)*s)) return 0;
    return 1;
}

int plex_file(const char *path, PLex *L)
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
        if (t[i] == '\n' && i + 1 < L->size) VPUSH(lo, i + 1);
    L->nlines = lo.n;
    VPUSH(lo, L->size);
    L->line_off = lo.v;
    L->line_code = xcalloc((size_t)L->nlines + 2, 1);
    L->line_comment = xcalloc((size_t)L->nlines + 2, 1);

    VEC(PTok) toks = {0};
    VEC(CFrame) st = {0};
    int taken = 1;
    int p = 0, line = 1, bol = 1, n = L->size;
#define MARKC(a, b)                                                                                                    \
    do {                                                                                                               \
        for (int _l = (a); _l <= (b) && _l <= L->nlines; _l++) L->line_comment[_l] = 1;                               \
    } while (0)
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
            PTok tk;
            tk.type = P_DIR;
            tk.line = line;
            tk.off = p;
            p++;
            while (p < n && (t[p] == ' ' || t[p] == '\t')) p++;
            int ws = p;
            while (p < n && is_ident_char((unsigned char)t[p])) p++;
            int wl = p - ws;
            int rs = p;
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
                    int cl = line;
                    p += 2;
                    while (p < n && !(t[p] == '*' && p + 1 < n && t[p + 1] == '/')) {
                        if (t[p] == '\n') line++;
                        p++;
                    }
                    p = p + 2 <= n ? p + 2 : n;
                    MARKC(cl, line);
                    continue;
                }
                if (t[p] == '/' && p + 1 < n && t[p + 1] == '/') {
                    MARKC(line, line);
                    while (p < n && t[p] != '\n') p++;
                    break;
                }
                p++;
            }
            int re = p;
            tk.end_line = line;
            tk.len = p - tk.off;
            const char *w = t + ws;
#define DIR(s) (wl == (int)strlen(s) && strncmp(w, s, wl) == 0)
            if (DIR("if") || DIR("ifdef") || DIR("ifndef")) {
                CFrame f;
                f.cur = !(DIR("if") && cond_is_zero(t + rs, re - rs));
                f.any = f.cur;
                VPUSH(st, f);
            } else if (DIR("elif") && st.n) {
                CFrame *f = &st.v[st.n - 1];
                if (f->any)
                    f->cur = 0;
                else {
                    f->cur = !cond_is_zero(t + rs, re - rs);
                    f->any = f->cur;
                }
            } else if (DIR("else") && st.n) {
                CFrame *f = &st.v[st.n - 1];
                f->cur = !f->any;
                f->any = 1;
            } else if (DIR("endif")) {
                if (st.n)
                    st.n--;
                else
                    L->cond_unbalanced = 1;
            }
#undef DIR
            taken = 1;
            for (int k = 0; k < st.n; k++)
                if (!st.v[k].cur) taken = 0;
            tk.taken = taken;
            for (int l = tk.line; l <= tk.end_line && l <= L->nlines; l++) L->line_code[l] = 1;
            VPUSH(toks, tk);
            bol = 1;
            continue;
        }
        bol = 0;
        if (c == '/' && p + 1 < n && t[p + 1] == '/') {
            MARKC(line, line);
            while (p < n && t[p] != '\n') p++;
            continue;
        }
        if (c == '/' && p + 1 < n && t[p + 1] == '*') {
            int cl = line;
            p += 2;
            while (p < n && !(t[p] == '*' && p + 1 < n && t[p + 1] == '/')) {
                if (t[p] == '\n') line++;
                p++;
            }
            p = p + 2 <= n ? p + 2 : n;
            MARKC(cl, line);
            continue;
        }
        PTok tk;
        tk.line = line;
        tk.off = p;
        tk.taken = taken;
        if (is_ident_start(c) && !(c == 'L' && p + 1 < n && (t[p + 1] == '"' || t[p + 1] == '\''))) {
            while (p < n && is_ident_char((unsigned char)t[p])) p++;
            tk.type = P_IDENT;
        } else if (isdigit(c) || (c == '.' && p + 1 < n && isdigit((unsigned char)t[p + 1]))) {
            p++;
            while (p < n) {
                int d = (unsigned char)t[p];
                if ((d == '+' || d == '-') && (t[p - 1] == 'e' || t[p - 1] == 'E') &&
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
            tk.type = P_NUM;
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
            tk.type = q == '"' ? P_STR : P_CHR;
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
            tk.type = P_PUNCT;
        }
        tk.len = p - tk.off;
        tk.end_line = line;
        for (int l = tk.line; l <= tk.end_line && l <= L->nlines; l++) L->line_code[l] = 1;
        VPUSH(toks, tk);
    }
    if (st.n) L->cond_unbalanced = 1;
    PTok eof = {0, line, line, n, 0, 1};
    VPUSH(toks, eof);
    L->toks = toks.v;
    L->ntoks = toks.n - 1;
    free(st.v);
    return 0;
}

void plex_free(PLex *L)
{
    free(L->text);
    free(L->line_off);
    free(L->toks);
    free(L->line_code);
    free(L->line_comment);
    memset(L, 0, sizeof *L);
}

int ptk_eq(const PLex *L, int i, const char *s)
{
    if (i < 0 || i >= L->ntoks) return 0;
    int n = (int)strlen(s);
    return L->toks[i].len == n && memcmp(L->text + L->toks[i].off, s, (size_t)n) == 0;
}

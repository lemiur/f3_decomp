/* check.c - pass 3: locate each recipe function's signature, header comment and body in its source file, then run
   the [match] checks (R1 R2 R4 R13 R17 R18) and the advisory checks (R7 R33 R37) over the body plus signature.
   A "// RULE-EXCEPTION: <rule>, <reason>" on the flagged line or the line before turns a finding into an exception. */
#include "model.h"

volatile LONG g_diag_no_sig, g_diag_no_body, g_diag_past_brace;

typedef struct {
    const Lexed *L;
    int fid;
    int *match;   /* matching bracket index for ( ) [ ] { } tokens, -1 otherwise */
    int *tok_line; /* tok_line[l] = first token index with line >= l */
    StrMap externs; /* file-scope extern variables of this file -> line */
} FileCtx;

typedef struct {
    FileCtx *fc;
    const Lexed *L;
    Func *fn;
    int fi; /* index in g_funcs */
    Unit *unit;
    int t0, tb, te; /* first token, opening brace (or -1), closing brace / last token (inclusive) */
    int sig_line, last_line, hdr_first, hdr_last;
    int original_asm;
    char qcls[512]; /* qualified class / namespace scope of the function, from its decorated name */
    char comps[16][128];
    int ncomps;
    FindingVec *out;
    int nmatch;
    char mrules[64], arules[64];
} FnCtx;

/* ------------------------------------------------------------------ names from decorated symbols */

enum { NK_PLAIN, NK_CTOR, NK_DTOR, NK_OPER, NK_GEN };

static void read_component(const char *s, char *out, int cap)
{
    int k = 0;
    while (*s && *s != '@' && k < cap - 1) out[k++] = *s++;
    out[k] = 0;
}

static void name_info(const char *sym, char *name, char *cls, int *kind)
{
    name[0] = cls[0] = 0;
    *kind = NK_PLAIN;
    const char *rest = NULL;
    if (sym[0] == '?') {
        if (sym[1] == '?') {
            char c = sym[2];
            if (c == '0' || c == '1') {
                read_component(sym + 3, cls, 256);
                snprintf(name, 256, "%s", cls);
                *kind = c == '0' ? NK_CTOR : NK_DTOR;
                return;
            }
            if (c == '$') {
                read_component(sym + 3, name, 256);
                rest = strchr(sym + 3, '@');
                /* template args end at the first "@@"-free point; class detection is unreliable here */
                return;
            }
            if (c == '_') {
                if (sym[3] == 'U' || sym[3] == 'V') {
                    *kind = NK_OPER;
                    snprintf(name, 256, "operator");
                    read_component(sym + 4, cls, 256);
                    return;
                }
                *kind = NK_GEN;
                read_component(sym + 4, cls, 256);
                return;
            }
            *kind = NK_OPER;
            snprintf(name, 256, "operator");
            read_component(sym + 3, cls, 256);
            return;
        }
        read_component(sym + 1, name, 256);
        rest = strchr(sym + 1, '@');
        if (rest && rest[1] && rest[1] != '@') {
            if (rest[1] == '?' && rest[2] == '$')
                read_component(rest + 3, cls, 256);
            else if (!isdigit((unsigned char)rest[1]))
                read_component(rest + 1, cls, 256);
        }
        return;
    }
    const char *s = sym;
    if (*s == '_' || *s == '@') s++;
    read_component(s, name, 256);
}

static int ident_ch(int c) { return isalnum(c) || c == '_' || c == '$'; }

/* scope components of a decorated name, innermost first ("?f@A@B@@" -> A, B); stops at templates and
   back-references */
static int scope_chain(const char *sym, char comps[][128], int max)
{
    const char *p;
    if (sym[0] != '?') return 0;
    if (sym[1] == '?') {
        if (sym[2] == '$') return 0;
        p = sym[2] == '_' ? sym + 4 : sym + 3;
    } else {
        p = strchr(sym + 1, '@');
        if (!p) return 0;
        p++;
    }
    int n = 0;
    while (*p && *p != '@' && n < max) {
        if (*p == '?' || isdigit((unsigned char)*p)) break;
        const char *e = strchr(p, '@');
        if (!e) break;
        snprintf(comps[n], 128, "%.*s", (int)(e - p), p);
        n++;
        p = e + 1;
    }
    return n;
}

/* does line text contain the function's name as it is defined (name followed by '(') */
static int line_has_def(const char *s, int len, const char *name, int kind)
{
    int nl = (int)strlen(name);
    if (!nl) return 0;
    for (int i = 0; i + nl <= len; i++) {
        if (memcmp(s + i, name, (size_t)nl) != 0) continue;
        if (i > 0 && ident_ch((unsigned char)s[i - 1])) continue;
        if (i + nl < len && ident_ch((unsigned char)s[i + nl])) continue;
        if (kind == NK_OPER) return 1;
        int j = i + nl;
        while (j < len && (s[j] == ' ' || s[j] == '\t')) j++;
        if (j < len && s[j] == '(') {
            if (kind == NK_DTOR) {
                int b = i - 1;
                while (b >= 0 && (s[b] == ' ' || s[b] == '\t')) b--;
                if (b < 0 || s[b] != '~') continue;
            }
            return 1;
        }
        if (j == len && kind != NK_DTOR) {
            /* name at end of line, '(' on the next line: accept only "name" alone as last token */
            continue;
        }
    }
    return 0;
}

static void trim(const char **s, int *len)
{
    while (*len > 0 && (**s == ' ' || **s == '\t')) {
        (*s)++;
        (*len)--;
    }
    while (*len > 0 && ((*s)[*len - 1] == ' ' || (*s)[*len - 1] == '\t' || (*s)[*len - 1] == '\r')) (*len)--;
}

static int starts(const char *s, int len, const char *p)
{
    int n = (int)strlen(p);
    return len >= n && memcmp(s, p, (size_t)n) == 0;
}

/* ------------------------------------------------------------------ findings */

static int exception_for(const Lexed *L, int line, const char *rule)
{
    for (int l = line; l >= line - 1 && l >= 1; l--) {
        int len;
        const char *s = line_start(L, l, &len);
        for (int i = 0; i + 15 <= len; i++) {
            if (memcmp(s + i, "RULE-EXCEPTION:", 15) != 0) continue;
            int j = i + 15;
            /* rules up to the first comma: R4, "R4/R17", "R4 R17" */
            while (j < len && s[j] != ',') {
                if (s[j] == 'R' && j + 1 < len && isdigit((unsigned char)s[j + 1])) {
                    int k = j + 1;
                    while (k < len && isdigit((unsigned char)s[k])) k++;
                    if ((int)strlen(rule) == k - j && memcmp(s + j, rule, (size_t)(k - j)) == 0) return 1;
                    j = k;
                    continue;
                }
                j++;
            }
        }
    }
    return 0;
}

static void add_rule(char *list, const char *rule)
{
    /* comma list, kept unique and ordered by first appearance */
    size_t n = strlen(rule);
    const char *p = list;
    while ((p = strstr(p, rule)) != NULL) {
        if ((p == list || p[-1] == ',') && (p[n] == 0 || p[n] == ',')) return;
        p += n;
    }
    if (strlen(list) + n + 2 >= 64) return;
    if (list[0]) strcat(list, ",");
    strcat(list, rule);
}

static void emit(FnCtx *c, const char *rule, int line, int kind, const char *note)
{
    if (kind == 0 && exception_for(c->L, line, rule)) kind = 2;
    if (kind == 0 && strcmp(rule, "R18") == 0 && c->original_asm) kind = 2;
    for (int i = c->out->n - 1; i >= 0; i--) {
        Finding *f = &c->out->v[i];
        if (f->func != c->fi) break;
        if (f->line == line && strcmp(f->rule, rule) == 0) return;
    }
    char buf[256];
    if (note) {
        snprintf(buf, sizeof buf, "%s", note);
    } else
        line_text(c->L, line, buf, sizeof buf);
    if (strlen(buf) > 120) buf[120] = 0;
    for (char *p = buf; *p; p++)
        if (*p == '\t' || *p == '\r' || *p == '\n') *p = ' ';
    Finding f;
    f.func = c->fi;
    f.line = line;
    snprintf(f.rule, sizeof f.rule, "%s", rule);
    f.kind = kind;
    f.excerpt = xstrdup(buf);
    VPUSH(*c->out, f);
    if (kind == 0) {
        c->nmatch++;
        add_rule(c->mrules, rule);
    } else if (kind == 1)
        add_rule(c->arules, rule);
}

/* a [match] finding whose excerpt starts with the identifier it is about */
static void emit_named(FnCtx *c, const char *rule, int line, const char *ident, const char *what)
{
    char txt[160], note[240];
    line_text(c->L, line, txt, sizeof txt);
    snprintf(note, sizeof note, "%s (%s): %s", ident, what, txt);
    emit(c, rule, line, 0, note);
}

/* a [match] finding whose excerpt starts with the sub-check that raised it */
static void emit_tag(FnCtx *c, const char *rule, int line, const char *tag)
{
    char txt[160], note[240];
    line_text(c->L, line, txt, sizeof txt);
    snprintf(note, sizeof note, "[%s] %s", tag, txt);
    emit(c, rule, line, 0, note);
}

/* ------------------------------------------------------------------ token helpers */

static int member_access(const Lexed *L, int i) { return tk_eq(L, i - 1, ".") || tk_eq(L, i - 1, "->"); }

#define EQ(i, s) tk_eq(L, (i), (s))
#define TYPE(i) (((i) >= 0 && (i) < L->ntoks) ? L->toks[i].type : 0)
#define LINE(i) (L->toks[i].line)

static int is_kw_expr_ctx(const Lexed *L, int i)
{
    static const char *kws[] = {"return", "case", "throw", "else", "do", "sizeof", "delete", NULL};
    for (int k = 0; kws[k]; k++)
        if (EQ(i, kws[k])) return 1;
    return 0;
}

/* nonzero if token i ends an operand (so a following '*' / '+' is binary) */
static int ends_operand(const FnCtx *c, int i)
{
    const Lexed *L = c->L;
    if (i < 0) return 0;
    int t = TYPE(i);
    if (t == T_NUM || t == T_STR || t == T_CHR) return 1;
    if (t == T_IDENT) return !is_kw_expr_ctx(L, i);
    if (EQ(i, "]")) return 1;
    if (EQ(i, ")")) {
        int o = c->fc->match[i];
        if (o > 0 && (EQ(o - 1, "if") || EQ(o - 1, "while") || EQ(o - 1, "for") || EQ(o - 1, "switch"))) return 0;
        return 1; /* a cast "(T*)" followed by '*' is rare enough */
    }
    if (EQ(i, "++") || EQ(i, "--")) return 1;
    return 0;
}

static const char *byte_types[][3] = {{"char"}, {"unsigned", "char"}, {"signed", "char"}, {"BYTE"}, {"UInt8"},
                                      {"uint8_t"}, {"byte"}, {"UCHAR"}, {"u8"}, {"__int8"}, {"unsigned", "__int8"},
                                      {"uint8"}, {"UINT8"}, {NULL}};
static const char *int_types[][3] = {{"int"}, {"unsigned"}, {"unsigned", "int"}, {"signed", "int"}, {"long"},
                                     {"unsigned", "long"}, {"DWORD"}, {"UInt32"}, {"uint32_t"}, {"uintptr_t"},
                                     {"intptr_t"}, {"size_t"}, {"UINT"}, {"ULONG"}, {"__int32"},
                                     {"unsigned", "__int32"}, {"INT_PTR"}, {"UINT_PTR"}, {"DWORD_PTR"}, {"ULONG_PTR"},
                                     {"LONG_PTR"}, {"ptrdiff_t"}, {"uint32"}, {"SInt32"}, {"int32_t"}, {"LONG"}, {NULL}};

enum { CT_NONE = 0, CT_BYTEPTR, CT_INT, CT_PTR };

/* classify the type tokens [a, b) of a cast */
static int classify_type(const Lexed *L, int a, int b)
{
    int idents[8], ni = 0, stars = 0, amp = 0, other = 0;
    for (int k = a; k < b; k++) {
        if (EQ(k, "const") || EQ(k, "volatile") || EQ(k, "struct") || EQ(k, "class")) continue;
        if (EQ(k, "*")) {
            stars++;
            continue;
        }
        if (EQ(k, "&")) {
            amp++;
            continue;
        }
        if (TYPE(k) == T_IDENT && stars > 0) return CT_NONE; /* "(a * b)" is not a cast */
        if (TYPE(k) == T_IDENT && stars == 0) {
            if (ni < 8) idents[ni++] = k;
            continue;
        }
        if (EQ(k, "::") || EQ(k, "<") || EQ(k, ">") || EQ(k, ",") || TYPE(k) == T_IDENT) {
            other++;
            continue;
        }
        return CT_NONE;
    }
    if (ni == 0 || amp) return CT_NONE;
    if (stars == 0 && ni == 1 && !other && (EQ(idents[0], "PBYTE") || EQ(idents[0], "LPBYTE"))) return CT_BYTEPTR;
    if (stars == 1 && !other) {
        for (int t = 0; byte_types[t][0]; t++) {
            int n = 0;
            while (n < 3 && byte_types[t][n]) n++;
            if (n != ni) continue;
            int ok = 1;
            for (int k = 0; k < n; k++)
                if (!EQ(idents[k], byte_types[t][k])) ok = 0;
            if (ok) return CT_BYTEPTR;
        }
    }
    if (stars >= 1) return CT_PTR;
    if (!other)
        for (int t = 0; int_types[t][0]; t++) {
            int n = 0;
            while (n < 3 && int_types[t][n]) n++;
            if (n != ni) continue;
            int ok = 1;
            for (int k = 0; k < n; k++)
                if (!EQ(idents[k], int_types[t][k])) ok = 0;
            if (ok) return CT_INT;
        }
    return CT_NONE;
}

static int operand_start(const Lexed *L, int i)
{
    int t = TYPE(i);
    if (t == T_IDENT || t == T_NUM || t == T_STR || t == T_CHR) return 1;
    return EQ(i, "(") || EQ(i, "*") || EQ(i, "&") || EQ(i, "!") || EQ(i, "~") || EQ(i, "-") || EQ(i, "::");
}

/* if token i starts a cast, return its class and set *after to the operand start (C-style) or the
   argument group's '(' (C++ casts, *arg_close set) */
static int cast_at(const FnCtx *c, int i, int *after, int *cxx)
{
    const Lexed *L = c->L;
    *cxx = 0;
    if (EQ(i, "(")) {
        int m = c->fc->match[i];
        if (m <= i + 1) return CT_NONE;
        int ct = classify_type(L, i + 1, m);
        if (ct == CT_NONE) return CT_NONE;
        if (!operand_start(L, m + 1)) return CT_NONE;
        *after = m + 1;
        return ct;
    }
    if (EQ(i, "reinterpret_cast") || EQ(i, "static_cast") || EQ(i, "const_cast")) {
        if (!EQ(i + 1, "<")) return CT_NONE;
        int d = 0, k;
        for (k = i + 1; k < L->ntoks; k++) {
            if (EQ(k, "<")) d++;
            else if (EQ(k, ">") && --d == 0) break;
            else if (EQ(k, ">>")) {
                d -= 2;
                if (d <= 0) break;
            } else if (EQ(k, ";") || EQ(k, "{")) return CT_NONE;
        }
        if (!EQ(k + 1, "(")) return CT_NONE;
        int ct = classify_type(L, i + 2, k);
        *after = k + 1;
        *cxx = 1;
        return ct;
    }
    return CT_NONE;
}

static int parse_operand(const FnCtx *c, int j, int lim);

/* end (exclusive) of a cast expression starting at i, or -1 */
static int cast_expr_end(const FnCtx *c, int i, int lim, int *ct_out, int *opnd)
{
    int after, cxx;
    int ct = cast_at(c, i, &after, &cxx);
    if (ct == CT_NONE) return -1;
    *ct_out = ct;
    *opnd = after;
    if (cxx) {
        int m = c->fc->match[after];
        return m > after ? m + 1 : -1;
    }
    return parse_operand(c, after, lim);
}

static int parse_operand(const FnCtx *c, int j, int lim)
{
    const Lexed *L = c->L;
    while (j < lim && (EQ(j, "&") || EQ(j, "*") || EQ(j, "!") || EQ(j, "~") || EQ(j, "-") || EQ(j, "+") || EQ(j, "++") ||
                       EQ(j, "--")))
        j++;
    if (j >= lim) return -1;
    int ct, op;
    int e = cast_expr_end(c, j, lim, &ct, &op);
    if (e >= 0) return e;
    if (EQ(j, "(")) {
        int m = c->fc->match[j];
        if (m < 0) return -1;
        j = m + 1;
    } else if (TYPE(j) == T_IDENT || TYPE(j) == T_NUM || TYPE(j) == T_STR) {
        j++;
        while (j + 1 < lim && EQ(j, "::") && TYPE(j + 1) == T_IDENT) j += 2;
    } else
        return -1;
    for (;;) {
        if (j + 1 < lim && (EQ(j, ".") || EQ(j, "->")) && TYPE(j + 1) == T_IDENT) {
            j += 2;
        } else if (j < lim && (EQ(j, "[") || EQ(j, "("))) {
            int m = c->fc->match[j];
            if (m < 0) return -1;
            j = m + 1;
        } else if (j < lim && (EQ(j, "++") || EQ(j, "--"))) {
            j++;
        } else
            break;
    }
    return j;
}

/* integer constant at k: literal, (literal), sizeof(...); returns end or -1 */
static int const_at(const FnCtx *c, int k)
{
    const Lexed *L = c->L;
    if (TYPE(k) == T_NUM) {
        const char *s = tk_ptr(L, k);
        int n = L->toks[k].len;
        int hex = n > 1 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X');
        for (int i = 0; i < n; i++)
            if (s[i] == '.' || (!hex && (s[i] == 'e' || s[i] == 'E' || s[i] == 'f' || s[i] == 'F'))) return -1;
        return k + 1;
    }
    if (EQ(k, "(") && TYPE(k + 1) == T_NUM && EQ(k + 2, ")")) return const_at(c, k + 1) > 0 ? k + 3 : -1;
    if (EQ(k, "sizeof") && EQ(k + 1, "(")) {
        int m = c->fc->match[k + 1];
        return m > 0 ? m + 1 : -1;
    }
    return -1;
}

static int binds_tighter(const Lexed *L, int k)
{
    return EQ(k, "*") || EQ(k, "/") || EQ(k, "%") || EQ(k, "[") || EQ(k, "(") || EQ(k, ".") || EQ(k, "->") ||
           EQ(k, "++") || EQ(k, "--");
}

/* is the expression starting at token s (a pointer cast) dereferenced: "*(T*)..." or "((T*)...)->" / "[...]" */
static int deref_before(const FnCtx *c, int s)
{
    const Lexed *L = c->L;
    if (EQ(s - 1, "*") && !ends_operand(c, s - 2)) return 1;
    if (EQ(s - 1, "(")) {
        int m = c->fc->match[s - 1];
        if (m > 0 && (EQ(m + 1, "->") || EQ(m + 1, "["))) return 1;
    }
    return 0;
}

/* group g..gc (parentheses) holding an offset expression: is the result dereferenced or indexed? */
static int group_derefed(const FnCtx *c, int g, int gc)
{
    const Lexed *L = c->L;
    if (EQ(gc + 1, "[")) return 1;
    if (EQ(g - 1, "*") && !ends_operand(c, g - 2)) return 1;
    /* preceded by a pointer cast: C style "(T*)" or C++ "reinterpret_cast<T*>" whose argument is the group */
    if (EQ(g - 1, ")")) {
        int o = c->fc->match[g - 1];
        if (o >= 0) {
            int ct = classify_type(L, o + 1, g - 1);
            if (ct == CT_PTR || ct == CT_BYTEPTR) return deref_before(c, o);
        }
    }
    if (EQ(g - 1, ">")) {
        /* find the cast keyword */
        for (int k = g - 2; k >= 0 && k > g - 40; k--) {
            if (EQ(k, "reinterpret_cast") || EQ(k, "static_cast") || EQ(k, "const_cast")) {
                int ct = classify_type(L, k + 2, g - 1);
                if (ct == CT_PTR || ct == CT_BYTEPTR) {
                    if (deref_before(c, k)) return 1;
                    if (EQ(c->fc->match[g] + 1, "->") || EQ(c->fc->match[g] + 1, "[")) return 1;
                }
                break;
            }
            if (EQ(k, ";") || EQ(k, "{") || EQ(k, "}")) break;
        }
    }
    return 0;
}

static void check_r4(FnCtx *c)
{
    const Lexed *L = c->L;
    for (int i = c->t0; i <= c->te; i++) {
        int ct, op;
        int e = cast_expr_end(c, i, c->te + 1, &ct, &op);
        if (e < 0) continue;
        int is_this = 0;
        if (EQ(op, "this") && op + 1 == e) is_this = 1;
        if (EQ(op, "(") && EQ(op + 1, "this") && EQ(op + 2, ")") && op + 3 == e) is_this = 1;
        /* cxx casts: operand is the group "(this)" */
        if ((EQ(e, "+") || EQ(e, "-")) && (ct == CT_BYTEPTR || ct == CT_INT || (ct == CT_PTR && is_this))) {
            int kc = const_at(c, e + 1);
            if (kc < 0 || binds_tighter(L, kc)) continue;
            if (is_this && ct == CT_BYTEPTR) {
                emit_tag(c, "R4", LINE(i), "byte cast of this + constant");
                continue;
            }
            if (EQ(i - 1, "(") && EQ(kc, ")") && c->fc->match[i - 1] == kc && group_derefed(c, i - 1, kc)) {
                emit_tag(c, "R4", LINE(i), "offset cast dereferenced");
                continue;
            }
        }
        /* ((char*)this)[N], ((T*)this)[N] */
        if (is_this && (ct == CT_BYTEPTR || ct == CT_PTR) && EQ(i - 1, "(") && EQ(e, ")") && c->fc->match[i - 1] == e &&
            EQ(e + 1, "[")) {
            int kc = const_at(c, e + 2);
            if (kc > 0 && EQ(kc, "]")) emit_tag(c, "R4", LINE(i), "this cast and indexed");
        }
    }
}

/* ------------------------------------------------------------------ R17 */

static int pad_ident(const char *s, int n)
{
    int p = 0;
    if (p < n && s[p] == '_') p++;
    if (n - p >= 3 && strncmp(s + p, "pad", 3) == 0) {
        for (int k = p + 3; k < n; k++)
            if (!isxdigit((unsigned char)s[k]) && s[k] != '_') goto dummy;
        return 1;
    }
dummy:
    p = 0;
    if (n >= 1 && s[0] == '_') {
        p = 1;
        if (n >= 2 && s[1] == '_') p = 2;
        if (n - p >= 5 && (s[p] == 'D' || s[p] == 'd') && strncmp(s + p + 1, "ummy", 4) == 0) return 1;
    }
    return 0;
}

static int int_value_is(const Lexed *L, int k, int v)
{
    if (TYPE(k) != T_NUM) return 0;
    const char *s = tk_ptr(L, k);
    int n = L->toks[k].len;
    while (n > 0 && (s[n - 1] == 'u' || s[n - 1] == 'U' || s[n - 1] == 'l' || s[n - 1] == 'L')) n--;
    int i = 0;
    if (n > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) i = 2;
    if (i == n) return 0;
    int seen_one = 0;
    for (; i < n; i++) {
        if (s[i] == '0') continue;
        if (s[i] == '1' && v == 1 && !seen_one && i == n - 1) {
            seen_one = 1;
            continue;
        }
        return 0;
    }
    return v == 0 ? !seen_one : seen_one;
}

static int simple_lvalue_tok(const Lexed *L, int k)
{
    int t = TYPE(k);
    if (t == T_IDENT) return !EQ(k, "return") && !EQ(k, "case");
    return t == T_NUM || EQ(k, ".") || EQ(k, "->") || EQ(k, "::") || EQ(k, "[") || EQ(k, "]") || EQ(k, "*");
}

static int volatile_is_decl(const FnCtx *c, int v)
{
    const Lexed *L = c->L;
    for (int j = v - 1; j > c->tb; j--) {
        if (EQ(j, ")") || EQ(j, "]")) {
            int o = c->fc->match[j];
            if (o < 0 || o >= j) return 0;
            j = o;
            continue;
        }
        if (EQ(j, "(")) return EQ(j - 1, "for");
        if (EQ(j, "<") && (EQ(j - 1, "static_cast") || EQ(j - 1, "reinterpret_cast") || EQ(j - 1, "const_cast")))
            return 0; /* a cast, not a declaration */
        if (EQ(j, ";") || EQ(j, "{") || EQ(j, "}") || EQ(j, ":")) return 1;
        if (EQ(j, "=") || EQ(j, ",") || EQ(j, "return")) return EQ(j, ",") ? 1 : 0;
    }
    return 1;
}

/* does the function declare a parameter or local with this name ("T name", "T* name" followed by ; = , ) [ ( :) */
static int declared_in_function(const FnCtx *c, const char *s, int n)
{
    const Lexed *L = c->L;
    static const char *notype[] = {"return", "case", "goto", "else", "delete", "new", "throw", "sizeof", "do", NULL};
    for (int i = c->t0; i <= c->te; i++) {
        if (TYPE(i) != T_IDENT || L->toks[i].len != n || memcmp(tk_ptr(L, i), s, (size_t)n) != 0) continue;
        if (!(EQ(i + 1, ";") || EQ(i + 1, "=") || EQ(i + 1, ",") || EQ(i + 1, ")") || EQ(i + 1, "[") || EQ(i + 1, "(") ||
              EQ(i + 1, ":")))
            continue;
        int p = i - 1;
        while (p >= c->t0 && (EQ(p, "*") || EQ(p, "&") || EQ(p, "const") || EQ(p, "volatile"))) p--;
        if (p < c->t0) continue;
        if (TYPE(p) == T_IDENT || EQ(p, ">")) {
            int bad = 0;
            for (int k = 0; notype[k]; k++)
                if (EQ(p, notype[k])) bad = 1;
            if (EQ(p - 1, ".") || EQ(p - 1, "->")) bad = 1;
            if (!bad) return 1;
        }
    }
    return 0;
}

static int visible(const Unit *u, IntVec *files)
{
    if (!files) return 0;
    for (int i = 0; i < files->n; i++)
        if (BIT_GET(u->closure, files->v[i])) return 1;
    return 0;
}

static void check_r17(FnCtx *c)
{
    const Lexed *L = c->L;
    if (c->tb < 0) return;
    int pd = 0;
    for (int i = c->tb + 1; i < c->te; i++) {
        if (EQ(i, "(") || EQ(i, "[")) pd++;
        else if (EQ(i, ")") || EQ(i, "]")) pd--;
        if (EQ(i, "volatile") && volatile_is_decl(c, i)) emit_tag(c, "R17", LINE(i), "volatile local");
        if (TYPE(i) == T_IDENT) {
            const char *s = tk_ptr(L, i);
            int n = L->toks[i].len;
            /* a bare "pad" / "_pad" local is often a real alignment amount: only a member of that name counts */
            int bare_pad = (n == 3 && memcmp(s, "pad", 3) == 0) || (n == 4 && memcmp(s, "_pad", 4) == 0);
            if (pad_ident(s, n) && (!bare_pad || member_access(L, i)))
                emit_tag(c, "R17", LINE(i), "padding/dummy name");
            if (!EQ(i + 1, "(")) {
                /* a volatile global used here, or a volatile member of the function's own class */
                int shadowed = !member_access(L, i) && declared_in_function(c, s, n);
                if (!member_access(L, i) && !shadowed) {
                    IntVec *fv = smap_getn(&g_vol_globals, s, (size_t)n);
                    int vis = 0;
                    for (int q = 0; fv && q + 1 < fv->n; q += 2)
                        if (BIT_GET(c->unit->closure, fv->v[q]) && (fv->v[q] != c->fc->fid || fv->v[q + 1] < c->sig_line))
                            vis = 1;
                    if (vis) emit_tag(c, "R17", LINE(i), "volatile global without note");
                }
                if (c->qcls[0] && !shadowed && (!member_access(L, i) || (EQ(i - 1, "->") && EQ(i - 2, "this")))) {
                    char key[1024];
                    snprintf(key, sizeof key, "%s\x01%.*s", c->qcls, n < 300 ? n : 300, s);
                    IntVec *fv = smap_get(&g_vol_members, key);
                    if (fv && visible(c->unit, fv)) emit_tag(c, "R17", LINE(i), "volatile member without note");
                }
            }
        }
        /* do { } while ( 0 ) */
        if (EQ(i, "do") && EQ(i + 1, "{")) {
            int m = c->fc->match[i + 1];
            if (m > 0 && EQ(m + 1, "while") && EQ(m + 2, "(") && int_value_is(L, m + 3, 0) && EQ(m + 4, ")"))
                emit_tag(c, "R17", LINE(i), "do-while(0) block");
        }
        /* empty if / else */
        if (EQ(i, "if") && EQ(i + 1, "(")) {
            int m = c->fc->match[i + 1];
            if (m > 0 && ((EQ(m + 1, "{") && EQ(m + 2, "}")) || EQ(m + 1, ";"))) emit_tag(c, "R17", LINE(i), "empty if");
        }
        if (EQ(i, "else") && ((EQ(i + 1, "{") && EQ(i + 2, "}")) || EQ(i + 1, ";"))) emit_tag(c, "R17", LINE(i), "empty else");
        /* bare ';' */
        if (EQ(i, ";") && pd == 0) {
            int p = i - 1;
            int bare = 0;
            if (EQ(p, ";") || EQ(p, "{")) bare = 1;
            else if (EQ(p, "}")) {
                int o = c->fc->match[p];
                if (o > 0) {
                    if (EQ(o - 1, "{") || EQ(o - 1, "}") || EQ(o - 1, ";") || EQ(o - 1, "else") || EQ(o - 1, ":") ||
                        EQ(o - 1, "try") || EQ(o - 1, "__try") || EQ(o - 1, "__finally"))
                        bare = 1;
                    else if (EQ(o - 1, ")")) {
                        int po = c->fc->match[o - 1];
                        if (po > 0 && (EQ(po - 1, "if") || EQ(po - 1, "for") || EQ(po - 1, "while") ||
                                       EQ(po - 1, "switch") || EQ(po - 1, "catch") || EQ(po - 1, "__except")))
                            bare = 1;
                    }
                }
            }
            if (bare) emit_tag(c, "R17", LINE(i), "bare ;");
        }
        /* self-assignment */
        if (EQ(i, "=") && pd == 0) {
            int ls = i;
            while (ls - 1 > c->tb && simple_lvalue_tok(L, ls - 1)) ls--;
            if (ls < i && (EQ(ls - 1, ";") || EQ(ls - 1, "{") || EQ(ls - 1, "}") || EQ(ls - 1, ":") || EQ(ls - 1, ")") ||
                           EQ(ls - 1, "else"))) {
                int n = i - ls, ok = 1;
                if (!EQ(i + 1 + n, ";")) ok = 0;
                for (int k = 0; ok && k < n; k++) {
                    if (L->toks[ls + k].len != L->toks[i + 1 + k].len ||
                        memcmp(tk_ptr(L, ls + k), tk_ptr(L, i + 1 + k), (size_t)L->toks[ls + k].len) != 0)
                        ok = 0;
                }
                /* a declaration "T x = x;" would start with a type: require no two adjacent identifiers */
                for (int k = ls; ok && k + 1 < i; k++)
                    if (TYPE(k) == T_IDENT && TYPE(k + 1) == T_IDENT) ok = 0;
                if (ok) emit_tag(c, "R17", LINE(i), "self-assignment");
            }
        }
        /* + 0 and * 1 */
        if ((EQ(i, "+") && int_value_is(L, i + 1, 0)) || (EQ(i, "*") && int_value_is(L, i + 1, 1))) {
            if (ends_operand(c, i - 1) && !binds_tighter(L, i + 2)) emit_tag(c, "R17", LINE(i), "+ 0 / * 1");
        }
    }
    /* probe comments in the body */
    for (int k = 0; k < L->ncoms; k++) {
        const Comment *cm = &L->coms[k];
        if (cm->line < c->sig_line || cm->line > c->last_line) continue;
        const char *s = L->text + cm->off;
        for (int i = 0; i + 5 <= cm->len; i++)
            if (_strnicmp(s + i, "probe", 5) == 0) {
                emit_tag(c, "R17", cm->line, "probe comment");
                break;
            }
    }
}

/* ------------------------------------------------------------------ R7 */

static int hexrun_has_digit(const char *s, int n)
{
    for (int i = 0; i < n; i++)
        if (!isxdigit((unsigned char)s[i])) return -1;
    for (int i = 0; i < n; i++)
        if (isdigit((unsigned char)s[i])) return 1;
    return 0;
}

int r7_placeholder(const char *s, int n)
{
    if (n >= 10 && strncmp(s, "FUN_", 4) == 0) {
        int k = 4;
        while (k < n && isxdigit((unsigned char)s[k])) k++;
        if (k - 4 >= 6) return 1;
    }
    if (n >= 4 && (strncmp(s, "DAT_", 4) == 0 || strncmp(s, "sub_", 4) == 0)) return 1;
    if (n >= 6 && strncmp(s, "local_", 6) == 0) return 1;
    if (n >= 7 && strncmp(s, "param_", 6) == 0 && isdigit((unsigned char)s[6])) return 1;
    if (n >= 8 && strncmp(s, "field_0x", 8) == 0) return 1;
    if (n >= 4 && strncmp(s, "unk", 3) == 0) {
        int k = 3;
        if (s[k] == '_') k++;
        if (k < n && hexrun_has_digit(s + k, n - k) >= 0) return 1;
    }
    if (n >= 5 && (s[0] == 'i' || s[0] == 'u' || s[0] == 'f') && strncmp(s + 1, "Var", 3) == 0) {
        int k = 4, ok = k < n;
        for (; k < n; k++)
            if (!isdigit((unsigned char)s[k])) ok = 0;
        if (ok) return 1;
    }
    /* address-like: [A-Za-z_]* then 6-8 hex chars with a digit, at the end of the identifier */
    for (int L = 6; L <= 8 && L <= n; L++) {
        int ok = 1;
        for (int k = 0; k < n - L; k++)
            if (!isalpha((unsigned char)s[k]) && s[k] != '_') ok = 0;
        if (ok && hexrun_has_digit(s + n - L, L) == 1) return 1;
    }
    return 0;
}

static void check_r7(FnCtx *c)
{
    const Lexed *L = c->L;
    StrBuf names = {0};
    int first = -1, count = 0;
    StrMap seen;
    smap_init(&seen, 32);
    for (int i = c->t0; i <= c->te; i++) {
        if (TYPE(i) != T_IDENT) continue;
        const char *s = tk_ptr(L, i);
        int n = L->toks[i].len;
        if (!r7_placeholder(s, n)) continue;
        char tmp[256];
        snprintf(tmp, sizeof tmp, "%.*s", n < 200 ? n : 200, s);
        if (smap_has(&seen, tmp)) continue;
        smap_put(&seen, tmp, (void *)1);
        if (first < 0) first = LINE(i);
        if (names.n < 140) {
            if (names.n) sb_adds(&names, ",");
            sb_adds(&names, tmp);
        }
        count++;
    }
    if (count) {
        char note[200];
        snprintf(note, sizeof note, "%d placeholder name%s: %s", count, count > 1 ? "s" : "", names.s);
        emit(c, "R7", first, 1, note);
    }
    free(names.s);
    smap_free(&seen);
}

/* ------------------------------------------------------------------ the other [match] rules */

static void check_r18(FnCtx *c)
{
    const Lexed *L = c->L;
    for (int i = c->t0; i <= c->te; i++)
        if (EQ(i, "__asm") || EQ(i, "_asm") || EQ(i, "__emit")) emit_tag(c, "R18", LINE(i), "inline assembly");
}



static void check_r2(FnCtx *c)
{
    const Lexed *L = c->L;
    if (c->tb >= 0)
        for (int i = c->tb + 1; i < c->te; i++)
            if (EQ(i, "extern")) emit_tag(c, "R2", LINE(i), "block-scope extern");
    if (!c->fc->externs.n) return;
    StrMap done;
    smap_init(&done, 8);
    int from = c->tb >= 0 ? c->tb + 1 : c->t0;
    for (int i = from; i <= c->te; i++) {
        if (TYPE(i) != T_IDENT || member_access(L, i)) continue;
        void *v = smap_getn(&c->fc->externs, tk_ptr(L, i), (size_t)L->toks[i].len);
        if (!v || (int)(intptr_t)v >= c->sig_line) continue;
        if (declared_in_function(c, tk_ptr(L, i), L->toks[i].len)) continue; /* a local or parameter shadows it */
        char tmp[256];
        snprintf(tmp, sizeof tmp, "%.*s", L->toks[i].len < 200 ? L->toks[i].len : 200, tk_ptr(L, i));
        if (smap_has(&done, tmp)) continue;
        smap_put(&done, tmp, (void *)1);
        emit_named(c, "R2", LINE(i), tmp, "file-scope extern");
    }
    smap_free(&done);
}

volatile LONG g_diag_r1_shared_only;

/* the conflicted definition a use of a type name at token i refers to, or NULL */
static R1Key *r1_resolve(FnCtx *c, int i)
{
    const Lexed *L = c->L;
    char x[256], key[2048];
    snprintf(x, sizeof x, "%.*s", L->toks[i].len < 200 ? L->toks[i].len : 200, tk_ptr(L, i));
    R1KeyVec *kv = smap_get(&g_r1_names, x);
    if (!kv) return NULL;
    if (EQ(i - 1, "::")) {
        if (TYPE(i - 2) == T_IDENT) {
            char q[512];
            snprintf(q, sizeof q, "%.*s::%s", L->toks[i - 2].len < 200 ? L->toks[i - 2].len : 200, tk_ptr(L, i - 2), x);
            size_t ql = strlen(q);
            for (int k = 0; k < kv->n; k++) {
                size_t kl = strlen(kv->v[k]->key);
                if (strcmp(kv->v[k]->key, q) == 0 ||
                    (kl > ql + 2 && strcmp(kv->v[k]->key + kl - ql, q) == 0 && kv->v[k]->key[kl - ql - 1] == ':'))
                    return kv->v[k];
            }
            return NULL;
        }
        R1Key *g = smap_get(&g_r1_keys, x);
        return g && g->conflicted ? g : NULL;
    }
    /* unqualified: innermost enclosing scope first, as C++ lookup does */
    for (int start = 0; start <= c->ncomps; start++) {
        key[0] = 0;
        for (int k = c->ncomps - 1; k >= start; k--) {
            strncat(key, c->comps[k], sizeof key - strlen(key) - 1);
            strncat(key, "::", sizeof key - strlen(key) - 1);
        }
        strncat(key, x, sizeof key - strlen(key) - 1);
        R1Key *rk = smap_get(&g_r1_keys, key);
        if (rk) return rk->conflicted ? rk : NULL;
    }
    /* a type from a namespace the function is not in (using-directive): any visible conflicted one */
    for (int k = 0; k < kv->n; k++)
        for (int d = 0; d < kv->v[k]->defs.n; d++)
            if (BIT_GET(c->unit->closure, kv->v[k]->defs.v[d].file)) return kv->v[k];
    return NULL;
}

/* does this unit see a copy of the type: two visible bodies, a visible definition outside include/, or a visible
   include/ definition that differs from another include/ definition */
static int r1_flag(FnCtx *c, R1Key *rk)
{
    int nv = 0, outside = 0, multi = 0;
    uint64_t h0 = 0;
    for (int d = 0; d < rk->defs.n; d++) {
        TDRef *r = &rk->defs.v[d];
        if (!BIT_GET(c->unit->closure, r->file)) continue;
        if (nv == 0) h0 = r->hash;
        else if (r->hash != h0) multi = 1;
        for (int e = 0; e < d; e++) {
            TDRef *q = &rk->defs.v[e];
            if (q->file == r->file && !fidx_cond_exclusive(&g_fidx[r->file], q->cond, r->cond)) multi = 1;
        }
        nv++;
        if (g_files[r->file].under_src) outside = 1;
    }
    if (nv == 0) return 0;
    if (multi || outside) return 1;
    for (int d = 0; d < rk->defs.n; d++)
        if (!g_files[rk->defs.v[d].file].under_src && rk->defs.v[d].hash != h0) return 1;
    return 0;
}

static void check_r1(FnCtx *c)
{
    const Lexed *L = c->L;
    StrMap done;
    smap_init(&done, 8);
    int literal = 0, flagged = 0;
    for (int i = c->t0; i <= c->te; i++) {
        if (TYPE(i) != T_IDENT || member_access(L, i)) continue;
        if (!smap_getn(&g_r1_names, tk_ptr(L, i), (size_t)L->toks[i].len)) continue;
        literal = 1;
        R1Key *rk = r1_resolve(c, i);
        if (!rk || !r1_flag(c, rk)) continue;
        if (smap_has(&done, rk->key)) continue;
        smap_put(&done, rk->key, (void *)1);
        char what[300];
        snprintf(what, sizeof what, "type %s defined more than once", rk->key);
        char tmp[256];
        snprintf(tmp, sizeof tmp, "%.*s", L->toks[i].len < 200 ? L->toks[i].len : 200, tk_ptr(L, i));
        emit_named(c, "R1", LINE(i), tmp, what);
        flagged = 1;
    }
    if (literal && !flagged) InterlockedIncrement(&g_diag_r1_shared_only);
    smap_free(&done);
}

typedef struct {
    int file;
    char *name;
} VirtRef;
typedef VEC(VirtRef) VirtVec;

static void check_r13(FnCtx *c, const char *cls)
{
    const Lexed *L = c->L;
    if (cls && cls[0]) {
        VirtVec *v = smap_get(&g_virt_by_class, c->qcls);
        if (v)
            for (int k = 0; k < v->n; k++)
                if (BIT_GET(c->unit->closure, v->v[k].file)) {
                    char note[200];
                    snprintf(note, sizeof note, "class %s declares placeholder virtual %s (%s)", c->qcls, v->v[k].name,
                             g_files[v->v[k].file].rel);
                    emit(c, "R13", c->sig_line, 0, note);
                    break;
                }
    }
    if (c->tb < 0) return;
    for (int i = c->tb + 1; i < c->te; i++) {
        if (TYPE(i) != T_IDENT || !member_access(L, i) || !EQ(i + 1, "(")) continue;
        if (!is_placeholder_virtual(tk_ptr(L, i), L->toks[i].len)) continue;
        IntVec *fv = smap_getn(&g_virt_names, tk_ptr(L, i), (size_t)L->toks[i].len);
        if (fv && visible(c->unit, fv)) emit_tag(c, "R13", LINE(i), "call through placeholder virtual");
    }
}

/* ------------------------------------------------------------------ locating */

static int is_comment_line(const char *s, int len) { return starts(s, len, "//"); }

static void locate(FnCtx *c, const char *name, int kind)
{
    const Lexed *L = c->L;
    Func *fn = c->fn;
    /* scan up from the entry at code offset 0 (the prologue, normally the '{' line), then from the smallest line */
    int starts_at[2] = {fn->first_entry > 0 ? fn->first_entry : fn->min_line, fn->min_line};
    int start = starts_at[0];
    int sig = -1;
    for (int a = 0; a < 2 && sig < 0; a++) {
        if (kind == NK_GEN || !name[0]) break;
        if (a == 1 && starts_at[1] == starts_at[0]) break;
        int from = starts_at[a];
        for (int l = from; l >= 1 && l >= from - 40; l--) {
            int len;
            const char *s = line_start(L, l, &len);
            if (line_has_def(s, len, name, kind)) {
                sig = l;
                start = from;
                break;
            }
            const char *t = s;
            int tl = len;
            trim(&t, &tl);
            if (l < from && tl > 0 && (t[tl - 1] == ';' || t[tl - 1] == '}') && !is_comment_line(t, tl)) break;
        }
    }
    if (sig < 0) start = fn->min_line;
    c->sig_line = sig > 0 ? sig : start;
    /* return-type / template lines directly above the name line */
    int top = c->sig_line;
    if (sig > 0)
        for (int k = 0; k < 2; k++) {
            int len;
            const char *s = line_start(L, top - 1, &len);
            trim(&s, &len);
            if (len == 0 || is_comment_line(s, len) || starts(s, len, "/*") || starts(s, len, "*") || s[0] == '#') break;
            char last = s[len - 1];
            if (last == ';' || last == '}' || last == '{' || last == ')' || last == ',' || last == ':') break;
            if (memchr(s, '(', (size_t)len)) break;
            top--;
        }
    /* header comment block */
    c->hdr_first = c->hdr_last = 0;
    int l = top - 1;
    while (l >= 1) {
        int len;
        const char *s = line_start(L, l, &len);
        trim(&s, &len);
        if (len && is_comment_line(s, len)) {
            if (!c->hdr_last) c->hdr_last = l;
            c->hdr_first = l;
            l--;
            continue;
        }
        if (len >= 2 && s[len - 2] == '*' && s[len - 1] == '/') {
            if (!c->hdr_last) c->hdr_last = l;
            while (l >= 1) {
                const char *u = line_start(L, l, &len);
                c->hdr_first = l;
                int found = 0;
                for (int i = 0; i + 1 < len; i++)
                    if (u[i] == '/' && u[i + 1] == '*') found = 1;
                l--;
                if (found) break;
            }
            continue;
        }
        break;
    }
    if (sig < 0 && kind != NK_GEN) InterlockedIncrement(&g_diag_no_sig);
    c->sig_line = top;
    int t0 = c->fc->tok_line[top];
    c->t0 = t0;
    c->tb = -1;
    c->te = -1;
    if (sig > 0) {
        /* the name token on the signature line, then the first '{' at paren depth 0 */
        int nt = -1;
        for (int i = c->fc->tok_line[sig]; i < L->ntoks && LINE(i) == sig; i++) {
            if (kind == NK_OPER ? EQ(i, "operator") : (TYPE(i) == T_IDENT && L->toks[i].len == (int)strlen(name) &&
                                                       memcmp(tk_ptr(L, i), name, strlen(name)) == 0 && EQ(i + 1, "("))) {
                if (kind == NK_DTOR && !EQ(i - 1, "~")) continue;
                nt = i;
                break;
            }
        }
        if (nt >= 0) {
            int d = 0;
            for (int i = nt; i < L->ntoks && LINE(i) <= fn->max_line + 1; i++) {
                if (EQ(i, "(")) d++;
                else if (EQ(i, ")")) d--;
                else if (d == 0 && EQ(i, ";")) break;
                else if (d == 0 && EQ(i, "{")) {
                    c->tb = i;
                    break;
                }
            }
        }
    }
    if (c->tb >= 0 && c->fc->match[c->tb] > c->tb) {
        /* the body is the brace-matched block; line entries past it are inlined code from later definitions */
        c->te = c->fc->match[c->tb];
        c->last_line = LINE(c->te);
        if (fn->max_line > c->last_line) InterlockedIncrement(&g_diag_past_brace);
    } else {
        InterlockedIncrement(&g_diag_no_body);
        c->tb = -1;
        c->last_line = fn->max_line > c->sig_line ? fn->max_line : c->sig_line;
        c->te = c->fc->tok_line[c->last_line + 1] - 1;
    }
    if (c->te < c->t0) c->te = c->t0 - 1;
}

static int header_describes(const FnCtx *c)
{
    /* a header comment is present when the block holds a line besides "@tag" address lines */
    if (!c->hdr_first) return 0;
    for (int l = c->hdr_first; l <= c->hdr_last; l++) {
        int len;
        const char *s = line_start(c->L, l, &len);
        trim(&s, &len);
        while (len && (*s == '/' || *s == '*' || *s == ' ' || *s == '=' || *s == '-')) {
            s++;
            len--;
        }
        trim(&s, &len);
        if (len == 0 || s[0] == '@') continue;
        return 1;
    }
    return 0;
}

static int header_has(const FnCtx *c, const char *word)
{
    if (!c->hdr_first) return 0;
    for (int l = c->hdr_first; l <= c->hdr_last; l++) {
        int len;
        const char *s = line_start(c->L, l, &len);
        int n = (int)strlen(word);
        for (int i = 0; i + n <= len; i++)
            if (memcmp(s + i, word, (size_t)n) == 0) return 1;
    }
    return 0;
}

void check_file(int fid, int *funcs, int nfuncs, FindingVec *out)
{
    Lexed L;
    if (lex_file(g_files[fid].abs, &L) != 0) {
        for (int k = 0; k < nfuncs; k++) {
            Func *fn = &g_funcs[funcs[k]];
            fn->status = ST_UNLOCATED;
            fn->unloc = UL_NOLINES;
        }
        return;
    }
    FileCtx fc;
    memset(&fc, 0, sizeof fc);
    fc.L = &L;
    fc.fid = fid;
    fc.match = xmalloc(sizeof(int) * (size_t)(L.ntoks + 1));
    int *stk = xmalloc(sizeof(int) * (size_t)(L.ntoks + 1));
    int sp = 0;
    for (int i = 0; i < L.ntoks; i++) {
        fc.match[i] = -1;
        if (L.toks[i].type != T_PUNCT || L.toks[i].len != 1) continue;
        char ch = L.text[L.toks[i].off];
        if (ch == '(' || ch == '[' || ch == '{') stk[sp++] = i;
        else if (ch == ')' || ch == ']' || ch == '}') {
            char want = ch == ')' ? '(' : ch == ']' ? '[' : '{';
            /* tolerate mismatches: pop to the nearest matching opener */
            int k = sp - 1;
            while (k >= 0 && L.text[L.toks[stk[k]].off] != want) k--;
            if (k >= 0) {
                fc.match[i] = stk[k];
                fc.match[stk[k]] = i;
                sp = k;
            }
        }
    }
    free(stk);
    fc.tok_line = xmalloc(sizeof(int) * (size_t)(L.nlines + 3));
    {
        int t = 0;
        for (int l = 0; l <= L.nlines + 2; l++) {
            while (t < L.ntoks && L.toks[t].line < l) t++;
            fc.tok_line[l] = t;
        }
    }
    smap_init(&fc.externs, 16);
    FileIdx *fi = &g_fidx[fid];
    for (int k = 0; k < fi->externs.n; k++)
        if (!smap_get(&fc.externs, fi->externs.v[k].name))
            smap_put(&fc.externs, fi->externs.v[k].name, (void *)(intptr_t)fi->externs.v[k].line);

    for (int k = 0; k < nfuncs; k++) {
        FnCtx c;
        memset(&c, 0, sizeof c);
        c.fc = &fc;
        c.L = &L;
        c.fi = funcs[k];
        c.fn = &g_funcs[c.fi];
        c.unit = &g_units[c.fn->unit];
        c.out = out;
        char name[256], cls[256];
        int kind;
        name_info(c.fn->symbol, name, cls, &kind);
        c.ncomps = scope_chain(c.fn->symbol, c.comps, 16);
        c.qcls[0] = 0;
        for (int q = c.ncomps - 1; q >= 0; q--) {
            strncat(c.qcls, c.comps[q], sizeof c.qcls - strlen(c.qcls) - 1);
            if (q) strncat(c.qcls, "::", sizeof c.qcls - strlen(c.qcls) - 1);
        }
        if (c.fn->max_line > L.nlines) c.fn->max_line = L.nlines;
        if (c.fn->min_line > L.nlines) c.fn->min_line = L.nlines;
        locate(&c, name, kind);
        c.original_asm = header_has(&c, "ORIGINAL-ASM");
        if (c.te >= c.t0) {
            check_r1(&c);
            check_r2(&c);
            check_r4(&c);
            check_r13(&c, cls);
            check_r17(&c);
            check_r18(&c);
            check_r7(&c);
        }
        if (!header_describes(&c)) emit(&c, "R33", c.sig_line, 1, "no header comment above the function");
        for (int i = 0; i < L.nif0; i++)
            if (L.if0_lines[i] >= c.sig_line && L.if0_lines[i] <= c.last_line) emit(&c, "R37", L.if0_lines[i], 1, NULL);
        Func *fn = c.fn;
        fn->sig_line = c.sig_line;
        fn->last_line = c.last_line;
        fn->status = c.nmatch ? ST_PENDING : ST_MATCHED;
        snprintf(fn->match_rules, sizeof fn->match_rules, "%s", c.mrules);
        snprintf(fn->adv_rules, sizeof fn->adv_rules, "%s", c.arules);
    }
    free(fc.match);
    free(fc.tok_line);
    smap_free(&fc.externs);
    lex_free(&L);
}

/* signature line of a definition whose first line entry is at line `start` (for unchecked definitions) */
int signature_line(const Lexed *L, const char *sym, int start)
{
    char name[256], cls[256];
    int kind;
    name_info(sym, name, cls, &kind);
    if (kind == NK_GEN || !name[0]) return start;
    for (int l = start; l >= 1 && l >= start - 40; l--) {
        int len;
        const char *s = line_start(L, l, &len);
        if (line_has_def(s, len, name, kind)) return l;
        const char *t = s;
        int tl = len;
        trim(&t, &tl);
        if (l < start && tl > 0 && (t[tl - 1] == ';' || t[tl - 1] == '}') && !is_comment_line(t, tl)) break;
    }
    return start;
}

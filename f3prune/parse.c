/* parse.c - see parse.h */
#include "../f3rules/util.h"
#include "parse.h"

typedef struct {
    int kind;
    int def;                   /* SK_FUNC: index of its Def */
    int s_start, s_n, s_dir;   /* SK_CLASS/SK_INIT at decl level: the enclosing statement state to restore */
    int s_eq, s_cls, s_paren;
} Scope;

static int is_decl_level(int k) { return k == SK_TOP || k == SK_NS || k == SK_EXTC || k == SK_CLASS; }

static int tk_is(const PLex *L, int i, const char *s) { return ptk_eq(L, i, s); }

static int is_attr_kw(const PLex *L, int i)
{
    return tk_is(L, i, "__declspec") || tk_is(L, i, "__pragma") || tk_is(L, i, "__attribute__") ||
           tk_is(L, i, "alignas") || tk_is(L, i, "__declspec");
}

/* skips a balanced group starting at the opening token i ("(" or "<"); returns the index after the closer */
static int skip_group(const PLex *L, int i, int e, const char *open, const char *close)
{
    int d = 0;
    for (int j = i; j < e; j++) {
        if (tk_is(L, j, open)) d++;
        else if (tk_is(L, j, close)) {
            d--;
            if (d == 0) return j + 1;
        } else if (open[0] == '<' && tk_is(L, j, ">>")) {
            d -= 2;
            if (d <= 0) return j + 1;
        }
    }
    return e;
}

/* index of the first taken non-directive token in [s,e) at or after s */
static int next_real(const PLex *L, int s, int e)
{
    while (s < e && (L->toks[s].type == P_DIR || !L->toks[s].taken)) s++;
    return s;
}

static int classify(const PLex *L, int s, int e, Def *d)
{
    int k = next_real(L, s, e);
    int is_tmpl = 0;
    while (k < e && tk_is(L, k, "template") && tk_is(L, next_real(L, k + 1, e), "<")) {
        is_tmpl = 1;
        k = skip_group(L, next_real(L, k + 1, e), e, "<", ">");
        k = next_real(L, k, e);
    }
    if (k < e && tk_is(L, k, "namespace")) return SK_NS;
    if (k + 1 < e && tk_is(L, k, "inline") && tk_is(L, k + 1, "namespace")) return SK_NS;
    if (tk_is(L, k, "extern") && L->toks[next_real(L, k + 1, e)].type == P_STR && next_real(L, next_real(L, k + 1, e) + 1, e) == e)
        return SK_EXTC;
    int pd = 0, ad = 0, clskey = 0, paren = -1, has_try = 0, is_inline = 0;
    for (int j = k; j < e; j++) {
        if (L->toks[j].type == P_DIR || !L->toks[j].taken) continue;
        if (is_attr_kw(L, j)) {
            int q = next_real(L, j + 1, e);
            if (tk_is(L, q, "(")) j = skip_group(L, q, e, "(", ")") - 1;
            continue;
        }
        if (tk_is(L, j, "(")) {
            if (pd == 0 && paren < 0) paren = j;
            pd++;
        } else if (tk_is(L, j, ")"))
            pd--;
        else if (pd == 0 && paren < 0 && tk_is(L, j, "=") && !tk_is(L, j - 1, "operator"))
            return SK_INIT;
        else if (pd == 0 && paren < 0 && (tk_is(L, j, "class") || tk_is(L, j, "struct") || tk_is(L, j, "union")))
            clskey = 1;
        else if (pd == 0 && paren < 0 && tk_is(L, j, "enum"))
            clskey = 2;
        else if (tk_is(L, j, "try"))
            has_try = 1;
        else if (paren < 0 && (tk_is(L, j, "inline") || tk_is(L, j, "__inline") || tk_is(L, j, "__forceinline")))
            is_inline = 1;
        (void)ad;
    }
    if (paren >= 0 && clskey != 2) {
        memset(d, 0, sizeof *d);
        d->head = next_real(L, s, e);
        d->is_template = is_tmpl;
        d->is_inline = is_inline;
        if (has_try) d->bad = DB_TRY;
        /* the name: "operator" anywhere before the parameter list, else the identifier before it */
        int op = -1;
        for (int j = k; j < paren; j++)
            if (tk_is(L, j, "operator")) {
                op = j;
                break;
            }
        if (op >= 0) {
            d->is_operator = 1;
            d->name = op;
            snprintf(d->name_s, sizeof d->name_s, "operator");
        } else {
            int nt = paren - 1;
            while (nt > k && (L->toks[nt].type == P_DIR || !L->toks[nt].taken)) nt--;
            d->name = nt;
            if (L->toks[nt].type == P_IDENT)
                snprintf(d->name_s, sizeof d->name_s, "%.*s", L->toks[nt].len, L->text + L->toks[nt].off);
            else
                d->bad = DB_PREFIX;
            int pt = nt - 1;
            while (pt > k && (L->toks[pt].type == P_DIR || !L->toks[pt].taken)) pt--;
            if (pt >= k && tk_is(L, pt, "~")) d->is_dtor = 1;
        }
        /* validate the tokens before the name */
        for (int j = k; j < d->name && !d->bad; j++) {
            const PTok *t = &L->toks[j];
            if (t->type == P_DIR || !t->taken) {
                d->bad = DB_DIRECTIVE;
                break;
            }
            if (is_attr_kw(L, j)) {
                int q = next_real(L, j + 1, e);
                if (tk_is(L, q, "(")) j = skip_group(L, q, e, "(", ")") - 1;
                continue;
            }
            if (tk_is(L, j, "<")) {
                j = skip_group(L, j, d->name, "<", ">") - 1;
                continue;
            }
            if (t->type == P_IDENT || t->type == P_STR) continue;
            if (tk_is(L, j, "::") || tk_is(L, j, "*") || tk_is(L, j, "&") || tk_is(L, j, "~")) continue;
            d->bad = DB_PREFIX;
        }
        /* the ctor-initializer, if any: a ':' at depth 0 after the parameter list */
        d->body_from = -1;
        int after = skip_group(L, op >= 0 ? next_real(L, paren + 1, e) : paren, e, "(", ")");
        if (op >= 0 && tk_is(L, paren + 1, ")")) after = skip_group(L, next_real(L, paren + 2, e), e, "(", ")");
        for (int j = after; j < e; j++)
            if (tk_is(L, j, ":")) {
                d->body_from = j;
                break;
            }
        return SK_FUNC;
    }
    if (clskey == 1) return SK_CLASS;
    return SK_INIT;
}

void parse_file(const PLex *L, Parsed *P)
{
    memset(P, 0, sizeof *P);
    VEC(Def) defs = {0};
    VEC(Stmt) stmts = {0};
    VEC(Scope) st = {0};
    int s_start = 0, s_n = 0, s_dir = 0, s_eq = -1, s_cls = -1, s_paren = 0;
    int s_clsr = -1;
    for (int i = 0; i < L->ntoks; i++) {
        const PTok *t = &L->toks[i];
        int top = st.n ? st.v[st.n - 1].kind : SK_TOP;
        if (t->type == P_DIR || !t->taken) {
            if (is_decl_level(top)) {
                if (s_n == 0)
                    s_start = i + 1;
                else
                    s_dir = 1;
            }
            continue;
        }
        if (!is_decl_level(top)) {
            if (tk_is(L, i, "{")) {
                Scope sc = {SK_BLOCK, -1};
                VPUSH(st, sc);
            } else if (tk_is(L, i, "}")) {
                Scope sc = st.v[--st.n];
                if (sc.kind == SK_FUNC) {
                    Def *d = &defs.v[sc.def];
                    d->rbrace = i;
                    d->endtok = i;
                    int nx = i + 1;
                    if (nx < L->ntoks && tk_is(L, nx, ";") && L->toks[nx].line == t->line) {
                        d->endtok = nx;
                        i = nx;
                    }
                    d->last_line = t->line;
                    if (d->endtok + 1 < L->ntoks && L->toks[d->endtok + 1].line == L->toks[d->endtok].line && !d->bad)
                        d->bad = DB_LINEEND;
                    for (int j = d->head; j <= d->rbrace && !d->bad; j++)
                        if (L->toks[j].type == P_DIR || !L->toks[j].taken) d->bad = DB_DIRECTIVE;
                    s_start = i + 1;
                    s_n = 0;
                    s_dir = 0;
                    s_eq = -1;
                    s_cls = -1;
                    s_paren = 0;
                } else if (sc.kind == SK_INIT) {
                    int nt = st.n ? st.v[st.n - 1].kind : SK_TOP;
                    if (is_decl_level(nt)) {
                        s_start = sc.s_start;
                        s_n = sc.s_n + 1;
                        s_dir = sc.s_dir;
                        s_eq = sc.s_eq;
                        s_cls = sc.s_cls;
                        s_paren = sc.s_paren;
                    }
                }
            }
            continue;
        }
        /* declaration level */
        if (tk_is(L, i, ";") && s_paren == 0) {
            if (s_n > 0) {
                Stmt sm;
                sm.first = next_real(L, s_start, i);
                sm.last = i;
                sm.parent = top;
                sm.has_eq = s_eq >= 0;
                sm.eq = s_eq;
                sm.class_body = s_cls;
                sm.class_rbrace = s_clsr;
                sm.dir = s_dir;
                VPUSH(stmts, sm);
            }
            s_start = i + 1;
            s_n = 0;
            s_dir = 0;
            s_eq = -1;
            s_cls = -1;
            s_clsr = -1;
            continue;
        }
        if (top == SK_CLASS && tk_is(L, i, ":") && s_n == 1 &&
            (tk_is(L, i - 1, "public") || tk_is(L, i - 1, "private") || tk_is(L, i - 1, "protected"))) {
            s_start = i + 1;
            s_n = 0;
            continue;
        }
        if (tk_is(L, i, "(")) s_paren++;
        if (tk_is(L, i, ")")) s_paren--;
        if (tk_is(L, i, "=") && s_paren == 0 && s_eq < 0 && !tk_is(L, i - 1, "operator")) s_eq = i;
        if (tk_is(L, i, "{")) {
            Def d;
            int k = classify(L, s_start, i, &d);
            Scope sc;
            memset(&sc, 0, sizeof sc);
            sc.kind = k;
            sc.def = -1;
            if (k == SK_FUNC) {
                d.lbrace = i;
                if (d.body_from < 0) d.body_from = i;
                d.parent = top;
                d.depth = st.n;
                d.first_line = L->toks[d.head].line;
                if (!d.bad && d.head > 0 && L->toks[d.head - 1].end_line >= L->toks[d.head].line) d.bad = DB_LINESTART;
                if (!d.bad && s_dir) d.bad = DB_DIRECTIVE;
                VPUSH(defs, d);
                sc.def = defs.n - 1;
            } else if (k == SK_CLASS || k == SK_INIT) {
                sc.s_start = s_start;
                sc.s_n = s_n;
                sc.s_dir = s_dir;
                sc.s_eq = s_eq;
                sc.s_cls = k == SK_CLASS ? i : s_cls;
                sc.s_paren = s_paren;
                if (k == SK_INIT && s_eq < 0) sc.s_eq = i;
            }
            VPUSH(st, sc);
            s_start = i + 1;
            s_n = 0;
            s_dir = 0;
            s_eq = -1;
            s_cls = -1;
            s_paren = 0;
            continue;
        }
        if (tk_is(L, i, "}")) {
            if (!st.n) {
                P->unbalanced = 1;
                continue;
            }
            Scope sc = st.v[--st.n];
            if (sc.kind == SK_CLASS) {
                s_start = sc.s_start;
                s_n = sc.s_n + 1;
                s_dir = sc.s_dir;
                s_eq = sc.s_eq;
                s_cls = sc.s_cls;
                s_clsr = i;
                s_paren = sc.s_paren;
            } else {
                s_start = i + 1;
                s_n = 0;
                s_dir = 0;
                s_eq = -1;
                s_cls = -1;
                s_paren = 0;
            }
            continue;
        }
        s_n++;
    }
    if (st.n) P->unbalanced = 1;
    if (L->cond_unbalanced) P->unbalanced = 1;
    free(st.v);
    P->defs = defs.v;
    P->ndefs = defs.n;
    P->stmts = stmts.v;
    P->nstmts = stmts.n;
}

void parsed_free(Parsed *P)
{
    free(P->defs);
    free(P->stmts);
    memset(P, 0, sizeof *P);
}

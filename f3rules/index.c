/* index.c - pass 2: per-file declarations index over src/ and include/, then the global indexes.

   Per file, a scope walker follows namespace / extern "C" / class / other braces and reads each declaration
   statement at namespace or class scope:
   - struct/class/union definitions at namespace level (R1): qualified name, normalized body hash, #if branch;
   - virtual members with placeholder names in class bodies (R13);
   - members and globals declared volatile, and whether a "// volatile: <evidence>" note sits at the declaration
     (R17);
   - file-scope extern variable declarations in .c/.cpp files (R2). */
#include "model.h"

enum { SC_NS = 1, SC_LINK, SC_CLASS, SC_OTHER };

typedef struct {
    int kind;
    char *name;
} Scope;

static const char *decl_keywords[] = {"int", "char", "short", "long", "unsigned", "signed", "float", "double", "bool",
                                      "void", "const", "volatile", "struct", "class", "union", "enum", "static",
                                      "extern", "register", "mutable", "inline", "typename", "__int64", "__int32",
                                      "__int16", "__int8", "wchar_t", "__declspec", "__cdecl", "__stdcall",
                                      "__fastcall", "__thiscall", "operator", "template", "virtual", "friend",
                                      "typedef", "public", "private", "protected", NULL};

static int is_decl_keyword(const Lexed *L, int i)
{
    for (int k = 0; decl_keywords[k]; k++)
        if (tk_eq(L, i, decl_keywords[k])) return 1;
    return 0;
}

int is_placeholder_virtual(const char *s, int n)
{
    int p;
    if (n >= 3 && s[0] == 'v' && s[1] == 'f' && isdigit((unsigned char)s[2])) {
        p = 2;
        while (p < n && isdigit((unsigned char)s[p])) p++;
    } else if (n >= 3 && strncmp(s, "pad", 3) == 0)
        p = 3;
    else if (n >= 5 && strncmp(s, "dummy", 5) == 0)
        p = 5;
    else if (n >= 3 && (strncmp(s, "unk", 3) == 0 || strncmp(s, "Unk", 3) == 0))
        p = 3;
    else
        return 0;
    for (; p < n; p++)
        if (!isxdigit((unsigned char)s[p]) && s[p] != '_') return 0;
    return 1;
}

static char *tok_str(const Lexed *L, int i) { return xstrndup(tk_ptr(L, i), (size_t)L->toks[i].len); }

static int brace_match_fwd(const Lexed *L, int open)
{
    int d = 0;
    for (int i = open; i < L->ntoks; i++) {
        if (tk_eq(L, i, "{")) d++;
        else if (tk_eq(L, i, "}")) {
            if (--d == 0) return i;
        }
    }
    return L->ntoks - 1;
}

/* Collect declarator names of statement [s, e). Function declarators are skipped. */
static void declarator_names(const Lexed *L, int s, int e, void (*cb)(void *, const Lexed *, int), void *ctx)
{
    int seg = s;
    while (seg < e) {
        int d = 0, end = seg, cut = -1;
        for (end = seg; end < e; end++) {
            if (tk_eq(L, end, "(") || tk_eq(L, end, "[") || tk_eq(L, end, "{")) d++;
            else if (tk_eq(L, end, ")") || tk_eq(L, end, "]") || tk_eq(L, end, "}")) d--;
            else if (d == 0 && tk_eq(L, end, ",")) break;
            else if (d == 0 && cut < 0 && (tk_eq(L, end, "=") || tk_eq(L, end, ":"))) cut = end;
        }
        int se = cut >= 0 ? cut : end;
        int firstparen = -1;
        d = 0;
        for (int k = seg; k < se; k++) {
            if (tk_eq(L, k, "(")) {
                if (d == 0 && firstparen < 0) firstparen = k;
                d++;
            } else if (tk_eq(L, k, ")"))
                d--;
        }
        if (firstparen >= 0) {
            int k = firstparen + 1;
            while (k < se && (tk_eq(L, k, "__cdecl") || tk_eq(L, k, "__stdcall") || tk_eq(L, k, "__fastcall") ||
                              tk_eq(L, k, "__thiscall")))
                k++;
            if (k < se && (tk_eq(L, k, "*") || tk_eq(L, k, "&"))) {
                while (k < se && (tk_eq(L, k, "*") || tk_eq(L, k, "&") || tk_eq(L, k, "const") || tk_eq(L, k, "volatile")))
                    k++;
                if (k < se && L->toks[k].type == T_IDENT) cb(ctx, L, k);
            }
        } else {
            int name = -1;
            for (int k = seg; k < se; k++) {
                if (tk_eq(L, k, "[")) break;
                if (L->toks[k].type == T_IDENT && !is_decl_keyword(L, k)) name = k;
            }
            if (name >= 0) cb(ctx, L, name);
        }
        seg = end + 1;
    }
}

typedef struct {
    FileIdx *fi;
    const Lexed *L;
    int noted;
    const char *cls;
} DeclCtx;

static void add_vol(void *c, const Lexed *L, int k)
{
    DeclCtx *dc = c;
    VolDecl v = {tok_str(L, k), dc->cls ? xstrdup(dc->cls) : NULL, L->toks[k].line, dc->noted};
    VPUSH(dc->fi->vols, v);
}

static void add_extern(void *c, const Lexed *L, int k)
{
    DeclCtx *dc = c;
    ExternDecl x = {tok_str(L, k), L->toks[k].line};
    VPUSH(dc->fi->externs, x);
}

static int has_volatile_note(const Lexed *L, int l0, int l1)
{
    for (int l = l0; l <= l1; l++) {
        int len;
        const char *s = line_start(L, l, &len);
        for (int i = 0; i + 1 < len; i++) {
            if (s[i] == '/' && s[i + 1] == '/') {
                int j = i + 2;
                while (j < len && (s[j] == ' ' || s[j] == '\t')) j++;
                if (len - j >= 9 && strncmp(s + j, "volatile:", 9) == 0) return 1;
            }
        }
    }
    return 0;
}

static void analyze_stmt(const Lexed *L, FileIdx *fi, int s, int e, int scope_kind, const char *cls, int cpp)
{
    if (s >= e) return;
    /* virtual members */
    if (scope_kind == SC_CLASS) {
        for (int k = s; k < e; k++) {
            if (!tk_eq(L, k, "virtual")) continue;
            int d = 0;
            for (int j = k + 1; j < e; j++) {
                if (tk_eq(L, j, "(")) {
                    if (d == 0 && j - 1 > k && L->toks[j - 1].type == T_IDENT) {
                        const char *nm = tk_ptr(L, j - 1);
                        int nl = L->toks[j - 1].len;
                        if (is_placeholder_virtual(nm, nl)) {
                            VirtDecl v = {xstrdup(cls ? cls : ""), tok_str(L, j - 1), L->toks[j - 1].line};
                            VPUSH(fi->virts, v);
                        }
                    }
                    break;
                }
            }
            break;
        }
    }
    if (tk_eq(L, s, "typedef") || tk_eq(L, s, "friend") || tk_eq(L, s, "using") || tk_eq(L, s, "template")) return;
    /* volatile members/globals */
    if (scope_kind == SC_NS || scope_kind == SC_LINK || scope_kind == SC_CLASS) {
        int d = 0, vol = -1;
        for (int k = s; k < e; k++) {
            if (tk_eq(L, k, "(") || tk_eq(L, k, "[")) d++;
            else if (tk_eq(L, k, ")") || tk_eq(L, k, "]")) d--;
            else if (d == 0 && tk_eq(L, k, "volatile")) {
                vol = k;
                break;
            }
        }
        if (vol >= 0) {
            DeclCtx dc = {fi, L, has_volatile_note(L, L->toks[s].line - 1, L->toks[e - 1].line),
                          scope_kind == SC_CLASS ? cls : NULL};
            declarator_names(L, s, e, add_vol, &dc);
        }
    }
    /* file-scope extern variables */
    if (cpp && (scope_kind == SC_NS || scope_kind == SC_LINK) && tk_eq(L, s, "extern")) {
        int k = s + 1;
        if (k < e && L->toks[k].type == T_STR) k++;
        DeclCtx dc = {fi, L, 0, NULL};
        declarator_names(L, k, e, add_extern, &dc);
    }
}

void index_file(int fid)
{
    SrcFile *sf = &g_files[fid];
    FileIdx *fi = &g_fidx[fid];
    Lexed L;
    if (lex_file(sf->abs, &L) != 0) return;
    fi->ok = 1;
    VEC(Scope) st = {0};
    int stmt = 0, paren = 0, pending_brace = -1;
    char *pending_name = NULL;
    for (int i = 0; i < L.ntoks; i++) {
        int top = st.n ? st.v[st.n - 1].kind : SC_NS;
        int declscope = top != SC_OTHER;
        Tok *t = &L.toks[i];
        if (t->type == T_PUNCT && t->len == 1) {
            char c = L.text[t->off];
            if (c == '(' || c == '[') {
                paren++;
                continue;
            }
            if (c == ')' || c == ']') {
                if (paren > 0) paren--;
                continue;
            }
            if (c == '{') {
                Scope sc = {SC_OTHER, NULL};
                if (declscope) {
                    if (i == pending_brace) {
                        /* qualified class name: enclosing class, else the namespace path */
                        StrBuf q = {0};
                        int inner = -1;
                        for (int k = st.n - 1; k >= 0 && inner < 0; k--)
                            if (st.v[k].kind == SC_CLASS) inner = k;
                        if (inner >= 0 && st.v[inner].name && st.v[inner].name[0]) {
                            sb_adds(&q, st.v[inner].name);
                            sb_adds(&q, "::");
                        } else if (inner < 0)
                            for (int k = 0; k < st.n; k++)
                                if (st.v[k].kind == SC_NS && st.v[k].name && st.v[k].name[0]) {
                                    sb_adds(&q, st.v[k].name);
                                    sb_adds(&q, "::");
                                }
                        sb_adds(&q, pending_name ? pending_name : "");
                        sc.kind = SC_CLASS;
                        sc.name = (pending_name && pending_name[0]) ? q.s : (free(q.s), xstrdup(""));
                        free(pending_name);
                        pending_name = NULL;
                    } else if (stmt < i && tk_eq(&L, stmt, "namespace")) {
                        sc.kind = SC_NS;
                        sc.name = (stmt + 1 < i && L.toks[stmt + 1].type == T_IDENT) ? tok_str(&L, stmt + 1) : xstrdup("");
                    } else if (stmt + 2 == i && tk_eq(&L, stmt, "extern") && L.toks[stmt + 1].type == T_STR) {
                        sc.kind = SC_LINK;
                    } else if (top == SC_CLASS) {
                        analyze_stmt(&L, fi, stmt, i, SC_CLASS, st.v[st.n - 1].name, 0);
                    }
                }
                VPUSH(st, sc);
                stmt = i + 1;
                paren = 0;
                continue;
            }
            if (c == '}') {
                if (st.n) {
                    st.n--;
                    free(st.v[st.n].name);
                }
                paren = 0;
                stmt = i + 1;
                continue;
            }
            if (c == ';' && declscope) {
                analyze_stmt(&L, fi, stmt, i, top, top == SC_CLASS ? st.v[st.n - 1].name : NULL, sf->is_cpp);
                stmt = i + 1;
                paren = 0;
                continue;
            }
            if (c == ':' && top == SC_CLASS && i > 0 &&
                (tk_eq(&L, i - 1, "public") || tk_eq(&L, i - 1, "private") || tk_eq(&L, i - 1, "protected"))) {
                stmt = i + 1;
                continue;
            }
        }
        if (!declscope || paren) continue;
        if (t->type == T_IDENT && (tk_eq(&L, i, "struct") || tk_eq(&L, i, "class") || tk_eq(&L, i, "union"))) {
            /* class head */
            int j = i + 1, name = -1, spec = 0, qual = 0;
            while (j < L.ntoks) {
                if (tk_eq(&L, j, "__declspec") || tk_eq(&L, j, "__attribute__")) {
                    j++;
                    if (tk_eq(&L, j, "(")) {
                        int d = 0;
                        for (; j < L.ntoks; j++) {
                            if (tk_eq(&L, j, "(")) d++;
                            else if (tk_eq(&L, j, ")") && --d == 0) break;
                        }
                        j++;
                    }
                    continue;
                }
                if (L.toks[j].type == T_IDENT) {
                    name = j++;
                    continue;
                }
                if (tk_eq(&L, j, "::") && name >= 0) {
                    qual = 1;
                    j++;
                    continue;
                }
                if (tk_eq(&L, j, "<") && name >= 0) {
                    spec = 1;
                    int d = 0;
                    for (; j < L.ntoks; j++) {
                        if (tk_eq(&L, j, "<")) d++;
                        else if (tk_eq(&L, j, ">") && --d == 0) break;
                        else if (tk_eq(&L, j, ";") || tk_eq(&L, j, "{")) break;
                    }
                    if (tk_eq(&L, j, ">")) j++;
                    continue;
                }
                break;
            }
            int b = -1;
            if (tk_eq(&L, j, "{")) b = j;
            else if (tk_eq(&L, j, ":") && name >= 0) {
                for (int k = j; k < L.ntoks; k++) {
                    if (tk_eq(&L, k, "{")) {
                        b = k;
                        break;
                    }
                    if (tk_eq(&L, k, ";") || tk_eq(&L, k, "}")) break;
                }
            }
            if (b < 0) continue;
            pending_brace = b;
            free(pending_name);
            pending_name = name >= 0 ? tok_str(&L, name) : xstrdup("");
            int nslevel = 1;
            for (int k = 0; k < st.n; k++)
                if (st.v[k].kind != SC_NS && st.v[k].kind != SC_LINK) nslevel = 0;
            if (nslevel && name >= 0 && !spec) {
                int close = brace_match_fwd(&L, b);
                uint64_t h = FNV64_INIT;
                for (int k = j; k <= close; k++) {
                    h = fnv64(tk_ptr(&L, k), (size_t)L.toks[k].len, h);
                    h = fnv64(" ", 1, h);
                }
                StrBuf key = {0};
                for (int k = 0; k < st.n; k++)
                    if (st.v[k].kind == SC_NS && st.v[k].name && st.v[k].name[0]) {
                        sb_adds(&key, st.v[k].name);
                        sb_adds(&key, "::");
                    }
                if (qual)
                    for (int k = i + 1; k < name; k++)
                        if (L.toks[k].type == T_IDENT || tk_eq(&L, k, "::")) sb_add(&key, tk_ptr(&L, k), (size_t)L.toks[k].len);
                sb_add(&key, tk_ptr(&L, name), (size_t)L.toks[name].len);
                TypeDef td = {key.s, tok_str(&L, name), L.toks[name].line, L.toks[name].cond, h};
                VPUSH(fi->types, td);
            }
            i = b - 1; /* continue at the brace */
        }
    }
    for (int k = 0; k < st.n; k++) free(st.v[k].name);
    free(st.v);
    free(pending_name);
    fi->includes = L.includes;
    fi->nincludes = L.nincludes;
    L.includes = NULL;
    L.nincludes = 0;
    fi->conds = L.conds;
    fi->conds_n = L.nconds;
    L.conds = NULL;
    lex_free(&L);
}

int fidx_cond_exclusive(const FileIdx *fi, int a, int b)
{
    for (int x = a; x > 0; x = fi->conds[x].parent)
        for (int y = b; y > 0; y = fi->conds[y].parent)
            if (fi->conds[x].group == fi->conds[y].group && fi->conds[x].branch != fi->conds[y].branch) return 1;
    return 0;
}

static void vec_add_file(StrMap *m, const char *key, int file)
{
    void **slot = smap_slot(m, key);
    IntVec *v = *slot;
    if (!v) {
        v = xcalloc(1, sizeof *v);
        *slot = v;
    }
    for (int i = 0; i < v->n; i++)
        if (v->v[i] == file) return;
    VPUSH(*v, file);
}

typedef struct {
    int file;
    char *name;
} VirtRef;
typedef VEC(VirtRef) VirtVec;

void build_global_indexes(void)
{
    smap_init(&g_r1_keys, 1 << 16);
    smap_init(&g_r1_names, 1024);
    smap_init(&g_virt_by_class, 1024);
    smap_init(&g_virt_names, 1024);
    smap_init(&g_vol_globals, 1024);
    smap_init(&g_vol_members, 1024);
    for (int f = 0; f < g_nfiles; f++) {
        FileIdx *fi = &g_fidx[f];
        for (int k = 0; k < fi->types.n; k++) {
            TypeDef *td = &fi->types.v[k];
            void **slot = smap_slot(&g_r1_keys, td->key);
            R1Key *rk = *slot;
            if (!rk) {
                rk = xcalloc(1, sizeof *rk);
                rk->key = xstrdup(td->key);
                *slot = rk;
            }
            TDRef r = {f, td->line, td->cond, td->hash};
            VPUSH(rk->defs, r);
        }
        for (int k = 0; k < fi->virts.n; k++) {
            VirtDecl *vd = &fi->virts.v[k];
            void **slot = smap_slot(&g_virt_by_class, vd->cls);
            VirtVec *v = *slot;
            if (!v) {
                v = xcalloc(1, sizeof *v);
                *slot = v;
            }
            VirtRef r = {f, vd->name};
            VPUSH(*v, r);
            vec_add_file(&g_virt_names, vd->name, f);
        }
        for (int k = 0; k < fi->vols.n; k++) {
            VolDecl *vd = &fi->vols.v[k];
            if (vd->noted) continue;
            if (vd->cls) {
                char key[1024];
                snprintf(key, sizeof key, "%s\x01%s", vd->cls, vd->name);
                vec_add_file(&g_vol_members, key, f);
            } else {
                /* pairs (file, line): the earliest declaration per file */
                void **slot = smap_slot(&g_vol_globals, vd->name);
                IntVec *v = *slot;
                if (!v) {
                    v = xcalloc(1, sizeof *v);
                    *slot = v;
                }
                int have = 0;
                for (int q = 0; q + 1 < v->n; q += 2)
                    if (v->v[q] == f) have = 1;
                if (!have) {
                    VPUSH(*v, f);
                    VPUSH(*v, vd->line);
                }
            }
        }
    }
    int nconf = 0;
    for (size_t s = 0; s < g_r1_keys.cap; s++) {
        if (!g_r1_keys.hashes[s]) continue;
        R1Key *rk = g_r1_keys.vals[s];
        TDVec *v = &rk->defs;
        for (int a = 0; a < v->n && !rk->conflicted; a++)
            for (int b = a + 1; b < v->n && !rk->conflicted; b++) {
                if (v->v[a].file == v->v[b].file) {
                    if (!fidx_cond_exclusive(&g_fidx[v->v[a].file], v->v[a].cond, v->v[b].cond)) rk->conflicted = 1;
                } else if (v->v[a].hash != v->v[b].hash)
                    rk->conflicted = 1;
            }
        if (!rk->conflicted) continue;
        nconf++;
        const char *un = strrchr(rk->key, ':');
        un = un ? un + 1 : rk->key;
        void **slot = smap_slot(&g_r1_names, un);
        R1KeyVec *kv = *slot;
        if (!kv) {
            kv = xcalloc(1, sizeof *kv);
            *slot = kv;
        }
        VPUSH(*kv, rk);
    }
    fprintf(stderr, "f3rules: type index: %zu type names, %d conflicting; %zu placeholder-virtual classes; "
                    "%zu volatile globals, %zu volatile members\n",
            g_r1_keys.n, nconf, g_virt_by_class.n, g_vol_globals.n, g_vol_members.n);
}

/* ---- include closures ---- */

static void norm_join(const char *dir, const char *rel, char *out, int cap)
{
    char buf[1024];
    snprintf(buf, sizeof buf, "%s%s", dir, rel);
    slash_inplace(buf);
    lower_inplace(buf);
    /* resolve . and .. */
    char *parts[128];
    int np = 0;
    char *ctx = NULL;
    for (char *p = strtok_s(buf, "/", &ctx); p && np < 128; p = strtok_s(NULL, "/", &ctx)) {
        if (strcmp(p, ".") == 0) continue;
        if (strcmp(p, "..") == 0) {
            if (np) np--;
            continue;
        }
        parts[np++] = p;
    }
    out[0] = 0;
    int k = 0;
    for (int i = 0; i < np; i++) {
        int n = snprintf(out + k, (size_t)(cap - k), "%s%s", i ? "/" : "", parts[i]);
        if (n < 0 || k + n >= cap) break;
        k += n;
    }
}

static int resolve_include(const char *inc, int includer, int tu)
{
    char path[1024];
    const char *name = inc + 1;
    if (inc[0] == '"') {
        norm_join(g_files[includer].dir_key, name, path, sizeof path);
        int f = file_lookup_rel(path);
        if (f >= 0) return f;
        if (tu >= 0) {
            norm_join(g_files[tu].dir_key, name, path, sizeof path);
            f = file_lookup_rel(path);
            if (f >= 0) return f;
        }
    }
    norm_join("include/", name, path, sizeof path);
    return file_lookup_rel(path);
}

void build_closures(void)
{
    int bytes = (g_nfiles + 7) / 8;
    int *stack = xmalloc(sizeof(int) * (size_t)(g_nfiles + 1));
    for (int u = 0; u < g_nunits; u++) {
        Unit *un = &g_units[u];
        un->closure = xcalloc((size_t)bytes, 1);
        int src = un->src_file;
        if (src < 0) continue;
        /* units sharing a source share the closure */
        int shared = 0;
        for (int v = 0; v < u; v++)
            if (g_units[v].src_file == src) {
                memcpy(un->closure, g_units[v].closure, (size_t)bytes);
                shared = 1;
                break;
            }
        if (shared) continue;
        int sp = 0;
        stack[sp++] = src;
        BIT_SET(un->closure, src);
        while (sp) {
            int f = stack[--sp];
            FileIdx *fi = &g_fidx[f];
            for (int k = 0; k < fi->nincludes; k++) {
                int g = resolve_include(fi->includes[k], f, src);
                if (g >= 0 && !BIT_GET(un->closure, g)) {
                    BIT_SET(un->closure, g);
                    stack[sp++] = g;
                }
            }
        }
    }
    free(stack);
}

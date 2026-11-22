/* decls.inc - the second pass (f3prune decls), included by main.c.

   In each listed .cpp/.c file, removes the file-scope (namespace-level) declarations that nothing else names:
   extern declarations, prototypes, class/struct/union definitions without declarators (stand-ins) and forward
   declarations. A declaration goes only when its name appears nowhere else in the translation-unit group (the
   .cpp/.c files joined by #include "x.cpp", directive text and untaken #if branches included) and in no header
   those files include. Never a statement that holds a directive, shares a line, has an initializer or several
   declarators, a class that holds a function definition, or anything that reads like a call or an object
   construction (Foo bar(baz);). Removing one may free others; the pass runs to a fixpoint. */

static StrMap g_hdr_seen;

static void dir_idents(StrMap *m, const char *d, const char *e, int sign)
{
    char buf[256];
    for (const char *q = d; q < e;) {
        if (isalpha((unsigned char)*q) || *q == '_') {
            const char *b = q;
            while (q < e && (isalnum((unsigned char)*q) || *q == '_')) q++;
            if (q - b < 200) {
                snprintf(buf, sizeof buf, "%.*s", (int)(q - b), b);
                void **v = smap_slot(m, buf);
                *v = (void *)((intptr_t)*v + sign);
            }
        } else
            q++;
    }
}

/* resolves a "..." include of a file in folder `dir`: that folder, include/, src/, the repository root */
static int resolve_include(const char *dir, const char *name, char *out, size_t cap)
{
    char b1[MAX_PATH], b2[MAX_PATH];
    snprintf(b1, sizeof b1, "%s/include", g_repo);
    snprintf(b2, sizeof b2, "%s/src", g_repo);
    const char *bases[4] = {dir, b1, b2, g_repo};
    for (int k = 0; k < 4; k++) {
        snprintf(out, cap, "%s/%s", bases[k], name);
        if (GetFileAttributesA(out) != INVALID_FILE_ATTRIBUTES) return 1;
    }
    return 0;
}

/* the quoted name of an #include directive token, or 0 */
static int include_name(const PLex *L, const PTok *t, char *name, size_t cap)
{
    const char *d = L->text + t->off, *e = d + t->len;
    const char *p = d + 1;
    while (p < e && (*p == ' ' || *p == '\t')) p++;
    if (e - p < 7 || strncmp(p, "include", 7) != 0) return 0;
    const char *q1 = memchr(p, '"', (size_t)(e - p));
    if (!q1) return 0;
    const char *q2 = memchr(q1 + 1, '"', (size_t)(e - q1 - 1));
    if (!q2) return 0;
    snprintf(name, cap, "%.*s", (int)(q2 - q1 - 1), q1 + 1);
    return 1;
}

static void header_idents(const char *path_abs, StrMap *H, int depth)
{
    if (depth > 60) return;
    char key[1024];
    norm_path(path_abs, key, sizeof key);
    void **slot = smap_slot(&g_hdr_seen, key);
    if (*slot) return;
    *slot = (void *)1;
    PLex L;
    if (plex_file(path_abs, &L) != 0) return;
    char dir[MAX_PATH];
    snprintf(dir, sizeof dir, "%s", path_abs);
    slash_inplace(dir);
    char *sl = strrchr(dir, '/');
    if (sl) *sl = 0;
    char buf[256];
    for (int j = 0; j < L.ntoks; j++) {
        PTok *t = &L.toks[j];
        if (t->type == P_IDENT && t->len < 200) {
            memcpy(buf, L.text + t->off, (size_t)t->len);
            buf[t->len] = 0;
            smap_put(H, buf, (void *)1);
        } else if (t->type == P_DIR) {
            dir_idents(H, L.text + t->off, L.text + t->off + t->len, 1);
            char name[512], cand[1024];
            if (include_name(&L, t, name, sizeof name) && resolve_include(dir, name, cand, sizeof cand))
                header_idents(cand, H, depth + 1);
        }
    }
    plex_free(&L);
}

enum { DK_EXTERN = 1, DK_PROTO, DK_CLASS, DK_FWD };
static const char *dk_name[] = {"", "extern", "prototype", "class", "forward"};

typedef struct {
    int file, stmt, kind, removed;
    char name[256];
} DeclC;

static int is_kw(const PLex *L, int j, const char *const *list)
{
    for (int k = 0; list[k]; k++)
        if (ptk_eq(L, j, list[k])) return 1;
    return 0;
}

static int skip_angles(const PLex *L, int j, int end)
{
    int d = 0;
    for (; j < end; j++) {
        if (ptk_eq(L, j, "<")) d++;
        else if (ptk_eq(L, j, ">") && --d == 0) return j;
        else if (ptk_eq(L, j, ">>") && (d -= 2) <= 0) return j;
    }
    return end;
}

/* the kind and declared name of a file-scope statement this pass may remove; 0 when it is none of them */
static int decl_kind(File *F, int si, char *name, size_t cap)
{
    PLex *L = &F->L;
    Parsed *P = &F->P;
    Stmt *sm = &P->stmts[si];
    if (sm->parent != SK_TOP && sm->parent != SK_NS && sm->parent != SK_EXTC) return 0;
    if (sm->dir) return 0;
    int a = sm->first, b = sm->last; /* b is the ';' */
    if (a >= b) return 0;
    if (a > 0 && L->toks[a - 1].end_line >= L->toks[a].line) return 0;
    if (b + 1 < L->ntoks && L->toks[b + 1].line == L->toks[b].line) return 0;
    for (int j = a; j <= b; j++)
        if (L->toks[j].type == P_DIR || !L->toks[j].taken) return 0;
    static const char *const never[] = {"typedef", "using", "template", "friend", "namespace", "static_assert",
                                        "__if_exists", "__if_not_exists", "enum", "operator", "__pragma", NULL};
    for (int j = a; j < b; j++)
        if (is_kw(L, j, never)) return 0;
    int is_extern = 0, k = a;
    if (ptk_eq(L, k, "extern")) {
        is_extern = 1;
        k++;
        if (L->toks[k].type == P_STR) k++;
    }
    if (sm->class_body >= 0) {
        if (is_extern || sm->has_eq || sm->class_rbrace + 1 != b) return 0;
        for (int d = 0; d < P->ndefs; d++)
            if (P->defs[d].lbrace > sm->class_body && P->defs[d].lbrace < sm->class_rbrace) return 0;
        if (!(ptk_eq(L, k, "struct") || ptk_eq(L, k, "class") || ptk_eq(L, k, "union"))) return 0;
        if (!class_stmt_name(F, sm, name, cap)) return 0;
        return DK_CLASS;
    }
    if (sm->has_eq) return 0;
    int pd = 0, sq = 0, paren = -1, pclose = -1;
    for (int j = k; j < b; j++) {
        if (ptk_eq(L, j, "<") && pd == 0) {
            j = skip_angles(L, j, b);
            continue;
        }
        if (ptk_eq(L, j, "(")) {
            if (pd == 0 && paren < 0) paren = j;
            pd++;
        } else if (ptk_eq(L, j, ")")) {
            pd--;
            if (pd == 0 && pclose < 0) pclose = j;
        } else if (ptk_eq(L, j, "[")) sq++;
        else if (ptk_eq(L, j, "]")) sq--;
        else if (ptk_eq(L, j, ",") && pd == 0 && sq == 0) return 0;
        else if (ptk_eq(L, j, "{") || ptk_eq(L, j, "}")) return 0;
    }
    if ((ptk_eq(L, k, "struct") || ptk_eq(L, k, "class") || ptk_eq(L, k, "union")) && paren < 0) {
        if (is_extern) return 0;
        int j = k + 1;
        if (j + 1 == b && L->toks[j].type == P_IDENT) {
            snprintf(name, cap, "%.*s", L->toks[j].len, L->text + L->toks[j].off);
            return DK_FWD;
        }
        return 0;
    }
    if (paren >= 0) {
        /* a prototype: <specifiers and type> name ( parameters ) [const] [throw ( ... )] ; */
        int nt = paren - 1;
        if (nt <= k || L->toks[nt].type != P_IDENT) return 0;
        if (ptk_eq(L, nt - 1, "::") || ptk_eq(L, nt - 1, "~")) return 0;
        if (ptk_eq(L, k + 1, "(")) return 0; /* call-like: a macro invocation */
        for (int j = k; j < nt; j++) {
            if (L->toks[j].type == P_IDENT || ptk_eq(L, j, "*") || ptk_eq(L, j, "&") || ptk_eq(L, j, "::")) continue;
            if (ptk_eq(L, j, "<")) {
                j = skip_angles(L, j, nt);
                continue;
            }
            return 0;
        }
        for (int j = k; j < nt; j++)
            if (ptk_eq(L, j, "__declspec")) return 0;
        for (int j = pclose + 1; j < b; j++) {
            if (ptk_eq(L, j, "const")) continue;
            if (ptk_eq(L, j, "throw") && ptk_eq(L, j + 1, "(")) {
                int d = 0;
                for (j = j + 1; j < b; j++) {
                    if (ptk_eq(L, j, "(")) d++;
                    else if (ptk_eq(L, j, ")") && --d == 0) break;
                }
                continue;
            }
            return 0;
        }
        /* the parameters must read as types, not as constructor arguments */
        static const char *const typeish[] = {"void", "int", "char", "short", "long", "float", "double", "bool",
                                              "unsigned", "signed", "const", "struct", "class", "union",
                                              "__int64", "__int32", "__int16", "__int8", "wchar_t", "volatile", NULL};
        static const char *const conv[] = {"__cdecl", "__stdcall", "__fastcall", "__thiscall", "static", "inline",
                                           "__forceinline", "__inline", "extern", "void", NULL};
        int ok = (pclose == paren + 1) || is_extern;
        for (int j = a; j < nt && !ok; j++)
            if (is_kw(L, j, conv)) ok = 1;
        for (int j = paren + 1; j < pclose; j++) {
            PTok *t = &L->toks[j];
            if (t->type == P_STR || t->type == P_CHR) return 0;
            if (t->type == P_NUM && !ptk_eq(L, j - 1, "=") && !ptk_eq(L, j - 1, "[") && !ptk_eq(L, j - 1, "-")) return 0;
            if (is_kw(L, j, typeish) || ptk_eq(L, j, "*") || ptk_eq(L, j, "&") || ptk_eq(L, j, "...")) ok = 1;
        }
        if (!ok) return 0;
        snprintf(name, cap, "%.*s", L->toks[nt].len, L->text + L->toks[nt].off);
        return DK_PROTO;
    }
    if (!is_extern) return 0;
    /* extern <type> name [ [N] ] ; */
    int nt = b - 1;
    if (ptk_eq(L, nt, "]")) {
        while (nt > k && !ptk_eq(L, nt, "[")) nt--;
        nt--;
    }
    if (nt <= k || L->toks[nt].type != P_IDENT) return 0;
    if (ptk_eq(L, nt - 1, "::")) return 0;
    for (int j = k; j < nt; j++) {
        if (L->toks[j].type == P_IDENT || ptk_eq(L, j, "*") || ptk_eq(L, j, "&") || ptk_eq(L, j, "::")) continue;
        if (ptk_eq(L, j, "<")) {
            j = skip_angles(L, j, nt);
            continue;
        }
        if (ptk_eq(L, j, "__declspec") && ptk_eq(L, j + 1, "(")) {
            int d = 0;
            for (j = j + 1; j < nt; j++) {
                if (ptk_eq(L, j, "(")) d++;
                else if (ptk_eq(L, j, ")") && --d == 0) break;
            }
            continue;
        }
        return 0;
    }
    snprintf(name, cap, "%.*s", L->toks[nt].len, L->text + L->toks[nt].off);
    return DK_EXTERN;
}

/* identifiers in directive text and in untaken #if branches */
static void count_hidden_idents(StrMap *m, File *F)
{
    char buf[256];
    for (int j = 0; j < F->L.ntoks; j++) {
        PTok *t = &F->L.toks[j];
        if (t->type == P_DIR) {
            dir_idents(m, F->L.text + t->off, F->L.text + t->off + t->len, 1);
            continue;
        }
        if (t->taken || t->type != P_IDENT || t->len >= 200) continue;
        memcpy(buf, F->L.text + t->off, (size_t)t->len);
        buf[t->len] = 0;
        void **v = smap_slot(m, buf);
        *v = (void *)((intptr_t)*v + 1);
    }
}

static int cmd_decls(int argc, char **argv)
{
    if (argc < 5) die("usage: f3prune decls <repo> <files.txt> <out.tsv> [--dry]");
    for (int i = 5; i < argc; i++) {
        if (strcmp(argv[i], "--dry") == 0)
            g_dry = 1;
        else
            die("unknown option %s", argv[i]);
    }
    g_no_banner = 1;
    smap_init(&g_file_by_rel, 8192);
    build_groups();
    size_t n;
    char *t = read_file(argv[3], &n);
    if (!t) die("cannot read %s", argv[3]);
    VEC(int) list = {0};
    char *sv = NULL;
    for (char *ln = strtok_s(t, "\r\n", &sv); ln; ln = strtok_s(NULL, "\r\n", &sv)) {
        char rel[1024];
        snprintf(rel, sizeof rel, "%s", ln);
        lower_inplace(rel);
        slash_inplace(rel);
        void *v = smap_get(&g_file_by_rel, rel);
        if (!v) {
            fprintf(stderr, "f3prune: not a source file: %s\n", ln);
            continue;
        }
        VPUSH(list, (int)(intptr_t)v - 1);
    }
    free(t);
    char *needg = xcalloc((size_t)g_files.n + 1, 1);
    for (int i = 0; i < list.n; i++) needg[find_root(list.v[i])] = 1;
    StrMap *T = xcalloc((size_t)g_files.n + 1, sizeof(StrMap));
    StrMap *H = xcalloc((size_t)g_files.n + 1, sizeof(StrMap));
    for (int f = 0; f < g_files.n; f++) {
        int grp = find_root(f);
        if (!needg[grp]) continue;
        File *F = load(f);
        if (F->loaded != 1) continue;
        count_idents(&T[grp], F, 0, F->L.ntoks - 1, 1);
        count_hidden_idents(&T[grp], F);
        if (!H[grp].cap) smap_init(&H[grp], 4096);
        smap_init(&g_hdr_seen, 1024);
        char dir[MAX_PATH];
        snprintf(dir, sizeof dir, "%s", F->abs);
        slash_inplace(dir);
        char *sl = strrchr(dir, '/');
        if (sl) *sl = 0;
        for (int j = 0; j < F->L.ntoks; j++) {
            PTok *tk = &F->L.toks[j];
            char name[512], cand[1024];
            if (tk->type != P_DIR || !include_name(&F->L, tk, name, sizeof name)) continue;
            if (is_cfile(name)) continue;
            if (resolve_include(dir, name, cand, sizeof cand)) header_idents(cand, &H[grp], 0);
        }
        smap_free(&g_hdr_seen);
    }
    VEC(DeclC) dc = {0};
    for (int i = 0; i < list.n; i++) {
        int f = list.v[i];
        File *F = &g_files.v[f];
        if (F->loaded != 1 || F->P.unbalanced) continue;
        for (int s2 = 0; s2 < F->P.nstmts; s2++) {
            DeclC d;
            memset(&d, 0, sizeof d);
            d.kind = decl_kind(F, s2, d.name, sizeof d.name);
            if (!d.kind) continue;
            d.file = f;
            d.stmt = s2;
            VPUSH(dc, d);
        }
    }
    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < dc.n; i++) {
            DeclC *d = &dc.v[i];
            if (d->removed) continue;
            int grp = find_root(d->file);
            if (smap_has(&H[grp], d->name)) continue;
            File *F = &g_files.v[d->file];
            Stmt *sm = &F->P.stmts[d->stmt];
            StrMap own = {0};
            count_idents(&own, F, sm->first, sm->last, 1);
            intptr_t rest = count_of(&T[grp], d->name) - count_of(&own, d->name);
            smap_free(&own);
            if (rest > 0) continue;
            d->removed = 1;
            count_idents(&T[grp], F, sm->first, sm->last, -1);
            changed = 1;
        }
    }
    int cnt[5] = {0}, files_edit = 0;
    for (int i = 0; i < list.n; i++) {
        int f = list.v[i];
        File *F = &g_files.v[f];
        int any = 0;
        for (int k = 0; k < dc.n; k++)
            if (dc.v[k].file == f && dc.v[k].removed) any = 1;
        if (!any) continue;
        F->drop = xcalloc((size_t)F->L.nlines + 2, 1);
        for (int k = 0; k < dc.n; k++) {
            DeclC *d = &dc.v[k];
            if (d->file != f || !d->removed) continue;
            Stmt *sm = &F->P.stmts[d->stmt];
            for (int l = F->L.toks[sm->first].line; l <= F->L.toks[sm->last].end_line; l++) F->drop[l] = 1;
            cnt[d->kind]++;
        }
        for (int l = 1; l <= F->L.nlines; l++) {
            if (!F->drop[l] || (l > 1 && F->drop[l - 1])) continue;
            int e = l;
            while (e + 1 <= F->L.nlines && F->drop[e + 1]) e++;
            int next = e + 1, follows = 0;
            if (next <= F->L.nlines && !line_blank(&F->L, next)) {
                const char *s = F->L.text + F->L.line_off[next - 1];
                while (*s == ' ' || *s == '\t') s++;
                follows = !(*s == '}' || *s == '#');
            }
            if (follows) continue;
            int c = l - 1;
            while (c >= 1 && is_comment_only(&F->L, c) && !F->drop[c]) c--;
            if (c == 0) continue;
            for (int k = c + 1; k < l; k++) F->drop[k] = 1;
        }
        files_edit++;
        write_file(F);
    }
    FILE *fo = fopen(argv[4], "wb");
    if (!fo) die("cannot write %s", argv[4]);
    fprintf(fo, "file\tline\tkind\tname\tstatus\n");
    for (int k = 0; k < dc.n; k++) {
        DeclC *d = &dc.v[k];
        File *F = &g_files.v[d->file];
        fprintf(fo, "%s\t%d\t%s\t%s\t%s\n", F->rel, F->L.toks[F->P.stmts[d->stmt].first].line, dk_name[d->kind],
                d->name, d->removed ? "removed" : "kept");
    }
    fclose(fo);
    printf("f3prune decls: %d files, %d candidate declarations; removed %d extern, %d prototypes, %d class definitions, "
           "%d forward declarations in %d files\n",
           list.n, dc.n, cnt[DK_EXTERN], cnt[DK_PROTO], cnt[DK_CLASS], cnt[DK_FWD], files_edit);
    return 0;
}

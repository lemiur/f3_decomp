/* f3ledger: write MATCH_PENDING.md from the rule checker's functions.tsv.
 *
 * usage: f3ledger <functions.tsv> <out.md> [<commit>]
 *
 * functions.tsv is f3rules' output (columns found by header name: address, unit_source, symbol, size, file,
 * first_line, status, match_rules). The ledger lists every MATCH-PENDING and UNLOCATED recipe function, grouped by
 * source file, with the [match] rules that fail, and opens with both progress numbers. Names are undecorated with
 * dbghelp (name only). The output is deterministic: files and functions sorted by path and address. */
#include <windows.h>
#include <dbghelp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma comment(lib, "dbghelp.lib")

typedef struct {
    unsigned addr, size;
    char *file, *symbol, *status, *rules, *module;
    int line;
} Row;

static char *dupstr(const char *s) { size_t n = strlen(s) + 1; char *p = malloc(n); memcpy(p, s, n); return p; }

static int split(char *line, char **f, int max)
{
    int n = 0;
    char *p = line;
    while (n < max) {
        f[n++] = p;
        p = strchr(p, '\t');
        if (!p) break;
        *p++ = 0;
    }
    return n;
}

static int col(char **h, int n, const char *name)
{
    for (int i = 0; i < n; i++) if (!strcmp(h[i], name)) return i;
    fprintf(stderr, "f3ledger: no column %s\n", name);
    exit(2);
}

static int cmp(const void *a, const void *b)
{
    const Row *x = a, *y = b;
    int c = strcmp(x->file, y->file);
    if (c) return c;
    return x->addr < y->addr ? -1 : x->addr > y->addr;
}

static void module_of(const char *file, char *out, size_t n)
{
    /* src/<dir>/ or src/ for files directly under src */
    const char *p = strchr(file, '/');
    const char *q = p ? strchr(p + 1, '/') : NULL;
    if (q) snprintf(out, n, "%.*s/", (int)(q - file), file);
    else snprintf(out, n, "src/");
}

typedef struct { char name[64]; unsigned fn, matched, pending, unloc; unsigned long long bytes, mbytes; } Mod;
typedef struct { const char *rule; unsigned n, only; } RuleCount;

int main(int argc, char **argv)
{
    if (argc < 3) { fprintf(stderr, "usage: f3ledger <functions.tsv> <out.md> [<commit>]\n"); return 2; }
    FILE *in = fopen(argv[1], "rb");
    if (!in) { perror(argv[1]); return 1; }
    static char buf[1 << 16];
    char *h[64], *f[64];
    if (!fgets(buf, sizeof buf, in)) return 1;
    buf[strcspn(buf, "\r\n")] = 0;
    char *hdr = dupstr(buf);
    int nh = split(hdr, h, 64);
    int cA = col(h, nh, "address"), cS = col(h, nh, "symbol"), cZ = col(h, nh, "size"), cF = col(h, nh, "file"),
        cL = col(h, nh, "first_line"), cT = col(h, nh, "status"), cR = col(h, nh, "match_rules"),
        cU = col(h, nh, "unit_source");
    size_t cap = 1 << 17, n = 0;
    Row *rows = malloc(cap * sizeof *rows);
    while (fgets(buf, sizeof buf, in)) {
        buf[strcspn(buf, "\r\n")] = 0;
        if (!*buf) continue;
        int k = split(buf, f, 64);
        if (k < nh) continue;
        if (n == cap) rows = realloc(rows, (cap *= 2) * sizeof *rows);
        Row *r = &rows[n++];
        r->addr = (unsigned)strtoul(f[cA], NULL, 16);
        r->size = (unsigned)strtoul(f[cZ], NULL, 10);
        r->file = dupstr(*f[cF] ? f[cF] : f[cU]);
        r->line = atoi(f[cL]);
        r->symbol = dupstr(f[cS]);
        r->status = dupstr(f[cT]);
        r->rules = dupstr(f[cR]);
        char m[64];
        module_of(r->file, m, sizeof m);
        r->module = dupstr(m);
    }
    fclose(in);
    qsort(rows, n, sizeof *rows, cmp);

    /* Totals, per module and per rule. Functions defined in several variant units appear once per unit, as the
       recipe lists them. */
    static Mod mods[256];
    int nm = 0;
    RuleCount rc[] = {{"R1"}, {"R2"}, {"R4"}, {"R13"}, {"R17"}, {"R18"}};
    unsigned tot = 0, matched = 0, pending = 0, unloc = 0;
    unsigned long long bytes = 0, mbytes = 0;
    for (size_t i = 0; i < n; i++) {
        Row *r = &rows[i];
        int j;
        for (j = 0; j < nm; j++) if (!strcmp(mods[j].name, r->module)) break;
        if (j == nm) { strncpy(mods[nm].name, r->module, 63); nm++; }
        Mod *m = &mods[j];
        m->fn++; tot++; m->bytes += r->size; bytes += r->size;
        if (!strcmp(r->status, "MATCHED")) { m->matched++; matched++; m->mbytes += r->size; mbytes += r->size; }
        else if (!strcmp(r->status, "MATCH-PENDING")) { m->pending++; pending++; }
        else { m->unloc++; unloc++; }
        int nr = 0;
        for (int k = 0; k < 6; k++) {
            char pat[8];
            const char *p = r->rules;
            snprintf(pat, sizeof pat, "%s", rc[k].rule);
            size_t L = strlen(pat);
            while ((p = strstr(p, pat)) != NULL) {
                if ((p == r->rules || p[-1] == ',') && (p[L] == 0 || p[L] == ',')) { rc[k].n++; nr++; break; }
                p += L;
            }
        }
        if (nr == 1)
            for (int k = 0; k < 6; k++) {
                const char *p = r->rules; size_t L = strlen(rc[k].rule);
                if (!strncmp(p, rc[k].rule, L) && p[L] == 0) rc[k].only++;
            }
    }

    FILE *o = fopen(argv[2], "wb");
    if (!o) { perror(argv[2]); return 1; }
    fprintf(o, "# MATCH-PENDING functions\n\n");
    fprintf(o, "Every function in `build/units.json` compiles to the game's bytes. A function counts as **matched under the "
               "rules** only when it also passes every [match] rule (`AGENTS.md`, \"The two laws\"); the others are "
               "listed here as `MATCH-PENDING`, with the rules they fail. Their source is kept: it is the best-known state, "
               "and it still matches byte for byte. `UNLOCATED` functions are compiler-generated (adjustor thunks, deleting "
               "destructors) and have no source lines to check.\n\n");
    fprintf(o, "Generated by `f3ledger` from the rule checker `f3rules` (branch `campaign-tools`)%s%s%s. Do not edit by "
               "hand; regenerate it.\n\n", argc > 3 ? " at commit `" : "", argc > 3 ? argv[3] : "", argc > 3 ? "`" : "");
    fprintf(o, "| measure | functions | bytes |\n|---|---:|---:|\n");
    fprintf(o, "| bytes matched | %u | %llu |\n", tot, bytes);
    fprintf(o, "| **matched under the rules** | **%u** | **%llu** |\n", matched, mbytes);
    fprintf(o, "| MATCH-PENDING | %u | |\n| UNLOCATED | %u | |\n\n", pending, unloc);
    fprintf(o, "| rule | what it requires | functions failing it | failing only it |\n|---|---|---:|---:|\n");
    static const char *what[] = {
        "each type defined once, in a shared header", "each global declared once, in a header",
        "typed members, no fixed-offset casts", "real vtables", "no fake code", "no assembly bodies"};
    for (int k = 0; k < 6; k++) fprintf(o, "| %s | %s | %u | %u |\n", rc[k].rule, what[k], rc[k].n, rc[k].only);
    fprintf(o, "\n## By module\n\n| module | functions | matched under the rules | MATCH-PENDING | UNLOCATED |\n"
               "|---|---:|---:|---:|---:|\n");
    for (int j = 0; j < nm; j++)
        fprintf(o, "| `%s` | %u | %u | %u | %u |\n", mods[j].name, mods[j].fn, mods[j].matched, mods[j].pending,
                mods[j].unloc);
    fprintf(o, "\n## By file\n");
    const char *cur = "";
    char und[2048];
    for (size_t i = 0; i < n; i++) {
        Row *r = &rows[i];
        if (!strcmp(r->status, "MATCHED")) continue;
        if (strcmp(cur, r->file)) {
            cur = r->file;
            fprintf(o, "\n### `%s`\n\n| address | function | rules |\n|---|---|---|\n", cur);
        }
        const char *name = r->symbol;
        if (r->symbol[0] == '?' && UnDecorateSymbolName(r->symbol, und, sizeof und, UNDNAME_NAME_ONLY)) name = und;
        /* The name goes in a code span (double backticks when it contains one); only '|' needs escaping there. */
        char esc[2048];
        size_t e = 0;
        for (const char *p = name; *p && e < sizeof esc - 3; p++) {
            if (*p == '|') esc[e++] = '\\';
            esc[e++] = *p;
        }
        esc[e] = 0;
        const char *tick = strchr(esc, '`') ? "`` " : "`";
        const char *tock = strchr(esc, '`') ? " ``" : "`";
        fprintf(o, "| 0x%08x | %s%s%s | %s |\n", r->addr, tick, esc, tock,
                !strcmp(r->status, "UNLOCATED") ? "UNLOCATED" : r->rules);
    }
    fclose(o);
    printf("f3ledger: %u functions, %u matched under the rules, %u MATCH-PENDING, %u UNLOCATED\n", tot, matched, pending,
           unloc);
    return 0;
}

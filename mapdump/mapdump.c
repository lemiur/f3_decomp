/* mapdump.c - parse an MSVC linker .map into UTF-8 TSV.
 *
 * usage: mapdump <file.map> <outdir> [image.exe]
 *
 * Writes publics.tsv (Publics by Value + Static symbols), sections.tsv (the section contribution
 * table at the top of the map) and image.txt (map header, plus the PE header of the image if given).
 */
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <dbghelp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peinfo.h"

static FILE *open_out(const char *dir, const char *name, const char *header)
{
    char path[MAX_PATH];
    FILE *f;
    _snprintf(path, sizeof path, "%s\\%s", dir, name);
    f = fopen(path, "wb");
    if (!f) { fprintf(stderr, "cannot write %s\n", path); exit(1); }
    setvbuf(f, NULL, _IOFBF, 1 << 20);
    fputs(header, f);
    fputc('\n', f);
    return f;
}

static void clean(char *s)
{
    for (; *s; s++) if (*s == '\t' || *s == '\r' || *s == '\n') *s = ' ';
}

/* Split a line into whitespace-separated tokens, in place. Returns count. */
static int tokenize(char *line, char **tok, int max)
{
    int n = 0;
    char *p = line;
    while (*p && n < max) {
        while (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n') p++;
        if (!*p) break;
        tok[n++] = p;
        while (*p && *p != ' ' && *p != '\t' && *p != '\r' && *p != '\n') p++;
        if (*p) *p++ = 0;
    }
    return n;
}

static int is_addr(const char *t, unsigned *sec, unsigned *off)
{
    char c;
    return sscanf(t, "%x:%x%c", sec, off, &c) == 2 && strlen(t) == 13 && t[4] == ':';
}

int main(int argc, char **argv)
{
    FILE *in, *fp, *fs, *fi;
    static char line[16384], raw[16384], und[8192];
    char *tok[16];
    enum { HEAD, SECTIONS, PUBLICS, STATICS, OTHER } state = HEAD;
    unsigned long long base = 0;
    unsigned ts = 0;
    char module[256] = "", entry[64] = "";
    size_t npub = 0, nstat = 0, nsec = 0, nfunc = 0;
    char path[MAX_PATH];

    if (argc < 3) { fprintf(stderr, "usage: mapdump <file.map> <outdir> [image.exe]\n"); return 2; }
    in = fopen(argv[1], "rb");
    if (!in) { fprintf(stderr, "cannot open %s\n", argv[1]); return 1; }
    CreateDirectoryA(argv[2], NULL);
    fp = open_out(argv[2], "publics.tsv", "rva\tva\tdecorated\tundecorated\tlib\tobject\tis_function\tis_inline\tis_static\tsection\toffset");
    fs = open_out(argv[2], "sections.tsv", "section\toffset\tlength\tname\tclass");

    while (fgets(line, sizeof line, in)) {
        int n;
        unsigned sec, off;
        strcpy(raw, line);
        n = tokenize(line, tok, 16);
        if (state == HEAD && n == 1 && !module[0]) { strncpy(module, tok[0], sizeof module - 1); continue; }
        if (n >= 3 && strcmp(tok[0], "Timestamp") == 0) { sscanf(tok[2], "%x", &ts); continue; }
        if (n >= 5 && strcmp(tok[0], "Preferred") == 0) { sscanf(tok[4], "%llx", &base); continue; }
        if (n >= 4 && strcmp(tok[0], "Start") == 0 && strcmp(tok[1], "Length") == 0) { state = SECTIONS; continue; }
        if (n >= 4 && strcmp(tok[0], "Address") == 0 && strcmp(tok[1], "Publics") == 0) { state = PUBLICS; continue; }
        if (n >= 4 && strcmp(tok[0], "entry") == 0 && strcmp(tok[1], "point") == 0) { strncpy(entry, tok[3], sizeof entry - 1); state = OTHER; continue; }
        if (n == 2 && strcmp(tok[0], "Static") == 0 && strcmp(tok[1], "symbols") == 0) { state = STATICS; continue; }
        if (n >= 1 && (strcmp(tok[0], "Exports") == 0 || strcmp(tok[0], "FIXUPS:") == 0)) { state = OTHER; continue; }
        if (n == 0) continue;

        if (state == SECTIONS && n >= 3 && is_addr(tok[0], &sec, &off)) {
            unsigned long long len = strtoull(tok[1], NULL, 16);
            clean(tok[2]);
            fprintf(fs, "%u\t0x%X\t0x%llX\t%s\t%s\n", sec, off, len, tok[2], n >= 4 ? tok[3] : "");
            nsec++;
        } else if ((state == PUBLICS || state == STATICS) && n >= 3 && is_addr(tok[0], &sec, &off)) {
            /* addr name va [f] [i] lib:object */
            const char *name = tok[1], *libobj = tok[n - 1];
            unsigned long long va = strtoull(tok[2], NULL, 16);
            int isf = 0, isi = 0, k;
            char lib[512] = "", obj[512] = "", rvas[24] = "";
            const char *colon;
            for (k = 3; k < n - 1; k++) {
                if (strcmp(tok[k], "f") == 0) isf = 1;
                else if (strcmp(tok[k], "i") == 0) isi = 1;
            }
            if (n == 3) libobj = "";
            colon = strrchr(libobj, ':');
            if (colon && libobj[0] != '<') {
                size_t ll = (size_t)(colon - libobj);
                if (ll >= sizeof lib) ll = sizeof lib - 1;
                memcpy(lib, libobj, ll); lib[ll] = 0;
                strncpy(obj, colon + 1, sizeof obj - 1);
            } else strncpy(obj, libobj, sizeof obj - 1);
            und[0] = 0;
            if (name[0] == '?') {
                if (!UnDecorateSymbolName(name, und, sizeof und, UNDNAME_COMPLETE)) und[0] = 0;
            }
            if (!und[0]) strncpy(und, name, sizeof und - 1);
            clean(und);
            if (sec != 0 && va >= base) sprintf(rvas, "0x%llX", va - base);
            fprintf(fp, "%s\t0x%llX\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%u\t0x%X\n", rvas, va, name, und, lib, obj, isf, isi,
                    state == STATICS, sec, off);
            if (state == PUBLICS) npub++; else nstat++;
            nfunc += isf;
        }
    }
    fclose(in);
    fclose(fp);
    fclose(fs);

    _snprintf(path, sizeof path, "%s\\image.txt", argv[2]);
    fi = fopen(path, "wb");
    fprintf(fi, "map: %s\nmap_module: %s\nmap_timestamp: 0x%08X\nmap_preferred_base: 0x%llX\nmap_entry_point: %s\n",
            argv[1], module, ts, base, entry);
    if (argc > 3) pe_write_info(fi, argv[3]);
    fclose(fi);

    printf("sections.tsv  %zu\npublics.tsv   %zu (%zu publics, %zu statics, %zu functions)\n", nsec, npub + nstat, npub,
           nstat, nfunc);
    return 0;
}

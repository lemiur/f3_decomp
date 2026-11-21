/* peinfo.h - print a PE image's header facts (machine, base, timestamp, sections, CodeView id).
   Plain C, header-only; shared by pdbdump and mapdump. Reads only the headers, never code bytes. */
#ifndef PEINFO_H
#define PEINFO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static unsigned pe_u16(const unsigned char *p) { return p[0] | (p[1] << 8); }
static unsigned pe_u32(const unsigned char *p) { return p[0] | (p[1] << 8) | (p[2] << 16) | ((unsigned)p[3] << 24); }
static unsigned long long pe_u64(const unsigned char *p) { return pe_u32(p) | ((unsigned long long)pe_u32(p + 4) << 32); }

static const char *pe_machine_name(unsigned m)
{
    switch (m) {
    case 0x014c: return "I386";
    case 0x8664: return "AMD64";
    case 0x01f2: return "POWERPCBE (Xbox 360)";
    case 0x01f0: return "POWERPC";
    case 0x01c0: return "ARM";
    case 0xaa64: return "ARM64";
    default: return "unknown";
    }
}

/* Writes "key: value" lines to f. Returns 0 on success. */
static int pe_write_info(FILE *f, const char *path)
{
    FILE *in = fopen(path, "rb");
    unsigned char *buf;
    size_t n, cap = 1 << 20;
    unsigned peoff, machine, nsec, optsz, magic, i, ts, ddoff, dbg_rva = 0, dbg_size = 0, nrva;
    unsigned long long base;
    const unsigned char *fh, *oh, *sh;
    time_t tt;
    char tbuf[64];

    if (!in) { fprintf(f, "exe: %s (cannot open)\n", path); return 1; }
    buf = (unsigned char *)malloc(cap);
    n = fread(buf, 1, cap, in);
    if (n < 0x40 || buf[0] != 'M' || buf[1] != 'Z') { fprintf(f, "exe: %s (not MZ)\n", path); fclose(in); free(buf); return 1; }
    peoff = pe_u32(buf + 0x3c);
    if (peoff + 0x200 > n || memcmp(buf + peoff, "PE\0\0", 4) != 0) { fprintf(f, "exe: %s (no PE header)\n", path); fclose(in); free(buf); return 1; }
    fh = buf + peoff + 4;
    machine = pe_u16(fh); nsec = pe_u16(fh + 2); ts = pe_u32(fh + 4); optsz = pe_u16(fh + 16);
    oh = fh + 20;
    magic = pe_u16(oh);
    if (magic == 0x20b) { base = pe_u64(oh + 24); ddoff = 112; nrva = pe_u32(oh + 108); }
    else { base = pe_u32(oh + 28); ddoff = 96; nrva = pe_u32(oh + 92); }
    if (nrva > 6) { dbg_rva = pe_u32(oh + ddoff + 6 * 8); dbg_size = pe_u32(oh + ddoff + 6 * 8 + 4); }
    tt = (time_t)ts;
    strftime(tbuf, sizeof tbuf, "%Y-%m-%d %H:%M:%S UTC", gmtime(&tt));

    fprintf(f, "exe: %s\n", path);
    fprintf(f, "machine: 0x%04X %s\n", machine, pe_machine_name(machine));
    fprintf(f, "optional_header: %s\n", magic == 0x20b ? "PE32+" : "PE32");
    fprintf(f, "image_base: 0x%llX\n", base);
    fprintf(f, "timestamp: 0x%08X (%s)\n", ts, tbuf);
    fprintf(f, "entry_point_rva: 0x%X\n", pe_u32(oh + 16));
    fprintf(f, "size_of_image: 0x%X\n", pe_u32(oh + 56));
    fprintf(f, "sections: %u\n", nsec);
    fprintf(f, "  %-8s %-10s %-10s %-10s %-10s %s\n", "name", "rva", "vsize", "rawptr", "rawsize", "flags");
    sh = oh + optsz;
    for (i = 0; i < nsec && (size_t)(sh + 40 - buf) <= n; i++, sh += 40) {
        char nm[9]; memcpy(nm, sh, 8); nm[8] = 0;
        fprintf(f, "  %-8s 0x%08X 0x%08X 0x%08X 0x%08X 0x%08X\n", nm, pe_u32(sh + 12), pe_u32(sh + 8),
                pe_u32(sh + 20), pe_u32(sh + 16), pe_u32(sh + 36));
    }
    /* CodeView record (RSDS / NB10) via the debug directory */
    if (dbg_rva && dbg_size) {
        unsigned dfo = 0, k;
        sh = oh + optsz;
        for (i = 0; i < nsec; i++, sh += 40) {
            unsigned va = pe_u32(sh + 12), vs = pe_u32(sh + 8), raw = pe_u32(sh + 20), rs = pe_u32(sh + 16);
            if (vs < rs) vs = rs;
            if (dbg_rva >= va && dbg_rva < va + vs) { dfo = dbg_rva - va + raw; break; }
        }
        for (k = 0; dfo && k < dbg_size / 28; k++) {
            unsigned char ent[28], cv[600];
            unsigned type, sz, ptr;
            fseek(in, dfo + k * 28, SEEK_SET);
            if (fread(ent, 1, 28, in) != 28) break;
            type = pe_u32(ent + 12); sz = pe_u32(ent + 16); ptr = pe_u32(ent + 24);
            if (type != 2) continue;
            if (sz > sizeof cv - 1) sz = sizeof cv - 1;
            fseek(in, ptr, SEEK_SET);
            if (fread(cv, 1, sz, in) != sz) break;
            cv[sz] = 0;
            if (memcmp(cv, "RSDS", 4) == 0) {
                const unsigned char *g = cv + 4;
                fprintf(f, "codeview: RSDS guid={%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X} age=%u pdb=%s\n",
                        pe_u32(g), pe_u16(g + 4), pe_u16(g + 6), g[8], g[9], g[10], g[11], g[12], g[13], g[14], g[15],
                        pe_u32(cv + 20), (const char *)cv + 24);
            } else if (memcmp(cv, "NB10", 4) == 0) {
                fprintf(f, "codeview: NB10 signature=0x%08X age=%u pdb=%s\n", pe_u32(cv + 8), pe_u32(cv + 12), (const char *)cv + 16);
            }
        }
    }
    fclose(in);
    free(buf);
    return 0;
}

#endif

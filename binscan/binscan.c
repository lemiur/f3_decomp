/*
 * binscan - per-function, architecture-independent link features from PE images
 *           (x86 PC builds and big-endian PowerPC Xbox 360 PE basefiles).
 *
 * usage: binscan --image <exe> --arch x86|ppc [--functions <json|tsv|map>] --out <dir>
 *                [--trace-insns <file>]   (debug: decoded x86 instruction starts, for
 *                                          comparison with a disassembler)
 *
 * Function lists:
 *   .json  [{"address": "0x..."}, ...]                extent = up to the next entry
 *   .map   MSVC linker map; "f" lines of "Publics by Value" and "Static symbols"
 *   .tsv   header row with columns rva (or va/address) and optionally size, name;
 *          values with 0x or hex letters are hex, otherwise decimal; rva < image base
 *          is relative to the base
 *   ppc    .pdata (begin + packed length) is always merged in, so a PDB list is
 *          completed by functions it lacks and vice versa
 *   none   x86: discovered from call targets and
 *          relocated code addresses
 *
 * Outputs in <dir> (all tab-separated, header row, addresses as 0x%08x):
 *   features.tsv  addr size nstr strings callees datarefs imports vrefs consts ninsn nbb
 *                 hash_norm coderefs name
 *       size: code bytes, without trailing int3/zero padding and without jump tables
 *       embedded after the code (x86: first in-function address operand past the
 *       current instruction; ppc: words carrying a HIGHLOW relocation are skipped).
 *       strings, imports, vrefs are \x1f-separated; callees, datarefs, consts, coderefs
 *       are comma-separated.  strings: unique literals in order of first reference
 *       (escaped: \\ \t \n \r \xHH).  callees: direct call targets in order, duplicates
 *       kept, plus tail jumps leaving the function; ppc register save/restore helpers
 *       are dropped.  imports: DLL!Name (or DLL!#ordinal), also via jmp/bctr thunks.
 *       vrefs: Class for a vtable at subobject offset 0, Class+0xNN otherwise, td:Class
 *       for a reference to a TypeDescriptor (dynamic_cast, typeid, EH).  consts: 0xNNNN
 *       immediates with |v| >= 0x10000 (x86 imm32, ppc lis+ori/addi outside the image),
 *       fXXXXXXXX / dXXXXXXXXXXXXXXXX float/double constants loaded from read-only data;
 *       capped at 16.  nbb: branches + 1.  hash_norm: FNV-1a 64 over the code bytes with
 *       relocated operands, rel32 call/jmp displacements (x86) or address immediates and
 *       external branch displacements (ppc) zeroed.  coderefs: addresses of code taken
 *       as values (function pointers) other than calls.
 *   strings.tsv   addr kind(a|w) text nfuncs funcs
 *   rtti.tsv      class mangled td_addr col_addr vtable_addr offset cd_offset nslots
 *   vtable.tsv    class vtable_addr offset slot func
 *   rtti_bases.tsv class index base num_contained mdisp pdisp vdisp attributes
 *
 * If the code sections have a flat byte histogram (encrypted, e.g. a DRM-wrapped .text)
 * only the RTTI tables are written.  Reads the image only; writes nothing but the tables above.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>
#include <ctype.h>
#include <time.h>
#ifdef _WIN32
#include <direct.h>
#endif

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;

static void die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "binscan: ");
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);
    exit(1);
}

static void *xmalloc(size_t n)
{
    void *p = malloc(n ? n : 1);
    if (!p) die("out of memory");
    return p;
}
static void *xcalloc(size_t n, size_t s)
{
    void *p = calloc(n ? n : 1, s ? s : 1);
    if (!p) die("out of memory");
    return p;
}
static void *xrealloc(void *p, size_t n)
{
    p = realloc(p, n ? n : 1);
    if (!p) die("out of memory");
    return p;
}
static char *xstrdup(const char *s)
{
    size_t n = strlen(s) + 1;
    char *p = xmalloc(n);
    memcpy(p, s, n);
    return p;
}

/* ------------------------------------------------------------------ buffers */

typedef struct {
    char *p;
    size_t n, cap;
} Buf;

static void bput(Buf *b, const char *s, size_t n)
{
    if (b->n + n + 1 > b->cap) {
        b->cap = (b->n + n + 1) * 2 + 64;
        b->p = xrealloc(b->p, b->cap);
    }
    memcpy(b->p + b->n, s, n);
    b->n += n;
    b->p[b->n] = 0;
}
static void bputs(Buf *b, const char *s) { bput(b, s, strlen(s)); }
static void bputc(Buf *b, char c) { bput(b, &c, 1); }
static void bprintf(Buf *b, const char *fmt, ...)
{
    char tmp[512];
    va_list ap;
    int n;
    va_start(ap, fmt);
    n = vsnprintf(tmp, sizeof tmp, fmt, ap);
    va_end(ap);
    if (n < 0) return;
    if (n >= (int)sizeof tmp) n = sizeof tmp - 1;
    bput(b, tmp, (size_t)n);
}
static void bclear(Buf *b)
{
    b->n = 0;
    if (b->p) b->p[0] = 0;
}
static const char *bstr(Buf *b) { return b->p ? b->p : ""; }

/* ------------------------------------------------------- u32 -> u32 hashmap */

typedef struct {
    u32 *k, *v;
    u32 cap, n;
} Map; /* key 0 is never stored */

static u32 hmix(u32 x)
{
    x ^= x >> 16;
    x *= 0x7feb352dU;
    x ^= x >> 15;
    x *= 0x846ca68bU;
    x ^= x >> 16;
    return x;
}
static void map_put(Map *m, u32 key, u32 val);
static void map_grow(Map *m)
{
    Map o = *m;
    u32 i;
    m->cap = o.cap ? o.cap * 2 : 1024;
    m->k = xcalloc(m->cap, sizeof(u32));
    m->v = xcalloc(m->cap, sizeof(u32));
    m->n = 0;
    for (i = 0; i < o.cap; i++)
        if (o.k[i]) map_put(m, o.k[i], o.v[i]);
    free(o.k);
    free(o.v);
}
static void map_put(Map *m, u32 key, u32 val)
{
    u32 i;
    if (!key) return;
    if ((m->n + 1) * 2 > m->cap) map_grow(m);
    i = hmix(key) & (m->cap - 1);
    while (m->k[i] && m->k[i] != key) i = (i + 1) & (m->cap - 1);
    if (!m->k[i]) m->n++;
    m->k[i] = key;
    m->v[i] = val;
}
static int map_get(const Map *m, u32 key, u32 *val)
{
    u32 i;
    if (!m->cap || !key) return 0;
    i = hmix(key) & (m->cap - 1);
    while (m->k[i]) {
        if (m->k[i] == key) {
            if (val) *val = m->v[i];
            return 1;
        }
        i = (i + 1) & (m->cap - 1);
    }
    return 0;
}

/* ----------------------------------------------------------------- image */

typedef struct {
    char name[9];
    u32 va, vsize, flags;
    int exec; /* code section we scan */
    int data; /* non-code section scanned for RTTI / strings */
} Sec;

static u8 *img;
static u32 base, imgsize, entry_va;
static Sec secs[96];
static int nsec;
static int be;      /* content is big-endian (ppc) */
static int is_ppc;
static u8 *relbits; /* HIGHLOW relocation at byte */
static u8 *relother; /* other relocation types (ppc HIGHADJ/LOW etc) */
static u32 nrel_hl, nrel_other;
static Map iat; /* IAT slot va -> import name index */
static char **impnames;
static u32 nimp;

static int inimg(u32 va) { return va >= base && va - base < imgsize; }
static int inimg4(u32 va) { return va >= base && va - base + 4 <= imgsize; }
static u32 rd32(u32 va)
{
    const u8 *p;
    if (!inimg4(va)) return 0;
    p = img + (va - base);
    return be ? ((u32)p[0] << 24 | (u32)p[1] << 16 | (u32)p[2] << 8 | p[3])
              : ((u32)p[3] << 24 | (u32)p[2] << 16 | (u32)p[1] << 8 | p[0]);
}
static u32 rd32le(u32 va)
{
    const u8 *p;
    if (!inimg4(va)) return 0;
    p = img + (va - base);
    return (u32)p[3] << 24 | (u32)p[2] << 16 | (u32)p[1] << 8 | p[0];
}
static u32 rd32x(u32 va, int bigend)
{
    const u8 *p;
    if (!inimg4(va)) return 0;
    p = img + (va - base);
    return bigend ? ((u32)p[0] << 24 | (u32)p[1] << 16 | (u32)p[2] << 8 | p[3])
                  : ((u32)p[3] << 24 | (u32)p[2] << 16 | (u32)p[1] << 8 | p[0]);
}
static u64 rd64(u32 va)
{
    u64 a = rd32(va), b = rd32(va + 4);
    return be ? (a << 32 | b) : (b << 32 | a);
}
static int isrel(u32 va)
{
    u32 r;
    if (!inimg(va)) return 0;
    r = va - base;
    return (relbits[r >> 3] >> (r & 7)) & 1;
}
static int isrelother(u32 va)
{
    u32 r;
    if (!inimg(va)) return 0;
    r = va - base;
    return (relother[r >> 3] >> (r & 7)) & 1;
}
static int secof(u32 va)
{
    int i;
    for (i = 0; i < nsec; i++)
        if (va >= secs[i].va && va - secs[i].va < secs[i].vsize) return i;
    return -1;
}
static int is_code(u32 va)
{
    int s = secof(va);
    return s >= 0 && secs[s].exec;
}
static int is_data(u32 va)
{
    int s = secof(va);
    return s >= 0 && secs[s].data;
}
static int is_rodata(u32 va)
{
    int s = secof(va);
    return s >= 0 && secs[s].data && !(secs[s].flags & 0x80000000u);
}

static u8 *read_file(const char *path, size_t *len)
{
    FILE *f = fopen(path, "rb");
    u8 *p;
    long n;
    if (!f) die("cannot open %s", path);
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    p = xmalloc((size_t)n + 1);
    if (fread(p, 1, (size_t)n, f) != (size_t)n) die("read error %s", path);
    p[n] = 0;
    fclose(f);
    *len = (size_t)n;
    return p;
}

static u32 le32(const u8 *p) { return (u32)p[3] << 24 | (u32)p[2] << 16 | (u32)p[1] << 8 | p[0]; }
static u16 le16(const u8 *p) { return (u16)(p[1] << 8 | p[0]); }

static u32 dir_rva[16], dir_size[16];

static void load_pe(const char *path, int want_ppc)
{
    size_t flen;
    u8 *f = read_file(path, &flen);
    u32 pe, opt, sh, i, nsh, machine, optsz, hdrsz;
    if (flen < 0x40 || f[0] != 'M' || f[1] != 'Z') die("%s: not an MZ image", path);
    pe = le32(f + 0x3c);
    if (pe + 24 > flen || memcmp(f + pe, "PE\0\0", 4)) die("%s: no PE header", path);
    machine = le16(f + pe + 4);
    nsh = le16(f + pe + 6);
    optsz = le16(f + pe + 20);
    opt = pe + 24;
    if (le16(f + opt) != 0x10b) die("%s: not PE32", path);
    is_ppc = (machine == 0x1F2 || machine == 0x1F0 || machine == 0x1F1);
    if (want_ppc != is_ppc) die("%s: --arch does not match machine 0x%x", path, machine);
    be = (machine == 0x1F2);
    entry_va = le32(f + opt + 16);
    base = le32(f + opt + 28);
    entry_va += base;
    imgsize = le32(f + opt + 56);
    hdrsz = le32(f + opt + 60);
    {
        u32 nd = le32(f + opt + 92);
        for (i = 0; i < nd && i < 16; i++) {
            dir_rva[i] = le32(f + opt + 96 + i * 8);
            dir_size[i] = le32(f + opt + 100 + i * 8);
        }
    }
    img = xcalloc(imgsize + 16, 1);
    memcpy(img, f, hdrsz < flen && hdrsz < imgsize ? hdrsz : 0x400);
    sh = opt + optsz;
    if (nsh > 96) die("too many sections");
    for (i = 0; i < nsh; i++) {
        const u8 *s = f + sh + i * 40;
        Sec *x = &secs[nsec++];
        u32 vs = le32(s + 8), va = le32(s + 12), rs = le32(s + 16), rp = le32(s + 20);
        memcpy(x->name, s, 8);
        x->name[8] = 0;
        x->va = base + va;
        x->vsize = vs ? vs : rs;
        x->flags = le32(s + 36);
        if (va < imgsize) {
            u32 n = rs < x->vsize ? rs : x->vsize;
            if (va + n > imgsize) n = imgsize - va;
            if (rp + n > flen) n = rp < flen ? (u32)(flen - rp) : 0;
            memcpy(img + va, f + rp, n);
        }
        x->exec = (x->flags & 0x20000020u) != 0;
    }
    /* F3 PC has a ".code" stub section next to .text: skip it */
    for (i = 0; i < (u32)nsec; i++)
        if (!strcmp(secs[i].name, ".code"))
            for (nsh = 0; nsh < (u32)nsec; nsh++)
                if (!strcmp(secs[nsh].name, ".text")) secs[i].exec = 0;
    for (i = 0; i < (u32)nsec; i++) {
        Sec *x = &secs[i];
        x->data = !x->exec && !(x->flags & 0x20000020u) && strcmp(x->name, ".reloc") &&
                  strcmp(x->name, ".rsrc") && strcmp(x->name, ".pdata") && strcmp(x->name, ".code") &&
                  strcmp(x->name, ".bind");
    }
    free(f);
}

static void load_relocs(void)
{
    u32 r = dir_rva[5], end = dir_rva[5] + dir_size[5];
    int bigend = -1;
    relbits = xcalloc(imgsize / 8 + 2, 1);
    relother = xcalloc(imgsize / 8 + 2, 1);
    if (!r) return;
    /* detect block header endianness on the first block */
    {
        u32 pl = rd32x(base + r, 0), sl = rd32x(base + r + 4, 0);
        u32 pb = rd32x(base + r, 1), sb = rd32x(base + r + 4, 1);
        int okl = pl < imgsize && sl >= 8 && sl < 0x10000 && !(sl & 1);
        int okb = pb < imgsize && sb >= 8 && sb < 0x10000 && !(sb & 1);
        bigend = (okb && (!okl || be)) ? 1 : 0;
    }
    while (r + 8 <= end) {
        u32 page = rd32x(base + r, bigend), sz = rd32x(base + r + 4, bigend), k;
        if (sz < 8 || r + sz > end) break;
        for (k = 8; k + 2 <= sz; k += 2) {
            const u8 *p = img + r + k;
            u16 e = bigend ? (u16)(p[0] << 8 | p[1]) : (u16)(p[1] << 8 | p[0]);
            u32 t = e >> 12, off = page + (e & 0xfff);
            if (off >= imgsize) continue;
            if (t == 3) {
                relbits[off >> 3] |= (u8)(1 << (off & 7));
                nrel_hl++;
            } else if (t != 0) {
                relother[off >> 3] |= (u8)(1 << (off & 7));
                nrel_other++;
                if (t == 4) k += 2; /* HIGHADJ carries its low half */
            }
        }
        r += sz;
    }
}

static void load_imports(void)
{
    u32 d = dir_rva[1];
    int bigend, pass;
    if (!d) return;
    /* descriptor contents may be big-endian on ppc */
    for (pass = 0; pass < 2; pass++) {
        bigend = pass == 0 ? be : !be;
        if (inimg(base + rd32x(base + d + 12, bigend)) && rd32x(base + d + 12, bigend)) break;
    }
    if (pass == 2) return;
    for (;; d += 20) {
        u32 oft = rd32x(base + d, bigend), nm = rd32x(base + d + 12, bigend), ft = rd32x(base + d + 16, bigend);
        char dll[128];
        u32 j, th;
        if (!nm || !ft || !inimg(base + nm)) break;
        snprintf(dll, sizeof dll, "%s", (const char *)img + nm);
        {
            char *dot = strchr(dll, '.');
            if (dot) *dot = 0;
        }
        th = oft ? oft : ft;
        for (j = 0; j < 100000; j++) {
            u32 t = rd32x(base + th + j * 4, bigend);
            char name[512];
            if (!t) break;
            if (t & 0x80000000u)
                snprintf(name, sizeof name, "%s!#%u", dll, t & 0xffff);
            else if (inimg(base + t + 2))
                snprintf(name, sizeof name, "%s!%.400s", dll, (const char *)img + t + 2);
            else
                snprintf(name, sizeof name, "%s!?%x", dll, t);
            impnames = xrealloc(impnames, (nimp + 1) * sizeof(char *));
            impnames[nimp] = xstrdup(name);
            map_put(&iat, base + ft + j * 4, nimp + 1);
            nimp++;
        }
    }
}

static const char *iat_name(u32 va)
{
    u32 i;
    if (map_get(&iat, va, &i)) return impnames[i - 1];
    return NULL;
}

/* ----------------------------------------------------------- function list */

typedef struct {
    u32 va, size;
    char *name;
    u32 ord; /* input order: stable tie-break */
} Func;
static Func *funcs;
static u32 nfuncs, capfuncs;

static void addfunc(u32 va, u32 size, const char *name)
{
    if (nfuncs == capfuncs) {
        capfuncs = capfuncs ? capfuncs * 2 : 65536;
        funcs = xrealloc(funcs, capfuncs * sizeof(Func));
    }
    funcs[nfuncs].va = va;
    funcs[nfuncs].size = size;
    funcs[nfuncs].name = name ? xstrdup(name) : NULL;
    funcs[nfuncs].ord = nfuncs;
    nfuncs++;
}

static int cmpfunc(const void *a, const void *b)
{
    const Func *x = a, *y = b;
    if (x->va != y->va) return x->va < y->va ? -1 : 1;
    if (x->size != y->size) return x->size > y->size ? -1 : 1; /* keep the sized entry */
    if (x->ord != y->ord) return x->ord < y->ord ? -1 : 1;
    return 0;
}

static u32 parse_num(const char *s)
{
    const char *t;
    while (*s == ' ' || *s == '"') s++;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) return (u32)strtoul(s + 2, NULL, 16);
    for (t = s; isxdigit((unsigned char)*t); t++)
        if (isalpha((unsigned char)*t)) return (u32)strtoul(s, NULL, 16);
    return (u32)strtoul(s, NULL, 10);
}

static void load_json(const char *path)
{
    size_t n;
    char *t = (char *)read_file(path, &n), *p = t;
    while ((p = strstr(p, "\"address\"")) != NULL) {
        p += 9;
        while (*p && *p != ':') p++;
        if (!*p) break;
        p++;
        while (*p == ' ' || *p == '"') p++;
        addfunc((u32)strtoul(p, NULL, 16), 0, NULL);
    }
    free(t);
}

static void load_map(const char *path)
{
    size_t n;
    char *t = (char *)read_file(path, &n), *line = t, *nl;
    int on = 0;
    while (line && *line) {
        char seg[64], name[4096], va[64], fl[16];
        nl = strchr(line, '\n');
        if (nl) *nl = 0;
        if (strstr(line, "Publics by Value") || strstr(line, "Static symbols")) on = 1;
        else if (on && sscanf(line, " %63s %4095s %63s %15s", seg, name, va, fl) == 4 && strchr(seg, ':') &&
                 !strcmp(fl, "f") && strlen(va) == 8)
            addfunc((u32)strtoul(va, NULL, 16), 0, name);
        line = nl ? nl + 1 : NULL;
    }
    free(t);
}

static void load_tsv(const char *path)
{
    size_t n;
    char *t = (char *)read_file(path, &n), *line = t, *nl;
    int col_rva = -1, col_va = -1, col_size = -1, col_name = -1, hdr = 1;
    while (line && *line) {
        char *f[64];
        int nf = 0, i;
        char *p = line;
        nl = strchr(line, '\n');
        if (nl) *nl = 0;
        if (nl && nl > line && nl[-1] == '\r') nl[-1] = 0;
        f[nf++] = p;
        while ((p = strchr(p, '\t')) != NULL && nf < 64) {
            *p++ = 0;
            f[nf++] = p;
        }
        if (hdr) {
            for (i = 0; i < nf; i++) {
                if (!_stricmp(f[i], "rva")) col_rva = i;
                else if (!_stricmp(f[i], "va") || !_stricmp(f[i], "address") || !_stricmp(f[i], "addr")) col_va = i;
                else if (!_stricmp(f[i], "size") || !_stricmp(f[i], "length")) col_size = i;
                else if (!_stricmp(f[i], "name")) col_name = i;
            }
            if (col_rva < 0 && col_va < 0) die("%s: no rva/va column", path);
            hdr = 0;
        } else if (f[0][0] && f[0][0] != '#') {
            int c = col_rva >= 0 ? col_rva : col_va;
            if (c < nf) {
                u32 a = parse_num(f[c]);
                u32 sz = col_size >= 0 && col_size < nf ? parse_num(f[col_size]) : 0;
                if (a < base) a += base;
                addfunc(a, sz, col_name >= 0 && col_name < nf ? f[col_name] : NULL);
            }
        }
        line = nl ? nl + 1 : NULL;
    }
    free(t);
}

static void load_pdata(void)
{
    u32 r = dir_rva[3], sz = dir_size[3], i;
    if (!r) {
        for (i = 0; i < (u32)nsec; i++)
            if (!strcmp(secs[i].name, ".pdata")) {
                r = secs[i].va - base;
                sz = secs[i].vsize;
            }
    }
    for (i = 0; i + 8 <= sz; i += 8) {
        u32 b = rd32(base + r + i), w = rd32(base + r + i + 4);
        u32 len = ((w >> 8) & 0x3fffff) * 4;
        if (!b) continue;
        addfunc(b, len, NULL);
    }
}

/* x86 discovery: call targets + relocated code addresses (no function list) */
typedef struct {
    int len, opc, modrm, mod, reg, rm;
    int imm_off, imm_size, rel_off, rel_size;
    int p66, pf2, pf3;
    int fp_size;
} X86I;
static int x86_decode(const u8 *p, int max, X86I *d);

static void discover_x86(void)
{
    int s;
    u8 *mark = xcalloc(imgsize / 8 + 2, 1);
#define MARK(v) (mark[((v) - base) >> 3] |= (u8)(1 << (((v) - base) & 7)))
    MARK(entry_va);
    for (s = 0; s < nsec; s++) {
        Sec *x = &secs[s];
        u32 pc, e = x->va + x->vsize;
        if (x->data) {
            for (pc = x->va; pc + 4 <= e; pc += 4)
                if (isrel(pc)) {
                    u32 v = rd32(pc);
                    if (is_code(v)) MARK(v);
                }
        }
        if (!x->exec) continue;
        for (pc = x->va; pc < e;) {
            X86I d;
            int len = x86_decode(img + (pc - base), (int)(e - pc), &d);
            if (len <= 0) len = 1;
            if (d.opc == 0xE8 && d.rel_size == 4) {
                u32 t = pc + len + rd32le(pc + d.rel_off);
                if (is_code(t)) MARK(t);
            }
            if ((d.opc == 0x68 || d.opc == 0xC7 || (d.opc >= 0xB8 && d.opc <= 0xBF)) && d.imm_size == 4 &&
                isrel(pc + d.imm_off)) {
                u32 t = rd32le(pc + d.imm_off);
                if (is_code(t)) MARK(t);
            }
            pc += len;
        }
    }
    {
        u32 r;
        for (r = 0; r < imgsize; r++)
            if (mark[r >> 3] >> (r & 7) & 1) addfunc(base + r, 0, NULL);
    }
    free(mark);
#undef MARK
}

static void finish_funcs(void)
{
    u32 i, j = 0;
    qsort(funcs, nfuncs, sizeof(Func), cmpfunc);
    for (i = 0; i < nfuncs; i++) {
        if (!is_code(funcs[i].va)) continue;
        if (j && funcs[j - 1].va == funcs[i].va) {
            if (!funcs[j - 1].name) funcs[j - 1].name = funcs[i].name;
            continue;
        }
        funcs[j++] = funcs[i];
    }
    nfuncs = j;
    for (i = 0; i < nfuncs; i++) {
        int s = secof(funcs[i].va);
        u32 send = secs[s].va + secs[s].vsize;
        u32 next = i + 1 < nfuncs && funcs[i + 1].va < send ? funcs[i + 1].va : send;
        if (!funcs[i].size || funcs[i].va + funcs[i].size > next) funcs[i].size = next - funcs[i].va;
    }
}

/* ----------------------------------------------------------- x86 decoder */

enum { F_M = 1, F_I8 = 2, F_IZ = 4, F_I16 = 8, F_R8 = 16, F_RZ = 32, F_AM = 64, F_PTR = 128, F_GRP3 = 256, F_ENTER = 512 };
static u16 t1[256], t2[256];

static void x86_init(void)
{
    int i;
    for (i = 0; i < 0x40; i++) {
        int lo = i & 7;
        t1[i] = lo < 4 ? F_M : lo == 4 ? F_I8 : lo == 5 ? F_IZ : 0;
    }
    t1[0x62] = t1[0x63] = F_M;
    t1[0x68] = F_IZ;
    t1[0x69] = F_M | F_IZ;
    t1[0x6A] = F_I8;
    t1[0x6B] = F_M | F_I8;
    for (i = 0x70; i < 0x80; i++) t1[i] = F_R8;
    t1[0x80] = F_M | F_I8;
    t1[0x81] = F_M | F_IZ;
    t1[0x82] = F_M | F_I8;
    t1[0x83] = F_M | F_I8;
    for (i = 0x84; i < 0x90; i++) t1[i] = F_M;
    t1[0x9A] = F_PTR;
    for (i = 0xA0; i < 0xA4; i++) t1[i] = F_AM;
    t1[0xA8] = F_I8;
    t1[0xA9] = F_IZ;
    for (i = 0xB0; i < 0xB8; i++) t1[i] = F_I8;
    for (i = 0xB8; i < 0xC0; i++) t1[i] = F_IZ;
    t1[0xC0] = t1[0xC1] = F_M | F_I8;
    t1[0xC2] = F_I16;
    t1[0xC4] = t1[0xC5] = F_M;
    t1[0xC6] = F_M | F_I8;
    t1[0xC7] = F_M | F_IZ;
    t1[0xC8] = F_ENTER;
    t1[0xCA] = F_I16;
    t1[0xCD] = F_I8;
    for (i = 0xD0; i < 0xD4; i++) t1[i] = F_M;
    t1[0xD4] = t1[0xD5] = F_I8;
    for (i = 0xD8; i < 0xE0; i++) t1[i] = F_M;
    for (i = 0xE0; i < 0xE4; i++) t1[i] = F_R8;
    for (i = 0xE4; i < 0xE8; i++) t1[i] = F_I8;
    t1[0xE8] = t1[0xE9] = F_RZ;
    t1[0xEA] = F_PTR;
    t1[0xEB] = F_R8;
    t1[0xF6] = t1[0xF7] = F_M | F_GRP3;
    t1[0xFE] = t1[0xFF] = F_M;

    for (i = 0; i < 256; i++) t2[i] = F_M;
    t2[0x05] = t2[0x06] = t2[0x07] = t2[0x08] = t2[0x09] = t2[0x0B] = t2[0x0E] = 0;
    t2[0x0F] = F_M | F_I8;
    for (i = 0x30; i < 0x38; i++) t2[i] = 0;
    t2[0x70] = t2[0x71] = t2[0x72] = t2[0x73] = F_M | F_I8;
    t2[0x77] = 0;
    for (i = 0x80; i < 0x90; i++) t2[i] = F_RZ;
    t2[0xA0] = t2[0xA1] = t2[0xA2] = t2[0xA8] = t2[0xA9] = t2[0xAA] = 0;
    t2[0xA4] = t2[0xAC] = t2[0xBA] = t2[0xC2] = t2[0xC4] = t2[0xC5] = t2[0xC6] = F_M | F_I8;
    for (i = 0xC8; i < 0xD0; i++) t2[i] = 0;
}

static int x86_decode(const u8 *p, int max, X86I *d)
{
    int i = 0, a16 = 0;
    u16 f;
    int c;
    memset(d, 0, sizeof *d);
    d->modrm = d->imm_off = d->rel_off = -1;
    for (; i < max && i < 14; i++) {
        c = p[i];
        if (c == 0x66) d->p66 = 1;
        else if (c == 0x67) a16 = 1;
        else if (c == 0xF2) d->pf2 = 1;
        else if (c == 0xF3) d->pf3 = 1;
        else if (c == 0xF0 || c == 0x2E || c == 0x36 || c == 0x3E || c == 0x26 || c == 0x64 || c == 0x65) {
        } else break;
    }
    if (i + 1 > max) return -1;
    c = p[i++];
    if (c == 0x0F) {
        int c2;
        if (i >= max) return -1;
        c2 = p[i++];
        if (c2 == 0x38) {
            if (i >= max) return -1;
            d->opc = 0x200 | p[i++];
            f = F_M;
        } else if (c2 == 0x3A) {
            if (i >= max) return -1;
            d->opc = 0x300 | p[i++];
            f = F_M | F_I8;
        } else {
            d->opc = 0x100 | c2;
            f = t2[c2];
        }
    } else {
        d->opc = c;
        f = t1[c];
    }
    if (f & F_M) {
        int m;
        if (i >= max) return -1;
        d->modrm = i;
        m = p[i++];
        d->mod = m >> 6;
        d->reg = (m >> 3) & 7;
        d->rm = m & 7;
        if (d->mod != 3) {
            if (!a16) {
                if (d->rm == 4) {
                    if (i >= max) return -1;
                    if (d->mod == 0 && (p[i] & 7) == 5) i += 4;
                    i++;
                }
                if (d->mod == 0 && d->rm == 5) i += 4;
                else if (d->mod == 1) i += 1;
                else if (d->mod == 2) i += 4;
            } else {
                if (d->mod == 0 && d->rm == 6) i += 2;
                else if (d->mod == 1) i += 1;
                else if (d->mod == 2) i += 2;
            }
        }
        if (f & F_GRP3) {
            if (d->reg == 0 || d->reg == 1) f |= (d->opc == 0xF6) ? F_I8 : F_IZ;
        }
        if (d->mod != 3) {
            int o = d->opc;
            if (o == 0xD8) d->fp_size = 4;
            else if (o == 0xD9 && d->reg == 0) d->fp_size = 4;
            else if (o == 0xDC) d->fp_size = 8;
            else if (o == 0xDD && d->reg == 0) d->fp_size = 8;
            else if ((o >= 0x110 && o <= 0x117) || (o >= 0x128 && o <= 0x12F) || (o >= 0x150 && o <= 0x15F))
                d->fp_size = (d->pf2 || (d->p66 && !d->pf3)) ? 8 : 4;
        }
    }
    if (f & F_I8) {
        d->imm_off = i;
        d->imm_size = 1;
        i += 1;
    }
    if (f & F_IZ) {
        d->imm_off = i;
        d->imm_size = d->p66 ? 2 : 4;
        i += d->imm_size;
    }
    if (f & F_I16) {
        d->imm_off = i;
        d->imm_size = 2;
        i += 2;
    }
    if (f & F_ENTER) i += 3;
    if (f & F_PTR) i += d->p66 ? 4 : 6;
    if (f & F_AM) {
        d->imm_off = i;
        d->imm_size = a16 ? 2 : 4;
        i += d->imm_size;
    }
    if (f & F_R8) {
        d->rel_off = i;
        d->rel_size = 1;
        i += 1;
    }
    if (f & F_RZ) {
        d->rel_off = i;
        d->rel_size = d->p66 ? 2 : 4;
        i += d->rel_size;
    }
    if (i > max) return -1;
    d->len = i;
    return i;
}

/* ------------------------------------------------------------- demangler */

typedef struct {
    const char *p;
    char *names[10];
    int nn;
    char *types[10];
    int nt;
    int fail;
} Dm;

static void dm_type(Dm *d, Buf *o);
static void dm_qname(Dm *d, Buf *o);

static void dm_remember(char **tab, int *n, const char *s, size_t len)
{
    char *c;
    if (*n >= 10) return;
    c = xmalloc(len + 1);
    memcpy(c, s, len);
    c[len] = 0;
    tab[(*n)++] = c;
}

static long long dm_number(Dm *d)
{
    int neg = 0;
    long long v = 0;
    if (*d->p == '?') {
        neg = 1;
        d->p++;
    }
    if (*d->p >= '0' && *d->p <= '9') {
        v = *d->p++ - '0' + 1;
    } else {
        while (*d->p >= 'A' && *d->p <= 'P') v = v * 16 + (*d->p++ - 'A');
        if (*d->p != '@') {
            d->fail = 1;
            return 0;
        }
        d->p++;
    }
    return neg ? -v : v;
}

static void dm_template(Dm *d, Buf *o)
{
    /* at "?$": Name@args@ */
    Dm in;
    int first = 1;
    const char *s = d->p;
    memset(&in, 0, sizeof in);
    while (*d->p && *d->p != '@') d->p++;
    if (!*d->p) {
        d->fail = 1;
        return;
    }
    bput(o, s, (size_t)(d->p - s));
    dm_remember(in.names, &in.nn, s, (size_t)(d->p - s));
    d->p++;
    bputc(o, '<');
    in.p = d->p;
    while (*in.p && *in.p != '@' && !in.fail) {
        if (!first) bputc(o, ',');
        first = 0;
        dm_type(&in, o);
    }
    if (*in.p != '@') in.fail = 1;
    else in.p++;
    {
        int i;
        for (i = 0; i < in.nn; i++) free(in.names[i]);
        for (i = 0; i < in.nt; i++) free(in.types[i]);
    }
    if (in.fail) d->fail = 1;
    d->p = in.p;
    if (o->n && o->p[o->n - 1] == '>') bputc(o, ' ');
    bputc(o, '>');
}

static void dm_component(Dm *d, Buf *o)
{
    const char *s = d->p;
    if (*d->p >= '0' && *d->p <= '9') {
        int k = *d->p++ - '0';
        if (k < d->nn) bputs(o, d->names[k]);
        else d->fail = 1;
        return;
    }
    if (d->p[0] == '?' && d->p[1] == '$') {
        Buf t = {0};
        d->p += 2;
        dm_template(d, &t);
        bputs(o, bstr(&t));
        dm_remember(d->names, &d->nn, bstr(&t), t.n);
        free(t.p);
        return;
    }
    if (d->p[0] == '?' && d->p[1] == 'A') {
        while (*d->p && *d->p != '@') d->p++;
        if (*d->p) d->p++;
        bputs(o, "`anonymous namespace'");
        return;
    }
    if (d->p[0] == '?') {
        d->fail = 1;
        return;
    }
    while (*d->p && *d->p != '@') d->p++;
    if (!*d->p) {
        d->fail = 1;
        return;
    }
    bput(o, s, (size_t)(d->p - s));
    dm_remember(d->names, &d->nn, s, (size_t)(d->p - s));
    d->p++;
}

static void dm_qname(Dm *d, Buf *o)
{
    /* components innermost first, terminated by '@' */
    char *parts[32];
    int n = 0, i;
    while (*d->p && *d->p != '@' && !d->fail && n < 32) {
        Buf t = {0};
        dm_component(d, &t);
        parts[n++] = t.p ? t.p : xstrdup("");
    }
    if (*d->p == '@') d->p++;
    else d->fail = 1;
    for (i = n - 1; i >= 0; i--) {
        bputs(o, parts[i]);
        if (i) bputs(o, "::");
        free(parts[i]);
    }
}

static void dm_type(Dm *d, Buf *o)
{
    const char *start = d->p;
    size_t ostart = o->n;
    char c = *d->p++;
    const char *simple = NULL;
    switch (c) {
    case 'X': simple = "void"; break;
    case 'C': simple = "signed char"; break;
    case 'D': simple = "char"; break;
    case 'E': simple = "unsigned char"; break;
    case 'F': simple = "short"; break;
    case 'G': simple = "unsigned short"; break;
    case 'H': simple = "int"; break;
    case 'I': simple = "unsigned int"; break;
    case 'J': simple = "long"; break;
    case 'K': simple = "unsigned long"; break;
    case 'M': simple = "float"; break;
    case 'N': simple = "double"; break;
    case 'O': simple = "long double"; break;
    case '_':
        c = *d->p++;
        switch (c) {
        case 'N': simple = "bool"; break;
        case 'J': simple = "__int64"; break;
        case 'K': simple = "unsigned __int64"; break;
        case 'W': simple = "wchar_t"; break;
        case 'D': simple = "__int8"; break;
        case 'E': simple = "unsigned __int8"; break;
        case 'F': simple = "__int16"; break;
        case 'G': simple = "unsigned __int16"; break;
        case 'H': simple = "__int32"; break;
        case 'I': simple = "unsigned __int32"; break;
        default: d->fail = 1; return;
        }
        break;
    case 'T': bputs(o, "union "); dm_qname(d, o); break;
    case 'U': bputs(o, "struct "); dm_qname(d, o); break;
    case 'V': bputs(o, "class "); dm_qname(d, o); break;
    case 'W':
        if (*d->p >= '0' && *d->p <= '7') d->p++;
        bputs(o, "enum ");
        dm_qname(d, o);
        break;
    case 'P': case 'Q': case 'R': case 'S': case 'A': {
        char cv;
        Buf t = {0};
        if (*d->p == 'E') d->p++;
        cv = *d->p++;
        if (cv == '6') { d->fail = 1; return; } /* function pointer */
        if (cv < 'A' || cv > 'D') { d->fail = 1; return; }
        if (cv == 'B' || cv == 'D') bputs(&t, "const ");
        dm_type(d, &t);
        bputs(o, bstr(&t));
        bputs(o, c == 'A' ? " &" : " *");
        free(t.p);
        break;
    }
    case '$':
        c = *d->p++;
        if (c == '0') {
            bprintf(o, "%lld", dm_number(d));
            return;
        } else if (c == '$' && (*d->p == 'C' || *d->p == 'B')) {
            char k = *d->p++;
            if (k == 'C') {
                char cv = *d->p++;
                if (cv == 'B' || cv == 'D') bputs(o, "const ");
            }
            dm_type(d, o);
        } else if (c == '1' && *d->p == '?') {
            /* &symbol: keep mangled */
            const char *s = d->p;
            while (*d->p && !(d->p[0] == '@' && d->p[1] == '@')) d->p++;
            /* not reliable: give up */
            (void)s;
            d->fail = 1;
            return;
        } else {
            d->fail = 1;
            return;
        }
        break;
    default:
        if (c >= '0' && c <= '9') {
            int k = c - '0';
            if (k < d->nt) bputs(o, d->types[k]);
            else d->fail = 1;
            return;
        }
        d->fail = 1;
        return;
    }
    if (simple) {
        bputs(o, simple);
        return;
    }
    if (d->p - start > 1) dm_remember(d->types, &d->nt, o->p + ostart, o->n - ostart);
}

/* ".?AVFoo@Outer@@" -> "Outer::Foo"; returns malloc'd string; falls back to the mangled body */
static char *demangle_td(const char *m)
{
    Dm d;
    Buf o = {0};
    int i;
    memset(&d, 0, sizeof d);
    if (strncmp(m, ".?A", 3) || !m[3]) return xstrdup(m);
    d.p = m + 4;
    dm_qname(&d, &o);
    if (*d.p) d.fail = 1;
    for (i = 0; i < d.nn; i++) free(d.names[i]);
    for (i = 0; i < d.nt; i++) free(d.types[i]);
    if (d.fail || !o.n) {
        free(o.p);
        return xstrdup(m + 4);
    }
    return o.p;
}

/* ------------------------------------------------------------------ RTTI */

typedef struct {
    u32 va;
    char *mangled, *name;
    int ncol;
} TD;
typedef struct {
    u32 va, td, off, cd, chd, vt, nslots;
} COL;

static TD *tds;
static u32 ntd;
static COL *cols;
static u32 ncol;
static Map tdmap, colmap, vtmap; /* va -> index+1 */
static u32 nvt, nslots_total;

static void scan_rtti(const char *outdir)
{
    int s;
    u32 i;
    char path[1024];
    FILE *f;
    /* TypeDescriptors */
    for (s = 0; s < nsec; s++) {
        Sec *x = &secs[s];
        u32 p, e = x->va + x->vsize;
        if (!x->data) continue;
        for (p = (x->va + 8 + 3) & ~3u; p + 5 < e; p += 4) {
            const u8 *q = img + (p - base);
            if (q[0] != '.' || q[1] != '?' || q[2] != 'A' || (q[3] != 'V' && q[3] != 'U')) continue;
            if (rd32(p - 4) != 0 || !inimg(rd32(p - 8))) continue;
            {
                u32 n = 0;
                while (p + n < e && q[n] && n < 4096) n++;
                if (p + n >= e || q[n]) continue;
                tds = xrealloc(tds, (ntd + 1) * sizeof(TD));
                tds[ntd].va = p - 8;
                tds[ntd].mangled = xstrdup((const char *)q);
                tds[ntd].name = demangle_td((const char *)q);
                tds[ntd].ncol = 0;
                map_put(&tdmap, p - 8, ntd + 1);
                ntd++;
            }
        }
    }
    /* CompleteObjectLocators */
    for (s = 0; s < nsec; s++) {
        Sec *x = &secs[s];
        u32 p, e = x->va + x->vsize, t;
        if (!x->data) continue;
        for (p = (x->va + 3) & ~3u; p + 20 <= e; p += 4) {
            if (!map_get(&tdmap, rd32(p + 12), &t)) continue;
            if (rd32(p) != 0 || !inimg(rd32(p + 16)) || rd32(p + 4) > 0x100000 || rd32(p + 8) > 0x100000) continue;
            cols = xrealloc(cols, (ncol + 1) * sizeof(COL));
            cols[ncol].va = p;
            cols[ncol].td = t - 1;
            cols[ncol].off = rd32(p + 4);
            cols[ncol].cd = rd32(p + 8);
            cols[ncol].chd = rd32(p + 16);
            cols[ncol].vt = 0;
            cols[ncol].nslots = 0;
            tds[t - 1].ncol++;
            map_put(&colmap, p, ncol + 1);
            ncol++;
        }
    }
    /* vtables: a pointer to a COL immediately precedes slot 0 */
    snprintf(path, sizeof path, "%s/vtable.tsv", outdir);
    f = fopen(path, "wb");
    if (!f) die("cannot write %s", path);
    fprintf(f, "class\tvtable_addr\toffset\tslot\tfunc\n");
    for (s = 0; s < nsec; s++) {
        Sec *x = &secs[s];
        u32 p, e = x->va + x->vsize, c;
        if (!x->data) continue;
        for (p = (x->va + 3) & ~3u; p + 8 <= e; p += 4) {
            u32 q, n = 0;
            if (!map_get(&colmap, rd32(p), &c)) continue;
            if (nrel_hl && !isrel(p)) continue;
            c--;
            for (q = p + 4; q + 4 <= e; q += 4, n++) {
                u32 v = rd32(q);
                if (!is_code(v) || (nrel_hl && !isrel(q))) break;
            }
            if (cols[c].vt == 0) {
                cols[c].vt = p + 4;
                cols[c].nslots = n;
            }
            map_put(&vtmap, p + 4, c + 1);
            nvt++;
            nslots_total += n;
            for (q = 0; q < n; q++)
                fprintf(f, "%s\t0x%08x\t0x%x\t%u\t0x%08x\n", tds[cols[c].td].name, p + 4, cols[c].off, q,
                        rd32(p + 4 + q * 4));
        }
    }
    fclose(f);

    snprintf(path, sizeof path, "%s/rtti.tsv", outdir);
    f = fopen(path, "wb");
    if (!f) die("cannot write %s", path);
    fprintf(f, "class\tmangled\ttd_addr\tcol_addr\tvtable_addr\toffset\tcd_offset\tnslots\n");
    for (i = 0; i < ntd; i++) {
        u32 c;
        int any = 0;
        for (c = 0; c < ncol; c++) {
            if (cols[c].td != i) continue;
            any = 1;
            fprintf(f, "%s\t%s\t0x%08x\t0x%08x\t", tds[i].name, tds[i].mangled, tds[i].va, cols[c].va);
            if (cols[c].vt) fprintf(f, "0x%08x", cols[c].vt);
            fprintf(f, "\t0x%x\t0x%x\t%u\n", cols[c].off, cols[c].cd, cols[c].nslots);
        }
        if (!any) fprintf(f, "%s\t%s\t0x%08x\t\t\t\t\t\n", tds[i].name, tds[i].mangled, tds[i].va);
    }
    fclose(f);

    /* class hierarchy (first COL per class) */
    snprintf(path, sizeof path, "%s/rtti_bases.tsv", outdir);
    f = fopen(path, "wb");
    if (!f) die("cannot write %s", path);
    fprintf(f, "class\tindex\tbase\tnum_contained\tmdisp\tpdisp\tvdisp\tattributes\n");
    {
        u8 *done = xcalloc(ntd + 1, 1);
        u32 c;
        for (c = 0; c < ncol; c++) {
            u32 chd = cols[c].chd, nb, bca, k;
            if (done[cols[c].td]) continue;
            done[cols[c].td] = 1;
            nb = rd32(chd + 8);
            bca = rd32(chd + 12);
            if (nb > 1024 || !inimg(bca)) continue;
            for (k = 0; k < nb; k++) {
                u32 bcd = rd32(bca + k * 4), t;
                if (!inimg(bcd) || !map_get(&tdmap, rd32(bcd), &t)) continue;
                fprintf(f, "%s\t%u\t%s\t%u\t%d\t%d\t%d\t0x%x\n", tds[cols[c].td].name, k, tds[t - 1].name,
                        rd32(bcd + 4), (s32)rd32(bcd + 8), (s32)rd32(bcd + 12), (s32)rd32(bcd + 16),
                        rd32(bcd + 20));
            }
        }
        free(done);
    }
    fclose(f);
}

/* -------------------------------------------------------------- strings */

typedef struct {
    u32 va;
    char kind;
    char *text;
    Buf funcs;
    u32 nfuncs, last;
} Str;
static Str *strs;
static u32 nstrs;
static Map strmap;

static void esc_char(Buf *o, unsigned c)
{
    if (c == '\\') bputs(o, "\\\\");
    else if (c == '\t') bputs(o, "\\t");
    else if (c == '\n') bputs(o, "\\n");
    else if (c == '\r') bputs(o, "\\r");
    else if (c < 0x20 || c >= 0x7f) bprintf(o, "\\x%02x", c);
    else bputc(o, (char)c);
}

static int okch(unsigned c) { return (c >= 0x20 && c < 0x7f) || c == '\t' || c == '\n' || c == '\r'; }

/* returns index+1 into strs, or 0 */
static u32 get_string(u32 va)
{
    u32 idx, n, maxn;
    const u8 *p;
    Buf o = {0};
    char kind = 0;
    if (map_get(&strmap, va, &idx)) return idx;
    if (!inimg(va) || !is_data(va)) return 0;
    p = img + (va - base);
    maxn = imgsize - (va - base);
    if (maxn > 8192) maxn = 8192;
    /* UTF-16 */
    if (maxn >= 6 && ((!be && p[0] && !p[1]) || (be && !p[0] && p[1]))) {
        for (n = 0; 2 * n + 1 < maxn; n++) {
            unsigned c = be ? (unsigned)(p[2 * n] << 8 | p[2 * n + 1]) : (unsigned)(p[2 * n + 1] << 8 | p[2 * n]);
            if (!c) break;
            if (!okch(c)) {
                n = 0;
                break;
            }
        }
        if (n >= 2 && 2 * n + 1 < maxn) {
            u32 k;
            for (k = 0; k < n; k++) esc_char(&o, be ? p[2 * k + 1] : p[2 * k]);
            kind = 'w';
        }
    }
    if (!kind) {
        for (n = 0; n < maxn && p[n]; n++)
            if (!okch(p[n])) {
                n = 0;
                break;
            }
        if (n >= 2 && n < maxn && !p[n]) {
            u32 k;
            for (k = 0; k < n; k++) esc_char(&o, p[k]);
            kind = 'a';
        }
    }
    if (!kind) {
        free(o.p);
        return 0;
    }
    strs = xrealloc(strs, (nstrs + 1) * sizeof(Str));
    memset(&strs[nstrs], 0, sizeof(Str));
    strs[nstrs].va = va;
    strs[nstrs].kind = kind;
    strs[nstrs].text = o.p;
    nstrs++;
    map_put(&strmap, va, nstrs);
    return nstrs;
}

/* --------------------------------------------------------- feature rows */

typedef struct {
    u32 *v;
    u32 n, cap;
} Set;
static int set_add(Set *s, u32 v)
{
    u32 i;
    for (i = 0; i < s->n; i++)
        if (s->v[i] == v) return 0;
    if (s->n == s->cap) {
        s->cap = s->cap ? s->cap * 2 : 32;
        s->v = xrealloc(s->v, s->cap * sizeof(u32));
    }
    s->v[s->n++] = v;
    return 1;
}

typedef struct {
    u32 start, end; /* function extent */
    Buf strings, callees, datarefs, imports, vrefs, consts, coderefs;
    Set sstr, sdata, simp, svref, sconst, scode;
    u32 nstr, nconst, ncall, nhelper;
} Feat;

static void list_add(Buf *b, const char *sep, const char *s)
{
    if (b->n) bputs(b, sep);
    bputs(b, s);
}
static void list_addx(Buf *b, u32 v)
{
    char t[16];
    snprintf(t, sizeof t, "0x%08x", v);
    list_add(b, ",", t);
}

static void feat_reset(Feat *F, u32 s, u32 e)
{
    F->start = s;
    F->end = e;
    bclear(&F->strings);
    bclear(&F->callees);
    bclear(&F->datarefs);
    bclear(&F->imports);
    bclear(&F->vrefs);
    bclear(&F->consts);
    bclear(&F->coderefs);
    F->sstr.n = F->sdata.n = F->simp.n = F->svref.n = F->sconst.n = F->scode.n = 0;
    F->nstr = F->nconst = F->ncall = F->nhelper = 0;
}

static void add_import(Feat *F, const char *name, u32 key)
{
    if (set_add(&F->simp, key)) list_add(&F->imports, "\x1f", name);
}

static void add_const_str(Feat *F, u32 key, const char *txt)
{
    if (F->nconst >= 16) return;
    if (!set_add(&F->sconst, key)) return;
    list_add(&F->consts, ",", txt);
    F->nconst++;
}
static void add_imm(Feat *F, u32 v)
{
    char t[16];
    snprintf(t, sizeof t, "0x%x", v);
    add_const_str(F, v, t);
}
static void add_fp(Feat *F, u32 va, int size)
{
    char t[32];
    if (size == 8) {
        u64 v = rd64(va);
        snprintf(t, sizeof t, "d%016llx", (unsigned long long)v);
    } else
        snprintf(t, sizeof t, "f%08x", rd32(va));
    add_const_str(F, va ^ 0x80000000u, t);
}

/* ppc import thunk: lis r11,hi; lwz r11,lo(r11); mtctr r11; bctr.  x86: jmp [iat] */
static const char *thunk_import(u32 t)
{
    if (!is_code(t)) return NULL;
    if (!is_ppc) {
        const u8 *p = img + (t - base);
        if (p[0] == 0xFF && p[1] == 0x25) return iat_name(rd32le(t + 2));
        return NULL;
    } else {
        u32 w0 = rd32(t), w1 = rd32(t + 4), w2 = rd32(t + 8), w3 = rd32(t + 12), r;
        if ((w0 >> 26) != 15 || ((w0 >> 16) & 31) != 0) return NULL;
        r = (w0 >> 21) & 31;
        if ((w1 >> 26) != 32 || ((w1 >> 16) & 31) != r) return NULL;
        if ((w2 & 0xFC1FFFFFu) != 0x7C0903A6u || w3 != 0x4E800420u) return NULL;
        return iat_name((w0 << 16) + (u32)(s32)(int16_t)(w1 & 0xffff));
    }
}

static void add_callee(Feat *F, u32 t)
{
    const char *imp = thunk_import(t);
    list_addx(&F->callees, t);
    F->ncall++;
    if (imp) add_import(F, imp, t);
}

/* classify an absolute address referenced by code. fp: float load size (0 if none).
   returns 1 if v points inside the current function after `after` (embedded data). */
static int classify(Feat *F, u32 v, int fp, u32 after)
{
    const char *imp;
    u32 k;
    if (!inimg(v)) return 0;
    if ((imp = iat_name(v)) != NULL) {
        add_import(F, imp, v);
        return 0;
    }
    if (is_code(v)) {
        if (v >= F->start && v < F->end) return v >= after;
        if (set_add(&F->scode, v)) list_addx(&F->coderefs, v);
        return 0;
    }
    if (map_get(&vtmap, v, &k)) {
        if (set_add(&F->svref, v)) {
            const COL *c = &cols[k - 1];
            Buf t = {0};
            bputs(&t, tds[c->td].name);
            if (c->off) bprintf(&t, "+0x%x", c->off);
            list_add(&F->vrefs, "\x1f", bstr(&t));
            free(t.p);
        }
        return 0;
    }
    if (map_get(&tdmap, v, &k)) {
        if (set_add(&F->svref, v)) {
            Buf t = {0};
            bputs(&t, "td:");
            bputs(&t, tds[k - 1].name);
            list_add(&F->vrefs, "\x1f", bstr(&t));
            free(t.p);
        }
        return 0;
    }
    if ((k = get_string(v)) != 0) {
        Str *s = &strs[k - 1];
        if (set_add(&F->sstr, v)) {
            list_add(&F->strings, "\x1f", s->text);
            F->nstr++;
            if (s->last != F->start || !s->nfuncs) {
                list_addx(&s->funcs, F->start);
                s->nfuncs++;
                s->last = F->start;
            }
        }
        return 0;
    }
    if (fp && is_rodata(v)) {
        add_fp(F, v, fp);
        return 0;
    }
    if (set_add(&F->sdata, v)) list_addx(&F->datarefs, v);
    return 0;
}

static FILE *ffeat, *ftrace; /* ftrace: --trace-insns debug listing of decoded instruction starts */
static u32 rows_with_str;

#define FNV_OFF 0xcbf29ce484222325ULL
#define FNV_PRIME 0x100000001b3ULL

static void write_row(Feat *F, const Func *fn, u32 size, u32 ninsn, u32 nbb, u64 h, int have_hash)
{
    if (F->nstr) rows_with_str++;
    fprintf(ffeat, "0x%08x\t%u\t%u\t%s\t%s\t%s\t%s\t%s\t%s\t%u\t%u\t", fn->va, size, F->nstr, bstr(&F->strings),
            bstr(&F->callees), bstr(&F->datarefs), bstr(&F->imports), bstr(&F->vrefs), bstr(&F->consts), ninsn,
            nbb);
    if (have_hash) fprintf(ffeat, "%016llx", (unsigned long long)h);
    fprintf(ffeat, "\t%s\t%s\n", bstr(&F->coderefs), fn->name ? fn->name : "");
}

static void scan_x86(Feat *F, const Func *fn)
{
    u32 s = fn->va, e = fn->va + fn->size, code_end, pc;
    u32 ninsn = 0, nbb = 1;
    u64 h = FNV_OFF;
    while (e > s && img[e - 1 - base] == 0xCC) e--;
    feat_reset(F, s, fn->va + fn->size);
    code_end = e;
    for (pc = s; pc < code_end;) {
        X86I d;
        u8 tmp[16];
        int len = x86_decode(img + (pc - base), (int)(code_end - pc), &d), k;
        if (len <= 0) {
            len = (int)(code_end - pc);
            if (len > 15) len = 1;
            memset(&d, 0, sizeof d);
            d.imm_off = d.rel_off = -1;
            d.len = len;
        }
        ninsn++;
        if (ftrace) fprintf(ftrace, "%08X\n", pc);
        memcpy(tmp, img + (pc - base), (size_t)len);
        for (k = 0; k + 4 <= len; k++) {
            if (!isrel(pc + (u32)k)) continue;
            {
                u32 v = rd32le(pc + (u32)k);
                if (classify(F, v, d.fp_size, pc + (u32)len) && v < code_end) code_end = v;
            }
            memset(tmp + k, 0, 4);
            k += 3;
        }
        if (d.rel_size == 4) {
            u32 t = pc + (u32)len + rd32le(pc + (u32)d.rel_off);
            memset(tmp + d.rel_off, 0, 4);
            if (d.opc == 0xE8) add_callee(F, t);
            else if (d.opc == 0xE9 && (t < s || t >= F->end)) add_callee(F, t);
            if (d.opc != 0xE8) nbb++;
        } else if (d.rel_size == 1)
            nbb++;
        if (d.imm_size == 4 && !isrel(pc + (u32)d.imm_off) && d.opc != 0xA0 && d.opc != 0xA1 && d.opc != 0xA2 &&
            d.opc != 0xA3) {
            s32 v = (s32)rd32le(pc + (u32)d.imm_off);
            if (v >= 0x10000 || v <= -0x10000) add_imm(F, (u32)v);
        }
        for (k = 0; k < len; k++) {
            h ^= tmp[k];
            h *= FNV_PRIME;
        }
        pc += (u32)len;
    }
    write_row(F, fn, code_end - s, ninsn, nbb, h, 1);
}

/* ----------------------------------------------------------- ppc scanner */

enum { R_INV = 0, R_HI = 1, R_TOP = 2 };
typedef struct {
    u8 st[32];
    u32 val[32];
} RS;

static void rs_all(RS *r, u8 st)
{
    memset(r->st, st, 32);
    memset(r->val, 0, sizeof r->val);
}
static void rs_meet(RS *a, const RS *b)
{
    int i;
    for (i = 0; i < 32; i++) {
        if (b->st[i] == R_TOP) continue;
        if (a->st[i] == R_TOP) {
            a->st[i] = b->st[i];
            a->val[i] = b->val[i];
        } else if (a->st[i] != b->st[i] || (a->st[i] == R_HI && a->val[i] != b->val[i]))
            a->st[i] = R_INV;
    }
}
static int rs_eq(const RS *a, const RS *b)
{
    int i;
    for (i = 0; i < 32; i++) {
        if (a->st[i] != b->st[i]) return 0;
        if (a->st[i] == R_HI && a->val[i] != b->val[i]) return 0;
    }
    return 1;
}

/* save/restore millicode (__savegprlr_N, __restgprlr_N, __savefpr, __savevmx...) */
static int ppc_helper(u32 t)
{
    u32 w = rd32(t), op = w >> 26, ra = (w >> 16) & 31;
    if ((op == 62 || op == 58) && ra == 1 && (w & 3) == 0) return 1;
    if ((op == 54 || op == 50) && (ra == 1 || ra == 12)) return 1;
    if (op == 14 && ra == 0) {
        u32 w2 = rd32(t + 4), op2 = w2 >> 26;
        u32 xo = (w2 >> 1) & 0x3ff;
        if (op2 == 4 || (op2 == 31 && (xo == 103 || xo == 231 || xo == 359 || xo == 487))) return 1;
    }
    return 0;
}

static u32 ppc_lo_hit, ppc_lo_miss, ppc_lo_extra;
static int *ppc_tgt;     /* per insn: target index or -1 */
static RS *ppc_in, *ppc_new;
static u32 ppc_cap, ppc_tcap;

static int ppc_branch_target(u32 w, u32 pc, u32 *t)
{
    u32 op = w >> 26;
    if (op == 18) {
        s32 li = (s32)((w & 0x03fffffc) << 6) >> 6;
        *t = (w & 2) ? (u32)li : pc + (u32)li;
        return 1;
    }
    if (op == 16) {
        s32 bd = (s32)(int16_t)(w & 0xfffc);
        *t = (w & 2) ? (u32)bd : pc + (u32)bd;
        return 1;
    }
    return 0;
}

static void scan_ppc(Feat *F, const Func *fn)
{
    u32 s = fn->va, e = fn->va + fn->size, n, i, ntg = 0, pass, ninsn = 0, nbb = 1;
    u64 h = FNV_OFF;
    while (e > s && rd32(e - 4) == 0) e -= 4;
    feat_reset(F, s, fn->va + fn->size);
    n = (e - s) / 4;
    if (n > ppc_cap) {
        ppc_cap = n * 2;
        ppc_tgt = xrealloc(ppc_tgt, ppc_cap * sizeof(int));
    }
    for (i = 0; i < n; i++) ppc_tgt[i] = -1;
    for (i = 0; i < n; i++) {
        u32 w = rd32(s + i * 4), t;
        if (isrel(s + i * 4)) continue;
        if (ppc_branch_target(w, s + i * 4, &t) && !(w & 1) && t >= s && t < e && !((t - s) & 3)) {
            u32 j = (t - s) / 4;
            if (ppc_tgt[j] < 0) ppc_tgt[j] = (int)ntg++;
        }
    }
    if (ntg > ppc_tcap) {
        ppc_tcap = ntg * 2;
        ppc_in = xrealloc(ppc_in, ppc_tcap * sizeof(RS));
        ppc_new = xrealloc(ppc_new, ppc_tcap * sizeof(RS));
    }
    for (i = 0; i < ntg; i++) rs_all(&ppc_in[i], R_TOP);

    for (pass = 0; pass < 8; pass++) {
        int final = 0, fall = 1;
        RS cur;
        if (pass > 0) {
            int same = 1;
            for (i = 0; i < ntg && same; i++)
                if (!rs_eq(&ppc_in[i], &ppc_new[i])) same = 0;
            if (pass > 1 && same) final = 1;
            if (pass == 7) final = 1;
            for (i = 0; i < ntg; i++) ppc_in[i] = ppc_new[i];
        }
        for (i = 0; i < ntg; i++) rs_all(&ppc_new[i], R_TOP);
        rs_all(&cur, R_INV);
        for (i = 0; i < n; i++) {
            u32 pc = s + i * 4, w = rd32(pc), op = w >> 26, rd = (w >> 21) & 31, ra = (w >> 16) & 31, t;
            u32 hw = w; /* masked word for hashing */
            int am = 0; /* address immediate resolved */
            s32 simm = (int16_t)(w & 0xffff);
            if (isrel(pc)) { /* table word (absolute address) inside code */
                fall = 0;
                if (final) {
                    hw = 0;
                    h ^= hw;
                    h *= FNV_PRIME;
                }
                continue;
            }
            if (ppc_tgt[i] >= 0) {
                if (fall) rs_meet(&cur, &ppc_in[ppc_tgt[i]]);
                else cur = ppc_in[ppc_tgt[i]];
            } else if (!fall)
                rs_all(&cur, R_INV);
            fall = 1;
            if (final) ninsn++;
#define HI(r) ((r) != 0 && cur.st[r] == R_HI)
#define INV(r) (cur.st[r] = R_INV)
            switch (op) {
            case 15: /* addis / lis */
                if (ra == 0) {
                    cur.st[rd] = R_HI;
                    cur.val[rd] = w << 16;
                    hw &= 0xffff0000u;
                } else if (HI(ra)) {
                    cur.val[rd] = cur.val[ra] + (w << 16);
                    cur.st[rd] = R_HI;
                    hw &= 0xffff0000u;
                } else
                    INV(rd);
                break;
            case 14: /* addi */
                if (HI(ra)) {
                    u32 v = cur.val[ra] + (u32)simm;
                    if (final) {
                        if (inimg(v)) classify(F, v, 0, pc + 4);
                        else add_imm(F, v);
                    }
                    if (inimg(v)) { hw &= 0xffff0000u; am = 1; }
                }
                INV(rd);
                break;
            case 24: /* ori rA,rS,uimm */
                if (HI(rd)) {
                    u32 v = cur.val[rd] | (w & 0xffff);
                    if (final) {
                        if (inimg(v)) classify(F, v, 0, pc + 4);
                        else add_imm(F, v);
                    }
                    if (inimg(v)) { hw &= 0xffff0000u; am = 1; }
                }
                INV(ra);
                break;
            case 32: case 33: case 34: case 35: case 36: case 37: case 38: case 39:
            case 40: case 41: case 42: case 43: case 44: case 45: case 46: case 47:
            case 48: case 49: case 50: case 51: case 52: case 53: case 54: case 55:
                if (HI(ra)) {
                    u32 v = cur.val[ra] + (u32)simm;
                    int fp = (op == 48 || op == 49) ? 4 : (op == 50 || op == 51) ? 8 : 0;
                    if (final && inimg(v)) classify(F, v, fp, pc + 4);
                    { hw &= 0xffff0000u; am = 1; }
                }
                if (op <= 35 || (op >= 40 && op <= 43)) INV(rd);
                if (op == 46) {
                    u32 r;
                    for (r = rd; r < 32; r++) INV(r);
                }
                if ((op & 1) && op != 47 && op != 46) INV(ra);
                break;
            case 58: /* ld/ldu/lwa */
            case 62: /* std/stdu */
                if (HI(ra)) {
                    u32 v = cur.val[ra] + (u32)(s32)(int16_t)(w & 0xfffc);
                    if (final && inimg(v)) classify(F, v, 0, pc + 4);
                    { hw &= 0xffff0003u; am = 1; }
                }
                if (op == 58) INV(rd);
                if ((w & 3) == 1) INV(ra);
                break;
            case 10: case 11: case 2: case 3: case 17: case 59: case 63: case 4: case 5: case 6:
                break;
            case 16: case 18: case 19:
                break;
            case 31: {
                u32 xo = (w >> 1) & 0x3ff, rb = (w >> 11) & 31;
                if (xo == 444 && rd == rb) { /* mr */
                    cur.st[ra] = cur.st[rd];
                    cur.val[ra] = cur.val[rd];
                } else {
                    INV(rd);
                    INV(ra);
                }
                break;
            }
            case 7: case 8: case 12: case 13:
                INV(rd);
                break;
            default:
                INV(rd);
                INV(ra);
                break;
            }
            /* branches */
            if (op == 18 || op == 16) {
                int lk = w & 1;
                int always = op == 18 || ((rd & 0x14) == 0x14);
                ppc_branch_target(w, pc, &t);
                if (lk) {
                    if (final) {
                        if (ppc_helper(t)) F->nhelper++;
                        else add_callee(F, t);
                    }
                    hw &= 0xfc000003u;
                    INV(0);
                    {
                        u32 r;
                        for (r = 3; r <= 12; r++) INV(r);
                    }
                } else {
                    if (final) nbb++;
                    if (t >= s && t < e && !((t - s) & 3)) {
                        u32 j = (t - s) / 4;
                        if (ppc_tgt[j] >= 0) rs_meet(&ppc_new[ppc_tgt[j]], &cur);
                    } else {
                        if (final && op == 18) {
                            if (ppc_helper(t)) F->nhelper++;
                            else add_callee(F, t);
                        }
                        if (op == 18) hw &= 0xfc000003u;
                    }
                    if (always) fall = 0;
                }
            } else if (op == 19) {
                u32 xo = (w >> 1) & 0x3ff;
                if (xo == 16 || xo == 528) {
                    if (w & 1) {
                        INV(0);
                        {
                            u32 r;
                            for (r = 3; r <= 12; r++) INV(r);
                        }
                    } else {
                        if (final) nbb++;
                        if ((rd & 0x14) == 0x14) fall = 0;
                    }
                }
            }
#undef HI
#undef INV
            if (final && !(op == 15 && ra == 0) && op != 18) { /* address-formation coverage vs. the LOW relocations */
                int rel = isrelother(pc + 2) || isrelother(pc);
                int got = am;
                if (rel && got) ppc_lo_hit++;
                else if (rel) ppc_lo_miss++;
                else if (got) ppc_lo_extra++;
            }
            if (final) {
                h ^= hw;
                h *= FNV_PRIME;
            }
        }
        if (final) break;
    }
    write_row(F, fn, e - s, ninsn, nbb, h, 1);
}

/* ------------------------------------------------------------------ main */

static void usage(void)
{
    fprintf(stderr, "usage: binscan --image <exe> --arch x86|ppc [--functions <json|tsv|map>] --out <dir> [--trace-insns <file>]\n");
    exit(2);
}

static int cmp_stridx(const void *a, const void *b)
{
    u32 x = strs[*(const u32 *)a].va, y = strs[*(const u32 *)b].va;
    return x < y ? -1 : x > y;
}

static int ends_with(const char *s, const char *suf)
{
    size_t a = strlen(s), b = strlen(suf);
    return a >= b && !_stricmp(s + a - b, suf);
}

int main(int argc, char **argv)
{
    const char *image = NULL, *arch = NULL, *flist = NULL, *out = NULL;
    char path[1024];
    int i;
    u32 fi;
    clock_t t0 = clock();
    Feat F;
    FILE *fs;
    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--image") && i + 1 < argc) image = argv[++i];
        else if (!strcmp(argv[i], "--arch") && i + 1 < argc) arch = argv[++i];
        else if (!strcmp(argv[i], "--functions") && i + 1 < argc) flist = argv[++i];
        else if (!strcmp(argv[i], "--out") && i + 1 < argc) out = argv[++i];
        else if (!strcmp(argv[i], "--trace-insns") && i + 1 < argc) ftrace = fopen(argv[++i], "wb");
        else usage();
    }
    if (!image || !arch || !out) usage();
    if (strcmp(arch, "x86") && strcmp(arch, "ppc")) usage();
#ifdef _WIN32
    _mkdir(out);
#endif
    x86_init();
    load_pe(image, !strcmp(arch, "ppc"));
    load_relocs();
    load_imports();
    if (flist) {
        if (ends_with(flist, ".json")) load_json(flist);
        else if (ends_with(flist, ".map")) load_map(flist);
        else load_tsv(flist);
    }
    if (is_ppc) load_pdata(); /* also fills functions a list leaves out */
    else if (!flist)
        discover_x86();
    finish_funcs();
    fprintf(stderr, "image %s: base 0x%08x size 0x%x, %d sections, relocs %u highlow + %u other, %u imports, %u functions\n",
            image, base, imgsize, nsec, nrel_hl, nrel_other, nimp, nfuncs);

    scan_rtti(out);

    /* packed/encrypted code (e.g. a DRM-wrapped .text) has a flat byte histogram: skip features */
    {
        u64 hist[256] = {0}, tot = 0;
        int s2, b2;
        for (s2 = 0; s2 < nsec; s2++)
            if (secs[s2].exec) {
                u32 a, n = secs[s2].vsize;
                if (secs[s2].va - base + n > imgsize) n = imgsize - (secs[s2].va - base);
                for (a = 0; a < n; a++) hist[img[secs[s2].va - base + a]]++;
                tot += n;
            }
        for (b2 = 0; b2 < 256 && tot; b2++)
            if (hist[b2] * 100 > tot) break;
        if (tot && b2 == 256) {
            fprintf(stderr, "binscan: code sections look encrypted or packed (flat byte histogram); "
                            "features.tsv and strings.tsv left empty, RTTI tables only\n");
            nfuncs = 0;
        }
    }

    snprintf(path, sizeof path, "%s/features.tsv", out);
    ffeat = fopen(path, "wb");
    if (!ffeat) die("cannot write %s", path);
    fprintf(ffeat, "addr\tsize\tnstr\tstrings\tcallees\tdatarefs\timports\tvrefs\tconsts\tninsn\tnbb\thash_norm\tcoderefs\tname\n");
    memset(&F, 0, sizeof F);
    for (fi = 0; fi < nfuncs; fi++) {
        if (is_ppc) scan_ppc(&F, &funcs[fi]);
        else scan_x86(&F, &funcs[fi]);
    }
    fclose(ffeat);

    snprintf(path, sizeof path, "%s/strings.tsv", out);
    fs = fopen(path, "wb");
    if (!fs) die("cannot write %s", path);
    fprintf(fs, "addr\tkind\ttext\tnfuncs\tfuncs\n");
    {
        /* strs are created in scan order; emit sorted by address */
        u32 *ord = xmalloc(nstrs * sizeof(u32)), k;
        u32 nused = 0;
        for (k = 0; k < nstrs; k++) ord[k] = k;
        qsort(ord, nstrs, sizeof(u32), cmp_stridx);
        for (k = 0; k < nstrs; k++) {
            Str *x = &strs[ord[k]];
            if (!x->nfuncs) continue;
            nused++;
            fprintf(fs, "0x%08x\t%c\t%s\t%u\t%s\n", x->va, x->kind, x->text, x->nfuncs, bstr(&x->funcs));
        }
        free(ord);
        fclose(fs);
        {
            u32 nclass = 0;
            for (k = 0; k < ntd; k++)
                if (tds[k].ncol) nclass++;
            fprintf(stderr,
                    "functions %u, rows with strings %u, strings %u, type descriptors %u, classes with COL %u, COLs %u, "
                    "vtables %u (%u slots), %.1fs\n",
                    nfuncs, rows_with_str, nused, ntd, nclass, ncol, nvt, nslots_total,
                    (double)(clock() - t0) / CLOCKS_PER_SEC);
            if (is_ppc)
                fprintf(stderr, "ppc lo-half address operands: %u resolved, %u relocated but unresolved, %u resolved without reloc\n",
                        ppc_lo_hit, ppc_lo_miss, ppc_lo_extra);
        }
    }
    return 0;
}

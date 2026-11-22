/* coff.c - COFF object and CodeView (signature 4, C13 subsections) reader. See coff.h.

   .debug$S holds subsections: DEBUG_S_SYMBOLS (0xF1) with S_GPROC32/S_LPROC32 (and the _ID variants), whose code
   offset carries a SECREL relocation to the function symbol; DEBUG_S_LINES (0xF2), whose header carries the same
   relocation; DEBUG_S_FILECHKSMS (0xF4), mapping a line block's file id (byte offset) to a DEBUG_S_STRINGTABLE
   (0xF3) offset. With /Gy every function has its own COMDAT section and an associative .debug$S. */
#include "util.h"
#include "coff.h"

#define S_LPROC32 0x110F
#define S_GPROC32 0x1110
#define S_LPROC32_ID 0x1146
#define S_GPROC32_ID 0x1147

typedef struct {
    char name[9];
    const char *lname;
    uint32_t size, ptr, relptr;
    uint16_t nrel;
    uint32_t chars;
} Sect;

typedef struct {
    const char *name;
    int16_t sect;
    uint32_t value;
    uint16_t type;
    uint8_t cls;
    uint8_t naux;
} Sym;

typedef struct {
    int fileid;
    uint32_t off;
    int line;
} LineEnt;

typedef struct {
    int sect;
    uint32_t start;
    const char *name;
    uint32_t size;
    int have_size;
    VEC(LineEnt) lines;
} Tmp;

static uint16_t rd16(const unsigned char *p) { return (uint16_t)(p[0] | (p[1] << 8)); }
static uint32_t rd32(const unsigned char *p) { return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24); }

typedef struct {
    const unsigned char *d;
    size_t len;
    Sect *sec;
    int nsec;
    Sym *sym;
    uint32_t nsym;
    const char *strtab;
    StrMap funcsym; /* "sect:value" -> symbol index+1 for function symbols */
    StrMap tmpmap;  /* "sect:value" -> Tmp* */
    VEC(Tmp *) tmps;
} Obj;

/* Resolve a relocation found at byte position pos inside section s (1-based) to (sect, offset, name). */
static int resolve_reloc(Obj *o, int s, uint32_t pos, int *tsect, uint32_t *toff, const char **tname)
{
    Sect *sc = &o->sec[s - 1];
    const unsigned char *r = o->d + sc->relptr;
    for (int i = 0; i < sc->nrel; i++, r += 10) {
        if (rd32(r) != pos) continue;
        uint32_t si = rd32(r + 4);
        if (si >= o->nsym) return 0;
        Sym *sy = &o->sym[si];
        uint32_t addend = rd32(o->d + sc->ptr + pos);
        *tsect = sy->sect;
        *toff = sy->value + addend;
        *tname = sy->name;
        if (sy->cls == 3 && sy->value == 0 && sy->naux > 0) {
            /* section symbol: find the function symbol at that offset */
            char key[32];
            sprintf(key, "%d:%u", *tsect, *toff);
            void *v = smap_get(&o->funcsym, key);
            *tname = v ? o->sym[(uintptr_t)v - 1].name : NULL;
        }
        return 1;
    }
    return 0;
}

static Tmp *tmp_for(Obj *o, int sect, uint32_t off, const char *name)
{
    char key[32];
    sprintf(key, "%d:%u", sect, off);
    void **slot = smap_slot(&o->tmpmap, key);
    if (!*slot) {
        Tmp *t = xcalloc(1, sizeof *t);
        t->sect = sect;
        t->start = off;
        t->name = name;
        *slot = t;
        VPUSH(o->tmps, t);
    }
    Tmp *t = *slot;
    if (!t->name && name) t->name = name;
    return t;
}

int coff_read(const char *path, ObjInfo *out, char *err, int errlen)
{
    memset(out, 0, sizeof *out);
    size_t len;
    unsigned char *d = (unsigned char *)read_file(path, &len);
    if (!d) {
        snprintf(err, (size_t)errlen, "cannot read %s", path);
        return -1;
    }
    Obj o;
    memset(&o, 0, sizeof o);
    o.d = d;
    o.len = len;
    if (len < 20 || rd16(d) != 0x14c) {
        snprintf(err, (size_t)errlen, "%s: not an i386 COFF object", path);
        free(d);
        return -1;
    }
    o.nsec = rd16(d + 2);
    uint32_t symptr = rd32(d + 8);
    o.nsym = rd32(d + 12);
    uint16_t optsz = rd16(d + 16);
    o.strtab = (const char *)d + symptr + o.nsym * 18;
    o.sec = xcalloc((size_t)o.nsec + 1, sizeof(Sect));
    for (int i = 0; i < o.nsec; i++) {
        const unsigned char *h = d + 20 + optsz + i * 40;
        Sect *s = &o.sec[i];
        memcpy(s->name, h, 8);
        s->name[8] = 0;
        s->lname = s->name;
        if (s->name[0] == '/') s->lname = o.strtab + atoi(s->name + 1);
        s->size = rd32(h + 16);
        s->ptr = rd32(h + 20);
        s->relptr = rd32(h + 24);
        s->nrel = rd16(h + 32);
        s->chars = rd32(h + 36);
    }
    o.sym = xcalloc((size_t)o.nsym + 1, sizeof(Sym));
    smap_init(&o.funcsym, o.nsym);
    smap_init(&o.tmpmap, 256);
    for (uint32_t i = 0; i < o.nsym; i++) {
        const unsigned char *p = d + symptr + i * 18;
        Sym *sy = &o.sym[i];
        if (rd32(p) == 0) {
            sy->name = o.strtab + rd32(p + 4);
        } else {
            char *n = xstrndup((const char *)p, 8); /* short names leak a few bytes; objects are freed per unit */
            sy->name = n;
        }
        sy->value = rd32(p + 8);
        sy->sect = (int16_t)rd16(p + 12);
        sy->type = rd16(p + 14);
        sy->cls = p[16];
        sy->naux = p[17];
        if (sy->sect > 0 && (sy->type & 0x30) == 0x20 && (sy->cls == 2 || sy->cls == 3)) {
            char key[32];
            sprintf(key, "%d:%u", sy->sect, sy->value);
            if (!smap_get(&o.funcsym, key)) smap_put(&o.funcsym, key, (void *)(uintptr_t)(i + 1));
        }
        for (int a = 0; a < sy->naux; a++) o.sym[i + 1 + a].name = "";
        i += sy->naux;
    }

    const unsigned char *chk = NULL, *str = NULL;
    uint32_t chklen = 0;
    for (int s = 1; s <= o.nsec; s++) {
        Sect *sc = &o.sec[s - 1];
        if (strcmp(sc->lname, ".debug$S") != 0 || sc->size < 4) continue;
        const unsigned char *base = d + sc->ptr;
        if (rd32(base) != 4) continue; /* CV_SIGNATURE_C13 */
        uint32_t p = 4;
        while (p + 8 <= sc->size) {
            uint32_t type = rd32(base + p), sl = rd32(base + p + 4);
            uint32_t q = p + 8;
            if (q + sl > sc->size) break;
            if (type == 0xF4 && !chk) {
                chk = base + q;
                chklen = sl;
            } else if (type == 0xF3 && !str) {
                str = base + q;
            } else if (type == 0xF1) {
                uint32_t r = q;
                while (r + 4 <= q + sl) {
                    uint16_t rl = rd16(base + r), rt = rd16(base + r + 2);
                    if (rl < 2) break;
                    if ((rt == S_GPROC32 || rt == S_LPROC32 || rt == S_GPROC32_ID || rt == S_LPROC32_ID) && rl >= 36) {
                        uint32_t codelen = rd32(base + r + 4 + 12);
                        int ts;
                        uint32_t to;
                        const char *tn;
                        if (resolve_reloc(&o, s, r + 4 + 28, &ts, &to, &tn) && ts > 0) {
                            Tmp *t = tmp_for(&o, ts, to, tn);
                            t->size = codelen;
                            t->have_size = 1;
                        }
                    }
                    r += rl + 2u;
                }
            } else if (type == 0xF2 && sl >= 12) {
                int ts;
                uint32_t to;
                const char *tn;
                if (resolve_reloc(&o, s, q, &ts, &to, &tn) && ts > 0) {
                    Tmp *t = tmp_for(&o, ts, to, tn);
                    uint16_t flags = rd16(base + q + 6);
                    uint32_t r = q + 12;
                    while (r + 12 <= q + sl) {
                        uint32_t fid = rd32(base + r), nl = rd32(base + r + 4), cb = rd32(base + r + 8);
                        if (cb < 12) break;
                        for (uint32_t k = 0; k < nl && r + 12 + k * 8 + 8 <= q + sl; k++) {
                            uint32_t off = rd32(base + r + 12 + k * 8), v = rd32(base + r + 12 + k * 8 + 4);
                            int line = (int)(v & 0xFFFFFF);
                            if (line == 0 || line >= 0xF00000) continue;
                            LineEnt e = {(int)fid, off + to - t->start, line};
                            VPUSH(t->lines, e);
                        }
                        (void)flags;
                        r += cb;
                    }
                }
            }
            p = q + ((sl + 3) & ~3u);
        }
    }

    out->funcs = xcalloc((size_t)o.tmps.n + 1, sizeof(ObjFunc));
    for (int i = 0; i < o.tmps.n; i++) {
        Tmp *t = o.tmps.v[i];
        if (!t->name || !t->name[0]) continue;
        ObjFunc *f = &out->funcs[out->n++];
        f->name = xstrdup(t->name);
        f->sect = t->sect;
        f->start = t->start;
        Sect *cs = (t->sect >= 1 && t->sect <= o.nsec) ? &o.sec[t->sect - 1] : NULL;
        f->code_size = t->have_size ? t->size : (cs ? cs->size : 0);
        if (t->lines.n && chk && str) {
            int best = 0;
            for (int k = 1; k < t->lines.n; k++)
                if (t->lines.v[k].off < t->lines.v[best].off) best = k;
            int fid = t->lines.v[best].fileid;
            f->first_line = t->lines.v[best].line;
            f->min_line = 0x7FFFFFFF;
            f->max_line = 0;
            for (int k = 0; k < t->lines.n; k++) {
                if (t->lines.v[k].fileid != fid) continue;
                int ln = t->lines.v[k].line;
                if (ln < f->min_line) f->min_line = ln;
                if (ln > f->max_line) f->max_line = ln;
            }
            if ((uint32_t)fid + 4 <= chklen) {
                uint32_t noff = rd32(chk + fid);
                f->file = xstrdup((const char *)str + noff);
            }
        }
        /* relocations inside the code */
        if (cs && cs->nrel) {
            VEC(char *) refs = {0};
            const unsigned char *r = d + cs->relptr;
            for (int k = 0; k < cs->nrel; k++, r += 10) {
                uint32_t at = rd32(r), si = rd32(r + 4);
                if (at < f->start || at >= f->start + f->code_size || si >= o.nsym) continue;
                Sym *sy = &o.sym[si];
                if (sy->cls == 3 && sy->value == 0 && sy->naux > 0) continue; /* section symbol */
                int dup = 0;
                for (int m = 0; m < refs.n; m++)
                    if (strcmp(refs.v[m], sy->name) == 0) dup = 1;
                if (!dup) VPUSH(refs, xstrdup(sy->name));
            }
            f->refs = refs.v;
            f->nrefs = refs.n;
        }
    }
    for (int i = 0; i < o.tmps.n; i++) {
        free(o.tmps.v[i]->lines.v);
        free(o.tmps.v[i]);
    }
    free(o.tmps.v);
    for (uint32_t i = 0; i < o.nsym; i++) {
        const unsigned char *p = d + symptr + i * 18;
        if (rd32(p) != 0 && o.sym[i].name && o.sym[i].name[0]) free((char *)o.sym[i].name);
        i += o.sym[i].naux;
    }
    smap_free(&o.funcsym);
    smap_free(&o.tmpmap);
    free(o.sym);
    free(o.sec);
    free(d);
    return 0;
}

void coff_free(ObjInfo *o)
{
    for (int i = 0; i < o->n; i++) {
        free(o->funcs[i].name);
        free(o->funcs[i].file);
        for (int k = 0; k < o->funcs[i].nrefs; k++) free(o->funcs[i].refs[k]);
        free(o->funcs[i].refs);
    }
    free(o->funcs);
    memset(o, 0, sizeof *o);
}

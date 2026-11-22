/* util.c - see util.h */
#include "util.h"
#include <stdarg.h>

void die(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    fprintf(stderr, "f3rules: ");
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);
    exit(2);
}

void *xmalloc(size_t n)
{
    void *p = malloc(n ? n : 1);
    if (!p) die("out of memory (%zu bytes)", n);
    return p;
}

void *xcalloc(size_t n, size_t m)
{
    void *p = calloc(n ? n : 1, m ? m : 1);
    if (!p) die("out of memory");
    return p;
}

void *xrealloc(void *p, size_t n)
{
    void *q = realloc(p, n ? n : 1);
    if (!q) die("out of memory (%zu bytes)", n);
    return q;
}

char *xstrndup(const char *s, size_t n)
{
    char *p = xmalloc(n + 1);
    memcpy(p, s, n);
    p[n] = 0;
    return p;
}

char *xstrdup(const char *s) { return xstrndup(s, strlen(s)); }

uint64_t fnv64(const void *data, size_t n, uint64_t h)
{
    const unsigned char *p = data;
    for (size_t i = 0; i < n; i++) {
        h ^= p[i];
        h *= 0x100000001b3ULL;
    }
    return h;
}

static uint32_t hash32(const char *s, size_t n)
{
    uint64_t h = fnv64(s, n, FNV64_INIT);
    uint32_t r = (uint32_t)(h ^ (h >> 32));
    return r ? r : 1;
}

void smap_init(StrMap *m, size_t cap_hint)
{
    size_t cap = 16;
    while (cap < cap_hint * 2) cap <<= 1;
    m->cap = cap;
    m->n = 0;
    m->keys = xcalloc(cap, sizeof(char *));
    m->vals = xcalloc(cap, sizeof(void *));
    m->hashes = xcalloc(cap, sizeof(uint32_t));
}

static size_t smap_find(const StrMap *m, const char *key, size_t len, uint32_t h)
{
    size_t mask = m->cap - 1, i = h & mask;
    for (;;) {
        if (!m->hashes[i]) return i;
        if (m->hashes[i] == h && strlen(m->keys[i]) == len && memcmp(m->keys[i], key, len) == 0) return i;
        i = (i + 1) & mask;
    }
}

static void smap_grow(StrMap *m)
{
    StrMap n;
    smap_init(&n, m->cap);
    for (size_t i = 0; i < m->cap; i++) {
        if (!m->hashes[i]) continue;
        size_t j = smap_find(&n, m->keys[i], strlen(m->keys[i]), m->hashes[i]);
        n.hashes[j] = m->hashes[i];
        n.keys[j] = m->keys[i];
        n.vals[j] = m->vals[i];
        n.n++;
    }
    free(m->keys);
    free(m->vals);
    free(m->hashes);
    *m = n;
}

void *smap_getn(const StrMap *m, const char *key, size_t len)
{
    if (!m->cap) return NULL;
    uint32_t h = hash32(key, len);
    size_t i = smap_find(m, key, len, h);
    return m->hashes[i] ? m->vals[i] : NULL;
}

void *smap_get(const StrMap *m, const char *key) { return smap_getn(m, key, strlen(key)); }

int smap_has(const StrMap *m, const char *key)
{
    if (!m->cap) return 0;
    size_t len = strlen(key);
    uint32_t h = hash32(key, len);
    return m->hashes[smap_find(m, key, len, h)] != 0;
}

void **smap_slot(StrMap *m, const char *key)
{
    if (!m->cap) smap_init(m, 16);
    if ((m->n + 1) * 2 > m->cap) smap_grow(m);
    size_t len = strlen(key);
    uint32_t h = hash32(key, len);
    size_t i = smap_find(m, key, len, h);
    if (!m->hashes[i]) {
        m->hashes[i] = h;
        m->keys[i] = xstrndup(key, len);
        m->vals[i] = NULL;
        m->n++;
    }
    return &m->vals[i];
}

const char *smap_put(StrMap *m, const char *key, void *val)
{
    void **slot = smap_slot(m, key);
    *slot = val;
    size_t len = strlen(key);
    return m->keys[smap_find(m, key, len, hash32(key, len))];
}

void smap_free(StrMap *m)
{
    for (size_t i = 0; i < m->cap; i++)
        if (m->hashes[i]) free(m->keys[i]);
    free(m->keys);
    free(m->vals);
    free(m->hashes);
    memset(m, 0, sizeof *m);
}

char *read_file(const char *path, size_t *len_out)
{
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    _fseeki64(f, 0, SEEK_END);
    long long n = _ftelli64(f);
    _fseeki64(f, 0, SEEK_SET);
    char *buf = xmalloc((size_t)n + 1);
    size_t got = fread(buf, 1, (size_t)n, f);
    fclose(f);
    buf[got] = 0;
    if (len_out) *len_out = got;
    return buf;
}

void sb_add(StrBuf *b, const char *s, size_t n)
{
    if (b->n + n + 1 > b->cap) {
        b->cap = (b->n + n + 1) * 2;
        b->s = xrealloc(b->s, b->cap);
    }
    memcpy(b->s + b->n, s, n);
    b->n += n;
    b->s[b->n] = 0;
}

void sb_adds(StrBuf *b, const char *s) { sb_add(b, s, strlen(s)); }

void sb_printf(StrBuf *b, const char *fmt, ...)
{
    char tmp[4096];
    va_list ap;
    va_start(ap, fmt);
    int n = vsnprintf(tmp, sizeof tmp, fmt, ap);
    va_end(ap);
    if (n < 0) return;
    if ((size_t)n < sizeof tmp) {
        sb_add(b, tmp, (size_t)n);
        return;
    }
    char *big = xmalloc((size_t)n + 1);
    va_start(ap, fmt);
    vsnprintf(big, (size_t)n + 1, fmt, ap);
    va_end(ap);
    sb_add(b, big, (size_t)n);
    free(big);
}

void lower_inplace(char *s)
{
    for (; *s; s++) *s = (char)tolower((unsigned char)*s);
}

void slash_inplace(char *s)
{
    for (; *s; s++)
        if (*s == '\\') *s = '/';
}

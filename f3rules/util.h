/* util.h - small helpers shared by f3rules: allocation, growable arrays, a string hash map, file reading. */
#ifndef F3RULES_UTIL_H
#define F3RULES_UTIL_H

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

void *xmalloc(size_t n);
void *xcalloc(size_t n, size_t m);
void *xrealloc(void *p, size_t n);
char *xstrdup(const char *s);
char *xstrndup(const char *s, size_t n);
void die(const char *fmt, ...);

/* Growable array of T: declare with VEC(T) name; push with VPUSH. */
#define VEC(T) struct { T *v; int n, cap; }
#define VPUSH(vec, x)                                                                    \
    do {                                                                                 \
        if ((vec).n == (vec).cap) {                                                      \
            (vec).cap = (vec).cap ? (vec).cap * 2 : 8;                                   \
            (vec).v = xrealloc((vec).v, (size_t)(vec).cap * sizeof(*(vec).v));           \
        }                                                                                \
        (vec).v[(vec).n++] = (x);                                                        \
    } while (0)

uint64_t fnv64(const void *data, size_t n, uint64_t h);
#define FNV64_INIT 0xcbf29ce484222325ULL

/* String -> pointer map. Keys are owned by the map (copied on insert). Not thread safe. */
typedef struct {
    char **keys;
    void **vals;
    uint32_t *hashes;
    size_t cap, n;
} StrMap;

void smap_init(StrMap *m, size_t cap_hint);
void *smap_getn(const StrMap *m, const char *key, size_t len);
void *smap_get(const StrMap *m, const char *key);
int smap_has(const StrMap *m, const char *key);
/* Inserts or replaces; returns the stored key. */
const char *smap_put(StrMap *m, const char *key, void *val);
void **smap_slot(StrMap *m, const char *key); /* returns value slot, inserting NULL if absent */
void smap_free(StrMap *m);

/* Reads a whole file; returns NUL-terminated buffer or NULL. */
char *read_file(const char *path, size_t *len_out);

/* Simple string builder. */
typedef struct {
    char *s;
    size_t n, cap;
} StrBuf;
void sb_add(StrBuf *b, const char *s, size_t n);
void sb_adds(StrBuf *b, const char *s);
void sb_printf(StrBuf *b, const char *fmt, ...);

void lower_inplace(char *s);
void slash_inplace(char *s); /* backslashes -> forward slashes */

#endif

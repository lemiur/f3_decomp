/* json.c - minimal recursive-descent JSON reader. Strings are decoded (\uXXXX to UTF-8). */
#include "util.h"
#include "json.h"

typedef struct {
    const char *p;
    const char *err;
} JP;

static void ws(JP *j)
{
    while (*j->p == ' ' || *j->p == '\t' || *j->p == '\n' || *j->p == '\r') j->p++;
}

static JVal *jnew(int t)
{
    JVal *v = xcalloc(1, sizeof *v);
    v->type = t;
    return v;
}

static void put_utf8(StrBuf *b, unsigned cp)
{
    char c[4];
    if (cp < 0x80) {
        c[0] = (char)cp;
        sb_add(b, c, 1);
    } else if (cp < 0x800) {
        c[0] = (char)(0xC0 | (cp >> 6));
        c[1] = (char)(0x80 | (cp & 0x3F));
        sb_add(b, c, 2);
    } else {
        c[0] = (char)(0xE0 | (cp >> 12));
        c[1] = (char)(0x80 | ((cp >> 6) & 0x3F));
        c[2] = (char)(0x80 | (cp & 0x3F));
        sb_add(b, c, 3);
    }
}

static char *jstr(JP *j)
{
    StrBuf b = {0};
    j->p++; /* opening quote */
    sb_add(&b, "", 0);
    while (*j->p && *j->p != '"') {
        const char *s = j->p;
        while (*j->p && *j->p != '"' && *j->p != '\\') j->p++;
        sb_add(&b, s, (size_t)(j->p - s));
        if (*j->p == '\\') {
            j->p++;
            char c = *j->p++;
            switch (c) {
            case 'n': sb_add(&b, "\n", 1); break;
            case 't': sb_add(&b, "\t", 1); break;
            case 'r': sb_add(&b, "\r", 1); break;
            case 'b': sb_add(&b, "\b", 1); break;
            case 'f': sb_add(&b, "\f", 1); break;
            case 'u': {
                unsigned cp = 0;
                for (int k = 0; k < 4 && *j->p; k++, j->p++) {
                    char h = *j->p;
                    cp = cp * 16 + (unsigned)(h >= 'a' ? h - 'a' + 10 : h >= 'A' ? h - 'A' + 10 : h - '0');
                }
                put_utf8(&b, cp);
                break;
            }
            default: sb_add(&b, &c, 1); break;
            }
        }
    }
    if (*j->p != '"') {
        j->err = "unterminated string";
        return b.s;
    }
    j->p++;
    return b.s;
}

static JVal *jval(JP *j)
{
    ws(j);
    if (j->err) return NULL;
    char c = *j->p;
    if (c == '{') {
        JVal *v = jnew(J_OBJ);
        VEC(JVal *) items = {0};
        VEC(char *) keys = {0};
        j->p++;
        ws(j);
        if (*j->p == '}') {
            j->p++;
            return v;
        }
        for (;;) {
            ws(j);
            if (*j->p != '"') {
                j->err = "expected key";
                return v;
            }
            char *k = jstr(j);
            ws(j);
            if (*j->p != ':') {
                j->err = "expected ':'";
                return v;
            }
            j->p++;
            JVal *x = jval(j);
            if (j->err) return v;
            VPUSH(keys, k);
            VPUSH(items, x);
            ws(j);
            if (*j->p == ',') {
                j->p++;
                continue;
            }
            if (*j->p == '}') {
                j->p++;
                break;
            }
            j->err = "expected ',' or '}'";
            return v;
        }
        v->items = items.v;
        v->keys = keys.v;
        v->n = items.n;
        return v;
    }
    if (c == '[') {
        JVal *v = jnew(J_ARR);
        VEC(JVal *) items = {0};
        j->p++;
        ws(j);
        if (*j->p == ']') {
            j->p++;
            return v;
        }
        for (;;) {
            JVal *x = jval(j);
            if (j->err) return v;
            VPUSH(items, x);
            ws(j);
            if (*j->p == ',') {
                j->p++;
                continue;
            }
            if (*j->p == ']') {
                j->p++;
                break;
            }
            j->err = "expected ',' or ']'";
            return v;
        }
        v->items = items.v;
        v->n = items.n;
        return v;
    }
    if (c == '"') {
        JVal *v = jnew(J_STR);
        v->str = jstr(j);
        return v;
    }
    if (c == 't' && strncmp(j->p, "true", 4) == 0) {
        j->p += 4;
        JVal *v = jnew(J_BOOL);
        v->num = 1;
        return v;
    }
    if (c == 'f' && strncmp(j->p, "false", 5) == 0) {
        j->p += 5;
        return jnew(J_BOOL);
    }
    if (c == 'n' && strncmp(j->p, "null", 4) == 0) {
        j->p += 4;
        return jnew(J_NULL);
    }
    if (c == '-' || (c >= '0' && c <= '9')) {
        char *end;
        JVal *v = jnew(J_NUM);
        v->num = strtod(j->p, &end);
        j->p = end;
        return v;
    }
    j->err = "unexpected character";
    return NULL;
}

JVal *json_parse(const char *text, char *err, int errlen)
{
    JP j = {text, NULL};
    JVal *v = jval(&j);
    if (j.err) {
        snprintf(err, (size_t)errlen, "%s at offset %lld", j.err, (long long)(j.p - text));
        return NULL;
    }
    return v;
}

JVal *json_get(const JVal *obj, const char *key)
{
    if (!obj || obj->type != J_OBJ) return NULL;
    for (int i = 0; i < obj->n; i++)
        if (strcmp(obj->keys[i], key) == 0) return obj->items[i];
    return NULL;
}

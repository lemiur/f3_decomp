/* json.h - minimal JSON reader (enough for build/units.json). */
#ifndef F3RULES_JSON_H
#define F3RULES_JSON_H

enum { J_NULL, J_BOOL, J_NUM, J_STR, J_ARR, J_OBJ };

typedef struct JVal JVal;
struct JVal {
    int type;
    double num;
    char *str;      /* J_STR */
    JVal **items;   /* J_ARR / J_OBJ values */
    char **keys;    /* J_OBJ keys */
    int n;
};

JVal *json_parse(const char *text, char *err, int errlen);
JVal *json_get(const JVal *obj, const char *key);

#endif

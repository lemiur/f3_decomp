/* parse.h - finds every function definition in a C/C++ file (scope-aware brace matching over the taken #if
   branches) and the file-scope initializer and declaration statements. */
#ifndef F3PRUNE_PARSE_H
#define F3PRUNE_PARSE_H
#include "lexp.h"

enum { SK_TOP = 0, SK_NS, SK_EXTC, SK_CLASS, SK_FUNC, SK_BLOCK, SK_INIT };

enum {
    DB_OK = 0,
    DB_DIRECTIVE,  /* a preprocessor line or an untaken #if branch inside the definition or its head */
    DB_PREFIX,     /* unexpected tokens before the name (a macro invocation, a function-like macro) */
    DB_LINESTART,  /* the head does not start its line */
    DB_LINEEND,    /* something follows the closing brace on its line */
    DB_TRY,        /* function-try-block */
};

typedef struct {
    int head, name, lbrace, rbrace, endtok; /* endtok: rbrace or a ';' right after it */
    int body_from;                          /* first token of the ctor-initializer or the lbrace */
    int first_line, last_line;
    int parent;                             /* SK_* of the enclosing scope */
    int depth;                              /* number of enclosing scopes */
    int is_template, is_dtor, is_operator, is_inline;
    int bad;
    char name_s[160];
} Def;

/* a file-scope statement ending in ';' (declaration, prototype, extern, typedef, class definition) */
typedef struct {
    int first, last;  /* token range, last is the ';' */
    int parent;       /* SK_* of the enclosing scope */
    int has_eq;       /* an initializer at depth 0 */
    int eq;           /* token of the '=' */
    int class_body;   /* the statement holds a class/struct/union body: lbrace token, else -1 */
    int class_rbrace;
    int dir;          /* a directive or untaken branch inside */
} Stmt;

typedef struct {
    Def *defs;
    int ndefs;
    Stmt *stmts;
    int nstmts;
    int unbalanced;
} Parsed;

void parse_file(const PLex *L, Parsed *P);
void parsed_free(Parsed *P);

#endif

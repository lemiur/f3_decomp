/* lex.h - C/C++ tokenizer for f3rules: tokens with lines, comments, preprocessor directives, #if 0 regions. */
#ifndef F3RULES_LEX_H
#define F3RULES_LEX_H

enum { T_IDENT = 1, T_NUM, T_STR, T_CHR, T_PUNCT };

typedef struct {
    int type;
    int line;
    int off, len;
    int cond; /* index into Lexed.conds: the #if branch the token sits in (0 = none) */
} Tok;

typedef struct {
    int line, end_line;
    int off, len;
} Comment;

typedef struct {
    int parent, group, branch;
} CondNode;

typedef struct {
    char *text;
    int size;
    int *line_off; /* line_off[k] = offset where line k+1 starts */
    int nlines;
    Tok *toks;
    int ntoks;
    Comment *coms;
    int ncoms;
    CondNode *conds;
    int nconds;
    int *if0_lines; /* lines of "#if 0" / "#elif 0" */
    int nif0;
    char **includes; /* "#include" targets: first char '"' or '<' then the name */
    int nincludes;
} Lexed;

int lex_file(const char *path, Lexed *L);
void lex_free(Lexed *L);

/* helpers */
int tk_eq(const Lexed *L, int i, const char *s);
const char *tk_ptr(const Lexed *L, int i);
/* copies line text (1-based), trimmed, at most cap-1 chars */
void line_text(const Lexed *L, int line, char *buf, int cap);
const char *line_start(const Lexed *L, int line, int *len);
/* nonzero when two #if branch nodes are mutually exclusive */
int cond_exclusive(const Lexed *L, int a, int b);

#endif

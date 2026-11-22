/* lexp.h - tokenizer for f3prune: every token keeps its offset and line; preprocessor directives are tokens of
   their own (T_DIR) so a definition that spans one can be refused; each token records whether the branch it sits in
   is the one taken (first branch whose condition is not a literal 0). Comments are recorded per line. */
#ifndef F3PRUNE_LEXP_H
#define F3PRUNE_LEXP_H

enum { P_IDENT = 1, P_NUM, P_STR, P_CHR, P_PUNCT, P_DIR };

typedef struct {
    int type;
    int line, end_line; /* end_line differs from line only for directives with continuations */
    int off, len;
    int taken;          /* 1 when every enclosing #if branch is the one taken */
} PTok;

typedef struct {
    char *text;
    int size;
    int *line_off;      /* line_off[k] = offset where line k+1 starts; line_off[nlines] = size */
    int nlines;
    PTok *toks;
    int ntoks;
    unsigned char *line_code;    /* [line] 1 when the line has a token (directives included) */
    unsigned char *line_comment; /* [line] 1 when the line has (part of) a comment */
    int cond_unbalanced;
} PLex;

int plex_file(const char *path, PLex *L);
void plex_free(PLex *L);
int ptk_eq(const PLex *L, int i, const char *s);
int line_blank(const PLex *L, int line);

#endif

/* coff.h - read an i386 COFF object built with /Z7: functions (CodeView C13 procs and line tables) and the
   relocations inside each function's code. */
#ifndef F3RULES_COFF_H
#define F3RULES_COFF_H
#include <stdint.h>

typedef struct {
    char *name;          /* decorated name of the function's COFF symbol */
    char *file;          /* source file of its first line entry, as recorded in the object; NULL without lines */
    int min_line;        /* smallest and largest line of the entries in that file */
    int max_line;
    int first_line;      /* line of the entry at the lowest code offset */
    uint32_t code_size;  /* from S_*PROC32, else the COMDAT section size */
    char **refs;         /* names of symbols relocated from inside its code */
    int nrefs;
    int sect;            /* internal: section number and offset of the code */
    uint32_t start;
} ObjFunc;

typedef struct {
    ObjFunc *funcs;
    int n;
} ObjInfo;

/* Returns 0 on success; on failure writes a message to err. */
int coff_read(const char *path, ObjInfo *out, char *err, int errlen);
void coff_free(ObjInfo *o);

#endif

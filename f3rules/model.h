/* model.h - data shared by the f3rules passes. */
#ifndef F3RULES_MODEL_H
#define F3RULES_MODEL_H
#include "util.h"
#include "lex.h"

/* ---- source files under src/ and include/ ---- */
typedef struct {
    char *rel;     /* repo-relative path with forward slashes, original case */
    char *abs;     /* absolute path */
    char *dir_key; /* lowercase repo-relative directory, with trailing '/' (or "") */
    int is_header; /* .h/.hpp/.inl */
    int is_cpp;    /* .c/.cpp/.cxx/.cc */
    int under_src;
    char *module;  /* "src/<dir>/" or "src/" or "include/" */
} SrcFile;

/* ---- per-file index (pass 2) ---- */
typedef struct {
    char *key;  /* qualified name, e.g. "NS::Foo" */
    char *name; /* unqualified name */
    int line;
    int cond;
    uint64_t hash;
} TypeDef;

typedef struct {
    char *cls;
    char *name;
    int line;
} VirtDecl;

typedef struct {
    char *name;
    char *cls; /* qualified class for a member, NULL at namespace scope */
    int line;
    int noted; /* has a "// volatile: <evidence>" note */
} VolDecl;

typedef struct {
    char *name;
    int line;
} ExternDecl;

typedef struct {
    VEC(TypeDef) types;
    VEC(VirtDecl) virts;
    VEC(VolDecl) vols;
    VEC(ExternDecl) externs;
    char **includes;
    int nincludes;
    int conds_n;
    CondNode *conds; /* kept for cond_exclusive on type defs */
    int ok;
} FileIdx;

/* ---- recipe ---- */
enum { ST_UNLOCATED = 0, ST_MATCHED, ST_PENDING };
enum { UL_NONE = 0, UL_COMPILE, UL_NOSYM, UL_NOLINES, UL_EXTERNAL };

typedef struct {
    char *symbol;
    char **aliases;
    int naliases;
    uint32_t addr;
    int size;
    int unit;
    /* location */
    int file;      /* SrcFile index or -1 */
    char *extfile; /* file outside the repo */
    int min_line, max_line, first_entry;
    int unloc;
    /* results of pass 3 */
    int sig_line, last_line;
    int status;
    char match_rules[64];
    char adv_rules[64];
} Func;

typedef struct {
    char *name;
    int file;      /* SrcFile index, -1 outside the repo or without lines */
    char *extfile; /* recorded path when outside the repo */
    int has_lines;
    int min_line, max_line, first_line;
    uint32_t size;
    int is_recipe;
    int ref_by_checked;
} UnitObjFunc;

typedef struct {
    char *source;
    char **flags;
    int nflags;
    int f0, nf; /* range in g_funcs */
    int src_file;
    int compile_ok;
    char compile_err[256];
    UnitObjFunc *objf;
    int nobjf;
    unsigned char *closure; /* bitset over g_files: files reachable by #include from the source */
} Unit;

typedef struct {
    int func;
    int line;
    char rule[8];
    int kind; /* 0 match, 1 advisory, 2 exception */
    char *excerpt;
} Finding;

extern SrcFile *g_files;
extern int g_nfiles;
extern StrMap g_file_by_key; /* lowercase rel path -> index+1 */
extern Func *g_funcs;
extern int g_nfuncs;
extern Unit *g_units;
extern int g_nunits;
extern FileIdx *g_fidx;
extern char g_repo[MAX_PATH];

/* global indexes built after pass 2 */
typedef struct {
    int file, line, cond;
    uint64_t hash;
} TDRef;
typedef VEC(TDRef) TDVec;
typedef struct {
    char *key;
    int conflicted; /* defined in 2+ files with different bodies, or twice in one file */
    TDVec defs;
} R1Key;
typedef VEC(R1Key *) R1KeyVec;
extern StrMap g_r1_keys;       /* qualified type name -> R1Key* (every namespace-level definition) */
extern StrMap g_r1_names;      /* unqualified name -> R1KeyVec* of its conflicted keys */
extern StrMap g_virt_by_class; /* qualified class -> VEC of (file,name) */
extern StrMap g_virt_names;    /* placeholder virtual name -> files declaring it */
extern StrMap g_vol_globals;   /* namespace-scope volatile name -> (file, line) pairs (decls without a note) */
extern StrMap g_vol_members;   /* "<qualified class>\x01<member>" -> files (decls without a note) */

typedef VEC(int) IntVec;

int file_lookup_rel(const char *rel_lower);
void index_file(int fid);                     /* pass 2 */
void build_global_indexes(void);
void build_closures(void);
typedef VEC(Finding) FindingVec;
void check_file(int fid, int *funcs, int nfuncs, FindingVec *out); /* pass 3 */
int is_placeholder_virtual(const char *s, int n);
int fidx_cond_exclusive(const FileIdx *fi, int a, int b);
extern volatile LONG g_diag_r1_shared_only;
int r7_placeholder(const char *s, int n);
int signature_line(const Lexed *L, const char *sym, int start);
extern volatile LONG g_diag_no_sig, g_diag_no_body, g_diag_past_brace;

#define BIT_GET(bs, i) (((bs)[(i) >> 3] >> ((i)&7)) & 1)
#define BIT_SET(bs, i) ((bs)[(i) >> 3] |= (unsigned char)(1 << ((i)&7)))

#endif

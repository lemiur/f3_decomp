#include "f3_common.h"
// src/gamebryo2.2/corelibs/niparticle/nipsysinitialrotspeedctlr.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsysinitialrotspeedctlr.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_012026e0;

void* __cdecl FUN_00a7d330(const void*);
extern void* g_012026e0;
struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct NiPSysInitialRotSpeedCtlr
{
    void __thiscall FUN_00c32f60(StrArr*);
    void __thiscall AppendString(StrArr* pkStrings);
};

extern "C" void* __cdecl FUN_00aa13e0(unsigned int);
extern char DAT_010bedbc[];

struct CtorBase_cls
{
    void ctorBase();
};

struct FUN_00c29fb0_cls
{
    void* m_vtbl;
    unsigned int unk04;
    unsigned int unk08;
    void FUN_00c32de0(void* obj, unsigned int a1);
    void* FUN_00c29fb0(unsigned int a1);
};

// Allocates a 0x40-byte object, runs its base constructor, sets its vtable, passes it to FUN_00c32de0 with a1, and returns it.
// @fnv 0x00c29fb0
void* FUN_00c29fb0_cls::FUN_00c29fb0(unsigned int a1)
{
    FUN_00c29fb0_cls* p = (FUN_00c29fb0_cls*)FUN_00aa13e0(0x40);
    if (p != 0)
    {
        ((CtorBase_cls*)p)->ctorBase();
        p->m_vtbl = (void*)&DAT_010bedbc;
    }
    else
    {
        p = 0;
    }
    this->FUN_00c32de0(p, a1);
    return p;
}

#include "f3_common.h"
// src/havok/physics/utilities/charactercontrol/statemachine/hkpcharacterstatemanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/charactercontrol/statemachine/hkpcharacterstatemanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkReferencedObject
{
    void RetainReference();
    void removeReference();
};

struct hkpCharacterStateManager
{
    int m_auiShapeKeys[2];
    hkReferencedObject* m_states[32];
    void FUN_00cbc4e0(hkReferencedObject* object, int index);
};

extern int DAT_010c9194;
extern int _DAT_0102e388;

struct DDCC60World
{
    void removeReference();
};

struct FUN_00cbc4a0
{
    int* m_ppVirtualMethodTable;
    int m_auiShapeKeys;
    hkReferencedObject* m_states[11];

    ~FUN_00cbc4a0();
};

// @f3 0x0098bbd0 (community match, verified in this file)
class hkBaseObject
{
  public:
    virtual ~hkBaseObject() {}
};

class FUN_00cd1e70
{
  public:
    virtual ~FUN_00cd1e70() {}
};

FUN_00cbc4a0::~FUN_00cbc4a0()
{
    *(int**)((char*)this + 0x00) = (int*)0xe7dabc;
    *(int**)((char*)this + 0x08) = (int*)0xe7dab0;
    *(int**)((char*)this + 0x0c) = (int*)0xe7daa0;

    for (int i = 3; i < 9; ++i)
    {
        hkReferencedObject* pState = m_states[i];
        if (pState)
        {
            pState->removeReference();
            m_states[i] = 0;
        }
    }

    *(int**)((char*)this + 0x0c) = (int*)0xe7a1a0;
    ((FUN_00cd1e70*)((char*)this + 0x08))->FUN_00cd1e70::~FUN_00cd1e70();
    ((hkBaseObject*)((char*)this + 0x00))->hkBaseObject::~hkBaseObject();
}


struct hkpCharacterStateView
{
    int m_auiShapeKeys[2];
    hkReferencedObject* m_states[32];
    hkReferencedObject* FUN_00cbc510(int index);
};

// @fnv 0x00cbc510
hkReferencedObject* hkpCharacterStateView::FUN_00cbc510(int index)
{
    return m_states[index];
}

struct FnvCpu_FUN_00cbc520_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00cbc520_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00cbc520_CpuAllocator* allocator;
};
FnvCpu_FUN_00cbc520_CpuAllocatorHolder* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00cbc520_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00cbc4a0();
    FnvCpu_FUN_00cbc520_CpuObject* FUN_00cbc520(unsigned int flags);
};

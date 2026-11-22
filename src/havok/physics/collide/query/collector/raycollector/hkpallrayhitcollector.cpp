#include "f3_common.h"
// src/havok/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl FUN_00c852c0(void* owner, int a2, int a3, int a4);

class FUN_00c855f0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_10;
    int m_14;

    void FUN_00c855f0();
};

// If m_14 exceeds 1, calls FUN_00c852c0 on m_10 with 0 and m_14 - 1.
// @fnv 0x00c855f0
void FUN_00c855f0_cls::FUN_00c855f0()
{
    union
    {
        volatile unsigned char b;
        int i;
    } flag;
    flag.b = 0;
    if (m_14 > 1)
    {
        FUN_00c852c0(m_10, 0, m_14 - 1, flag.i);
    }
}

#include <xmmintrin.h>
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
    virtual void v0c();
    virtual void FreeArray(void* apMemory, int aiSize);
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(AudioAllocator* apAllocator, void* apContainer, unsigned int auiElemSize);
void __cdecl CollectValuesReversed(void* apDst, unsigned int auiSize, void* apOwner);

struct ChainNode
{
    int unk00;
    int unk04;
    int unk08;
    ChainNode* m_pNext;
};

struct ChainOwner
{
    int unk00;
    int unk04;
    int unk08;
    ChainNode* m_pHead;
};

struct SourceEntry
{
    __m128 m_v0;
    float m_f10;
    int m_i14;
    int m_i18;
    int m_i1C;
};

struct SpawnedEntry
{
    __m128 m_v0;
    float m_f10;
    int m_i14;
    int m_i18;
    int m_i1C;
    int m_i20;
    int m_i24;
    int m_i28;
    int m_i2C;
    int m_i30;
    int m_i34;
    int m_i38;
    int m_i3C;
    int m_i40;
    int m_i44;
    int m_i48;
    int m_i4C;
    ChainNode* m_pReferencedNode;
    int m_i54;
    int m_i58;
    int m_i5C;
};

struct EntryListNode
{
    SpawnedEntry* m_pData;
    unsigned int m_uCount;
    unsigned int m_uCapFlags;
};

struct FUN_00c85520_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    EntryListNode m_kNode;

    void AddEntry(ChainOwner* apOwner, SourceEntry* apSource);
};

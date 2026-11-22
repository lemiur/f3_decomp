#include "f3_common.h"
// src/havok/common/base/memory/allocator/freelist/systemmemoryblockserver/hksystemmemoryblockserver.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/freelist/systemmemoryblockserver/hksystemmemoryblockserver.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d60480
{
    int __thiscall GetValueAsInteger();
};

struct hkSystemMemoryBlockServer
{
    unsigned int GetBlockSize(unsigned int size);
};

struct FUN_00d60460_Block
{
// @fnv 0x00d60460
    virtual void FUN_00d60460_dummy1()
    {}
    virtual void FUN_00d60460_dummy2()
    {}
    virtual void free(void*, int)
    {}
};

struct FUN_00d60460_Class
{
    int m_auiShapeKeys[2];
    int m_uiBufferCapacity;
    int m_pAuxiliaryObject;
    FUN_00d60460_Block* m_block;

    void FUN_00d60460(void*, int);
};

struct FUN_00d604e0_inner
{
    virtual void v00();
    virtual void Tail(int a);
};

struct FUN_00d604e0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00d604e0_inner* m_pInner;
    void FUN_00d604e0(int a);
};

struct SpawnedTarget
{
    virtual void vSlot00();
    virtual void vSlot04();
    virtual void Forward(int a);
};

struct FUN_00d604f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    SpawnedTarget* m_10;
    void FUN_00d604f0(int a);
};

// FUN_00d60530: stdcall, 5 stack params, clears one byte through the first param.
// Original: mov eax,[esp+4]; mov byte ptr [eax],0; ret 0x14

class hkStreamReaderD604
{
  public:
    virtual void V0();
    virtual int read(int iNumBytes);
};

class hkObjD604
{
  public:
    int unk00;
    int unk04;
    unsigned int m_pos;
    unsigned int m_pFreeList;
    hkStreamReaderD604* m_pStreamReader;

    int ReadBytes(int iNumBytes, int* piOut);
};

struct FUN_00d60490_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int FUN_00d60490();
};

// @fnv 0x00d60490
int FUN_00d60490_cls::FUN_00d60490()
{
    return unk0C;
}

namespace fnv_00d604a0 {
struct hkBoolD604
{
    char m_cBooleanValue;
    hkBoolD604()
    {}
    hkBoolD604(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct hkObjD604
{
    int unk00;
    int unk04;
    unsigned int m_pRayCursor;
    unsigned int m_iElementCount;

    hkBoolD604 FUN_00d604a0(unsigned int n);
};

}  // namespace fnv_00d604a0

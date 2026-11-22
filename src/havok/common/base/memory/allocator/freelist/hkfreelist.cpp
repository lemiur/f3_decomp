#include "f3_common.h"
// src/havok/common/base/memory/allocator/freelist/hkfreelist.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/freelist/hkfreelist.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkFreeListNode
{
    hkFreeListNode* next;
    int a;
    int b;
    int size;
};

struct PointerChainNode
{
    void* m_data;
    void* m_kBlocks;
    void* m_next;
    void* m_pSecondNode;
    void* m_pFreeBlocks;
    void* m_field5;
    void* m_field6;
    void* m_field7;
    void AttachPointer(void*);
    void FUN_00dd7360();
};

namespace fnv_00dd7510 {
struct PointerChainNode
{
    void FUN_00dd7200();
    void FUN_00dd74b0(int, int, int, int);
    void FUN_00dd7510(int a, int b, int c, int d);
};

}  // namespace fnv_00dd7510

struct hkFreeListAllocator
{
    virtual void unused1()
    {}
    virtual void unused2()
    {}
    virtual void freeBlock(hkFreeListNode* node)
    {
        (void)node;
    }
};

struct hkFreeListStandin
{
    void* m_data;
    void* m_kBlocks;
    void* m_next;
    unsigned char m_ucUnknownByte[0x1c];
    int m_field8;
    int m_field9;
    hkFreeListAllocator* m_pThreadAllocator;

    int FreeBlocks(hkFreeListNode* node);
};

struct FUN_00dd7200_hkFreeList : PointerChainNode
{
    void FUN_00dd7200();
};

// @f3 0x00ba1250 (community match, verified in this file)
struct FreeReceiver {
    void FUN_0086ba60(void* memory);
};
extern FreeReceiver DAT_01090a78;
void FUN_00dd7200_hkFreeList::FUN_00dd7200() {
    DAT_01090a78.FUN_0086ba60(m_next);
    m_next = 0;
    DAT_01090a78.FUN_0086ba60(m_pFreeBlocks);
    m_pFreeBlocks = 0;
    m_data = 0;
    m_field5 = 0;
    m_field6 = 0;
}


struct hkFreeListStandIn
{
    void* m_data;
    void* m_kBlocks;
    void* m_next;
    void* m_pSecondNode;
    void* m_pFreeBlocks;
    void* m_field5;
    void* m_field6;
    void* m_field7;
    unsigned int m_field8;
    unsigned int m_field9;

    unsigned int FUN_00dd7240();
};

namespace fnv_00dd73f0 {
struct hkFreeListStandIn
{
    void* m_data;
    void* m_kBlocks;
    void* m_next;
    hkFreeListNode* m_pSecondNode;
    hkFreeListNode* m_pFreeBlocks;
    void* m_field5;
    void* m_field6;
    void* m_field7;
    void* m_field8;
    void* m_field9;
    int m_field10;
    int m_field11;

    void ResetFreeList();
};

}  // namespace fnv_00dd73f0

struct hkFreeListFUN_00dd7480 : PointerChainNode
{
    void CollectFreeNodes(hkFreeListNode** blocks, int unused);
};

struct FreeNode
{
    FreeNode* next;
};
struct FreeBlock
{
    FreeBlock* next;
    unsigned int unk04;
    unsigned int m_pRayStart;
    unsigned int m_uiItemCount;
};
struct HavokBool
{
    unsigned char value;
    HavokBool(bool v) : value(v)
    {}
    operator bool() const
    {
        return value != 0;
    }
};
struct FreeAllocator
{
    virtual void unknown00();
    virtual void unknown04();
    virtual void unknown08();
    virtual HavokBool TestBlock(FreeBlock* block);
};
struct FreeListCheck
{
    FreeNode* m_freeHead;
    unsigned int m_iFirstIndex;
    unsigned int unk08;
    FreeBlock* m_kBlocks;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_alignment;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    FreeAllocator* m_pThreadAllocator;
    bool* ValidateFreeList(bool* result);
};

struct hkNodeDD72
{
    hkNodeDD72* m_next;
    int m_iElementCount;
};

class hkCounterDD72
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual int count(hkNodeDD72* pNode, int iSize);
};

class hkObjDD72
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkCounterDD72* m_iFirstInteger;

    int SumNodeCounts(hkNodeDD72* pNode);
};

// Walks the linked list from pNode and sums the counter's count for each node, returning the total.
// @f3 0x0050a800 (community match, verified in this file)
namespace f3m_0050a800 {
void __cdecl FUN_00454890(unsigned int tag, int value);

struct hkItem50a800 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct hkListNode50a800 {
    hkItem50a800* item;
    hkListNode50a800* next;
};

struct Shader447 {
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    hkListNode50a800 list18;

    void FUN_00b874f0();
    bool InitPasses();
    bool FUN_0050a800();
};

bool Shader447::FUN_0050a800()
{
    FUN_00b874f0();
    hkListNode50a800* node = &list18;
    while (node) {
        if (node->next == 0 && node->item == 0)
            break;
        FUN_00454890(0x4d414e4c, node->item->unk0C);
        node = node->next;
    }
    return InitPasses();
}
}   // namespace f3m_0050a800


class hkBoolDD72
{
  public:
    hkBoolDD72(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    hkBoolDD72(const hkBoolDD72& o)
    {
        m_cBooleanValue = o.m_cBooleanValue;
    }
    char m_cBooleanValue;
};

typedef void(__cdecl* hkMemoryWalkCallbackDD72)(void* start, int size, hkBoolDD72 allocated, int pool, void* param);

struct hkBlockDD72
{
    hkBlockDD72* m_next;
    int unk04;
    char* m_kRayStart;
    int m_iCapacity;
};

class hkFreeListDD72
{
  public:
    int unk00;
    int m_iFirstIndex;

    void WalkFreeBlocks(hkBlockDD72* block, hkMemoryWalkCallbackDD72 callback, int pool, void* param);
};

struct hkFreeListCallsDD75
{
    static unsigned int __cdecl FUN_00dd73d0(unsigned int uiSize, unsigned int uiAlign);
};

struct hkMemoryAllocatorDD75
{
    virtual void V0();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void V2();
    virtual void V3();
    virtual int GetUsableSize(const void* pObj, int iNumBytes);
};

struct hkFreeListBlockDD75
{
    hkFreeListBlockDD75* m_pkNext;
    int m_iBlockSize;
    char* m_pcStart;
    unsigned int m_uiNumElements;
};

struct hkFreeListDD75
{
    void* m_pkFree;
    unsigned int m_uiFreeCount;
    int m_iUnk08;
    hkFreeListBlockDD75* m_pkActiveBlocks;
    hkFreeListBlockDD75* m_pkFreeBlocks;
    unsigned int m_uiIndexCapacity;
    unsigned int m_uiAlign;
    unsigned int m_uiMaxBlockSize;
    char* m_pcTop;
    char* m_pcBlockEnd;
    int m_iNumFreeElements;
    int m_iTotalNumElements;
    hkMemoryAllocatorDD75* m_pkBlockAllocator;
    void* AllocateElement();
};

struct hkStackDD7B
{
    char* m_pcCur;
};
extern "C" hkStackDD7B* __cdecl FUN_00c85750();

bool __cdecl CompareLessThan(const hkFreeListNode* pkA, const hkFreeListNode* pkB);
void __cdecl FUN_00dd7d00(hkFreeListNode** ppArray, int iLow, int iHigh,
                          bool(__cdecl* pfnLess)(const hkFreeListNode*, const hkFreeListNode*));

struct hkBlockDD7B
{
    int m_iUnk00;
    int m_iUnk04;
    char* m_pcStart;
    int m_iNumElements;
};

struct hkFreeListDD7B
{
    hkFreeListNode* m_pkFree;
    unsigned int m_uiFreeCount;
    char m_acUnk08[0x18];
    char* m_pcTop;
    char* m_pcBlockEnd;
    int FUN_00dd7b40(hkBlockDD7B* pkBlock);
};

struct hkBoolDD7C
{
    char m_cBooleanValue;
    hkBoolDD7C(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};

struct hkFreeListBlockDD7C
{
    hkFreeListBlockDD7C* m_next;
};

class hkFreeListDD7C
{
  public:
    int unk00;
    int unk04;
    hkFreeListBlockDD7C* m_incrementalBlock;
    hkFreeListBlockDD7C* m_kBlocks;
    hkFreeListBlockDD7C* m_pFreeBlocks;

    int FUN_00dd7b40(hkFreeListBlockDD7C* pkBlock) throw();
    hkBoolDD7C FUN_00dd7c40(int m_iFreeBlockCount, int& iNumBlocksOut) throw();
};

struct B60Link
{
    int unk00;
    int unk04;
};

struct B60Large
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct B60State
{
    int current;
    int link;
    int limit;
};

struct B60Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA4;

    void AdvanceState(unsigned char* result, B60State* state);
};

struct hkBlockDD73
{
    hkBlockDD73* m_next;
    unsigned int m_key;
    int unk08;
    int m_iElementCount;
};

class hkBlockAllocDD73
{
  public:
    virtual ~hkBlockAllocDD73();
    virtual void* alloc(int n);
    virtual void free(hkBlockDD73* block);
};

class hkBlockListDD73
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkBlockDD73* m_pFirstNode;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_totalSize;
    int m_usedSize;
    hkBlockAllocDD73* m_alloc;

    void FUN_00dd7380(unsigned int key);
};

struct Info_dd7430
{
    int m_iTotal;
    int m_iSpan;
    int unk08;
    int m_iStart;
    int m_iStartCopy;
    int m_iArrayCapacity;
};
struct FUN_00dd7430_cls
{
    int unk00;
    int m_iArrayCapacity;
    int unk08;
    int m_iB;
    int m_iA;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int m_iFirst;
    int m_iLast;
    int SumNodeCounts(int iValue);
    void FUN_00dd7430(Info_dd7430* pkInfo);
};

struct hkFreeListBlockAllocator
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void* AllocateBufferWithSize(int numBytes);
    virtual void ReturnMemory(void* p, int numBytes);
};

void __cdecl hkFreeList_quickSortRecursive(void** pArr, int d, int h, bool(__cdecl* cmpLess)(const void*, const void*));
bool __cdecl hkFreeList_comparePointers(const void* a, const void* b);

struct hkFreeListGC
{
    struct Element
    {
        Element* m_next;
    };

    struct Block
    {
        Block* m_next;
        int m_unk04;
        char* m_kRayStart;
        int m_iCapacity;
    };

    Element* m_free;
    unsigned int m_iFirstIndex;
    int m_iFreeCount;
    Block* m_kBlocks;
    Block* m_pFreeBlocks;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    char* m_fMinimumV;
    char* m_pSecondString;
    int m_unk28;
    int m_unk2C;
    hkFreeListBlockAllocator* m_blockAllocator;

    int Compact();
};

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

typedef void(__cdecl* hkMemoryWalkCallback)(void* start, unsigned int size, hkBool allocated, int pool, void* param);

struct hkFreeListBlockServer
{
    virtual ~hkFreeListBlockServer();
    virtual void* unk04();
    virtual void free(void* p);
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void* AllocateBufferWithSize(int numBytes);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct hkFreeListElement
{
    hkFreeListElement* m_next;
};

struct hkFreeListBlock
{
    hkFreeListBlock* m_next;
    unsigned int m_unk04;
    char* m_kRayStart;
    unsigned int m_iCapacity;
};

bool __cdecl CompareLessThan(void* a, void* b);
void __cdecl FUN_00dd7d00(void** arr, int lo, int hi, bool(__cdecl* cmpLess)(void*, void*));

struct hkFreeListWalker
{
    hkFreeListElement* m_free;
    unsigned int m_iFirstIndex;
    unsigned int m_unk08;
    hkFreeListBlock* m_activeBlocks;
    hkFreeListBlock* m_pFreeBlocks;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1c;
    char* m_fMinimumV;
    char* m_pSecondString;
    unsigned int m_unk28;
    unsigned int m_unk2c;
    hkFreeListBlockServer* m_blockServer;

    void WalkFreeBlocks(hkFreeListBlock* blocks, hkMemoryWalkCallback callback, int pool, void* param);
    void FUN_00dd78f0(hkMemoryWalkCallback callback, int pool, void* param);
};

namespace fnv_00dd74b0 {

struct S00dd74b0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;

    void FUN_00dd74b0(int a2, int a3, int a4, int a5);
};

}  // namespace fnv_00dd74b0

struct FreeListElementCounter : hkFreeListDD75
{
    int FUN_00dd72d0();
};

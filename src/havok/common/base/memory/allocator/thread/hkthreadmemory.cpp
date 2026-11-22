#include "f3_common.h"
// src/havok/common/base/memory/allocator/thread/hkthreadmemory.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/thread/hkthreadmemory.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d2c3a0_class
{
    void* m0;
    void* m4;
    void* m8;
    void FUN_00d2c3a0(void* a);
};

// @f3 0x006f48a0 (community match, verified in this file)
void FUN_00d2c3a0_class::FUN_00d2c3a0(void* a)
{
    unsigned char* p = this ? (unsigned char*)this->m8 : 0;
    p[0x5c] = (unsigned char)a;
}


struct SlowPath
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void process(int* output, int count, int value);
};
struct FUNClass
{
    virtual void unused();
    virtual unsigned int generate(int value);
    SlowPath* unk04;
    void FUN_00d2c030(int* output, int count, int value);
};

struct Helper
{
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual void h4();
    virtual void h5();
    virtual void h6();
    virtual void dispatch(unsigned int* values, int count, int threshold);
};
struct Owner
{
    virtual void v0();
    virtual void v1();
    virtual void check(unsigned int value, int threshold);
    Helper* helper;
    void ProcessValues(unsigned int* values, int count, int threshold);
};

struct ComponentValue
{
    int value;
    int unk04;
};

struct Target : FUN_00d2c3a0_class
{
    int unk0C;
    ComponentValue values[16];
    int terminal;
    volatile int weights[17];
    int ComputeWeightedSum();
};

struct Block
{
    Block* next;
};
struct Allocator
{
    virtual void v0();
    virtual void* Allocate(int size);
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void AllocateBatch(Block** output, int count, int size);
};
struct Cache
{
    Block* head;
    volatile int count;
};
struct CachedBlockAllocator
{
    void* owner;
    Allocator* allocator;
    int batchCount;
    Cache caches[17];
    int blockSizes[17];
    void* AllocateBlock(int index);
    __forceinline void* AllocateBatchCached(int index, int count)
    {
        Block* blocks[4];
        if (count >= 4)
            count = 4;
        allocator->AllocateBatch(blocks, count, blockSizes[index]);
        for (int i = 1; i < count; ++i)
        {
            Block* block = blocks[i];
            Block* previous = caches[index].head;
            ++caches[index].count;
            block->next = previous;
            caches[index].head = block;
        }
        return blocks[0];
    }
};

struct D2C520Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void AllocateFixedSizeBlocks(void** blocks, int numBlocks, int blockSize);
};

struct D2C520Block
{
    D2C520Block* m_next;
};

struct D2C520FreeList
{
    D2C520Block* m_pFirstNode;
    int m_iBlockCount;

    void* pop()
    {
        D2C520Block* block = m_pFirstNode;
        if (block)
        {
            m_iBlockCount--;
            m_pFirstNode = block->m_next;
            return block;
        }
        return 0;
    }
};

inline int D2C520Min2(int a, int b)
{
    return (a < b) ? a : b;
}

struct D2C520ThreadMemory
{
    int unk00;
    D2C520Allocator* m_pThreadAllocator;
    int unk08;
    D2C520FreeList m_kFreeListEntries[17];
    int m_iDofCount[17];

    void FUN_00d2c520(int rowIndex);
};

// @f3 0x008f6960 (community match, verified in this file)
struct TMAllocW130
{
    virtual void unk00();
    virtual void unk04();
    virtual void AllocateFixedSizeBlocks(void** blocks, int numBlocks, int blockSize);
};
struct TMW130
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    TMAllocW130* m_pThreadAllocator;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    D2C520FreeList m_kFreeListEntries[17];
    int m_iDofCount[17];
};

void D2C520ThreadMemory::FUN_00d2c520(int rowIndex)
{
    TMW130* self = reinterpret_cast<TMW130*>(this);
    int numElem = self->m_kFreeListEntries[rowIndex].m_iBlockCount;
    int blockSize = self->m_iDofCount[rowIndex];
    while (numElem > 0)
    {
        void* blocks[4];
        int batch = D2C520Min2(4, numElem);
        for (int i = 0; i < batch; i++)
            blocks[i] = self->m_kFreeListEntries[rowIndex].pop();
        numElem -= batch;
        self->m_pThreadAllocator->AllocateFixedSizeBlocks(blocks, batch, blockSize);
    }
}


namespace fnv_00d2c5a0 {
struct FreeNode
{
    FreeNode* next;
};
struct FreeBlock
{
    FreeNode* head;
    int count;
};
struct OverflowHandler
{
    virtual void f0();
    virtual FreeNode* f1(int);
};
struct Allocator : FUN_00d2c3a0_class
{
    FreeBlock blocks[25];
    int unkD4;
    signed char bucketForSmallSize[44];
    int bucketForLargeSize[8];
    FreeNode* FUN_00d2c5a0(int size);
};
// The target helper ignores EDX; this ABI-compatible signature keeps its this pointer in ECX and bucket on the stack.
extern "C" FreeNode* __fastcall AllocateBlock(Allocator* self, int unused, int bucket);
}  // namespace fnv_00d2c5a0

extern void FUN_00d2caa0(void* res, int a1, int n);

struct SelfCls
{
    virtual void vslot0();
    virtual void* vslot1(void* p);
    virtual void vslot2(int a, int b);

    void* FUN_00d2c6d0(int a1, int a2, FUN_00d2c3a0_class* a3);
};

struct FUN_00d2c7a0_Slot
{
    void* object;
    int unk04;
};

struct FUN_00d2c7a0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d2c7a0_Slot slots[17];
    void __thiscall FUN_00d2c520(int index);
    void __thiscall FUN_00d2c7a0();
};

// Iterates the 17 slots backwards and calls FUN_00d2c520 on each index whose slot holds an object.
// @f3 0x008f6d00 (community match, verified in this file)
struct SlotOrig
{
    void* object;
    int unk04;
};
struct SlotHolderOrig
{
    int pad00, pad04, pad08, pad0c, pad10, pad14, pad18, pad1c;
    int pad20, pad24, pad28, pad2c, pad30, pad34, pad38;
    SlotOrig slots[17];
    void FUN_008f6960(int index);
};

void FUN_00d2c7a0_class::FUN_00d2c7a0()
{
    SlotHolderOrig* self = (SlotHolderOrig*)this;
    int index = 16;
    SlotOrig* slot = self->slots + 16;
    while (index >= 0)
    {
        if (slot->object)
            self->FUN_008f6960(index);
        --index;
        --slot;
    }
}


struct FUN_00d60500
{
    virtual void placeholder();
    unsigned int capacity;
    unsigned int count;
    void* storage;
    void* owner;
    FUN_00d60500(void* parent, unsigned int requested);
};

class DispatchInterface
{
  public:
    virtual void Unknown0() = 0;
    virtual int Dispatch(void*) = 0;
    int DispatchValue(void* const& value);
};

struct FUN_00d2c020_class
{
    virtual void __fastcall slot00(unsigned int value);
    virtual void __fastcall slot04(unsigned int value);
    virtual void __fastcall slot08(unsigned int value);

    void __fastcall FUN_00d2c020(unsigned int value);
};

struct FnvCpu_FUN_00d2c0f0_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void slot24();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00d2c0f0_CpuOwner
{
    unsigned int unk00;
    FnvCpu_FUN_00d2c0f0_CpuInterface* target;
    void FUN_00d2c0f0(int arg0);
};

extern "C" void __debugbreak();

struct SizeClassTable
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
    int iClassSize[17];
    unsigned char ucSmallClass[41];
    int iLargeClass[8];

    void InitSizeClasses(void*, void*);
};

struct FUN_00d2c600_bucket
{
    void* m_pFirstNode;
    volatile int m_uiItemCount;
};

struct FUN_00d2c600_obj
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08(void* p, int size);
};

struct FUN_00d2c600_cls
{
    int unk00;
    FUN_00d2c600_obj* m_04;
    int m_08;

    void FUN_00d2c450(int index, void* p);
    void Free(void* p, int size);
};

struct FUN_00d2c670_inner
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void Forward(int a);
};

struct FUN_00d2c670_cls
{
    void* m_00;
    FUN_00d2c670_inner* m_04;

    void FUN_00d2c670(int a);
};

struct S_00d2c680_Inner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual int v2c(int a0, int a1);
};

struct S_00d2c680_Cls
{
    int unk00;
    S_00d2c680_Inner* unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int m_94[0x10];
    int unkd4;
    signed char m_d8[0x2c];
    int m_104[8];
    int FUN_00d2c680(int a0, int a1);
};

struct Allocator219
{
    virtual void v0();
    virtual void v1();
    virtual void v2(void* out, int blockSize);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(void** batch, int count, int blockSize);
};

struct Node219
{
    Node219* next;
};

struct CacheSlot219
{
    Node219* head;
    int count;
    inline Node219* Pop()
    {
        if (head)
        {
            Node219* p = head;
            --count;
            head = p->next;
            return p;
        }
        return 0;
    }
};

struct Owner219
{
    void* owner;
    Allocator219* allocator;
    int batchThreshold;
    CacheSlot219 caches[17];
    int blockSizes[17];

    void FUN_00d2c450(int index, Node219* out, void* p);
};
// Uses blockSizes[index] to release out directly when batchThreshold is zero; otherwise trims cache batches and pushes out onto its head.
// @f3 0x008f6890 (community match, verified in this file)
struct AllocSlots219
{
    virtual void s0();
    virtual void s1();
    virtual void s2(void** batch, int count, int blockSize);
    virtual void s3();
    virtual void s4(void* out, int blockSize, void* extra);
};

void Owner219::FUN_00d2c450(int aiSizeIndex, Node219* apBlock, void* p)
{
    int blockSize = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xc0)[aiSizeIndex];
    int threshold = *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x34);
    if (threshold == 0)
    {
        (*reinterpret_cast<AllocSlots219**>(reinterpret_cast<char*>(this) + 0x10))->s4(apBlock, blockSize, p);
        return;
    }
    CacheSlot219* slot = reinterpret_cast<CacheSlot219*>(reinterpret_cast<char*>(this) + 0x38) + aiSizeIndex;
    int count = slot->count;
    int half = threshold / 2;
    while (count > half)
    {
        int n = count - half <= 4 ? count - half : 4;
        Node219* batch[4];
        for (int i = 0; i < n; i++)
            batch[i] = slot->Pop();
        count -= n;
        (*reinterpret_cast<AllocSlots219**>(reinterpret_cast<char*>(this) + 0x10))->s2((void**)batch, n, blockSize);
    }
    Node219* head = reinterpret_cast<CacheSlot219*>(reinterpret_cast<char*>(this) + 0x38)[aiSizeIndex].head;
    reinterpret_cast<CacheSlot219*>(reinterpret_cast<char*>(this) + 0x38)[aiSizeIndex].count++;
    apBlock->next = head;
    reinterpret_cast<CacheSlot219*>(reinterpret_cast<char*>(this) + 0x38)[aiSizeIndex].head = apBlock;
}


extern "C" char DAT_010cacd0;

struct BlockEntry
{
    void* block;
    void* size;
};

struct ThreadMemoryBase
{
    void* m0;
    void* m4;
    void* m8;
    void FUN_00d2c3a0(void* a, void* b);
};

struct HKThreadMemory : ThreadMemoryBase
{
    BlockEntry blocks[17];
    int blockTable[17];
    unsigned char freeList[0x29];
    int bigBlocks[8];
    void InitSizeClasses();
    HKThreadMemory* FUN_00d2c720();
};

namespace fnv_00d2c760 {
extern "C" char DAT_010cacd0;

struct BlockEntry
{
    void* block;
    int count;
    BlockEntry() : block(0), count(0)
    {}
};

struct ThreadMemoryView : FUN_00d2c3a0_class
{
    BlockEntry blocks[17];
    int blockTable[17];
    unsigned char freeList[41];
    int bigBlocks[8];
    void InitSizeClasses();
    void FUN_00d2c3a0(void* allocator, int limit);
    ThreadMemoryView* FUN_00d2c760(void* allocator);
};

}  // namespace fnv_00d2c760

// @f3 0x008f6a50 (community match, verified in this file)
extern const void* DAT_00e33ea8;
namespace f3m_008f6a50 {
namespace n8f6a50 {
__forceinline int GetSizeClass8f(int aiSize)
{
    if (aiSize <= 0x8)
        return 1;
    if (aiSize <= 0x10)
        return 2;
    if (aiSize <= 0x20)
        return 3;
    if (aiSize <= 0x30)
        return 4;
    if (aiSize <= 0x40)
        return 5;
    if (aiSize <= 0x60)
        return 6;
    if (aiSize <= 0x80)
        return 7;
    if (aiSize <= 0xA0)
        return 8;
    if (aiSize <= 0xC0)
        return 9;
    if (aiSize <= 0x100)
        return 10;
    if (aiSize <= 0x140)
        return 11;
    if (aiSize <= 0x200)
        return 12;
    if (aiSize <= 0x400)
        return 13;
    if (aiSize <= 0x800)
        return 14;
    if (aiSize <= 0x1000)
        return 15;
    if (aiSize <= 0x2000)
        return 16;
    __debugbreak();
    return -1;
}
struct Source {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual bool IsUnlimited();
};
struct Bin {
    void* first;
    int count;
    Bin() : first(0), count(0) {}
};
struct State {
    void* current;
    void* previous;
    int base;
    void* end;
    State() : current(0), previous(0), base(-1), end(0) {}
};
class FUN_008f6a50 {
public:
    const void* vtable;
    int m4;
    int m8;
    int mc;
    Source* source;
    int m14;
    int m18;
    int m1c;
    State state;
    int m30;
    int limit;
    Bin bins[17];
    int classSize[17];
    unsigned char smallClass[0x201];
    int largeClass[8];
    FUN_008f6a50(Source* src, volatile int max);
};
FUN_008f6a50::FUN_008f6a50(Source* src, volatile int max)

    : vtable(&DAT_00e33ea8), m14(1)
{

    int v = src->IsUnlimited() ? 0 : max;
    source = src;
    if (v >= 0xfffffff)
        v = 0xfffffff;
    limit = v;
    for (int i = 0; i <= 0x200; ++i) {
        int c = GetSizeClass8f(i);
        smallClass[i] = (unsigned char)c;
        classSize[c] = i;
    }
    int i = 0x400;
    int* p = largeClass;
    for (; i < 0x2400; i += 0x400) {
        int c = GetSizeClass8f(i);
        *p = c;
        classSize[c] = i;
        ++p;
    }
}
}

}   // namespace f3m_008f6a50

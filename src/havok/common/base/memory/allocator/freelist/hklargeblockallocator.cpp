#include "f3_common.h"
// src/havok/common/base/memory/allocator/freelist/hklargeblockallocator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/allocator/freelist/hklargeblockallocator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00dd74b0_cls
{
    void FUN_00dd74b0(int a, int b, int c, int d);
    void* FUN_00dd7650(int a, int b, int c, int d);
};

struct hkReferencedObject
{
    void removeReference();
};
extern int DAT_0102e388;
extern int DAT_010d7c80;
struct hkLargeBlockAllocator
{
    int* m_p;
    int* m_q;
    hkReferencedObject* m_r;
    void FUN_00dd91f0();
};

struct DD7F10ListNode
{
    DD7F10ListNode* m_next;
    DD7F10ListNode* m_pSecondNode;
};

struct DD7F10Pool
{
    int unk00;
    int unk04;
    int m_numAllocated;
    int m_numFree;
    void** m_freeListPtr;
    void* m_kFreeListEntries;
    void* m_buckets[32];
    int unk98;
    void* m_freeHead;
    int m_blockShift;
    DD7F10ListNode m_kBlocks;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int m_totalBytes;
    int m_peakBytes;

    void FUN_00dd7f10();
};

struct WorkItem
{
    int unk00;
    WorkItem* next;
    int unk08;
    int value;
};

struct WorkProcessor
{
    virtual void first();
    virtual void second();
    virtual void third();
    virtual void fourth();
    virtual void process(WorkItem*, int);
};

struct QueueOwner
{
    int unk00;
    int unk04;
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
    int unk94;
    WorkProcessor* processor;
    int unk9c;
    int unka0;
    WorkItem sentinel;
    void ProcessAllItems();
    void FUN_00dd7f10();
};

struct TreeChunk
{
    unsigned int m_iWordAt00;
    unsigned int m_pFirstNode;
    int m_8, m_iThirdValue;
    TreeChunk* m_pChildAtom[2];
};

int __cdecl FUN_00dd7e00(unsigned int size);

struct FUN_00dd8350_Alloc
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int unk14;
    void* m_treeBins[32];

    unsigned int GetMaxChunkSize(void* tree, unsigned int size);
    unsigned int FUN_00dd8350();
};

struct DD89B0MemChunk
{
    unsigned int m_uiPreviousChunkSize;
    unsigned int head;

    unsigned int getChunkSize() const
    {
        return head & ~3u;
    }
    bool isPinuse() const
    {
        return (head & 1) != 0;
    }
    bool isCinuse() const
    {
        return (head & 2) != 0;
    }
    DD89B0MemChunk* chunkPlusOffset(unsigned int s)
    {
        return (DD89B0MemChunk*)((char*)this + s);
    }
    DD89B0MemChunk* chunkMinusOffset(unsigned int s)
    {
        return (DD89B0MemChunk*)((char*)this - s);
    }
    void setSizeAndPinuseOfFreeChunk(unsigned int s)
    {
        head = s | 1;
        chunkPlusOffset(s)->m_uiPreviousChunkSize = s;
    }
    void setFreeWithPinuse(unsigned int s, DD89B0MemChunk* n)
    {
        n->head &= ~1u;
        setSizeAndPinuseOfFreeChunk(s);
    }
};

struct DD89B0LargeBlockAllocator
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DD89B0MemChunk* m_fMinimumV;
    unsigned int m_uiChunkSize;
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
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    unsigned int m_uiBufferCapacity;
    int m_overhead;

    void _unlinkChunk(DD89B0MemChunk* p);
    void _insertChunk(DD89B0MemChunk* p, unsigned int size);
    void Free(void* mem);
};

typedef void(__cdecl* S_00dd8aa0_Callback)(void* start, unsigned int size, void* param);

struct S_00dd8aa0_Chunk
{
    unsigned int m_uiPreviousChunkSize;
    unsigned int head;
    S_00dd8aa0_Chunk* fd;
    S_00dd8aa0_Chunk* bk;
    unsigned int getChunkSize() const
    {
        return head & ~3u;
    }
    bool isInuse() const
    {
        return ((head >> 1) & 1) != 0;
    }
    void* getPayload()
    {
        return (void*)(this + 1);
    }
    unsigned int getPayloadSize() const
    {
        return getChunkSize() - sizeof(S_00dd8aa0_Chunk);
    }
    S_00dd8aa0_Chunk* nextChunk()
    {
        return (S_00dd8aa0_Chunk*)((char*)this + getChunkSize());
    }
};

struct S_00dd8aa0_Page
{
    S_00dd8aa0_Page* m_pSecondNode;
    S_00dd8aa0_Page* m_next;
    int unk8;
    int unkC;
    char* m_kRayStart;
    char* m_kRayEnd;
    S_00dd8aa0_Chunk* getFirstChunk()
    {
        return (S_00dd8aa0_Chunk*)m_kRayStart;
    }
    S_00dd8aa0_Chunk* getFooter()
    {
        return (S_00dd8aa0_Chunk*)(m_kRayEnd - sizeof(S_00dd8aa0_Chunk));
    }
};

struct S_00dd8aa0_Allocator
{
    void* m_vtbl;
    int unk4;
    int unk8;
    int unkC;
    S_00dd8aa0_Chunk* m_fMinimumV;
    unsigned int m_uiChunkSize;
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
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    S_00dd8aa0_Page m_kPage;
    void ForEachAllocatedBlock(S_00dd8aa0_Callback callback, void* param);
};

struct ListNode
{
    int unk00;
    ListNode* next;
    int unk08;
    int value;
};

extern int DAT_010d7c34;
extern int DAT_010d7c10;

struct ListTarget
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(ListNode* node, int value);
};

struct FUN_00dd7ec0_cls
{
    int* m_vptr;
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
    ListTarget* m_98;
    int unk9C;
    int unkA0;
    ListNode m_a4;
    void FUN_00dd7ec0();
};

struct tchunk
{
    int prev_foot;
    int head;
    tchunk* fd;
    tchunk* bk;
    tchunk* child[2];
    tchunk* parent;
    int index;
};

int __cdecl FUN_00dd7e00(int size);

struct TargetClass
{
    char pad00[8];
    unsigned int m_uiChunkCount;
    char pad0c[0xc];
    tchunk* m_apChunkLists[32];

    void InsertChunk(tchunk* x, int size);
};

struct FUN_00dd80d0_node
{
    unsigned int unk00;
    unsigned int unk04;
    FUN_00dd80d0_node* m_pSecondNode;  // +0x08
    FUN_00dd80d0_node* m_next;         // +0x0c
    FUN_00dd80d0_node* m_fMinimumU;    // +0x10
    FUN_00dd80d0_node* m_fMaximumU;    // +0x14
    FUN_00dd80d0_node* m_parent;       // +0x18
    unsigned int m_bin;                // +0x1c
};

struct FUN_00dd80d0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int m_freeMask;  // +0x08
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    FUN_00dd80d0_node* m_bins[32];  // +0x18
    void RemoveNode(FUN_00dd80d0_node* node);
};

struct FUN_00dd83a0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned char* m_10;
    unsigned int m_14;
    void FUN_00dd83a0();
};

struct hkBlockAllocator
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    char* m_next;
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
    int unk94;
    int unk98;
    int unk9c;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    void* AllocateBlock(int a);
};

struct FUN_00dd8480_cls
{
    int unk00;
    int unk04;
    int m_08;
    int unk0C;
    int unk10;
    unsigned int m_14;
    int AllocSlow(int a);
    int Allocate(int a);
};

int __stdcall ProbeSmall(int a);

// Tries ProbeSmall when m_08 is set, then AllocSlow if a+0x100 is below m_14, otherwise returns 0.
// @f3 0x00a7df80 (community match, verified in this file)
struct FUN_00dd8480_sub
{
    int FUN_009b10f0(int a, int b);
};
struct FUN_00dd8480_iface
{
    virtual int unk00();
    virtual int unk04();
    virtual int unk08();
    virtual int unk0C();
    virtual int unk10(int a);
};
int FUN_00dd8480_cls::Allocate(int aiSize)
{
    int r = ((FUN_00dd8480_sub*)((char*)this + 0x0c))->FUN_009b10f0(aiSize, 0);
    if (r != 0)
    {
        return r;
    }
    if (*(FUN_00dd8480_iface**)((char*)this + 0x1c) != (FUN_00dd8480_iface*)r)
    {
        return (*(FUN_00dd8480_iface**)((char*)this + 0x1c))->unk10(aiSize);
    }
    return 0;
}


struct hkMemoryAllocator
{
    virtual void* unk00() = 0;
    virtual void* allocate(unsigned int size) = 0;
};

struct hkMemoryManager
{
    virtual void* unk00() = 0;
    virtual void* unk04() = 0;
    virtual void* unk08() = 0;
    virtual void* unk0c() = 0;
    virtual void* unk10() = 0;
    virtual void* unk14() = 0;
    virtual void* unk18() = 0;
    virtual void* unk1c() = 0;
    virtual void* unk20() = 0;
    virtual void* allocate(unsigned int size) = 0;
};

struct FUN_00dd8700_cls : public hkMemoryAllocator
{
    int unk04;
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
    int unk94;
    hkMemoryManager* unk98;

    void* FUN_00dd8700(unsigned int size);
};

struct Heap
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
    virtual void V28(void* apBlock, unsigned int auiSize);
};

struct FUN_00dd8750_cls
{
    virtual void v00();
    virtual void v04();
    virtual void V08(void* apBlock);
    int unk04;
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
    int unk94;
    Heap* m_pHeap;

    void FUN_00dd8750(void* apBlock, unsigned int auiSize);
};

// @f3 0x00aae990 (community match, verified in this file)
namespace f3m_00aae990 {
struct Emitter_e990 {
    int unk00;
    int unk04;
    const char* name;
};
struct System_e990 {
    void FUN_00ab7320(Emitter_e990* emitter);
};
void FUN_00887da0(const char* fmt, ...);
}

void FUN_00dd8750_cls::FUN_00dd8750(void* apBlock, unsigned int auiSize)
{
    unsigned int index = (unsigned int)apBlock;
    f3m_00aae990::Emitter_e990* emitter = (f3m_00aae990::Emitter_e990*)auiSize;
    if (index < *(unsigned int*)((char*)this + 0xb0)) {
        int slot = (*(int**)((char*)this + 0xac))[index];
        if (slot != -1) {
            f3m_00aae990::System_e990* sys = (*(f3m_00aae990::System_e990***)((char*)this + 0xa0))[slot];
            if (sys) {
                sys->FUN_00ab7320(emitter);
                return;
            }
        }
    }
    f3m_00aae990::FUN_00887da0("DEFAULT: Trying to add an emitter (%s) to a master particle system (idx: %d) that hasn't been loaded.", emitter->name, index);
}


namespace fnv_00dd8790 {
struct FUN_00dd8790_hdr
{
    unsigned int m_00;
    unsigned int m_04;
};
struct FUN_00dd8790_node
{
    FUN_00dd8790_node* m_00;
    FUN_00dd8790_node* m_04;
    int unk08;
    void* m_0c;
    FUN_00dd8790_hdr* m_10;
    char* m_14;
};
struct FUN_00dd8790_owner
{
    virtual void v00();
    virtual unsigned char* v04(unsigned char* out);
    virtual void v08();
    virtual void v0c();
    virtual void v10(FUN_00dd8790_node* node, void* data);
};
struct FUN_00dd8790_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00dd8790_hdr* m_10;
    unsigned int m_14;
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
    int unk94;
    FUN_00dd8790_owner* m_98;
    int m_9c;
    int unka0;
    FUN_00dd8790_node m_a4;

    void PurgeAndSelectBlock();
};

struct FUN_00dd83a0_cls
{
    void FUN_00dd83a0();
};
struct FUN_00dd80d0_cls
{
    void RemoveNode(FUN_00dd8790_hdr* h);
};
struct FUN_00dd8010_cls
{
    void InsertChunk(FUN_00dd8790_hdr* h, unsigned int n);
};
struct FUN_00dd8400_cls
{
    void ResizeSegment(unsigned char* p, unsigned int n);
};

}  // namespace fnv_00dd8790

struct BlockPage
{
    unsigned int unk00;
    BlockPage* next;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int start;
    unsigned int end;
};

struct FUN_00dd8910_cls
{
    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    unsigned int unk28, unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    unsigned int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74;
    unsigned int unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int unkA0;
    BlockPage m_kPage;
    bool* IsChunkInPageList(bool* result, char* mem);
};

struct S_00dd8b20_Ref
{
    int unk00;
    int unk04;
};
struct S_00dd8b20_Node
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int key;
    int size;
};
struct S_00dd8b20_Ret
{
    int key;
    S_00dd8b20_Node* node;
    int size;
    S_00dd8b20_Ret()
    {}
};
struct FUN_00dd8b20_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00dd8b20_Ref* m10;
    unsigned m14;
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
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    S_00dd8b20_Node* ma8;
    S_00dd8b20_Ret FUN_00dd8b20();
};

struct FUN_00dd8df0_cls
{
    int unk00;

    void FUN_00dd7ec0();
    FUN_00dd8df0_cls* FUN_00dd8df0(int arg);
};

struct SpanSegment
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_kRayEnd;
    unsigned int unk10;
    unsigned int m_iElementCount;
};

struct SpanServer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual unsigned char* resize(unsigned int* sizePtr, SpanSegment* seg, unsigned int end, unsigned int size,
                                  unsigned int* newEnd);
};

struct hkBool
{
    bool m_cBooleanValue;
    hkBool()
    {}
    hkBool(bool b) : m_cBooleanValue(b)
    {}
};

struct FUN_00dd8400_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned char* m_base;
    unsigned int m_fMinimumV;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    SpanServer* m_pServer;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    SpanSegment* m_seg;
    hkBool ResizeSegment(unsigned int size);
};

struct AllocatorListener
{
    virtual void v00() = 0;
    virtual void v04(unsigned int size) = 0;
    virtual void v08(unsigned int size) = 0;
};

struct MemoryProvider
{
    virtual void v00() = 0;
    virtual hkBool canExtend() = 0;
    virtual unsigned int v08(unsigned int sizeNeeded) = 0;
    virtual S_00dd8aa0_Page* v0c(unsigned int size, unsigned int* actualSize) = 0;
};

struct Allocator_dd84c0
{
    void* m_vtbl;
    AllocatorListener* m_kListener;
    int unk08;
    int unk0c;
    S_00dd8aa0_Chunk* m_fMinimumV;
    unsigned int m_uiChunkSize;
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
    int unk94;
    MemoryProvider* m_provider;
    int unk9c;
    int unka0;
    S_00dd8aa0_Page m_kPage;

    void* Allocate(unsigned int size);
    hkBool ResizeSegment(unsigned int newSize);
    void* AllocateBlock(unsigned int size);
    void FUN_00dd83a0();
    void InsertChunk(void* chunk, unsigned int size);

    void* FUN_00dd84c0(unsigned int size);
};

inline void alignEnd(char*& p)
{
    *(unsigned int*)&p &= ~15;
}

struct S_dd8180_Chunk
{
    unsigned int unk00;
    unsigned int head;
    int unk08;
    int unk0c;
    S_dd8180_Chunk* child0;
    S_dd8180_Chunk* child1;
};

int __cdecl FUN_00dd7e00(unsigned int size);
int __cdecl FUN_00dd7e70(unsigned int bit);

struct S_dd8180_Alloc
{
    int unk00;
    int unk04;
    unsigned int treemap;
    int unk0c;
    int unk10;
    int unk14;
    S_dd8180_Chunk* bins[32];
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    unsigned int footprint;
    unsigned int used;
    void RemoveNode(S_dd8180_Chunk* c);
    void InsertChunk(S_dd8180_Chunk* c, unsigned int size);
    void* FUN_00dd8180(unsigned int nb);
};

struct FUN_00dd7de0
{
    virtual ~FUN_00dd7de0();
};
// @fnv 0x00dd7de0
FUN_00dd7de0::~FUN_00dd7de0()
{}

namespace fnv_00dd7e00 {
// FUN_00dd7e00: fast 2*log2-style bit scan of (x >> 8).

}  // namespace fnv_00dd7e00

// @f3 0x00594fb0 (community match, verified in this file)
namespace f3m_00594fb0 {
// 0x00594fb0: the secure-SCL std::copy_backward over 64-byte records (random-access overload):
// result = dest - (last - first) computed first, then the arbitrary-iterator loop is inlined.
// Element assignment is the out-of-line operator= at 0x5949c0.
struct Rec594 {
    int unk00; int unk04; int unk08; int unk0C;
    int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C;
    int unk30; int unk34; int unk38; int unk3C;
    Rec594& operator=(const Rec594& src);
};
__forceinline Rec594* CopyBack594(Rec594* first, Rec594* last, Rec594* dest)
{
    while (first != last)
        *--dest = *--last;
    return dest;
}
Rec594* FUN_00594fb0(Rec594* first, Rec594* last, Rec594* dest)
{
    Rec594* result = dest - (last - first);
    CopyBack594(first, last, dest);
    return result;
}
}   // namespace f3m_00594fb0

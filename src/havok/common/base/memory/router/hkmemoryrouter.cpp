#include "f3_common.h"
// src/havok/common/base/memory/router/hkmemoryrouter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/router/hkmemoryrouter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00c85690_Allocator
{
    virtual void unk00();
    virtual void* Allocate(unsigned int size);
};

struct FUN_00c85690_Header
{
    FUN_00c85690_Allocator* allocator;
    unsigned int size;
    int unk08;
    int unk0C;
};

struct Child
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void Release();
};
struct Owner
{
    int unk00, unk04, unk08;
    Child* child0C;
    Child* child10;
    Child* child14;
    Child* child18;
    Child* child1C;
    void ReleaseChildren();
};

class MemHeap
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void Free(char* block, unsigned int size);
};

// If p is non-null, clears the field at p-0x10 and calls heap->Free on the block at p minus the offset stored at p-8, with size from p-0xc plus 0x10.
// @f3 0x008f7010 (community match, verified in this file)
namespace f3m_008f7010 {
struct HeapBlockHeader
{
    unsigned int magic;
    unsigned int size;
    unsigned int tag;
    unsigned int offset;
};

class F3MemHeap
{
  public:
    void FUN_008f6d90(void* block, unsigned int size, unsigned int tag);
    void FUN_008f7010(char* data);
};

void F3MemHeap::FUN_008f7010(char* data)
{
    if (!data)
        return;

    HeapBlockHeader* header = (HeapBlockHeader*)(data - 0x10);
    unsigned int tag = header->tag;
    unsigned int size = header->size + 0x10;
    char* block = data - header->offset;
    header->magic = 0xdeadbeef;
    FUN_008f6d90(block, size, tag);
}
}   // namespace f3m_008f7010


struct FNV_Dispatch
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08(void* block, unsigned int size);
};

struct FNV_BlockHeader
{
    unsigned int m_iObjectReferenceCount;
    unsigned int m_iElementCount;
};

// If data is non-null, clears the block header's first field and dispatches the header with its size plus 0x10 to owner->unk08.
// @f3 0x008f6f90 (community match, verified in this file)
namespace f3m_008f6f90 {
struct HeapBlockHeader
{
    unsigned int magic;
    unsigned int size;
    unsigned int tag;
    unsigned int unk0C;
};

class F3MemHeap
{
  public:
    void FUN_008f6d90(void* block, unsigned int size, unsigned int tag);
    void FUN_008f6f90(char* data);
};

void F3MemHeap::FUN_008f6f90(char* data)
{
    if (!data)
        return;

    HeapBlockHeader* header = (HeapBlockHeader*)(data - 0x10);
    unsigned int size = header->size + 0x10;
    unsigned int tag = header->tag;
    header->magic = 0xdeadbeef;
    FUN_008f6d90(header, size, tag);
}
}   // namespace f3m_008f6f90


struct TargetClass
{
    int m_f00;
    int m_f04;
    int m_f08;
    int m_f0c;
    int m_f10;
    int m_f14;
    int m_f18;
    int m_f1c;

    TargetClass* Clear();
};

#include <windows.h>
extern DWORD g_01268108;

namespace fnv_00c85760 {
// Global TLS slot index used by the thread-local accessor.
extern DWORD g_dwTlsIndex;

// @fnv 0x00c85760
void* FUN_00c85760()
{
    return TlsGetValue(g_dwTlsIndex);
}
}  // namespace fnv_00c85760

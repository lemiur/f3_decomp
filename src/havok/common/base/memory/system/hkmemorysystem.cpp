#include "f3_common.h"
// src/havok/common/base/memory/system/hkmemorysystem.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/memory/system/hkmemorysystem.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00cbc440
int __stdcall FUN_00cbc440(int a, int b)
{
    return 1;
}

extern int DAT_01268418;

// @fnv 0x00cbbfc0
int FUN_00cbbfc0()
{
    return DAT_01268418;
}

extern int g_CBBFD0Value;

// @fnv 0x00cbbfd0
int __cdecl FUN_00cbbfd0()
{
    return g_CBBFD0Value;
}

extern int DAT_010c8efc;

struct FUN_00cbbfe0_This
{
    int unk00;
    void __thiscall FUN_00cbbfe0();
};

// @fnv 0x00cbbfe0
void FUN_00cbbfe0_This::FUN_00cbbfe0()
{
    this->unk00 = reinterpret_cast<int>(&DAT_010c8efc);
}

// FUN_00cbc450 - 10 bytes
//   call 0xcbbfe0
//   mov eax, ecx
//   ret 4
//
// The callee FUN_00cbbfe0 is DEFINED here (stand-in) because MSVC must be able
// to see that it leaves ECX untouched: the original returns `this` in EAX right
// after the call, so `this` has to stay live in ECX across it.  Declaring the
// helper only would make MSVC spill `this` to a callee-saved register.
//
// The stand-in body is behaviourally equivalent to the original callee
// (0x00cbbfe0 = "mov dword ptr [ecx], 0x010c8efc ; ret"): it stores the class
// vtable pointer into the object and returns, never touching ECX.

struct VTable
{
    void* entries[4];
};

extern void FUN_00cbbfe0_dummy();

static const VTable g_vtbl = {
    {(void*)&FUN_00cbbfe0_dummy, (void*)&FUN_00cbbfe0_dummy, (void*)&FUN_00cbbfe0_dummy, (void*)&FUN_00cbbfe0_dummy}};

struct MyCls
{
    const VTable* m_vtbl;
    __declspec(noinline) void FUN_00cbbfe0();
    MyCls* FUN_00cbc450(int arg);
};

void __cdecl FUN_00cc0410(int handle, const char* fmt, ...);
extern const char str_010c9078[];
extern const char str_010c9058[];
extern const char str_010c902c[];
extern const char str_010c900c[];
extern const char str_010c8fe0[];
extern const char str_010c8fc0[];
extern const char str_010c8f94[];
extern const char str_010c8f68[];
extern const char str_010c8f3c[];

struct S00cbc000_Stats
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

struct hkOstream;
int __cdecl FUN_00cc0410(hkOstream* ostr, const char* fmt, ...);

struct SixUnsignedValueRecord
{
    unsigned int m_uiFirstValue;
    unsigned int m_pAllocationMap;
    unsigned int m_uiThirdValue;
    unsigned int m_uiFourthUnsignedValue;
    unsigned int GetFifthValue;
    unsigned int GetSixthValue;
    SixUnsignedValueRecord()
        : m_uiFirstValue(0), m_pAllocationMap(0), m_uiThirdValue(0), m_uiFourthUnsignedValue(0), GetFifthValue(0),
          GetSixthValue(0)
    {}
};

struct hkMemoryAllocator
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
    virtual void v09();
    virtual void FillMemoryStatistics(SixUnsignedValueRecord& stats);
};

struct hkThreadMemory
{
    unsigned int ComputeWeightedSum();
};

struct StringPointerTriple
{
    char* m_pTileTemplate;
    char* m_kRayStart;
    char* m_kRayEnd;
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
};

struct MemSystemInfo
{
    hkMemoryAllocator* m_pStreamAllocator;
    hkArray<hkThreadMemory*> m_threadMemory;
    hkArray<StringPointerTriple*> m_kAllocatorList;
    int m_stackTotal;
    int m_heapSoftLimit;
};

struct AllocatorHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    hkMemoryAllocator* m_pAllocator;
    hkMemoryAllocator* m_pSolverAllocator;
    hkMemoryAllocator& debugAllocator()
    {
        return *m_pAllocator;
    }
    hkMemoryAllocator& solverAllocator()
    {
        return *m_pSolverAllocator;
    }
};
AllocatorHolder* __cdecl FUN_00c85750();

namespace MathUtilities {
}

// bscore/memorymanager.cpp: MemoryManager, TESQuest, TESActorBaseData, Actor and more (1 function)
#include "f3_common.h"
#include "memorymanager_identity.h"
#include "memorymanager_memory.h"
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

MemoryManager* FUN_00401020();

struct FUN_00473960_shell : public TESFile
{
    void FUN_00473960(void*);
};

void __cdecl Deallocate(void*);

// If the pointer at offset 0x420 is non-null, deallocates it and clears the pointer and the count at offset 0x424.
// @f3 0x00989ef0 (community match, verified in this file)
struct FUN_00473960_elem
{
    virtual void vf00(int flags);
    unsigned short unk04;
    short unk06;
};

void FUN_00473960_shell::FUN_00473960(void* aArg)
{
    unsigned int index = (unsigned int)aArg;
    FUN_00473960_elem** items = *(FUN_00473960_elem***)((char*)this + 0x14);
    FUN_00473960_elem* elem = items[index];
    if (elem->unk04 != 0)
    {
        elem->unk06--;
        if (elem->unk06 == 0)
            elem->vf00(1);
    }
    unsigned int count = --*(unsigned int*)((char*)this + 0x18);
    items = *(FUN_00473960_elem***)((char*)this + 0x14);
    items[index] = items[count];
}


struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct FUN_00aa3cc0_shell : public MemoryManager
{
    void CreateMemoryPool(unsigned int, unsigned int, char*);
};

extern __declspec(thread) int g_tlsMemContext;
struct MemCtxGuard
{
    int iOld;
    static int GetCtx()
    {
        return g_tlsMemContext;
    }
    static void SetCtx(int c)
    {
        g_tlsMemContext = c;
    }
    MemCtxGuard(int c)
    {
        iOld = GetCtx();
        SetCtx(c);
    }
    ~MemCtxGuard()
    {
        SetCtx(iOld);
    }
};
struct MemoryPoolView : public MemoryPool
{
    bool HasMemory()
    {
        return *(void**)((char*)this + 4) != 0;
    }
};

struct FUN_00aa3a10_shell
{
    void ClearFlagAndSetByte();
};

struct FUN_00aa3a10_tls_struct
{
    unsigned char pad[0x2b4];
    unsigned int flag;
};

__declspec(thread) FUN_00aa3a10_tls_struct g_fun_tls;

struct _RTL_CRITICAL_SECTION;
__declspec(dllimport) void __stdcall EnterCriticalSection(_RTL_CRITICAL_SECTION*);
extern _RTL_CRITICAL_SECTION DAT_011f6234;

struct _RTL_CRITICAL_SECTION;
__declspec(dllimport) void __stdcall LeaveCriticalSection(_RTL_CRITICAL_SECTION*);
extern _RTL_CRITICAL_SECTION DAT_011f6234;

extern char DAT_011f6230;

namespace fnv_00aa4490 {
extern unsigned int DAT_011f6234;

}  // namespace fnv_00aa4490

extern char DAT_011f6230;

struct FUN_00aa46a0_holder
{
    char pad0[2];
    unsigned short countA;
    unsigned short countB;
    char pad1[2];
    void** tableA;
    char pad2[0x118];
    void** tableB;
    void* GetEntryAt(unsigned int index);
};

extern "C" int _tls_index;
struct FUN_00aa39c0_tls
{
    unsigned char unk0000[0x2b4];
    unsigned int m_2b4;
};
extern __declspec(thread) FUN_00aa39c0_tls g_tls;

void ClearMemoryPoolTables();

class FUN_00aa39c0_cls
{
  public:
    unsigned char m_00;
    void InitializeHeaps();
    void FUN_00866770();
    void FUN_00483710();
    void FUN_00aa39c0();
};

extern FUN_00aa46a0_holder DAT_011f6238;
extern unsigned short DAT_011f623a;
extern unsigned short DAT_011f623c;
struct S_00aa4400_Obj
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
    virtual void v0a();
    virtual void v0b();
};
inline int S_Sum(int a, int b)
{
    return a + b;
}

__forceinline void operator delete[](void* p)
{
    g_memoryManager.Deallocate(p);
}
struct ScrapView
{
    ~ScrapView();
    static __forceinline void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
struct HeapView
{
    virtual ~HeapView();
};
struct WeightedMapNode
{
    WeightedMapNode* unk00;
};
struct MapView
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(WeightedMapNode*);
    virtual void slot5();
    virtual void slot6(WeightedMapNode*);
    unsigned int unk04;
    WeightedMapNode** unk08;
    void* unk0C;
    ~MapView();
    __forceinline WeightedMapNode* First()
    {
        for (unsigned int i = 0; i < unk04; ++i)
        {
            if (unk08[i])
                return unk08[i];
        }
        return 0;
    }
    void FUN_00a0c850(WeightedMapNode*&, unsigned long&, ScrapView*&);
    inline void ClearAll()
    {
        for (unsigned int bucket = 0; bucket < unk04; ++bucket)
        {
            while (unk08[bucket])
            {
                WeightedMapNode* node = unk08[bucket];
                unk08[bucket] = unk08[bucket]->unk00;
                slot4(node);
                slot6(node);
            }
        }
        unk0C = 0;
    }
};
inline void FreeArray(void* p)
{
    g_memoryManager.Deallocate(p);
}
struct FUN_00aa5950_s
{
    ~FUN_00aa5950_s();
    static __forceinline void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
extern FUN_00aa5950_s* DAT_011f63b4;
struct PoolView
{
    ~PoolView();
    static __forceinline void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
extern PoolView* DAT_011f67b8[256];
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned int);
struct FUN_00aa3a40
{
    bool unk00;
    unsigned char unk01;
    unsigned short unk02;
    unsigned short unk04;
    unsigned short unk06;
    HeapView** unk08;
    void* unk0C[66];
    MapView unk114;
    HeapView** unk124;
    void FUN_00483710();
    ~FUN_00aa3a40();
};

namespace fnv_00aa43a0 {
void __cdecl FUN_00aa7370();

class ItemAA43
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void unk10();
    virtual void Update();
};

class FUN_00aa46a0_holder
{
  public:
    short unk00;
    unsigned short m_count2;
    unsigned short m_count4;

    int GetCount()
    {
        return m_count2 + m_count4;
    }
    void* GetEntryAt(unsigned int index);
    void FUN_00aa43a0(int unused);
};

}  // namespace fnv_00aa43a0

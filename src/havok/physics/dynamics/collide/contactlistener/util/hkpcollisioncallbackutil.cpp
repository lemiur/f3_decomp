#include "f3_common.h"
// src/havok/physics/dynamics/collide/contactlistener/util/hkpcollisioncallbackutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/collide/contactlistener/util/hkpcollisioncallbackutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d0b1e0
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    void* unk0c;
    int unk10;
    struct Base
    {
        void FUN_00d0b0d0();
    };
    FUN_00d0b1e0(int flags);
};
extern int DAT_0102e388;
extern int DAT_010cb1e4;
extern int DAT_010cb1c4;
extern "C" void* __cdecl FUN_00c85750();
struct CallbackInterface
{
    virtual void f0();
    virtual void f1();
    virtual void callback(void*, unsigned short);
};
struct Manager
{
    int unk00[4];
    CallbackInterface* interface10;
};

struct CallbackTarget
{
    void FUN_00c91750(void* apValue);
    void FUN_00c91a70(void* apValue);
};

struct OuterRefHolder
{
    int unk00;
    int unk04;
    int unk08;

    void FUN_00c905b0();
};

struct SubEntry
{
    int unk00;

    void FUN_00d9e280(CallbackTarget* apTarget);
};

struct FUN_00d0ae30_cls
{
    int unk00;
    int unk04;
    SubEntry m_08;

    void FUN_00d0ae30(CallbackTarget* apTarget);
};

// @f3 0x006a37a0 (community match, verified in this file)
struct Interface401 { unsigned int value; };
struct Outer401 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void Destroy(unsigned int deleting);
    Interface401 first;
    Interface401 second;
};
struct Target401 {
    void FUN_0090b020(Outer401* object);
    void FUN_0090b960(Interface401* object);
    void FUN_0090afd0(Interface401* object);
};
void FUN_00d0ae30_cls::FUN_00d0ae30(CallbackTarget* target) {
    Outer401* outer = reinterpret_cast<Outer401*>(reinterpret_cast<char*>(this) - 4);
    Target401* receiver = reinterpret_cast<Target401*>(target);
    receiver->FUN_0090b020(outer);
    receiver->FUN_0090b960(outer ? &outer->first : 0);
    receiver->FUN_0090afd0(outer ? &outer->second : 0);
    if (outer)
        outer->Destroy(1);
}


extern int DAT_010cb1e4;
extern int DAT_010cb1c4;
extern int DAT_010cd33c;
extern int DAT_010cd31c;
extern int DAT_010cd30c;

struct FUN_00d0b180_sub
{
    void FUN_00d9e860();
};

struct FUN_00d0b180_cls
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    void* unk0c;
    int unk10;
    FUN_00d0b180_sub unk14;
    FUN_00d0b180_cls* Initialize();
};

#include <windows.h>
extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);

struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
};

struct ProfBuf
{
    DWORD unk00;
    ProfRec* m_pCur;
    DWORD unk08;
    ProfRec* m_pRecordEnd;
};

typedef LPVOID(WINAPI* PFN_TlsGetValue)(DWORD dwTlsIndex);

struct Collider
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int v20();
    void* unk04;
    void* unk08;
    void* GetBase();
};

struct Node
{
    void* unk00;
    void* unk04;
    void* unk08;
};

struct Params
{
    void* unk00;
    void* unk04;
    void* unk08;
    Collider* unk0c;
    void* unk10;
    Node* unk14;
    void* unk18;
};

struct Data
{
    int kind;
    Node* a;
    void* b;
    void* c;
};

extern "C" void __cdecl DispatchCollisionEvents(void* obj, Data* data);
extern "C" void __cdecl FUN_00cfffb0(void* obj, Data* data);

extern DWORD hkMonitorStreamTls;

struct S_00d0af60_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00d0af60_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

struct S_00d0af60_Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int getType();
    void* FUN_00d92820();
};

struct S_00d0af60_Entity
{
    int unk0;
    int unk4;
    void* unk8;
};

struct S_00d0af60_Event
{
    int m_type;
    S_00d0af60_Entity* m_kPointA;
    S_00d0af60_Entity* m_kPointB;
    void* m_obj;
};

struct S_00d0af60_Input
{
    int unk0;
    int unk4;
    int unk8;
    S_00d0af60_Shape* unkC;
    int unk10;
    S_00d0af60_Entity* unk14;
    S_00d0af60_Entity* unk18;
};

void FUN_00d00de0(void*, S_00d0af60_Event*);
void FUN_00d00060(S_00d0af60_Entity*, S_00d0af60_Event*);

// sub ecx,8; jmp target: MSVC adjustor thunk for the SecondaryBase slot of a
// class deriving from two bases; PrimaryBase is 8 bytes (vptr + one int).
struct AdjPrimaryBase
{
    virtual void FUN_00d0b1c0();
    int unk04;
};

struct AdjSecondaryBase
{
    virtual void FUN_00d0b1c0();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x00d0b1c0
    virtual void FUN_00d0b1c0();
};

AdjDerived::AdjDerived()
{}

// sub ecx,0xc; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0xc).
struct PrimaryBase
{
    virtual void FUN_00d0b1d0();
    int unk04;
    int unk08;
};

struct SecondaryBase
{
    virtual void FUN_00d0b1d0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0b1d0
    virtual void FUN_00d0b1d0();
};

Derived::Derived()
{}

namespace fnv_00d0b040 {
struct hkMemory
{
    virtual void unk00();
    virtual void* allocateChunk(int size);
};

struct hkThreadMemory
{
    char pad00[0x10];
    hkMemory* m_pMemoryAllocator;
};

extern "C" hkThreadMemory* __cdecl FUN_00c85750();

struct SubObj
{
    void __thiscall PassObjectToTarget(void* obj);
};

struct hkpCollisionCallbackUtil
{
    char pad00[4];
    unsigned short m_usMemSizeAndFlags;
    char pad06[2];
    void* field_08;
    void* field_0C;
    int m_sReferenceCount;
    SubObj field_14;

    hkpCollisionCallbackUtil* __thiscall Initialize();
};

struct TargetClass
{
    char pad00[0x1c0];
    hkpCollisionCallbackUtil* m_pCallbackData;

    void __thiscall FUN_00c93a60(void* p);
    void __thiscall FUN_00c937e0(void* p);
};

}  // namespace fnv_00d0b040

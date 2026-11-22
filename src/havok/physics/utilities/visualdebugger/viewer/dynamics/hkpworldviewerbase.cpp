#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpworldviewerbase.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpworldviewerbase.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00ddcdd0
unsigned int FUN_00ddcdd0(unsigned int auiValue, unsigned int auiIndex, unsigned int auiFieldValue)
{
    return (auiValue & ~(0x1f << (auiIndex * 5))) | (auiFieldValue << (auiIndex * 5));
}

struct DDCC60BaseObject
{
    virtual ~DDCC60BaseObject()
    {}
};

struct DDCC60ReferencedObject : DDCC60BaseObject
{
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct DDCC60Action
{
    virtual ~DDCC60Action()
    {}

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct DDCC60Listener
{
    virtual ~DDCC60Listener()
    {}
};

struct DDCC60World
{
    __declspec(nothrow) void removeListener(DDCC60Listener* listener);
    __declspec(nothrow) void removeReference();
};

struct FUN_00ddcc60 : DDCC60ReferencedObject, DDCC60Action, DDCC60Listener
{
    DDCC60World* m_pOwningWorld;

    virtual ~FUN_00ddcc60();
};

// If the world pointer is set, removes this listener and reference from it, then clears the pointer.
// @fnv 0x00ddcc60
FUN_00ddcc60::~FUN_00ddcc60()
{
    if (m_pOwningWorld)
    {
        m_pOwningWorld->removeListener(this);
        m_pOwningWorld->removeReference();
        m_pOwningWorld = 0;
    }
}

struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl FUN_00c85750();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00ddcc60();
    CpuObject* DestroyOrFree(unsigned int flags);
};

extern double DAT_010cd5a8;
extern double DAT_0101ff40;

int __cdecl FUN_00cb0fa0(const char* pcA, const char* pcB);

class __declspec(novtable) BDDCCB0ReferencedObject
{
  public:
    BDDCCB0ReferencedObject() : m_sReferenceCount(1)
    {}
    virtual ~BDDCCB0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
};

class BDDCCB0ProcessContext
{
  public:
    virtual ~BDDCCB0ProcessContext();
    virtual const char* getType();
};

class BDDCCB0WorldAddedListener;

class BDDCCB0PhysicsContext : public BDDCCB0ReferencedObject, public BDDCCB0ProcessContext
{
  public:
    void AddWorldAddedListener(BDDCCB0WorldAddedListener* pkListener);
    void RetainReference();
};

template <class T> class BDDCCB0Array
{
  public:
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i) const
    {
        return m_data[i];
    }

    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class BDDCCB0Process
{
  public:
    BDDCCB0Process(bool bSelectable) : m_bSelectable(bSelectable)
    {}
    virtual ~BDDCCB0Process();

    bool m_bSelectable;
    void* m_pkProcessHandler;
    void* m_pkDisplayHandler;
    void* m_pkInStream;
    void* m_pkOutStream;
};

class BDDCCB0WorldAddedListener
{
  public:
    virtual ~BDDCCB0WorldAddedListener();
};

class FUN_00ddccb0_cls : public BDDCCB0ReferencedObject, public BDDCCB0Process, public BDDCCB0WorldAddedListener
{
  public:
    FUN_00ddccb0_cls(const BDDCCB0Array<BDDCCB0ProcessContext*>& kContexts) throw();
    virtual ~FUN_00ddccb0_cls();

    BDDCCB0PhysicsContext* m_pkContext;
};

// @f3 0x00a648d0 (community match, verified in this file)
FUN_00ddccb0_cls::FUN_00ddccb0_cls(const BDDCCB0Array<BDDCCB0ProcessContext*>& kContexts) throw()
    : BDDCCB0Process(true), m_pkContext(0)
{
    int iSize = kContexts.GetLogicalSize();
    for (int i = 0; i < iSize; i++)
    {
        if (FUN_00cb0fa0("Physics", kContexts[i]->getType()) == 0)
        {
            m_pkContext = static_cast<BDDCCB0PhysicsContext*>(kContexts[i]);
            break;
        }
    }
    if (m_pkContext)
    {
        m_pkContext->AddWorldAddedListener(this);
        if (m_pkContext->m_usMemSizeAndFlags != 0)
            m_pkContext->m_sReferenceCount++;
    }
}


struct Item
{
    int unk00;
    int unk04;
    float unk08;
};

struct Flag
{
    bool value;
    Flag(bool v) : value(v)
    {}
};

// Compares unk08 of two Item objects and returns a Flag holding whether the first is less than the second.
// @f3 0x00a58ad0 (community match, verified in this file)
Flag __cdecl FUN_00ddcda0(Item* left, Item* right) {
    bool result;
    if (*(float*)&left->unk04 < *(float*)&right->unk04)
        result = true;
    else
        result = false;
    return Flag(result);
}


#include <math.h>
struct DDCE80Point
{
    float x;
    float y;
    float z;
};

struct DDCE80Bool
{
    char m_cBooleanValue;

    DDCE80Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00ddd040 {
extern "C" double __cdecl fabs(double);
extern double DAT_0103c7c8;
struct S_V
{
    __m128 q;
};
struct S_P
{
    const S_V* p;
    const S_V* val() const
    {
        return p;
    }
};
}  // namespace fnv_00ddd040

struct FUN_00ddcc40
{
    virtual ~FUN_00ddcc40();
};

struct Base1
{
// @fnv 0x00ddcd50
    virtual void FUN_00ddcd50();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct Base2
{
    virtual void FUN_00ddcd50();
};
struct Derived : Base1, Base2
{
    Derived();
    virtual void FUN_00ddcd50();
};
Derived::Derived()
{}

// FUN_00ddcd60 : MSVC this-adjusting thunk  (sub ecx, 0x08 ; jmp <impl>)
struct A1_00ddcd60
{
    A1_00ddcd60();
    virtual void FUN_00ddcd60();
    char pad[0x04];
};
struct A2_00ddcd60
{
    A2_00ddcd60();
    virtual void FUN_00ddcd60();
};
struct Own_00ddcd60 : A1_00ddcd60, A2_00ddcd60
{
    Own_00ddcd60();
    virtual void key_fn();
// @fnv 0x00ddcd60
    void FUN_00ddcd60();
};

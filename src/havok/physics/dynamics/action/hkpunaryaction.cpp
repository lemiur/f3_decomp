#include "f3_common.h"
// src/havok/physics/dynamics/action/hkpunaryaction.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/action/hkpunaryaction.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpUnaryAction.h"

struct FUN_00c97510
{
    void ProcessPointer(void*);
};

struct FUN_00d2b1f0
{
    char m0[8];
    FUN_00c97510* m1;
    void EntityRemovedCallback(int);
};

// @fnv 0x00d2b1f0
void FUN_00d2b1f0::EntityRemovedCallback(int)
{
    if (m1)
        m1->ProcessPointer(this);
}

extern int DAT_010cc2fc;
extern int DAT_010ce528;
extern int _DAT_0102e388;

struct DDCC60World
{
    void removeReference();
};

struct S_00d49310_Lock
{
    ~S_00d49310_Lock();
};

struct FUN_00d2b2b0_class
{
    void* vptr;
    unsigned char padding[0x10];
    S_00d49310_Lock lock;
    DDCC60World* world;

    void FUN_00d2b2b0();
};

// Resets the vtable, releases the world reference if present, then destroys the lock and resets the vtable again.
// @f3 0x004d8840 (community match, verified in this file)
struct FUN_004d8740_elem
{
    void FUN_004d8740();
};

struct FUN_00433530_mgr
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
    FUN_004d8740_elem** m_arr;
    unsigned int FUN_00433530();
};

extern FUN_00433530_mgr* DAT_0107a0d8;

void FUN_00d2b2b0_class::FUN_00d2b2b0()
{
    for (unsigned int i = 0; i < DAT_0107a0d8->FUN_00433530(); i++)
    {
        FUN_004d8740_elem* e = DAT_0107a0d8->m_arr[i];
        if (e)
            e->FUN_004d8740();
    }
}


struct hkMemoryManager
{
    virtual void FUN_00d4d950_0() = 0;
    virtual void FUN_00d4d950_1() = 0;
    virtual void free(void* object, unsigned int size) = 0;
};

struct NineIntegerRecord
{
    unsigned char padding[0x10];
    hkMemoryManager* memoryManager;
};

void FUN_00d2b2b0();
NineIntegerRecord* _D1A0E0GetMemoryRouter();

struct Action
{
    virtual void FUN_00d4d950_2() = 0;
    unsigned short size;

    Action* FUN_00d4d950(unsigned char flags);
};

class hkpWorld;

class hkpEntity : public hkReferencedObject
{
  public:
    void RetainReference();
    void removeReference();
};

class hkpWorld
{
  public:
    void RemoveActionFromEntity(hkpUnaryAction* action, hkpEntity* entity);
    void FUN_00c92bd0(hkpUnaryAction* action, hkpEntity* entity);
};

class UnaryActionHelper : public hkpUnaryAction
{
  public:
    void SetEntity(hkpEntity* entity);
};

// @fnv 0x00d2b210
void UnaryActionHelper::SetEntity(hkpEntity* entity)
{
    if (m_pEntity)
    {
        if (hkpWorld* world = (hkpWorld*)m_pOwningWorld)
        {
            world->RemoveActionFromEntity(this, m_pEntity);
        }
        m_pEntity->removeReference();
        m_pEntity = 0;
    }
    m_pEntity = entity;
    m_pEntity->RetainReference();
    if (hkpWorld* world = (hkpWorld*)m_pOwningWorld)
    {
        world->FUN_00c92bd0(this, m_pEntity);
    }
}

struct FUN_00cb0a60_Field
{
    unsigned int value;
    void initialize();
};
struct FUN_00c90510_Entity
{
    void RetainReference();
};
struct FUN_00d2b260
{
    void* vptr;
    unsigned short memSizeAndFlags;
    short referenceCount;
    void* world;
    void* island;
    unsigned int userData;
    FUN_00cb0a60_Field name;
    FUN_00c90510_Entity* entity;
    FUN_00d2b260(FUN_00c90510_Entity* entity, unsigned int userData);
};

class hkMemoryAllocatorXd2b2f0;

struct hkMemoryRouterXd2b2f0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXd2b2f0* m_pStreamAllocator;
    hkMemoryAllocatorXd2b2f0& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterXd2b2f0& __cdecl FUN_00c85750();

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iElemSize);

template <class T> __forceinline void constructWithCopyXd2b2f0(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> class hkArrayXd2b2f0
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void AddBack(const T& t)
    {
        hkMemoryAllocatorXd2b2f0& kAlloc = FUN_00c85750().heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&kAlloc, this, sizeof(T));
        constructWithCopyXd2b2f0(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
};

class hkObjXd2b2f0
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_uiFilterValue;

    void AppendPointer(hkArrayXd2b2f0<void*>& kArray);
};

// @f3twin 0x009ae940 of 0x00979da0
struct F3Twin_009ae940 : public UnaryActionHelper { void F3_FUN_009ae940(hkpEntity* entity) ; };
void F3Twin_009ae940::F3_FUN_009ae940(hkpEntity* entity) 
{
    if (m_pEntity)
    {
        if (hkpWorld* world = (hkpWorld*)m_pOwningWorld)
        {
            world->RemoveActionFromEntity(this, m_pEntity);
        }
        m_pEntity->removeReference();
        m_pEntity = 0;
    }
    m_pEntity = entity;
    m_pEntity->RetainReference();
    if (hkpWorld* world = (hkpWorld*)m_pOwningWorld)
    {
        world->FUN_00c92bd0(this, m_pEntity);
    }
}

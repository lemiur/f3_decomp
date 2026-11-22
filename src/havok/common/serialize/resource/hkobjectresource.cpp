#include "f3_common.h"
// src/havok/common/serialize/resource/hkobjectresource.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/resource/hkobjectresource.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkReferencedObject
{
    void RetainReference();
    void removeReference();
};

struct FUN_00e04eb0_class
{
    char _pad[0x10];
    hkReferencedObject* m_p;
    void FUN_00e04eb0(hkReferencedObject* p);
};

namespace fnv_00e04ee0 {
struct hkReferencedObject
{
    void RetainReference();
    void removeReference();
};

struct FUN_00e04ee0_class
{
    void __thiscall FUN_00e04ee0(hkReferencedObject* p);
    char _pad[0x14];
    hkReferencedObject* m_p;
};

}  // namespace fnv_00e04ee0

struct D481D0Class
{
    const char* getName() const;
};

struct FUN_00e04ea0_class
{
    char _pad[0xc];
    D481D0Class* p;
    const char* FUN_00e04ea0();
};

struct FUN_00e05090_class;

struct FUN_00e05090_manager
{
    // Virtual destructor for the manager class; performs no work.
// @fnv 0x00e05090
    virtual ~FUN_00e05090_manager()
    {}
    virtual void FUN_00e05090_other();
    virtual void FUN_00e05090_free(FUN_00e05090_class* pObject, unsigned short resourceId);
};

struct FUN_00e05090_router
{
    char _pad[0x10];
    FUN_00e05090_manager* m_pManager;
};

extern FUN_00e05090_router* _D1A0E0GetMemoryRouter();

struct FUN_00e05090_class
{
    virtual FUN_00e05090_class* FUN_00e05090(int flags);
    unsigned short m_resourceId;
    void ReleaseResource();
};

int __cdecl FUN_00cb0fa0(int, int);

struct hkBoolD46D
{
    char m_cBooleanValue;
    hkBoolD46D(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class FUN_00d46d40_s
{
  public:
    const char* FUN_00d46d40();
    FUN_00d46d40_s* FUN_00d46d50();

    hkBoolD46D FUN_00d46d80(FUN_00d46d40_s* pkNode);
};

// @fnv 0x00e04e50
int __cdecl FUN_00e04e50()
{
    return 0;
}

struct FUN_00e04e70_class
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual int vf6(void* first, void* second);
    int unknown04;
    void* value08;
    void* value0c;
    int FUN_00e04e70(void* first, void* second);
};

struct FUN_00e04f10_Resource
{
    int refs;
};
extern "C" void __fastcall FUN_00c90510(FUN_00e04f10_Resource* resource);
struct FUN_00e04f10_Manager
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual FUN_00e04f10_Resource* GetSecond();
    virtual FUN_00e04f10_Resource* GetFirst();
};
extern "C" FUN_00e04f10_Manager* DAT_01268b08;
extern "C" void* DAT_010ea4dc[];
struct FUN_00e04f10_Values
{
    int first, second;
};
class FUN_00e04f10_Class
{
  public:
    void** vtable;
    unsigned short unk04, refCount;
    FUN_00e04f10_Values values;
    FUN_00e04f10_Resource* first;
    FUN_00e04f10_Resource* second;
    FUN_00e04f10_Class* Initialize(const FUN_00e04f10_Values* init);
};
// @f3 0x006d5980 (community match, verified in this file)
namespace f3m_006d5980 {
struct Heap {
    void FUN_0086ba60(void*);
};
extern Heap DAT_01090a78;

struct Item {
    void FUN_006cdb80();
    ~Item() { FUN_006cdb80(); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct ListNode {
    Item* item;
    ListNode* next;
    void FUN_006c8220();
    ~ListNode() { FUN_006c8220(); }
    static void operator delete(void* p) { DAT_01090a78.FUN_0086ba60(p); }
};

struct Owner {
    ListNode* list;
    int unk04;
    void FUN_006d5980();
};

void Owner::FUN_006d5980()
{
    for (ListNode* node = list; node; node = node->next) {
        if (node->item)
            delete node->item;
    }
    if (list) {
        list->FUN_006c8220();
        delete list;
        list = 0;
    }
    unk04 = 0;
}
}


namespace fnv_00e04f80 {
struct Resource_00e04f80
{
    const char* FUN_00d46d40();
    unsigned int FUN_00d470d0();
};

struct Referenced_00e04f80
{
    void FUN_00c905b0();
};

struct ListenerVTable_00e04f80;
struct Listener_00e04f80
{
    ListenerVTable_00e04f80* methods;
};
typedef void (Listener_00e04f80::*ResourceCallback_00e04f80)(Referenced_00e04f80*, const char*);
struct ListenerVTable_00e04f80
{
    ResourceCallback_00e04f80 vfunc00;
    ResourceCallback_00e04f80 vfunc04;
    ResourceCallback_00e04f80 vfunc08;
    ResourceCallback_00e04f80 vfunc0c;
    ResourceCallback_00e04f80 vfunc10;
    ResourceCallback_00e04f80 onResourceRemoved;
};

struct Manager_00e04f80
{
    virtual void vfunc00();
    virtual void vfunc04();
    virtual void removeResource(Referenced_00e04f80* owner, unsigned int resourceId);
};

struct Router_00e04f80
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    Manager_00e04f80* manager;
};

struct Registry_00e04f80
{
    char* FUN_00d46d80(char* status, Resource_00e04f80* resource);
};

extern Registry_00e04f80 DAT_01268748;
extern char DAT_010ea4dc;
extern char DAT_0102e388;
extern Router_00e04f80* __cdecl FUN_00c85750();

struct FUN_00e04f80_class
{
    void* vtable;
    unsigned short resourceId;
    unsigned short unk06;
    Referenced_00e04f80* owner;
    Resource_00e04f80* resource;
    Referenced_00e04f80* context;
    Listener_00e04f80* listener;

    void ReleaseResource();
};

}  // namespace fnv_00e04f80

namespace fnv_00e05030 {
struct hkBool
{
    char m_cBooleanValue;
    hkBool();
};

struct FUN_00d46d40_s
{
    const char* FUN_00d46d40();
    hkBool FUN_00d46d80(FUN_00d46d40_s* other);
};

struct Registry
{
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual FUN_00d46d40_s* GetClassByName(const char* name);
};

struct MyClass
{
    int unk00;
    int unk04;
    void* unk08;
    D481D0Class* unk0C;
    Registry* unk10;

    void* LookupByName(const char* name, hkBool b);
};

}  // namespace fnv_00e05030

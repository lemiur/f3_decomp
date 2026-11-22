#include "f3_common.h"
// src/havok/common/serialize/data/native/hkdataobjectnative.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/data/native/hkdataobjectnative.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkReferencedObject
{
    void RetainReference();
    void removeReference();
};

struct FUN_00dbb490_class
{
    int m_iWordAt00;
    int m_iWordAt04;
    hkReferencedObject* m_8;
    void SetReferencedObject(hkReferencedObject* p);
};

namespace fnv_00dbb4c0 {
struct hkReferencedObject
{
    void RetainReference();
    void removeReference();
};
struct FUN_00dbb4c0_class
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    int m_pAuxiliaryObject;
    hkReferencedObject* m_pObject;
    void SetObject(hkReferencedObject* object);
};
}  // namespace fnv_00dbb4c0

struct FUN_00dbbb20_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    void* m_10;
    int __thiscall FUN_00dbbb20(int a);
};

struct FUN_00d46f00_Class
{
    int __thiscall FUN_00d46f00();
};

struct FUN_00dbbc50_Class
{
    int __thiscall FUN_00dbbc50(int a);
};

struct FUN_00dbbc60_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int __thiscall FUN_00dbbc60(int a);
};

struct FUN_00d873b0_t
{
    int a;
    int b;
    FUN_00d873b0_t(int x, int y);
};
// @fnv 0x00d873b0
FUN_00d873b0_t::FUN_00d873b0_t(int aiFirst, int aiSecond)
{
    a = aiFirst;
    b = aiSecond;
}

struct D481D0Class
{
    const char* __thiscall getName();
};
struct FUN_00dbb920_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    const char* __thiscall FUN_00dbb920();
};

namespace fnv_00dbb940 {
struct D481D0Class
{
    char const* getName() const;
};

struct FUN_00d46d50_s
{
    D481D0Class* FUN_00d46d50();
};

struct FUN_00dbb940_VirtualClass
{
    virtual void FUN_00dbb940_0() = 0;
    virtual void FUN_00dbb940_1() = 0;
    virtual void FUN_00dbb940_2() = 0;
    virtual void FUN_00dbb940_3() = 0;
    virtual void FUN_00dbb940_4() = 0;
    virtual void FUN_00dbb940_5() = 0;
    virtual void FUN_00dbb940_6() = 0;
    virtual void FUN_00dbb940_7() = 0;
    virtual void FUN_00dbb940_8() = 0;
    virtual int FUN_00dbb940_9(char const* name) = 0;
};

struct hkDataClassNative
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00d46d50_s* m_0C;
    FUN_00dbb940_VirtualClass* m_10;

    int __thiscall FUN_00dbb940();
};

}  // namespace fnv_00dbb940

struct TypeNode
{
    int FUN_00d46f70();
};
struct FUN_00dbb9d0_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int FUN_00dbb9d0();
};

namespace fnv_00dbba80 {
struct D481D0Class
{
    char const* getName() const;
};

struct FUN_00dbba80_Manager
{
    virtual void FUN_00dbba80_0() = 0;
    virtual void FUN_00dbba80_1() = 0;
    virtual void FUN_00dbba80_2() = 0;
    virtual void FUN_00dbba80_3() = 0;
    virtual void FUN_00dbba80_4() = 0;
    virtual void FUN_00dbba80_5() = 0;
    virtual void FUN_00dbba80_6() = 0;
    virtual void FUN_00dbba80_7() = 0;
    virtual void FUN_00dbba80_8() = 0;
    virtual D481D0Class* GetVariantValue(char const* name) = 0;
};

struct FUN_00dbba80_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    D481D0Class* m_10;
    FUN_00dbba80_Manager* m_14;

    D481D0Class* __thiscall GetNamedClass();
};

}  // namespace fnv_00dbba80

namespace fnv_00dbbc20 {
struct D481D0Class
{
    virtual int FUN_00dbbc20_1();
    virtual int FUN_00dbbc20_2();
    virtual int FUN_00dbbc20_3();
    virtual int FUN_00dbbc20_4();
    virtual int FUN_00dbbc20_5();
    virtual int FUN_00dbbc20_6();
    virtual int FUN_00dbbc20_7();
    virtual int FUN_00dbbc20_8();
    virtual int FUN_00dbbc20_9();
    virtual int FUN_00dbbc20_10(char const* name);

    char const* getName() const;
};

struct FUN_00dbbc20_Class : D481D0Class
{
    int m_04;
    int m_08;
    D481D0Class* m_0C;
    void* m_10;
    int m_14;
    int m_18;
    int m_1C;
    D481D0Class* m_20;

    int FUN_00dbbc20();
};

}  // namespace fnv_00dbbc20

struct hkDataArrayNative
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int GetElementAsInt(int index);
};

struct FUN_00dbbd70_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    char* m_10;
    int m_14;
    int m_18;
    __int64 __thiscall GetEntry64(int a);
};

struct Shape
{
};

struct Container
{
    Shape const* __thiscall FUN_00d46f80(int) const;
};

struct FUN_00dbbfa0_Class
{
    int m_00;
    int m_04;
    int m_08;
    Container* m_0c;

    void __thiscall GetMemberInfo(Shape const*, int);
    void __thiscall FUN_00dbbfa0(int, int);
};

struct FUN_00d46f20_Class
{
    int __thiscall FUN_00d46f20(int a, int b);
};

struct hkDataClassNative
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00d46f20_Class* m_0c;

    void SetInvocationResult(int result);
    void InvokeMemberFunction(int a, int b);
};

struct FUN_00dbc640_class;

struct FUN_00dbc640_allocator
{
// @fnv 0x00dbc640
    virtual void FUN_00dbc640_0()
    {}
    virtual void FUN_00dbc640_1()
    {}
    virtual void __thiscall FUN_00dbc640_2(FUN_00dbc640_class* p, unsigned short size);
};

struct FUN_00dbc640_router
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0C;
    FUN_00dbc640_allocator* m_10;
};

FUN_00dbc640_router* _D1A0E0GetMemoryRouter();

struct FUN_00dbc640_class
{
    int m_00;
    unsigned short m_04;

    void __thiscall FUN_00dbb3f0();

    FUN_00dbc640_class* __thiscall FUN_00dbc640(int flags);
};

struct Inner
{
    void Run();
};

struct FUN_00dbb930_cls
{
    int unk00;
    int unk04;
    int unk08;
    Inner* m_pInner;
    void FUN_00dbb930();
};

struct FUN_00d47080_Class
{
    void __thiscall FindIndexByName();
};

struct FUN_00dbb9e0_Class
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d47080_Class* unk0c;

    void __thiscall FUN_00dbb9e0();
};

struct FUN_00dbb9f0_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d46f00_Class* m_0C;
    void FUN_00dbb9f0();
};

struct FUN_00dbba00_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int __thiscall FUN_00d47030(int param_1);
    int __thiscall FUN_00dbba00(int param_1);
};

// @fnv 0x00dbb130
int __stdcall FUN_00dbb130(int a, int b)
{
    return 0;
}

struct FUN_00c90510_Obj : hkReferencedObject
{
    void FUN_00c90510();
};
struct FUN_00d87790_Result
{
    unsigned char value;
};
struct FUN_00d87790_Obj
{
    void __thiscall FUN_00d87790(FUN_00d87790_Result);
};
struct FUN_00dbb360_Global
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual FUN_00c90510_Obj* vf10();
    virtual FUN_00c90510_Obj* vf14();
};
extern FUN_00dbb360_Global* DAT_01268b08;
extern int DAT_010d6518[];
struct FUN_00dbb360_Class
{
    int m_00;
    unsigned short m_04, m_06;
    hkReferencedObject* m_08;
    hkReferencedObject* m_0C;
    FUN_00d87790_Obj m_10;
    int m_14, m_18, m_1C, m_20, m_24;
    FUN_00dbb360_Class* __thiscall Initialize();
};

class hkMemoryAllocatorDBB5
{
  public:
    virtual ~hkMemoryAllocatorDBB5() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterDBB5
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDBB5* m_pStreamAllocator;

    hkMemoryAllocatorDBB5& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDBB5 {
extern "C" hkMemoryRouterDBB5& __cdecl FUN_00c85750() throw();
}

class hkRefObjDBB5
{
  public:
    virtual ~hkRefObjDBB5() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjDBB5() throw()
    {
        m_sReferenceCount = 0;
    }

    static void* operator new(unsigned int nbytes)
    {
        hkRefObjDBB5* b = static_cast<hkRefObjDBB5*>(hkRouterDBB5::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

class hkStringDBB5
{
  public:
    void FUN_00d873b0(const char* name, int len) throw();
    int unk00;
    int unk04;
};

class hkStringFnDBB5
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual int strLen(const char* s);
};

struct hkNameDescDBB5
{
    const char* m_name;
    int m_len;
};

class hkLibDBB5;

class hkResourceDBB5 : public hkRefObjDBB5
{
  public:
    int m_08;

    hkResourceDBB5() throw() : m_08(0)
    {}
    virtual ~hkResourceDBB5() throw();
};

class hkNodeDBB5 : public hkResourceDBB5
{
  public:
    hkStringDBB5 m_name;
    hkLibDBB5* m_pOwnerObject;

    hkNodeDBB5() throw()
    {}
    virtual ~hkNodeDBB5() throw();
};

class hkNodeRefDBB5
{
  public:
    void FUN_00dba760(hkNodeDBB5* node) throw();
    hkNodeDBB5* m_node;
};

class hkLibDBB5
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStringFnDBB5* m_pStringFunctions;

    hkNodeRefDBB5 CreateNode(const hkNameDescDBB5& desc);
};

struct hkErrorDBB7
{
    virtual ~hkErrorDBB7();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int message(int iType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
};
extern hkErrorDBB7* DAT_01268360;

struct hkOstreamDBB7
{
    int m_iUnk00;
    char* m_pString;
    int m_uiLogicalSize;
    void FUN_00cc00e0() throw();
    hkOstreamDBB7& FUN_00cc01c0(const char* pcString) throw();
    hkOstreamDBB7& FUN_00cc0120(const void* pvPointer) throw();
};

struct FUN_00cb1600 : hkOstreamDBB7
{
    FUN_00cb1600(char* pcBuffer, int iSize) throw();
};

struct hkBoolDBB7
{
    char m_bValue;
    hkBoolDBB7() throw()
    {}
};

struct FUN_00d46d40_s
{
    const char* FUN_00d46d40() throw();
};

struct hkClassDBB7 : FUN_00d46d40_s
{
    hkBoolDBB7 GetLastNodeFlag() const throw();
};

class hkVtableClassRegistryDBB7
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual hkClassDBB7* GetClassFromVirtualInstance(void* pvObject) throw();
};

class hkDataWorldNativeDBB7
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void* GetClassFromName(const char* pcName) throw();
};

class hkDataObjectNativeDBB7
{
  public:
    int m_iUnk00;
    int m_iUnk04;
    hkDataWorldNativeDBB7* m_pkWorld;
    hkVtableClassRegistryDBB7* m_pkVtableRegistry;
    int m_aiUnk10[4];
    void* m_pvObject;
    void* m_pkClass;

    hkDataWorldNativeDBB7* getWorld() const
    {
        return m_pkWorld;
    }
    void SetContents(void* pvObject, hkClassDBB7& kClass);
};

int __cdecl FUN_00cb0fa0(int, int);

struct hkBoolDBB9
{
    char m_cBooleanValue;
    hkBoolDBB9(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class hkNamedNodeDBB9
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual const char* getName() const throw();
    virtual void V3() throw();
    virtual hkNamedNodeDBB9* getNext() const throw();

    hkBoolDBB9 FUN_00dbb970(const hkNamedNodeDBB9* pkNode) const;
};

class hkHalf
{
  public:
    short m_uiFilterValue;
    hkHalf()
    {}
    hkHalf(float f)
    {
        int t = *(int*)&f;
        m_uiFilterValue = (short)(t >> 16);
    }
};

struct FUN_00d871a0_Data
{
    int memberData;
    int key;
    void FUN_00d871a0(void* value, int argument);
    const char* FUN_00d871e0(const int* argument);
};
struct FUN_00dbbae0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int FUN_00dbbae0(int argument);
};

class hkOwnerDBBB;

struct hkRefDBBB
{
    hkOwnerDBBB* m_pOwnerObject;
    int m_uiFilterValue;

    hkRefDBBB(hkOwnerDBBB* pkOwner, int iValue) : m_pOwnerObject(pkOwner), m_uiFilterValue(iValue)
    {}
};

class hkOwnerDBBB
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2(void* pValue);
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int V8(int iKey);

    hkRefDBBB MakeRef(int iKey);
    void MakeRef(void* pValue);
};

// Constructs and returns an hkRefDBBB holding this owner and the value from V8(iKey).
// @f3 0x004227a0 (community match, verified in this file)
namespace mr_004227a0 {
struct Fields
{
    void* vtable;
    int unk04;
    int unk08;
    char unk0C;
    char pad0D;
    short unk0E;
};
}

void hkOwnerDBBB::MakeRef(void* pValue)
{
    V2(pValue);
    mr_004227a0::Fields* self = (mr_004227a0::Fields*)this;
    const mr_004227a0::Fields* src = (const mr_004227a0::Fields*)pValue;
    self->unk0C = src->unk0C;
    self->unk0E = src->unk0E;
}


struct FUN_00dbbca0_class
{
    int m_00, m_04, m_08, m_0c;
    char* m_10;
    int m_14, m_18, m_1c;
    float FUN_00dbbca0(int index);
};

class hkMemoryAllocatorDBBD
{
  public:
    virtual ~hkMemoryAllocatorDBBD() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterDBBD
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDBBD* m_pStreamAllocator;
    hkMemoryAllocatorDBBD& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDBBD& __cdecl FUN_00c85750();

struct hkClassMemberTypeDBBD
{
    int unk00;
    int unk04;
    short m_iElementCount;
};

hkClassMemberTypeDBBD* __cdecl FUN_00d868a0(int iType);

struct hkArrayBaseDBBD
{
    void* m_data;
    int m_iElementCount;
};

class FUN_00dbbb90
{
  public:
    virtual ~FUN_00dbbb90() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void* operator new(unsigned int nbytes)
    {
        FUN_00dbbb90* b = static_cast<FUN_00dbbb90*>(FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }

    FUN_00dbbb90(int iWorld, void* pvData, int iSize, int iStride, int iType, int m_iMenuId, int iTupleCount) throw();

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
};

class hkDataObjectNativeDBBD
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int m_pOwningWorld;
    char* m_data;
    int unk14;
    int m_iElementIndex;
    int m_type;
    int m_class;
    int unk24;
    int m_iFlags;

    FUN_00dbbb90* GetElement(int iIndex);
};

struct FUN_00d46f20_Map
{
    int* FUN_00d46f20(int iKey);
};

struct FUN_00dbbe30_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    FUN_00d46f20_Map* m_map;

    int GetValueForKey(int iKey);
};

namespace fnv_00dbbe50 {
class hkBaseDBBE
{
  public:
    virtual ~hkBaseDBBE() throw()
    {}
};

class hkMemoryAllocatorXdbbe50
{
  public:
    virtual ~hkMemoryAllocatorXdbbe50() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterXdbbe50
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXdbbe50* m_pStreamAllocator;

    hkMemoryAllocatorXdbbe50& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterXdbbe50& __cdecl FUN_00c85750() throw();

class hkObjdbbe50 : public hkBaseDBBE
{
  public:
    hkObjdbbe50* FUN_00dbbe50(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkObjdbbe50*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

}  // namespace fnv_00dbbe50

namespace fnv_00dbbe80 {
struct FUN_00d46d40_s
{
    const char* FUN_00d46d40();
};

struct hkClassMemberDBBE
{
    const char* m_name;
    int m_class;
    int m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_iArraySize;
    unsigned short m_flags;
    unsigned short m_offset;

    bool flagsAllAreSet(unsigned short usMask) const
    {
        return (m_flags & usMask) == usMask;
    }
    int FUN_00d86940() const throw();
    FUN_00d46d40_s* FUN_00d86920() const throw();
    void* FUN_00d86960(const char* pcName) const throw();
};

struct hkDataWorldDBBE
{
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void V8() throw();
    virtual void* GetClassFromName(const char* pcName) throw();
};

struct FUN_00d871a0
{
    void* m_object;
    const void* m_pObjectTypeInfo;
    FUN_00d871a0(void* pvObject, const char* pcMember) throw();
    const char** FUN_00d87220(int iIndex) throw();
};

struct hkMemberInfoDBBE
{
    const char* m_name;
    const void* m_pOwnerObject;
    int m_type;
    void* m_valueClass;
    int m_arrayCount;
};

extern const char* DAT_011b7958;
int __cdecl GetShapeTypeFlags(int iType, int iSubType, FUN_00d46d40_s* pkClass, int iCount) throw();

struct hkDataClassNativeDBBE
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkDataWorldDBBE* m_pOwningWorld;

    void GetMemberInfo(const hkClassMemberDBBE& kMember, hkMemberInfoDBBE& kInfo) const throw();
};

}  // namespace fnv_00dbbe80

enum hkTypeDBC3
{
    TYPE_POINTER = 0x1d,
    TYPE_FLAGS = 0x21
};

struct hkClassMemberDBC3
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_type;
    hkTypeDBC3 getType() const
    {
        return (hkTypeDBC3)m_type;
    }
};

class hkVariantDBC3
{
  public:
    int unk00;
    int unk04;

    hkVariantDBC3(void* obj, void* name) throw()
    {
        FUN_00d871a0(obj, name);
    }
    void FUN_00d871a0(void* obj, void* name) throw();
    hkClassMemberDBC3* FUN_00d87370() throw();
    unsigned int* FUN_00d87220(int i) throw();
    unsigned int* FUN_00d87230(int i) throw();
};

class hkObjDBC3
{
  public:
    int unk00;
    int unk04;
    int unk08;
    char m_data[4];

    unsigned int GetMemberValue(void* name);
};

namespace fnv_00dbc370 {
class hkClassMemberDBC3
{
  public:
    enum Type
    {
        TYPE_VOID,
        TYPE_BOOL,
        TYPE_CHAR,
        TYPE_INT8,
        TYPE_UINT8,
        TYPE_INT16,
        TYPE_UINT16,
        TYPE_INT32,
        TYPE_UINT32,
        TYPE_INT64,
        TYPE_UINT64,
        TYPE_REAL,
        TYPE_VECTOR4,
        TYPE_QUATERNION,
        TYPE_MATRIX3,
        TYPE_ROTATION,
        TYPE_QSTRANSFORM,
        TYPE_MATRIX4,
        TYPE_TRANSFORM,
        TYPE_ZERO,
        TYPE_POINTER,
        TYPE_FUNCTIONPOINTER,
        TYPE_ARRAY,
        TYPE_INPLACEARRAY,
        TYPE_ENUM,
        TYPE_STRUCT,
        TYPE_SIMPLEARRAY,
        TYPE_HOMOGENEOUSARRAY,
        TYPE_VARIANT,
        TYPE_CSTRING,
        TYPE_ULONG,
        TYPE_FLAGS
    };
    const char* m_name;
    const void* m_class;
    const void* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_iArraySize;
    unsigned short m_flags;
    unsigned short m_offset;
    const void* m_pCustomAttributes;

    Type getType() const
    {
        return (Type)m_type;
    }
    Type getSubType() const
    {
        return (Type)m_eSubtype;
    }
};

struct hkVariantDBC3
{
    void* m_object;
    const void* m_class;
};

class hkClassMemberAccessorDBC3
{
  public:
    void* m_pTargetObject;
    const hkClassMemberDBC3* m_kMemberDescriptor;

    void FUN_00d871a0(hkVariantDBC3& kObject, const hkClassMemberDBC3* pkMember) throw();
    hkClassMemberAccessorDBC3(hkVariantDBC3& kObject, const hkClassMemberDBC3* pkMember)
    {
        FUN_00d871a0(kObject, pkMember);
    }

    const hkClassMemberDBC3& FUN_00d87370() const throw();
    signed char& FUN_00d872e0(int iIndex) throw();
    unsigned char& FUN_00d872f0(int iIndex) throw();
    short& FUN_00d872c0(int iIndex) throw();
    unsigned short& FUN_00d872d0(int iIndex) throw();
    int& FUN_00d87270(int iIndex) throw();
    unsigned int& FUN_00d87280(int iIndex) throw();
    __int64& FUN_00d87290(int iIndex) throw();
    unsigned __int64& FUN_00d872a0(int iIndex) throw();
    unsigned long& FUN_00d872b0(int iIndex) throw();
};

class hkDataObjectNativeDBC3
{
  public:
    void* m_ppVirtualMethodTable;
    int m_04;
    int m_08;
    hkVariantDBC3 m_object;

    __int64 GetMemberValueAsInt64(const hkClassMemberDBC3* pkHandle) throw();
};

}  // namespace fnv_00dbc370

struct FUN_00c85750_Result
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    class FUN_00dba490_heap* m_10;
};

struct FUN_00c85750_Class
{
    int __thiscall FUN_00c85750();
};

class FUN_00dba490_heap
{
  public:
    virtual void h_slot0();
    virtual void h_slot1();
    virtual void h_slot2();
    virtual void h_slot3();
    virtual void h_freeBlock(int param, int size);
};

struct FUN_00dba490_class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;

    void FUN_00dba490();
};

class hkMemoryAllocatorDBB6
{
  public:
    virtual ~hkMemoryAllocatorDBB6() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
};

struct hkMemoryRouterDBB6
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDBB6* m_pStreamAllocator;

    hkMemoryAllocatorDBB6& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterDBB6 {
extern "C" hkMemoryRouterDBB6& __cdecl FUN_00c85750() throw();
}

class hkRefObjDBB6
{
  public:
    virtual ~hkRefObjDBB6() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjDBB6() throw()
    {
        m_sReferenceCount = 0;
    }

    static void* operator new(unsigned int nbytes)
    {
        hkRefObjDBB6* b = static_cast<hkRefObjDBB6*>(hkRouterDBB6::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

class hkStringDBB6
{
  public:
    void FUN_00d873d0(const hkStringDBB6& other) throw();
    int unk00;
    int unk04;
};

class hkStringFnDBB6
{
  public:
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual int strLen(const char* s);
};

struct hkNameDescDBB6
{
    const char* m_name;
    int m_len;
};

class hkLibDBB6;

class hkResourceDBB6 : public hkRefObjDBB6
{
  public:
    int m_08;

    hkResourceDBB6() throw() : m_08(0)
    {}
    virtual ~hkResourceDBB6() throw();
};

class hkNodeDBB6 : public hkResourceDBB6
{
  public:
    hkStringDBB6 m_name;
    hkLibDBB6* m_pOwnerObject;

    hkNodeDBB6() throw()
    {}
    virtual ~hkNodeDBB6() throw();
};

class hkNodeRefDBB6
{
  public:
    void FUN_00dba760(hkNodeDBB6* node) throw();
    hkNodeDBB6* m_node;
};

class hkLibDBB6
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStringFnDBB6* m_pStringFunctions;

    int unk10[4];
    hkStringDBB6 m_name;

    hkNodeRefDBB6 FUN_00dbb620();
};

// Returns 0.0f.
// @fnv 0x00dbba10
float __stdcall FUN_00dbba10(void* pArg)
{
    return 0.0f;
}

struct FUN_00d470f0_Obj
{
    unsigned char* __thiscall GetLastNodeFlag(unsigned char* flag);
};

struct HKDBB50Handle
{
    void* m_pObject;
    int m_iClass;
};

struct FUN_00dbba50_Obj
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    FUN_00d470f0_Obj* m_10;

    HKDBB50Handle* __thiscall GetHandle(HKDBB50Handle* __restrict handle);
};

struct FUN_00d871a0
{
    int m_00;
    int m_04;
    FUN_00d871a0(void* pair, int x);
    void* FUN_00d87200();
};

struct FUN_00dbbb60_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    void* __thiscall FUN_00dbbb60(int a, int b);
};

struct ComponentDescDBC5C0
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_type;
};
struct StreamDBC5C0;
struct AccessorDBC5C0
{
    AccessorDBC5C0(StreamDBC5C0* pkStream, int iIndex);
    const ComponentDescDBC5C0* GetDesc();
    const float* FUN_00d87250(int iComponent);
    const short* FUN_00d87260(int iComponent);
    int m_iA;
    int m_iB;
};
struct StreamDBC5C0
{
    int unk00;
};
struct VertexDataDBC5C0
{
    int unk00;
    int unk04;
    int unk08;
    StreamDBC5C0 m_kVertexStream;
    float GetFloat(int iIndex);
};

extern "C" int __cdecl Vsnprintf(char* pcBuffer, unsigned int uSize, const char* pcFormat, ...);
extern const char str_010a5824[];
extern "C" int __cdecl FUN_00cb10d0(const char* s);
struct WriterC12
{
    virtual void write(const char* s, int len) throw();
};
static __declspec(noinline) void FUN_00cc0080(WriterC12* pkWriter, const char* pcString)
{
    if (pcString == 0)
        pkWriter->write("(null)", 6);
    else
        pkWriter->write(pcString, FUN_00cb10d0(pcString));
}
// @fnv 0x00cc0120
hkOstreamDBB7& hkOstreamDBB7::FUN_00cc0120(const void* pvPointer) throw()
{
    int buffer[2506];
    Vsnprintf((char*)buffer, 0x2728u, str_010a5824, pvPointer);
    FUN_00cc0080((WriterC12*)m_uiLogicalSize, (const char*)buffer);
    return *this;
}

namespace dbb {
struct Pair
{
    int a;
    int b;
};
}
void DbbExtern(void*);

struct DbbOwner
{
    int unk00;
    int unk04;
    void __thiscall FUN_00dbb4f0(int a, int b);
};

struct Input680
{
    void* FUN_00dba680();
};
struct Size680
{
    int FUN_00d470d0();
};
struct Dispatch680
{
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void RunFourthVirtual();
    virtual void* v4(void* a);
    virtual void q5();
    virtual void RunSeventhVirtualOperation();
    virtual void* v7(void* a);
    virtual void q8();
    virtual void* q9(const char* s);
};
struct Manager680
{
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual Dispatch680* RunFourthVirtual();
};
typedef void(__cdecl* Callback680)(void*, int);
struct CallbackEntry680
{
    void* object;
    Callback680 callback;
};
struct Pair680
{
    void* a;
    FUN_00d46d40_s* b;
};
struct Resolved680
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00d46d40_s* descriptor;
};
struct Node680
{
    void* vtable;
    unsigned short size;
    unsigned short refs;
    int unk08;
    hkStringDBB6 name;
    Dispatch680* owner;
};
extern const char DAT_010d64bc[], DAT_010d64d0[], DAT_010d64dc[], DAT_010d6394[];
extern int DAT_010d6334;
extern "C" void FUN_00cb1280(void*, int, int);

struct Owner680
{
    int unk00;
    int unk04;
    Dispatch680* dispatch;
    void FUN_00dbb680(Input680* input);
};
struct RawDispatch680;
typedef void*(__thiscall* DispatchFn680)(RawDispatch680*, void*);
struct DispatchTable680
{
    DispatchFn680 q0, q1, q2, RunFourthVirtual, v4, q5, RunSeventhVirtualOperation, v7;
};
struct RawDispatch680
{
    DispatchTable680* table;
};

void __cdecl ResizeAudioStream(void* allocator, void* array, int elemSize) throw();
void* __fastcall FUN_00d47280(void* item) throw();

struct Allocator_s
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void free(void* p, int nbytes) throw();
};

template <typename T> __forceinline void constructWithCopyRange(T* p, int n, const T& t) throw()
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArray() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(int(0x80000000))
    {}

    ~hkArray() throw()
    {
        FUN_00dbc640_router* router = _D1A0E0GetMemoryRouter();
        void* alloc = router->m_10;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & int(0x80000000)) == 0)
        {
            ((Allocator_s*)alloc)->free(m_data, (cap & 0x3FFFFFFF) * sizeof(T));
        }
    }

    T& operator[](int i) throw()
    {
        return m_data[i];
    }

    void AddBack(const T& item) throw()
    {
        FUN_00dbc640_router* router = _D1A0E0GetMemoryRouter();
        if (m_iElementCount == (m_iCapacityState & 0x3FFFFFFF))
        {
            ResizeAudioStream(router->m_10, this, sizeof(T));
        }
        constructWithCopyRange(m_data + m_iElementCount, 1, item);
        m_iElementCount++;
    }
};

// local members list (same layout/semantics as hkArray, used for the loop scan)
template <typename T> struct MemberArrLcl
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    MemberArrLcl() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(int(0x80000000))
    {}

    ~MemberArrLcl() throw()
    {
        FUN_00dbc640_router* router = _D1A0E0GetMemoryRouter();
        void* alloc = router->m_10;
        int cap = m_iCapacityState;
        m_iElementCount = 0;
        if ((cap & int(0x80000000)) == 0)
        {
            ((Allocator_s*)alloc)->free(m_data, (cap & 0x3FFFFFFF) * sizeof(T));
        }
    }

    T& operator[](int i) throw()
    {
        return m_data[i];
    }
    int GetLogicalSize() const throw()
    {
        return m_iElementCount;
    }
};

struct TargetClass
{
    virtual void t0() throw();
    virtual void t1() throw();
    virtual void t2() throw();
    virtual void t3() throw();
    virtual void t4() throw();
    virtual void getDeclaredMembers(MemberArrLcl<FUN_00d46d40_s*>* out) throw();
};

struct FUN_00dbb840_class
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual void v7() throw();
    virtual void v8() throw();
    virtual FUN_00d46d40_s* getMemberHandle(const char* name) throw();

    int unk04;
    TargetClass* m_class;

    void FUN_00dbb840(hkArray<FUN_00d46d40_s*>& out) throw();
};

struct MemberDBC0
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_iFlags;
    unsigned short m_flags;
    unsigned short m_offset;
    int FUN_00d86940() throw();
    int FUN_00d86920() throw();
};
struct ClassDBC0
{
    MemberDBC0* FUN_00d46fe0(int index);
};
struct ObjectDBC0
{
    int unk00;
    int unk04;
    int unk08;
    int m_pOwningWorld;
    char* m_data;
    int m_iElementCount;
    int m_iElementIndex;
    int unk1c;
    ClassDBC0* m_class;
    FUN_00dbbb90* FUN_00dbc0c0(int index);
};

struct S00dbc150_ClassDef
{
    int FUN_00d470d0();
};

struct S00dbc150_Member
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_carraySize;

    S00dbc150_ClassDef* FUN_00d86920();
    int FUN_00d86940();
};

struct S00dbc150_Pair
{
    void* m_data;
    S00dbc150_Member* m_kMemberDescriptor;

    S00dbc150_Pair(void* obj, const char* name)
    {
        FUN_00d871a0(obj, name);
    }
    void FUN_00d871a0(void* obj, const char* name);
    void* FUN_00d87200();
    S00dbc150_Member* FUN_00d87370();
};

struct S00dbc150_HomArray
{
    S00dbc150_ClassDef* m_pObjectTypeInfo;
    void* m_data;
    int m_iElementCount;
};

struct S00dbc150_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_14;

    FUN_00dbbb90* FUN_00dbc150(const char* name);
};

int __cdecl GetShapeTypeFlags(int a, int b, int c, int d);
extern int DAT_010d642c[];

struct S00dbbb90_Obj
{
    int* m_00;
    unsigned short unk04;
    unsigned short m_06;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    S00dbbb90_Obj* FUN_00dbbb90(int a1, int a2, int a3, int a4, int a5, int a6, int a7);
};

// Initializes S00dbbb90_Obj fields from a1-a7, sets m_00 to DAT_010d642c, and computes m_24 from GetShapeTypeFlags.
// @fnv 0x00dbbb90
S00dbbb90_Obj* S00dbbb90_Obj::FUN_00dbbb90(int ai0c, int ai10, int ai14, int ai18, int ai1c, int ai20, int ai28)
{
    m_06 = 0;
    m_08 = 0;
    m_0c = ai0c;
    m_10 = ai10;
    m_14 = ai14;
    m_18 = ai18;
    m_00 = DAT_010d642c;
    m_1c = ai1c;
    m_20 = ai20;
    m_28 = ai28;
    int r = GetShapeTypeFlags(0x16, ai1c, ai20, ai28);
    m_24 = (r > 0x10) ? (r - 0x10) : 0x10;
    return this;
}

extern "C" void _ReadWriteBarrier();
struct VariantC4D0
{
    int m_00;
    int m_04;
    void FUN_00d871a0(void* obj, int name);
    int* FUN_00d87370();
    int* FUN_00d87360(int a);
    void* FUN_00d87200();
    char* FUN_00d87210(int a);
};
struct MemberC4D0
{
    int m_00;
    int m_04;
    int m_08;
    unsigned char m_type;
    int FUN_00d86920();
};
extern "C" int dummy_call(int a);
struct TailC4D0
{
    int FUN_00dbb260();
};
struct PairC4D0
{
    int lo;
    int hi;
    void FUN_00d873d0(const PairC4D0& other);
};
struct NativeC4D0
{
    int m_00, m_04, m_08;
    PairC4D0 value;
    int* world;
};
struct ClassC4D0
{
    const char* FUN_00d46d40();
};
struct FoundClassC4D0
{
    int m_00, m_04, m_08;
    int classValue;
};
struct WorldC4D0
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual FoundClassC4D0* GetClassFromName(const char* name);
};
extern NativeC4D0* allocateNativeC4D0();
extern void warnNativeC4D0(int, int);
struct FUN_00dbc4d0_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int* m_14;

    int __thiscall FUN_00dbc4d0(int name);
};

struct NativeVariant
{
    void* object;
    void* pClassInfo;
};
hkClassDBB7* volatile inputClass;
hkVtableClassRegistryDBB7* volatile inputRegistry;
hkDataWorldNativeDBB7* volatile inputWorld;
void* volatile inputObject;
void* volatile outputObject;
void* volatile outputClass;
extern hkErrorDBB7* DAT_01268360;

namespace fnv_00dbb520 {
extern int DAT_010d62fc;
struct Source
{
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void* vf10(void*);
};
struct Allocator
{
    virtual void a();
    virtual void* allocate(unsigned int);
};
struct Router
{
    int a, b, c, d;
    Allocator* allocator;
};
Router* __cdecl FUN_00c85750();
struct Index
{
    void* __thiscall GetValue(void*, void*);
    void __thiscall FUN_00d874d0(void*, void*);
};
struct Record
{
    void* type;
    unsigned short byteSize;
    unsigned short flags;
    unsigned int state;
    void* reference;
    void* owner;
};
struct Object
{
    int a, b;
    Source* source;
    int d;
    Index index;
    Record* __thiscall FUN_00dbb520(void*);
};
}  // namespace fnv_00dbb520

struct NativeMemberReferenceDBBA
{
    int object;
    int name;

    NativeMemberReferenceDBBA(int owner, int memberName) : object(owner), name(memberName)
    {}
};

struct C_dbbab0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;

    NativeMemberReferenceDBBA __thiscall FUN_00dbbab0(int param_1);
};

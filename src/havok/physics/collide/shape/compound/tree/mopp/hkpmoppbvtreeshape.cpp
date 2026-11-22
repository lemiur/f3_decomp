#include "f3_common.h"
// src/havok/physics/collide/shape/compound/tree/mopp/hkpmoppbvtreeshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/tree/mopp/hkpmoppbvtreeshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpMoppBvTreeShape.h"

struct FUN_00d54420_Interface
{
// @fnv 0x00d54420
    virtual ~FUN_00d54420_Interface()
    {}
    virtual void FUN_00d54420_f0() = 0;
    virtual void FUN_00d54420_f1() = 0;
    virtual void FUN_00d54420_f2() = 0;
    virtual void FUN_00d54420_f3() = 0;
    virtual void FUN_00d54420_f4() = 0;
    virtual void FUN_00d54420_f5(int, float, int) = 0;
    virtual void FUN_00d54420_f6(int, float, int) = 0;
};

struct FUN_00d54420_Owner
{
    virtual void FUN_00d54420_virtual() = 0;

    unsigned char padding[0x30];
    FUN_00d54420_Interface* m_pInterface;

    void FUN_00d54420(int, float, int);
};

void FUN_00d54420_Owner::FUN_00d54420(int a, float b, int c)
{
    m_pInterface->FUN_00d54420_f6(a, b, c);
}

struct hkReferencedObject
{
    void RetainReference();
};

extern int DAT_010c6fd0;
extern int DAT_010d0dac;

struct FUN_00d54490
{
    FUN_00d54490(int, int);
};

struct FUN_00d544f0 : public FUN_00d54490
{
    FUN_00d544f0(hkReferencedObject*, int);
};

struct FUN_00d54930MemoryManager
{
    virtual void ReportDiagnostic() = 0;
    virtual void unused1() = 0;
    virtual void Free(void* object, unsigned short size) = 0;
};

struct FUN_00d54930MemoryRouter
{
    unsigned char padding[0x10];
    FUN_00d54930MemoryManager* manager;
};

FUN_00d54930MemoryRouter* _D1A0E0GetMemoryRouter();

struct FUN_00d54930Object
{
    virtual void ReportDiagnostic() = 0;

    unsigned short m_iElementCount;

    void FUN_00d543e0();
    FUN_00d54930Object* Destroy(unsigned char flags);
};

class hkClassD543;

extern const hkClassD543 DAT_01269c8c;

class hkStatisticsCollectorD543
{
  public:
    virtual ~hkStatisticsCollectorD543() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass) throw();
};

class hkpShapeD543
{
  public:
    void FUN_00c90360(hkStatisticsCollectorD543* pkCollector, const hkClassD543* pkClass) const throw();
};

class hkpSingleShapeContainerD543 : public hkpShapeD543
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    const void* m_pMoppCode;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    const void* m_pContainedShape;

    void AddShapeChildrenToCollector(hkStatisticsCollectorD543* pkCollector, const hkClassD543* pkClass) const throw();
};

struct __declspec(align(16)) FUN_00dd1bf0_Obj
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

    void __thiscall FUN_00dd1bf0(void* target, int a, int b, float c, int d);
};

struct FUN_00d54350_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    void* unk14;

    void __thiscall ForwardToTarget(int a, int b, float c, int d);
};

// @f3 0x009e1be0 (community match, verified in this file)
struct FUN_00dd1bf0_ObjF3
{
    void __thiscall FUN_00a52bd0(void* target, int a, int b, float c, int d);
};
void __thiscall FUN_00d54350_Obj::ForwardToTarget(int a, int b, float c, int d)
{
    FUN_00dd1bf0_Obj local;
    ((FUN_00dd1bf0_ObjF3*)&local)->FUN_00a52bd0(*(void**)((char*)this + 0x10), a, b, c, d);
}


namespace fnv_00d543e0 {
struct FUN_00c905b0_s
{
    void FUN_00c905b0() throw();
};

class hkReferencedObjectD543
{
  public:
    virtual ~hkReferencedObjectD543() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShapeD543 : public hkReferencedObjectD543
{
  public:
    unsigned long m_ulUserData;
    unsigned int m_type;
};

class hkMoppBvTreeShapeBaseD543 : public hkpShapeD543
{
  public:
    ~hkMoppBvTreeShapeBaseD543() throw()
    {
        m_pMoppCode->FUN_00c905b0();
    }

    int m_10;
    FUN_00c905b0_s* m_pMoppCode;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
};

class hkpShapeContainerD543
{
  public:
    virtual ~hkpShapeContainerD543() throw()
    {}
};

class hkpSingleShapeContainerD543 : public hkpShapeContainerD543
{
  public:
    FUN_00c905b0_s* m_pContainedShape;

    ~hkpSingleShapeContainerD543() throw()
    {
        if (m_pContainedShape)
            m_pContainedShape->FUN_00c905b0();
    }
};

class FUN_00d543e0 : public hkMoppBvTreeShapeBaseD543
{
  public:
    virtual ~FUN_00d543e0() throw();

    hkpSingleShapeContainerD543 m_pChildAtom;
};

// @fnv 0x00d543e0
FUN_00d543e0::~FUN_00d543e0() throw()
{}
}  // namespace fnv_00d543e0

class hkMemoryAllocatorD548
{
  public:
    virtual ~hkMemoryAllocatorD548() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD548
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD548* m_pStreamAllocator;
    hkMemoryAllocatorD548& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD548& __cdecl FUN_00c85750();

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

class hkReferencedObjectD548
{
  public:
    virtual ~hkReferencedObjectD548() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkReferencedObjectD548*>(p)->m_usMemSizeAndFlags);
    }
};

class hkpShapeD548 : public hkReferencedObjectD548
{
  public:
    hkUlong m_ulUserData;
    hkUint32 m_type;
};

class hkpSingleChildShapeD548 : public hkpShapeD548
{
  public:
    int m_10;
    FUN_00d1df70* m_pContainedShape;

    virtual ~hkpSingleChildShapeD548() throw()
    {
        m_pContainedShape->removeReference();
    }
    hkpSingleChildShapeD548* FUN_00d548f0(unsigned int uiFlags) throw();
};

struct S00d54440_Child
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    volatile unsigned char m_2C;
};

struct S00d54440_Vtable
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6(int, int);
};

struct S00d54440_Obj
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    S00d54440_Child* m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    int m_30;
    S00d54440_Vtable* m_34;
    int m_38;

    int FUN_00d54440(int, int);
};

// Returns -1 unless m_14->m_2C is 0 and m_34->v6(a, 0x100) is within 0..0x100; otherwise stores it in m_38 and returns 0x40.
// @f3 0x009e1dd0 (community match, verified in this file)
struct Status427 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned char state;
};
struct Reader427 {
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual int Read(int argument, int capacity);
};
struct Layout427 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    Status427* status;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    Reader427* reader;
    int pending;
    unsigned int unk3C;
    Reader427 inlineReader;
};
int S00d54440_Obj::FUN_00d54440(int argument, int bytes) {
    Layout427* self = reinterpret_cast<Layout427*>(this);
    if (self->status->state == 1)
        return -1;
    int capacity = bytes - 64;
    int result = self->reader->Read(argument, capacity);
    if (result < 0) return -1;
    if (result > capacity) return -1;
    if (self->reader == &self->inlineReader) {
        self->pending = 0;
        return result + 64;
    }
    self->pending = result;
    return 64;
}


#include <xmmintrin.h>
extern char DAT_010d0d70;
struct S00d54490_Ref
{
    void FUN_00c90510();
};
struct S00d54490_Obj
{
    void* volatile unk00;
    unsigned char unk04;
    unsigned char unk05;
    unsigned short volatile unk06;
    int volatile unk08;
    int unk0C;
    volatile unsigned char unk10;
    void* unk14;
    int unk18;
    int unk1C;
    float unk20[4];
    S00d54490_Obj* __thiscall FUN_00d54490(int arg1, const hkpMoppBvTreeShape& arg2);
};

namespace fnv_00d54520 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern unsigned long DAT_0126835c;
extern const char str_010d0de4[];
extern const char str_010c41f8[];
struct S54520_Mon
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_cap;
    char* m_capMinus16;
};
struct S54520_Timer
{
    const char* m_name;
    unsigned int m_ticks;
    unsigned int m_unk08;
};
struct S54520_Out
{
    char m_flag;
};
struct S54520_Params
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_slots[8];
    int m_depth;
};
struct S54520_Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct S54520_Box
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    __m128 m_vComponents;
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    char m_kind;
};
struct __declspec(align(16)) S54520_Work
{
    __m128 m_kShapeVectorData[4];
    int m_z0;
    int m_z1;
    int t48;
    int t4c;
    int t50;
    int t54;
    int t58;
    int t5c;
    int t60;
    int t64;
    void FUN_00dd2df0(S54520_Out*, S54520_Sub*, S54520_Box*, int, S54520_Params*);
};
struct S54520_Frame
{
    unsigned int m_codeStorage[16];
    S54520_Work m_vm;
};
struct S54520_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int m_kPointA;
    int m_kPointB;
    __m128 m_vComponents;
    int unk30;
    S54520_Sub* m_sub;
    S54520_Out* FUN_00d54520(S54520_Out* out, int p1, S54520_Params* params);
};
}  // namespace fnv_00d54520

extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);
extern unsigned long DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern const int DAT_010c92e0[4];

extern "C" const char str_010d0df0[];
extern "C" const char str_010c41f8[];

struct hkTimerCommandD546
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
    void setTime()
    {
        _ReadWriteBarrier();
        volatile unsigned int uiTicks = (unsigned int)__rdtsc();
        m_uiStartTicks = uiTicks;
    }
};

struct hkMonitorStreamD546
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_capacityMinusReserve;
    static hkMonitorStreamD546& GetMonitorStream()
    {
        return *(hkMonitorStreamD546*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_capacityMinusReserve;
    }
    char* GetStreamEnd()
    {
        return m_kRayEnd;
    }
    void setEnd(char* p)
    {
        m_kRayEnd = p;
    }
};

__forceinline void timerD546(const char* pcCommand)
{
    hkMonitorStreamD546& kStream = hkMonitorStreamD546::GetMonitorStream();
    if (kStream.memoryAvailable())
    {
        hkTimerCommandD546* h = reinterpret_cast<hkTimerCommandD546*>(kStream.GetStreamEnd());
        h->m_pCommandName = pcCommand;
        h->setTime();
        kStream.setEnd((char*)(h + 1));
    }
}

struct __declspec(align(16)) hkVector4D546
{
    float x, y, z, w;
    const __m128& getQuad() const
    {
        return *(const __m128*)&x;
    }
    __m128& getQuad()
    {
        return *(__m128*)&x;
    }
};

struct hkVector4ComparisonD546
{
    union
    {
        __m128 m_uiMask;
        unsigned int m_int[4];
        float m_float[4];
    };
    int anyIsSet(int iMask) const
    {
        return _mm_movemask_ps(m_uiMask) & iMask;
    }
};

struct hkpShapeRayCastOutputD546
{
    hkVector4D546 m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int m_18;
    int m_1c;
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    const void* m_pRootCollidable;
    int m_48;
    int m_4c;

    void changeLevel(int iDelta)
    {
        m_uiShapeKeyIndex += iDelta;
    }
    void setKey(unsigned int uiKey)
    {
        m_uiShapeKeys[m_uiShapeKeyIndex] = uiKey;
    }
};

struct hkpShapeRayBundleCastOutputD546
{

    hkpShapeRayCastOutputD546 m_akRayOutputs[4];
};

struct hkpShapeRayBundleCastInputD546;

struct hkpShapeContainerD546
{
    void* m_ppVirtualMethodTable;
};

struct hkpShapeD546
{
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    int m_ulUserData;
    int m_type;
};

struct hkpShapeCollectionD546 : public hkpShapeD546, public hkpShapeContainerD546
{
};

struct hkpMoppCodeD546
{
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    int m_08;
    int m_0c;
    hkVector4D546 m_offset;
    unsigned char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    unsigned char m_eBuildType;
};

struct hkpMoppRayBundleVirtualMachineD546
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
    int m_20, m_24, m_28, m_2c, m_30, m_34, m_38, m_3c;
    int m_40, m_44, m_48, m_4c, m_50, m_54, m_58, m_5c;
    int m_60, m_64, m_68, m_6c, m_70, m_74, m_78, m_7c;
    int m_80, m_84, m_88, m_8c, m_90, m_94, m_98, m_9c;
    int m_a0, m_a4, m_a8, m_ac, m_b0, m_b4, m_b8, m_bc;
    int m_c0, m_c4, m_c8, m_cc, m_d0, m_d4, m_d8, m_dc;
    hkVector4ComparisonD546 FUN_00dd4870(const hkpShapeContainerD546* pkCollection, const hkpMoppCodeD546* pkCode,
                                         const hkpShapeRayBundleCastInputD546& kInput,
                                         hkpShapeRayBundleCastOutputD546& kResults,
                                         const hkVector4ComparisonD546& kRayMask) throw();
};

class hkpMoppBvTreeShapeD546
{
  public:
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    int m_ulUserData;
    int m_type;
    int m_uiUserData;
    const hkpMoppCodeD546* m_pMoppCode;
    unsigned char* m_pMoppData;
    int m_uiMoppDataSize;
    hkVector4D546 m_kMoppCodeInfo;
    void* m_childVtable;
    const hkpShapeD546* m_pContainedShape;
    int m_iChildSize;
    int m_3c;

    hkVector4ComparisonD546 FUN_00d54610(const hkpShapeRayBundleCastInputD546& kInput,
                                         hkpShapeRayBundleCastOutputD546& kResults,
                                         const hkVector4ComparisonD546& kRayMask) const throw();
};

extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern void* DAT_00fdf044;
extern unsigned long DAT_0126835c;
extern "C" const char str_010c41f8[];
extern char str_010d0de4;
struct S00d54720_Record
{
    const char* name;
    unsigned int ticks;
    unsigned int unk08;
};
struct S00d54720_Monitor
{
    void* unk00;
    S00d54720_Record* current;
    void* unk08;
    S00d54720_Record* end;
};
typedef S00d54720_Monitor*(__stdcall* S00d54720_GetFn)(unsigned long);
struct S00d54720_Body
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
};
struct S00d54720_Info
{
    __m128 value;
    S00d54720_Info& operator=(const S00d54720_Info& other)
    {
        value = other.value;
        return *this;
    }
};
struct S00d54720_Code
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    S00d54720_Info info;
    void* data;
    int size;
    int capacity;
    volatile unsigned char flags;
};
struct S00d54720_CodeBuf
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
};
struct S00d54720_Vm
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    int unk40;
    int unk44;
    void* unk48;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6c;
    void FUN_00dd2ed0(const void* code, const S00d54720_Code* info, const void* input, const S00d54720_Body* body,
                      void* collector);
};
struct S00d54720_Frame
{
    S00d54720_Body body;
    S00d54720_CodeBuf codePtrBuffer;
};
struct S00d54720_Container
{
    void* vtable;
};
struct S00d54720_ChildShape
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00d54720_Container container;
};
struct S00d54720_MoppShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    void* unk14;
    void* m_pMoppData;
    int m_uiMoppDataSize;
    S00d54720_Info m_kMoppInfo;
    int unk30;
    S00d54720_ChildShape* m_pContainedShape;
    void FUN_00d54720(const void* a0, const void* cdBody, void* collector);
};
// Wraps a FUN_00dd2ed0 call in two timer records, passing the MOPP data and info, the contained shape's container, a0, a body built from cdBody, and collector.
// @f3 0x009e1fd0 (community match, verified in this file)
struct __declspec(align(16)) S00d54720_VmF3
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2c;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3c;
    int unk40;
    int unk44;
    void* unk48;
    void* unk4c;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5c;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6c;
    void FUN_00a54420(const void* container, const void* code, const void* input, const S00d54720_Body* body, void* collector);
};
void S00d54720_MoppShape::FUN_00d54720(const void* apInput, const void* cdBody, void* collector)
{
    timerD546("TtrcMopp");
    {
        S00d54720_Body body;
        S00d54720_VmF3 vm;

        body.unk0c = (void*)cdBody;
        body.unk08 = ((const S00d54720_Body*)cdBody)->unk08;
        S00d54720_ChildShape* child = m_pContainedShape;
        vm.unk40 = 0;
        vm.unk44 = 0;
        body.unk00 = child;
        body.unk04 = 0;
        vm.FUN_00a54420(child ? &child->container : 0, (const void*)unk10, apInput, &body, collector);
    }
    timerD546("Et");
}


#include <xmmintrin.h>
namespace fnv_00d54380 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    };
};

extern "C" __m128 _mm_load_ps1(const float* p);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_max_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_min_ps(__m128 a, __m128 b);

struct hkVector4D543
{
    __m128 m_vComponents;

    void SetAllComponents(float f)
    {
        m_vComponents = _mm_load_ps1(&f);
    }
    void add4(const hkVector4D543& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    void setMax4(const hkVector4D543& a, const hkVector4D543& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    void setMin4(const hkVector4D543& a, const hkVector4D543& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(&m_vComponents)[i];
    }
};

struct hkAabbD543
{
    hkVector4D543 m_kMinimumCorner;
    hkVector4D543 m_kMaximumCorner;
};

template <class T> struct hkArrayD543
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class hkpMoppCodeD543;

struct hkMoppObbVirtualMachineD543
{
    __declspec(noalias) void FUN_00dd1da0(const hkpMoppCodeD543* pkCode, const hkAabbD543& kAabb,
                                          hkArrayD543<unsigned int>* pkHits);

    unsigned int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    unsigned int unk30, unk34, unk38, unk3C;
};

class hkBaseObjectD543
{
  public:
    virtual ~hkBaseObjectD543() throw();
};

class hkReferencedObjectD543 : public hkBaseObjectD543
{
  public:
    virtual ~hkReferencedObjectD543() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class ShapeBaseD543 : public hkReferencedObjectD543
{
  public:
    virtual ~ShapeBaseD543() throw();

    unsigned long m_ulUserData;
    unsigned int m_type;
};

class hkpBvTreeShapeD543 : public ShapeBaseD543
{
  public:
    virtual ~hkpBvTreeShapeD543() throw();

    unsigned char m_uiUserData;
};

class hkpMoppBvTreeShapeD543 : public hkpBvTreeShapeD543
{
  public:
    virtual ~hkpMoppBvTreeShapeD543() throw();

    void FUN_00d54380(const hkAabbD543& kAabbIn, hkArrayD543<unsigned int>& kHits) const;

    const hkpMoppCodeD543* m_pMoppCode;
    void* m_pMoppData;
    unsigned int m_uiMoppDataSize;
    hkVector4D543 m_kMoppCodeInfo;
};

}  // namespace fnv_00d54380

#include "f3_common.h"
// src/havok/physics/collide/shape/misc/transform/hkptransformshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/misc/transform/hkptransformshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpTransformShape.h"

struct FUN_00cf5900
{
    int calc(int a2, int a3);
};

class hkClassCF58;

extern const hkClassCF58 DAT_01268910;

class hkStatisticsCollectorCF58
{
  public:
    virtual ~hkStatisticsCollectorCF58() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass) throw();
};

class hkpShapeCF58
{
  public:
    void FUN_00c90360(hkStatisticsCollectorCF58* pkCollector, const hkClassCF58* pkClass) const throw();
};

class hkpSingleShapeContainerCF58 : public hkpShapeCF58
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    const void* m_pContainedShape;

    void AddChildShapeToCollector(hkStatisticsCollectorCF58* pkCollector, const hkClassCF58* pkClass) const throw();
};

struct FnvCpu_FUN_00cf58f0_CpuObject
{
    char* FUN_00cf58f0();
};
// @fnv 0x00cf58f0
char* FnvCpu_FUN_00cf58f0_CpuObject::FUN_00cf58f0()
{
    return reinterpret_cast<char*>(this) + 16;
}

class hkMemoryAllocatorCF5E
{
  public:
    virtual ~hkMemoryAllocatorCF5E() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCF5E
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCF5E* m_pStreamAllocator;
    hkMemoryAllocatorCF5E& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterCF5E& __cdecl FUN_00c85750();

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

class hkReferencedObjectCF5E
{
  public:
    virtual ~hkReferencedObjectCF5E() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkReferencedObjectCF5E*>(p)->m_usMemSizeAndFlags);
    }
};

class hkpShapeCF5E : public hkReferencedObjectCF5E
{
  public:
    hkUlong m_ulUserData;
    hkUint32 m_type;
};

class hkpShapeContainerCF5E
{
  public:
    virtual ~hkpShapeContainerCF5E() throw()
    {}
};

class hkpSingleShapeContainerCF5E : public hkpShapeContainerCF5E
{
  public:
    FUN_00d1df70* m_pContainedShape;

    ~hkpSingleShapeContainerCF5E() throw()
    {
        if (m_pContainedShape)
            m_pContainedShape->removeReference();
    }
};

class hkpTransformShapeCF5E : public hkpShapeCF5E, public hkpSingleShapeContainerCF5E
{
  public:
    hkpTransformShapeCF5E* DestroyAndMaybeFree(unsigned int uiFlags) throw();
};

extern int DAT_010cc41c;
extern int DAT_010c6fd0;

struct FUN_00c90510_class
{
    void FUN_00c90510();
};

struct cf5990_TransformShape
{
    void* m_vtbl;                      // 0x00
    unsigned short unk04;              // 0x04 (memSizeAndFlags, untouched here)
    unsigned short m_sReferenceCount;  // 0x06
    unsigned int m_ulUserData;         // 0x08
    unsigned int m_type;               // 0x0c
    void* m_childContainerVtbl;        // 0x10
    hkpShape* m_pContainedShape;       // 0x14

    void CopyBlock(const hkTransform& transform);
    int FUN_00cf5990(hkpShape* child, const hkTransform& transform);
};

struct __declspec(align(16)) Quaternion
{
    float x, y, z, w;
};
struct PackedTransform
{
    Quaternion rotationColumn0;
    Quaternion rotationColumn1;
    Quaternion rotationColumn2;
    Quaternion translation;
    void FUN_00cb2240(int a, Quaternion* base);
};
struct Dispatch
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1c(PackedTransform* tmp, float factor, int flags);
};
struct FUN_00cf59e0_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Dispatch* dispatch;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Quaternion quaternion;
    void FUN_00cf59e0(int a, float factor, int flags);
};
// Builds a PackedTransform from a and quaternion, then forwards it to dispatch->vfn1c with factor and flags.
// @fnv 0x00cf59e0
void FUN_00cf59e0_Class::FUN_00cf59e0(int a, float factor, int flags)
{
    PackedTransform transformed;
    transformed.FUN_00cb2240(a, &quaternion);
    dispatch->vfn1c(&transformed, factor, flags);
}

#include <xmmintrin.h>
struct __declspec(align(16)) Vec4_cf5a
{
    float x, y, z, w;
};

class ConvexChild_cf5a
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual float getMaximumProjection(const Vec4_cf5a& direction) const;
};

class TransformShape_cf5a
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    ConvexChild_cf5a* m_pContainedShape;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_vTranslation;

    float FUN_00cf5a20(const __m128& direction);
};

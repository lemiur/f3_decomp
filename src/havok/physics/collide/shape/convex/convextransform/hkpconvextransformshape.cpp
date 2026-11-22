#include "f3_common.h"
// src/havok/physics/collide/shape/convex/convextransform/hkpconvextransformshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convextransform/hkpconvextransformshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConvexTransformShape.h"

extern const char* const g_01268970_arg1;

struct FUN_00d5d730_class
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(const char*, const char*, int);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    void FUN_00d5d730(FUN_00d5d730_class* pChild, const char* name);
};

struct FUN_00c90360_helper
{
    void FUN_00c90360(FUN_00d5d730_class* pChild, const char* const* name);
};

struct FUN_00d5e020_standin
{
    int FUN_00d5e020(int a, int b);
};

// @fnv 0x00d5e020
int FUN_00d5e020_standin::FUN_00d5e020(int a, int aiLimit)
{
    char* p = (char*)this;
    int iLimit = aiLimit - 0x60;
    int iResult =
        (*(int(__thiscall**)(void*, int, int))(*(int*)(*(int*)(p + 0x18)) + 0x18))(*(void**)(p + 0x18), a, iLimit);
    if (iResult < 0)
        return -1;
    if (iResult > iLimit)
        return -1;
    if (*(int*)(p + 0x18) == (int)(p + 0x60))
    {
        *(int*)(p + 0x1c) = 0;
        return iResult + 0x60;
    }
    *(int*)(p + 0x1c) = iResult;
    return 0x60;
}

struct Inner
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
    virtual void Tail();
};

struct FUN_00d5d720_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Inner* m_pInner;
    void FUN_00d5d720();
};

struct GetChildShapeHost : hkpConvexTransformShapeBase
{
    hkpSingleShapeContainer* FUN_00d5d760();
};

// @fnv 0x00d5d760
hkpSingleShapeContainer* GetChildShapeHost::FUN_00d5d760()
{
    return &m_pContainedShape;
}

struct Aabb_00d5d800;

struct Shape_00d5d800
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void getAabb(const hkTransform& t, float tol, Aabb_00d5d800& out) = 0;
};

struct Xf_00d5d800 : hkTransform
{
    void FUN_00cb2240(const hkTransform& a, const hkTransform& b);
};

struct Cls_00d5d800
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    hkpShape* m_pContainedShape;
    int unk1c;
    hkTransform m_kMotionTransform;
    void GetAabb(const hkTransform& t, float tol, Aabb_00d5d800& out);
};

// Combines t and m_kMotionTransform via FUN_00cb2240 and calls the contained shape's getAabb with the result, tol and out.
// @fnv 0x00d5d800
void Cls_00d5d800::GetAabb(const hkTransform& t, float tol, Aabb_00d5d800& out)
{
    __declspec(align(16)) Xf_00d5d800 tmp;
    tmp.FUN_00cb2240(t, m_kMotionTransform);
    reinterpret_cast<Shape_00d5d800*>(m_pContainedShape)->getAabb(tmp, tol, out);
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_load_ps(const float*);
    void _mm_store_ps(float*, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}

extern "C" unsigned long DAT_0126835c;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern const char str_010d1074[];
extern const char str_010c41f8[];

struct StringCursor
{
    int unk0;
    char* m_ptr;
    int unk8;
    char* m_kRayEnd;
};

struct hkBoolResult
{
    char m_cBooleanValue;
    hkBoolResult()
    {}
    hkBoolResult(const hkBoolResult& o) : m_cBooleanValue(o.m_cBooleanValue)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct hkVector4q
{
    __m128 m_vComponents;
};

struct hkVector4Rot : public hkVector4
{
    void SetRotatedDirection(const hkRotation& r, const hkVector4& v);
};

struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;
};

struct ShapeRayCastQuery
{
    hkVector4q m_vFrom;
    hkVector4q m_vTo;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

struct ShapeRayCastOutput
{
    hkVector4 m_vHitNormal;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
};

struct RtChild : public hkpShape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual hkBoolResult RayCast(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
};

struct RtStandin : public hkpConvexTransformShape
{
    hkBoolResult FUN_00d5d940(const ShapeRayCastQuery& input, ShapeRayCastOutput& output) const;
};

namespace fnv_00d5dae0 {
extern "C" void _ReadWriteBarrier(void);
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

extern "C" unsigned long DAT_0126835c;
extern "C" const char str_010d1084[];
extern "C" const char str_010c41f8[];
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned __int64 __rdtsc(void);

struct MonitorEntry
{
    const char* m_name;
    unsigned int m_uiCommandId;
    int unk08;
};

struct MonitorStream
{
    int unk00;
    MonitorEntry* m_stream;
    int unk08;
    MonitorEntry* m_kRayEnd;
};

struct ShapeRayCastQuery
{
    hkVector4 m_vFrom;
    hkVector4 m_vTo;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
};

struct hkpCdBody
{
    const hkpShape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_kMotionState;
    const hkpCdBody* m_parent;
    __forceinline hkpCdBody(const hkpCdBody* parent, const void* motionState)
    {
        m_kMotionState = motionState;
        m_parent = parent;
    }
    __forceinline void SetCollisionShapeAndKey(const hkpShape* shape, unsigned int key)
    {
        m_pCollisionShape = shape;
        m_uiCollisionShapeKey = key;
    }
};

static __forceinline __m128 rotateInverse(const hkTransform& a, const hkVector4& b)
{
    __m128 t = _mm_sub_ps((const __m128&)b, (const __m128&)a.m_vTranslation);
    __m128 c0 = (const __m128&)a.m_rotation.m_kColumn0;
    __m128 c1 = (const __m128&)a.m_rotation.m_kColumn1;
    __m128 c2 = (const __m128&)a.m_rotation.m_kColumn2;
    __m128 tmp = _mm_unpacklo_ps(c0, c1);
    __m128 ctmp = _mm_unpackhi_ps(c0, c1);
    c0 = _mm_movelh_ps(tmp, c2);
    c1 = _mm_movehl_ps(c0, tmp);
    c1 = _mm_shuffle_ps(c1, c2, 0xd4);
    c2 = _mm_shuffle_ps(ctmp, c2, 0xe4);
    __m128 b0 = _mm_shuffle_ps(t, t, 0x00);
    __m128 b1 = _mm_shuffle_ps(t, t, 0x55);
    __m128 b2 = _mm_shuffle_ps(t, t, 0xaa);
    return _mm_add_ps(_mm_add_ps(_mm_mul_ps(b0, c0), _mm_mul_ps(b1, c1)), _mm_mul_ps(b2, c2));
}

struct MyVector4 : public hkVector4
{
    __forceinline void _setTransformedInversePos(const hkTransform& a, const hkVector4& b)
    {
        (__m128&)* this = rotateInverse(a, b);
    }
};

struct MyTransform : public hkTransform
{
    void FUN_00cb2240(const void* motionState, const hkTransform* transform);
};

struct hkpRayHitCollector;

struct MyShape : public hkpShape
{
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void castRayWithCollector(const ShapeRayCastQuery& input, const hkpCdBody& cdBody,
                                      hkpRayHitCollector& collector) const;
};

class hkpConvexTransformShapeWrapper : public hkpConvexTransformShape
{
  public:
    void FUN_00d5dae0(const ShapeRayCastQuery& input, const hkpCdBody& cdBody, hkpRayHitCollector& collector) const;
};

}  // namespace fnv_00d5dae0

struct FUN_00d5de40_Child
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
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44(hkVector4* value)
    {}
};

struct FUN_00d5de40_Obj
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
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44(hkVector4* value)
    {}

    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00d5de40_Child* unk18;
    int unk1c;
    hkVector4 unk20;
    hkVector4 unk30;
    hkVector4 unk40;
    hkVector4 unk50;

    void FUN_00d5de40(hkVector4* value);
};

namespace fnv_00d5dea0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);

struct hkTransformD5DE;

struct hkVector4D5DE
{
    __m128 m_vComponents;

    void _setTransformedPos(const hkTransformD5DE& t, const hkVector4D5DE& b);
};

struct hkTransformD5DE
{
    hkVector4D5DE m_kColumn0;
    hkVector4D5DE m_kColumn1;
    hkVector4D5DE m_kColumn2;
    hkVector4D5DE m_vTranslation;
};

class hkpShapeD5DE
{
  public:
    virtual ~hkpShapeD5DE() throw();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void getCentre(hkVector4D5DE& kCentreOut) const;
};

class hkBaseObjectD5DE
{
  public:
    virtual ~hkBaseObjectD5DE() throw();
};

class hkpTransformShapeD5DE : public hkBaseObjectD5DE
{
  public:
    void FUN_00d5dea0(hkVector4D5DE& kCentreOut) const;

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    unsigned int m_ulUserData;
    unsigned int m_type;
    unsigned int unk10, unk14;
    hkpShapeD5DE* m_pContainedShape;
    unsigned int unk1C;
    hkTransformD5DE m_kMotionTransform;
};

}  // namespace fnv_00d5dea0

struct FnvCpu_FUN_00d5d770_CpuData0
{
    __m128 field00;
    __m128 field10;
    __m128 field20;
    __m128 field30;
};
struct FnvCpu_FUN_00d5d770_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    __m128 field20;
    __m128 field30;
    __m128 field40;
    __m128 field50;
    void CopyFromCpuData(FnvCpu_FUN_00d5d770_CpuData0* input0);
};

extern int DAT_010d102c;

struct BaseHelper
{
    void* FUN_00c9e340(int a, float r, const hkpConvexShape* child, int refPolicy);
};

struct AlignedTransform
{
    __m128 r0;
    __m128 r1;
    __m128 r2;
    __m128 r3;
};

struct Standin
{
    const void* vtable;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    AlignedTransform m_kMotionTransform;

    Standin* FUN_00d5d7a0(const hkpConvexShape* childShape, const AlignedTransform& transform, int refPolicy);
};

extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

struct TransformChild
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
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c(int a, int b, int c);
};

struct TransformHost
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    TransformChild* unk18;
    int unk1c;
    hkVector4 unk20;
    hkVector4 unk30;
    hkVector4 unk40;
    hkVector4 unk50;

    void __thiscall FUN_00d5dd40(int a, int b, float* c);
};

struct __declspec(align(16)) LocalTransform
{
    hkVector4 c0, c1, c2, c3;
};

struct hkSphereq
{
    hkVector4q m_pos;
};

union hkVector4U
{
    hkVector4 m_vec;
    __m128 m_vComponents;
};

class hkpConvexShapeSpheres
{
  public:
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
    virtual int getNumCollisionSpheres() const;
    virtual const hkSphereq* getCollisionSpheres(hkSphereq* sphereBuffer) const;
};

class hkpConvexTransformShapeSpheres : public hkpConvexTransformShape
{
  public:
    const hkpConvexShapeSpheres* GetShapeForKey() const
    {
        return (const hkpConvexShapeSpheres*)m_pContainedShape.m_pContainedShape;
    }
    const hkSphereq* FUN_00d5df10(hkSphereq* sphereBuffer) const;
};

extern "C"
{
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_load_ps1(const float*);
    void _mm_store_ss(float*, __m128);
}

struct __declspec(align(16)) Vec4_d5d8
{
    float x, y, z, w;
};

class ConvexChild_d5d8
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual float getMaximumProjection(const Vec4_d5d8& direction) const;
};

class TransformShape_d5d8
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ConvexChild_d5d8* m_pContainedShape;
    int unk1c;
    __m128 m_kColumn0;
    __m128 m_kColumn1;
    __m128 m_kColumn2;
    __m128 m_vTranslation;

    float FUN_00d5d840(const __m128& direction);
};

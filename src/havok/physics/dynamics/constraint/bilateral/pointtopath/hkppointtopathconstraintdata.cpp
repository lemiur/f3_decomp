#include "f3_common.h"
// src/havok/physics/dynamics/constraint/bilateral/pointtopath/hkppointtopathconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/pointtopath/hkppointtopathconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPointToPathConstraintData.h"

// @fnv 0x00dee720
void __stdcall FUN_00dee720(int aiUnused, void* apData)
{
    *(int*)((char*)apData + 4) = 7;
    *(int*)apData = 0x3c;
}

struct FUN_00dee7f0_class
{
    void __thiscall FUN_00dee7f0(void* a);
};

// Fills the struct at a with a pointer to this+0xc and constant fields 0, 0x180, 7, 8, 0xc.
// @fnv 0x00dee7f0
void __thiscall FUN_00dee7f0_class::FUN_00dee7f0(void* a)
{
    *(int*)((char*)a + 0x10) = (int)((char*)this + 0xc);
    *(int*)((char*)a + 0x14) = 0xc;
    *(int*)((char*)a + 0x0) = 0;
    *(int*)((char*)a + 0x4) = 0x180;
    *(int*)((char*)a + 0x8) = 7;
    *(int*)((char*)a + 0xc) = 8;
}

extern int DAT_010da004;
extern int _DAT_0102e388;
struct DDCC60World
{
    void removeReference();
};
struct FUN_00dee7d0_class
{
    void* m_vft;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    DDCC60World* m_obj;
    void __thiscall Destroy();
};

// @fnv 0x00dee740
int __cdecl FUN_00dee740()
{
    return 3;
}

struct FUN_00c7f640_Class
{
    void __thiscall FUN_00c7f640(unsigned int arg, void* position);
};
class FUN_00dee820_Class
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int m_60;
    void FUN_00dee820(unsigned int a, FUN_00c7f640_Class* owner);
};
// @fnv 0x00dee820
void FUN_00dee820_Class::FUN_00dee820(unsigned int uiValue, FUN_00c7f640_Class* owner)
{
    owner->FUN_00c7f640(uiValue, &m_60);
}

struct hkBoolDEE8
{
    char m_cBooleanValue;
    hkBoolDEE8(bool b)
    {
        m_cBooleanValue = static_cast<char>(b);
    }
};

class hkObjectDEE8
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    void* m_18;
    int unk1c;
    char m_20;

    hkBoolDEE8 FUN_00dee840() const;
};

// Returns true when m_18 is non-null and m_20 is set.
// @fnv 0x00dee840
hkBoolDEE8 hkObjectDEE8::FUN_00dee840() const
{
    return m_18 != 0 && m_20;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

struct hkVector4DEE7
{
    __m128 m_vComponents;

    hkVector4DEE7()
    {}
    hkVector4DEE7(const hkVector4DEE7& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4DEE7& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};

struct hkMatrix3DEE7
{
    hkVector4DEE7 m_kColumn0;
    hkVector4DEE7 m_kColumn1;
    hkVector4DEE7 m_kColumn2;

    void setIdentity()
    {
        hkVector4DEE7 kZero;
        kZero.setZero4();
        m_kColumn0 = kZero;
        m_kColumn1 = kZero;
        m_kColumn2 = kZero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct hkTransformDEE7
{
    hkMatrix3DEE7 m_rotation;
    hkVector4DEE7 m_vTranslation;

    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
};

class hkBaseObjectDEE7
{
  public:
    virtual ~hkBaseObjectDEE7() throw();
};

class hkReferencedObjectDEE7 : public hkBaseObjectDEE7
{
  public:
    hkReferencedObjectDEE7() throw() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectDEE7() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpConstraintDataDEE7 : public hkReferencedObjectDEE7
{
  public:
    hkpConstraintDataDEE7() throw() : m_ulUserData(0)
    {}
    virtual ~hkpConstraintDataDEE7() throw();

    unsigned long m_ulUserData;
};

struct hkpConstraintAtomDEE7
{
    hkpConstraintAtomDEE7(unsigned short usType) : m_type(usType)
    {}

    unsigned short m_type;
};

struct hkpBridgeConstraintAtomDEE7 : public hkpConstraintAtomDEE7
{
    hkpBridgeConstraintAtomDEE7() : hkpConstraintAtomDEE7(1)
    {}

    void FUN_00d21ce0(void* pkConstraintData);

    void* m_pBridge;
    void* m_pConstraintData;
};

struct hkpBridgeAtomsDEE7
{
    hkpBridgeConstraintAtomDEE7 m_kBridgeAtom;
};

class FUN_00dee750 : public hkpConstraintDataDEE7
{
  public:
    FUN_00dee750() throw();
    virtual ~FUN_00dee750() throw();

    hkpBridgeAtomsDEE7 m_kBridgeAtoms;
    void* m_path;
    float m_fFriction;
    signed char m_cOrientationConstraintType;
    hkTransformDEE7 m_kLocalTransforms[2];
};

namespace fnv_00dee870 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);

struct Vec_00dee870
{
    __m128 m_vComponents;
    void FUN_00c7f690(const void* m, const void* src);
    __forceinline void setCross(const Vec_00dee870& a, const Vec_00dee870& b)
    {
        __m128 t1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xc9);
        __m128 t2 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xc9);
        __m128 t3 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xd2);
        __m128 t0 = _mm_shuffle_ps(a.m_vComponents, a.m_vComponents, 0xd2);
        m_vComponents = _mm_sub_ps(_mm_mul_ps(t1, t0), _mm_mul_ps(t3, t2));
    }
};

struct Mat_00dee870
{
    Vec_00dee870 c0;
    Vec_00dee870 c1;
    Vec_00dee870 c2;
    Vec_00dee870 c3;
    void FUN_00cb2240(const void* a, const void* b);
    void FUN_00cb22f0(const void* a, const void* b);
    __forceinline void copyFrom(const Mat_00dee870& o)
    {
        c0.m_vComponents = o.c0.m_vComponents;
        c1.m_vComponents = o.c1.m_vComponents;
        c2.m_vComponents = o.c2.m_vComponents;
        c3.m_vComponents = o.c3.m_vComponents;
    }
};

struct Pair_00dee870
{
    Vec_00dee870 lo;
    Vec_00dee870 hi;
    Mat_00dee870 res;
};

struct Solver_00dee870
{
    virtual void vt00();
    virtual void vt04();
    virtual void vt08();
    virtual void vt0c();
    virtual float vt10(float t, Vec_00dee870* a, Vec_00dee870* b);
    virtual void vt14(float t, Vec_00dee870* a);
    virtual void vt18();
    virtual void vt1c();
    virtual void vt20();
    virtual void vt24(float t, Vec_00dee870* a);
};

extern void __fastcall FUN_00c90510(void* a);
extern void __fastcall FUN_00c905b0(void* a);

struct Obj_00dee870
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Solver_00dee870* m_18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    Mat_00dee870 m_30;
    Mat_00dee870 m_70;
    void FUN_00dee870(void* a1, void* a2, void* a3, void* a4, void* a5);
};

}  // namespace fnv_00dee870

namespace fnv_00deea00 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

namespace hkDEEA {
struct hkVector4
{
    __m128 m_vComponents;

    hkVector4()
    {}
    hkVector4(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(&m_vComponents)[i];
    }
};

struct hkMatrix3
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;

    void setIdentity()
    {
        hkVector4 kZero;
        kZero.setZero4();
        m_kColumn0 = kZero;
        m_kColumn1 = kZero;
        m_kColumn2 = kZero;
        m_kColumn0(0) = 1.0f;
        m_kColumn1(1) = 1.0f;
        m_kColumn2(2) = 1.0f;
    }
};

struct hkTransform
{
    hkMatrix3 m_rotation;
    hkVector4 m_vTranslation;

    void setIdentity()
    {
        m_rotation.setIdentity();
        m_vTranslation.setZero4();
    }
    void setTranslation(const hkVector4& v)
    {
        m_vTranslation = v;
    }
};

class hkBaseObject
{
  public:
    virtual ~hkBaseObject() throw();
};

class hkReferencedObject : public hkBaseObject
{
  public:
    void FUN_00c90510() throw();
    void FUN_00c905b0() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpParametricCurve : public hkReferencedObject
{
};

struct hkpSetLocalTransformsConstraintAtom
{
    unsigned short m_type;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0C;
    hkTransform m_kBodyALocalFrame;
    hkTransform m_kBodyBLocalFrame;
};

struct hkpPointToPathAtoms
{
    hkpSetLocalTransformsConstraintAtom m_kTransforms;
};

class hkpConstraintData : public hkReferencedObject
{
  public:
    unsigned long m_ulUserData;
};

class hkpPointToPathConstraintData : public hkpConstraintData
{
  public:
    void FUN_00deea00(const hkVector4& kPivotA, const hkVector4& kPivotB, hkpParametricCurve* pkPath);

    unsigned int unk0C, unk10, unk14;
    hkpParametricCurve* m_path;
    unsigned int unk1C;
    hkpPointToPathAtoms m_kBridgeAtoms;
};

}
}  // namespace fnv_00deea00

#include <math.h>
extern "C" void _WriteBarrier(void);
extern "C" void _ReadBarrier(void);
extern "C" void _ReadWriteBarrier(void);
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_set_ps1(float);
    __m128 _mm_load_ps(const float*);
}

extern __m128 DAT_010c44d0;

struct TransformQ;

struct VectorQ
{
    __m128 m_vComponents;

    __forceinline void operator=(const VectorQ& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline hkReal& operator()(int i)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[i];
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }

    void FUN_00c7f690(const TransformQ& t, const VectorQ& v);
    void FUN_00c7f640(const TransformQ& t, const VectorQ& v);
    void FUN_00c7f700(const TransformQ& t, const VectorQ& v);
};

struct TransformQ
{
    VectorQ m_kColumn0;
    VectorQ m_kColumn1;
    VectorQ m_kColumn2;
    VectorQ m_vTranslation;

    void FUN_00cb2240(const hkTransform& a, const hkTransform& b);
};

class hkBoolC
{
  public:
    char m_cBooleanValue;
    hkBoolC(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class hkpParametricCurve
{
  public:
    virtual ~hkpParametricCurve();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual hkReal FindNearestPoint(hkReal t, const VectorQ& point, VectorQ& nearestPointOut);
    virtual void GetTangentAt(hkReal t, VectorQ& tangentOut);
    virtual hkReal GetStreamStart();
    virtual hkReal GetStreamEnd();
    virtual hkReal GetCurvature(hkReal t);
    virtual void GetBinormal(hkReal t, VectorQ& binormalOut);
    virtual hkBoolC IsClosedCurve();
};

typedef hkReal(__thiscall* CurveLengthCall)(hkpParametricCurve*, hkReal);
struct CurveDispatchTable
{
    void* destructor;
    void* vf04;
    void* vf08;
    void* vf0c;
    void* nearestPoint;
    void* tangent;
    void* start;
    void* end;
    CurveLengthCall length;
};
struct CurveDispatch
{
    CurveDispatchTable* table;
};

struct PathRuntime
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
    hkReal m_fValueAtOffset38;
};

struct QueryIn
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
    const hkTransform* m_kBodyALocalFrame;
    const hkTransform* m_kBodyBLocalFrame;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    PathRuntime* m_pByteBuffer;
};

struct QueryOut;

struct LinearRow
{
    VectorQ m_kPivotA;
    VectorQ m_kPivotB;
    VectorQ m_kAxisEndPoints;
};
struct FrictionRow
{
    VectorQ m_kPivotVector;
    VectorQ m_kAxisEndPoints;
    hkReal m_fFriction;
    PathRuntime* m_pRuntime;
};
struct AngularRow
{
    VectorQ m_kAxisEndPoints;
    VectorQ m_perpA;
    VectorQ m_perpB;
};
struct LimitRow
{
    VectorQ m_kPivotA;
    VectorQ m_kPivotB;
    VectorQ m_kAxisEndPoints;
    hkReal m_kMinimumCorner;
    hkReal m_kMaximumCorner;
};

void __cdecl AppendEventRecord(const QueryIn& in, QueryOut& out, PathRuntime* runtime, int size);
void __cdecl FUN_00dcf100(FrictionRow* row, const QueryIn& in, QueryOut& out);
void __cdecl FUN_00dcf280(LinearRow* row, const QueryIn& in, QueryOut& out);
void __cdecl FUN_00dcee80(AngularRow* row, const QueryIn& in, QueryOut& out);
void __cdecl FUN_00dcfa30(LimitRow* row, const QueryIn& in, QueryOut& out);

static __forceinline void hkSetCross(VectorQ& out, const VectorQ& v0, const VectorQ& v1)
{
    __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
    __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2),
                               _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
    out.m_vComponents = _mm_sub_ps(cross0, cross1);
}

struct PointToPathData : public hkpPointToPathConstraintData
{
    void FUN_00deea90(const QueryIn& in, QueryOut& out);
};

struct PathDeleteAllocator
{
    virtual void vf00();
    virtual void vf04();
    virtual void ReleaseBlock(void* object, int size);
};

struct PathDeleteRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    PathDeleteAllocator* heap;
};

PathDeleteRouter* __cdecl FUN_00c85750();

struct PathDeleteData : hkpPointToPathConstraintData
{
    void __thiscall Destroy();
    void* __thiscall FUN_00deef10(unsigned char flags);
};

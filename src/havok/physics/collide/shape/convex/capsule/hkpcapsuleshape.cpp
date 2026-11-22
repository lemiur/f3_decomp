#include "f3_common.h"
// src/havok/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/capsule/hkpcapsuleshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpCapsuleShape.h"

extern char const* const g_01268970_arg1;
void __cdecl FUN_00c90360(char const* const* arg1, char const* const* arg2);

// @fnv 0x00d22350
int __cdecl FUN_00d22350()
{
    return 2;
}

// @fnv 0x00d22d60
int __stdcall FUN_00d22d60(int a, int b)
{
    return 0x40;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C" __m128 _mm_load_ps(float const* p);
extern "C" void _mm_store_ps(float* p, __m128 v);

class FUN_00d223f0_cls
{
  public:
    void GatherIndexedVectors(unsigned short const* indices, int count, hkVector4* out);
};

struct __declspec(align(16)) hkVector4D224
{
    __m128 m_vComponents;

    hkVector4D224()
    {}
    hkVector4D224(const hkVector4D224& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

class FUN_00d22480_cls
{
  public:
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
    hkVector4D224 m_vector;

    hkVector4D224 FUN_00d22480() const;
};

struct FUN_00d224a0_Data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __m128 unk20;
    __m128 unk30;

    void __thiscall FUN_00d224a0(__m128* result);
};

extern int DAT_010ce25c;
union __declspec(align(16)) AlignedHKVector4
{
    __m128 simd;
    struct
    {
        float x, y, z, w;
    };
};
struct FUN_00d22590_Class : hkpCapsuleShape
{
    FUN_00d22590_Class* __thiscall FUN_00d22590(const AlignedHKVector4& first, const AlignedHKVector4& second,
                                                float radius);
};

struct __declspec(align(16)) Point4
{
    float x, y, z, w;
};
struct ClosestLineResult
{
    float distance;
    float fractionA;
    float fractionB;
    float extraValue;
    Point4 pointA;
    Point4 pointB;
};
void __cdecl FUN_00d231b0(const Point4& a, const Point4& b, const Point4& c, const Point4& d, ClosestLineResult* out);

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ps(float*, __m128);
extern float DAT_01016248;

class Aabb_d22440
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    __m128 m_kMin;
    __m128 m_kMax;

    void __thiscall FUN_00d22440(__m128* pkCenter) const;
};

extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" void _mm_store_ss(float*, __m128);

struct hkSimdRealD223
{
    __m128 m_vValue;

    hkSimdRealD223(const __m128& x) : m_vValue(x)
    {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
};

struct hkVector4D223
{
    __m128 m_vComponents;

    hkVector4D223()
    {}
    hkVector4D223(const hkVector4D223& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4D223& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setSub4(const hkVector4D223& a, const hkVector4D223& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    hkSimdRealD223 dot3(const hkVector4D223& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    void setInt24W(int i)
    {
        reinterpret_cast<int*>(&m_vComponents)[3] = i | 0x3f000000;
    }
};

class hkBaseObjectD223
{
  public:
    virtual ~hkBaseObjectD223() throw();
};

class hkReferencedObjectD223 : public hkBaseObjectD223
{
  public:
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpCapsuleShapeD223 : public hkReferencedObjectD223
{
  public:
    void FUN_00d22370(const hkVector4D223& kDirection, hkVector4D223& kSupportingVertexOut) const;

    unsigned int m_ulUserData;
    unsigned int m_type;
    float m_fSphereRadius;
    unsigned int unk14, unk18, unk1C;
    hkVector4D223 m_kVertexA;
    hkVector4D223 m_kVertexB;
};

extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);
extern "C" __m128 _mm_set_ps1(float);

struct hkTransformq;

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void SetAllComponents(hkReal x)
    {
        m_vComponents = _mm_set_ps1(x);
    }
    __forceinline void setMin4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMax4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void add4(const hkVector4q& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void sub4(const hkVector4q& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }
    __forceinline void SetTransformedPoint(const hkTransformq& a, const hkVector4q& bIn);
};

struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;
};

union hkVector4U
{
    hkVector4 m_vec;
    __m128 m_vComponents;
};

struct hkTransformU
{
    hkVector4U m_kColumn0;
    hkVector4U m_kColumn1;
    hkVector4U m_kColumn2;
    hkVector4U m_vTranslation;

    __forceinline void set(const hkTransform& t)
    {
        m_kColumn0.m_vec = t.m_rotation.m_kColumn0;
        m_kColumn1.m_vec = t.m_rotation.m_kColumn1;
        m_kColumn2.m_vec = t.m_rotation.m_kColumn2;
        m_vTranslation.m_vec = t.m_vTranslation;
    }
};

__forceinline void hkVector4q::SetTransformedPoint(const hkTransformq& a, const hkVector4q& bIn)
{
    const __m128 b = bIn.m_vComponents;
    const __m128 b0 = _mm_shuffle_ps(b, b, 0x00);
    const __m128 r0 = _mm_mul_ps(a.m_kColumn0.m_vComponents, b0);
    const __m128 b1 = _mm_shuffle_ps(b, b, 0x55);
    const __m128 r1 = _mm_mul_ps(a.m_kColumn1.m_vComponents, b1);
    const __m128 b2 = _mm_shuffle_ps(b, b, 0xaa);
    const __m128 r2 = _mm_mul_ps(a.m_kColumn2.m_vComponents, b2);
    m_vComponents = _mm_add_ps(_mm_add_ps(r0, r1), _mm_add_ps(r2, a.m_vTranslation.m_vComponents));
}

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

class hkpCapsuleShapeAabb : public hkpCapsuleShape
{
  public:
    void FUN_00d225e0(const hkTransform& localToWorld, hkReal tolerance, hkAabbq& out) const;
};

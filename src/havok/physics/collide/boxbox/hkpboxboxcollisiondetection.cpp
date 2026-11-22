#include "f3_common.h"
// src/havok/physics/collide/boxbox/hkpboxboxcollisiondetection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/boxbox/hkpboxboxcollisiondetection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// RemoveValueAt - drops slot <index> of the eight-slot table held by
// FUN_00db0920: the last slot in use is moved into the hole and the used-slot
// counter goes down by one.
struct FUN_00db0920
{
    int values[8];        // +0x00: eight four-byte slots, low half holds the key
    unsigned char unk20;  // +0x20
    unsigned char count;  // +0x21: number of slots in use
    unsigned char flag;   // +0x22
    void RemoveValueAt(int index);
};

// @fnv 0x00db0900
void FUN_00db0920::RemoveValueAt(int index)
{
    // Stored through an alias on purpose: with a direct member store the
    // compiler hoists the count load above the store, the original does not.
    unsigned char* pFlag = &flag;
    *pFlag = 0;
    values[index] = values[count - 1];
    count--;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_set_ps1(float);
    __m128 _mm_set_ss(float);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    void _mm_store_ss(float*, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_xor_ps(__m128, __m128);
}

extern "C"
{
    double __cdecl fabs(double _X);
}
extern "C++"
{
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct hkVector4
{
    __m128 m_vComponents;
    __m128 q() const
    {
        return m_vComponents;
    }
    void set(__m128 v)
    {
        m_vComponents = v;
    }
    float& operator()(int i)
    {
        return reinterpret_cast<float*>(this)[i];
    }
    const float& operator()(int i) const
    {
        return reinterpret_cast<const float*>(this)[i];
    }
};

struct hkTransform
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_vTranslation;
};

struct BoxBoxEdgeContact
{
    hkVector4 m_vContactPosition;                  // 0x00
    hkVector4 unk10;                       // 0x10
    hkVector4 m_vHitNormal;                    // 0x20
    float unk30;                           // 0x30
    float m_fClosestPointDistanceSquared;  // 0x34
    int m_featureA;                        // 0x38
    int m_featureB;                        // 0x3c
};

extern const hkVector4 g_boxVertexSigns[8];
extern const __m128 g_negateMask;

struct BoxBoxCollisionDetection
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    hkVector4 m_rotation[3];        // 0x20
    hkVector4 m_vTranslation;       // 0x50
    hkVector4 m_kBoxBasisVector;            // 0x60
    hkVector4 m_kThirdBasisVector;  // 0x70
    hkVector4 unk80;
    hkVector4 unk90;
    hkVector4 unkA0;
    float m_fScalar;          // 0xb0
    float m_minNormalLength;  // 0xb4

    hkBool TestEdgeEdgeContact(BoxBoxEdgeContact* contact);
};

static __forceinline __m128 dot3v(__m128 a, __m128 b)
{
    __m128 p = _mm_mul_ps(a, b);
    __m128 s = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
    return _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), s);
}

static __forceinline float toReal(__m128 v)
{
    float r;
    _mm_store_ss(&r, v);
    return r;
}

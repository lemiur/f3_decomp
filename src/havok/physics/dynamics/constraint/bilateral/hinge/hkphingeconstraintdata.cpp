#include "f3_common.h"
// src/havok/physics/dynamics/constraint/bilateral/hinge/hkphingeconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/hinge/hkphingeconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpHingeConstraintData.h"

struct FUN_00cbe1b0_class
{
    void FUN_00cbe1b0(int index);
};

extern "C" void* __cdecl FUN_00d21a60(void* thisPtr, int size, int param);

struct hkpHingeConstraintData_ : public hkpConstraintData
{
    void* __thiscall FUN_00cbe210(int param);
};

// Writes 5 and 0x28 into target[1] and target[0] when param is nonzero, otherwise writes zeros.
// @fnv 0x00cbe1e0
void __stdcall SetTargetValues(char param, int* target)
{
    if (param)
    {
        target[1] = 5;
        target[0] = 0x28;
    }
    else
    {
        target[1] = 0;
        target[0] = 0;
    }
}

struct FUN_00cbe190_class
{
    void FUN_00cbe190(float value);
};
// @fnv 0x00cbe190
void FUN_00cbe190_class::FUN_00cbe190(float value)
{
    *(float*)((char*)this + 0xa8) = value;
}

struct CpuObject
{
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
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    float value;
    float FUN_00cbe1a0();
};
// @fnv 0x00cbe1a0
float CpuObject::FUN_00cbe1a0()
{
    return value;
}

// Reads a flag byte at +0xA6 and returns it shifted right by one.

class FUN_00cbe1d0_cls
{
  public:
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0C;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1C;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2C;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3C;
    unsigned int m_40;
    unsigned int m_44;
    unsigned int m_48;
    unsigned int m_4C;
    unsigned int m_50;
    unsigned int m_54;
    unsigned int m_58;
    unsigned int m_5C;
    unsigned int m_60;
    unsigned int m_64;
    unsigned int m_68;
    unsigned int m_6C;
    unsigned int m_70;
    unsigned int m_74;
    unsigned int m_78;
    unsigned int m_7C;
    unsigned int m_80;
    unsigned int m_84;
    unsigned int m_88;
    unsigned int m_8C;
    unsigned int m_90;
    unsigned int m_94;
    unsigned int m_98;
    unsigned int m_9C;
    unsigned short m_A0;
    unsigned short m_A2;
    unsigned short m_A4;
    unsigned char m_A6;
    unsigned int FUN_00cbe1d0();
};

// @fnv 0x00cbe230
int __cdecl FUN_00cbe230()
{
    return 1;
}

class hkBoolCBE7
{
  public:
    hkBoolCBE7()
    {}
    hkBoolCBE7(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

class hkTransformCBE7
{
  public:
    float m_data[16];

    hkBoolCBE7 IsOrthonormal(float fEpsilon) const;
};

class FUN_00cbe750_C
{
  public:
    int unk00[8];
    hkTransformCBE7 m_kPointA;
    hkTransformCBE7 m_kPointB;

    hkBoolCBE7 FUN_00cbe750() const;
};

// @fnv 0x00cbe750
hkBoolCBE7 FUN_00cbe750_C::FUN_00cbe750() const
{
    return m_kPointA.IsOrthonormal(0.001f) && m_kPointB.IsOrthonormal(0.001f);
}

#include <xmmintrin.h>
#include <math.h>
namespace fnv_00cbe240 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
}

union hkVector4q
{
    __m128 m_vComponents;
    hkVector4 m_vec;

    __forceinline hkReal& operator()(int i)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[i];
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }

    void FUN_004b4ab0(const hkRotation& r, const hkVector4q& v);
    void FUN_00c7f690(const hkTransform& t, const hkVector4& v);
};

struct hkpSetLocalTransformsAtom
{
    hkUint16 m_type;
    hkUint16 unk02;
    hkUint32 unk04;
    hkUint32 unk08;
    hkUint32 unk0C;
    hkVector4q m_kRotationA[3];
    hkVector4q m_kTranslationA;
    hkVector4q m_kRotationB[3];
    hkVector4q m_kTranslationB;
};

struct hkpHingeConstraintDataEx : public hkpHingeConstraintData
{
    void SetLocalTransforms(const hkTransform& bodyATransform, const hkTransform& bodyBTransform,
                            const hkVector4& pivot, const hkVector4& axis);
};

}  // namespace fnv_00cbe240

namespace fnv_00cbe400 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
}

union hkVector4q
{
    __m128 m_vComponents;
    hkVector4 m_vec;

    __forceinline hkReal& operator()(int i)
    {
        return reinterpret_cast<hkReal*>(&m_vComponents)[i];
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }
};

struct hkMatrix3q
{
    hkVector4q m_col[3];
};

struct hkpHingeTransforms
{
    char pad0[0x10];
    hkMatrix3q m_kRotationA;
    hkVector4q m_kTranslationA;
    hkMatrix3q m_kRotationB;
    hkVector4q m_kTranslationB;
};

struct hkpHingeConstraintDataEx : public hkpHingeConstraintData
{
    void FUN_00cbe400(const hkVector4& pivotA, const hkVector4& pivotB, const hkVector4& axisA, const hkVector4& axisB);
};

}  // namespace fnv_00cbe400

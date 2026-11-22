#include "f3_common.h"
// src/havok/physics/dynamics/motion/rigid/hkpkeyframedrigidmotion.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/motion/rigid/hkpkeyframedrigidmotion.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpKeyframedRigidMotion.h"

struct FUN_00d1df70
{
    void RetainReference();
    void removeReference();
    void SetAndAddReference(hkReferencedObject* obj);
};

struct DDCC60World
{
    void removeReference();
};
extern int DAT_010c6bec;
extern int _DAT_0102e388;
struct FUN_00d1dff0
{
    void setMotion();
};

// @fnv 0x00d1dec0
void __stdcall FUN_00d1dec0(int)
{}

// @fnv 0x00d1ded0
void __stdcall FUN_00d1ded0(int)
{}

// @fnv 0x00d1dee0
void __stdcall FUN_00d1dee0(int)
{}

// @fnv 0x00d1def0
void __stdcall FUN_00d1def0(int)
{}

// @fnv 0x00d1df00
void __stdcall FUN_00d1df00(int)
{}

// @fnv 0x00d1df10
void __stdcall FUN_00d1df10(int, int)
{}

// @fnv 0x00d1df20
void __stdcall FUN_00d1df20(int)
{}

// @fnv 0x00d1df30
void __stdcall FUN_00d1df30(int, int)
{}

// @fnv 0x00d1df40
void __stdcall FUN_00d1df40(int a, int b, int c)
{}

// @fnv 0x00d1df50
void __stdcall FUN_00d1df50(int, int)
{}

// @fnv 0x00d1df60
void __stdcall FUN_00d1df60(int, int)
{}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

struct hkVector4D1DF
{
    __m128 m_vComponents;

    hkVector4D1DF()
    {}
    hkVector4D1DF(const hkVector4D1DF& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4D1DF& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

struct hkQuaternionD1DF
{
    hkVector4D1DF m_vec;
};

class hkBaseObjectD1DF
{
  public:
    virtual ~hkBaseObjectD1DF() throw();
};

class hkReferencedObjectD1DF : public hkBaseObjectD1DF
{
  public:
    virtual ~hkReferencedObjectD1DF() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00c86530 : public hkReferencedObjectD1DF
{
  public:
    FUN_00c86530(const hkVector4D1DF& kPosition, const hkQuaternionD1DF& kRotationBasis,
                 bool bWantDeactivation) throw();
    virtual ~FUN_00c86530() throw();

    unsigned char m_type;
    unsigned char m_ucDeactivationIntegrateCounter;
    unsigned short m_ausDeactivationNumInactiveFrames[2];
    unsigned short unk0E;
    unsigned int unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    unsigned int unk70, unk74, unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C;
    unsigned int unkA0, unkA4, unkA8, unkAC, unkB0, unkB4, unkB8, unkBC;
    hkVector4D1DF m_kInertiaAndMassInv;
    hkVector4D1DF m_kTranslationalVelocity;
    hkVector4D1DF m_kAngularVelocity;
    hkVector4D1DF m_akDeactivationReferencePositions[2];
    unsigned int m_auiDeactivationReferenceOrientations[2];
    void* m_pSavedMotion;
    unsigned short m_savedMotionSize;
    short m_fGravityFactor;
};

class FUN_00d1dfa0 : public FUN_00c86530
{
  public:
    FUN_00d1dfa0(const hkVector4D1DF& kPosition, const hkQuaternionD1DF& kRotationBasis) throw();
    virtual ~FUN_00d1dfa0() throw();
};

struct FUN_00d1e030_t
{
    float f0, f1, f2, f3;
    float f4, f5, f6, f7;
    float f8, f9, fA, fB;
    float fC, fD, fE, fF;
};

namespace fnv_00d1e090 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_load_ps(const float*);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    void _mm_store_ss(float*, __m128);
}

struct Veh_00d1e090 : public hkpKeyframedRigidMotion
{
    void ComputeVelocityAlongDirection(hkVector4* position, hkVector4* direction, float* angularResult,
                                       float* zeroResult);
};

}  // namespace fnv_00d1e090

extern "C" void _mm_store_ps(float*, __m128);

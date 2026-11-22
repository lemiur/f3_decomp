#include "f3_common.h"
// src/havok/physics/dynamics/constraint/atom/hkpconstraintatom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/atom/hkpconstraintatom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConstraintAtom.h"

struct FUN_00d21ce0_cls
{
    void* m_base;
    void* m_pBridge;
    void* m_pConstraintData;
    void FUN_00d21ce0(void* data);
};

struct FUN_00d22090_cls
{
    int FUN_00d22090(void* a, void* b);
};

// Walks a linked list from self while the node's first ushort is at least 0x17, OR-ing each node's FUN_00d22090(a, b) result and returning it.
// @f3 0x009a1f20 (community match, verified in this file)
struct ConstraintNode {
    unsigned short type, unk02;
    unsigned int unk04, unk08, unk0c, unk10;
    ConstraintNode* next;
    int FUN_009a1ee0(void* payload);
};
int __cdecl FUN_00d22120(void* first, void* payload, void*) {
    ConstraintNode* node = static_cast<ConstraintNode*>(first);
    int result = 0;
    while (node->type >= 23) {
        result |= node->FUN_009a1ee0(payload);
        node = node->next;
    }
    return result;
}


// @fnv 0x00d21d00
void __stdcall FUN_00d21d00(int, int, int, int, int, int)
{}

struct FUN_00d21de0_cls
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    FUN_00d21de0_cls* __thiscall FUN_00d21de0(int a);
};

// @f3 0x009a1c00 (community match, verified in this file)
FUN_00d21de0_cls* FUN_00d21de0_cls::FUN_00d21de0(int) {
    unk0A = (unsigned char)((unk09 + unk08 + 5) * 4);
    return this;
}


struct ConstraintAtom;
struct ConstraintInfo
{
    int maxSizeOfSchema;
    int sizeOfSchemas;
    int numSolverResults;
    int numSolverElemTemps;
    ConstraintAtom* atoms;
    unsigned int sizeOfAllAtoms;
};
struct ConstraintAtom
{
    unsigned short type;
    unsigned short unk02;
    int unk04;
    int unk08;
    int unk0C;
    unsigned short unk10;
    unsigned short count;
    ConstraintAtom* next;
    int FUN_00d22030(ConstraintInfo* info);
};
void __cdecl FUN_00d21a60(ConstraintAtom* atom, unsigned int count, ConstraintInfo* result);

// Walks the atom chain while type >= 23, then subtracts the partial solver temps, results and schema size from info unless the atom type is 22 or 1.
// @fnv 0x00d22030
int ConstraintAtom::FUN_00d22030(ConstraintInfo* info)
{
    ConstraintAtom* atom = this;
    unsigned int count = 0;
    while (atom->type >= 23)
    {
        count = atom->count;
        atom = atom->next;
    }
    if (atom->type != 22 && atom->type != 1)
    {
        ConstraintInfo partialInfo;
        FUN_00d21a60(atom, count, &partialInfo);
        info->numSolverElemTemps -= partialInfo.numSolverElemTemps;
        info->numSolverResults -= partialInfo.numSolverResults;
        info->sizeOfSchemas -= partialInfo.sizeOfSchemas;
    }
    return 0;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void mul4(const hkVector4q& v)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return m_vComponents.m128_f32[i];
    }
};

struct hkSimdRealq
{
    __m128 m_vValue;

    __forceinline hkSimdRealq(const __m128& q)
    {
        m_vValue = q;
    }
};

struct hkMatrix3q
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;

    __forceinline float& operator()(int r, int c)
    {
        return (&m_kColumn0)[c](r);
    }

    void setTransposeMul(const hkMatrix3q& a, const hkMatrix3q& b);
    void SetProduct(const hkMatrix3q& a, const hkMatrix3q& b);
    void SetInverseProduct(const hkMatrix3q& a, const hkMatrix3q& b);
    void mul(const hkSimdRealq& scale);
};

struct hkpSimpleConstraintInfoInitInputq
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMatrix3q m_kInverseInertiaMatrix;
    hkVector4q m_vInverseInertiaAndMass;
    const hkMatrix3q* m_rotation;
};

class hkpMassChangerModifierConstraintAtomq
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
    hkVector4q m_kFactorA;
    hkVector4q m_kFactorB;

    void ScaleInverseInertia(const void* cp, hkpSimpleConstraintInfoInitInputq& inA, void* velA,
                             hkpSimpleConstraintInfoInitInputq& inB, void* velB);
};

namespace fnv_00d21f50 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);

struct hkSimdRealD21F
{
    __m128 m_vValue;

    hkSimdRealD21F(const __m128& x) : m_vValue(x)
    {}
};

struct hkVector4D21F
{
    __m128 m_vComponents;

    hkSimdRealD21F dot3(const hkVector4D21F& a) const
    {
        const __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        const __m128 sum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), sum);
    }
    void subMul4(const hkSimdRealD21F& s, const hkVector4D21F& a)
    {
        m_vComponents =
            _mm_sub_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(s.m_vValue, s.m_vValue, 0), a.m_vComponents));
    }
    void add4(const hkVector4D21F& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }
};

struct hkContactPointD21F
{
    hkVector4D21F m_vContactPosition;
    hkVector4D21F m_vSeparatingNormal;
};

class hkpMovingSurfaceModifierConstraintAtomD21F
{
  public:
    void FUN_00d21f50(const hkContactPointD21F& kCp, void* pvA, void* pvB, void* pvC, hkVector4D21F& kVelOut);

    unsigned short m_type;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    hkVector4D21F m_fVelocity;
};

}  // namespace fnv_00d21f50

struct hkpConstraintInfoD220
{
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
};

class hkpModifierConstraintAtomD220
{
  public:
    unsigned short m_type;

    int FUN_00d22030(hkpConstraintInfoD220& kInfo) const;
    int FUN_00d22090(hkpConstraintInfoD220& kInfo, unsigned char& ucUsedFlagsOut) const;
};

extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, int c);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);

struct Vec4
{
    __m128 m_vComponents;

    __forceinline void sub4(const Vec4& v)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, v.m_vComponents);
    }
    __forceinline void setCross(const Vec4& v1, const Vec4& v2)
    {
        const __m128 cross0 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xC9),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xD2));
        const __m128 cross1 = _mm_mul_ps(_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xD2),
                                         _mm_shuffle_ps(v2.m_vComponents, v2.m_vComponents, 0xC9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
};

struct Mat3
{
    Vec4 m_kColumn0;
    Vec4 m_kColumn1;
    Vec4 m_kColumn2;
};

struct Transform
{
    Mat3 m_rotation;
    Vec4 m_vTranslation;
};

struct InitInput
{
    Vec4 m_kFirstVector;
    Mat3 m_kInverseInertiaMatrix;
    Vec4 m_vInverseInertiaAndMass;
    const Transform* m_kMotionTransform;
};

struct BodyVelocity
{
    Vec4 m_kTranslationalVelocity;
    Vec4 m_kAngularVelocity;
};

struct ComChangerAtom
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    Vec4 m_kDisplacementA;
    Vec4 m_kDisplacementB;

    void FUN_00d22160(const void* cp, InitInput& inA, BodyVelocity& velA, InitInput& inB, BodyVelocity& velB);
};

extern __m128 DAT_012689a0;
extern __m128 DAT_012689b0;
extern __m128 DAT_012689c0;
extern __m128 DAT_012689d0;

extern "C" __m128 _mm_load_ps(float const* p);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
struct FUN_00d21fc0_n
{
    float x, y, z, w;
};
struct Cls_00d21fc0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FUN_00d21fc0_n m_uiValueCount;
    void __thiscall FUN_00d21fc0(__m128* a, int b, int c, int d, int e, int out);
};

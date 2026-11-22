#include "f3_common.h"
// src/havok/animation/animation/mapper/hkaskeletonmapperutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/mapper/hkaskeletonmapperutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CE5F90QsTransform
{
    float m_vTranslation[4];
    float m_rotation[4];
    float m_vScale[4];
};

void __cdecl FUN_00ce5a70(CE5F90QsTransform* out, const CE5F90QsTransform* a, const CE5F90QsTransform* b, int mode,
                          float weightA, float weightB);

// @f3 0x006f5500 (community match, verified in this file)
struct GlobalStub { float FUN_006e2a90(); };
extern GlobalStub DAT_01079f68;
struct X { void FUN_006f5500(int a, float b); };
extern void __cdecl FUN_00450ba0(X* self, int a, float b, float c);
void X::FUN_006f5500(int a, float b)
{
    float c = DAT_01079f68.FUN_006e2a90();
    FUN_00450ba0(this, a, b, c);
}


#include <xmmintrin.h>
extern const float DAT_0104da48;
extern const float DAT_0104e148;

struct __declspec(align(16)) VertexRecord
{
    __m128 m_kPathOffset;
    int m_ai10;
    int m_ai14;
    int m_ai18;
    int m_ai1c;
    int m_ai20;
    int m_ai24;
    int m_ai28;
    int m_ai2c;
};

namespace fnv_00ce55d0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps(void);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);

typedef float hkReal;

extern __m128 DAT_010c71b0;

struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void SetAllComponents(hkReal r)
    {
        m_vComponents = _mm_set_ps1(r);
    }
    __forceinline void setSub4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline hkReal length3() const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2));
        hkReal r;
        _mm_store_ss(&r, _mm_sqrt_ss(len2));
        return r;
    }
};

struct hkQsTransformq
{
    hkVector4q m_vTranslation;
    hkVector4q m_rotation;
    hkVector4q m_vScale;

    __forceinline void setIdentity()
    {
        m_vTranslation.setZero4();
        m_rotation.m_vComponents = DAT_010c71b0;
        m_vScale.SetAllComponents(1.0f);
    }
};

struct ScaleParams
{
    int m_iValueAfterFlags;
    int m_sBoneA;
    int m_sBoneB;
    hkReal m_scaleA;
    hkReal m_scaleB;
};

void __cdecl FUN_00ce5560(const hkQsTransformq* pose, int numBones, hkVector4q& minOut, hkVector4q& maxOut);

}  // namespace fnv_00ce55d0

#include <math.h>
struct ThresholdState
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    float threshold;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int mode;
};

struct ValueSource
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};

extern "C" float __cdecl GetAngle();
typedef float(__thiscall* ReadValue)(void*);

namespace fnv_00ce5e60 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_setzero_ps(void);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sqrt_ss(__m128);
    void _mm_store_ss(float*, __m128);
}

typedef float hkReal;
typedef short hkInt16;

struct hkVector4f
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

union hkVector4q
{
    hkVector4f m_vec;
    __m128 m_vComponents;
};

struct hkQsTransformq
{
    hkVector4q m_vTranslation;
    hkVector4q m_rotation;
    hkVector4q m_vScale;
};

struct hkaSkeletonq
{
    int m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    const char* m_name;
    hkInt16* m_kParentIndices;
};

extern hkVector4q DAT_010c71e0;

}  // namespace fnv_00ce5e60

namespace fnv_00ce5fe0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_set_ss(float);
    __m128 _mm_set_ps1(float);
}

typedef float hkReal;
typedef short hkInt16;

struct hkVector4
{
    __m128 m_vComponents;

    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }

    __forceinline void normalize3()
    {
        __m128 p = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0x55), p);
        len2 = _mm_add_ss(_mm_shuffle_ps(p, p, 0xaa), len2);
        __m128 e = _mm_rsqrt_ss(len2);
        __m128 r = _mm_mul_ss(_mm_mul_ss(_mm_set_ss(0.5f), e),
                              _mm_sub_ss(_mm_set_ss(3.0f), _mm_mul_ss(_mm_mul_ss(len2, e), e)));
        r = _mm_andnot_ps(_mm_cmpeq_ss(len2, _mm_set_ss(0.0f)), r);
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r, r, 0), m_vComponents);
    }
};

struct hkQuaternion
{
    hkVector4 m_vec;

    __forceinline void operator=(const hkQuaternion& q)
    {
        m_vec.m_vComponents = q.m_vec.m_vComponents;
    }
    void FUN_00cd9d10(const hkVector4& from, const hkVector4& to);
    void FUN_00c74b70(const hkQuaternion& a, const hkQuaternion& b);
};

struct hkQsTransform
{
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;
};

struct hkaSkeleton;

struct BonePairInfo
{
    hkInt16 m_boneA0;
    hkInt16 m_boneA1;
    hkInt16 m_boneB0;
    hkInt16 m_boneB1;
    int unk08;
    int unk0C;
    hkVector4 m_offset;
    hkVector4 unk20;
    hkVector4 unk30;
    hkQuaternion m_rotation;
    hkQuaternion m_relRotation;
    hkVector4 m_vScale;
};

void FUN_00ce5f90(const void* data, const hkQsTransform* poseA, hkInt16 boneA, const hkQsTransform* poseB,
                  hkInt16 boneB, hkVector4* out, hkReal eps, hkReal weight);
void FUN_00ce5e60(const hkaSkeleton* skel, const hkQsTransform* poses, hkInt16 ancestor, hkInt16 bone,
                  hkReal* lengthOut, hkVector4* posOut);

}  // namespace fnv_00ce5fe0

typedef unsigned int size_t;

inline void* operator new(size_t, void* p)
{
    return p;
}

struct hkMemoryAllocator;

struct hkMemoryRouterStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
    hkMemoryAllocator* m_pStreamAllocator;
};

hkMemoryRouterStub* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00c908c0(hkMemoryAllocator* mem, void* array, int numElems, int elemSize);

struct HkElem8
{
    int a;
    int b;
};

template <typename T> struct HkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    HkArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void copy(T* dst, const T* src, int n)
    {
        for (int i = 0; i < n; i++)
        {
            dst[i] = src[i];
        }
    }

    __forceinline void constructWithCopy(T* dst, int n, const T* src)
    {
        for (int i = 0; i < n; i++)
        {
            new (dst + i) T(src[i]);
        }
    }

    __forceinline void reserve(hkMemoryAllocator& alloc, int n)
    {
        int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newCap = n < cap2 ? cap2 : n;
            FUN_00c908c0(&alloc, this, newCap, sizeof(T));
        }
    }

    __forceinline void copyFromArray(hkMemoryAllocator& alloc, const HkArray& a)
    {
        const int oldSize = m_iElementCount;
        const int newSize = a.m_iElementCount;
        const int copiedSize = newSize > oldSize ? oldSize : newSize;
        reserve(alloc, newSize);
        copy(m_data, a.m_data, copiedSize);
        constructWithCopy(m_data + copiedSize, newSize - copiedSize, a.m_data + copiedSize);
        m_iElementCount = newSize;
    }

    __forceinline HkArray& operator=(const HkArray& other)
    {
        copyFromArray(FUN_00c85750()->heap(), other);
        return *this;
    }
};

struct FUN_00ce9580
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
    float unk10;
    HkArray<HkElem8> arr14;
    HkArray<HkElem8> arr20;
    HkArray<HkElem8> arr2C;
    char unk38;
    char unk39;
    struct Tail
    {
        int unk3C;
        int unk40;
        int unk44;
        int unk48;
        int unk4C;
        int unk50;
    } tail;

    FUN_00ce9580(const FUN_00ce9580& other);
};

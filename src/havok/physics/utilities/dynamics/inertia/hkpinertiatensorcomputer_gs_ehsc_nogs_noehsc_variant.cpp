#include "f3_common.h"
// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/dynamics/inertia/hkpinertiatensorcomputer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Object
{
};
void __cdecl FUN_00cebdf0(float* source, float value, Object* destination);
void __cdecl FUN_00cebe50(float* source, float scale, Object* destination);
struct Receiver
{
    void FUN_00cecc90(float value);
};
struct State
{
    int first;
    int count;
    int context;
};
void FUN_00cebbb0(void* state, float zero, void* receiver);
int __cdecl ApplyLimitToReceiver(int owner, int context, int count, float limit, Receiver* receiver, float value);
struct FUN_00cebe80_Struct
{
    float unk00;
    float unk04;
    float unk08;
};
void __cdecl FUN_00cebe80(FUN_00cebe80_Struct* pThis, float fParam2, float* pOut);
void __cdecl AddInertiaTensor(float* param_1, float param_2, float* param_3);
struct FUN_00cec6b0_cls
{
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
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    float m_64;
    float m_68;
    float m_6C;
    float m_70;
    float m_74;
    float m_78;
    float m_7C;
    float m_80;
    float m_84;
    float m_88;

    void FUN_00cec6b0(float a1, float b, float* p, float* M);
};
struct CECCD0Value
{
    float m_uiFilterValue;

    void set(float v);
    void ScaleValue(float scale);
};
struct S_00ced230_T
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    float unk10;
    float unk14;
    float unk18;
    float unk1c;
    float unk20;
    float unk24;
    float unk28;
    float unk2c;
    float unk30;
    float unk34;
    float unk38;
    float unk3c;
    float unk40;
    float unk44;
    float unk48;
    float unk4c;
    float unk50;
    float unk54;
    float unk58;
    float unk5c;
    float unk60;
    float unk64;
    float unk68;
    float unk6c;
    float unk70;
    float unk74;
    float unk78;
};
static inline float S_MaxGT(float x, float y)
{
    return (x > y) ? x : y;
}
static inline float S_MaxLT(float x, float y)
{
    return (x < y) ? y : x;
}
void __cdecl FUN_00ced230(float d, S_00ced230_T* p);
struct S_00cee1c0_Heap
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Free(void* p, unsigned int size);
};
struct S_00cee1c0_Router
{
    unsigned int cursor;
    int unk04;
    int unk08;
    int unk0C;
    S_00cee1c0_Heap* heap;
};
struct S_00cee1c0_Arr
{
    unsigned int* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    unsigned int* m_pTrailingData;
};
S_00cee1c0_Router* FUN_00c85750();
float __cdecl FUN_00cedec0(S_00cee1c0_Arr* arr, int unk, float value);
void __cdecl ProcessArrayWithValue(unsigned int* source, int count, int unk, float value);
namespace fnv_anon_00cec3d0 {}
using namespace fnv_anon_00cec3d0;
namespace fnv_anon_00cec3d0 {
struct S00cec3d0_Base
{
    int A;
    int B;
    int C;
    float P1;
    float Pa;
    float Pb;
    float m_fComponent0;
    float m_fComponent1;
    float m_fComponent2;
    float m_fComponent3;
    float m_fComponent4;
    float m_fComponent5;
    float m_fComponent6;

    __declspec(noinline) void FUN_00cec000(const float* v);
};
}

struct S00cec3d0_Face : S00cec3d0_Base
{
    float Fa;
    float Fb;
    float Fc;
    float m_fVertex0X;
    float m_fVertex0Y;
    float m_fVertex0Z;
    float m_fVertex1X;
    float m_fVertex1Y;
    float m_fVertex1Z;
    float m_fVertex2X;
    float m_fVertex2Y;
    float m_fVertex2Z;
    void FUN_00cec3d0(const float* verts, const float* n);
};
static inline float S00cec3d0_Sqr(float x)
{
    return x * x;
}
static inline float S00cec3d0_Cube(float x)
{
    return x * x * x;
}
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_setzero_ps();
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
}
struct Vector
{
    union
    {
        __m128 q;
        struct
        {
            float x, y, z, w;
        };
    };
    Vector()
    {}
    Vector(const Vector& other) : q(other.q)
    {}
    void operator=(const Vector& other)
    {
        q = other.q;
    }
    void set(float x, float y, float z, float w)
    {
        q = _mm_setr_ps(x, y, z, w);
    }
    float& operator()(int i)
    {
        return q.m128_f32[i];
    }
    int maxAxisSecond() const
    {
        if (x < y)
            return y < z ? 2 : 1;
        return x < z ? 2 : 0;
    }
    int maxAxis() const
    {
        if (x < y)
        {
            if (z > y)
                return 2;
            return 1;
        }
        if (z > x)
            return 2;
        return 0;
    }
};
struct Matrix
{
    Vector c0, c1, c2;
};
struct Transform
{
    Vector columns[4];
};
struct Bounds
{
    Vector lo, hi;
};
extern const Vector DAT_01017d10;
void FUN_00d5ac50(char*, Matrix*, Vector*, Vector*, Vector*);
struct Shape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void getAabb(const Transform*, float, Bounds*);
};
void FUN_00cedae0(Shape* shape, const Matrix* input, Vector* outA, Vector* outB);

extern "C" void _mm_store_ps(float*, __m128);

extern const float DAT_01011d78;
extern const double DAT_010240b0;
struct __declspec(align(16)) CE50Vector
{
    float x, y, z, w;
};
struct CE50Matrix
{
    CE50Vector row0, row1, row2;
    void FUN_00c6cd00(const CE50Matrix* source);
    void Subtract(const CE50Matrix* source);
};
struct CE50Body
{
    float volume, mass;
    CE50Vector center;
    CE50Matrix inertia;
    CE50Body() : volume(0.0f), mass(0.0f)
    {
        _mm_store_ps(&center.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row0.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row1.x, _mm_setzero_ps());
        _mm_store_ps(&inertia.row2.x, _mm_setzero_ps());
    }
};
// Diagnostic hypothesis: box mass-property helper implementations.
__declspec(noinline) void __cdecl FUN_00cebaf0(const float* radii, float mass, CE50Body* result)
{
    _mm_store_ps(&result->center.x, _mm_setzero_ps());
    result->mass = mass;
    result->volume = (float)(radii[0] * DAT_010240b0 * radii[1] * radii[2]);
    float scale = mass / 3.0f;
    result->inertia.row0.x = scale * (radii[1] * radii[1] + radii[2] * radii[2]);
    result->inertia.row1.y = scale * (radii[0] * radii[0] + radii[2] * radii[2]);
    result->inertia.row2.z = scale * (radii[0] * radii[0] + radii[1] * radii[1]);
}
static __declspec(noinline) void FUN_00cebfd0(CE50Body* body, float scale)
{
    body->mass *= scale;
    body->inertia.row0.x *= scale;
    body->inertia.row0.y *= scale;
    body->inertia.row0.z *= scale;
    body->inertia.row1.x *= scale;
    body->inertia.row1.y *= scale;
    body->inertia.row1.z *= scale;
    body->inertia.row2.x *= scale;
    body->inertia.row2.y *= scale;
    body->inertia.row2.z *= scale;
}
// @f3 0x009727c0 (community match, verified in this file)
struct __declspec(align(16)) FUN_00971350
{
    float volume, mass;
    CE50Vector center;
    CE50Matrix inertia;
    FUN_00971350();
};

int __cdecl FUN_00cece50(float* src, float mass, float thickness, CE50Body* out, ...)
{
    if (!(mass <= 0.0f) && src[0] > thickness && src[1] > thickness &&
        src[2] > thickness && !(thickness <= 0.0f))
    {
        float x = src[0] - thickness;
        float y = src[1] - thickness;
        float z = src[2] - thickness;
        CE50Vector inner;
        inner.x = x;
        inner.y = y;
        inner.z = z;
        inner.w = 0.0f;

        float outerVolume = (float)(src[0] * DAT_010240b0 * src[1] * src[2]);
        float innerVolume = (float)(inner.x * DAT_010240b0 * inner.y * inner.z);

        FUN_00971350 outer;
        FUN_00971350 inside;
        FUN_00cebaf0((const float*)src, outerVolume, (CE50Body*)&outer);
        FUN_00cebaf0((const float*)&inner.x, innerVolume, (CE50Body*)&inside);

        out->center.x = out->center.y = out->center.z = out->center.w = 0.0f;
        out->inertia.FUN_00c6cd00(&((CE50Body*)&outer)->inertia);
        out->inertia.Subtract(&((CE50Body*)&inside)->inertia);
        out->mass = ((CE50Body*)&outer)->mass - ((CE50Body*)&inside)->mass;
        out->volume = ((CE50Body*)&outer)->volume - ((CE50Body*)&inside)->volume;
        FUN_00cebfd0(out, mass / (outerVolume - innerVolume));
        return 0;
    }
    return 1;
}


extern "C"
{
    void _mm_store_ps(float*, __m128);
    __m128 _mm_load_ps(const float*);
    __m128 _mm_set_ps1(float);
    __m128 _mm_xor_ps(__m128, __m128);
    __m128 _mm_min_ps(__m128, __m128);
    __m128 _mm_max_ps(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}

extern const float DAT_0104da48;
extern const float DAT_01016248;
extern const __m128 DAT_010c44d0;
extern const __m128 DAT_010ec7f0;
__int64 __cdecl FUN_00cebaf0(float* source, float value, void* dest);

__declspec(align(16)) struct Vec4F
{
    float x;
    float y;
    float z;
    float w;
};

__declspec(align(16)) struct Pair
{
    float x;
    float y;
};

// Plain float fields (no __m128 members, no arrays): keeps /GS from adding a cookie.
__declspec(align(16)) struct Mat4
{
    float unk00_0;
    float unk00_1;
    float unk00_2;
    float unk00_3;
    float row0_0;
    float row0_1;
    float row0_2;
    float row0_3;
    float row1_0;
    float row1_1;
    float row1_2;
    float row1_3;
    float row2_0;
    float row2_1;
    float row2_2;
    float row2_3;
};

__declspec(align(16)) struct Solver
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    float unk24;
    float unk28;
    float unk2C;
    float unk30;
    float unk34;
    float unk38;
    float unk3C;
    float unk40;
    float unk44;
    float unk48;
    float unk4C;
    float unk50;
    float unk54;
    float unk58;
    float unk5C;
    float unk60;
    float unk64;
    float unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88;
    void __thiscall FUN_00ced390(State* self, float* a);
    void __thiscall FUN_00cec6b0(float value, float ratio, float* vec, float* mat);
};

__declspec(align(16)) struct Work
{
    Pair pair;
    Mat4 mat;
    Solver solver;
};

struct OutBlock
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    __m128 vec10;
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
};

__declspec(noinline) __int64 __cdecl FUN_00cebaf0(float* source, float value, void* dest)
{
    if (value <= 0.0f)
        return 1;
    OutBlock* result = (OutBlock*)dest;
    float x = source[0], y = source[1], z = source[2];
    _mm_store_ps(&result->m00, _mm_setzero_ps());
    _mm_store_ps(&result->m10, _mm_setzero_ps());
    _mm_store_ps(&result->m20, _mm_setzero_ps());
    result->m00 = result->m11 = result->m22 = 1.0f;
    result->vec10 = _mm_setzero_ps();
    float factor = value * (1.0 / 3.0);
    result->m00 = factor * (y * y + z * z);
    result->m11 = factor * (x * x + z * z);
    result->m22 = factor * (x * x + y * y);
    result->unk00 = x * y * z * 8.0;
    result->unk04 = value;
    return 0;
}

struct MeshTriangle
{
    int a, b, c, material;
};
struct MeshInput
{
    __m128* vertices;
    int count, context;
    MeshTriangle* triangles;
    int triangleCount;
};

inline float MaxVal(float a, float b)
{
    return a > b ? a : b;
}

// @f3 0x009733c0 (community match, verified in this file)
static __forceinline float NativeMaximum(float a, float b)
{
    return b > a ? b : a;
}

struct NativeMassSolverCalls {
    void FUN_00972d20(State* state, float* shift);
    void FUN_00971e80(float value, float ratio, float* vector, float* matrix);
};

void FUN_00971fc0(int first, int count, float* center, float* extent);
void FUN_00971440(float* extent, float value, Pair* result);

int __cdecl FUN_00ced8e0(State* self, float value, OutBlock* out)
{
    if (value <= 0.0f)
        return 1;
    Vec4F b;
    Vec4F a;
    FUN_00971fc0(self->first, self->count, (float*)&b, (float*)&a);
    Work w;
    w.pair.x = 0.0f;
    w.pair.y = 0.0f;
    w.mat.unk00_3 = 0.0f;
    w.mat.unk00_2 = 0.0f;
    w.mat.unk00_1 = 0.0f;
    w.mat.unk00_0 = 0.0f;
    w.mat.row0_0 = 0.0f;
    w.mat.row0_1 = 0.0f;
    w.mat.row0_2 = 0.0f;
    w.mat.row0_3 = 0.0f;
    w.mat.row1_0 = 0.0f;
    w.mat.row1_1 = 0.0f;
    w.mat.row1_2 = 0.0f;
    w.mat.row1_3 = 0.0f;
    w.mat.row2_0 = 0.0f;
    w.mat.row2_1 = 0.0f;
    w.mat.row2_2 = 0.0f;
    w.mat.row2_3 = 0.0f;




    FUN_00971440((float*)&a, value, &w.pair);
    w.mat.unk00_0 = b.x;
    w.mat.unk00_1 = b.y;
    w.mat.unk00_2 = b.z;
    w.mat.unk00_3 = b.w;
    a.x = -b.x;
    a.y = -b.y;
    a.z = -b.z;
    a.w = -b.w;
    reinterpret_cast<NativeMassSolverCalls*>(&w.solver)->FUN_00972d20(self, (float*)&a);
    float r = w.solver.unk64;
    if (r <= 0.0f)
    {
        return 1;
    }
    out->unk00 = r;
    out->unk04 = value;
    reinterpret_cast<NativeMassSolverCalls*>(&w.solver)->FUN_00971e80(value, value / r, (float*)&out->vec10, &out->m00);
    float* outputVector = reinterpret_cast<float*>(&out->vec10);
    const float* center = reinterpret_cast<const float*>(&b);
    outputVector[0] += center[0];
    outputVector[1] = *static_cast<const volatile float*>(&center[1]) + outputVector[1];
    outputVector[2] += center[2];
    outputVector[3] += center[3];
    float* bf = (float*)&b;
    float* u = &w.mat.row0_0;
    float* M = &out->m00;
    double scale = 0.10000000149011612;
    for (int i = 0; i < 3; ++i)
    {
        double t = u[i * 5] * scale;
        if (t > M[i * 5])
        {
            M[i * 5] = t;
            ((float*)&out->vec10)[i] = bf[i];
            for (int j = 0; j < 3; ++j)
            {
                if (j != i)
                {
                    float temp = NativeMaximum(M[i * 4 + j], 0.0f);
                    float v = temp;
                    M[j * 4 + i] = v;
                    M[i * 4 + j] = v;
                }
            }
        }
    }
    return 0;
}


extern "C" __m128 _mm_mul_ps(__m128 _A, __m128 _B);
extern "C" __m128 _mm_set_ps1(float _A);
struct __declspec(align(16)) S00cf0690_Vec
{
    float x, y, z, w;
};
struct S00cf0690_Mass
{
    float volume;
    float mass;
    S00cf0690_Vec center;
    S00cf0690_Vec row0, row1, row2;
};
struct S00cf0690_Xf
{
    S00cf0690_Vec row0, row1, row2, translation;
};
void __cdecl FUN_00ceff00(void*, const S00cf0690_Xf*, float, S00cf0690_Mass*);
extern const float DAT_01013ea4;
static __declspec(noinline) void FUN_00cebfd0(S00cf0690_Mass* p, float density)
{
    float newMass = density * p->volume;
    float k = newMass / p->mass;
    p->mass = newMass;
    __m128 f = _mm_set_ps1(k);
    *(__m128*)&p->row0 = _mm_mul_ps(*(__m128*)&p->row0, f);
    *(__m128*)&p->row1 = _mm_mul_ps(*(__m128*)&p->row1, f);
    *(__m128*)&p->row2 = _mm_mul_ps(*(__m128*)&p->row2, f);
}

#include "f3_common.h"
// src/havok/common/base/math/matrix/hkmatrix4.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/matrix/hkmatrix4.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00de8f30_Class
{
    float m_data[16];
    void TransposeTo(float* dst);
};

struct FUN_00de8f10_Class
{
    float m_data[16];
    void FUN_00de8f10();
};

struct FUN_00de8fa0_Class
{
    float m_data[16];
    void FUN_00de8fa0(const float* src);
};

struct FUN_00de9010_Class
{
    float m_data[16];
    void CopyTo(float* dst);
};

struct FUN_00de9080_Class
{
    float m_data[16];
    void CopyFromFloats(const float* src);
};

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;

struct __declspec(align(16)) hkVector4
{
    float x, y, z, w;
    void operator=(const hkVector4& o)
    {
        *(__m128*)&x = *(const __m128*)&o.x;
    }
};

struct hkMatrix4
{
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
    hkVector4 m_kColumn3;
    void FUN_00de8da0(const hkMatrix4& a, const hkMatrix4& b);
    void FUN_00de8e50(const hkMatrix4& b);
    void operator=(const hkMatrix4& o)
    {
        m_kColumn0 = o.m_kColumn0;
        m_kColumn1 = o.m_kColumn1;
        m_kColumn2 = o.m_kColumn2;
        m_kColumn3 = o.m_kColumn3;
    }
};

struct FUN_00de90f0_Class
{
    __m128 rows[4];
    void FUN_00de90f0(const __m128* source);
};

struct CB20B0_Class
{
    void FUN_00cb20b0(void* src);
};
struct Matrix44_shell
{
    float m_data[16];
    void FUN_00de9130(CB20B0_Class* dst);
};
// @fnv 0x00de9130
void Matrix44_shell::FUN_00de9130(CB20B0_Class* dst)
{
    dst->FUN_00cb20b0(this);
}

struct Owner
{
    __m128 row00;
    __m128 row10;
    __m128 row20;
    __m128 row30;
    void FUN_00de8910(float value);
    void FUN_00de8c50(const __m128* source, float value);
};

struct SourceBlockCDF
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
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
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
};
struct TargetBlockCDF
{
    void FUN_00cd55b0(SourceBlockCDF* pkSource, int iArg);
};
struct FUN_00cdf230_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
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
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    SourceBlockCDF m_kSource;
    TargetBlockCDF m_kRoomNode;
    void FUN_00cdf230(int iArg);
};

extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);

struct Row
{
    __m128 v;
    void operator+=(const Row& o)
    {
        __m128 t = o.v;
        v = _mm_add_ps(t, v);
    }
};

struct MatR
{
    Row m_row0;
    Row m_row1;
    Row m_row2;
    Row m_row3;
    const MatR* Add(const MatR* other);
};

extern float DAT_0104da4c;

__declspec(align(16)) struct S00de9270_Vec
{
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
};

struct S00de9270_Mat
{
    S00de9270_Vec m_r0;
    S00de9270_Vec m_r1;
    S00de9270_Vec m_r2;
    S00de9270_Vec m_r3;
};

struct FUN_00de8910_Class
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    void FUN_00de8910(float s);
};

struct FUN_00de8da0_Class
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    void FUN_00de8da0(void* dst, const float* src);
};

struct S00de9270_cls
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    void FUN_00de9270(void* dst, const S00de9270_Mat* src);
};

extern "C" __m128 _mm_sub_ps(__m128, __m128);

struct MatrixSubtract : hkMatrix4
{
    const hkMatrix4* FUN_00de8ce0(const hkMatrix4* rhs);
};

extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
}

struct C
{
    __m128 m_00;
    __m128 m_10;
    __m128 m_20;
    __m128 m_30;
    const __m128* FUN_00de8d30(const __m128* s);
};

extern "C"
{
    __m128 _mm_unpacklo_ps(__m128, __m128);
    __m128 _mm_unpackhi_ps(__m128, __m128);
    __m128 _mm_movelh_ps(__m128, __m128);
    __m128 _mm_movehl_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    void _mm_store_ss(float*, __m128);
}

struct Matrix4Q
{
    hkVector4 row0;
    hkVector4 row1;
    hkVector4 row2;
    hkVector4 row3;

    Matrix4Q(const Matrix4Q& value)
    {
        *(__m128*)&row0 = *(const __m128*)&value.row0;
        *(__m128*)&row1 = *(const __m128*)&value.row1;
        *(__m128*)&row2 = *(const __m128*)&value.row2;
        *(__m128*)&row3 = *(const __m128*)&value.row3;
    }

    __declspec(noinline) void __fastcall SwapFields(hkMatrix4* context);
};

struct MatrixPointerQ
{
    const Matrix4Q* volatile value;
    MatrixPointerQ(const MatrixPointerQ& other);
};
struct Matrix4V
{
    void FUN_00de8da0(const Matrix4Q* left, MatrixPointerQ right);
};

extern "C"
{
    __m128 _mm_setr_ps(float, float, float, float);
    __m128 _mm_sub_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_set_ps1(float);
    __m128 _mm_cmple_ps(__m128, __m128);
    int _mm_movemask_ps(__m128);
}

extern float DAT_01011d78;
extern float DAT_01012068;
extern __m128 DAT_01017d10;

struct FUN_00de8ea0_cls
{
    float m_data[16];

    int FUN_00de8ea0();
};

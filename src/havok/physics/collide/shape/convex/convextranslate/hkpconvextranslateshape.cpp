#include "f3_common.h"
// src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConvexTranslateShape.h"

// FUN_00dd5e60 : the stub family - load a sub-object pointer out of `this`
// and tail-jump to one of its virtuals.
//   mov ecx,[ecx+0x18] / mov eax,[ecx] / mov edx,[eax+0x2c] / jmp edx
// The target is in EDX, so the virtual takes NO stack argument.  MSVC puts the
// first virtual at vptr+0 (the RTTI pointer is at [vftable-4]), so vtable
// offset 0x2c needs twelve virtuals: eleven dummies and the real one.
struct Sub_dd5e60
{
    virtual void v00();
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
};

struct Own_dd5e60
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Sub_dd5e60* m_sub;  // at +0x18
    void __thiscall FUN_00dd5e60();
};

class hkpShapeCollectionDD5E
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual int getChildShapes(int iKey, int iBufferSize) throw();
};

class hkpShapeBufferDD5E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkpShapeCollectionDD5E* m_pShapeCollection;
    int m_offset;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    hkpShapeCollectionDD5E m_inlineCollection;

    int GetChildShapes(int iKey, int iBufferSize);
};

// @fnv 0x00dd5e10
int hkpShapeBufferDD5E::GetChildShapes(int iKey, int iBufferSize)
{
    const int iMax = iBufferSize - 0x30;
    int iResult = m_pShapeCollection->getChildShapes(iKey, iMax);
    if (iResult < 0)
        return -1;
    if (iResult > iMax)
        return -1;
    if (m_pShapeCollection == &m_inlineCollection)
    {
        m_offset = 0;
        return iResult + 0x30;
    }
    m_offset = iResult;
    return 0x30;
}

struct Sub_dd5e70
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C(const char* name, void* child, int flags);
};

extern int DAT_01268940;

struct Own_dd5e70
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* m_sub;

    void __thiscall FUN_00c90360(Sub_dd5e70* object, const int* attribute);
    void __thiscall AttachChildAndAttribute(Sub_dd5e70* object, int unused);
};

struct FUN_00dd5ea0_class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* FUN_00dd5ea0();
};
// @fnv 0x00dd5ea0
void* FUN_00dd5ea0_class::FUN_00dd5ea0()
{
    return &unk14;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _mm_store_ps(float*, __m128);

struct hkVector4D5F
{
    __m128 m_vComponents;
    void add4(const hkVector4D5F& v)
    {
        m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents);
    }
    void setAdd4(const hkVector4D5F& a, const hkVector4D5F& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
};

struct ObjDD5F50
{
    void* m_vptr;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void __thiscall FUN_00dd5f50_v(const unsigned short* ids, int numIds, hkVector4D5F* verticesOut);
};

struct ClsDD5F50
{
    void* m_unk00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    ObjDD5F50* m_pContainedShape;  // +0x18
    int m_1c;
    hkVector4D5F m_vTranslation;  // +0x20

    void __thiscall FUN_00dd5f50(const unsigned short* ids, int numIds, hkVector4D5F* verticesOut);
};

namespace fnv_00dd60e0 {
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    __int32 m128_i32[4];
    __int64 m128_i64[2];
    unsigned __int32 m128_u32[4];
} __m128;
extern "C" __m128 _mm_sub_ps(__m128 _A, __m128 _B);

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" unsigned long DAT_0126835c;
extern "C" const char DAT_010d1074[];
extern "C" const char DAT_010c41f8[];
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();

struct CommandTimingEntry
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
    static MonitorStream* GetMonitorStream()
    {
        return (MonitorStream*)TlsGetValue(DAT_0126835c);
    }
};

static const char s_kEndTimer[] = "Et";

class HkBoolDD
{
  public:
    char m_cBooleanValue;
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class Vec4DD
{
  public:
    __m128 m_vComponents;
    void setSub4(const Vec4DD& a, const Vec4DD& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
};

struct RayInputDD60
{
    Vec4DD m_vFrom;
    Vec4DD m_vTo;
    unsigned int m_uiFilterInfo;
    void* m_pRayShapeCollectionFilter;
    int pad[2];
};

struct RayOutputDD60
{
    Vec4DD m_vHitNormal;
    float m_fHitFraction;
    int m_iExtraInfo;
    int pad[2];
    unsigned int m_uiShapeKeys[8];
    int m_uiShapeKeyIndex;
    void changeLevel(int delta)
    {
        m_uiShapeKeyIndex += delta;
    }
    void setKey(unsigned int key)
    {
        m_uiShapeKeys[m_uiShapeKeyIndex] = key;
    }
};

class ShapeDD60
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual HkBoolDD RayCast(const RayInputDD60& input, RayOutputDD60& results) const;
};

class ConvexTranslateDD60
{
  public:
    int pad[6];
    const ShapeDD60* m_pContainedShape;
    int pad1c;
    Vec4DD m_vTranslation;
    HkBoolDD FUN_00dd60e0(const RayInputDD60& input, RayOutputDD60& results) const;
};

}  // namespace fnv_00dd60e0

extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);

struct FNV_dd6060_Shape
{

    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();

    virtual void v10();
    virtual void v14();
    virtual void v18();

    virtual void v1C(const hkRotation* rotation, float distance, __m128* output);
};

struct FNV_dd6060_Class : hkpConvexTranslateShape
{

    void __thiscall FUN_00dd6060(const hkRotation* rotation, float distance, __m128* output);
};

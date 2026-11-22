#include "f3_common.h"
// src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/shape/convex/convextranslate/hkpconvextranslateshape.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

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

#include <xmmintrin.h>
struct FUN_00dd5eb0_Sub
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual float v0C(__m128* a);
};
struct FUN_00dd5eb0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_00dd5eb0_Sub* m_18;
    int unk1C;
    __m128 unk20;
    float FUN_00dd5eb0(__m128* a);
};

struct Sub_dd5f10
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
    virtual void v30();
    virtual void v34();
    virtual void v38(float* a, float* b);
};

struct Own_dd5f10
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Sub_dd5f10* m_sub;
    int unk1C;
    __m128 m_trans;
    void __thiscall FUN_00dd5f10(float* a, float* b);
};

struct __declspec(align(16)) hkVector4DD60
{
    __m128 m_vComponents;
    void setAdd4(const hkVector4DD60& a, const hkVector4DD60& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }
};

class hkpConvexVerticesShapeDD60
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void V7() throw();
    virtual void V8() throw();
    virtual void V9() throw();
    virtual void V10() throw();
    virtual int getNumVertices() const throw();
    virtual const hkVector4DD60* GetIndexedVertices(hkVector4DD60* pBuffer) const throw();
};

class hkpTranslateShapeDD60
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    const hkpConvexVerticesShapeDD60* m_pContainedShape;
    int unk1C;
    hkVector4DD60 m_vTranslation;

    hkVector4DD60* FUN_00dd6000(hkVector4DD60* pBuffer) const;
};

// @f3 0x009b4ae0 (community match, verified in this file)
namespace f3m_009b4ae0 {
namespace f3m_009b4ae0 {

struct __declspec(align(16)) KeyBuffer
{
    unsigned short m_key;
    unsigned short unk02;
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
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};

struct Initialiser
{
    int __thiscall init(const void* a, KeyBuffer* buf, int zero);
};

typedef int (__cdecl* Handler)(const void* a, void* b, void* c, KeyBuffer* buf);

struct Table
{
    Handler m_handlers[101];
    int FUN_009b4ae0(const void* a, void* b, void* c) const;
};

}

int f3m_009b4ae0::Table::FUN_009b4ae0(const void* a, void* b, void* c) const
{
    f3m_009b4ae0::KeyBuffer buf;
    int result = ((f3m_009b4ae0::Initialiser*)c)->init(a, &buf, 0);
    if (result == 0)
    {
        unsigned short key = buf.m_key;
        do
        {
            if (key <= 100)
            {
                result = m_handlers[key](a, b, c, &buf);
                key = buf.m_key;
            }
        } while (result == 0);
    }
    else
    {
        result = 1;
    }
    return result;
}
}   // namespace f3m_009b4ae0


#include <string.h>
struct __declspec(align(16)) MyVec
{
    union
    {
        __m128 quad;
        struct
        {
            float x, y, z, w;
        };
    };
};

struct __declspec(align(16)) MyTransform
{
    MyVec col0;
    MyVec col1;
    MyVec col2;
    MyVec col3;
};

struct LocalCdBody
{
    MyTransform m_kMotionTransform;
    void FUN_00cb2240(const void*, const MyTransform*);
};

struct Context2
{
    void* m_pContainedShape;
    int m_zero;
    const void* m_localBody;
    const Context2* m_parentContext;
};

struct ChildShape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24(MyVec* vectors, const Context2* c2, int value);
};

struct Dummy
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ChildShape* m_pContainedShape;
    MyVec m_vTranslation;

    void FUN_00dd61b0(const MyVec* points, const Context2* context, int value);
};

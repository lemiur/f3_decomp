#include "f3_common.h"
// src/havok/physics/collide/shape/convex/hkpconvexshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/convex/hkpconvexshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConvexShape.h"

// @fnv 0x00c9e1e0
int __stdcall FUN_00c9e1e0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    return 2;
}

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

class hkReferencedObjectC9E3
{
  public:
    hkReferencedObjectC9E3() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectC9E3() throw();
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class hkpShapeC9E3 : public hkReferencedObjectC9E3
{
  public:
    hkpShapeC9E3(int iType) : m_ulUserData(0), m_type(iType)
    {}
    hkUlong m_ulUserData;
    int m_type;
};

class hkpConvexShapeC9E3 : public hkpShapeC9E3
{
  public:
    hkpConvexShapeC9E3(int iType, hkReal fRadius) : hkpShapeC9E3(iType)
    {
        m_fSphereRadius = fRadius;
    }
    hkReal m_fSphereRadius;
};

class hkpShapeContainerC9E3
{
  public:
    virtual ~hkpShapeContainerC9E3() throw()
    {}
};

class hkpSingleShapeContainerC9E3 : public hkpShapeContainerC9E3
{
  public:
    hkpSingleShapeContainerC9E3(FUN_00d1df70* pkChild, int iRef) : m_pContainedShape(pkChild)
    {
        if (iRef == 1)
            m_pContainedShape->FUN_00c90510();
    }
    virtual ~hkpSingleShapeContainerC9E3() throw();
    FUN_00d1df70* m_pContainedShape;
};

class FUN_00c9e340 : public hkpConvexShapeC9E3
{
  public:
    hkpSingleShapeContainerC9E3 m_pContainedShape;

    FUN_00c9e340(int iType, hkReal fRadius, FUN_00d1df70* pkChild, int iRef) throw();
    virtual ~FUN_00c9e340() throw();
};

#include <xmmintrin.h>
struct S00c9e1f0_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void method(int arg, float* out);

    float unk04;
    float unk08;
    float unk0C;
    float m_10;

    float GetDotProductOffset(int arg);
};

// Calls method(arg, buf), then returns m_10 plus the 3-component dot product of the vector at arg and buf.
// @f3 0x00916f60 (community match, verified in this file)
float S00c9e1f0_Obj::GetDotProductOffset(int arg)
{
    __declspec(align(16)) float v[4];
    typedef void (__thiscall *VectorMethod)(S00c9e1f0_Obj*, int, float*);
    VectorMethod* methods = *reinterpret_cast<VectorMethod**>(this);
    methods[12](this, arg, v);
    const float* a = reinterpret_cast<const float*>(arg);
    float dot = a[1] * v[1] + a[0] * v[0] + a[2] * v[2];
    float result = dot + m_10;
    return result;
}


struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
};

struct Mat3
{
    Vec4 c0, c1, c2;
};

struct Out
{
    Vec4 v;
    float t;
    int flags;
    int unk01;
    int unk02;
    int b;
    int unk03;
    int unk04;
    int unk05;
    int unk06;
    int unk07;
    int unk08;
    int unk09;
    int c;
};

struct P2
{
    int unk0;
    int unk1;
    Mat3* m;
};

struct Cb;

struct VTable
{
    void(__thiscall* fn)(Cb*, P2*, Vec4*);
};

struct Cb
{
    VTable* vt;
    float f;
};

class Shape
{
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(bool* ok, void* p1, Out* out);
};

struct FN : public Shape
{
    void FUN_00c9e2a0(int p1, int p2, Cb* p3);
};

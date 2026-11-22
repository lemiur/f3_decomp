#include "f3_common.h"
// src/havok/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldcollection.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/trisampledheightfield/hkptrisampledheightfieldcollection.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpTriSampledHeightFieldCollection.h"

struct FUN_00d263f0_t
{
    char pad0[0x18];
    void* m_obj;    // +0x18
    int m_field1c;  // +0x1c
    char pad20[0x20];
    char m_buf40[0x40];  // +0x40

    int FUN_00d263f0(int a, int b);
};

// Calls a virtual function on m_obj with a and b-0x40, then maps the result to an offset in m_buf40 or stores it in m_field1c, returning -1 when out of range.
// @f3 0x009a7e40 (community match, verified in this file)
struct Vt00d263f0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6(int a, int b);
};

int FUN_00d263f0_t::FUN_00d263f0(int a, int b)
{
    int limit = b - 0x24;
    int n = ((Vt00d263f0*)m_obj)->v6(a, limit);
    if (n < 0 || n > limit)
        return -1;
    if (m_obj == (void*)((char*)this + 0x24))
    {
        m_field1c = 0;
        return n + 0x24;
    }
    m_field1c = n;
    return 0x30;
}


struct FUN_00d26760_StandIn
{
    void FUN_00d26760();
};

struct FUN_00d26880_MemoryManagerClient
{
    virtual void BeforeAllocate1() = 0;
    virtual void BeforeAllocate2() = 0;
    virtual void Deallocate(void* object, unsigned short size) = 0;
};

struct FUN_00d26880_MemoryRouter
{
    unsigned char Padding[0x10];
    FUN_00d26880_MemoryManagerClient* Manager;
};

FUN_00d26880_MemoryRouter* _D1A0E0GetMemoryRouter();

struct FUN_00d26880_StandIn : public hkpTriSampledHeightFieldCollection
{
    hkpTriSampledHeightFieldCollection* FUN_00d26880(unsigned int flags);
};

// @fnv 0x00d26390
int FUN_00d26390()
{
    return 0;
}

struct FUN_00d263a0_data
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct FUN_00d263a0_cls
{
    int unk00;
    int unk04;
    FUN_00d263a0_data* unk08;
    int GetNextKey(unsigned int key);
};

// Returns the next key in a sequence derived from the given key, or -1 when the sequence is exhausted.
// @fnv 0x00d263a0
int __thiscall FUN_00d263a0_cls::GetNextKey(unsigned int key)
{
    if ((key & 1) == 0)
        return key | 1;
    unsigned int hi = key >> 16;
    unsigned int idx = ((key >> 1) & 0x7fff) + 1;
    unsigned int uiLimit = unk08->unk10 - 1;
    if (idx == uiLimit)
    {
        unsigned int uiLimit2 = unk08->unk14 - 1;
        hi++;
        idx = 0;
        if (hi == uiLimit2)
            return -1;
    }
    return (int)(((hi << 15) + idx) * 2);
}

// @fnv 0x00d26440
int __stdcall FUN_00d26440(int arg0)
{
    return 0;
}

struct FUN_00d26450_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    void* unk18;
    void* FUN_00d26450();
};
// @fnv 0x00d26450
void* FUN_00d26450_Obj::FUN_00d26450()
{
    return unk18;
}

class hkpSampledHeightFieldShape : public hkpShape
{
  public:
    int m_unk10;
};

struct S_d264d0_Coll : public hkpTriSampledHeightFieldCollection
{
    hkpSampledHeightFieldShape* FUN_00d26450();
    void FUN_00d264d0(unsigned int key, unsigned short value);
};

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);

extern int DAT_010ce390;
extern int DAT_010ce370;

void __stdcall FUN_00d21410(int a, int b);

struct Target26700
{
    void __thiscall FUN_00c90510();
};

struct FUN_00d26700
{
    void* m_vptr1;  // +0x00
    int m_04;
    int m_08;
    int m_0c;
    void* m_vptr2;  // +0x10
    int m_14;
    void* m_p;  // +0x18
    int m_1c;
    volatile float m_f;  // +0x20
    volatile int m_uiX;  // +0x24
    volatile int m_uiY;  // +0x28
    volatile int m_uiZ;  // +0x2c
    __m128 m_v;          // +0x30

    FUN_00d26700(void* p, float f);
};

class hkMemoryAllocatorD267
{
  public:
    virtual ~hkMemoryAllocatorD267() throw();
    virtual void* AllocateMemoryBlock(int n) throw();
    virtual void ReleaseBlock(void* p, int n) throw();
    virtual void* AllocateBufferWithSize(int& n) throw();
    virtual void ReturnMemory(void* p, int n) throw();
};

struct hkMemoryRouterD267
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD267* m_pStreamAllocator;
    hkMemoryAllocatorD267& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterD267 {
extern "C" hkMemoryRouterD267& __cdecl FUN_00c85750() throw();
}

template <class T> struct hkArrayD267
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayD267() throw()
    {
        hkMemoryAllocatorD267& alloc = hkRouterD267::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct RefD267 : public hkReferencedObject
{
    void FUN_00c905b0() throw();
};

class hkBase0D267
{
  public:
    virtual ~hkBase0D267() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08[2];
};

class hkBase1D267
{
  public:
    virtual ~hkBase1D267() throw()
    {}
    int unk14;
};

class FUN_00d26760 : public hkBase0D267, public hkBase1D267
{
  public:
    RefD267* m_pkRef;
    int unk1C[2];
    hkArrayD267<short> m_ppData;

    virtual ~FUN_00d26760() throw();
};

// @fnv 0x00d26760
FUN_00d26760::~FUN_00d26760() throw()
{
    m_pkRef->FUN_00c905b0();
}

struct FUN_00d26450_S
{
    void* FUN_00d26450();
};

struct FUN_00d267c0_Alloc
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void Free(void* data, int size);
};

void* FUN_00c85750(void);
void FUN_00c908c0(int a1, int a2, int a3, int a4);

struct FUN_00d267c0_t : FUN_00d26450_S
{
    void FUN_00d267c0(int mode);
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_setr_ps(float a, float b, float c, float d);
extern "C" void _mm_store_ss(float* p, __m128 a);

struct S00d26510_Bool
{
    char m_cBooleanValue;
};

struct S00d26510_Vec
{
    __m128 m_vComponents;
    void set(float a, float b, float c, float d)
    {
        m_vComponents = _mm_setr_ps(a, b, c, d);
    }
    void mul4(const S00d26510_Vec& v)
    {
        m_vComponents = _mm_mul_ps(v.m_vComponents, m_vComponents);
    }
};

struct S00d26510_Shape
{
    virtual ~S00d26510_Shape();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int m_ulUserData;
    int m_type;
};

struct S00d26510_HFBase
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
    virtual float getHeightAt(int x, int z) const;
    virtual void getTriangleFlip(S00d26510_Bool& out) const;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int m_ulUserData;
    int m_type;
};

struct S00d26510_HF : public S00d26510_HFBase
{
    int m_iXResolution;
    int m_iZResolution;
    int unk18;
    int unk1C;
    S00d26510_Vec m_kHeightScaleVector;
};

struct S00d26510_ShapeB
{
    virtual ~S00d26510_ShapeB();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int m_ulUserData;
    int m_type;
    S00d26510_ShapeB(int type)
    {
        m_sReferenceCount = 1;
        m_ulUserData = 0;
        m_type = type;
    }
};

struct S00d26510_Convex : public S00d26510_ShapeB
{
    float m_fSphereRadius;
    S00d26510_Convex(int type, float radius) : S00d26510_ShapeB(type)
    {
        m_fSphereRadius = radius;
    }
};

struct S00d26510_Tri : public S00d26510_Convex
{
    unsigned short m_kWeldingInfo;
    unsigned char m_eWeldingType;
    unsigned char m_ucWeldingPadding;
    int unk18;
    int unk1C;
    __m128 m_kVertexA;
    __m128 m_kVertexB;
    __m128 m_kVertexC;
    __m128 m_kVertexTransform;

    void* operator new(unsigned int, void* p) throw()
    {
        return p;
    }
    S00d26510_Tri(float radius) : S00d26510_Convex(3, radius)
    {
        m_kWeldingInfo = 0;
        m_eWeldingType = 6;
        m_kVertexTransform = _mm_setzero_ps();
        m_ucWeldingPadding = 0;
    }
    virtual ~S00d26510_Tri();
};

struct S00d26510_Container
{
    virtual ~S00d26510_Container();
    virtual const S00d26510_ShapeB* FUN_00d26510(unsigned int key, void* buffer) const;
};

struct S00d26510_Coll : public S00d26510_Shape, public S00d26510_Container
{
    int unk14;
    S00d26510_HF* m_pHeightFieldShape;
    int m_iChildSize;
    float m_fSphereRadius;
    unsigned short* m_weldingData;
    int m_weldingSize;
    int m_weldingCap;
    __m128 m_kTriangleExtrusion;

    S00d26510_HF* getHF() const;
    virtual const S00d26510_ShapeB* FUN_00d26510(unsigned int key, void* buffer) const;
};

// FUN_00d26870 - MSVC this-adjusting thunk for a secondary base.
//
// The original is 8 bytes:
//     00d26870  83 e9 10          sub  ecx, 0x10
//     00d26873  e9 08 00 00 00    jmp  00d26880
//
// It is the adjustor thunk that cl 15.00.30729.01 emits for a virtual that a
// DERIVED class overrides but that was DECLARED by a SECONDARY base: the slot
// in the secondary base's vftable must hand the callee the address of the
// complete object, so the thunk subtracts the offset of the secondary base
// (0x10) from the incoming `this` before tail-jumping to the implementation.
//
// The game's own RTTI confirms the shape (the image has intact RTTI):
//     010ce36c  COL -> 011322d0, off = 16      (secondary vftable)
//     010ce370  00d26870  <-- this thunk, slot 0 of that vftable
//     010ce38c  COL -> 01132274, off = 0       (primary vftable)
//     010ce390  00d26880  <-- the implementation, slot 0 of the primary vftable
//     both COLs point at the type descriptor of hkpTriSampledHeightFieldCollection
// so the class really does have a second base at +0x10 and really does override
// that base's first virtual.
//
// Source shape (the standard cl adjustor-thunk recipe):
//   * two bases declare the same virtual at the same slot,
//   * the first base is padded so that the second base lands at +0x10,
//   * the derived class overrides the virtual - DECLARED ONLY, never defined,
//     so the `jmp` target stays an undefined external and the checker resolves
//     it from the original's own bytes (0x00d26880),
//   * a DEFINED key function in the derived class makes the compiler emit the
//     vftable, and with it the thunk.
//
// The thunk is the only DEFINED function symbol carrying the name FUN_00d26870
// (the three declarations below are undefined externals), which is what the
// canary requires.

struct TtrcHeightFieldShapeBase
{
    TtrcHeightFieldShapeBase();
    virtual void FUN_00d26870();
    char pad[0x0c];  // the vptr plus padding: this base is 0x10 bytes
};

struct TtrcHeightFieldShape
{
    TtrcHeightFieldShape();
// @fnv 0x00d26870
    virtual void FUN_00d26870();
};

struct TtrcHeightFieldCollection : public TtrcHeightFieldShapeBase, public TtrcHeightFieldShape
{
    TtrcHeightFieldCollection();
    virtual void key_fn();  // key function - defined, so the vftable is emitted
    void FUN_00d26870();    // the shared override - declared only
};

TtrcHeightFieldCollection::TtrcHeightFieldCollection()
{}
void TtrcHeightFieldCollection::key_fn()
{}

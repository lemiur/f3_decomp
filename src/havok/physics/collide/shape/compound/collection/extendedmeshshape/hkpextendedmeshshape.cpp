#include "f3_common.h"
// src/havok/physics/collide/shape/compound/collection/extendedmeshshape/hkpextendedmeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/compound/collection/extendedmeshshape/hkpextendedmeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d554a0_class
{
    int m_d0;
    int __thiscall FUN_00d1f1e0();
    int __thiscall GetOrInitValue();
};

void __cdecl FUN_00d26230(void* first, void* second, void* third, float value, int last);
struct FUN_00d56040_shell
{
    void __thiscall FUN_00d56040(void* first, float value, int last);
};

struct hkMemoryAllocator;

struct AudioMgr
{
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
__declspec(nothrow) BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

__declspec(nothrow) void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* arr, int numElem, int sizeElem);

struct hkShortArray
{
    short* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserveExactly(int n)
    {
        AudioMgr* m = audio();
        if (getCapacity() < n)
            FUN_00c908c0(m->heap(), this, n, sizeof(short));
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(short));
        }
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
};

struct Elem
{
    char pad0[0x14];
    int m_uiItemCount;
    char pad1[0x4c - 0x18];
    int m_offset;
    char pad2[0x60 - 0x50];
};

struct FUN_00d56070_class
{
    char pad0[0xb0];
    int m_bits;
    Elem* m_pElements;
    int m_iCapacityFlags;
    char pad1[0xcc - 0xbc];
    hkShortArray m_aiIndexedValues;
    void SetShortAtKey(int key, short value);
};

struct S_00d56880_Alloc
{
};
struct S_00d56880_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    S_00d56880_Alloc* m_pStreamAllocator;
    static S_00d56880_Router& FUN_00c85750();
    S_00d56880_Alloc& heap()
    {
        return *m_pStreamAllocator;
    }
};
void __cdecl FUN_00c908c0(S_00d56880_Alloc& a, void* arr, int n, int elemSize);

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct S_00d56880_Elem
{
    unsigned char unk0;
    unsigned char unk1;
    short unk2;
    int unk4;
    short unk8;
    short unka;
    int unkc;
    int unk10;
    void* m_data;
    int m_iElementCount;
    int m_cap;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    S_00d56880_Elem()
    {
        unk8 = 0;
        unk2 = 0;
        unka = 1;
        unk0 = 1;
        unk1 = 1;
        unkc = 0;
        unk4 = 0;
        unk10 = 0;
        m_data = 0;
        m_iElementCount = 0;
        m_cap = 0x80000000;
    }
};

struct S_00d56880_Array
{
    S_00d56880_Elem* m_data;
    int m_iElementCount;
    int m_cap;
    int getCapacity() const
    {
        return m_cap & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(S_00d56880_Alloc& a, int n)
    {
        if (getCapacity() < n)
        {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(a, this, newSize, sizeof(S_00d56880_Elem));
        }
    }
    __forceinline S_00d56880_Elem* expandBy(int n)
    {
        S_00d56880_Alloc& a = S_00d56880_Router::FUN_00c85750().heap();
        int oldsize = m_iElementCount;
        GrowArrayCapacity(a, oldsize + n);
        S_00d56880_Elem* p = m_data + m_iElementCount;
        for (int i = 0; i < n; i++)
            new (p + i) S_00d56880_Elem();
        m_iElementCount += n;
        return m_data + oldsize;
    }
};

struct S_00d56880
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    S_00d56880_Array m_aiIndexedValues;
    S_00d56880_Elem* AppendElement();
};

struct FUN_00d55520_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int m_18;
};

struct SpawnedOwner
{
    int unk00;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int m_0xdc;

    int FUN_00d55530(int aiIndex);
};

struct FUN_00d555d0_cls
{
    int m_d0;
    int GetSpawnedValue(int aiKey);
};

struct Child
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual int v18(int a1, int a2);
};

struct Group
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    Child** m_14;
    int m_18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    unsigned int m_3c;
};

struct FUN_00d55a90_cls
{
    int unk00;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    Group* m_0c0;
    int m_0c4;

    int __thiscall FUN_00d55a90(int a1, int a2);
};

// @f3 0x009e3420 (community match, verified in this file)
struct ChildF3
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual int v18(int a, int b);
};
struct GroupF3
{
    int unk00, unk04, unk08, unk0C;
    ChildF3** m_ppChildren;
    int m_iChildCount;
    unsigned char m_bA;
    unsigned char m_bB;
};
struct OwnerD55AF3
{
    int unk00;
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
    GroupF3* m_pGroups;
    int m_iGroupCount;
};
int FUN_00d55a90_cls::FUN_00d55a90(int a1, int a2)
{
    OwnerD55AF3* self = (OwnerD55AF3*)this;
    int i = 0;
    if (self->m_iGroupCount > 0)
    {
        volatile int off = 0;
        do
        {
            GroupF3* pGroup = self->m_pGroups;
            pGroup = (GroupF3*)((char*)pGroup + off);
            for (int iChildIndex = 0; iChildIndex < pGroup->m_iChildCount; ++iChildIndex)
            {
                int r = pGroup->m_ppChildren[iChildIndex]->v18(a1, 0x100);
                int limit;
                if (pGroup->m_bA == 0 && pGroup->m_bB == 0)
                    limit = 0x200;
                else if (pGroup->m_bB == 0 && pGroup->m_bA != 0)
                    limit = 0x1d0;
                else
                    limit = 0x1a0;
                if (r < 0 || r > limit)
                    return -1;
            }
            ++i;
            off += 0x40;
        } while (i < self->m_iGroupCount);
    }
    return 0xc0;
}


struct __declspec(align(16)) S_00d55bd0_Vector4
{
    float x;
    float y;
    float z;
    float w;
};

struct S_00d55bd0_Bool
{
    char m_cBooleanValue;
    S_00d55bd0_Bool(bool b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct S_00d55bd0_Shape
{
    int unk0;
    int unk4;
    int unk8;
    int m_type;
};

struct S_00d55bd0_TriangleShape : S_00d55bd0_Shape
{
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    S_00d55bd0_Vector4 m_kVertexA;
    S_00d55bd0_Vector4 m_kVertexB;
    S_00d55bd0_Vector4 m_kVertexC;
};

S_00d55bd0_Bool IsDegenerateTriangle(const S_00d55bd0_Vector4& a, const S_00d55bd0_Vector4& b,
                                     const S_00d55bd0_Vector4& c, float tolerance);

struct S_00d55bd0_TrianglesSubpart
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int m_iTriangleCount;
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
};

struct S_00d55bd0_ShapesSubpart
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int m_iChildShapeCount;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
};

static const float DAT_011b2e90 = 1e-07f;

struct S_00d55bd0_MeshShape
{
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void vf10();
    virtual const S_00d55bd0_Shape* GetShapeForKey(unsigned int key, void* buffer) const;
    int unk4;
    int unk8;
    int unkc;
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int m_iNumBitsForSubpartIndex;
    S_00d55bd0_TrianglesSubpart* m_kTrianglesSubparts;
    unsigned int m_numTrianglesSubparts;
    int unkac;
    S_00d55bd0_ShapesSubpart* m_kShapesSubparts;
    unsigned int m_numShapesSubparts;

    unsigned int FindNextNonDegenerateShapeKey(unsigned int initialKey) const;
};

// @f3 0x009e3d00 (community match, verified in this file)
struct TriSubpartF3
{
    int unk00, unk04, unk08, unk0C;
    int m_iTriangleCount;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
};
struct ShapeSubpartF3
{
    int unk00, unk04, unk08, unk0C, unk10;
    int m_iChildShapeCount;
    int unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
};
struct MeshShapeF3
{
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void vf10();
    virtual const S_00d55bd0_Shape* GetShapeForKey(unsigned int key, void* buffer) const;
    int unk04;
    int m_iNumBitsForSubpartIndex;
    int unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    TriSubpartF3* m_kTrianglesSubparts;
    unsigned int m_numTrianglesSubparts;
    ShapeSubpartF3* m_kShapesSubparts;
    unsigned int m_numShapesSubparts;
};
unsigned int S_00d55bd0_MeshShape::FindNextNonDegenerateShapeKey(unsigned int initialKey) const
{
    const MeshShapeF3* self = (const MeshShapeF3*)this;
    // hkpShapeBuffer (512 bytes, 16-aligned); non-char element type, see brief
    __declspec(align(16)) unsigned int buffer[128];

    unsigned int subpartIndex = (initialKey & 0x7fffffff) >> (32 - self->m_iNumBitsForSubpartIndex);
    int terminalIndex = initialKey & (~0U >> self->m_iNumBitsForSubpartIndex);
    unsigned int subpartType = initialKey & 0x80000000;

    while (1)
    {
        if (subpartType == 0)
        {
            if (++terminalIndex >= self->m_kTrianglesSubparts[subpartIndex].m_iTriangleCount)
            {
                subpartIndex++;
                terminalIndex = 0;
                if (subpartIndex >= self->m_numTrianglesSubparts)
                {
                    if (self->m_numShapesSubparts == 0)
                    {
                        return 0xffffffff;
                    }
                    subpartIndex = 0;
                    subpartType = 0x80000000;
                    terminalIndex = -1;
                    continue;
                }
            }
        }
        else
        {
            if (++terminalIndex >= self->m_kShapesSubparts[subpartIndex].m_iChildShapeCount)
            {
                subpartIndex++;
                if (subpartIndex >= self->m_numShapesSubparts)
                {
                    return 0xffffffff;
                }
                terminalIndex = 0;
            }
        }

        unsigned int key = (subpartIndex << (32 - self->m_iNumBitsForSubpartIndex)) | subpartType | terminalIndex;
        const S_00d55bd0_Shape* shape = self->GetShapeForKey(key, buffer);
        if (shape->m_type == 4)
        {
            const S_00d55bd0_TriangleShape* pTriangle = static_cast<const S_00d55bd0_TriangleShape*>(shape);
            if (IsDegenerateTriangle(pTriangle->m_kVertexA, pTriangle->m_kVertexB, pTriangle->m_kVertexC, DAT_011b2e90))
            {
                continue;
            }
        }
        return key;
    }
}


namespace fnv_00d56160 {
__declspec(align(16)) struct FUN_00d56160_vec
{
    float x;
    float y;
    float z;
    float w;
};

__declspec(align(16)) struct FUN_00d56160_out
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    FUN_00d56160_vec m_20;
    FUN_00d56160_vec m_30;
    FUN_00d56160_vec m_40;
};

struct FUN_00d56160_big
{
    FUN_00d56160_out m_out;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
};

struct FUN_00d56160_items
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_uiItemCount;
};

struct FUN_00d56160_sub
{
    FUN_00d56160_out* FUN_00d55ce0(unsigned int value, FUN_00d56160_out* out);
};

extern float DAT_011b2e90;
unsigned char* __cdecl IsDegenerateTriangle(unsigned char* out, FUN_00d56160_vec* a, FUN_00d56160_vec* b,
                                            FUN_00d56160_vec* c, float r);

struct FUN_00d56160_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_00d56160_sub m_sub;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int m_b0;

    int Vec4(FUN_00d56160_items* items, unsigned int value);
};

}  // namespace fnv_00d56160

struct hkReferencedObject
{
    void removeReference();
};
struct BufferAllocator
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Release(void* data, unsigned bytes);
};
struct BSAudio
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    BufferAllocator* allocator;
};
BSAudio* FUN_00c85750();
struct Container
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    hkReferencedObject** data;
    int count;
    unsigned capacityFlags;
    void FUN_00d56800();
};

namespace fnv_00d56e00 {
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct BSAudio
{
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

BSAudio* FUN_00c85750();

extern "C" char DAT_010d0ecc[];
extern "C" char DAT_010d0ea8[];
extern "C" char DAT_010c6fb0[];
extern "C" char DAT_0102e388[];

struct Elem40
{
    int v00, v04, v08, v0c, v10, v14, v18, v1c;
    int v20, v24, v28, v2c, v30, v34, v38, v3c;
    void FUN_00d56800();
};

struct Elem60
{
    int v00, v04, v08, v0c, v10, v14, v18, v1c;
    int v20, v24, v28, v2c, v30, v34, v38, v3c;
    int v40, v44, v48, v4c, v50, v54, v58, v5c;
};

template <class T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void ClearAndRelease()
    {
        hkMemoryAllocator& alloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void destroyAndDeallocate()
    {
        hkMemoryAllocator& alloc = FUN_00c85750()->heap();
        int n = m_iElementCount;
        T* p = m_data;
        for (int i = 0; i < n; i++)
        {
            p[i].FUN_00d56800();
        }
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct Obj
{
    void* m_vtbl;
    int unk04, unk08, unk0c;
    void* m_vtbl10;
    int unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0;
    hkArray<Elem60> mb4;
    hkArray<Elem40> mc0;
    hkArray<short> mcc;
    void FUN_00d56e00();
};

}  // namespace fnv_00d56e00

struct FUN_00d55b40_Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    float unk20[4];
    float unk30[4];
    float unk40[4];
};

struct __declspec(align(16)) FUN_00d55b40_Buffer
{
    int v[128];
};

extern char* __cdecl IsDegenerateTriangle(char* result, const void* v0, const void* v1, const void* v2, float tol);

struct bhkShapeOwner
{
    virtual void* v0();
    virtual void* v1();
    virtual void* v2();
    virtual int v3(int);
    virtual void* v4();
    virtual void* v5(int, void*);
    struct
    {
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
        int unk60;
        int unk64;
        int unk68;
        int unk6c;
        int unk70;
        int unk74;
        int unk78;
        int unk7c;
        int unk80;
        int unk84;
        int unk88;
        int unk8c;
        int unk90;
        int unk94;
        int unk98;
        int unk9c;
        int unka0;
        int unka4;
    } unk04;
    int unk_a8;
    int unk_ac;
    int unk_b0;
    int unk_b4;
    int GetShapeKey();
};

// @f3 0x009e3c70 (community match, verified in this file)
extern "C" char* __cdecl FUN_00a564b0(char* result, const void* v0, const void* v1, const void* v2, float tol);
int bhkShapeOwner::GetShapeKey()
{
    FUN_00d55b40_Shape* shape;
    FUN_00d55b40_Buffer buffer;
    char degenerate;
    unsigned int key;

    if (this->unk04.unk44 + this->unk04.unk4c == 0)
        return -1;

    key = (this->unk04.unk44 != 0) ? 0u : 0x80000000u;

    shape = (FUN_00d55b40_Shape*)this->v5((int)key, &buffer);

    if (shape->unk0c != 4)
        return (int)key;

    char* result = FUN_00a564b0(&degenerate, &shape->unk20[0], &shape->unk30[0], &shape->unk40[0], 1.0e-7f);

    if (*result == 0)
        return (int)key;

    return this->v3((int)key);
}


// @fnv 0x00d554e0
void __stdcall FUN_00d554e0(int a)
{}

// @fnv 0x00d554f0
void __stdcall FUN_00d554f0(int a0)
{}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

struct hkVector4D562
{
    __m128 m_vComponents;

    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

struct ElemD562
{
    unsigned char m_b0;
    unsigned char m_b1;
    short m_s2;
    int m_i4;
    short m_s8;
    short m_sA;
    int m_iC;
    int m_i10;
    int unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    hkVector4D562 m_kVec;
    int unk40, unk44;
    unsigned char unk48;
    unsigned char m_b49;
    short unk4A;
    int unk4C;
    int m_i50;
    int unk54, unk58, unk5C;

    ElemD562()
    {
        m_s8 = 0;
        m_s2 = 0;
        m_b0 = 0;
        m_b1 = 1;
        m_sA = 1;
        m_iC = 0;
        m_i4 = 0;
        m_i10 = 0;
        m_b49 = 0;
        m_kVec.setZero4();
        m_i50 = 0;
    }
};

struct ArrayD562
{
    ElemD562* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocator& alloc, int n)
    {
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(ElemD562));
        }
    }
    __forceinline ElemD562& AllocatePair()
    {
        hkMemoryAllocator& alloc = audio()->heap();
        int oldSize = m_iElementCount;
        reserve(alloc, oldSize + 1);
        new (m_data + m_iElementCount) ElemD562();
        m_iElementCount += 1;
        return m_data[oldSize];
    }
};

struct OwnerD562
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    ElemD562 m_kInline;
    int unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    int unkB0;
    ArrayD562 m_kArray;

    ElemD562* FUN_00d562f0();
};

namespace fnv_00d569c0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_set_ps1(float fA);
extern "C" __m128 _mm_setzero_ps();

struct hkVector4D569
{
    __m128 m_vComponents;

    hkVector4D569()
    {}
    hkVector4D569(const hkVector4D569& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void operator=(const hkVector4D569& kV)
    {
        m_vComponents = kV.m_vComponents;
    }
    void SetAllComponents(float fA)
    {
        m_vComponents = _mm_set_ps1(fA);
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

template <class T> struct hkArrayD569
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrayD569() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};

class hkBaseObjectD569
{
  public:
    virtual ~hkBaseObjectD569() throw();
};

class hkReferencedObjectD569 : public hkBaseObjectD569
{
  public:
    virtual ~hkReferencedObjectD569() throw();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkpShapeD569 : public hkReferencedObjectD569
{
  public:
    virtual ~hkpShapeD569() throw();

    unsigned long m_ulUserData;
    unsigned int m_type;
};

class hkpShapeContainerD569
{
  public:
    virtual ~hkpShapeContainerD569() throw();
};

class FUN_00d21410 : public hkpShapeD569, public hkpShapeContainerD569
{
  public:
    FUN_00d21410(unsigned int uiType, unsigned char ucCollectionType) throw();
    virtual ~FUN_00d21410() throw();

    char m_bDisableWelding;
    unsigned char m_eCollectionType;
};

struct hkpExtendedMeshShapeTrianglesSubpartD569
{
    hkpExtendedMeshShapeTrianglesSubpartD569()
    {
        m_type = 0;
        m_materialIndexStridingPad = 0;
        m_pVertexBase = 0;
        m_pIndexBase = 0;
        m_bFlipAlternateTriangles = 0;
        m_iTriangleOffset = 0;
        m_iMaterialIndexType = 1;
        m_iVertexStriding = 0;
        m_iIndexStriding = 0;
        m_iNumTriangles = 1;
        m_kVertexTransform.setZero4();
    }

    unsigned char m_type;
    unsigned char m_iMaterialIndexType;
    unsigned short m_iIndexStriding;
    const void* m_pVertexBase;
    unsigned short m_iVertexStriding;
    unsigned short m_iNumTriangles;
    const void* m_materialIndexStridingPad;
    const void* m_pIndexBase;
    unsigned int unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    hkVector4D569 m_kVertexTransform;
    unsigned int unk60, unk64;
    unsigned char unk68;
    unsigned char m_bFlipAlternateTriangles;
    unsigned short unk6A;
    unsigned int unk6C;
    int m_iTriangleOffset;
    unsigned int unk74, unk78, unk7C;
};

class FUN_00d569c0 : public FUN_00d21410
{
  public:
    FUN_00d569c0(float fRadius, int iNumBitsForSubpartIndex) throw();
    virtual ~FUN_00d569c0() throw();

    unsigned int unk18, unk1C;
    hkpExtendedMeshShapeTrianglesSubpartD569 m_kTrianglesSubpart;
    hkVector4D569 m_kScaling;
    hkVector4D569 m_kAabbHalfExtents;
    hkVector4D569 m_kAabbCenter;
    int m_iNumBitsForSubpartIndex;
    hkArrayD569<void*> m_kTrianglesSubparts;
    hkArrayD569<void*> m_kShapesSubparts;
    hkArrayD569<unsigned short> m_kWeldingInfo;
    unsigned char m_eWeldingType;
    unsigned int m_uiShapeFlags;
    int m_iFinishingFlag;
    float m_fTriangleRadius;
};

static const float DAT_0104e148 = -3.40282e+38f;

}  // namespace fnv_00d569c0

struct FUN_00d554c0_Class
{
    int unk00;
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
    __m128 unk80;
    void FUN_00d554c0(const __m128* value);
};

extern "C" void _ReadWriteBarrier(void);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_xor_ps(__m128, __m128);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);

extern float DAT_0104da48;
extern __m128 DAT_010c44d0;

struct hkVec4
{
    __m128 m_vComponents;
    void setMin4(const hkVec4& a, const hkVec4& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    void setMax4(const hkVec4& a, const hkVec4& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
};
struct hkAabbS
{
    hkVec4 m_kMinimumCorner;
    hkVec4 m_kMaximumCorner;
};
struct hkQuatS
{
    hkVec4 m_vec;
};
struct hkTransformS
{
    hkVec4 m_kColumn0;
    hkVec4 m_kColumn1;
    hkVec4 m_kColumn2;
    hkVec4 m_vTranslation;
    void FUN_00cb2d90(const hkQuatS& q);
};
struct hkShapeS
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const hkTransformS& t, float tolerance, hkAabbS& out) const;
};
struct ShapeHolderS
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkShapeS** m_shapes;
    int m_numShapes;
    int unk1C;
    hkQuatS m_rotation;
    hkVec4 m_vTranslation;
};

ShapeHolderS* volatile g_src;
hkAabbS* volatile g_out;
extern void SomeOtherCall_d558(hkAabbS*);

extern "C"
{
    __m128 _mm_set_ps1(float a);
    __m128 _mm_setr_ps(float a, float b, float c, float d);
    __m128 _mm_xor_ps(__m128 a, __m128 b);
    __m128 _mm_min_ps(__m128 a, __m128 b);
    __m128 _mm_max_ps(__m128 a, __m128 b);
}

typedef float hkReal;

extern __m128 DAT_010c44d0;

struct hkTransformq;
extern hkTransformq DAT_01268370;

struct __declspec(align(16)) hkVector4q
{
    __m128 m_vComponents;

    hkVector4q()
    {}
    hkVector4q(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void set(hkReal x, hkReal y, hkReal z, hkReal w = 0.0f)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    __forceinline void SetAllComponents(hkReal r)
    {
        m_vComponents = _mm_set_ps1(r);
    }
    __forceinline void setMin4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline void setMax4(const hkVector4q& a, const hkVector4q& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
    __forceinline const hkReal& operator()(int i) const
    {
        return reinterpret_cast<const hkReal*>(&m_vComponents)[i];
    }
    void FUN_00c7f640(const hkTransformq& t, const hkVector4q& v);
};

struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};

struct TrianglesSubpart
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int m_iTriangleCount;
    const char* m_pMaterialIndexBase;
    int m_iTriangleIndexStride;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    const char* m_pMaterialDataBase;
    int m_iMaterialStriding;
    signed char m_ucIndexStridingType;
};

struct VertexScratch
{
    __m128 q;
    __forceinline float& at(int i)
    {
        return ((float*)&q)[i];
    }
    __forceinline void load(const float* p)
    {
        at(0) = p[0];
        at(1) = p[1];
        at(2) = p[2];
    }
};
extern "C" void _ReadWriteBarrier(void);
extern "C"
{
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_and_ps(__m128, __m128);
    void _mm_store_ss(float*, __m128);
}

extern int DAT_010c749c;
extern int DAT_010d0e5c;
extern __m128 DAT_010c4c10;
extern float DAT_011b153c;

void __cdecl CopySixteenByteBlocks(void* dst, const void* src);
void __cdecl FUN_00d570d0(void* dst, const void* src);

struct HelperC9E340
{
    void FUN_00c9e340(int type, float radius, const S_00d55bd0_Shape* child, int unk);
};
struct HelperCB2D90
{
    void FUN_00cb2d90(const void* rotation);
};
struct HelperD5D7A0
{
    const S_00d55bd0_Shape* FUN_00d5d7a0(const S_00d55bd0_Shape* child, const void* transform, int unk);
};

struct MeshSubpartTriangle
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int m_iTriangleCount;
    const void* m_pMaterialIndexBase;  // 0x18
    int m_iTriangleIndexStride;        // 0x1c
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S_00d55bd0_Vector4 m_kVertexTransform;  // 0x30
    const void* m_pMaterialDataBase;        // 0x40
    int m_iMaterialStriding;                // 0x44
    char m_ucIndexStridingType;             // 0x48
    char m_bFlipAlternateTriangles;         // 0x49
    short unk4A;                            // 0x4a
    int m_weldingInfoOffset;                // 0x4c
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
};

struct MeshSubpartShape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    const S_00d55bd0_Shape** m_kChildShapes;  // 0x14
    int m_iChildShapeCount;                   // 0x18
    int unk1C;
    int m_rotation[4];  // 0x20
    union
    {
        S_00d55bd0_Vector4 m_vTranslation;
        struct
        {
            float tx, ty, tz;
            int m_type;
        };
    };
};

struct Transform
{
    S_00d55bd0_Vector4 m_rotation[3];
    S_00d55bd0_Vector4 m_vTranslation;
};

struct TriangleShape
{
    int vtable;                             // 0x00
    short unk04;                            // 0x04
    short m_iObjectReferenceCount;          // 0x06
    int m_ulUserData;                       // 0x08
    int m_type;                             // 0x0c
    float m_fSphereRadius;                  // 0x10
    short m_kWeldingInfo;                   // 0x14
    char m_eWeldingType;                    // 0x16
    char m_ucWeldingPadding;                // 0x17
    int unk18;                              // 0x18
    int unk1c;                              // 0x1c
    S_00d55bd0_Vector4 m_kVertexA;          // 0x20
    S_00d55bd0_Vector4 m_kVertexB;          // 0x30
    S_00d55bd0_Vector4 m_kVertexC;          // 0x40
    S_00d55bd0_Vector4 m_kVertexTransform;  // 0x50

    __forceinline void setVertices(const __m128* vertices)
    {
        *(__m128*)&m_kVertexA = vertices[0];
        *(__m128*)&m_kVertexB = vertices[1];
        *(__m128*)&m_kVertexC = vertices[2];
    }

    __forceinline TriangleShape(float radius)
    {
        m_iObjectReferenceCount = 1;
        m_fSphereRadius = radius;
        m_ulUserData = 0;
        m_type = 3;
        vtable = (int)&DAT_010c749c;
        m_kWeldingInfo = 0;
        m_eWeldingType = 6;
        *(__m128*)&m_kVertexTransform = _mm_setzero_ps();
        m_ucWeldingPadding = 0;
    }
};

struct ExtendedMeshShape : S_00d55bd0_MeshShape
{
    int unkb8;
    const unsigned short* m_weldingInfoData;  // 0xbc
    int m_weldingInfoSize;                    // 0xc0
    int unkc4;                                // 0xc4
    char m_eWeldingType;                      // 0xc8
    char unkc9;
    short unkca;
    int unkcc;
    int unkd0;
    float m_fTriangleRadius;  // 0xd4
    int unkd8;

    const S_00d55bd0_Shape* FUN_00d55ce0(unsigned int key, void* buffer) const;
};

extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern __m128 DAT_010c71d0;
struct MeshEntry
{
    void FUN_00d4ad60(int);
};
struct MeshOwner
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    __m128 m_vHalfExtents;
    __m128 m_kCenterPosition;
    int unkB0, unkB4, unkB8, unkBC;
    ShapeHolderS* m_shapes;
    int m_uiItemCount;
    int unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;
    int m_children;
    S_00d56880_Elem* AppendElement();
    int FUN_00d55520(int);
    int FUN_00d56900(volatile int);
};

namespace fnv_00d56200 {
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_10;
};

struct SubBuf
{
    void* m_00;
    int m_04;
    int m_08;
};

AudioHolder* __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(void* a, void* b, int c, int d);

struct Allocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10(void* p, int n);
};

struct FUN_00d56200_cls
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    char* m_b4;
    int m_b8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    SubBuf m_cc;
    unsigned char m_d8;
    void FUN_00d56200(int a1);
};

// FUN_00d56200 wrapper for the pack
}  // namespace fnv_00d56200

struct ChanEntry
{
    unsigned char unk00;
    unsigned char type;
    short scale;
    unsigned char* data;
    unsigned short stride;
    short unk0A;
    unsigned char* base;
    unsigned char* get(unsigned int off)
    {
        unsigned char* pData = data;
        unsigned char* pBase = base;
        int iScale = scale;
        if (pData)
        {
            unsigned char* p = pData + stride * off;
            if (type == 1)
                return pBase + *p * iScale;
            return pBase + *(unsigned short*)p * iScale;
        }
        return 0;
    }
};
struct ChanGroup
{
    ChanEntry ch;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
};
struct ChanGroupNeg
{
    ChanEntry ch;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
};
struct SpawnedOwnerQ
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1C;
    ChanEntry inlineCh;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    void* unk50;
    void* unk54;
    void* unk58;
    void* unk5C;
    void* unk60;
    void* unk64;
    void* unk68;
    void* unk6C;
    void* unk70;
    void* unk74;
    void* unk78;
    void* unk7C;
    void* unk80;
    void* unk84;
    void* unk88;
    void* unk8C;
    void* unk90;
    void* unk94;
    void* unk98;
    void* unk9C;
    void* unkA0;
    void* unkA4;
    void* unkA8;
    void* unkAC;
    unsigned int bits;
    ChanGroup* groups;
    unsigned int numGroups;
    int unkBC;
    ChanGroupNeg* negGroups;
    int FUN_00d55530(int aiIndex);
};

extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);

extern float DAT_01011d78;

struct __declspec(align(16)) Vec4Q
{
    float x, y, z, w;
    void __thiscall FUN_00c7f640(const void* transform, const Vec4Q* point);
};

struct AabbQ
{
    Vec4Q m_kMinimumCorner;
    Vec4Q m_kMaximumCorner;
};

struct Vec3
{
    float x, y, z;
};

extern "C" __m128 _mm_load_ps1(const float* p);
extern "C" __m128 _mm_min_ps(__m128, __m128);
struct hkVector4D563
{

    __m128 m_vComponents;

    hkVector4D563()
    {}

    hkVector4D563(const hkVector4D563& v)
    {
        m_vComponents = v.m_vComponents;
    }

    void operator=(const hkVector4D563& v)
    {
        m_vComponents = v.m_vComponents;
    }

    void SetAllComponents(const float& f)
    {
        m_vComponents = _mm_load_ps1(&f);
    }

    void setAdd4(const hkVector4D563& a, const hkVector4D563& b)
    {
        m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    }

    void setSub4(const hkVector4D563& a, const hkVector4D563& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }

    void add4(const hkVector4D563& a)
    {
        m_vComponents = _mm_add_ps(m_vComponents, a.m_vComponents);
    }

    void sub4(const hkVector4D563& a)
    {
        m_vComponents = _mm_sub_ps(m_vComponents, a.m_vComponents);
    }

    void mul4(const __m128& s)
    {
        m_vComponents = _mm_mul_ps(m_vComponents, s);
    }

    void setMin4(const hkVector4D563& a, const hkVector4D563& b)
    {
        m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents);
    }

    void setMax4(const hkVector4D563& a, const hkVector4D563& b)
    {
        m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents);
    }
};

struct hkAabbD563
{

    hkVector4D563 m_kMinimumCorner;

    hkVector4D563 m_kMaximumCorner;

    void includeAabb(const hkAabbD563& other)
    {

        m_kMinimumCorner.setMin4(m_kMinimumCorner, other.m_kMinimumCorner);

        m_kMaximumCorner.setMax4(m_kMaximumCorner, other.m_kMaximumCorner);
    }
};

struct hkpD563Tree
{
    void FUN_00d4abf0(void* arg);
};

struct hkpD563Key
{
    unsigned int unk00, unk04, unk08, unk0c;
};

void __cdecl FUN_00d55680(hkpD563Tree* tree, const hkpD563Key* key, hkAabbD563* out);

class hkpD563Shape
{

  public:
    hkpD563Tree* FUN_00d562f0();

    int Vec4(void* arg, int level);

    void FUN_00d563a0(void* arg);

    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;

    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;

    unsigned int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;

    unsigned int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;

    hkpD563Key m_key;

    hkVector4D563 m_kAabbHalfExtents;

    hkVector4D563 m_kAabbCenter;

    unsigned int unkB0, unkB4;

    int m_numLevels;

    unsigned int unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC;

    int m_total;

    float m_fScalar;
};

extern "C"
{
    __m128 _mm_cmple_ps(__m128 a, __m128 b);
    int _mm_movemask_ps(__m128 a);
}

typedef signed char hkInt8;
typedef short hkInt16;
typedef unsigned short hkUint16;

extern const __m128 g_hkQuadZero;
extern const __m128 g_hkQuadAbsMask;

struct hkConvexShapeS
{
    void RetainReference() const;
    void removeReference() const;
};

template <class T> struct hkRefPtrS
{
    T* m_pRetainedObject;

    __forceinline hkRefPtrS() : m_pRetainedObject(0)
    {}
    __forceinline void operator=(T* e)
    {
        if (e)
        {
            e->RetainReference();
        }
        if (m_pRetainedObject)
        {
            m_pRetainedObject->removeReference();
        }
        m_pRetainedObject = e;
    }
};

template <typename T> struct hkArrS
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void init()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
    }

    __forceinline static void construct(T* p, int n)
    {
        for (int i = 0; i < n; i++)
        {
            new (p + i) T;
        }
    }

    __forceinline T* _expandBy(hkMemoryAllocator& alloc, int n)
    {
        int oldsize = m_iElementCount;
        GrowArrayCapacity(alloc, oldsize + n);
        construct(m_data + m_iElementCount, n);
        m_iElementCount += n;
        return m_data + oldsize;
    }

    __forceinline T* expandBy(int n)
    {
        return _expandBy(audio()->heap(), n);
    }
};

struct hkVector4f
{
    hkReal x;
    hkReal y;
    hkReal z;
    hkReal w;
};

struct hkQuaternionS
{
    __m128 m_vec;
    void FUN_00cb26e0(const void* rotation);
};

struct hkBoolS
{
    char m_cBooleanValue;
    hkBoolS(bool b) : m_cBooleanValue(b)
    {}
};

struct hkTransformD566
{
    hkVector4f m_kColumn0;
    hkVector4f m_kColumn1;
    hkVector4f m_kColumn2;
    hkVector4f m_vTranslation;

    hkBoolS FUN_00cd4e00(const hkTransformD566& other, hkReal epsilon) const;
};

extern const hkTransformD566 g_hkTransformIdentity;

struct hkVector4CompS
{
    __m128 m_uiMask;
    __forceinline bool allAreSetXYZ() const
    {
        return (_mm_movemask_ps(m_uiMask) & 7) == 7;
    }
};

struct ShapesSubpartT
{
    hkInt8 m_type;
    hkInt8 m_iMaterialIndexType;
    hkInt16 m_iIndexStriding;
    const void* m_pVertexBase;
    hkUint16 m_iVertexStriding;
    hkUint16 m_iNumTriangles;
    const void* m_pIndexBase;
    unsigned int m_ulUserData;
    hkArrS<hkRefPtrS<hkConvexShapeS> > m_kChildShapes;
    hkQuaternionS m_rotation;
    hkVector4f m_vTranslation;

    __forceinline void initSubpart(hkInt8 type)
    {
        m_type = type;
        m_iMaterialIndexType = 1;
        m_iVertexStriding = 0;
        m_iIndexStriding = 0;
        m_iNumTriangles = 1;
        m_pIndexBase = 0;
        m_pVertexBase = 0;
        m_ulUserData = 0;
    }
    ShapesSubpartT* FUN_00d56660(hkConvexShapeS* const* childShapes, int numChildShapes,
                                 const hkTransformD566& transform);
};

struct hkMemoryAllocator
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* AllocateBufferWithSize(int* reqNumInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct SrcElem
{
    int f0, f4, f8, fc;
    char f10, f11;
    char p12_0, p12_1;
    int f14;
    char f18;
    char p19_0, p19_1, p19_2;
    int f1c, f20;
    unsigned short f24;
    char p26_0, p26_1;
    int f28;
    unsigned short f2c;
    char p2e_0, p2e_1;
    unsigned short f30;
    char p32_0, p32_1;
    int f34;
};

struct Src
{
    int p0_00, p0_04, p0_08, p0_0c, p0_10, p0_14, p0_18, p0_1c;
    __m128 v20;
    int f30;
    SrcElem* arr;
    int count;
    int p3c;
    unsigned short* us;
    int m_usPassCountLocal;
    int p48;
    char f4c;
    char p4d_0, p4d_1, p4d_2;
    float f50;
};

struct WeldingElem
{
    char a0, a1;
    unsigned short a2;
    int a4;
    unsigned short a8, aa;
    int ac;
    int a10;
    int a14, a18, a1c, a20, a24, a28, a2c;
    __m128 a30;
    int a40, a44;
    char a48, a49, a4a, a4b;
    int a4c, a50;
    int a54, a58, a5c;

    WeldingElem()
    {
        a0 = 0;
        a1 = 1;
        a8 = 0;
        a2 = 0;
        aa = 1;
        ac = 0;
        a4 = 0;
        a10 = 0;
        a49 = 0;
        a30 = _mm_setzero_ps();
        a50 = 0;
    }
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_cap;

    hkArray() : m_data(0), m_iElementCount(0), m_cap(0x80000000)
    {}
    int getCapacity() const
    {
        return m_cap & 0x3fffffff;
    }
    __forceinline void reserve(int n)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (getCapacity() < n)
        {
            int cap = 2 * getCapacity();
            FUN_00c908c0(alloc, this, n < cap ? cap : n, sizeof(T));
        }
    }
};

struct Base1
{
    virtual void v1();
    int unk04, unk08, unk0c;
};

struct Base2
{
    virtual void v2();
    int unk14, unk18, unk1c;
};

struct FUN_00d21410 : public Base1, public Base2
{
    FUN_00d21410(int, int) throw();
};

struct FUN_00d56ab0 : public FUN_00d21410
{
    virtual void v1();
    virtual void v2();

    WeldingElem m_sub;
    __m128 m_c80;
    int m_p90_0, m_p90_4, m_p90_8, m_p90_c, m_p90_10, m_p90_14, m_p90_18, m_p90_1c;
    int m_cb0;
    hkArray<WeldingElem> m_aiIndexedValues;
    hkArray<int> m_arr2;
    hkArray<unsigned short> m_w;
    char m_cd8;
    char m_pd9_0, m_pd9_1, m_pd9_2;
    int m_cdc;
    int m_ce0;
    float m_ce4;

    FUN_00d56ab0(Src& input);
    void __thiscall FUN_00d55950();
};

// src/havok/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/physics/internal/collide/gjk/continuous/hkpcontinuousgsk.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <xmmintrin.h>
struct S_00db4b50_B
{
    float unk00;
    int unk04;
    float unk08;
};
struct S_00db4b50_A
{
    char* unk00;
    char* unk04;
    int unk08;
    int unk0c;
    int unk10;
    float unk14;
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
    S_00db4b50_B* unk40;
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
};
struct S_00db4b50_Out
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
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    float unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
};

void FUN_00cf1710(void* a, float b, float c, void* out);
struct S_00db4b50_Sub
{
    void FUN_00cb22f0(void* p, void* q);
    void FUN_00c7f700(void* p, void* q);
    void FUN_00c7f640(void* p, void* q);
    void FUN_004b4ab0(void* p, void* q);
};

namespace fnv_00db52c0 {
union __declspec(intrin_type) __declspec(align(16)) __m128
{
    struct
    {
        float x, y, z, w;
    };
};
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_unpackhi_ps(__m128, __m128);
extern "C" __m128 _mm_movelh_ps(__m128, __m128);
extern "C" __m128 _mm_movehl_ps(__m128, __m128);

union Vec4
{
    __m128 v;
    struct
    {
        float x, y, z, w;
    };
};
struct Transform
{
    Vec4 row0, row1, row2, translation;
    void FUN_00cb22f0(const Transform*, const Transform*);
};
struct Shape
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Vec4 vector20;
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
    Vec4 vectora0;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    Vec4 vector130;
    void FUN_00daad40(void*, void*, Transform*, Vec4*);
};
struct Pair
{
    int unk00, unk04, unk08, unk0c;
    float radius;
};
struct PairArg
{
    Pair* p;
};
struct OutArg
{
    Vec4* p;
};

// @fnv 0x00db52c0
extern Shape* volatile inputObj;
extern const Transform* volatile inputMat;
extern const Transform* volatile inputOther;
extern Pair* volatile inputPair1;
extern Pair* volatile inputPair2;
extern Vec4* volatile inputOut1;
extern Vec4* volatile inputOut2;
}  // namespace fnv_00db52c0

extern const double DAT_010c9300;
void* __cdecl FUN_00c85750();
struct Table
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    void* unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    unsigned int(__thiscall* f2c)(struct Ctrl*);
    void(__thiscall* f30)(struct Ctrl*, unsigned int);
};
struct Ctrl
{
    Table* tab;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    float f10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    float fa0;
};
struct Stat
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    float fa0;
};
struct ObjA
{
    Ctrl* ctrl;
    unsigned int unk04;
    void* p8;
};
struct ObjB
{
    Ctrl* ctrl;
    unsigned int unk04;
    Stat* p8;
};
struct In
{
    ObjA* a;
    ObjB* b;
    unsigned int unk08;
    unsigned char* p0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    __m128 v70;
};
struct Out
{
    void* f0;
    void* f4;
    unsigned int f8;
    unsigned int f0c;
    unsigned int f10;
    float f14;
    float f18;
    float f1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned char* f40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    __m128 f50;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    float f6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    float f7c;
};
// Fills out from in: stores both p8 pointers and the f10 sum, reserves v*16 bytes (rounded to 128) from FUN_00c85750's cursor, and computes f18 and f1c.
// @f3 0x00a42140 (community match, verified in this file)
namespace ns_00a42140 {

struct Float4 {
    float x, y, z, w;
};

struct CtrlVtbl {
    void* unk00; void* unk04; void* unk08; void* unk0c; void* unk10;
    void* unk14; void* unk18; void* unk1c; void* unk20;
    int(__thiscall* GetCount)(Ctrl*);
    void(__thiscall* SetBuffer)(Ctrl*, void*);
};

struct ScratchArena;
struct ScratchArenaVtbl {
    void* unk00; void* unk04; void* unk08; void* unk0c; void* unk10;
    char* (__thiscall* AllocSlow)(ScratchArena*, int);
};

struct ScratchArena {
    ScratchArenaVtbl* vtbl;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* cur;
    unsigned int unk24, unk28;
    char* end;
    char* Alloc(int size) {
        char* p = cur;
        char* next = p + size;
        if (next <= end) { cur = next; return p; }
        return vtbl->AllocSlow(this, size);
    }
};

struct MyIn {
    ObjA* a; ObjB* b; unsigned int unk08; unsigned char* p0c;
    unsigned int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    unsigned int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    unsigned int unk50, unk54, unk58, unk5c;
    Float4 vector60;
    __m128 v70;
};

struct MyOut {
    void* f0; void* f4; unsigned int f8; unsigned int f0c; unsigned int f10;
    float f14; float f18; float f1c;
    unsigned int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    unsigned char* f40;
    unsigned int unk44, unk48, unk4c;
    Float4 f50;
    unsigned int unk60, unk64, unk68; float f6c;
    unsigned int unk70, unk74, unk78; float f7c;
};

} // namespace ns_00a42140

extern int DAT_010f3170;
extern "C" void* (__stdcall* const DAT_00fdf044)(unsigned long);

static __declspec(noinline) void FUN_00db53f0(In* in, Out* out)
{
    ns_00a42140::MyIn* mi = (ns_00a42140::MyIn*)in;
    ns_00a42140::MyOut* mo = (ns_00a42140::MyOut*)out;
    ObjA* a = mi->a;
    ObjB* b = mi->b;
    Ctrl* ctrlA = a->ctrl;
    Ctrl* ctrlB = b->ctrl;
    Stat* statA = (Stat*)a->p8;
    Stat* statB = b->p8;
    mo->f0 = statA;
    mo->f4 = statB;
    mo->f14 = ctrlB->f10 + ctrlA->f10;
    mo->f50.x = mi->vector60.x;
    mo->f50.y = mi->vector60.y;
    mo->f50.z = mi->vector60.z;
    double w = mi->vector60.w;
    mo->f40 = (unsigned char*)mi->unk08 + 0x50;
    mo->f50.w = (float)w;
    int count = ((ns_00a42140::CtrlVtbl*)ctrlA->tab)->GetCount(ctrlA);
    mo->f10 = count;
    mo->f0c = count;
    ns_00a42140::ScratchArena* arena = (ns_00a42140::ScratchArena*)DAT_00fdf044(DAT_010f3170);
    char* p = arena->Alloc((count * 16 + 16) & ~15);
    mo->f8 = (unsigned int)p;
    ((ns_00a42140::CtrlVtbl*)ctrlA->tab)->SetBuffer(ctrlA, p);
    float t1 = statB->fa0 * mo->f7c * mo->f7c;
    float t2 = statA->fa0 * mo->f6c * mo->f6c;
    float t = t1 + t2;
    mo->f18 = t;
    mo->f1c = (float)(1.0 / (t + 1.1920928955078125e-07));
}

namespace ns_00a42140 {
extern In* volatile gIn_00a42140;
extern Out* volatile gOut_00a42140;
void caller_00a42140() { FUN_00db53f0(gIn_00a42140, gOut_00a42140); }
}


extern In* volatile inputIn;
extern Out* volatile inputOut;
void emit_function()
{
    FUN_00db53f0(inputIn, inputOut);
}

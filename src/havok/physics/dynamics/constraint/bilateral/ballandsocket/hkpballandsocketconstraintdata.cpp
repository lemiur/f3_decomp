#include "f3_common.h"
// src/havok/physics/dynamics/constraint/bilateral/ballandsocket/hkpballandsocketconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/ballandsocket/hkpballandsocketconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d541f0_class
{
    void __thiscall FUN_00d541f0(int index);
};

extern void* __cdecl FUN_00d21a60(void* a, int b, int c);
struct hkpBallAndSocketConstraintData
{
    void* FUN_00d54210(int a);
};

extern double DAT_0104e138;
struct FUN_00d54230_class
{
    void __thiscall FUN_00d54230(char a, int* b);
};

struct FUN_00d541d0_class
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
    float unk44;
    void __thiscall FUN_00d541d0(float value);
};

struct FUN_00d54200_class
{
    unsigned char __thiscall FUN_00d54200();
};

struct D54270Bool
{
    char m_cBooleanValue;

    D54270Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct D54270Object
{
    virtual D54270Bool FUN_00d54270() const;
};

// @fnv 0x00d54270
D54270Bool D54270Object::FUN_00d54270() const
{
    return true;
}

struct FUN_00d541e0_class
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
    float unk44;

    float __thiscall FUN_00d541e0();
};

// @fnv 0x00d54280
int __cdecl FUN_00d54280()
{
    return 0;
}

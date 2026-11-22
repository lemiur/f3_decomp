#include "f3_common.h"
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpconstraintdrawer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/constraint/drawer/hkpconstraintdrawer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ResetField
{
    void __thiscall FUN_00e10a00();
};
struct EmbeddedState
{
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
};
struct FUN_00de4470_class
{
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    int unk18;
    float unk1C;
    EmbeddedState state;
    ResetField reset;
    void* __thiscall InitializeDefaults();
};

struct DE44C0Vector4
{
    float x;
    float y;
    float z;
    float w;
};

struct DE44C0Display
{
    void FUN_00e10bf0(const DE44C0Vector4* a, const DE44C0Vector4* b, float radius, unsigned int color, int id,
                      int tag);
};

struct DE44C0Object
{
    int unk00;
    int unk04;
    float m_vScale;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    float m_fSphereRadius;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    DE44C0Vector4 m_vFirstVector;
    DE44C0Vector4 m_vSecondVector;
    DE44C0Vector4 m_dirA;
    DE44C0Vector4 unk70;
    DE44C0Vector4 unk80;
    DE44C0Vector4 m_dirB;
    DE44C0Vector4 unkA0;
    DE44C0Vector4 unkB0;
    DE44C0Display m_display;

    float getScaledRadius() const
    {
        return m_fSphereRadius * m_vScale;
    }
    void FUN_00de44c0(int id, int tag);
};

struct FUN_00de4780_cls
{
    float m_fValue;

    void FUN_00de4780(float afValue);
};

// @fnv 0x00de4780
void FUN_00de4780_cls::FUN_00de4780(float afValue)
{
    m_fValue = afValue;
}

struct FUN_00de4790_Class
{
    int unk00;
    float value04;
    void FUN_00de4790(float value);
};
// @fnv 0x00de4790
void FUN_00de4790_Class::FUN_00de4790(float value)
{
    value04 = value;
}

struct DE47B0Object
{
    int unk00;
    int unk04;
    float m_uiFilterValue;

    void FUN_00de47b0(float value);
};

// @fnv 0x00de47b0
void DE47B0Object::FUN_00de47b0(float value)
{
    m_uiFilterValue = value;
}

struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    float value;
    void FUN_00de47c0(float input);
};

struct FUN_00de47d0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    float m_fValue;
    void FUN_00de47d0(float afValue);
};

// @fnv 0x00de47d0
void FUN_00de47d0_cls::FUN_00de47d0(float afValue)
{
    m_fValue = afValue;
}

struct FUN_00de47a0_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int m_18;

    void FUN_00de47a0(unsigned int value);
};

// @fnv 0x00de47a0
void FUN_00de47a0_cls::FUN_00de47a0(unsigned int value)
{
    m_18 = value;
}

#include <xmmintrin.h>
struct __declspec(align(16)) Vec4
{
    float x;
    float y;
    float z;
    float w;
};

extern float DAT_01016248;

unsigned int PackColorBigEndian(float r, float g, float b, float a);

struct Struct00e10d50
{
    void FUN_00e10d50(const void* origin, const Vec4* from, const Vec4* to, unsigned int color, float width, int arg6,
                      int arg7);
};

struct FUN_00de4530Owner
{
    int unk00;
    int unk04;
    int unk08;
    float unk0c;
    int unk10;
    int unk14;
    int unk18;
    float unk1c;
    Vec4 unk20;
    Vec4 unk30;
    Vec4 unk40;
    Vec4 unk50;
    Vec4 unk60;
    Vec4 unk70;
    Vec4 unk80;
    Vec4 unk90;
    Vec4 unka0;
    Vec4 unkb0;
    Struct00e10d50 unkc0;

    void FUN_00de4530(int arg1, int arg2);
};

class FUN_00de47e0_cls
{
  public:
    void FUN_00de47e0(char* a1, __m128* a2, __m128* a3);
};

// @f3twin 0x00a752a0 of 0x00941ff0
struct F3Twin_00a752a0 : public DE47B0Object { void F3_FUN_00a752a0(float value) ; };
void F3Twin_00a752a0::F3_FUN_00a752a0(float value) 
{
    m_uiFilterValue = value;
}

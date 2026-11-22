#include "f3_common.h"
// src/havok/physics/vehicle/driverinput/default/hkpvehicledefaultanalogdriverinput.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/driverinput/default/hkpvehicledefaultanalogdriverinput.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpVehicleDefaultAnalogDriverInput.h"

struct FUN_00e43540_Arg1
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
    unsigned char unkcc;
};

struct FUN_00e43540_Arg2
{
    int unk00;
    int unk04;
    int unk08;
    float unk0c;
};

class FUN_00e43540_cls : public hkpVehicleDefaultAnalogDriverInput
{
  public:
    float FUN_00e43540(int a0, FUN_00e43540_Arg1* a1, FUN_00e43540_Arg2* a2, int a3);
};

struct VehicleStatus
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    unsigned char unk10;
};

struct VehicleOutput
{
    float x;
    float y;
    float z;
    unsigned char autoReverse;
    unsigned char buttonPressed;
};

struct ButtonResult
{
    unsigned char value;
};

struct VehicleInput
{
    virtual void virtual0();
    virtual void virtual1();
    virtual void virtual2();
    virtual void virtual3();
    virtual float calculateX(float timeStep, void* vehicle, VehicleStatus* status, VehicleOutput* output);
    virtual float calculateY(float timeStep, void* vehicle, VehicleStatus* status, VehicleOutput* output);
    virtual ButtonResult calculateButton(float timeStep, void* vehicle, VehicleStatus* status, VehicleOutput* output);
    virtual float calculateZ(float timeStep, void* vehicle, VehicleStatus* status, VehicleOutput* output);
    void CalculateOutput(float timeStep, void* vehicle, VehicleStatus* status, VehicleOutput* output);
};

// Fills output with the results of calculateX, calculateY, calculateZ and calculateButton, and copies status->unk10 into output->autoReverse.
// @f3 0x007fa880 (community match, verified in this file)
struct PlaybackSource1188
{
    int first;
    int second;
};
struct PlaybackManager1188
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void* GetReader();

    float FUN_007fb000(int, int, bool);
    float FUN_007fb080(float, int, bool);
    float FUN_007fb0d0(float, int, bool);
};

extern PlaybackManager1188* DAT_0108ebbc;
extern const char DAT_00e20140[];
void* __cdecl FUN_007fa220(void*, int, int, int, int, int);
void __cdecl FUN_00887da0(const char*, const char*);

struct NiPlaybackFile
{
    PlaybackSource1188* source;
    void* reader;
    void* buffer;
    int unk0c, unk10;
    float first, second, third;
    int active;

    bool FUN_007fa6c0(const char*, bool, bool, bool);
    bool FUN_007fa880(const char* path, bool quiet, bool option, bool sample);
};

bool NiPlaybackFile::FUN_007fa880(const char* path, bool quiet, bool option, bool sample)
{
    if (!source && !FUN_007fa6c0(path, quiet, option, false))
        return false;

    reader = DAT_0108ebbc->GetReader();
    float value = DAT_0108ebbc->FUN_007fb000(source->first, source->second, sample);
    first = value;
    second = DAT_0108ebbc->FUN_007fb080(value, source->first, sample);
    third = DAT_0108ebbc->FUN_007fb0d0(first, source->second, sample);
    buffer = FUN_007fa220(reader, source->first, source->second, 4, 256, 22);
    if (!buffer)
    {
        if (!quiet)
            FUN_00887da0(DAT_00e20140, path);
        active = 0;
        return false;
    }
    return true;
}


struct hkBoolE436
{
    char m_cBooleanValue;
    void operator=(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

class hkReferencedObjectE436
{
  public:
    hkReferencedObjectE436() : m_sReferenceCount(1)
    {}
    virtual ~hkReferencedObjectE436()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;
};

class hkpVehicleDriverInputE436 : public hkReferencedObjectE436
{
  public:
    hkpVehicleDriverInputE436()
    {}
};

class FUN_00e43680 : public hkpVehicleDriverInputE436
{
  public:
    hkReal m_fSlopeUp;
    hkReal m_fDeadZone;
    hkReal m_fSlopeDown;
    hkBoolE436 m_bAutoReverse;

    FUN_00e43680();
    virtual ~FUN_00e43680();
};

typedef char hkBool;
typedef float hkReal;

// hkpVehicleDriverInputAnalogStatus: m_iGearCount sits at offset 0xcc.
struct hkpVehicleDriverInputAnalogStatus
{
    char pad0[0xcc];
    hkBool m_iGearCount;
};

struct hkpVehicleDriverInputFilteredInput
{
    char pad0[0xc];
    hkReal m_uiFilterValue;
};

// this-call wrapper with the layout of hkpVehicleDefaultAnalogDriverInput
struct AnalogDriverInput
{
    char pad0[0x14];
    hkBool m_bAutoReverse;

    hkReal FUN_00e435a0(hkReal deltaTime, const hkpVehicleDriverInputAnalogStatus* status,
                        const hkpVehicleDriverInputFilteredInput* input, int wheel);
};

class hkMemoryAllocatorE43A
{
  public:
    virtual ~hkMemoryAllocatorE43A() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterE43A
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE43A* m_pStreamAllocator;

    hkMemoryAllocatorE43A& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterE43A {
extern "C" hkMemoryRouterE43A& __cdecl FUN_00c85750() throw();
}

class hkRefObjE43A
{
  public:
    virtual ~hkRefObjE43A();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        hkRefObjE43A* b = static_cast<hkRefObjE43A*>(hkRouterE43A::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
    hkRefObjE43A()
    {
        m_sReferenceCount = 1;
    }
};

class hkCloneE43A : public hkRefObjE43A
{
  public:
    float m_08;
    float m_0C;
    bool m_10;
    bool m_11;

    virtual ~hkCloneE43A();
    hkCloneE43A* FUN_00e43a60() const;
};

#include <math.h>
namespace fnv_00e436b0 {
typedef float hkReal;

struct AnalogStatus
{
    void* vtable;
    int refCount;
    hkReal m_fPositionX;
    hkReal m_fPositionY;
};

class AnalogDriverInput
{
  public:
    void* vtable;
    int refCount;
    hkReal m_fSlopeUp;
    hkReal m_fDeadZone;
    hkReal m_fSlopeDown;
    bool m_bAutoReverse;

    hkReal GetOutput(hkReal deltaTime, const void* vehicle, const AnalogStatus* status, void* out) const;
};

}  // namespace fnv_00e436b0

struct __declspec(intrin_type) __declspec(align(16)) __m128
{
    float f0, f1, f2, f3;
};
extern "C"
{
    __m128 _mm_set_ss(float);
    __m128 _mm_load_ps(const float*);
    void _mm_store_ss(float*, __m128);
    float _mm_cvtss_f32(__m128);
    __m128 _mm_add_ss(__m128, __m128);
    __m128 _mm_sub_ss(__m128, __m128);
    __m128 _mm_mul_ss(__m128, __m128);
    __m128 _mm_sqrt_ss(__m128);
    __m128 _mm_rsqrt_ss(__m128);
    __m128 _mm_cmpeq_ss(__m128, __m128);
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_andnot_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, int);
}

extern const float DAT_01011d78 = 0.0f;
extern const float DAT_01016248 = 0.5f;
extern const float DAT_01017718 = 3.0f;
extern const float DAT_0104da4c = 1.1920928955078125e-07f;
extern const float DAT_010ebf10 = 1.38888896f;
extern const double DAT_0101ffa0 = 0.10000000149011612;

namespace e43780 {
struct HkVec
{
    float x, y, z, w;
    __forceinline const __m128& quad() const
    {
        return *(const __m128*)&x;
    }
};

struct Pad40
{
    int u00, u04, u08, u0c;
    int u10, u14, u18, u1c;
    int u20, u24, u28, u2c;
    int u30, u34, u38, u3c;
};

struct VehInst
{
    Pad40 p00, p40, p80;
    int uc0, uc4, uc8, ucc;
    int ud0, ud4, ud8, udc;
    int ue0, ue4, ue8, uec;
    HkVec m_kColumn0;
    HkVec m_kColumn1;
    HkVec m_kColumn2;
    Pad40 p120, p160;
    int u1a0, u1a4, u1a8, u1ac;
    HkVec m_pos;
};

struct ChassisX
{
    Pad40 p00;
    HkVec m_pos;
};

struct StatusX
{
    int u00, u04, u08, u0c, u10, u14;
    VehInst* m_veh;
    ChassisX* m_pChassisCollidable;
    Pad40 p20, p60;
    int ua0, ua4, ua8, uac;
    int ub0, ub4, ub8, ubc;
    int uc0, uc4, uc8;
    hkBool m_iGearCount;
};

struct InputX
{
    int u00, u04, u08;
    hkReal m_uiFilterValue;
    char u10;
    ButtonResult m_flag;
};

class Cls : public hkpVehicleDefaultAnalogDriverInput
{
  public:
    ButtonResult FUN_00e43780(int a1, StatusX* status, InputX* input, int a4);
};

}

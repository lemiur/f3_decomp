// fallout_shared/tesimagespacemodifier.cpp: TESImageSpaceModifier, RgbaColor, ImageSpaceModifierEffectData, NiColorInterpolator and more (11 functions)
#include "f3_common.h"
#include "tesimagespacemodifier_decls.h"

// @fnv 0x0052bd40
void TESImageSpaceModifier::ResetFormData()
{
    int i, j, kKey;
    memset(&Data, 0, sizeof(Data));
    Data.m_bOverride = false;
    Data.fDuration = 1.0f;
    Data.m_bUseRadialBlur = false;
    Data.m_kRadialBlurCenter = NiPoint2(0.5f, 0.5f);
    Data.m_bUseEffectEntries = false;
    Data.m_ucEffectMode = 0;
    for (i = 0; i < 21; ++i)
        for (j = 0; j < 2; ++j)
        {
            Data.m_auiKeyframeCountsByTypeAndChannel[i][j] = 2;
            pEffectEntryTable[i][j] = new TimedFloatKey[2];
            for (kKey = 0; kKey < 2; ++kKey)
            {
                pEffectEntryTable[i][j][kKey].FUN_0052ce20(DAT_0118aba0[kKey]);
                pEffectEntryTable[i][j][kKey].FUN_004f5d90(DAT_0118aba8[j]);
            }
            m_akFloatInterpolators[i][j].SetAnimationKeys(
                pEffectEntryTable[i][j], Data.m_auiKeyframeCountsByTypeAndChannel[i][j], AnimationKey::LINKEY);
        }
    Data.m_uiEffectEntryCountFirst = 2;
    pFirstEffectRecordArray = new AlphaColor[2];
    for (i = 0; i < 2; ++i)
    {
        pFirstEffectRecordArray[i].FUN_0052ce20(DAT_0118aba0[i]);
        pFirstEffectRecordArray[i].FUN_0052cfc0(RgbaColor(1.0f, 1.0f, 1.0f, 0.0f));
    }
    m_kColorInterpolatorOne.SetAnimationKeys(pFirstEffectRecordArray, Data.m_uiEffectEntryCountFirst,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountTwelfth = 2;
    pSecondEffectRecordArray = new AlphaColor[2];
    for (i = 0; i < 2; ++i)
    {
        pSecondEffectRecordArray[i].FUN_0052ce20(DAT_0118aba0[i]);
        pSecondEffectRecordArray[i].FUN_0052cfc0(RgbaColor(1.0f, 1.0f, 1.0f, 0.0f));
    }
    m_kColorInterpolatorTwo.SetAnimationKeys(pSecondEffectRecordArray, Data.m_uiEffectEntryCountTwelfth,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountSecond = 2;
    pSecondEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pSecondEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pSecondEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorOne.SetAnimationKeys(pSecondEffectEntries, Data.m_uiEffectEntryCountSecond,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountThird = 2;
    pThirdEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pThirdEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pThirdEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorTwo.SetAnimationKeys(pThirdEffectEntries, Data.m_uiEffectEntryCountThird, AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountFourth = 2;
    pTenthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pTenthEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pTenthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorNine.SetAnimationKeys(pTenthEffectEntries, Data.m_uiEffectEntryCountFourth,
                                              AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountFifth = 2;
    pEleventhEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pEleventhEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pEleventhEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorTen.SetAnimationKeys(pEleventhEffectEntries, Data.m_uiEffectEntryCountFifth,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountSixth = 2;
    pTwelfthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pTwelfthEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pTwelfthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorEleven.SetAnimationKeys(pTwelfthEffectEntries, Data.m_uiEffectEntryCountSixth,
                                                AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountTenth = 2;
    pFourthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pFourthEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pFourthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorThree.SetAnimationKeys(pFourthEffectEntries, Data.m_uiEffectEntryCountTenth,
                                               AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountEleventh = 2;
    pFifthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pFifthEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pFifthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorFour.SetAnimationKeys(pFifthEffectEntries, Data.m_uiEffectEntryCountEleventh,
                                              AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountSeventh = 2;
    pSeventhEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pSeventhEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pSeventhEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorFive.SetAnimationKeys(pSeventhEffectEntries, Data.m_uiEffectEntryCountSeventh,
                                              AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountEighth = 2;
    pEighthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pEighthEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pEighthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorSix.SetAnimationKeys(pEighthEffectEntries, Data.m_uiEffectEntryCountEighth,
                                             AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountNinth = 2;
    pNinthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pNinthEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pNinthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorSeven.SetAnimationKeys(pNinthEffectEntries, Data.m_uiEffectEntryCountNinth,
                                               AnimationKey::LINKEY);
    Data.m_uiEffectEntryCountThirteenth = 2;
    pSixthEffectEntries = new TimedFloatKey[2];
    for (i = 0; i < 2; ++i)
    {
        pSixthEffectEntries[i].FUN_0052ce20(DAT_0118aba0[i]);
        pSixthEffectEntries[i].FUN_004f5d90(0.0f);
    }
    m_kFloatInterpolatorEight.SetAnimationKeys(pSixthEffectEntries, Data.m_uiEffectEntryCountThirteenth,
                                               AnimationKey::LINKEY);
    pIntroSound = 0;
    pOutroSound = 0;
}

// Sets the form type to IMAD, calls the initializer, and if this is the global instance DAT_011c9750 calls the second initializer.
// @fnv 0x0052b8f0
TESImageSpaceModifier::TESImageSpaceModifier()
{
    SetFormType(ENUM_FORM_ID_IMAD_ID);
    ResetFormData();
    if (this == &DAT_011c9750)
        NotifySaveLoadGameOfFormChange();
}
// @fnv 0x0052d260
// @f3 0x004a3bb0 (community match, verified in this file)
inline bool TESForm::IsFormInitialized() const { return (m_uiFormFlags >> 3) & 1; }
inline unsigned int TESForm::GetFormID() { return iFormID; }

class ISMStandIn : public TESForm
{
  public:
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
    TESSound* pIntroSound;
    TESSound* pOutroSound;
};
FNV_STATIC_ASSERT(offsetof(ISMStandIn, pIntroSound) == 0xa8);
FNV_STATIC_ASSERT(offsetof(ISMStandIn, pOutroSound) == 0xac);

extern char DAT_00f49948, DAT_00f460fc, DAT_00f46078;
void* __cdecl FUN_00c0050a(void*, int, const void*, const void*, int);

void TESImageSpaceModifier::InitItem()
{
    if (IsFormInitialized())
        return;
    ResetFormData();
    ISMStandIn* pThis = (ISMStandIn*)this;
    unsigned int formID = (unsigned int)pThis->pIntroSound;
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        pThis->pIntroSound = static_cast<TESSound*>(FUN_00c0050a(TESForm::GetFormByID(formID), 0, &DAT_00f46078, &DAT_00f49948, 0));
        if (!pThis->pIntroSound)
            Warning("MASTERFILE: Could not find item list (%08X) on constructible object '%s' (%08X).", formID,
                    GetName(), GetFormID());
    }
    formID = (unsigned int)pThis->pOutroSound;
    if (formID)
    {
        RemapFormIDForFile(formID, GetFile(-1));
        pThis->pOutroSound = static_cast<TESSound*>(FUN_00c0050a(TESForm::GetFormByID(formID), 0, &DAT_00f46078, &DAT_00f460fc, 0));
        if (!pThis->pOutroSound)
            Warning("MASTERFILE: Could not find created item (%08X) on constructible object '%s' (%08X).", formID,
                    GetName(), GetFormID());
    }
    SetInitializationState(true);
}

// @fnv 0x005316c0

// Multiplies the r, g, b and a components by scale and returns a reference to this object.
// @fnv 0x005321d0
// @fnv 0x0052bad0
TESImageSpaceModifier::ImageSpaceModifierEffectData::ImageSpaceModifierEffectData()
{}
// @fnv 0x0052d3b0
// @fnv 0x00532fd0
NiPoint2 operator*(float scale, const NiPoint2& arPoint)
{
    return arPoint * scale;
}

struct NiStream;
struct blob12
{
    char b[12];
};
struct blob48
{
    char b[48];
};
struct blob64
{
    char b[64];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct ThreeByThreeMatrix
{
    void GetRow(unsigned int, float*);
    void GetRow(unsigned int, float*, float*, float*);
    void GetRow(unsigned int, NiPoint3*);
    void SetRow(unsigned int, float*);
    void SetRow(unsigned int, float, float, float);
    void SetRow(unsigned int, void*);
    void GetCol(unsigned int, float*);
    void GetCol(unsigned int, float*, float*, float*);
    void GetCol(unsigned int, NiPoint3*);
    void SetCol(unsigned int, float*);
    void SetCol(unsigned int, float, float, float);
    void SetCol(unsigned int, void*);
    float GetEntry(unsigned int, unsigned int);
    void SetEntry(unsigned int, unsigned int, float);
    void MakeZero();
    void ResetToIdentity();
    void MakeDiagonal(float, float, float);
    void SetXRotation(float);
    void SetYRotation(float);
    void SetZRotation(float);
    void MakeZRotationQ(float);
    void MakeAxisAngleRotation(float, void*);
    void MakeAxisAngleRotation(float, float, float, float);
    bool Inverse(ThreeByThreeMatrix*);
    struct blob48 Inverse();
    struct blob48 Transpose();
    void ToQuaternion(float*, float*, float*, float*);
    bool ExtractEulerAnglesXYZ(float*, float*, float*);
    bool ToEulerAnglesXZY(float*, float*, float*);
    bool ToEulerAnglesYXZ(float*, float*, float*);
    bool ToEulerAnglesYZX(float*, float*, float*);
    bool ToEulerAnglesZXY(float*, float*, float*);
    bool ToEulerAnglesZYX(float*, float*, float*);
    void SetRotationFromEulerXYZ(float, float, float);
    void FromEulerAnglesXZY(float, float, float);
    void FromEulerAnglesYXZ(float, float, float);
    void FromEulerAnglesYZX(float, float, float);
    void SetRotationFromEulerZXY(float, float, float);
    void SetRotationFromEulerZYX(float, float, float);
    bool Reorthogonalize();
    struct blob48 ComposeMatrices(void*);
    struct blob48 Congruence(void*);
    static void TransformPositions(void*, void*, unsigned int, void*, NiPoint3*);
    static void TransformNormals(void*, unsigned int, void*, NiPoint3*);
    static void TransformVerticesAndNormals(void*, void*, unsigned int, void*, NiPoint3*, void*, NiPoint3*);
    void ApplyToVector(float*, NiPoint3*);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    void Scale(float, float, float);
    static struct blob64 XMLoadFloat3x4(float*);
    static void XMStoreFloat3x4(float*, struct blob64);
    bool Tridiagonal(float*, float*);
    bool QLAlgorithm(float*, float*);
    float Determinant();
    char m_afEntries[48];
};
typedef char _sizecheck_NiMatrix3[sizeof(ThreeByThreeMatrix) == 48 ? 1 : -1];

struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];

struct Obj52 : NiMemObject
{
    void FUN_00a3cc80();
    void* FUN_0052cf90(unsigned int);
    static void operator delete(void*, unsigned int);
};

namespace fnv_0052d130 {
struct Obj52 : NiMemObject
{
    void FUN_00a3cc80();
    void* FUN_0052d130(unsigned int);
    static void operator delete(void*, unsigned int);
};
}  // namespace fnv_0052d130

struct GlobalObjectO2_00a7b610;
extern GlobalObjectO2_00a7b610 g_011f3748;

struct FUN_0052cf80_shell
{
    GlobalObjectO2_00a7b610* GetGlobalObject();
};

namespace fnv_0052d120 {
struct NiRTTI;

extern NiRTTI g_011f3750;

struct NiColorData
{
    NiRTTI* __thiscall GetRTTI() const;
};

}  // namespace fnv_0052d120

struct GlobalObject_0052b8f0
{
    ~GlobalObject_0052b8f0();
    void* __thiscall Destroy(unsigned int flags);
};

extern void* __cdecl _Deallocate(void*);

struct FUN_00533060_shell
{
    void* __thiscall FUN_00533060(void** a, void** b, char* c);
};

namespace fnv_00533000 {
struct Flt
{
    operator unsigned int();
};
struct FUN_00533060_shell
{
    void* FUN_00533060(void**, void**, char*);
};
struct FUN_00533000_shell
{
    char _pad[16];
    Flt m_kHandle;
    void* FUN_00533000(void**, void**, char*);
};
}  // namespace fnv_00533000

struct Base5a
{
    virtual ~Base5a();
};
struct FUN_0052bb70
{
    virtual ~FUN_0052bb70();
    char pad[0x20];
};

struct FUN_0052bbd0 : Base5a
{
    char pad[0x110];
    NiFloatInterpolator m_akFloatInterpolators[21][2];
    NiFloatInterpolator m_kFloatInterpolatorOne, m_kFloatInterpolatorTwo;
    FUN_0052bb70 m_kColorInterpolatorOne, m_kColorInterpolatorTwo;
    NiFloatInterpolator m_kFloatInterpolatorNine, m_kFloatInterpolatorTen, m_kFloatInterpolatorEleven,
        m_kFloatInterpolatorThree, m_kFloatInterpolatorFour;
    NiFloatInterpolator m_kFloatInterpolatorFive, m_kFloatInterpolatorSix, m_kFloatInterpolatorSeven,
        m_kFloatInterpolatorEight;
    ~FUN_0052bbd0();
};

struct FUN_00532e40_s
{
    float x;
    float y;
    float z;
    float w;
    FUN_00532e40_s* AddDelta(FUN_00532e40_s* result, float* delta);
};

struct FUN_00532ec0_v4
{
    float x;
    float y;
    float z;
    float w;
};
struct FUN_00532ec0
{
    FUN_00532ec0_v4* SUB(FUN_00532ec0_v4* result, const FUN_00532ec0_v4& sub);
};

struct FUN_0052ed90_shell
{
    void CacheObjectValues();
};

struct FUN_005e79a0_t
{
    bool FUN_00485270(TESForm* form);
};

struct FUN_005310b0_shell
{
    bool FUN_005310b0(TESForm* form);
};

int __cdecl _memcmp(const void* left, const void* right, unsigned int count);
void* __cdecl FUN_00ec43fb(void* object, unsigned int type, void* data, const void* typeInfo, unsigned char option);
extern char _DAT_01183028;

struct FUN_00531490_shell
{
    void SwapEndian();
};

struct FUN_0045cec0
{
    ~FUN_0045cec0();
};

struct FUN_00a3ca30
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;

    ~FUN_00a3ca30();
};

struct FUN_0052bb10 : public FUN_00a3ca30
{
    FUN_0045cec0 unk10;

    ~FUN_0052bb10();
};

FUN_0045cec0::~FUN_0045cec0()
{}

FUN_00a3ca30::~FUN_00a3ca30()
{}

namespace Real {
struct InterpolatorBase
{
    unsigned int referenceCount;
    unsigned int flags;
    float lastTime;
    float currentTime;
    float startTime;
    float endTime;
    void* controller;
    ~InterpolatorBase();
};
struct ColorDataReference
{
    void* colorData;
    ~ColorDataReference();
};
struct FUN_0052bb70 : InterpolatorBase
{
    ColorDataReference colorData;
    ~FUN_0052bb70();
};
// Destructor for an interpolator that owns a ColorDataReference; the body is empty.
// @fnv 0x0052bb70
FUN_0052bb70::~FUN_0052bb70()
{}
}

struct SpawnedObject
{
    void Method(float* pOut, float f);
};

// @fnv 0x00532f40
float* __cdecl FUN_00532f40(float* pOut, float f, SpawnedObject* pObj)
{
    pObj->Method(pOut, f);
    return pOut;
}

struct FUN_00532f60_vec4
{
    float x;
    float y;
    float z;
    float w;
};

class FUN_00532f60_cls
{
  public:
    float m_uiX;
    float m_uiY;
    float m_uiZ;
    float m_w;
    FUN_00532f60_vec4* ScaleVector4(FUN_00532f60_vec4* out, float scale);
};

struct xA
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual int GetA(int i);
    virtual void v0e4();
    virtual void v0e8();
    virtual int GetB(int i);
    int m_kNextStreamField[5];
};

struct xB : xA
{
    int m_aiExtra[3];
};

struct xSkyX
{
    char _pad000[0x28];
    int m_aiA[21][2];
    int m_i0d0;
    int m_i0d4;
    int m_i0d8;
    int m_i0dc;
    int m_i0e0;
    int m_i0e4;
    char _pad0e8[0xc];
    int m_i0f4;
    int m_i0f8;
    int m_i0fc;
    char _pad100[0x4];
    int m_i104;
    int m_i108;
    int m_i10c;
    int m_i110;
    xA m_akObj[21][2];
    xA m_k504;
    xA m_k51c;
    xB m_k534;
    xB m_k558;
    xA m_k57c;
    xA m_k594;
    xA m_k5ac;
    xA m_k5c4;
    xA m_k5dc;
    xA m_k5f4;
    xA m_k60c;
    xA m_k624;
    xA m_k63c;
    int m_aiB[21][2];
    int m_i6fc;
    int m_i700;
    int m_i704;
    int m_i708;
    int m_i70c;
    int m_i710;
    int m_i714;
    int m_i718;
    int m_i71c;
    int m_i720;
    int m_i724;
    int m_i728;
    int m_i72c;
    void CacheObjectValues();
};

struct FUN_004855a0_shell
{
    void FUN_004855a0();
};
struct FUN_00485680_shell
{
    void FUN_00485680();
};
bool FUN_00401500();
void AppendChunk(unsigned int, void*, unsigned int);
void FUN_00485910(unsigned int, unsigned int);
void* __memcpy(void*, const void*, unsigned int);
struct FUN_0052f250_shell : TESImageSpaceModifier
{
    void WriteToStream();
};

extern char _DAT_011862b8;
extern "C" void* __cdecl FUN_00401460(void*, const void*, unsigned int);
extern "C" void __fastcall CacheObjectValues(TESImageSpaceModifier*);
struct PassPtr
{
    TESImageSpaceModifier* value;
};
extern "C" void __fastcall FUN_004851b0(TESImageSpaceModifier*, PassPtr);
struct CopyBaseShell
{
    void FUN_004851b0(TESImageSpaceModifier*);
};
struct TESImageSpaceModifierCopy : TESImageSpaceModifier
{
    void FUN_00530160(TESForm*);
};

struct BlendColor
{
    float r, g, b, a;
    BlendColor(float, float, float, float);
    BlendColor FUN_00532ec0(const BlendColor&) const;
    BlendColor AddDelta(const BlendColor&) const;
};
BlendColor FUN_00532f40(float, const BlendColor&);
struct BlendPoint
{
    float x, y;
    BlendPoint();
    BlendPoint(float, float);
    BlendPoint Subtract(const BlendPoint&) const;
    BlendPoint FUN_004dfe30(const BlendPoint&) const;
};
BlendPoint FUN_00532fd0(float, const BlendPoint&);
struct BlendImageManager : ImageSpaceManager
{
    void FUN_00b8b1c0(const NiBound&, BlendPoint&);
    void FUN_00b8bb70(const NiBound&, BlendPoint&);
};
TESImageSpaceModifier* FUN_00532ff0();

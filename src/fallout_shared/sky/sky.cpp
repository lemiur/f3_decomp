// fallout_shared/sky/sky.cpp: Sky, ThisCls, TESObjectCELL, Host and more (2 functions)
#include "f3_common.h"
#include "sky_packet.h"
namespace fnv_00454b10 {
class TESObjectCELL
{
  public:
    unsigned char pad[0x24];
    unsigned char flags;
    unsigned char GetFakeExterior();
};

}  // namespace fnv_00454b10

// @fnv 0x00639d40
Sky::Sky() : m_pRootNode(0), m_pSkyNode(0), m_kSunlightColor(0.0f, 0.0f, 0.0f), m_kSkyColor(0.0f, 0.0f, 0.0f)
{
    m_pAtmosphere = 0;
    m_pStars = 0;
    m_pClouds = 0;
    m_pSun = 0;
    m_pPrimaryMoon = 0;
    m_pSecondaryMoon = 0;
    m_pPrecipitation = 0;
    m_pRootNode = 0;
    m_pSkyNode = 0;
    m_fFogFarDistance = 10.0f;
    eMode = 4;
    m_pCurrentClimate = 0;
    m_pOverrideWeather = 0;
    m_pQueuedWeather = 0;
    m_pPreviousWeather = 0;
    m_pRegionWeather = 0;
    fWeatherChance = 0.0f;
    field11c = 0;
    field124 = 0;
    field120 = 0;
    field128 = 0;
    for (int i = 0; i < 10; i++)
        m_kSkyColors[i] = DAT_011a9b7c;
    *(NiColor*)&m_kSkyColor = DAT_011a9b7c;
    m_fCurrentWeatherBlend = 0.0f;
    m_fTargetWeatherBlend = 1.0f;
    m_fWeatherBlend = 1.0f;
    field110 = 0.0f;
    m_pSkySounds = new BSSimpleList<SkySound*>;
    m_fWeatherFade = 0.0f;
    field108 = 0;
    field10c = originalRuntimeFloatSetting76.Float()->f;
    flags = 0;
    FUN_0063a030(true);
    field12c = 12.0f;
    field130 = 23.99f;
    field134 = 0.0f;
}

struct FUN_0063a030_shell : public Sky
{
    void FUN_0063a030(bool);
};

struct FUN_0063a610_shell : public Clouds
{
    void FUN_0063a610();
};

struct FUN_0063b600_shell : public Clouds
{
    void FUN_0063b600(int, NiColor*);
};

struct FUN_0063b9b0_shell : public Sky
{
    float FUN_0063b9b0();
};

float __cdecl FUN_00404010(float, float);
float __fastcall FUN_00595ea0(void*);
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting78;
extern float DAT_011cccfc;

struct FUN_0063ba30_shell : public Sky
{
    float FUN_0063ba30();
};

float __cdecl FUN_0040ebd0(float, float);
float __fastcall FUN_00596030(void*);
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting78;
extern float DAT_011ccd00;

struct FUN_0063bb40_stand
{
    char pad[0x108];
    int tbl[4][6];
    int FUN_0063bb40(int a, int b);
};
// Returns the int stored at tbl[a][b].
// @f3 0x00a49650 (community match, verified in this file)
namespace EntryStorageA49650 {
struct Entry {
    int value;
    int metadata;
};

struct Storage {
    Entry* entries;
    int FUN_00a2a180();
};
}

int FUN_0063bb40_stand::FUN_0063bb40(int valueAddress, int metadata)
{
    EntryStorageA49650::Storage* storage = reinterpret_cast<EntryStorageA49650::Storage*>(this);
    int index = storage->FUN_00a2a180();
    EntryStorageA49650::Entry& entry = storage->entries[index];
    entry.value = *reinterpret_cast<const int*>(valueAddress);
    entry.metadata = metadata;
    return index;
}


struct NiStream;
struct blob8
{
    char b[8];
};
struct NiPoint2
{
    static struct blob8 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float Dot(void*);
    float Unitize();
    static void LoadBinary(NiStream*, NiPoint2*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint2*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float x;
    float y;
};
typedef char _sizecheck_NiPoint2[sizeof(NiPoint2) == 8 ? 1 : -1];
struct FUN_0063c490_shell : public Sky
{
    void FUN_0063c490();
};

float __cdecl FUN_00452e70(bool);
float __cdecl FUN_0057e960(float);
float __cdecl FUN_0063c600(float);
void __cdecl FUN_0063c640(int, int);
void __cdecl FUN_0063c660(float);
void __cdecl FUN_0063c670(NiPoint2);
void __fastcall _ref_006815c0(NiPoint2*);

extern double _DAT_01012640;
extern double _DAT_0104eea0;
extern double DAT_0104ee98;
extern int DAT_011a9b50;
extern int DAT_011a9b54;

struct TESWeatherEx : public TESWeather
{
    float GetWeatherData(int, float, float);
};

extern float runtimeInitializationFloat2719;
extern float DAT_011f52e0[512];

struct FUN_0063c8a0_shell : public NiPoint3
{
    NiPoint3* FUN_0063c8a0(void*);
};

struct NiPoint3Fields
{
    float x;
    float y;
    float z;
};

struct FUN_0063c9f0_shell : public Sky
{
    void FUN_0063c9f0();
};

struct FUN_0063d000_shell : public TESClimate
{
    bool FUN_0063d000();
};

struct FUN_0063d020_shell : public TESClimate
{
    bool FUN_0063d020();
};

struct FUN_0063d060_shell : public Sky
{
    void FUN_0063d060();
};

struct Sky_Helper : public Sky
{
    void FUN_0063e860(int);
};

void __fastcall FUN_005827d0(char*);

struct FUN_0063dd50_shell
{
    unsigned char pad[0xe0];
    unsigned char data[4];
    unsigned char FUN_0063dd50(int index);
};

namespace fnv_0063e010 {
class SoundPlaybackHandle
{
  public:
    void Stop(void);
};

SoundPlaybackHandle* const& __fastcall _ref_006815c0(void* pNode);
void* __fastcall _ref_00726070(void* pNode);

}  // namespace fnv_0063e010

struct FUN_0063e210_shell : public Sky
{
    void FUN_0063e210();
};

void __fastcall FUN_006349e0(void*);
void __fastcall FUN_006369a0(void*);
void __fastcall FUN_00642940(void*);
void __fastcall FUN_0063e290(void*);

namespace fnv_0063e290 {
template <class T> class BSStringT
{
  public:
    operator const char*() const;
};

class NiNode
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void InsertChild(const char*);
};

}  // namespace fnv_0063e290

struct FUN_0063e860_stand
{
    char pad0[0x14];
    int f14;
    char pad1[0xf4 - 0x18];
    float fF4;
    char pad2[0x110 - 0xf8];
    float f110;
    int pad3;
    unsigned int flags;
    void FUN_0063e860(bool on);
};

namespace fnv_0063bab0 {
struct FUN_0063bab0_shell : public Sky
{
    void FUN_0063bab0(void*, TESWeather*, TESWeather*, int, int*, int*);
};

struct FUN_0063bb40_stand
{
    int FUN_0063bb40(int, int);
};
}  // namespace fnv_0063bab0

struct FUN_0063c420_shell
{
    unsigned char pad[0xf0];
    float arr[0x100];
    float __thiscall FUN_0063c420(int index);
};

struct Flt
{
    operator unsigned int(void) const;
};

struct FUN_0063c440_shell
{
    unsigned char pad[8];
    Flt m_flt;
    int FUN_0063c440(int index);
};

extern unsigned char DAT_0119f188;

extern int DAT_011c7a3c;

extern "C"
{
    extern float DAT_011c7a5c;
}

extern int DAT_011f95dc;
extern int DAT_011f95e0;

extern float DAT_011ad824;

extern "C" float DAT_011fd884;
extern "C" float DAT_011fd888;

struct FUN_0063dd90_shell
{
    unsigned char pad[0x18];
    unsigned int m_flags;
    void FUN_0063dd90();
};

struct FUN_0063dff0_shell
{
    void* FUN_0063dff0();
};

struct FUN_0063e8f0_shell
{
    unsigned char pad[0x118];
    unsigned int flags;
    void FUN_0063e8f0(bool set);
};

namespace fnv_0063b120 {
struct FUN_0063b120_shell : public Sky
{
    void FUN_0063b120();
};

extern const float runtimeFloatSettingDefault40;
extern const float g_011cc6cc_arg1;
extern const float g_011c7200_arg1;
extern const float runtimeFloatSettingDefault538;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting75;
extern SettingT_GameSettingCollection_ g_011ccccc;
extern NiColor DAT_011f4998;

struct FUN_00544890_shell
{
    void FUN_00544890(NiColor*);
    void FUN_005447b0(NiColor*);
    void FUN_00544a30(NiColor*);
};
struct CP_008c48d0
{
    FUN_00544890_shell* GetPrevPath();
};
extern CP_008c48d0* g_TES;

struct FUN_0063b600_shell
{
    void FUN_0063b600(int, void*);
};
struct FUN_00634830_shell
{
    int GetOffset58();
};

struct FUN_0063b630_shell
{
    void FUN_0063b630(void* cb, void* weather, float f, int* t1, int* t2);
    void FUN_0063bab0(void* cb, void* w1, void* w2, int i, int* t1, int* t2);
    void QueryTwoSources(void* cb, void* w1, void* w2, int i, int* t1, int* t2);
    void FUN_0063c690(void* out, void* cb, float flash);
};

struct Sky_COLOR_BLEND
{
    int data[8];
};

}  // namespace fnv_0063b120

unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);
unsigned int __cdecl gm_GetTickCount(void);
struct Host
{
    unsigned int FUN_00639ce0();
    void FUN_00639d00(unsigned int);
    bool FUN_00639c90(unsigned int);
};

void __cdecl _Deallocate(void*);
struct Cls_0063a080
{
    void FUN_0063a0b0();
    void* FUN_0063a080(unsigned int);
};

namespace fnv_0063d0e0 {
extern "C" void* __cdecl _alloca(unsigned int);
struct Sky_Helper
{
    void FUN_0063e860(int);
};
struct PC7d
{
    void FUN_0093a7a0(int);
};
extern PC7d* g_thePlayer;
struct FUN_0063d0e0_shell : public Sky
{
    void FUN_0063d0e0(TESWeather* w, bool b);
};
}  // namespace fnv_0063d0e0

struct FUN_0063dd70_shell
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    bool FUN_0063dd70();
};

struct S63cfa0
{
    char _pad[0x38];
    char _items[2][12];
    void* FUN_0063cfa0(int);
};

namespace fnv_0063ac70 {
struct FUN_0063ac70_shell : public Sky
{
    void FUN_0063ac70(float);
};

struct AutoMemHelper
{
    int m_eMemoryContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
struct BSOcclusionPlane
{
    int GetCullResult() const;
};
struct MobileObject
{
    float GetRelevantWaterHeight() const;
};
struct PC7d : public BSOcclusionPlane
{
};
struct Calendar
{
    float GetGameTime();
    unsigned int GetGameDaysPassed();
};
struct AnimIdle
{
    int GetSection();
};
struct NiNode_00558310;
class NiAVObject;
NiNode_00558310* __cdecl FUN_0045c670();
NiAVObject* __fastcall FUN_00558310(NiNode_00558310*);
const NiPoint3& __fastcall FUN_0045bb80(NiAVObject*);
bool __cdecl FUN_006368f0(const Sky*);
struct BGSSaveLoadGame_FUN_0042ce10
{
    bool FUN_0042ce10();
};
struct Precipitation_FUN_00636ed0
{
    void FUN_00636ed0(float);
};
struct FUN_0063ca20_t
{
    void FUN_0063ca20();
};
struct FUN_0063d1d0_t
{
    void FUN_0063d1d0();
};
struct FUN_0063c490_shell
{
    void FUN_0063c490();
};
struct FUN_0063d5e0_t
{
    void FUN_0063d5e0();
};
extern PC7d* g_thePlayer;
extern Calendar g_calendar;
extern AnimIdle g_timeGlobal;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting74;

}  // namespace fnv_0063ac70

namespace fnv_0063d5e0 {
struct SkySound
{
    bool HandleCheckTime(int);
    bool IsFlaggedToBeKilled();
    unsigned int GetNextCheck();
    void FlagToKill();
    void SetNextCheck(unsigned int);
    void Play(float);
    void* __vecDelDtor(unsigned int);
    char IdentifierState[12];
    void* m_pWeatherObject;
    int m_iSoundType;
    unsigned int auiFormId;
    unsigned int uiData;
};
typedef char _sizecheck_SkySound[sizeof(SkySound) == 28 ? 1 : -1];
struct FUN_0063d5e0_shell : public Sky
{
    void FUN_0063d5e0();
};

struct SndX
{
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned int uiState;
    bool IsValid();
    bool IsPlaying();
    void Stop();
    void PausePlayback();
};
struct TESWeatherEx
{
    float GetWeatherData(int, float, float);
    unsigned char GetWeatherDataRaw(int);
};
struct SkySoundObj
{
    SndX hSound;
    TESWeatherEx* m_pWeatherObject;
    unsigned int eType;
    unsigned int iSoundFormID;
    ~SkySoundObj();
    bool FUN_0063dd70();
    bool FUN_00639c90(int);
    void FUN_0063dd90();
    void FUN_0063e0d0(float);
};
struct SL
{
    SkySoundObj* m_item;
    SL* m_pkNext;
    SL();
    ~SL();
    SkySoundObj** FUN_006815c0();
    SL* FUN_00726070();
    void AddHead(SkySoundObj**);
    void RemoveAll();
};
struct SkyEx
{
    bool FUN_00634870();
    void FUN_0063ddb0(TESWeather*);
    bool FUN_0063e060(unsigned int, TESWeather*);
};
struct AnimIdle
{
    int GetSection();
};
extern AnimIdle g_timeGlobal;
extern unsigned char DAT_011ccb74;
extern bool DAT_011ccd04;
unsigned int DialogueRandom();

}  // namespace fnv_0063d5e0

struct TESSaveLoadGame
{
    unsigned char FUN_008df040();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_0063e940_shell
{
    unsigned short FUN_0063e940();
};

struct FUN_0063bc60_shell
{
    int FUN_0063bc60(int b, int a);
};

namespace fnv_0063e9f0 {
class TESSaveLoadGame
{
  public:
    void FUN_008579b0(void*, int);
    void FUN_00857a10(int*, int);
};

class SaveManager : public TESSaveLoadGame
{
  public:
    unsigned char FUN_008df040();
};

extern SaveManager* DAT_011de45c;

struct FUN_0063e9f0_shell
{
    unsigned char pad_00[0x10];
    TESForm* form_10;
    TESForm* form_14;
    TESForm* form_18;
    TESForm* form_1c;
    unsigned char pad_20[0xcc];
    int value_ec;
    int value_f0;
    int value_f4;
    int value_f8;
    unsigned char pad_fc[0x14];
    int value_110;
    unsigned char pad_114[4];
    int value_118;

    void FUN_0063e9f0();
};

}  // namespace fnv_0063e9f0

struct SaveFormIDHelper
{
    void SerializeFormData(void* data, int value);
};

struct BGSSaveFormBuffer : SaveFormIDHelper
{
    void SaveData(void* data, int size, int value);
};

struct FUN_0063eb70_shell
{
    unsigned char pad000[0x10];
    void* m10;
    void* m14;
    void* m18;
    void* m1c;
    unsigned char pad020[0x94];
    int mB4;
    int mB8;
    int mBC;
    unsigned char pad0C0[0x24];
    int mE4;
    int mE8;
    int mEC;
    int mF0;
    int mF4;
    int mF8;
    unsigned char pad0FC[0x14];
    int m110;
    unsigned char pad114[4];
    int m118;

    void FUN_0063eb70(BGSSaveFormBuffer* buffer);
};

class ElemC_b9476
{
  public:
    int unk00;
};
class ElemB_b9476
{
  public:
    ElemC_b9476* Resolve();
};
class ElemA_b9476
{
  public:
    int unk00;
    int Test();
    void Clear(int);
    ElemB_b9476* Get(int);
};
class ResultX_b9476
{
  public:
    void SetFlag(int);
    void Scale(float);
};

void* LookupB9476(void*, void*);
extern char DAT_012005b8;

class FUN_00634930_cls
{
  public:
    int CountItems();
    int unk00;
    int unk04;
    ElemA_b9476 m_08[4];
    ElemA_b9476 m_18[4];
    void FUN_00634930();
};

class SkySound
{
  public:
    void* field00;
    void* field04;
    void* field08;
    unsigned int field0c;
    void* field10;
    void* field14;
};

SkySound** __fastcall FUN_006815c0(void* node);
void* __fastcall FUN_00726070(void* node);

struct FUN_0063e060_shell
{
    unsigned char pad0[0xfc];
    void* m_pSkySounds;
    bool FUN_0063e060(void* m_pWeatherObject, unsigned int uiType);
};

struct FogVector
{
    float x, y, z;
};
struct FogNode
{
    void FUN_00450f90(bool);
    const FogVector& FUN_0045bb80();
};
struct FogRoot
{
    FogNode* FUN_00559450();
};
struct FogCelestial
{
    FogNode* FUN_005585e0();
    FogNode* FUN_0043b230();
};
struct FogClouds
{
    int GetOffset58();
    FogNode* FUN_0063c440(int);
};
struct FogWeather
{
    float FUN_0063c420(int);
};
struct FogWater
{
    float FUN_004e3d00();
    float FUN_00507b20();
    int FUN_004f9bf0();
    int FUN_009ee040();
};
struct FogCell
{
    float FUN_005471e0();
    float FUN_00544b10();
    float FUN_00544ab0();
    float FUN_00544b70();
};
struct FogPlayer
{
    FogCell* FUN_008d6f30();
};
struct FogEnvironment
{
    FogCell* FUN_005f36f0();
};
struct FogSetting
{
    float* FUN_00403e20();
};
struct FogCamera
{
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual float GetFarPlane();
    FogNode* FUN_00558310();
};
struct FogBlend
{
    int colors[4];
    float weights[4];
};
struct FogSky
{
    void* table;
    FogRoot root;
    int unk08, unk0c;
    FogWeather* currentWeather;
    FogWeather* lastWeather;
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
    FogVector waterColor;
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
    int unkcc;
    int unkd0;
    float nearDistance, farDistance, unkdc, unke0, unke4, power, hour, unkf0, transition;
    unsigned int mode;
    FogClouds* FUN_0055b980();
    FogCelestial* FUN_007af430();
    FogCelestial* FUN_0045cd60();
    float FUN_0063b9b0();
    float FUN_00595f50();
    float FUN_00595fc0();
    float FUN_0063ba30();
    void FUN_0063c690(FogVector*, FogBlend*, float);
    void FUN_0063bce0();
};
int FUN_0063c470();
bool FUN_004e2180();
bool FUN_004e3c40();
FogCamera* FUN_0045c670();
float FUN_0063c480();
unsigned char FUN_0063c460();
float FUN_0040ebd0(float, float);
extern FogPlayer* DAT_011dea3c;
extern FogEnvironment* DAT_011dea10;
extern float DAT_011ccc60;
extern FogSetting DAT_01203144;
extern const double DAT_01012070, DAT_01011588, DAT_01012060, DAT_0103a480, DAT_0104ee90;
extern const float DAT_010317c4;

namespace SkyAssets {
struct Object;
struct Scene;
struct Texture;
struct Model;
struct String
{
    unsigned int unk0, unk4;
    String();
    ~String();
    void FUN_00438390(const char*);
    void FUN_00404820(const char*);
    const char* FUN_00559450();
};
struct Pointer
{
    Object* object;
    Pointer(int);
    ~Pointer();
    Object* FUN_00559450();
};
struct Update
{
    unsigned int unk0, unk4, unk8;
    Update(float, int, int);
};
struct Object
{
    void FUN_00a5a040();
    void FUN_00a59c60(Update*);
};
struct ScenePointer
{
    Object* object;
    Object* FUN_00559450();
};
struct Texture
{
    void FUN_006348e0(Object*);
};
struct Property
{
    Texture* FUN_00a59d30();
};
struct Visible
{
    void FUN_00635fe0(bool);
};
struct Cloud
{
    Property* FUN_006fa820(int);
    Property* FUN_0063d040(int);
    Visible* FUN_005585e0();
    Visible* FUN_0043b230();
};
struct Model
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void slot10();
    virtual void slot14();
    virtual const char* Prefix();
    unsigned int FUN_0048cee0();
    const char* FUN_00408da0();
};
struct Weather
{
    void* FUN_0063cfe0();
    Model* FUN_0063cfa0(int);
    bool FUN_0063d000();
    bool FUN_0063d020();
};
struct Atmosphere
{
    void FUN_0063fdb0(void*);
};
struct Particle
{
    virtual ~Particle();
    virtual void slot4();
    virtual void slot8();
    virtual void slotc();
    virtual void Attach(Object*, const char*);
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    Particle(const char*, float, float, float, float, float, int);
};
struct Setting
{
    float* FUN_00403e20();
    int* FUN_0043d4d0();
};
extern Setting DAT_011ccc18;
extern Setting DAT_011ccc54;
extern Setting DAT_011ccbfc;
extern Setting DAT_011ccba4;
extern Setting DAT_011ccc94;
extern Setting DAT_011cccb8;
extern Setting DAT_011cccec;
extern Setting DAT_011ccc7c;
extern Setting DAT_011ccbcc;
extern Setting DAT_011ccc64;
extern Setting DAT_011ccbe8;
extern Setting DAT_011ccb98;
extern bool DAT_011f941e;
extern char DAT_0102d7c4, DAT_0104eeb8, DAT_0104eeb0, DAT_0104eea8;
int FUN_00404dc0(const char*, const char*);
void FUN_00b55840(const char*, int, Pointer*, int, int);
struct Sky
{
    unsigned int unk0;
    ScenePointer scene, root;
    Weather* weather;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    Atmosphere* atmosphere;
    Cloud* cloud;
    unsigned int unk2c;
    Particle* rain;
    Particle* snow;
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
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    int mode;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int flags;
    void FUN_0063ca20();
};
}

bool FUN_00702360();
bool FUN_00705ea0();
struct BSAudio;
BSAudio* FUN_00453a70();
struct BSSoundHandleEx
{
    unsigned int uiID;
    bool m_bLooping;
    unsigned int uiState;
    ~BSSoundHandleEx();
};
struct FUN_00ad73b0_t
{
    BSSoundHandleEx FUN_00ad73b0(const char* apName, unsigned int auiFlags);
};
struct BSStr
{
    operator const char*() const;
};
struct SndX
{
    bool IsValid();
};
struct SH_00418890
{
    void FUN_copy(const void* apHandle);
};
struct FUN_00ad8830_shell
{
    bool FUN_00ad8830(bool abFlag);
};
struct FUN_00ad8a20
{
    float Op();
};
struct FUN_00ad89e0_shell
{
    bool FUN_00ad89e0(float afVolume);
};
struct std
{
    static float __cdecl abs(float afValue);
};
struct FUN_0063e0d0_shell
{
    char pad[0x10];
    int iState;
    bool FUN_00ad8930();
    void FUN_0063e0d0(float afVolume);
};

class Texture139;
class Property139
{
  public:
    void FUN_006348e0(Texture139*);
};
class Node139
{
  public:
    Property139* FUN_00a59d30(unsigned int);
    void FUN_00635fe0(bool);
};
class Model139
{
  public:
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual const char* Path();
    int FUN_0048cee0();
    const char* FUN_00408da0();
};
class Weather139
{
  public:
    Model139* FUN_006347a0(int);
};
class Clouds139
{
  public:
    int GetOffset58();
    Node139* FUN_0063c440(int);
};
class Moon139
{
  public:
    int unk00, unk04, unk08, unk0c, unk10;
    NiPointer<Node139> node;
    int unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54,
        unk58, unk5c, unk60, unk64, unk68, unk6c;
    int phase;
};
class Sun139
{
  public:
    Node139* FUN_006fa820();
    Node139* FUN_005585e0();
    Node139* FUN_0063d040();
    Node139* FUN_0043b230();
};
class Climate139
{
  public:
    Model139* FUN_0063cfa0(int);
    int FUN_0063cfe0();
};
class Stars139
{
  public:
    void FUN_0063fdb0(int);
};
class Save139
{
  public:
    bool FUN_0042ce10();
};
class Append139
{
  public:
    void FUN_00404820(const char*);
};
int __cdecl FUN_00406f60(BSStringT<char>*, const char*, ...);
int __cdecl FUN_00456a20(const char*, char*, unsigned int, unsigned int);
void __cdecl FUN_00b55840(const char*, bool, NiPointer<Texture139>&, bool, bool);
int __cdecl FUN_00404dc0(const char*, const char*);
extern unsigned char DAT_011f941e;
struct FUN_0063e2f0_shell : Sky
{
    void FUN_0063e2f0();
};

namespace fnv_0063ef20 {
struct TESObjectDoorController
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct ImageSpaceModifierInstanceDOF : public TESObjectDoorController
{
    int f00;
    int f04;
    unsigned char f08;
    unsigned char f09;
    unsigned char f0a;
    unsigned char f0b;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    ImageSpaceModifierInstanceDOF();
    void FUN_005bbd60(bool);
    void FUN_0063f790(float);
    void FUN_0050f9a0(void*);
};

struct GlobalObject_00633c90
{
    GlobalObject_00633c90(int v);
    ~GlobalObject_00633c90();
    int m_ptr;
};

struct ListX
{
    void FUN_00631540(const GlobalObject_00633c90&);
};
struct TESX
{
    ListX* FUN_0043b5d0();
};
extern TESX* DAT_011dea10;

struct WeatherSub
{
    void* FUN_005822a0(int);
};
struct WeatherX
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    WeatherSub sub18;
};

void* __cdecl FUN_00532ff0();
float __fastcall FUN_00595f50(Sky*);
float __fastcall FUN_00595fc0(Sky*);
void __cdecl FNV_Warning(const char*, ...);
extern char DAT_0104ee38;

struct FUN_0063ef20_shell : public Sky
{
    void FUN_0063ef20();
};
}  // namespace fnv_0063ef20

struct GlobalObject_0045cf30
{
    SETTING_VALUE* Bool();
};
extern GlobalObject_0045cf30 g_011ccb8c;
extern unsigned char DAT_011ccb74;

struct GlobalObject_0041a250
{
    int m00;
    unsigned char m04;
    int m08;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    GlobalObject_0041a250(const GlobalObject_0041a250&);
    void FUN_copy(const void*);
    bool FUN_00ad8d10();
};

struct BSAudio
{
    GlobalObject_0041a250 FUN_00ad73b0(int, int);
};
BSAudio* __cdecl FUN_00453a70();

struct Entry
{
    int m00;
    int m04;
};

struct ParamObj
{
    BSSimpleList<Entry*>* FUN_0063dff0();
};

struct NodeObj
{
    GlobalObject_0041a250 m_handle;
    ParamObj* m0c;
    int m10;
    int m14;
    int m18;
    NodeObj(GlobalObject_0041a250, ParamObj*, int, int);
};

struct NodeList
{
    NodeObj*& GetItem();
    NodeList* GetNext();
    void AddHead(NodeObj* const& item);
};

struct ThisCls
{
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    int m70;
    int m74;
    int m78;
    int m7c;
    int m80;
    int m84;
    int m88;
    int m8c;
    int m90;
    int m94;
    int m98;
    int m9c;
    int ma0;
    int ma4;
    int ma8;
    int mac;
    int mb0;
    int mb4;
    int mb8;
    int mbc;
    int mc0;
    int mc4;
    int mc8;
    int mcc;
    int md0;
    int md4;
    int md8;
    int mdc;
    int me0;
    int me4;
    int me8;
    int mec;
    int mf0;
    int mf4;
    int mf8;
    NodeList* m_fc;
    void FUN_0063ddb0(ParamObj* arg);
};

namespace fnv_0063b630 {
struct SkyInterpolationData
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float weight1;
    float weight2;
    float weight3;
    float weight4;
};

struct FUN_0063b9b0_shell
{
    float FUN_0063b9b0();
};

struct FUN_0063ba30_shell
{
    float FUN_0063ba30();
};

void FNV_Warning(const char*);

class SkyHelper : public Sky
{
  public:
    float FUN_00595f50();
    float FUN_00595fc0();
    void FUN_0063b630(SkyInterpolationData* pData, TESWeather* m_pWeatherObject, float fPct, int* pPhase, int* pNextPhase);
};

}  // namespace fnv_0063b630

struct SetHelper
{
    float x, y, z;
    NiPoint3* Set(float a, float b, float c);
};

union CU
{
    unsigned int u;
    unsigned short w;
};

struct SkyColors
{
    CU c[4];
    float f[4];
};

struct Wx
{
    float GetWeatherData(int idx, float a, float b);
};

struct Sh63c8a0
{
    void* FUN_0063c8a0(NiPoint3* p);
};

struct ShA69690
{
    void FUN_00a69690();
};

float __cdecl FUN_0040ebd0(float a, float b);
void __cdecl FUN_005330e0(float* p, float lo, float hi);

struct FUN_0063c690_shell
{
    char pad[0x10];
    Wx* m_pWeatherObject;
    void FUN_0063c690(float* out, SkyColors* sc, float t);
};

class ClimateWeather : public TESClimate
{
  public:
    unsigned char FUN_00451cd0();
    TESWeather* FUN_0063d5c0();
};
class WeatherValues : public TESWeather
{
  public:
    float GetWeatherData(int, float, float);
};
class WeatherRegion
{
  public:
    void FUN_004f1050();
};
class TESRegionList : public BSSimpleList<WeatherRegion*>
{
  public:
    virtual ~TESRegionList();
};
class WeatherDataHandler : public TESDataHandler
{
  public:
    TESRegionList* FUN_004169d0();
};
extern WeatherDataHandler* g_dataHandler;
class WeatherCell
{
  public:
    TESWeather* FUN_0059bb30();
};
class PlayerCharacter
{
  public:
    WeatherCell* FUN_005454d0();
};
extern PlayerCharacter* g_thePlayer;
class SaveWeatherState : public BGSSaveLoadGame
{
  public:
    bool FUN_0042ce10();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting71;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting72;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting73;
TESForm* FUN_004839c0(unsigned int);
class SkyWeatherUpdate : public Sky
{
  public:
    void FUN_0063d1d0();
    void FUN_0063e860(bool);
};

namespace fnv_0063a630 {
struct GlobalObject_0045cf30
{
    SETTING_VALUE* Bool();
};
extern GlobalObject_0045cf30 g_011ccb8c;
extern unsigned char DAT_011f426c;
extern bool DAT_011F941E;
extern float DAT_011ad87c, DAT_011ad880;
class NiAlphaProperty;
class NiNode
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void AttachChildInAvailableSlot(NiNode*, bool);
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void InsertChild(NiNode*);
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
    int m54;
    int m58;
    int m5c;
    int m60;
    int m64;
    int m68;
    int m6c;
    int m70;
    int m74;
    int m78;
    int m7c;
    int m80;
    int m84;
    int m88;
    int m8c;
    int m90;
    int m94;
    int m98;
    int m9c;
    int ma0;
    int ma4;
    int ma8;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    NiNode(unsigned short);
    NiNode* FUN_009611e0();
    void FUN_005468d0(bool);
    void FUN_004902f0(bool);
    void FUN_00440460(const void*);
    void FUN_00439410(NiAlphaProperty*);
    void FUN_00a5a040();
};
class FUN_00c46970 : public NiNode
{
  public:
    int mac, mb0;
    FUN_00c46970();
};
class AtmosphereObj
{
  public:
    virtual ~AtmosphereObj();
    virtual void vfn04();
    virtual void Init(NiNode*);
    virtual void vfn0c();
    virtual void Init2(NiNode*, int);
    int m04, m08, m0c, m10, m14, m18;
};
class FUN_00633080 : public AtmosphereObj
{
  public:
    FUN_00633080();
};
class StarsObj
{
  public:
    virtual ~StarsObj();
    virtual void vfn04();
    virtual void Init(NiNode*);
    int m04, m08, m0c;
};
class FUN_0063fc70 : public StarsObj
{
  public:
    FUN_0063fc70();
};
class Sun
{
  public:
    virtual ~Sun();
    virtual void vfn04();
    virtual void Init(NiNode*);
    int m04, m08, m0c, m10, m14, m18, m1c, m20, m24, m28;
    Sun();
};
class PrecipObj
{
  public:
    virtual ~PrecipObj();
    int m04, m08, m0c, m10, m14;
    void FUN_00636bb0();
};
class FUN_00636a40 : public PrecipObj
{
  public:
    FUN_00636a40();
};
class CloudsObj
{
  public:
    virtual ~CloudsObj();
    virtual void vfn04();
    virtual void Init(NiNode*);
    int m04, m08, m0c, m10, m14, m18, m1c, m20, m24, m28, m2c, m30, m34, m38, m3c, m40, m44, m48, m4c, m50, m54, m58;
};
class FUN_00633cc0 : public CloudsObj
{
  public:
    FUN_00633cc0();
};
class NiAlphaProperty
{
  public:
    int m00, m04, m08, m0c, m10, m14, m18;
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    NiAlphaProperty();
    void FUN_00439340(int);
    void FUN_00439390(int);
    void FUN_0049ed90(bool);
    void FUN_00636000(bool);
};
struct RootPointer
{
    NiNode* p;
    bool FUN_0052aa80(int) const;
    NiNode* operator->() const;
    operator NiNode*() const;
    RootPointer& operator=(NiNode*);
};
struct ThisCls
{
    int m00;
    NiPointer<NiNode> m04, m08;
    int m0c, m10, m14, m18, m1c;
    AtmosphereObj* m20;
    StarsObj* m24;
    Sun* m28;
    CloudsObj* m2c;
    int m30, m34;
    PrecipObj* m38;
    void FUN_0063a630(NiNode*, int);
};
}  // namespace fnv_0063a630

struct FUN_0063bb70_value
{
    int value;
};

struct FUN_0063bb70_result
{
    int value0;
    int value1;
    int value2;
    int value3;
};

struct FUN_0063bb70_shell
{
    void QueryTwoSources(FUN_0063bb70_result* result, FUN_0063bc60_shell* first, FUN_0063bc60_shell* second, int value,
                         FUN_0063bb70_value* source1, FUN_0063bb70_value* source2);
};

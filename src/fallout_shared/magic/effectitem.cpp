// fallout_shared/magic/effectitem.cpp: EffectItem, EffectItemList, ScriptEffect, Setting and more (2 functions)
#include "f3_common.h"
#include "effectitem_decls.h"

// @f3 0x006f7fa0 (community match, verified in this file)
struct FUN_0045e360_cls
{
    bool FUN_0045e360();
};
struct FUN_006f7fa0_obj
{
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00c();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01c();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02c();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03c();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04c();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05c();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06c();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07c();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08c();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09c();
    virtual void vfn0a0();
    virtual void vfn0a4();
    virtual void vfn0a8();
    virtual void vfn0ac();
    virtual void vfn0b0();
    virtual void vfn0b4();
    virtual void vfn0b8();
    virtual void vfn0bc();
    virtual void vfn0c0();
    virtual void vfn0c4();
    virtual void vfn0c8();
    virtual void vfn0cc();
    virtual void vfn0d0();
    virtual void vfn0d4();
    virtual void vfn0d8();
    virtual void vfn0dc();
    virtual void vfn0e0();
    virtual void vfn0e4();
    virtual void vfn0e8();
    virtual void vfn0ec();
    virtual void vfn0f0();
    virtual void vfn0f4();
    virtual void vfn0f8();
    virtual void vfn0fc();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10c();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11c();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12c();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13c();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14c();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15c();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16c();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17c();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18c();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19c();
    virtual void vfn1a0();
    virtual void vfn1a4();
    virtual void vfn1a8();
    virtual void vfn1ac();
    virtual void vfn1b0();
    virtual void vfn1b4();
    virtual void vfn1b8();
    virtual void vfn1bc();
    virtual void vfn1c0();
    virtual void vfn1c4();
    virtual void vfn1c8();
    virtual void vfn1cc();
    virtual void vfn1d0();
    virtual void vfn1d4();
    virtual void vfn1d8();
    virtual void vfn1dc();
    virtual void vfn1e0();
    virtual FUN_0045e360_cls* vfn1e4(int aValue);
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    int unk024;
    int unk028;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    int unk03c;
    int unk040;
    int unk044;
    int unk048;
    int unk04c;
    int unk050;
    int unk054;
    int unk058;
    int unk05c;
    int unk060;
    int unk064;
    int unk068;
    int unk06c;
    int unk070;
    int unk074;
    int unk078;
    int unk07c;
    int unk080;
    int unk084;
    int unk088;
    int unk08c;
    int unk090;
    int unk094;
    int unk098;
    int unk09c;
    int unk0a0;
    int unk0a4;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int unk0c0;
    int unk0c4;
    int unk0c8;
    int unk0cc;
    int unk0d0;
    int unk0d4;
    int unk0d8;
    int unk0dc;
    int unk0e0;
    unsigned char unk0e4;
    unsigned char unk0e5;
};

bool EffectItem::IsHostile()
{
    FUN_006f7fa0_obj* pObject = (FUN_006f7fa0_obj*)this;
    int iValue = pObject->unk0e5;
    bool bResult = pObject->vfn1e4(iValue)->FUN_0045e360();
    pObject->unk0e5 = 0;
    return bResult;
}


// Constructs a ScriptEffect from caster, item and effect, initializing the base ActiveEffect and storing the effect's script with unknown set to 0.
// @fnv 0x00827740
ScriptEffect::ScriptEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect)
    : ActiveEffect(caster, item, effect)
{
    script = effect->GetScript();
    unknown = 0;
}

struct MagicEffectSystem
{
    static bool __cdecl IsFlagSet(int, unsigned int);
};
struct S3c60
{
    int GetArchetype();
    bool HasFlag2();
};

struct EffectArchetypeEntry
{
    unsigned int uiFlags;
    unsigned int pad[3];
};

extern EffectArchetypeEntry DAT_01183328[];

void* __cdecl _fnv_zlib_memset(void* apDest, int aiValue, unsigned int aCount);

struct FUN_00403db0_shell : public EffectItem
{
    void FUN_00403db0(TESForm*);
};

struct S3e60
{
    bool GetFlag(unsigned int) const;
    bool FUN_00403e60(unsigned int f);
};

struct FUN_00403e80_shell : public EffectSetting
{
    bool FUN_00403e80();
};

struct FUN_00403ee0_shell : public EffectItem
{
    bool FUN_00403ee0();
};

struct FUN_00403f00_shell : public EffectItem
{
    float FUN_00403f00();
};

class TESGrass
{
  public:
    float GetLowestAllowedSlope();
};

float __cdecl CalcEffectCost(float, int, int, int, bool);

struct Actor;
struct AlchemyItem;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct NiNode;
struct SpellItem;
struct TESBoundObject;
struct TESObjectCELL;
struct TESObjectREFR;
struct hkpRigidBody;
struct blob12
{
    char b[12];
};
struct TESChildCell
{
    virtual TESObjectCELL* GetSaveParentCell();
};
typedef char _sizecheck_TESChildCell[sizeof(TESChildCell) == 4 ? 1 : -1];
struct ActorValueOwner
{
    virtual int GetBaseActorValue(int);
    virtual float GetBaseActorValueFloat(int);
    virtual int GetActorValue(int);
    virtual float GetCurrentActorValue(int);
    virtual float GetPermanentActorValueFloat(int);
    virtual float GetTemporaryActorValue(int);
    virtual float GetDamageActorValue(int);
    virtual int GetPermanentActorValue(int);
    virtual float GetPermanentActorValueAdjustment(int);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    int GetActorValueAsInteger(int);
    float GetActorValueFloatByIndex(int);
};
typedef char _sizecheck_ActorValueOwner[sizeof(ActorValueOwner) == 4 ? 1 : -1];
struct CachedValuesOwner
{
    virtual float GetFloatValue0();
    virtual float GetFloatValue1();
    virtual float GetFloatValue2();
    virtual float GetFloatValue3();
    virtual float GetFloatValue4();
    virtual float GetFloatValue5();
    virtual float GetFloatValue6();
    virtual float GetFloatValue7();
    virtual float GetFloatValue8();
    virtual float GetFloatValue9();
    virtual float GetFloatValue10();
    virtual float GetFloatValue11();
    virtual int GetIntegerValue12();
    virtual int GetIntegerValue13();
    virtual float GetFloatValue14();
    virtual float GetFloatValue15();
    virtual bool GetBooleanValue16();
    void PrecalculateCachedValues();
};
typedef char _sizecheck_CachedValuesOwner[sizeof(CachedValuesOwner) == 4 ? 1 : -1];
struct FUN_00403f80_shell : public EffectItem
{
    float GetModifiedCost(Actor*);
};

float __fastcall FUN_00403f00(EffectItem*);
float __cdecl ScaleBySettingBlend(float, int, int);
float __cdecl FUN_00404040(float);
float __cdecl FUN_00404010(float, float);

float __cdecl TruncateToInt(float);
extern const double _gModifierZero;

struct FUN_004042a0_shell : public EffectItem
{
    bool IsDifferentFrom(EffectItem*);
};

struct FUN_00404390_shell : public EffectItem
{
    int FUN_00404390();
};

struct FUN_00404420_shell : public EffectItem
{
    int FUN_00404420();
};

struct FUN_004044d0_shell : public EffectItem
{
    int FUN_004044d0();
};

namespace fnv_004045e0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct ExtraDataList;
struct ScriptHeaderData;
struct ScriptReferencedObject;
struct Script;
struct CStringArgument;
struct ScriptCompiler;
struct ScriptLocals;
struct TESObject;
struct TESObjectREFR;
struct TESQuest;
struct FUN_004045e0_shell : public EffectItem
{
    Script* GetScriptFromEffectSetting();
};

int __fastcall _FNV_GetFormType(int);
int __fastcall EffectSetting_GetArchetype(EffectSetting*);
__pragma(comment(
    linker, "/alternatename:?EffectSetting_GetArchetype@@YIHPAUEffectSetting@@@Z=?GetArchetype@EffectSetting@@QAEHXZ"))
    __pragma(comment(
        linker,
        "/alternatename:?EffectSetting_GetArchetype@@YIHAAVEffectSetting@@@Z=?GetArchetype@EffectSetting@@QAEHXZ"))

        class MagicEffectSystem
{
  public:
    struct _Type
    {
        enum Type
        {
        };
    };
    static bool __cdecl IsFlagSet(_Type::Type, unsigned int);
};

class TESChallenge
{
  public:
    int GetInterval();
};

}  // namespace fnv_004045e0

char* __cdecl _strcpy(char*, const char*);

struct S4eb0
{
    int a;
    unsigned int b;
    int c;
    void FUN_00404f00(int, bool, char*, int);
    S4eb0* FUN_00404eb0(int, bool, char*, int);
};

struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct FUN_00404f00_shell : public AutoMemContext
{
    void FUN_00404f00(int, bool, char*, int);
};

int __cdecl GetTlsField();
void __cdecl FUN_00404f30(int);

namespace fnv_00404f70 {
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct FUN_00404f70_shell : public AutoMemContext
{
    void FUN_00404f70();
};

void __cdecl FUN_00404f30(int);

}  // namespace fnv_00404f70

unsigned int __cdecl _strlen(const char*);

namespace fnv_005f5f80 {
struct Actor;
struct ActorMover;
struct ActorPathHandler;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct DetailedActorPathHandler;
struct IDebugText;
struct NiPoint3;
struct PathingRequest;
struct TESObjectREFR;
struct blob12
{
    char b[12];
};
struct FUN_005f5f80_shell : public EffectSetting
{
    TESForm* FUN_005f5f80();
};

}  // namespace fnv_005f5f80

extern "C" int __tls_index;

__declspec(thread) int DAT_tls_field = 0x3b;

struct MagicCaster;
struct FUN_0045cd60_shell : public ActiveEffect
{
    MagicCaster* FUN_0045cd60();
};

struct FUN_004040b0_shell : BGSImpactData__IMPACT_DATA_DATA, EffectItem
{
    void Save();
};

extern "C" bool __cdecl FUN_00401500();
extern "C" void __cdecl AppendChunk(unsigned int, void*, unsigned int);

struct TESConditionSave
{
    void ProcessItems();
};

struct EffectItem_shell : EffectItem
{
    bool FUN_00404470(int range);
};

namespace fnv_00404f30 {
extern "C" unsigned int __tls_index;

__declspec(thread) int tlsVar[0x2b4 / 4 + 1];

}  // namespace fnv_00404f30

struct FUN_006808b0
{
    ~FUN_006808b0();
};
struct MyCondProxy
{
    void InitializeConditionItems();
};
struct FUN_00403d50
{
    char _pad[0x1c];
    FUN_006808b0 _c;
    ~FUN_00403d50();
};

struct Unk004043d0
{
    bool FUN_004043d0(int);
};

struct S00404510
{
    char _00[8];
    int m08;
    char _0C[8];
    EffectSetting* m14;
    float m18;
    bool FUN_00404510(int);
};

struct Setting
{
    void FUN_00404950();
    void* FUN_004049a0(unsigned int);
};
void __cdecl _Deallocate(void*);

struct Dummy
{
    void FUN_00404c00();
    void* FUN_00404ca0(unsigned int);
};
void _Deallocate(void*);

struct ArrSI
{
    unsigned int GetFlags();
};

struct MapH
{
    bool RemoveAt(unsigned int);
};

struct FUN_00404f90_shell
{
    unsigned char _pad[0x10c];
    MapH _map;
    void RemoveSettingFromMap(ArrSI* apSetting);
};

namespace fnv_00404fd0 {
struct AutoMemHelper
{
    int padding;

    AutoMemHelper(int, bool, char const*, int);
    ~AutoMemHelper();
};

template <class T> struct NiTPrimitiveArray
{
};

struct Setting
{
    void FUN_00c33280(NiTPrimitiveArray<char*>*);
};

struct MapX
{
    void* GetFirstPos();
};

struct NiTMap
{
    void GetNext(void*&, unsigned int&, void*&);
};

template <class T> struct SettingCollectionMap
{
    unsigned int FUN_00404fd0(NiTPrimitiveArray<char*>*);
};

int _data_011c16bc;

}  // namespace fnv_00404fd0

class FUN_00403b30_base
{
  public:
    FUN_00403b30_base();
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
};

class FUN_00403b30_member
{
  public:
    FUN_00403b30_member();
    ~FUN_00403b30_member();
    unsigned int m_00;
};

class FUN_00403b30_cls : public FUN_00403b30_base
{
  public:
    FUN_00403b30_member m_1c;
    FUN_00403b30_cls(int a);
    void Init(int a);
};

extern float DAT_01012054;

struct FUN_00403be0_target
{
    bool HasFlag2();
};

class FUN_00403be0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    int m_iResult;
    InterfaceManager* m_pManager;
    float m_fValue;

    void FUN_00403be0(InterfaceManager* manager);
};

struct MapAccess
{
    void* FUN_004b9ba0();
    void FUN_006b7f20(void** position, int* key, void** value);
};
struct EffectProcess
{
    virtual void unknown00() = 0;
    virtual void unknown04() = 0;
    virtual void unknown08() = 0;
    virtual void unknown0c() = 0;
    virtual bool ProcessEffect(void* effect) = 0;
    bool FUN_00404d30();
    bool ProcessAllEffects();
};

namespace fnv_00404560 {
extern const float DAT_01012054;

struct FUN_00404210_t
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    S3e60* unk14;
    float unk18;

    bool __thiscall FUN_00404560(unsigned int value);
};

}  // namespace fnv_00404560

extern char str_01012220[];
struct SettingMap
{
    int FUN_004b9ba0();
    void FUN_006b7f20(int*, int*, int*);
};
struct SettingRegistry
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual bool HandleSetting(int);
    bool FUN_00405120();
};
extern "C" bool __fastcall FUN_00404d30(SettingRegistry*);
extern "C" void __fastcall FUN_00404ee0(S4eb0*);
struct ScopedContext
{
    int previousContext;
    __forceinline ScopedContext(int context, bool temporary, char* file, int line)
    {
        reinterpret_cast<S4eb0*>(this)->FUN_00404eb0(context, temporary, file, line);
    }
    __forceinline ~ScopedContext()
    {
        FUN_00404ee0(reinterpret_cast<S4eb0*>(this));
    }
};

char* __cdecl FUN_00401000(unsigned int aSize);
const char* __cdecl FUN_00464f30(const char* apString, int aFlag);

struct FUN_004d61b0_sub
{
    FUN_004d61b0_sub(int aValue);
    ~FUN_004d61b0_sub();
};

class FUN_004d61b0
{
  public:
    int m00;
    int m04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_004d61b0_sub m18;
    int unk1C;
    int unk20;
    int unk24;
    int m28;
    char* m2c;

    void CreateTreeWindows(int a5, int a6, int a7, int a8);
    void FUN_004d6490();
    void FUN_004d64c0(int aValue, int aFlag);
    FUN_004d61b0(int a1, int a2, int a3, const char* a4, int a5, int a6, int a7, int a8);
};

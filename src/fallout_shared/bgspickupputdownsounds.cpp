// fallout_shared/bgspickupputdownsounds.cpp: TESIcon, BGSPickupPutdownSounds (1 function)
#include "f3_common.h"
#include "bgspickupputdownsounds_decls.h"
#include "bgspickupputdownsounds_types_BGSPickupPutdownSounds.h"

// @f3 0x00593340 (community match, verified in this file)
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern volatile long g_liveObjectCount;
extern const int FUN_00db7764[];   // TESIcon vftable
extern const int FUN_00dfc184[];   // TESTexture vftable (the base ctor's store)

template <class T> BSStringT<T>::BSStringT()
{
}

TESIcon::TESIcon()
{
    *(int*)((char*)this + 4) = 0;
    InterlockedIncrement(&g_liveObjectCount);
    *(const int**)this = FUN_00dfc184;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 0xc) = 0;
}


extern int DAT_0101abd8;
void __fastcall FUN_0047b540(void* pThis);

struct BGSMenuIcon;
struct BGSMessageIcon;
struct BGSTextureSet;
struct BipedAnim;
struct NiAVObject;
struct NiPoint3;
struct Script;
struct TESBoundObject;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESObjectREFR;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob12
{
    char b[12];
};
struct BGSClipRoundsForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static int GetClipRounds(TESForm*);
    int GetClipRounds();
    void SetFormClipRounds(int);
    void* __vecDelDtor(unsigned int);
    unsigned char m_ucClipRounds;
    char _pad_5[3];
};
typedef char _sizecheck_BGSClipRoundsForm[sizeof(BGSClipRoundsForm) == 8 ? 1 : -1];
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct TESScriptableForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    static Script* GetScriptForForm(TESForm*);
    Script* GetScriptForForm();
    static char* GetFormScriptEditorID(TESForm*);
    char* GetFormScriptEditorID();
    static void SetFormScript(TESForm*, Script*);
    void SetFormScript(Script*);
    Script* m_pFormScript;
    bool m_bHasScript;
    char _pad_9[3];
};
typedef char _sizecheck_TESScriptableForm[sizeof(TESScriptableForm) == 12 ? 1 : -1];
struct TESWeightForm : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static float GetWeightForForm(TESForm*, bool);
    float GetWeightForForm();
    void SetFormWeight(float);
    void* __vecDelDtor(unsigned int);
    float fWeight;
};
typedef char _sizecheck_TESWeightForm[sizeof(TESWeightForm) == 8 ? 1 : -1];
struct BGSEquipType : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static int GetEquipType(TESForm*);
    int GetEquipType();
    void SetEquipType(int);
    static BGSMenuIcon* GetEquipTypeIcon(int);
    static char* GetEquipTypeName(int);
    static void GenerateDefaultMenuIcons();
    int m_eEquipType;
};
typedef char _sizecheck_BGSEquipType[sizeof(BGSEquipType) == 8 ? 1 : -1];
struct FUN_0047b540_shell : public BGSClipRoundsForm
{
    void FUN_0047b540();
};

struct TESObjectREFR
{
    void SetFlags(unsigned int);
};
struct TESRaceForm
{
    void Initialize(unsigned int);
};
struct ArrSI
{
    unsigned int GetFlags();
};
struct CombatNode
{
    unsigned int FUN_00726070();
};
struct FUN_0047b5d0_cls
{
    void FUN_0047b5d0(BaseFormComponent* component);
};

namespace fnv_0047b560 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct ItemList
{
    void* GetItem();
};
extern "C" void __cdecl FUN_00485910(int, int);
struct FUN_0047b560_shell : public TESForm
{
    void LogFormIDs();
};
}  // namespace fnv_0047b560

namespace fnv_0047b630 {
struct ArrSI
{
    unsigned int GetFlags();
};

struct FUN_0047b630_shell
{
    unsigned int FUN_00726070();
    bool IsSamePickupPutdownSounds(BaseFormComponent* component);
};

}  // namespace fnv_0047b630

extern int DAT_0101abd8;

struct FUN_0047b520_shell : TESForm
{
    void FUN_0047b520();
};

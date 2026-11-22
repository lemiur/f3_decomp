#include "f3_common.h"
// src/staging/blk_00400000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

extern int $SG3295;

struct FUN_00401280_Class
{
    int* __thiscall FUN_00401280();
};

struct FUN_00401660_Class
{
    unsigned int __thiscall GetField25C();
};

struct FUN_004036b0_Class
{
    unsigned int __thiscall FUN_004036b0();
};

struct Dummy
{
    void FUN_00404c00();
};

struct FUN_00404b70 : Dummy
{
    void FUN_00404b71();
};

extern "C" void* DAT_01012188;

struct Twin_008d0360
{
    bool GetBooleanValue();
    void FUN_00404c80();
};

extern "C" void* __cdecl DAT_010121b4;

struct FUN_00405570_struct
{
    void* __thiscall InitFromGlobal(int, char);
};

struct FUN_00404d50_class
{
    void* __thiscall ConstructWithVTable(int a, char b);
};

struct FUN_00405230_Class
{
    void __thiscall FUN_00405250();
    void __thiscall FUN_00405230();
};

extern int DAT_01012298;
void __cdecl FUN_004055d0(int, char);

struct FUN_00405570_cls
{
    void __thiscall FUN_004055d0(int, char);
    FUN_00405570_cls* __thiscall InitFromGlobal(int, char);
};

extern "C" void __cdecl Init(int);
extern int DAT_01012258;

struct FUN_00405600_class
{
    void __thiscall Init(int);
    void* __thiscall FUN_00405600(int param_2);
};

// Calls Init with param_2, stores the address of DAT_01012258 into this, and returns this.
// @fnv 0x00405600
void* __thiscall FUN_00405600_class::FUN_00405600(int param_2)
{
    Init(param_2);
    *(int*)this = (int)&DAT_01012258;
    return this;
}

struct EffectSetting
{
    bool IsFlagSet(unsigned int);
    void* __thiscall FUN_00402a10(void*);
    void __thiscall FUN_00405e60(const void*);
    void* __thiscall FUN_00405e60(void*);
};

// @f3 0x00402af0 (community match, verified in this file)
void* __thiscall EffectSetting::FUN_00405e60(void* a0)
{
    EffectSetting* p = *(EffectSetting**)((char*)this + 0x14);
    volatile int unused = 0;
    p->FUN_00402a10(a0);
    return a0;
}


struct FUN_00407860_class
{
    void FUN_00407860(float value);
};

struct FUN_00407880_Class
{
    void FUN_00407880(float value);
};

extern "C" void* DAT_01183320;

struct FUN_00409130_Class
{
    int __thiscall FUN_00409130();
};

struct FUN_00409700_Class
{
    bool FUN_00409700();
};

struct ContainerItemExtraFileData
{
    void Endian();
};

struct FUN_004098d0_class
{
    void FUN_004098d0();
};

int __cdecl FinishScriptRunLock(void*);

struct FUN_0040c130_Class
{
    int FUN_0040c130();
};

extern int DAT_010142ac;

struct BE
{
    int* pv;
    int pad;
    int mExtra;
    BE(unsigned char);
};

struct FUN_0040f6b0 : BE
{
    int* pBound;
    FUN_0040f6b0();
};

int __cdecl InitScriptRunLock(void*);

struct FUN_0040f6e0_class
{
    int __thiscall FUN_0040f6e0();
};

struct FUN_00413ff0_class
{
    float f;
    FUN_00413ff0_class* SetFromFloat(const float* p);
};

struct FUN_004181c0_class
{
    void __thiscall SetIndexedValue(int index, int value);
};

struct BSExtraData;
struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
    BSExtraData* FUN_00418200();
};
// @f3 0x00401b10 (community match, verified in this file)
struct Layout_BSExtraList
{
    BSExtraData* m_pExtra;
    unsigned short m_us4;
    unsigned short m_us6;
};
struct Global_01090a78
{
    void* FUN_0086ba60(void* p);
};
extern Global_01090a78 DAT_01090a78;
BSExtraData* BaseExtraList::FUN_00418200()
{
    Layout_BSExtraList* self = (Layout_BSExtraList*)this;
    BSExtraData* p = self->m_pExtra;
    if (p)
        p = (BSExtraData*)DAT_01090a78.FUN_0086ba60(p);
    self->m_pExtra = 0;
    self->m_us6 = 0;
    self->m_us4 = 0;
    return p;
}


namespace fnv_0041af30 {
struct BaseExtraList
{
    void RemoveExtra(unsigned char);
};

struct FUN_0041af30_shell : BaseExtraList
{
    void FUN_0041af30();
};

}  // namespace fnv_0041af30

struct GlobalObject_0040c150
{
    ~GlobalObject_0040c150();
    GlobalObject_0040c150* __thiscall FUN_004049d0(unsigned int flags);
};

struct FUN_00404da0_class
{
    void __thiscall FUN_00404da0();
    void* __thiscall FUN_00405200(unsigned int flags);
};

void __cdecl Deallocate(void*);

struct FUN_00405370_Class
{
    void __thiscall FUN_00405370();
    void* __thiscall FUN_004053a0(unsigned int flags);
};

void __cdecl operator delete(void*);
void FUN_00405310();
struct FUN_004053d0_class
{
    void FUN_00405310();
    void* FUN_004053d0(unsigned int flags);
};

namespace fnv_0040ecd0 {
struct BSExtraData
{
    virtual ~BSExtraData();
    void* __thiscall FUN_0040ecd0(unsigned int flags);
};
}  // namespace fnv_0040ecd0

struct FUN_00401270_Class
{
    bool __thiscall FUN_00401270(int, int, int, int, int);
};

struct FUN_00401290_Class
{
    char __thiscall FUN_00401290(int);
};

struct Base5a
{
    virtual ~Base5a();
};
struct FUN_00401ac0 : Base5a
{
    void ClearData();
    ~FUN_00401ac0();
};

extern int _gHungerStageCount;
extern int* _gHungerStages;

extern int _DAT_011c31b0;
extern void* _DAT_011c31b4;

struct FUN_00402a20_class
{
    void __thiscall FUN_00402a20(unsigned int flags, bool set);
};

void __cdecl _Deallocate(void*);
struct FUN_004055a0_Class
{
    void* __thiscall FUN_004055a0(unsigned int flags);
};

extern int DAT_01012238;
struct FUN_004055d0 : public FUN_00405600_class
{
    FUN_004055d0(int, char);
};
// Calls the base constructor with a, installs the vtable from DAT_01012238, and stores b at offset 0x10.
// @fnv 0x004055d0
FUN_004055d0::FUN_004055d0(int a, char b)
{
    FUN_00405600(a);
    *(int**)this = &DAT_01012238;
    *(char*)((char*)this + 0x10) = b;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);
extern "C" void* DAT_01012278;
struct FUN_00405630_s
{
    void* vtbl;
    int count;
    void* data;
    int pad;
    FUN_00405630_s* __thiscall Init(int count);
};
// Sets the vtable, stores count, allocates count*4 zeroed bytes into data and returns this.
// @fnv 0x00405630
FUN_00405630_s* __thiscall FUN_00405630_s::Init(int count)
{
    vtbl = &DAT_01012278;
    this->count = count;
    pad = 0;
    unsigned int size = this->count << 2;
    data = NiMalloc(size);
    memset(data, 0, this->count << 2);
    return this;
}

struct SL
{
    int m1;
    int m2;
    SL();
};
extern int DAT_01012508;
struct FUN_004056a0
{
    int vf;
    SL lst;
    int hostile;
    FUN_004056a0();
};

namespace fnv_00406db0 {
struct SL
{
    SL();
};
struct FUN_00406db0
{
    const char* f0;
    SL f4;
    FUN_00406db0();
};
}  // namespace fnv_00406db0

struct Flt
{
    operator unsigned int();
};
struct FUN_00408da0_Class
{
    int* __thiscall FUN_00408da0();
};

struct Inner0040e230
{
    void __thiscall FUN_0040e230(int, bool);
};
struct Outer00409100
{
    void __thiscall FUN_00409100(bool);
};

struct TESSound;
extern TESSound* DAT_011c3538;
extern TESSound* DAT_011c353c;
extern TESSound* DAT_011c3540;
extern TESSound* DAT_011c3544;
extern TESSound* DAT_011c3548;
extern TESSound* DAT_011c354c;

struct SettingBase_01012120
{
    float _04;
    const char* _08;
    virtual ~SettingBase_01012120();
    SettingBase_01012120* __thiscall FUN_0040e130(const char* a, float b);
};
extern int vftable_SettingBase_01012120;

struct FUN_0040e230_Class
{
    unsigned char bFlags;
    void __thiscall FUN_0040e230(unsigned int flags, bool set);
};

int __fastcall _FNV_GetFormType(void*);
struct Holder0040e9f0
{
    void* form;
    void* val;
    void* __thiscall GetValueIfFormType42();
};

struct Interface
{
    static void __cdecl PrintDebugMessage();
};
struct RecursiveSpinLock
{
    unsigned int* pCount;
    unsigned int count;
    void __thiscall FUN_0040fba0();
};

struct FUN_00413f60_Data
{
    int v[9];
};
struct FUN_00413f60_Holder
{
    char pad[0x1C];
    FUN_00413f60_Data data;
    FUN_00413f60_Data* __thiscall CopyData(FUN_00413f60_Data* dst);
};

template <int N> struct EndianSizeTag
{
};
void __cdecl BSEndian(unsigned char*, EndianSizeTag<0>);
void __cdecl BSEndian(unsigned char*, EndianSizeTag<10>);
struct FUN_004141e0_class
{
    void __thiscall FUN_004141e0();
};

extern int DAT_010151c0;
struct FUN_0041fcd0 : BE
{
    FUN_0041fcd0();
};

struct ScriptS
{
    void* GetHeader();
};

struct BGSDehydrationStage : ScriptS
{
    static BGSDehydrationStage** __cdecl AllocateStageArray(unsigned int count);
};

extern int _DAT_011c3180;
extern BGSDehydrationStage** _DAT_011c3184;

struct ListX
{
    int m1;
    ~ListX();
};
struct FUN_0040a1c0_Class
{
    int m0;
    ListX m1;
    ~FUN_0040a1c0_Class();
};

namespace fnv_00411ea0 {
int DAT_01014458;
struct BSExtraData
{
    virtual ~BSExtraData();
};
struct FUN_00411ea0 : BSExtraData
{
    ~FUN_00411ea0();
};
}  // namespace fnv_00411ea0

struct BaseExtraList_0041af50
{
    void __thiscall RemoveExtra(unsigned char);
    void __thiscall FUN_0041af50();
};

// FUN_00408b50 : a one-line function - globalvalue
extern int g_value_00408b50;

extern int DAT_01012238;
void __cdecl FUN_00aa10f0(void* p);

struct C405250Node
{
    C405250Node* next;
    void* payload;
};
struct FUN_00405310
{
    virtual ~FUN_00405310();
};
struct FUN_00405250 : public FUN_00405310
{
    unsigned int count;
    C405250Node** buckets;
    int reserved;
    unsigned char ownsData;
    virtual ~FUN_00405250();
};
// @fnv 0x00405250
FUN_00405250::~FUN_00405250()
{
    if (ownsData)
    {
        for (unsigned int uiIndex = 0; uiIndex < count; ++uiIndex)
        {
            C405250Node* node = buckets[uiIndex];
            while (node != 0)
            {
                C405250Node* current = node;
                node = node->next;
                FUN_00aa10f0(current->payload);
            }
        }
    }
}

struct Setting405c
{
    int FUN_00810fd0();
    bool HasFlag2();
    int FUN_00586150();
    bool FUN_00403e60(unsigned int uiFlag);
};

struct Item405c
{
    Setting405c* FUN_00825c00();
    int FUN_0084e3a0();
    int FUN_004044d0();
    int FUN_00404390();
};

struct ListNode405c
{
    Item405c* m_pkItem;
    ListNode405c* m_pkNext;
    Item405c** FUN_006815c0();
    ListNode405c* FUN_00726070();
};

struct ListBase405c
{
    void* m_pvVtbl;
};

struct EffectList405c : public ListBase405c, public ListNode405c
{
    float FUN_00405c00(int iArchetype, int m_eRange, int m_eAssociatedActorValue);
};

class TESForm
{
  public:
    virtual ~TESForm();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    void SetFormType(ENUM_FORM_ID eType);
};

template <> class BSSimpleList<TESForm*>
{
  public:
    TESForm* m_item;
    BSSimpleList<TESForm*>* m_pkNext;

    void FUN_004019f0();
};

class FUN_00483370
{
  public:
    FUN_00483370();
    virtual ~FUN_00483370();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class FUN_004010b0 : public FUN_00483370
{
  public:
    FUN_004010b0();
    virtual ~FUN_004010b0();

    void FUN_00401b20();

    BSSimpleList<TESForm*> m_kList;
};

template <class T> class SettingCollection
{
  public:
    virtual ~SettingCollection();
    char path[260];
    void* handle;
};
struct SettingMapNode;
// Representative of the native case-insensitive setting pointer map.
class SettingPointerMap
{
  public:
    virtual ~SettingPointerMap();
    unsigned int hashSize;
    SettingMapNode** hashTable;
    unsigned int count;
    void RemoveAll();
};
// Native SettingCollectionMap<Setting> destructor.
class FUN_00404c00 : public SettingCollection<Setting>
{
  public:
    SettingPointerMap settings;
    virtual ~FUN_00404c00();
};
// Destructor that calls RemoveAll on the settings map.
// @fnv 0x00404c00
FUN_00404c00::~FUN_00404c00()
{
    settings.RemoveAll();
}

namespace fnv_00405310 {
void __fastcall DeleteAllEntries(void* pkMap);

class FUN_00405370
{
  public:
    virtual ~FUN_00405370();
};

class FUN_00405310 : public FUN_00405370
{
  public:
    virtual ~FUN_00405310();
};

// Destructor that calls DeleteAllEntries with this.
// @fnv 0x00405310
FUN_00405310::~FUN_00405310()
{
    DeleteAllEntries(this);
}
}  // namespace fnv_00405310

struct EffectSetting4056
{
    unsigned int FUN_0084e3a0();
};

struct EffectItem4056
{
    EffectSetting4056* FUN_00825c00();
    void FUN_004040b0();
};

void __cdecl FUN_00485910(unsigned int uiType, unsigned int auiFormId);

struct EffectItemNode4056
{
    EffectItem4056* m_item;
    EffectItemNode4056* m_pkNext;

    EffectItem4056*& FUN_006815c0();
    EffectItemNode4056* FUN_00726070();
};

struct EffectItemListBase4056
{
    virtual ~EffectItemListBase4056();
};

struct EffectItemList4056 : public EffectItemListBase4056, public EffectItemNode4056
{
    void FUN_004056d0();
};

struct ItmQ
{
    int GetScriptFromEffectSetting();
    bool FUN_00405e40();
};
struct LstQ
{
    int unk00;
    bool FUN_008256d0();
    ItmQ** FUN_006815c0();
    LstQ* FUN_00726070();
};
struct BasQ
{
    int unk00;
};
struct NodQ : BasQ, LstQ
{
    bool FUN_00405e80(int iType);
};

class PathingSolution;

template <class T> class PathingRef
{
  public:
    void Reset(void* p);
};

class FUN_00633c90
{
  public:
    int unk00;
    FUN_00633c90(int flag);
    ~FUN_00633c90();
};

class FUN_0040ec80
{
  public:
    int unk04;
    int unk08;
    FUN_0040ec80(unsigned char flag);
    virtual ~FUN_0040ec80();
};

class FUN_0040ec00 : public FUN_0040ec80
{
  public:
    FUN_00633c90 m_ref;

    FUN_0040ec00();
    virtual ~FUN_0040ec00();
};

class TESFormV
{
  public:
    virtual ~TESFormV();
};
class TESObject : public TESFormV
{
};
class TESBoundObject : public TESObject
{
  public:
    int GetFormType() const;
};
class BaseFormComponent
{
  public:
    virtual ~BaseFormComponent();
};
class TESEnchantableForm : public BaseFormComponent
{
};
class TESBipedModelForm : public BaseFormComponent
{
  public:
    virtual ~TESBipedModelForm();  // polymorphic: its RTTI is used (rtti_fix.py)
  public:
    bool FUN_0047c850();
};
struct ItemExtraList
{
    bool FUN_00418b10();
};

struct StringMapDeletingEntry : FUN_00405230_Class
{
    void* __thiscall FUN_00405400(unsigned int flags);
};

struct AssociatedForm40df
{
    TESForm* __thiscall FUN_005f5f80();
};

struct FUN_00480ad0_shell
{
    bool __thiscall HasFlag(unsigned int);
};

// fallout/interface/menus/levelupmenu.cpp: Holder, LBItemListBox, LevelUpMenu, EffectSetting and more (3 functions)
#include "f3_common.h"
#include "levelupmenu_decls.h"

struct ActorValue
{
    static bool __cdecl GetFlag(int, unsigned int);
};
struct EffectSetting
{
    bool IsFlagSet(unsigned int);
    bool IsDetrimentalToActorValue(int av);
};

struct RecursiveLock;
struct Menu;
struct NiAVObject;
struct NiNode;
struct Tile;
struct TileShaderProperty;
struct MenuValueDescriptor;

struct ListBoxItemX
{
    Tile* tile;
    void* data;
};
struct LBNode
{
    ListBoxItemX** _ref_006815c0();
    LBNode* _ref_00726070();
};
struct LBList
{
    int pad;
    LBNode first;
    void* FindItemData(Tile* apTile);
};

struct FUN_00784b80_shell
{
    int __thiscall FUN_00784b80();
};

namespace fnv_007851d0 {
struct ActorValue
{
    enum Index
    {
    };
};
struct NiNodeBooleanState
{
    bool GetBooleanValue();
    void FUN_008d5270();
};
struct Actor
{
    void ConfigureActorState(bool, bool);
};
struct Tile
{
    void Set(int, int);
};
struct ListBox_enum_ActorValue__Index_
{
    void Traverse(void(__cdecl*)(Tile*, ActorValue::Index), int, int);
};
struct StatsMenu
{
    static void __cdecl UpdateStatusEffects();
};
struct PC7d
{
    NiNodeBooleanState* FUN_00464e10();
    void ConfigureActorState(bool, bool);
};
extern PC7d* g_thePlayer;
extern int DAT_011d9fdc;
extern "C" void __cdecl UpdateStatsMenuLevelText();
void __cdecl FUN_0077da30();
void __cdecl FUN_008d5270();
void __cdecl FUN_00786570(Tile*, ActorValue::Index);
struct LevelUpMenuShell
{
    Tile* _ref_00726070();
    void LoadMenuData();
};

}  // namespace fnv_007851d0

extern int DAT_011d9fdc;

struct FUN_007866e0_shell
{
    void UpdateDisplayValue(const char*);
};

struct FUN_00784b90_shell
{
    void SetTileByID(int aiID, void* apTile);
};

struct S
{
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual int f(int);
    int FUN_0071ae60(int);
    int FUN_007315b0();
};

struct FUN_00784bc0_shell
{
    void FUN_00784bf0();
    void* FUN_00784bc0(unsigned int);
};
void _Deallocate(void*);

struct TESObjectREFR
{
};
struct PerkEntryConditionSet
{
    bool ContainsTrait(TESObjectREFR*, TESObjectREFR*, bool&, bool);
};
struct FUN_00785150_This
{
    bool FUN_00785150(TESObjectREFR*);
};

struct FUN_00785190_This
{
    int _pad[11];
    int vals[10];
    bool HasAllValsNonZero();
};

struct Tile
{
    bool ContainsTrait(int);
    void Set(int, int);
};
struct Holder
{
    void UpdateTileEffects(Tile*);
};
extern int DAT_011d9fdc;
extern int DAT_011d9fe0;
// If the tile reports the state stored in DAT_011d9fe0, clears that state via Set and notifies the holder at DAT_011d9fdc.
// @f3 0x0048bad0 (community match, verified in this file)
struct A1450MemoryManager { void Deallocate(void*); };
extern A1450MemoryManager DAT_011f6238;
struct Cls_0048bad0 {
    int unk00, unk04;
    void** ptr08;
    void* ptr0c;
    void FUN_0048bad0();
};
void Cls_0048bad0::FUN_0048bad0() {
    DAT_011f6238.Deallocate(*ptr08);
    DAT_011f6238.Deallocate(ptr08);
    DAT_011f6238.Deallocate(ptr0c);
}


namespace fnv_00786570 {
struct BGSPerk;
struct Tile
{
    bool ContainsTrait(int);
};
extern int DAT_011d9fe0;
template <int N> struct Pad;
template <> struct Pad<1>
{
    virtual void F(int (*)[1]);
};
template <int N> struct Pad : Pad<N - 1>
{
    virtual void F(int (*)[N]);
};
struct PC7d : Pad<294>
{
    virtual void Func498(BGSPerk*, int);
    virtual void Filler();
    virtual bool Func4A0(BGSPerk*, int, int);
};
extern PC7d* g_thePlayer;
}  // namespace fnv_00786570

namespace fnv_007871c0 {
struct WeatherEntry;
struct BSSimpleList
{
    void Sort(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
};
struct Holder
{
    char _0[4];
    BSSimpleList _4;
    void SortWeatherEntries(int(__cdecl*)(WeatherEntry*, WeatherEntry*));
    void ResetAndProcessTiles();
};
}  // namespace fnv_007871c0

struct Unk_7879c0
{
    void FUN_00786c80();
    void* FUN_007879c0(unsigned int);
};

namespace fnv_007864e0 {
struct TESObjectREFR;
struct PC7d;
struct FUN_006aabf0_shell
{
    signed char GetByteAt39();
};
struct FUN_00785150_This
{
    bool FUN_00785150(TESObjectREFR*);
};
struct Actor
{
    unsigned short GetLevel();
};
struct Tile
{
    void Set(int, float, bool);
};
extern int DAT_011d9ff4;
extern PC7d* g_thePlayer;
}  // namespace fnv_007864e0

struct FUN_00787760_shell
{
    void SetTileSelection(int, int);
    void FUN_00787760(int a);
};

struct FUN_00787c40_shell
{
    void SetTileSelection(int a1, int a2);
    void FUN_00787780(int arg);
};

struct FUN_00787c20_shell
{
    void __thiscall SetTileSelection(unsigned int a, int b);
    void __thiscall FUN_00787c20(unsigned int a);
};

namespace fnv_00786110 {
struct Tile
{
    bool ContainsTrait(int);
};
struct Interface
{
    static void __cdecl PlayUISound(int);
};
struct FakeMenu
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, int);
    char _pad[0x44];
    Tile* mTile;
    bool HandleButton(int aiButton, float afValue);
};
}  // namespace fnv_00786110

struct CombatMember_1024
{
    int a;
    int b;
    int c;
    int d;
    int e;
};

struct BSSimpleArray_CombatMember_1024
{
    int mSize;
    CombatMember_1024* mBase;
    unsigned int FUN_007881d0();
    void ConstructElems(CombatMember_1024*, int);
};

struct FUN_00787950_shell : BSSimpleArray_CombatMember_1024
{
    int AppendMember(CombatMember_1024* apSrc);
};

struct TGF
{
    float GetFloat(int);
};
struct VATSMenu
{
    int GetSelectedTargetIndex();
};
int __cdecl GetTileValueID(const char*, int);
struct FUN_007879f0
{
    int GetIntegerResult();
};

namespace fnv_00785990 {
struct GlobalObject_0040c150;

extern GlobalObject_0040c150 g_011d1d48;
extern GlobalObject_0040c150 g_011d2a00;
extern GlobalObject_0040c150 g_011d2a24;
extern GlobalObject_0040c150 g_011d2e74;

struct StartMenu
{
    char const* GetMenuTitle();
};

struct Tile
{
    void Set(int, int);
    void Set(int, char const*, bool);
};

struct FUN_00785990_shell
{
    unsigned char pad00[0x28];
    int iValue;
    unsigned char pad2C[0x14];
    Tile* tile;
    unsigned char pad44[0x10];
    int m_iPointsUsed[2];
    int m_iPointsRemaining[2];

    void FUN_00785990();
};

int __cdecl _sprintf_s(char*, unsigned int, char const*, ...);

}  // namespace fnv_00785990

namespace fnv_007865d0 {
class FUN_006aabf0_shell
{
  public:
    unsigned char GetByteAt39(void);
};

class TGF
{
  public:
    float GetFloat(int);
};

class Tile : public TGF
{
  public:
    char const* GetString(int);
};

class BGSPerk : public Tile
{
};

template <class T> class ListBoxItem
{
  public:
    T m_pInventoryEntryData;
    FUN_006aabf0_shell* m_pShell;
};

extern int DAT_011d9ff4;

int __cdecl FUN_00408b20(char const*, char const*);

}  // namespace fnv_007865d0

namespace fnv_007866e0 {
struct TGF
{
    float GetFloat(int);
};

struct Tile : public TGF
{
    void Set(int, char const*, bool);
};

int __cdecl _sprintf_s(char*, unsigned int, char const*, ...);
int __cdecl MinInt(int, int);
int __cdecl FUN_00647b70(int, int);
int GetTileValueID(char const*, int);

extern int DAT_011d9fe4;
extern int DAT_011d9fec;
extern int DAT_011d9ff0;
extern char const str_01020764[];
extern char const str_01073e14[];

struct FUN_007866e0_shell
{
    void UpdateDisplayValue(Tile* apTile);
};

}  // namespace fnv_007866e0

// FUN_00786bb0 : constructor of a polymorphic object. It constructs the base,
// constructs the sub-object at +4, installs its own vtable, zeroes a set of
// members and two words, clears three floats, runs two setup calls and
// returns this.

struct ObjBase
{
    ObjBase();
    virtual void v00();
};

struct ObjSub
{
    ObjSub();
    ~ObjSub();
    int m_i00;
    int m_i04;
};

void __cdecl AddToHeadList(void* p);

struct FUN_00786bb0 : public ObjBase, public ObjSub
{
    int m_i0c;
    int m_i10;
    int m_i14;
    int m_i18;
    unsigned short m_w1c;
    float m_f20;
    float m_f24;
    float m_f28;
    unsigned short m_w2c;

    FUN_00786bb0();
    void FUN_007a1950(int a, int b);
};

extern int DAT_01071b64;
void* __cdecl FUN_00a00940(const void* data, int flags);
struct LevelOption
{
    bool __thiscall IsTraitNonZero(void* data);
};
struct FUN_007877a0_Object
{
    bool FUN_007877a0(LevelOption* option);
};

struct LevelValue
{
    float __thiscall FUN_00a011b0(unsigned int property);
    void __thiscall FUN_00a012d0(int property, float value, int doUpdate);
    void __thiscall FUN_00700320(int property, int value);
};
struct FUN_007879f0_helper
{
    unsigned int __thiscall FUN_007879f0();
};
extern const double DAT_01012060;
extern char str_0106f90c[];
extern char str_0106f8f8[];
extern "C" int __cdecl FUN_00a01860(const char*);
extern "C" float __cdecl FUN_004e4430(float);
extern "C" int __cdecl FUN_00647b70(int, int);
struct LevelMenuView
{
    int unk00;
    int unk04;
    int unk08;
    LevelValue* meter0c;
    int unk10;
    LevelValue* count14;
    int unk18;
    int unk1c;
    float maximum20;
    void __thiscall FUN_007880a0();
};

struct ViewTile
{
    void Set(int, const char*, bool);
    void Set(int, int);
    const char* GetString(int);
    ViewTile* Parent();
};
struct ItemName
{
    const char* GetFullName();
};
struct MenuItem
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
    ItemName name;
    void Describe(char*, unsigned int);
};
struct SkillList
{
    virtual void Select(ViewTile*);
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
    unsigned int Lookup(ViewTile*);
};
const char* SkillName(unsigned int);
const char* SkillDescription(unsigned int);
unsigned int SkillExtra(unsigned int);
void Notify(int);
unsigned int BSStringLength(const char*);
struct LevelView
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void Hover(int, ViewTile*);
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
    ViewTile* tile38;
    ViewTile* tile3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    ViewTile* tile50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    SkillList skills;
    SkillList perks;
    void FUN_00785280(int, ViewTile*);
};

namespace fnv_00785540 {
struct SkillTile
{
    void SetName(const char*);
    void FUN_00700320(int, int);
    void FUN_00a012d0(int, float, int);
};
struct SkillList
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void Sort(void(__cdecl*)());
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
    void FUN_0075a0d0(Tile*, const char*);
    SkillTile* AddListEntry(int, const char*, int, int);
    SkillTile* AddItemTile(void*, const char*, int, int);
};
struct ActorValues
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual int GetValue(int);
};
struct Perk;
struct PlayerSkills
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot00a();
    virtual void slot00b();
    virtual void slot00c();
    virtual void slot00d();
    virtual void slot00e();
    virtual void slot00f();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot01a();
    virtual void slot01b();
    virtual void slot01c();
    virtual void slot01d();
    virtual void slot01e();
    virtual void slot01f();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot02a();
    virtual void slot02b();
    virtual void slot02c();
    virtual void slot02d();
    virtual void slot02e();
    virtual void slot02f();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot03a();
    virtual void slot03b();
    virtual void slot03c();
    virtual void slot03d();
    virtual void slot03e();
    virtual void slot03f();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot04a();
    virtual void slot04b();
    virtual void slot04c();
    virtual void slot04d();
    virtual void slot04e();
    virtual void slot04f();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot05a();
    virtual void slot05b();
    virtual void slot05c();
    virtual void slot05d();
    virtual void slot05e();
    virtual void slot05f();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot06a();
    virtual void slot06b();
    virtual void slot06c();
    virtual void slot06d();
    virtual void slot06e();
    virtual void slot06f();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual void slot076();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot07a();
    virtual void slot07b();
    virtual void slot07c();
    virtual void slot07d();
    virtual void slot07e();
    virtual void slot07f();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot08a();
    virtual void slot08b();
    virtual void slot08c();
    virtual void slot08d();
    virtual void slot08e();
    virtual void slot08f();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
    virtual void slot09a();
    virtual void slot09b();
    virtual void slot09c();
    virtual void slot09d();
    virtual void slot09e();
    virtual void slot09f();
    virtual void slot0a0();
    virtual void slot0a1();
    virtual void slot0a2();
    virtual void slot0a3();
    virtual void slot0a4();
    virtual void slot0a5();
    virtual void slot0a6();
    virtual void slot0a7();
    virtual void slot0a8();
    virtual void slot0a9();
    virtual void slot0aa();
    virtual void slot0ab();
    virtual void slot0ac();
    virtual void slot0ad();
    virtual void slot0ae();
    virtual void slot0af();
    virtual void slot0b0();
    virtual void slot0b1();
    virtual void slot0b2();
    virtual void slot0b3();
    virtual void slot0b4();
    virtual void slot0b5();
    virtual void slot0b6();
    virtual void slot0b7();
    virtual void slot0b8();
    virtual void slot0b9();
    virtual void slot0ba();
    virtual void slot0bb();
    virtual void slot0bc();
    virtual void slot0bd();
    virtual void slot0be();
    virtual void slot0bf();
    virtual void slot0c0();
    virtual void slot0c1();
    virtual void slot0c2();
    virtual void slot0c3();
    virtual void slot0c4();
    virtual void slot0c5();
    virtual void slot0c6();
    virtual void slot0c7();
    virtual void slot0c8();
    virtual void slot0c9();
    virtual void slot0ca();
    virtual void slot0cb();
    virtual void slot0cc();
    virtual void slot0cd();
    virtual void slot0ce();
    virtual void slot0cf();
    virtual void slot0d0();
    virtual void slot0d1();
    virtual void slot0d2();
    virtual void slot0d3();
    virtual void slot0d4();
    virtual void slot0d5();
    virtual void slot0d6();
    virtual void slot0d7();
    virtual void slot0d8();
    virtual void slot0d9();
    virtual void slot0da();
    virtual void slot0db();
    virtual void slot0dc();
    virtual void slot0dd();
    virtual void slot0de();
    virtual void slot0df();
    virtual void slot0e0();
    virtual void slot0e1();
    virtual void slot0e2();
    virtual void slot0e3();
    virtual void slot0e4();
    virtual void slot0e5();
    virtual void slot0e6();
    virtual void slot0e7();
    virtual void slot0e8();
    virtual void slot0e9();
    virtual void slot0ea();
    virtual void slot0eb();
    virtual void slot0ec();
    virtual void slot0ed();
    virtual void slot0ee();
    virtual void slot0ef();
    virtual void slot0f0();
    virtual void slot0f1();
    virtual void slot0f2();
    virtual void slot0f3();
    virtual void slot0f4();
    virtual void slot0f5();
    virtual void slot0f6();
    virtual void slot0f7();
    virtual void slot0f8();
    virtual void slot0f9();
    virtual void slot0fa();
    virtual void slot0fb();
    virtual void slot0fc();
    virtual void slot0fd();
    virtual void slot0fe();
    virtual void slot0ff();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot10a();
    virtual void slot10b();
    virtual void slot10c();
    virtual void slot10d();
    virtual void slot10e();
    virtual void slot10f();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot11a();
    virtual void slot11b();
    virtual void slot11c();
    virtual void slot11d();
    virtual void slot11e();
    virtual void slot11f();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual unsigned char GetPerkRank(void*, int);
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
    ActorValues values;
};
struct PerkName
{
    const char* FUN_00408da0();
};
struct Perk
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    PerkName name;
    unsigned char FUN_005d4ee0();
};
struct FallbackSetting
{
    const char* FUN_00403df0();
};
extern FallbackSetting DAT_011d35b8;
extern PlayerSkills* DAT_011dea3c;
extern int DAT_011d9ff0, DAT_011d9fe4, DAT_011d9ff8;
extern const char str_01073dcc[], str_01073db8[], str_0106eb00[];
unsigned int FUN_0066ecf0(int);
int FUN_0066ec10(int, unsigned char);
const char* FUN_0066e950(int);
void CompareActorValueNames();
int MinInt(int, int);
bool FUN_00406d70(int, unsigned int);
int strcpy_s(char*, unsigned int, const char*);
int FUN_00406d00(char*, unsigned int, const char*, ...);
unsigned int FUN_0044a670(const char*);
struct SkillsMenu
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
    Tile* skillRoot;
    Tile* perkRoot;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int points;
    int unk60;
    SkillList skills;
    SkillList perks;
    LBNode availablePerks;
    void UpdateSkillsAndPerks();
};
}  // namespace fnv_00785540

int FUN_00a01860(const char*);
void UpdateLevelUpMenu();
void FUN_007864e0(const char*);
void ComparePerkListItems(const char*);
extern int DAT_011d9fe8;
extern int DAT_011d9fd8;
extern int DAT_011d9fd4;
struct RootTile
{
    double FUN_00a011b0(int);
    void Set(int, int);
};
struct OptionList
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void Apply(void (*)(const char*));
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
    void FUN_007314c0(void (*)(const char*), int, int);
    void FUN_007312e0();
    void FUN_00786a50(bool);
    void UpdateScrollTile(bool);
};
struct Target
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
    int first[2];
    int second[2];
    OptionList listA, listB;
    RootTile* FUN_00726070();
    void FUN_00785990();
    void SetPage(int);
};

struct VT_b9166
{
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229(int a, float b);
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual double v291(int a, bool& flag);
};
extern int DAT_011dea3c;
extern int DAT_011d9ff0;
struct FUN_00a011b0_cls
{
    double FUN_00a011b0(int);
    void FUN_00a012d0(int, float, int);
};

struct EffectItem
{
    int FUN_00403ea0();
    int GetMagnitude();
    EffectSetting* GetEffectSetting();
};

struct ContObj
{
    int c00;
    int c04;
    int c08;
    int c0c;
    int c10;
    int c14;
    int c18;
    int c1c;
    int c20;
    int c24;
    LBNode node;
};

struct NodeSrc
{
    virtual void ReleaseA();
    virtual void ReleaseB();
    virtual void ReleaseC();
    virtual void ReleaseD();
    virtual int CheckType();
    NodeSrc* FindEntryByLevel(int lvl);
    ContObj* FUN_0044ddc0();
};

struct EffRec
{
    int mag;
    int f04;
    int f08;
    int f0c;
    void FUN_00403ba0();
};

struct GlobalObj
{
    void FUN_008454f0(bool clear);
    void AppendMember(EffRec* rec);
};

struct TravObj
{
    int t00;
    int t04;
    int t08;
    int t0c;
    int t10;
    int t14;
    int t18;
    int t1c;
    int t20;
    int t24;
    int t28;
    int t2c;
    void FUN_007314c0(void (*cb)(Tile*, int), int a, int b);
};

struct HolderThis
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    TravObj trav;
    LBList list;
};

extern int DAT_011d9ff8;
extern GlobalObj DAT_011da050;

void FUN_00786240(Tile* tile, int idx);

// Destructor: clear the model list, unregister from the global tracker, then the list member is destroyed.

class C6C80List
{
  public:
    ~C6C80List();

    void* m_pkHead;
    void* m_pkTail;
};

class FUN_00786c80;
void __cdecl C6C80Unregister(FUN_00786c80* pkObject);

class FUN_00786c80
{
  public:
    virtual ~FUN_00786c80();
    void Clear();

    C6C80List m_kModels;
};

// Clears the object's model list, then unregisters the object from the C6C80 registry.
// @fnv 0x00786c80
FUN_00786c80::~FUN_00786c80()
{
    Clear();
    C6C80Unregister(this);
}

struct LBTile;
struct LBMenu
{
    LBTile* AddTileFromTemplate(LBTile* parent, const char* templ, int unk);
};
struct LBValue
{
    void ResetOps();
    void AddOp(int op, LBTile* src, int traitID);
    void AddFloatOp(int op, float val);
    void Finish(bool b);
};
struct LBTile
{
    LBMenu* GetMenu();
    void* GetValue(int traitID);
    void Set(int traitID, int val);
    void SetString(int traitID, const char* str, bool propagate);
    float GetFloat(int traitID);
    LBValue* GetActionValue(int traitID);
    static int __cdecl TraitNameToID(const char* name, int unk);
};
struct LBItem
{
    LBItem(LBTile* tile, int* item);
    LBTile* tile;
    int item;
    bool filtered;
};
struct LBItemList
{
    LBItem* data;
    LBItemList* next;
    void Insert(LBItem* item, int (*sortFunc)(LBItem*, LBItem*));
    void AddTail(LBItem* const& item);
};
struct LBItemListBox
{
    int unk00;
    LBItemList list;
    LBTile* parentTile;
    int unk10;
    int unk14;
    const char* templateName;
    unsigned short itemCount;
    bool FUN_007242c0(unsigned int a);
    void Sort();
    void AccumulateTileHeight(LBTile* tile);
    void FUN_007880a0();
    int GetNumVisible();
    LBTile* AddItemTile(int item, const char* text, int (*sortFunc)(LBItem*, LBItem*), const char* templ);
};

namespace fnv_00786f90 {
extern bool s_bAllowDetach;

struct LBTile
{
    virtual ~LBTile();
    void Set(int aiID, float afValue, bool abPropagate);
};

struct LBObject
{
    ~LBObject();
};

struct LBItem
{
    LBTile* pTile;
    LBObject* pObject;
};

struct LBListNode
{
    LBItem* pItem;
    LBListNode* pNext;

    ~LBListNode();
    LBItem** GetItem();
    LBListNode* GetNext();
    void SetItem(unsigned int auiItem);
};

struct LBListBox
{
    void* pVtable;
    LBItem* pHeadItem;
    LBListNode* pHeadNext;
    LBTile* m_pHighlightedTile;
    int iUnk10;
    int iUnk14;
    int iUnk18;
    unsigned short usUnk1C;
    float fScroll;

    bool FUN_007242c0(unsigned int auiFlag);
    void FUN_007880a0();
    void UpdateHighlight();
    void ClearItems();
};

}  // namespace fnv_00786f90

int __cdecl FUN_00a00940(const char* pcName, int iDefault);

class Tile787
{
  public:
    bool GetBool(int m_iValueId);
};

class ListBox787
{
  public:
    bool IsActive();
    bool Contains(Tile787* pkTile);
    void UpdateSelection();
    bool SelectTile(Tile787* pkTile);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    Tile787* m_pkSelected;
};

class Tile;
class Menu;
struct InterfaceManager;
int FUN_00a01860(const char* apName);
float FUN_0040ebd0(float afA, float afB);
InterfaceManager* FUN_004b7210();
bool FUN_004b71d0();
struct IMStandIn
{
    void FUN_00715860(int aiA, int aiB, int aiC);
};
struct FUN_00a012d0_t
{
    void FUN_00a012d0(int aiTrait, float afValue, bool abFlag);
};
struct FUN_00a01290_shell
{
    void SetTraitAndReset(int aiTrait, float afValue);
};
struct FUN_00a03d40_shell
{
    Tile* FUN_00a03d40();
};
struct FUN_00a03c90_shell
{
    Menu* FUN_00a03c90();
};
struct FUN_00787600_Tile
{
    float FUN_00a011b0(int aiTrait);
};
struct FUN_00787600_MenuVT
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05(int aiValue, FUN_00787600_Tile* apTile);
};
struct FUN_00787600_shell
{
    virtual void Unk_00(FUN_00787600_Tile* apTile);
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual FUN_00787600_Tile* Unk_05(unsigned int auiIndex);
    char pad04[8];
    FUN_00a03d40_shell* m_pFourthMenuObject;
    int iPad10;
    FUN_00a012d0_t* pScrollTile;
    char pad18[0xc];
    float fScrollPos;
    float fValue;
    unsigned int FUN_007879f0(int aiArg);
    void UpdateScrollTile(bool abFlag);
};

struct FUN_00787850_item
{
    Tile* tile;
    void* data;
    unsigned char flag8;
};

class FUN_00787850_cls
{
  public:
    int pad;
    LBNode first;
    void FUN_00787850(unsigned char flag);
};

struct ListItem787aa0
{
    Tile* tile;
    void* data;
    unsigned char unk08;
};

struct TileCallees787aa0
{
    void FUN_00700320(int a, int b);
};

struct Callees787aa0
{
    void AccumulateTileHeight(Tile* t);
    void FUN_007880a0();
    void UpdateHighlight();
};

struct FUN_00787aa0_cls : Callees787aa0
{
    int unk00;
    LBNode first;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_1c;
    float m_20;

    void ResetAndProcessTiles();
};

int __cdecl TraitNameToID(const char* name, int unk);
extern int DAT_011d9fe4;
extern int DAT_011d9fec;
extern int DAT_011d9ff0;
extern int DAT_011d9fe8;
extern int DAT_011d9fd8;
extern int DAT_011d9fd4;
extern int DAT_011d9ff8;
extern int DAT_011d9fe0;
extern int DAT_011d9ff4;
struct Menu
{
    Menu();
    virtual ~Menu();
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
};
struct Member64
{
    Member64();
    ~Member64();
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
};
struct Member94
{
    Member94();
    ~Member94();
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
};
template <class T> struct BSSimpleList
{
    T item;
    BSSimpleList* next;
    BSSimpleList();
    ~BSSimpleList();
};
struct FUN_00784a40 : Menu
{
    Member64 unk64;
    Member94 unk94;
    BSSimpleList<void*> unkC4;
    FUN_00784a40();
    virtual ~FUN_00784a40();
};

class GlobalObject_009c6a30;
extern GlobalObject_009c6a30 g_011f2250;

struct FUN_00525430_Class
{
    bool FUN_00525430();
};
struct BSSoundHandleEx
{
    int unk00;
    int unk04;
    int unk08;
    ~BSSoundHandleEx();
    bool Play(bool);
};
struct BSAudio
{
    BSSoundHandleEx GetSoundHandleByEditorID(const char* name, unsigned int flags);
};
struct FUN_00a1dc20_Obj
{
    void FUN_00a1dc20(int a1);
};

BSAudio* __cdecl FUN_00453a70(void);
bool __cdecl IsStartMenuFlag1Set(void);

struct LevelUpMenuStand
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
    void PlayLevelUpSuccessSound();
};

struct FUN_00787b70_inner
{
    bool IsTraitNonZero(void* apKey);
};

struct FUN_00787b70_cls
{
    int m_00;
    int m_04;
    int m_08;
    FUN_00787b70_inner* m_0c;
    bool FUN_00787b70();
};

int __cdecl FUN_00a00940(const char* s, int n);

struct TileStandIn
{
    TileStandIn* fn_45cd60();
    float fn_a011b0(int k);
    bool fn_a01230(int k);
    void fn_a012d0(int k, float v, bool b);
    void fn_700320(int k, int v);
};

struct ListBox64
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
    int fn_7e1110(TileStandIn* t);
    void fn_7314c0(void(__cdecl* cb)(TileStandIn*), int a, int b);
};

struct ListBox94
{
    int unk00;
    bool fn_7877a0(TileStandIn* t);
    void fn_787780(TileStandIn* t);
    void fn_787850(bool b);
    void fn_787760(TileStandIn* t);
    int fn_7878d0();
    void fn_7314c0(void(__cdecl* cb)(TileStandIn*), int a, int b);
};

struct ClassStandIn
{
    bool fn_5a5f40(int av);
};

struct SettingStandIn
{
    int* fn_43d4d0();
};

struct PlayerStandIn
{
    virtual void vf000();
    virtual void vf001();
    virtual void vf002();
    virtual void vf003();
    virtual void vf004();
    virtual void vf005();
    virtual void vf006();
    virtual void vf007();
    virtual void vf008();
    virtual void vf009();
    virtual void vf010();
    virtual void vf011();
    virtual void vf012();
    virtual void vf013();
    virtual void vf014();
    virtual void vf015();
    virtual void vf016();
    virtual void vf017();
    virtual void vf018();
    virtual void vf019();
    virtual void vf020();
    virtual void vf021();
    virtual void vf022();
    virtual void vf023();
    virtual void vf024();
    virtual void vf025();
    virtual void vf026();
    virtual void vf027();
    virtual void vf028();
    virtual void vf029();
    virtual void vf030();
    virtual void vf031();
    virtual void vf032();
    virtual void vf033();
    virtual void vf034();
    virtual void vf035();
    virtual void vf036();
    virtual void vf037();
    virtual void vf038();
    virtual void vf039();
    virtual void vf040();
    virtual void vf041();
    virtual void vf042();
    virtual void vf043();
    virtual void vf044();
    virtual void vf045();
    virtual void vf046();
    virtual void vf047();
    virtual void vf048();
    virtual void vf049();
    virtual void vf050();
    virtual void vf051();
    virtual void vf052();
    virtual void vf053();
    virtual void vf054();
    virtual void vf055();
    virtual void vf056();
    virtual void vf057();
    virtual void vf058();
    virtual void vf059();
    virtual void vf060();
    virtual void vf061();
    virtual void vf062();
    virtual void vf063();
    virtual void vf064();
    virtual void vf065();
    virtual void vf066();
    virtual void vf067();
    virtual void vf068();
    virtual void vf069();
    virtual void vf070();
    virtual void vf071();
    virtual void vf072();
    virtual void vf073();
    virtual void vf074();
    virtual void vf075();
    virtual void vf076();
    virtual void vf077();
    virtual void vf078();
    virtual void vf079();
    virtual void vf080();
    virtual void vf081();
    virtual void vf082();
    virtual void vf083();
    virtual void vf084();
    virtual void vf085();
    virtual void vf086();
    virtual void vf087();
    virtual void vf088();
    virtual void vf089();
    virtual void vf090();
    virtual void vf091();
    virtual void vf092();
    virtual void vf093();
    virtual void vf094();
    virtual void vf095();
    virtual void vf096();
    virtual void vf097();
    virtual void vf098();
    virtual void vf099();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual void vf125();
    virtual void vf126();
    virtual void vf127();
    virtual void vf128();
    virtual void vf129();
    virtual void vf130();
    virtual void vf131();
    virtual void vf132();
    virtual void vf133();
    virtual void vf134();
    virtual void vf135();
    virtual void vf136();
    virtual void vf137();
    virtual void vf138();
    virtual void vf139();
    virtual void vf140();
    virtual void vf141();
    virtual void vf142();
    virtual void vf143();
    virtual void vf144();
    virtual void vf145();
    virtual void vf146();
    virtual void vf147();
    virtual void vf148();
    virtual void vf149();
    virtual void vf150();
    virtual void vf151();
    virtual void vf152();
    virtual void vf153();
    virtual void vf154();
    virtual void vf155();
    virtual void vf156();
    virtual void vf157();
    virtual void vf158();
    virtual void vf159();
    virtual void vf160();
    virtual void vf161();
    virtual void vf162();
    virtual void vf163();
    virtual void vf164();
    virtual void vf165();
    virtual void vf166();
    virtual void vf167();
    virtual void vf168();
    virtual void vf169();
    virtual void vf170();
    virtual void vf171();
    virtual void vf172();
    virtual void vf173();
    virtual void vf174();
    virtual void vf175();
    virtual void vf176();
    virtual void vf177();
    virtual void vf178();
    virtual void vf179();
    virtual void vf180();
    virtual void vf181();
    virtual void vf182();
    virtual void vf183();
    virtual void vf184();
    virtual void vf185();
    virtual void vf186();
    virtual void vf187();
    virtual void vf188();
    virtual void vf189();
    virtual void vf190();
    virtual void vf191();
    virtual void vf192();
    virtual void vf193();
    virtual void vf194();
    virtual void vf195();
    virtual void vf196();
    virtual void vf197();
    virtual void vf198();
    virtual void vf199();
    virtual void vf200();
    virtual void vf201();
    virtual void vf202();
    virtual void vf203();
    virtual void vf204();
    virtual void vf205();
    virtual void vf206();
    virtual void vf207();
    virtual void vf208();
    virtual void vf209();
    virtual void vf210();
    virtual void vf211();
    virtual void vf212();
    virtual void vf213();
    virtual void vf214();
    virtual void vf215();
    virtual void vf216();
    virtual void vf217();
    virtual void vf218();
    virtual void vf219();
    virtual void vf220();
    virtual void vf221();
    virtual void vf222();
    virtual void vf223();
    virtual void vf224();
    virtual void vf225();
    virtual void vf226();
    virtual void vf227();
    virtual void vf228();
    virtual void vf229(int av, float val);
    virtual void vf230();
    virtual void vf231();
    virtual void vf232();
    virtual void vf233();
    virtual void vf234();
    virtual void vf235();
    virtual void vf236();
    virtual void vf237();
    virtual void vf238();
    virtual void vf239();
    virtual void vf240();
    virtual void vf241();
    virtual void vf242();
    virtual void vf243();
    virtual void vf244();
    virtual void vf245();
    virtual void vf246();
    virtual void vf247();
    virtual void vf248();
    virtual void vf249();
    virtual void vf250();
    virtual void vf251();
    virtual void vf252();
    virtual void vf253();
    virtual void vf254();
    virtual void vf255();
    virtual void vf256();
    virtual void vf257();
    virtual void vf258();
    virtual void vf259();
    virtual void vf260();
    virtual void vf261();
    virtual void vf262();
    virtual void vf263();
    virtual void vf264();
    virtual void vf265();
    virtual void vf266();
    virtual void vf267();
    virtual void vf268();
    virtual void vf269();
    virtual void vf270();
    virtual void vf271();
    virtual void vf272();
    virtual void vf273();
    virtual void vf274();
    virtual void vf275();
    virtual void vf276();
    virtual void vf277();
    virtual void vf278();
    virtual void vf279();
    virtual void vf280();
    virtual void vf281();
    virtual void vf282();
    virtual void vf283();
    virtual void vf284();
    virtual void vf285();
    virtual void vf286();
    virtual void vf287();
    virtual void vf288();
    virtual void vf289();
    virtual void vf290();
    virtual float vf291(int av, bool* out);

    ClassStandIn* fn_884350();
};

extern int g_11d9ff4;
extern int g_11d9fd8;
extern int g_11d9ff0;
extern PlayerStandIn* g_11dea3c;
extern SettingStandIn g_11cd6c0;

void __cdecl fn_706f30(int a);
void __cdecl fn_786170(TileStandIn* t);
void __cdecl fn_786200(TileStandIn* t);

struct MenuStandIn
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
    TileStandIn* unk48;
    TileStandIn* unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    ListBox64 unk64;
    ListBox94 unk94;

    void fn_7867a0(TileStandIn* t);
    TileStandIn* fn_726070();
    void fn_785990();
    void fn_7866e0(TileStandIn* t);
    void fn_785830(int page);
    void OnButtonPressed(int btn, TileStandIn* tile);
};

struct ScrollTile;

struct ScrollMenuObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void SetValue(int aiValue, ScrollTile* apTile);
};

struct ScrollTile
{
    void SetFloat(int aiID, float afValue, bool abPropagate);
    void SetFloatNoProp(int aiID, float afValue);
    float GetFloat(unsigned int aiID);
    ScrollTile* GetParentTile();
    ScrollMenuObj* GetParentMenu();
};

struct ScrollIM
{
    void PlayScroll(ScrollTile* apTile, int aiType, bool abSound);
};
ScrollIM* GetScrollIM();
bool IsScrollBlocked();
float ScrollMin(float a, float b);

struct ScrollBar
{
    virtual void Update(ScrollTile* apTile);
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual ScrollTile* GetItemTile(int aiIndex);

    int unk04;
    int unk08;
    ScrollTile* parent0c;
    int unk10;
    ScrollTile* tile14;
    int unk18;
    int unk1c;
    float unk20;
    float maxValue24;
    float currentValue28;

    unsigned int GetCount(int aiArg);
    void FUN_00786a50(bool abSound);
};

namespace fnv_00787260 {
struct LBTile
{
    double FUN_00a011b0(int traitID);
    bool IsTraitNonZero(int traitID);
};
int __cdecl FUN_00a01860(const char* name);
int __cdecl FUN_00a00940(const char* name, int fallback);
float __cdecl FUN_004bd510(float value, float step);

struct LBItem
{
    LBTile* tile;
    int item;
    bool filtered;
};
struct LBItemList
{
    LBItem* data;
    LBItemList* next;
    LBItemList* FUN_00726070();
    LBItem** FUN_006815c0();
};
struct LBIndex
{
    unsigned int value;
};
struct LBItemListBox : LBItemList
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual LBTile* GetItemTile(unsigned int index, bool option);
    LBTile* parentTile;
    LBTile* selectedTile;
    int unk14;
    const char* templateName;
    unsigned short itemCount;
    bool FUN_00787b70();
    LBTile* FUN_00787260(int key);
};

}  // namespace fnv_00787260

struct ListItem_007878d0
{
    int iKey;
};

struct ListNode_007878d0
{
    ListItem_007878d0* m_item;
    ListNode_007878d0* m_pkNext;
    ListItem_007878d0*& FUN_006815c0();
    ListNode_007878d0* FUN_00726070();
};

struct Base_007878d0
{
    int unk00;
};

struct Counter_007878d0 : Base_007878d0, ListNode_007878d0
{
    bool FUN_007877a0(int iKey);
    int FUN_007878d0();
};

struct HighlightValue
{
    void FUN_00a09130(int property, void* source, int sourceProperty);
    void FUN_00a09410(int value);
};
struct HighlightTile : LevelValue
{
    HighlightValue* FUN_00a00f30(int property);
    bool FUN_0071aa80();
    HighlightTile* FUN_00a03da0(const char* name);
    void FUN_0071aa60(bool value);
    void FUN_00a07530(int flags);
};
HighlightTile* __cdecl FUN_00a08b20(HighlightTile*, const char*);
struct SkillHighlight
{
    int unk00;
    int unk04;
    int unk08;
    HighlightTile* tile;
    HighlightTile* selected;
    void UpdateHighlight();
};

namespace fnv_00784c80 {
struct DelObj
{
    virtual ~DelObj();
};
struct MenuV
{
    virtual int ph0();
    virtual int ph1();
    virtual int ph2();
    virtual int ph3();
    virtual int ph4();
    virtual int ph5();
    virtual int ph6();
    virtual int ph7();
    virtual int ph8();
    virtual int ph9();
    virtual int ph10();
    virtual int ph11();
    virtual int ph12();
    virtual int GetID();
};
struct ActorV
{
    virtual int q0();
    virtual int q1();
    virtual int q2();
    virtual int RunFourthVirtual();
    virtual int InvokeFifthVirtualFunction();
    virtual int q5();
    virtual int RunSeventhVirtualOperation();
    virtual int q7();
    virtual int q8();
    virtual int q9();
    virtual int q10();
    virtual int q11();
    virtual int q12();
    virtual int q13();
    virtual int q14();
    virtual int q15();
    virtual int q16();
    virtual int q17();
    virtual int q18();
    virtual int q19();
    virtual int q20();
    virtual int q21();
    virtual int q22();
    virtual int q23();
    virtual int q24();
    virtual int q25();
    virtual int q26();
    virtual int q27();
    virtual int q28();
    virtual int q29();
    virtual int q30();
    virtual int q31();
    virtual int q32();
    virtual int q33();
    virtual int q34();
    virtual int q35();
    virtual int q36();
    virtual int q37();
    virtual int q38();
    virtual int q39();
    virtual int q40();
    virtual int q41();
    virtual int q42();
    virtual int q43();
    virtual int q44();
    virtual int q45();
    virtual int q46();
    virtual int q47();
    virtual int q48();
    virtual int q49();
    virtual int q50();
    virtual int q51();
    virtual int q52();
    virtual int q53();
    virtual int q54();
    virtual int q55();
    virtual int q56();
    virtual int q57();
    virtual int q58();
    virtual int q59();
    virtual int q60();
    virtual int q61();
    virtual int q62();
    virtual int q63();
    virtual int q64();
    virtual int q65();
    virtual int q66();
    virtual int q67();
    virtual int q68();
    virtual int q69();
    virtual int q70();
    virtual int q71();
    virtual int q72();
    virtual int q73();
    virtual int q74();
    virtual int q75();
    virtual int q76();
    virtual int q77();
    virtual int q78();
    virtual int q79();
    virtual int q80();
    virtual int q81();
    virtual int q82();
    virtual int q83();
    virtual int q84();
    virtual int q85();
    virtual int q86();
    virtual int q87();
    virtual int q88();
    virtual int q89();
    virtual int q90();
    virtual int q91();
    virtual int q92();
    virtual int q93();
    virtual int q94();
    virtual int q95();
    virtual int q96();
    virtual int q97();
    virtual int q98();
    virtual int q99();
    virtual int q100();
    virtual int q101();
    virtual int q102();
    virtual int q103();
    virtual int q104();
    virtual int q105();
    virtual int q106();
    virtual int q107();
    virtual int q108();
    virtual int q109();
    virtual int q110();
    virtual int q111();
    virtual int q112();
    virtual int q113();
    virtual int q114();
    virtual int q115();
    virtual int q116();
    virtual int q117();
    virtual int q118();
    virtual int q119();
    virtual int q120();
    virtual int q121();
    virtual int q122();
    virtual int q123();
    virtual int q124();
    virtual int q125();
    virtual int q126();
    virtual int q127();
    virtual int q128();
    virtual int q129();
    virtual int q130();
    virtual int q131();
    virtual int q132();
    virtual int q133();
    virtual int q134();
    virtual int q135();
    virtual int q136();
    virtual int q137();
    virtual int q138();
    virtual int q139();
    virtual int q140();
    virtual int q141();
    virtual int q142();
    virtual int q143();
    virtual int q144();
    virtual int q145();
    virtual int q146();
    virtual int q147();
    virtual int q148();
    virtual int q149();
    virtual int q150();
    virtual int q151();
    virtual int q152();
    virtual int q153();
    virtual int q154();
    virtual int q155();
    virtual int q156();
    virtual int q157();
    virtual int q158();
    virtual int q159();
    virtual int q160();
    virtual int q161();
    virtual int q162();
    virtual int q163();
    virtual int q164();
    virtual int q165();
    virtual int q166();
    virtual int q167();
    virtual int q168();
    virtual int q169();
    virtual int q170();
    virtual int q171();
    virtual int q172();
    virtual int q173();
    virtual int q174();
    virtual int q175();
    virtual int q176();
    virtual int q177();
    virtual int q178();
    virtual int q179();
    virtual int q180();
    virtual int q181();
    virtual int q182();
    virtual int q183();
    virtual int q184();
    virtual int q185();
    virtual int q186();
    virtual int q187();
    virtual int q188();
    virtual int q189();
    virtual int q190();
    virtual int q191();
    virtual int q192();
    virtual int q193();
    virtual int q194();
    virtual int q195();
    virtual int q196();
    virtual int q197();
    virtual int q198();
    virtual int q199();
    virtual int q200();
    virtual int q201();
    virtual int q202();
    virtual int q203();
    virtual int q204();
    virtual int q205();
    virtual int q206();
    virtual int q207();
    virtual int q208();
    virtual int q209();
    virtual int q210();
    virtual int q211();
    virtual int q212();
    virtual int q213();
    virtual int q214();
    virtual int q215();
    virtual int q216();
    virtual int q217();
    virtual int q218();
    virtual int q219();
    virtual int q220();
    virtual int q221();
    virtual int q222();
    virtual int q223();
    virtual int q224();
    virtual int q225();
    virtual int q226();
    virtual int q227();
    virtual int q228();
    virtual int q229();
    virtual int q230();
    virtual int q231();
    virtual int q232();
    virtual int q233();
    virtual int q234();
    virtual int q235();
    virtual int q236();
    virtual int q237();
    virtual int q238();
    virtual int q239();
    virtual int q240();
    virtual int q241();
    virtual int q242();
    virtual int q243();
    virtual int q244();
    virtual int q245();
    virtual int q246();
    virtual int q247();
    virtual int q248();
    virtual int q249();
    virtual int q250();
    virtual int q251();
    virtual int q252();
    virtual int q253();
    virtual int q254();
    virtual int q255();
    virtual int q256();
    virtual int q257();
    virtual int q258();
    virtual int q259();
    virtual int q260();
    virtual int q261();
    virtual int q262();
    virtual int q263();
    virtual int q264();
    virtual int q265();
    virtual int q266();
    virtual int q267();
    virtual int q268();
    virtual int q269();
    virtual int q270();
    virtual int q271();
    virtual int q272();
    virtual int q273();
    virtual int q274();
    virtual int q275();
    virtual int q276();
    virtual int q277();
    virtual int q278();
    virtual int q279();
    virtual int q280();
    virtual int q281();
    virtual int q282();
    virtual int q283();
    virtual int q284();
    virtual int q285();
    virtual int q286();
    virtual int q287();
    virtual int q288();
    virtual int q289();
    virtual int q290();
    virtual int q291();
    virtual int q292();
    virtual int q293();
    virtual int q294();
    virtual int q295();
    virtual unsigned char FUN_v4a0(void* a1, int a2);
};
struct Tile;
struct TileMenu;
struct ResourceProvider
{
    Tile* FUN_00586150(const char*);
};
struct TileB
{
    void* FUN_00a01b00();
};
struct FUN_00a03c90_shell
{
    Menu* FUN_00a03c90();
};
struct TileMenuO
{
    float FUN_00a011b0(int);
};
struct FUN_00a012d0_t
{
    void FUN_00a012d0(int, float);
};
struct FUN_00a01290_shell
{
    void SetTraitAndReset(int, float);
};
struct FUN_00a1dc70_shell
{
    void FUN_00a1dc70(TileMenu*, bool);
};
struct InventoryMenuSetting
{
    const char* FUN_00403df0();
};
struct MgrObj
{
    void FUN_00718630(int, int, int);
};
struct TileF
{
    void FUN_00a01350(int, const char*, int);
    void FUN_00a01350(int, int, int);
};
struct DatObj
{
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    TileF* f2c;
    int f30;
    int f34;
    int f38;
    int f3c;
    int f40;
    TileF* f44;
    TileF* f48;
    TileF* f4c;
    int f50;
    int f54;
    int f58;
    int f5c;
    int f60;
    void UpdateSkillsAndPerks();
    void SetPage(int);
};
struct ListObj
{
    void FUN_00905820(void**);
    int FUN_005ae380();
};
extern int DAT_011dea3c;
extern int DAT_011d4048;
extern int DAT_011d33d8;
extern int DAT_011d3564;
extern int DAT_011d35c4;
extern int DAT_011d1fec;
extern int DAT_011da034;
extern int DAT_011c3f2c;
extern int DAT_011cd074;
void* FUN_00a09030(int);
void* FUN_004b7210();
int FUN_005b5e40(const char*);
float __stdcall FUN_00a01530(int);
int FUN_00406d00(char*, int, const char*, ...);
struct Dummy648bc0;
int FUN_00648bc0(Dummy648bc0*);
int FUN_005e58f0(int, int, float*);
unsigned short __fastcall FUN_0087f9f0(void*);
int& __fastcall FUN_0043d4d0(int*);
struct ContNode;
ContNode* __fastcall FUN_00726070(ContNode*);
char __fastcall GetByteAtOffset56(char*);
struct TESConditionItem;
struct ConditionList_t
{
    TESConditionItem* const* FUN_006815c0();
};
struct FUN_00460fb0_class
{
    void* FUN_00460fb0();
};
struct FUN_006aabf0_shell
{
    unsigned char GetByteAt39();
};
struct FUN_005d4ee0Class
{
    char FUN_005d4ee0();
};
struct FUN_005eb5e0_t
{
    bool CheckPlayerConditions();
};
struct ItemO
{
    unsigned char FUN_005eba00(int);
};
struct ByteO
{
    unsigned char* FUN_00408d60();
};
int FUN_00a01860(const char*);
struct HeadO
{
    void FUN_00700320(int, int);
};

static const char s_xml[] = "Data\\Menus\\levelup_menu.xml";
static const char s_err[] = "MENUS: Level Up Menu Creation Failed... Are your menu and art resources up to date?";
static const char s_title0[] = "_Title_0";
static const char s_title1[] = "_Title_1";
static const char s_curpage[] = "_CurrentPage";
static const char s_endpage[] = "_EndPage";
}  // namespace fnv_00784c80

struct TileValue
{
    bool IsTraitNonZero(int m_iValueId);
};
struct ListBox_int_
{
    bool FUN_00787b70();
    bool ContainsKey(Tile* pkTile);
    bool SetTileSelection(Tile* pkTile, int eMode);
};

extern int DAT_011d9fe4;
extern int DAT_011d9fec;
extern int DAT_011d9ff0;

struct LUM_Item
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
};

class GlobalObject_00788300
{
  public:
    unsigned int GetCount();
    LUM_Item* GetItem(unsigned int index);
};

extern GlobalObject_00788300 g_011da050;

// Finds the matching item, adjusts its stored value against tile bounds and overflow, then updates a tile trait.
// @f3 0x00655570 (community match, verified in this file)
struct F6AD50_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
};
struct Tile_00655570
{
    float __thiscall FUN_00becf40(int trait);
    void __thiscall FUN_00bee190(int trait, float value, int doUpdate);
    void SetInt(int trait, int value) { FUN_00bee190(trait, (float)value, 1); }
    void AddInt(const int& trait, const int& value) { FUN_00bee190(trait, FUN_00becf40(trait) + value, 1); }
};
struct Array_00f6ad50
{
    F6AD50_Entry* data;
    unsigned int count;
    unsigned int GetCount() const { return count; }
    F6AD50_Entry* GetItem(unsigned int index) const { return &data[index]; }
};
extern Array_00f6ad50 DAT_00f6ad50;
extern int DAT_010768f4;
extern int DAT_010768fc;
extern int DAT_01076900;
extern char str_00e06058[];
extern char str_00e06064[];
extern char str_00e06070[];
extern "C" int __cdecl FUN_00bea9e0(const char*);

void __cdecl FUN_00786240(LevelValue* apTile, int aiMatchValue)
{
    Tile_00655570* T = (Tile_00655570*)apTile;
    unsigned int i = 0;
    for (; i < DAT_00f6ad50.GetCount(); ++i)
    {
        if (DAT_00f6ad50.GetItem(i)->unk10 == aiMatchValue)
        {
            int totalI = (int)(T->FUN_00becf40(DAT_010768f4) + T->FUN_00becf40(DAT_010768fc) + T->FUN_00becf40(DAT_01076900));
            int overflow = FUN_00bea9e0(str_00e06070);
            if (T->FUN_00becf40(overflow) != 0.0f)
            {
                DAT_00f6ad50.GetItem(i)->unk00 += (int)T->FUN_00becf40(overflow);
                T->FUN_00bee190(overflow, 0.0f, 1);
            }
            if ((double)(totalI + DAT_00f6ad50.GetItem(i)->unk00) > T->FUN_00becf40(FUN_00bea9e0(str_00e06064)))
            {
                int diff = (int)((double)(totalI + DAT_00f6ad50.GetItem(i)->unk00) - T->FUN_00becf40(FUN_00bea9e0(str_00e06064)));
                T->SetInt(FUN_00bea9e0(str_00e06070), diff);
                DAT_00f6ad50.GetItem(i)->unk00 -= diff;
            }
            else if ((double)(totalI + DAT_00f6ad50.GetItem(i)->unk00) < T->FUN_00becf40(FUN_00bea9e0(str_00e06058)))
            {
                int diff = (int)((double)(totalI + DAT_00f6ad50.GetItem(i)->unk00) - T->FUN_00becf40(FUN_00bea9e0(str_00e06058)));
                T->SetInt(FUN_00bea9e0(str_00e06070), diff);
                DAT_00f6ad50.GetItem(i)->unk00 -= diff;
            }
            T->AddInt(DAT_010768fc, DAT_00f6ad50.GetItem(i)->unk00);
        }
    }
}


struct LevelGamepadTile
{
    LevelGamepadTile* FUN_00a03eb0(int id);
    bool IsTraitNonZero(int trait);
    void FUN_00a0b110(int trait);
};

struct LevelGamepadList
{
    virtual void vfunc0();
    virtual LevelGamepadTile* GetSelectedTile();
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
};

class LevelGamepadView
{
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void HandleClick(int id, LevelGamepadTile* tile);
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual bool FUN_00785ed0(int code, float val);

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
    LevelGamepadTile* tile4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    LevelGamepadList list64;
    LevelGamepadList list94;
};

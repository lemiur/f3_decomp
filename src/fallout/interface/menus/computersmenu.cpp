#include "f3_common.h"
// src/fallout/interface/menus/computersmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/computersmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Tile
{
    Tile* pParent;
};

struct ComputersMenu
{
    char _base[0x28];
    Tile* m_pTiles[64];
    void FUN_00754c00(int aiID, Tile* apTile);
};

namespace fnv_00757a10 {
struct ComputersMenu
{
    int __thiscall GetMenuId();
};

}  // namespace fnv_00757a10

struct FUN_00757e80_shell
{
    unsigned char IsFlagBitSet();
};

struct FUN_00758390_shell
{
    signed char m_74;
    bool __thiscall FUN_00758390();
};

struct FUN_00758a60_shell
{
    char m_74;
    bool __thiscall FUN_00758a60();
};

namespace fnv_007596a0 {
struct Tile
{
    void Set(int a, int b);
};
extern int __cdecl GetTileValueID(const char*, int);
extern char $SG7172[];

}  // namespace fnv_007596a0

void __cdecl _Deallocate(void*);
struct S757a20
{
    void __thiscall FUN_00757a50();
    void* __thiscall FUN_00757a20(unsigned int);
};

struct FUN_00757e30_Class
{
    char _pad[0x28];
    Tile* arr[16];
    bool __thiscall HasAllTiles(int* p);
};

struct FUN_00758350_shell
{
    char m_6c[4];
    bool __thiscall FUN_00758350();
};

struct Helper98
{
    void __thiscall _ref_0063f7b0();
    int* __thiscall _ref_006815c0();
};
struct DispHelper
{
    void __thiscall FUN_007586e0(int);
};
void __cdecl RefreshF57EA0TerminalMenu();
struct FUN_00758a80_shell
{
    void __thiscall FUN_00758a80();
};

struct StartMenu
{
    char const* GetMenuTitle();
};
extern StartMenu* DAT_01189e94[];
struct Host
{
    char _pad[0xA6];
    unsigned char mA6;
    char const* __thiscall FUN_00758fe0();
};

struct GlobalObject_0048f200
{
    GlobalObject_0048f200();
};
GlobalObject_0048f200::GlobalObject_0048f200()
{}
struct FUN_00759760_shell : GlobalObject_0048f200
{
    FUN_00759760_shell();
};
// @fnv 0x00759760
FUN_00759760_shell::FUN_00759760_shell()
{}

struct S_7597c0
{
    int __thiscall FUN_007597c0(int);
};
extern S_7597c0* DAT_011d9338;
// Calls FUN_007597c0(1) on DAT_011d9338 if non-null, then sets DAT_011d9338 to null.
// @fnv 0x00759780
void FUN_00759780()
{
    S_7597c0* b = DAT_011d9338;
    S_7597c0* a = b;
    a ? a->FUN_007597c0(1) : 0;
    DAT_011d9338 = 0;
}

void __cdecl operator delete(void*);
struct FUN_007597c0_shell
{
    void FUN_007597f0();
    void* __thiscall FUN_007597c0(unsigned int flags);
};

namespace fnv_007597f0 {
struct GlobalObject_0048f200
{
    ~GlobalObject_0048f200();
};
struct FUN_00759850_owner
{
    void __thiscall FUN_00759850();
};
struct FUN_007597f0 : GlobalObject_0048f200
{
    ~FUN_007597f0();
};
// Destructor that calls FUN_00759850 on this object before the base GlobalObject_0048f200 destructor runs.
// @fnv 0x007597f0
FUN_007597f0::~FUN_007597f0()
{
    ((FUN_00759850_owner*)this)->FUN_00759850();
}
}  // namespace fnv_007597f0

struct ArrHelper
{
    bool FUN_0076b610() const;
};
struct ScriptObj
{
    int FUN_007598a0(int);
};
struct ListBase
{
    ScriptObj* RemoveHead();
};
struct Holder
{
    void FUN_00759850();
};

void Deallocate(void*);
struct FUN_007598a0_shell
{
    void __thiscall FUN_00726cf0();
    void* __thiscall FUN_007598a0(unsigned int flags);
};

struct Flt
{
    operator unsigned int();
};
struct TL
{
    Tile*& GetNext(void*&);
};
struct NoArgumentMethodObject
{
    void FUN_00700110();
};
struct TileProcessor
{
    void ProcessAllTiles();
};

void __cdecl operator delete(void*);

struct FUN_0075aa20_shell
{
    void __thiscall FUN_0075a060();
    void* __thiscall FUN_0075aa20(unsigned int flags);
};

struct FUN_007583b0_shell
{
    char _pad[0x74];
    signed char m_74;
    void __thiscall SetFlag4(bool aFlag);
};

struct BSSimpleList
{
    void __thiscall Sort(int(__cdecl* f)(void*, void*));
};

struct FUN_0075aa50_shell
{
    void __thiscall ResetAndProcessNodes();
};

struct FUN_0075a5e0_shell
{
    char _pad[4];
    BSSimpleList m_kNode;
    void __thiscall FUN_0075a5e0(int(__cdecl* f)(void*, void*));
};

struct InterfaceH
{
    static bool __cdecl GetSelectedTargetIndex(int);
};
struct TV
{
    bool __thiscall IsVisible();
};
struct FUN_007583f0_shell
{
    char _pad[0x30];
    Tile* pTile30;
    char _pad2[0xbc - 0x34];
    const char* m_pText;
    bool __thiscall HandleButtonInput(int aiButton, float afValue);
};

struct FUN_00a01230_shell
{
    bool __thiscall IsTraitNonZero(int);
};

struct FUN_0075ab20_shell
{
    char _pad[0x0C];
    Tile* m_pTile;
    bool __thiscall IsTileTraitEnabled();
};

int __cdecl GetTileValueID(char const*, int);
extern int DAT_011d93d8;
extern int DAT_011d93dc;

void* __cdecl operator new(unsigned int);

struct M788
{
    void __thiscall FUN_004ed8c0(void*);
};

struct GO
{
    operator unsigned int();
};

struct NiTPointerList
{
    void* __thiscall DereferenceIfNotNull(void*);
};

struct FUN_006ffe80_shell
{
    void __thiscall FUN_006ffe80(int, int);
};

struct FUN_00726db0_class
{
    bool __thiscall FUN_00726db0(bool);
};

struct FUN_00759eb0
{
    char _pad[0x2c];

    FUN_00759eb0(char const*);
};

struct FUN_007b5330_shell
{
    void __thiscall FUN_007b5330(void*, void*);
};

struct FUN_00759da0_shell : FUN_007b5330_shell
{
    void __thiscall InsertAtPosition(char const*, int, int, int);
};

struct MenuBase
{
    virtual ~MenuBase();
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
};
struct Obj68
{
    int a;
    ~Obj68();
};
struct SList
{
    void* head;
    void* next;
    void RemoveAll();
    ~SList();
};
struct BStr
{
    char* p;
    short len;
    short max;
    ~BStr();
};
struct SoundH
{
    int a;
    int b;
    int c;
    void Stop();
    void FUN_00ad8d10();
    ~SoundH();
};
struct SysColorMgr
{
    static SysColorMgr* GetSingleton();
    void ApplyToChild(int, int*);
};
extern int DAT_011d9334;
extern int DAT_011d934c;
void FUN_00759780();
struct FUN_00757a50 : MenuBase
{
    Obj68 m68;
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
    SList list98;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    BStr strB4;
    int unkbc;
    int unkc0;
    SoundH sounds[3];
    virtual ~FUN_00757a50();
};
// @fnv 0x00757a50
FUN_00757a50::~FUN_00757a50()
{
    DAT_011d9334 = 0;
    FUN_00759780();
    list98.RemoveAll();
    for (int i = 0; i < 3; i++)
    {
        sounds[i].Stop();
        sounds[i].FUN_00ad8d10();
    }
    SysColorMgr::GetSingleton()->ApplyToChild(3, &DAT_011d934c);
}

struct BlinkValue
{
    float FUN_00488d50();
    void FUN_00a0a270(float, bool);
};
struct TraitValueCollection
{
    float FUN_00a011b0(int);
    BlinkValue* FindTraitValue(int);
};
unsigned int __cdecl gm_GetTickCount();
struct BlinkMenu
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
    TraitValueCollection* tile;
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
    BlinkValue* value;
    void UpdateBlink();
};

struct BSStringT
{
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT(const char* apStr);
    ~BSStringT();
    BSStringT& operator+=(const char* apStr);
    operator const char*() const;
};

struct TileValue;

struct MenuTile
{
    void Set(int aiID, int aiValue);
    TileValue* GetValue(int aiID);
};

int __cdecl TraitNameToID(const char* apName, int aiDefault);

struct NoteFlags
{
    bool Check(int a, int b);
};

struct NoteEntry
{
    BSStringT kName;
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
    NoteFlags kFlags;
    bool IsUnread();
    void SetUnread(bool abUnread);
};

struct GameSettingString
{
    const char* String();
};
extern GameSettingString g_011d2cb8;

struct NoteTextSetter
{
    void Apply();
};
NoteTextSetter* __stdcall CreateNoteTextSetter(const char* apText, TileValue* apValue1, TileValue* apValue2,
                                               int aiIndex);

struct FUN_00759760_storage : FUN_00759760_shell
{
    int unk00;
    int unk04;
    int unk08;
};

// Destructor: release the entries, unregister this object, then the entry list member is destroyed.

class A060EntryList
{
  public:
    ~A060EntryList();
    void* m_pkHead;
    void* m_pkTail;
};

class FUN_0075a060;
void __cdecl A060Unregister(FUN_0075a060* pkObject);

class FUN_0075a060
{
  public:
    virtual ~FUN_0075a060();
    void Clear();

    A060EntryList m_kEntries;
};

// Clears the object's entry list, then unregisters the object via A060Unregister.
// @fnv 0x0075a060
FUN_0075a060::~FUN_0075a060()
{
    Clear();
    A060Unregister(this);
}

struct Shell
{
    bool __thiscall IsTileTraitEnabled();
    bool __thiscall ContainsKey(Tile* a1);
    void __thiscall UpdateHighlight();
};

struct ParamShell
{
    bool __thiscall IsTraitNonZero(int a1);
};

char const* __cdecl FUN_00a00940(char const* a1, int a2);

class SetTileHelper
{
  public:
    char _pad[0x10];
    Tile* m_pTile10;

    bool FUN_0075a610(Tile* apTile);
};

struct b9165Obj
{
    void __thiscall FUN_00700320(int a, int b);
};

struct b9165Inner
{
    b9165Obj* m_00;
    char unk04[4];
    unsigned char m_08;
};

struct b9165Ref
{
    b9165Inner* p;
};

struct b9165Node
{
    char unk00[0x18];
    b9165Ref* __thiscall FUN_006815c0();
    b9165Node* __thiscall FUN_00726070();
};

struct FUN_0075aa50_cls
{
    char unk00[4];
    b9165Node m_04;
    unsigned short m_1c;
    char unk1e[2];
    float m_20;
    void __thiscall AccumulateTileHeight(b9165Obj* p);
    void __thiscall UpdateScrollItems();
    void __thiscall UpdateHighlight();
    void __thiscall ResetAndProcessNodes();
};

// Refresh the terminal menu tile; if the rendered menu is showing this menu's scene, refresh the rendered terminal too.

class InterfaceManager;
class NiNode;

class F57EA0Tile
{
  public:
    void SetFloat(int m_iValueId, float fValue, bool bPropagate);
    void SetInt(int m_iValueId, int iValue);
    NiNode* GetNode();
};

class FORenderedMenu
{
  public:
    virtual ~FORenderedMenu();
    NiNode* GetSceneNode();
};

class FORenderedTerminal : public FORenderedMenu
{
  public:
    void Refresh();
};

class F57EA0Menu
{
  public:
    F57EA0Tile* GetTile();
    void Update();
};

extern F57EA0Menu* g_pF57EA0TerminalMenu;
extern const float g_fF57EA0TileDefault;

void F57EA0Prepare();
InterfaceManager* F57EA0GetInterfaceManager();
FORenderedMenu* __fastcall F57EA0GetRenderedMenu(InterfaceManager* pkManager);

namespace fnv_00758470 {
struct InterfaceManager;
struct S8840
{
    bool FUN_00718840(int);
};
struct InterfaceManager
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
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    S8840 unk4d4;
};
InterfaceManager* FUN_004b7210();
struct HH84
{
    unsigned int GetReferenceFlags();
    void ProcessQueue();
};
struct Tile_Set_Helper
{
    void Set(int, int);
};
struct TESObjectREFR;
template <class T> struct ListBox
{
    void Traverse(void (*f)(Tile*, T), int, int);
};
void FUN_007596a0(Tile*, TESObjectREFR*);
unsigned int __cdecl gm_GetTickCount();
extern unsigned int DAT_011d93c4;
struct CompMenu
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
    Tile_Set_Helper* tile3c;
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
    ListBox<TESObjectREFR*> list68;
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
    unsigned int unka0;
    int unka4;
    int unka8;
    int unkac;
    int iStateB0;
    int unkb4;
    int unkb8;
    int unkbc;
    bool bC0;
    bool bC1;
    char unkc2;
    char unkc3;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    HH84* pE8;
    void FUN_00758470();
    void UpdateBlink();
    void RefreshDisplay();
};
}  // namespace fnv_00758470

struct CHValue
{
    const char* GetString();
};

struct CHTile
{
    CHValue* GetValue(int aiTrait);
    CHValue* GetValueAlt(int aiTrait);
    bool IsVisible();
    void SetInt(int aiTrait, int aiValue);
};

struct CHString
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;

    CHString();
    ~CHString();
    const char* CStr();
};

int __cdecl CHSprintf(CHString* apString, const char* apFormat, ...);
int __cdecl CHStricmp(const char* apString1, const char* apString2);
int __cdecl CHTraitNameToID(const char* apName, int aiDefault);

struct CHSetting
{
    const char* GetString();
};

struct CHUIntSetting
{
    unsigned int* Int();
};

struct CHCondition
{
    bool Evaluate(void* apSubject, int aiUnk);
};

struct CHChallenge;

struct CHListNode
{
    CHChallenge* pItem;
    CHListNode* pNext;

    CHChallenge** GetItem();
    CHListNode* GetNext();
};

struct CHDescription
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual const char* Get(CHChallenge* apForm, unsigned int auiChunk);
};

struct CHChallenge
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    CHCondition kCondition;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    CHDescription kDescription;

    CHListNode* GetChallengeList();
    bool IsCompleted();
    const char* GetName();
    void SetSeen(bool abSeen);
};

struct CHSimpleList
{
    CHChallenge* pItem;
    CHListNode* pNext;

    void AddHead(CHChallenge*& arItem);
    CHListNode* GetNext();
};

struct CHListBox
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Clear();
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;

    CHTile* Insert(CHChallenge* apItem, int aiUnk1, int aiUnk2, int aiUnk3);
};

struct CHDisplay
{
    void Reset();
    void AddLine(const char* apText, CHValue* apValue1, CHValue* apValue2, int aiUnk);
};

extern CHUIntSetting g_kChallengeRateSetting;
extern CHSetting g_kNoChallengesSetting;
extern unsigned int g_uiChallengeUpdateMS;

struct CHMenu
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    CHTile* pTile44;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    CHTile* pTile64;
    CHListBox kListBox;
    CHSimpleList kRecent;
    short unkA0;
    short unkA2;
    int unkA4;
    CHChallenge* pChallenge;
    void* pSubject;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    char unkC0;
    bool bRefreshed;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    CHDisplay* pDisplay;

    void FUN_007586e0(bool abAddRecent);
};

class TESSound
{
  public:
    unsigned int GetFormID();
};

class BGSNote
{
  public:
    TESSound* FUN_005e9100();
};

class BSAudio
{
  public:
    static BSAudio* GetSingleton();
};

struct FUN_00483710
{
    int unk;
    int unkCur;
    int unkValue;

    ~FUN_00483710();
    bool FUN_00ad8830(bool abFlag);
};

struct FUN_00ad73b0_t
{
    FUN_00483710 FUN_00ad73b0(unsigned int auiFormID, unsigned int auiFlags);
};

struct Shell_759030
{
    void PlayNoteSound(BGSNote* apNote);
};

struct Setting
{
    unsigned int* Int();
};
extern Setting g_011d4bb8;
extern int DAT_0119f278;
struct TextTile
{
    void Set(int, int);
    double Read(int);
    void* Find(int);
    void* GetValue(int);
};
struct TextString
{
    char* text;
    unsigned short len, capacity;
    bool Set(const char*);
    operator const char*() const;
    unsigned int Length() const;
};
struct TextLayout
{
    TextLayout(int, int, int, int, int);
    ~TextLayout();
    operator const char*() const;
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned int consumed;
    int unk1c;
    int unk20;
    int unk24;
};
struct TextFont
{
    float Height();
    void Format(const char*, TextLayout*);
};
struct TextFonts
{
    static TextFonts* Instance();
    TextFont* GetFont(int);
};
struct TextAnimator
{
    void Clear();
    void SetText(const char*, void*, void*, int);
};
struct TextSource;
struct TextSourceInterface
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual const char* GetText(TextSource*, int, int);
};
struct TextSource
{
    TextSourceInterface* GetInterface();
};
unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);
struct TextMenu
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    TextTile* field2c;
    TextTile* field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    TextTile* field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    TextTile* field60;
    int field64;
    int field68;
    int field6c;
    int field70;
    int field74;
    int field78;
    int field7c;
    int field80;
    int field84;
    int field88;
    int field8c;
    int field90;
    int field94;
    int field98;
    int field9c;
    int fielda0;
    int fielda4;
    int fielda8;
    int fieldac;
    int fieldb0;
    TextString buffer;
    const char* fieldbc;
    int fieldc0;
    int fieldc4;
    int fieldc8;
    int fieldcc;
    int fieldd0;
    int fieldd4;
    int fieldd8;
    int fielddc;
    int fielde0;
    int fielde4;
    TextAnimator* fielde8;

    void SetTextSource(TextSource*);
};

namespace fnv_007598d0 {
struct TextTile
{
    TextTile* FUN_0045cd60();
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
    void FUN_00700320(int, int);
    void* FUN_00a00f30(int);
    void FUN_00a04640(bool);
    void FUN_00a04620(bool);
    bool IsAllChildrenFlag0();
};
struct QueueText
{
    ~QueueText();
    bool FUN_00759d80();
    const char* FUN_00458b50();
    const char* FUN_0059bb30();
    unsigned int FUN_0044edb0();
    TextTile* FUN_007001f0();
    void FUN_006ffea0();
};
struct TextQueue
{
    bool FUN_0076b610() const;
    QueueText** FUN_0073ac90();
    QueueText* PopFrontScript();
    void ProcessQueue();
};
struct TextSound
{
    int id;
    int state;
    int flags;
    ~TextSound();
    void FUN_00ad8870();
    void FUN_00ad8830(bool);
};
struct TextAudioManager
{
    TextSound ResolveAudioHandle(const char*, int, unsigned int, int);
};
TextAudioManager* FUN_00ad9060();
unsigned int FUN_0044a670(const char*);
struct QueueMenu
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
    TextTile* previousTile;
    TextTile* positionTile;
    TextTile* activeTile;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    TextTile* modeTile;
    Shell selection;
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
    int mode;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    TextSound unusedSound;
    TextSound advanceSound;
    TextSound promptSound;
};
extern unsigned int DAT_011d93d4;
extern const char DAT_01072118[];
}  // namespace fnv_007598d0

int __cdecl TraitNameToID(const char* apName, int aiDefault);

struct LBTile;

struct LBTileValue
{
    void RemoveFromReactions();
    void FUN_00a09130(int aiOperator, LBTile* apTile, int aiID);
    void AppendFloatAction(int aiOperator, float afValue);
    void FUN_00a09410(int aiFlag);
};

struct LBTileMenu
{
    LBTile* AddTileFromTemplate(LBTile* apParent, const char* apTemplate, int aiUnk);
};

struct LBTile
{
    LBTileMenu* GetMenu();
    void* GetValue(int aiID);
    LBTileValue* GetValueAction(int aiID);
    void SetInt(int aiID, int aiValue);
    void SetString(int aiID, const char* apString, bool abPropagate);
    float GetFloat(int aiID);
};

struct LBItem
{
    LBTile* pTile;
    int iObject;
    int iUnk08;
    LBItem(LBTile* apTile, const int& arObject);
};

struct LBItemList
{
    LBItem* pFirst;
    void* pNext;
    void InsertSorted(LBItem* apItem, int(__cdecl* apSort)(LBItem*, LBItem*));
    void Append(LBItem* const& arItem);
};

struct LBListBox
{
    virtual void v00();
    LBItemList kList;
    LBTile* pParentTile;
    LBTile* pSelected;
    LBTile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short usItemCount;

    bool FUN_007242c0(int aiUnk);
    void ResetAndProcessNodes();
    void AccumulateTileHeight(LBTile* apTile);
    void UpdateScrollItems();
    int GetRaceCount();
    LBTile* AddItem(int aiObject, const char* apText, int(__cdecl* apSort)(LBItem*, LBItem*),
                    const char* apTemplateName);
};

struct OwnedObject
{
    virtual ~OwnedObject();
};
struct OwnedText
{
    ~OwnedText();
};
struct AnimationEntry
{
    OwnedObject* object;
    OwnedText* text;
};
struct AnimationNode
{
    AnimationEntry** FUN_006815c0();
    AnimationNode* FUN_00726070();
    void FUN_006ecd40(int value);
    ~AnimationNode();
};
struct AnimationTile
{
    void Set(int trait, float value, bool propagate);
};
extern bool s_bAllowDetach;
int __cdecl FUN_00a01860(const char* name);
struct AnimationList
{
    int unk00;
    AnimationEntry* entry;
    AnimationNode* node;
    AnimationTile* tile;
    Tile* currentTile;
    int unk14;
    int unk18;
    unsigned short count;
    unsigned short unk1e;
    float elapsed;
    bool FUN_007242c0(unsigned int flag);
    void UpdateScrollItems();
    void UpdateHighlight();
    void ClearEntries();
};

float __cdecl FUN_004bd510(float, float);
int __cdecl FUN_00a01860(const char*);

struct MyTile : FUN_00a01230_shell
{
    float __thiscall FUN_00a011b0(int);
};

struct MyInner
{
    MyTile* m_00;
};

struct MyRef
{
    MyInner* p;
};

struct MyNode
{
    void* m_item;
    MyNode* m_next;
    MyRef* __thiscall FUN_006815c0();
    MyNode* __thiscall FUN_00726070();
};

struct MyListBox
{
    virtual void* v00();
    virtual void* v04();
    virtual void* v08();
    virtual void* v0c();
    virtual void* v10();
    virtual MyTile* FUN_0075a955(int, int);

    MyNode m_kNode;
    MyTile* m_tile0c;
    MyTile* m_tile10;
    int m_unk14;
    int m_unk18;
    unsigned short m_count1c;

    bool __thiscall IsTileTraitEnabled();
    MyTile* GetScrollTargetTile(int a1);
};

struct ScrollListHelper
{
    void __thiscall FUN_00700320(int aiID, int aiValue);
};

struct ScrollTileHelper
{
    void __thiscall FUN_00a012d0(int aiID, float afValue, bool abCreate);
};

struct FUN_0075b020_cls
{
    unsigned int __thiscall FUN_0075b020();
};

struct ScrollData
{
    int unk00;
    int unk04;
    int unk08;
    TraitValueCollection* pTile0c;
    int unk10;
    ScrollListHelper* pTile14;
};

extern double DAT_01012060;
float __cdecl FUN_004e4430(float afValue);
int __cdecl FUN_00647b70(int aiMinimum, int aiValue);
int __cdecl FUN_00a01860(const char* apText);

namespace fnv_00757b70 {
struct Terminal;
struct Ref
{
    Terminal* GetTerminal();
};
struct Terminal
{
    unsigned char IsFlagBitSet();
    bool CanUse(Ref*);
};
struct Color
{
    float r, g, b, a;
    Color(float, float, float, float);
};
struct Colors
{
    static Colors* Singleton();
    bool Get(int, int*);
    void Set(int, Color const&);
};
extern int DAT_011d934c;
struct OpenTile;
struct ListUI
{
    void Initialize(OpenTile*, const char*);
};
struct SoundUI
{
    bool Play(bool);
};
struct OpenMenu
{
    virtual ~OpenMenu();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual int ID();
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
    OpenTile* root;
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
    ListUI list;
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
    Terminal* terminal;
    Ref* ref;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    unsigned char unkc0;
    unsigned char unkc1;
    unsigned char unkc2;
    unsigned char unkc3;
    SoundUI sound;
    void Attach(OpenTile*, bool);
    bool Validate(int*);
    void Populate();
    void Alternate();
    void Show(int);
    void* Data();
};
extern OpenMenu* gComputerMenu;
struct OpenTile
{
    OpenTile* ReadFile(const char*);
    OpenMenu* GetMenu();
    float Value(int);
    void Set(int, float, bool);
};
struct KeyState
{
    unsigned char Check(int, int, int);
};
struct UI
{
    int unk0;
    int unk4;
    int unk8;
    int unkc;
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
    unsigned char unkc0;
    unsigned char unkc1;
    unsigned char unkc2;
    unsigned char unkc3;
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
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    KeyState keys;
    OpenTile* Root();
};
UI* GetUI();
int FUN_00757e20();
OpenMenu* FindMenu(int);
float GetDefault();
void Warn(const char*, ...);
}  // namespace fnv_00757b70

struct HighlightTile;
struct HighlightValue
{
    void FUN_00a09130(int trait, HighlightTile* tile, int sourceTrait);
    void FUN_00a09410(int mode);
};
struct HighlightTile
{
    HighlightValue* FUN_00a00f30(const char* trait);
    bool GetSpeechChallengeFailure();
    HighlightTile* FUN_00a03da0(const char* name);
    void FUN_0071aa60(bool visible);
    void FUN_00a07530(int flags);
    void FUN_00700320(const char* trait, int value);
};
HighlightTile* __cdecl FUN_00a08b20(HighlightTile* root, const char* path);
struct HighlightList
{
    int unk00;
    int unk04;
    int unk08;
    HighlightTile* root;
    HighlightTile* selected;
    void UpdateHighlight();
};

struct MyMenuTile
{
    void FUN_00700320(int, int);
    void* FindTraitValue(int);
    void* FUN_00a00f30(int);
    MyMenuTile* FUN_0045cd60();
    float FUN_00a011b0(int);
    void FUN_00a012d0(int, float, bool);
};

class GlobalObject_0040c150
{
  public:
    const char* FUN_004c69f0();
    const char* FUN_00403df0();
};

extern GlobalObject_0040c150 g_011d3d78;
extern GlobalObject_0040c150 g_011d4978;

unsigned int __cdecl BSStringLength(const char*);

struct MyDisplay
{
    void ProcessAllTiles();
    void InsertAtPosition(const char*, void*, void*, int);
};

struct ChallengeMenu
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
    MyMenuTile* pTile28;
    int unk2C;
    int unk30;
    MyMenuTile* pTile34;
    MyMenuTile* pTile38;
    int unk3C;
    int unk40;
    int unk44;
    MyMenuTile* pTile48;
    MyMenuTile* pTile4C;
    MyMenuTile* pTile50;
    MyMenuTile* pTile54;
    MyMenuTile* pTile58;
    MyMenuTile* pTile5C;
    int unk60;
    int unk64;
    CHListBox kListBox;
    CHSimpleList kRecent;
    short unkA0;
    short unkA2;
    int unkA4;
    Host* pChallenge;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    MyDisplay* pDisplay;

    void FUN_007586e0(int);
    void RefreshDisplay();
};

#include <string.h>
struct Menu
{
    Menu();
    virtual ~Menu();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};
struct ComputerEntryList
{
    ComputerEntryList();
    ~ComputerEntryList();
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
};
struct SL2
{
    SL2();
    ~SL2();
    void* head;
    void* next;
};
struct StrMem
{
    StrMem();
    ~StrMem();
    char* text;
    unsigned short length;
    unsigned short capacity;
};
struct BSSoundHandleEx
{
    BSSoundHandleEx();
    ~BSSoundHandleEx();
    BSSoundHandleEx& operator=(const BSSoundHandleEx&);
    unsigned int id;
    unsigned int state;
    unsigned int sound;
};
struct ConstructorAudio
{
    BSSoundHandleEx ResolveAudioHandle(const char*, unsigned int);
};
ConstructorAudio* FUN_00ad9060();
void PlayNoteSound();
void SetTextSource();
void UpdateNoteDisplay();

struct FUN_007577f0 : Menu
{
    Tile* tile28;
    Tile* tile2c;
    Tile* tile30;
    Tile* tile34;
    Tile* tile38;
    Tile* tile3c;
    Tile* tile40;
    Tile* tile44;
    Tile* tile48;
    Tile* tile4c;
    Tile* tile50;
    Tile* tile54;
    Tile* tile58;
    Tile* tile5c;
    Tile* tile60;
    Tile* tile64;
    ComputerEntryList entries;
    SL2 notes;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    StrMem text;
    int unkbc;
    bool unkc0;
    BSSoundHandleEx sounds[3];
    S_7597c0* manager;
    void (*callbackec)();
    void (*callbackf0)();
    void (*callbackf4)();
    int unkf8;
    FUN_007577f0();
    virtual ~FUN_007577f0();
};

namespace fnv_00757f70 {
struct TileF;
struct Value
{
    const char* FUN_0084e3a0();
};
struct TileF
{
    void FUN_00700320(int, int);
    bool IsAllChildrenFlag0();
    Value* FUN_00a00f30(int);
    void* FindTraitValue(int);
};
struct BStr
{
    void* m_data;
    int m_len;
    BStr();
    ~BStr();
    const char* FUN_00559450();
};
struct NameObj
{
    const char* FUN_00408da0();
};
struct Note
{
    void* m_n0[18];
    NameObj m_name;
    int GetNoteType();
};
struct Obj
{
    void* m_00;
    void* m_04;
    BStr m_str;
    void* m_rest[23];
    Note* m_note;
    void* m_70;
    void SetFlag4(bool);
    void FUN_00501830(void*);
    bool FUN_00758350();
    bool FUN_00758390();
};
struct ListObj
{
    void* m_items[14];
    bool ContainsKey(TileF*);
    Obj* FindItemData(TileF*);
    void FUN_007314c0(void(__cdecl*)(TileF*, void*), int, int);
};
struct SoundObj
{
    void* m_s0;
    void* m_s4;
    void* m_s8;
    bool FUN_00ad8830(bool);
};
struct Mgr
{
    void ProcessAllTiles();
    void InsertAtPosition(const char*, void*, void*, int);
};
struct Player
{
    bool FUN_00966c10(Note*);
    void FUN_00966a70(Note*, int);
};
struct SettingObj
{
    const char* FUN_00403df0();
};
struct TickObj
{
    int* FUN_0043d4d0();
};
extern Player* DAT_011dea3c;
extern SettingObj DAT_011d3ca0;
extern TickObj DAT_011d3e50;
extern unsigned char DAT_011d93c0;
unsigned int __cdecl FUN_00457fe0();
int __cdecl FUN_00406f60(BStr*, const char*, ...);
bool __cdecl DispatchMessageToSink(const char*, int, const char*, const char*, float, bool);
void __cdecl UpdateNoteTile(TileF*, void*);
struct HostF
{
    void* m_pFirstNode[10];
    TileF* m_pTiles[16];
    ListObj m_kNode;
    int m_a0;
    int m_a4;
    void* m_a8;
    void* m_ac;
    int m_b0;
    int m_b4;
    int m_b8;
    int m_bc;
    unsigned char m_c0;
    unsigned char m_c1;
    unsigned char m_c2[26];
    SoundObj m_sound;
    Mgr* m_pManager;
    typedef void (HostF::*Handler)(Note*);
    Handler m_handlers[16];
    void SetTextSource(int);
    void FUN_007586e0(int);
    void FUN_00758a80();
    void RefreshDisplay();
    void __thiscall FUN_00757f70(int a1, TileF* a2);
};
}  // namespace fnv_00757f70

namespace fnv_00758ad0 {
struct StrMem
{
    char* text;
    unsigned short length;
    unsigned short capacity;
    StrMem();
    ~StrMem();
    const char* FUN_00559450() const;
};
struct TimingSetting
{
    unsigned int* FUN_0043d4d0();
};
struct TextSetting
{
    const char* FUN_004c69f0();
    const char* FUN_00403df0();
};
extern TimingSetting g_011d3de4;
extern TimingSetting g_011d4e4c;
extern TextSetting g_011d3a38;
extern TextSetting g_011d2ee0;
extern TextSetting g_011d430c;
extern int DAT_0119f278;
struct TextTile
{
    void* FindTraitValue(int);
    void* FUN_00a00f30(int);
};
struct TerminalReference
{
    unsigned int FUN_00501270(void*);
};
int __cdecl FUN_00406f60(StrMem*, const char*, ...);
void __cdecl FUN_00403d30(void*, int, unsigned int);
struct TerminalTextMenu
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
    TextTile* introTile;
    TextTile* promptTile;
    TextTile* headerTile;
    TextTile* passwordTile;
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
    TerminalReference* terminal;
    void* reference;
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
    FUN_00759da0_shell* animation;
    void BuildAnimation();
};

}  // namespace fnv_00758ad0

// @f3 0x004a5280 (community match, verified in this file)
namespace f3m_004a5280 {
int __cdecl FUN_00509780(void* a);

class S_0050a0f0
{
public:
    int __thiscall FUN_0050a0f0(int aiValue);
};

class BGSExplosion
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
    S_0050a0f0* unk90;

public:
    int __thiscall FUN_004a5280(void* a);
};

int __thiscall BGSExplosion::FUN_004a5280(void* a)
{
    int r = 0;
    S_0050a0f0* p = unk90;
    if (p)
        r = p->FUN_0050a0f0(FUN_00509780(a));
    return r;
}


}   // namespace f3m_004a5280

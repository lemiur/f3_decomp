// fallout_shared/bsanimgroupsequence.cpp: BSAnimGroupSequence, TaskQueueInterface, TargetClass, SoundPlaybackManager (1 function)
#include "f3_common.h"
#include "bsanimgroupsequence_decls.h"

struct NP
{
    ~NP();
};
struct BaseH
{
    virtual void v();
    ~BaseH();
};
struct FUN_004eeb00 : BaseH
{
    int pad[0x1c];
    NP m;
    ~FUN_004eeb00();
};

struct FUN_004eec60_shell : public BSAnimGroupSequence
{
    float FUN_004eec60(float);
};

struct FUN_00a30970_helper
{
    float FUN_00a30970(float afTime, bool bClamp);
};

struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
};
struct HY
{
    float FUN_004eec60(float);
};
struct HX
{
    char pad[0x34];
    int i34;
    int i38;
    char p1[8];
    int i44;
    float f48;
    float f4c;
    float f50;
    int i54;
    void FUN_004efd10(BGSLoadFormBuffer*, float);
};

extern NiFixedString* DAT_011c61c8;

struct CloningProcess;
struct NiObject;

struct FUN_00a344f0_shell
{
    NiObject* __thiscall FUN_00a344f0(CloningProcess*);
};

struct FUN_004eec20_shell
{
    NiObject* __thiscall FUN_004eec20(CloningProcess* arCloneData);
};

struct NiTPrimitiveArray_char_ptr;
struct BSAnimGroupSequence;

struct FUN_00a34540_shell : BSAnimGroupSequence
{
    void FUN_00a34540(NiTPrimitiveArray_char_ptr* pkStrings);
};

struct FUN_004eec40_shell : BSAnimGroupSequence
{
    void FUN_004eec40(NiTPrimitiveArray_char_ptr* pkStrings);
};

struct TaskQueueInterface
{
    void __thiscall SetTaskFlagDWord(bool, unsigned int);
    void __thiscall FUN_004ef970(bool);
};

struct TESSaveLoadGame
{
    unsigned char FUN_008df040();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

namespace fnv_004efb20 {
// Stand-ins for types not in scope
struct TESSaveLoadGame
{
    unsigned char FUN_008df040(void);
    void FUN_008579b0(void* data, unsigned int size);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct FUN_004efb20_shell
{
    void FUN_004efb20(float afTime);
};

}  // namespace fnv_004efb20

struct NiControllerManager
{
    int GetStringAtOffset(int);
};
struct TargetClass
{
    char _pad[0x40];
    NiControllerManager* field40;
    int FUN_00a31910(int, int);
    int FUN_004eedd0(int, int);
};
// Returns the result of FUN_00a31910 with a1 and the value GetStringAtOffset returns for a2 on field40.
// @f3 0x005fd4b0 (community match, verified in this file)
struct ArgumentObjectView6
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
    void* m_field3c;
    void* FUN_004e8880();
};

struct TargetTableView6
{
    void* m_pTable;
    void FUN_005fcac0(int a, int f, void* r);
};

extern int DAT_00dc4dc0;

int TargetClass::FUN_004eedd0(int a, int b)
{
    ArgumentObjectView6* p = (ArgumentObjectView6*)b;
    TargetTableView6* self = reinterpret_cast<TargetTableView6*>(this);
    self->m_pTable = (void*)&DAT_00dc4dc0;
    int f = (int)p->m_field3c;
    void* r = p->FUN_004e8880();
    self->FUN_005fcac0(a, f, r);
    return (int)(void*)this;
}


unsigned short __cdecl FUN_004efaa0();

struct FUN_004efb10_shell
{
    unsigned short __thiscall FUN_004efb10();
};

struct FUN_004efa50_Holder
{
    char _pad[20];
    struct Item
    {
        int f0;
        int f1;
        int f2;
        int f3;
    }* arr;
    void ClearItemField2();
};

struct BGSSaveFormBuffer
{
    void SaveData(void* data, int size, int type);
};

struct FUN_004efc90_shell
{
    char pad_0x00[0x34];
    char m_0x34[4];
    char m_0x38[4];
    char pad_0x3c[0x44 - 0x3c];
    unsigned char m_0x44;
    char pad_0x45[0x48 - 0x45];
    float m_0x48;
    char pad_0x4c[0x54 - 0x4c];
    char m_0x54[4];
    void FUN_004efc90(BGSSaveFormBuffer* buffer, float value);
};

struct GO
{
    int data;

    GO(int);
    ~GO();
    operator unsigned int() const;
    void operator=(void*);
};

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

struct FUN_004ee9f0 : A51BF0Base
{
    unsigned char data[0x78];

    FUN_004ee9f0(int, unsigned int);
};

void __cdecl FUN_00a35700(int, int, GO*);

namespace fnv_004efbc0 {
class TESSaveLoadGame
{
  public:
    void ReadTypedData(void* data, unsigned int size);
};

struct SaveManager : public TESSaveLoadGame
{
  public:
    unsigned char FUN_008df040();
};

extern SaveManager* DAT_011de45c;

class HY
{
  public:
    float FUN_004eec60(float value);
    void FUN_004efbc0(float value);
};

}  // namespace fnv_004efbc0

struct NameECB
{
    void* GetItem();
};
struct CollectionECB;
struct RootECB
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual RootECB* v08C(const NiFixedString&);
    virtual void v090(NameECB*, bool);
    virtual void v094();
    virtual CollectionECB* v098();
    NiFixedString& GetName();
};
struct CollectionECB
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00C();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01C();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02C();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03C();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04C();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05C();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06C();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07C();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08C();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void* v09C(NameECB*);
};
struct ManagerECB
{
    RootECB* GetStringAtOffset();
};
struct TagECB
{
    int unk00, unk04, unk08, unk0C, unk10;
    NameECB* FUN_006815c0();
};
struct PointerECB
{
    void* object;
    PointerECB& operator=(void*);
};
struct ItemECB
{
    int unk00;
    PointerECB pointer;
    void* unk08;
    unsigned char priority;
    unsigned char unk0D, unk0E, unk0F;
};
extern unsigned char DAT_01096968;
struct FUN_004eecb0_Class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int count;
    int unk10;
    ItemECB* items;
    TagECB* tags;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    ManagerECB* manager;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    RootECB* accumulation;
    void FUN_004eecb0();
};

struct S004eee_Controller
{
    virtual void slot_00();
    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0c();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
    virtual void slot_1c();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2c();
    virtual void slot_30();
    virtual void slot_34();
    virtual void slot_38();
    virtual void slot_3c();
    virtual void slot_40();
    virtual void slot_44();
    virtual void slot_48();
    virtual void slot_4c();
    virtual void slot_50();
    virtual void slot_54();
    virtual void slot_58();
    virtual void slot_5c();
    virtual void slot_60();
    virtual void slot_64();
    virtual void slot_68();
    virtual void slot_6c();
    virtual void slot_70();
    virtual void slot_74();
    virtual void slot_78();
    virtual void slot_7c();
    virtual void slot_80();
    virtual void slot_84();
    virtual void slot_88();
    virtual int Find(const void* key);
};
struct S004eee_Factory
{
    S004eee_Controller* GetStringAtOffset();
};
struct S004eee_Anim
{
    int FUN_0043b1b0();
};
struct S004eee_Entry20
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    S004eee_Anim* FUN_006815c0();
};
struct S004eee_Entry16Sub
{
    unsigned int unk00;
    void FUN_0066b0d0(int);
};
struct S004eee_Entry16
{
    unsigned int unk00;
    S004eee_Entry16Sub m_sub04;
    unsigned int unk08;
    unsigned char unk0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
};
extern unsigned char DAT_01096968;
struct S004eee_Owner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_uiItemCount;
    unsigned int unk10;
    S004eee_Entry16* m_dest;
    S004eee_Entry20* m_pObservedSource;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    S004eee_Factory* m_factory;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int m_priorHandle;
    unsigned int m_handle;
    void UpdateEntryStates();
};

struct SeqSound : NiControllerSequence
{
    int GetState();
    float GetScale();
    unsigned int GetThreadID();
};
struct KeySound : TimedTextEntry
{
    NiFixedString& Text();
    float Time();
};
void CopySoundText(char*, const char*);
char* FindSoundChar(char*, int);

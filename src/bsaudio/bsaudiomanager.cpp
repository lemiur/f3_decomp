#include "f3_common.h"
// src/bsaudio/bsaudiomanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsaudio/bsaudiomanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" int __cdecl FUN_00ec7d40(int);

struct BSAudioManager
{
    static BSAudioManager& __cdecl GetRandomGenerator(void);
    void FUN_00adc670(int, int);
};

struct FUN_00ad8d60_shell
{
    int m_uiSoundResourceID;
    int pad;
    int eState;
    bool __thiscall FUN_00ad8d60(int param2);
};

struct FUN_00ada300_shell
{
    void FUN_00ada300(float fval, int param);
};

namespace fnv_00adad60 {
struct BottomlessStack
{
    void FUN_00ae76b0();
};
struct BSAudioManager
{
    BottomlessStack m_aiEntries;  // +0x24
    void FUN_00adad60();
};

}  // namespace fnv_00adad60

namespace fnv_00adaf80 {
struct SoundMessageRecord;

struct BottomlessStack
{
    SoundMessageRecord* Pop();
};

struct BSAudioManager
{
    SoundMessageRecord* FUN_00adaf80();
};

}  // namespace fnv_00adaf80

struct FUN_00adb960_shell
{
    bool __thiscall FUN_00adb960(int arg1, int arg2);
};

struct FUN_00adbf40_shell
{
    bool FUN_00adbf40(float f1, float f2, float f3, float f4);
};

struct FUN_00c3d0e0_stub
{
    bool __thiscall FUN_00c3d0e0(char* apDescription, unsigned int aiBufferSize, const char* apName);
};

struct FUN_00ae7480_shell : FUN_00c3d0e0_stub
{
    bool __thiscall FUN_00ae7480(char* apDescription, unsigned int aiBufferSize);
};

struct FUN_00adcaa0_shell
{
    void FUN_00adcaa0(int param_2, int param_3);
};

struct FUN_00ad84b0_shell
{
    void FUN_00ad84b0(int param_2, int param_3);
};

struct FUN_00adcc10_shell
{
    void __thiscall FUN_00adcc10(int, int);
};
struct FUN_00ad8540_shell
{
    void __thiscall FUN_00ad8540(int param1, bool param2);
};

struct S_00ae5f70
{
    int f0;
    char f4;
    int f8;
};
struct C_00ae5f70
{
    S_00ae5f70* __thiscall Init(S_00ae5f70* p, int a2, int a3, int a4, int a5, int a6, int a7);
};

extern int g_011f6ec8;
extern int DAT_011f6ecc;
extern int DAT_01202800;
struct FUN_00ae6c60_shell
{
    int __thiscall FUN_00ae6c60();
};

namespace fnv_00ae6ca0 {
extern int DAT_011f6ec0;
extern char DAT_01202800;
extern int g_011f6ebc;
struct BSAudioManager_shell : BSAudioManager
{
    void __thiscall AddSound(int arg2);
    void __thiscall FUN_00ae6ca0(bool enable);
};
}  // namespace fnv_00ae6ca0

namespace fnv_00ae6cf0 {
extern int g_011f6ebc;
extern bool DAT_011f6ec0;
extern bool DAT_01202800;
struct FUN_00ae6cf0_shell
{
    bool __thiscall FUN_00ae6cf0();
};
}  // namespace fnv_00ae6cf0

extern int DAT_010a3718;

struct _Base_00441d20
{
    _Base_00441d20();
    ~_Base_00441d20();
};

struct FUN_00ae7020_shell : _Base_00441d20
{
    void __thiscall FUN_00ae7020();
};

struct SoundMessageRecord;
struct BottomlessStack
{
    void Push(SoundMessageRecord*);
    SoundMessageRecord* Pop();
    void SetBottomless(bool);
    void* __vecDelDtor(unsigned int);
    unsigned int iCount;
    bool m_bBottomless;
    char _pad_5[3];
    SoundMessageRecord* pTop;
    unsigned int m_uiStackLimit;
};
typedef char _sizecheck_AudioMessageStack[sizeof(BottomlessStack) == 16 ? 1 : -1];
struct FUN_00ae7510_shell : public BottomlessStack
{
    void FUN_00ae7510();
};

struct FUN_00ae7510 : public BottomlessStack
{
    FUN_00ae7510();
};
// Initializes the stack: clears the count, top pointer, bottomless flag and the extra field.
// @fnv 0x00ae7510
FUN_00ae7510::FUN_00ae7510()
{
    iCount = 0;
    pTop = 0;
    m_bBottomless = false;
    m_uiStackLimit = 0;
}

struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager* g_memoryManager;
struct FUN_00ad93f0_shell
{
    void __thiscall FUN_00ad93f0(void);
};
struct FUN_00ae77a0_shell : FUN_00ae7480_shell
{
    void* FUN_00ae77a0(unsigned int flags);
};

namespace fnv_00ae7870 {
struct P03MM
{
    void __thiscall DeallocateAlias(void*);
};
extern P03MM* g_memoryManager;

struct FUN_00ae7870_shell
{
    void __thiscall FUN_00ae78a0();
    void* __thiscall FUN_00ae7870(unsigned int flags);
};

}  // namespace fnv_00ae7870

namespace fnv_00ae7b10 {
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
void __cdecl DeallocateAlias(void*);
struct FUN_00ae7020_shell
{
    void __thiscall FUN_00ae7020();
};
struct AudioLoadTask : FUN_00ae7020_shell
{
    void* __thiscall FUN_00ae7b10(unsigned int flags);
};
}  // namespace fnv_00ae7b10

struct GO
{
    GO& __thiscall operator=(void*);
};
template <typename T> struct NiTPointerAllocator
{
    void __thiscall Deallocate(void*);
};
struct Host00ae8ef0
{
    char _p[12];
    NiTPointerAllocator<unsigned int> alloc;
    void __thiscall FUN_00ae8ef0(void* p);
};

namespace fnv_00ae8f20 {
void __cdecl _NiFreeAlias(void*);
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
extern int DAT_010a3370;
struct S00a0d390
{
    int _0;
    int _4;
    void* _8;
    void __thiscall ClearAll();
    void* __thiscall FUN_00ae8f20(int);
};
}  // namespace fnv_00ae8f20

namespace fnv_00ae9010 {
extern int DAT_010a3390;
void __cdecl _NiFreeAlias(void*);
struct MemoryManager
{
    void __thiscall _DeallocateAlias(void*);
};
extern MemoryManager g_memoryManager;
struct S00a0d390
{
    void __thiscall ClearAll();
};
struct FUN_00ae9010Owner
{
    void* f0;
    int f4;
    void* f8;
    void* __thiscall DestroyOwner(int);
};
}  // namespace fnv_00ae9010

namespace fnv_00ae9100 {
void _NiFreeAlias(void*);
struct S00a0d390
{
    void* _00;
    int _04;
    void* _08;
    void __thiscall ClearAll();
    void* __thiscall FUN_00ae9100(unsigned int);
};
extern int DAT_010a33b0;
struct MemoryManager
{
    void __thiscall Deallocate(void*);
};
extern MemoryManager g_memoryManager;
}  // namespace fnv_00ae9100

struct AudioLoadTask
{
    int _pad[12];
    void* SoundAssetTmp;
    void __thiscall FUN_00ae7360();
};
struct Helper
{
    void __thiscall FUN_00ae6f10(void*);
};

struct BSAudioDefinition
{
    BSAudioDefinition();
};
struct FUN_00ae89f0
{
    unsigned int m_uiSoundID;
    float m_fSoundVolume;
    int _08;
    unsigned int m_uiValueAt0C;
    unsigned int m_uiPlaybackFlags;
    bool m_bValueAt14;
    char _pad[3];
    BSAudioDefinition _18;
    FUN_00ae89f0();
};

struct Setting_00ad9da0
{
    void* vtbl;
    float fValue;
    const char* pKey;
};
extern Setting_00ad9da0 g_011f6e14;
extern Setting_00ad9da0 g_011f6e20;
extern Setting_00ad9da0 g_011f6e2c;
extern Setting_00ad9da0 g_011f6e38;
extern Setting_00ad9da0 g_011f6e44;
extern Setting_00ad9da0 g_011f6e50;
struct AudioVolumes_00ad9da0
{
    float fVal[6];
    float fMult[6];
};
struct FUN_00ad9da0_t
{
    void InitAudioVolumes();
};

struct FUN_00ae6d30_shell
{
    bool __thiscall HasMatchingEntry(unsigned int mask);
};

struct FUN_00ae6e60_shell
{
    bool __thiscall FUN_00ae6e60(int param_2, unsigned char param_3);
};

struct SoundEmitter;
struct AudioLoadTask;
struct BSAudioManager;
struct BSAudioManagerThread;
struct BSGameSound;
struct SoundMessageRecord;
struct NiAVObject;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};

struct Snd_
{
    void __thiscall FUN_00ad7fa0(char const*, int);
};

struct BSAudio : Snd_
{
    unsigned char _pad[6];
    bool bIsMultiThreaded;
};

extern BSAudio* DAT_011f6d98;
extern char $SG6265[];

struct FUN_00ada330_shell
{
    void __thiscall FUN_00ada330();
};

struct FUN_00addc00_shell
{
    void __thiscall FUN_00addc00();
};

struct FUN_00ada1d0_shell
{
    unsigned char _pad[0x134];
    bool m_bUISoundsEnabled;
    void __thiscall InitUISounds(bool);
};

struct BADC7D0Item
{
    unsigned int m_uiKey;
};

class BADC7D0Map
{
  public:
    bool GetAt(unsigned int uiKey, BADC7D0Item*& pkItem);
};

class BADC7D0Cache
{
  public:
    bool ContainsKey(unsigned int uiKey);

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
    BADC7D0Map m_kUnsortedGeometryList;
};

struct CritSecA
{
    int unk[6];
};
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CritSecA* cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CritSecA* cs);

struct ObjEntry
{
    char unk0[0x144];
    int m_144;
    int m_148;
};

struct ObjNode
{
    ObjNode* m_pNext;
    int unk4;
    ObjEntry* m_pEntryObject;
};

struct ObjRegistry
{
    char unk0[0x94];
    ObjNode* m_pHead;
    char unk98[0xdc - 0x98];
    CritSecA m_kCS;

    bool FUN_00add480(int m_uiSoundID, bool bCheckAlt);
};

extern "C" void __cdecl FUN_005b5e40(const char* msg, int value);

extern int g_011f6ec8;
extern int DAT_011f6ecc;
extern int DAT_01202800;

struct AudioCacheOwner
{
    void FUN_00ae6ca0(int flags);
    void SetAudioCacheSize(int size);
};

struct AE6DE0Slot
{
    void* m_pResource;
    unsigned short m_usState;
    unsigned short unk06;
};

class AE6DE0Table
{
  public:
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
    int unk064;
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
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    AE6DE0Slot* m_pkSlots;
    unsigned int m_uiSlotCount;

    bool AddSlot(void* pvData, bool bPrimary);
};

extern "C" int __cdecl CopyRelativeDataPath(int src, char* dst, unsigned int size);

class BaseObj_b5112
{
  public:
    virtual void vfn_0000();
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;

    BaseObj_b5112(int aValue);
    ~BaseObj_b5112();
    void SetupBuffer(char* apBuffer);
    void SetMode(int aMode);
};

class FUN_00ae6f50 : public BaseObj_b5112
{
  public:
    virtual void vfn_0000();
    int m_30;

    FUN_00ae6f50(int aValue);
};

// @f3 0x00bd1060 (community match, verified in this file)
FUN_00ae6f50::FUN_00ae6f50(int aValue) : BaseObj_b5112(0)
{
    m_30 = aValue;
    char buf[0x104];
    CopyRelativeDataPath(m_30 + 0x36, buf, 0x104);
    SetupBuffer(buf);
    SetMode(3);
}


struct Sound7390
{
    virtual void* __thiscall ScalarDeletingDestructor(unsigned int);
    int unk04;
    unsigned int uiFlags08;
    int unk0C;
    unsigned int uiFlags10;
};
struct AudioLoadTask7390
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C;
    Sound7390* SoundAssetTmp;
    void __thiscall ReleaseSound(int, int);
};
struct AudioHelper7390
{
    void __thiscall FUN_00ae6f10();
};
AudioHelper7390* __stdcall FUN_00ad9060(AudioLoadTask7390*);

struct Ptr_6e5cc0
{
    void* p;
    Ptr_6e5cc0& operator=(const Ptr_6e5cc0& rhs);
};

struct Msg_ae7990
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Ptr_6e5cc0 ptr10;
    union
    {
        float f14[3];
        unsigned short s14[5];
    };
    Msg_ae7990& CopyFrom(const Msg_ae7990& rhs);
};

struct AE8470Item;

struct AE8470List
{
    AE8470Item* m_pkItem;
    AE8470List* m_pkNext;

    void SortList(int(__cdecl* pfnCompare)(AE8470Item*, AE8470Item*));
};

struct FUN_00ae8550_shell
{
    void __thiscall FUN_00ae8550(int* values, int(__cdecl* compare)(int, int), int count);
};

struct Setting_01017720_011f96a0
{
    void* m_pVtbl;
    int m_iValue;
};
extern Setting_01017720_011f96a0 g_011f6ee0;

struct BSThread
{
    enum StackSize
    {
        kDefaultStack = 0x8000
    };

    void __thiscall Initialize(StackSize eStackSize, const char* apName, bool abSuspended);
    void __thiscall SetName(const char* apName);
    void __thiscall SetPriority(int aiPriority);
    void __thiscall Wakeup(void);

    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    int m_iThreadId;
};

void __cdecl SetAudioThreadName(int aiHandle, const char* apName);

class AudioThreadHost_00ad9f30
{
  public:
    void FUN_00ad9f30(void);

    int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
    int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
    int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
    int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
    int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
    int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
    int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
    int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
    int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
    int unk120, unk124, unk128, unk12C, unk130, unk134;
    unsigned int m_uiThreadID;
    BSThread* m_pAudioThread;
};

namespace fnv_00add630 {
typedef bool(__cdecl* ADD630ResolveFunc)(const char* pcName, char* pcPath, unsigned int* puiFlags,
                                         unsigned int* puiExtra);

class ADD630Audio
{
  public:
    int unk00;
    bool m_bEnableState;
    char unk05;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ADD630ResolveFunc m_pfnResolve;
};

extern ADD630Audio* DAT_011f6d98;

class ADD630Manager
{
  public:
    void FUN_00add6f0(char* pcPath, unsigned int uiFlags, unsigned int uiExtra);
    void FUN_00add630(const char* pcName, unsigned int uiFlags);
};

}  // namespace fnv_00add630

struct Sub
{
    void __thiscall FUN_00ae88c0(const void* src);
};

struct S
{
    int f0;
    float f4;
    float f8;
    int fc;
    int f10;
    unsigned char f14;
    char pad15[3];
    Sub sub;
    S* __thiscall AssignFrom(const S* src);
};

extern Setting_01017720_011f96a0 g_011f6e74;

struct AudioMgr_adac30
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
    int unk064;
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
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    float m_f140;
    float m_f144;
    float m_f148;
    float m_f14C;
    float m_f150;
    float m_f154;
    float m_f158;
    float m_f15C;
    float m_f160;
    float m_f164;
    float m_f168;
    float m_f16C;

    float FUN_00adac30(float a1, unsigned int a2);
};

extern "C" char DAT_011f6ebc;
extern "C" char DAT_011f6ed4;
extern "C" char DAT_011f6ec8;
struct Sound
{
    virtual ~Sound();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual Sound* Create(int);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void Copy(Sound*, int);
    int p4;
    unsigned int flags;
    char padding[0x138];
    unsigned int id;
    int p148;
    unsigned int size;
};
struct Node
{
    Node* next;
    int p4;
    Sound* sound;
};
struct LinkedSoundQueue
{
    Node* head;
    int p4;
    unsigned int count;
    Sound* FUN_00ae7f90();
    Sound* PopFront();
    void FUN_00a0c9f0(Sound* const&);
};
struct Owner
{
    char pad[0x94];
    LinkedSoundQueue list;
    unsigned int total;
    char more[0x38];
    CritSecA cs;
    void AddSound(Sound*);
};
struct DeleteView
{
    virtual void* Destroy(unsigned int);
};

namespace fnv_00addc70 {
struct LinkedSoundQueue
{
    int pHead;
    int pTail;
    int iCount;
    int __thiscall FUN_00ae7f90();
    void __thiscall FUN_00ae8370();
};
struct FUN_00ae76b0_shell
{
    void __thiscall FUN_00ae75f0(int item);
    int __thiscall FUN_00ae76b0();
};
struct AudioThreadData
{
    int unk00;
    int iWriteIndex;
    int iReadIndex;
    LinkedSoundQueue kLists0;
    LinkedSoundQueue kLists1;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    FUN_00ae76b0_shell kQueue;
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
    CritSecA kLock;
    bool __thiscall FUN_00adf080(int item);
    void __thiscall FUN_00adad80(int item);
    void __thiscall ProcessAudioQueue();
};
}  // namespace fnv_00addc70

struct Handle_ae5680
{
    int f0;
    char f4;
    int f8;
};

typedef bool(__cdecl* Resolver_ae5680)(int, void*, unsigned int*, int*);

struct AudioMgr_011f6d98
{
    void* vtbl;
    bool bReady;
    char pad[0x1f];
    Resolver_ae5680 pfnResolve;
};

struct AudioClass_ae5680
{
    Handle_ae5680 __thiscall FUN_00ae5a50(const void* pPath, unsigned int uiFlags, int iExtra);
    Handle_ae5680* __thiscall ResolveAudioHandle(Handle_ae5680* pOut, int aiSoundId, unsigned int uiFlags);
};

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* addend);
struct FUN_00ae8650_cls
{
    unsigned int m_00, m_04, m_08, m_0c;
    void* m_10;
    float m_14, m_18, m_1c;
    FUN_00ae8650_cls* FUN_00ae8650();
};

extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl FUN_00fdbfd0();
extern int DAT_011f6ef0;
struct FUN_00ad90e0_shell
{
    FUN_00ad90e0_shell();
    ~FUN_00ad90e0_shell();
};

extern "C" __declspec(dllimport) int __stdcall fnv_Import_TryEnterCriticalSection(void*);

struct AudioHelperA
{
    void UpdateAccumulatedTime();
};

struct AudioHelperB
{
    void ProcessAudioQueue();
    void FUN_00adddd0();
};

struct AudioSystemUpdate
{
    unsigned int unk00, unk04, unk08, unk0c, unk10;
    AudioHelperA m_14;
};

struct AudioManagerUpdate
{
    unsigned int unk000, unk004, unk008, unk00c, unk010, unk014, unk018, unk01c;
    unsigned int unk020, unk024, unk028, unk02c, unk030, unk034, unk038, unk03c;
    unsigned int unk040, unk044, unk048, unk04c, unk050, unk054, unk058, unk05c;
    unsigned int unk060, unk064, unk068, unk06c, unk070, unk074, unk078, unk07c;
    unsigned int unk080, unk084, unk088, unk08c, unk090, unk094, unk098, unk09c;
    unsigned int unk0a0, unk0a4, unk0a8, unk0ac, unk0b0, unk0b4, unk0b8, unk0bc;
    unsigned int unk0c0, unk0c4, unk0c8, unk0cc, unk0d0, unk0d4, unk0d8;
    CritSecA critical0dc;
    CritSecA m_cs;
    void FUN_00addc00();
};

extern "C" __declspec(dllimport) void* __stdcall CreateSemaphoreA(void*, long, long, const char*);
struct S_00ae77d0_Sem
{
    long initial;
    void* h;
    long max;
};
struct S_00ae77d0_Base
{
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
    S_00ae77d0_Base();
    virtual void v0();
};
struct FUN_00ae77d0 : S_00ae77d0_Base
{
    S_00ae77d0_Sem sem0;
    S_00ae77d0_Sem sem1;
    char unk48;
    FUN_00ae77d0();
    virtual void v0();
};

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* h, long n, long* prev);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* h, unsigned long ms);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* addend);

struct SyncSemaphore
{

    volatile long count;

    void* handle;
};

struct AudioWorker
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

    SyncSemaphore waitSemaphore;

    unsigned int unk38;

    SyncSemaphore signalSemaphore;

    unsigned int unk44;

    bool processing;

    void FUN_00ae7a50();
};

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*, long, long*);

struct BSSemaphore_adf080
{
    long count;
    void* semaphore;
};

struct BSAudioManagerThread
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    unsigned int unk20, unk24, unk28, unk2c;
    BSSemaphore_adf080 doneSemaphore30;
    unsigned int unk38;
    BSSemaphore_adf080 workSemaphore3c;
    unsigned int unk44;
    bool waiting48;

    void __thiscall FUN_00aa6590(int, int);
    void FUN_00ae7ac0();
};

struct S00ae6f10_SubObj_00ae6f10
{
    void __thiscall FUN_00ae8150(void* p);
};
struct S00ae6f10_FUN_00ae6f10_cls
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
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    CritSecA m_10c;
    S00ae6f10_SubObj_00ae6f10 m_124;
    void FUN_00ae6f10(int arg);
};

struct S00ae6f10_FUN_00ae6f10_frame
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
};

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long milliseconds);
extern int DAT_01202d98;

struct AudioThreadEntry : BSAudioManagerThread
{
    int FUN_00ae74b0();
};

struct ScrapHeapBuffer;
struct BSMapBase
{
    bool __thiscall GetAt(unsigned long, ScrapHeapBuffer*&);
};
struct FUN_00adc8b0_shell
{
    float __thiscall FUN_00adc8b0(unsigned long);
};

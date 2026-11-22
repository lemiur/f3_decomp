#include "f3_common.h"
// src/staging/blk_004c0000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct FUN_004dfdd0_StandIn
{
    float m_f0;
    float m_f4;
    float m_f8;
    float m_fC;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1C;
    float m_f20;
    void InitIdentity();
};

struct FUN_004d4e10_StandIn
{
    void FUN_004d4eb0();
    void* DestroyIfFlagged(unsigned int flags);
};

void __cdecl ClearGlobalArray();

struct FUN_004d5d40_Class
{
    void __thiscall FUN_004d5d40();
};

extern void(__stdcall* DAT_00fdf28c)(void*, int, int, int);

struct FUN_004d7490_Class
{
    void FUN_004d7490();
};

struct ArrSI
{
    unsigned int GetFlags();
};
struct FUN_004d7d50_StandIn
{
    unsigned int __thiscall FUN_004d7d50();
};

struct FUN_004d8510_StandIn
{
    void GetResultValue(int);
    void FUN_004d8510();
};

struct TESObjectREFR;
struct bhkShape;
bhkShape* __cdecl FUN_004a3a40(void*);
void* GetLocalSubValue(TESObjectREFR* p, int a);
struct FUN_004d85a0_Class
{
    void* GetLocalSubValue(int a);
    void* FUN_004d85a0(int a);
};

struct FUN_004d8670_Class
{
    BSSimpleList<int>* GetListNext();
};

struct FUN_004d8a00_Class
{
    unsigned short GetField3C();
};

struct FUN_004d8a20_Class
{
    int m_f0;
    int m_f4;
    int m_f8;
    int m_fC;
    int m_f10;
    int m_f14;
    int m_f18;
    int m_f1C;
    int m_f20;
    int m_f24;
    int m_f28;
    int m_f2C;
    int m_f30;
    int m_f34;
    int* m_p38;
    int GetEntry(unsigned short index);
};

extern int DAT_01020fe4;
struct FUN_004d8fa0_StandIn
{
    int m_p;
    void FUN_004d9000(int a);
    FUN_004d8fa0_StandIn* FUN_004d8fa0(int a);
};

struct FUN_004d9190_Class
{
    void __thiscall FUN_004d91b0();
    void __thiscall FUN_004d9190();
};

struct FUN_004dc020_Class
{
    unsigned int m_p288;
    unsigned int FUN_004dc020();
};

struct FUN_004dc1c0_Class
{
    int m_i0;
    int m_i4;
    char HasNonZeroValue();
};

extern char DAT_011c6fc8;
void __cdecl ___insecure_strcpy(char* dst, const char* src);

struct Arr
{
    unsigned int GetSize();
};
struct FUN_004dcce0_Class
{
    void FUN_004dcce0();
};

namespace fnv_004dcd00 {
struct Arr
{
    unsigned int* GetAt(int);
};
struct FUN_004dcd00_Class
{
    unsigned int m_450;
    unsigned int GetElementAt(int idx);
};
}  // namespace fnv_004dcd00

struct FUN_004dcd60_Class
{
    unsigned char GetByteAt140();
};

struct FUN_004dd220_Class
{
    unsigned int GetField5C8();
};

void __stdcall ClearAndFreePointer(void*);

struct FUN_004de290_StandIn
{
    float m_f0;
    float m_f4;
    FUN_004de290_StandIn* SetValue(float);
};

struct FUN_004de2b0_StandIn
{
    FUN_004de2b0_StandIn* __thiscall SetCharAtOffset4(char c);
};

extern unsigned char DAT_011c77e9;
extern float DAT_011c77ec;

struct GlobalObject_004aff00
{
    void RemoveAll();
};

struct FUN_004def90_Class
{
    void FUN_004def90();
};

struct GO
{
    GO& operator=(void*);
};

struct FUN_004dfe80_Class
{
    GO m_p[12];
    void SetSlotValue(int index, void* value);
};

struct MersenneTwister
{
    static MersenneTwister* GetRandomGenerator();
};

struct FUN_004dfec0_StandIn
{
    void FUN_004dfec0();
};

void _NiFreeAlias(void*);
struct FUN_004d4f10_StandIn : public NiTPointerMap<int, int>
{
    void FUN_004d4f10();
};

extern "C" void NiFreeAlias(void*);

extern int DAT_01021004;

struct FUN_004d90d0_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void FUN_004d90d0();
};

void Deallocate(void*);
struct FUN_004d8fd0_Class
{
    void __thiscall FUN_004d9070();
    void* __thiscall Destroy(unsigned int flags);
};

void __cdecl Deallocate(void* p);
struct FUN_004d9160_Class : public FUN_004d9190_Class
{
    void* FUN_004d9160(unsigned int flags);
};

extern int DAT_01020924;
struct FUN_004d4e40_Holder
{
    void __thiscall FUN_004d4e40(unsigned int);
};
struct FUN_004d4de0_Class
{
    void* __thiscall FUN_004d4de0(unsigned int);
};

extern "C" void* __cdecl NiMalloc(unsigned int size);
extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);
extern int DAT_01020944;
struct FUN_004d4e40_Class
{
    void* m_pVT;
    unsigned int m_uiSize;
    void* m_pData;
    unsigned int m_uiCount;
    FUN_004d4e40_Class(unsigned int size);
};

void __cdecl _Deallocate(void*);
struct FUN_004d4f40_StandIn
{
    void* __thiscall FUN_004d4f40(unsigned int flags);
};

struct FUN_004d5c20_Base
{
    virtual int __thiscall FUN_000(int);
};
struct FUN_004d5c20_StandIn
{
    FUN_004d5c20_Base* m_p0;
    void __thiscall FUN_004d5c20();
};

void __cdecl _Deallocate(void*);
struct FUN_004d5dd0_Class
{
    void __thiscall FUN_004d5c20();
    void* __thiscall FUN_004d5dd0(unsigned int);
};

extern void* DAT_011c6d50[43];

extern void*(__stdcall* DAT_00fdf020)(void*, int, int, int, int, int, int);
struct FUN_004d6490_Class
{
    void* m_p0;
    void* m_p4;
    void* m_p8;
    void* m_pC;
    void* m_p10;
    void* m_p14;
    void __thiscall FUN_004d6490();
};

extern void(__stdcall* DAT_00fdf290)(void*);
struct FUN_004d7440_Class
{
    char _0[8];
    void* p8;
    void* pC;
    void __thiscall FUN_004d7440();
};
// @f3 0x004c1150 (community match, verified in this file)
struct ReleaseTarget {
    void FUN_004d81b0(int mode);
};
struct LinkedNode {
    unsigned int unk00, unk04, unk08;
    ReleaseTarget* target;
};
struct LinkReceiver {
    void FUN_004c0fe0(LinkedNode* node);
};
void FUN_004d7440_Class::FUN_004d7440() {
    ((LinkReceiver*)*(void**)((char*)this + 0x18))
        ->FUN_004c0fe0((LinkedNode*)*(void**)((char*)this + 0x1c));
    ((LinkedNode*)*(void**)((char*)this + 0x1c))
        ->target->FUN_004d81b0(1);
}


extern int(__cdecl* DAT_011c6f18)(int, int, int, int);

void* __cdecl FUN_004b5a80(void const*);
struct FUN_004d8530_Class
{
    virtual void const* f00();
    virtual void const* f01();
    virtual void const* f02();
    virtual void const* f03();
    virtual void const* f04();
    virtual void const* f05();
    virtual void const* f06();
    virtual void const* f07();
    virtual void const* f08();
    virtual void const* f09();
    virtual void const* f10();
    virtual void const* f11();
    virtual void const* f12();
    virtual void const* f13();
    virtual void const* f14();
    virtual void const* f15();
    virtual void const* f16();
    virtual void const* f17();
    virtual void const* f18();
    virtual void const* f19();
    virtual void const* f20();
    virtual void const* f21();
    virtual void const* f22();
    virtual void const* f23();
    virtual void const* f24();
    virtual void const* f25();
    virtual void const* f26();
    virtual void const* f27();
    virtual void const* f28();
    virtual void const* f29();
    virtual void const* f30();
    virtual void const* f31();
    virtual void const* f32();
    virtual void const* f33();
    virtual void const* f34();
    virtual void const* f35();
    virtual void const* f36();
    virtual void const* f37();
    virtual void const* f38();
    virtual void const* f39();
    virtual void const* f40();
    virtual void const* f41();
    virtual void const* f42();
    virtual void const* f43();
    virtual void const* f44();
    virtual void const* f45();
    virtual void const* f46();
    virtual void const* f47();
    virtual void const* f48();
    virtual void const* f49();
    virtual void const* f50();
    virtual void const* f51();
    virtual void const* f52();
    void* __thiscall FUN_004d8530();
};

struct FUN_004d8560_Inner
{
    virtual void f0();
    virtual void* f1();
};
struct FUN_004d8560_Outer
{
    char _0[0x10];
    FUN_004d8560_Inner _10;
};
struct ScriptLocalsX
{
    FUN_004d8560_Outer* GetLocalData();
};
struct FUN_004d8560_StandIn
{
    void* __thiscall GetInnerVirtualResult();
};

namespace fnv_004d8630 {
struct ScriptLocalsX
{
    void* __thiscall GetLocalData();
};
struct FUN_004d8630_Class
{
    bhkShape* __thiscall GetShape();
};
}  // namespace fnv_004d8630

void* __cdecl NiMalloc(unsigned int size);
void* __cdecl memset(void* dest, int value, unsigned int count);

struct FUN_004d8fa0_Class
{
    int* m_p0;
    unsigned int m_i4;
    void* m_p8;
    unsigned int m_iC;
    FUN_004d8fa0_Class* FUN_004d9000(unsigned int size);
};

void __cdecl _Deallocate(void*);
struct FUN_004d9130_Class
{
    void* __thiscall FUN_004d9130(unsigned int flags);
};

void __cdecl _Deallocate(void*);
struct FUN_004d91e0_Class : public FUN_004d9190_Class
{
    void* __thiscall FUN_004d91e0(unsigned int flags);
};

void Deallocate(void* p);

struct FUN_004d9380_Class
{
    char m_p0;
    void* m_p4;
    void __thiscall FreeAndClear();
};

extern unsigned char DAT_011f4508;

extern bool DAT_011a9594;

extern unsigned char DAT_011f9180;

extern int DAT_011f91c0;
extern int DAT_011f948c;
unsigned int __cdecl BSStringCapacityMaximum(unsigned int a, unsigned int b);
unsigned int __cdecl FUN_0042f5a0(unsigned int a, unsigned int b);

extern int DAT_011f916c;

struct TgtOps
{
    void* GetPosition();
};
struct FUN_004dc120_StandIn
{
    TgtOps* __thiscall FUN_004dc160(int a);
    void* __thiscall FUN_004dc120(int a);
};

struct FUN_004dc160_StandIn
{
    unsigned int FUN_004dc160(int a);
};

struct GlobalObject_004a4a40
{
    int GetCellStandValue();
};
extern GlobalObject_004a4a40 g_011c738c;

struct CellStand
{
    int GetCellStandValue();
};
struct GlobalObject_0045cfe0
{
    CellStand m_cell;
};
extern GlobalObject_0045cfe0 g_011c7100;

extern float DAT_0118945c;
extern float DAT_011ad83c;
extern char DAT_011c6fb8;
extern double _gModifierZero;

struct Flt
{
    operator unsigned int();
};
struct Date
{
    ~Date();
};
struct NiNode;
extern NiPointer<NiNode> g_011dee84;

namespace fnv_004dc590 {
struct Flt
{
    operator unsigned int();
};
struct Date
{
    ~Date();
};
struct GlobalObject_00633c90
{
    char _pad;
};
extern GlobalObject_00633c90 g_011deca4;
}  // namespace fnv_004dc590

extern "C" unsigned char __cdecl FUN_00446e10(void);
struct S0042fa20
{
    S0042fa20* FUN_0045ce80(int);
};
extern S0042fa20 g_011c75d4;
extern S0042fa20 g_011c7654;

struct FUN_004dcd30_Class
{
    FUN_004dcd60_Class* __thiscall FUN_004dc160(int p);
    unsigned char __thiscall FUN_004dcd30(int p);
};

struct G7d1
{
    bool GetBoolValue();
};
G7d1 g_011c726c;

struct MyArr_GetAt
{
    unsigned int* GetAt(int);
};
struct FUN_004dcdf0_Class
{
    int _0;
    union
    {
        Arr a;
        MyArr_GetAt m;
    } _4;
    unsigned int __thiscall FUN_004dcdf0(unsigned int index);
};

void __cdecl _Deallocate(void*);
struct FUN_004de550_StandIn
{
    void __thiscall FUN_0045d240();
    void* __thiscall FUN_004de550(unsigned int);
};

struct NiTexture;
struct SkyTextureManager
{
    static void __cdecl LoadTextureFromPath(NiPointer<NiTexture>*, char const*);
};
extern NiPointer<NiTexture> DAT_011c7804[];

struct FUN_004d4f70
{
    unsigned int m_uiCount;
    int m_iParam;
    float** m_ppfA;
    float** m_ppfB;

    FUN_004d4f70(unsigned int ItemUpdateArray, int iParam);
};

extern "C" void __cdecl FUN_00401030(void*);

struct FUN_004d5080_Class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;

    void __thiscall FUN_004d5080();
};

struct GlobalObject_0044f440
{
    float* Float();
};
extern GlobalObject_0044f440 g_011c6528;
extern GlobalObject_0044f440 g_011c6534;
extern GlobalObject_0044f440 g_011c651c;

struct Buf
{
    unsigned int m0;
    unsigned int m4;
    float** p8;
    float** pC;
    Buf(unsigned int a, unsigned int b);
    ~Buf();
};

extern double DAT_010209a8;

struct FUN_004d5a90_Class
{
    int m_i0;
    int m_i4;
    float GetNegativeMagnitude();
};

extern "C" int __cdecl sprintf_s(char* destination, unsigned int size, const char* format, ...);
extern const char DAT_01020d58[];

struct FUN_0040c150
{
    int value0;
    int value4;
    int value8;
    FUN_0040c150(char* text, int index);
};

struct FUN_004d5b60
{
    FUN_0040c150* object;
    int value;
    FUN_004d5b60(int index, int number, int extra);
};

namespace fnv_004d5c80 {
struct FUN_004d5b60
{
    char* m_p0;
    unsigned short m_w4;
    unsigned short m_w6;
    FUN_004d5b60(const char* name, unsigned int index, unsigned short flags);
};
extern void* DAT_011c6d50[43];
extern const char* DAT_01189280[43];

}  // namespace fnv_004d5c80

extern void* DAT_011c6d50[43];

extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);

extern int DAT_011f36f4;
extern int DAT_011f36f8;
void __cdecl _Deallocate(void* p);

struct FUN_004d9070
{
    ~FUN_004d9070();
};

struct FUN_004d62a0_Class
{
    int m_00;
    int m_04;
    int m_08;
    int m_0C;
    int m_10;
    int m_14;
    FUN_004d9070 m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    void* m_p2C;

    void __thiscall FUN_004d7490();
    void __thiscall FUN_004d7470();
    void __thiscall FUN_004d7440();
    ~FUN_004d62a0_Class();
};

struct InitCommonControls4d63
{
    unsigned long m_ulSize;
    unsigned long m_ulICC;
};
struct Rect4d63
{
    long left;
    long top;
    long right;
    long bottom;
};
struct WndClass4d63
{
    unsigned int style;
    long(__stdcall* lpfnWndProc)(void*, unsigned int, unsigned int, long);
    int cbClsExtra;
    int cbWndExtra;
    void* hInstance;
    void* hIcon;
    void* hCursor;
    void* hbrBackground;
    const char* lpszMenuName;
    const char* lpszClassName;
};

extern int(__stdcall* DAT_00fdf024)(InitCommonControls4d63*);
extern void*(__stdcall* DAT_00fdf280)(void*, const char*);
extern void*(__stdcall* DAT_00fdf2a0)(void*, const char*);
extern void*(__stdcall* DAT_00fdf03c)(int);
extern unsigned short(__stdcall* DAT_00fdf2b4)(const WndClass4d63*);
extern void*(__stdcall* DAT_00fdf2b8)(unsigned long, const char*, const char*, unsigned long, int, int, int, int, void*,
                                      void*, void*, void*);
extern int(__stdcall* DAT_00fdf2bc)(void*, Rect4d63*);
const char* PrepareScriptMessage(const char* pcText, bool bFlag);
extern char DAT_01189338[];
long __stdcall FUN_004d75b0(void* hWnd, unsigned int auiMessage, unsigned int wParam, long lParam);

struct TreeCtrl4d63
{
    void* m_hInstance;
    int unk04;
    void* m_hWnd;
    void* m_hTreeWnd;
    int unk10[7];
    const char* m_pcTitle;
    void CreateTreeWindows(int iX, int iY, int iWidth, int iHeight);
};

struct ClearMap64
{
    int unk00;
    void __thiscall FUN_00438af0();
};
const char* __cdecl FUN_00464f30(const char* value, bool format);
typedef int(__stdcall* SendMessageResult64)(void*, int, int, int);
extern void(__stdcall* DAT_00fdf288)(void*, int);
extern void(__stdcall* DAT_00fdf284)(void*);
struct Header64
{
    int primary, secondary, tertiary, unused0c, unused10, unused14;
};
struct Params64
{
    const char* message;
    int unused04;
    int flags;
    int flagsCopy;
    int unused10;
    int number;
    int status18;
    int context1c;
    int callback20;
    int source24;
};
struct Owner64
{
    void* unk00;
    void* unk04;
    void* window;
    void* dialog;
    int result;
    int hwndContext;
    ClearMap64 messageMap;
    int unk1c, unk20, unk24, unk28;
    const char* defaultText;
    void __thiscall FUN_004d66d0(int a, int b);
    void __thiscall FUN_004d64c0(int value, const char* text);
};

extern void(__stdcall* DAT_00fdf01c)(void*);
struct FUN_004d7470_StandIn
{
    char _0[20];
    void* p14;
    void __thiscall FUN_004d7470();
};

extern char DAT_011c6e10;
void __cdecl FUN_00403d30(void* destination, int pNodeValue, unsigned int size);
typedef int(__stdcall* SendTreeMessage)(void*, int, int, int);

struct FUN_004d74c0_Value
{
    int FUN_00453470();
};
struct FUN_004d74c0_Node
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual FUN_004d74c0_Value* getValue();
};
struct FUN_004d74c0_Item
{
    unsigned int mask;
    int handle;
    int state;
    int stateMask;
    char* text;
    int textCapacity;
    int image;
    int selectedImage;
    int children;
    FUN_004d74c0_Node* itemData;
    int integral;
    int stateEx;
    void* hwnd;
    int expandedImage;
};

int FUN_00406d30(char* pcDest, unsigned int uiSize, const char* pcSrc);
int FUN_00406d50(char* pcDest, unsigned int uiSize, const char* pcSrc);

class NiObject
{
  public:
    int m_aiObject[2];
};

class NiFixedString
{
  public:
    operator const char*() const;
    const char* m_kHandle;
};

struct NiUpdateData
{
    float m_fTime;
    bool m_bUpdate;
    bool m_bIsMultiThreaded;
    int m_pkUpdateProcess;
    NiUpdateData(float fTime, bool m_bUpdateEnabled, bool bIsMultiThreaded);
};

class NiAVObject : public NiObject
{
  public:
    void FUN_00450f90(bool bCulled);
    void FUN_00a5a040();
    void Update(NiUpdateData& kUpdateData);
    NiFixedString& GetName();
};

class NiStream
{
  public:
    NiStream();
    ~NiStream();
    void InsertObject(NiObject* pkObject);
    bool FUN_00a640b0(const char* pcFileName);
    int m_kNextStreamField[0x172];
};

struct NiObject;
struct NiRTTI
{
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};
extern const NiRTTI DAT_012024e0;
NiObject* __cdecl FUN_00653270(const NiRTTI*, NiObject*);

const char* __cdecl PrepareScriptMessage(const char* msg, bool flag);

class BGSAddonNode;
struct Holder_004d9100 : public NiTArray<BGSAddonNode*, NiTMallocInterface<BGSAddonNode*> >
{
    Holder_004d9100(int a, int b);
};

struct NiTArray_Layout;
void __fastcall FUN_005e03d0(NiTArray_Layout*);

class ActorPathingMessageQueue;

struct Name
{
    const char* FUN_00559450() const;
};
struct ItemClass
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual Name& GetName();
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
    virtual void FillHolders(Holder_004d9100* holder);
};

struct MsgStruct
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    const char* unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    void* unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
};

void __cdecl FUN_004add50(char* dst, const char* src, unsigned int count);

struct ObjClass : public FUN_004d7d50_StandIn
{
    ItemClass* __thiscall GetByIndex(unsigned int);
};

typedef int(__stdcall* DAT_00fdf28c_fn)(void*, int, int, void*);

struct HostClass
{
    int unk00;
    int unk04;
    int unk08;
    void* unk0C;
    void __thiscall SendModifierMessages(int a1, NiObject* a2);
};

extern "C" char DAT_01267b70;
extern "C" char DAT_01020ebc;
struct Node7
{
    virtual void v0();
    virtual void v1();
    virtual void* v2();
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
    virtual void v24(void*);
    void* FUN_006fa820();
};
struct FUN_004d9100
{
    FUN_004d9100(int, int);
    virtual ~FUN_004d9100();
    char pad[12];
    unsigned GetShortAtOffsetA();
    char** FUN_00877a30(unsigned);
    void FUN_005e03d0();
};
Node7* __cdecl FUN_00653270(void*, Node7*);
const char* __cdecl FUN_00464f30(const char*, bool);
const char* __fastcall FUN_00559450(void*);
void __cdecl FUN_004add50(char*, const char*, unsigned);
struct Insert7
{
    void* parent;
    unsigned after, mask;
    unsigned item, state, stateMask;
    const char* text;
    int max, image, selected, children;
    Node7* param;
    int extra[4];
};
struct C7
{
    char pad[12];
    void* hwnd;
    void BuildTreeItems(void*, void*);
    void AddChildTreeItem(void* parent, Node7* node);
};

namespace fnv_004d80b0 {
struct FUN_004d9100
{
    virtual ~FUN_004d9100();
    unsigned int length;
    unsigned int capacity;
    void* elements;
    FUN_004d9100(unsigned int initialCapacity, unsigned int growthCapacity);
    unsigned int GetShortAtOffsetA();
    void** FUN_00877a30(unsigned int index);
    void FUN_005e03d0();
};
struct FNVObjectName
{
    void* FUN_00559450();
};
struct FNVTreeNode
{
    virtual void* f0();
    virtual void* f1();
    virtual FNVObjectName* GetName();
    virtual void* f3();
    virtual void* f4();
    virtual void* f5();
    virtual void* f6();
    virtual void* f7();
    virtual void* f8();
    virtual void* f9();
    virtual void* f10();
    virtual void* f11();
    virtual void* f12();
    virtual void* f13();
    virtual void* f14();
    virtual void* f15();
    virtual void* f16();
    virtual void* f17();
    virtual void* f18();
    virtual void* f19();
    virtual void* f20();
    virtual void* f21();
    virtual void* f22();
    virtual void* f23();
    virtual void CollectChildren(FUN_004d9100* result);
};
struct FNVTreeItem
{
    unsigned int mask;
    void* itemHandle;
    unsigned int state;
    unsigned int stateMask;
    char* text;
    int textCapacity;
    int image;
    int selectedImage;
    int nodeArray;
    FNVTreeNode* node;
    int integralHeight;
    unsigned int extendedState;
    void* ownerWindow;
    int expandedImage;
};
struct FNVTreeInsert
{
    void* parent;
    void* insertAfter;
    FNVTreeItem item;
};
struct FNVChildLink
{
    FNVObjectName* FUN_006815c0();
    FNVChildLink* FUN_00726070();
};
struct FNVTypeA
{
    FNVObjectName* FUN_004ae6a0();
};
struct FNVTypeB
{
    int GetNodeCount();
    FNVChildLink* FUN_007d6bb0();
};
struct FNVTypeC
{
    FNVTreeNode* GetShape();
};
struct FNVTypeD
{
    unsigned int GetInnerVirtualResult();
    FNVTreeNode* FUN_004d85a0(unsigned int index);
};
struct FNVTypeE
{
    FNVTreeNode* FUN_004d8510();
};
struct FNVTypeF
{
    FNVTreeNode* FUN_004d8530();
};
extern unsigned char DAT_01268110;
extern unsigned char DAT_012681c0;
extern unsigned char DAT_01268100;
extern unsigned char DAT_012681b4;
extern unsigned char DAT_012681a8;
extern unsigned char DAT_01268198;
extern unsigned char DAT_0126818c;
extern void* __cdecl FUN_00653270(const void*, void*);
extern char* __cdecl FUN_00464f30(const void*, int);
extern void __cdecl FUN_004add50(char*, const char*, unsigned int);
struct FUN_004d80b0_Class
{
    void* m_object;
    void* m_pOwnerObject;
    void* m_pTreeNode;
    void* m_treeWindow;
    void __thiscall BuildTreeItems(void* parent, FNVTreeNode* node);
};
}  // namespace fnv_004d80b0

struct FUN_0062e150_Obj
{
    int* FUN_0062e150(int a1);
};
struct FUN_004d8610_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    FUN_0062e150_Obj sub18;
    int GetSubValue(int arg);
};

struct TreeItem4d86
{
    unsigned int mask;
    void* hItem;
    unsigned int state;
    unsigned int stateMask;
    const char* pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    long lParam;
    int iIntegral;
    unsigned int uStateEx;
    void* hwnd;
    int iExpandedImage;
};

struct TreeInsert4d86
{
    void* hParent;
    void* hInsertAfter;
    TreeItem4d86 item;
};

typedef void*(__stdcall* SendMessage4d86)(void*, int, int, int);

const char* PrepareScriptMessage(const char* pcText, bool bFlag);

struct MediaSet4d86
{
    int FUN_008041a0();
};

struct Palette4d86;

struct Object4d86
{
    Palette4d86* GetStringAtOffset();
    unsigned int FUN_00495d00();
    MediaSet4d86* FUN_00495d20(unsigned int uiIndex);
};

struct TreeCtrl4d86
{
    void* m_hInstance;
    int unk04;
    void* m_hWnd;
    void* m_hTreeWnd;
    void AddNameItems(void* hParent, Palette4d86* pkPalette);
    void FUN_004d8b90(void* hParent, MediaSet4d86* pkSet);
    void PopulateObjectTree(void* hParent, Object4d86* pkObject);
};

struct TreeItem4d88
{
    unsigned int mask;
    void* hItem;
    unsigned int state;
    unsigned int stateMask;
    const char* pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    long lParam;
    int iIntegral;
    unsigned int uStateEx;
    void* hwnd;
    int iExpandedImage;
};

struct TreeInsert4d88
{
    void* hParent;
    void* hInsertAfter;
    TreeItem4d88 item;
};

typedef void*(__stdcall* SendMessage4d88)(void*, int, int, int);

extern const char DAT_01020f14[];
const char* PrepareScriptMessage(const char* pcText, bool bFlag);

struct Target4d88
{
    const char** FUN_00413f40();
};

struct Interp4d88;

struct BlendInterp4d88
{
    unsigned short GetField3C();
    Target4d88* GetEntry(unsigned short usIndex);
    Interp4d88* GetExtraDataAt(unsigned short usIndex);
};

struct TreeCtrl4d88
{
    void* m_hInstance;
    int unk04;
    void* m_hWnd;
    void* m_hTreeWnd;
    void AddNameItems(void* hParent, Interp4d88* pkInterp);
    void AddBlendInterpTreeItems(void* hParent, BlendInterp4d88* pkBlend);
};

namespace fnv_004d8a40 {
struct TreeItem4d8a
{
    unsigned int mask;
    void* hItem;
    unsigned int state;
    unsigned int stateMask;
    const char* pszText;
    int cchTextMax;
    int iImage;
    int iSelectedImage;
    int cChildren;
    long lParam;
    int iIntegral;
    unsigned int uStateEx;
    void* hwnd;
    int iExpandedImage;
};

struct TreeInsert4d8a
{
    void* hParent;
    void* hInsertAfter;
    TreeItem4d8a item;
};

const char* PrepareScriptMessage(const char* pcText, bool bFlag);

struct FUN_004d9100
{
    FUN_004d9100(int aiInitialSize, int iGrowBy);
    virtual ~FUN_004d9100();
    unsigned int GetShortAtOffsetA();
    const char** FUN_00877a30(unsigned int uiIndex);
    void FUN_005e03d0();
    int unk04[3];
};

struct NameSource4d8a
{
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void GetNames(FUN_004d9100* pkNames);
};

struct TreeCtrl4d8a
{
    void* m_hInstance;
    int unk04;
    void* m_hWnd;
    void* m_hTreeWnd;
    void AddNameItems(void* hParent, NameSource4d8a* pkSource);
};

}  // namespace fnv_004d8a40

void* __cdecl FUN_0096afc0(unsigned int size);

struct FUN_004d9210
{
    virtual ~FUN_004d9210();
    void* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;

    FUN_004d9210(unsigned short capacity, unsigned short growBy);
};

class DepthDevice;

extern DepthDevice* DAT_0126f0d8;

extern int DAT_011f94b8;

char* DAT_01202fa0;

extern int DAT_011c6fbc;

extern unsigned int DAT_0118947c;

extern int DAT_01189480;

extern unsigned int DAT_01189478;

extern int DAT_011c70d4;

extern int DAT_011c70d8;

extern int DAT_01189464;

extern int DAT_011c70d0;

extern int DAT_01189470;

extern int DAT_01189474;

extern int DAT_011c70cc;

extern int DAT_011c6fb0;

extern "C" void* DAT_011c74b8;

extern int DAT_01189468;

extern int DAT_0118946c;

namespace fnv_004dd180 {
struct FUN_00559450_Object
{
    void* FUN_00559450();
};
extern FUN_00559450_Object DAT_011c73b4;
struct FUN_004b9930_Object
{
    unsigned char FUN_004b9930(int id, int enabled);
};
extern FUN_004b9930_Object DAT_011c77b4;
int __cdecl FUN_004dc270();
int __cdecl MapIndexToValue(int value);
int __stdcall FUN_004dc210(int value);
struct FUN_004dd220_Object
{
    int GetField5C8();
};
struct DispatchInterface;
struct DispatchVTable
{
    void* method00;
    void* method01;
    void* method02;
    void* method03;
    void* method04;
    void* method05;
    void* method06;
    void* method07;
    void* method08;
    void* method09;
    void* method10;
    long(__stdcall* dispatch)(DispatchInterface*, int, int, int);
};
struct DispatchInterface
{
    DispatchVTable* vtable;
};
DispatchInterface* __cdecl FUN_004dc040();
}  // namespace fnv_004dd180

extern float DAT_01189490;

struct DisplayDevice4de1
{
    unsigned long cb;
    char DeviceName[32];
    char DeviceString[128];
    unsigned long StateFlags;
    char DeviceID[128];
    char DeviceKey[128];
};

struct EyefinityInfo4de1
{
    int iSLSActive;
    int iSLSGridWidth;
    int iSLSGridHeight;
    int iSLSWidth;
    int iSLSHeight;
    int iPadding;
};

struct DisplayInfo4de1
{
    int iGridXCoord;
    int iGridYCoord;
    int iRectLeft;
    int iRectTop;
    int iRectRight;
    int iRectBottom;
};

extern int(__stdcall* DAT_00fdf2f0)(const char*, unsigned long, DisplayDevice4de1*, unsigned long);
int __cdecl FUN_004dd2c0(int iPrimaryDisplay, EyefinityInfo4de1* pkInfo, int* piNumTargets,
                         DisplayInfo4de1** ppkTargets);
int __cdecl FUN_00ec9d4a(const char* pcFormat, ...);
extern bool DAT_01189484;
extern float DAT_01189488;
extern float DAT_0118948c;
extern float DAT_01189490;
extern "C" float DAT_01189494;
extern float DAT_01189498;
extern bool DAT_011c70ed;
extern bool DAT_011c70ee;
extern bool DAT_011c70ef;
extern float DAT_011c70f0;

struct FUN_004de2d0_StandIn : FUN_004de2b0_StandIn
{
    FUN_004de2b0_StandIn* __thiscall FUN_004de2d0(char c);
};

extern "C" void __cdecl FUN_00401030(void*);

struct FUN_004de3f0_Class
{
    void __thiscall FUN_004de420();
    void* __thiscall FUN_004de3f0(int flags);
};

struct INISettingCollection
{
    INISettingCollection();
    virtual void v0();
};
struct FUN_004de530 : public INISettingCollection
{
    FUN_004de530();
};
// @fnv 0x004de530
FUN_004de530::FUN_004de530()
{}

extern char DAT_011c77e8;
extern void* DAT_011c7810;
extern void* DAT_011c781c;
struct FUN_00559450_Helper
{
    void* FUN_00559450();
};
struct FUN_0066b0d0_Helper
{
    void FUN_004def90();
    void FUN_0066b0d0(int);
};

void* __cdecl operator new(unsigned int uiSize);
void __cdecl operator delete(void* pvMem);

class C4DF040Object
{
  public:
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
};

class C4DF040Point3
{
  public:
    C4DF040Point3();
    C4DF040Point3(float fX, float fY, float fZ);

    C4DF040Point3 operator+(const C4DF040Point3& kPt) const;

    float x;
    float y;
    float z;
};

class C4DF040Point2
{
  public:
    C4DF040Point2();
    C4DF040Point2(float fX, float fY);

    C4DF040Point2 operator+(const C4DF040Point2& kPt) const;

    float x;
    float y;
};

class C4DF040Matrix3
{
  public:
    C4DF040Matrix3();

    void MakeRandomRotation();
    C4DF040Point3 operator*(const C4DF040Point3& kPt) const;

    float m_afEntries[3][3];
};

class C4DF040Texture;

class C4DF040TexturePtr
{
  public:
    C4DF040Texture* Get();

    C4DF040Texture* m_pPointer;
};

class C4DF040Property : public C4DF040Object
{
  public:
    C4DF040Property();

    void SetTexture(int iSlot, C4DF040Texture* pkTexture);

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
};

class C4DF040TriShape : public C4DF040Object
{
  public:
    C4DF040TriShape(unsigned short usVertices, C4DF040Point3* pkVertex, C4DF040Point3* pkNormal, void* pkColor,
                    C4DF040Point2* pkTexture, unsigned short usNumTextureSets, unsigned int eNBTMethod,
                    unsigned short usTriangles, unsigned short* pusTriList);

    void AttachProperty(C4DF040Property* pkProperty);

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
};

class C4DF040Node : public C4DF040Object
{
  public:
    C4DF040Node(unsigned int uiMode);

    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual void VFunc094();
    virtual void VFunc098();
    virtual void VFunc09C();
    virtual void VFunc0A0();
    virtual void VFunc0A4();
    virtual void VFunc0A8();
    virtual void VFunc0AC();
    virtual void VFunc0B0();
    virtual void VFunc0B4();
    virtual void VFunc0B8();
    virtual void VFunc0BC();
    virtual void VFunc0C0();
    virtual void VFunc0C4();
    virtual void VFunc0C8();
    virtual void VFunc0CC();
    virtual void VFunc0D0();
    virtual void VFunc0D4();
    virtual void VFunc0D8();
    virtual void AttachChildInAvailableSlot(C4DF040TriShape* pkChild, bool abFirstAvailableSlot);

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
};

class C4DF040FloatSetting
{
  public:
    float* Float();
};

extern C4DF040FloatSetting g_kDebrisMinWidth;
extern C4DF040FloatSetting g_kDebrisMaxWidth;
extern C4DF040FloatSetting g_kDebrisMinHeight;
extern C4DF040FloatSetting g_kDebrisMaxHeight;
extern C4DF040FloatSetting g_kDebrisMinAltHeight;
extern C4DF040FloatSetting g_kDebrisMaxAltHeight;
extern C4DF040FloatSetting g_kDebrisAltHeightChance;
extern C4DF040FloatSetting g_kDebrisShadowSize;
extern bool g_bDebrisShadows;
extern float g_fDebrisRangeX;
extern float g_fDebrisRangeY;
extern C4DF040TexturePtr g_spDebrisTexture;
extern C4DF040TexturePtr g_spDebrisNormalMap;
extern C4DF040TexturePtr g_spDebrisShadowTexture;

float __cdecl C4DF040Random();
float __cdecl C4DF040RandomFloat(float fMin, float fScaledValue);
bool __cdecl C4DF040RandomChance(float afChance);
void __cdecl C4DF040UpdateProperties(C4DF040TriShape* pkShape, int iArg1, int iArg2);

extern double DAT_010229b8;
extern double DAT_01012070;
struct FUN_004dfec0_Class
{
    unsigned int FUN_00476be0();
    float FUN_004dfec0();
};

class FUN_004d4f10
{
  public:
    virtual ~FUN_004d4f10();

    void FUN_00438af0();
};

class FUN_004d4eb0 : public FUN_004d4f10
{
  public:
    virtual ~FUN_004d4eb0();
};

// @fnv 0x004d4eb0
FUN_004d4eb0::~FUN_004d4eb0()
{
    FUN_00438af0();
}

struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    void FUN_00864980(void*, unsigned int);
};
struct SavedSettingValue
{
    unsigned int unk00;
    unsigned int value;
};

class ListT
{
  public:
    unsigned int FUN_0044ddc0();
    void* FUN_00559450();
    ListT* FUN_0057cbe0(void**);
};
class Owner
{
  public:
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
    ListT kList;
    void* GetByIndex(unsigned int idx);
};

namespace fnv_004d9070 {
void __fastcall DeleteAllEntries(void* pkMap);

class FUN_004d90d0
{
  public:
    virtual ~FUN_004d90d0();
};

class FUN_004d9070 : public FUN_004d90d0
{
  public:
    virtual ~FUN_004d9070();
};

// Destructor that calls DeleteAllEntries on the object to free all entries before base class cleanup.
// @fnv 0x004d9070
FUN_004d9070::~FUN_004d9070()
{
    DeleteAllEntries(this);
}
}  // namespace fnv_004d9070

struct NiTMallocInterface_004d91b0
{
    static void __cdecl Deallocate(void*);
};
struct FUN_004d91b0_Class
{
    virtual void v00();
    void* pData;
    ~FUN_004d91b0_Class();
};

struct DoorTeleportLoadData
{
    unsigned int unk00;
    float positionX, positionY, positionZ;
    float rotationX, rotationY, rotationZ;
    DoorTeleportLoadData();
};
struct FUN_008579e0_shell
{
    void FUN_008579e0(void*, unsigned int);
};
extern FUN_008579e0_shell* g_TESSaveLoadGame;
struct DoorTeleportArray
{
    unsigned char count;
    DoorTeleportLoadData* entries;
    void FUN_004da3f0();
};

extern int DAT_011c70e0;
extern int DAT_011c70e4;
extern bool DAT_011c70eb;
extern int DAT_011c6fbc;

struct OutT
{
    int x;
    int y;
};
extern int(__stdcall* DAT_00fdf2ec)(int, int);
extern int(__stdcall* DAT_00fdf2e8)(unsigned int, int);
extern int(__stdcall* DAT_00fdf310)(OutT*, int, int);
extern int(__stdcall* DAT_00fdf2a4)(unsigned int, int, int);

unsigned int FUN_004bc3f0();

class NiAVObject;
struct FUN_004dc540_shell
{
    void FUN_004dc540(NiAVObject*);
};

class BGSMoviePlayer
{
  public:
    void FUN_00ec25e0();
};
extern BGSMoviePlayer* DAT_0126fac4;

class BSAudio
{
  public:
    unsigned int FUN_0044ddc0();
};
extern BSAudio* g_osGlobals;

struct FUN_00b7b930_Ctx
{
    void FUN_00b631d0();
};
FUN_00b7b930_Ctx* FUN_00b4f5c0();

struct GO45
{
    void FUN_0045ce80(int);
    int FUN_004503f0();
};
extern GlobalObject_004a4a40 g_011c73dc;
extern GlobalObject_004a4a40 g_011c718c;

struct S45a
{
    int FUN_004503f0(int, int, int);
};
struct S45b
{
    int FUN_004503f0(int);
};

class GlobalObject_00633c90
{
  public:
    FUN_004dc540_shell* FUN_00559450();
};
extern GlobalObject_00633c90 g_011c73b4;

struct FUN_00558310_node
{
    void FUN_00c52520();
};
FUN_00558310_node* FUN_0045c670();

class E73shell
{
  public:
    int FUN_00e73eb0(int, int);
};

class Interface
{
  public:
    static void Init(bool);
};

void FUN_00702330();
void FUN_004dc560();
void FUN_004dc590();
void FUN_00a62030();
void FUN_00b578a0();
void FUN_004dc5c0();
void FUN_004dc650();
void FUN_007022c0();
void FUN_007053f0();
void __cdecl CopyStringToGlobal(const char* src);

extern bool DAT_011c70ed;

extern float g_0118948c;

extern float DAT_01189498;

struct FUN_004dfe30_Class
{
    float x;
    float y;

    FUN_004dfe30_Class();
    FUN_004dfe30_Class __thiscall FUN_004dfe30(const FUN_004dfe30_Class& kPt) const;
};

struct FUN_004d8610_StandIn
{
    void* GetSubValue(int);
};

namespace fnv_004dc710 {
#include <windows.h>
#include <d3d9.h>
bool FUN_004dcda0_Result();
int __cdecl FUN_004dc2b0_Result();

namespace std {
float __cdecl abs(float value);
}
struct DisplayAdapter
{
    unsigned int FUN_004dcce0();
    D3DDISPLAYMODE* GetElementAt(unsigned int indexInfo);
    unsigned char FUN_004dcd30(int windowed);
    D3DCAPS9* FUN_004dc120(int indexInfo);
};
void* __cdecl FUN_004dce30();
DisplayAdapter* __cdecl GetFltValueAt(int indexInfo);
int __cdecl FUN_004dc270();
D3DFORMAT __cdecl MapIndexToValue(int format);
int __cdecl FUN_004dc1f0();
int __cdecl FUN_004dc200();
unsigned int __cdecl FUN_004dcd90();
unsigned int __cdecl FUN_004dcd80();
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011c74e0;
void __cdecl DetectGpuVendor(unsigned int, unsigned int, unsigned char, int, int, int);
extern unsigned int DAT_0118947c;
extern unsigned int DAT_01189480;
extern unsigned int DAT_0118946c;
extern unsigned int DAT_01189468;
extern unsigned char DAT_011c70ec;
extern unsigned char DAT_011c6fba;

}  // namespace fnv_004dc710

class B004de530
{
  public:
    int unk[0x45];
    B004de530();
};
extern FUN_004de530* DAT_011f35a0;

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* pcFileName);
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* pvModule, const char* pcProcName);
extern int(__stdcall* DAT_00fdf0a8)(void* pvModule);

struct EFAdapterText
{
    unsigned int word00, word04, word08, word0c;
    unsigned int word10, word14, word18, word1c;
    unsigned int word20, word24, word28, word2c;
    unsigned int word30, word34, word38, word3c;
    unsigned int word40, word44, word48, word4c;
    unsigned int word50, word54, word58, word5c;
    unsigned int word60, word64, word68, word6c;
    unsigned int word70, word74, word78, word7c;
    unsigned int word80, word84, word88, word8c;
    unsigned int word90, word94, word98, word9c;
    unsigned int worda0, worda4, worda8, wordac;
    unsigned int wordb0, wordb4, wordb8, wordbc;
    unsigned int wordc0, wordc4, wordc8, wordcc;
    unsigned int wordd0, wordd4, wordd8, worddc;
    unsigned int worde0, worde4, worde8, wordec;
    unsigned int wordf0, wordf4, wordf8, wordfc;
};
struct EFAdapterInfo
{
    int iSize;
    int iAdapterIndex;
    EFAdapterText strUDID;
    int iBusNumber;
    int iDeviceNumber;
    int iFunctionNumber;
    int iVendorID;
    EFAdapterText strAdapterName;
    EFAdapterText strDisplayName;
    int iPresent;
    int iExist;
    EFAdapterText strDriverPath;
    EFAdapterText strDriverPathExt;
    EFAdapterText strPNPString;
    int iOSDisplayIndex;
};
struct EFDisplayTarget
{
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iDisplayMapIndex;
    int iDisplayTargetMask;
    int iDisplayTargetValue;
};
struct EFMode
{
    int iAdapterIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iXPos;
    int iYPos;
    int iXResTmp;
    int iYResData;
    int iColourDepth;
    float fRefreshRate;
    int iOrientation;
    int iModeFlag;
    int iModeMask;
    int iModeValue;
};
struct EFDisplayMap
{
    int iDisplayMapIndex;
    EFMode displayMode;
    int iNumDisplayTarget;
    int iFirstDisplayTargetArrayIndex;
    int iDisplayMapMask;
    int iDisplayMapValue;
};
struct EFSLSTarget
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iDisplayMapIndex;
    int iDisplayTargetMask;
    int iDisplayTargetValue;
    int iGridX;
    int iGridY;
    EFMode viewSize;
    int iSLSTargetMask;
    int iSLSTargetValue;
};
struct EFNativeMode
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iSLSModeIndex;
    int iModeAdapterIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iXPos;
    int iYPos;
    int iXResTmp;
    int iYResData;
    int iColourDepth;
    float fRefreshRate;
    int iOrientation;
    int iModeFlag;
    int iModeMask;
    int iModeValue;
    int iSLSNativeModeMask;
    int iSLSNativeModeValue;
};
struct EFBezelMode
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iBezelModeIndex;
    int iModeAdapterIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iXPos;
    int iYPos;
    int iXResTmp;
    int iYResData;
    int iColourDepth;
    float fRefreshRate;
    int iOrientation;
    int iModeFlag;
    int iModeMask;
    int iModeValue;
    int iNumBezelOffset;
    int iFirstBezelOffsetArrayIndex;
    int iSLSBezelTransientModeMask;
    int iSLSBezelTransientModeValue;
};
struct EFTransientMode
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iSLSModeIndex;
    EFMode displayMode;
    int iNumBezelOffset;
    int iFirstBezelOffsetArrayIndex;
    int iSLSBezelTransientModeMask;
    int iSLSBezelTransientModeValue;
};
struct EFSLSOffset
{
    int iAdapterIndex;
    int iSLSMapIndex;
    int iDisplayLogicalIndex;
    int iDisplayPhysicalIndex;
    int iDisplayLogicalAdapterIndex;
    int iDisplayPhysicalAdapterIndex;
    int iBezelModeIndex;
    int iLeft;
    int iTop;
    int iWidth;
    int iHeight;
    int iBezelOffsetMask;
    int iBezelOffsetValue;
};
struct EFSLSGrid
{
    int iAdapterIndex;
    int iSLSGridIndex;
    int iSLSGridRow;
    int iSLSGridColumn;
    int iSLSGridMask;
    int iSLSGridValue;
};
struct EFSLSMap
{
    int iAdapterIndex;
    int iSLSMapIndex;
    EFSLSGrid kGrid;
    int iSurfaceMapIndex;
    int iOrientation;
    int iNumSLSTarget;
    int iFirstSLSTargetArrayIndex;
    int iNumNativeMode;
    int iFirstNativeModeArrayIndex;
    int iNumBezelMode;
    int iFirstBezelModeArrayIndex;
    int iNumBezelOffset;
    int iFirstBezelOffsetArrayIndex;
    int iSLSMapMask;
    int iSLSMapValue;
};

struct EFRect
{
    int iLeft;
    int iTop;
    int iWidth;
    int iHeight;
};
struct EFDisplayInfo
{
    int iGridXCoord;
    int iGridYCoord;
    EFRect kDisplayRect;    // +0x08
    EFRect kVisibleRect;    // +0x18
    int iPreferredDisplay;  // +0x28
};
struct EFEyefinityInfo
{
    int iSLSActive;
    int iSLSGridWidth;
    int iSLSGridHeight;
    int iSLSWidth;
    int iSLSHeight;
    int iBezelCompensatedDisplay;
};

typedef int (*EFMainControlCreate)(void*(__stdcall* pfnAlloc)(unsigned int), int iEnumConnectedAdapters);
typedef int (*EFMainControlDestroy)();
typedef int (*EFNumberOfAdaptersGet)(int* piNumAdapters);
typedef int (*EFAdapterInfoGet)(EFAdapterInfo* pkInfo, int iInputSize);
typedef int (*EFSLSMapIndexGet)(int iAdapterIndex, int iTargetCount, EFDisplayTarget* pkTargets, int* piSLSMapIndex);
typedef int (*EFSLSMapConfigGet)(int iAdapterIndex, int iSLSMapIndex, EFSLSMap* pkMap, int* piNumTarget,
                                 EFSLSTarget** ppkTarget, int* piNumNative, EFNativeMode** ppkNative, int* piNumBezel,
                                 EFBezelMode** ppkBezel, int* piNumTransient, EFTransientMode** ppkTransient,
                                 int* piNumOffset, EFSLSOffset** ppkOffset, int iOption);
typedef int (*EFModesGet)(int iAdapterIndex, int iDisplayIndex, int* piNumModes, EFMode** ppkModes);
typedef int (*EFDisplayMapConfigGet)(int iAdapterIndex, int* piNumMap, EFDisplayMap** ppkMap, int* piNumTarget,
                                     EFDisplayTarget** ppkTarget, int iOptions);

void __stdcall ClearAndFreePointer(void* pointer);
void* FUN_00ec61c0(void* pvDst, int iValue, unsigned int uiSize);

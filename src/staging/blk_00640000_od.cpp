#include "f3_common.h"
// src/staging/blk_00640000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.

#include "../../include/layout_support.h"

struct GlobalObject_0040e0b0
{
    float* Float();
};

GlobalObject_0040e0b0 g_011ce00c;

struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting289;
extern double DAT_01011588;

// Returns a plus the product of the float setting from originalRuntimeFloatSetting289 and DAT_01011588.
// @f3 0x00601d30 (community match, verified in this file)
namespace f3m_00601d30 {

namespace f3m_00601d30 {

struct S00601d30
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
    int unk_a0;
    int unk_a4;
    int unk_a8;
    int unk_ac;
    float f_b0;
    float f_b4;

    void FUN_00601080(S00601d30* arg);
    void FUN_00601d30(S00601d30* arg);
};

void S00601d30::FUN_00601d30(S00601d30* arg)
{
    FUN_00601080(arg);
    arg->f_b0 = f_b0;
    arg->f_b4 = f_b4;
}

}
}   // namespace f3m_00601d30


namespace fnv_00643fd0 {
struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting289;

}  // namespace fnv_00643fd0

extern int DAT_0104f3e8;

extern int DAT_0104f3e8;

namespace fnv_00644520 {
struct Setting_S
{
    float* Float();
};

struct GameSettingCollection
{
    float* Float();
};

template <class T> struct SettingT
{
    float* Float();
};

}  // namespace fnv_00644520

extern "C" void __cdecl FUN_0064e3f0(int, int, int);

struct FUN_0065e9a0_holder
{
    void FUN_0065e9a0(int* p);
};

struct FUN_00657880_class
{
    bool FUN_00658160(int);
    bool operator==(int other);
};

// @fnv 0x00657880
bool FUN_00657880_class::operator==(int other)
{
    return !FUN_00658160(other);
}

extern "C" void __cdecl FUN_00659230(int, int);
extern int DAT_01065870;

extern "C" void* __cdecl NiFreeAlias(void*);

struct NiTStringTemplateMap
{
    int m_auiShapeKeys[1];
    int m_pObject;
};

struct BSFaceGenModelMap
{
    void FUN_00658b80(NiTStringTemplateMap* pStringMap);
};

// If the byte at offset 0x10 of this map is set, frees the object pointer held by the given string map via NiFreeAlias.
// @fnv 0x00658b80
void BSFaceGenModelMap::FUN_00658b80(NiTStringTemplateMap* pStringMap)
{
    if (*(unsigned char*)((char*)this + 0x10))
        NiFreeAlias((void*)pStringMap->m_pObject);
}

struct FUN_00658d30_class
{
    void __thiscall FUN_00658d50();
    void __thiscall FUN_00658d30();
};

// @fnv 0x00658d30
void __thiscall FUN_00658d30_class::FUN_00658d30()
{
    FUN_00658d50();
}

struct FUN_006592f0
{
    void __thiscall operator()(void*);
};

extern int DAT_010658b0;

struct FUN_00659490_cls
{
    void InitArray(int);
};

struct FUN_00659460_cls
{
    int* m;
    FUN_00659460_cls* Construct(int a);
};

// Calls InitArray with a, sets m to point at DAT_010658b0, and returns this.
// @fnv 0x00659460
FUN_00659460_cls* FUN_00659460_cls::Construct(int a)
{
    ((FUN_00659490_cls*)this)->InitArray(a);
    m = &DAT_010658b0;
    return this;
}

struct FUN_0065cc50_Class
{
    int FUN_0065cc50();
};

// @fnv 0x0065cc50
int FUN_0065cc50_Class::FUN_0065cc50()
{
    return *(int*)((char*)this + 0x10) - *(int*)((char*)this + 0xc);
}

struct FUN_0065e9a0
{
    void __thiscall Destroy(void* p);
};

extern "C" void __cdecl FUN_0065f9a0(int, int, int);

struct FUN_0065f400_class
{
    void __thiscall FUN_0065f400(int a, int b);
};

// @fnv 0x0065f400
void __thiscall FUN_0065f400_class::FUN_0065f400(int aiArg1, int aiArg2)
{
    FUN_0065f9a0(aiArg1, aiArg2, (int)this + 8);
}

struct FUN_0065f7c0_Class
{
    void FUN_0065f7c0();
};

struct FUN_0065f580_Class
{
    void FUN_0065f580();
};

// @fnv 0x0065f580
void FUN_0065f580_Class::FUN_0065f580()
{
    ((FUN_0065f7c0_Class*)((char*)this + 8))->FUN_0065f7c0();
}

extern "C" void __cdecl FUN_0065f9e0(int a, int b);

struct FUN_0065f6c0_class
{
    void __thiscall FUN_0065f6c0(int a);
};

// @fnv 0x0065f6c0
void __thiscall FUN_0065f6c0_class::FUN_0065f6c0(int aiValue)
{
    FUN_0065f9e0(aiValue, 0);
}

extern void* DAT_010658d0;

struct Flt
{
    operator unsigned int();
};

struct GameSettingCollection
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetFloat(unsigned int index);
};

namespace fnv_00643f20 {
struct GameSettingCollection
{
    float f;
    float* Float();
};
template <typename T> struct SettingT
{
    float* Float();
};
template <> struct SettingT<GameSettingCollection> : public GameSettingCollection
{
    float* Float();
};
float FUN_00404010(float a, float b);
}  // namespace fnv_00643f20

void* __cdecl operator new(unsigned int size, void* placement);

namespace fnv_00644540 {
struct GameSettingCollection
{
};
template <class T> struct SettingT
{
    float* Float();
};

}  // namespace fnv_00644540

GlobalObject_0040e0b0 g_011ce840;
GlobalObject_0040e0b0 g_011cfd8c;

struct ActorValueOwner
{
    float GetActorValueFloatByIndex(ActorValue::Index);
};
extern double g_d100;

namespace fnv_00649580 {
struct ActorValueOwner
{
    float GetActorValueFloatByIndex(int);
};
extern double g_d100;
}  // namespace fnv_00649580

unsigned int __cdecl FUN_00ec7c56(void);

char __cdecl FUN_0065e750(int*, int*);
extern "C" void __cdecl FUN_0064e3f0(int, int, int);

int __cdecl CallWithFlag(int* p);

namespace fnv_006505d0 {
struct Flt
{
    operator unsigned int();
};
}  // namespace fnv_006505d0

unsigned char __cdecl FUN_0065e750(void*, void*);

namespace fnv_00658c60 {
unsigned char __cdecl FUN_0065e750(int*, int*);
}  // namespace fnv_00658c60

void __cdecl operator delete(void* p);

void _Deallocate(void*);

void __cdecl operator delete(void* p);

void __cdecl operator delete(void*);

extern int DAT_010658f0;
struct FUN_00659230
{
    void* vptr;
    void __thiscall InitializeWithGlobal(int a, unsigned char b);
    FUN_00659230(int a, unsigned char b);
};
// Calls InitializeWithGlobal with the two arguments, then sets the vtable pointer to DAT_010658f0.
// @fnv 0x00659230
FUN_00659230::FUN_00659230(int a, unsigned char b)
{
    InitializeWithGlobal(a, b);
    vptr = (void*)&DAT_010658f0;
}

void _Deallocate(void*);

extern int DAT_01065890;
struct FUN_00659330_class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_C;
    unsigned char m_10;
    void* __thiscall InitializeWithGlobal(int a, unsigned char b);
};
// Calls Construct on this, then stores a pointer to DAT_01065890 and the byte b into the object's fields.
// @fnv 0x00659330
void* __thiscall FUN_00659330_class::InitializeWithGlobal(int a, unsigned char b)
{
    ((FUN_00659460_cls*)this)->Construct(a);
    m_iWordAt00 = &DAT_01065890;
    m_10 = b;
    return this;
}

void __cdecl operator delete(void*);

void __cdecl Deallocate(void*);

struct NarrowString
{
    char* p;
    ~NarrowString();
};
struct FaceGenMatrix
{
    ~FaceGenMatrix();
};

namespace fnv_00659440 {
template <typename T> struct FaceGenMatrix
{
    ~FaceGenMatrix();
    char data[32];
};
struct FUN_00659440
{
    char pad[8];
    FaceGenMatrix<float> arr[4];
    ~FUN_00659440();
};
// @fnv 0x00659440
FUN_00659440::~FUN_00659440()
{}
}  // namespace fnv_00659440

extern "C" __declspec(dllimport) void* __stdcall CreateSemaphoreA(void*, long, long, const char*);

unsigned int __cdecl FUN_00ec7c56(void);

unsigned int __cdecl FUN_00ec7c56();

struct FUN_0064df10_helper
{
    void deallocate(void* p, unsigned int n);
};

namespace fnv_0065d330 {
struct FUN_0064df10_helper
{
    void __thiscall deallocate(void*, unsigned int);
};
}  // namespace fnv_0065d330

struct _Out_0044a170
{
    void __thiscall FUN_0065e000(int, void*);
};

namespace fnv_0065e2d0 {
unsigned char __cdecl FUN_0065e750(int*, int*);
}  // namespace fnv_0065e2d0

namespace fnv_0065e360 {
bool __cdecl FUN_0065e750(void*, void*);
}  // namespace fnv_0065e360

namespace fnv_0065e3f0 {
bool __cdecl FUN_0065e750(int*, int*);
}  // namespace fnv_0065e3f0

namespace fnv_0065e480 {
unsigned char __cdecl FUN_0065e750(int* a, int* b);
}  // namespace fnv_0065e480

unsigned char __cdecl FUN_0065e750(void*, void*);

unsigned char __cdecl FUN_0065e750(void*, void*);

namespace fnv_0065e630 {
struct DummyTag
{
    char dummy;
};
DummyTag __cdecl FUN_0065e750(void* a, void* b);
}  // namespace fnv_0065e630

namespace fnv_0065e6c0 {
int __cdecl FUN_0065e750(void*, void*);
}  // namespace fnv_0065e6c0

struct FUN_0065ec10_class
{
    void __thiscall FUN_0065ec10(int b);
};

struct FUN_0065ec70_class
{
    void FUN_0065ec70(int a);
};

namespace fnv_0065ec10 {
struct FUN_0065ec10_class
{
    void* FUN_0065ed30();
    void* FUN_0065ec10(unsigned int flags);
};
}  // namespace fnv_0065ec10

void __cdecl operator delete(void*);

void __cdecl operator delete(void* p);

namespace fnv_0065ed70 {
struct S_0065c6a0
{
    ~S_0065c6a0();
};
struct NarrowString
{
    ~NarrowString();
};
struct FUN_0065ed70
{
    ~FUN_0065ed70();
    NarrowString m_pcFileName;
    char m_auiShapeKeys[27];
    S_0065c6a0 m_data;
};
// @fnv 0x0065ed70
FUN_0065ed70::~FUN_0065ed70()
{}
}  // namespace fnv_0065ed70

namespace fnv_0065edd0 {
struct NarrowString
{
    ~NarrowString();
};
}  // namespace fnv_0065edd0

void FUN_0065f060();

namespace fnv_0065f550 {
struct _Out_0044a170
{
    void FUN_0065e000(int, void*);
};
}  // namespace fnv_0065f550

struct S_0065f7c0
{
    unsigned int FUN_0065f7c0();
};
// @fnv 0x0065f7c0
unsigned int S_0065f7c0::FUN_0065f7c0()
{
    unsigned int v = 0x2AAAAAAA;
    return v > 0 ? v : 1;
}

namespace fnv_0065f960 {
struct Interface
{
    static void __cdecl PrintDebugMessage(int a, int b, int c, int d);
};
unsigned char __cdecl FUN_0065e750(int* a, int* b);
}  // namespace fnv_0065f960

unsigned char __cdecl FUN_0065e750(void* a, void* b);
void __cdecl FUN_0065ff00(void* a, void* b, void* c, unsigned char d);
// @fnv 0x0065f9a0
void __cdecl FUN_0065f9a0(void* pFirst, void* pSecond, void* pThird)
{
    unsigned char r = FUN_0065e750(&pFirst, &pSecond);
    FUN_0065ff00(pFirst, pSecond, pThird, r);
}

// @fnv 0x0065ff00
void __cdecl FUN_0065ff00(char* _First, char* _Last, FUN_0065e9a0_holder* _Dest)
{
    for (; _First != _Last; _First += 6)
        _Dest->FUN_0065e9a0((int*)_First);
}

extern "C" void __cdecl FUN_00660130(int a, int b, int c, int d, int e, int f);

struct FUN_0065ff30_Class
{
    void __thiscall FUN_0065ff30(int a, int b, int c, int d, int e);
};

// @fnv 0x0065ff30
void __thiscall FUN_0065ff30_Class::FUN_0065ff30(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5)
{
    FUN_00660130(aiArg1, aiArg2, aiArg3, aiArg4, aiArg5, (int)(this + 8));
}

struct FUN_0065ff60_class
{
    void __thiscall FUN_0065ff60(int a, int b, int c, int d, int e);
};
extern "C" void __cdecl FUN_00660190(int a, int b, int c, int d, int e, int f);
// Passes the five arguments plus a pointer to this object's offset 8 to FUN_00660190.
// @fnv 0x0065ff60
void __thiscall FUN_0065ff60_class::FUN_0065ff60(int aiArg1, int aiArg2, int aiArg3, int aiArg4, int aiArg5)
{
    FUN_00660190(aiArg1, aiArg2, aiArg3, aiArg4, aiArg5, (int)(this + 8));
}

struct NiProperty;

struct H_0060b3b0
{
    float* FUN_006578b0(unsigned int a) const;
};
int __cdecl _memcmp(const void* a, const void* b, unsigned int n);
// @fnv 0x00658160
bool FUN_00657880_class::FUN_00658160(int other)
{
    if (*(unsigned int*)((char*)other + 0x18) != *(unsigned int*)((char*)this + 0x18) ||
        *(unsigned int*)((char*)other + 0x1c) != *(unsigned int*)((char*)this + 0x1c))
        return false;
    if (*(unsigned int*)((char*)this + 0x18) == 0 || *(unsigned int*)((char*)this + 0x1c) == 0)
        return true;
    return _memcmp(((H_0060b3b0*)this)->FUN_006578b0(0), ((H_0060b3b0*)other)->FUN_006578b0(0),
                   (*(unsigned int*)((char*)this + 0x18) << 2) * *(unsigned int*)((char*)this + 0x1c)) == 0;
}

struct EGMDeltaList;
int __fastcall FUN_00657bc0(EGMDeltaList*);
struct Elem_65eed0
{
    short a, b, c;
};

struct FUN_0065f430_class
{
    void* m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void* m_iThirdValue;
    int m_10;
    int m_14;
    void FUN_0065f430();
};
// @fnv 0x0065f430
void FUN_0065f430_class::FUN_0065f430()
{
    if (m_iThirdValue)
    {
        ((FUN_0065f400_class*)this)->FUN_0065f400((int)m_iThirdValue, m_10);
        ((FUN_0064df10_helper*)((char*)this + 8))->deallocate(m_iThirdValue, (unsigned int)((m_14 - (int)m_iThirdValue) / 6));
    }
    m_iThirdValue = 0;
    m_10 = 0;
    m_14 = 0;
}

void* __cdecl NiMalloc(unsigned int);
void* __cdecl memset(void* dst, int value, unsigned int size);
struct FUN_00659490_cls2
{
    void* m_vtbl;
    int m_uiItemCount;
    void* m_data;
    int m_auiShapeKeys;
    FUN_00659490_cls2* InitArray(int count);
};
// Sets the vtable, stores count, allocates count*4 zeroed bytes into m_data and returns this.
// @fnv 0x00659490
FUN_00659490_cls2* FUN_00659490_cls2::InitArray(int count)
{
    unsigned int size;
    m_vtbl = &DAT_010658d0;
    m_uiItemCount = count;
    m_auiShapeKeys = 0;
    size = m_uiItemCount << 2;
    m_data = NiMalloc(size);
    memset(m_data, 0, m_uiItemCount << 2);
    return this;
}

struct Helper62d0
{
    void* operator=(const void*);
};

struct FUN_00658bb0 : FUN_00658d30_class
{
    ~FUN_00658bb0();
};

// @fnv 0x00658bb0
FUN_00658bb0::~FUN_00658bb0()
{
    *(void**)this = &DAT_01065870;
    FUN_00658d30_class::FUN_00658d30();
}

struct FUN_00508050
{
    float FUN_00508050_value();
};
struct FUN_00559450
{
    FUN_00508050* FUN_00559450_value();
};

extern double DAT_01012060;
float __cdecl FUN_00476b70(float a, float b);

extern double DAT_01012060;
extern double DAT_01017a40;

float __cdecl FUN_00476b70(float a, float b);

// Scale a value by the remaining fraction (max - current) / max, clamped to [0, 1].

extern double DAT_01017a40;
extern double DAT_01011588;

extern double DAT_01012060;

struct FUN_0064bda0_Class
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual float vf94(int index);

    int __thiscall FUN_0064bda0();
};

// @fnv 0x0064bda0
inline void FUN_0064bda0_Class::vf00()
{}
inline void FUN_0064bda0_Class::vf04()
{}
inline void FUN_0064bda0_Class::vf08()
{}
inline void FUN_0064bda0_Class::vf0c()
{}
inline void FUN_0064bda0_Class::vf10()
{}
inline void FUN_0064bda0_Class::vf14()
{}
inline void FUN_0064bda0_Class::vf18()
{}
inline void FUN_0064bda0_Class::vf1c()
{}
inline void FUN_0064bda0_Class::vf20()
{}
inline void FUN_0064bda0_Class::vf24()
{}
inline void FUN_0064bda0_Class::vf28()
{}
inline void FUN_0064bda0_Class::vf2c()
{}
inline void FUN_0064bda0_Class::vf30()
{}
inline void FUN_0064bda0_Class::vf34()
{}
inline void FUN_0064bda0_Class::vf38()
{}
inline void FUN_0064bda0_Class::vf3c()
{}
inline void FUN_0064bda0_Class::vf40()
{}
inline void FUN_0064bda0_Class::vf44()
{}
inline void FUN_0064bda0_Class::vf48()
{}
inline void FUN_0064bda0_Class::vf4c()
{}
inline void FUN_0064bda0_Class::vf50()
{}
inline void FUN_0064bda0_Class::vf54()
{}
inline void FUN_0064bda0_Class::vf58()
{}
inline void FUN_0064bda0_Class::vf5c()
{}
inline void FUN_0064bda0_Class::vf60()
{}
inline void FUN_0064bda0_Class::vf64()
{}
inline void FUN_0064bda0_Class::vf68()
{}
inline void FUN_0064bda0_Class::vf6c()
{}
inline void FUN_0064bda0_Class::vf70()
{}
inline void FUN_0064bda0_Class::vf74()
{}
inline void FUN_0064bda0_Class::vf78()
{}
inline void FUN_0064bda0_Class::vf7c()
{}
inline void FUN_0064bda0_Class::vf80()
{}
inline void FUN_0064bda0_Class::vf84()
{}
inline void FUN_0064bda0_Class::vf88()
{}
inline void FUN_0064bda0_Class::vf8c()
{}
inline void FUN_0064bda0_Class::vf90()
{}
inline float FUN_0064bda0_Class::vf94(int)
{
    return 0.0f;
}

struct S_0064ccf0_Obj
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual int vfn_94();
    virtual int vfn_98();
};
struct S_0064ccf0_Ptr
{
    S_0064ccf0_Obj* unk00;
    S_0064ccf0_Ptr(S_0064ccf0_Obj* p);
    ~S_0064ccf0_Ptr();
    S_0064ccf0_Ptr& operator=(S_0064ccf0_Obj* p);
    operator S_0064ccf0_Obj*() const;
};

struct Ret8
{
    int x;
    int y;
    Ret8()
    {}
    Ret8(const Ret8& other)
    {
        x = other.x;
        y = other.y;
    }
};

unsigned int __cdecl FUN_00ec7c56(void);

unsigned int __cdecl FUN_00ec7c56(void);

namespace std {
struct exception
{
    virtual ~exception() throw();
    const char* message;
    bool ownsMessage;
};
struct bad_alloc : public exception
{
    bad_alloc(const char* = 0) throw();
};
}

unsigned char __cdecl FUN_0065e750(void* p);
int __cdecl CallWithFlag(int* p);

struct SpawnedFlagBox
{
    unsigned char v;
};

struct PathingSolutionBase
{
    int unk04;
    PathingSolutionBase();
    ~PathingSolutionBase();
    virtual void Release()
    {}
};

struct S_006503b0_Elem;
struct S_006503b0_Slot
{
    int unk00;
    S_006503b0_Slot(int);
    ~S_006503b0_Slot();
    void FUN_0066b0d0(int);
    S_006503b0_Elem* FUN_00559450();
};
struct S_006503b0_Elem
{
    int unk00;
    int unk04;
    S_006503b0_Slot slot08;
    int FUN_00726070();
};
void __cdecl FUN_00652140();
void __cdecl FUN_00652190();

void FUN_00652140();
void FUN_00652190();

struct FUN_00657ee0_sub
{
    int unk00;
    unsigned int __thiscall Alloc(unsigned int n);
};

struct FUN_00657ee0_cls
{
    int unk00;
    int unk04;
    FUN_00657ee0_sub m_08;
    unsigned int m_0c;
    unsigned int m_10;
    unsigned int m_14;

    unsigned int __thiscall Count();
    static void __cdecl Grow();
    bool __thiscall FUN_00657ee0(unsigned int a);
};

// @fnv 0x00657ee0
bool FUN_00657ee0_cls::FUN_00657ee0(unsigned int a)
{
    m_0c = 0;
    m_10 = 0;
    m_14 = 0;
    if (a == 0)
    {
        return false;
    }
    else
    {
        if (this->Count() < a)
        {
            Grow();
        }
        else
        {
            m_0c = m_08.Alloc(a);
            m_10 = m_0c;
            m_14 = m_0c + a;
        }
    }
    return true;
}

struct Hldr0044
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    void FUN_0044d6c0(int a);
};

extern "C" void __stdcall FUN_00ec7894(Hldr0044* p, void* dat);
extern "C" void __cdecl FUN_00401000(int scaled);
extern "C" int DAT_01140ef8;

class SubMember
{
  public:
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;

    SubMember(bool flag);
    ~SubMember();
    void Apply(int value);
};

class SubMember_d0045cec0 : public SubMember
{
  public:
    SubMember_d0045cec0(bool f) : SubMember(f)
    {}
    ~SubMember_d0045cec0();
};

struct FUN_0065cfb0
{
    ~FUN_0065cfb0();
};

// Container default constructor: base storage takes a default allocator, then reserve nothing.

struct FUN_006815c0
{
    int unk00;
    FUN_006815c0();
    FUN_006815c0(const FUN_006815c0&);
};
struct FUN_0065d3a0
{
    FUN_0065d3a0(FUN_006815c0 value);
    ~FUN_0065d3a0();
};

namespace fnv_0065cb00 {
struct FUN_0065cfb0
{
    ~FUN_0065cfb0();
};
}  // namespace fnv_0065cb00

// Container default constructor: base storage takes a default allocator, then reserve nothing.

namespace fnv_0065cbd0 {
struct FUN_0065cfb0
{
    ~FUN_0065cfb0();
};
}  // namespace fnv_0065cbd0

namespace fnv_0065cdd0 {
struct FUN_006815c0
{
    int value;
    FUN_006815c0();
    FUN_006815c0(const FUN_006815c0&);
};
struct FUN_0065d3a0
{
    FUN_0065d3a0(FUN_006815c0 value);
    ~FUN_0065d3a0();
    void __thiscall FUN_0065d980(int value);
};
}  // namespace fnv_0065cdd0

struct FNVPair8
{
    unsigned int lo;
    unsigned int hi;
};

extern "C" void __cdecl ThrowVectorTooLong();

extern void __cdecl ThrowVectorTooLong();

extern "C" void __cdecl ThrowVectorTooLong();

void __cdecl ThrowVectorTooLong();

namespace fnv_0065d740 {
struct FNVPair8
{
    unsigned int lo;
    unsigned int hi;
    bool Compare(FNVPair8* other);
};

}  // namespace fnv_0065d740

void __cdecl ThrowVectorTooLong();

unsigned int __cdecl FUN_00ec7c56(void);

namespace fnv_0065e310 {

extern "C" void __stdcall FUN_00ec7894(void* obj, void* dtor);
extern "C" void* __cdecl FUN_00401000(unsigned int size);
extern int DAT_01140ef8;

}  // namespace fnv_0065e310

namespace fnv_0065e430 {
namespace std {
class bad_alloc
{
  public:
    virtual ~bad_alloc();
    bad_alloc(const char* message = 0);
    const char* message;
    bool ownsMessage;
};
}

}  // namespace fnv_0065e430

void* __cdecl operator new(unsigned int size);

namespace fnv_0065e5e0 {
struct FUN_0065e5e0_Hldr
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    void Init(int code);
};

extern "C" void __stdcall FUN_00ec7894(FUN_0065e5e0_Hldr* p, void* dat);
extern "C" void* __cdecl FUN_00401000(unsigned int size);
extern "C" int DAT_01140ef8;

}  // namespace fnv_0065e5e0

namespace fnv_0065e670 {
class FUN_0065e670_cls
{
  public:
    FUN_0065e670_cls(int unk00);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

extern "C" char DAT_01140ef8;
int __cdecl FUN_00401000(unsigned int size);
void __stdcall FUN_00ec7894(FUN_0065e670_cls* obj, char* msg);

}  // namespace fnv_0065e670

// @fnv 0x0065e750
unsigned char __cdecl FUN_0065e750(void* a, void* b)
{
    char c;
    return c;
}

int __cdecl CallWithFlag(int*);

class FUN_0065f060_base
{
  public:
    ~FUN_0065f060_base();
    int unk04;
};

class FUN_0065f060 : public FUN_0065f060_base
{
  public:
    ~FUN_0065f060();
    void unk08();
};

// Destructor that calls unk08() on this object.
// @fnv 0x0065f060
FUN_0065f060::~FUN_0065f060()
{
    this->unk08();
}

namespace fnv_0065f4f0 {
struct FNVPair8
{
    unsigned int lo;
    unsigned int hi;
};

}  // namespace fnv_0065f4f0

namespace fnv_0065f5a0 {
struct FNVPair8
{
    unsigned int lo;
    unsigned int hi;
    bool FUN_0065dfd0(FNVPair8* other);
};

}  // namespace fnv_0065f5a0

namespace fnv_0065f640 {
// vector<T>::_Xlen: report a length error by throwing length_error("vector<T> too long").

class TooLongString
{
  public:
    int m_aiBuf0;
    int m_aiBuf1;
    int m_aiBuf2;
    int m_aiBuf3;
    unsigned int m_uiSize;
    unsigned int m_uiRes;
    int m_iAlloc;

    TooLongString(const char* pText);
    ~TooLongString();
};

class LengthError
{
  public:
    const char* m_pWhat;
    int m_iDoFree;
    TooLongString m_kStr;

    LengthError(const TooLongString& kError);
    LengthError(const LengthError& kOther);
    virtual ~LengthError();
};

// Throws a LengthError constructed from the message "vector<T> too long".
// @fnv 0x0065f640
void __cdecl ThrowVectorTooLong()
{
    throw LengthError("vector<T> too long");
}
}  // namespace fnv_0065f640

struct C65F700Node;

struct C65F700Iterator
{
    void* m_pvContainer;
    C65F700Node* m_pkNode;

    bool operator==(const C65F700Iterator& kOther);
};

struct S_0065f8c0_PtrTag
{
    char v;
};
struct S_0065f8c0_IterTag
{
    char v;
    S_0065f8c0_IterTag()
    {}
};
S_0065f8c0_PtrTag __cdecl FUN_0065e750(char** first, char** dest);
S_0065f8c0_IterTag __cdecl FUN_0065fd70(char** first, char** dest);
char* __cdecl CallWithFlag(char** p);

namespace fnv_0065f9e0 {
namespace std {
class bad_alloc
{
  public:
    bad_alloc(const char* message);
    virtual ~bad_alloc();
    virtual const char* what() const;

  private:
    const char* message_;
    bool owns_message_;
};
}
// @fnv 0x0065f9e0
extern "C" void __cdecl FUN_0065f9e0(int count, int unused)
{
    if ((unsigned int)count <= 0u)
    {
        count = 0;
    }
    else if (0xffffffffu / (unsigned int)count < 6u)
    {
        throw std::bad_alloc(0);
    }
    ::operator new((unsigned int)count * 6u);
}
}  // namespace fnv_0065f9e0

namespace fnv_0065fa30 {
namespace std {
class bad_alloc
{
  public:
    virtual ~bad_alloc();
    bad_alloc(const char* message = 0);
    const char* description;
    int ownsMessage;
};
}
}  // namespace fnv_0065fa30

extern void FUN_0065f060();
extern void FUN_0065fc10();

int __cdecl CallWithFlag(int* p);

struct _DummyTag
{
};
struct S_0065ff90_Dest
{
    int* m_ptr;
    unsigned int m_iElementCount;
};
_DummyTag __cdecl FUN_0065e750(S_0065ff90_Dest* dest);

namespace fnv_0065ffe0 {
struct SpawnedFlagBox
{
    unsigned char v;
};

unsigned char __cdecl FUN_0065e750(void* p);

}  // namespace fnv_0065ffe0

class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

template <class T> struct FGPointer
{
    T* m_pObject;

    FGPointer(T* apObject);
    ~FGPointer();
    operator T*() const;
};

// Destructor: clear the contents, then the base container is destroyed.

void* __cdecl operator new(unsigned int uiSize);

struct Node_658d50
{
    Node_658d50* next;
    void* data;
};

struct Base_658d50
{
    virtual ~Base_658d50();
};

struct FUN_00658d50 : Base_658d50
{
    unsigned int count;
    Node_658d50** buckets;
    int unk0c;
    unsigned char flag;
    ~FUN_00658d50();
};

void __cdecl NiFree(void* p);

// If flag is set, walks every bucket, frees each node's data with NiFree, and advances to the next node.
// @fnv 0x00658d50
FUN_00658d50::~FUN_00658d50()
{
    if (this->flag)
    {
        for (unsigned int i = 0; i < this->count; ++i)
        {
            Node_658d50* node = this->buckets[i];
            while (node)
            {
                Node_658d50* tmp = node;
                node = node->next;
                NiFree(tmp->data);
            }
        }
    }
}

struct ObjectCleanupBase658e10
{
    virtual ~ObjectCleanupBase658e10();
};
struct FUN_00658e10 : ObjectCleanupBase658e10
{
    void FUN_00438af0();
    virtual ~FUN_00658e10();
};
// @fnv 0x00658e10
FUN_00658e10::~FUN_00658e10()
{
    FUN_00438af0();
}

unsigned char* __cdecl FUN_0065fd70(unsigned char* out, int* a1, int* a2);

typedef int* Iter65E;

struct FUN_0065ee70 : FUN_0065cfb0
{
    ~FUN_0065ee70();
};
// Destructor that calls FUN_0065f430 on this object.
// @fnv 0x0065ee70
FUN_0065ee70::~FUN_0065ee70()
{
    ((FUN_0065f430_class*)this)->FUN_0065f430();
}

// Copy-style range helper: unwrap both iterators and forward them with the iterator-category and range tags.

namespace c820 {
struct RCTag
{
};
struct InTag
{
};
struct FwdTag : InTag
{
};
struct BiTag : FwdTag
{
};
struct RaTag : BiTag
{
};
struct PtrCat
{
};
typedef Elem_65eed0* It;
PtrCat __cdecl FUN_0065e750(It& a, It& b);
RaTag __cdecl FUN_0065fd70(const It& a, const It& b);
}

namespace de {
struct RCTag
{
};
struct PtrCat
{
};
PtrCat __cdecl FUN_0065e750(int& a, int& b);
}

struct TagA
{
    char v;
};

TagA* __cdecl FUN_0065fd70(TagA* flag, int* a, int* b);

int __cdecl CallWithFlag(int* p);

class NiRefObject
{
  public:
    void IncRefCount();
    void DecRefCount();
};

class NiExtraData;

class NiObject : public NiRefObject
{
  public:
    virtual ~NiObject();
    NiObject* Clone();
    void ResolveObjectPointer(NiPointer<NiObject>& spCopy);
};

class NiObjectNET : public NiObject
{
  public:
    bool AddExtraData(NiExtraData* pExtraData);
};

struct S_0065fb10_Elem
{
    short a;
    short b;
    short c;
};
struct S_0065fb10_Alloc
{
    S_0065fb10_Alloc(const S_0065fb10_Alloc&);
};
struct S_0065fb10_Iter
{
    S_0065fb10_Elem* ptr;
    void* cont;
};
struct S_0065fb10_Base
{
    int unk00;
    int unk04;
    S_0065fb10_Alloc _Alval;
    S_0065fb10_Elem* _Myfirst;
    S_0065fb10_Elem* _Mylast;
    S_0065fb10_Elem* _Myend;
    S_0065fb10_Base(S_0065fb10_Alloc al);
    ~S_0065fb10_Base();
    unsigned int FUN_00657bc0() const;
    bool FUN_0065f380(unsigned int n);
    S_0065fb10_Iter FUN_0065fd10() const;
    S_0065fb10_Iter FUN_0065fd40() const;
    S_0065fb10_Elem* FUN_0065ff30(S_0065fb10_Iter first, S_0065fb10_Iter last, S_0065fb10_Elem* dest);
    void FUN_0065f430();
};
struct FUN_0065fb10 : S_0065fb10_Base
{
    FUN_0065fb10(const FUN_0065fb10& other);
};
// @fnv 0x0065fb10
FUN_0065fb10::FUN_0065fb10(const FUN_0065fb10& other) : S_0065fb10_Base(other._Alval)
{
    if (FUN_0065f380(other.FUN_00657bc0()))
    {
        try
        {
            _Mylast = FUN_0065ff30(other.FUN_0065fd10(), other.FUN_0065fd40(), _Myfirst);
        }
        catch (...)
        {
            FUN_0065f430();
            throw;
        }
    }
}

struct ObjectPointer64ce20
{
    void* m_object;
    ObjectPointer64ce20& operator=(void* object);
    ~ObjectPointer64ce20();
};

struct ItE4E0
{
    int* m_ptr;
};

struct CatTagE4E0
{
};

struct PtrCatE4E0
{
    PtrCatE4E0()
    {}
};

CatTagE4E0 __cdecl FUN_0065e750(const ItE4E0& it);
PtrCatE4E0 __cdecl FUN_0065fd70(const ItE4E0& a, const ItE4E0& b);
int* __cdecl CallWithFlag(ItE4E0& it);

struct ItQ
{
    int* p;
    int c;
};
struct FUN_0065fc10 : FUN_0065d3a0
{
    int unk00;
    int unk04;
    int m_al;
    int* m_pHeadNode;
    int* m_last;
    int* m_kRayEnd;
    int FUN_0065cc50();
    bool FUN_00657ee0(unsigned int n);
    ItQ FUN_0065fd40();
    ItQ FUN_0065fd10();
    int* FUN_0065ff60(ItQ f, ItQ l, int* d);
    void FUN_00657f60();
    FUN_0065fc10(FUN_0065fc10& r);
};
// Constructs the base from r.m_al; if FUN_00657ee0(r.FUN_0065cc50()) is true, sets m_last via FUN_0065ff60, calling FUN_00657f60 on exception.
// @fnv 0x0065fc10
FUN_0065fc10::FUN_0065fc10(FUN_0065fc10& arSource) : FUN_0065d3a0(*(FUN_006815c0*)&arSource.m_al)
{
    if (FUN_00657ee0(arSource.FUN_0065cc50()))
    {
        try
        {
            m_last = FUN_0065ff60(arSource.FUN_0065fd10(), arSource.FUN_0065fd40(), m_pHeadNode);
        }
        catch (...)
        {
            FUN_00657f60();
            FUN_00ec7894(0, 0);
        }
    }
}

struct FloatGetterGlobal
{
    float* FUN_00403e20();
};
extern FloatGetterGlobal DAT_011cfb5c, DAT_011cf264;

namespace ctor_0065c8f0 {

struct FUN_006815c0
{
    FUN_006815c0();
    FUN_006815c0(const FUN_006815c0& other);
};

struct FUN_0065d3a0
{
    FUN_0065d3a0(FUN_006815c0 al) throw();
    ~FUN_0065d3a0();
    void FUN_0065d2b0(int value);
};

}

namespace ctor_0065d3a0 {

struct FUN_0065de30
{
    FUN_0065de30(const FUN_0065de30& other);
};

struct RebindAllocator
{
    RebindAllocator(const FUN_0065de30& other);
    ~RebindAllocator();
};

struct FUN_0065dc90
{
    int unk00;
    int unk04;
    FUN_0065dc90(RebindAllocator al) throw();
};

struct FUN_0065d3a0 : FUN_0065dc90
{
    FUN_0065de30 alval;
    FUN_0065d3a0(FUN_0065de30 al) throw();
};

// Constructs a FUN_0065d3a0 object by delegating to the FUN_0065dc90 base and copying the FUN_0065de30 argument into alval.
// @fnv 0x0065d3a0
FUN_0065d3a0::FUN_0065d3a0(FUN_0065de30 al) throw() : FUN_0065dc90(al), alval(al)
{}

}

struct Elem6_f380
{
    short a, b, c;
};
struct Alloc_f380
{
    Elem6_f380* FUN_0065f6c0(unsigned int n);
};
void __cdecl ThrowVectorTooLong();
struct VecF380
{
    int unk00;
    int unk04;
    Alloc_f380 _Alval;
    Elem6_f380* _Myfirst;
    Elem6_f380* _Mylast;
    Elem6_f380* _Myend;
    unsigned int FUN_0065f580() const;
    bool FUN_0065f380(unsigned int _Capacity);
};
// Resets first/last/end pointers; returns false if _Capacity is 0, throws if it exceeds FUN_0065f580(), else allocates that many elements and returns true.
// @fnv 0x0065f380
bool VecF380::FUN_0065f380(unsigned int _Capacity)
{
    _Myfirst = 0;
    _Mylast = 0;
    _Myend = 0;
    if (_Capacity == 0)
        return false;
    else if (FUN_0065f580() < _Capacity)
        ThrowVectorTooLong();
    else
    {
        _Myfirst = _Alval.FUN_0065f6c0(_Capacity);
        _Mylast = _Myfirst;
        _Myend = _Myfirst + _Capacity;
    }
    return true;
}

#include <math.h>
template <class Collection> class SettingT
{
  public:
    float* Float();
};
float FUN_00404010(float, float);

namespace fnv_006592f0 {

}  // namespace fnv_006592f0

namespace fnv_00659310 {

}  // namespace fnv_00659310

struct BGSLoadGameBuffer;
struct Interface
{
    static void __cdecl PrintDebugMessage(BGSLoadGameBuffer*);
};
struct FUN_0065e9a0_Class
{
    void __thiscall FUN_0065e9a0(BGSLoadGameBuffer* p);
};
// @fnv 0x0065e9a0
void __thiscall FUN_0065e9a0_Class::FUN_0065e9a0(BGSLoadGameBuffer* apBuffer)
{
    Interface::PrintDebugMessage(apBuffer);
}

namespace fnv_0065ec40 {
extern "C" void __cdecl Deallocate(void*);
}  // namespace fnv_0065ec40

namespace fnv_0065ec70 {
struct FUN_0065ec70_class
{
    void __thiscall FUN_0065ed70();
    void* __thiscall FUN_0065ec70(unsigned int flags);
};

}  // namespace fnv_0065ec70

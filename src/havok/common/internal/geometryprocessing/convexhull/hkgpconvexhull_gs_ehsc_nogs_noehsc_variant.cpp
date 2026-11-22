#include "f3_common.h"
#include "fnv_asm_helpers.h"
// src/havok/common/internal/geometryprocessing/convexhull/hkgpconvexhull_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/internal/geometryprocessing/convexhull/hkgpconvexhull.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/internal/geometryprocessing/convexhull/hkgpconvexhull.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/build/20091222_000100_aianbecldeph/source/common/internal/geometryprocessing/convexhull/hkgpconvexhull.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00d74dd0_Class {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void FUN_00d74dd0();
};
struct FUN_00d7ac40_class {
    void FUN_00d7ac40(int);
};
struct FUN_00d75850_class {
    int m0;
    int m1;
    FUN_00d7ac40_class* m2;
    int m3;
    int m4;
    void FUN_00d75850();
};
int __stdcall FUN_00d76300(const int* p, int i);
struct FUN_00d7c200_cls { void __thiscall FreeAll(); };
struct FUN_00d7c250_cls { void __thiscall FlushQueuedElements(); };
struct FUN_00d7c950_cls {
    void __thiscall FUN_00d7c950();
};
int __stdcall FUN_00d752c0(int* arr, int idx);
struct CpuScalar {
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
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    int value;
};
struct CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    CpuScalar* value;
    int FUN_00d74df0();
};
struct ValueBlock {
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
};
struct Implementation {
    int unk000;
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
    ValueBlock m_kValue;
};
struct FUN_00d74e50_cls {
    int unk00;
    int unk04;
    Implementation* m_pImpl;

    ValueBlock GetValueBlock();
};
struct PayloadOwner {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m_iPayload;
};
int* __stdcall FUN_00d74ed0(PayloadOwner* apOwner);
struct TargetCallee {
    void FUN_00d7a5a0(void* p1, void* p2, void* p3, void* p4, float p5);
};
struct FUN_00d74ee0_Class : FUN_00d74dd0_Class {
    void ForwardToCallee(void* p1, void* p2, void* p3, void* p4, float p5);
};
struct D75060Inner {
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
};
struct D75060Outer {
    int unk00;
    int unk04;
    D75060Inner* unk08;

    int FUN_00d75060();
};
struct TextBuffer {
    int unk00;
    int unk04;
    int unk08;
    int storage[128];
    void FUN_00cb1600(char* buffer, int capacity);
    TextBuffer* FUN_00cc01c0(const char* first, const char* middle, const char* last);
    TextBuffer* FUN_00cc01c0();
    TextBuffer* FUN_00cc02d0();
    void FUN_00cc00e0();
};
struct ChildData {
    int unk000;
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
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    char unk1b4;
    char flag1b5;
};
struct Request {
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
};
struct ErrorReporter {
    virtual void unk0();
    virtual void unk1();
    virtual void unk2();
    virtual int message(int type, int hash, const char* text, const char* file, int line);
};
extern ErrorReporter* DAT_01268360;
void __debugbreak();
struct Owner {
    int unk00;
    int unk04;
    ChildData* unk08;
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
    int FUN_00d75070(Request* request);
};
int __stdcall FUN_00d75120(int* p);
struct D75130Inner {
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
};
struct D75130Outer {
    int unk00;
    int unk04;
    D75130Inner* unk08;

    int FUN_00d75130();
};
int __stdcall FUN_00d75200(const int* value);
struct S_00d75210_ErrStream {
    void* m_vt;
    int unk04;
    int unk08;
    S_00d75210_ErrStream(void* buf, int bufSize) throw();
    ~S_00d75210_ErrStream() throw();
    S_00d75210_ErrStream& operator<<(const char* s) throw();
    S_00d75210_ErrStream& operator<<(unsigned int u) throw();
};
struct S_00d75210_Error {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int message(int type, int id, const char* desc, const char* file, int line) throw();
};
extern S_00d75210_Error* g_hkError;
struct S_00d75210_Data {
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
    int m_uiEdgeIndex;
};
struct S_00d75210_Config {
    int unk000;
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
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    unsigned int m_1b0;
    char unk1b4;
    bool m_hasIndex;
};
struct S_00d75210_Self {
    int unk00;
    int unk04;
    S_00d75210_Config* m_pConfiguration;
    int FUN_00d75210(const S_00d75210_Data* v) const throw();
};
struct D762F0Target {
    void update();
};
struct D762F0Owner {
    int unk00;
    int unk04;
    D762F0Target* m_target;

    void FUN_00d762f0();
};
struct D76910Inner { void FUN_00d7cf00(); };
struct D76910Owner {
    int unk00;
    int unk04;
    D76910Inner* inner;
    void FUN_00d76910();
};
struct FUN_00d76990_State {
    int unk00;
    float unk04;
    void FUN_00d7d2a0();
};
struct FUN_00d76990_Class {
    int unk00;
    int unk04;
    FUN_00d76990_State* unk08;
    void SetValue(float value, bool clearFlag);
};
typedef union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;
extern "C" __m128 _mm_setr_ps(float a, float b, float c, float d);
struct Vec3 { float x, y, z; };
struct __declspec(align(16)) hkVec4 {
    float x, y, z, w;
};
struct Shape {
    float FUN_00d768b0(const hkVec4& v);
    float FUN_00d76840(const hkVec4& v);
    float FUN_00d769c0(const Vec3& p);
};
struct AudioSink {
    void FUN_00d7df60(void* apFirst, void* apSecond, bool abIsNull, void* apThird);
};
struct FUN_00d76c50_cls {
    int unk00;
    int unk04;
    AudioSink* m_pSink;

    void DispatchToSink(void* apKey, void* apFirst, void* apSecond, void* apThird);
};
struct Vec4i {
    int x, y, z, w;
};
struct FUN_00d81510_Class {
    Vec4i m_00;
    void FUN_00d81510(int a, int b, int c, int d);
};
struct FUN_00d771c0_Owner {
    int unk00;
    int unk04;
    FUN_00d81510_Class* unk08;
    void FUN_00d771c0(int a, int b, const Vec4i& v);
};
struct FUN_00d83430_class {
    void FUN_00d83430(int, int, int, float);
};
struct FUN_00d790a0_class {
    int unk00;
    int unk04;
    FUN_00d83430_class* unk08;
    void FUN_00d790a0(int a, int b, int c, float d);
};
struct S_00d79f90_Opts
{
    int mode;
    float value;
    S_00d79f90_Opts();
};
struct S_00d79f90_Result
{
    virtual ~S_00d79f90_Result();
    void FUN_00d78720(float f, const S_00d79f90_Opts& opts);
};
struct S_00d79f90_World
{
    S_00d79f90_Result* FUN_00d76cf0();
};
void __cdecl FUN_00d79ab0(S_00d79f90_World* world, int a, void* b, float c);
void __cdecl FUN_00d79580(S_00d79f90_Result* res, void* b, int n, float eps);
void __cdecl FUN_00d79f90(S_00d79f90_World* world, int a, void* b, int n, float d);
struct S_00d7a010_Alloc {
    virtual void unk0();
    virtual void unk4();
    virtual void ReleaseBlock(void* p, int n);
    virtual void unkc();
    virtual void ReturnMemory(void* p, int n) throw();
};
struct S_00d7a010_Router {
    int unk0; int unk4; int unk8; int unkc;
    S_00d7a010_Alloc* m_pStreamAllocator;
    static S_00d7a010_Router& FUN_00c85750() throw();
    S_00d7a010_Alloc& heap() throw() { return *m_pStreamAllocator; }
};
template <typename T>
struct S_00d7a010_Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00d7a010_Array() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline void _clearAndDeallocate(S_00d7a010_Alloc& a) throw() {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            a.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
};
struct S_00d7a010_Obj {
    virtual ~S_00d7a010_Obj() throw();
    void operator delete(void* p) throw();
};
void __cdecl FUN_00d79f90(int a, int b, S_00d7a010_Array<S_00d7a010_Obj*>& out, int c, float f) throw();
void __cdecl DeleteCollectedObjects(int a, int b, int c, float f);
struct S_00d7c200_Heap {
    virtual void v0();
    virtual void v1();
    virtual void ReleaseBlock(void* p, int nbytes);
};
struct S_00d7c200_Router {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d7c200_Heap* m_pStreamAllocator;
    static S_00d7c200_Router& GetMonitorStream();
    S_00d7c200_Heap& heap() { return *m_pStreamAllocator; }
};
struct S_00d7c200 {
    void** m_kBlocks;
    int m_iBlockCount;
    int unk8;
    int unkC;
    int unk10;
    void FreeAll();
};
struct S_00d7c340_Allocator {
    virtual void vfn_00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct S_00d7c340_Router {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00d7c340_Allocator* unk10;
    S_00d7c340_Allocator* heap() { return unk10; }
};
S_00d7c340_Router* FUN_00c85750();
int ResizeAudioStream(S_00d7c340_Allocator* alloc, void* array, int elemSize);
struct S_00d7c340_Elem {
    S_00d7c340_Elem* next;
    int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44;
};
struct S_00d7c340_Block {
    S_00d7c340_Elem elems[32];
    S_00d7c340_Elem* freeList;
    int numUsed;
};
struct S_00d7c340 {
    S_00d7c340_Block** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    S_00d7c340_Block* AllocateBlock();
};
struct UnknownBlock {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};
struct Node {
    Node *link0;
    Node *link4;
    void *unk08;
    void *unk0c;
    int value10, value14, value18, value1c, value20, value24, value28;
    float value2c;
    int value30, value34;
};
struct NodeBank {
    UnknownBlock unk000, unk040, unk080, unk0c0, unk100, unk140, unk180, unk1c0;
    UnknownBlock unk200, unk240, unk280, unk2c0, unk300, unk340, unk380, unk3c0;
    UnknownBlock unk400, unk440, unk480, unk4c0, unk500, unk540, unk580, unk5c0;
    UnknownBlock unk600, unk640, unk680, unk6c0, unk700, unk740, unk780, unk7c0;
    Node *freeHead;
    int allocated;
};
struct PoolList {
    NodeBank **banks;
    int bankValid;
    void *unk08;
    Node *head;
    int activeCount;
    NodeBank *FUN_00d7c2a0();
    Node *CloneNode(Node *source);
};
extern float DAT_0106ea1c;
class FUN_00d74d40_cls
{
public:
    unsigned char m_00;
    float m_04;
    volatile unsigned char m_08;
    volatile unsigned char m_09;
    volatile unsigned char m_0a;
    volatile unsigned char m_0b;
    volatile unsigned char m_0c;
    volatile unsigned char m_0d;

    FUN_00d74d40_cls* FUN_00d74d40();
};
struct FUN_00d74d70_cls {
    int m_00;
    unsigned char m_04;
    float m_08;
    float m_0c;
    unsigned char m_10;
    unsigned char m_11;
    FUN_00d74d70_cls* FUN_00d74d70();
};
extern float DAT_0104da4c;
struct FUN_00d74d90_cls {
    int m_i00;
    float m_f04;

    FUN_00d74d90_cls* FUN_00d74d90();
};
struct SpawnedInner {
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
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int m_i1a8;
};
struct FUN_00d74e10_cls {
    int unk00;
    int unk04;
    SpawnedInner* m_pInner;

    int FUN_00d74e10();
};
struct FourFloatVector { int x,y,z,w; };
struct FUN_00d74e20_class {
    void* m_00; void* m_04; char* m_08;
    FourFloatVector __thiscall GetFieldAtD0();
};
struct Inner {
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
    int m_i28;
};
struct FUN_00d75050_cls {
    int unk00;
    int unk04;
    Inner* m_pInner;

    int FUN_00d75050();
};
struct FUN_00d7a180_target {
    void FUN_00d7a180();
};
struct FUN_00d752d0_cls {
    void* m_00;
    void* m_04;
    FUN_00d7a180_target* m_08;
    void FUN_00d752d0();
};
struct DiagStream {
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_buf[128];
    void FUN_00cb1600(unsigned int* buf, unsigned int size);
    DiagStream* FUN_00cc01c0(const char* fmt, unsigned int count, const char* tail);
    DiagStream* FUN_00cc02d0();
    void FUN_00cc01c0();
    void FUN_00cc00e0();
};
struct DiagLogger {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Report(int level, unsigned int hash, char* msg, const char* file, int line);
};
extern DiagLogger* g_diagLogger;
struct DiagState {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2C;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3C;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4C;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5C;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6C;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7C;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8C;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9C;
    unsigned int unkA0;
    unsigned int unkA4;
    unsigned int unkA8;
    unsigned int unkAC;
    unsigned int unkB0;
    unsigned int unkB4;
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCC;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDC;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEC;
    unsigned int unkF0;
    unsigned int unkF4;
    unsigned int unkF8;
    unsigned int unkFC;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10C;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11C;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13C;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14C;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15C;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16C;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17C;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18C;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19C;
    unsigned int unk1A0;
    float m_1a4;
    unsigned int unk1A8;
    unsigned int unk1AC;
    unsigned int m_1b0;
    unsigned char m_1b4;
};
struct FUN_00d75390_cls {
    unsigned int unk00;
    unsigned int unk04;
    DiagState* m_08;
    float GetMass();
};
extern "C" double __cdecl pow(double base, double exponent);
extern const double DAT_010d35e8;
extern const double DAT_010d35e0;
struct FUN_00d75440_cls {
    float FUN_00d752e0();
    double GetMass();
    float ComputeScaledPowerRatio();
};
struct FUN_00d75820_Tmp8 {
    int m00;
    int m04;
};
struct FUN_00d75820_Target {
    void FUN_00d7a200(int a, float b, FUN_00d75820_Tmp8* c, int d);
};
struct FUN_00d75820_cls {
    int m00;
    int m04;
    FUN_00d75820_Target* m08;

    void CallTargetWithTemp(int a1, float a2, int a3);
};
struct FUN_00d7b330_cls {
    void FUN_00d7b330(int a1, int a2, float a3);
};
struct FUN_00d76100_cls {
    void* unk00;
    void* unk04;
    FUN_00d7b330_cls* m_08;
    void FUN_00d76100(int a1, int a2, float a3);
};
struct FUN_00d7caa0_class {
    void __thiscall FUN_00d7caa0(float, int);
};
struct FUN_00d76920_class {
    void* m_00;
    void* m_04;
    FUN_00d7caa0_class* m_08;
    void FUN_00d76920(float, int);
};
struct SpawnedObject {
    void* m_00;
    void* m_04;
    void* m_08;
};
struct TailCallee {
    void Tail();
};
class FUN_00d77bc0_cls {
public:
    void FUN_00d77bc0();
};
struct ArgPair
{
    int m_kPointA;
    int m_kPointB;
};
void __cdecl FUN_00d78ea0(int first, ArgPair* apPairs, int count);
void __cdecl CallWithPair(int a0, int a1, int a2);
struct D79090Target {
    void update();
};
struct D79090Owner {
    int unk00;
    int unk04;
    D79090Target* m_target;

    void FUN_00d79090();
};
// FUN_00d79510 (0x00d79510, 102 bytes)
//
// The function walks the item table of a record and asks every item to
// "do it" (the virtual at vtable slot 0, called with the argument 1).
// Before that it hands the record to FUN_00d79250 (0x00d79250) with five
// arguments: the two leading pointers, the address of the third parameter
// (the callee clears *arg3), the record itself (the callee clears the
// record's +4 field) and the float.
//
// The callee is only DECLARED here on purpose: the checker then binds the
// call relocation to the original's own target 0x00d79250.
// an item of the table: a virtual at vtable slot 0
struct FUN_00d79510_Item {
    virtual void FUN_00d79510_doIt(int);
};
// the record the table lives in: the item array at +0, the count at +4
struct FUN_00d79510_Record {
    FUN_00d79510_Item** m_00;
    int m_04;
};
// the third parameter: an object with a virtual at vtable slot 0
struct FUN_00d79510_Object {
    virtual void FUN_00d79510_doIt(int);
    int m_04;
};
struct FUN_00d79510_A;
struct FUN_00d79510_B;
void __cdecl FUN_00d79250_helper(FUN_00d79510_A* a, FUN_00d79510_B* b,
                                 FUN_00d79510_Object** out, void* p, float f);
bool __cdecl FUN_00d79510(FUN_00d79510_A* a, FUN_00d79510_B* b, FUN_00d79510_Object* c, float f);
static int SortKeyOf(void* p)
{
    return ((int*)p)[0xe];
}
void __cdecl QuickSortByKey(void** arr, int lo, int hi, int ctx);
struct RandomGenerator {
    unsigned int stateFlags;
    unsigned int seed;
    void FUN_00d7a4b0(float* components);
};
struct Record {
    unsigned int payload;
    float key;
};

// The script object that receives the queued elements: its third virtual
// function is the one that is called with the element and the command id.
struct ScriptHandler {
    virtual void v00();
virtual void v01();
virtual void v02(void* element, int command);
};
// What FUN_00c85750() hands back: the audio system object, whose field at
// offset 0x10 is the script handler that owns the vtable.
struct AudioSystem {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    ScriptHandler* m_10;
};
// The audio system object the game hands out.
// The layout of the object this method belongs to: a queue of elements at
// m_00 with its length at m_04, plus two counters that are cleared again.
struct QueuedElements {
    void** m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
};
// FUN_00d7c2a0 - create a new object of type 0x808 and append it to the
// item list of this container.
//
// The container keeps an array of item pointers (m_00), the number of items
// (m_04) and a capacity/flags field (m_08).  The new object is allocated
// through the creation interface found at offset 0x10 of the global manager;
// the object itself starts with a free list of 32 linked 64 byte blocks.
struct GlobalManager {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
};
// The creation interface: slot 1 takes the object type id and returns a
// freshly allocated object of that type.
struct CreateIface {
    virtual void* v0();
    virtual void* v1(int);
};
void __cdecl ResizeAudioStream(void*, void*, int);
// A writable handle for one slot of the item array.
struct SlotRef {
    void** m_slot;
    void operator=(void* p) { *m_slot = p; }
};
static __forceinline SlotRef MakeSlot(void** a, int i) { SlotRef r; r.m_slot = a + i; return r; }
struct FUN_00d7c2a0_cls {
    void** m_00;
    int m_04;
    int m_08;
    void* FUN_00d7c2a0();
};
// Candidate for ClearAndFlush (115 bytes).
//
// Reconstructed shape (from the original bytes):
//
//   this+0x00  void**   an array of element pointers
//   this+0x04  int      the number of elements
//   this+0x08  unsigned a size/flag word: bit 31 marks "already handed over",
//                        the low 30 bits hold an element count
//
//   the service object lives at holder+0x10 and is polymorphic.  Slot 0x08 is
//   called once per element with (element, 0x808), slot 0x10 is called once
//   with (data, byte size) when the buffer has not been handed over yet.
//
// The two "count = 0" stores and the "array = 0" store are immediate stores:
// the zero constant would have to be live across the calls, so MSVC 2008 does
// not materialise it in a register.
struct D7C850_Target {
    virtual void v_dummy0();
    virtual void v_dummy1();
    virtual void v1(void* element, unsigned int flags);   // vtable offset 0x08
    virtual void v_dummy2();
    virtual void v2(void* data, unsigned int size);        // vtable offset 0x10
};
struct D7C850_Holder {
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    D7C850_Target* m_10;
};
struct D7C850_Class {
    void** m_00;
    int m_04;
    unsigned int m_08;
    void ClearAndFlush();
};
extern char DAT_0103d078;
struct RetBlock64
{
	__m128 m_v0;
	__m128 m_v1;
	__m128 m_v2;
	__m128 m_v3;
};
struct RetBlock16
{
	__m128 m_v0;
};
struct SharedOwner
{
	int unk000, unk004, unk008, unk00C, unk010, unk014, unk018, unk01C;
	int unk020, unk024, unk028, unk02C, unk030, unk034, unk038, unk03C;
	int unk040, unk044, unk048, unk04C, unk050, unk054, unk058, unk05C;
	int unk060, unk064, unk068, unk06C, unk070, unk074, unk078, unk07C;
	int unk080, unk084, unk088, unk08C, unk090, unk094, unk098, unk09C;
	int unk0A0, unk0A4, unk0A8, unk0AC, unk0B0, unk0B4, unk0B8, unk0BC;
	int unk0C0, unk0C4, unk0C8, unk0CC, unk0D0, unk0D4, unk0D8, unk0DC;
	int unk0E0, unk0E4, unk0E8, unk0EC, unk0F0, unk0F4, unk0F8, unk0FC;
	int unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C;
	__m128 m_v120;
	__m128 m_v130;
	__m128 m_v140;
	__m128 m_v150;
	__m128 m_v160;
	int unk170, unk174, unk178, unk17C;
	int unk180, unk184, unk188, unk18C;
	int unk190, unk194, unk198, unk19C;
	int unk1A0, unk1A4, unk1A8, unk1AC;
	int m_i1B0;
	unsigned char m_b1B4;
};
class DbgStr_cls
{
public:
	int unk00;
	int unk04;
	int unk08;
	void Init(char *buf, int size);
	DbgStr_cls *Append(const char *pszPrefix, int value, const char *pszSuffix);
	DbgStr_cls *Pad(void);
	DbgStr_cls *Last(void);
	void Release(void);
};
class AssertMgr_cls
{
public:
	virtual void vtbl00(void);
	virtual void vtbl04(void);
	virtual void vtbl08(void);
	virtual int vtbl0C(int level, unsigned int id, char *buf, const char *file, int line);
};
class FUN_00d75490_cls
{
public:
	int unk00;
	int unk04;
	SharedOwner *m_pSharedOwner;
	void GetMassProperties(RetBlock64 *pOut64, RetBlock16 *pOut16);
};
struct D76250Allocator;
struct D76250MemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    D76250Allocator* m_pStreamAllocator;

    D76250Allocator& heap() { return *m_pStreamAllocator; }
};
namespace fnvc_adapt { extern "C" D76250MemoryRouter& __cdecl FUN_00c85750(); }
void __cdecl FUN_00c908c0(D76250Allocator* alloc, void* array, int numElements, int sizeElem);
struct D76250Vector4 {
    __m128 m_vComponents;

    void operator=(const D76250Vector4& v) { m_vComponents = v.m_vComponents; }
};
struct D76250VectorArray {
    D76250Vector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void reserve(D76250Allocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(D76250Vector4));
        }
    }

    D76250Vector4* expandBy(int n)
    {
        D76250Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        int oldSize = m_iElementCount;
        reserve(alloc, oldSize + n);
        m_iElementCount += n;
        return m_data + oldSize;
    }
};
struct D76250Shape {
    int getNumVertices() const;
    const D76250Vector4& getVertex(int i) const;

    void CopyVerticesToArray(D76250VectorArray& vertices) const;
};
struct FUN_00d81510_cls {
    void FUN_00d81510(int a1, int a2, int a3, int a4);
};
struct FUN_00d77320_cls {
    int unk00;
    int unk04;
    FUN_00d81510_cls* m_08;

    void CopyAndDispatch(int* a1, int a2, const __m128* a3, const unsigned int* a4);
};
struct FnvCpu_FUN_00d74e00_CpuObject {
    unsigned int unk00;
    unsigned int unk04;
    int value;
    int FUN_00d74e00();
};
struct S_00cc01c0_Class {
    S_00cc01c0_Class* FUN_00cc02d0();
    void FUN_00cc01c0();
    S_00cc01c0_Class* FUN_00cc01c0(const char*, int, char*);
};
struct S_00d752e0_Entity {
    int unk000;
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
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    float unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    char unk1b4;
};
struct S_00d752e0_Class {
    int unk00;
    int unk04;
    S_00d752e0_Entity* unk08;
    float FUN_00d752e0();
};
extern const char str_010d3540[];
extern const char str_010d358c[];
struct S_00cb1600_Class {
    int unk000;
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
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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

    void FUN_00cb1600(int*, unsigned int);
    S_00cc01c0_Class* FUN_00cc01c0(const char*, int, char*);
    void FUN_00cc00e0();
};
// Recursive quicksort partition over 12-byte records keyed by a float at +8;
// the key delta is scaled by the double literal -1.0 before testing against 0.0.
struct SortRec12 {
    unsigned int m0;
    unsigned int m4;
    float key;
};
void __cdecl FUN_00d7b160(SortRec12* base, int lo, int hi, int unkArg);
extern "C" {
__m128 __cdecl _mm_sub_ps(__m128, __m128);
__m128 __cdecl _mm_mul_ps(__m128, __m128);
__m128 __cdecl _mm_shuffle_ps(__m128, __m128, unsigned int);
__m128 __cdecl _mm_add_ss(__m128, __m128);
void __cdecl _mm_store_ss(float*, __m128);
}
struct DistanceScalar {
    __m128 q;
__forceinline DistanceScalar(__m128 v) : q(v) {}
__forceinline float getReal() const { float f; _mm_store_ss(&f,q); return f; }
};
struct DistanceVector {
    __m128 q;
    __forceinline DistanceVector() {}
    __forceinline DistanceVector(const DistanceVector& v) : q(v.q) {}
    __forceinline void operator=(const DistanceVector& v) { q=v.q; }
    __forceinline void setSub(const DistanceVector& a,const DistanceVector& b) { q=_mm_sub_ps(a.q,b.q); }
    __forceinline DistanceScalar lengthSquared() const {
        __m128 d=_mm_mul_ps(q,q);
        __m128 y=_mm_shuffle_ps(d,d,0x55);
        __m128 z=_mm_shuffle_ps(d,d,0xaa);
        return DistanceScalar(_mm_add_ss(z,_mm_add_ss(y,d)));
    }
};
struct DistanceLess {
    const DistanceVector* reference;
    __forceinline bool operator()(const DistanceVector& a,const DistanceVector& b) const {
        DistanceVector da,db;
        da.setSub(a,*reference);
        db.setSub(b,*reference);
        struct Floats {
            float first;
            float second;
        };
        Floats values;
        _mm_store_ss(&values.first,da.lengthSquared().q);
        _mm_store_ss(&values.second,db.lengthSquared().q);
        return values.first<values.second;
    }
};
void FUN_00d7aaf0(DistanceVector* pa,int lo,int hi,DistanceLess less);
struct S00d7d1c0_Alloc {
    virtual void s0();
    virtual void s1();
    virtual void s2(void* p, int size);
};
struct S00d7d1c0_Router {
    int u00;
    int u04;
    int u08;
    int u0c;
    S00d7d1c0_Alloc* m10;
};
struct S00d7d1c0_M08 {
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    void FreeAll();
    void ClearAndFlush();
};
struct S00d7d1c0_M20 {
    void FlushQueuedElements();
    void FUN_00d7c8d0();
};
struct S00d7d1c0_Base {
    virtual void v0();
    virtual void v1();
    virtual void v2(void* p, int size);
    unsigned short m04;
};
inline void* operator new(unsigned int, void* p) { return p; }
struct S00d7d1c0_Derived : S00d7d1c0_Base {
    S00d7d1c0_M08 m08;
    S00d7d1c0_M20 m20;
    ~S00d7d1c0_Derived() {
        m20.FlushQueuedElements();
        m20.FUN_00d7c8d0();
        m08.FreeAll();
        m08.ClearAndFlush();
    }
    S00d7d1c0_Derived* FUN_00d7d1c0(int flags);
};

extern "C" __m128 _mm_load_ss(const float* p);
extern "C" __m128 _mm_setr_ps(float a, float b, float c, float d);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);

struct VectorComponentValue
{
    float x;
    float y;
    float z;
    float w;

    VectorComponentValue() {}
    VectorComponentValue(const float& f) { q() = _mm_load_ss(&f); }
    VectorComponentValue(__m128 v) { q() = v; }
    __m128& q() { return reinterpret_cast<__m128&>(*this); }
    const __m128& q() const { return reinterpret_cast<const __m128&>(*this); }
    operator float() const { float s; _mm_store_ss(&s, q()); return s; }
};

struct hkVector4
{
    __m128 m_vComponents;

    void operator=(const hkVector4& v) { m_vComponents = v.m_vComponents; }
    void setSub4(const hkVector4& a, const hkVector4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    void mul4(const hkVector4& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
    void add4(const hkVector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    VectorComponentValue lengthSquared3() const
    {
        __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq);
        return _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), s);
    }
};

extern float DAT_0104da48;

struct S_00d75cb0_Node
{
    S_00d75cb0_Node* m_next;
    int unk04;
    int unk08;
    int unk0C;
    hkVector4 m_pos;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
};

struct S_00d75cb0_Obj
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
    S_00d75cb0_Node* m_pFirstNode;
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
    hkVector4 m_offset;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    hkVector4 m_vScale;
};

struct S_00d75cb0_Ref
{
    hkVector4* p;
    S_00d75cb0_Ref(hkVector4* q) : p(q) {}
};

struct S_00d75cb0
{
    int unk00;
    int unk04;
    S_00d75cb0_Obj* m_obj;

    void FUN_00d75cb0(int mode, const hkVector4& point, hkVector4& closest);
};

int __cdecl Vsnprintf(void* buf, int size, const char* fmt, unsigned int arg);
int __cdecl FUN_00cb10d0(int x);
extern const char str_010c1a98[];

struct Cc0080Stream {
    virtual void Write(const char* s, int n);
};

// Private-convention callee: str arrives in esi (entry null-check), out in edi
// (used second, both live across FUN_00cb10d0).
static __declspec(noinline) void FUN_00cc0080(Cc0080Stream* out, const char* str) {
    if (!str)
        out->Write("(null)", 6);
    else
        out->Write(str, FUN_00cb10d0((int)str));
}

struct FUN_00cc02d0_cls {
    int m_00;
    int m_04;
    Cc0080Stream* m_08;

    FUN_00cc02d0_cls* FUN_00cc02d0(int arg);
};

// @fnv 0x00cc02d0
FUN_00cc02d0_cls* FUN_00cc02d0_cls::FUN_00cc02d0(int arg) {
    char buf[0x2728];
    Vsnprintf(buf, 0x2728, str_010c1a98, arg);
    FUN_00cc0080(m_08, buf);
    return this;
}

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
struct GridVec4 {
    __m128 m_vComponents;
};
struct GridCell {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int x, y, z;
};
struct TESFileRecordLoader {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec;
    GridVec4 m_offset;
    int unk100, unk104, unk108, unk10c;
    GridVec4 m_vScale;
    void getCellPosition(const GridCell& c, GridVec4& out) const
    {
        out.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_setr_ps((float)c.x, (float)c.y, (float)c.z, 0.0f), m_vScale.m_vComponents), m_offset.m_vComponents);
    }
};
struct GridOwner {
    int unk00, unk04;
    TESFileRecordLoader* m_grid;
    void FUN_00d74e80(GridVec4& out, const GridCell& c) const;
};

extern "C" __m128 _mm_unpackhi_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 _mm_rcp_ps(__m128 a);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_and_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_sub_ss(__m128 a, __m128 b);
extern "C" void _mm_store_ss(float* p, __m128 a);

extern const __m128 DAT_010c7170;
extern const __m128 DAT_01017d10;
extern const __m128 DAT_010c7160;

struct S00d756a0_Ostream {
    int m_00;
    int m_04;
    int m_08;
    void FUN_00cb1600(char* buf, int size);
    S00d756a0_Ostream* FUN_00cc01c0(const char* s);
    S00d756a0_Ostream* FUN_00cc02d0(int v);
    void FUN_00cc00e0();
    S00d756a0_Ostream(char* buf, int size) { FUN_00cb1600(buf, size); }
    ~S00d756a0_Ostream() { FUN_00cc00e0(); }
};

inline __m128 S00d756a0_quadReciprocal(__m128 r)
{
    __m128 e = _mm_rcp_ps(r);
    return _mm_sub_ps(_mm_add_ps(e, e), _mm_mul_ps(_mm_mul_ps(e, r), e));
}

struct S00d756a0_Vec {
    __m128 m_vComponents;
    void setXYZ_W(const S00d756a0_Vec& xyz, const S00d756a0_Vec& w)
    {
        m_vComponents = _mm_shuffle_ps(xyz.m_vComponents, _mm_unpackhi_ps(xyz.m_vComponents, w.m_vComponents), 0xc4);
    }
    void setReciprocal4(const S00d756a0_Vec& v) { m_vComponents = S00d756a0_quadReciprocal(v.m_vComponents); }
    void setAbs4(const S00d756a0_Vec& v) { m_vComponents = _mm_and_ps(v.m_vComponents, DAT_01017d10); }
};

struct S00d756a0_Plain {
    float x, y, z, w;
};

struct S00d756a0_Shape {
    int m_00;
    int m_04;
    char* m_08;
    void GetMassProperties(S00d756a0_Vec* axes, S00d756a0_Vec* ext);
    void FUN_00d756a0(S00d756a0_Plain& out);
};

extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_set_ps1(float);
extern "C" void _ReadWriteBarrier();
extern "C" {
__m128 _mm_load_ps(const float*);
void _mm_store_ps(float*, __m128);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_add_ps(__m128, __m128);
__m128 _mm_sub_ps(__m128, __m128);
__m128 _mm_min_ps(__m128, __m128);
__m128 _mm_max_ps(__m128, __m128);
__m128 _mm_cmple_ps(__m128, __m128);
int _mm_movemask_ps(__m128);
__m128 _mm_add_ss(__m128, __m128);
__m128 _mm_sqrt_ss(__m128);
__m128 _mm_set_ps(float, float, float, float);
__m128 _mm_set1_ps(float);
float _mm_cvtss_f32(__m128);
}

struct Vec4 {
    __m128 q;
    __forceinline void setMin(const Vec4& a,const Vec4& b) { q=_mm_min_ps(a.q,b.q); }
    __forceinline void setMax(const Vec4& a,const Vec4& b) { q=_mm_max_ps(a.q,b.q); }
};
struct Box { Vec4 lo; Vec4 hi; };

struct Impl {
    int u00; int u04; int u08; int u0c;
    int u10; int u14; int u18; int u1c;
    int u20; int u24; int u28; int u2c;
    int u30; int u34; int u38; int u3c;
    int u40; int u44; int u48; int u4c;
    int u50; int u54; int u58; int u5c;
    int u60; int u64; int u68; int u6c;
    int u70; int u74; int u78; int u7c;
    int u80; int u84; int u88; int u8c;
    Box boxes[2];
    int ud0,ud4,ud8,udc;
    int ue0,ue4,ue8,uec;
    Vec4 offset;
    int u100,u104,u108,u10c;
    Vec4 scale;
};

struct PointNode {
    PointNode* next;
    int flag,unk08,unk0c;
    Vec4 source;
    int x,y,z;
};
struct HullAccess {
    int unk00,unk04;
    Impl* data;
    __declspec(noinline) int FUN_00d75050();
    __declspec(noinline) PointNode* FUN_00d75060();
    __declspec(noinline) Vec4* FUN_00d74ed0(PointNode* node);
    __declspec(noinline) PointNode* FUN_00d75120(PointNode* node);
    __declspec(noinline) Vec4* FUN_00d74e80(Vec4* out, PointNode* node);
};

extern "C" void _mm_store_ss(float*,__m128);
extern "C" __m128 _mm_load_ps1(const float*);
static __forceinline __m128 broadcast(float f) { __m128 q=_mm_load_ss(&f); return _mm_shuffle_ps(q,q,0); }
static __forceinline float scalar(__m128 q) { float f; _mm_store_ss(&f,q); return f; }

struct Self {
    int unk00; int unk04; Impl* m_pClassImpl;
    Box __thiscall FUN_00d75920(int index, float a2, float a3);
};

extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);

struct S00d76120_Node {
    S00d76120_Node* m_00;
    int unk04;
    int unk08;
    int unk0C;
    D76250Vector4 m_10;
    int m_20;
    int m_24;
    int m_28;
};

struct S00d76120_Owner {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    S00d76120_Node* m_24;
    int m_28;
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
    __m128 m_f0;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    __m128 m_110;
};

struct S00d76120_Arr {
    D76250Vector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    __forceinline void reserve(D76250Allocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(D76250Vector4));
        }
    }

    __forceinline D76250Vector4* expandBy(int n)
    {
        D76250Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        int oldSize = m_iElementCount;
        reserve(alloc, oldSize + n);
        m_iElementCount += n;
        return m_data + oldSize;
    }

    __forceinline D76250Vector4* expandBy2(int n)
    {
        D76250Allocator& alloc = *(D76250Allocator*)FUN_00c85750()->heap();
        int oldSize = m_iElementCount;
        int want = oldSize + n;
        int cap = getCapacity();
        if (cap < want) {
            if (want < cap * 2) want = cap * 2;
            FUN_00c908c0(&alloc, this, want, sizeof(D76250Vector4));
        }
        m_iElementCount += n;
        return &m_data[oldSize];
    }
};

struct S00d76120_cls {
    void* m_00;
    void* m_04;
    union {
        S00d76120_Owner* m_08;
        S00d76120_Owner* m_08b;
    };
    void FUN_00d76120(int mode, S00d76120_Arr& arr);

    __forceinline void copyRaw(S00d76120_Arr& arr) const
    {
        S00d76120_Owner* o = m_08;
        D76250Vector4* dst = arr.expandBy(o->m_28);
        for (S00d76120_Node* node = o->m_24; node != 0; node = node->m_00) {
            *dst++ = node->m_10;
        }
    }

    __forceinline void copyScaled(S00d76120_Arr& arr) const
    {
        S00d76120_Owner* o = m_08b;
        D76250Vector4* dst = arr.expandBy2(o->m_28);
        for (S00d76120_Node* node = o->m_24; node != 0; node = node->m_00) {
            __m128 v = _mm_setr_ps((float)node->m_20, (float)node->m_24, (float)node->m_28, 0.0f);
            D76250Vector4 r;
            r.m_vComponents = _mm_add_ps(_mm_mul_ps(v, o->m_110), o->m_f0);
            *dst++ = r;
        }
    }
};

struct S_00d76410_Alloc {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void ReturnMemory(void* p, int numBytes);
};
struct S_00d76410_Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d76410_Alloc* m_pStreamAllocator;
    S_00d76410_Alloc& heap() { return *m_pStreamAllocator; }
};
void __cdecl FUN_00c908c0(S_00d76410_Alloc* alloc, void* array, int numElements, int elemSize);
static __forceinline S_00d76410_Router& getRouter() { return *reinterpret_cast<S_00d76410_Router*>(FUN_00c85750()); }
template <typename T>
struct S_00d76410_Array {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void GrowArrayCapacity(S_00d76410_Alloc& alloc, int n)
    {
        if (getCapacity() < n) {
            int cap2 = 2 * getCapacity();
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void reserve(int n) { GrowArrayCapacity(getRouter().heap(), n); }
    __forceinline T* _expandBy(S_00d76410_Alloc& alloc, int n)
    {
        int oldSize = m_iElementCount;
        GrowArrayCapacity(alloc, oldSize + n);
        m_iElementCount += n;
        return m_data + oldSize;
    }
    __forceinline T* expandBy(int n) { return _expandBy(getRouter().heap(), n); }
    __forceinline void pushBackUnchecked(const T& e) { m_data[m_iElementCount] = e; m_iElementCount++; }
};
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
struct S_00d76410_Vec4 {
    __m128 m_vComponents;
    S_00d76410_Vec4& operator=(const S_00d76410_Vec4& o) { m_vComponents = o.m_vComponents; return *this; }
};
struct S_00d76410_Tri {
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iMaterialIndex;
};
struct S_00d76410_Geometry {
    S_00d76410_Array<S_00d76410_Vec4> m_kVertices;
    S_00d76410_Array<S_00d76410_Tri> m_uiTriangleCount;
};
template <typename T>
struct S_00d76410_Pad {
    T m_kStorage;
    T val() const { return m_kStorage; }
};
struct S_00d76410_Vertex {
    S_00d76410_Vertex* m_next;
    int unk04;
    int unk08;
    int unk0c;
    S_00d76410_Vec4 m_pObservedSource;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
};
struct S_00d76410_Triangle {
    S_00d76410_Triangle* m_next;
    int unk04;
    S_00d76410_Vertex* m_vertex0;
    S_00d76410_Vertex* m_vertex1;
    S_00d76410_Vertex* m_vertex2;
};
struct S_00d76410_Map {
    S_00d76410_Vertex** m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    S_00d76410_Map() { m_kPrimitiveElement = 0; m_iCapacityFlags = 0; m_iPairCount = -1; }
    ~S_00d76410_Map() throw();
    int GetLogicalSize() const { return m_iCapacityFlags & 0x7fffffff; }
    void EnsureCapacity(S_00d76410_Alloc& alloc, int numElements);
    void FUN_00cb1870(S_00d76410_Alloc& alloc, S_00d76410_Vertex* key, int val);
    int LookupHashEntry(S_00d76410_Vertex* key, int def);
    void ProcessArgument(S_00d76410_Alloc& alloc);
    __forceinline void writeIndex(S_00d76410_Vertex* v,int& out) { out=LookupHashEntry(v,-1); }
    __forceinline void reserve(int n) { EnsureCapacity(getRouter().heap(), n); }
    __forceinline void insert(S_00d76410_Vertex* key, int value) { FUN_00cb1870(getRouter().heap(), key, value); }
    __forceinline void clear() { ProcessArgument(getRouter().heap()); }
};
struct S_00d76410_Hull {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    S_00d76410_Vertex* m_kVertices;
    int m_iStridedVertexCount;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    S_00d76410_Triangle* m_uiTriangleCount;
    int m_iTriangleCount;
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
    S_00d76410_Vec4 m_offset;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    S_00d76410_Vec4 m_vScale;
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
    int m_eVertexFloatDimensions;
    __forceinline void getPosition(const S_00d76410_Vertex* v, S_00d76410_Vec4& out) const
    {
        __m128 position = _mm_setr_ps((float)v->m_uiX, (float)v->m_uiY, (float)v->m_uiZ, 0.0f);
        position = _mm_mul_ps(position, m_vScale.m_vComponents);
        out.m_vComponents = _mm_add_ps(position, m_offset.m_vComponents);
    }
};
struct S_00d76410_HullData {
    char unk00;
};
struct S_00d76410_Builder {
    int unk00;
    int unk04;
    S_00d76410_Hull* m_data;
    __forceinline void generateConvex(bool useSource, S_00d76410_Geometry& geom) const throw();
    __forceinline void generatePlanar(bool useSource, S_00d76410_Geometry& geom) const throw();
    void FUN_00d76410(int mode, S_00d76410_Geometry& geom) const throw();
};

struct S_00d77380_Strided {
    char* data;
    int count;
    int stride;
};

struct S_00d77380_Allocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReleaseBlock(void* p, int bytes);
};

struct S_00d77380_Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_00d77380_Allocator* m_pStreamAllocator;
    S_00d77380_Allocator& heap() { return *m_pStreamAllocator; }
};
namespace fnvc_adapt2 { extern "C" S_00d77380_Router& __cdecl FUN_00c85750(); }
void __cdecl FUN_00c908c0(S_00d77380_Allocator* alloc, void* array, int numElements, int sizeElem);

struct S_00d77380_Vec4 {
    __m128 m_vComponents;
    void set(float x, float y, float z, float w = 0.0f) { m_vComponents = _mm_setr_ps(x, y, z, w); }
};

struct S_00d77380_Array {
    S_00d77380_Vec4* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    S_00d77380_Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    ~S_00d77380_Array()
    {
        S_00d77380_Allocator& alloc = fnvc_adapt2::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReleaseBlock(m_data, getCapacity() * sizeof(S_00d77380_Vec4));
    }
    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    void reserve(int n)
    {
        S_00d77380_Allocator& alloc = fnvc_adapt2::FUN_00c85750().heap();
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(S_00d77380_Vec4));
        }
    }
    void SetSizeAndGrow(int n) { reserve(n); m_iElementCount = n; }
    int GetLogicalSize() const { return m_iElementCount; }
    S_00d77380_Vec4* begin() { return m_iElementCount ? m_data : 0; }
    S_00d77380_Vec4& operator[](int i) { return m_data[i]; }
};

struct S_00d77380 {
    int CopyAndDispatch(const S_00d77380_Vec4* verts, int count, int a, int b);
    int FUN_00d77380(S_00d77380_Strided* s, int a, int b);
};

extern const char str_010d3574[];
extern const float s_faderClearedAlpha;
void __cdecl FUN_00c908c0(void*,void*,int,int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" __m128 _mm_load_ps1(const float*);
extern "C" void _mm_store_ss(float*, __m128);

struct ExportStream {
    int unk00,unk04,unk08;
    void FUN_00cb1600(char*,int);
    ExportStream* FUN_00cc01c0(const char*,int,char*);
    ExportStream* FUN_00cc02d0();
    void FUN_00cc01c0();
    void FUN_00cc00e0();
};
struct OffsetVector { int x,y,z,w; };
struct OffsetView { __m128* data; int size; int stride; };
struct OffsetArray {
    __m128* data;
    int size;
    int capacity;
    __forceinline void init() { data=0; size=0; capacity=0x80000000; }
    __forceinline void reserve(int n) {
        S_00d7a010_Router& router=S_00d7a010_Router::FUN_00c85750();
        if((capacity&0x3fffffff)<n) FUN_00c908c0(router.m_pStreamAllocator,this,n,16);
    }
    __forceinline void AddBack(const __m128& value) {
        S_00d7a010_Router& router=S_00d7a010_Router::FUN_00c85750();
        if(size==(capacity&0x3fffffff)) ResizeAudioStream(router.m_pStreamAllocator,this,16);
                __m128* dest=data+size;
        for(int j=0;j<1;++j) dest[j]=value;
        ++size;
    }
    __forceinline void clearAndFree() {
        S_00d7a010_Alloc& a=S_00d7a010_Router::FUN_00c85750().heap();
        size=0;
        if((capacity&0x80000000)==0) a.ReturnMemory(data,(capacity&0x3fffffff)*16);
    }
};
union OffsetWorkspace { ExportStream stream; OffsetArray array; };
struct OffsetOwner {
    int unk00,unk04;
    ChildData* state;
    OffsetVector* FUN_00d75600();
    OffsetVector* FUN_00d752d0();
    int FUN_00d74f10();
    OffsetVector* FUN_00d74fb0(int);
    __declspec(noinline) int FUN_00d74e10();
    __declspec(noinline) void* FUN_00d74e00();
    ValueBlock GetValueBlock();
    int FUN_00d75050();
    PayloadOwner* FUN_00d75060();
    __declspec(noinline) __m128* FUN_00d74ed0(PayloadOwner* n);
    __declspec(noinline) PayloadOwner* FUN_00d75120(PayloadOwner* n);
    void FUN_00d77840(__m128*,int,const ValueBlock&,void*);
    void FUN_00d774a0(__m128*,int,void*);
    void FUN_00d77380(const OffsetView&,const ValueBlock&,void*);
    void FUN_00d77200(const OffsetView&,void*);
    void FUN_00d762f0();
    void SetValue(float,bool);
};

extern "C" __m128 _mm_mul_ps(__m128,__m128);
extern "C" __m128 _mm_add_ps(__m128,__m128);
extern "C" __m128 _mm_shuffle_ps(__m128,__m128,unsigned int);

struct BlendOptions {
    unsigned char m_00;
    float m_04;
    unsigned char m_08,m_09,m_0a,m_0b,m_0c,m_0d;
    void FUN_00d74d40();
};
struct BlendObject {
    virtual ~BlendObject();
    unsigned short size;
    int unk08,unk0c,unk10;
    BlendObject* FUN_00d76ca0();
    int FUN_00d77200(void* vertices,BlendOptions* options);
};
struct BlendFactory {
    virtual void v0();
    virtual void* alloc(int size);
};
struct BlendHeap {
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vc();
    virtual void ReturnMemory(void*,int);
};
struct BlendRouter {
    int unk00,unk04,unk08;
    BlendHeap* heap;
    BlendFactory* factory;
};
static __forceinline BlendRouter* router() { return (BlendRouter*)FUN_00c85750(); }
struct BlendInput {
    const float* data;
    int count;
    int stride;
};
struct BlendArray {
    __m128* data;
    int count;
    int capacity;
    __forceinline __m128* AllocatePair() {
        BlendRouter* h=router();
        if(count==(capacity&0x3fffffff)) ResizeAudioStream((void*)h->heap,this,16);
        return data+count++;
    }
    __forceinline void clearAndFree(BlendHeap& heap) {
        count=0;
        if((capacity&0x80000000)==0) heap.ReturnMemory(data,(capacity&0x3fffffff)*16);
    }
    __forceinline ~BlendArray() { clearAndFree(*router()->heap); }
};
struct BlendSpan { __m128* data; int count; int stride; };

extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_move_ss(__m128,__m128);
extern "C" __m128 _mm_shuffle_ps(__m128,__m128,unsigned int);
extern "C" __m128 _mm_load_ps(const float*);
extern "C" void _ReadWriteBarrier();
extern "C" __m128 _mm_load_ps1(const float*);

extern "C" __m128 _mm_add_ps(__m128, __m128);

extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern __m128 DAT_01267e30;
extern double DAT_0104e138;
struct Scalar352 {
    __m128 value;
    Scalar352(const float& scalar) { value = _mm_load_ps1(&scalar); }
};
struct Vector352 {
    __m128 value;
    void SetZero() { value = DAT_01267e30; }
    void Add(const Vector352& other) { value = _mm_add_ps(other.value, value); }
    void Multiply(const Scalar352& factor) { value = _mm_mul_ps(factor.value, value); }
};
struct Node352 {
    Node352* next;
    unsigned int unk04, unk08, unk0c;
    Vector352 point;
};
struct Centroid352 {
    unsigned int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    Node352* head;
    int count;
    unsigned int unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c;
    unsigned int unk50,unk54,unk58,unk5c,unk60,unk64,unk68,unk6c;
    Vector352 centroid;
    const Vector352& FUN_00d7a180();
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);
extern "C" double fabs(double x);

struct __declspec(align(16)) S_00d7a200_V4 {
    float x, y, z, w;
};

struct S_00d7a200_Node {
    S_00d7a200_Node* m_next;
    int m_flag;
    int unk08;
    int unk0c;
    __declspec(align(16)) S_00d7a200_V4 m_pos;
    int unk20;
    int unk24;
    int unk28;
    float m_fHitFraction;
};

struct S_00d7a200_Owner {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14;
    int unk18; int unk1c; int unk20;
    S_00d7a200_Node* m_pFirstNode;
    int FUN_00d7a200(const S_00d7a200_V4& plane, float tol, int* counts, float* range);
};

extern const char str_010d365c[];
extern const char str_010d35f0[];

struct CharBuffer
{
    char* begin;
    char* end;
    unsigned int capacity;
    void FUN_00cb1600(char*, unsigned int);
    CharBuffer* FUN_00cc01c0(const char*);
    void FUN_00cc00e0();
};

struct BlockAllocAB
{
    virtual void v00();
    virtual void v04();
    __declspec(nothrow) virtual void ReleaseBlock(void* p, int size);
};

template <int SIZE> __forceinline void MemCpyOneAB(void* dst, const void* src)
{
    for (int i = 0; i < SIZE / 4; i++)
        ((unsigned int*)dst)[i] = ((const unsigned int*)src)[i];
}

template <class T> struct ArrAB
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            MemCpyOneAB<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};

struct PoolItem40
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
};

struct PoolBlock40
{
    PoolItem40 m_items[32];
    int unk800;
    int m_iAllocatedCount;

    static void operator delete(void* p, unsigned int size)
    {
        ((BlockAllocAB*)FUN_00c85750()->heap())->ReleaseBlock(p, size);
    }
};

struct PoolAllocator40
{
    ArrAB<PoolBlock40*> m_pools;

    void FUN_00d7adb0(PoolItem40* item);
};

// @f3 0x008f6e10 (community match, verified in this file)
struct Stream8F6E10
{
    int unk00, unk04, unk08;
    void FUN_00923070(char* buffer, int capacity);
    void FUN_00943710(const char* text);
    void FUN_00943a60();
};
struct Reporter8F6E10
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Report(int severity, unsigned int id, const char* buffer, const char* file, int line);
};
struct Heap8F6E10
{
    void* FUN_008f6d30(int bytes, int category);
};
extern Reporter8F6E10* DAT_010f3364;
extern void* DAT_010f3170;
extern Heap8F6E10* (__stdcall* DAT_00d9b080)(void*);
extern const char DAT_00e33ee0[], DAT_00e33ec4[];

struct Allocator8F6E10
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    char* cursor;
    void* block;
    char* begin;
    char* end;

    char* FUN_008f6e10(int bytes);
};

char* Allocator8F6E10::FUN_008f6e10(int bytes)
{
    if (!cursor)
    {
        char buffer[512];
        Stream8F6E10 stream;
        stream.FUN_00923070(buffer, sizeof(buffer));
        stream.FUN_00943710(DAT_00e33ee0);
        DAT_010f3364->Report(3, 0x2bebba62, buffer, DAT_00e33ec4, 301);
        stream.FUN_00943a60();
    }

    int capacity = bytes + 1024;
    if (capacity <= 4096)
        capacity = 4096;

    struct Header
    {
        char* cursor;
        void* block;
        char* begin;
        char* end;
    };
    Heap8F6E10* heap = DAT_00d9b080(DAT_010f3170);
    Header* next = static_cast<Header*>(heap->FUN_008f6d30(capacity + sizeof(Header), 23));
    next->cursor = cursor;
    next->block = block;
    next->begin = begin;
    next->end = end;
    char* data = reinterpret_cast<char*>(next + 1);
    cursor = data + bytes;
    char* limit = data + capacity;
    begin = data;
    end = limit;
    block = next;
    return data;
}


namespace fnv_00d7aea0 {
extern const char str_010d365c[];
extern const char str_010d35f0[];

struct CharBuffer
{
    char* begin;
    char* end;
    unsigned int capacity;
    void FUN_00cb1600(char*, unsigned int);
    CharBuffer* FUN_00cc01c0(const char*);
    void FUN_00cc00e0();
};

struct BlockAllocAB
{
    virtual void v00();
    virtual void v04();
    __declspec(nothrow) virtual void ReleaseBlock(void* p, int size);
};

template <int SIZE> __forceinline void MemCpyOneAB(void* dst, const void* src)
{
    for (int i = 0; i < SIZE / 4; i++)
        ((unsigned int*)dst)[i] = ((const unsigned int*)src)[i];
}

template <class T> struct ArrAB
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            MemCpyOneAB<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};

struct PoolItem48
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44;
};

struct PoolBlock48
{
    PoolItem48 m_items[32];
    int unk900;
    int m_iAllocatedCount;

    static void operator delete(void* p, unsigned int size)
    {
        ((BlockAllocAB*)FUN_00c85750()->heap())->ReleaseBlock(p, size);
    }
};

struct PoolAllocator48
{
    ArrAB<PoolBlock48*> m_pools;

    void FUN_00d7aea0(PoolItem48* item);
};

}  // namespace fnv_00d7aea0

extern "C" {
__m128 _mm_xor_ps(__m128,__m128);
__m128 _mm_mul_ps(__m128,__m128);
__m128 _mm_shuffle_ps(__m128,__m128,unsigned int);
__m128 _mm_add_ss(__m128,__m128);
void _mm_store_ss(float*,__m128);
}
extern __m128 DAT_010c44d0;
struct ProjectionAllocator {
    virtual void v0(); virtual void v4(); virtual void v8(); virtual void vc();
    virtual void ReturnMemory(void*,int);
};
struct ProjectionArray: D76250VectorArray {
    __forceinline ProjectionArray() { m_data=0; m_iElementCount=0; m_iCapacityState=0x80000000; }
    __forceinline ~ProjectionArray() {
        ProjectionAllocator& a=(ProjectionAllocator&)fnvc_adapt::FUN_00c85750().heap();
        m_iElementCount=0;
        if((m_iCapacityState&0x80000000)==0) a.ReturnMemory(m_data,getCapacity()*sizeof(D76250Vector4));
    }
    __forceinline D76250Vector4* _expandBy(D76250Allocator& alloc,int n) {
        int oldSize=m_iElementCount;
        reserve(alloc,oldSize+n);
        m_iElementCount+=n;
        return m_data+oldSize;
    }
    __forceinline D76250Vector4* expandBy(int n) {
        return _expandBy(fnvc_adapt::FUN_00c85750().heap(),n);
    }
};
struct ProjectionVertex {
    ProjectionVertex* next;
    int unk04,unk08,unk0c;
    D76250Vector4 value;
};
void __cdecl FUN_00dedcf0(D76250VectorArray*,D76250VectorArray*);
void __cdecl FUN_00dea810(D76250VectorArray*,const D76250Vector4*,D76250Vector4*);
struct ProjectionHull {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    ProjectionVertex* vertices; int numVertices;
    int unk2c,unk30,unk34,unk38,unk3c,unk40,unk44,unk48,unk4c,unk50,unk54,unk58,unk5c;
    D76250VectorArray cached;
    __forceinline void build() {
        ProjectionArray temp;
        D76250Vector4* out=temp.expandBy(numVertices);
        for(ProjectionVertex* v=vertices;v;v=v->next) *out++=v->value;
        FUN_00dedcf0(&temp,&cached);

    }
    __forceinline void support(const D76250Vector4& dir,D76250Vector4& out) {
        if(cached.m_iElementCount==0) build();
        FUN_00dea810(&cached,&dir,&out);
    }
    float FUN_00d7c610(const D76250Vector4& direction,float& lower,float& upper);
};
static __forceinline float dot3(const D76250Vector4& a,const D76250Vector4& b) {
    __m128 p=_mm_mul_ps(a.m_vComponents,b.m_vComponents);
    __m128 y=_mm_shuffle_ps(p,p,0x55);
    __m128 z=_mm_shuffle_ps(p,p,0xaa);
    float f; _mm_store_ss(&f,_mm_add_ss(z,_mm_add_ss(y,p))); return f;
}

namespace fnv_00d7e740 {
extern const char str_010d3574[];
struct ExportStream {
    int unk00,unk04,unk08;
    void FUN_00cb1600(char*,int);
    ExportStream* FUN_00cc01c0(const char*,int,char*);
    ExportStream* FUN_00cc02d0();
    void FUN_00cc01c0();
    void FUN_00cc00e0();
};

struct ExportAllocator {
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void ReturnMemory(void*, int);
};

template<class T> struct ExportArray {
    T* data;
    int size;
    int capacity;
    __forceinline void init() { data=0; size=0; capacity=0x80000000; }
    __forceinline void init(T* p,int n) { data=p; size=0; capacity=0x80000000|n; }
    __forceinline int getCapacity() const { return capacity & 0x3fffffff; }
    __forceinline void reserve(int n) {
        D76250Allocator& a=fnvc_adapt::FUN_00c85750().heap();
        if(getCapacity()<n) {
            int cap2=getCapacity()*2;
            int newcap=n<cap2?cap2:n;
            FUN_00c908c0(&a,this,newcap,sizeof(T));
        }
    }
    __forceinline void AddBack(const T& v) {
        D76250Allocator& a=fnvc_adapt::FUN_00c85750().heap();
        if(size==getCapacity()) ResizeAudioStream((void*)&a,this,sizeof(T));
        T* p=data+size;
        for(int i=0;i<1;++i) p[i]=v;
        ++size;
    }
    __forceinline void clearAndFree() {
        ExportAllocator& a=(ExportAllocator&)fnvc_adapt::FUN_00c85750().heap();
        size=0;
        if((capacity & 0x80000000)==0) a.ReturnMemory(data,getCapacity()*sizeof(T));
    }
};
template<class T,int N> struct ExportLocalArray:ExportArray<T> {
    T storage[N];
    __forceinline ExportLocalArray() { this->init(storage,N); }
    __forceinline ~ExportLocalArray() { this->clearAndFree(); }
};

struct ExportVertex {
    ExportVertex* next;
    int flag;
    int unk08,unk0c,unk10,unk14,unk18;
    int index;
    int x,y,z,unk2c,unk30;
    int alternateIndex;
};
struct ExportInt3 { int x,y,z; };
struct ExportFace {
    ExportFace* next;
    int unk04;
    ExportVertex* vertices[3];
    unsigned int links[3];
    int unk20,unk24,unk28,unk2c,unk30,unk34;
    int mark;
};
struct ExportNullEdge { ExportFace* face; int corner; __forceinline ExportNullEdge():face(0),corner(0) {} };
struct ExportEdge {
    int corner;
    ExportFace* face;
    __forceinline ExportEdge():face(0),corner(0) {}
    __forceinline ExportEdge(ExportFace* f,int c):face(f),corner(c) {}
    __forceinline ExportVertex* vertex() const { return face->vertices[corner]; }
    __forceinline ExportEdge next() const { return ExportEdge(face,(9>>(corner*2))&3); }
    __forceinline ExportEdge adjacent() const {
        unsigned int link=face->links[corner];
        return ExportEdge((ExportFace*)(link&~3u),link&3);
    }
};
static __forceinline int NextCorner(int i) { return (9>>(i*2))&3; }

union ExportWorkspace { ExportStream stream; ExportArray<ExportFace*> sorted; ExportArray<ExportVertex*> map; };
struct ExportCompare { unsigned char dummy; };
void __cdecl QuickSortByKey(void**,int,int,ExportCompare);

struct ExportShape {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    ExportVertex* vertices;
    int numVertices,unk2c,unk30,unk34,unk38;
    ExportFace* faces;
    int numFaces,unk44,unk48,unk4c,unk50,unk54;
    int numPolygons;
    int unk5c,unk60,unk64,unk68,unk6c,unk70,unk74,unk78,unk7c;
    int unk80,unk84,unk88,unk8c,unk90,unk94,unk98,unk9c;
    int unka0,unka4,unka8,unkac,unkb0,unkb4,unkb8,unkbc;
    int unkc0,unkc4,unkc8,unkcc,unkd0,unkd4,unkd8,unkdc;
    int unke0,unke4,unke8,unkec,unkf0,unkf4,unkf8,unkfc;
    int unk100,unk104,unk108,unk10c,unk110,unk114,unk118,unk11c;
    int unk120,unk124,unk128,unk12c,unk130,unk134,unk138,unk13c;
    int unk140,unk144,unk148,unk14c,unk150,unk154,unk158,unk15c;
    int unk160,unk164,unk168,unk16c,unk170,unk174,unk178,unk17c;
    int unk180,unk184,unk188,unk18c,unk190,unk194,unk198,unk19c;
    int unk1a0,unk1a4;
    int dimension,unk1ac,index;
    unsigned char unk1b4;
    bool indexed;
    int FUN_00d7e740(ExportArray<unsigned char>& sizes,ExportArray<unsigned short>& indices,bool useIndex,bool rotate);
};

}  // namespace fnv_00d7e740

extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);

struct __declspec(align(16)) FUN_00d7a0b0_Matrix {
    __m128 m_row0;
    __m128 m_row1;
    __m128 m_row2;
    __m128 m_row3;
};

struct __declspec(align(16)) FUN_00d7a0b0_Vertex {
    FUN_00d7a0b0_Vertex* m_next;
    int unk04;
    int unk08;
    int unk0C;
    __m128 m_pos;
};

struct FUN_00d7a0b0_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    FUN_00d7a0b0_Vertex* m_kVertices;
    void FUN_00d7a0b0(const FUN_00d7a0b0_Matrix* m, const __m128* scale, __m128* out);
};

extern "C" {
__m128 __cdecl _mm_load_ss(float const*);
void __cdecl _mm_store_ps(float*, __m128);
}

extern float DAT_01011d78;

struct SpatialNode {
    SpatialNode* m_next;
    int unk04;
    int unk08;
    int unk0C;
    __m128 m_pos;
};

struct SpatialSimd {
    __m128 q;
};

__declspec(align(16)) struct SpatialVec4 {
    float x;
    float y;
    float z;
    float w;
};

struct FUN_00d7a350_cls {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    SpatialNode* m_24;

    SpatialSimd FUN_00d7a350(const __m128& p);
};

extern const char str_010d3574[];
struct D76250Allocator : S_00d7a010_Alloc {};

struct PolygonStream {
    int unk00, unk04, unk08;
    void FUN_00cb1600(char*, int) throw();
    PolygonStream& FUN_00cc01c0(const char*) throw();
    PolygonStream& FUN_00cc02d0(unsigned int) throw();
    void FUN_00cc00e0() throw();
};

template<class T> struct PolygonArray {
    T* data;
    int size;
    int capacityAndFlags;
    __forceinline PolygonArray() : data(0), size(0), capacityAndFlags(0x80000000) {}
    struct NoInit {};
    __forceinline explicit PolygonArray(NoInit) {}
    __forceinline void init() { data = 0; size = 0; capacityAndFlags = 0x80000000; }
    __forceinline PolygonArray(T* p, int cap) : data(p), size(0), capacityAndFlags(cap | 0x80000000) {}
    __forceinline int capacity() const { return capacityAndFlags & 0x3fffffff; }
    __forceinline void reserve(D76250Allocator& a, int n) {
        if (capacity() < n) {
            int cap2 = 2 * capacity();
            int newSize = n < cap2 ? cap2 : n;
            FUN_00c908c0(&a, this, newSize, sizeof(T));
        }
    }
    __forceinline void reserve(int n) {
        reserve(fnvc_adapt::FUN_00c85750().heap(), n);
    }
    __forceinline static void construct(T* p, int n, const T& value) {
        for (int i = 0; i < n; ++i) p[i] = value;
    }
    __forceinline void pushBackUnchecked(const T& value) {
        construct(data + size, 1, value);
        ++size;
    }
    __forceinline void AddBack(const T& value) {
        D76250MemoryRouter& router = fnvc_adapt::FUN_00c85750();
        if (size == capacity()) ResizeAudioStream((void*)&router.heap(), this, sizeof(T));
        pushBackUnchecked(value);
    }
    __forceinline void ClearAndRelease(D76250Allocator& a) {
        size = 0;
        if ((capacityAndFlags & 0x80000000) == 0) a.ReturnMemory(data, capacity() * sizeof(T));
    }
    __forceinline void release() { ClearAndRelease(fnvc_adapt::FUN_00c85750().heap()); }
};
template<class T, int N> struct PolygonInplaceArray : PolygonArray<T> {
    T storage[N];
    __forceinline PolygonInplaceArray() : PolygonArray<T>(storage, N) {}
};

struct PolygonInt3 {
    int x, y, z;
    __forceinline void setSub(const PolygonInt3& a, const PolygonInt3& b) {
        y = a.y - b.y; x = a.x - b.x; z = a.z - b.z;
    }
    __forceinline void setCross(const PolygonInt3& a, const PolygonInt3& b) {
        x = a.y * b.z - a.z * b.y;
        y = a.z * b.x - a.x * b.z;
        z = a.x * b.y - a.y * b.x;
    }
    __forceinline __int64 lengthSquared() const {
        return (__int64)x * x + (__int64)y * y + (__int64)z * z;
    }
};
struct PolygonVertex {
    PolygonVertex* next;
    int flag;
    int unk08, unk0c;
    hkVec4 position;
    PolygonInt3 integerPosition;
    float distance;
    int unk30;
    int index;
    __forceinline int getID() const { return *(const int*)&position.w & 0xc0ffffff; }
    __forceinline const int& getIndex() const { return index; }
};
struct PolygonTriangle {
    PolygonTriangle* next;
    int unk04;
    PolygonVertex* vertices[3];
    unsigned int links[3];
    int unk20, unk24, unk28, unk2c, unk30, unk34;
    int component;
    __forceinline PolygonTriangle* neighbor(int edge) const {
        return (PolygonTriangle*)(links[edge] & ~3);
    }
};
struct PolygonLess {
    bool flag;
    __forceinline PolygonLess() : flag(false) {}
};
void __cdecl QuickSortByKey(PolygonTriangle**, int, int, PolygonLess);
struct PolygonEdge {
    PolygonTriangle* triangle;
    int edge;
    __forceinline PolygonEdge() : triangle(0), edge(0) {}
    __forceinline PolygonEdge(PolygonTriangle* t, int e) : triangle(t), edge(e) {}
    __forceinline static int nextIndex(int e) { return (9 >> (e + e)) & 3; }
    __forceinline PolygonEdge getNext() const { return PolygonEdge(triangle, nextIndex(edge)); }
    __forceinline PolygonEdge getTwin() const {
        unsigned int link = triangle->links[edge];
        PolygonEdge r; r.edge = link & 3; r.triangle = (PolygonTriangle*)(link & ~3); return r;
    }
    __forceinline void advance(int component) {
        *this = getNext();
        while (triangle->neighbor(edge)->component == component) {
            *this = getTwin();
            *this = getNext();
        }
    }
    __forceinline PolygonVertex* vertex() const { return triangle->vertices[edge]; }
};

struct PolygonMesh {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    PolygonVertex* vertexHead;
    int vertexCount;
    int unk2c, unk30, unk34, unk38;
    PolygonTriangle* triangleHead;
    int triangleCount;
    int unk44, unk48, unk4c, unk50, unk54;
    int polygonCount;
    int unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8, unkfc;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    int unk120, unk124, unk128, unk12c, unk130, unk134, unk138, unk13c;
    int unk140, unk144, unk148, unk14c, unk150, unk154, unk158, unk15c;
    int unk160, unk164, unk168, unk16c, unk170, unk174, unk178, unk17c;
    int unk180, unk184, unk188, unk18c, unk190, unk194, unk198, unk19c;
    int unk1a0, unk1a4;
    int dimension;
    int unk1ac;
    int errorValue;
    char unk1b4;
    bool hasIndices;
    int FUN_00d7df60(PolygonArray<int>& counts, PolygonArray<int>& indices, bool ids, bool rotate);
};

extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);

extern const double DAT_01011588;
extern const char str_010d3574[];
extern const char str_010d3540[];

union D81340Vec4 {
    __m128 q;
    struct { float x; float y; float z; float w; };
};

struct D81340Dbg {
    void* unk00;
    int unk04;
    int unk08;
    void __thiscall FUN_00cb1600(char* buf, unsigned int n);
    D81340Dbg* __thiscall FUN_00cc01c0(const char* fmt, int a, const char* b);
    D81340Dbg* __thiscall FUN_00cc02d0();
    void __thiscall FUN_00cc01c0();
    void __thiscall FUN_00cc00e0();
};

struct D81340Workspace {
    union {
        D81340Dbg stream;
        struct { float lower; float upper; } bounds;
    };
    float bestR;
    float result;
    float bestD;
};
struct D81340Transform { D81340Vec4 c0,c1,c2,c3; };

struct D81340F090 { float __thiscall FUN_00d7f090(const D81340Vec4& dir, void* b, void* c); };
struct D81340F610 { int m_auiShapeKeys; float __thiscall FUN_00d7c610(const D81340Vec4& dir, float* b, float* c); };

struct D81340Cls {
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
    D81340Vec4* m_54;
    int m_58;
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
    int m_e0;
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
    int m_1a8;
    int unk1ac;
    void* m_1b0;
    unsigned char unk1b4;
    unsigned char m_1b5;
    unsigned char unk1b6;
    unsigned char unk1b7;
    float __thiscall FUN_00d7c610(int, float*, float*);
    float __thiscall FUN_00d7f090(int, D81340Vec4*, D81340Transform*);
    void __thiscall FUN_00d81340(D81340Vec4& a0, D81340Transform& a1);
};

struct SupportVector { __m128 q; };
struct SupportShape {
    void FUN_00d76320(const SupportVector& input, SupportVector& output);
    float FUN_00d768b0(const SupportVector& input);
};

extern float DAT_0104e148;
class PlaneScalar {
    __m128 value;
public:
    PlaneScalar(const __m128& q):value(q) {}
    PlaneScalar() {}
    operator float() const { float result; _mm_store_ss(&result,value); return result; }
    __forceinline const __m128& quad() const { return value; }
};
inline PlaneScalar __cdecl operator+(const PlaneScalar& a,const PlaneScalar& b) {
    return _mm_add_ss(a.quad(),b.quad());
}
struct PlaneVector {
    __m128 value;
    __forceinline PlaneScalar dot(const PlaneVector& b) const {
        __m128 product=_mm_mul_ps(value,b.value);
        __m128 xy=_mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
        return _mm_add_ss(_mm_shuffle_ps(product,product,0xaa),xy);
    }
    __forceinline PlaneScalar offset(int i) const {
        switch(i) {
        case 0: return value;
        case 1: return _mm_shuffle_ps(value,value,0x55);
        case 2: return _mm_shuffle_ps(value,value,0xaa);
        default: return _mm_shuffle_ps(value,value,0xff);
        }
    }
};
struct PlaneArgument {
    const PlaneVector* p;
    PlaneArgument(const PlaneVector* v):p(v) {}
};
struct PlaneHull {
    int FUN_00d74f10();
    const PlaneVector& FUN_00d74fb0(int i);
    float FUN_00d75880(PlaneArgument point);
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern "C" void _ReadWriteBarrier(void);
extern "C" unsigned __int64 __rdtsc(void);

extern "C" __m128 _mm_sub_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);
extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_load_ps(const float* p);
extern "C" void _mm_store_ps(float* p, __m128 a);

extern unsigned long DAT_0126835c;
extern float DAT_01011d78;
extern const __m128 DAT_010c7160;

struct Tt_ProfRec {
    const char* m_pName;
    unsigned long m_iTick;
    unsigned long unk08;
};
struct Tt_ProfBuf {
    unsigned long unk00;
    Tt_ProfRec* m_pCur;
    unsigned long unk08;
    Tt_ProfRec* m_pRecordEnd;
};

struct __declspec(align(16)) Tt_Mat3 {
    __m128 r0;
    __m128 r1;
    __m128 r2;
    int FUN_00cd4f10(float eps);
};

struct __declspec(align(16)) Tt_W {
    float x, y, z, w;
};


extern "C" __m128 _mm_setr_ps(float a, float b, float c, float d);
struct Tt_Simd {
    __m128 m_vValue;
    Tt_Simd(const __m128& x) : m_vValue(x) {}
    operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
};
static __forceinline Tt_Simd operator-(const Tt_Simd& r)
{
    extern const __m128 DAT_010c7160;
    return _mm_sub_ss(DAT_010c7160, r.m_vValue);
}
struct __declspec(align(16)) Tt_V4 {
    __m128 m_vComponents;
    __forceinline void set(float a, float b, float c, float d = 0) { m_vComponents = _mm_setr_ps(a, b, c, d); }
    __forceinline float& operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
    __forceinline const float& operator()(int a) const { return reinterpret_cast<const float*>(&m_vComponents)[a]; }
    __forceinline Tt_Simd getW() const { return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff); }
    __forceinline Tt_Simd dot4xyz1(const Tt_V4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        __m128 zwSum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff));
        return _mm_add_ps(xySum, zwSum);
    }
};
struct __declspec(align(16)) Tt_M3 {
    Tt_V4 m_col[3];
    int FUN_00cd4f10(float eps);
    __forceinline void setRows(const Tt_V4& r0, const Tt_V4& r1, const Tt_V4& r2)
    {
        m_col[0].set(r0(0), r1(0), r2(0));
        m_col[1].set(r0(1), r1(1), r2(1));
        m_col[2].set(r0(2), r1(2), r2(2));
    }
};

struct S_00d77840 {
    int unk00;
    int FUN_00d77380(D76250VectorArray* view, const D76250Vector4* sph, int a4);
    int FUN_00d77840(const D76250Vector4* pts, int n, const D76250Vector4* sph, int a4);
};

extern "C" {
__m128 _mm_sub_ss(__m128, __m128);
__m128 _mm_mul_ss(__m128, __m128);
__m128 _mm_rsqrt_ss(__m128);
__m128 _mm_cmpeq_ss(__m128, __m128);
__m128 _mm_andnot_ps(__m128, __m128);
__m128 _mm_set_ss(float);
}
extern const __m128 DAT_010c7160;

class S00d79ab0_SimdReal {
public:
    S00d79ab0_SimdReal(const __m128& x) : m_vValue(x) {}
    S00d79ab0_SimdReal(float x) { m_vValue = _mm_load_ss(&x); }
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const __m128& getQuad() const { return m_vValue; }
private:
    __m128 m_vValue;
};
inline S00d79ab0_SimdReal __cdecl operator*(const S00d79ab0_SimdReal& r, const S00d79ab0_SimdReal& s) { return _mm_mul_ss(r.getQuad(), s.getQuad()); }
inline S00d79ab0_SimdReal __cdecl operator+(const S00d79ab0_SimdReal& r, const S00d79ab0_SimdReal& s) { return _mm_add_ss(r.getQuad(), s.getQuad()); }
inline S00d79ab0_SimdReal __cdecl operator-(const S00d79ab0_SimdReal& r) { return _mm_sub_ss(DAT_010c7160, r.getQuad()); }

class S00d79ab0_Vector4 {
public:
    __forceinline void setSub4(const S00d79ab0_Vector4& v0, const S00d79ab0_Vector4& v1) { m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents); }
    __forceinline S00d79ab0_SimdReal dot3(const S00d79ab0_Vector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S00d79ab0_SimdReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline S00d79ab0_SimdReal distanceToSquared3(const S00d79ab0_Vector4& p) const
    {
        S00d79ab0_Vector4 d;
        d.setSub4(*this, p);
        return d.lengthSquared3();
    }
    __forceinline S00d79ab0_SimdReal lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 len2 = this->dot3(*this).getQuad();
        const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const __m128 approx = _mm_rsqrt_ss(len2);
        const __m128 refined = _mm_mul_ss(_mm_mul_ss(half, approx), _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline void normalize3()
    {
        __m128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    __forceinline float& operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
    __forceinline void operator=(const S00d79ab0_Vector4& v) { m_vComponents = v.m_vComponents; }
    __m128 m_vComponents;
};

struct S00d79ab0_TypeIsPod {};
template <typename T> struct S00d79ab0_IsPodType { typedef S00d79ab0_TypeIsPod type; };

struct S00d79ab0_ArrayUtil {
    template <typename T>
    static __forceinline void constructWithCopy(T* t, int n, const T& tcopy, S00d79ab0_TypeIsPod)
    {
        for (int i = 0; i < n; ++i) {
            t[i] = tcopy;
        }
    }
    static __forceinline void GrowArrayCapacity(S_00d7a010_Alloc& a, void* array, int reqElem, int sizeElem) { FUN_00c908c0(&a, array, reqElem, sizeElem); }
    static __forceinline void GrowArray(S_00d7a010_Alloc& a, void* array, int sizeElem) { ResizeAudioStream(&a, array, sizeElem); }
};

template <typename T>
static __forceinline void S00d79ab0_bufFree(S_00d7a010_Alloc& a, void* p, int numElem) { a.ReturnMemory(p, numElem * (int)sizeof(T)); }

struct S00d79ab0_ContainerHeapAllocator {
    __forceinline S_00d7a010_Alloc& get(const void*) { return S_00d7a010_Router::FUN_00c85750().heap(); }
};

template <typename T>
class S00d79ab0_ArrayBase {
public:
    __forceinline S00d79ab0_ArrayBase() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~S00d79ab0_ArrayBase() {}
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline const T& operator[](int i) const { return m_data[i]; }
    __forceinline void clear() { m_iElementCount = 0; }
    __forceinline void _clearAndDeallocate(S_00d7a010_Alloc& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0) {
            S00d79ab0_bufFree<T>(alloc, m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void _reserveExactly(S_00d7a010_Alloc& alloc, int n)
    {
        if (getCapacity() < n) {
            S00d79ab0_ArrayUtil::GrowArrayCapacity(alloc, this, n, sizeof(T));
        }
    }
    __forceinline void pushBackUnchecked(const T& t)
    {
        S00d79ab0_ArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, typename S00d79ab0_IsPodType<T>::type());
        m_iElementCount++;
    }
    __forceinline void _pushBack(S_00d7a010_Alloc& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity()) {
            S00d79ab0_ArrayUtil::GrowArray(alloc, this, sizeof(T));
        }
        S00d79ab0_ArrayUtil::constructWithCopy(m_data + m_iElementCount, 1, t, typename S00d79ab0_IsPodType<T>::type());
        m_iElementCount++;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

template <typename T>
class S00d79ab0_Array : public S00d79ab0_ArrayBase<T> {
public:
    typedef S00d79ab0_ContainerHeapAllocator AllocatorType;
    __forceinline S00d79ab0_Array() : S00d79ab0_ArrayBase<T>() {}
    __forceinline ~S00d79ab0_Array() { ClearAndRelease(); }
    __forceinline void ClearAndRelease() { S00d79ab0_ArrayBase<T>::_clearAndDeallocate(AllocatorType().get(this)); }
    __forceinline void AddBack(const T& e) { S00d79ab0_ArrayBase<T>::_pushBack(AllocatorType().get(this), e); }
    __forceinline void reserveExactly(int size) { S00d79ab0_ArrayBase<T>::_reserveExactly(AllocatorType().get(this), size); }
};

struct S00d79ab0_RadialSort {
    __forceinline S00d79ab0_RadialSort(const S00d79ab0_Vector4& c) : m_kCenterPosition(c) {}
    const S00d79ab0_Vector4& m_kCenterPosition;
};
void __cdecl FUN_00d7aaf0(S00d79ab0_Vector4* pArr, int d, int h, S00d79ab0_RadialSort cmpLess);

class S00d79ab0_Bool {
public:
    __forceinline S00d79ab0_Bool& operator=(bool b) { m_cBooleanValue = (char)(b ? 1 : 0); return *this; }
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
private:
    char m_cBooleanValue;
};

struct S00d79ab0_Impl {
    int unk00;
    int unk04;
    char unk08;
    S00d79ab0_Bool m_flag09;
    S00d79ab0_Bool m_flag0a;
    char unk0b;
    S00d79ab0_SimdReal FUN_00d7a350(const S00d79ab0_Vector4& c) const;
    int FUN_00d83430(float planeW, class S00d79ab0_Hull** posOut, class S00d79ab0_Hull** negOut, float thickness) const;
};
struct S00d79ab0_ImplFlags {
    int unk1b0;
    S00d79ab0_Bool m_bFirstImplementationFlag;
    S00d79ab0_Bool m_bSecondImplementationFlag;
};

class S00d79ab0_Hull {
public:
    virtual ~S00d79ab0_Hull();
    void operator delete(void* p);
    S00d79ab0_Hull* FUN_00d76cf0() const;
    int FUN_00d790a0(const S00d79ab0_Vector4& plane, S00d79ab0_Hull** posOut, S00d79ab0_Hull** negOut, float thickness) const;
    void SetValue(float minCosAngle, bool keepPlanes);
    int FUN_00d762f0();
    int unk04;
    S00d79ab0_Impl* m_data;
    __forceinline bool hasIndexing() const { return reinterpret_cast<const S00d79ab0_ImplFlags*>(reinterpret_cast<const char*>(m_data) + 0x1b0)->m_bSecondImplementationFlag; }
    __forceinline bool hasMassProperties() const { return reinterpret_cast<const S00d79ab0_ImplFlags*>(reinterpret_cast<const char*>(m_data) + 0x1b0)->m_bFirstImplementationFlag; }
};

extern "C" {
__m128 _mm_sub_ps(__m128,__m128);
__m128 _mm_mul_ps(__m128,__m128);
__m128 _mm_add_ss(__m128,__m128);
__m128 _mm_shuffle_ps(__m128,__m128,unsigned int);
__m128 _mm_sqrt_ss(__m128);
void _mm_store_ss(float*,__m128);
}
class S00d7cf00_SimdReal {
public:
    S00d7cf00_SimdReal(const __m128& x) : m_vValue(x) {}
    operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline const __m128& getQuad() const { return m_vValue; }
    __m128 m_vValue;
};
class S00d7cf00_Vector4 {
public:
    __forceinline void setSub4(const S00d7cf00_Vector4& v0, const S00d7cf00_Vector4& v1) { m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents); }
    __forceinline S00d7cf00_SimdReal dot3(const S00d7cf00_Vector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S00d7cf00_SimdReal length3() const { return _mm_sqrt_ss(this->dot3(*this).getQuad()); }
    __forceinline S00d7cf00_SimdReal distanceTo3(const S00d7cf00_Vector4& p) const
    {
        S00d7cf00_Vector4 d;
        d.setSub4(*this, p);
        return d.length3();
    }
    __forceinline void operator=(const S00d7cf00_Vector4& v) { m_vComponents = v.m_vComponents; }
    __m128 m_vComponents;
};
struct S00d7cf00_Vertex {
    S00d7cf00_Vertex* m_next;
    S00d7cf00_Vertex* m_pSecondNode;
    int unk08;
    int unk0c;
    S00d7cf00_Vector4 m_pObservedSource;
    int m_uiX[3];
    __forceinline int compare(const S00d7cf00_Vertex& o) const
    {
        for (int i = 0; i < 3; ++i) {
            if (m_uiX[i] < o.m_uiX[i]) return -1;
            if (m_uiX[i] > o.m_uiX[i]) return 1;
        }
        return 0;
    }
    static __forceinline bool isOrdered(const S00d7cf00_Vertex* a, const S00d7cf00_Vertex* b)
    {
        const int c((*a).compare(*b));
        if (c < 0) return true;
        if (c > 0) return false;
        return true;
    }
};
struct S00d7cf00_Triangle {
    S00d7cf00_Triangle* m_next;
    S00d7cf00_Triangle* m_pSecondNode;
    S00d7cf00_Vertex* m_kVertices[3];
    unsigned long m_ppLinks[3];
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int m_iTriangleValueAtOffset0x38;
};
struct S00d7cf00_HullEdge;
template <typename T>
static __forceinline void S00d7cf00_ulong2uid(unsigned long uid, T*& t, unsigned& i)
{
    i = (unsigned)(uid & 3);
    uid &= ~3;
    t = *(T**)&uid;
}
template <typename T>
static __forceinline void S00d7cf00_unpackUid(unsigned long uid, T*& t, unsigned& i) { S00d7cf00_ulong2uid(uid, t, i); }
struct S00d7cf00_TopoEdge {
    __forceinline S00d7cf00_TopoEdge(S00d7cf00_Triangle* t, unsigned i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    __forceinline S00d7cf00_TopoEdge(const unsigned long& id) { S00d7cf00_unpackUid(id, m_pkTriangle, m_uiEdgeIndex); }
    static __forceinline unsigned ip1mod3(unsigned i) { return (9 >> (i << 1)) & 3; }
    __forceinline S00d7cf00_HullEdge link() const;
    __forceinline S00d7cf00_Triangle* triangle() const { return m_pkTriangle; }
    __forceinline S00d7cf00_Vertex*& start() const { return m_pkTriangle->m_kVertices[m_uiEdgeIndex]; }
    __forceinline S00d7cf00_Vertex*& end() const { return m_pkTriangle->m_kVertices[ip1mod3(m_uiEdgeIndex)]; }
    __forceinline bool isValid() const { return triangle() != 0; }
    __forceinline bool isNaked() const;
    __forceinline bool isMaster() const { return S00d7cf00_Vertex::isOrdered(start(), end()) || isNaked(); }
    S00d7cf00_Triangle* m_pkTriangle;
    unsigned m_uiEdgeIndex;
};
struct S00d7cf00_HullEdge : S00d7cf00_TopoEdge {
    __forceinline S00d7cf00_HullEdge(S00d7cf00_Triangle* t, int i) : S00d7cf00_TopoEdge(t, i) {}
    __forceinline S00d7cf00_HullEdge(unsigned long id) : S00d7cf00_TopoEdge(id) {}
    __forceinline bool samePlane() const { return triangle()->m_iTriangleValueAtOffset0x38 == link().triangle()->m_iTriangleValueAtOffset0x38; }
};
__forceinline S00d7cf00_HullEdge S00d7cf00_TopoEdge::link() const { return S00d7cf00_HullEdge(m_pkTriangle->m_ppLinks[m_uiEdgeIndex]); }
struct S00d7cf00_FreeAllocator {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
    __forceinline void _bufFree(void* p, int numElem) { ReturnMemory(p, numElem * (int)sizeof(S00d7cf00_Vector4)); }
};
class S00d7cf00_Array {
public:
    __forceinline S00d7cf00_Array() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~S00d7cf00_Array() { ClearAndRelease(); }
    __forceinline D76250Allocator& alloc() { return fnvc_adapt::FUN_00c85750().heap(); }
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline S00d7cf00_Vector4& operator[](int i) { return m_data[i]; }
    __forceinline void clear() { m_iElementCount = 0; }
    __forceinline void ClearAndRelease() { _clearAndDeallocate((S00d7cf00_FreeAllocator&)alloc()); }
    __forceinline void _clearAndDeallocate(S00d7cf00_FreeAllocator& a)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            a._bufFree(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(D76250Allocator& a, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&a, this, newSize, sizeof(S00d7cf00_Vector4));
        }
    }
    __forceinline S00d7cf00_Vector4* _expandBy(D76250Allocator& a, int n)
    {
        int oldsize = m_iElementCount;
        GrowArrayCapacity(a, m_iElementCount + n);
        m_iElementCount += n;
        return m_data + oldsize;
    }
    __forceinline S00d7cf00_Vector4* expandBy(int n) { return _expandBy(alloc(), n); }
    S00d7cf00_Vector4* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct S00d7cf00_Hull {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    S00d7cf00_Vertex* m_firstVertex;
    int m_iStridedVertexCount;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    S00d7cf00_Triangle* m_firstTriangle;
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
    int m_eVertexFloatDimensions;
    __forceinline void fetchWorldPositions(S00d7cf00_Array& positions) const
    {
        S00d7cf00_Vector4* p = positions.expandBy(m_iStridedVertexCount);
        for (const S00d7cf00_Vertex* v = m_firstVertex; v; v = v->m_next)
            *p++ = v->m_pObservedSource;
    }
    float FUN_00d7cf00() const;
};

extern "C" __m128 __cdecl _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 __cdecl _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 __cdecl _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 __cdecl _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" __m128 __cdecl _mm_xor_ps(__m128 a, __m128 b);
extern "C" void __cdecl _mm_store_ss(float* p, __m128 a);
extern "C" void* __cdecl memcpy(void* d, const void* s, unsigned int n);

extern double DAT_01032980;
extern double DAT_0101dae8;
extern unsigned int DAT_0126a3e0;

struct __declspec(align(16)) S_00d827b0_Sign {
    unsigned int a, b, c, d;
};
extern __m128 DAT_010c44d0;

struct __declspec(align(16)) S_00d827b0_V4 {
    __m128 quad;
};

struct __declspec(align(16)) S_00d827b0_Xf {
    float c0x, c0y, c0z, c0w;
    float c1x, c1y, c1z, c1w;
    float c2x, c2y, c2z, c2w;
    float c3x, c3y, c3z, c3w;
    void FUN_00de8e50(const S_00d827b0_Xf* other);
};

static __forceinline __m128 S_00d827b0_load(const void* p) { return *(const __m128*)p; }
static __forceinline unsigned int S_00d827b0_ubit(const void* p) { return *(const unsigned int*)p; }

static __forceinline float supportDot(const S_00d827b0_V4& a, const S_00d827b0_V4& b) {
    __m128 prod = _mm_mul_ps(S_00d827b0_load(&a.quad.m128_f32[0]), S_00d827b0_load(&b.quad.m128_f32[0]));
    __m128 ys = _mm_shuffle_ps(prod, prod, 0x55);
    __m128 zs = _mm_shuffle_ps(prod, prod, 0xaa);
    float dot;
    _mm_store_ss(&dot, _mm_add_ss(zs, _mm_add_ss(ys, prod)));
    return dot;
}

struct S_00d827b0_Param {
    D76250Vector4* points;
    int count;
};

struct S_00d827b0_Node {
    S_00d827b0_Node* next;
    int unk04;
    int unk08;
    int unk0c;
    D76250Vector4 pos;
};

struct PlaneFace {
    PlaneFace* next;
    int unk04;
    S_00d827b0_Node* vertices[3];
};

extern "C" void __cdecl FUN_00d74c70(S_00d827b0_V4* v, float t, S_00d827b0_Xf* out);

struct FixBool { char value; };

struct S_00d827b0_Owner {
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20;
    S_00d827b0_Node* m_pFirstNode;
    int m_uiItemCount;
    int unk2c, unk30, unk34, unk38;
    PlaneFace* m_faces;
    int unk40, unk44, unk48;
    int unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    int unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88;
    int unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8;
    int unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8;
    int unkcc, unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8;
    int unkec, unkf0, unkf4, unkf8, unkfc, unk100, unk104, unk108;
    int unk10c, unk110, unk114, unk118, unk11c, unk120, unk124, unk128;
    int unk12c, unk130, unk134, unk138, unk13c, unk140, unk144, unk148;
    int unk14c, unk150, unk154, unk158, unk15c, unk160, unk164, unk168;
    int unk16c, unk170, unk174, unk178, unk17c, unk180, unk184, unk188;
    int unk18c, unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8;
    int unk1ac, unk1b0;
    FixBool m_b1b4;
    FixBool m_b1b5;

    float FUN_00d7a810(S_00d827b0_Param* p, S_00d827b0_Xf* xf, S_00d827b0_V4* out);
    void FUN_00d7a0b0(S_00d827b0_Xf* xf, S_00d827b0_V4* dir, S_00d827b0_V4* out);
    void FUN_00d81510(D76250Vector4* data, int n, int a, int b);
    void FUN_00d7d2a0();
    void FUN_00d7b600();
    void FUN_00d827b0(S_00d827b0_Param* param);
};


extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_mul_ss(__m128, __m128);
extern "C" __m128 _mm_rsqrt_ss(__m128);
extern "C" __m128 _mm_cmpeq_ss(__m128, __m128);
extern "C" __m128 _mm_andnot_ps(__m128, __m128);
extern float DAT_01017718;
extern float DAT_01016248;
extern float DAT_01011d78;

extern "C" __m128 __cdecl _mm_add_ps(__m128, __m128);

struct S00d82ad0_Vec {
    __m128 q;
    __forceinline void operator=(const S00d82ad0_Vec& o) { q = o.q; }
};

struct S00d82ad0_Vtx {
    S00d82ad0_Vtx* next;
    S00d82ad0_Vtx* prev;
    int unk08;
    int unk0c;
    S00d82ad0_Vec m_pObservedSource;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    float m_data;
};

struct S00d82ad0_Tri {
    S00d82ad0_Tri* next;
    S00d82ad0_Tri* prev;
    S00d82ad0_Vtx* m_kVertices[3];
    unsigned long m_ppLinks[3];
    __forceinline S00d82ad0_Vtx*& vertex(unsigned i) { return m_kVertices[i]; }
    __forceinline unsigned long& link(unsigned i) { return m_ppLinks[i]; }
};

struct S00d82ad0_E {
    S00d82ad0_Tri* m_pkTriangle;
    unsigned m_uiEdgeIndex;
    static __forceinline unsigned ip1mod3(unsigned i) { return (0x09 >> (i << 1)) & 3; }
    static __forceinline unsigned ip2mod3(unsigned i) { return (0x12 >> (i << 1)) & 3; }
    __forceinline S00d82ad0_E() {}
    __forceinline S00d82ad0_E(S00d82ad0_Tri* t, unsigned i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    __forceinline S00d82ad0_E(const unsigned long& id) { unsigned long uid = id; m_uiEdgeIndex = (unsigned)(uid & 3); uid &= ~3; m_pkTriangle = *(S00d82ad0_Tri**)&uid; }
    __forceinline S00d82ad0_E next() const { return S00d82ad0_E(m_pkTriangle, ip1mod3(m_uiEdgeIndex)); }
    __forceinline S00d82ad0_E prev() const { return S00d82ad0_E(m_pkTriangle, ip2mod3(m_uiEdgeIndex)); }
    __forceinline S00d82ad0_E link() const { return S00d82ad0_E(m_pkTriangle->link(m_uiEdgeIndex)); }
    __forceinline S00d82ad0_E turnCcw() const { return link().next(); }
    __forceinline S00d82ad0_E turnCw() const { return prev().link(); }
    __forceinline unsigned long uid() const { return (*(const unsigned long*)&m_pkTriangle) + (unsigned long)m_uiEdgeIndex; }
    __forceinline S00d82ad0_Vtx*& start() const { return m_pkTriangle->vertex(m_uiEdgeIndex); }
    __forceinline S00d82ad0_Vtx*& end() const { return m_pkTriangle->vertex(ip1mod3(m_uiEdgeIndex)); }
    __forceinline S00d82ad0_Vtx*& apex() const { return m_pkTriangle->vertex(ip2mod3(m_uiEdgeIndex)); }
    __forceinline S00d82ad0_E self() const { return S00d82ad0_E(m_pkTriangle, m_uiEdgeIndex); }
    __forceinline bool isValid() const { return m_pkTriangle != 0; }
    __forceinline bool operator!=(const S00d82ad0_E& e) const { return uid() != e.uid(); }
    template <class F>
    __forceinline void applyFan(F& fnc) const
    {
        S00d82ad0_E base(self());
        S00d82ad0_E curr(base);
        do {
            if (fnc(curr)) curr = curr.turnCw(); else return;
        } while (curr.isValid() && (curr != base));
        if (!curr.isValid()) {
            curr = base.turnCcw();
            while (curr.isValid()) {
                if (fnc(curr)) curr = curr.turnCcw(); else return;
            }
        }
    }
};

struct S00d82ad0_Edge {
    S00d82ad0_Tri* m_pkTriangle;
    int m_uiEdgeIndex;
    float m_uiFilterValue;
    __forceinline S00d82ad0_Edge() {}
    __forceinline S00d82ad0_Vtx* vertex() const { int i = m_uiEdgeIndex; return m_pkTriangle->m_kVertices[i]; }
};

struct S00d82ad0_Less {
};

void __cdecl FUN_00c908c0(void* alloc, void* arr, int n, int elemSize);
void __cdecl FUN_00d7b160(S00d82ad0_Edge* data, int lo, int hi, S00d82ad0_Less cmp);

struct S00d82ad0_Alloc {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct S00d82ad0_Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00d82ad0_Alloc* m_pStreamAllocator;
    S00d82ad0_Alloc& heap() { return *m_pStreamAllocator; }
};

static __forceinline S00d82ad0_Router* S00d82ad0_router()
{
    return (S00d82ad0_Router*)FUN_00c85750();
}

struct S00d82ad0_VecArr {
    S00d82ad0_Vec* m_data;
    int m_iElementCount;
    int m_capFlags;
    S00d82ad0_VecArr() : m_data(0), m_iElementCount(0), m_capFlags((int)0x80000000) {}
    void destroy()
    {
        S00d82ad0_Alloc& a = S00d82ad0_router()->heap();
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0) a.ReturnMemory(m_data, (m_capFlags & 0x3fffffff) * sizeof(S00d82ad0_Vec));
        m_data = 0;
        m_capFlags = (int)0x80000000;
    }
    __forceinline S00d82ad0_Vec* expandBy(int n)
    {
        S00d82ad0_Alloc& a = S00d82ad0_router()->heap();
        int oldSize = m_iElementCount;
        int newSize = oldSize + n;
        int cap = m_capFlags & 0x3fffffff;
        if (cap < newSize) {
            int c2 = cap + cap;
            FUN_00c908c0(&a, this, newSize < c2 ? c2 : newSize, sizeof(S00d82ad0_Vec));
        }
        m_iElementCount += n;
        return m_data + oldSize;
    }
};

struct S00d82ad0_EdgeArr {
    S00d82ad0_Edge* m_data;
    int m_iElementCount;
    int m_capFlags;
    S00d82ad0_EdgeArr() : m_data(0), m_iElementCount(0), m_capFlags((int)0x80000000) {}
    void destroy()
    {
        S00d82ad0_Alloc& a = S00d82ad0_router()->heap();
        m_iElementCount = 0;
        if ((m_capFlags & 0x80000000) == 0) a.ReturnMemory(m_data, (m_capFlags & 0x3fffffff) * sizeof(S00d82ad0_Edge));
        m_data = 0;
        m_capFlags = (int)0x80000000;
    }
    void reserve(int n)
    {
        S00d82ad0_Router* r = S00d82ad0_router();
        if ((m_capFlags & 0x3fffffff) < n) FUN_00c908c0(r->m_pStreamAllocator, this, n, sizeof(S00d82ad0_Edge));
    }
    S00d82ad0_Edge& AllocatePair()
    {
        S00d82ad0_Router* r = S00d82ad0_router();
        if (m_iElementCount == (m_capFlags & 0x3fffffff)) ResizeAudioStream(r->m_pStreamAllocator, this, sizeof(S00d82ad0_Edge));
        S00d82ad0_Edge* t = m_data + m_iElementCount;
        for (int i = 0; i < 1; ++i) {
            ::new ((void*)(t + i)) S00d82ad0_Edge;
        }
        return m_data[m_iElementCount++];
    }
};

struct S00d82ad0_Stream {
    int unk00;
    int unk04;
    int unk08;
    void FUN_00cb1600(char* buf, int size);
    S00d82ad0_Stream& FUN_00cc01c0(const char* s);
    S00d82ad0_Stream& WriteInt(int v);
    void FUN_00cc00e0();
};

struct S00d82ad0_Err {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int type, int id, const char* text, const char* file, int line);
};

extern S00d82ad0_Err* g_01268360;
extern const float g_01011d78;

struct S00d82ad0_Tri3 {
    S00d82ad0_Vec a;
    S00d82ad0_Vec b;
    S00d82ad0_Vec c;
    S00d82ad0_Vec& FUN_00cd51c0(S00d82ad0_Vec& out);
};

struct S00d82ad0_VtxList {
    int unk00;
    int unk04;
    int unk08;
    S00d82ad0_Vtx* m_pHeadNode;
    int m_iElementCount;
    void FUN_00d7adb0(S00d82ad0_Vtx* v);
    void remove(S00d82ad0_Vtx* v)
    {
        S00d82ad0_Vtx* n = v->next;
        S00d82ad0_Vtx* p = v->prev;
        if (n) n->prev = p;
        if (p) p->next = n;
        else m_pHeadNode = n;
        --m_iElementCount;
        FUN_00d7adb0(v);
    }
};



struct S00d82ad0_Hull {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    S00d82ad0_VtxList m_kVertices;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    S00d82ad0_Tri* m_firstTriangle;
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
    S00d82ad0_Vec m_offset;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    S00d82ad0_Vec m_vScale;
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
    int m_eVertexFloatDimensions;
    int unk1ac;
    int unk1b0;
    char m_hasPlanes;
    char m_bSecondImplementationFlag;

    static __forceinline __m128 position(const S00d82ad0_Vtx* v, const __m128& scale, const __m128& offset, const float& w)
    {
        __m128 p = _mm_setr_ps((float)v->m_uiX, (float)v->m_uiY, (float)v->m_uiZ, 1.0f);
        return _mm_add_ps(_mm_mul_ps(p, scale), offset);
    }
    __forceinline S00d82ad0_Vec transform(const S00d82ad0_Vtx& v) const
    {
        S00d82ad0_Vec r;
        r.q = _mm_setr_ps((float)v.m_uiX, (float)v.m_uiY, (float)v.m_uiZ, 0.0f);
        r.q = _mm_mul_ps(r.q, m_vScale.q);
        r.q = _mm_add_ps(r.q, m_offset.q);
        return r;
    }

    bool FUN_00d82ad0(int numVerticesToKeep, bool abOptionalVertexReduction);
    void FUN_00d827b0(S00d82ad0_VecArr& v);
    void FUN_00d7d2a0();
    void FUN_00d7b600();
    int FUN_00d81510(S00d82ad0_Vec* p, int n, int a, int b);
};

template <class F>
static __forceinline void S00d82ad0_fan(const S00d82ad0_E& start, F& f)
{
    S00d82ad0_E e = start;
    do {
        f(e);
        e = e.prev().link();
    } while (e.isValid() && e != start);
    if (!e.isValid()) {
        e = start.link().next();
        while (e.isValid()) {
            f(e);
            e = e.link().next();
        }
    }
}

static __forceinline float S00d82ad0_tetrahedronVolume6(const S00d82ad0_Vec& a, const S00d82ad0_Vec& b, const S00d82ad0_Vec& c, const S00d82ad0_Vec& d)
{
    S00d82ad0_Tri3 m;
    m.a.q = _mm_sub_ps(b.q, a.q);
    m.b.q = _mm_sub_ps(c.q, a.q);
    m.c.q = _mm_sub_ps(d.q, a.q);
    S00d82ad0_Vec out;
    float f;
    _mm_store_ss(&f, m.FUN_00cd51c0(out).q);
    return f;
}

struct S00d82ad0_AreaFn {
    const S00d82ad0_Hull* m_pHull;
    float m_area;
    __forceinline S00d82ad0_AreaFn(const S00d82ad0_Hull* h) : m_pHull(h), m_area(0.0f) {}
    __forceinline bool operator()(S00d82ad0_E e)
    {
        const S00d82ad0_Vec a = m_pHull->transform(*e.end());
        const S00d82ad0_Vec b = m_pHull->transform(*e.start());
        const S00d82ad0_Vec c = m_pHull->transform(*e.apex());
        const S00d82ad0_Vec d = m_pHull->transform(*e.link().apex());
        m_area += S00d82ad0_tetrahedronVolume6(a, b, c, d);
        return true;
    }
};

struct S00d82ad0_CountFn {
    bool m_changed;
    __forceinline S00d82ad0_CountFn() : m_changed(false) {}
    __forceinline bool operator()(S00d82ad0_E e)
    {
        float& c = e.end()->m_data;
        float d = c + 1.0f;
        c = d;
        if (d > 1.0f) m_changed = true;
        return true;
    }
};

#include <math.h>
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_load_ps1(const float*);
extern "C" __m128 _mm_load_ss(const float*);
static __forceinline __m128 HullBroadcast(float f) { __m128 v=_mm_load_ss(&f); return _mm_shuffle_ps(v,v,0); }
extern "C" void _mm_store_ss(float*, __m128);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" double __cdecl fabs(double);
struct HullAllocator {
    virtual void v00();
    __declspec(nothrow) virtual void* BlockAlloc(int iSize) throw();
    virtual void v08();
    virtual void v0c();
    __declspec(nothrow) virtual void BufFree(void* p, int iSize) throw();
};
struct HullMemory {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    HullAllocator* m_pAllocator;
};
void __cdecl FUN_00c908c0(HullAllocator* pAlloc, void* pArray, int iNewCap, int iElemSize) throw();
void __cdecl ResizeAudioStream(HullAllocator* pAlloc, void* pArray, int iElemSize) throw();
struct ErrReporter {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    __declspec(nothrow) virtual int Message(int iType, int aiSoundId, const char* pDesc, const char* pFile, int iLine) throw();
};
struct ErrStream {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    __declspec(nothrow) ErrStream(void* pBuf, int iSize) throw();
    __declspec(nothrow) ~ErrStream() throw();
    __declspec(nothrow) ErrStream& operator<<(const char* s) throw();
};
extern const double DAT_01012060;
extern const double DAT_01011588;
extern const __m128 DAT_010ec7f0;
class HullVec {
    __m128 q;
public:
    __forceinline operator __m128() const { return q; }
    __forceinline void operator=(const HullVec& v) { q=v.q; }
    __forceinline void setInterpolate4(const HullVec& first,const HullVec& second,float fraction) {
        __m128 t=HullBroadcast(fraction);
        __m128 s=_mm_sub_ps(DAT_010ec7f0,t);
        q=_mm_add_ps(_mm_mul_ps(s,first.q),_mm_mul_ps(t,second.q));
    }
    __forceinline float dot4xyz1(const HullVec& v) const {
        __m128 product=_mm_mul_ps(q,v.q);
        __m128 xy=_mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
        __m128 zw=_mm_add_ss(_mm_shuffle_ps(product,product,0xaa),_mm_shuffle_ps(q,q,0xff));
        float value; _mm_store_ss(&value,_mm_add_ps(xy,zw)); return value;
    }
};
struct SplitVertex {
    SplitVertex* m_pNext;
    int unk04;
    int unk08;
    int unk0c;
    HullVec m_pos;
    int unk20;
    int unk24;
    int unk28;
    float m_fDist;
};
struct SplitTriangle {
    SplitTriangle* m_pNext;
    int unk04;
    SplitVertex* m_pVerts[3];
};
struct HullConfig {
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;
};
struct HullVector4 {
    __m128 m_vComponents;
    void Set(const __m128& v) throw() { m_vComponents = v; }
};
struct VecArrayBase {
    HullVec* m_pData;
    int m_uiLogicalSize;
    int m_iCapAndFlags;
    __forceinline HullVec& operator[](int i) { return m_pData[i]; }
    __forceinline int GetSize() const { return m_uiLogicalSize; }
    __forceinline void Clear() throw()
    {
        HullMemory* pMem = ((HullMemory*)&fnvc_adapt::FUN_00c85750());
        HullAllocator* pAlloc = pMem->m_pAllocator;
        int iCap = m_iCapAndFlags;
        m_uiLogicalSize = 0;
        if ((iCap & 0x80000000) == 0) {
            pAlloc->BufFree(m_pData, (iCap & 0x3fffffff) * 16);
        }
        m_pData = 0;
        m_iCapAndFlags = 0x80000000;
    }
    __forceinline void Reserve(int n) throw()
    {
        HullMemory* pMem = ((HullMemory*)&fnvc_adapt::FUN_00c85750());
        HullAllocator* pAlloc = pMem->m_pAllocator;
        int iCap = m_iCapAndFlags & 0x3fffffff;
        if (iCap < n) {
            int iCap2 = iCap * 2;
            FUN_00c908c0((D76250Allocator*)pAlloc, this, n < iCap2 ? iCap2 : n, 16);
        }
    }
    __forceinline void PushBack(const HullVec& v) throw()
    {
        HullMemory* pMem = ((HullMemory*)&fnvc_adapt::FUN_00c85750());
        if (m_uiLogicalSize == (m_iCapAndFlags & 0x3fffffff)) {
            ResizeAudioStream((D76250Allocator*)pMem->m_pAllocator, this, 16);
        }
        HullVec* dst=m_pData+m_uiLogicalSize; for(int i=0;i<1;++i) dst[i]=v;
        m_uiLogicalSize++;
    }
};
struct VecArray : VecArrayBase {
    __forceinline VecArray() throw()
    {
        m_pData = 0;
        m_uiLogicalSize = 0;
        m_iCapAndFlags = 0x80000000;
    }
    __forceinline ~VecArray() throw()
    {
        Clear();
    }
};
struct ErrorWork {
    int unk00, unk04, unk08;
    void FUN_00cb1600(void* buf, int size) throw();
    ErrorWork& FUN_00cc01c0(const char* text) throw();
    void FUN_00cc00e0() throw();
};
struct __declspec(align(16)) SplitRawVec { unsigned int x,y,z,w; };
struct SplitWork {
    VecArrayBase back;
    union { float rounded; SplitVertex** edge; } scratch;
    union { VecArrayBase front; SplitRawVec position; ErrorWork stream; } current;
};
inline void* operator new(unsigned int, HullVec* place) { return place; }
struct HullImpl;
struct FUN_00d76ca0 {
    __declspec(nothrow) virtual ~FUN_00d76ca0() throw();
    unsigned short m_uMemSize;
    unsigned short m_uRefCount;
    HullImpl* m_pImpl;
    int unk0c;
    int unk10;
    __declspec(nothrow) FUN_00d76ca0() throw();
    __declspec(nothrow) static void* operator new(unsigned int n)
    {
        HullMemory* mem = (HullMemory*)&fnvc_adapt::FUN_00c85750();
        FUN_00d76ca0* p = (FUN_00d76ca0*)mem->m_pAllocator->BlockAlloc(n);
        p->m_uMemSize = (unsigned short)n;
        return p;
    }
    static void operator delete(void* p) throw();
};
struct HullImpl {
    HullConfig m_pConfiguration;
    int unk010; int unk014; int unk018; int unk01c; int unk020;
    SplitVertex* m_pVertexData;
    int m_iNumVertices;
    int unk02c; int unk030; int unk034; int unk038;
    SplitTriangle* m_pTriangles;
    int unk040; int unk044; int unk048; int unk04c; int unk050; int unk054; int unk058; int unk05c; int unk060; int unk064; int unk068; int unk06c; int unk070; int unk074; int unk078; int unk07c; int unk080; int unk084; int unk088; int unk08c; int unk090; int unk094; int unk098; int unk09c; int unk0a0; int unk0a4; int unk0a8; int unk0ac; int unk0b0; int unk0b4; int unk0b8; int unk0bc; int unk0c0; int unk0c4; int unk0c8; int unk0cc; int unk0d0; int unk0d4; int unk0d8; int unk0dc;
    HullVec m_vE0;
    int unk0f0; int unk0f4; int unk0f8; int unk0fc; int unk100; int unk104; int unk108; int unk10c; int unk110; int unk114; int unk118; int unk11c; int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c; int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c; int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c; int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c; int unk1a0; int unk1a4;
    int m_iDimension;
    __declspec(noinline) int FUN_00d7a200(const HullVec&,float,int*,float*) const;
    int FUN_00d81510(const HullVec*,int,bool,const HullImpl*);
    int FUN_00d83430(const HullVec& plane,FUN_00d76ca0** ppFront,FUN_00d76ca0** ppBack,float fEps) const;
};
inline float HullCrtAbs(float f) { return (float)fabs((double)f); }
extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();

extern "C" void _ReadWriteBarrier();
extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_set_ps1(float);
extern "C" __m128 _mm_load_ss(const float*);

extern "C" __m128 _mm_setr_ps(float, float, float, float);
extern double DAT_0104e138;

struct VecNode {
    VecNode* m_next;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int m_20;
    int m_24;
    int m_28;
};

struct CentroidHull {
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20;
    VecNode* m_24;
    int m_28;
    int unk2C, unk30, unk34, unk38, unk3C, unk40, unk44, unk48, unk4C;
    int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74, unk78, unk7C;
    union {
        __m128 m_80;
        struct {
            float unk80;
            float unk84;
            float unk88;
            float m_8c;
        };
    };
    int unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC;
    int unkB0, unkB4, unkB8, unkBC, unkC0, unkC4, unkC8, unkCC;
    int unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC;
    __m128 m_f0;
    int unk100, unk104, unk108, unk10C;
    __m128 m_110;

    void* FUN_00d7aa30();
};

// Cached centroid of the transformed hull vertices.

extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sub_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_set_ss(float);
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_load_ps1(const float*);
extern "C" void _mm_store_ss(float*,__m128);
extern "C" float _mm_cvtss_f32(__m128);
extern "C" double __cdecl sqrt(double);
extern const char str_010d358c[];
extern const char str_010d3540[];
extern const __m128 DAT_010c7160;
struct MessageStream {
    int unk00, unk04, unk08;
    void FUN_00cb1600(void*, int);
    MessageStream* FUN_00cc01c0(const char*, int, const char*);
    MessageStream* FUN_00cc02d0();
    void FUN_00cc01c0();
    void FUN_00cc00e0();
};
struct BasisTransform {
    PlaneVector axes[3];
    PlaneVector origin;
};
struct PlaneShape {
    int unk00, unk04;
    ChildData* state;
    void GetMassProperties(BasisTransform*, void*);
    float FUN_00d769c0(const PlaneVector&);
    void FUN_00d76a20(PlaneVector* planes);
};
static __forceinline __m128 dot3(const __m128& a, const __m128& b) {
    __m128 p = _mm_mul_ps(a,b);
    __m128 y = _mm_shuffle_ps(p,p,0x55);
    __m128 z = _mm_shuffle_ps(p,p,0xaa);
    y = _mm_add_ss(y,p);
    return _mm_add_ss(z,y);
}

extern __m128 DAT_01268370;
extern __m128 DAT_01268380;
extern __m128 DAT_01268390;
extern __m128 DAT_012683a0;
struct SampleTransform {
    D76250Vector4 x,y,z,w;
    __forceinline SampleTransform(const D76250Vector4& a,const D76250Vector4& b,const D76250Vector4& c,const D76250Vector4& d) {
        x=a; y=b; z=c; w=d;
    }
};
extern const char str_010d36fc[];
struct SamplePoint: D76250Vector4 {
    void FUN_00c7f640(const SampleTransform&,const D76250Vector4&);
};
struct SampleBuilder {
    int unk00,unk04;
    ChildData* hull;
    void FUN_00d76d80(D76250Vector4&,SampleTransform&);
    bool FUN_00d76100(const D76250Vector4&,unsigned char,float);
};
struct SampleStream {
    int unk00,unk04,unk08;
    void FUN_00cb1600(char*,int);
    void FUN_00cc01c0(const char*);
    void FUN_00cc00e0();
};
struct SampleTrivialVector { __m128 m_vComponents; };
union SampleWorkspace { SampleTrivialVector extents; SampleStream stream; __forceinline SampleWorkspace(const D76250Vector4& v):extents((const SampleTrivialVector&)v) {} };
struct SampleBuilderRef { SampleBuilder* value; };
struct SampleRandomRef { RandomGenerator* value; };

namespace tolerance { extern const float DAT_0104da4c=1.1920928955078125e-7f; }
extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_shuffle_ps(__m128,__m128,unsigned int);
extern "C" __m128 _mm_sub_ss(__m128,__m128);
extern "C" __m128 _mm_mul_ps(__m128,__m128);
extern "C" __m128 _mm_add_ps(__m128,__m128);
extern "C" __m128 _mm_add_ss(__m128,__m128);
extern "C" void _mm_store_ss(float*,__m128);
extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);



void __cdecl ResizeAudioStream(void*,void*,int);
namespace enumeration_rework {
typedef ::PlaneScalar PlaneScalar;
static __forceinline PlaneScalar operator-(const PlaneScalar& s) {
    return _mm_sub_ss(DAT_010c7160,s.quad());
}
class PlaneVector: public ::PlaneVector {
public:
    operator __m128() const {return value;}
    __forceinline void operator=(const PlaneVector& v) {value=v.value;}
    __forceinline void operator=(const __m128& v) {value=v;}
    __forceinline float& lane(int i) {return value.m128_f32[i];}
    __forceinline const float& lane(int i) const {return value.m128_f32[i];}
    __forceinline void set(float x,float y,float z,float w=0) {value=_mm_setr_ps(x,y,z,w);}
    __forceinline PlaneScalar scalar(int i) const {
        switch(i) {
        case 0:return value;
        case 1:return _mm_shuffle_ps(value,value,85);
        case 2:return _mm_shuffle_ps(value,value,170);
        default:return _mm_shuffle_ps(value,value,255);
        }
    }
    __forceinline void broadcast(const PlaneVector& v,int i) {
        if(i==0) value=_mm_shuffle_ps(v.value,v.value,0);
        else if(i==1) value=_mm_shuffle_ps(v.value,v.value,85);
        else if(i==2) value=_mm_shuffle_ps(v.value,v.value,170);
        else if(i==3) value=_mm_shuffle_ps(v.value,v.value,255);
    }
    __forceinline void mul(const PlaneVector& a,const PlaneVector& b) {value=_mm_mul_ps(a.value,b.value);}
    __forceinline void addMul(const PlaneVector& a,const PlaneVector& b) {
        __m128 product=_mm_mul_ps(a.value,b.value);value=_mm_add_ps(value,product);
    }
    __forceinline PlaneScalar distance(const PlaneVector& v) const {
        __m128 planeq=value; _ReadWriteBarrier();
        __m128 product=_mm_mul_ps(v,planeq);
        __m128 xy=_mm_add_ss(_mm_shuffle_ps(product,product,85),product);
        __m128 zw=_mm_add_ss(_mm_shuffle_ps(product,product,170),_mm_shuffle_ps(planeq,planeq,255));
        return _mm_add_ps(xy,zw);
    }
};
struct PlaneMatrix {
    PlaneVector c0,c1,c2;
    __forceinline PlaneMatrix() {}
    __forceinline void rows(const PlaneVector& a,const PlaneVector& b,const PlaneVector& c) {
        c0.set(a.lane(0),b.lane(0),c.lane(0));
        c1.set(a.lane(1),b.lane(1),c.lane(1));
        c2.set(a.lane(2),b.lane(2),c.lane(2));
    }
    int FUN_00cd4f10(float);
    __forceinline void transform(const PlaneVector& v,PlaneVector& out) const {
        PlaneVector x,y,z;
        x.broadcast(v,0);y.broadcast(v,1);z.broadcast(v,2);
        PlaneVector sum;
        sum.mul(x,c0);sum.addMul(y,c1);sum.addMul(z,c2);
        out=sum;
    }
};
struct EnumerationTimer {
    const char* tag;
    unsigned int clock0,clock1;
    __forceinline void sample() {
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        clock0=ticks;
    }
};
struct EnumerationStream {
    char *start,*end,*capacity,*limit;
};
struct PlanePointArray: D76250VectorArray {
    __forceinline PlanePointArray() {m_data=0;m_iElementCount=0;m_iCapacityState=0x80000000;}
    __forceinline ~PlanePointArray() {
        S_00d7a010_Alloc& heap=S_00d7a010_Router::FUN_00c85750().heap();
        m_iElementCount=0;
        if((m_iCapacityState&0x80000000)==0) heap.ReturnMemory(m_data,getCapacity()*sizeof(PlaneVector));
    }
    __forceinline void reserve(int n) {
        D76250Allocator& heap=fnvc_adapt::FUN_00c85750().heap();
        D76250VectorArray::reserve(heap,n);
    }
    __forceinline void append(const PlaneVector& v) {
        D76250Allocator& heap=fnvc_adapt::FUN_00c85750().heap();
        if(m_iElementCount==getCapacity()) ResizeAudioStream((void*)&heap,this,sizeof(PlaneVector));
        PlaneVector* dst=(PlaneVector*)m_data+m_iElementCount;
        for(int n=0;n<1;++n) dst[n]=v;
        ++m_iElementCount;
    }
};
struct PlaneHull: ::PlaneHull {
    int FUN_00d771c0(const PlaneVector*,int,int);
    int FUN_00d774a0(const PlaneVector*,int,int);
};

}

extern "C" {
__m128 _mm_load_ps(const float* a);
void _ReadWriteBarrier();
__m128 _mm_add_ss(__m128 a, __m128 b);
__m128 _mm_add_ps(__m128 a, __m128 b);
__m128 _mm_sub_ss(__m128 a, __m128 b);
__m128 _mm_sub_ps(__m128 a, __m128 b);
__m128 _mm_mul_ss(__m128 a, __m128 b);
__m128 _mm_mul_ps(__m128 a, __m128 b);
__m128 _mm_sqrt_ss(__m128 a);
__m128 _mm_rsqrt_ss(__m128 a);
__m128 _mm_cmpeq_ss(__m128 a, __m128 b);
__m128 _mm_andnot_ps(__m128 a, __m128 b);
__m128 _mm_xor_ps(__m128 a, __m128 b);
__m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm8);
__m128 _mm_set_ss(float a);
__m128 _mm_load_ss(const float* a);

void _mm_store_ss(float* p, __m128 a);

double sqrt(double);
}



extern float DAT_01012054;

struct AllocHolder {
    int unk00;
    int unk04;
    int unk08;
    HullAllocator* m_pHeap;
    HullAllocator* m_pTemp;
};
inline AllocHolder* Holder() { return (AllocHolder*)FUN_00c85750(); }

void __cdecl FUN_00c909d0(HullAllocator* alloc, void* arr, int elemSize, int unused, int n);
struct IndexVertex {
    IndexVertex* m_pNext;
    int unk04;
    int unk08;
    int unk0c;
    __m128 m_pos;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    int unk2c;
    int unk30;
    int m_uiEdgeIndex;
};
struct HullFace {
    HullFace* m_pNext;
    int unk04;
    IndexVertex* m_vert[3];
    unsigned int m_kEdge[3];
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int m_planeIndex;
    int unk3c;
    int unk40;
    int m_uiEdgeIndex;
};
struct IndexEdge;
template<class E> struct IndexEdgeBase {
    HullFace* m_face;
    unsigned int m_ucOperationType;
    IndexEdgeBase() {}
    IndexEdgeBase(HullFace* f,int t):m_face(f),m_ucOperationType(t) {}
    IndexEdgeBase(unsigned int packed) { m_ucOperationType=packed&3; m_face=(HullFace*)(packed&~3u); }
    HullFace* triangle() const { return m_face; }
    E next() const { return E(m_face,(9>>(m_ucOperationType*2))&3); }
    E prev() const { return E(m_face,(18>>(m_ucOperationType*2))&3); }
    E link() const { return E(m_face->m_kEdge[m_ucOperationType]); }
};
struct IndexEdge:IndexEdgeBase<IndexEdge> {
    IndexEdge() {}
    IndexEdge(HullFace*f,int i):IndexEdgeBase<IndexEdge>(f,i) {}
    IndexEdge(unsigned int packed):IndexEdgeBase<IndexEdge>(packed) {}
    IndexEdge(const IndexEdge& e) { m_face=e.m_face; m_ucOperationType=e.m_ucOperationType; }
};
struct FaceArea {
    HullFace* m_face;
    float m_area;
};
struct FaceLess { unsigned char context; FaceLess() : context(0) {} };
void __cdecl FUN_00d7b270(FaceArea* arr, int lo, int hi, FaceLess cmp);
struct HullBool {
    unsigned char m_cBooleanValue;
};
struct HullVec4 {
    __m128 m_vComponents;
    HullBool* FUN_00c7f520(HullBool* out, float eps);
};
struct __declspec(align(16)) HullFloat4 {
    float x;
    float y;
    float z;
    float w;
};
union HullPlane {
    __m128 m_vComponents;
    HullFloat4 m_fields;
};
template <class T> struct HullArrayBase {
    T* m_data;
    int m_iElementCount;
    int m_capAndFlags;
    T& operator[](int i) { return m_data[i]; }
};
template<class T>struct HullArray:HullArrayBase<T> {
    HullArray() {m_data=0;m_iElementCount=0;m_capAndFlags=0x80000000;}
};
struct FacePtrMap {
    void* m_kPrimitiveElement;
    int m_num;
    int m_iPairCount;
    FacePtrMap() : m_kPrimitiveElement(0), m_num(0), m_iPairCount(-1) { Reserve(0); }
    void EnsureCapacity(HullAllocator* alloc, int n);
    void Reserve(int n)
    {
        AllocHolder* h = Holder();
        HullAllocator* a = h->m_pTemp;
        EnsureCapacity(a, n);
    }
    void FUN_00cb1870(HullAllocator* alloc, HullFace* key, int val);
    void Insert(HullFace* key, int val)
    {
        AllocHolder* h = Holder();
        HullAllocator* a = h->m_pTemp;
        FUN_00cb1870(a, key, val);
    }
    int LookupHashEntry(HullFace* key, int def);
    void ProcessArgument(HullAllocator* alloc);
    void FUN_00a29680();
};

class GeoScalar {
    __m128 value;
public:
    GeoScalar() {}
    GeoScalar(const __m128& x):value(x) {}
    GeoScalar(float x) { value=_mm_load_ss(&x); }
    operator float() const { float f; _mm_store_ss(&f,value); return f; }
    const __m128& quad() const { return value; }
};
inline GeoScalar operator+(const GeoScalar& a,const GeoScalar& b) { return _mm_add_ss(a.quad(),b.quad()); }
class GeoVector {
    __m128 value;
public:
    GeoScalar dot(const GeoVector& b) const {
        __m128 prod=_mm_mul_ps(_mm_load_ps((const float*)&value),b.value);
        __m128 sum=_mm_add_ss(_mm_shuffle_ps(prod,prod,85),prod);
        return _mm_add_ss(_mm_shuffle_ps(prod,prod,170),sum);
    }
    GeoScalar at(int i) const {
        switch(i) {
        case 0:return value;
        case 1:return _mm_shuffle_ps(value,value,85);
        case 2:return _mm_shuffle_ps(value,value,170);
        default:return _mm_shuffle_ps(value,value,255);
        }
    }
};
struct HullBuilder {
    int unk00;
    float m_fScalar;
    int unk08;
    unsigned char unk0c;
    unsigned char m_bFixup;
    unsigned char unk0e;
    unsigned char unk0f;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    IndexVertex* m_kVertices;
    int m_iStridedVertexCount;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    HullFace* m_faces;
    int m_numFaces;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    HullArray<__m128> m_kPlaneArray;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
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
    int fieldb4;
    int fieldb8;
    int fieldbc;
    int fieldc0;
    int fieldc4;
    int fieldc8;
    int fieldcc;
    int fieldd0;
    int fieldd4;
    int fieldd8;
    int fielddc;
    __m128 m_e0;
    __m128 m_f0;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    __m128 m_110;
    int field120;
    int field124;
    int field128;
    int field12c;
    int field130;
    int field134;
    int field138;
    int field13c;
    int field140;
    int field144;
    int field148;
    int field14c;
    int field150;
    int field154;
    int field158;
    int field15c;
    int field160;
    int field164;
    int field168;
    int field16c;
    int field170;
    int field174;
    int field178;
    int field17c;
    int field180;
    int field184;
    int field188;
    int field18c;
    int field190;
    int field194;
    int field198;
    int field19c;
    int field1a0;
    int field1a4;
    int m_dimension;
    int unk1ac;
    int unk1b0;
    unsigned char unk1b4;
    unsigned char m_bPlanesBuilt;
    HullFloat4* FUN_00d7aa30();
    void FUN_00d7d2a0();
};

extern "C" __m128 _mm_load_ss(const float*);
extern "C" __m128 _mm_set_ss(float);
extern "C" void _mm_store_ss(float*, __m128);
extern "C" void _mm_store_ps(float*, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_sub_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" __m128 _mm_unpacklo_ps(__m128, __m128);
extern "C" __m128 _mm_move_ss(__m128, __m128);

extern float DAT_01011d78;


class MatchScalar {
    hkVec4 data;
public:
    MatchScalar(float x) { _mm_store_ps(&data.x,_mm_load_ss(&x)); }
    MatchScalar(const __m128& v) { _mm_store_ps(&data.x,v); }
    operator float() const { float x; _mm_store_ss(&x,*(const __m128*)&data); return x; }
};
class MatchVector {
public:
    __m128 data;
    void operator=(const MatchVector& v) { data=v.data; }
    void set(float x,float y,float z,float w) { data=_mm_setr_ps(x,y,z,w); }
    void mul4(const MatchVector& v) { data=_mm_mul_ps(data,v.data); }
    void add4(const MatchVector& v) { data=_mm_add_ps(data,v.data); }
    MatchScalar distanceToSquared3(const MatchVector& v) const {
        __m128 delta=_mm_sub_ps(data,v.data);
        __m128 square=_mm_mul_ps(delta,delta);
        return _mm_add_ss(_mm_shuffle_ps(square,square,0xaa),_mm_add_ss(_mm_shuffle_ps(square,square,0x55),square));
    }
};


struct ProbeNode {
    ProbeNode* next;
    int unk04, unk08, unk0c;
    MatchVector source;
    int x,y,z;
};
struct ProbeHull {
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    ProbeNode* vertices;
    int unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec;
    MatchVector offset,unk100,scale;
};
struct ProbeSource {
    static const MatchVector& position(ProbeHull*, ProbeNode* n) { return n->source; }
};
struct ProbeTransform {
    static MatchVector position(ProbeHull* h, ProbeNode* n) {
        MatchVector v;
        v.set((float)n->x,(float)n->y,(float)n->z,0.0f);
        v.mul4(h->scale);
        v.add4(h->offset);
        return v;
    }
};
struct ProbeObj {
    int unk00,unk04;
    ProbeHull* hull;
    void FUN_00d75e30(int mode,const MatchVector& input,MatchVector& output);
};

extern const char str_010d3574[];
extern float DAT_0104da4c;
extern const __m128 DAT_010ec7f0;
extern "C" {
__m128 _mm_mul_ps(__m128,__m128);
__m128 _mm_add_ps(__m128,__m128);
__m128 _mm_sub_ps(__m128,__m128);
__m128 _mm_add_ss(__m128,__m128);
__m128 _mm_shuffle_ps(__m128,__m128,unsigned int);
__m128 _mm_load_ss(const float*);
void _mm_store_ss(float*,__m128);
double fabs(double);
}
struct ClipStream {
    int unk00,unk04,unk08;
    void FUN_00cb1600(char*,int);
    ClipStream* FUN_00cc01c0(const char*,int,char*);
    ClipStream* FUN_00cc02d0();
    void FUN_00cc01c0();
    void FUN_00cc00e0();
};
class ClipSimdReal {
public:
    ClipSimdReal(const __m128& x):m_vValue(x) {}
    ClipSimdReal(float x) { m_vValue=_mm_load_ss(&x); }
    operator float() const { float s; _mm_store_ss(&s,m_vValue); return s; }
    __forceinline float get(float& s) const { _mm_store_ss(&s,m_vValue); return s; }
    __forceinline void store(float& s) const { _mm_store_ss(&s,m_vValue); }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(m_vValue,m_vValue,0); }
private:
    __m128 m_vValue;
};
class __declspec(align(16)) ClipVector {
public:
    __forceinline ClipSimdReal dot4xyz1(const ClipVector& a) const {
        __m128 x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
        __m128 xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,0x55),x2);
        __m128 zwSum=_mm_add_ss(_mm_shuffle_ps(x2,x2,0xaa),_mm_shuffle_ps(m_vComponents,m_vComponents,0xff));
        return _mm_add_ps(xySum,zwSum);
    }
    __forceinline void setInterpolate4(const ClipVector& v0,const ClipVector& v1,const ClipSimdReal& _t) {
        __m128 t=_t.broadcast();
        __m128 s=_mm_sub_ps(DAT_010ec7f0,t);
        m_vComponents=_mm_add_ps(_mm_mul_ps(s,v0.m_vComponents),_mm_mul_ps(t,v1.m_vComponents));
    }
    __forceinline void operator=(const ClipVector& v) { m_vComponents=v.m_vComponents; }
    __m128 m_vComponents;
};
struct ClipHull {
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
    ClipVector* planes;
    int numPlanes;
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
    int index;
    unsigned char unk1b4;
    bool indexed;
    __forceinline void mustHaveIndex() const;
    bool FUN_00d7a5a0(const ClipVector& a,const ClipVector& b,float& t0,float& t1,float planeThickness) const;
};

extern "C" __m128 _mm_mul_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ps(__m128 a, __m128 b);
extern "C" __m128 _mm_add_ss(__m128 a, __m128 b);
extern "C" __m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
extern "C" void _mm_store_ss(float* p, __m128 a);
extern "C" void _mm_store_ps(float* p, __m128 a);
extern "C" __m128 _mm_load_ps(const float* p);
extern "C" __m128 _mm_load_ps1(const float* p);
extern "C" __m128 _mm_load_ss(const float*);

extern const char str_010d3574[];
extern float DAT_01011d78;


class BevelScalar {
    __m128 q;
public:
    BevelScalar() {}
    BevelScalar(const __m128& v): q(v) {}
    BevelScalar(float v) { q=_mm_load_ss(&v); }
    operator float() const { float v; _mm_store_ss(&v,q); return v; }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(q,q,0); }
};
class BevelVector {
public:
    __m128 q;
    __forceinline void operator=(const BevelVector& v) { q=v.q; }
    __forceinline void operator=(const __m128& v) { q=v; }
    __forceinline void set(float x,float y,float z,float w=0) { q=_mm_setr_ps(x,y,z,w); }
    __forceinline void add(const BevelVector& v) { q=_mm_add_ps(q,v.q); }
    __forceinline void sum(const BevelVector& a,const BevelVector& b) { q=_mm_add_ps(a.q,b.q); }
    __forceinline void mul(const BevelVector& v) { q=_mm_mul_ps(q,v.q); }
    __forceinline void mul(const BevelScalar& v) { q=_mm_mul_ps(v.broadcast(),q); }
    inline BevelScalar dot(const BevelVector& v) const {
        __m128 prod=_mm_mul_ps(q,v.q);
        __m128 xy=_mm_add_ss(_mm_shuffle_ps(prod,prod,85),prod);
        return _mm_add_ss(_mm_shuffle_ps(prod,prod,170),xy);
    }
    inline BevelScalar squared() const { return dot(*this); }
    __forceinline int normalize() {
        const float sq=squared();
        if(sq!=0.0f) { mul(1.0f/sqrtf(sq)); return 0; }
        return 1;
    }
    inline float& operator()(int i) { return reinterpret_cast<float*>(&q)[i]; }
    inline const float& operator()(int i) const { return reinterpret_cast<const float*>(&q)[i]; }
    inline BevelScalar at(int i) const {
        switch(i) { case 0:return q; case 1:return _mm_shuffle_ps(q,q,85); case 2:return _mm_shuffle_ps(q,q,170); default:return _mm_shuffle_ps(q,q,255); }
    }
};
struct BevelVertex {
    BevelVertex* m_next;
    BevelVertex* m_pSecondNode;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int m_pos[3];
    static __forceinline bool ordered(const BevelVertex* a,const BevelVertex* b) {
        for(int k=0;k<3;k++) {
            if(a->m_pos[k]<b->m_pos[k]) return true;
            if(a->m_pos[k]>b->m_pos[k]) return false;
        }
        return true;
    }
};

struct BevelTri {
    BevelTri* m_next;
    BevelTri* m_pSecondNode;
    BevelVertex* m_kVertices[3];
    unsigned int m_ppLinks[3];
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int m_kTriangleNormal;
    __forceinline BevelVertex*& vertex(int i) { return m_kVertices[i]; }
    __forceinline unsigned int& link(int i) { return m_ppLinks[i]; }
};


template<class E> struct BevelEdgeBase {
protected:
    BevelTri* face;
    unsigned int corner;
    static __forceinline unsigned advance(unsigned i) { return (9>>(i<<1))&3; }
public:
    __forceinline BevelEdgeBase() {}
    __forceinline BevelEdgeBase(BevelTri* f,unsigned i):face(f),corner(i) {}
    __forceinline BevelEdgeBase(const unsigned int& id) {
        unsigned int value=id;
        corner=value&3; value&=~3;
        face=*(BevelTri**)&value;
    }
    __forceinline E link() const { return E(face->link(corner)); }
    __forceinline BevelTri* triangle() const { return face; }
    __forceinline BevelVertex*& start() const { return face->vertex(corner); }
    __forceinline BevelVertex*& end() const { return face->vertex(advance(corner)); }
    __forceinline bool valid() const { return triangle()!=0; }
    __forceinline bool unbound() const { return !link().valid(); }
    __forceinline bool master() const { return BevelVertex::ordered(start(),end())||unbound(); }
};
struct BevelEdge: BevelEdgeBase<BevelEdge> {
    __forceinline BevelEdge(BevelTri* f,int i):BevelEdgeBase<BevelEdge>(f,i) {}
    __forceinline BevelEdge(const unsigned int& id):BevelEdgeBase<BevelEdge>(id) {}
    __forceinline BevelEdge(const BevelEdge& e) { face=e.face; corner=e.corner; }
    __forceinline bool samePlane() const { return triangle()->m_kTriangleNormal==link().triangle()->m_kTriangleNormal; }
};
struct BevelArray {
    BevelVector* m_data; int m_iElementCount,m_cap;
    __forceinline const BevelVector& operator[](int i) const { return m_data[i]; }
    __forceinline void append(const BevelVector& v) {
        S_00d7c340_Router* r=FUN_00c85750();
        if(m_iElementCount==(m_cap&0x3fffffff)) ResizeAudioStream(r->unk10,this,16);
        BevelVector* dst=m_data+m_iElementCount;
        for(int k=0;k<1;k++) dst[k]=v;
        m_iElementCount++;
    }
};
struct BevelHull {
    int m_00;
    int m_04;
    int m_08;
    char m_0c;
    char m_walk;
    char m_0e;
    char m_0f;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    BevelVertex* m_firstVertex;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    BevelTri* m_firstTri;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    BevelArray m_kPlaneArray;
    int m_60; int m_64; int m_68; int m_6c; int m_70; int m_74;
    int m_78; int m_7c; int m_80; int m_84; int m_88; int m_8c; int m_90; int m_94;
    int m_98; int m_9c; int m_a0; int m_a4; int m_a8; int m_ac; int m_b0; int m_b4;
    int m_b8; int m_bc; int m_c0; int m_c4; int m_c8; int m_cc; int m_d0; int m_d4;
    int m_d8; int m_dc; int m_e0; int m_e4; int m_e8; int m_ec;
    BevelVector m_offset;
    BevelVector m_unk100;
    BevelVector m_vScale;
    int m_120; int m_124; int m_128; int m_12c; int m_130; int m_134; int m_138; int m_13c;
    int m_140; int m_144; int m_148; int m_14c; int m_150; int m_154; int m_158; int m_15c;
    int m_160; int m_164; int m_168; int m_16c; int m_170; int m_174; int m_178; int m_17c;
    int m_180; int m_184; int m_188; int m_18c; int m_190; int m_194; int m_198; int m_19c;
    int m_1a0; int m_1a4;
    int m_eVertexFloatDimensions;
    int m_1ac;
    unsigned int m_uiUniqueId;
    char m_1b4;
    char m_hasIndices;

    void FUN_00d7caa0(float maxCos, BevelArray& out) const;
    __forceinline BevelVector position(const BevelVertex* v) const {
        BevelVector point;
        point.set((float)v->m_pos[0],(float)v->m_pos[1],(float)v->m_pos[2],DAT_01011d78);
        point.mul(m_vScale); point.add(m_offset); return point;
    }
};


struct BevelStream {
    void* vtable; int unk04,unk08;
    void FUN_00cb1600(char*,int) throw();
    BevelStream& FUN_00cc01c0(const char*) throw();
    BevelStream& FUN_00cc02d0(unsigned int) throw();
    void FUN_00cc00e0() throw();
};

extern "C" __m128 __cdecl _mm_mul_ss(__m128, __m128);
extern "C" __m128 __cdecl _mm_add_ps(__m128, __m128);


extern const char str_010d3574[];
extern const char str_010d3540[];

struct BoxStream {
    int unk00;
    int unk04;
    int unk08;
    BoxStream* FUN_00cb1600(void* buf, int size);
    BoxStream* FUN_00cc01c0(const char*,int,char*);
    BoxStream* FUN_00cc02d0();
    void FUN_00cc01c0();
    void FUN_00cc00e0();
};
struct BoxScalar;
class __declspec(align(16)) BoxVector {
    __m128 value;
public:
    __m128& q() { return value; }
    const __m128& q() const { return value; }
    BoxVector& operator=(const BoxVector& v) { value=v.value; return *this; }
    __forceinline BoxScalar dot(const BoxVector& v) const;
    __forceinline void scale(float f);
    __forceinline void cross(const BoxVector& a,const BoxVector& b);
    __forceinline int normalize();
};
extern float DAT_0104da48;

class BoxScalar {
    __m128 m_vValue;
public:
    BoxScalar() {}
    BoxScalar(float f):m_vValue(_mm_load_ss(&f)) {}
    BoxScalar(const __m128& r) : m_vValue(r) {}
    const __m128& get() const { return m_vValue; }
    __m128 broadcast() const { return _mm_shuffle_ps(m_vValue,m_vValue,0); }
    operator float() const { float f; _mm_store_ss(&f, m_vValue); return f; }
};
__forceinline BoxScalar operator*(const BoxScalar& a, const BoxScalar& b)
{
    return _mm_mul_ss(a.get(), b.get());
}

extern "C" __m128 _mm_load_ps(const float*);
struct BoxTransform {
    BoxVector m_kColumn0;
    BoxVector m_kColumn1;
    BoxVector m_kColumn2;
    BoxVector m_vTranslation;
};

template <class T> struct BoxPointer {
    T m_kStorage;
    T val() const { return m_kStorage; }
};

struct BoxFace {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned int m_ppLinks[3];
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int m_kTriangleNormal;
};

struct BoxEdge {
    BoxFace* m_tri;
    int m_uiEdgeIndex;
    BoxEdge(BoxFace* t, int i) : m_tri(t), m_uiEdgeIndex(i) {}
};

struct BoxIterator {
    BoxFace* m_tri;
    int m_uiEdgeIndex;
    void FUN_00d7d220(BoxEdge e);
    void FUN_00d7c970();
    operator const void*() const { return m_tri ? this : 0; }
};

struct BoxHull {
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
    BoxFace* m_firstTri;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    BoxVector* m_kPlaneArray;
    int m_iValue;
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
    int m_eVertexFloatDimensions;
    int unk1ac;
    int m_uiEdgeIndex;
    char unk1b4;
    char m_hasIndex;
    float FUN_00d7c610(const BoxVector& axis, float& mn, float& mx) const;
    float FUN_00d7f090(BoxPointer<const BoxVector*> plane, BoxVector& halfExtents, BoxTransform& transform) const;
};

namespace S00d81510_Intrinsics {
extern "C" {
__m128 _mm_mul_ps(__m128,__m128);
__m128 _mm_add_ps(__m128,__m128);
__m128 _mm_sub_ps(__m128,__m128);
__m128 _mm_add_ss(__m128,__m128);
__m128 _mm_sub_ss(__m128,__m128);
__m128 _mm_min_ps(__m128,__m128);
__m128 _mm_max_ps(__m128,__m128);
__m128 _mm_and_ps(__m128,__m128);
__m128 _mm_rcp_ps(__m128);
__m128 _mm_unpackhi_ps(__m128,__m128);
__m128 _mm_shuffle_ps(__m128,__m128,unsigned int);
__m128 _mm_load_ss(const float*);
__m128 _mm_setr_ps(float,float,float,float);
void _mm_store_ss(float*,__m128);
}
}
extern const char str_010d3718[];
extern const char str_010d3540[];
extern const __m128 DAT_010c7160;
extern const __m128 DAT_010c7170;
extern const __m128 DAT_01017d10;

namespace S00d81510_Constants {
static const double DAT_01032980 = double(1e-4f);
}
struct S00d81510_Stream {
    int unk00;
    int unk04;
    int unk08;
    S00d81510_Stream* FUN_00cb1600(void* buf, int size);
    S00d81510_Stream& FUN_00cc01c0(const char* s);
    void FUN_00cc00e0();
};
class S00d81510_SimdReal {
public:
    __forceinline S00d81510_SimdReal(const __m128& x) : m_vValue(x) {}
    __forceinline S00d81510_SimdReal(float x) { m_vValue = S00d81510_Intrinsics::_mm_load_ss(&x); }
    __forceinline operator float() const { float s; S00d81510_Intrinsics::_mm_store_ss(&s, m_vValue); return s; }
    __forceinline __m128 broadcast() const { return S00d81510_Intrinsics::_mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const __m128& getQuad() const { return m_vValue; }
    __m128 m_vValue;
};
typedef const S00d81510_SimdReal& S00d81510_SimdParam;
__forceinline S00d81510_SimdReal operator-(S00d81510_SimdParam r)
{
    return S00d81510_Intrinsics::_mm_sub_ss(DAT_010c7160, r.getQuad());
}
__forceinline float S00d81510_sqrt(float r) { return sqrtf(r); }
__forceinline float S00d81510_sqrtInverse(float r) { return 1.0f / S00d81510_sqrt(r); }
template <typename T> __forceinline T S00d81510_min2(T x, T y) { return x < y ? x : y; }
template <typename T> __forceinline T S00d81510_max2(T x, T y) { return x > y ? x : y; }
template <typename T> __forceinline void S00d81510_swap(T& x, T& y) { T t(x); x = y; y = t; }
__forceinline __m128 S00d81510_quadReciprocal(__m128 r)
{
    __m128 e = S00d81510_Intrinsics::_mm_rcp_ps(r);
    return S00d81510_Intrinsics::_mm_sub_ps(S00d81510_Intrinsics::_mm_add_ps(e, e), S00d81510_Intrinsics::_mm_mul_ps(S00d81510_Intrinsics::_mm_mul_ps(e, r), e));
}

class __declspec(align(16)) S00d81510_Vector4 {
public:
    __forceinline void operator=(const S00d81510_Vector4& v) { m_vComponents = v.m_vComponents; }
    __forceinline float& operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
    __forceinline const float& operator()(int a) const { return reinterpret_cast<const float*>(&m_vComponents)[a]; }
    __forceinline __m128& getQuad() { return m_vComponents; }
    __forceinline void set(float a, float b, float c, float d) { m_vComponents = S00d81510_Intrinsics::_mm_setr_ps(a, b, c, d); }
    __forceinline void mul4(S00d81510_SimdParam s) { m_vComponents = S00d81510_Intrinsics::_mm_mul_ps(s.broadcast(), m_vComponents); }
    __forceinline void mul4(const S00d81510_Vector4& v) { m_vComponents = S00d81510_Intrinsics::_mm_mul_ps(m_vComponents, v.m_vComponents); }
    __forceinline void sub4(const S00d81510_Vector4& v) { m_vComponents = S00d81510_Intrinsics::_mm_sub_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setAdd4(const S00d81510_Vector4& a, const S00d81510_Vector4& b) { m_vComponents = S00d81510_Intrinsics::_mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setSub4(const S00d81510_Vector4& a, const S00d81510_Vector4& b) { m_vComponents = S00d81510_Intrinsics::_mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setMin4(const S00d81510_Vector4& a, const S00d81510_Vector4& b) { m_vComponents = S00d81510_Intrinsics::_mm_min_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setMax4(const S00d81510_Vector4& a, const S00d81510_Vector4& b) { m_vComponents = S00d81510_Intrinsics::_mm_max_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setAbs4(const S00d81510_Vector4& v) { m_vComponents = S00d81510_Intrinsics::_mm_and_ps(DAT_01017d10, v.m_vComponents); }
    __forceinline void setXYZW(const S00d81510_Vector4& xyz, const S00d81510_Vector4& w)
    {
        m_vComponents = S00d81510_Intrinsics::_mm_shuffle_ps(xyz.m_vComponents, S00d81510_Intrinsics::_mm_unpackhi_ps(xyz.m_vComponents, w.m_vComponents), 0xc4);
    }
    __forceinline void setReciprocal4(const S00d81510_Vector4& v) { m_vComponents = S00d81510_quadReciprocal(v.m_vComponents); }
    __forceinline void setReciprocal3(const S00d81510_Vector4& v)
    {
        S00d81510_Vector4 v1111; v1111.getQuad() = DAT_010c7170;
        S00d81510_Vector4 tmp; tmp.setXYZW(v, v1111);
        setReciprocal4(tmp);
    }
    __forceinline void setCross(const S00d81510_Vector4& v0, const S00d81510_Vector4& v1)
    {
        __m128 cross0;
        cross0 = S00d81510_Intrinsics::_mm_mul_ps(S00d81510_Intrinsics::_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9), S00d81510_Intrinsics::_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        __m128 cross1;
        cross1 = S00d81510_Intrinsics::_mm_mul_ps(S00d81510_Intrinsics::_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2), S00d81510_Intrinsics::_mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = S00d81510_Intrinsics::_mm_sub_ps(cross0, cross1);
    }
    __forceinline S00d81510_SimdReal dot3(const S00d81510_Vector4& a) const
    {
        __m128 x2 = S00d81510_Intrinsics::_mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = S00d81510_Intrinsics::_mm_add_ss(S00d81510_Intrinsics::_mm_shuffle_ps(x2, x2, 0x55), x2);
        return S00d81510_Intrinsics::_mm_add_ss(S00d81510_Intrinsics::_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S00d81510_SimdReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline int normalize3IfNotZero()
    {
        const float lengthSqrd3 = this->lengthSquared3();
        if (lengthSqrd3 != 0.0f) {
            this->mul4(S00d81510_sqrtInverse(lengthSqrd3));
            return 0;
        }
        return 1;
    }
    __forceinline void setInt24W(int value) { (reinterpret_cast<unsigned int*>(this))[3] = value |= 0x3f000000; }
    __forceinline int getMajorAxis() const
    {
        S00d81510_Vector4 tmp;
        tmp.setAbs4(*this);
        return tmp(0) < tmp(1) ? (tmp(1) < tmp(2) ? 2 : 1) : (tmp(0) < tmp(2) ? 2 : 0);
    }
    __forceinline static const S00d81510_Vector4& getZero() { return *reinterpret_cast<const S00d81510_Vector4*>(&DAT_01267e30); }
    __m128 m_vComponents;
};

struct S00d81510_TypeIsPod {};
struct S00d81510_TypeIsClass {};
struct S00d81510_Vertex;
__forceinline void* operator new(unsigned int, S00d81510_Vertex* p) throw() { return p; }

struct S00d81510_Allocator {
    virtual void vtbl00();
    virtual void vtbl04();
    virtual void vtbl08();
    virtual void vtbl0c();
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T> __forceinline void _bufFree(void* p, int numElem)
    {
        const int SIZE_ELEM = sizeof(T);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};
struct S00d81510_Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00d81510_Allocator* m_pStreamAllocator;
    __forceinline S00d81510_Allocator& heap() { return *m_pStreamAllocator; }
};
extern "C" void __cdecl FUN_00c908c0(S00d81510_Allocator* alloc, void* array, int numElements, int sizeElem);

template <typename T> __forceinline void S00d81510_construct(T* t, int n, S00d81510_TypeIsPod) {}
template <typename T> __forceinline void S00d81510_destruct(T* t, int n, S00d81510_TypeIsPod) {}
template <typename T> __forceinline void S00d81510_construct(T* t, int n, S00d81510_TypeIsClass)
{
    for (int i = 0; i < n; ++i) {
        ::new (t + i) T;
    }
}
template <typename T> __forceinline void S00d81510_destruct(T* t, int n, S00d81510_TypeIsClass)
{
    for (int i = 0; i < n; ++i) {
        static_cast<T*>(t)[i].~T();
    }
}

template <typename T, typename Tag>
class S00d81510_ArrayBase {
public:
    __forceinline S00d81510_ArrayBase() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~S00d81510_ArrayBase() {}
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline void clear() { S00d81510_destruct(m_data, m_iElementCount, Tag()); m_iElementCount = 0; }
    __forceinline void _clearAndDeallocate(S00d81510_Allocator& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0) {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void GrowArrayCapacity(S00d81510_Allocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n) {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(S00d81510_Allocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        S00d81510_destruct(m_data + n, m_iElementCount - n, Tag());
        S00d81510_construct(m_data + m_iElementCount, n - m_iElementCount, Tag());
        m_iElementCount = n;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct S00d81510_ContainerHeapAllocator {
    __forceinline S00d81510_Allocator& get(const void*) { return reinterpret_cast<S00d81510_Router&>(*FUN_00c85750()).heap(); }
};
template <typename T, typename Tag>
class S00d81510_Array : public S00d81510_ArrayBase<T, Tag> {
public:
    typedef S00d81510_ContainerHeapAllocator AllocatorType;
    __forceinline S00d81510_Array() : S00d81510_ArrayBase<T, Tag>() {}
    __forceinline ~S00d81510_Array() { ClearAndRelease(); }
    __forceinline void ClearAndRelease() { S00d81510_ArrayBase<T, Tag>::_clearAndDeallocate(AllocatorType().get(this)); }
    __forceinline void SetSizeAndGrow(int n) { S00d81510_ArrayBase<T, Tag>::_setSize(AllocatorType().get(this), n); }
    void SwapThreeInts(S00d81510_Array& a);
};

struct S00d81510_Item {
    __forceinline S00d81510_Item() {}
    __forceinline S00d81510_Item(const S00d81510_Item& o) {}
    __forceinline S00d81510_Item& operator=(const S00d81510_Item& o) { return *this; }
    S00d81510_Vertex* m_next;
    S00d81510_Vertex* m_pSecondNode;
};
struct S00d81510_Vertex : S00d81510_Item {
    __forceinline S00d81510_Vertex() { m_2c = 0.0f; m_uiEdgeIndex = -1; }
    S00d81510_Vector4 m_pObservedSource;
    int m_uiX[3];
    float m_2c;
    int m_refs;
    int m_uiEdgeIndex;
};
__forceinline bool operator==(const S00d81510_Vertex& a, const S00d81510_Vertex& b)
{
    return a.m_uiX[0] == b.m_uiX[0] && a.m_uiX[1] == b.m_uiX[1];
}
__forceinline bool operator!=(const S00d81510_Vertex& a, const S00d81510_Vertex& b) { return !(a == b); }
__forceinline int S00d81510_round(float x) { return (int)(x + (x < 0 ? -0.5f : 0.5f)); }

struct S00d81510_Less {};
void __cdecl FUN_00d7af90(S00d81510_Vertex* pArr, int d, int h, S00d81510_Less cmpLess);

struct S00d81510_VertexList {
    int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14;
    int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c;
    S00d81510_Vertex* CloneNode(const S00d81510_Vertex& v);
    __forceinline S00d81510_Vertex* allocate(const S00d81510_Vertex& v = S00d81510_Vertex()) { return CloneNode(v); }
};
struct S00d81510_Bool {
    char m_cBooleanValue;
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
};
typedef S00d81510_Array<S00d81510_Vector4, S00d81510_TypeIsPod> S00d81510_VecArray;
typedef S00d81510_Array<S00d81510_Vertex, S00d81510_TypeIsClass> S00d81510_VertexArray;

class __declspec(align(16)) S00d81510_Hull {
public:
    S00d81510_Bool m_bFlagAtOffset00;
    char unk01; char unk02; char unk03;
    int unk04;
    S00d81510_Bool m_bFlagAtOffset08;
    S00d81510_Bool m_bFlagAtOffset09;
    S00d81510_Bool m_bFlagAtOffset0A;
    S00d81510_Bool m_bFlagAtOffset0B;
    S00d81510_Bool m_bFlagAtOffset0C;
    char unk0d; char unk0e; char unk0f;
    int unk10;
    int unk14;
    S00d81510_VertexList m_meshVertices;
    S00d81510_VertexArray m_kVertices;
    int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc;
    S00d81510_Vector4 m_kVectorAtOffsetD0;
    S00d81510_Vector4 m_kVectorAtOffsetE0;
    S00d81510_Vector4 m_domainCenter;
    S00d81510_Vector4 m_domainScale;
    S00d81510_Vector4 m_domainScaleInv;
    int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c;
    int unk1a0; int unk1a4;
    int m_eVertexFloatDimensions;

    void FUN_00d7ac40(bool planar);
    bool FUN_00d7fb80();
    void FUN_00d7d2a0();
    void FUN_00d7b600();
    int FUN_00d81510(const S00d81510_Vector4* points, int numPoints, bool planar, const S00d81510_Hull* domainSource);

    __forceinline S00d81510_Vertex transformChecked(const S00d81510_Vector4& x, bool& outOfRange) const
    {
        S00d81510_Vertex v;
        S00d81510_Vector4 tx = x;
        tx.sub4(m_domainCenter);
        v.m_pObservedSource = x;
        tx.mul4(m_domainScale);
        for (int i = 0; i < 3; ++i) {
            outOfRange |= (tx(i) > 8191.0 || tx(i) < -8192.0);
            v.m_uiX[i] = S00d81510_round(S00d81510_max2(-8192.0f, S00d81510_min2(8191.0f, tx(i))));
        }
        return v;
    }
    __forceinline S00d81510_Vertex transform(const S00d81510_Vector4& x) const
    {
        bool outOfRange;
        return transformChecked(x, outOfRange);
    }
    __forceinline static void makeVertex(const S00d81510_Vertex& v, S00d81510_Vertex* dst)
    {
        *dst = v;
        dst->m_refs = 0;
    }
    __forceinline static int orientation(const S00d81510_Vertex& a, const S00d81510_Vertex& b, const S00d81510_Vertex& c)
    {
        const int d0 = (b.m_uiX[0] - a.m_uiX[0]) * (c.m_uiX[1] - a.m_uiX[1]);
        const int d1 = (b.m_uiX[1] - a.m_uiX[1]) * (c.m_uiX[0] - a.m_uiX[0]);
        return d0 - d1;
    }
    template <int A, int B> __forceinline void swapCoordinates()
    {
        for (int i = 0, n = m_kVertices.GetLogicalSize(); i < n; ++i) {
            S00d81510_swap(m_kVertices[i].m_uiX[A], m_kVertices[i].m_uiX[B]);
        }
    }
    __forceinline void projectOnMajorAxis(const S00d81510_Vector4& plane)
    {
        switch (plane.getMajorAxis()) {
        case 0: swapCoordinates<0, 2>(); break;
        case 1: swapCoordinates<1, 2>(); break;
        }
    }
};

struct HullPlaneOwner {
    void FUN_00d75b80(__m128& out, const int* triangle);
};

class ScalarPlaneQ {
    __m128 value;
public:
    ScalarPlaneQ(const __m128& a):value(a){}
    ScalarPlaneQ(float a){value=_mm_load_ss(&a);}
    ScalarPlaneQ(){}
    operator float() const {float f;_mm_store_ss(&f,value);return f;}
    __forceinline const __m128& quad() const {return value;}
};
inline ScalarPlaneQ operator+(const ScalarPlaneQ& a,const ScalarPlaneQ& b){return _mm_add_ss(a.quad(),b.quad());}

struct PlaneTransformQ;
struct PlaneVectorQ {
    __m128 q;
    __forceinline void SetTransformedPoint(const PlaneTransformQ& t,const PlaneVectorQ& src);
    __forceinline void operator=(const PlaneVectorQ& a) { q=a.q; }
    __forceinline void setW(float w) { q.m128_f32[3]=w; }
    __forceinline ScalarPlaneQ dot(const PlaneVectorQ& point) const {
        __m128 product=_mm_mul_ps(q,point.q);
        __m128 xy=_mm_add_ss(_mm_shuffle_ps(product,product,0x55),product);
        return _mm_add_ss(_mm_shuffle_ps(product,product,0xaa),xy);
    }
    __forceinline ScalarPlaneQ lane(int i) const {
        switch(i) { case 0:return q;case 1:return _mm_shuffle_ps(q,q,0x55);case 2:return _mm_shuffle_ps(q,q,0xaa);
        default:return _mm_shuffle_ps(q,q,0xff); }
    }
};
struct PlaneVertexQ {
    PlaneVertexQ* next; int flag,unk08,unk0c;
    PlaneVectorQ position;
};
struct PlaneFaceQ {
    PlaneFaceQ* next; int unk04;
    PlaneVertexQ* vertices[3];
};
struct PlanePointsQ {
    PlaneVectorQ* data; int size; int capacityAndFlags;
    __forceinline int GetLogicalSize() const { return size; }
    __forceinline const PlaneVectorQ& operator[](int i) const { return data[i]; }
};
struct PlaneTransformQ { PlaneVectorQ rows[4]; };

struct PlaneHullQ {
    int unk00,unk04,unk08,unk0c,unk10,unk14,unk18,unk1c,unk20;
    PlaneVertexQ* vertices; int numVertices,unk2c,unk30,unk34,unk38;
    PlaneFaceQ* faces;
    float FUN_00d7a810(const PlanePointsQ& points,const PlaneTransformQ& transform,PlaneVectorQ& out);
};

namespace N {
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; short m128_i16[8]; int m128_i32[4]; __int64 m128_i64[2]; unsigned short m128_u16[8]; unsigned int m128_u32[4]; };
extern "C" {
__m128 _mm_add_ss(__m128, __m128);
__m128 _mm_mul_ps(__m128 a, __m128 b);
__m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm);
__m128 _mm_sqrt_ss(__m128);
void _mm_store_ss(float*, __m128);
__m128 _mm_sub_ps(__m128 a, __m128 b);
}
}
extern const char str_010d37a8[];
extern const char str_010d3574[];
struct S83_Vec4 {
    N::__m128 q;
    __forceinline void operator=(const S83_Vec4& v) { q = v.q; }
};
struct S83_Vertex {
    S83_Vertex* next;
    int unk04;
    int unk08;
    int unk0c;
    S83_Vec4 point;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int removalFlag;
};
struct S83_Tri {
    S83_Tri* next;
    int unk04;
    S83_Vertex* v[3];
};
struct S83_Options {
    int vertexLimit;
    unsigned char reseat;
    float tolerance;
    int unk0c;
    unsigned char rebuild;
    unsigned char modified;
};
struct S83_Alloc {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int bytes);

    template<class T> __forceinline void freeElements(void* p,int count) { ReturnMemory(p,count*sizeof(T)); }

};
static __forceinline S83_Alloc& S83_heap() { return *reinterpret_cast<S83_Alloc*>(FUN_00c85750()->heap()); }
struct S83_PlainElement {};
struct S83_ElementOps {
    template<class T> static __forceinline void create(T*,int,S83_PlainElement) {}
    template<class T> static __forceinline void discard(T*,int,S83_PlainElement) {}
    template<class T> static __forceinline void copy(T* dest,int count,const T& value,S83_PlainElement) {
        for(int i=0;i<count;++i) dest[i]=value;
    }
};
struct S83_HeapAccess {
    __forceinline S83_Alloc& get(const void*) { return S83_heap(); }
};
extern void __cdecl FUN_00c908c0(S83_Alloc&,void*,int,int);
extern void __cdecl ResizeAudioStream(S83_Alloc&,void*,int);
template <class T> struct S83_ArrayBase {
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline S83_ArrayBase() : m_data(0),m_iElementCount(0),m_iCapacityState(0x80000000) {}
    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void grow(S83_Alloc& heap,int required) {
        int oldCapacity=getCapacity();
        if(oldCapacity<required) {
            int doubled=oldCapacity*2;
            FUN_00c908c0(heap,this,required<doubled?doubled:required,sizeof(T));
        }
    }
    __forceinline void resize(S83_Alloc& heap,int n) {
        grow(heap,n);
        S83_ElementOps::discard(m_data+n,m_iElementCount-n,S83_PlainElement());
        S83_ElementOps::create(m_data+m_iElementCount,n-m_iElementCount,S83_PlainElement());
        m_iElementCount=n;
    }
    __forceinline T* appendSpace(S83_Alloc& heap,int n) {
        int old=m_iElementCount;
        grow(heap,m_iElementCount+n);
        S83_ElementOps::create(m_data+m_iElementCount,n,S83_PlainElement());
        m_iElementCount+=n;
        return m_data+old;
    }
    __forceinline void append(S83_Alloc& heap,const T& value) {
        if(m_iElementCount==getCapacity()) ResizeAudioStream(heap,this,sizeof(T));
        S83_ElementOps::copy(m_data+m_iElementCount,1,value,S83_PlainElement());
        ++m_iElementCount;
    }
    __forceinline int indexOf(const T& v) const {
        for(int i=0;i<m_iElementCount;++i) if(m_data[i]==v) return i;
        return -1;
    }
    __forceinline void clear() {
        S83_ElementOps::discard(m_data,m_iElementCount,S83_PlainElement());
        m_iElementCount=0;
    }
    __forceinline void release(S83_Alloc& heap) {
        clear();
        if((m_iCapacityState & 0x80000000)==0) heap.freeElements<T>(m_data,getCapacity());
        m_data=0;
        m_iCapacityState=0x80000000;
    }
};
template<class T> struct S83_OwnedArray : S83_ArrayBase<T> {
    __forceinline S83_OwnedArray() : S83_ArrayBase<T>() {}
    __forceinline ~S83_OwnedArray() { clearAndFree(); }
    __forceinline void clearAndFree() { this->release(S83_HeapAccess().get(this)); }
    __forceinline void reserve(int n) { this->grow(S83_HeapAccess().get(this),n); }
    __forceinline void SetSizeAndGrow(int n) { this->resize(S83_HeapAccess().get(this),n); }
    __forceinline T* expandBy(int n) { return this->appendSpace(S83_HeapAccess().get(this),n); }
    __forceinline void AddBack(const T& v) { this->append(S83_HeapAccess().get(this),v); }
};
template<class T> struct S83_Array : S83_OwnedArray<T> {};
struct S83_Fmt {
    int unk00;
    int unk04;
    int unk08;
    void FUN_00cb1600(char* buffer, int capacity);
    S83_Fmt* FUN_00cc01c0(const char* text);
    S83_Fmt* FUN_00cc01c0(const char* text, int code, const char* tail);
    S83_Fmt* FUN_00cc02d0();
    void FUN_00cc01c0();
    void FUN_00cc00e0();
};
struct S83_Mesh {
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk020;
    S83_Vertex* vertices;
    int vertexCount;
    int unk02c;
    int unk030;
    int unk034;
    int unk038;
    S83_Tri* triangles;
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
    int unk0e4;
    int unk0e8;
    int unk0ec;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int state;
    int unk1ac;
    int diagnosticCode;
    unsigned char flag1b4;
    unsigned char flag1b5;
    void FUN_00d83f30(S83_Options* options);
    void FUN_00d82ad0(int limit, bool reseat);
    int FUN_00d81510(const S83_Vec4* points, int numPoints, int a, int b);
    void FUN_00d7d2a0();
    void FUN_00d7b600();
    void FUN_00d7df60(S83_Array<int>* a, S83_Array<int>* b, int c, int d);
};

extern "C" {
__m128 _mm_mul_ps(__m128,__m128);
__m128 _mm_add_ps(__m128,__m128);
__m128 _mm_sub_ps(__m128,__m128);
__m128 _mm_add_ss(__m128,__m128);
__m128 _mm_sub_ss(__m128,__m128);
__m128 _mm_mul_ss(__m128,__m128);
__m128 _mm_cmpeq_ss(__m128,__m128);
__m128 _mm_rsqrt_ss(__m128);
__m128 _mm_andnot_ps(__m128,__m128);
__m128 _mm_set_ss(float);
void _mm_store_ss(float*,__m128);
}
extern const char str_010d36ec[];
extern const char str_010d3540[];
extern const __m128 DAT_010c7160;

struct S00d7fb80_Stream {
    int unk00;
    int unk04;
    int unk08;
    S00d7fb80_Stream* FUN_00cb1600(void* buf, int size);
    S00d7fb80_Stream& FUN_00cc01c0(const char* s);
    void FUN_00cc00e0();
};
class S00d7fb80_SimdReal {
public:
    __forceinline S00d7fb80_SimdReal(const __m128& x) : m_vValue(x) {}
    __forceinline operator float() const { float s; _mm_store_ss(&s, m_vValue); return s; }
    __forceinline __m128 broadcast() const { return _mm_shuffle_ps(m_vValue, m_vValue, 0); }
    __forceinline const __m128& getQuad() const { return m_vValue; }
    __m128 m_vValue;
};
typedef const S00d7fb80_SimdReal& S00d7fb80_SimdParam;
__forceinline S00d7fb80_SimdReal operator-(S00d7fb80_SimdParam r)
{
    return _mm_sub_ss(DAT_010c7160, r.getQuad());
}

class __declspec(align(16)) S00d7fb80_Vector4 {
public:
    __forceinline void operator=(const S00d7fb80_Vector4& v) { m_vComponents = v.m_vComponents; }
    __forceinline float& operator()(int a) { return reinterpret_cast<float*>(&m_vComponents)[a]; }
    __forceinline const float& operator()(int a) const { return reinterpret_cast<const float*>(&m_vComponents)[a]; }
    __forceinline void set(float a, float b, float c, float d) { m_vComponents = _mm_setr_ps(a, b, c, d); }
    __forceinline void mul4(const S00d7fb80_Vector4& v) { m_vComponents = _mm_mul_ps(m_vComponents, v.m_vComponents); }
    __forceinline void add4(const S00d7fb80_Vector4& v) { m_vComponents = _mm_add_ps(m_vComponents, v.m_vComponents); }
    __forceinline void setSub4(const S00d7fb80_Vector4& a, const S00d7fb80_Vector4& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setCross(const S00d7fb80_Vector4& v0, const S00d7fb80_Vector4& v1)
    {
        __m128 cross0;
        cross0 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xc9), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xd2));
        __m128 cross1;
        cross1 = _mm_mul_ps(_mm_shuffle_ps(v0.m_vComponents, v0.m_vComponents, 0xd2), _mm_shuffle_ps(v1.m_vComponents, v1.m_vComponents, 0xc9));
        m_vComponents = _mm_sub_ps(cross0, cross1);
    }
    __forceinline S00d7fb80_SimdReal dot3(const S00d7fb80_Vector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline S00d7fb80_SimdReal lengthSquared3() const { return this->dot3(*this); }
    __forceinline S00d7fb80_SimdReal lengthInverse3() const
    {
        const __m128 half = _mm_set_ss(0.5f);
        const __m128 three = _mm_set_ss(3.0f);
        const __m128 zero = _mm_set_ss(0.0f);
        const __m128 len2 = this->dot3(*this).getQuad();
        const __m128 len2EqualsZero = _mm_cmpeq_ss(len2, zero);
        const __m128 approx = _mm_rsqrt_ss(len2);
        const __m128 refined = _mm_mul_ss(
            _mm_mul_ss(half, approx),
            _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(len2, approx), approx)));
        return _mm_andnot_ps(len2EqualsZero, refined);
    }
    __forceinline void normalize3()
    {
        __m128 lenInv = lengthInverse3().broadcast();
        m_vComponents = _mm_mul_ps(lenInv, m_vComponents);
    }
    __forceinline static const S00d7fb80_Vector4& getZero() { return *reinterpret_cast<const S00d7fb80_Vector4*>(&DAT_01267e30); }
    __m128 m_vComponents;
};

struct S00d7fb80_TypeIsClass {};
template <typename T> __forceinline void S00d7fb80_destruct(T* t, int n, S00d7fb80_TypeIsClass)
{
    for (int i = 0; i < n; ++i) {
        static_cast<T*>(t)[i].~T();
    }
}
template <unsigned int ELEMENTSIZE, unsigned int ALIGN>
__forceinline void S00d7fb80_memCpyOneAligned(void* dst, const void* src)
{
    typedef unsigned __int64 CopyType;
    unsigned int i = 0;
    do {
        static_cast<CopyType*>(dst)[i] = static_cast<const CopyType*>(src)[i];
    } while (++i < ELEMENTSIZE / sizeof(CopyType));
}

struct S00d7fb80_Allocator {
    virtual void vtbl00();
    virtual void vtbl04();
    virtual void vtbl08();
    virtual void vtbl0c();
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T> __forceinline void _bufFree(void* p, int numElem)
    {
        const int SIZE_ELEM = sizeof(T);
        ReturnMemory(p, numElem * SIZE_ELEM);
    }
};
struct S00d7fb80_Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S00d7fb80_Allocator* m_pStreamAllocator;
    __forceinline S00d7fb80_Allocator& heap() { return *m_pStreamAllocator; }
};
template <typename T>
class S00d7fb80_ArrayBase {
public:
    __forceinline int GetLogicalSize() const { return m_iElementCount; }
    __forceinline int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline T& operator[](int i) { return m_data[i]; }
    __forceinline void clear() { S00d7fb80_destruct(m_data, m_iElementCount, S00d7fb80_TypeIsClass()); m_iElementCount = 0; }
    __forceinline void removeAt(int index)
    {
        S00d7fb80_destruct(&m_data[index], 1, S00d7fb80_TypeIsClass());
        m_iElementCount--;
        if (m_iElementCount != index) {
            S00d7fb80_memCpyOneAligned<sizeof(T), __alignof(T)>(m_data + index, m_data + m_iElementCount);
        }
    }
    __forceinline void popBack(int numElemsToRemove = 1)
    {
        S00d7fb80_destruct(m_data + m_iElementCount - numElemsToRemove, numElemsToRemove, S00d7fb80_TypeIsClass());
        m_iElementCount -= numElemsToRemove;
    }
    __forceinline void _clearAndDeallocate(S00d7fb80_Allocator& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0) {
            alloc._bufFree<T>(m_data, getCapacity());
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct S00d7fb80_ContainerHeapAllocator {
    __forceinline S00d7fb80_Allocator& get(const void*) { return reinterpret_cast<S00d7fb80_Router&>(*FUN_00c85750()).heap(); }
};
template <typename T>
class S00d7fb80_Array : public S00d7fb80_ArrayBase<T> {
public:
    __forceinline void ClearAndRelease() { S00d7fb80_ArrayBase<T>::_clearAndDeallocate(S00d7fb80_ContainerHeapAllocator().get(this)); }
};

template <typename T>
struct S00d7fb80_Item {
    __forceinline S00d7fb80_Item() {}
    __forceinline S00d7fb80_Item(const S00d7fb80_Item& o) {}
    __forceinline S00d7fb80_Item& operator=(const S00d7fb80_Item& o) { return *this; }
    __forceinline T* next() const { return m_next; }
    T* m_next;
    T* m_pSecondNode;
};
struct S00d7fb80_Vertex : S00d7fb80_Item<S00d7fb80_Vertex> {
    __forceinline S00d7fb80_Vertex() { m_2c = 0.0f; m_uiEdgeIndex = -1; }
    S00d7fb80_Vector4 m_pObservedSource;
    int m_uiX[3];
    float m_2c;
    int m_refs;
    int m_uiEdgeIndex;
};
struct S00d7fb80_Plane {
    __forceinline S00d7fb80_Plane() { m_uiEdgeIndex = -1; }
    int m_uiX[3];
    __int64 m_offset;
    int m_uiEdgeIndex;
};
typedef unsigned long S00d7fb80_Uid;
struct S00d7fb80_Triangle;
template <typename VERTEX>
struct S00d7fb80_TriangleBase : S00d7fb80_Item<S00d7fb80_Triangle> {
    __forceinline VERTEX& vertex(int i) { return m_kVertices[i]; }
    __forceinline S00d7fb80_Uid& link(int i) { return m_ppLinks[i]; }
    VERTEX m_kVertices[3];
    S00d7fb80_Uid m_ppLinks[3];
};
struct S00d7fb80_Triangle : S00d7fb80_TriangleBase<S00d7fb80_Vertex*> {
    __forceinline S00d7fb80_Triangle() { m_uiEdgeIndex = -1; }
    __forceinline ~S00d7fb80_Triangle() {}
    S00d7fb80_Plane m_kTriangleNormal;
    int m_40;
    int m_uiEdgeIndex;
};
__forceinline S00d7fb80_Uid S00d7fb80_uid2ulong(void* t, unsigned int i) { return (*(const unsigned long*)&t) + (unsigned long)i; }
__forceinline S00d7fb80_Uid S00d7fb80_packUid(void* t, unsigned int i) { return S00d7fb80_uid2ulong(t, i); }
template <typename T>
__forceinline void S00d7fb80_ulong2uid(unsigned long uid, T*& t, unsigned int& i)
{
    i = (unsigned int)(uid & 3);
    uid &= ~3;
    t = *(T**)&uid;
}
template <typename T>
__forceinline void S00d7fb80_unpackUid(S00d7fb80_Uid uid, T*& t, unsigned int& i) { S00d7fb80_ulong2uid(uid, t, i); }

template <typename EDGE, typename VERTEX, typename TRIANGLE, typename VERTEX_MEMBER>
struct S00d7fb80_TopoEdge {
    static __forceinline unsigned ip1mod3(unsigned i) { return (0x09 >> (i << 1)) & 3; }
    __forceinline S00d7fb80_TopoEdge() {}
    __forceinline S00d7fb80_TopoEdge(TRIANGLE* t, unsigned i) : m_pkTriangle(t), m_uiEdgeIndex(i) {}
    __forceinline S00d7fb80_TopoEdge(const S00d7fb80_Uid& id) { S00d7fb80_unpackUid(id, m_pkTriangle, m_uiEdgeIndex); }
    __forceinline EDGE next() const { return EDGE(m_pkTriangle, ip1mod3(m_uiEdgeIndex)); }
    __forceinline EDGE link() const { return EDGE(m_pkTriangle->link(m_uiEdgeIndex)); }
    __forceinline EDGE nextCcw() const { return link().next(); }
    __forceinline TRIANGLE* triangle() const { return m_pkTriangle; }
    __forceinline S00d7fb80_Uid uid() const { return S00d7fb80_packUid(m_pkTriangle, m_uiEdgeIndex); }
    __forceinline VERTEX_MEMBER& start() const { return m_pkTriangle->vertex(m_uiEdgeIndex); }
    __forceinline VERTEX_MEMBER& end() const { return m_pkTriangle->vertex(ip1mod3(m_uiEdgeIndex)); }
    __forceinline bool isValid() const { return triangle() != 0; }
    __forceinline bool isNaked() const { return !link().isValid(); }
    __forceinline void bind(const S00d7fb80_TopoEdge& edge) const
    {
        m_pkTriangle->link(m_uiEdgeIndex) = edge.uid();
        if (edge.isValid()) edge.m_pkTriangle->link(edge.m_uiEdgeIndex) = uid();
    }
    __forceinline bool operator!=(const EDGE& e) const { return uid() != e.uid(); }
    TRIANGLE* m_pkTriangle;
    unsigned int m_uiEdgeIndex;
};
struct S00d7fb80_Edge : S00d7fb80_TopoEdge<S00d7fb80_Edge, S00d7fb80_Vertex, S00d7fb80_Triangle, S00d7fb80_Vertex*> {
    typedef S00d7fb80_TopoEdge<S00d7fb80_Edge, S00d7fb80_Vertex, S00d7fb80_Triangle, S00d7fb80_Vertex*> tBase;
    __forceinline S00d7fb80_Edge(S00d7fb80_Triangle* t, int i) : tBase(t, i) {}
    __forceinline S00d7fb80_Edge(S00d7fb80_Uid id) : tBase(id) {}
};
struct S00d7fb80_VertexList {
    int unk00; int unk04; int unk08;
    S00d7fb80_Vertex* m_uiBufferCapacity;
    int m_iAllocatedCount; int unk14;
    S00d7fb80_Vertex* allocateItem();
    S00d7fb80_Vertex* CloneNode(const S00d7fb80_Vertex& v);
    __forceinline S00d7fb80_Vertex* allocate(const S00d7fb80_Vertex& v = S00d7fb80_Vertex()) { return CloneNode(v); }
};
struct S00d7fb80_TriangleList {
    int unk00; int unk04; int unk08;
    S00d7fb80_Triangle* m_uiBufferCapacity;
    int m_iAllocatedCount; int unk14;
    S00d7fb80_Triangle* allocateItem();
    S00d7fb80_Triangle* FUN_00d7efc0(const S00d7fb80_Triangle& t);
    __forceinline S00d7fb80_Triangle* allocate(const S00d7fb80_Triangle& t = S00d7fb80_Triangle()) { return FUN_00d7efc0(t); }
    __forceinline S00d7fb80_Triangle* getFirst() const { return m_uiBufferCapacity; }
};
__forceinline void* operator new(unsigned int, S00d7fb80_Vertex* p) throw() { return p; }
__forceinline void* operator new(unsigned int, S00d7fb80_Triangle* p) throw() { return p; }

struct S00d7fb80_Bool {
    char m_cBooleanValue;
    __forceinline operator bool() const { return m_cBooleanValue != 0; }
};

class __declspec(align(16)) S00d7fb80_Hull {
public:
    S00d7fb80_Bool m_bFlagAtOffset00;
    char unk01; char unk02; char unk03;
    int unk04; int unk08; int unk0c; int unk10; int unk14;
    S00d7fb80_VertexList m_meshVertices;
    S00d7fb80_TriangleList m_meshTriangles;
    S00d7fb80_Array<S00d7fb80_Vertex> m_kVertices;
    int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    int unk80; int unk84; int unk88; int unk8c; int unk90; int unk94; int unk98; int unk9c;
    int unka0; int unka4; int unka8; int unkac; int unkb0; int unkb4; int unkb8; int unkbc;
    int unkc0; int unkc4; int unkc8; int unkcc; int unkd0; int unkd4; int unkd8; int unkdc;
    S00d7fb80_Vector4 m_kVectorAtOffsetE0;
    S00d7fb80_Vector4 m_domainCenter;
    S00d7fb80_Vector4 m_domainScale;
    S00d7fb80_Vector4 m_domainScaleInv;
    int unk120; int unk124; int unk128; int unk12c; int unk130; int unk134; int unk138; int unk13c;
    int unk140; int unk144; int unk148; int unk14c; int unk150; int unk154; int unk158; int unk15c;
    int unk160; int unk164; int unk168; int unk16c; int unk170; int unk174; int unk178; int unk17c;
    int unk180; int unk184; int unk188; int unk18c; int unk190; int unk194; int unk198; int unk19c;
    int unk1a0; int unk1a4;
    int m_eVertexFloatDimensions;
    int m_uiUniqueId;

    bool FUN_00d7fb80();
    void FUN_00d7c3e0(const S00d7fb80_Vertex& v, const S00d7fb80_Edge& edge, S00d7fb80_Edge& out);

    template <typename T> static __forceinline T mul_32x32(int a, int b) { return (T)a * (T)b; }
    static __forceinline __int64 distanceToPlane(const S00d7fb80_Vertex& v, const S00d7fb80_Plane& p)
    {
        return mul_32x32<__int64>(v.m_uiX[0], p.m_uiX[0]) + mul_32x32<__int64>(v.m_uiX[1], p.m_uiX[1]) + mul_32x32<__int64>(v.m_uiX[2], p.m_uiX[2]) + p.m_offset;
    }
    static __forceinline bool makePlane(const S00d7fb80_Vertex& a, const S00d7fb80_Vertex& b, const S00d7fb80_Vertex& c, S00d7fb80_Plane& plane)
    {
        int ab[3]; ab[0] = b.m_uiX[0] - a.m_uiX[0]; ab[1] = b.m_uiX[1] - a.m_uiX[1]; ab[2] = b.m_uiX[2] - a.m_uiX[2];
        int ac[3]; ac[0] = c.m_uiX[0] - a.m_uiX[0]; ac[1] = c.m_uiX[1] - a.m_uiX[1]; ac[2] = c.m_uiX[2] - a.m_uiX[2];
        plane.m_uiX[0] = ab[1] * ac[2] - ab[2] * ac[1];
        plane.m_uiX[1] = ab[2] * ac[0] - ab[0] * ac[2];
        plane.m_uiX[2] = ab[0] * ac[1] - ab[1] * ac[0];
        plane.m_offset = 0;
        if (plane.m_uiX[0] | plane.m_uiX[1] | plane.m_uiX[2]) {
            plane.m_offset = -distanceToPlane(a, plane);
            return true;
        }
        return false;
    }
    static __forceinline bool makeTriangle(S00d7fb80_Vertex* a, S00d7fb80_Vertex* b, S00d7fb80_Vertex* c, S00d7fb80_Triangle* t)
    {
        t->vertex(0) = a;
        t->vertex(1) = b;
        t->vertex(2) = c;
        t->m_40 = 0;
        t->m_uiEdgeIndex = -1;
        a->m_refs++;
        b->m_refs++;
        c->m_refs++;
        return makePlane(*a, *b, *c, t->m_kTriangleNormal);
    }
    static __forceinline void makeVertex(const S00d7fb80_Vertex& v, S00d7fb80_Vertex* dst)
    {
        *dst = v;
        dst->m_refs = 0;
    }
    __forceinline S00d7fb80_Vector4 transform(const S00d7fb80_Vertex& v) const
    {
        S00d7fb80_Vector4 x;
        x.set((float)v.m_uiX[0], (float)v.m_uiX[1], (float)v.m_uiX[2], 0.0f);
        x.mul4(m_domainScaleInv);
        x.add4(m_domainCenter);
        return x;
    }
    __forceinline S00d7fb80_Triangle* locateBoundaryExhaustive(const S00d7fb80_Vertex& x) const
    {
        for (S00d7fb80_Triangle* t = m_meshTriangles.getFirst(); t; t = t->next()) {
            const __int64 d = distanceToPlane(x, t->m_kTriangleNormal);
            if (d > 0) {
                return t;
            }
        }
        return 0;
    }
    static __forceinline S00d7fb80_Edge nextHorizon(const S00d7fb80_Edge& edge)
    {
        S00d7fb80_Edge e = edge.next();
        while (!e.isNaked()) {
            e = e.nextCcw();
        }
        return e;
    }
    __forceinline bool insert(const S00d7fb80_Vertex& x)
    {
        S00d7fb80_Triangle* root = locateBoundaryExhaustive(x);
        if (root) {
            S00d7fb80_Vertex* newVertex = m_meshVertices.allocate();
            S00d7fb80_Edge edge(0, 0);
            makeVertex(x, newVertex);
            m_uiUniqueId++;
            FUN_00d7c3e0(*newVertex, S00d7fb80_Edge(root, 0), edge);
            while (!edge.isNaked()) {
                edge = edge.next();
            }
            const S00d7fb80_Edge first = edge;
            S00d7fb80_Triangle* firstT = 0;
            S00d7fb80_Triangle* lastT = 0;
            while (first != (edge = nextHorizon(edge))) {
                S00d7fb80_Triangle* t = m_meshTriangles.allocate();
                makeTriangle(newVertex, edge.end(), edge.start(), t);
                edge.bind(S00d7fb80_Edge(t, 1));
                if (lastT) {
                    S00d7fb80_Edge(lastT, 0).bind(S00d7fb80_Edge(t, 2));
                } else {
                    firstT = t;
                }
                lastT = t;
            }
            while (edge != first) {
            }
            S00d7fb80_Triangle* t = m_meshTriangles.allocate();
            makeTriangle(newVertex, edge.end(), edge.start(), t);
            edge.bind(S00d7fb80_Edge(t, 1));
            S00d7fb80_Edge(lastT, 0).bind(S00d7fb80_Edge(t, 2));
            S00d7fb80_Edge(t, 0).bind(S00d7fb80_Edge(firstT, 2));
            return true;
        }
        return false;
    }
};

extern "C" {
__m128 _mm_sub_ps(__m128, __m128);
__m128 _mm_add_ps(__m128, __m128);
__m128 _mm_mul_ps(__m128, __m128);
__m128 _mm_add_ss(__m128, __m128);
__m128 _mm_sub_ss(__m128, __m128);
__m128 _mm_mul_ss(__m128, __m128);
__m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
__m128 _mm_rsqrt_ss(__m128);
__m128 _mm_cmpeq_ss(__m128, __m128);
__m128 _mm_andnot_ps(__m128, __m128);
__m128 _mm_setzero_ps();
__m128 _mm_set_ss(float);
__m128 _mm_load_ss(const float*);
void _mm_store_ss(float*, __m128);
double fabs(double);
void* memcpy(void*,const void*,unsigned int);
}
extern const float DAT_010141cc;
extern const float s_faderClearedAlpha;
extern const char str_010d3748[];
extern const char str_010d3540[];

class ExpandTruth {
    char value;
public:
    __forceinline ExpandTruth() {}
    __forceinline ExpandTruth(bool b) { value=static_cast<char>(b); }
    __forceinline operator bool() const { return value!=0; }
    __forceinline ExpandTruth& operator=(bool b) { value=static_cast<char>(b);return *this; }
    __forceinline ExpandTruth operator==(bool b) const { return (int)value==(int)b; }
    __forceinline ExpandTruth operator!=(bool b) const { return (int)value!=(int)b; }
};
struct ExpandScalar {
    __m128 q;
    __forceinline ExpandScalar(const float& f) : q(_mm_load_ss(&f)) {}
    __forceinline ExpandScalar(__m128 v) : q(v) {}
};
struct __declspec(align(16)) ExpandVector {
    union { __m128 q; struct { int x,y,z,w; } bits; };
    __forceinline void assign(const ExpandVector& v) { q=v.q; }
    __forceinline float& operator[](int i) { return q.m128_f32[i]; }
    __forceinline const float& operator[](int i) const { return q.m128_f32[i]; }
    __forceinline void setZero() { q=_mm_setzero_ps(); }
    __forceinline void setSub(const ExpandVector& a,const ExpandVector& b) { q=_mm_sub_ps(a.q,b.q); }
    __forceinline void setAdd(const ExpandVector& a,const ExpandVector& b) { q=_mm_add_ps(a.q,b.q); }
    __forceinline void setAddMul(const ExpandVector& a,const ExpandVector& b,const ExpandScalar& s) {
        __m128 mul=_mm_mul_ps(_mm_shuffle_ps(s.q,s.q,0),b.q);
        q=_mm_add_ps(mul,a.q);
    }
    __forceinline void setCross(const ExpandVector& a,const ExpandVector& b) {
        __m128 t0=_mm_mul_ps(_mm_shuffle_ps(b.q,b.q,0xc9),_mm_shuffle_ps(a.q,a.q,0xd2));
        __m128 t1=_mm_mul_ps(_mm_shuffle_ps(b.q,b.q,0xd2),_mm_shuffle_ps(a.q,a.q,0xc9));
        q=_mm_sub_ps(t1,t0);
    }
    __forceinline void normalize3() {
        __m128 sq=_mm_mul_ps(q,q);
        __m128 len=_mm_add_ss(_mm_shuffle_ps(sq,sq,0xaa),_mm_add_ss(_mm_shuffle_ps(sq,sq,0x55),sq));
        __m128 r=_mm_rsqrt_ss(len);
        __m128 zero=_mm_set_ss(DAT_01011d78);
        __m128 three=_mm_set_ss(DAT_01017718);
        __m128 half=_mm_set_ss(DAT_01016248);
        __m128 rr=_mm_mul_ss(len,r); rr=_mm_mul_ss(rr,r);
        __m128 nr=_mm_mul_ss(_mm_mul_ss(half,r),_mm_sub_ss(three,rr));
        __m128 inv=_mm_andnot_ps(_mm_cmpeq_ss(len,zero),nr);
        q=_mm_mul_ps(_mm_shuffle_ps(inv,inv,0),q);
    }
    __forceinline void mul(const ExpandScalar& s) { q=_mm_mul_ps(q,_mm_shuffle_ps(s.q,s.q,0)); }
    unsigned char* FUN_00c7f520(unsigned char*,float) const;
};

struct ExpandHeap {
    virtual void unknown0();
    virtual void unknown4();
    virtual void unknown8();
    virtual void unknownC();
    virtual void ReturnMemory(void*,int);
};
struct ExpandRouter {
    int unk00,unk04,unk08,unk0c;
    ExpandHeap* heap;
    static ExpandRouter* FUN_00c85750();
};
struct ExpandArray {
    ExpandVector* data;
    int size;
    int capacity;
    __forceinline void init() {data=0;size=0;capacity=0x80000000;}
    __forceinline void clearAndFree() {
        ExpandHeap& heap=(ExpandHeap&)fnvc_adapt::FUN_00c85750().heap();
        size=0;
        if ((capacity&0x80000000)==0) heap.ReturnMemory(data,(capacity&0x3fffffff)*sizeof(ExpandVector));
    }
    __forceinline void reserve(int n) {
        D76250Allocator& heap=fnvc_adapt::FUN_00c85750().heap();
        const int cap=capacity&0x3fffffff;
        if (cap<n) {
            int twice=cap*2;
            int newSize=n<twice?twice:n;
            FUN_00c908c0(&heap,this,newSize,sizeof(ExpandVector));
        }
    }
    __forceinline void SetSizeAndGrow(int n,const ExpandVector& value) {
        reserve(n);
        int count=n-size;
        ExpandVector* p=&data[size];
        for (int i=0;i<count;++i) p[i].assign(value);
        size=n;
    }
    __forceinline ExpandVector& AllocatePair() {
        D76250MemoryRouter& router=fnvc_adapt::FUN_00c85750();
        if (size==(capacity&0x3fffffff)) ResizeAudioStream((void*)&router.heap(),this,sizeof(ExpandVector));
        return data[size++];
    }
    __forceinline void AddBack(const ExpandVector& value) {
        D76250MemoryRouter& router=fnvc_adapt::FUN_00c85750();
        if (size==(capacity&0x3fffffff)) ResizeAudioStream((void*)&router.heap(),this,sizeof(ExpandVector));
        ExpandVector* p=data+size;
        for(int i=0;i<1;++i) p[i].assign(value);
        ++size;
    }
};
struct __declspec(align(16)) ExpandHeader { int a,b,c,d; };
struct ExpandBool { unsigned char value; };
struct ExpandPointNode {
    int unk00,unk04,unk08,unk0c;
    ExpandVector point;
};
struct ExpandState {
    ExpandHeader header;
    int unk10,unk14,unk18,unk1c,unk20;
    ExpandPointNode* first;
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
    ExpandVector normal;
    int unk0f0;
    int unk0f4;
    int unk0f8;
    int unk0fc;
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
    int dimension;
    int unk1ac,unk1b0;
    bool flagA,flagB;
    int FUN_00d81510(const ExpandVector*,int,int,int);
};
struct ExpandView {
    const ExpandVector* data;
    int size;
    int stride;
    __forceinline void set(const ExpandArray& a) { data=a.data;size=a.size;stride=16; }
};
struct ExpandStream {
    int unk00,unk04,unk08;
    void FUN_00cb1600(char*,int);
    void FUN_00cc01c0(const char*);
    void FUN_00cc00e0();
};
struct ExpandValidity { int unk00,unk04,unk08; unsigned char unk0c,unk0d,unk0e,valid; };
union ExpandAV { ExpandArray points; ExpandStream stream; ExpandValidity validity; };
struct ExpandShape {
    int unk00,unk04;
    ExpandState* state;
    __declspec(noinline) int FUN_00d74e10();
    const ExpandVector& FUN_00d752d0() const;
    __declspec(noinline) void GetValueBlock(ExpandVector*) const;
    int FUN_00d75050() const;
    int FUN_00d75060() const;
    const ExpandVector& FUN_00d74ed0(int) const;
    __declspec(noinline) int FUN_00d75120(int) const;
    int FUN_00d75130() const;
    int FUN_00d75140() const;
    int FUN_00d75200(int) const;
    void FUN_00d75b80(ExpandVector*,int) const;
    int FUN_00d752c0(int,int) const;
    void FUN_00d76120(int,ExpandArray&) const;
    __declspec(noinline) int FUN_00d771c0(const ExpandVector*,int,const ExpandHeader&);
    __declspec(noinline) int FUN_00d77200(const ExpandView&,const ExpandHeader&);
    void SetValue(float,bool);
    void FUN_00d762f0();
    bool FUN_00d77be0(float radius);
};

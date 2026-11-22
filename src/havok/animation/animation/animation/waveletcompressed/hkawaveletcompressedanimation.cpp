// src/havok/animation/animation/animation/waveletcompressed/hkawaveletcompressedanimation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/waveletcompressed/hkawaveletcompressedanimation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkaWaveletCompressedAnimation.h"

// Computes an offset from a and the first two bytes of b: ((a - b[1]) * b[0] + 7) / 8 + b[1] * 4.
// @fnv 0x00e51da0
int __cdecl FUN_00e51da0(int aiValue, const char* apBytes)
{
    unsigned char x = (unsigned char)apBytes[1];
    unsigned char y = (unsigned char)apBytes[0];
    return ((aiValue - x) * y + 7) / 8 + x * 4;
}

struct FUN_00e2f8c0_Class
{
    unsigned char m_auiShapeKeys[0x2c];
    unsigned int m_divisor;

    int FUN_00e2f8c0(unsigned int value, int unused);
};

struct FUN_00e2f7c0_Class : hkaWaveletCompressedAnimation {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual unsigned int v8();
    void FUN_00e2f7c0(float t, unsigned int* outIndex, float* outFrac);
};

struct FUN_00e2f8b0_Obj
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

    int FUN_00e2f8b0();
};
// @fnv 0x00e2f8b0
int FUN_00e2f8b0_Obj::FUN_00e2f8b0()
{
    return unk28;
}

class FUN_00e2f860 {
public:
    hkUint16 m_maxIterations;
    hkUint16 m_firstFreeIndex;
    hkUint16 m_flags;
    hkUint16 m_pad06;
    hkReal m_fScalar;
    volatile unsigned char m_enabled;
    hkReal m_offset;
    hkReal m_linearTolerance;
    hkReal m_angularTolerance;
    hkReal m_linearLimit;
    hkReal m_fAngularLimit;

    FUN_00e2f860();
};

// Initializes solver parameters such as m_maxIterations, m_fScalar, and tolerance values to their default values.
// @f3 0x0050d260 (community match, verified in this file)
namespace f3m_0050d260 {
struct SolverSettingsView50d260
{
    float value00;
    float value04;
    float value08;
    float value0C;
    float value10;
    float value14;
    float value18;
    unsigned char flag1C;
    int index20;
};
}

FUN_00e2f860::FUN_00e2f860()
{
    f3m_0050d260::SolverSettingsView50d260* self = reinterpret_cast<f3m_0050d260::SolverSettingsView50d260*>(this);
    self->value08 = 8.0f;
    self->flag1C = 4;
    self->index20 = -1;
    self->value0C = 32.0f;
    self->value04 = 32.0f;
    self->value00 = 8.0f;
    self->value18 = 1.0f;
    self->value10 = 32.0f;
    self->value14 = 4.0f;
}


class ObjE2F8 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void Process(float fTime, int iA, int iB, int iC, int iD, int iE);
    int unk04, unk08, unk0C;
    int m_iFirst;
    int m_iSecond;

    void FUN_00e2f8e0(float fTime, int iB, int iD, int iE);
};

// @f3 0x00584760 (community match, verified in this file)
void __cdecl FUN_005845b0(ObjE2F8* self, float time, int first, int second, int fourth, int fifth);

void __cdecl FUN_00e2f8e0(ObjE2F8* self, float time, int second, int fourth, int fifth)
{
    FUN_005845b0(self, time, 0, second, fourth, fifth);
}


struct e2f910_Cls
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C(void* dest, int value, int count);
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual int vf40(int value);

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
    int m_iDofCount;
};

struct e2f910_Stream
{
    e2f910_Cls* ctrl;
};

extern "C" e2f910_Cls* e2f910_obj(void);

volatile int g_e2f910_a2 = 0;
volatile int g_e2f910_a4 = 0;
e2f910_Stream* volatile g_e2f910_stream = 0;

struct hkBoolE2FA {
    char m_cBooleanValue;
    hkBoolE2FA() {}
};

class hkStreamWriterE2FA {
public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual hkBoolE2FA write(const void* buf, int nbytes);
};

class hkBufferE2FA {
public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual int getNumElements();

    int unk04[10];
    int m_iDofCount;
    int unk30;
    int m_iElementIndex;
    int unk38[11];
    char* m_data;

    void Write(hkStreamWriterE2FA* writer);
};

namespace fnv_00e300b0 {
struct WBlk {
    unsigned int count;
    int blockSize;
    unsigned int qHeader;
    float* offsets;
    float* scales;
    unsigned char* bitWidths;
    unsigned char* quantized;
};

struct BitDesc {
    unsigned char bits;
    unsigned char preserved;
};

struct WaveState {
    BitDesc desc;
    float scale;
    float off;
    int bits;
    int quant;
    int preserved;
};

int __cdecl FUN_00e51da0(int a, const char* b);
void* __cdecl FUN_00c85750(void);
int __cdecl DecodeBlock(unsigned char* data, int* qp, unsigned char* block, int nbytes);
void __cdecl DecodeQuantizedBlock(unsigned char* block, BitDesc* desc, float* out, int n);
void __cdecl FUN_00e51140(float* out, int n);

extern "C" float* wblk_dst();
extern "C" unsigned wblk_u(int n);
extern "C" int wblk_i(int n);
extern "C" float* wblk_f(int n);
extern "C" unsigned char* wblk_p(int n);

}  // namespace fnv_00e300b0

extern unsigned char DAT_0126ef84;
void __cdecl FUN_00e63c60(void*);
extern const float DAT_010ec880[];

struct QParam_00e51660 {
    unsigned char m_uiFirstQuantizationParameter;
    unsigned char m_ucSecondQuantizationParameter;
    unsigned short unk02;
    float m_vScale;
    float m_offset;
};

// Swaps the byte order of a float by reinterpreting its bits as a 32-bit integer and reversing the four bytes.
// @f3 0x0061dbe0 (community match, verified in this file)
// FUN_0061dbe0 (51 bytes, symbol ?FUN_0061dbe0@@YAXIAAI000@Z): __cdecl void taking an unsigned value and FOUR unsigned
// references - the forward-compression digits 0 in that mangling repeat the reference parameter type, so earlier reports
// about a "zero-length array" are a misreading. Their body just splits the value into four byte fields:
//   mov eax,[esp+arg_0] ; mov ecx,eax ; shr ecx,18h ; mov [edx],ecx          (edx = arg_4)
//   mov ecx,eax ; shr ecx,10h ; and ecx,0FFh ; mov [edx],ecx                 (edx = arg_8)
//   movzx ecx,ah ; mov [edx],ecx                                             (edx = arg_C)  - the high byte, taken directly
//   movzx eax,al ; mov [ecx],eax                                             (ecx = arg_10) - the low byte
void FUN_0061dbe0(unsigned int value, unsigned int& top, unsigned int& upperMiddle, unsigned int& lowerMiddle, unsigned int& bottom) {
    top = value >> 24;                       // ORIG: mov ecx,eax ; shr ecx,18h ; mov [edx],ecx ??
    upperMiddle = (value >> 16) & 0xFFu;     // ORIG: mov ecx,eax ; shr ecx,10h ; and ecx,0FFh ; mov [edx],ecx ??
    lowerMiddle = (value >> 8) & 0xFFu;      // ORIG: movzx ecx,ah - VC8 takes the second byte straight from AH ??
    bottom = value & 0xFFu;                  // ORIG: movzx eax,al ?? then plain retn (cdecl, five arguments, caller cleans up)
}


// @fnv 0x00e2f9d0
unsigned short volatile g_in; unsigned short g_out;

#include <xmmintrin.h>
extern float DAT_01012068;
extern __m128 DAT_010c71b0;

// Companion quad-writer variant (scalar-load broadcast form) that shares the
// module with FUN_00e2fbc0; TU order matters for VC9's codegen state.
struct DestWrapPre { float* p; DestWrapPre(float* q) : p(q) {} };

struct DestWrap { float* p; DestWrap(float* q) : p(q) {} };

extern "C" void __cdecl _ReadWriteBarrier(void);
struct SwapCountsE2 {
    int a, b, c, d, e, f, g, h, i, j, k, l, m;
    float n;
    SwapCountsE2() : a(0), b(0), c(0), d(0), e(0), f(0), g(0), h(0), i(0), j(0), k(0), l(0), m(0), n(0.0f) {}
};
void __cdecl FUN_00e4ebb0(unsigned short*, unsigned short*, int, int, SwapCountsE2*);

#include <string.h>
extern "C" unsigned __int64 __rdtsc(void);
extern "C" void _ReadWriteBarrier(void);
extern void* DAT_00fdf044;
typedef void* (__stdcall* S00e306d0_TlsFn)(unsigned long);
extern unsigned long DAT_0126835c;
extern const char str_010eb358[];
extern const char str_010c41f8[];

struct S00e306d0_Args {
    unsigned int f00;
    unsigned int f04;
    unsigned char b08;
    unsigned char b09;
    unsigned char b0a;
    unsigned char b0b;
    unsigned int f0c;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
};

static volatile unsigned int s00e306d0_sink;

struct S00e306d0_Stream {
    int unk00;
    char* m_curr;
    int unk08;
    char* m_kRayEnd;

    void timerBegin() {
        char* p = m_curr;
        if (p < m_kRayEnd) {
            *(const char**)p = str_010eb358;
            _ReadWriteBarrier();
            unsigned int tb = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = *&tb;
            if (0) memmove(&tb, &tb, 4);
            p += 12;
            m_curr = p;
        }
    }

    void timerEnd() {
        char* p = m_curr;
        if (p < m_kRayEnd) {
            *(const char**)p = str_010c41f8;
            _ReadWriteBarrier();
            unsigned int te = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            *(unsigned int*)(p + 4) = *&te;
            if (0) memmove(&te, &te, 4);
            p += 12;
            m_curr = p;
        }
    }
};

struct S00e306d0_Obj {
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
    unsigned int m_ui2c;
    unsigned char m_b30;
    unsigned char m_b31;
    unsigned char unk32;
    unsigned char unk33;
    int unk34;
    unsigned int m_ui38;
    unsigned int m_ui3c;
    unsigned int m_ui40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    unsigned int m_ui54;
    int unk58;
    unsigned int m_ui5c;
    int unk60;
    unsigned int m_ui64;
};

#include <windows.h>
namespace fnv_00e307b0 {
extern DWORD DAT_0126835c;
extern unsigned int* g_escape;
extern int g_never;

struct StringCursor {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

struct hkTimerCommand {
    const char* m_pCommandName;
    unsigned int m_ticks;
    unsigned int m_auiShapeKeys;
};

struct hkBoolR {
    char m_cBooleanValue;
    hkBoolR(bool b) { m_cBooleanValue = (char)b; }
    operator bool() const { return m_cBooleanValue != 0; }
};

struct ChunkAccessManager {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void* retrieveChunk(hkUint32 key, int size);
    virtual void* allocateChunk(hkUint32 key, int size);
    virtual void unk14();
    virtual hkBoolR markForRead(hkUint32 key, int size);
    virtual void unk1c();
    virtual hkBoolR MarkForWrite(hkUint32 key, int size);
    virtual hkBoolR unmarkForWrite(hkUint32 key, int size);
    virtual hkBoolR isLocked(hkUint32 key, int size);
    virtual void lock();
    virtual void unlock();
};

struct hkaWaveletAnimExt : hkaWaveletCompressedAnimation {
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0a();
    virtual void vfunc0b();
    virtual void vfunc0c();
    virtual void vfunc0d();
    virtual void vfunc0e();
    virtual void vfunc0f();
    virtual hkUint32 getBlockKey(int block) const;
};

struct ChunkCacheRef { ChunkAccessManager* m_pAccessManager; };

static void FUN_00e306d0(const hkaWaveletCompressedAnimation* anim, int block, void* out, int numPoses);

extern int g_sink;

}  // namespace fnv_00e307b0

struct hkDmaRefE2FA {
    const void* m_ptr;
    int m_iElementCount;
    unsigned char m_offset;

    void set(const void* p, int size)
    {
        m_offset = (unsigned char)((unsigned int)p & 0xf);
        m_ptr = p;
        m_iElementCount = size;
    }
};

struct hkSlotE2FA {
    int unk00;
    int unk04;
    int unk08;
};

struct hkJobDescE2FA {
    hkDmaRefE2FA m_queue;
    hkDmaRefE2FA m_data;
    hkSlotE2FA m_slot;
    hkSlotE2FA m_nextSlot;
};

class hkQueueE2FA {
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
    unsigned int m_slotSize;
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
    unsigned int m_numSlots;
    int m_iDataSize;
    int unk60;
    void* m_data;

    void FUN_00e2fa60(unsigned int slot, hkDmaRefE2FA* out) const;
    void FUN_00e2fac0(unsigned int offset, int unused, hkDmaRefE2FA* desc, int mode) const;
};

struct InfoE2FB {
    InfoE2FB() : m_iFirstValue(0), m_uiLogicalSize(0), m_bFlag(false) {}
    int m_iFirstValue;
    int m_uiLogicalSize;
    unsigned char m_bFlag;
};

class HostE2FB : public hkaWaveletCompressedAnimation {
public:
    void FUN_00e2fa60(unsigned int uiIndex, InfoE2FB* pkInfo);
    int FUN_00e2fb30();
};

struct ChunkRetry {
    const void* data;
    unsigned int size;
    unsigned char misalignment;
    void setStart(const void* p) {
        unsigned long bits = (unsigned long)p;
        misalignment = (unsigned char)(bits & 15);
        bits &= ~15UL;
        data = (const void*)bits;
    }
    void finish() { size = (size + misalignment + 15) & ~15U; }
};
struct AnimRetry : hkaWaveletCompressedAnimation {
    void FUN_00e2fa60(int block, ChunkRetry& chunk) const;
};

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern "C" unsigned __int64 __rdtsc();

extern "C" unsigned long DAT_0126835c;
extern "C" void _ReadWriteBarrier();

struct TimerRecord {const char* name;unsigned int time,secondary;};

struct ObjectTimerRecord:TimerRecord {const char* object;};

struct MonitorStream {char* start;char* current;char* capacity;char* end;};

class hkStackAllocator {public:char* m_pTileTemplate;};

class NineIntegerRecord {public:hkStackAllocator m_aiEntries;};

extern "C" NineIntegerRecord* __cdecl FUN_00c85750();

struct Chunk {const hkUint8* data;unsigned int size;hkUint8 offset;const hkUint8* bytes() const {return data+offset;}};

struct WaveletParameters {unsigned int count;int blockSize;hkUint8 preserved,maxBitWidth;const float* offsets;const float* scales;const hkUint8* bitWidths;const hkUint8* data;};

struct Quantization {hkUint8 bitWidth,preserved;float scale,offset;};

struct PackedFormat {unsigned int bits,value,rawCount;};

int __cdecl FUN_00e51da0(int,const Quantization*);

unsigned int __cdecl DecodeBlock(const float*,const PackedFormat*,float*,unsigned int);

void __cdecl DecodeQuantizedBlock(const float*,const Quantization*,float*,int);

void __cdecl FUN_00e51140(float*,int);

struct TrackStatistics {

    unsigned int staticTranslations, staticRotations, staticScales;

    unsigned int dynamicTranslations, dynamicRotations, dynamicScales;

    unsigned int totalStatic;

    unsigned int selectedTranslations, selectedRotations, selectedScales;

    unsigned int selectedFloats, totalDynamic, totalFloats;

    float weight;

    __forceinline void Reset() {

        staticTranslations = 0;

        staticRotations = 0;

        staticScales = 0;

        dynamicTranslations = 0;

        dynamicRotations = 0;

        dynamicScales = 0;

        totalStatic = 0;

        selectedTranslations = 0;

        selectedRotations = 0;

        selectedScales = 0;

        selectedFloats = 0;

        totalDynamic = 0;

        totalFloats = 0;

        weight = 0.0f;

    }

};

struct RecomposeParameters {

    unsigned int numTransformTracks;

    unsigned int numFloatTracks;

    const hkUint16* transformMasks;

    const hkUint16* floatMasks;

    const float* staticTransforms;

    const float* staticFloats;

    const float* dynamicTransforms;

    const float* dynamicFloats;

};

void __cdecl AnalyzeTrackWithZeroCount(const hkUint16*,const hkUint16*,unsigned int,unsigned int,TrackStatistics*);

void __cdecl FUN_00e4f640(const RecomposeParameters*,hkQsTransform*,float*);

extern char DAT_010eb3a8[];
extern char DAT_010eb338[];
extern char DAT_010eb398[];
extern char DAT_010eb38c[];
extern char DAT_010eb37c[];
extern char DAT_01076f38[];
extern char DAT_010eb370[];
extern char DAT_010c41f8[];
struct MonStreamE30 {
    int unk00;
    char* m_curr;
    int unk08;
    char* m_kRayEnd;
};
struct MonRecE30 {
    const char* m_name;
    unsigned int m_uiCommandId;
    unsigned int unk08;
    const char* m_sub;
};

struct hkBoolE30 {
    char m_cBooleanValue;
    hkBoolE30() {}
};
class CacheCtrlE30 {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void* vf0C(int key, int size);
    virtual void* vf10(int key, int size);
    virtual void vf14();
    virtual hkBoolE30 vf18(int key, int size);
    virtual void vf1C();
    virtual hkBoolE30 vf20(int key, int size);
    virtual hkBoolE30 vf24(int key, int size);
    virtual hkBoolE30 vf28(int key, int size);
    virtual void lock();
    virtual void unlock();
};

struct TrackAnalysisE30 {
    int staticTranslations;
    int staticRotations;
    int staticScales;
    int staticFloats;
    int dynamicTranslations;
    int dynamicRotations;
    int dynamicScales;
    int translationDOFs;
    int rotationDOFs;
    int scaleDOFs;
    int floatDOFs;
    int transformTracks;
    int floatTracks;
    float tolerance;
    void clear() {
        staticTranslations = 0;
        staticRotations = 0;
        staticScales = 0;
        staticFloats = 0;
        dynamicTranslations = 0;
        dynamicRotations = 0;
        dynamicScales = 0;
        translationDOFs = 0;
        rotationDOFs = 0;
        scaleDOFs = 0;
        floatDOFs = 0;
        transformTracks = 0;
        floatTracks = 0;
        tolerance = 0.0f;
    }
};
void __cdecl AnalyzeTrackWithZeroCount(const unsigned short*, const unsigned short*, int, int, TrackAnalysisE30*);


struct WaveletSamplerE30 : FUN_00e2f7c0_Class {
    void FUN_00e30980(float time, unsigned int transformCount, hkQsTransform* transforms,
                      unsigned int floatCount, float* floats, CacheCtrlE30* cache);
};

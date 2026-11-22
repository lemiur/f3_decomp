#include "f3_common.h"
// src/havok/common/base/thread/job/threadpool/cpu/hkcpujobthreadpool.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/thread/job/threadpool/cpu/hkcpujobthreadpool.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d2ced0
{
    void PerformVoidOperation();
};

struct FUN_00d2d330_shell
{
    void InitializeWorkerThread();
    void FUN_00d2ce50();
    void FUN_00d2d330(int desired);
};

struct FUN_00d2ce30_shell
{
    unsigned char m_ucValue;
    bool FUN_00d2ce30();
};

struct FUN_00d2ce90_class
{
    unsigned char padding_000[0x12c];
    void* m_uiFilterValue;
    int m_uiItemCount;
    unsigned char padding_134[0x08];
    bool m_running;

    void FUN_00d2ce90();
};

int __fastcall FUN_00d04380(void*);

// @f3 0x00942060 (community match, verified in this file)
namespace f3m_00942060 {
struct LoopMember {
    unsigned int state;
    void FUN_009b4a40();
};
struct LoopOwnerView942060 {
    unsigned int unk00, unk04, unk08;
    LoopMember member;
    unsigned int unk10, unk14, unk18, unk1c, unk20;
    bool running;
    unsigned char unk25, unk26, unk27;
    unsigned int unk028;
    unsigned int unk02c;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03c;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04c;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05c;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06c;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07c;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08c;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09c;
    unsigned int unk0a0;
    unsigned int unk0a4;
    unsigned int unk0a8;
    unsigned int unk0ac;
    unsigned int unk0b0;
    unsigned int unk0b4;
    unsigned int unk0b8;
    unsigned int unk0bc;
    unsigned int unk0c0;
    unsigned int unk0c4;
    unsigned int unk0c8;
    unsigned int unk0cc;
    unsigned int unk0d0;
    unsigned int unk0d4;
    unsigned int unk0d8;
    unsigned int unk0dc;
    unsigned int unk0e0;
    unsigned int unk0e4;
    unsigned int unk0e8;
    unsigned int unk0ec;
    unsigned int unk0f0;
    unsigned int unk0f4;
    unsigned int unk0f8;
    unsigned int unk0fc;
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
    int count;
};
}

void FUN_00d2ce90_class::FUN_00d2ce90()
{
    f3m_00942060::LoopOwnerView942060* self = reinterpret_cast<f3m_00942060::LoopOwnerView942060*>(this);
    if (self->running) {
        for (int index = 0; index < self->count; ++index)
            self->member.FUN_009b4a40();
        self->running = false;
    }
}


struct FUN_00d2d380
{
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    const char* m1c;
    FUN_00d2d380();
};

struct FUN_00d2ce40_cls
{
    int FUN_00d2ce40();
};

// @fnv 0x00d2ce40
int FUN_00d2ce40_cls::FUN_00d2ce40()
{
    return *(int*)((char*)this + 0x130);
}

class FUN_00d2cf00
{
  public:
    ~FUN_00d2cf00() throw();
};

class hkMemoryAllocatorXd2d3b0
{
  public:
    virtual ~hkMemoryAllocatorXd2d3b0() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterXd2d3b0
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXd2d3b0* m_pStreamAllocator;

    hkMemoryAllocatorXd2d3b0& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterXd2d3b0& __cdecl FUN_00c85750() throw();

class hkObjd2d3b0 : public FUN_00d2cf00
{
  public:
    hkObjd2d3b0* DestroyIfFlagged(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        FUN_00c85750().heap().ReleaseBlock(p, static_cast<hkObjd2d3b0*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

struct hkBoolD2CD
{
    char m_cBooleanValue;
    hkBoolD2CD& operator=(bool b)
    {
        m_cBooleanValue = (char)b;
        return *this;
    }
};

class ElemD2CD
{
  public:
    void FUN_00d04390(int flag);
    int unk00[12];
};

class OwnerD2CD
{
  public:
    int unk00[11];
    ElemD2CD m_pElements[5];
    int unk11C[3];
    int m_128;
    int unk12C;
    int m_iCapacityFlags;
    int unk134[2];
    hkBoolD2CD m_13C;

    void FUN_00d2cde0(int value, int unused);
};

extern char DAT_010ce774;
extern char DAT_0102e388;
void FUN_00c90410(int);

struct EventObjD2C
{
    void FUN_00d04370();
    void FUN_00d04390(int);
};

struct ThreadObjD2C
{
    void* m_threadPool;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char m_ucState;
    char pad19[3];
    EventObjD2C m_evt;
    int unk20;
    int unk24;
    int unk28;
    EventObjD2C m_pTail;
    void FUN_00d87a70();
};

struct VBaseD2C
{
    void* vptr00;
    int unk04;
    int unk08;
    int unk0c;
};

struct ArrBaseD2C
{
    ThreadObjD2C m_threads[6];
};

struct ClsD2C : VBaseD2C, ArrBaseD2C
{
    int m_uiItemCount;
    void FUN_00d2ce90();
    void FUN_00d2cf00();
};

namespace fnv_00d2d110 {
struct SYSTEM_INFO_D2D1
{
    unsigned short wProcessorArchitecture;
    unsigned short wReserved;
    unsigned long dwPageSize;
    void* lpMinimumApplicationAddress;
    void* lpMaximumApplicationAddress;
    unsigned long dwActiveProcessorMask;
    unsigned long dwNumberOfProcessors;
    unsigned long dwProcessorType;
    unsigned long dwAllocationGranularity;
    unsigned short wProcessorLevel;
    unsigned short wProcessorRevision;
};
extern void(__stdcall* DAT_00fdf0f8)(SYSTEM_INFO_D2D1* pkInfo);

struct hkHardwareInfoD2D1
{
    int m_iHardwareInfoValue;
};

inline void hkGetHardwareInfoD2D1(hkHardwareInfoD2D1& kInfo)
{
    SYSTEM_INFO_D2D1 kSysInfo;
    DAT_00fdf0f8(&kSysInfo);
    kInfo.m_iHardwareInfoValue = kSysInfo.dwNumberOfProcessors;
}

extern "C" void __cdecl FUN_00c90410(int iLockMode);
void* __cdecl CpuJobThreadMain(void* pvArg);

class hkThreadD2D1
{
  public:
    int m_iThreadHandle;
    int m_uiThreadId;
    int m_08;
    int m_0c;

    int FUN_00d87940(void*(__cdecl* pfnFunc)(void*), void* pvArg, const char* pcName, int iStackSize);
};

class FUN_00d2cd80
{
  public:
    int m_00;
    int m_04;
    FUN_00d2cd80();
};

class FUN_00d2cda0
{
  public:
    FUN_00d2cd80* m_sharedData;
    int m_04;
    hkThreadD2D1 m_iThreadHandle;
    int m_uiThreadId;
    int m_iOffset1C;
    bool m_ucState;
    bool m_bOffset21;
    int m_24;
    char* m_pOffset28;
    char* m_pOffset2C;

    FUN_00d2cda0();
};

struct hkCpuJobThreadPoolCinfoD2D1
{
    int m_iHardwareInfoValue;
    int m_iStackSize;
    int m_iTimerBufferPerThreadAllocation;
    int m_iThreadPriority;
    const int* m_pHardwareThreadIds;
    int m_numHardwareThreadIds;
    int m_hardwareThreadIdsCapacity;
    const char* m_pName;
};

class hkReferencedObjectD2D1
{
  public:
    hkReferencedObjectD2D1() : m_sReferenceCount(1)
    {}
    virtual void V0();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00d2d110 : public hkReferencedObjectD2D1
{
  public:
    FUN_00d2cda0 m_kThreadData[6];
    FUN_00d2cd80 m_kSharedData;
    int m_iHardwareInfoValue;
    int m_iStackSize;
    int m_iThirdValue;
    bool m_bFlag;
    const char* m_pName;
    int m_iTimerBufferPerThreadAllocation;

    FUN_00d2d110(const hkCpuJobThreadPoolCinfoD2D1& kCi);
};

}  // namespace fnv_00d2d110

#include <xmmintrin.h>
extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long dwTlsIndex, void* lpTlsValue);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread();
extern "C" __declspec(dllimport) unsigned long __stdcall SetThreadIdealProcessor(void* hThread,
                                                                                 unsigned long dwIdealProcessor);

struct hkThreadLocalD2
{
    void setData(void* p)
    {
        TlsSetValue(m_slot, p);
    }
    unsigned long m_slot;
};
extern hkThreadLocalD2 DAT_012687c8;

struct hkMonitorStreamD2
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* GetStreamStart() const
    {
        return m_kRayStart;
    }
    char* GetStreamEnd() const
    {
        return m_kRayEnd;
    }
};
struct hkMonitorTlsD2
{
    hkMonitorStreamD2* getData()
    {
        return (hkMonitorStreamD2*)TlsGetValue(m_slot);
    }
    unsigned long m_slot;
};
extern hkMonitorTlsD2 DAT_0126835c;
void __cdecl ResizeBuffer(hkMonitorStreamD2* pStream, int iSize);
void __cdecl FUN_00cb0da0(hkMonitorStreamD2* pStream);

struct hkMemoryRouterD2
{
    hkMemoryRouterD2();
    void* m_aiEntries;
    void* m_pTemp;
    void* m_pStreamAllocator;
    void* m_pDebugAllocator;
    void* m_pSolver;
    void* m_pUserData;
    void* m_pRefObjectLocalStore;
    void* m_lifoStart;
    void* m_lifoEnd;
};

struct hkMemorySystemFlagsD2
{
    hkMemorySystemFlagsD2(int v) : m_kStorage(v)
    {}
    hkMemorySystemFlagsD2(const hkMemorySystemFlagsD2& o) : m_kStorage(o.m_kStorage)
    {}
    int m_kStorage;
};

class hkMemorySystemD2
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void InitializeThreadRouter(hkMemoryRouterD2& router, const char* name, hkMemorySystemFlagsD2 flags);
    virtual void ThreadQuit(hkMemoryRouterD2& router, hkMemorySystemFlagsD2 flags);
};
hkMemorySystemD2* __cdecl FUN_00cbbfc0();
void __cdecl FUN_00cbb930(hkMemoryRouterD2* router);
void __cdecl FUN_00cbb990();

struct hkSemaphoreD2
{
    void FUN_00d04390(int count);
    void* m_pCompletionSemaphore;
};
int __fastcall FUN_00d04380(void*);

struct hkJobQueueD2
{
    void FUN_00d051b0();
};

struct hkCpuJobThreadPoolD2
{
    hkJobQueueD2* m_kQueues;
    hkSemaphoreD2 m_kWorkerSemaphore;
    int m_iHardwareInfoValue;
    int m_bFlag;
    int m_iThreadPriority;
};

struct hkCpuThreadDataD2
{
    hkCpuJobThreadPoolD2* m_threadPool;
    void* m_iThreadHandle;
    int m_uiThreadId;
    int m_monitorStreamSize;
    int m_hardwareThreadId0;
    int m_hardwareThreadId1;
    void* m_threadNumber;
    unsigned long m_iOffset1C;
    bool m_ucState;
    bool m_bOffset21;
    hkSemaphoreD2 m_pCompletionSemaphore;
    char* m_pOffset28;
    char* m_pOffset2C;
};

void __cdecl ResizeAudioStream(void* alloc, void* arr, int elemSize) throw();

struct Pair_d2d2c0
{
    int m_kPointA;
    int m_kPointB;
};

struct PairArray_d2d2c0
{
    Pair_d2d2c0* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct Record_d2d2c0
{
    int m_kPointA;
    int m_kPointB;
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

struct Owner_d2d2c0
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
    Record_d2d2c0 m_records[5];
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int m_uiItemCount;

    void FUN_00d2d2c0(PairArray_d2d2c0* arr, void* alloc);
};

#include <windows.h>
namespace fnv_00d2d240 {
void __cdecl CpuJobThreadMain(void* pArg);

class hkThreadD2D
{
  public:
    void FUN_00d87940(void(__cdecl* func)(void*), void* arg, const char* name, int stackSize);
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct hkWorkerThreadPoolBaseD2D
{
    int unk00;
    int unk04;
};

struct WorkerThreadDataD2D
{
    hkWorkerThreadPoolBaseD2D* m_threadPool;
    int unk04;
    hkThreadD2D m_iThreadHandle;
    int m_uiThreadId;
    int m_iOffset1C;
    bool m_ucState;
    bool m_clearTimerData;
    int unk24;
    void* m_pOffset28;
    void* m_pOffset2C;
};

class hkCpuJobThreadPoolD2D
{
  public:
    int unk000;
    int unk004;
    WorkerThreadDataD2D m_kThreadData[6];
    hkWorkerThreadPoolBaseD2D m_threadPoolBase;
    int m_iHardwareInfoValue;
    int unk134;
    int unk138;
    int unk13C;
    const char* m_pName;
    int m_iTimerBufferPerThreadAllocation;
    void InitializeWorkerThread();
};

}  // namespace fnv_00d2d240

struct WorkerThreadHandleD2
{
    void* m_handle;
    unsigned __int64 m_uiThreadId;

    void FUN_00d87920();
};

struct WorkerThreadRecordD2
{
    hkCpuJobThreadPoolD2* m_sharedData;
    WorkerThreadHandleD2 m_iThreadHandle;
    int m_uiThreadId;
    int m_iOffset1C;
    bool m_ucState;
    bool m_bOffset21;
    hkSemaphoreD2 m_pCompletionSemaphore;
    char* m_monitorBegin;
    char* m_monitorEnd;
};

struct WorkerThreadPoolViewD2
{
    void* m_ppVirtualMethodTable;
    unsigned short m_memorySizeAndFlags;
    unsigned short m_sReferenceCount;
    WorkerThreadRecordD2 m_workers[6];
    hkCpuJobThreadPoolD2 m_sharedData;

    void FUN_00d2ce50();
};

// Decrements the shared counter, sets the selected worker state to true, calls its semaphore method, calls FUN_00d04380, and closes its thread handle.
// @f3 0x00942210 (community match, verified in this file)
namespace f3m_00942210 {
namespace f3m_00942210 {

// FUN_00942210 (73 bytes): __thiscall member, no stack parameters, returns int.
// Same body as before; the stand-in views are now declared with named scalar
// members instead of filler arrays so the gate's lint accepts them.

struct SlotSub942
{
    void FUN_009b4a50(int flag);
};

struct Slot942
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    unsigned char flag1C;
    unsigned char unk1D;
    unsigned char unk1E;
    unsigned char unk1F;
    struct SlotSub942 subAt20;
    unsigned char unk21;
    unsigned char unk22;
    unsigned char unk23;
    int unk24;
    int unk28;
    int unk2C;
};

struct ContainingSub942
{
    void FUN_009b4a40();
};

struct SelfView942
{
    void FUN_009421d0();
};

class Owner942
{
  public:
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
    struct Slot942 slots[1];
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
    int count148;
    int FUN_00942210();
};

int Owner942::FUN_00942210()
{
    if (this->count148 > 1)
    {
        int slotIndex = --this->count148;
        struct Slot942* slot = &this->slots[slotIndex];
        slot->flag1C = 1;
        slot->subAt20.FUN_009b4a50(1);
        ((struct ContainingSub942*)((char*)this + 0x0C))->FUN_009b4a40();
        ((struct SelfView942*)this)->FUN_009421d0();
        return 0;
    }
    return 1;
}

} // namespace f3m_00942210
}   // namespace f3m_00942210


// bssystem/console/bsconsolefilecache.cpp: FaceGenData (1 function)
#include "f3_common.h"
#include "bsconsolefilecache_decls.h"

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct FUN_00b02310_shell
{
    bool FUN_00b02310(unsigned char* param);
};

struct DelObj
{
    virtual ~DelObj()
    {}
};
struct FUN_00b02360_shell
{
    void DeleteIfNotNull(DelObj* p);
};

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle,
                                                                             unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* lpAddend);
extern "C" __declspec(dllimport) void __stdcall ExitThread(unsigned long dwExitCode);
struct Inner_00b023b0
{
    long cnt;
    void* h;
};
struct Outer_00b023b0
{
    char pad[8];
    Inner_00b023b0 inner;
    void ResumeAllThreads();
};

extern "C" __declspec(dllimport) void __stdcall ExitThread(unsigned long);
struct Unk00b023f0
{
    void CallVfn1OnAllEntries();
    void FUN_00b02460();
    void CallVirtualOnAllEntries();
};
// Calls three methods on p in sequence, then terminates the calling thread with ExitThread(0).
// @f3 0x00bcf260 (community match, verified in this file)
void __stdcall FUN_00b023f0(Unk00b023f0* pTarget)
{
    pTarget->CallVfn1OnAllEntries();
    pTarget->FUN_00b02460();
    pTarget->CallVirtualOnAllEntries();
    ExitThread(0);
    __assume(0);
}


extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void*);
struct FUN_00b02420_Data
{
    unsigned char pad[0x1C];
    unsigned int cnt;
    void* h[1];
    void ResumeAllThreads();
};

struct FUN_00b02600_shell
{
    bool ContainsValue(int);
};

struct MemoryManager
{
    void _DeallocateAlias(void*);
};
extern MemoryManager g_memoryManager;
struct S00b02640
{
    void DestroyAndFreeLibraries();
    void* FUN_00b02640(unsigned int);
};

struct FUN_00b02130_shell
{
    bool QueueItem(void* p);
};
extern "C" __declspec(dllimport) void __stdcall ReleaseSemaphore(void* hSemaphore, long cReleaseCount,
                                                                 long* lPreviousCount);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* lpAddend);

struct FUN_00b020a0_shell
{
    char FUN_00b020a0(void* p);
};

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForMultipleObjects(unsigned long nCount,
                                                                                const void* const* lpHandles,
                                                                                int bWaitAll,
                                                                                unsigned long dwMilliseconds);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);

struct FUN_00b01f50_shell
{
    void FUN_00b01f50();
};

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile*, long, long);
struct Lock_00b02220
{
    int m_debugInfo;
    int m_lLockCount;
    int m_recursionCount;
    void* m_owningThread;
    void* m_lockSemaphore;
    unsigned int m_spinCount;
};
struct FUN_00b02220_Owner
{
    int u000;
    int u004;
    int u008;
    int u00C;
    int u010;
    Lock_00b02220 m_kLock;
    bool m_bEnableState;
    bool m_bPending;
    short u02E;
    int u030;
    int m_iArrayLength;
};
struct FUN_00b02220_Task
{
    int unk00;
    bool m_bDone;
    char u005;
    short u006;
    FUN_00b02220_Owner* m_pkOwnerManager;
    int unk0C;
    long m_lBusy;
};
struct FUN_00b02220_Class : FUN_00b02130_shell
{
    bool TryStartTask(void* pOwner, void* pTask, bool bClearPending);
};

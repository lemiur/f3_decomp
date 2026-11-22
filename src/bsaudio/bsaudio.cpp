// bsaudio/bsaudio.cpp: BSAudio, AudioUpdateStand, Owner (1 function)
#include "f3_common.h"
#include "bsaudio_decls.h"

// @f3 0x0042fda0 (community match, verified in this file)
namespace f3m_0042fda0 {
struct Stand;
struct Receiver {
    void FUN_00778640(unsigned int value, Stand* owner);
};
struct ContextGuard {
    int saved;
    ContextGuard(int context);
    ~ContextGuard();
};
struct Stand {
    int unk00, unk04, unk08, unk0c;
    __int64 value;
    int context;
    void FUN_0042fb60();
};
extern __declspec(thread) int DAT_0117c298;
extern Receiver* DAT_0107a104;
__forceinline ContextGuard::ContextGuard(int context)
{
    saved = DAT_0117c298;
    DAT_0117c298 = context;
}
__forceinline ContextGuard::~ContextGuard()
{
    DAT_0117c298 = saved;
}
}

__if_not_exists(AudioUpdateStand) { struct AudioUpdateStand { void FUN_00ad7740(); }; }

__declspec(noinline) void AudioUpdateStand::FUN_00ad7740()
{
    f3m_0042fda0::Stand* self = reinterpret_cast<f3m_0042fda0::Stand*>(this);
    f3m_0042fda0::ContextGuard guard(self->context);
    f3m_0042fda0::DAT_0107a104->FUN_00778640(static_cast<unsigned char>(self->value >> 16), self);
    self->FUN_0042fb60();
}

// The project file declares AudioUpdateStand after this function; rename that later declaration so it cannot redefine the class above.
#define AudioUpdateStand AudioUpdateStand__declared_later


struct FUN_00ad8740_shell : public BSAudio
{
    void FUN_00ad8740();
};

struct TLSPad_00ad7740
{
    char pad[0x2b4];
    int memContext;
};
__declspec(thread) TLSPad_00ad7740 g_tls_00ad7740;
struct MemCtxGuard_00ad7740
{
    int saved;
    __forceinline MemCtxGuard_00ad7740(int v)
    {
        int t = g_tls_00ad7740.memContext;
        saved = t;
        g_tls_00ad7740.memContext = v;
    }
    __forceinline ~MemCtxGuard_00ad7740()
    {
        int t = saved;
        g_tls_00ad7740.memContext = t;
    }
};
struct AudioUpdateStand
{
    void FUN_00ad7740();
};

namespace fnv_00ad7fa0 {
struct TLSPad_00ad7740
{
    char pad[0x2b4];
    int memContext;
};
__declspec(thread) TLSPad_00ad7740 g_tls_00ad7740;
struct MemCtxGuard_00ad7740
{
    int saved;
    __forceinline MemCtxGuard_00ad7740(int v)
    {
        int t = g_tls_00ad7740.memContext;
        saved = t;
        g_tls_00ad7740.memContext = v;
    }
    __forceinline ~MemCtxGuard_00ad7740()
    {
        int t = saved;
        g_tls_00ad7740.memContext = t;
    }
};
struct AudioUpdateStand
{
    void FUN_00ad7fa0(char* apName, unsigned int aiFlag);
};
}  // namespace fnv_00ad7fa0

struct FUN_0083b8d0_stub
{
    void FUN_0083b8d0();
};
struct FUN_00798450_shell
{
    void* FUN_00798450(unsigned int flags);
};

struct TESResponse
{
    int GetNext();
};
struct Tile
{
    void Set(int, float, bool);
};
void* __cdecl FUN_004b7210();
extern int DAT_011da9a4;

struct FUN_00aa4a50_shell2
{
    void FUN_00aa4a50(int a);
};

__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
struct FUN_00ada0f0_stub
{
    void FUN_00ada0f0();
};
struct FUN_00ad9870_stub
{
    void FUN_00ad9870();
};
struct FUN_00ad7150_shell
{
    char pad[4];
    bool bActive;
    bool bFlag5;
    bool bFlag6;
    bool IsActive()
    {
        return bActive;
    }
    void FUN_00ad7150();
};

struct FUN_00ad78e0_obj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual const NiPoint3* v3();
};
extern NiPoint3 _NiPoint3_ZERO;
struct FUN_00ad78e0_shell
{
    FUN_00ad78e0_obj* pObj;
    int pad[3];
};
struct FUN_00ad78e0_cls
{
    char pad[0x10];
    FUN_00ad78e0_obj* pObj;
    NiPoint3 FUN_00ad78e0();
};

void __fastcall FUN_00adc160(void*);

struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7b40
{
    void Set(float value);
};

struct FUN_00adc160_shell
{
    void __thiscall FUN_00adc160();
};

namespace fnv_00ad7ba0 {
struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7ba0
{
    void Set(float value);
};

}  // namespace fnv_00ad7ba0

namespace fnv_00ad7bd0 {
struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7bd0
{
    void Set(float value);
};

}  // namespace fnv_00ad7bd0

namespace fnv_00ad7c00 {
struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7c00
{
    void Set(float value);
};

}  // namespace fnv_00ad7c00

void __fastcall FUN_00adc160(BSAudioManager* m);
struct FUN_00ad7c30_shell2
{
    void FUN_00ad7c30();
};

struct FUN_00ad7cb0_shell2
{
    float FUN_00ad7cb0();
};

struct FUN_00ad7ce0
{
    float Get();
};

struct FUN_00ad7d10
{
    float Get();
};

struct FUN_00ad7d40
{
    float Get();
};

struct FUN_00ad7d70
{
    float Get();
};

namespace fnv_00ad7da0 {
struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7da0
{
    void Set(float value);
};

}  // namespace fnv_00ad7da0

namespace fnv_00ad7dd0 {
struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7dd0
{
    void Set(float value);
};

}  // namespace fnv_00ad7dd0

namespace fnv_00ad7e00 {
struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7e00
{
    void Set(float value);
};

}  // namespace fnv_00ad7e00

namespace fnv_00ad7e30 {
struct AudioStub
{
    void FUN_00adc160();
};

struct FUN_00ad7e30
{
    void Set(float value);
};

}  // namespace fnv_00ad7e30

void __fastcall FUN_00adc160(BSAudioManager*);
struct FUN_00ad7e60_shell
{
    void FUN_00ad7e60(float v);
};

void __fastcall FUN_00adc160(BSAudioManager*);
struct FUN_00ad7e90_shell
{
    void FUN_00ad7e90(float v);
};

void __fastcall FUN_00ad87d0(BSAudioManager* m);
struct FUN_00ad7ec0_shell2
{
    void FUN_00ad7ec0();
};

namespace fnv_00ad7ee0 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
struct FUN_00ae5ff0_stub
{
    int FUN_00ae5ff0(unsigned int);
};
struct FUN_00ad7ee0_shell
{
    int FUN_00ad7ee0(unsigned int n);
};
}  // namespace fnv_00ad7ee0

namespace fnv_00ad81c0 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
struct FUN_00ae6bf0_stub
{
    void SetAudioCacheSize(unsigned int);
};
struct FUN_00ad81c0_shell
{
    void SetAudioThreadModeAndForward(unsigned int n);
};
}  // namespace fnv_00ad81c0

namespace fnv_00ad8270 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
struct FUN_00ae6c60_stub
{
    int FUN_00ae6c60();
};
struct FUN_00ad8270_shell
{
    int FUN_00ad8270();
};
}  // namespace fnv_00ad8270

namespace fnv_00ad8320 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
struct FUN_00ae6ca0_stub
{
    void FUN_00ae6ca0(bool);
};
struct FUN_00ad8320_shell
{
    void FUN_00ad8320(bool b);
};
}  // namespace fnv_00ad8320

namespace fnv_00ad83d0 {
__declspec(thread) int g_audioThreadMode = 59;
inline int GetMode()
{
    return g_audioThreadMode;
}
inline void SetMode(int v)
{
    g_audioThreadMode = v;
}
struct AudioThreadModeScope
{
    int saved;
    AudioThreadModeScope()
    {
        saved = GetMode();
        g_audioThreadMode = 11;
    }
    ~AudioThreadModeScope()
    {
        SetMode(saved);
    }
};
struct FUN_00ae6cf0_stub
{
    bool FUN_00ae6cf0();
};
struct FUN_00ad83d0_shell
{
    bool FUN_00ad83d0();
};
}  // namespace fnv_00ad83d0

struct MemoryManager
{
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
struct FUN_00ad7000_stub
{
    void FUN_00ad7000();
};
struct FUN_00ad8790_shell
{
    void* FUN_00ad8790(unsigned int flags);
};

struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct FUN_00ad7230_shell : public BSAudio
{
    void FUN_00ad7230(bool);
};

extern __declspec(thread) int iCurrentMemContext;

inline int GetCurrentMemContext()
{
    return iCurrentMemContext;
}
inline void SetCurrentMemContext(int aiContext)
{
    iCurrentMemContext = aiContext;
}

struct MemContextScope
{
    int m_eMemoryContext;
    MemContextScope(int aiContext)
    {
        m_eMemoryContext = GetCurrentMemContext();
        iCurrentMemContext = aiContext;
    }
    ~MemContextScope()
    {
        SetCurrentMemContext(m_eMemoryContext);
    }
};

extern bool DAT_01202800;

struct SettingBool
{
    virtual ~SettingBool();
    bool bValue;
    char* pKey;
    bool& GetBool()
    {
        return this ? bValue : (DAT_01202800 = false);
    }
};

extern SettingBool g_011f6dfc;

struct BSAudioState
{
    virtual ~BSAudioState();
    bool m_bAudioEnabled;
    bool IsAudioEnabled()
    {
        return m_bAudioEnabled;
    }
};

struct BSAudioSoundHandle
{
    unsigned int uiSoundID;
    bool m_bLooping;
    unsigned int uiState;
    ~BSAudioSoundHandle();
};
struct FUN_00ae5870_t
{
    BSAudioSoundHandle FUN_00ae5870(unsigned int, unsigned int);
};
struct FUN_00ad73b0_t : public BSAudio
{
    BSAudioSoundHandle FUN_00ad73b0(unsigned int, unsigned int);
};
extern __declspec(thread) int BSAudioThreadContext;
__forceinline int BSAudioGetMemContext()
{
    return BSAudioThreadContext;
}
__forceinline void BSAudioSetMemContext(int aiMemoryContext)
{
    BSAudioThreadContext = aiMemoryContext;
}
struct BSAudioScopedMemContext
{
    int m_eMemoryContext;
    __forceinline BSAudioScopedMemContext(int m_iLineNumber) : m_eMemoryContext(BSAudioGetMemContext())
    {
        BSAudioSetMemContext(m_iLineNumber);
    }
    __forceinline ~BSAudioScopedMemContext()
    {
        BSAudioSetMemContext(m_eMemoryContext);
    }
};

namespace fnv_00ad7620 {
extern __declspec(thread) int iCurrentMemContext;

inline int GetCurrentMemContext()
{
    return iCurrentMemContext;
}
inline void SetCurrentMemContext(int aiContext)
{
    iCurrentMemContext = aiContext;
}

struct MemContextScope
{
    int m_eMemoryContext;
    MemContextScope(int aiContext)
    {
        m_eMemoryContext = GetCurrentMemContext();
        iCurrentMemContext = aiContext;
    }
    ~MemContextScope()
    {
        SetCurrentMemContext(m_eMemoryContext);
    }
};

struct BSSoundHandleEx
{
    unsigned int uiSoundID;
    bool m_bLooping;
    unsigned int uiState;
    BSSoundHandleEx(const BSSoundHandleEx& rhs)
        : uiSoundID(rhs.uiSoundID), m_bLooping(rhs.m_bLooping), uiState(rhs.uiState)
    {}
    ~BSSoundHandleEx()
    {}
    bool Play(bool);
    bool SetPosition(float, float, float);
};

struct FUN_00ae5870_t
{
    BSSoundHandleEx FUN_00ae5870(unsigned int, unsigned int);
};

struct FUN_00ad7620_t : public BSAudio
{
    BSSoundHandleEx FUN_00ad7620(unsigned int aiFormID, unsigned int aiTypeFlags, NiPoint3 aLoc, unsigned int aiID);
};

}  // namespace fnv_00ad7620

namespace fnv_00ad77f0 {
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct FUN_00ad77f0_shell : public BSAudio
{
    void FUN_00ad77f0(float, unsigned int);
};

struct OH2TlsBlock
{
    char pad[0x2b4];
    int m_iThreadLocalValue;
};
extern __declspec(thread) OH2TlsBlock g_OH2Tls;
struct OH2MemContext
{
    int m_eMemoryContext;
    __forceinline OH2MemContext(int aiContext)
    {
        int iOld = g_OH2Tls.m_iThreadLocalValue;
        m_eMemoryContext = iOld;
        g_OH2Tls.m_iThreadLocalValue = aiContext;
    }
    __forceinline ~OH2MemContext()
    {
        int iOld = m_eMemoryContext;
        g_OH2Tls.m_iThreadLocalValue = iOld;
    }
};
}  // namespace fnv_00ad77f0

class TargetAD79
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void Apply(void* pA, void* pB);
};

template <class T> class NiPointerAD79
{
  public:
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
    T* m_pObject;
};

class FUN_00ad7940_C
{
  public:
    char unk00[0x10];
    NiPointerAD79<TargetAD79> m_spReferencedObject;

    void FUN_00ad7940(int a1, int a2, int a3, int a4, int a5, int a6);
};

struct FUN_00ad79b0_shell : public BSAudio
{
    void FUN_00ad79b0(unsigned int);
};

namespace sad7c50 {

struct Settings
{
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
    unsigned char unk174;
    bool m_bEnableState;

    bool IsEnabled()
    {
        return m_bEnableState;
    }
};

Settings* FUN_00ad9060();

struct Owner
{
    bool FUN_00ad7c50();
};

}

extern __declspec(thread) int g_tlsMemContext;

namespace sad8050 {

struct MemContextGuard
{
    int m_iPrevious;

    MemContextGuard(int aiMemoryContext)
    {
        int iPrevious = g_tlsMemContext;
        m_iPrevious = iPrevious;
        g_tlsMemContext = aiMemoryContext;
    }
    ~MemContextGuard()
    {
        int iPrevious = m_iPrevious;
        g_tlsMemContext = iPrevious;
    }
};

struct Manager
{
    void FUN_00add630(int iArg0, int iArg1);
};

Manager* FUN_00ad9060();

struct Owner
{
    void ForwardToManager(int iArg0, int iArg1);
};

}

namespace fnv_00ad8100 {
struct AutoMemContext
{
    void Enter(int, bool, char*, int);
    void Leave();
    void* __vecDelDtor(unsigned int);
    int m_eMemoryContext;
    unsigned int m_pFileName;
    int m_iLineNumber;
};
typedef char _sizecheck_AutoMemContext[sizeof(AutoMemContext) == 12 ? 1 : -1];
struct FUN_00ad8100_shell : public BSAudio
{
    void FUN_00ad8100(char*, unsigned int, void*);
};

struct TLSData
{
    char pad[0x2b4];
    int memContext;
};
__declspec(thread) TLSData g_tlsData;

static inline int GetCurrentMemContext()
{
    return g_tlsData.memContext;
}

static inline void SetCurrentMemContext(int context)
{
    g_tlsData.memContext = context;
}

struct MemContextScope
{
    int oldContext;
    MemContextScope(int newContext)
    {
        oldContext = GetCurrentMemContext();
        g_tlsData.memContext = newContext;
    }
    ~MemContextScope()
    {
        SetCurrentMemContext(oldContext);
    }
};

}  // namespace fnv_00ad8100

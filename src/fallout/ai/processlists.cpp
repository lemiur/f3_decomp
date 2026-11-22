// fallout/ai/processlists.cpp: ProcessLists, ProcessListsEx, TESObjectREFR, BGSProjectile and more (1 function)
#include "f3_common.h"
#include "processlists_private/processlists_ProcessLists.h"
#include "processlists_private/processlists_Actor.h"
#include "processlists_private/processlists_BGSTalkingActivator.h"
#include "processlists_private/processlists_BGSProjectile.h"
#include "processlists_private/processlists_Projectile.h"
#include "processlists_private/processlists_Explosion.h"
#include "processlists_private/processlists_BaseProcess.h"
#include "processlists_private/processlists_PlayerCharacter.h"
#include "processlists_private/processlists_types_TESPackage.h"
#include "processlists_private/processlists_BSTempEffect.h"
#include "processlists_private/processlists_GarbageCollector.h"
#include "processlists_private/processlists_dead_animation_actorbase.h"
#include "processlists_private/processlists_decls.h"
extern PlayerCharacter* pPlayer;

#pragma optimize("gty", on)
// @f3 0x008d6240 (community match, verified in this file)
extern void __cdecl FUN_008d4c10();
void bhkWorld::SetWorldActive(bool arg)
{
    if (*(unsigned int*)&m_pObjectAt24 > 0u)
    {
        if (--*(unsigned int*)&m_pObjectAt24 == 0)
        {
            FUN_008d4c10();
            ReleaseBodies();
            ClearReferences();
            if (arg)
                FlushEntries();
            else
                ClearEntries();
        }
    }
    else if (*(unsigned int*)&_pdbpad_54[4] > 0u && !arg)
    {
        ClearEntries();
    }
}

#pragma optimize("", off)

struct FUN_00632d20_shell : public Crime
{
    void FUN_00632d20(bool);
};

struct FUN_0096bbc0_list
{
    virtual void v0(MobileObject*);
    int GetFirst();
};
struct FUN_0096bbc0_cls
{
    char pad[4];
    MobileObjectProcessArray pa;
    void ProcessMobileObjects(FUN_0096bbc0_list* l);
};

struct FUN_008f63e0_wrap
{
    void ProcessDetectionStateLists(MobileObject* pActor);
};

struct FUN_0096cfa0_proc
{
    void FUN_008ff030(MobileObject*);
};
struct FUN_0096cfa0_virt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool vlast();
};
struct FUN_0096cfa0_cls
{
    char pad[4];
    MobileObjectProcessArray pa;
    void FUN_0096cfa0();
};

struct FUN_0096d490_shell : public ProcessLists
{
    float FUN_0096d490();
};

struct FUN_0096e570_shell : public ProcessLists
{
    void FUN_0096e570();
};

struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011cde2c;
int __cdecl FUN_00970ee0(Actor*, Actor*);

struct FUN_0096e6f0_shell : public ProcessLists
{
    void RemoveActor(Actor*);
};

void __cdecl FUN_008661e0(void*, unsigned int, const void*, unsigned int);

extern double DAT_0102c188;
struct FUN_00973de0_virt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool vlast();
};
struct FUN_00973de0_act
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool vlast(int);
    bool IsPlayerTeammate();
    void SetSpeakingState(bool);
    void FUN_008ad910(void*, bool, bool);
};
struct FUN_00973de0_player
{
    bool FUN_009549a0(FUN_00973de0_act*);
    float GetDistanceToReference(void*, bool, bool);
};
struct BGSMessageInitAccess
{
    unsigned int GetIconFormID();
};
struct FUN_00973de0_cls
{
    char pad[4];
    MobileObjectProcessArray pa;
    void FUN_00973de0();
};

struct TESFormList
{
    bool _ref_008256d0();
    MobileObject** _ref_006815c0();
    void _ref_00905330(MobileObject**);
    TESFormList* GetFirst();
};
struct MobileObjectStub
{
    bool FUN_009bec50(float);
};

struct FUN_00975f90_virt
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool vlast();
};
struct FUN_00975f90_act
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool vlast(int);
};
struct FUN_00975f90_cls
{
    char pad[4];
    MobileObjectProcessArray pa;
    void ClearMobileObjectData();
};

struct NiAVObject;
struct TESObjectLIGH;
struct TESObjectWEAP;
struct MuzzleFlash
{
    void Init(TESObjectREFR*);
    void Update(float, TESObjectREFR*);
    void SetParentRef(TESObjectREFR*);
    void Enable();
    void AttachLight();
    void UpdateMagicCaster();
    void DisableMuzzleFlash();
    bool GetEnabled();
    NiAVObject* FindAVObject();
    BGSProjectile* GetProjectileData();
    TESObjectWEAP* GetWeaponSource();
    TESModel* GetMuzzleFlashModel();
    TESObjectLIGH* GetMuzzleFlashLight();
    TESObjectREFR* GetParentRef();
    void SetDurationTimer(float);
    static void TriggerMuzzleFlash(TESObjectREFR*, Projectile*);
    void* __vecDelDtor(unsigned int);
    bool bEnabled;
    bool bMPSEnabled;
    bool bUpdateLight;
    char _pad_3[1];
    float m_fDurationTimer;
    float m_fFlashDuration;
    char pChild[4];
    char m_pMenuLight[4];
    BGSProjectile* pProjectile;
    TESObjectWEAP* m_pFiringWeapon;
    TESObjectREFR* m_pParentRef;
};
typedef char _sizecheck_MuzzleFlash[sizeof(MuzzleFlash) == 32 ? 1 : -1];
struct FUN_00978890_shell : public ProcessLists
{
    void UpdateMuzzleFlashes(float);
};

struct FUN_00978890_m
{
    unsigned char GetKey();
    unsigned int GetMinLevel();
    void FUN_009bb080(float, unsigned int);
};
struct FUN_00978890_list
{
    bool _ref_008256d0();
    MuzzleFlash** _ref_006815c0();
    FUN_00978890_list* GetFirst();
    void _ref_00905330(MuzzleFlash**);
};
struct FUN_00978890_cls
{
    char pad[0x68];
    FUN_00978890_list list;
    void UpdateMuzzleFlashes(float dt);
};

extern int DAT_0108c23c;
class NavMeshInfo;
template <> class BSSimpleArray<NavMeshInfo*, 1024>
{
  public:
    void FUN_006b3eb0(unsigned int, bool);
};

struct _LARGE_INTEGER
{
    long HighPart;
    unsigned long LowPart;
};
typedef char _sizecheck__LARGE_INTEGER[sizeof(_LARGE_INTEGER) == 8 ? 1 : -1];
struct FUN_0096b050_shell : public ProcessLists
{
    void UpdateLowProcesses(float, bool);
};

struct MobileObjectExt
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void Update(float afDelta);
    void SetCurrentProcess(BaseProcess* apProcess);
    void FUN_00565870();
};

class LowProcess
{
  public:
    float FUN_007df1f0();
    void ResetPackageState();
};

class Calendar
{
  public:
    float GetGameTime();
};

struct SettingT_GameSettingCollection_
{
    void* vptr_;
    SETTING_VALUE uValue;
    SETTING_VALUE* Int();
};

struct PathfindQueueStorage
{
    void FUN_0096aaf0(MobileObject* apObject, int aeLevel);
};

__declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* apCount);
bool __fastcall FUN_00437bb0(MobileObject* apObject);
int __fastcall FUN_004f8960(void* apActor);
bool __cdecl FUN_005ac740();

extern Calendar g_calendar;
extern SettingT_GameSettingCollection_ g_011e0e64;
extern __int64 DAT_011e0e20;
extern unsigned int DAT_011e0e30;
extern bool DAT_011e0e34;
extern RecursiveSpinLock DAT_011f11a0;
extern const double _gModifierZero;

namespace fnv_0096bcd0 {
namespace lc1 {
struct AutoMemContext
{
    AutoMemContext(int aeContext, bool abFlag, const char* apFile, int aiLine);
    ~AutoMemContext();
    int m_eMemoryContext;
};
}
struct ExtraFollower
{
    void* pVtbl;
    unsigned char m_ucExtraDataType;
    BSExtraData* pNext;
    BSSimpleList<Actor*>* pFollowers;
};
struct ExtraFollowerList
{
    TESPackage* GetPackageOverride();
    void AddFollowerActor(Actor* apActor);
    ExtraFollower* GetExtraFollower();
    void FUN_00422720();
};
struct LivingActor
{
    bool FUN_008b0520();
    TESPackage* GetCurrentAIPackage();
    void RestoreHealth(float afAmount);
    void UpdateLifeState(float afAmount);
};
struct MobileObjectProcess
{
    PROCESS_TYPE GetCurrentProcessLevel();
};
struct BaseProcessUpdate
{
    void FUN_008c8fd0(bool abVal);
    void FUN_00693d50(float afHour);
};
struct ProcessListsUpdate
{
    void FUN_00977130(float afTime);
};
struct MobileObjectHigh : public TESObjectREFR
{
    virtual void StartHighProcess();
    virtual void Unk_91();
    virtual void Unk_92();
    virtual void Unk_93();
    virtual void Unk_94();
    virtual void Unk_95();
    virtual void Unk_96();
    virtual void UpdateHigh(float afDelta);
};
struct Calendar
{
    float GetGameTime();
};
struct TimeGlobal
{
    float GetStoredFloatValue();
};
extern Calendar g_calendar;
extern TimeGlobal g_timeGlobal;
extern PlayerCharacter* g_thePlayer;
extern bool DAT_011e0e34;
extern float _DAT_010162c0;
void __cdecl FUN_008c8bd0();

struct ProcessListsHigh : public ProcessLists
{
    void FUN_0096bcd0(float afDelta, bool abSleeping);
};

}  // namespace fnv_0096bcd0

namespace fnv_00977cb0 {
struct FUN_00977cb0_shell : public ProcessLists
{
    void StartActorDialogue(int, TESObjectREFR*, bool);
};

struct Setting_S
{
    float* Float();
};
struct BSSpinLockS
{
    void Lock(const char*);
    void Unlock();
};
struct PCH
{
    bool HasCombatState();
};
struct Ref_S
{
    float GetDistanceToReference(void*, bool, bool);
};
struct RefUse
{
    bool CanBeUsed(Actor*, bool);
};
struct ActorDetect
{
    int CalculateDetectionLevel(int, Actor*, bool*, bool, int, bool, bool*);
    bool UpdateActorPackageState(int);
};
struct FUN_00884480_shell
{
    bool FUN_00884480();
};
struct FUN_008bc3d0_shell
{
    void FUN_008bc3d0(TESTopic*);
};
bool __fastcall FUN_008a67f0(Actor*);
struct ProcStub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual bool IsInDialogue();
};
struct PC7d
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual Actor* GetDialogueTarget();
};
extern double _gModifierZero;
extern Setting_S originalRuntimeFloatSetting1062;
extern Setting_S originalRuntimeFloatSetting1060;
extern PC7d* g_thePlayer;

}  // namespace fnv_00977cb0

namespace fnv_008661e0 {
extern "C" void* __cdecl FUN_00ec7ce3(void*, unsigned int, const void*, unsigned int);

}  // namespace fnv_008661e0

struct FUN_0096cc80_shell
{
    char m_00[0x50];
    unsigned char m_50;
    void __thiscall SetByte50(unsigned char value);
};

struct FUN_00973a90_shell
{
    char pad[0x66d];
    unsigned char GetByteAtOffset();
};

struct FUN_0096abc0_stub
{
    int __thiscall FindKeyIndex(int, int);
};

struct FUN_0096aa40_stub
{
    void __thiscall FUN_0096aa40(int);
};

struct FUN_0096aaf0_shell
{
    void FUN_0096aaf0(int arg1, int arg2);
};

struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct FindData;
struct KFModel;
struct NiAVObject;
struct NiControllerManager;
struct NiControllerSequence;
struct NiNode;
struct TESAnimGroup;
struct TESIdleForm;
struct Animation
{
    void SetField(unsigned char, unsigned char, unsigned char);
    unsigned char GetField(unsigned char, unsigned char);
    void SetBit(bool, unsigned char);
    bool GetBit(unsigned char);
    NiNode* GetAnimNode();
    NiNode* GetAccumRoot();
    void* GetAnimSequenceMap();
    float GetSmallestHavokBlendValue(NiNode*);
    NiControllerManager* GetControllerManager();
    void RemoveObject(NiAVObject*);
    float GetTime();
    float GetTime(NiControllerSequence*);
    void SetTime(float);
    static void SetLipTime(float, NiControllerManager*, NiControllerSequence*);
    void SetLipTime(float);
    bool Init(void*, NiNode*, TESObjectREFR*, bool);
    void SetAnimationName(void*, char*);
    void SetAnimationOwner(void*);
    void QueueReloadAnim(unsigned short);
    bool ReloadAnimQueued();
    bool AddAnimation(KFModel*, bool);
    bool IsAnimationLoaded();
    void SetReloadState(bool);
    void BlendOut(int, bool);
    static float GetDuration(NiControllerSequence*);
    static float GetDuration(NiNode*, float*, float*);
    float GetDuration();
    void SetLookingDir(float);
    void SkipUpdate(int);
    void Update(TESObjectREFR*, float, float);
    void UpdateMovement(TESObjectREFR*);
    void UpdateActorAnimation(TESObjectREFR*);
    bool UpdateQueuedScenegraph();
    bool GetMovementDelta(NiPoint3*, TESObjectREFR*, bool, bool);
    void ClearDelta();
    bool IsGroupQueued(unsigned short);
    void ClearGroup(int, float);
    unsigned short GetQueuedGroup(int);
    void ClearBlendInterps();
    static void ClearBlendInterpsCallback(NiAVObject*);
    void SetAnimationGroup(TESAnimGroup*);
    short GetGroupSection(unsigned short);
    void UpdateBipOnly(float, NiPoint3*, bool);
    void RefreshAnimation();
    void SetMoveSpeed(float);
    float GetMoveSpeed();
    void SetAttackSpeed(float);
    float GetAttackSpeedModifier();
    void AddGroup(TESAnimGroup*);
    BSAnimGroupSequence* PlayGroup(BSAnimGroupSequence*, int, int, int);
    BSAnimGroupSequence* PlayGroup(unsigned short, int, int, int);
    BSAnimGroupSequence* SyncSequences(BSAnimGroupSequence*, unsigned short);
    unsigned short PickBestAnimation(unsigned short, bool);
    bool ShouldBeMoving();
    BSAnimGroupSequence* GetCurrentSequence(int);
    unsigned short GetGroup(int);
    int GetGroupAction(int);
    BSAnimGroupSequence* GetFirstActiveSequence();
    BSAnimGroupSequence* GetNextActiveSequence(BSAnimGroupSequence*);
    void SetCurrentSequence(int, BSAnimGroupSequence*);
    void VerifyUniqueControllerPriorities(NiNode*);
    static bool StripAllBSKeyframeControllers(NiAVObject*);
    bool SwapSequences(int);
    char GetNextNoteKey(float*);
    int FindNoteKey(int, char*, float*);
    char FindNextNoteKey(int, char*, float*);
    void ForceSection(int, unsigned short, int, float, char);
    void ClearForcedSection();
    TESAnimGroup* GetAnimGroupByID(unsigned short);
    bool AreAnimationsLoaded();
    unsigned int GetAnimsLoadingCount();
    void QueueReplacementAnimation(KFModel*);
    void SetLoopCount(int, int);
    void SpecialIdleQueue(TESIdleForm*, int);
    void PlaySpecialIdle(TESIdleForm*, Actor*, int, int);
    bool SpecialIdleReplace();
    void SpecialIdleReplace(TESIdleForm*, Actor*, int);
    bool CanReplaceSpecialIdle();
    bool CanReplaceSpecialIdle(Actor*);
    bool IsSpecialIdlePlaying();
    bool IsSpecialIdlePlaying(TESIdleForm*);
    bool IsSpecialIdlePlaying(BSAnimGroupSequence*);
    bool SpecialIdleLoaded();
    bool IsSpecialIdleReady();
    bool IsSequenceActive();
    void SpecialIdleFree(bool, bool);
    BSAnimGroupSequence* GetPlayingSequence();
    void ShutdownAllAnimIdles();
    static NiNode* FindKeyframeNode(NiNode*);
    static bool RemoveKeyframeControllers(NiAVObject*);
    char GetSkipNextBlend();
    void SkipNextBlend();
    void SetHavokChaseBone(NiAVObject*);
    TESIdleForm* GetSpecialIdleForm();
    BSAnimGroupSequence* GetSpecialIdleSequence();
    unsigned short GetSaveSize(TESObjectREFR*);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(TESObjectREFR*);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(TESObjectREFR*);
    void Revert(BGSLoadFormBuffer*);
    void Revert(TESObjectREFR*);
    static unsigned short GetAnimationID(TESObjectREFR*, Animation*);
    static void SaveAnimation(TESObjectREFR*, Animation*);
    static void RestoreAnimation(TESObjectREFR*, Animation*);
    static void ResetCloneCount();
    void ClearAccumRootTranslate();
    void SetGlobalTimeMultiplier(float);
    float GetGlobalTimeMultiplier();
    void SetReloadModifier(float);
    void SetEquipModifier(float);
    float GetReloadModifier();
    float GetEquipModifier();
    BSAnimGroupSequence* GetAnimationSequence(BSAnimGroupSequence*, unsigned short, int);
    BSAnimGroupSequence* GetAnimationSequence(unsigned short, int);
    void AssignControllerManager(void*);
    static void FindHighestPriorityCallback(NiAVObject*, FindData*);
    BSAnimGroupSequence* GetHighestPriority(NiAVObject*);
    bool GetMoved();
    void SetMoved(bool);
    bool GetDelayUpdateScenegraph();
    void SetDelayUpdateScenegraph(bool);
    void* __vecDelDtor(unsigned int);
    unsigned char m_uiObjectFlags;
    char _pad_1[3];
    TESObjectREFR* m_pAttachedReference;
    char m_acHeaderData[4];
    NiNode* m_pObjectNode;
    NiPoint3 m_kNodeTranslation;
    NiPoint3 m_kRootTranslation;
    char m_acNodeName[32];
    float m_fAnimationAmount;
    char group[16];
    char action[32];
    char m_acTargetName[32];
    char usReloadGroup[16];
    char m_acAnimationName[32];
    char m_cState;
    bool m_bIsPlaying;
    char _pad_ce[2];
    float time;
    float m_fTimeOffset;
    char m_acReservedBytes[4];
    void* m_pOwnerReference;
    char m_pChildTile[32];
    BSAnimGroupSequence* m_pCurrentSequence;
    char kfModelList[8];
    float m_fMovementRate;
    float m_fCombatAnimationRate;
    float m_fEquipAnimationRate;
    float m_fReloadAnimationRate;
    float m_fAnimationTimeScale;
    char m_cSkipNextBlend;
    char _pad_121[1];
    unsigned short m_usQueuedGroup;
    char LocalInput[4];
    char LocalStateValue[4];
    char LocalOutput[8];
    char m_acTrailingData[8];
};
typedef char _sizecheck_Animation[sizeof(Animation) == 316 ? 1 : -1];
struct IndexedTaskData
{
    static void TaskFunc(void*);
    int* m_pIntegerData;
    void* pData;
    unsigned int iSize;
    unsigned int iIndex;
};
typedef char _sizecheck_BSParallelArrayTask[sizeof(IndexedTaskData) == 16 ? 1 : -1];
struct FUN_0096c970_shell : public ProcessLists
{
    void FUN_0096c970();
};

template <class T, unsigned int N> class BSScrapArray
{
  public:
    BSScrapArray();
    virtual ~BSScrapArray();
    unsigned int Add(T& item);
    unsigned int GetTarget();
    T* pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    unsigned int uiGrowSize;
};
struct GlobalObject_0045cf30
{
    bool* GetLifeStateControlFlag();
};
extern GlobalObject_0045cf30 g_011f1260;
struct ShadowSceneNode
{
    void RemoveSceneObject(NiAVObject*, bool);
};
struct NiAdditionalGeometryData
{
    static ShadowSceneNode* GetShadowSceneNodeForIndex(int);
};
struct AnimUpdateHelper
{
    bool FUN_00493930();
};
struct MobileLightHelper
{
    void SetByteAt14E(bool);
};
void __cdecl FUN_0096cb20(unsigned int, void*);
struct FUN_0087cf10_shell
{
    FUN_0087cf10_shell* Construct(void(__cdecl*)(unsigned int, void*), void*, unsigned int);
};
struct TaskQueueParallelManager
{
    void FUN_00c44c90(void*);
};
extern TaskQueueParallelManager* DAT_01202df4;

struct FUN_0096cb50_shell : public ProcessLists
{
    void UpdateHighProcessActors();
};

struct RagH
{
    bool FUN_00552490();
    void SetByte50(unsigned char);
};
struct BSFadeNode
{
    bool FUN_00552470() const;
};
struct ActorDialogueHelper
{
    bool IsInDialogueWithPlayer() const;
    void UpdateRagdollController(unsigned char);
};

struct FUN_009707f0_shell
{
    void FUN_009707f0(int value);
};

struct ActorAnimHelper
{
    void PickAnimations(float, float);
};
struct FUN_00971ba0_shell
{
    void FUN_00971ba0();
};

namespace fnv_009724e0 {
class TESFormList
{
  public:
    MobileObject** _ref_006815c0();
    TESFormList* GetFirst();
};
struct TESResponse
{
    int GetNext();
};
struct FUN_009724e0_shell
{
    MobileObject* FindMobileObjectByValue(int, int);
};

}  // namespace fnv_009724e0

namespace fnv_00974af0 {
class TESFormList
{
  public:
    NiPointer<BSTempEffect>* _ref_006815c0();
    TESFormList* GetFirst();
};
struct MagicHitEffect
{
    char* GetData();
    void SetByteAt24(unsigned char);
};
struct FUN_00974af0_shell
{
    void FUN_00974af0(char*);
};

}  // namespace fnv_00974af0

namespace fnv_00977660 {
struct FUN_00977660_shell : public ProcessLists
{
    void FUN_00977660();
};

struct Setting_S
{
    float* Float();
};
struct Ref_S
{
    float GetDistanceToReference(void*, bool, bool);
};
struct FUN_0096e570_shell
{
    void FUN_0096e570();
};
void* __cdecl MemsetWrapper(void*, int, unsigned int);
extern Setting_S originalRuntimeFloatSetting248;
struct ProcessListsInsertHelper
{
    void FUN_0096e3c0(Actor*);
};

}  // namespace fnv_00977660

struct ActorMagicHelper
{
    void ConfigureActorState(bool, bool);
};
struct FUN_009784c0_shell
{
    void FUN_009784c0();
};

struct FUN_00973a70_shell
{
    void __thiscall SetByteAt66c(char arg);
};

namespace fnv_0096cb20 {
struct AnimUpdateHelper
{
    bool FUN_00493930();
};
}  // namespace fnv_0096cb20

struct FakeObj
{
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual bool Check(float);
};
struct ParentSpaceNode
{
    FakeObj* unk0;
    float unk4;
    unsigned char unk8;
    unsigned char unk9;
};

extern double DAT_01011598;
struct FUN_009781a0_shell
{
    char _pad[0x154];
    float _154;
    void FUN_009781a0();
};

namespace fnv_0096c860 {
struct C00493930
{
    bool FUN_00493930();
};
struct FUN_00496960_shell
{
    void SetByteAt14E(unsigned char);
};
struct NiAdditionalGeometryData
{
    static NiAVObject* GetShadowSceneNodeForIndex(int);
};
struct ShadowSceneNode
{
    void RemoveSceneObject(NiAVObject*, bool);
};
struct FUN_0096c860_shell : ProcessLists
{
    void FUN_0096c860();
};
}  // namespace fnv_0096c860

struct Flt
{
    operator unsigned int();
};
extern const NiRTTI g_011d6b04;
struct MiddleHighProcess
{
    void FUN_00929260(unsigned char);
};
struct BSTempEffectGeometryDecal
{
    NiPointer<BSTempEffect> operator*();
    void FUN_00929260(unsigned char);
};
struct FUN_00974c30_shell
{
    BSSimpleList<NiPointer<BSTempEffect> > effects;
    void FUN_00974c30();
};

namespace fnv_00978550 {
struct FUN_00978550_shell
{
    void* p;
    MobileObjectProcessArray arr;
    void FUN_00978550();
};

class MobileObjectExt : public MobileObject
{
  public:
    void FUN_00565870();
};

}  // namespace fnv_00978550

struct Dummy_96cf60
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void Exec();
};

namespace fnv_00971fd0 {
struct CTSHelper
{
    CTSHelper();
    float GetElapsedTime();
    int m_iPackageData;
};
struct NodeS
{
    bool _ref_008256d0();
    void** _ref_006815c0();
    void _ref_00905330(void* const* item);
};
struct TESFormList
{
    void* GetFirst();
};
struct TESTopicInfoData;
struct TESTopicInfo
{
    TESTopicInfoData* GetConversationData();
    CTSHelper FUN_008bcc60();
};
struct TESObjectREFR_GetFlags_Helper
{
    unsigned int CallGetFlags();
};
struct FUN_009722e0_shell
{
    bool IsActorInOtherList(void* apRef, TESTopicInfo* apInfo);
};
struct FUN_0047eb90_shell
{
    void FUN_0047eb90(int);
};
struct FUN_0041cf00_shell
{
    void* FUN_0041cf00();
};
struct List_009e03e0
{
    ~List_009e03e0();
    void* pItem;
    void* pNext;
};
struct SL : List_009e03e0
{
    SL();
};
struct G2
{
    void AddHead(int*);
};
struct FUN_00971fd0_shell
{
    SL* FUN_00971fd0(float afTime);
};

}  // namespace fnv_00971fd0

namespace fnv_0096e3c0 {
struct CloningProcess;
struct NiStream;
struct ahkpCharacterProxy;
struct bhkCharacterProxy;
struct BhkPhysicsObject;
struct bhkSerializable;
struct bhkShapePhantom;
struct PhysicsSimulationContext;
struct hkReferencedObject;
struct hkSerializableCinfo;
struct hkStatisticsCollector;
struct hkStepInfo;
struct hkVector4;
struct CharacterProxyConfiguration;
struct Vector4Data;
struct hkpCharacterProxy;
struct hkpCharacterProxyListener;
struct hkpPhantom;
struct hkpShapePhantom;
struct CharacterPhysicsController;
struct hkpSurfaceInfo;
struct hkpWorld;
struct blob1
{
    char b[1];
};
struct FUN_0096e3c0_shell : public ProcessLists
{
    void FUN_0096e3c0(Actor*);
};

struct bhkCharacterController_shell
{
    float FUN_008a3b50() const;
};
struct SettingInt
{
    int* Int();
};
extern SettingInt g_011cde2c;
void __cdecl FUN_008661e0(void*, unsigned int, const void*, unsigned int);
struct MobileCharHelper
{
    bhkCharacterController* GetPhysicsCharacterController();
};

}  // namespace fnv_0096e3c0

namespace fnv_00972570 {
struct TESFormList
{
    TESFormList* GetFirst();
};

Crime** __fastcall _ref_006815c0(void*);

struct Crime_Standin : Crime
{
    TESObjectREFR* GetTarget();
};

struct FUN_00972570_shell
{
    char pad[0x44];
    TESFormList* crimeLists[6];

    Crime* FindCrime(unsigned int formID, TESObjectREFR* target, int crimeType);
};

}  // namespace fnv_00972570

namespace fnv_00974a50 {
struct Flt
{
    operator unsigned int();
};

Flt* __fastcall _ref_006815c0(void*);

struct MagicHitEffect
{
    void SetByteAt24(unsigned int);
};

struct TESFormList
{
    TESFormList* GetFirst();
};

class MagicShaderHitEffect;

struct FUN_00974a50_shell
{
    char pad[0x60];
    BSSimpleList<NiPointer<BSTempEffect> > tempEffects;

    void FUN_00974a50(TESObjectREFR* apEffectTarget, void* apShader);
};

}  // namespace fnv_00974a50

namespace fnv_00977130 {
struct ActorPackageData;
struct ActorValueStore;
struct AnimIdle;
struct Animation;
struct ArrowProjectile;
struct BGSBodyPartData;
struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BSAnimGroupSequence;
struct BSBound;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct BSShaderPPLightingProperty;
struct BipedAnim;
struct ActorCombatGroup;
struct DetectionEvent;
struct DetectionViewData;
struct DialogueItem;
struct DetectionParameters;
struct FurnitureMark;
struct GuardActorPackageData;
struct HighProcess;
struct BooleanFloatQuery;
struct InventoryStackRecord;
struct KFModel;
struct LipSyncAnimation;
struct LowProcess;
struct MagicItem;
struct MiddleHighProcess;
struct MiddleLowProcess;
struct DetectionEventData;
struct MuzzleFlash;
struct NiAVObject;
struct NiBSBoneLODController;
struct NiBillboardNode;
struct NiControllerManager;
struct NiNode;
struct TargetDoorController;
struct PackageTargetRecord;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PatrolActorPackageData;
struct SpellItem;
struct TESEffectShader;
struct TESFaction;
struct TESIdleForm;
struct TESObjectSTAT;
struct TESObjectWEAP;
struct TESWorldSpace;
struct bhkCharacterController;
struct bhkSimpleShapePhantom;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_00977130_shell : public ProcessLists
{
    void FUN_00977130(float);
};

struct ActorQuery_00977130
{
    int FUN_004f8960();
};
bool FUN_00525420();
bool __fastcall FUN_00577de0(Actor*);
extern double _gModifierZero;
struct Setting_S
{
    float* Float();
};
extern Setting_S originalRuntimeFloatSetting1023;
extern Setting_S originalRuntimeFloatSetting1024;
struct GlobalObject2_0040c150
{
    int* Int();
};
extern GlobalObject2_0040c150 g_011d08f8;
extern GlobalObject2_0040c150 g_011d0964;
extern GlobalObject2_0040c150 g_011d09a0;
extern GlobalObject2_0040c150 g_011d0cd8;
struct TESResponse
{
    int GetNext();
};
struct Fn56ac90
{
    void* FUN_0056ac90();
};
struct FUN_005722c0_shell
{
    bool FUN_005722c0(int);
};
struct ActorV_S
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual bool IsDisabledOrDeleted();
};
struct HighProcess
{
    virtual void V000();
    virtual void V001();
    virtual void V002();
    virtual void V003();
    virtual void V004();
    virtual void V005();
    virtual void V006();
    virtual void V007();
    virtual void V008();
    virtual void V009();
    virtual void V010();
    virtual void V011();
    virtual void V012();
    virtual void V013();
    virtual void V014();
    virtual void V015();
    virtual void V016();
    virtual void V017();
    virtual void V018();
    virtual void V019();
    virtual void V020();
    virtual void V021();
    virtual void V022();
    virtual void V023();
    virtual void V024();
    virtual void V025();
    virtual void V026();
    virtual void V027();
    virtual void V028();
    virtual void V029();
    virtual void V030();
    virtual void V031();
    virtual void V032();
    virtual void V033();
    virtual void V034();
    virtual void V035();
    virtual void V036();
    virtual void V037();
    virtual void V038();
    virtual void V039();
    virtual void V040();
    virtual void V041();
    virtual void V042();
    virtual void V043();
    virtual void V044();
    virtual void V045();
    virtual void V046();
    virtual void V047();
    virtual void V048();
    virtual void V049();
    virtual void V050();
    virtual void V051();
    virtual void V052();
    virtual void V053();
    virtual void V054();
    virtual void V055();
    virtual void V056();
    virtual void V057();
    virtual void V058();
    virtual void V059();
    virtual void V060();
    virtual void V061();
    virtual void V062();
    virtual void V063();
    virtual void V064();
    virtual void V065();
    virtual void V066();
    virtual void V067();
    virtual void V068();
    virtual void V069();
    virtual void V070();
    virtual void V071();
    virtual void V072();
    virtual void V073();
    virtual void V074();
    virtual void V075();
    virtual void V076();
    virtual void V077();
    virtual void V078();
    virtual void V079();
    virtual void V080();
    virtual void V081();
    virtual void V082();
    virtual void V083();
    virtual void V084();
    virtual void V085();
    virtual void V086();
    virtual void V087();
    virtual void V088();
    virtual void V089();
    virtual void V090();
    virtual void V091();
    virtual void V092();
    virtual void V093();
    virtual void V094();
    virtual void V095();
    virtual void V096();
    virtual void V097();
    virtual void V098();
    virtual void V099();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual void V136();
    virtual void V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual void V175();
    virtual void V176();
    virtual void V177();
    virtual void V178();
    virtual void V179();
    virtual void V180();
    virtual void V181();
    virtual void V182();
    virtual void V183();
    virtual void V184();
    virtual void V185();
    virtual void V186();
    virtual void V187();
    virtual void V188();
    virtual void V189();
    virtual void V190();
    virtual void V191();
    virtual void V192();
    virtual void V193();
    virtual void V194();
    virtual void V195();
    virtual void V196();
    virtual void V197();
    virtual void V198();
    virtual void V199();
    virtual void V200();
    virtual void V201();
    virtual void V202();
    virtual void V203();
    virtual void V204();
    virtual void V205();
    virtual void V206();
    virtual void V207();
    virtual void V208();
    virtual void V209();
    virtual void V210();
    virtual void V211();
    virtual void V212();
    virtual void V213();
    virtual void V214();
    virtual void V215();
    virtual void V216();
    virtual void V217();
    virtual void V218();
    virtual void V219();
    virtual void V220();
    virtual void V221();
    virtual void V222();
    virtual void V223();
    virtual void V224();
    virtual void V225();
    virtual void V226();
    virtual void V227();
    virtual void V228();
    virtual void V229();
    virtual void V230();
    virtual void V231();
    virtual void V232();
    virtual void V233();
    virtual void V234();
    virtual void V235();
    virtual void V236();
    virtual void V237();
    virtual void V238();
    virtual void V239();
    virtual void V240();
    virtual void V241();
    virtual void V242();
    virtual void V243();
    virtual void V244();
    virtual void V245();
    virtual void V246();
    virtual void V247();
    virtual void V248();
    virtual void V249();
    virtual void V250();
    virtual void V251();
    virtual void V252();
    virtual void V253();
    virtual void V254();
    virtual void V255();
    virtual void V256();
    virtual void V257();
    virtual void V258();
    virtual void V259();
    virtual void V260();
    virtual void V261();
    virtual void V262();
    virtual void V263();
    virtual void V264();
    virtual void V265();
    virtual void V266();
    virtual void V267();
    virtual void V268();
    virtual void V269();
    virtual void V270();
    virtual void V271();
    virtual void V272();
    virtual void V273();
    virtual void V274();
    virtual void V275();
    virtual void V276();
    virtual void V277();
    virtual void V278();
    virtual void V279();
    virtual void V280();
    virtual void V281();
    virtual void V282();
    virtual void V283();
    virtual void V284();
    virtual void V285();
    virtual void V286();
    virtual void V287();
    virtual void V288();
    virtual void V289();
    virtual void V290();
    virtual void V291();
    virtual void V292();
    virtual void V293();
    virtual void V294();
    virtual void V295();
    virtual void V296();
    virtual void V297();
    virtual void V298();
    virtual void V299();
    virtual float GetDeadTimer();
    virtual void V301();
    virtual void V302();
    virtual void V303();
    virtual void V304();
    virtual void V305();
    virtual void V306();
    virtual void V307();
    virtual void V308();
    virtual void V309();
    virtual void V310();
    virtual void V311();
    virtual void V312();
    virtual void V313();
    virtual void V314();
    virtual void V315();
    virtual void V316();
    virtual void V317();
    virtual void V318();
    virtual void V319();
    virtual void V320();
    virtual void V321();
    virtual void V322();
    virtual void V323();
    virtual void V324();
    virtual void V325();
    virtual void V326();
    virtual void V327();
    virtual void V328();
    virtual void V329();
    virtual void V330();
    virtual void V331();
    virtual void V332();
    virtual void V333();
    virtual void V334();
    virtual void V335();
    virtual void V336();
    virtual void V337();
    virtual void V338();
    virtual void V339();
    virtual void V340();
    virtual void V341();
    virtual void V342();
    virtual void V343();
    virtual void V344();
    virtual void V345();
    virtual void V346();
    virtual void V347();
    virtual void V348();
    virtual void V349();
    virtual void V350();
    virtual void V351();
    virtual void V352();
    virtual void V353();
    virtual void V354();
    virtual void V355();
    virtual void V356();
    virtual void V357();
    virtual void V358();
    virtual void V359();
    virtual void V360();
    virtual void V361();
    virtual void V362();
    virtual void V363();
    virtual void V364();
    virtual void V365();
    virtual void V366();
    virtual void V367();
    virtual void V368();
    virtual void V369();
    virtual void V370();
    virtual void V371();
    virtual void V372();
    virtual void V373();
    virtual void V374();
    virtual void V375();
    virtual void V376();
    virtual void V377();
    virtual void V378();
    virtual void V379();
    virtual void V380();
    virtual void V381();
    virtual void V382();
    virtual void V383();
    virtual void V384();
    virtual void V385();
    virtual void V386();
    virtual void V387();
    virtual int IsInDialogue();
    void FUN_008feb60(Actor*);
};

}  // namespace fnv_00977130

struct FUN_009785d0_shell
{
    int unk0;
    MobileObjectProcessArray processes;
    void RemoveDetectionEventsFromActors();
};

struct FUN_0096bc50_shell
{
    unsigned int pad0;
    MobileObjectProcessArray processes;
    unsigned int CountHighProcessActors();
};

struct CrimeListNode
{
    bool vfn_008256d0();
    BGSPerk** GetItem();
    CrimeListNode* GetFirst();
};
struct FUN_00972740_shell
{
    unsigned short FUN_00972740(unsigned int aeType, BGSPerk* apCrime);
};
void FNV_Warning(const char*);

namespace fnv_00974b80 {
struct TESFormList
{
    void* GetFirst();
};
struct GO
{
    operator unsigned int();
};
struct MagicHitEffect
{
    void SetByteAt24(unsigned int);
};
struct ScriptText
{
    char* GetText();
};
int __cdecl FUN_00408b20(char const*, char const*);
extern const NiRTTI g_011dc724;
struct FUN_00974b80_shell
{
    BSSimpleList<NiPointer<BSTempEffect> > listEffects;
    void FUN_00974b80(unsigned int a, char* b);
};
}  // namespace fnv_00974b80

struct Modifier
{
    unsigned char GetKey();
};

struct ConsoleManager
{
    static ConsoleManager* __cdecl Instance(bool create);
    bool IsConsoleActive();
    void Print(char const* text, char const* context);
};

Modifier* __cdecl _FUN_004b7210();
unsigned char __cdecl FUN_005b6f70();

namespace fnv_009721f0 {
extern unsigned int _data_011c16bc;

struct MemoryManager
{
    static void* __cdecl Allocate(unsigned int);
};

struct TESFormList
{
    void* GetFirst();
};

struct LH
{
    bool __thiscall IsInList(int& value);
};

struct G2
{
    void __thiscall AddHead(int* value);
};

struct SL
{
    int field0;
    int field4;

    SL();
};

struct FUN_009721f0_layout
{
    unsigned char padding[0x44];
    SL* bItemFound[5];
};

struct FUN_009721f0_shell
{
    void AddObjectToList(TESFormList* objectList);
};

}  // namespace fnv_009721f0

namespace fnv_009754f0 {
struct SaveManager;
struct GameTimerRecord
{
    unsigned int* GetTime() const;
};

struct TESSaveLoadGame
{
    void FUN_008579b0(void* data, int type);
};

struct TESFormList
{
    void* GetFirst();
};

struct _ref_008256d0_shell
{
    unsigned char _ref_008256d0();
};

struct FUN_009ebca0_shell
{
    void WriteToSave();
};

extern SaveManager* DAT_011de45c;

struct FUN_009754f0_shell
{
    void* pad[0x11];
    void* lists[5];

    void FUN_009754f0();
};

}  // namespace fnv_009754f0

struct FUN_00975ea0_shell
{
    unsigned int m_unused;
    MobileObjectProcessArray m_processArray;
    void FUN_00975ea0();
};

bool FUN_009336c0(MobileObject* pCurrentObject);

struct FUN_009336c0_shell
{
    bool FUN_009336c0() const;
};

PlayerCharacter* _g_thePlayer;

struct FUN_00974fc0_V178
{
    virtual void f000() = 0;
    virtual void f001() = 0;
    virtual void f002() = 0;
    virtual void f003() = 0;
    virtual void f004() = 0;
    virtual void f005() = 0;
    virtual void f006() = 0;
    virtual void f007() = 0;
    virtual void f008() = 0;
    virtual void f009() = 0;
    virtual void f010() = 0;
    virtual void f011() = 0;
    virtual void f012() = 0;
    virtual void f013() = 0;
    virtual void f014() = 0;
    virtual void f015() = 0;
    virtual void f016() = 0;
    virtual void f017() = 0;
    virtual void f018() = 0;
    virtual void f019() = 0;
    virtual void f020() = 0;
    virtual void f021() = 0;
    virtual void f022() = 0;
    virtual void f023() = 0;
    virtual void f024() = 0;
    virtual void f025() = 0;
    virtual void f026() = 0;
    virtual void f027() = 0;
    virtual void f028() = 0;
    virtual void f029() = 0;
    virtual void f030() = 0;
    virtual void f031() = 0;
    virtual void f032() = 0;
    virtual void f033() = 0;
    virtual void f034() = 0;
    virtual void f035() = 0;
    virtual void f036() = 0;
    virtual void f037() = 0;
    virtual void f038() = 0;
    virtual void f039() = 0;
    virtual void f040() = 0;
    virtual void f041() = 0;
    virtual void f042() = 0;
    virtual void f043() = 0;
    virtual void f044() = 0;
    virtual void f045() = 0;
    virtual void f046() = 0;
    virtual void f047() = 0;
    virtual void f048() = 0;
    virtual void f049() = 0;
    virtual void f050() = 0;
    virtual void f051() = 0;
    virtual void f052() = 0;
    virtual void f053() = 0;
    virtual void f054() = 0;
    virtual void f055() = 0;
    virtual void f056() = 0;
    virtual void f057() = 0;
    virtual void f058() = 0;
    virtual void f059() = 0;
    virtual void f060() = 0;
    virtual void f061() = 0;
    virtual void f062() = 0;
    virtual void f063() = 0;
    virtual void f064() = 0;
    virtual void f065() = 0;
    virtual void f066() = 0;
    virtual void f067() = 0;
    virtual void f068() = 0;
    virtual void f069() = 0;
    virtual void f070() = 0;
    virtual void f071() = 0;
    virtual void f072() = 0;
    virtual void f073() = 0;
    virtual void f074() = 0;
    virtual void f075() = 0;
    virtual void f076() = 0;
    virtual void f077() = 0;
    virtual void f078() = 0;
    virtual void f079() = 0;
    virtual void f080() = 0;
    virtual void f081() = 0;
    virtual void f082() = 0;
    virtual void f083() = 0;
    virtual void f084() = 0;
    virtual void f085() = 0;
    virtual void f086() = 0;
    virtual void f087() = 0;
    virtual void f088() = 0;
    virtual void f089() = 0;
    virtual void f090() = 0;
    virtual void f091() = 0;
    virtual void f092() = 0;
    virtual void f093() = 0;
    virtual void f094() = 0;
    virtual void f095() = 0;
    virtual void f096() = 0;
    virtual void f097() = 0;
    virtual void f098() = 0;
    virtual void f099() = 0;
    virtual void f100() = 0;
    virtual void f101() = 0;
    virtual void f102() = 0;
    virtual void f103() = 0;
    virtual void f104() = 0;
    virtual void f105() = 0;
    virtual void f106() = 0;
    virtual void f107() = 0;
    virtual void f108() = 0;
    virtual void f109() = 0;
    virtual void f110() = 0;
    virtual void f111() = 0;
    virtual void f112() = 0;
    virtual void f113() = 0;
    virtual void f114() = 0;
    virtual void f115() = 0;
    virtual void f116() = 0;
    virtual void f117() = 0;
    virtual void f118() = 0;
    virtual void f119() = 0;
    virtual void f120() = 0;
    virtual void f121() = 0;
    virtual void f122() = 0;
    virtual void f123() = 0;
    virtual void f124() = 0;
    virtual void f125() = 0;
    virtual void f126() = 0;
    virtual void f127() = 0;
    virtual void f128() = 0;
    virtual void f129() = 0;
    virtual void f130() = 0;
    virtual void f131() = 0;
    virtual void f132() = 0;
    virtual void f133() = 0;
    virtual void f134() = 0;
    virtual void f135() = 0;
    virtual void f136() = 0;
    virtual void f137() = 0;
    virtual void f138() = 0;
    virtual void f139() = 0;
    virtual void f140() = 0;
    virtual void f141() = 0;
    virtual void f142() = 0;
    virtual void f143() = 0;
    virtual void f144() = 0;
    virtual void f145() = 0;
    virtual void f146() = 0;
    virtual void f147() = 0;
    virtual void f148() = 0;
    virtual void f149() = 0;
    virtual void f150() = 0;
    virtual void f151() = 0;
    virtual void f152() = 0;
    virtual void f153() = 0;
    virtual void f154() = 0;
    virtual void f155() = 0;
    virtual void f156() = 0;
    virtual void f157() = 0;
    virtual void f158() = 0;
    virtual void f159() = 0;
    virtual void f160() = 0;
    virtual void f161() = 0;
    virtual void f162() = 0;
    virtual void f163() = 0;
    virtual void f164() = 0;
    virtual void f165() = 0;
    virtual void f166() = 0;
    virtual void f167() = 0;
    virtual void f168() = 0;
    virtual void f169() = 0;
    virtual void f170() = 0;
    virtual void f171() = 0;
    virtual void f172() = 0;
    virtual void f173() = 0;
    virtual void f174() = 0;
    virtual void f175() = 0;
    virtual void f176() = 0;
    virtual void f177() = 0;
    virtual PlayerCharacter* Unk_B2() = 0;
};

struct FUN_00974fc0_shell
{
    void FUN_00974fc0();
};

struct FUN_00978420_actor_base
{
    virtual void M0()
    {}
    virtual void M1()
    {}
    virtual void M2()
    {}
    virtual void M3()
    {}
    virtual void M4()
    {}
    virtual void M5()
    {}
    virtual void M6()
    {}
    virtual void M7()
    {}
    virtual void M8()
    {}
    virtual void M9()
    {}
    virtual void M10()
    {}
    virtual void M11()
    {}
    virtual void M12()
    {}
    virtual void M13()
    {}
    virtual void M14()
    {}
    virtual void M15()
    {}
    virtual void M16()
    {}
    virtual void M17()
    {}
    virtual void M18()
    {}
    virtual void M19()
    {}
    virtual void M20()
    {}
    virtual void M21()
    {}
    virtual void M22()
    {}
    virtual void M23()
    {}
    virtual void M24()
    {}
    virtual void M25()
    {}
    virtual void M26()
    {}
    virtual void M27()
    {}
    virtual void M28()
    {}
    virtual void M29()
    {}
    virtual void M30()
    {}
    virtual void M31()
    {}
    virtual void M32()
    {}
    virtual void M33()
    {}
    virtual void M34()
    {}
    virtual void M35()
    {}
    virtual void M36()
    {}
    virtual void M37()
    {}
    virtual void M38()
    {}
    virtual void M39()
    {}
    virtual void M40()
    {}
    virtual void M41()
    {}
    virtual void M42()
    {}
    virtual void M43()
    {}
    virtual void M44()
    {}
    virtual void M45()
    {}
    virtual void M46()
    {}
    virtual void M47()
    {}
    virtual void M48()
    {}
    virtual void M49()
    {}
    virtual void M50()
    {}
    virtual void M51()
    {}
    virtual void M52()
    {}
    virtual void M53()
    {}
    virtual void M54()
    {}
    virtual void M55()
    {}
    virtual void M56()
    {}
    virtual void M57()
    {}
    virtual void M58()
    {}
    virtual void M59()
    {}
    virtual void M60()
    {}
    virtual void M61()
    {}
    virtual void M62()
    {}
    virtual void M63()
    {}
    virtual void M64()
    {}
    virtual void M65()
    {}
    virtual void M66()
    {}
    virtual void M67()
    {}
    virtual void M68()
    {}
    virtual void M69()
    {}
    virtual void M70()
    {}
    virtual void M71()
    {}
    virtual void M72()
    {}
    virtual void M73()
    {}
    virtual void M74()
    {}
    virtual void M75()
    {}
    virtual void M76()
    {}
    virtual void M77()
    {}
    virtual void M78()
    {}
    virtual void M79()
    {}
    virtual void M80()
    {}
    virtual void M81()
    {}
    virtual void M82()
    {}
    virtual void M83()
    {}
    virtual void M84()
    {}
    virtual void M85()
    {}
    virtual void M86()
    {}
    virtual void M87()
    {}
    virtual void M88()
    {}
    virtual void M89()
    {}
    virtual void M90()
    {}
    virtual void M91()
    {}
    virtual void M92()
    {}
    virtual void M93()
    {}
    virtual void M94()
    {}
    virtual void M95()
    {}
    virtual void M96()
    {}
    virtual void M97()
    {}
    virtual void M98()
    {}
    virtual void M99()
    {}
    virtual void M100()
    {}
    virtual void M101()
    {}
    virtual void M102()
    {}
    virtual void M103()
    {}
    virtual void M104()
    {}
    virtual void M105()
    {}
    virtual void M106()
    {}
    virtual void M107()
    {}
    virtual void M108()
    {}
    virtual void M109()
    {}
    virtual void M110()
    {}
    virtual void M111()
    {}
    virtual void M112()
    {}
    virtual void M113()
    {}
    virtual void M114()
    {}
    virtual void M115()
    {}
    virtual void M116()
    {}
    virtual void M117()
    {}
    virtual void M118()
    {}
    virtual void M119()
    {}
    virtual void M120()
    {}
    virtual void M121()
    {}
    virtual void M122()
    {}
    virtual void M123()
    {}
    virtual void M124()
    {}
    virtual void M125()
    {}
    virtual void M126()
    {}
    virtual void M127()
    {}
    virtual void M128()
    {}
    virtual void M129()
    {}
    virtual void M130()
    {}
    virtual void M131()
    {}
    virtual void M132()
    {}
    virtual void M133()
    {}
    virtual void M134()
    {}
    virtual void M135()
    {}
    virtual void M136()
    {}
    virtual void M137()
    {}
    virtual void M138()
    {}
    virtual void M139()
    {}
    virtual void M140()
    {}
    virtual void M141()
    {}
    virtual void M142()
    {}
    virtual void M143()
    {}
    virtual void M144()
    {}
    virtual void M145()
    {}
    virtual void M146()
    {}
    virtual void M147()
    {}
    virtual void M148()
    {}
    virtual void M149()
    {}
    virtual void M150()
    {}
    virtual void M151()
    {}
    virtual void M152()
    {}
    virtual void M153()
    {}
};

struct FUN_00978420_actor : public FUN_00978420_actor_base
{
    virtual void M154(float f)
    {}
};

struct FUN_00978420_shell
{
    unsigned int m_unknown;
    MobileObjectProcessArray m_processArray;

    void FUN_00978420(float f, int unused);
};

struct LinkedListNode
{
    int FUN_005ae380();
    void** FUN_006815c0();
    void FUN_00726c60(void** item);
    LinkedListNode* FUN_00726070();
    void FUN_007a8790(int(__cdecl* compare)(void*, void*));
};

class ProcessLoopObject;

class ProcessLoopObject
{
  public:
    virtual void v000();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual void v013();
    virtual void v014();
    virtual void v015();
    virtual void v016();
    virtual void v017();
    virtual void v018();
    virtual void v019();
    virtual void v020();
    virtual void v021();
    virtual void v022();
    virtual void v023();
    virtual void v024();
    virtual void v025();
    virtual void v026();
    virtual void v027();
    virtual void v028();
    virtual void v029();
    virtual void v030();
    virtual void v031();
    virtual void v032();
    virtual void v033();
    virtual void v034();
    virtual void v035();
    virtual void v036();
    virtual void v037();
    virtual void v038();
    virtual void v039();
    virtual void v040();
    virtual void v041();
    virtual void v042();
    virtual void v043();
    virtual void v044();
    virtual void v045();
    virtual void v046();
    virtual void v047();
    virtual void v048();
    virtual void v049();
    virtual void v050();
    virtual void v051();
    virtual void v052();
    virtual void v053();
    virtual void v054();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual unsigned char v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void v073();
    virtual void v074();
    virtual void v075();
    virtual void v076();
    virtual void v077();
    virtual void v078();
    virtual void v079();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual void v086();
    virtual void v087();
    virtual void v088();
    virtual void v089();
    virtual void v090();
    virtual void v091();
    virtual void v092();
    virtual void v093();
    virtual void v094();
    virtual void v095();
    virtual void v096();
    virtual void v097();
    virtual void v098();
    virtual void v099();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual unsigned int v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154(float f);
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
    unsigned char m_bc;
    void* Get8D6F30();
    unsigned char Get440D80();
    unsigned char Get440DA0();
};

class ProcessLoopX
{
  public:
    unsigned char Get450FF0();
};

struct FUN_0096cca0_shell
{
    unsigned int m_unk0;
    MobileObjectProcessArray m_processArray;
    void FUN_0096cca0();
};

struct ProcActorStub
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActorV();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void* GetProcessV();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void UpdateV();
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
    unsigned char byteBC;
    bool GetDeleted() const;
    bool GetDisabled();
    void* Get3D() const;
};
bool __fastcall FUN_00450ff0(void* apNode);
void __cdecl ProcTaskFunc(unsigned int, void*);
struct ProcParallelTask
{
    void* m_pIntegerData;
    void* pData;
    unsigned int iSize;
    unsigned int iIndex;
    ProcParallelTask* Init(void(__cdecl*)(unsigned int, void*), void*, unsigned int);
};
struct ProcTaskManager
{
    void Queue(ProcParallelTask*);
};
extern ProcTaskManager* DAT_01202df4_mgr;
struct SettingBoolStub
{
    bool* Bool();
};
extern SettingBoolStub g_011f126c;
struct ProcScrapArray
{
    ProcScrapArray();
    ~ProcScrapArray();
    unsigned int Add(ProcActorStub*& item);
    unsigned int GetSize();
    void* vtbl;
    ProcActorStub** pBuffer;
    unsigned int uiSize;
    unsigned int uiAllocSize;
    unsigned int uiGrowSize;
};

struct ProcListsExt : public ProcessLists
{
    void FUN_0096cda0();
};

struct CellProcessState
{
    BSSimpleList<MobileObject*>* currentActors;
    int generation;
    int count;
    BSSimpleList<MobileObject*>* actors;
};

struct CellProcessType
{
    int FUN_0041ca90();
};

struct CellProcessManager
{
    CellProcessState* FUN_00422700();
    void FUN_00422690(MobileObject* actor);
    void FUN_00422720();
    CellProcessType* FUN_0041cb10();
};

struct ActorProcessProxy
{
    CellProcessManager* FUN_005d43c0();
    int FUN_008d8520();
    CellProcessType* FUN_00881510();
    int FUN_00931850();
    void FUN_00881680(int flag);
};

extern float DAT_01084838;

struct Settings970d50
{
    float FUN_00867da0();
    int FUN_00867c60();
    int FUN_00867d20();
    bool FUN_00867d60();
};
extern Settings970d50 DAT_011de7b8;
extern float DAT_011e0358;
extern int DAT_011e035c;
extern int DAT_011a39c4;
extern bool DAT_011e0360;
struct Actor970d50 : Actor
{
    void* FUN_005d43c0();
    bool FUN_00440d80();
    int FUN_007af430();
    void FUN_008a1800(int);
    int FUN_008d8520();
    void FUN_00893340(bool);
};
void __cdecl FUN_005ac190(Actor970d50*, void*);
struct ProcessQueue970d50
{
    void FUN_0096aaf0(MobileObject*, int);
};
struct Lists970d50 : ProcessLists
{
    void FUN_00970d50();
};

struct FUN_005723b0_Obj
{
    float FUN_005723b0(void* a1, unsigned char a2, int a3);
};
extern void* DAT_011dea3c;

struct S_972600_Crime
{
    int FUN_00726070();
    int FUN_0084e3a0();
    int FUN_0044ddc0();
    int FUN_0045cd60();
    bool IsActorInList(int);
};
struct S_972600_Node
{
    S_972600_Crime** FUN_006815c0();
    S_972600_Node* FUN_00726070();
};
struct S_972600_Lists
{
    int unk00;
    int unk04[16];
    S_972600_Node* unk44[6];
    bool HasMatchingCrime(int a, int b, int c, int d, int e, int f);
};

struct FUN_009726e0_idx
{
    int FUN_00726070();
};

struct FUN_009726e0_elem
{
    void FUN_00905330(FUN_009726e0_idx** pp);
};

struct FUN_009726e0_cls
{
    char pad[0x44];
    FUN_009726e0_elem* m_44[6];
    void FUN_009726e0(FUN_009726e0_idx* p);
};

class ContNode;

struct FUN_009727c0_list
{
    bool _ref_008256d0();
    Crime** FUN_006815c0();
};

ContNode* __fastcall FUN_00726070(ContNode* node);

struct FUN_009727c0_shell : public ProcessLists
{
    Crime* FUN_009727c0(int listIndex, unsigned short crimeIndex);
};

struct List_973590
{
    bool FUN_005f65d0(Actor*&);
    void FUN_005ae3d0(Actor*&);
};
struct Node_973590
{
    bool FUN_008256d0();
    Actor** FUN_006815c0();
    Node_973590* FUN_00726070();
};
struct Extra_973590
{
    int unk00;
    int unk04;
    int unk08;
    Node_973590* followers;
};
struct ExtraList_973590
{
    Extra_973590* FUN_00422700();
};
struct Actor_973590
{
    ExtraList_973590* FUN_005d43c0();
    TESPackage* FUN_009344a0();
    Actor* FUN_00881650();
};
struct Array_973590
{
    unsigned int FUN_005be5c0(int);
    MobileObject* FUN_00968670(unsigned int);
};
struct FUN_00973590_shell
{
    int unk00;
    Array_973590 processes;
    void FUN_00973590(Actor* target, List_973590* output);
};

struct S973_Process
{
    void* IsReady973();
};

struct S973_Base;

struct S973_Ref;

struct S973_Faction
{
    bool Contains973(S973_Ref* apObj);
};

struct S973_Actor
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsValid973();
    S973_Base* GetBase973();
    S973_Process* GetProc973();
};

struct S973_Base
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
    S973_Faction factions;
};

struct S973_Ref
{
    bool CanUse973(S973_Actor* apActor, bool abFlag);
    S973_Ref* GetObj973();
};

struct S973_Node
{
    S973_Actor** GetItem973();
    S973_Node* GetNext973();
};

struct S973_Array
{
    unsigned int GetCount973(int aiLevel);
    S973_Actor* GetAt973(unsigned int auiIndex);
};

struct FUN_00973ab0_shell
{
    int unk00;
    S973_Array kArray;
    S973_Actor* FindUsableActorInArray(S973_Ref* apRef);
};

struct FUN_00973cb0_cls : public ProcessLists
{
    void FUN_00973cb0(Actor* target);
};

// FUN_00973fd0 candidate (b6121)
class FnvArgObj
{
  public:
    void** m_ppVirtualMethodTable;
    virtual void Unk_00(void);
    virtual void Unk_01(void);
    virtual void Unk_02(void);
    virtual void Unk_03(void);
    virtual void Unk_04(void);
    virtual void Unk_05(void);
    virtual void Unk_06(void);
    virtual void Unk_07(void);
    virtual void Unk_08(void);
    virtual void Unk_09(void);
    virtual void Unk_0A(void);
    virtual void Unk_0B(void);
    virtual void Unk_0C(void);
    virtual void Unk_0D(void);
    virtual void Unk_0E(void);
    virtual void Unk_0F(void);
    virtual void Unk_10(void);
    virtual void Unk_11(void);
    virtual void Unk_12(void);
    virtual void Unk_13(void);
    virtual void Unk_14(void);
    virtual void Unk_15(void);
    virtual void Unk_16(void);
    virtual void Unk_17(void);
    virtual void Unk_18(void);
    virtual void Unk_19(void);
    virtual void Unk_1A(void);
    virtual void Unk_1B(void);
    virtual void Unk_1C(void);
    virtual void Unk_1D(void);
    virtual void Unk_1E(void);
    virtual void Unk_1F(void);
    virtual void Unk_20(void);
    virtual void Unk_21(void);
    virtual void Unk_22(void);
    virtual void Unk_23(void);
    virtual void Unk_24(void);
    virtual void Unk_25(void);
    virtual void Unk_26(void);
    virtual int Unk_9C(void);
};

class FnvTemp
{
  public:
    FnvTemp(FnvArgObj* arg);
    ~FnvTemp();
    int unk00;
};

class FnvSubObj
{
  public:
    int unk00;
    int unk04;
    void Process(FnvTemp* t);
};

class FUN_00973fd0_cls
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
    FnvSubObj m_58;
    FnvSubObj m_60;

    void FUN_00973fd0(FnvArgObj* arg);
};

struct ParticleObj
{
    void SetAppCulled(bool abCulled);
};
struct ParticleSource;

class BSTempEffectParticle : public BSTempEffect
{
  public:
    ParticleObj* GetParticleObject();
    ParticleSource* GetSource();
    void SetParentCell(TESObjectCELL* apCell);
};

struct TempEffectListOwner : public ProcessLists
{
    void RemoveParticleEffectsBySource(ParticleSource* apSource);
};

struct TESObjectREFR_9749
{
};
struct ObjV
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void Fn();
    int FUN_00441110();
    void SetByteAt24(bool);
};
struct Base9749
{
    void* FUN_006815c0();
};
struct BNode9749
{
    bool FUN_004a4460();
    BNode9749* FUN_00726070();
    void* FUN_006815c0();
};
struct Mid9749
{
    ObjV* FUN_00559450();
};
extern int DAT_011dc6b4;
bool __cdecl FUN_0043b300(const void*, ObjV*);
struct FUN_009749b0_shell
{
    char pad[0x60];
    BNode9749 list;
    void FUN_009749b0(int id);
};

struct ShaderHitTargetForm
{
    virtual void v00();
    virtual int GetKind();
};
struct ShaderHitTarget
{
    ShaderHitTargetForm* GetForm();
};
class MagicShaderHitEffect : public BSTempEffect
{
  public:
    virtual void v31();
    ShaderHitTarget* GetHitTarget();
    float GetTimeLeft();
    void Finish();
};
bool __cdecl IsValidShaderHitTarget(int aTarget);

struct ProcessListsEx : public ProcessLists
{
    bool FUN_00974e90(int aiKind, int aTarget);
};

struct TESSaveLoadGame
{
    unsigned short* GetSaveCountPtr();
    void SaveData(void* data, int size);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct PLTempEffectSaver : public ProcessLists
{
    void SaveTempEffects();
};

namespace fnv_00976680 {
struct Obj;
struct Obj
{
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
    virtual void d26();
    virtual void d27();
    virtual void d28();
    virtual void d29();
    virtual void d30();
    virtual void d31();
    virtual void d32();
    virtual void d33();
    virtual void d34();
    virtual void d35();
    virtual void d36();
    virtual void d37();
    virtual void d38();
    virtual void d39();
    virtual void d40();
    virtual void d41();
    virtual void d42();
    virtual void d43();
    virtual void d44();
    virtual void d45();
    virtual void d46();
    virtual void d47();
    virtual void d48();
    virtual void d49();
    virtual void d50();
    virtual void d51();
    virtual void d52();
    virtual void d53();
    virtual void d54();
    virtual void d55();
    virtual void d56();
    virtual void d57();
    virtual void d58();
    virtual void d59();
    virtual void d60();
    virtual void d61();
    virtual void d62();
    virtual void d63();
    virtual bool v100();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual Obj* v128();
    virtual void v12c(int a);
    virtual void d76();
    virtual void d77();
    virtual void d78();
    virtual void d79();
    virtual void d80();
    virtual void d81();
    virtual void d82();
    virtual void d83();
    virtual void d84();
    virtual void d85();
    virtual void d86();
    virtual void d87();
    virtual void d88();
    virtual void d89();
    virtual void d90();
    virtual void d91();
    virtual void d92();
    virtual void d93();
    virtual void d94();
    virtual void d95();
    virtual void d96();
    virtual void d97();
    virtual void d98();
    virtual void d99();
    virtual void d100();
    virtual void d101();
    virtual int v198();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual Obj* v20c();
    virtual void d132();
    virtual void v214();
    virtual void d134();
    virtual void d135();
    virtual bool v220();
    virtual bool v224();
    virtual void d138();
    virtual void d139();
    virtual void d140();
    virtual void v234();
    virtual void d142();
    virtual void d143();
    virtual void d144();
    virtual void d145();
    virtual void d146();
    virtual void d147();
    virtual void d148();
    virtual void d149();
    virtual void d150();
    virtual void d151();
    virtual void d152();
    virtual void d153();
    virtual void d154();
    virtual void d155();
    virtual void d156();
    virtual void d157();
    virtual void d158();
    virtual Obj* v27c();
    virtual void d160();
    virtual void d161();
    virtual void v288();
    virtual void d163();
    virtual void d164();
    virtual void d165();
    virtual void d166();
    virtual void d167();
    virtual void d168();
    virtual void d169();
    virtual void d170();
    virtual void d171();
    virtual void d172();
    virtual void d173();
    virtual void d174();
    virtual void d175();
    virtual void d176();
    virtual void v2c4(Obj* a, int b);
    virtual Obj* v2c8();
    virtual void d179();
    virtual void d180();
    virtual void d181();
    virtual void d182();
    virtual void d183();
    virtual void d184();
    virtual void d185();
    virtual void d186();
    virtual void d187();
    virtual void d188();
    virtual void d189();
    virtual void d190();
    virtual void d191();
    virtual void d192();
    virtual void d193();
    virtual void d194();
    virtual void d195();
    virtual void v310(int a);
    virtual void d197();
    virtual void d198();
    virtual void d199();
    virtual void d200();
    virtual void d201();
    virtual void d202();
    virtual void d203();
    virtual void d204();
    virtual void d205();
    virtual void d206();
    virtual void d207();
    virtual void d208();
    virtual void d209();
    virtual void d210();
    virtual void d211();
    virtual void d212();
    virtual void d213();
    virtual void d214();
    virtual void d215();
    virtual void d216();
    virtual void d217();
    virtual void d218();
    virtual void d219();
    virtual void d220();
    virtual void d221();
    virtual void d222();
    virtual void d223();
    virtual void d224();
    virtual void d225();
    virtual void d226();
    virtual void d227();
    virtual void d228();
    virtual void d229();
    virtual void d230();
    virtual void d231();
    virtual void d232();
    virtual void d233();
    virtual void d234();
    virtual void d235();
    virtual void d236();
    virtual void d237();
    virtual void d238();
    virtual void d239();
    virtual void d240();
    virtual void d241();
    virtual void d242();
    virtual void d243();
    virtual void d244();
    virtual void d245();
    virtual void d246();
    virtual void d247();
    virtual void d248();
    virtual void d249();
    virtual void d250();
    virtual void d251();
    virtual void d252();
    virtual void d253();
    virtual void d254();
    virtual void d255();
    virtual void d256();
    virtual void d257();
    virtual void d258();
    virtual void d259();
    virtual void d260();
    virtual void d261();
    virtual void d262();
    virtual void d263();
    virtual void d264();
    virtual void d265();
    virtual Obj* v428();
    virtual void d267();
    virtual void d268();
    virtual void d269();
    virtual void d270();
    virtual void d271();
    virtual void d272();
    virtual void d273();
    virtual void d274();
    virtual void d275();
    virtual void d276();
    virtual void d277();
    virtual void d278();
    virtual void d279();
    virtual void d280();
    virtual void d281();
    virtual void d282();
    virtual void d283();
    virtual void d284();
    virtual void d285();
    virtual void d286();
    virtual void v47c(Obj* a);
    virtual void d288();
    virtual void d289();
    virtual void d290();
    virtual void d291();
    virtual void d292();
    virtual void d293();
    virtual void d294();
    virtual void d295();
    virtual void v4a0();
    virtual void d297();
    virtual void d298();
    virtual void d299();
    virtual void d300();
    virtual void d301();
    virtual void d302();
    virtual void d303();
    virtual void d304();
    virtual void d305();
    virtual void d306();
    virtual void d307();
    virtual void d308();
    virtual void d309();
    virtual void d310();
    virtual void d311();
    virtual void d312();
    virtual void d313();
    virtual void d314();
    virtual void d315();
    virtual void d316();
    virtual void d317();
    virtual void d318();
    virtual void d319();
    virtual void d320();
    virtual void d321();
    virtual void d322();
    virtual void d323();
    virtual void d324();
    virtual void d325();
    virtual void d326();
    virtual void d327();
    virtual void d328();
    virtual void d329();
    virtual void d330();
    virtual void d331();
    virtual void d332();
    virtual void d333();
    virtual void d334();
    virtual void d335();
    virtual void d336();
    virtual void d337();
    virtual void d338();
    virtual void d339();
    virtual void d340();
    virtual void d341();
    virtual void d342();
    virtual void d343();
    virtual void d344();
    virtual void d345();
    virtual void d346();
    virtual void d347();
    virtual void d348();
    virtual void d349();
    virtual void d350();
    virtual void d351();
    virtual void d352();
    virtual void d353();
    virtual void d354();
    virtual void d355();
    virtual void d356();
    virtual void d357();
    virtual void d358();
    virtual void d359();
    virtual void d360();
    virtual void d361();
    virtual void d362();
    virtual void d363();
    virtual void d364();
    virtual void d365();
    virtual void d366();
    virtual void d367();
    virtual void d368();
    virtual void d369();
    virtual void d370();
    virtual void d371();
    virtual void d372();
    virtual void d373();
    virtual void d374();
    virtual void d375();
    virtual void d376();
    virtual void d377();
    virtual void d378();
    virtual void d379();
    virtual void d380();
    virtual void d381();
    virtual void d382();
    virtual void d383();
    virtual void d384();
    virtual void d385();
    virtual void d386();
    virtual void d387();
    virtual void d388();
    virtual void d389();
    virtual void d390();
    virtual void d391();
    virtual void d392();
    virtual void d393();
    virtual void d394();
    virtual void d395();
    virtual void d396();
    virtual void d397();
    virtual void d398();
    virtual void d399();
    virtual void d400();
    virtual void d401();
    virtual void d402();
    virtual void d403();
    virtual void d404();
    virtual void d405();
    virtual void d406();
    virtual void d407();
    virtual void d408();
    virtual void v664(Obj* a);
    virtual void d410();
    virtual void d411();
    virtual void d412();
    virtual void d413();
    virtual void d414();
    virtual void d415();
    virtual void d416();
    virtual void d417();
    virtual void d418();
    virtual void d419();
    virtual void d420();
    virtual void d421();
    virtual void d422();
    virtual void d423();
    virtual void d424();
    virtual void d425();
    virtual void d426();
    virtual void d427();
    virtual void d428();
    virtual void d429();
    virtual void d430();
    virtual void d431();
    virtual void d432();
    virtual void d433();
    virtual void d434();
    virtual void d435();
    virtual void d436();
    virtual void d437();
    virtual void d438();
    virtual void d439();
    virtual void d440();
    virtual void d441();
    virtual void d442();
    virtual void d443();
    virtual void d444();
    virtual void d445();
    virtual void d446();
    virtual void d447();
    virtual void d448();
    virtual void d449();
    virtual void d450();
    virtual void d451();
    virtual void d452();
    virtual void d453();
    virtual void d454();
    virtual void d455();
    virtual void d456();
    virtual void d457();
    virtual void d458();
    virtual void d459();
    virtual void d460();
    virtual void d461();
    virtual void d462();
    virtual void d463();
    virtual void d464();
    virtual void d465();
    virtual void d466();
    virtual void d467();
    virtual void d468();
    virtual void d469();
    virtual void d470();
    virtual void d471();
    virtual void d472();
    virtual void d473();
    virtual void d474();
    virtual void d475();
    virtual void d476();
    virtual void d477();
    virtual void d478();
    virtual void d479();
    virtual void d480();
    virtual void d481();
    virtual void d482();
    virtual void d483();
    virtual void d484();
    virtual void d485();
    virtual void d486();
    virtual void d487();
    virtual void d488();
    virtual void d489();
    virtual void d490();
    virtual void d491();
    virtual void v7b0(Obj* a);
    int u04;
    int u08;
    Obj* f0c;
    int u10;
    Obj* f14;
    int u18;
    int u1c;
    int u20;
    int u24;
    int u28;
    int u2c;
    int u30;
    int u34;
    int u38;
    int u3c;
    int u40;
    int u44;
    int u48;
    int u4c;
    int u50;
    int u54;
    int u58;
    int u5c;
    int u60;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    int u80;
    int u84;
    int u88;
    int u8c;
    int u90;
    int u94;
    int u98;
    int u9c;
    int ua0;
    int ua4;
    int ua8;
    int uac;
    int ub0;
    int ub4;
    int ub8;
    int ubc;
    Obj* fc0;
    Obj* FUN_005d43c0();
    Obj* FUN_00422700();
    void FUN_00905330(void* a);
    Obj* FUN_008d8520();
    Obj* FUN_004fd380();
    void FUN_0057bd60(int a);
    bool FUN_00576d30();
    Obj* FUN_00881510();
    bool FUN_00674d40();
    int FUN_0041ca90();
    Obj* FUN_00671d10();
    Obj* FUN_00680020();
    void FUN_00672fc0(int a);
    Obj* FUN_00676140(Obj* a);
    void FUN_00671d30(int a);
    Obj* FUN_00881650();
    bool FUN_009336c0();
    Obj* FUN_009344a0();
    void FUN_00881680(int a);
    void FUN_008c4f10(int a);
    Obj* FUN_00410220(unsigned char a);
    bool FUN_008a6650(int a);
    Obj* FUN_005e3fc0();
    void FUN_00994ef0(int a);
    void FUN_008a6730(Obj* a);
    bool FUN_00493bb0();
    void FUN_0097f9c0(Obj* a);
    Obj* FUN_00422690(Obj* a);
    void FUN_00881620(int a);
    void FUN_009c4c80(Obj* a);
    bool FUN_00440da0();
    void FUN_009b28a0(Obj* a);
    void ProcessCombatTarget(Obj* a);
};
struct ArrObj
{
    int data[16];
    unsigned int FUN_005be5c0(unsigned int a);
    Obj* FUN_00968670(unsigned int a);
};
struct ListNode
{
    bool FUN_008256d0();
    Obj** FUN_006815c0();
    ListNode* FUN_00726070();
};
extern Obj* DAT_011f1958;
extern Obj* DAT_011dea3c;
struct Host
{
    int u00;
    ArrObj arr;
    int p44;
    int p48;
    int p4c;
    int p50;
    int p54;
    int p58;
    int p5c;
    int p60;
    int p64;
    int p68;
    int p6c;
    int p70;
    int p74;
    ListNode node78;
    void RemoveActor(Obj* a);
    void FUN_00976680(Obj* param);
};

}  // namespace fnv_00976680

struct ProcStub
{
    virtual void P_v000();
    virtual void P_v001();
    virtual void P_v002();
    virtual void P_v003();
    virtual void P_v004();
    virtual void P_v005();
    virtual void P_v006();
    virtual void P_v007();
    virtual void P_v008();
    virtual void P_v009();
    virtual void P_v010();
    virtual void P_v011();
    virtual void P_v012();
    virtual void P_v013();
    virtual void P_v014();
    virtual void P_v015();
    virtual void P_v016();
    virtual void P_v017();
    virtual void P_v018();
    virtual void P_v019();
    virtual void P_v020();
    virtual void P_v021();
    virtual void P_v022();
    virtual void P_v023();
    virtual void P_v024();
    virtual void P_v025();
    virtual void P_v026();
    virtual void P_v027();
    virtual void P_v028();
    virtual void P_v029();
    virtual void P_v030();
    virtual void P_v031();
    virtual void P_v032();
    virtual void P_v033();
    virtual void P_v034();
    virtual void P_v035();
    virtual void P_v036();
    virtual void P_v037();
    virtual void P_v038();
    virtual void P_v039();
    virtual void P_v040();
    virtual void P_v041();
    virtual void P_v042();
    virtual void P_v043();
    virtual void P_v044();
    virtual void P_v045();
    virtual void P_v046();
    virtual void P_v047();
    virtual void P_v048();
    virtual void P_v049();
    virtual void P_v050();
    virtual void P_v051();
    virtual void P_v052();
    virtual void P_v053();
    virtual void P_v054();
    virtual void P_v055();
    virtual void P_v056();
    virtual void P_v057();
    virtual void P_v058();
    virtual void P_v059();
    virtual void P_v060();
    virtual void P_v061();
    virtual void P_v062();
    virtual void P_v063();
    virtual void P_v064();
    virtual void Upd104();
    virtual void P_v066();
    virtual void P_v067();
    virtual void P_v068();
    virtual void P_v069();
    virtual void P_v070();
    virtual void P_v071();
    virtual void P_v072();
    virtual void P_v073();
    virtual void P_v074();
    virtual void P_v075();
    virtual void P_v076();
    virtual void P_v077();
    virtual void P_v078();
    virtual void P_v079();
    virtual void P_v080();
    virtual void P_v081();
    virtual void P_v082();
    virtual void P_v083();
    virtual void P_v084();
    virtual void P_v085();
    virtual void P_v086();
    virtual void P_v087();
    virtual void P_v088();
    virtual void P_v089();
    virtual void P_v090();
    virtual void P_v091();
    virtual void Add170(void* a);
    virtual void P_v093();
    virtual void P_v094();
    virtual void P_v095();
    virtual void P_v096();
    virtual void P_v097();
    virtual void P_v098();
    virtual void P_v099();
    virtual void P_v100();
    virtual void P_v101();
    virtual void P_v102();
    virtual void P_v103();
    virtual void P_v104();
    virtual void P_v105();
    virtual void P_v106();
    virtual void P_v107();
    virtual void P_v108();
    virtual void P_v109();
    virtual void P_v110();
    virtual void P_v111();
    virtual void P_v112();
    virtual void P_v113();
    virtual void P_v114();
    virtual void P_v115();
    virtual void P_v116();
    virtual void P_v117();
    virtual void Add1d8(void* a);
    virtual void P_v119();
    virtual void P_v120();
    virtual void P_v121();
    virtual void P_v122();
    virtual void P_v123();
    virtual void P_v124();
    virtual void P_v125();
    virtual void P_v126();
    virtual void P_v127();
    virtual void P_v128();
    virtual void P_v129();
    virtual void P_v130();
    virtual void P_v131();
    virtual void P_v132();
    virtual void P_v133();
    virtual void P_v134();
    virtual void P_v135();
    virtual void P_v136();
    virtual void P_v137();
    virtual void P_v138();
    virtual void P_v139();
    virtual void P_v140();
    virtual void P_v141();
    virtual void P_v142();
    virtual void P_v143();
    virtual void P_v144();
    virtual void P_v145();
    virtual void P_v146();
    virtual void P_v147();
    virtual void P_v148();
    virtual void P_v149();
    virtual void P_v150();
    virtual void P_v151();
    virtual void P_v152();
    virtual void P_v153();
    virtual void P_v154();
    virtual void P_v155();
    virtual void P_v156();
    virtual void P_v157();
    virtual void P_v158();
    virtual void P_v159();
    virtual void P_v160();
    virtual void P_v161();
    virtual void P_v162();
    virtual void P_v163();
    virtual void P_v164();
    virtual void P_v165();
    virtual void P_v166();
    virtual void P_v167();
    virtual void P_v168();
    virtual void P_v169();
    virtual void P_v170();
    virtual void P_v171();
    virtual void P_v172();
    virtual void P_v173();
    virtual void P_v174();
    virtual void P_v175();
    virtual void P_v176();
    virtual void P_v177();
    virtual void P_v178();
    virtual void P_v179();
    virtual void P_v180();
    virtual void P_v181();
    virtual void P_v182();
    virtual void P_v183();
    virtual void P_v184();
    virtual void P_v185();
    virtual void P_v186();
    virtual void P_v187();
    virtual void P_v188();
    virtual void P_v189();
    virtual void P_v190();
    virtual void P_v191();
    virtual void P_v192();
    virtual void P_v193();
    virtual void P_v194();
    virtual void P_v195();
    virtual void P_v196();
    virtual void P_v197();
    virtual void P_v198();
    virtual void P_v199();
    virtual void P_v200();
    virtual void P_v201();
    virtual void P_v202();
    virtual void P_v203();
    virtual void P_v204();
    virtual void P_v205();
    virtual void P_v206();
    virtual void P_v207();
    virtual void P_v208();
    virtual void P_v209();
    virtual void P_v210();
    virtual void P_v211();
    virtual void P_v212();
    virtual void P_v213();
    virtual void P_v214();
    virtual void P_v215();
    virtual void P_v216();
    virtual void P_v217();
    virtual void P_v218();
    virtual void P_v219();
    virtual void P_v220();
    virtual void P_v221();
    virtual void P_v222();
    virtual void P_v223();
    virtual void P_v224();
    virtual void P_v225();
    virtual void P_v226();
    virtual void P_v227();
    virtual void P_v228();
    virtual void P_v229();
    virtual void P_v230();
    virtual void P_v231();
    virtual void P_v232();
    virtual void P_v233();
    virtual void P_v234();
    virtual void P_v235();
    virtual void P_v236();
    virtual void P_v237();
    virtual void P_v238();
    virtual void P_v239();
    virtual void P_v240();
    virtual void P_v241();
    virtual void P_v242();
    virtual void P_v243();
    virtual void P_v244();
    virtual void P_v245();
    virtual void P_v246();
    virtual void P_v247();
    virtual void P_v248();
    virtual void P_v249();
    virtual void P_v250();
    virtual void P_v251();
    virtual void P_v252();
    virtual void P_v253();
    virtual void P_v254();
    virtual void P_v255();
    virtual void P_v256();
    virtual void P_v257();
    virtual void P_v258();
    virtual void P_v259();
    virtual void P_v260();
    virtual void P_v261();
    virtual void P_v262();
    virtual void P_v263();
    virtual void P_v264();
    virtual void P_v265();
    virtual void P_v266();
    virtual void P_v267();
    virtual void P_v268();
    virtual void P_v269();
    virtual void P_v270();
    virtual void P_v271();
    virtual void P_v272();
    virtual void P_v273();
    virtual void P_v274();
    virtual void P_v275();
    virtual void P_v276();
    virtual void P_v277();
    virtual void P_v278();
    virtual void P_v279();
    virtual void P_v280();
    virtual void P_v281();
    virtual void P_v282();
    virtual void P_v283();
    virtual void P_v284();
    virtual void P_v285();
    virtual void P_v286();
    virtual void P_v287();
    virtual void P_v288();
    virtual void P_v289();
    virtual void P_v290();
    virtual void P_v291();
    virtual void P_v292();
    virtual void P_v293();
    virtual void P_v294();
    virtual void P_v295();
    virtual void P_v296();
    virtual void P_v297();
    virtual void P_v298();
    virtual void P_v299();
    virtual void P_v300();
    virtual void P_v301();
    virtual void P_v302();
    virtual void P_v303();
    virtual void P_v304();
    virtual void P_v305();
    virtual void P_v306();
    virtual void P_v307();
    virtual void P_v308();
    virtual void P_v309();
    virtual void P_v310();
    virtual void P_v311();
    virtual void P_v312();
    virtual void P_v313();
    virtual void P_v314();
    virtual void P_v315();
    virtual void P_v316();
    virtual void P_v317();
    virtual void P_v318();
    virtual void P_v319();
    virtual void Add500(void* a, int b);
};
struct BodyStub;
struct FilterStub
{
    int F4a3a20();
};
struct BodyStub
{
    void Fca2ad0(int a);
    void Fca1410();
};
struct ActStub
{
    virtual void A_v000();
    virtual void A_v001();
    virtual void A_v002();
    virtual void A_v003();
    virtual void A_v004();
    virtual void A_v005();
    virtual void A_v006();
    virtual void A_v007();
    virtual void A_v008();
    virtual void A_v009();
    virtual void A_v010();
    virtual void A_v011();
    virtual void A_v012();
    virtual void A_v013();
    virtual void A_v014();
    virtual void A_v015();
    virtual void A_v016();
    virtual void A_v017();
    virtual void A_v018();
    virtual void A_v019();
    virtual void A_v020();
    virtual void A_v021();
    virtual void A_v022();
    virtual void A_v023();
    virtual void A_v024();
    virtual void A_v025();
    virtual void A_v026();
    virtual void A_v027();
    virtual void A_v028();
    virtual void A_v029();
    virtual void A_v030();
    virtual void A_v031();
    virtual void A_v032();
    virtual void A_v033();
    virtual void A_v034();
    virtual void A_v035();
    virtual void A_v036();
    virtual void A_v037();
    virtual void A_v038();
    virtual void A_v039();
    virtual void A_v040();
    virtual void A_v041();
    virtual void A_v042();
    virtual void A_v043();
    virtual void A_v044();
    virtual void A_v045();
    virtual void A_v046();
    virtual void A_v047();
    virtual void A_v048();
    virtual void A_v049();
    virtual void A_v050();
    virtual void A_v051();
    virtual void A_v052();
    virtual void A_v053();
    virtual void A_v054();
    virtual void A_v055();
    virtual void A_v056();
    virtual void A_v057();
    virtual void A_v058();
    virtual void A_v059();
    virtual void A_v060();
    virtual void A_v061();
    virtual void A_v062();
    virtual void A_v063();
    virtual bool Is100();
    virtual void A_v065();
    virtual void A_v066();
    virtual void A_v067();
    virtual void A_v068();
    virtual void A_v069();
    virtual void A_v070();
    virtual void A_v071();
    virtual void A_v072();
    virtual void A_v073();
    virtual void A_v074();
    virtual void A_v075();
    virtual void A_v076();
    virtual void A_v077();
    virtual void A_v078();
    virtual void A_v079();
    virtual void A_v080();
    virtual void A_v081();
    virtual void A_v082();
    virtual void A_v083();
    virtual void A_v084();
    virtual void A_v085();
    virtual void A_v086();
    virtual void A_v087();
    virtual void A_v088();
    virtual void A_v089();
    virtual void A_v090();
    virtual void A_v091();
    virtual void A_v092();
    virtual void A_v093();
    virtual void A_v094();
    virtual void A_v095();
    virtual void A_v096();
    virtual void A_v097();
    virtual void A_v098();
    virtual void A_v099();
    virtual void A_v100();
    virtual void A_v101();
    virtual void A_v102();
    virtual void A_v103();
    virtual void A_v104();
    virtual void A_v105();
    virtual void A_v106();
    virtual void A_v107();
    virtual void A_v108();
    virtual void A_v109();
    virtual void A_v110();
    virtual void A_v111();
    virtual void A_v112();
    virtual void A_v113();
    virtual void A_v114();
    virtual void A_v115();
    virtual int Get1d0(int a);
    virtual void A_v117();
    virtual void A_v118();
    virtual void A_v119();
    virtual void A_v120();
    virtual void A_v121();
    virtual void A_v122();
    virtual void A_v123();
    virtual void A_v124();
    virtual void A_v125();
    virtual void A_v126();
    virtual void A_v127();
    virtual void A_v128();
    virtual void A_v129();
    virtual void A_v130();
    virtual void A_v131();
    virtual void A_v132();
    virtual void A_v133();
    virtual void A_v134();
    virtual void A_v135();
    virtual bool Is220();
    virtual void A_v137();
    virtual void A_v138();
    virtual bool Is22c(int a);
    virtual void A_v140();
    virtual void A_v141();
    virtual void A_v142();
    virtual void A_v143();
    virtual void A_v144();
    virtual void A_v145();
    virtual void A_v146();
    virtual void A_v147();
    virtual void A_v148();
    virtual void A_v149();
    virtual void A_v150();
    virtual void A_v151();
    virtual void A_v152();
    virtual void A_v153();
    virtual void A_v154();
    virtual void A_v155();
    virtual void A_v156();
    virtual void A_v157();
    virtual void A_v158();
    virtual void A_v159();
    virtual void A_v160();
    virtual void A_v161();
    virtual void A_v162();
    virtual void A_v163();
    virtual void A_v164();
    virtual void A_v165();
    virtual void A_v166();
    virtual void A_v167();
    virtual void A_v168();
    virtual void A_v169();
    virtual void A_v170();
    virtual void A_v171();
    virtual void A_v172();
    virtual void A_v173();
    virtual void A_v174();
    virtual void A_v175();
    virtual void A_v176();
    virtual void A_v177();
    virtual void A_v178();
    virtual void A_v179();
    virtual void A_v180();
    virtual void A_v181();
    virtual void A_v182();
    virtual void A_v183();
    virtual void A_v184();
    virtual void A_v185();
    virtual void A_v186();
    virtual void A_v187();
    virtual void A_v188();
    virtual void A_v189();
    virtual void A_v190();
    virtual void A_v191();
    virtual void A_v192();
    virtual void A_v193();
    virtual void A_v194();
    virtual void A_v195();
    virtual void A_v196();
    virtual void A_v197();
    virtual void A_v198();
    virtual void A_v199();
    virtual void A_v200();
    virtual void A_v201();
    virtual void A_v202();
    virtual void A_v203();
    virtual void A_v204();
    virtual void A_v205();
    virtual void A_v206();
    virtual void A_v207();
    virtual void A_v208();
    virtual void A_v209();
    virtual void A_v210();
    virtual void Upd34c(float dt, bool b);
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
    BodyStub* unkB0;
    void F8ba600();
    ProcStub* F8d8520();
    bool F576d30();
    FilterStub* F931ed0(int* out);
    void F9b17a0(float dt);
};
struct PlayerStub
{
    ProcStub* F8d8520();
    bool F94df60();
};
extern PlayerStub* g_player;
bool __fastcall GetField18Byte(BodyStub* b);
void __cdecl FUN_0062c430(ActStub* a);
struct PAStub
{
    int unk00;
    unsigned int F5be5c0(int lvl);
    ActStub* F968670(unsigned int i);
};
struct BodyHolder
{
    BodyStub* body;
};
struct PLStub
{
    int unk00;
    PAStub arr;
    void F978890(float dt);
    void FUN_009781d0(float dt);
};

namespace fnv_009eb500 {
struct RefObj
{
    void FUN_00564db0(int);
};
struct DispatchMembers
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int unk10;
    unsigned int field14;
    DispatchMembers();
    ~DispatchMembers();
};
struct FloatValue
{
    float v;
    FloatValue();
    FloatValue(float);
};
struct SingletonData
{
    unsigned int FUN_009eb620();
};
struct RandomData
{
    int FUN_00867d20();
    signed char FUN_00867d60();
    int FUN_00867c60();
};
extern "C" SingletonData DAT_011e0e80;
extern "C" RandomData DAT_011de7b8;
float __cdecl FUN_00435dd0();
struct FUN_009eb500
{
    int field00;
    unsigned int field04;
    RefObj* field08;
    unsigned int field0c;
    bool field10;
    unsigned int field14;
    unsigned int field18;
    DispatchMembers members;
    FloatValue point;
    unsigned int field38;
    FUN_009eb500(unsigned int, RefObj*, unsigned int, unsigned int, unsigned int, unsigned int);
};
}  // namespace fnv_009eb500

// FUN_00c44c90: TaskQueueParallelManager wrapper that forwards a callback
// and one argument to the task queue base class.
typedef void(__cdecl* FUN_00c44d90_t)(void);

extern "C" void __cdecl RunWorkItems(void);

struct TaskQueueBase
{
    void __thiscall FUN_00c44c40(FUN_00c44d90_t callback, int argument);
};

struct TaskQueueShell : public TaskQueueBase
{
    void FUN_00c44c90(int argument);
};

struct RefStub
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsValidTarget();
    unsigned int GetDetectFlags();
};

extern RefStub* g_thePlayerRef;
float __cdecl CalcLow(float);
float __cdecl CalcHigh(float);

struct OwnerStub
{
    RefStub* GetTarget();
    float GetDistance(RefStub*, int, int);
    bool CanCheck();
    unsigned int UpdateDetectionFlags(unsigned int aFlags, float afValue, int aUnused);
};

struct SoundHandleStub
{
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    int eState;
    SoundHandleStub();
    ~SoundHandleStub();
    SoundHandleStub& operator=(const SoundHandleStub& rhs);
    bool IsPlaying();
    bool Play(bool abUnk);
};

struct AudioStub
{
    static AudioStub* GetSingleton();
    SoundHandleStub GetSoundHandleByEditorID(const char* apEditorID, unsigned int auiFlags);
};

struct ActorSoundStub
{
    const char* GetSoundName(int aiType, bool abA, bool abB);
    SoundHandleStub PlaySoundAt(const char* apName, int aiUnk, unsigned int auiFlags, bool abUnk);
    void PlayActorSound(int aiType, bool abA, bool abB);
};

extern ActorSoundStub* _g_thePlayerStub;

struct LowListArray
{
    unsigned int FUN_005de0f0(int);
    unsigned int FUN_005be5c0(int);
    MobileObject* FUN_00968670(unsigned int);
    void FUN_0096aaf0(MobileObject*, int);
};
struct LowListObject : MobileObject
{
    bool FUN_00493bb0();
    void FUN_0092f190();
};
struct LowListProcessLists : ProcessLists
{
    void UpdateLowListProcessLists(float delta, bool);
};

struct Proc96
{
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void p63();
    virtual void p64();
    virtual void p65();
    virtual void p66();
    virtual void p67();
    virtual void p68();
    virtual void p69();
    virtual void p70();
    virtual void p71();
    virtual void p72();
    virtual void p73();
    virtual void p74();
    virtual void p75();
    virtual void p76();
    virtual void p77();
    virtual void p78();
    virtual void p79();
    virtual void p80();
    virtual void p81();
    virtual void p82();
    virtual void p83();
    virtual void p84();
    virtual void p85();
    virtual void p86();
    virtual void p87();
    virtual void p88();
    virtual void p89();
    virtual void p90();
    virtual void p91();
    virtual void p92();
    virtual void p93();
    virtual void p94();
    virtual void p95();
    virtual void p96();
    virtual void p97();
    virtual void p98();
    virtual void p99();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void p111();
    virtual void p112();
    virtual void p113();
    virtual void p114();
    virtual void p115();
    virtual void p116();
    virtual void p117();
    virtual void p118();
    virtual void p119();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual bool ready();
    float FUN_007df1f0();
};
struct Obj96
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool isActor();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void update(float);
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual bool destroyed();
    bool FUN_00576d30();
    bool FUN_00440da0();
    bool FUN_00440d80();
    int FUN_00931850();
    Proc96* FUN_008d8520();
    void FUN_0092f190();
    void FUN_00565870();
    int FUN_004f8960();
    void FUN_00407800(int);
};
struct Array96
{
    unsigned int FUN_005de0f0(int);
    unsigned int FUN_005be5c0(int);
    MobileObject* FUN_00968670(unsigned int);
    void FUN_0096aaf0(MobileObject*, int);
};
struct Shell96
{
    int unk0;
    Array96 arr;
    void FUN_0096b810(float, int);
};

struct ActorEntity;
struct DetectProcess
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual bool Check(ActorEntity*);
};
struct DetectComponent
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual bool Check();
};
struct DetectMisc
{
    bool FUN_00705cf0();
};
struct DetectBase
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
    int field2c;
    DetectComponent component;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
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
    DetectMisc misc;
};
struct ActorEntity
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActor();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual int Active();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool State(int);
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void SetTimer(float);
    virtual float Timer();
    virtual void Reset();
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
    int field2c;
    int field30;
    int field34;
    int field38;
    int field3c;
    int field40;
    int field44;
    int field48;
    int field4c;
    int field50;
    int field54;
    int field58;
    int field5c;
    int field60;
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
    int fieldb4;
    int fieldb8;
    unsigned char enabled;
    float FUN_005723b0(ActorEntity*, int, int);
    bool FUN_00437bd0();
    DetectBase* Base();
    DetectProcess* Process();
    unsigned char FUN_00493bb0();
    int FUN_008a0d10(int, ActorEntity*, bool*, unsigned char, int, int, bool*);
    bool IsHostileTo(ActorEntity*, int, int*, int);
    bool FUN_008bc700(ActorEntity*);
    bool FUN_008a78f0(int);
    void FUN_008c8bb0(int);
    void FUN_00966f20(ActorEntity*, bool, int);
    void FUN_00967350(ActorEntity*);
};
struct DetectArray
{
    unsigned int Count(int);
    unsigned int Head(int);
    ActorEntity* Item(unsigned int);
};
struct DetectTime
{
    float Delta();
};
extern DetectTime DAT_011f6394;
struct DetectLoad
{
    bool FUN_0047c850();
};
extern DetectLoad* DAT_011de45c;
struct DetectInterface
{
    float FUN_007014e0(int);
};
extern DetectInterface* DAT_011d8804;
struct DetectSetting
{
    float* Value();
};
extern DetectSetting DAT_011ccf94, DAT_011d13c8;
float __cdecl FUN_0040ebd0(float, float);
float RandomFloat(float, float);
struct DetectionLists
{
    int field00;
    DetectArray actors;
    void FUN_0096e3c0(ActorEntity*);
    void UpdateDetection();
};
extern DetectionLists DAT_011e0e80;

namespace fnv_0096d810 {
extern const double DAT_01012060;
extern const double DAT_01011590;

class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT aeContext, bool abPush, const char* apFile, int aiLine);
    ~AutoMemContext();
    int aiMemoryContext;
};

struct FUN_0084d030_timer
{
    float FUN_0084d030();
};
extern FUN_0084d030_timer DAT_011f6394;

struct FUN_009640b0_player
{
    int FUN_009640b0();
    int GetActionObjectItemId();
};

struct FUN_0040fbf0_lock
{
    bool FUN_0078d200();
    void FUN_0040fbf0(char* apName);
    void FUN_0040fba0();
};

void __cdecl FUN_008d5bc0();
void __cdecl FUN_008d1560();
void __cdecl FUN_004772f0();
unsigned char __cdecl FUN_00525420();
int& __fastcall FUN_0043d4d0(int* apValue);
extern int DAT_011c3ea4;

struct FUN_0096d810_shell : public ProcessLists
{
    float FUN_0096d490();
    void FUN_0096d4b0(float afTime);
    void StartActorDialogue(int a1, int a2, int a3);
    void UpdateLowProcesses(float afTime, bool abFlag);
    void UpdateLowListProcessLists(float afTime, bool abFlag);
    void FUN_0096b810(float afTime, bool abFlag);
    void UpdateCrimeLists();
    void FUN_0096d810();
};

}  // namespace fnv_0096d810

namespace fnv_0096db30 {
struct Obj96;
struct Proc96
{
    float FUN_007df1f0();
    void UpdateSelectionTimer(Obj96*);
};
struct Obj96
{
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
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
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual void V53();
    virtual void V54();
    virtual void V55();
    virtual void V56();
    virtual void V57();
    virtual void V58();
    virtual void V59();
    virtual void V60();
    virtual void V61();
    virtual void V62();
    virtual void V63();
    virtual bool V64();
    virtual void V65();
    virtual void V66();
    virtual void V67();
    virtual void V68();
    virtual void V69();
    virtual void V70();
    virtual void V71();
    virtual void V72();
    virtual void V73();
    virtual void V74();
    virtual void V75();
    virtual void V76();
    virtual void V77();
    virtual void V78();
    virtual void V79();
    virtual void V80();
    virtual void V81();
    virtual void V82();
    virtual void V83();
    virtual void V84();
    virtual void V85();
    virtual void V86();
    virtual void V87();
    virtual void V88();
    virtual void V89();
    virtual void V90();
    virtual void V91();
    virtual void V92();
    virtual void V93();
    virtual void V94();
    virtual void V95();
    virtual void V96();
    virtual void V97();
    virtual void V98();
    virtual void V99();
    virtual void V100();
    virtual void V101();
    virtual void V102();
    virtual void V103();
    virtual void V104();
    virtual void V105();
    virtual void V106();
    virtual void V107();
    virtual void V108();
    virtual void V109();
    virtual void V110();
    virtual void V111();
    virtual void V112();
    virtual void V113();
    virtual void V114();
    virtual void V115();
    virtual void V116();
    virtual void V117();
    virtual void V118();
    virtual void V119();
    virtual void V120();
    virtual void V121();
    virtual void V122();
    virtual void V123();
    virtual void V124();
    virtual void V125();
    virtual void V126();
    virtual void V127();
    virtual void V128();
    virtual void V129();
    virtual void V130();
    virtual void V131();
    virtual void V132();
    virtual void V133();
    virtual void V134();
    virtual void V135();
    virtual bool V136();
    virtual bool V137();
    virtual void V138();
    virtual void V139();
    virtual void V140();
    virtual void V141();
    virtual void V142();
    virtual void V143();
    virtual void V144();
    virtual void V145();
    virtual void V146();
    virtual void V147();
    virtual void V148();
    virtual void V149();
    virtual void V150();
    virtual void V151();
    virtual void V152();
    virtual void V153();
    virtual void V154();
    virtual void V155();
    virtual void V156();
    virtual void V157();
    virtual void V158();
    virtual void V159();
    virtual void V160();
    virtual void V161();
    virtual void V162();
    virtual void V163();
    virtual void V164();
    virtual void V165();
    virtual void V166();
    virtual void V167();
    virtual void V168();
    virtual void V169();
    virtual void V170();
    virtual void V171();
    virtual void V172();
    virtual void V173();
    virtual void V174();
    virtual void V175();
    virtual void V176();
    virtual void V177();
    virtual void V178();
    virtual void V179();
    virtual void V180();
    virtual void V181();
    virtual void V182();
    virtual void V183();
    virtual void V184();
    virtual void V185();
    virtual void V186();
    virtual void V187();
    virtual void V188();
    virtual void V189();
    virtual void V190();
    virtual void V191();
    virtual void V192();
    virtual void V193();
    virtual void V194();
    virtual void V195();
    virtual void V196();
    virtual void V197();
    virtual void V198();
    virtual void V199();
    virtual void V200();
    virtual void V201();
    virtual void V202();
    virtual void V203();
    virtual void V204();
    virtual void V205();
    virtual void V206();
    virtual void V207();
    virtual void V208();
    virtual void V209();
    virtual void V210(float, bool);
    bool FUN_00576d30();
    Proc96* FUN_008d8520();
};
struct Array96
{
    unsigned int FUN_005de0f0(int);
    unsigned int FUN_005be5c0(int);
    Obj96* FUN_00968670(unsigned int);
};
struct Global96
{
    Array96* FUN_00717e50();
};
extern Global96 DAT_011e0e80;
struct TimeGlobal
{
    unsigned int GetTimeStamp();
};
extern TimeGlobal g_timeGlobal;
struct FUN_009bec10_shell
{
    void FUN_009bec10(float);
};
struct FUN_009ae580_shell
{
    void FUN_009ae580(float);
};
struct Target96
{
    void FUN_0096db30(float delta, bool flag, int level);
};
}  // namespace fnv_0096db30

struct Controller96
{
    unsigned int FUN_0084e3a0();
};
struct Actor96
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActor();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual Controller96* GetController();
    BaseProcess* FUN_008d8520();
};
struct EntryArray96
{
    unsigned int FUN_0055b980();
    Actor96* FUN_00968670(unsigned int);
};
struct FUN_0096a2d0
{
    Actor96* data;
    FUN_0096a2d0* next;
    FUN_0096a2d0();
    void FUN_005ae3d0(Actor* const&);
};
TESObjectREFR* __cdecl FUN_004839c0(unsigned int);
struct Target96
{
    int unk00;
    EntryArray96 entries;
    FUN_0096a2d0* FUN_0096f450(unsigned int, Actor96*);
};

namespace fnv_0096f600 {
struct ExtraFollower
{
    int f0;
    int f4;
    int f8;
    BSSimpleList<TESObjectREFR*>* pNext;
};
struct FUN_00422700_shell
{
    ExtraFollower* FUN_00422700();
};
struct FUN_00422690_shell
{
    void FUN_00422690(Actor*);
};
struct EffectSettingShell
{
    TESObjectLIGH* GetLight();
};
struct EffectSetting
{
    void SetLight(TESObjectLIGH*);
};
struct DetEv18
{
    char pad[0x18];
    Actor* p18;
};
struct TopicInfoArray
{
    unsigned int FUN_005be5c0(int);
    Actor* FUN_00968670(unsigned int);
};
struct TESChallenge
{
    Actor* GetProgressValue();
};
struct InterfaceManager
{
    Actor* FUN_00874480();
};
struct FUN_008b3200_shell
{
    void FUN_008b3200(Actor*);
};
struct FUN_00419ea0_shell
{
    Actor* FUN_00419ea0();
};
struct FUN_00419dc0_shell
{
    void FUN_00419dc0(int);
};
struct FUN_0044ddc0_shell
{
    Actor* FUN_0044ddc0();
};
struct FUN_0041ca90
{
    int get();
};
struct FUN_008d80e0_shell
{
    Actor* FUN_008d80e0();
};
struct FUN_00881680_shell
{
    void FUN_00881680(int);
};
struct Extra19
{
    char pad[0x14];
    Actor* p14;
};
struct Holder00420dd0
{
    Extra19* GetExtraData(unsigned char);
};
struct FUN_008a6650_shell
{
    bool FUN_008a6650(int);
};
struct SandboxTargetInfo;
struct ActorTargetSource
{
    SandboxTargetInfo* GetProcessTarget();
};
struct FUN_005e3fc0_shell
{
    Actor* FUN_005e3fc0();
};
struct FUN_00994ef0_Class
{
    void Set(int);
};
struct FUN_0098420_shell
{
    void FUN_009f8420(Actor*);
};
struct FUN_008a6730_Actor
{
    void FUN_008a6730(Actor*);
};
bool __fastcall IsInPackageType(Actor*);
struct IdleForm67
{
    Actor* FUN_0067f390();
    void FUN_0067f3c0(int);
};
struct ScriptGetText
{
    IdleForm67* GetText();
    char* GetData();
};
struct FUN_00680020_shell
{
    Actor* FUN_00680020();
};
struct FUN_00674d40_shell
{
    bool FUN_00674d40();
};
struct FUN_009336c0_shell
{
    bool FUN_009336c0();
};
struct Host00881620
{
    void FUN_00881620(int);
};
struct FUN_00881650_shell
{
    Actor* FUN_00881650();
};
struct FUN_0097f9c0_shell
{
    void FUN_0097f9c0(Actor*);
};
struct PkgDataVirt
{
    virtual void v0();
    virtual void v1(Actor*);
};
struct FUN_004212b0_shell
{
    PkgDataVirt* FUN_004212b0();
};
struct FUN_0041cb70_shell
{
    Actor* FUN_0041cb70();
};
struct FUN_0041cab0_shell
{
    void FUN_0041cab0(int);
};
struct FurnMarkShell
{
    void FUN_00c54550(float);
    void FUN_00568ab0(int);
    void FUN_0098ddd0(void*);
};
extern int DAT_011f426c;
struct ActorView : public TESObjectREFR
{
    virtual void a144();
    virtual void a145();
    virtual void a146();
    virtual void a147();
    virtual void a148();
    virtual void a149();
    virtual void a150();
    virtual void a151();
    virtual void a152();
    virtual void a153();
    virtual void a154();
    virtual void a155();
    virtual void a156();
    virtual void a157();
    virtual void a158();
    virtual void a159();
    virtual void a160();
    virtual void a161();
    virtual void a162();
    virtual void a163();
    virtual void a164();
    virtual void a165();
    virtual void a166();
    virtual void a167();
    virtual void a168();
    virtual void a169();
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual Actor* v2c8();
    virtual void b171();
    virtual void b172();
    virtual void b173();
    virtual void b174();
    virtual void b175();
    virtual void b176();
    virtual void b177();
    virtual void b178();
    virtual void b179();
    virtual void b180();
    virtual void b181();
    virtual void b182();
    virtual void b183();
    virtual void b184();
    virtual void b185();
    virtual void b186();
    virtual void b187();
    virtual void b188();
    virtual void b189();
    virtual void b190();
    virtual void b191();
    virtual void b192();
    virtual void b193();
    virtual void b194();
    virtual void b195();
    virtual void b196();
    virtual void b197();
    virtual void b198();
    virtual void b199();
    virtual void b200();
    virtual void b201();
    virtual void b202();
    virtual void b203();
    virtual void b204();
    virtual void b205();
    virtual void b206();
    virtual void b207();
    virtual void b208();
    virtual void b209();
    virtual void b210();
    virtual void b211();
    virtual void b212();
    virtual void b213();
    virtual void b214();
    virtual void b215();
    virtual void b216();
    virtual void b217();
    virtual void b218();
    virtual void b219();
    virtual void b220();
    virtual void b221();
    virtual void b222();
    virtual void b223();
    virtual void b224();
    virtual void b225();
    virtual void b226();
    virtual void b227();
    virtual void b228();
    virtual void b229();
    virtual void b230();
    virtual void b231();
    virtual void b232();
    virtual void b233();
    virtual void b234();
    virtual void b235();
    virtual void b236();
    virtual void b237();
    virtual void b238();
    virtual void b239();
    virtual void b240();
    virtual void b241();
    virtual void b242();
    virtual void b243();
    virtual void b244();
    virtual void b245();
    virtual void b246();
    virtual void b247();
    virtual void b248();
    virtual void b249();
    virtual void b250();
    virtual void b251();
    virtual void b252();
    virtual void b253();
    virtual void b254();
    virtual void b255();
    virtual void b256();
    virtual void b257();
    virtual void* v428();
};
struct PlayerView : public MobileObject
{
    virtual void c193();
    virtual void c194();
    virtual void c195();
    virtual void c196();
    virtual void c197();
    virtual void c198();
    virtual void c199();
    virtual void c200();
    virtual void c201();
    virtual void c202();
    virtual void c203();
    virtual void c204();
    virtual void c205();
    virtual void c206();
    virtual void c207();
    virtual void c208();
    virtual void c209();
    virtual void c210();
    virtual void c211();
    virtual void c212();
    virtual void c213();
    virtual void c214();
    virtual void c215();
    virtual void c216();
    virtual void c217();
    virtual void c218();
    virtual void c219();
    virtual void c220();
    virtual void c221();
    virtual void c222();
    virtual void c223();
    virtual void c224();
    virtual void c225();
    virtual void c226();
    virtual void c227();
    virtual void c228();
    virtual void c229();
    virtual void c230();
    virtual void c231();
    virtual void c232();
    virtual void c233();
    virtual void c234();
    virtual void c235();
    virtual void c236();
    virtual void c237();
    virtual void c238();
    virtual void c239();
    virtual void c240();
    virtual void c241();
    virtual void c242();
    virtual void c243();
    virtual void c244();
    virtual void c245();
    virtual void c246();
    virtual void c247();
    virtual void c248();
    virtual void c249();
    virtual void c250();
    virtual void c251();
    virtual void c252();
    virtual void c253();
    virtual void c254();
    virtual void c255();
    virtual void c256();
    virtual void c257();
    virtual void c258();
    virtual void c259();
    virtual void c260();
    virtual void c261();
    virtual void c262();
    virtual void c263();
    virtual void c264();
    virtual void c265();
    virtual void c266();
    virtual void c267();
    virtual void c268();
    virtual void c269();
    virtual void c270();
    virtual void c271();
    virtual void c272();
    virtual void c273();
    virtual void c274();
    virtual void c275();
    virtual void c276();
    virtual void c277();
    virtual void c278();
    virtual void c279();
    virtual void c280();
    virtual void c281();
    virtual void v282(Actor*);
};

struct FUN_0096f600_shell : public ProcessLists
{
    void FUN_0096f600(Actor* arg1, bool arg2);
    void FUN_0096e2f0(Actor*);
};

}  // namespace fnv_0096f600

namespace fnv_009715c0 {
struct Mob9715
{
    virtual void m0();
};
struct Obj9715;
struct X9715
{
    bool FUN_00425fd0();
};
struct W9715
{
    X9715* FUN_008d6f30();
    int FUN_00575d70();
};
struct Z9715
{
    W9715* FUN_00559450();
};
struct Proc9715
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void EnterCombatV(Obj9715*, Obj9715*, bool, bool, void*, bool, bool, bool, bool, bool, bool, bool, void*);
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual int GetNumV();
    virtual void ModNumV(int);
};
struct Obj9715 : Mob9715
{
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActorV();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual bool V193();
    X9715* FUN_008d6f30();
    int FUN_00575d70();
    bool FUN_00493bb0();
    float FUN_005723b0(void*, int, int);
    Proc9715* FUN_008d8520();
    Z9715* FUN_00568e50();
};
struct Node9715
{
    Obj9715** FUN_006815c0();
    Node9715* FUN_00726070();
};
struct G9715
{
    int* FUN_0043d4d0();
};
extern G9715 g_011cdbec;
extern Obj9715* DAT_011dea3c;
extern float DAT_01016970;
struct RetCls
{
    RetCls();
    int m_00;
    int m_04;
    void FUN_005ae3d0(Mob9715* const&);
};
struct Cont9715
{
    unsigned int FUN_005be5c0(int);
    Obj9715* FUN_00968670(unsigned int);
};
struct Cls9715
{
    int m_00;
    Cont9715 m_04;
    RetCls* CollectCombatTargets(Obj9715*, Node9715*);
};
}  // namespace fnv_009715c0

class Actor_ext : public Actor
{
  public:
    TESPackage* GetCurrentPackage();
};

class DialoguePackageStub : public TESPackage
{
  public:
    bool IsSpeakerTarget(TESObjectREFR* apTarget);
    void AddSpeaker(TESObjectREFR* apTarget, Actor* apActor);
};

class ActorRefArrayStub
{
  public:
    unsigned int GetCountOfType(int aiType);
    Actor* GetActorAt(unsigned int auiIndex);
};

class ActorQueryOwner
{
  public:
    int unk00;
    ActorRefArrayStub kActors;

    BSSimpleList<Actor*>* FindDialogueSpeakers(TESObjectREFR* apTarget, bool abAssign);
};

struct FUN_009722e0_member
{
    BSSimpleList<Actor*>* GetActorList();
};

struct FUN_009722e0_shell
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
    BSSimpleList<FUN_009722e0_member*>* pList50;
    BSSimpleList<FUN_009722e0_member*>* pList54;
    bool IsActorInOtherList(Actor* pActor, FUN_009722e0_member* apBoundObject);
};

namespace fnv_00972aa0 {
struct S_972aa0_Actor
{
    void FUN_0047eb90(int a);
};
struct S_972aa0_ActorNode
{
    bool FUN_008256d0();
    S_972aa0_Actor** FUN_006815c0();
    S_972aa0_ActorNode* FUN_00726070();
};
struct S_972aa0_Crime
{
    unsigned int FUN_0084e3a0();
    S_972aa0_ActorNode* GetField38();
};
struct S_972aa0_Node
{
    S_972aa0_Crime** FUN_006815c0();
    S_972aa0_Node* FUN_00726070();
};
struct S_972aa0_List
{
    void FUN_00905330(S_972aa0_Crime* const& crime);
};
struct S_972aa0_Lists
{
    bool IsActorInOtherList(S_972aa0_Actor* actor, S_972aa0_Crime* crime);
};
extern S_972aa0_Lists DAT_011e0e80;

struct S_972aa0_Owner
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
    S_972aa0_List* crimeLists[5];
    void RemoveCrimeById(unsigned int id);
};

}  // namespace fnv_00972aa0

struct TempEffectCellAccess : public BSTempEffect
{
    TESObjectCELL* GetParentCell();
    void SetParentCell(TESObjectCELL* apCell);
};

struct ProcessListsCellAccess : public ProcessLists
{
    void FUN_009740a0(TESObjectCELL* apCell);
};

struct EffectThreadSetting
{
    unsigned char* Bool();
};
extern EffectThreadSetting g_011f127c;
struct EffectListCount
{
    unsigned int CountReferencedNodes();
};
struct EffectUpdate
{
    BSTempEffect* effect;
    float delta;
    unsigned char global;
    unsigned char finished;
};
struct FUN_00978c50
{
    void* vtable;
    EffectUpdate* buffer;
    unsigned int size;
    unsigned int capacity;
    void* allocator;
    FUN_00978c50();
    ~FUN_00978c50();
    unsigned int FUN_00978bc0();
    EffectUpdate& FUN_006a1440(unsigned int);
    unsigned int GetSize();
    EffectUpdate& FUN_006a7af0(int);
};
struct EffectParallelTask
{
    void* function;
    void* data;
    unsigned int size;
    unsigned int index;
    EffectParallelTask(void(__cdecl*)(BSSimpleArray<ParentSpaceNode, 1024>*, int), void*, unsigned int);
};
struct EffectProcessLists : ProcessLists
{
    void FUN_00974420(float);
    void FUN_009746c0(float);
};

class ProjectileBaseStub
{
  public:
    bool GetHasExplosionAltTrigger() const;
    bool GetHasExplosionDetonates() const;
};

class ProjectileExt : public Projectile
{
  public:
    ProjectileBaseStub* GetProjectileBase() const;
    void Detonate();
};

class MagicProjectile : public Projectile
{
};

class ArrowProjectile : public Projectile
{
};

struct ProcessListsShell : public ProcessLists
{
    void FUN_00975160();
};

struct FUN_008f25e0
{
    ~FUN_008f25e0();
    TESForm* FUN_0084e3a0();
    TESForm* FUN_0044ddc0();
    void FUN_009eba00(Actor*);
};
struct CrimeListView
{
    bool FUN_008256d0();
    FUN_008f25e0** FUN_006815c0();
    CrimeListView* FUN_00726070();
    void FUN_00905330(FUN_008f25e0* const&);
    void FUN_0063f7b0();
};
struct CrimeProcess : ProcessLists
{
    void FUN_00975320(TESForm*);
};

struct SaveProcessLists : ProcessLists
{
    unsigned int FUN_009755b0();
};

extern bool _s_bAllowDetach;

class TES
{
  public:
    bool FUN_004511e0(TESObjectCELL* pCell, bool bArg);
    void ProcessItemNodes();
};
extern TES* g_TES;

class ModelLoader
{
  public:
    bool FUN_00445750(Actor* pActor);
};
extern ModelLoader* g_modelLoader;

struct TESObjectCELLSub : public TESObjectCELL
{
    void AddReference(TESObjectREFR* pRef, bool bArg);
};

struct ProcessListsSub : public ProcessLists
{
    void FUN_00972d30();
    void UpdateActor3D();
};

struct Actor976030 : Actor
{
    bool FUN_00565450();
    const char* FUN_005715d0();
};
int __cdecl FUN_00404dc0(const char*, const char*);
struct Lists976030
{
    int unk00;
    Array_973590 processes;
    void FUN_00976030(int mode);
};

struct DetectionSetting
{
    SETTING_VALUE* FUN_00403e20();
};
extern DetectionSetting g_011d0bb4;
extern DetectionSetting g_011d04b4;
struct DetectionActor : public MobileObject
{
    virtual void Unk_C1();
    virtual void Unk_C2();
    virtual void Unk_C3();
    virtual void Unk_C4();
    virtual void Unk_C5();
    virtual void Unk_C6();
    virtual void Unk_C7();
    virtual void Unk_C8();
    virtual void Unk_C9();
    virtual void Unk_CA();
    virtual void Unk_CB();
    virtual void Unk_CC();
    virtual void Unk_CD();
    virtual void Unk_CE();
    virtual void Unk_CF();
    virtual void Unk_D0();
    virtual int FUN_D1(PlayerCharacter*, bool);
    bool FUN_00440da0();
    BaseProcess* FUN_008d8520();
    bool FUN_008bc700(PlayerCharacter*);
    bool IsHostileTo(PlayerCharacter*, bool, unsigned int*, bool);
};
struct DetectionProcessArray
{
    unsigned int FUN_005be5c0(int);
};
struct DetectionList : public ProcessLists
{
    bool HasNearbyDetectedActor(bool differentDistance);
};

// Remove (and delete) every list entry whose level equals the given level.

class F8660Entry
{
  public:
    ~F8660Entry();
    unsigned int GetLevel();
};

class F8660Node
{
  public:
    bool IsEmpty();
    F8660Entry** GetItem();
    F8660Node* GetNext();
};

class F8660List : public F8660Node
{
  public:
    void Remove(F8660Entry*& rpkEntry);
};

class F8660Owner
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
    F8660List m_kEntries;

    void FUN_00978660(unsigned int uiTreeBlockIndex);
};

struct MuzzleOwnerRef
{
    void* GetFlashSource();
    int GetFlashStamp();
};
struct MuzzleProjectileRef
{
    void SetMuzzleFlashSpawned(bool);
};
struct MuzzleFlashEx : public MuzzleFlash
{
    MuzzleFlashEx(MuzzleOwnerRef* parent, MuzzleProjectileRef* projectile);
    void* GetSource();
    int GetStamp();
    MuzzleProjectileRef* GetProjectileRef();
    void Activate();
};

struct FUN_00978740_shell : public ProcessLists
{
    void ActivateMuzzleFlash(MuzzleOwnerRef* parent, MuzzleProjectileRef* projectile);
};

namespace fnv_009723f0 {
class CrimeFull
{
  public:
    ~CrimeFull();
    bool FUN_009eb8a0();
    void FUN_009eba30();
};

class ProcessListsEx : public ProcessLists
{
  public:
    void UpdateCrimeLists();
};

}  // namespace fnv_009723f0

namespace fnv_0096dcb0 {
extern "C" char DAT_011dea3c;
extern "C" char DAT_011de7b8;
struct State96
{
    int FUN_0041ca90();
};
struct Actor96;
struct Slots64
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
    virtual void a48();
    virtual void a49();
    virtual void a50();
    virtual void a51();
    virtual void a52();
    virtual void a53();
    virtual void a54();
    virtual void a55();
    virtual void a56();
    virtual void a57();
    virtual void a58();
    virtual void a59();
    virtual void a60();
    virtual void a61();
    virtual void a62();
    virtual void a63();
};
struct ProcOwner96 : Slots64
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual Actor96* owner();
};
struct Proc96 : ProcOwner96
{
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void c17();
    virtual void c18();
    virtual void c19();
    virtual void c20();
    virtual void c21();
    virtual void c22();
    virtual void c23();
    virtual void c24();
    virtual void c25();
    virtual void c26();
    virtual void c27();
    virtual void c28();
    virtual void c29();
    virtual void c30();
    virtual void c31();
    virtual void c32();
    virtual void c33();
    virtual void c34();
    virtual void c35();
    virtual void c36();
    virtual void c37();
    virtual void c38();
    virtual void c39();
    virtual void c40();
    virtual void c41();
    virtual void c42();
    virtual void c43();
    virtual void c44();
    virtual void c45();
    virtual void c46();
    virtual void c47();
    virtual void c48();
    virtual void c49();
    virtual void c50();
    virtual void c51();
    virtual void c52();
    virtual void c53();
    virtual void c54();
    virtual void c55();
    virtual void c56();
    virtual void c57();
    virtual void c58();
    virtual void c59();
    virtual void c60();
    virtual void c61();
    virtual void c62();
    virtual void c63();
    virtual State96* state();
    float FUN_007df1f0();
};
struct ActorValid96 : Slots64
{
    virtual bool valid();
};
struct Actor96 : ActorValid96
{
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual void b17();
    virtual void b18();
    virtual void b19();
    virtual void b20();
    virtual void b21();
    virtual void b22();
    virtual void b23();
    virtual void b24();
    virtual void b25();
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual void b42();
    virtual void b43();
    virtual void b44();
    virtual void b45();
    virtual void b46();
    virtual void b47();
    virtual void b48();
    virtual void b49();
    virtual void b50();
    virtual void b51();
    virtual void b52();
    virtual void b53();
    virtual void b54();
    virtual void b55();
    virtual void b56();
    virtual void b57();
    virtual void b58();
    virtual void b59();
    virtual void b60();
    virtual void b61();
    virtual void b62();
    virtual void b63();
    virtual void b64();
    virtual void b65();
    virtual void b66();
    virtual void b67();
    virtual void b68();
    virtual void b69();
    virtual void b70();
    virtual void b71();
    virtual void b72();
    virtual void b73();
    virtual void b74();
    virtual void b75();
    virtual void b76();
    virtual void b77();
    virtual void b78();
    virtual void b79();
    virtual void b80();
    virtual void b81();
    virtual void b82();
    virtual void b83();
    virtual void b84();
    virtual void b85();
    virtual void update(float);
    Proc96* FUN_008d8520();
    bool FUN_00440d80();
    bool FUN_00440da0();
    bool FUN_00493bb0();
    bool FUN_008842c0();
};
struct Clock96
{
    float FUN_00867da0();
};
struct FUN_0096a2d0
{
    char data[8];
    FUN_0096a2d0();
    ~FUN_0096a2d0();
    Actor96** FUN_006815c0();
    FUN_0096a2d0* FUN_00726070();
    void FUN_005ae3d0(Actor96**);
    void FUN_0063f7b0();
    void FUN_00470470();
    void* FUN_004702f0(unsigned);
};
struct Owner96
{
    void UpdateActorsFromList(FUN_0096a2d0*);
};
}  // namespace fnv_0096dcb0

template <int N> struct Slot970
{
};
template <int N> struct ProcessSlots970 : ProcessSlots970<N - 1>
{
    virtual void pad(Slot970<N>*);
};
template <> struct ProcessSlots970<0>
{
};
template <> struct ProcessSlots970<211> : ProcessSlots970<210>
{
    virtual void SetCount(int);
};
struct Process970 : ProcessSlots970<368>
{
    virtual int GetCount();
};
template <int N> struct ActorSlots970 : ActorSlots970<N - 1>
{
    virtual void pad(Slot970<N>*);
};
template <> struct ActorSlots970<0>
{
};
template <> struct ActorSlots970<65> : ActorSlots970<64>
{
    virtual bool IsActor();
};
template <> struct ActorSlots970<140> : ActorSlots970<139>
{
    virtual bool Check(int);
};
struct Actor970 : ActorSlots970<141>
{
    virtual bool Check2();
    bool FUN_00440da0();
    bool FUN_00440d80();
    char FUN_00437bd0();
    Process970* FUN_008d8520();
    int FUN_008a0d10(int, Actor970*, bool*, int, int, int, int);
};
struct Input970
{
    Actor970* FUN_0084e3a0();
};
struct List970
{
    int x[2];
    List970();
    unsigned FUN_005ae380();
    void FUN_005ae3d0(Actor970**);
    void SortItems(void*);
};
struct Array970
{
    unsigned FUN_005be5c0(int);
    Actor970* FUN_00968670(unsigned);
};
extern "C" char DAT_00970ee0;
struct C970
{
    int unused;
    Array970 array;
    List970* CollectActorsByPackage(Actor970*, int, int);
    List970* FUN_00970f60(Input970* input);
};

struct ZPack
{
    int FUN_0041ca90();
    int FUN_004030b0();
    bool FUN_0097fa10(int);
};
struct ZProc
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual int Pack();
};
struct ZAct
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActor();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual bool Check();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual bool Check2();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void Disable(int);
    bool FUN_00493bb0();
    ZPack* FUN_00881510();
    ZPack* FUN_009344a0();
    ZProc* FUN_008d8520();
    bool FUN_005653d0();
};
struct ZArray
{
    unsigned int FUN_005be5c0(int);
    unsigned int FUN_005de0f0(int);
    ZAct* FUN_00968670(unsigned int);
};
struct ZOwner
{
    int unk00;
    ZArray unk04;
    BSSimpleList<Actor*>* CollectActorsByPackage(int, int, bool);
};

struct CombatActor;
struct FactionView;
struct ProcessView
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void v269();
    virtual void v270();
    virtual void v271();
    virtual void v272();
    virtual void v273();
    virtual void v274();
    virtual void v275();
    virtual void v276();
    virtual void v277();
    virtual void v278();
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual void v285();
    virtual void v286();
    virtual void v287();
    virtual void v288();
    virtual void v289();
    virtual void v290();
    virtual void v291();
    virtual void v292();
    virtual void v293();
    virtual void v294();
    virtual void v295();
    virtual void v296();
    virtual void v297();
    virtual void v298();
    virtual void v299();
    virtual void v300();
    virtual void v301();
    virtual void v302();
    virtual void v303();
    virtual void v304();
    virtual void v305();
    virtual void v306();
    virtual void v307();
    virtual void v308();
    virtual void v309();
    virtual void v310();
    virtual void v311();
    virtual void v312();
    virtual void v313();
    virtual void v314();
    virtual void v315();
    virtual void v316();
    virtual void v317();
    virtual void v318();
    virtual void v319();
    virtual void v320();
    virtual void v321();
    virtual void v322();
    virtual void v323();
    virtual void v324();
    virtual void v325();
    virtual void v326();
    virtual void v327();
    virtual void v328();
    virtual void v329();
    virtual void v330();
    virtual void v331();
    virtual void v332();
    virtual void v333();
    virtual void v334();
    virtual void v335();
    virtual void v336();
    virtual void v337();
    virtual void v338();
    virtual void v339();
    virtual void v340();
    virtual void v341();
    virtual void v342();
    virtual void v343();
    virtual void v344();
    virtual void v345();
    virtual void v346();
    virtual void v347();
    virtual void v348();
    virtual void v349();
    virtual void v350();
    virtual void v351();
    virtual void v352();
    virtual void v353();
    virtual void v354();
    virtual void v355();
    virtual void v356();
    virtual void v357();
    virtual void v358();
    virtual void v359();
    virtual void v360();
    virtual void v361();
    virtual void v362();
    virtual void v363();
    virtual void v364();
    virtual void v365();
    virtual void v366();
    virtual void v367();
    virtual void v368();
    virtual void v369();
    virtual void v370();
    virtual void v371();
    virtual void v372();
    virtual void v373();
    virtual void v374();
    virtual void v375();
    virtual void v376();
    virtual void v377();
    virtual void v378();
    virtual void v379();
    virtual void v380();
    virtual void v381();
    virtual void v382();
    virtual void v383();
    virtual void v384();
    virtual void v385();
    virtual void v386();
    virtual void v387();
    virtual void v388();
    virtual void v389();
    virtual void v390();
    virtual void v391();
    virtual void v392();
    virtual void v393();
    virtual void v394();
    virtual void v395();
    virtual void v396();
    virtual void v397();
    virtual void v398();
    virtual void v399();
    virtual void v400();
    virtual void Reset(bool);
};
struct TargetData
{
    CombatActor* Target();
};
struct PackageView
{
    TargetData* Data();
};
struct FactionView
{
    bool Enemy() const;
    void SetEnemy(bool);
};
struct FactionChanges
{
    int unk00;
    int unk04;
    int unk08;
    void* list;
};
struct ExtraView
{
    void Clear(CombatActor*);
    FactionChanges* Changes();
};
struct BaseFactionView
{
    void* List();
};
struct ActorBaseView
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
    BaseFactionView factions;
};
struct CombatActor
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool IsActor();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual bool HasFactions();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual void v266();
    virtual void v267();
    virtual void v268();
    virtual void StopTarget(CombatActor*);
    bool HasTarget(CombatActor*);
    bool HasPackage();
    PackageView* Package();
    void Stop(int);
    ProcessView* Process();
    void Reset();
    ExtraView* Extra();
    ActorBaseView* Base();
    unsigned Gather(FactionView**, unsigned, void*, void*);
};
struct ActorArrayView
{
    unsigned Begin(int);
    unsigned End(int);
    CombatActor* At(unsigned);
};
struct ListsView
{
    ActorArrayView* Array();
    void FUN_00972840(CombatActor*, bool);
};
extern ListsView combatLists;
extern CombatActor* playerActor;

struct CombatController9734
{
    Actor* FUN_004030b0();
    bool FUN_009818b0();
};

// Actor's primary vtable seen through MobileObject; slot 266 returns the combat controller
class ActorView9734 : public MobileObject
{
  public:
    virtual void V193();
    virtual void V194();
    virtual void V195();
    virtual void V196();
    virtual void V197();
    virtual void V198();
    virtual void V199();
    virtual void V200();
    virtual void V201();
    virtual void V202();
    virtual void V203();
    virtual void V204();
    virtual void V205();
    virtual void V206();
    virtual void V207();
    virtual void V208();
    virtual void V209();
    virtual void V210();
    virtual void V211();
    virtual void V212();
    virtual void V213();
    virtual void V214();
    virtual void V215();
    virtual void V216();
    virtual void V217();
    virtual void V218();
    virtual void V219();
    virtual void V220();
    virtual void V221();
    virtual void V222();
    virtual void V223();
    virtual void V224();
    virtual void V225();
    virtual void V226();
    virtual void V227();
    virtual void V228();
    virtual void V229();
    virtual void V230();
    virtual void V231();
    virtual void V232();
    virtual void V233();
    virtual void V234();
    virtual void V235();
    virtual void V236();
    virtual void V237();
    virtual void V238();
    virtual void V239();
    virtual void V240();
    virtual void V241();
    virtual void V242();
    virtual void V243();
    virtual void V244();
    virtual void V245();
    virtual void V246();
    virtual void V247();
    virtual void V248();
    virtual void V249();
    virtual void V250();
    virtual void V251();
    virtual void V252();
    virtual void V253();
    virtual void V254();
    virtual void V255();
    virtual void V256();
    virtual void V257();
    virtual void V258();
    virtual void V259();
    virtual void V260();
    virtual void V261();
    virtual void V262();
    virtual void V263();
    virtual void V264();
    virtual void V265();
    virtual CombatController9734* GetCombatController();
};

class Actor9734 : public Actor
{
  public:
    int FUN_008a81e0(Actor* pkTarget);
    bool FUN_00493bb0();
};

struct ActorArray9734
{
    unsigned int FUN_005be5c0(int iUnused);
    TESObjectREFR* FUN_00968670(unsigned int uiIndex);
};

struct ActorGroup9734
{
    int m_iUnk00;
    ActorArray9734 kActors;
    bool FUN_00973460(Actor* pkTarget);
};

namespace fnv_00973710 {
struct ActorX;
struct Process;
struct Combat
{
    ActorX* FUN_004030b0();
    bool FUN_009818b0();
};
struct Process
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual void v139();
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual int detect(ActorX*, int);
};
struct ActorX
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual bool isActorXor();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual void v109();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual void v125();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual void v135();
    virtual void v136();
    virtual void v137();
    virtual void v138();
    virtual bool isDead(int);
    virtual void v140();
    virtual void v141();
    virtual void v142();
    virtual void v143();
    virtual void v144();
    virtual void v145();
    virtual void v146();
    virtual void v147();
    virtual void v148();
    virtual void v149();
    virtual void v150();
    virtual void v151();
    virtual void v152();
    virtual void v153();
    virtual void v154();
    virtual void v155();
    virtual void v156();
    virtual void v157();
    virtual void v158();
    virtual void v159();
    virtual void v160();
    virtual void v161();
    virtual void v162();
    virtual void v163();
    virtual void v164();
    virtual void v165();
    virtual void v166();
    virtual void v167();
    virtual void v168();
    virtual void v169();
    virtual void v170();
    virtual void v171();
    virtual void v172();
    virtual void v173();
    virtual void v174();
    virtual void v175();
    virtual void v176();
    virtual void v177();
    virtual void v178();
    virtual void v179();
    virtual void v180();
    virtual void v181();
    virtual void v182();
    virtual void v183();
    virtual void v184();
    virtual void v185();
    virtual void v186();
    virtual void v187();
    virtual void v188();
    virtual void v189();
    virtual void v190();
    virtual void v191();
    virtual void v192();
    virtual void v193();
    virtual void v194();
    virtual void v195();
    virtual void v196();
    virtual void v197();
    virtual void v198();
    virtual void v199();
    virtual void v200();
    virtual void v201();
    virtual void v202();
    virtual void v203();
    virtual void v204();
    virtual void v205();
    virtual void v206();
    virtual void v207();
    virtual void v208();
    virtual void v209();
    virtual void v210();
    virtual void v211();
    virtual void v212();
    virtual void v213();
    virtual void v214();
    virtual void v215();
    virtual void v216();
    virtual void v217();
    virtual void v218();
    virtual void v219();
    virtual void v220();
    virtual void v221();
    virtual void v222();
    virtual void v223();
    virtual void v224();
    virtual void v225();
    virtual void v226();
    virtual void v227();
    virtual void v228();
    virtual void v229();
    virtual void v230();
    virtual void v231();
    virtual void v232();
    virtual void v233();
    virtual void v234();
    virtual void v235();
    virtual void v236();
    virtual void v237();
    virtual void v238();
    virtual void v239();
    virtual void v240();
    virtual void v241();
    virtual void v242();
    virtual void v243();
    virtual void v244();
    virtual void v245();
    virtual void v246();
    virtual void v247();
    virtual void v248();
    virtual void v249();
    virtual void v250();
    virtual void v251();
    virtual void v252();
    virtual void v253();
    virtual void v254();
    virtual void v255();
    virtual void v256();
    virtual void v257();
    virtual void v258();
    virtual void v259();
    virtual void v260();
    virtual void v261();
    virtual void v262();
    virtual void v263();
    virtual void v264();
    virtual void v265();
    virtual Combat* combat();
    bool IsPlayerTeammate();
    bool GetDisabled();
    bool FUN_00437bd0();
    void SetByteAt66c(char);
    unsigned char GetByteAtOffset();
    float FUN_005723b0(ActorX*, int, int);
    bool FUN_00493bb0();
    bool FUN_008a61b0();
    ActorX* FUN_00881650();
    Process* FUN_008d8520();
    bool IsHostileTo(ActorX*, int, float*, int);
    void FUN_008c8bb0(int);
};
typedef BSSimpleList<Actor*> List;
struct MyArray
{
    unsigned int FUN_005be5c0(int);
    ActorX* FUN_00968670(unsigned int);
};
struct Setting
{
    int* FUN_0043d4d0();
};
extern Setting DAT_011cd850;
extern ActorX* _g_thePlayer;
struct Shell
{
    int unk00;
    MyArray unk04;
    void FUN_00973590(ActorX*, List*);
    int GetHighestDetectionValue(ActorX*, bool);
};
}  // namespace fnv_00973710

namespace fnv_00970810 {
// Menu75x::FUN_00970810
struct Vt75
{
    virtual void d000();
    virtual void d001();
    virtual void d002();
    virtual void d003();
    virtual void d004();
    virtual void d005();
    virtual void d006();
    virtual void d007();
    virtual void d008();
    virtual void v09(void* obj, int flag);
    virtual void d010();
    virtual void d011();
    virtual void d012();
    virtual void d013();
    virtual void d014();
    virtual void d015();
    virtual void d016();
    virtual void d017();
    virtual void d018();
    virtual void d019();
    virtual void d020();
    virtual void d021();
    virtual void d022();
    virtual void d023();
    virtual void d024();
    virtual void d025();
    virtual void d026();
    virtual void d027();
    virtual void d028();
    virtual void d029();
    virtual void d030();
    virtual void d031();
    virtual void d032();
    virtual void d033();
    virtual void d034();
    virtual void d035();
    virtual void d036();
    virtual void d037();
    virtual void d038();
    virtual void d039();
    virtual void d040();
    virtual void d041();
    virtual void d042();
    virtual void d043();
    virtual void d044();
    virtual void d045();
    virtual void d046();
    virtual void d047();
    virtual void d048();
    virtual void d049();
    virtual void d050();
    virtual void d051();
    virtual void d052();
    virtual void d053();
    virtual void d054();
    virtual void d055();
    virtual void d056();
    virtual void d057();
    virtual void d058();
    virtual void d059();
    virtual void d060();
    virtual void d061();
    virtual void d062();
    virtual void d063();
    virtual bool v40();
    virtual void d065();
    virtual void d066();
    virtual void d067();
    virtual void d068();
    virtual void d069();
    virtual void d070();
    virtual void d071();
    virtual void d072();
    virtual void d073();
    virtual void d074();
    virtual void d075();
    virtual void d076();
    virtual void d077();
    virtual void d078();
    virtual void d079();
    virtual void d080();
    virtual void d081();
    virtual void d082();
    virtual void d083();
    virtual void d084();
    virtual void d085();
    virtual void d086();
    virtual void d087();
    virtual void d088();
    virtual void d089();
    virtual void d090();
    virtual void d091();
    virtual void d092();
    virtual void d093();
    virtual void d094();
    virtual void d095();
    virtual void d096();
    virtual void d097();
    virtual void d098();
    virtual void d099();
    virtual void d100();
    virtual void d101();
    virtual void d102();
    virtual void d103();
    virtual void d104();
    virtual void d105();
    virtual void d106();
    virtual void d107();
    virtual void d108();
    virtual void d109();
    virtual void d110();
    virtual void d111();
    virtual void d112();
    virtual void d113();
    virtual void d114();
    virtual void d115();
    virtual void d116();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual void d125();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual void d131();
    virtual void d132();
    virtual void v85();
    virtual void d134();
    virtual void d135();
    virtual void d136();
    virtual void d137();
    virtual void d138();
    virtual int v8b();
    virtual void d140();
    virtual void v8d();
    virtual void d142();
    virtual void d143();
    virtual void d144();
    virtual void d145();
    virtual void d146();
    virtual void d147();
    virtual void d148();
    virtual void d149();
    virtual void d150();
    virtual void d151();
    virtual void d152();
    virtual void d153();
    virtual void d154();
    virtual void d155();
    virtual void d156();
    virtual void d157();
    virtual void d158();
    virtual int v9f();
};

struct Sh008d8520
{
    void* FUN_008d8520();
};
struct Sh0045cd60
{
    int FUN_0045cd60();
};
struct Sh00576d30
{
    bool FUN_00576d30();
};
struct Sh005d43c0
{
    void* FUN_005d43c0();
};
struct Sh0041cb10
{
    void* FUN_0041cb10();
};
struct Sh0041c930
{
    void FUN_0041c930(int a, int b, int c, int d, int e, int f);
};
struct Sh0042ce10
{
    bool FUN_0042ce10();
};
struct Sh005de0f0
{
    int FUN_005de0f0(int a);
};
struct Sh005be5c0
{
    unsigned int FUN_005be5c0(int a);
};
struct Sh00968670
{
    void* FUN_00968670(unsigned int i);
};
struct Sh00717e50
{
    void* FUN_00717e50();
};

extern "C" char DAT_011e0e80;
extern "C" void* DAT_011ddf38;

struct Menu75x
{
    void FUN_00970810(int arg);
};

}  // namespace fnv_00970810

struct R9711
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
    virtual bool IsValid40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v5A();
    virtual void v5B();
    virtual void v5C();
    virtual void v5D();
    virtual void v5E();
    virtual void v5F();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v6A();
    virtual void v6B();
    virtual void v6C();
    virtual void v6D();
    virtual void v6E();
    virtual void v6F();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v7A();
    virtual void v7B();
    virtual void v7C();
    virtual void v7D();
    virtual void v7E();
    virtual void v7F();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v8A();
    virtual bool Check8B(int a);
    R9711* GetObj();
    R9711* GetParentCell();
    R9711* GetWorld();
    void SetFlag(int a);
    bool IsInterior();
    bool Is440da0();
    bool Is440d80();
    R9711* GetExtra();
    unsigned int GetType();
    bool Is9ec810(R9711* a);
    float GetDist(R9711* a, int b, int c);
    int* GetSetting();
    void AddItem(R9711* const& p);
    R9711** GetItem();
    R9711* Next();
    R9711* Get568e50();
    R9711* Get559450();
    void SetCallback(void (*f)());
    unsigned int Count(int a);
    R9711* At(unsigned int a);
};

struct Ref9711 : R9711
{
};

struct Res9711 : R9711
{
    Res9711();
    int unk04;
};

extern R9711 DAT_011cdbec;
extern float DAT_01016970;
void FUN_00970ee0();

struct Lst9711
{
    int unk00;
    int unk04;
    R9711* CollectNearbyRefs(R9711* apObj, R9711* apList);
};

struct ItmQ
{
    unsigned short FUN_009ebb80();
};
struct LstQ
{
    bool FUN_008256d0();
    ItmQ** FUN_006815c0();
    LstQ* FUN_00726070();
};
struct OwnQ
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40;
    LstQ* apLists[5];
    unsigned short GetTotalSize();
};

struct CrimeCleanup
{
    ~CrimeCleanup();
};

struct FUN_00975b60_shell : ProcessLists
{
    void CleanupCrimeLists(BGSLoadGameBuffer* buffer);
};

struct Buffer652
{
    void FUN_00864980(void*, unsigned int);
    unsigned int FUN_00864a60();
    void FUN_008648e0(TESObjectREFR**);
};
struct Receiver652;
Receiver652* __cdecl FUN_00832930(TESObjectREFR*);
struct ReceiverList652
{
    Receiver652* item;
    ReceiverList652* next;
    void FUN_005ae3d0(Receiver652*&);
};
struct FUN_0083b830
{
    int unk00;
    int unk04;
    int unk08;
    FUN_0083b830();
    void FUN_0083c330(Buffer652*);
};
struct Radio652
{
    FUN_0083b830* conversation;
    int unk04;
    int unk08;
    int unk0c;
    bool unk10;
    bool unk11;
    int unk14;
    ReceiverList652 receivers;
    void FUN_00836240(Buffer652*);
};

struct ListA
{
    unsigned int FUN_0055b980();
    void* FUN_00968670(unsigned int i);
};
struct ObjA
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
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
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v2a();
    virtual void v2b();
    virtual void v2c();
    virtual void v2d();
    virtual void v2e();
    virtual void v2f();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v3a();
    virtual void v3b();
    virtual void v3c();
    virtual void v3d();
    virtual void v3e();
    virtual void v3f();
    virtual bool IsActor();
    void FUN_00881680(int);
    bool FUN_00566950();
    void FUN_008ad910(int, int, int);
};
struct ActorA : ObjA
{
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void w48();
    virtual void w49();
    virtual void w4a();
    virtual void w4b();
    virtual void w4c();
    virtual void w4d();
    virtual void w4e();
    virtual void w4f();
    virtual void w50();
    virtual void w51();
    virtual void w52();
    virtual void w53();
    virtual void w54();
    virtual void w55();
    virtual void w56();
    virtual void w57();
    virtual void w58();
    virtual void w59();
    virtual void w5a();
    virtual void w5b();
    virtual void w5c();
    virtual void w5d();
    virtual void w5e();
    virtual void w5f();
    virtual void w60();
    virtual void w61();
    virtual void w62();
    virtual void w63();
    virtual void w64();
    virtual void w65();
    virtual void w66();
    virtual void w67();
    virtual void w68();
    virtual void w69();
    virtual void w6a();
    virtual void w6b();
    virtual void w6c();
    virtual void w6d();
    virtual void w6e();
    virtual void w6f();
    virtual void w70();
    virtual void w71();
    virtual void w72();
    virtual void w73();
    virtual void w74();
    virtual void w75();
    virtual void w76();
    virtual void w77();
    virtual void w78();
    virtual void w79();
    virtual void w7a();
    virtual void w7b();
    virtual void w7c();
    virtual void w7d();
    virtual void w7e();
    virtual void w7f();
    virtual void w80();
    virtual void w81();
    virtual void w82();
    virtual void w83();
    virtual void w84();
    virtual void w85();
    virtual void w86();
    virtual void w87();
    virtual void w88();
    virtual void w89();
    virtual void w8a();
    virtual bool IsDead(int);
};
struct MgrA
{
    bool IsPlayerTargeted(ActorA*, int);
};
extern MgrA* g_mgrA;
struct StubX
{
    int unk00;
    ListA list;
    void FUN_00973ee0(int a);
};

namespace fnv_0096eb40 {
struct Pkg;
struct Ref;
struct Proc;
struct Proc
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual Pkg* GetPkg();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32c();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33c();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34c();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35c();
    virtual bool Is360();
    virtual void Set364(int);
    virtual void v368();
    virtual void v36c();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37c();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38c();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39c();
    virtual void v3a0();
    virtual void v3a4();
    virtual void v3a8();
    virtual void v3ac();
    virtual void v3b0();
    virtual void v3b4();
    virtual void v3b8();
    virtual void v3bc();
    virtual void v3c0();
    virtual void v3c4();
    virtual void v3c8();
    virtual void v3cc();
    virtual void v3d0();
    virtual void v3d4();
    virtual void v3d8();
    virtual void v3dc();
    virtual void v3e0();
    virtual void v3e4();
    virtual void v3e8();
    virtual void v3ec();
    virtual void v3f0();
    virtual void v3f4();
    virtual void v3f8();
    virtual void v3fc();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40c();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41c();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42c();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43c();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44c();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45c();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46c();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47c();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48c();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49c();
    virtual void v4a0();
    virtual void v4a4();
    virtual void v4a8();
    virtual void v4ac();
    virtual void v4b0();
    virtual void v4b4();
    virtual void v4b8();
    virtual void v4bc();
    virtual void v4c0();
    virtual void v4c4();
    virtual void v4c8();
    virtual void v4cc();
    virtual void v4d0();
    virtual void v4d4();
    virtual void v4d8();
    virtual void v4dc();
    virtual void v4e0();
    virtual void v4e4();
    virtual void v4e8();
    virtual void v4ec();
    virtual void v4f0();
    virtual void v4f4();
    virtual void v4f8();
    virtual void v4fc();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50c();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51c();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52c();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53c();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54c();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55c();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56c();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57c();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58c();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59c();
    virtual void v5a0();
    virtual void v5a4();
    virtual void v5a8();
    virtual void v5ac();
    virtual void v5b0();
    virtual void v5b4();
    virtual void v5b8();
    virtual void v5bc();
    virtual void v5c0();
    virtual void v5c4();
    virtual void v5c8();
    virtual void v5cc();
    virtual void v5d0();
    virtual void v5d4();
    virtual void v5d8();
    virtual void v5dc();
    virtual void v5e0();
    virtual void v5e4();
    virtual void v5e8();
    virtual void v5ec();
    virtual void v5f0();
    virtual void v5f4();
    virtual void v5f8();
    virtual void v5fc();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60c();
    virtual void v610();
    virtual void v614();
    virtual void v618();
    virtual void v61c();
    virtual void v620();
    virtual void v624();
    virtual void v628();
    virtual void v62c();
    virtual void v630();
    virtual void v634();
    virtual void v638();
    virtual void v63c();
    virtual void v640();
    virtual void v644();
    virtual void v648();
    virtual void v64c();
    virtual void v650();
    virtual void v654();
    virtual void v658();
    virtual void v65c();
    virtual void v660();
    virtual void v664();
    virtual void v668();
    virtual void v66c();
    virtual void v670();
    virtual void v674();
    virtual void v678();
    virtual void v67c();
    virtual void v680();
    virtual void v684();
    virtual void v688();
    virtual void v68c();
    virtual void v690();
    virtual void v694();
    virtual void v698();
    virtual float Get69c();
    int f45cd60();
};
struct Ref
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual ~Ref();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void HandleInteger(int);
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual bool IsA();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11c();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12c();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13c();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14c();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15c();
    virtual bool Is160();
    virtual void v164();
    virtual void v168();
    virtual void v16c();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17c();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18c();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19c();
    virtual void v1a0();
    virtual void v1a4();
    virtual void v1a8();
    virtual void v1ac();
    virtual void v1b0();
    virtual void v1b4();
    virtual void v1b8();
    virtual void v1bc();
    virtual void v1c0();
    virtual void v1c4();
    virtual void v1c8();
    virtual void v1cc();
    virtual void v1d0();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual void v1f4();
    virtual void v1f8();
    virtual void v1fc();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20c();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21c();
    virtual void v220();
    virtual bool Is224();
    virtual void v228();
    virtual bool Is22c(int);
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23c();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24c();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25c();
    virtual void Do260();
    virtual void v264();
    virtual void v268();
    virtual void v26c();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27c();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28c();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29c();
    virtual void v2a0();
    virtual void v2a4();
    virtual void v2a8();
    virtual void v2ac();
    virtual void v2b0();
    virtual void v2b4();
    virtual void v2b8();
    virtual void v2bc();
    virtual void v2c0();
    virtual void v2c4();
    virtual void v2c8();
    virtual void v2cc();
    virtual void v2d0();
    virtual void v2d4();
    virtual void v2d8();
    virtual void v2dc();
    virtual void v2e0();
    virtual void v2e4();
    virtual void v2e8();
    virtual void v2ec();
    virtual void v2f0();
    virtual void v2f4();
    virtual void v2f8();
    virtual void v2fc();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30c();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31c();
    virtual void v320();
    virtual void Do324(int, int, int);
};

struct Pkg
{
    int f41ca90();
};
struct Inv;
struct Node;
struct Inv
{
    Node* f41df90();
    void f41de40(int);
    void f41dfd0();
};
struct Node
{
    Ref** Item();
    Node* Next();
    bool f8256d0();
    void f63f7b0();
};
struct X567
{
    bool f526320();
};
struct RefEx : Ref
{
    char pad[0x7e];
    bool b82;
    bool f576d30();
    Proc* GetProc();
    bool f574900();
    bool f92f160();
    bool f440d80();
    int f484e60(int);
    bool f440da0();
    int f931850();
    void f931e80();
    int f44ddc0();
    bool f87f3d0();
    bool f87f4a0();
    int f8d6f30(int);
    X567* f567d20();
    Inv* f5d43c0();
    void f572270();
};
struct Mgr94
{
    bool f94df60();
};
struct Mgr10
{
    bool f4511e0(int);
};
struct MgrB8
{
    unsigned int f867e30();
};
struct Lock
{
    void Enter(int);
    void Leave();
    bool TryEnter();
};
struct Q80
{
    void f96d450(RefEx*, int, int, int, int);
};
struct Sub4
{
    void f96aaf0(RefEx*, int);
    void f96a970(RefEx*, int);
};
struct List78
{
    void Remove(Ref* const&);
};
extern Mgr94* g_11dea3c;
extern Mgr10* g_11dea10;
extern MgrB8 g_11de7b8;
extern RefEx* g_ref;
extern Q80 g_11e0e80;
extern Lock g_lock;
unsigned int f526100();
RefEx* f705190();
int f702640();

struct FUN_0096eb40_cls
{
    int unk00;
    Sub4 sub4;
    char pad[0x73];
    List78 list;
    void FUN_0096eb40();
};

}  // namespace fnv_0096eb40

struct WeaponShaderEffectAccess : public ::MagicShaderHitEffect
{
    unsigned int FUN_00441110();
    bool IsUnk28Set();
    unsigned char GetField24();
    char* FUN_00671d10();
    void SetByteAt24(unsigned int);
};
struct WeaponShaderCleanup : public ::ProcessLists
{
    ::MagicShaderHitEffect* FUN_00974db0(::TESObjectREFR*, ::TESEffectShader*);
};

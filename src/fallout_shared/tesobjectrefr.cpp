// fallout_shared/tesobjectrefr.cpp: XActor, Owner, Thing, Ref and more (18 functions)
#include "tesobjectrefr_decls.h"

// @fnv 0x0057acc0
void FUN_0057acc0(unsigned int index)
{
    g_011ca304.RemoveAt(index);
}

struct Actor;
struct ActorCause;
struct ActorPackageData;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSPrimitive;
struct BGSSaveFormBuffer;
struct BGSTalkingActivator;
struct BSExtraData;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct BSOcclusionPlane;
struct BSPortal;
struct SoundPlaybackHandle;
struct BaseExtraList;
struct BipedAnim;
struct CellMopp;
struct CollisionData;
struct Crime;
struct TeleportableReference;
struct ExtraAction;
struct ExtraActorCause;
struct ExtraAmmo;
struct ExtraAnim;
struct ExtraAshPileReference;
struct ExtraAudioBuoyMarker;
struct ExtraAudioMarker;
struct ExtraCannotWearData;
struct ExtraDataList;
struct ExtraDismemberedLimbs;
struct ExtraFactionChanges;
struct ExtraFollower;
struct ExtraFollowerSwimBreadcrumbs;
struct ExtraLeveledItem;
struct ExtraLight;
struct ExtraLock;
struct ExtraMapMarker;
struct ExtraNavMeshPortal;
struct ExtraRefractionProperty;
struct ExtraSayToTopicInfo;
struct ExtraSayTopicInfoOnceADay;
struct ExtraStartingPosition;
struct ExtraTalkingActor;
struct ExtraTeleport;
struct PositionRotation;
struct ImpactSwap;
struct InventoryChanges;
struct MapMarkerData;
struct MenuTopic;
struct Point3Offset;
struct NiNode;
struct NiPoint3;
struct NiRenderedTexture;
struct PatrolReferenceData;
struct PatrolRefData;
struct LinkedReferencePair;
struct RadioReferenceData;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceFloatEntry;
struct RagDollData;
struct PointerFlagNode;
struct TopicInfoVisitRecord;
struct Script;
struct ScriptLocals;
struct SeenData;
struct TESActorBase;
struct TESAmmo;
struct TESClimate;
struct TESCombatStyle;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESImageSpace;
struct TESModel;
struct TESNPC;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESPackage;
struct TESRegionList;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct TrespassPackage;
struct WorldLocation;
struct WaterZone;
struct _D3DLOCKED_RECT;
struct bhkWorld;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};

struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
};

struct FUN_00439f90_shell : public TESObjectREFR
{
    bool FUN_00439f90();
};

class TESObjectSTAT;
extern TESObjectSTAT* DAT_011ca230;
extern TESObjectSTAT* DAT_011ca238;
TESObjectSTAT* __fastcall _FNV_GetObjectReference(TESObjectREFR*);

namespace fnv_0043fcd0 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_0043fcd0_shell : public TESObjectREFR
{
    NiAVObject* FUN_0043fcd0();
};

template <typename T> struct BSStringT
{
    operator const char*() const;
};

struct TLS_Pad_0043fcd0
{
    char pad[0x260];
    NiAVObject* val260;
    FUN_0043fcd0_shell* val264;
};

__declspec(thread) TLS_Pad_0043fcd0 g_tls_0043fcd0;

}  // namespace fnv_0043fcd0

struct AnimIdle;
struct Animation;
struct AttachDistant3DTask;
struct BSFile;
struct BSFileEntry;
struct BackgroundCloneThread;
struct BipedAnim;
struct EffectSetting;
struct KFModel;
struct LoadedFile;
struct MagicItem;
struct Model;
struct NiAVObject;
struct NiControllerSequence;
struct NiNode;
struct QueuedFile;
struct QueuedReference;
struct QueuedTexture;
struct TESAnimGroup;
struct TESBoundObject;
struct TESModel;
struct TESNPC;
struct TESObjectCELL;
struct TESObjectTREE;
struct FileEntryList;
struct FileEntryListCollection;
struct ModelLoadData;
struct ModelLoader
{
    void LoadModelFileList(BSFile*, bool);
    bool QueueModelFilePath(BSFileEntry*, int, QueuedFile*);
    bool QueueModelFilePath(char*, int, QueuedFile*);
    void ProcessModelRequest(char*, FileEntryList*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, void*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, void*, int, QueuedFile*, int, bool, bool, bool, float);
    void ProcessModelRequest(char*, FileEntryList*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(char*, int, QueuedFile*, int, bool, bool, bool);
    void ProcessModelRequest(TESModel*, int, QueuedFile*, int, bool, bool, bool);
    void QueueTree(TESObjectREFR*, TESObjectTREE*, void*, int, QueuedFile*, int);
    void QueueTree(TESObjectREFR*, TESObjectTREE*, int, QueuedFile*, int);
    bool EnqueueFile(char*, int, QueuedFile*);
    void QueueMagicEffectModel(MagicItem*, EffectSetting*, int);
    void QueueReference(TESObjectREFR*, int, bool);
    void QueueBoundObjectModel(TESBoundObject*, void*, int, QueuedFile*, TESObjectREFR*);
    void QueueBoundObjectModel(TESBoundObject*, int, QueuedFile*, TESObjectREFR*);
    void QueueTESModel(TESModel*, int, QueuedFile*, TESObjectREFR*);
    void QueueModelWithOptions(TESModel*, int, QueuedFile*, TESObjectREFR*, bool, bool);
    void QueueModelList(void*, FileEntryListCollection*, int, QueuedFile*, char*);
    void QueueFileList(void*, int, QueuedFile*, char*);
    void QueueReplacementKFList(void*, Animation*, int, QueuedFile*, char*);
    void QueueHead(TESNPC*, void*, int, QueuedFile*);
    void QueueBipedAnimation(BipedAnim*, void*, int, QueuedFile*, int);
    KFModel* FindIdleKFModel(char*, AnimIdle*, int, TESObjectREFR*);
    void QueueTreeBillboard(char*, ModelLoadData*);
    void QueueFileLoad(char*, int, QueuedFile*, int);
    void EnqueueModelFile(char*, int, QueuedFile*, int);
    void QueueModelFile(TESModel*, int, QueuedFile*, int);
    void QueueAlternateModel(TESModel*, int, QueuedFile*, int);
    bool QueueFileFromArchive(BSFileEntry*, int, QueuedFile*);
    void QueueModelLoad(char*, bool, unsigned int);
    void ReleaseKF(char*, bool);
    void CancelReplacementKFList(Animation*);
    void CancelAnimIdle(AnimIdle*);
    void CancelReferenceFiles(TESObjectREFR*);
    void CancelReferencesForCell(TESObjectCELL*);
    bool IsReferenceQueued(TESObjectREFR*);
    TESModel* GetModelForBoundObject(TESBoundObject*, TESObjectREFR*);
    bool BoundObjectOrModelAlreadyQueued(TESObjectREFR*, TESModel*, int, bool);
    void UpdateQueuedReferencePriorities(TESObjectCELL*);
    void PauseBackgroundCloning();
    void ResumeBackgroundCloning();
    void QueueDistant3DTask(AttachDistant3DTask*);
    bool IsBackgroundCloningPaused();
    bool UpdateReferencesToQueue();
    bool SetLoadTexturesDegraded(bool);
    bool GetLoadTexturesDegraded();
    void UpgradeTextures(NiAVObject*);
    bool AddLoadedFileToMap(char*, LoadedFile*);
    void RemoveLoadedFileFromMap(char*);
    LoadedFile* GetLoadedFileFromMap(char*);
    void DebugMessage(char*, ...);
    void DisplayBackgroundLoadDebugText(int, int*, int*, bool);
    void DisplayDebugLoadingText();
    static void UpdateQueueCallback();
    static bool UpdateSecondaryQueueCallback();
    static void LoadQueuedPriorityCallback(float);
    static unsigned int GetExternalCountCallback();
    static void PauseCallback();
    static void ResumeCallback();
    void SetExiting();
    void AddBackgroundCloneReference(QueuedReference*);
    void RemoveReferenceFromMap(TESObjectREFR*);
    void RemoveAnimIdleFromMap(AnimIdle*);
    void RemoveReplacementKFListFromMap(Animation*);
    void RemoveHelmetFromMap(TESObjectREFR*);
    bool RegisterQueuedTexture(BSFileEntry*, QueuedTexture*);
    void RemoveQueuedTextureFromMap(BSFileEntry*);
    QueuedTexture* GetQueuedTextureFromMap(BSFileEntry*);
    bool HasQueuedTextures();
    unsigned int GetBackgroundCloningCount();
    unsigned int GetQueuedReferenceCount();
    unsigned int GetQueuedHelmetCount();
    bool AddModel(char*, Model*);
    bool AddKF(char*, KFModel*);
    NiNode* LoadFile(char*, int, bool, bool, bool, bool);
    KFModel* LoadKF(char*);
    void LoadPSA(char*, void*);
    bool FindModel(char*, void*);
    void* UpdateLoadingStatusCallback(char*, char*, void*);
    void* BuildNIFFileList(char*);
    void* GetModelFileList(char*, bool, bool, int);
    void* FindNIFFileListEntry(void*, void*);
    bool ProcessQueuedFile(TESObjectCELL*);
    KFModel* FindKFModel(char*);
    KFModel* FindKFModel(NiControllerSequence*);
    KFModel* FindKFModel(TESAnimGroup*);
    void CancelAllFiles();
    void SetLoadingEnabled(bool);
    void ReleaseFile(char*);
    void ReleaseKFFile(char*);
    void UpdateReferenceNode(TESObjectREFR*, NiNode*);
    void UpdateModelNode(NiNode*);
    bool QHasDelayedFree();
    static int GetArchiveTypeIndexForIOFileIndex(int);
    static int GetIOFileIndexForArchiveTypeIndex(int);
    void AddModelToMap(Model*, char*);
    void* __vecDelDtor(unsigned int);
    void* m_pLoadedModelMap;
    void* m_pLoadedKFModelMap;
    void* m_pQueuedReferenceMap;
    void* m_pQueuedReferenceUpdateMap;
    void* m_pQueuedAnimIdleMap;
    void* m_pQueuedReplacementKFListMap;
    void* m_pQueuedHelmetMap;
    void* m_pDistant3DTaskQueue;
    void* m_pQueuedTextureMap;
    void* m_pLoadedFileMap;
    BackgroundCloneThread* m_pBackgroundCloneThread;
    bool m_bLoadTexturesDegraded;
    char _pad_2d[3];
};
typedef char _sizecheck_ModelLoader[sizeof(ModelLoader) == 48 ? 1 : -1];
struct FUN_004409e0_shell : public ModelLoader
{
    void FUN_004409e0(TESObjectREFR*);
};

struct _Vtbl004409e0
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10();
    virtual void v14(TESObjectREFR*);
};

struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct TESForm;
struct BGSLoadGameSubBuffer
{
    void SetBuffer(char*);
    void ResetReadPosition();
    void RestoreAnimation(TESForm*);
    void ReadAnimationState(TESForm*);
    void LoadHavokData(TESForm*);
    void SaveAnimation(TESForm*);
    void SaveFormState(TESForm*);
    void SaveGame(BGSSaveGameBuffer*);
    void LoadGame(BGSLoadGameBuffer*);
    BGSLoadFormBuffer* CreateFormBuffer(TESForm*);
    void RenderCopyData(BGSSaveFormBuffer*);
    char* pBuffer;
};
typedef char _sizecheck_BGSLoadGameSubBuffer[sizeof(BGSLoadGameSubBuffer) == 4 ? 1 : -1];
struct FUN_0044dee0_shell : public BGSLoadGameSubBuffer
{
    void FUN_0044dee0(char*);
};

struct TESObjectCELL;
struct TESWorldSpace;
struct PlayerTargetLocation
{
    TESWorldSpace* pWorld;
    TESObjectCELL* m_pCell;
    char Location[12];
    char Angle[12];
    bool m_bHasTargetLocation;
    char _pad_21[3];
    int* m_pIntegerData;
    long m_lValue;
    TESObjectREFR* m_pFirstReference;
    TESObjectREFR* m_pSecondMapReference;
};
typedef char _sizecheck_PLAYER_TARGET_LOC[sizeof(PlayerTargetLocation) == 52 ? 1 : -1];
struct FUN_00456540_shell : public PlayerTargetLocation
{
    void FUN_00456540();
};

struct _NiPoint3_pod
{
    float x, y, z;
};

void __fastcall _ref_006815c0(void* pThis);
extern _NiPoint3_pod _NiPoint3_ZERO;

namespace fnv_004a3e00 {
struct NiStream;
struct FourComponentNumericValue;
struct blob1
{
    char b[1];
};
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];

float __cdecl FUN_004a3e90(float);

struct bhkCharacterController
{
    float& GetVectorElement(int);
};

}  // namespace fnv_004a3e00

struct Actor;
struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct ExtraDataList;
struct InventoryIterator;
struct InventoryStackRecord;
struct IndexedPointerCollection;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESForm;
struct TESLevItem;
struct TESObject;
struct TESObjectWEAP;
struct InventoryChanges
{
    void ForceWeightRecalculation();
    static void KillTempRef();
    void AddItemToEntry(TESBoundObject*, int, Actor*, ExtraDataList*, InventoryStackRecord*);
    bool IsEmpty();
    void AddItem(TESBoundObject*, ExtraDataList*, int);
    void AddItem(TESObjectREFR*, int, bool, bool);
    void AddChangeEntry(InventoryStackRecord*, bool);
    void RemoveChangeItem(TESBoundObject*);
    TESObjectREFR* RemoveItem(TESObjectREFR*, TESBoundObject*, bool, int, ExtraDataList*, bool, TESObjectREFR*, void*,
                              void*, bool, bool, InventoryStackRecord*);
    void UpdateItemCount(int, bool, int);
    TESObjectREFR* DropItem(TESObjectREFR*, TESBoundObject*, int, TESObjectREFR*, void*, void*);
    void PutItemIntoContainer(TESBoundObject*, int, TESObjectREFR*, ExtraDataList*);
    void DamageItem(TESBoundObject*, float);
    void RepairBatch(TESBoundObject*, float);
    void AddOwnership(TESBoundObject*, TESForm*);
    void RemoveOwnership(TESBoundObject*);
    TESContainer* GetOriginalContainer();
    void RemoveBoundItem(TESBoundObject*, int, Actor*, ExtraDataList*, bool, bool);
    bool RemoveInventoryItem(bool*, TESBoundObject*, int, Actor*, ExtraDataList*, bool, bool, InventoryStackRecord*, bool*);
    void ResetInventoryChanges();
    bool RunScripts(TESObjectREFR*);
    void ResetInventoryState();
    void CleanUpBoundItems(Actor*);
    TESBoundObject* GetLeveledCalculatedBaseObject(TESLevItem*);
    void ModifyCharge(float);
    InventoryStackRecord* GetOrCreateInventoryEntry(TESBoundObject*, bool, unsigned int);
    static InventoryChanges* CreateForReference(TESObjectREFR*);
    ExtraDataList* GetExtraDataListForObject(TESBoundObject*, bool);
    bool WearingWeapon(TESBoundObject**);
    bool WearingAmmo(TESBoundObject**);
    bool WearingTorch(TESBoundObject**);
    InventoryStackRecord* WearingRing(bool);
    bool WearingVoiceModulateItem();
    bool HasItemOfType(unsigned int);
    bool FindItemInInventory(TESBoundObject*, int, int, int*, unsigned int, TESObjectREFR*);
    bool HasQuestObject();
    bool HasScript();
    TESBoundObject* GetObjectAtIndex(int, int*);
    TESBoundObject* GetBoundObjectByIndex(int, int*);
    InventoryStackRecord* GetPotion(void*);
    InventoryStackRecord* GetBestAmmoForActor(TESActorBase*, bool);
    TESAmmo* GetBestAmmoForWeapon(TESObjectWEAP*, bool*);
    InventoryStackRecord* GetBestWeapon(TESActorBase*, float*, int, bool);
    InventoryStackRecord* FindBestArmor(TESActorBase*, int, bool);
    void* GetListBestArmor(TESActorBase*);
    InventoryStackRecord* GetBestClothing(TESActorBase*, int, bool);
    InventoryStackRecord* GetBestLight(TESActorBase*, bool);
    InventoryStackRecord* GetInventoryEntryData(int, bool);
    InventoryStackRecord* GetEquippedItemForSlot(int);
    InventoryStackRecord** GetEntryPointerByIndices(int, int);
    void SetHotKeyItem(InventoryStackRecord*, ExtraDataList*, int);
    void SetInventoryEntryCount(InventoryStackRecord*, int);
    void RemoveAllObjectsWorn(bool, TESObjectREFR*);
    bool RechargeAll();
    void RemoveAllHealth();
    int GetCount(bool);
    InventoryStackRecord* GetInventoryEntryAtIndex(int);
    IndexedPointerCollection* GetFirstItem();
    InventoryStackRecord* GetEntryForListNode(IndexedPointerCollection*);
    void RemoveItemChangeEntry(TESBoundObject*, void*);
    void RefreshItemChange(TESBoundObject*, void*);
    void UpdateItemChangeEntry(TESBoundObject*, void*);
    int GetObjectCount(int);
    int GetObjectCount(TESBoundObject*);
    InventoryStackRecord* GetFirstInventoryEntry();
    int GetInventoryEntryCount();
    void TransferItemToReference(TESObjectREFR*, int, TESObjectREFR*);
    float RemoveAllTypedItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, BGSListForm*);
    float RemoveAllItems(TESObjectREFR*, TESObjectREFR*, bool, bool, bool, bool, int, BGSListForm*);
    void DuplicateAllItems(TESObjectREFR*, TESObjectREFR*);
    void MoveItemsOfType(TESObjectREFR*, TESObjectREFR*, TESForm*);
    void RemoveNonStolenItems(TESObjectREFR*, TESObjectREFR*);
    float GetInventoryWeight(bool);
    unsigned int GetTotalItemCount(bool, bool);
    void AddAmountToItemChange(TESBoundObject*, int);
    float GetArmorValueForActor(Actor*);
    void UpdateArmorWeight();
    void UpdateWeight();
    void RemoveDefaultLeveledItems();
    bool IsLevelItemInited(int);
    InventoryStackRecord* FindEntryForObject(TESBoundObject*, unsigned int);
    void SetItemsBacktoDefaultState();
    void CopyInventoryChanges(InventoryChanges*, TESObjectREFR*, bool);
    void ResetEntryList();
    void ResetCachedWeights();
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    int GetExtraDataListIndexForItem(TESBoundObject*, ExtraDataList*);
    ExtraDataList* GetExtraDataListFromIndexForItem(TESBoundObject*, int);
    unsigned int FindItemEntryData(int*, void*, unsigned int);
    bool GetNextItem(InventoryIterator*, InventoryStackRecord**, unsigned int);
    TESObjectREFR* GetRef();
    static TESObjectREFR* GetTempRef();
    void RemoveExtraFromObject(TESObject*, ExtraDataList*);
    void DeleteExtraData(TESBoundObject*, ExtraDataList*);
    void* __vecDelDtor(unsigned int);
    void* m_pEntryList;
    TESObjectREFR* pRef;
    float m_fTotalWeight;
    float m_fArmorWeight;
    bool m_bChanged;
    char _pad_11[3];
};
typedef char _sizecheck_InventoryChanges[sizeof(InventoryChanges) == 20 ? 1 : -1];
struct FUN_004bffb0_shell : public InventoryChanges
{
    TESContainer* FUN_004bffb0();
};

TESContainer* __fastcall FUN_0055d310(TESObjectREFR*);

class RecursiveSpinLock
{
  public:
    void Unlock();
};

struct ReferenceIntersectionData
{
    void Endian();
    TESObjectREFR* m_pHitReference;
    char Intersect[12];
    char Normal[12];
};
typedef char _sizecheck_REF_DECAL_DATA[sizeof(ReferenceIntersectionData) == 28 ? 1 : -1];
struct FUN_0055a400_shell : public ReferenceIntersectionData
{
    void FUN_0055a400();
};

void __fastcall _ref_006815c0(void* pThis);

namespace fnv_0055d420 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSImpactDataSet;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CombatGroupCollection;
struct CellMopp;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct CellRecord;
struct DialogueResponse;
struct DetectionParameters;
struct ExteriorData;
struct EffectItem;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanFloatQuery;
struct IDebugText;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct InventoryStackRecord;
struct LoadedCellData;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SeenData;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESClimate;
struct TESCombatStyle;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESIdleForm;
struct TESImageSpace;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct _D3DLOCKED_RECT;
struct bhkCharacterController;
struct BhkPickData;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct bhkWorld;
struct bhkWorldM;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct CachedValuesOwner
{
    virtual float GetFloatValue0();
    virtual float GetFloatValue1();
    virtual float GetFloatValue2();
    virtual float GetFloatValue3();
    virtual float GetFloatValue4();
    virtual float GetFloatValue5();
    virtual float GetFloatValue6();
    virtual float GetFloatValue7();
    virtual float GetFloatValue8();
    virtual float GetFloatValue9();
    virtual float GetFloatValue10();
    virtual float GetFloatValue11();
    virtual int GetIntegerValue12();
    virtual int GetIntegerValue13();
    virtual float GetFloatValue14();
    virtual float GetFloatValue15();
    virtual bool GetBooleanValue16();
    void PrecalculateCachedValues();
};
typedef char _sizecheck_CachedValuesOwner[sizeof(CachedValuesOwner) == 4 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct FUN_0055d420_shell : public TESObjectREFR
{
    void FUN_0055d420(bool);
};

struct TESForm
{
    bool IsTemporary() const;
    void SetAltered(bool);
};
struct FUN_0055d420_Tgt
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
    virtual void SetFlag(bool);
};
struct FUN_0055d420_Holder
{
    virtual FUN_0055d420_Tgt* Get();
};
}  // namespace fnv_0055d420

struct FUN_0055d520_shell : public TESObjectREFR
{
    char* FUN_0055d520();
};

class TESForm;
struct TESFullName
{
    static char const* __cdecl GetFullName(TESForm*);
};
struct TESFile
{
    char const* GetName();
};

struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct TESActorBase;
struct TESFaction;
struct TESForm;
struct TESLevItem;
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESActorBaseData : public BaseFormComponent
{
    virtual void CopyFromTemplateForm(TESActorBase*);
    virtual bool GetVATSmeleeDisabled();
    virtual bool GetNoVATSranged();
    virtual bool GetCanBePickpocketed();
    virtual bool GetIsGhost();
    virtual bool GetIsInvulnerable();
    virtual bool GetNoKnockdowns();
    virtual bool GetCanBeAllRaces();
    virtual bool GetNoHeadTracking();
    virtual bool GetNoPersuasion();
    virtual bool GetNoLeftArm();
    virtual bool GetNoRightArm();
    virtual bool GetNoHead();
    virtual bool GetNoShadow();
    virtual bool GetNoBloodSpray();
    virtual void SetNoBloodSpray(bool);
    virtual bool GetNoBloodDecal();
    virtual void SetNoBloodDecal(bool);
    virtual int GetBloodImpactMaterial();
    virtual void SetBloodImpactMaterial(int);
    virtual unsigned short GetFatigue();
    virtual float GetHealthRegeneration();
    virtual BGSVoiceType* GetVoiceType();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    bool QCopiedTemplate();
    void SetCopiedTemplate(bool);
    void SetTemplateUseFlag(int, bool);
    bool GetTemplateUseFlag(int);
    TESForm* QTemplateForm();
    void SetTemplateForm(TESForm*);
    unsigned short QTemplateUseFlags();
    void SetTemplateUseFlags(unsigned short);
    bool GetUsesLeveledTemplate();
    bool IsTemplateLeveled();
    void SetTemplateReference(TESObjectREFR*);
    static TESActorBase* GetTemplateForActorBase(TESActorBase*, TESActorBase*);
    static bool HasCircularTemplateHierarchy(TESActorBase*);
    static bool IsActorBaseInTemplateHierarchy(TESActorBase*, TESActorBase*);
    static TESForm* GetLeveledTemplateInHierarchy(TESActorBase*, unsigned short*);
    int* GetFlags();
    void SetFlags(int);
    bool GetFlagBit(int);
    void UpdateFlagBit(int, bool, bool);
    bool IsEssentialActor();
    void SetEssential(bool);
    bool GetRespawn();
    void SetRespawn(bool);
    bool GetRunsInLow();
    void UpdateRunsInLow(bool, bool);
    bool GetKnockedDowns();
    void SetKnockedDowns(bool);
    bool GetNotPushable();
    void SetNotPushable(bool);
    bool GetNoRotatingToHeadtrack();
    void SetNoRotatingToHeadtrack(bool);
    bool GetMatchesPCLevel();
    void SetMatchesPCLevel(bool);
    bool GetSummonable();
    void SetSummonable(bool);
    bool GetNoRumors();
    void SetNoRumors(bool);
    void SetNoVATSMelee(bool);
    void SetAllowPCDialogue(bool);
    void SetAllowPickPocket(bool);
    void SetIsGhost(bool);
    void SetInvulnerable(bool);
    void SetCantOpenDoors(bool);
    void SetCanBeAllRaces(bool);
    void SetAutoCalcServiceFlags(bool);
    unsigned short GetLevelExact();
    unsigned short GetLevel();
    void SetLevel(unsigned short);
    unsigned short GetCalcLevelMin();
    void SetCalcLevelMin(unsigned short);
    unsigned short GetCalcLevelMax();
    void SetCalcLevelMax(unsigned short);
    unsigned short GetBaseDisposition();
    void SetBaseDisposition(unsigned short);
    TESLevItem* GetDeathItem();
    void SetDeathItem(TESLevItem*);
    void SetFatigue(unsigned short);
    static int ConvertToInteger(float);
    static char* GetActorDisplayName(Actor*);
    void SetKarmaValue(float);
    void ModKarma(float);
    unsigned short GetBarterGold();
    void SetBarterGold(unsigned short);
    int GetFactionReaction(TESActorBase*, int*);
    int GetFactionRank(TESFaction*, bool);
    void SetFactionRank(TESFaction*, char);
    void ModFactionRank(TESFaction*, char, bool);
    bool GetGhostFlag();
    bool CanBeDetected();
    void* GetFactionList();
    unsigned short GetSpeedMult();
    void SetSpeedMult(unsigned short);
    void SetVoiceType(BGSVoiceType*);
    void AddFormChange(int);
    void RemoveFormChange(int);
    void AddFormChangeFlags(int);
    void ClearChangeFlags(int);
    int GetChangeFlags();
    unsigned short GetSaveSize(unsigned int);
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame(unsigned int);
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame(unsigned int, unsigned int);
    void SetPCFactionFlags(int);
    bool HasFaction(TESFaction*);
    void RemoveAllFactions();
    void CopyFactionList(TESActorBaseData*);
    void* __vecDelDtor(unsigned int);
    char actorData[24];
    TESLevItem* m_pBaseTemplateForm;
    BGSVoiceType* m_kFactionList;
    TESForm* m_ppTemplateForms;
    int m_pDeathItem;
    char m_pVoiceType[8];
};
typedef char _sizecheck_TESActorBaseData[sizeof(TESActorBaseData) == 52 ? 1 : -1];
struct FUN_0055e200_shell : public TESActorBaseData
{
    bool FUN_0055e200();
};

struct hkBool
{
    char m_cBooleanValue;
};
typedef char _sizecheck_hkBool[sizeof(hkBool) == 1 ? 1 : -1];
struct FUN_005609f0_shell : public hkBool
{
    bool FUN_005609f0();
};

namespace fnv_00560d80 {
struct PhysicsSimulationContext;
struct hkMatrix3;
struct hkMotionState;
struct hkMultiThreadCheck;
struct hkReferencedObject;
struct hkStatisticsCollector;
struct hkTransform;
struct hkVector4;
struct hkaiObjectData;
struct hkdBreakableBody;
struct hkpAction;
struct hkpBreakableBody;
struct hkpCollidable;
struct hkpConstraintInstance;
struct hkpContactListener;
struct hkpDynamicsContactMgr;
struct hkpEntity;
struct hkpEntityActivationListener;
struct hkpEntityListener;
struct hkpLinkedCollidable;
struct hkpMaterial;
struct hkpMaxSizeMotion;
struct hkpMotion;
struct hkpRigidBody;
struct WorldPhysicsSettings;
struct hkpSimulationIsland;
struct hkpWorld;
struct blob1
{
    char b[1];
};
struct blob8
{
    char b[8];
};

const hkVector4& __cdecl FUN_00458b20(void);
hkpRigidBody* __fastcall FUN_004ae750(void*);
const hkVector4& __fastcall FUN_00560dc0(hkpRigidBody*);

}  // namespace fnv_00560d80

template <class T> class BSSimpleList;
class BGSRagdoll;

class TESDataHandler
{
  public:
    BSSimpleList<BGSRagdoll*>* GetBGSRagdollList();
};

int __fastcall FUN_004b4f20(void* pThis);

class bhkCharacterController
{
  public:
    float& GetVectorElement(int);
};
class Modifier
{
  public:
    float GetValue(void);
};
class BSFaceGenKeyframe
{
  public:
    float GetTime(void);
};
class Twin_0084d030
{
  public:
    float GetStoredFloatValue(void);
};
class RegionPoint
{
  public:
    float GetX(void);
};

struct TESBoundObjectX;
struct ScriptLocalsX
{
    TESBoundObjectX* GetLocalData();
};
struct ScriptX
{
    void GetLocalData();
};
struct ObjX
{
    void FUN_00c93a20(int);
};
struct S
{
    void FUN_00561690(int a);
};

struct Actor;
struct BGSLoadFormBuffer;
struct BGSReconstructFormsInAllFilesMap;
struct BGSSaveLoadChangesMap;
struct SaveLoadFile;
struct FormIDConverter;
struct SaveLoadChangeHistory;
struct LoadGameSubBufferQueue;
struct BGSSaveLoadReferencesMap;
struct IDebugText;
struct TESForm;
struct TESObjectCELL;
struct blob4
{
    char b[4];
};
struct BGSSaveLoadGame
{
    static void Create();
    static void Destroy();
    void ApplyFormChanges(BGSSaveLoadChangesMap*, FormIDConverter*);
    void LoadCellChanges(bool);
    void LoadForm(TESForm*);
    void SetFormLoaded(TESForm*, bool);
    bool ShouldUnloadForm(TESForm*);
    void FormReconstructionMap(TESObjectCELL*);
    bool ContainsReference(unsigned int);
    bool ShouldSaveForm(TESForm*, bool);
    void NotifyFormIDChanged(TESForm*, struct blob4, bool);
    bool HasFormChangeFlags(TESForm*, struct blob4);
    bool GetOldChange(TESForm*, struct blob4);
    bool IsFormChanged(TESForm*);
    void ClearFormChangeFlags(TESForm*, struct blob4);
    void HasFormChanges(TESForm*);
    void ClearAllForms();
    void CleanupExpiredData();
    void ProcessSubBuffer(int, BGSLoadFormBuffer*, TESForm*);
    void ClearForm(TESForm*);
    void ClearFormID(unsigned int);
    void DeleteForm(TESForm*);
    void ChangeFormID(unsigned int, unsigned int);
    unsigned int GetNewFormID(unsigned int);
    bool IsFormIDRemapped(unsigned int);
    void AreStringsEqual(char*, char*);
    void DisplayReferenceDebugText(TESObjectREFR*, IDebugText*);
    void DisplayCellDebugText(TESObjectREFR*, IDebugText*);
    FormIDConverter* GetFormIDMap();
    FormIDConverter* GetWorldspaceFormIDMap();
    SaveLoadChangeHistory* GetHistory();
    BGSReconstructFormsInAllFilesMap* GetReconstructFormsMap();
    unsigned char GetConvertedFileIndex(unsigned char);
    unsigned char GetReverseConvertedFileIndex(unsigned char);
    unsigned char GetLoadState();
    bool SetGlobalAllowChanges(bool);
    bool GetGlobalAllowChanges();
    void SetDeferInitForms(bool);
    bool GetDeferInitForms();
    void SetSaveGameLoading(bool);
    bool GetSaveGameLoading();
    void SetSaveGameSaving(bool);
    bool GetSaveGameSaving();
    void SetInitingForms(bool);
    bool GetInitingForms();
    void SetPositioningPlayerCharacter(bool);
    bool GetPositioningPlayerCharacter();
    void SetPlayerLocationInvalid(bool);
    bool GetPlayerLocationInvalid();
    void SetSaveLoadFailed(bool);
    bool GetSaveLoadFailed();
    bool SetThreadAllowChanges(bool);
    bool GetThreadAllowChanges();
    void SetLoadingMovedRefs(bool);
    bool GetLoadingMovedRefs();
    void SetReconstructingForms(bool);
    bool GetReconstructingForms();
    bool GetAllowChanges();
    void SaveGame(SaveLoadFile*);
    bool LoadGame(SaveLoadFile*, bool);
    void PrepareLoadGame(SaveLoadFile*);
    bool IsValidSaveGame(SaveLoadFile*);
    unsigned int LoadFormRecord(SaveLoadFile*, BGSLoadFormBuffer*, FormIDConverter*);
    bool FindFormByID(TESForm**, struct blob4, bool);
    void InitializePackageLocations(Actor*);
    void CancelInitPackageLocations(Actor*);
    void ClearFormChanges();
    BGSSaveLoadChangesMap* GetChangesMap();
    void* __vecDelDtor(unsigned int);
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    BGSSaveLoadChangesMap* m_pSecondChangesMap;
    FormIDConverter* m_pSecondSaveLoadData;
    FormIDConverter* m_pSaveLoadData;
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    LoadGameSubBufferQueue* m_pSaveLoadMap;
    void* m_pAuxiliaryData;
    SaveLoadChangeHistory* m_pNoteHandler;
    BGSReconstructFormsInAllFilesMap* m_pFormReconstructionMap;
    char LoadFormBufferArray[16];
    char m_acTextBuffer[16];
    char m_acFirstTextBuffer[255];
    char m_acSecondTextBuffer[255];
    char _pad_242[2];
    unsigned int m_uiInitializationFlags;
    unsigned char m_ucSaveLoadState;
    char _pad_249[3];
};
typedef char _sizecheck_BGSSaveLoadGame[sizeof(BGSSaveLoadGame) == 588 ? 1 : -1];
struct FUN_005621d0_shell : public BGSSaveLoadGame
{
    bool FUN_005621d0();
};

namespace fnv_00562d00 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FUN_00562d00_shell : public BGSLoadFormBuffer
{
    bool FUN_00562d00();
};

}  // namespace fnv_00562d00

namespace fnv_005636e0 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_005636e0_shell : public TESObjectREFR
{
    void FUN_005636e0(BGSLoadFormBuffer*);
};

class NiNode;
class ExtraDataList;
class NiRTTI;

class Model
{
  public:
    NiNode* GetObject3D();
};

class BGSOpenCloseForm
{
  public:
    static bool __cdecl HasOpenCloseComponent(TESForm*);
};

class TaskQueueInterface
{
  public:
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};

extern NiRTTI DAT_011f36ac;
extern float DAT_0102f510;

void* __cdecl DynamicCastByRTTI(void*, NiNode*);
template <typename T> unsigned int __cdecl BSStringLength(const T*);
int __cdecl _stricmp(const char*, const char*);
void __cdecl UpdatePackagesFromBuffer(void*, BGSLoadFormBuffer*, float);

struct FakeExtra
{
    void __thiscall FUN_00422850(const char*);
};

struct FakeREFR
{
    Model* __thiscall GetReferenceType();
    const ExtraDataList* __thiscall GetExtra() const;
    TESForm* __thiscall _FNV_GetObjectReference();
    void __thiscall FUN_00563d80(void*, const char*, float);
};

}  // namespace fnv_005636e0

namespace fnv_00564930 {
struct FUN_00564930_shell : public TESObjectREFR
{
    void FUN_00564930(bool);
};

struct TESForm
{
    bool IsTemporary() const;
    void MarkForDeletion(bool);
    unsigned int _ref_0084e3a0();
};
struct TESDataHandler
{
    bool FUN_004226e0();
    bool FormIDExists(unsigned int);
};
struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
    void HasFormChanges(TESForm*);
};
extern TESDataHandler* g_dataHandler;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
}  // namespace fnv_00564930

void* __fastcall _FNV_GetObjectReference(void* _this);
unsigned int __fastcall _FNV_GetFormType(void* _this);

struct TESObjectREFR_GetFlags_Helper
{
    unsigned int GetFlags();
};

struct VTable64
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
    virtual bool v64();
};

unsigned int __fastcall FUN_0044ddc0(void*);

struct BSExtraData;
struct TESForm;
struct FUN_00564f00_shell : public TESObjectREFR
{
    bool FUN_00564f00();
};

struct TESObjectREFR_Helper
{
    BSExtraData* GetExtraData(unsigned char) const;
};

unsigned int __fastcall _ref_0084e3a0(BSExtraData*);

class BSExtraData;
unsigned int __fastcall _ref_0084e3a0(BSExtraData* pExtra);

struct FUN_00565050_shell : TESObjectREFR
{
    BSExtraData* GetExtraData(unsigned char) const;
    bool FUN_00565050();
};

class BSExtraData;
unsigned int __fastcall _ref_0084e3a0(BSExtraData* pExtra);

struct FUN_00565090_shell : public TESObjectREFR
{
    BSExtraData* GetExtraData(unsigned char) const;
    bool FUN_00565090();
};

struct FUN_005651e0_shell : public TESObjectREFR
{
    bool FUN_005651e0();
};

unsigned int __fastcall TESObjectREFR_GetFlags(TESObjectREFR*);

struct FUN_00565210_shell : public TESObjectREFR
{
    void FUN_00565210(bool);
};

struct TESObjectREFR_Flags : public TESObjectREFR
{
    unsigned int GetFlags();
    void SetFlags(unsigned int);
};

namespace fnv_005653d0 {
struct BSFile;
struct FormRecordHeader;
struct TESFileGroup;
struct TESBitArrayFile;
struct TESForm;
struct TESObjectCELL;
struct _FILETIME;
struct _SYSTEMTIME;
struct _WIN32_FIND_DATAA;
struct TESFile
{
    bool CreateTES(char*, char*, int);
    bool CreateTES(int);
    bool OpenTESFile(char*, char*, int, bool);
    bool OpenTESFile(int, bool);
    bool CloseTESFile();
    bool DeleteTES();
    bool IsOpen();
    bool QDLC();
    void SetDLC(bool);
    int ReadTESInfo();
    int SaveTESInfo();
    int RewriteFormHeader();
    TESForm* BuildTESInfoForm();
    int GetFormCount();
    void ModFormCount(int);
    void SetFormCount(int);
    int GetFileLanguage();
    void SetFileLanguage(int);
    float GetFileVersion();
    void SetFileVersion(float);
    bool IsValidFileVersion();
    unsigned int GetFORMSize();
    char* GetPath();
    char* GetFilename();
    unsigned int GetFileSize();
    _WIN32_FIND_DATAA* GetFileData();
    void GetCreateTime(_SYSTEMTIME*);
    void GetLastWriteTime(_FILETIME*);
    void GetLastWriteTime(_SYSTEMTIME*);
    void* GetCreator();
    void* GetSummary();
    bool MastersChecked(void*);
    bool CheckMasterFiles(void*, bool);
    TESFile* GetMasterFile(unsigned int);
    char* GetMasterFileName(unsigned int);
    unsigned int GetMasterFileCount();
    unsigned int GetFileIndex(TESFile*);
    void ClearMasters();
    void AddMaster(char*);
    bool AddMasters(void*);
    void RemoveMaster(unsigned int);
    bool DependsOnMaster(char*);
    bool MastersChanged();
    bool CheckLODPlugins();
    void* GetMasterList();
    unsigned char GetFileCompileIndex();
    void SetCompileIndex(unsigned char);
    void AddToDataHandler();
    bool CurrentGroupMayContainForm(TESForm*);
    void GetAnimationSequence(FormRecordHeader*);
    void ClearGroupStack();
    void OpenGroup(FormRecordHeader*);
    void CloseGroup();
    bool IsFormInCurrentGroup(TESForm*);
    bool IsGroupOpen();
    void SetCurrentForm(TESForm*);
    void ResetCurrentForm();
    TESFileGroup* GetCurrentGroup();
    void* GetGroupList();
    void SetGroupMode(bool);
    void TESRewindChunk();
    bool NextForm(bool);
    bool HasNextForm();
    void RewindForm();
    int GetTESForm();
    unsigned int GetOffset();
    unsigned int GetOffsetChunk();
    bool SetOffset(unsigned int);
    bool SetOffsetChunk(unsigned int);
    int GetFormAtOffset(unsigned int);
    unsigned int CopyCurrentFormToBuffer(void*, unsigned int);
    int ReadCurrentForm();
    bool NextChunk();
    unsigned int GetChunkSize();
    bool GetChunkData(unsigned short*);
    bool GetChunkData(short*);
    bool GetChunkData(float*);
    bool GetChunkData(unsigned int*);
    bool GetChunkData(int*);
    bool GetChunkData(void*, unsigned int);
    void ClearCurrentChunk();
    bool HasMaster(char*);
    int WriteForm(TESForm*);
    int WriteFormContents(TESForm*);
    void LoadForm(TESForm*);
    int WriteChunkData(int, void*, unsigned int);
    unsigned int GetCurrentReadPosition();
    bool ForceSaveFormHeader(FormRecordHeader*, unsigned int);
    void SetMasterFile(bool);
    bool IsMasterFile();
    void SetOptimizedFile(bool);
    bool GetOptimizedFile();
    void SetChecked(bool);
    bool GetIsChecked();
    void SetAltered(bool);
    bool GetAltered();
    void SetActive(bool);
    bool GetActive();
    void SetLittleEndian(bool);
    bool GetLittleEndian();
    bool QEndian();
    void SetUnicode(bool);
    bool GetUnicode();
    bool GetHasGroups();
    void SetHasGroups(bool);
    float GetPercentage();
    void CopyToBackup();
    static void DeleteFileList(void*);
    TESFile* GetParentTESFile();
    TESFile* GetThreadSafeRootFile();
    void CopyThreadSafeParentAuxBuffer();
    void ClearAuxBuffer();
    void SetFile(BSFile*);
    BSFile* GetFile();
    int GetLastFileError();
    FormRecordHeader* GetFormData();
    unsigned int GetID();
    unsigned short GetFormVersion();
    bool TakeOwnership();
    static bool TakeFileOwnership(char*);
    static unsigned short GetFileFormVersion();
    void SetCached(bool);
    void SetCaching(bool);
    void ResetWithCachedFile();
    bool GetCached();
    bool GetCaching();
    unsigned int GetMasterCount();
    unsigned int GetFlags();
    unsigned int GetFNVVersionInfo();
    void InitEndian();
    bool IsCurrentFormCompressed();
    unsigned int GetDecompressedBufferSize();
    char* GetDecompressedBuffer();
    void ReleaseDecompressedBuffer();
    void ClearDecompressedBuffer();
    bool ReadFormHeader();
    bool ReadChunkHeader();
    void* GetMasterDataList();
    void ClearMasterLists();
    void ClearThreadSafeFiles();
    void SetThreadSafeParent(TESFile*);
    TESFile* GetFileForThread(unsigned int);
    int ReadFileBuffer(void*, unsigned int);
    void MoveToFilePosition(int);
    bool IsTempIDLoadable(unsigned int, unsigned int);
    void SetTempIDOwner(bool);
    bool GetTempIDOwner();
    static void SetTempIDOwnerForForm(unsigned int, TESFile*);
    static bool GetTempIDCanLoadFromFile(unsigned int, TESFile*);
    static TESFile* GetTempIDOwnerFile(unsigned int);
    void ClearTempIDOwner();
    void* __vecDelDtor(unsigned int);
    int m_eReturnCode;
    TESFile* m_pThreadSafeParent;
    void* m_pThreadSafeFileMap;
    BSFile* m_pSecondaryFile;
    BSFile* m_pFile;
    TESBitArrayFile* m_pBitArrayFile1;
    TESBitArrayFile* m_pBitArrayFile2;
    TESBitArrayFile* m_pBitArrayFile3;
    char m_acFilename[260];
    char m_acPath[260];
    char* m_pBuffer;
    unsigned int m_uiBufferAllocSize;
    unsigned int m_uiReadPosition;
    unsigned int m_uiBufferSize;
    TESObjectCELL* m_pCurrentCell;
    unsigned int m_uiFormCount;
    char m_kRecordInfo[24];
    int m_eChunkID;
    unsigned int m_uiChunkSize;
    unsigned int m_uiChunkOffset;
    unsigned int m_uiRecordSize;
    unsigned int m_uiRecordOffset;
    unsigned int m_uiCurrentOffset;
    char m_kChunkInfo[24];
    unsigned int m_uiChunkValue1;
    unsigned int m_uiChunkValue2;
    char m_kRecordList[8];
    bool m_bIsLoading;
    bool m_bIsSaving;
    bool m_bHasCurrentGroup;
    char _pad_29b[1];
    char m_kFindData[320];
    char m_kFileMetadata[12];
    unsigned int m_uiFileCount;
    char m_kFilenameList[8];
    char m_kFileSizeList[8];
    unsigned int m_uiTESFileCount;
    TESFile** m_ppTESFiles;
    char m_kLastWriteTime[8];
    unsigned char m_ucCompileIndex;
    char _pad_40d[3];
    char m_kCreator[8];
    char m_kSummary[8];
    char* m_pDecompressedFormBuffer;
    unsigned int m_uiAuxBufferSize;
    bool m_bIsMaster;
    bool m_bOptimizedFile;
    bool m_bIsDLC;
    char _pad_42b[1];
};
typedef char _sizecheck_TESFile[sizeof(TESFile) == 1068 ? 1 : -1];
struct FUN_005653d0_shell : public TESObjectREFR
{
    bool FUN_005653d0();
};

struct TESDataHandler
{
    bool FUN_004516b0();
    bool FUN_004226e0();
};
extern TESDataHandler* g_dataHandler;

struct TESSaveLoadGame
{
    bool GetLoading();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct _FNVHelper
{
    TESFile* _FNV_GetFile(int);
};

struct _Helper5450
{
    bool FUN_00565450();
};

}  // namespace fnv_005653d0

struct FUN_00565450_shell : public TESObjectREFR
{
    bool FUN_00565450();
};

unsigned int __fastcall FUN_0044ddc0(TESObjectREFR* pThis);

struct ScriptLocals;
struct FUN_005673e0_shell : public TESObjectREFR
{
    ScriptLocals* FUN_005673e0();
};

class ExtraDataList
{
  public:
    ScriptLocals* GetScriptLocalData();
};

struct TESObjectREFR_GetExtra : public TESObjectREFR
{
    const ExtraDataList* GetExtra() const;
};

struct bhkCharacterController_00567730
{
    char _pad[0x550];
    float m_fValueAt550;
    float FUN_00567730() const;
};

namespace fnv_00567770 {
struct TESForm;
struct FUN_00567770_shell : public TESObjectREFR
{
    TESForm* FUN_00567770();
};

class ExtraDataList
{
  public:
    TESForm* GetOwner();
};

ExtraDataList* __fastcall FUN_005d43c0(TESObjectREFR*);

}  // namespace fnv_00567770

namespace fnv_00567960 {
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct CHUNK;
struct TeleportableReference;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESObjectCELL;
struct TESWorldSpace;
struct blob8
{
    char b[8];
};
struct blob16
{
    char b[16];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_00567960_shell : public TESObjectREFR
{
    TESGlobal* FUN_00567960();
};

class ExtraDataList;

const ExtraDataList* __fastcall FUN_005d43c0(const TESObjectREFR* pThis);
TESGlobal* __fastcall FUN_00418690(const ExtraDataList* pThis);
TeleportableReference* __fastcall FUN_00568e50(TESObjectREFR* pThis);
const TESObjectREFR* __fastcall FUN_00559450(TeleportableReference* pThis);
TESObjectCELL* __fastcall FUN_008d6f30(TESObjectREFR* pThis);
TESGlobal* __fastcall FUN_00546aa0(TESObjectCELL* pThis);

}  // namespace fnv_00567960

namespace fnv_00567dd0 {
struct BGSEncounterZone;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESObjectCELL;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_00567dd0_shell : public TESObjectREFR
{
    void FUN_00567dd0(BGSEncounterZone*);
};

struct FUN_00567dd0_X
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
    virtual void Fn(unsigned int);
};
struct ExtraDataList
{
    void FUN_00421c60();
};
struct FUN_00567dd0_Y
{
    ExtraDataList* GetExtra(BGSEncounterZone* z) const;
};
}  // namespace fnv_00567dd0

namespace fnv_00567ec0 {
struct BGSEncounterZone
{
    char pad[0x2c];
    unsigned short iCalcedLevel;
    unsigned short GetCalculatedLevel(void);
};

}  // namespace fnv_00567ec0

struct FUN_00568260_shell : public TESObjectREFR
{
    bool FUN_00568260(bool);
};

void* __fastcall _FNV_GetObjectReference(const void* self);
int __fastcall _FNV_GetFormType(const void* self);

struct FUN_005682c0_caller
{
    int FUN_005682c0(bool);
};

struct NiStream;
struct FurnitureMark
{
    unsigned int QNumber();
    void SetNumber(unsigned int);
    void* QPosition();
    void SetPosition(void*);
    float GetCurrentTargetDistance();
    void SetFurnitureHeading(float);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void __dflt_ctor_closure();
    char Position[12];
    unsigned short m_usMarkerId;
    unsigned char m_ucFlags;
    char _pad_f[1];
};
typedef char _sizecheck_FurnitureMark[sizeof(FurnitureMark) == 16 ? 1 : -1];
struct FUN_00568650_shell : public FurnitureMark
{
    float FUN_00568650();
};

namespace fnv_00568ab0 {
struct NiStream;
struct FurnitureMark
{
    unsigned int QNumber();
    void SetNumber(unsigned int);
    void* QPosition();
    void SetPosition(void*);
    float GetCurrentTargetDistance();
    void SetFurnitureHeading(float);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void __dflt_ctor_closure();
    char Position[12];
    unsigned short m_usMarkerId;
    unsigned char m_ucFlags;
    char _pad_f[1];
};
typedef char _sizecheck_FurnitureMark[sizeof(FurnitureMark) == 16 ? 1 : -1];
struct FUN_00568ab0_shell : public FurnitureMark
{
    void FUN_00568ab0(unsigned int);
};

}  // namespace fnv_00568ab0

namespace fnv_00568bb0 {
struct Actor;
struct ActorCause;
struct ActorPackageData;
struct AlchemyItem;
struct Animation;
struct TwoIntegerValues;
struct MediaLocation;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSPrimitive;
struct BGSSaveFormBuffer;
struct BGSTalkingActivator;
struct BSExtraData;
struct BSMultiBound;
struct BSMultiBoundRoom;
struct BSOcclusionPlane;
struct BSPortal;
struct SoundPlaybackHandle;
struct BaseExtraList;
struct BipedAnim;
struct CellMopp;
struct CollisionData;
struct Crime;
struct TeleportableReference;
struct ExtraAction;
struct ExtraActorCause;
struct ExtraAmmo;
struct ExtraAnim;
struct ExtraAshPileReference;
struct ExtraAudioBuoyMarker;
struct ExtraAudioMarker;
struct ExtraCannotWearData;
struct ExtraDataList;
struct ExtraDismemberedLimbs;
struct ExtraFactionChanges;
struct ExtraFollower;
struct ExtraFollowerSwimBreadcrumbs;
struct ExtraLeveledItem;
struct ExtraLight;
struct ExtraLock;
struct ExtraMapMarker;
struct ExtraNavMeshPortal;
struct ExtraRefractionProperty;
struct ExtraSayToTopicInfo;
struct ExtraSayTopicInfoOnceADay;
struct ExtraStartingPosition;
struct ExtraTalkingActor;
struct ExtraTeleport;
struct PositionRotation;
struct ImpactSwap;
struct InventoryChanges;
struct MapMarkerData;
struct MenuTopic;
struct Point3Offset;
struct NiNode;
struct NiPoint3;
struct NiRenderedTexture;
struct PatrolReferenceData;
struct PatrolRefData;
struct LinkedReferencePair;
struct RadioReferenceData;
struct ReferenceLightData;
struct LockExtraData;
struct ReferenceFloatEntry;
struct RagDollData;
struct PointerFlagNode;
struct TopicInfoVisitRecord;
struct Script;
struct ScriptLocals;
struct SeenData;
struct TESActorBase;
struct TESAmmo;
struct TESClimate;
struct TESCombatStyle;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESImageSpace;
struct TESModel;
struct TESNPC;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESPackage;
struct TESRegionList;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct TrespassPackage;
struct WorldLocation;
struct WaterZone;
struct _D3DLOCKED_RECT;
struct bhkWorld;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_00568bb0_shell : public TESObjectREFR
{
    void FUN_00568bb0(ExtraDataList*);
};

void __fastcall FUN_00411ec0(const ExtraDataList*, int, ExtraDataList*);
const ExtraDataList* __fastcall GetExtra_005d43c0(TESObjectREFR*, int);

struct ExtraDataList_helper
{
    void FUN_00411ec0(ExtraDataList*) const;
};

struct TESObjectREFR_helper
{
    ExtraDataList_helper* GetExtra() const;
};

}  // namespace fnv_00568bb0

struct MapMarkerData;
struct FUN_00569060_shell : public TESObjectREFR
{
    MapMarkerData* FUN_00569060();
};

class ExtraDataList;
ExtraDataList* __fastcall FUN_005d43c0(TESObjectREFR*);
MapMarkerData* __fastcall FUN_00418490(ExtraDataList*);

struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct TESFile;
struct TESForm;
struct TESKey;
struct TESObjectCELL;
struct TESWorldSpace;
struct blob16
{
    char b[16];
};
struct LockExtraData
{
    int GetLockLevel(TESObjectREFR*);
    void SetLockLevel(int);
    int GetLevel(TESObjectREFR*);
    bool IsLocked();
    void SetLocked(bool);
    bool MeetsMinimumLockLevel();
    static int ConvertLockLevel(int);
    static int EnumToNumericValue(int);
    void Endian();
    unsigned char m_uiLockState;
    char _pad_1[3];
    TESKey* pKey;
    char cFlags;
    char _pad_9[3];
    unsigned int m_uiLockDifficulty;
    unsigned int m_uiLockValue;
};
typedef char _sizecheck_REFR_LOCK[sizeof(LockExtraData) == 20 ? 1 : -1];
struct TeleportableReference
{
    TESObjectREFR* GetLinkedDoor();
    void* GetTeleportPosition();
    void* GetTeleportRotation();
    TESObjectCELL* GetTeleportCell();
    void GetTeleportCellMapName(void*);
    TESWorldSpace* GetTeleportWorldspace();
    struct blob16 GetTeleportDestinationPosition();
    TESForm* GetTeleportDestinationForm();
    bool GetNoAlarm();
    void SetNoAlarm(bool);
    void SetLinkedDoor(TESObjectREFR*);
    void SetTeleportPosition(void*);
    void SetTeleportRotation(void*);
    void SetLinkedDoorReference(TESObjectREFR*, bool);
    void Save();
    void Load(TESFile*);
    bool InitItem(TESForm*);
    void Copy(TeleportableReference*);
    bool Compare(TeleportableReference*);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveGameBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadGameBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadGameBuffer*);
    void InitLoadGame();
    void FinishLoadGameTES();
    void* __vecDelDtor(unsigned int);
    TESObjectREFR* m_pLinkedDoorReference;
    char position[12];
    char rotation[12];
    unsigned char cFlags;
    char _pad_1d[3];
};
typedef char _sizecheck_DoorTeleportData[sizeof(TeleportableReference) == 32 ? 1 : -1];
struct FUN_00569160_shell : public TESObjectREFR
{
    LockExtraData* FUN_00569160();
};

template <typename T> struct BSStringT
{
    operator const char*() const;
};

struct ExtraRadioData;
struct TESObjectREFR_ext
{
    LockExtraData* GetMyLock();
    ExtraRadioData* GetExtraRadioData();
};

namespace fnv_005691f0 {
struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct BSExtraData;
struct TeleportableReference;
struct ExtraLock;
struct LockExtraData;
struct TESFile;
struct TESForm;
struct TESObjectCELL;
struct TESWorldSpace;
struct blob16
{
    char b[16];
};
struct FUN_005691f0_shell : public TESObjectREFR
{
    ExtraLock* FUN_005691f0();
};

template <class T> class BSStringT
{
  public:
    operator char const*() const;
};

struct ExtraRadioData;

struct TESObjectREFR_Helper
{
    BSExtraData* GetExtraData(unsigned char) const;
    ExtraRadioData* GetExtraRadioData();
};

}  // namespace fnv_005691f0

struct BSExtraData;
struct LockExtraData;
struct FUN_00569250_shell : public TESObjectREFR
{
    void FUN_00569250();
};

class ExtraLock
{
  public:
    void Lock();
};

ExtraLock* __fastcall FUN_005691f0(void*);
void __fastcall FUN_005789b0(void*);

namespace fnv_005692a0 {
struct BSExtraData;
struct LockExtraData;
struct FUN_005692a0_shell : public TESObjectREFR
{
    void FUN_005692a0();
};

class ExtraLock
{
  public:
    void Unlock();
};

ExtraLock* __fastcall FUN_005691f0(TESObjectREFR* pThis);
void __fastcall FUN_005789b0(TESObjectREFR* pThis);

}  // namespace fnv_005692a0

struct FUN_00569b80_shell : public TESObjectREFR
{
    TESObjectREFR* FUN_00569b80();
};

class ExtraDataList;
const ExtraDataList* __fastcall FUN_005d43c0(const TESObjectREFR*);
TESObjectREFR* __fastcall FUN_0041da10(const ExtraDataList*);

namespace fnv_0056a250 {
struct FUN_0056a250_shell : public TESObjectREFR
{
    bool FUN_0056a250();
};

struct ExtraDataList
{
    float FUN_0041f020();
};
struct REFRExtraStandIn
{
    ExtraDataList* GetExtra() const;
};
}  // namespace fnv_0056a250

struct TESForm;
struct TESWorldSpace;
struct WorldLocation
{
    void Endian();
    TESForm* m_pWorldSpace;
    char m_kWorldPosition[12];
    float m_fRotation;
};
typedef char _sizecheck_WORLD_LOCATION[sizeof(WorldLocation) == 20 ? 1 : -1];
struct FUN_0056ad30_shell : public TESObjectREFR
{
    TESWorldSpace* FUN_0056ad30();
};

class ExtraDataList;

struct TESObjectREFR_GetExtra_Helper
{
    const ExtraDataList* GetExtra() const;
};

WorldLocation* __fastcall FUN_00418b70(const ExtraDataList* pExtra);
int __fastcall _FNV_GetFormType(TESForm* pForm);

namespace fnv_0056b0b0 {
struct FUN_0056b0b0_shell : public TESObjectREFR
{
    void FUN_0056b0b0();
};

class TESDataHandler
{
  public:
    bool FormIDExists(unsigned int);
};
class ExtraDataList;
extern TESDataHandler* g_dataHandler;

struct DummyForm56b0b0
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~DummyForm56b0b0();
};

unsigned int __fastcall _ref_0084e3a0(DummyForm56b0b0*);
bool __fastcall FUN_0056af40(TESObjectREFR*);
DummyForm56b0b0* __fastcall FUN_004216f0(const ExtraDataList*);

struct TESObjectREFR_GetExtra_Caller
{
    const ExtraDataList* GetExtra() const;
};

}  // namespace fnv_0056b0b0

struct RadioReferenceData
{
    void Copy(RadioReferenceData*);
    void Endian();
    float fRadius;
    int m_iIntegerValue;
    float m_fValueBeforeRadioReference;
    TESObjectREFR* m_pRadioReference;
};
typedef char _sizecheck_RADIO_DATA[sizeof(RadioReferenceData) == 16 ? 1 : -1];
struct FUN_0056b140_shell : public TESObjectREFR
{
    TESObjectREFR* FUN_0056b140();
};

class ExtraDataList;
RadioReferenceData* __fastcall FUN_004182e0(const ExtraDataList* pExtra);

struct TESObjectREFR_Fake
{
    const ExtraDataList* GetExtra() const;
};

namespace fnv_0056b190 {
struct RadioReferenceData
{
    void Copy(RadioReferenceData*);
    void Endian();
    float fRadius;
    int m_iIntegerValue;
    float m_fValueBeforeRadioReference;
    TESObjectREFR* m_pRadioReference;
};
typedef char _sizecheck_RADIO_DATA[sizeof(RadioReferenceData) == 16 ? 1 : -1];
struct FUN_0056b190_shell : public TESObjectREFR
{
    float FUN_0056b190();
};

class ExtraDataList;

struct TESObjectREFR_GetExtra_Caller
{
    const ExtraDataList* GetExtra() const;
};

RadioReferenceData* __fastcall FUN_004182e0(const ExtraDataList* pExtra);

}  // namespace fnv_0056b190

namespace fnv_0056b210 {
struct RadioReferenceData
{
    void Copy(RadioReferenceData*);
    void Endian();
    float fRadius;
    int m_iIntegerValue;
    float m_fValueBeforeRadioReference;
    TESObjectREFR* m_pRadioReference;
};
typedef char _sizecheck_RADIO_DATA[sizeof(RadioReferenceData) == 16 ? 1 : -1];
struct FUN_0056b210_shell : public TESObjectREFR
{
    int FUN_0056b210();
};

class ExtraDataList;
extern "C++"
{
    RadioReferenceData* __fastcall FUN_004182e0(const ExtraDataList*);
}

struct GetExtra_helper
{
    const ExtraDataList* GetExtra() const;
};

}  // namespace fnv_0056b210

struct Dummy_0056c7d0
{
    char pad[0xcc];
    void* pData;
    void FUN_0056c7d0(void* apData);
};

struct FUN_0056c880_L
{
    void FUN_0056c8b0(unsigned int f, bool v);
};
struct FUN_0056c880_S
{
    char pad[0x64];
    FUN_0056c880_L* pLoaded;
    void FUN_0056c880(unsigned int aiFlag, bool abValue);
};

struct FUN_0056d300_In
{
    void FUN_004a3f10(const void* p);
};
struct FUN_0056d300_S
{
    char pad[0x30];
    FUN_0056d300_In in;
    void FUN_0056d300(const void* p);
};

struct NiMemObject
{
    static void operator delete(void*, unsigned int);
};
void FUN_00c8e9c0();
struct Obj56d550
{
    void FUN_00c8e9c0();
    void* FUN_0056d550(unsigned int);
};

void __fastcall FUN_0056d780(void* pThis);

struct _Dummy_0056e090
{
    void FUN_0056e0b0();
    _Dummy_0056e090* FUN_0056e090();
};

struct hkTransform;
struct HavokTransformData
{
    void setIdentity();
    hkTransform* ToHK(hkTransform*);
    HavokTransformData* FromHK(void*);
    char Rot[48];
    char Trans[16];
};
typedef char _sizecheck_bhkTransform[sizeof(HavokTransformData) == 64 ? 1 : -1];
struct FUN_0056e120_shell : public HavokTransformData
{
    void FUN_0056e120();
};

void __fastcall FUN_0056e140(void*);
void __fastcall FUN_004b4fc0(void*);

void __fastcall FUN_0056e6c0(void* pThis);
extern int DAT_01030a24;
extern int DAT_01268250;

void __fastcall FUN_0056ea40(void*);

struct _bhkSphereShape_vtbl_helper
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
    virtual void vb0(void*);
};

struct _hkSphereShapeCinfo_no_gs
{
    int _pad;
    float m_fSphereRadius;
};

struct CFilter;
struct hkSerializableCinfo
{
    char _pad_0[1];
};
typedef char _sizecheck_hkSerializableCinfo[sizeof(hkSerializableCinfo) == 1 ? 1 : -1];
struct CollisionFilterConfiguration : public hkSerializableCinfo
{
    CFilter* GetCFilter();
    void* __vecDelDtor(unsigned int);
    char _pad_1[3];
    void* m_pCollisionShape;
    char m_cBroadPhaseType[1];
    char _pad_9[3];
    char m_kProperties[12];
};
typedef char _sizecheck_hkWorldObjectCinfo[sizeof(CollisionFilterConfiguration) == 24 ? 1 : -1];
struct PhantomCreationInfo : public CollisionFilterConfiguration
{
    void* __vecDelDtor(unsigned int);
};
typedef char _sizecheck_hkPhantomCinfo[sizeof(PhantomCreationInfo) == 24 ? 1 : -1];
struct ExtendedPhantomCreationInfo : public PhantomCreationInfo
{
    void* __vecDelDtor(unsigned int);
    char _pad_18[8];
    char m_kMotionTransform[64];
};
typedef char _sizecheck_hkShapePhantomCinfo[sizeof(ExtendedPhantomCreationInfo) == 96 ? 1 : -1];
struct DerivedPhantomCreationInfo : public ExtendedPhantomCreationInfo
{
    void* __vecDelDtor(unsigned int);
};
typedef char _sizecheck_hkSimpleShapePhantomCinfo[sizeof(DerivedPhantomCreationInfo) == 96 ? 1 : -1];
struct FUN_0056ea90_shell : public DerivedPhantomCreationInfo
{
    void FUN_0056ea90();
};

void __fastcall FUN_0056d730(void*);

struct FilterArg_0056f0f0
{
    unsigned int v;
};

namespace fnv_0056fac0 {
struct M36_0056fac0
{
    float m[9];
};
int __fastcall _FNV_GetFormType(void*);
struct R_0056fac0
{
    char pad[0x20];
    void* pBase;
    M36_0056fac0 FUN_0056fac0(M36_0056fac0* mat);
};
}  // namespace fnv_0056fac0

namespace fnv_0056fc30 {
struct V3
{
    float x, y, z;
};
struct ExtraVec
{
    void FUN_0050ea50(V3* out);
};
struct NiExtraDataX
{
};
struct NiAVObjectX
{
    NiExtraDataX* GetExtraData(int name);
};
int FUN_0050ea90();
extern V3 g_011ca3d4;
extern V3 _NiPoint3_ZERO;
}  // namespace fnv_0056fc30

namespace fnv_00570f00 {
struct Actor;
struct BGSLoadFormBuffer;
struct BGSReconstructFormsInAllFilesMap;
struct BGSSaveLoadChangesMap;
struct SaveLoadFile;
struct FormIDConverter;
struct SaveLoadChangeHistory;
struct LoadGameSubBufferQueue;
struct BGSSaveLoadReferencesMap;
struct IDebugText;
struct TESForm;
struct TESObjectCELL;
struct blob4
{
    char b[4];
};
struct BGSSaveLoadGame
{
    static void Create();
    static void Destroy();
    void ApplyFormChanges(BGSSaveLoadChangesMap*, FormIDConverter*);
    void LoadCellChanges(bool);
    void LoadForm(TESForm*);
    void SetFormLoaded(TESForm*, bool);
    bool ShouldUnloadForm(TESForm*);
    void FormReconstructionMap(TESObjectCELL*);
    bool ContainsReference(unsigned int);
    bool ShouldSaveForm(TESForm*, bool);
    void NotifyFormIDChanged(TESForm*, struct blob4, bool);
    bool HasFormChangeFlags(TESForm*, struct blob4);
    bool GetOldChange(TESForm*, struct blob4);
    bool IsFormChanged(TESForm*);
    void ClearFormChangeFlags(TESForm*, struct blob4);
    void HasFormChanges(TESForm*);
    void ClearAllForms();
    void CleanupExpiredData();
    void ProcessSubBuffer(int, BGSLoadFormBuffer*, TESForm*);
    void ClearForm(TESForm*);
    void ClearFormID(unsigned int);
    void DeleteForm(TESForm*);
    void ChangeFormID(unsigned int, unsigned int);
    unsigned int GetNewFormID(unsigned int);
    bool IsFormIDRemapped(unsigned int);
    void AreStringsEqual(char*, char*);
    void DisplayReferenceDebugText(TESObjectREFR*, IDebugText*);
    void DisplayCellDebugText(TESObjectREFR*, IDebugText*);
    FormIDConverter* GetFormIDMap();
    FormIDConverter* GetWorldspaceFormIDMap();
    SaveLoadChangeHistory* GetHistory();
    BGSReconstructFormsInAllFilesMap* GetReconstructFormsMap();
    unsigned char GetConvertedFileIndex(unsigned char);
    unsigned char GetReverseConvertedFileIndex(unsigned char);
    unsigned char GetLoadState();
    bool SetGlobalAllowChanges(bool);
    bool GetGlobalAllowChanges();
    void SetDeferInitForms(bool);
    bool GetDeferInitForms();
    void SetSaveGameLoading(bool);
    bool GetSaveGameLoading();
    void SetSaveGameSaving(bool);
    bool GetSaveGameSaving();
    void SetInitingForms(bool);
    bool GetInitingForms();
    void SetPositioningPlayerCharacter(bool);
    bool GetPositioningPlayerCharacter();
    void SetPlayerLocationInvalid(bool);
    bool GetPlayerLocationInvalid();
    void SetSaveLoadFailed(bool);
    bool GetSaveLoadFailed();
    bool SetThreadAllowChanges(bool);
    bool GetThreadAllowChanges();
    void SetLoadingMovedRefs(bool);
    bool GetLoadingMovedRefs();
    void SetReconstructingForms(bool);
    bool GetReconstructingForms();
    bool GetAllowChanges();
    void SaveGame(SaveLoadFile*);
    bool LoadGame(SaveLoadFile*, bool);
    void PrepareLoadGame(SaveLoadFile*);
    bool IsValidSaveGame(SaveLoadFile*);
    unsigned int LoadFormRecord(SaveLoadFile*, BGSLoadFormBuffer*, FormIDConverter*);
    bool FindFormByID(TESForm**, struct blob4, bool);
    void InitializePackageLocations(Actor*);
    void CancelInitPackageLocations(Actor*);
    void ClearFormChanges();
    BGSSaveLoadChangesMap* GetChangesMap();
    void* __vecDelDtor(unsigned int);
    BGSSaveLoadChangesMap* m_pFormChangesMap;
    BGSSaveLoadChangesMap* m_pSecondChangesMap;
    FormIDConverter* m_pSecondSaveLoadData;
    FormIDConverter* m_pSaveLoadData;
    BGSSaveLoadReferencesMap* m_pReferencesMap;
    LoadGameSubBufferQueue* m_pSaveLoadMap;
    void* m_pAuxiliaryData;
    SaveLoadChangeHistory* m_pNoteHandler;
    BGSReconstructFormsInAllFilesMap* m_pFormReconstructionMap;
    char LoadFormBufferArray[16];
    char m_acTextBuffer[16];
    char m_acFirstTextBuffer[255];
    char m_acSecondTextBuffer[255];
    char _pad_242[2];
    unsigned int m_uiInitializationFlags;
    unsigned char m_ucSaveLoadState;
    char _pad_249[3];
};
typedef char _sizecheck_BGSSaveLoadGame[sizeof(BGSSaveLoadGame) == 588 ? 1 : -1];
struct FUN_00570f00_shell : public BGSSaveLoadGame
{
    bool FUN_00570f00();
};

bool __fastcall FUN_00462480(BGSSaveLoadGame* pThis);
bool __fastcall FUN_00570f40(BGSSaveLoadGame* pThis);

}  // namespace fnv_00570f00

namespace fnv_00571080 {
struct NiAVObject;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_00571080_shell : public TESObjectREFR
{
    void FUN_00571080(NiAVObject*);
};

class NiNode;
template <class T> class NiPointer
{
  public:
    NiPointer<T>& operator=(T*);
};

void __fastcall FUN_0057c180(TESObjectREFR*);
void __fastcall FUN_0057c300(TESObjectREFR*);

}  // namespace fnv_00571080

namespace fnv_00571530 {
struct NiAVObject;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiFixedString
{
    bool Exists();
    unsigned int GetLength();
    unsigned int GetRefCount();
    bool Equals(char*);
    bool EqualsNoCase(char*);
    bool Contains(char*);
    bool HasSuffix(char*);
    unsigned int QHandle();
    void Init();
    void* __vecDelDtor(unsigned int);
    char* m_kHandle;
};
typedef char _sizecheck_NiFixedString[sizeof(NiFixedString) == 4 ? 1 : -1];
struct FUN_00571530_shell : public TESObjectREFR
{
    NiAVObject* FUN_00571530(NiAVObject*, NiFixedString*);
};

NiAVObject* __cdecl FUN_00c4b470(NiAVObject*, NiFixedString*, bool);

}  // namespace fnv_00571530

struct FUN_00572350_shell : public TESObjectREFR
{
    bool FUN_00572350();
};

struct FUN_00572350_Vtbl
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
    virtual bool v64();
};

struct ReferenceLightData;
struct FUN_005725f0_shell : public TESObjectREFR
{
    ReferenceLightData* FUN_005725f0();
};

class ExtraDataList;
ReferenceLightData* __fastcall FUN_00418250(const ExtraDataList* pExtra);

namespace fnv_anon_tesobjectrefr {}
using namespace fnv_anon_tesobjectrefr;
namespace fnv_anon_tesobjectrefr {
struct TESObjectREFR_GetExtra_Caller
{
    const ExtraDataList* GetExtra() const;
};
}

namespace fnv_005728c0 {
struct ReferenceLightData
{
    void* __vecDelDtor(unsigned int);
    char m_pMenuLight[4];
    float m_fLightRadius;
};
typedef char _sizecheck_REFR_LIGHT[sizeof(ReferenceLightData) == 8 ? 1 : -1];
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_005728c0_shell : public TESObjectREFR
{
    void FUN_005728c0(bool);
};

struct NiLightX;
struct SSLight;
struct SSNode
{
    SSLight* GetShadowSceneLight(NiLightX*, bool);
};
struct NiAdditionalGeometryData
{
    static SSNode* GetShadowSceneNodeForIndex(int);
};
struct NameStr
{
    operator const char*() const;
};
struct Sub2
{
    bool _ref_008256d0();
};
struct ExtraStub
{
    NameStr* FUN_00418250();
    NameStr* FUN_00418280();
    Sub2* FUN_0041f810();
};
struct FormTypeStub
{
    int _FNV_GetFormType();
    bool FUN_0050dd90();
};
struct FormStub
{
    bool IsDeleted() const;
    bool GetDisabled();
    const ExtraStub* GetExtra() const;
    FormTypeStub* _FNV_GetObjectReference();
};
}  // namespace fnv_005728c0

namespace fnv_00572d30 {
struct FUN_00572d30_shell : public TESObjectREFR
{
    bool FUN_00572d30(int);
};

class ExtraDataList
{
  public:
    bool FUN_0041b3a0(int) const;
};

struct TESObjectREFR_GetExtra_helper
{
    const ExtraDataList* GetExtra() const;
};

}  // namespace fnv_00572d30

struct FUN_00572d50_shell : public TESObjectREFR
{
    void FUN_00572d50(int);
};

struct ExtraDataList_helper
{
    void FUN_0041b440(int);
};

struct TESObjectREFR_helper
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
    virtual void v48(unsigned int);
    virtual void v4c(unsigned int);
    bool FUN_00561d90();
    ExtraDataList_helper* FUN_005d43c0();
};

struct FUN_00572db0_shell : public TESObjectREFR
{
    void FUN_00572db0(int);
};

struct FUN_00572db0_Extra
{
    void FUN_0041b470(int);
};

struct FUN_00572db0_Helper
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
    virtual void v48(unsigned int);
    virtual void v4c(unsigned int);

    bool FUN_00561d90();
    FUN_00572db0_Extra* GetExtra();
};

struct FUN_00572e30_shell : public TESObjectREFR
{
    TESObjectREFR* FUN_00572e30();
};

class ExtraDataList;

const ExtraDataList* __fastcall FUN_005d43c0(const TESObjectREFR* pThis);
TESObjectREFR* __fastcall FUN_0041b520(const ExtraDataList* pExtra);

struct TempShell_005737e0
{
    char pad[0x64c];
    bool val;
    bool Get()
    {
        return val;
    }
};

struct FUN_00575770_shell : public TESObjectREFR
{
    void FUN_00575770(float);
};

struct FUN_005757d0_shell : public TESObjectREFR
{
    void FUN_005757d0(float);
};

float __cdecl WrapAngle(float);

namespace fnv_00575d10 {
struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CHUNK;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct FUN_00575d10_shell : public TESObjectREFR
{
    bool FUN_00575d10();
};

struct BSOcclusionPlane
{
    int GetCullResult() const;
};

struct TESObjectCELL
{
    bool IsInterior();
};

struct DoorCell
{
    TESWorldSpace* GetParentWorldSpace();
};

struct ChildCellHelper
{
    virtual TESObjectCELL* GetSaveParentCell();
};

}  // namespace fnv_00575d10

namespace fnv_00575d70 {
struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BGSTerrainManager;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CHUNK;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct GlobalVariableForm;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESTerrainLODManager;
struct TESWaterForm;
struct TESWorldSpace;
struct PointerPairData;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];
struct FUN_00575d70_shell : public TESObjectREFR
{
    TESWorldSpace* FUN_00575d70();
};

struct BSOcclusionPlane
{
    int GetCullResult() const;
};

struct DoorCell
{
    TESWorldSpace* GetParentWorldSpace();
};

struct DummyPad24
{
    virtual void dummy();
    char pad[0x14];
};

struct DummyChildCell
{
    virtual TESObjectCELL* vfn0();
};

struct DummyREFR : DummyPad24, DummyChildCell
{
};

}  // namespace fnv_00575d70

namespace fnv_00576260 {
struct Actor;
struct ActorValueOwner;
struct AlchemyItem;
struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct ExtraDataList;
struct ExtraLeveledItem;
struct InventoryChanges;
struct InventoryIterator;
struct IndexedPointerCollection;
struct Script;
struct ScriptLocals;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESForm;
struct TESLevItem;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESObjectWEAP;
struct InventoryStackRecord
{
    void Copy(InventoryStackRecord*);
    void MergeEntryData(InventoryStackRecord*);
    void ClearEntryData();
    TESBoundObject* GetContainerObject();
    void* GetExtraDataList();
    float GetConditionPercent(bool);
    int GetItemUses();
    float GetItemCharge();
    TESForm* GetInventoryObject();
    float GetItemValue();
    int GetHotKey();
    void SetHotKey(int);
    AlchemyItem* GetPoison();
    void RemovePoison();
    bool IsWorn(bool);
    bool IsWornDefault(bool);
    int GetCount();
    Script* GetScript();
    ScriptLocals* GetScriptLocalData();
    ExtraLeveledItem* RemoveLeveledItemExtra();
    bool HasPerkEntry();
    int NumberLeveledExtra();
    bool HasApplicablePerkEntry();
    int NumberStolenData();
    void RemoveOriginalChanges();
    bool IsWornStolen();
    unsigned char GetWeaponCategory();
    void SetModSlot(unsigned char);
    unsigned char GetModEffect(unsigned char);
    bool SetEquipmentState(unsigned char);
    bool SetEquipmentState(unsigned char, float*);
    void RoundToNearestStep();
    void GetPayloadAddress();
    static float GetModifiedAttackDamage(TESObjectWEAP*, ActorValueOwner*, float);
    float GetModifiedAttackDamage(ActorValueOwner*, float, bool);
    float GetDamageResistance(ActorValueOwner*);
    float GetArmorDamageThreshold(ActorValueOwner*);
    int GetTypeforMenu();
    char* GetDisplayNameForReference(TESObjectREFR*);
    char* GetFullName();
    float GetValueforMenuCol1(bool, Actor*, bool);
    float GetValueforMenuCol2(bool, Actor*, bool);
    float GetValueforMenuCol3(bool, Actor*, bool);
    float GetValueforMenuCol4(bool, bool, Actor*, bool);
    char* GetValueforMenu(int, bool, bool, Actor*, bool);
    void SetItemHealth(float, InventoryChanges*, ExtraDataList*, bool);
    void SetItemUses(int);
    void SetItemCharge(float, InventoryChanges*, ExtraDataList*);
    void SetItemOwner(TESForm*);
    void SetPoison(AlchemyItem*);
    void SetEquippedState(bool, bool, bool);
    void SetCount(int);
    bool ShouldDisplayItem(Actor*, bool, int, bool, bool);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveFormBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadFormBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadFormBuffer*);
    void InitLoadGame();
    int GetStatusFlags();
    char* GetStatusIcon(int);
    TESBoundObject* GetItemChangeObject();
    void SetItemChangeObject(TESBoundObject*);
    int GetCountWithExtras(bool);
    int GetTotalCount();
    int GetAmountDefaultExtra();
    int GetExtraDataCount();
    void* __vecDelDtor(unsigned int);
    void* m_pExtraDataLists;
    int m_iCountChange;
    TESBoundObject* m_pItemObject;
};
typedef char _sizecheck_ItemChange[sizeof(InventoryStackRecord) == 12 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESContainer : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    void InitItem(TESForm*);
    void ClearObjects();
    InventoryItemEntry* AddObject(ContainerChanges*);
    InventoryItemEntry* AddObject(TESObject*, int, ContainerItemExtra*);
    void AddDuplicateObject(InventoryItemEntry*);
    InventoryItemEntry* GetFirstContainerObject();
    void RemoveContainerObject(InventoryItemEntry*);
    void ReplaceObject(TESObject*, TESObject*);
    bool HasObjectOfType(TESObject*);
    float GetContainerWeight(bool);
    int GetObjectCount(TESObject*);
    char Compare(InventoryItemEntry*, InventoryItemEntry*);
    float GetClothingModifier();
    static bool IsValidContainerType(unsigned char);
    static bool IsValidContainerObject(TESObject*);
    void MergeContainer(TESContainer*);
    void MultiplyContainerCounts(int);
    void SetClothingModifier(float);
    void AddContentsFromReference(TESObjectREFR*, bool);
    void AddInventoryChangesToContainer(int, InventoryChanges*);
    TESAmmo* GetBestAmmoForActor(TESActorBase*);
    TESObjectWEAP* GetBestWeapon(TESActorBase*);
    TESObjectARMO* FindBestArmor(TESActorBase*, int);
    TESObjectCLOT* GetBestClothing(TESActorBase*, int);
    TESBoundObject* GetInventoryEntryData(int);
    void* GetObjectList();
    void* GetObjectListEnd();
    void* __vecDelDtor(unsigned int);
    char objectList[8];
};
typedef char _sizecheck_TESContainer[sizeof(TESContainer) == 12 ? 1 : -1];
struct FUN_00576260_shell : public TESObjectREFR
{
    InventoryStackRecord* FUN_00576260(TESBoundObject*, unsigned int);
};

struct InventoryChanges
{
    InventoryStackRecord* FUN_004d0650(TESBoundObject*, unsigned int);
};
struct ExtraDataList
{
    InventoryChanges* GetContainerChangeData();
};
struct REFRExtraStandIn
{
    ExtraDataList* GetExtra() const;
};
}  // namespace fnv_00576260

namespace fnv_00576330 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_00576330_shell : public TESObjectREFR
{
    BSFaceGenNiNode* FUN_00576330(NiNode*);
};

struct SceneObjectLookup
{
    static NiAVObject* __cdecl GetObjectByName(NiAVObject*, char const*);
};

struct VTable576330
{
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
    virtual bool v064();
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
    virtual int v228();

    NiAVObject* FUN_0043fcd0();
};

}  // namespace fnv_00576330

namespace fnv_00576390 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct BSFaceGenNiNode;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_00576390_shell : public TESObjectREFR
{
    BSFaceGenNiNode* FUN_00576390(NiNode*);
};

NiAVObject* __fastcall FUN_0043fcd0(TESObjectREFR*);

struct SceneObjectLookup
{
    static NiAVObject* __cdecl GetObjectByName(NiAVObject*, char const*);
};

struct VTable_00576390
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
    virtual bool v64();
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
    virtual void* v228();
};

}  // namespace fnv_00576390

namespace fnv_005763f0 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_005763f0_shell : public TESObjectREFR
{
    BSFaceGenAnimationData* FUN_005763f0(NiNode*);
};

}  // namespace fnv_005763f0

namespace fnv_00576420 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_00576420_shell : public TESObjectREFR
{
    BSFaceGenAnimationData* FUN_00576420(NiNode*);
};

struct BSFaceGenNiNode_vtbl_helper
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
    virtual BSFaceGenAnimationData* GetAnimationData();  // +0x100
};

struct TESObjectREFR_vtbl_helper
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
    virtual BSFaceGenNiNode_vtbl_helper* GetFacialAnimationNode(NiNode*);  // +0x1b4
};

}  // namespace fnv_00576420

void* __fastcall FUN_005771f0(void* _this);
void* __cdecl FUN_005771d0(void* pc);

struct PX
{
    void FUN_004d9910(void* r);
};
struct EDL
{
    PX* FUN_0041d6d0() const;
    void FUN_0041d5b0(PX* p) const;
};
struct FUN_00577330_cls
{
    int GetReferenceType();
    const EDL* GetExtra() const;
    void FUN_00577330(PX* p);
};

struct Z577
{
    float FUN_00577bf0();
};
struct SF577;
struct TESForm
{
    virtual ~TESForm();  // polymorphic: its RTTI is used (rtti_fix.py)
    SF577* GetSourceFiles();
};
struct Tmp577
{
    Z577* FUN_00577bd0(float);
};
struct Y577
{
    TESForm* FUN_00ca86c0();
    float FUN_00577c10();
};
struct X577
{
    Y577* FUN_004ae750();
    float FUN_00577bd0f();
};
struct Y577b;
struct A577
{
    Y577* FUN_00ca86c0();
    float FUN_00577c10();
};
struct Obj577
{
    A577* FUN_004ae750();
    float FUN_00577b50();
};

struct Dummy_00577bd0
{
    void FUN_00ca9360(float*);
};

extern float DAT_010c7948[];

namespace fnv_00577c10 {
struct Lst;
struct TESForm
{
    Lst* GetSourceFiles();
};
struct Sub
{
    int FUN_00577bf0();
};
struct TESDataHandler
{
    TESForm* GetBGSRagdollList();
    int FUN_00577c10();
};
}  // namespace fnv_00577c10

class NiFixedString;
struct NiExtraData;

struct BSXFlags
{
    bool GetAddon(void) const;
};

struct NiAVObject
{
    NiExtraData* GetExtraData(NiFixedString const&);
};

struct NiNode : NiAVObject
{
};

NiFixedString const& __cdecl FUN_00448a80(void);

namespace fnv_005789b0 {
struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct TESFile;
struct TESForm;
struct TESObjectCELL;
struct TESWorldSpace;
struct blob16
{
    char b[16];
};
struct TeleportableReference
{
    TESObjectREFR* GetLinkedDoor();
    void* GetTeleportPosition();
    void* GetTeleportRotation();
    TESObjectCELL* GetTeleportCell();
    void GetTeleportCellMapName(void*);
    TESWorldSpace* GetTeleportWorldspace();
    struct blob16 GetTeleportDestinationPosition();
    TESForm* GetTeleportDestinationForm();
    bool GetNoAlarm();
    void SetNoAlarm(bool);
    void SetLinkedDoor(TESObjectREFR*);
    void SetTeleportPosition(void*);
    void SetTeleportRotation(void*);
    void SetLinkedDoorReference(TESObjectREFR*, bool);
    void Save();
    void Load(TESFile*);
    bool InitItem(TESForm*);
    void Copy(TeleportableReference*);
    bool Compare(TeleportableReference*);
    unsigned short GetSaveSize();
    void SaveGame(BGSSaveGameBuffer*);
    void SaveGame();
    void LoadGame(BGSLoadGameBuffer*);
    void LoadGame();
    void InitLoadGame(BGSLoadGameBuffer*);
    void InitLoadGame();
    void FinishLoadGameTES();
    void* __vecDelDtor(unsigned int);
    TESObjectREFR* m_pLinkedDoorReference;
    char position[12];
    char rotation[12];
    unsigned char cFlags;
    char _pad_1d[3];
};
typedef char _sizecheck_DoorTeleportData[sizeof(TeleportableReference) == 32 ? 1 : -1];
struct FUN_005789b0_shell : public TESObjectREFR
{
    void FUN_005789b0();
};

template <class T> struct BSStringT
{
    operator const T*() const;
};
struct VT18
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
    virtual void v18(int flags);
};
struct LockExtraData;
struct ExtraRadioData;
struct RefrExt : public VT18
{
    LockExtraData* GetMyLock();
    ExtraRadioData* GetExtraRadioData();
};
}  // namespace fnv_005789b0

namespace fnv_0057a3c0 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct FUN_0057a3c0_shell : public TESObjectREFR
{
    void FUN_0057a3c0(bool);
};

struct TESObjectREFR_Helper
{
    void* GetReferenceType();
    bool FUN_004523e0(int);
    void FUN_0057a410(void*, bool);
};

}  // namespace fnv_0057a3c0

extern int DAT_01030f14;

struct BSExtraData
{
    virtual ~BSExtraData();  // polymorphic: its RTTI is used (rtti_fix.py)
    BSExtraData(unsigned char);
};

struct FUN_0057a870_helper
{
    BSExtraData* __thiscall init(void* a2);
};

struct MemberAt8
{
    void FUN_0057c700(int, int);
};

struct FUN_0057a9d0
{
    FUN_0057a9d0();
    virtual ~FUN_0057a9d0();
};

struct FUN_0057a960 : FUN_0057a9d0
{
    int unk4;
    MemberAt8 unk8;

    FUN_0057a960();
    virtual ~FUN_0057a960();
};

extern int DAT_0101fc80;

namespace fnv_0057ace0 {
struct ActorValueInfo;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSSaveFormBuffer;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct TESResponseList;
struct Script;
struct TESActorBase;
struct TESBoundObject;
struct PerkEntryConditionSet;
struct TESTopicInfoData;
struct TESFile;
struct TESForm;
struct TESQuest;
struct TESTopic;
struct TESTopicInfo;
struct TopicInfoData;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_0057ace0_shell : public TESObjectREFR
{
    void FUN_0057ace0(TESTopicInfo*);
};

struct ExtraDataList
{
    void FUN_0042ec70(TESTopicInfo*);
};

struct TESObjectREFR_GetExtra_helper
{
    ExtraDataList* GetExtra() const;
};

struct TESObjectREFR_vtable_helper
{
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18(unsigned int);
};

}  // namespace fnv_0057ace0

namespace fnv_0057ad20 {
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct CHUNK;
struct DialogueTopicData;
struct DialogueItem;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiColor;
struct NiPoint3;
struct QuestDialogueInfo;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESQuest;
struct TESTopic;
struct TESTopicInfo;
struct TopicInfoArray;
struct blob8
{
    char b[8];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct FUN_0057ad20_shell : public TESObjectREFR
{
    void FUN_0057ad20(TESTopic*);
};

class ExtraDataList
{
  public:
    void FUN_0042ee00(TESTopic* apTopic) const;
    ExtraDataList const* GetExtra() const;
};

struct VTable_0057ad20
{
    void* v[0x48 / 4];
    void(__thiscall* vfn_18)(TESObjectREFR*, unsigned int);
};

}  // namespace fnv_0057ad20

namespace fnv_0057ad60 {
struct FUN_0057ad60_shell : public TESObjectREFR
{
    void FUN_0057ad60(unsigned int);
};

class ExtraDataList
{
  public:
    void FUN_0042eec0(unsigned int) const;
};

struct VTable_0057ad60
{
    virtual void vfn_00();
    virtual void vfn_01();
    virtual void vfn_02();
    virtual void vfn_03();
    virtual void vfn_04();
    virtual void vfn_05();
    virtual void vfn_06();
    virtual void vfn_07();
    virtual void vfn_08();
    virtual void vfn_09();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18(unsigned int);
};

struct Helper_TESObjectREFR
{
    const ExtraDataList* GetExtra() const;
};

}  // namespace fnv_0057ad60

struct FUN_0057b0a0_shell : public TESObjectREFR
{
    float FUN_0057b0a0();
};

extern float const DAT_01015f5c;

float __cdecl FUN_004a3e90(float);

struct FUN_0057bd10_S
{
    int a;
    char b;
    int c;
    FUN_0057bd10_S* FUN_0057bd10(int v);
};

struct TESTopic;
struct FUN_0057bd40_shell : public TESObjectREFR
{
    TESTopic* FUN_0057bd40();
};

class ExtraDataList;
TESTopic* __fastcall FUN_0042ed30(const ExtraDataList* pExtra);

namespace fnv_anon_tesobjectrefr {}
using namespace fnv_anon_tesobjectrefr;
namespace fnv_anon_tesobjectrefr {
struct TESObjectREFR_Access
{
    const ExtraDataList* GetExtra() const;
};
}

namespace fnv_0057bd60 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct SoundPlaybackHandle;
struct BaseProcess;
struct DialogueResponse;
struct MobileObject;
struct NiAVObject;
struct NiPoint3;
struct LocationDescriptor;
struct TESIdleForm;
struct TESObjectCELL;
struct TESPackage;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct bhkCharacterController;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};

namespace fnv_anon_tesobjectrefr {}
using namespace fnv_anon_tesobjectrefr;
namespace fnv_anon_tesobjectrefr {
struct Dummy
{
    char pad[0x70];
    MobileObject* m_pMobileObject;
    void FUN_0057bd60(MobileObject* pref);
};
}

}  // namespace fnv_0057bd60

void* __cdecl operator new(unsigned int);
extern float const DAT_01015f5c;
float __fastcall FUN_005471e0(void*);
void* __fastcall FUN_0057c2a0(void*);

struct MobileObjectCellAccess
{
    bool FUN_004518e0() const;
};

struct BSOcclusionPlane
{
    int GetCullResult() const;
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer<T>& operator=(T*);
};

struct TempLoadedRefData
{
    int unk00;
    int unk04;
    float unk08;
    float unk0c;
    int unk10;
    NiPointer<NiNode> spNode14;
    NiPointer<NiNode> spNode18;
    TempLoadedRefData()
    {
        FUN_0057c2a0(this);
    }
};

struct GlobalObject_00633c90
{
    int m_val;
    GlobalObject_00633c90(int = 0);
    ~GlobalObject_00633c90();
};

struct FUN_0057c2a0
{
    char pad00[0x14];
    GlobalObject_00633c90 field14;
    GlobalObject_00633c90 field18;

    FUN_0057c2a0();
};

// Default-constructs the two GlobalObject_00633c90 members at offsets 0x14 and 0x18.
// @fnv 0x0057c2a0
FUN_0057c2a0::FUN_0057c2a0()
{}

struct NiNodeX;
struct NiPtrX
{
    int v;
    NiPtrX& operator=(NiNodeX* p);
};
struct Obj57
{
    char pad[0x14];
    NiPtrX a;
    NiPtrX b;
    void* FUN_0057c370(int f);
};
struct FUN_0057c300_cls
{
    char pad[0x64];
    Obj57* obj;
    void FUN_0057c300();
};

namespace fnv_006dcbb0 {
struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTerrainManager;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CHUNK;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct FindTriangleForLocationFilter;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NavMeshPtr;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct GlobalVariableForm;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESTerrainLODManager;
struct TESWaterForm;
struct TESWorldSpace;
struct PointerPairData;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct PathingLocation
{
    virtual void SaveGame(BGSSaveGameBuffer*);
    virtual void LoadGame(BGSLoadGameBuffer*);
    void SetNavMeshInfo(void*);
    void SetLocation(void*);
    void SetLocationSimple(void*);
    void SetTriangleIndex(unsigned short);
    struct blob12 GetLocation();
    TESObjectCELL* GetContainingCell();
    TESWorldSpace* GetParentWorldspace();
    TESObjectCELL* GetCellSimple();
    TESWorldSpace* GetWorldspaceSimple();
    void* GetAssociatedNavMesh();
    bool IsOnNavMesh(void*);
    bool ResolveNavMesh(NavMeshPtr*);
    bool FindNavMeshTriangle(NavMeshPtr*, unsigned short*);
    unsigned short GetTriangle();
    bool HasValidTriangle();
    bool HasNavMesh();
    void* GetNavMeshInfo();
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
    bool IsPathingLocationValid();
    bool HasPathingLocation();
    bool QUnused();
    void SetUnused();
    void ClearUnused();
    bool QValid();
    void ResetLocation();
    void WriteDebugString(char*, int);
    bool IsDistanceBelowThreshold(float);
    bool IsCloseTo(void*, float);
    void SetLocationData(void*, TESObjectCELL*, TESWorldSpace*);
    bool QAllMeshesReachable();
    void SetAllMeshesReachable(int);
    bool GetAllMeshesReachable();
    void* __vecDelDtor(unsigned int);
    char Location[12];
    void* m_pLocationNavMesh;
    void* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    char _pad_27[1];
};
typedef char _sizecheck_PathingLocation[sizeof(PathingLocation) == 40 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];
struct FUN_006dcbb0_shell : public PathingLocation
{
    void FUN_006dcbb0(void*);
};

extern int DAT_0102583c;
void __fastcall _ref_006815c0(void* pThis);

}  // namespace fnv_006dcbb0

struct Node_00837410
{
    float m_item;
    Node_00837410* m_pkNext;
    ~Node_00837410();
};

struct FUN_0086a830_S
{
    char FUN_0086a830(int a);
};

namespace fnv_0088b4e0 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiColor;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESFormList;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWaterForm;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_0088b4e0_shell : public TESObjectREFR
{
    TESObjectREFR* FUN_0088b4e0(TESBoundObject*, ExtraDataList*, int, bool, bool, TESObjectREFR*, void*, void*, bool,
                                bool);
};

class Sky;
class TES
{
  public:
    Sky* GetLogDate();
};

int __fastcall FUN_00418250(const ExtraDataList*);

struct TESObjectREFR_Helper : public TESObjectREFR
{
    const ExtraDataList* GetExtra() const;
};

}  // namespace fnv_0088b4e0

struct ActorMover
{
    void ForceStopMoving(void);
};

namespace fnv_008be4f0 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_008be4f0_shell : public TESObjectREFR
{
    BSAnimNoteReceiver* FUN_008be4f0();
};

extern double _gModifierZero;

struct CombatLOS
{
    bool FUN_00884920();
    float FUN_008be5a0(ActorValueOwner*);
};

struct ActorValueOwnerVtbl
{
    void (*vfn_00)();
    void (*vfn_04)();
    void (*vfn_08)();
    void (*vfn_0c)();
    void (*vfn_10)();
    void (*vfn_14)();
    void (*vfn_18)();
    float(__thiscall* vfn_1c)(ActorValueOwner*);
};

struct DummyActor : public TESObjectREFR
{
    char pad[0xa8 - sizeof(TESObjectREFR)];
    ActorValueOwnerVtbl* vfptr_avo;
};

}  // namespace fnv_008be4f0

struct Arg8E
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float V1c();
};
struct Inner8E
{
    char pad[0x1c];
    float f1c;
    bool FUN_00884e90(int a);
};
struct FUN_008be5a0_cls
{
    char pad[0x2c];
    Inner8E* inner;
    float FUN_008be5a0(Arg8E* a);
};

struct Sky;

struct TES
{
    Sky* GetLogDate();
};

struct VTable_008c13d0_2
{
    virtual void pad000();
    virtual void pad004();
    virtual void pad008();
    virtual void pad00c();
    virtual void pad010();
    virtual void pad014();
    virtual void pad018();
    virtual void pad01c();
    virtual void pad020();
    virtual void pad024();
    virtual void pad028();
    virtual void pad02c();
    virtual void pad030();
    virtual void pad034();
    virtual void pad038();
    virtual void pad03c();
    virtual void pad040();
    virtual void pad044();
    virtual void pad048();
    virtual void pad04c();
    virtual void pad050();
    virtual void pad054();
    virtual void pad058();
    virtual void pad05c();
    virtual void pad060();
    virtual void pad064();
    virtual void pad068();
    virtual void pad06c();
    virtual void pad070();
    virtual void pad074();
    virtual void pad078();
    virtual void pad07c();
    virtual void pad080();
    virtual void pad084();
    virtual void pad088();
    virtual void pad08c();
    virtual void pad090();
    virtual void pad094();
    virtual void pad098();
    virtual void pad09c();
    virtual void pad0a0();
    virtual void pad0a4();
    virtual void pad0a8();
    virtual void pad0ac();
    virtual void pad0b0();
    virtual void pad0b4();
    virtual void pad0b8();
    virtual void pad0bc();
    virtual void pad0c0();
    virtual void pad0c4();
    virtual void pad0c8();
    virtual void pad0cc();
    virtual void pad0d0();
    virtual void pad0d4();
    virtual void pad0d8();
    virtual void pad0dc();
    virtual void pad0e0();
    virtual void pad0e4();
    virtual void pad0e8();
    virtual void pad0ec();
    virtual void pad0f0();
    virtual void pad0f4();
    virtual void pad0f8();
    virtual void pad0fc();
    virtual void pad100();
    virtual void pad104();
    virtual void pad108();
    virtual void pad10c();
    virtual void pad110();
    virtual void pad114();
    virtual void pad118();
    virtual void pad11c();
    virtual void pad120();
    virtual void pad124();
    virtual void pad128();
    virtual void pad12c();
    virtual void pad130();
    virtual void pad134();
    virtual void pad138();
    virtual void pad13c();
    virtual void pad140();
    virtual void pad144();
    virtual void pad148();
    virtual void pad14c();
    virtual void pad150();
    virtual void pad154();
    virtual void pad158();
    virtual void pad15c();
    virtual void pad160();
    virtual void pad164();
    virtual void pad168();
    virtual void pad16c();
    virtual void pad170();
    virtual void pad174();
    virtual void pad178();
    virtual void pad17c();
    virtual void pad180();
    virtual void pad184();
    virtual void pad188();
    virtual void pad18c();
    virtual void pad190();
    virtual void pad194();
    virtual void pad198();
    virtual void pad19c();
    virtual void pad1a0();
    virtual void pad1a4();
    virtual void pad1a8();
    virtual void pad1ac();
    virtual void pad1b0();
    virtual void pad1b4();
    virtual void pad1b8();
    virtual void pad1bc();
    virtual void pad1c0();
    virtual void pad1c4();
    virtual void pad1c8();
    virtual void pad1cc();
    virtual void pad1d0();
    virtual void pad1d4();
    virtual void pad1d8();
    virtual void pad1dc();
    virtual void pad1e0();
    virtual void pad1e4();
    virtual void pad1e8();
    virtual void pad1ec();
    virtual void pad1f0();
    virtual void pad1f4();
    virtual void pad1f8();
    virtual void pad1fc();
    virtual void pad200();
    virtual void pad204();
    virtual void pad208();
    virtual void pad20c();
    virtual void pad210();
    virtual void pad214();
    virtual void pad218();
    virtual void pad21c();
    virtual void pad220();
    virtual void pad224();
    virtual void pad228();
    virtual void pad22c();
    virtual void pad230();
    virtual void pad234();
    virtual void pad238();
    virtual void pad23c();
    virtual void pad240();
    virtual void pad244();
    virtual void pad248();
    virtual void pad24c();
    virtual void pad250();
    virtual void pad254();
    virtual void pad258();
    virtual void pad25c();
    virtual void pad260();
    virtual void pad264();
    virtual void pad268();
    virtual void pad26c();
    virtual void pad270();
    virtual void pad274();
    virtual void pad278();
    virtual void pad27c();
    virtual void pad280();
    virtual void pad284();
    virtual void pad288();
    virtual void pad28c();
    virtual void pad290();
    virtual void pad294();
    virtual void pad298();
    virtual void pad29c();
    virtual void pad2a0();
    virtual void pad2a4();
    virtual void pad2a8();
    virtual void pad2ac();
    virtual void pad2b0();
    virtual void pad2b4();
    virtual void pad2b8();
    virtual void pad2bc();
    virtual void pad2c0();
    virtual void pad2c4();
    virtual void pad2c8();
    virtual void pad2cc();
    virtual void pad2d0();
    virtual void pad2d4();
    virtual void pad2d8();
    virtual void pad2dc();
    virtual void pad2e0();
    virtual void pad2e4();
    virtual void pad2e8();
    virtual void pad2ec();
    virtual void pad2f0();
    virtual void pad2f4();
    virtual void pad2f8();
    virtual void pad2fc();
    virtual void pad300();
    virtual void pad304();
    virtual void pad308();
    virtual void pad30c();
    virtual void pad310();
    virtual void pad314();
    virtual void pad318();
    virtual void pad31c();
    virtual void pad320();
    virtual void pad324();
    virtual void pad328();
    virtual void pad32c();
    virtual void pad330();
    virtual void pad334();
    virtual void pad338();
    virtual void pad33c();
    virtual void pad340();
    virtual void pad344();
    virtual void pad348();
    virtual void pad34c();
    virtual void pad350();
    virtual void pad354();
    virtual void pad358();
    virtual void pad35c();
    virtual void pad360();
    virtual void pad364();
    virtual void pad368();
    virtual void pad36c();
    virtual void pad370();
    virtual void pad374();
    virtual void pad378();
    virtual void pad37c();
    virtual void pad380();
    virtual void pad384();
    virtual void pad388();
    virtual void pad38c();
    virtual void pad390();
    virtual void pad394();
    virtual void pad398();
    virtual void pad39c();
    virtual void pad3a0();
    virtual void pad3a4();
    virtual void pad3a8();
    virtual void pad3ac();
    virtual void pad3b0();
    virtual void pad3b4();
    virtual void pad3b8();
    virtual void pad3bc();
    virtual void pad3c0();
    virtual void pad3c4();
    virtual void pad3c8();
    virtual void pad3cc();
    virtual void pad3d0();
    virtual void pad3d4();
    virtual void pad3d8();
    virtual void pad3dc();
    virtual void pad3e0();
    virtual void pad3e4();
    virtual void pad3e8();
    virtual void pad3ec();
    virtual void pad3f0();
    virtual void pad3f4();
    virtual void pad3f8();
    virtual void pad3fc();
    virtual void pad400();
    virtual void pad404();
    virtual void pad408();
    virtual void pad40c();
    virtual void pad410();
    virtual void pad414();
    virtual void pad418();
    virtual void pad41c();
    virtual void pad420();
    virtual void pad424();
    virtual void pad428();
    virtual void pad42c();
    virtual void pad430();
    virtual void pad434();
    virtual void pad438();
    virtual void pad43c();
    virtual void pad440();
    virtual void pad444();
    virtual void pad448();
    virtual void pad44c();
    virtual void pad450();
    virtual void pad454();
    virtual void pad458();
    virtual void pad45c();
    virtual void pad460();
    virtual void pad464();
    virtual void pad468();
    virtual void pad46c();
    virtual void pad470();
    virtual void pad474();
    virtual void pad478();
    virtual void pad47c();
    virtual void pad480();
    virtual void pad484();
    virtual void pad488();
    virtual void pad48c();
    virtual void pad490();
    virtual void pad494();
    virtual void pad498();
    virtual void pad49c();
    virtual void pad4a0();
    virtual void pad4a4();
    virtual void pad4a8();
    virtual void pad4ac();
    virtual void pad4b0();
    virtual void pad4b4();
    virtual void pad4b8();
    virtual void pad4bc();
    virtual void pad4c0();
    virtual void pad4c4();
    virtual void pad4c8();
    virtual void pad4cc();
    virtual void pad4d0();
    virtual unsigned char* v4d4();
};

struct VTable_008c13d0_1
{
    virtual void pad000();
    virtual void pad004();
    virtual void pad008();
    virtual void pad00c();
    virtual void pad010();
    virtual void pad014();
    virtual void pad018();
    virtual void pad01c();
    virtual void pad020();
    virtual void pad024();
    virtual void pad028();
    virtual void pad02c();
    virtual void pad030();
    virtual void pad034();
    virtual void pad038();
    virtual void pad03c();
    virtual void pad040();
    virtual void pad044();
    virtual void pad048();
    virtual void pad04c();
    virtual void pad050();
    virtual void pad054();
    virtual void pad058();
    virtual void pad05c();
    virtual void pad060();
    virtual void pad064();
    virtual void pad068();
    virtual void pad06c();
    virtual void pad070();
    virtual void pad074();
    virtual void pad078();
    virtual void pad07c();
    virtual void pad080();
    virtual void pad084();
    virtual void pad088();
    virtual void pad08c();
    virtual void pad090();
    virtual void pad094();
    virtual void pad098();
    virtual void pad09c();
    virtual void pad0a0();
    virtual void pad0a4();
    virtual void pad0a8();
    virtual void pad0ac();
    virtual void pad0b0();
    virtual void pad0b4();
    virtual void pad0b8();
    virtual void pad0bc();
    virtual void pad0c0();
    virtual void pad0c4();
    virtual void pad0c8();
    virtual void pad0cc();
    virtual void pad0d0();
    virtual void pad0d4();
    virtual void pad0d8();
    virtual void pad0dc();
    virtual void pad0e0();
    virtual void pad0e4();
    virtual void pad0e8();
    virtual void pad0ec();
    virtual void pad0f0();
    virtual void pad0f4();
    virtual void pad0f8();
    virtual void pad0fc();
    virtual void pad100();
    virtual void pad104();
    virtual void pad108();
    virtual void pad10c();
    virtual void pad110();
    virtual void pad114();
    virtual void pad118();
    virtual void pad11c();
    virtual void pad120();
    virtual void pad124();
    virtual void pad128();
    virtual void pad12c();
    virtual void pad130();
    virtual void pad134();
    virtual void pad138();
    virtual void pad13c();
    virtual void pad140();
    virtual void pad144();
    virtual void pad148();
    virtual void pad14c();
    virtual void pad150();
    virtual void pad154();
    virtual void pad158();
    virtual void pad15c();
    virtual void pad160();
    virtual void pad164();
    virtual void pad168();
    virtual void pad16c();
    virtual void pad170();
    virtual void pad174();
    virtual void pad178();
    virtual void pad17c();
    virtual void pad180();
    virtual void pad184();
    virtual void pad188();
    virtual void pad18c();
    virtual void pad190();
    virtual void pad194();
    virtual void pad198();
    virtual void pad19c();
    virtual void pad1a0();
    virtual void pad1a4();
    virtual void pad1a8();
    virtual void pad1ac();
    virtual void pad1b0();
    virtual void pad1b4();
    virtual void pad1b8();
    virtual void pad1bc();
    virtual void pad1c0();
    virtual void pad1c4();
    virtual void pad1c8();
    virtual void pad1cc();
    virtual void pad1d0();
    virtual void pad1d4();
    virtual void pad1d8();
    virtual void pad1dc();
    virtual void pad1e0();
    virtual void pad1e4();
    virtual void pad1e8();
    virtual void pad1ec();
    virtual void pad1f0();
    virtual void pad1f4();
    virtual void pad1f8();
    virtual void pad1fc();
    virtual void pad200();
    virtual void pad204();
    virtual void pad208();
    virtual void pad20c();
    virtual void pad210();
    virtual int v214();
};

struct ExtraX
{
};
struct NiAVObjectX
{
    ExtraX* GetExtraData(int name);
};
int FUN_0050ea90();
struct Holder
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
    virtual void V5f4(void* e);
};
struct FUN_009335b0_cls
{
    char pad[0x68];
    Holder* holder;
    NiAVObjectX* FUN_0056b2d0(unsigned char a);
    void SetReferenceFlag(bool b);
    NiAVObjectX* FUN_009335b0(unsigned char a);
};

namespace fnv_00950b60 {
template <typename T> class BSStringT
{
  public:
    operator const T*() const;
};

const char* __fastcall FUN_0043fcd0(TESObjectREFR*);

}  // namespace fnv_00950b60

namespace fnv_0098ddd0 {
struct NiStream;
struct blob12
{
    char b[12];
};
struct FurnitureMark
{
    unsigned int QNumber();
    void SetNumber(unsigned int);
    void* QPosition();
    void SetPosition(void*);
    float GetCurrentTargetDistance();
    void SetFurnitureHeading(float);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void __dflt_ctor_closure();
    char Position[12];
    unsigned short m_usMarkerId;
    unsigned char m_ucFlags;
    char _pad_f[1];
};
typedef char _sizecheck_FurnitureMark[sizeof(FurnitureMark) == 16 ? 1 : -1];
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct FUN_0098ddd0_shell : public FurnitureMark
{
    void FUN_0098ddd0(void*);
};

}  // namespace fnv_0098ddd0

unsigned int __fastcall _FNV_GetFormType(void*);
extern const float g_011c5aa8_arg1;
bool __cdecl FUN_0040eb10(float, float, float);
struct HealthForm
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int GetHealth();
};
struct ExtraL
{
    void FUN_00419700(void*);
    void SetExtraDataValue(int);
    void FUN_004198a0(int);
    void SetExtraHealth(float);
};
struct Fn40ea20
{
    void* form;
    int count;
    float health;
    void FUN_0040ea20(ExtraL* apExtra, HealthForm* apHealthForm);
};

namespace fnv_0047a520 {
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiFixedString
{
    bool Exists();
    unsigned int GetLength();
    unsigned int GetRefCount();
    bool Equals(char*);
    bool EqualsNoCase(char*);
    bool Contains(char*);
    bool HasSuffix(char*);
    unsigned int QHandle();
    void Init();
    void* __vecDelDtor(unsigned int);
    char* m_kHandle;
};
typedef char _sizecheck_NiFixedString[sizeof(NiFixedString) == 4 ? 1 : -1];

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
struct NFSHelper : public NiFixedString
{
    operator char const*() const;
};
struct Fn47a520
{
    char _p[0x50];
    DummyPointerMap map;
    unsigned int FUN_0047a520(NFSHelper* name);
};
}  // namespace fnv_0047a520

namespace fnv_0055d6d0 {
struct FUN_00565090_shell;
class TESObjectSTAT;
TESObjectSTAT* __fastcall _FNV_GetObjectReference(FUN_00565090_shell*);
struct FUN_00565090_shell
{
    bool FUN_00565090();
};
struct BSFadeNode
{
    int GetLODMultType() const;
};
struct FUN_00705b10_Dummy
{
    void Set(int);
};
struct BSFadeNode_Dummy;
struct TESLODH
{
    static int __cdecl GetModelResourceType(void*);
};
struct NodeObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual BSFadeNode* GetFadeNode();
};
void __fastcall FUN_00476ab0(BSFadeNode_Dummy*);
void __fastcall FUN_0054b800(void*);
}  // namespace fnv_0055d6d0

class TESObjectSTAT;
TESObjectSTAT* __fastcall _FNV_GetObjectReference(TESObjectREFR*);
unsigned int __fastcall _FNV_GetFormType(void*);
struct ArrSI
{
    unsigned int GetFlags();
};
struct Fn564ab0 : public TESObjectREFR
{
    bool FUN_00564ab0();
};

namespace fnv_005672c0 {
int __cdecl _stricmp(const char*, const char*);
unsigned int __fastcall _FNV_GetFormType(void*);
extern const char* DAT_01197b5c;
struct NiFixedString
{
    operator char const*() const;
};
struct NiAVObject
{
    NiFixedString& GetName();
};
struct RoomH
{
    void* GetRoomId();
};
struct TQI
{
    static TQI* __cdecl GetInstance();
    void FUN_0087b1e0(NiAVObject*, int);
};
struct Creature
{
    static void __cdecl SetNodeFlagsRecursive(NiAVObject*, int, bool, bool, bool);
};
bool __cdecl IsConditionMet();
void __cdecl FUN_00c6a270(NiAVObject*, bool, bool, int);
struct Fn5672c0
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
    virtual void v18(int);
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
    virtual NiAVObject* v116();
    char _p[0x1c];
    void* form;
    char _q[0x1c];
    RoomH* room;
    void FUN_005672c0(NiAVObject* obj);
};
}  // namespace fnv_005672c0

namespace fnv_00567f80 {
struct BSExtraData;
struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
};
class TESObjectSTAT;
TESObjectSTAT* __fastcall _FNV_GetObjectReference(void*);
unsigned int __fastcall _FNV_GetFormType(void*);
struct XActor
{
    BaseExtraList* GetExtra() const;
};
struct MarkH
{
    bool FUN_00432f80(unsigned int);
};
struct Fn567f80 : public XActor
{
    bool FUN_00567f80(unsigned int aiMarkerIndex, bool abIgnoreReservations);
};
}  // namespace fnv_00567f80

namespace fnv_00568fa0 {
struct NiPoint3
{
    float x, y, z;
};
extern NiPoint3 _NiPoint3_ZERO;
struct DTDH
{
    NiPoint3 const& GetPosition();
};
struct Fn568fa0;
struct Flt
{
    operator Fn568fa0*() const;
};
struct Fn568fa0
{
    Flt* GetExtraRadioData();
    NiPoint3 const& FUN_00568fa0();
};
}  // namespace fnv_00568fa0

struct NiAVObject;
struct PropHelper
{
    void* GetProperty(unsigned int);
};
struct Fake_FUN_004a2020
{
    bool GetFlag(unsigned int) const;
};
struct NiObjectNET
{
    unsigned int GetNumChildren();
};
struct NiNodeHelper
{
    NiAVObject* GetAt(unsigned int);
};
unsigned int FUN_00438220();

struct XExtraList;
struct XActor
{
    const XExtraList* GetExtra() const;
};
struct Fn56ac90 : public XActor
{
    void* FUN_0056ac90();
};
void* __fastcall FUN_0041dca0(const XExtraList*);

struct M3
{
    float a, b, c, d, e, f, g, h, i;
};
void __fastcall _ref_006815c0(void* pThis);
struct NiMatrix3Helper
{
    void FUN_00a59540(float, float, float);
};

namespace fnv_0056fb10 {
struct NiPoint3;
struct P3
{
    float x, y, z;
};
struct ExtraX;
struct NiAVObjectX
{
    ExtraX* GetExtraData(int);
};
struct RandHelper
{
    NiAVObjectX* GetReferenceType();
};
struct FUN_0050ea10_class
{
    void FUN_0050ea10(NiPoint3&) const;
};
int FUN_0050ea90();
extern P3 g_011ca3b8;
extern P3 _NiPoint3_ZERO;
}  // namespace fnv_0056fb10

namespace fnv_00572380 {
struct NiStream;
struct blob12
{
    char b[12];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct FUN_00572380_shell : public TESObjectREFR
{
    float FUN_00572380(void*);
};

struct NiP3Sub : public NiPoint3
{
    NiPoint3 operator-(NiPoint3 const&) const;
};
struct Fn572380
{
    char _p[0x30];
    NiPoint3 pt;
    float FUN_00572380(NiP3Sub* other);
};
}  // namespace fnv_00572380

namespace fnv_00572a50 {
struct ExtraDataList;
struct ReferenceLightData;
ReferenceLightData* __fastcall FUN_00418250(const ExtraDataList* pExtra);
struct NiAVObject;
struct XExtraList;
struct XActor
{
    const XExtraList* GetExtra() const;
};
struct BoolArg
{
    bool v;
};
struct Flt
{
    operator unsigned int() const;
};
struct NP_0081c630
{
    NP_0081c630& operator=(void*);
};
struct GetTeleportHelper
{
    void Set3DObject(NiAVObject*);
};
namespace fnv_005728c0 {
struct NameStr;
struct ExtraStub
{
    NameStr* FUN_00418280();
};
}
struct NiAdditionalGeometryData
{
    static void* GetShadowSceneNodeForIndex(int);
};
void __fastcall FUN_0041ae30(const XExtraList*);
void __fastcall FUN_0041ae50(const XExtraList*);
}  // namespace fnv_00572a50

bool __cdecl FUN_004753d0(void*);
struct ABD575
{
    bool FUN_0055e200();
};
struct DestrH
{
    void SetDestructible(bool);
};
struct Fn575690
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
    virtual bool v63();
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
    virtual void v126(bool);
    char _p[0x1c];
    void* obj;
    void FUN_00575690(void* apObject);
};

namespace fnv_006dcd70 {
struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSLoadGameBuffer;
struct BGSMusicType;
struct BGSSaveFormBuffer;
struct BGSSaveGameBuffer;
struct BGSTerrainManager;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct CHUNK;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct FindTriangleForLocationFilter;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NavMeshPtr;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESGlobal;
struct GlobalVariableForm;
struct TESImageSpace;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct TESTerrainLODManager;
struct TESWaterForm;
struct TESWorldSpace;
struct PointerPairData;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct PathingLocation
{
    virtual void SaveGame(BGSSaveGameBuffer*);
    virtual void LoadGame(BGSLoadGameBuffer*);
    void SetNavMeshInfo(void*);
    void SetLocation(void*);
    void SetLocationSimple(void*);
    void SetTriangleIndex(unsigned short);
    struct blob12 GetLocation();
    TESObjectCELL* GetContainingCell();
    TESWorldSpace* GetParentWorldspace();
    TESObjectCELL* GetCellSimple();
    TESWorldSpace* GetWorldspaceSimple();
    void* GetAssociatedNavMesh();
    bool IsOnNavMesh(void*);
    bool ResolveNavMesh(NavMeshPtr*);
    bool FindNavMeshTriangle(NavMeshPtr*, unsigned short*);
    unsigned short GetTriangle();
    bool HasValidTriangle();
    bool HasNavMesh();
    void* GetNavMeshInfo();
    bool FindContainingTriangle(FindTriangleForLocationFilter*);
    bool IsPathingLocationValid();
    bool HasPathingLocation();
    bool QUnused();
    void SetUnused();
    void ClearUnused();
    bool QValid();
    void ResetLocation();
    void WriteDebugString(char*, int);
    bool IsDistanceBelowThreshold(float);
    bool IsCloseTo(void*, float);
    void SetLocationData(void*, TESObjectCELL*, TESWorldSpace*);
    bool QAllMeshesReachable();
    void SetAllMeshesReachable(int);
    bool GetAllMeshesReachable();
    void* __vecDelDtor(unsigned int);
    char Location[12];
    void* m_pLocationNavMesh;
    void* pNavMeshInfoArray;
    TESObjectCELL* pCell;
    TESWorldSpace* m_pContainingWorldspace;
    unsigned int m_uiPathingFlags;
    unsigned short m_usTriangleID;
    unsigned char uiFlags;
    char _pad_27[1];
};
typedef char _sizecheck_PathingLocation[sizeof(PathingLocation) == 40 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct TESFullName : public BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetFullNameLength(TESForm*);
    unsigned int GetFullNameLength();
    static char* GetFullName(TESForm*);
    char* GetFullName();
    void SetFullName(char*);
    static void LoadFullNameChunk(TESFullName*, TESFile*);
    void* GetFullNameString();
    void* __vecDelDtor(unsigned int);
    char m_kName[8];
};
typedef char _sizecheck_TESFullName[sizeof(TESFullName) == 12 ? 1 : -1];
struct TESTexture : public BaseFormComponent
{
    virtual unsigned int GetTexturePathLength();
    virtual char* NormalizeTextureFilePath(void*);
    virtual char* GetRegularTextureFilePath(void*);
    virtual char* GetTextureResourcePath();
    virtual void InitializeComponent();
    virtual void ClearComponent();
    void Save(int);
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
    static unsigned int GetTextureNameLength(TESForm*);
    unsigned int GetTextureNameLength();
    static char* GetTextureResourceName(TESForm*, TESObjectREFR*);
    char* GetTextureResourceName();
    void AssignTextureName(char*);
    static void NormalizeTextureFilePath(char*, char*);
    static char* NormalizeTextureFilePath(void*, char*);
    static char* NormalFileToRegularFile(void*, char*);
    static void GetRegularTextureFilePath(char*, char*);
    static char* GetRegularTextureFilePath(void*, char*);
    static void ConvertTexturePath(char*, char*);
    static bool IsTextureChunk(int);
    static void ReadTextureData(TESTexture*, TESFile*);
    static char* GetMessageIconName(TESForm*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char FullNameComponent[8];
};
typedef char _sizecheck_TESTexture[sizeof(TESTexture) == 12 ? 1 : -1];
struct FUN_006dcd70_shell : public PathingLocation
{
    void FUN_006dcd70(void*);
};

struct RefHelper;
struct RefArg
{
    RefHelper* p;
};
struct TESWorldSpace;
struct TESObjectCELL;
struct PC7d;
struct BGSCameraPath
{
    BGSCameraPath* GetPrevPath();
};
struct TES
{
    TESWorldSpace* GetHitSound();
};
struct RefHelper
{
    TESWorldSpace* GetParentWorldSpace();
};
struct BSOcclusionPlane
{
    int GetCullResult() const;
};
struct fnv_006dcbb0
{
    static int DAT_0102583c;
};
void __fastcall _ref_006815c0(void* pThis);
extern TES* g_TES;
extern PC7d* g_thePlayer;
}  // namespace fnv_006dcd70

namespace fnv_009624d0 {
struct ReferenceLightData;
struct ExtraDataList;
ReferenceLightData* __fastcall FUN_00418250(const ExtraDataList*);
struct XExtraList;
struct XActor
{
    const XExtraList* GetExtra() const;
};
struct NPH
{
    bool operator==(NPH const&) const;
};
struct Helper62d0
{
    Helper62d0& operator=(void* const&);
};
struct NodeH
{
    bool FUN_00456610();
};
struct PC605
{
    NodeH* GetNode(bool);
};
struct Fn88b4e0
{
    void FUN_0088b4e0();
};
struct Fn9624d0
{
    void FUN_009624d0();
};
}  // namespace fnv_009624d0

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0055a3d0(unsigned int flags);
};
}

namespace fnv_00561d90 {
struct FUN_00561d90_shell : public TESObjectREFR
{
    bool FUN_00561d90();
};

struct FUN_0041b3a0_shell
{
    bool FUN_0041b3a0(int);
};
struct ShellH;
class TESForm;
class XActor
{
  public:
    ShellH* GetExtra() const;
};
struct FormChangeMask
{
    FormChangeMask(int);
    FormChangeMask(const FormChangeMask&);
    int iFlags;
};
class BGSSaveLoadGame
{
  public:
    bool HasFormChangeFlags(TESForm*, FormChangeMask);
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
}  // namespace fnv_00561d90

extern int DAT_0126822c;
struct FUN_0056e370
{
    FUN_0056e370();
    virtual ~FUN_0056e370();
    void FUN_00c9f050(const void*);
    void FUN_0056e350();
};
class FUN_0056e2d0 : public FUN_0056e370
{
  public:
    FUN_0056e2d0(const void* arInfo);
    virtual ~FUN_0056e2d0();
};

struct V4_538f40
{
    void FUN_00538f40();
    float v[4];
};
struct FUN_00437c10
{
    FUN_00437c10();
    V4_538f40 m_kMinimumCorner;
    V4_538f40 m_kMaximumCorner;
};
struct FUN_0056e180
{
    FUN_0056e180();
    ~FUN_0056e180();
    char pad00[0x18];
};
class FUN_0056e4e0 : public FUN_0056e180
{
  public:
    char pad18[8];
    FUN_00437c10 aabb;
    FUN_0056e4e0();
};

namespace fnv_0056e550 {
extern int DAT_0126822c;
struct FUN_0056e370
{
    FUN_0056e370();
    virtual ~FUN_0056e370();
    void FUN_00c9f050(const void*);
    void FUN_0056e350();
};
class FUN_0056e550 : public FUN_0056e370
{
  public:
    FUN_0056e550(const void* arInfo);
    virtual ~FUN_0056e550();
};
}  // namespace fnv_0056e550

struct GO
{
    GO(int);
    void* m_pObject;
};
struct FUN_005726c0
{
    GO m_pMenuLight;
    float m_fLightRadius;
    FUN_005726c0();
};
// @f3 0x004471d0 (community match, verified in this file)
struct A1450MemoryManager { void Deallocate(void*); };
extern A1450MemoryManager DAT_011f6238;
struct Cls_004471d0 {
    char pad[0x420];
    void* ptr420;
    int unk424;
    void FUN_004471d0();
};
void Cls_004471d0::FUN_004471d0() {
    if (ptr420) {
        DAT_011f6238.Deallocate(ptr420);
        ptr420 = 0;
        unk424 = 0;
    }
}


namespace fnv_00575700 {
struct NiStream;
struct blob12
{
    char b[12];
};
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct FUN_00575700_shell : public TESObjectREFR
{
    void FUN_00575700(struct blob12);
};

float __cdecl WrapAngle(float);
struct RefrV
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
    virtual void v18(int);
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
    virtual bool v64();
    void FUN_00575700(NiPoint3 aPoint);
};
}  // namespace fnv_00575700

struct Stand62a
{
    int FUN_004b5220();
};

namespace fnv_0055a2f0 {
struct TESForm
{
    virtual void vf();
    char pad[0x14];
    TESForm();
    ~TESForm();
};

struct DoorTeleportLoadData
{
    int unk00;
    DoorTeleportLoadData();
};

struct SFTX
{
    void SetFormType(int);
};

struct TESChildCell
{
    virtual void UnkChildCell();
    TESChildCell();
};

struct ExtraDataList_helper
{
    ExtraDataList_helper();
    ~ExtraDataList_helper();
};

struct FUN_0055a2f0 : public TESForm, public TESChildCell
{
    void* m_pSoundForm;               // at 0x1c
    DoorTeleportLoadData m_teleport;  // at 0x20
    char pad_data[0x40 - 0x24];
    void* m_pOwningCell;             // at 0x40
    ExtraDataList_helper m_extra;  // at 0x44
    char pad_extra[0x64 - 0x44 - sizeof(ExtraDataList_helper)];
    void* m_pRenderData;  // at 0x64

    void FUN_0055ac90();
    FUN_0055a2f0();
};

// @fnv 0x0055a2f0
FUN_0055a2f0::FUN_0055a2f0()
{
    ((SFTX*)this)->SetFormType(0x3a);
    m_pRenderData = 0;
    FUN_0055ac90();
    m_teleport.unk00 = 0;
    m_pOwningCell = 0;
    m_pSoundForm = 0;
}
}  // namespace fnv_0055a2f0

int DAT_011dea24;
// @fnv 0x0055ac70
int FUN_0055ac70()
{
    return DAT_011dea24;
}

extern int DAT_011dea24;
// @fnv 0x0055ac80
void FUN_0055ac80()
{
    DAT_011dea24 = 0;
}

namespace fnv_00565580 {
struct NiAVObject;
struct NiProperty;

struct Model
{
    void* GetObject3D();
};

struct Flt
{
    operator unsigned int() const;
};

struct TL
{
    Flt* GetNext(void*&);
};

struct TESRecipe
{
    TL* GetData();
};

struct NiObjectNET
{
    unsigned int GetNumChildren();
};

struct NiNode
{
    NiAVObject* GetAt(unsigned int);
};

struct VTable_0c
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* vfn_0c();
};

}  // namespace fnv_00565580

namespace fnv_00569880 {
struct XActor
{
    void* GetExtra() const;
};

struct FUN_0041fbe0_shell
{
    void* FUN_0041fbe0();
};

struct FUN_00413fc0_Class
{
    blob12 GetRadii() const;
};

struct HalfExtentsHelper
{
    bool _Call_439090(const blob12&);
};

struct DataHelper
{
    HalfExtentsHelper* _ref_006815c0();
    void FUN_0098ddd0(const blob12&);
};

struct ScriptS
{
    void* GetHeader();
};

void* FUN_00569910();

struct FUN_00569880_cls : public TESObjectREFR
{
    DataHelper* FUN_00569840();
    void* FUN_00569880();
};

}  // namespace fnv_00569880

extern int DAT_011c3ae4;

namespace fnv_0056a8d0 {
extern int g_011c7d34;

bool FUN_0045bad0(void*, void*);

struct ChildHelper
{
    void FUN_0050f5a0();
};

struct NiObjectNET
{
    unsigned int GetNumChildren();
};

struct NiNode
{
    void* GetAt(unsigned int);
};

struct Vtbl1d0
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void* Get3DData();
};

struct Vtbl0c
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void* GetNode();
};

struct VtblF8
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
    virtual void SetAt(unsigned int, void*);
};

struct FUN_0056a8d0_cls : public TESObjectREFR
{
    void FUN_0056a8d0();
};

}  // namespace fnv_0056a8d0

extern const char* const g_01268200_arg1;
struct Stand62b
{
    const char* const* FUN_0056d480();
};

extern char g_012681c0_arg1;
struct S_0056d4f0
{
    const void* FUN_0056d4f0();
};

extern char g_01268224_arg1;
struct S_0056e410
{
    const void* FUN_0056e410();
};

extern char g_01268230_arg1;
struct S_0056e450
{
    const void* FUN_0056e450();
};

extern char g_01268444_arg1;
struct S_0056e490
{
    const void* FUN_0056e490();
};

struct S_0056e4a0
{
    unsigned int FUN_0056e4a0();
};

extern char g_01268304_arg1;
struct S_0056e5d0
{
    const void* FUN_0056e5d0();
};

extern char g_012681b4_arg1;
struct S_0056e730
{
    const void* FUN_0056e730();
};

extern char g_01268254_arg1;
struct S_0056e770
{
    const void* FUN_0056e770();
};

extern char g_01268264_arg1;
struct S_0056e7b0
{
    const void* FUN_0056e7b0();
};

namespace fnv_0056fba0 {
struct NiPoint3
{
    float x, y, z;
};

extern NiPoint3 g_011ca3d4;
extern NiPoint3 _NiPoint3_ZERO;

int FUN_0050ea90();

struct ExtraX;
struct NiAVObjectX
{
    ExtraX* GetExtraData(int);
};

struct ExtraHelper
{
    void FUN_0050ea50(void*);
};

struct FUN_0056fba0_cls : public TESObjectREFR
{
    int GetReferenceType();
    NiPoint3* FUN_0056fba0(NiPoint3* out);
};

}  // namespace fnv_0056fba0

struct NiFixedString;
extern NiFixedString* DAT_011c61a4;

namespace fnv_00572610 {
struct NP
{
    void* ptr;
    NP& operator=(void*);
};

struct FUN_005726c0 : public NP
{
    float fScale;
    FUN_005726c0();
};

struct XActor
{
    void* GetExtra() const;
};

struct ExtraDataListHelper
{
    void FUN_00418e30(void*);
};

struct FUN_00572610_cls : public TESObjectREFR
{
    void FUN_00572610(void* apObj);
};

}  // namespace fnv_00572610

namespace fnv_0057a770 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSAnimNoteReceiver;
struct BSExtraData;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FurnitureMark;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct SpellItem;
struct TESActorBase;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESFaction;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectWEAP;
struct TESPackage;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_0057a770_shell : public TESObjectREFR
{
    BSAnimNoteReceiver* FUN_0057a770();
};

struct StandIn_RefrExtra
{
    BSExtraData* GetExtraData(unsigned char) const;
};

struct FUN_0057a960
{
    char pad[0x18];
    FUN_0057a960();
};

struct TESRaceForm
{
    void Initialize(unsigned int);
};

struct FUN_0057a870
{
    char pad[0x10];
    FUN_0057a870(void*);
};

struct ShellH;
struct XActor
{
    ShellH* GetExtra() const;
};

struct StandIn_BaseExtraList
{
    BSExtraData* AddExtra(BSExtraData*);
};

struct ExtraAnimNoteReceiver
{
    unsigned char pad[0xc];
    BSAnimNoteReceiver* m_pReceiver;
};

}  // namespace fnv_0057a770

struct FUN_0067b170
{
    char pad[0x11];
    char field_11;
    char pad2[0x20 - 0x12];
    FUN_0067b170();
};

struct TESPackage
{
    char pad[0x28];
    FUN_0067b170* field_28;
    int GetPackType();
    void FUN_00672aa0(char arg);
};

namespace fnv_0084e730 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct SaveLoadFile;
struct ReferencePlacementData;
struct TESForm;
struct blob4
{
    char b[4];
};
struct BGSSaveLoadInitialDataPacket
{
    static int DetermineInitialDataType(unsigned int, int, struct blob4);
    static int DetermineInitialDataType(TESForm*, struct blob4);
    static unsigned int GetInitialDataTypeSize(int);
    static unsigned int GetInitialDataTypeDataSize(int);
    static bool IsInitialDataRefType(int);
    static bool IsInitialDataCellType(int);
    static unsigned int ReadInitialDataBlock(char*, int, void*);
    static unsigned int ReadInitialDataBlock(BGSLoadFormBuffer*, int, void*);
    static unsigned int ReadInitialDataBlock(SaveLoadFile*, int, void*);
    static int AddFormToChangesMap(BGSSaveFormBuffer*, TESForm*, struct blob4);
    static int LoadInitialDataForForm(BGSLoadFormBuffer*, TESForm*, struct blob4);
    static TESForm* CreateReference(unsigned int, ReferencePlacementData*, TESForm*);
    char _pad_0[1];
};
typedef char _sizecheck_BGSSaveLoadInitialData[sizeof(BGSSaveLoadInitialDataPacket) == 1 ? 1 : -1];
struct FormChangeMask
{
    bool ContainsAnyFlags(int);
    bool CheckFlagsExact(int);
    bool CheckFlagsExclusive(int);
    void SetFlags(int);
    void AddFlags(int);
    void RemoveFlags(int);
    struct blob4 GetDifference(int);
    static char* GetFullFlagName(int, unsigned int, bool);
    static char* GetShortFlagName(int, unsigned int);
    static bool IsFlagSetForType(int, unsigned int, unsigned int);
    bool HasFormChanged(TESForm*);
    static struct blob4 CombineFlags(struct blob4, struct blob4, unsigned int, bool);
    int iFlags;
};
typedef char _sizecheck_BGSChangeFlags[sizeof(FormChangeMask) == 4 ? 1 : -1];

bool __cdecl FUN_00564900(int);

struct DataHandler
{
    bool FormIDExists(unsigned int);
};

extern DataHandler* g_dataHandler;

}  // namespace fnv_0084e730

namespace fnv_00418220 {
struct BSExtraData;

struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
    int FUN_00418220();
};

}  // namespace fnv_00418220

struct FUN_0055abe0_class
{
    unsigned int mUnused;
    unsigned int mUnused2;
    unsigned int mFlags;
    bool FUN_0055abe0() const;
};

struct FUN_0055ac00_t
{
    void* FUN_0055ac00();
};

struct FUN_0055ac20_Class
{
    void FUN_0055ac20();
};

struct FUN_005611c0_t
{
    void FUN_005611e0();
    void FUN_005611c0();
};

namespace fnv_00561580 {
struct ScriptLocalsX
{
    void* GetLocalData(void);
};
struct ScriptX
{
    void GetLocalData(void);
};
struct hkpEntity
{
    void activate();
    void deactivate();
};

struct FUN_00561580_Class
{
    void FUN_00561580(unsigned char value);
};

}  // namespace fnv_00561580

namespace fnv_005617c0 {
struct ScriptLocalsX
{
    void* GetLocalData();
};
struct ScriptX
{
    void GetLocalData();
};
struct FUN_00561800_
{
    void __thiscall FUN_00561800(int value);
};

struct FUN_005617c0_
{
    void __thiscall FUN_005617c0(int value);
};

}  // namespace fnv_005617c0

namespace fnv_00562020 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct SoundPlaybackHandle;
struct BaseProcess;
struct DialogueResponse;
struct MobileObject;
struct NiAVObject;
struct NiPoint3;
struct LocationDescriptor;
struct TESIdleForm;
struct TESObjectCELL;
struct TESPackage;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct bhkCharacterController;
struct PhysicsSimulationContext;
struct hkStatisticsCollector;
struct hkVector4;
struct CharacterProxyConfiguration;
struct Vector4Data;
struct hkpCharacterProxy;
struct CharacterPhysicsController;
struct blob1
{
    char b[1];
};
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];
struct FUN_00562020_shell : public TESObjectREFR
{
    void FUN_00562020();
};

struct RA_H
{
    int GetReferenceType();
};
struct M3
{
    float a, b, c, d, e, f, g, h, i;
    M3();
};
struct FUN_00440460_S
{
    void FUN_00440460(const void*);
};
struct CharCtl_S
{
    void FUN_005620e0(void*);
};
struct S_00931f80
{
    CharCtl_S* GetPhysicsCharacterController();
};
struct NiAVObject_H
{
    void SetLocalRotation(const M3&);
};
struct UpdData
{
    float t;
    char b0, b1, b2, b3, b4, b5, b6, b7;
    void NiUpdateData(float, bool, bool);
};
struct NiNode_H
{
    void Update(const UpdData&);
};
struct F56_H
{
    M3 FUN_0056fa00();
};
void __cdecl FUN_00c69f50(void*, int, int);

}  // namespace fnv_00562020

namespace fnv_005691b0 {
struct LockExtraData
{
    int GetLevel(TESObjectREFR* ref);
};

struct P01RefA
{
    LockExtraData* GetLock();
    int FUN_005691b0();
};

}  // namespace fnv_005691b0

namespace fnv_00569ac0 {
struct FUN_00421e10_shell
{
    TESObjectREFR* FUN_00421e10(void);
};

struct ShellH
{
    TESObjectREFR* FUN_00421e10(void);
};

struct XActor
{
    ShellH* GetExtra(void) const;
};

struct FUN_00569ac0_shell : XActor
{
    TESObjectREFR* FUN_00569ac0(void);
};

}  // namespace fnv_00569ac0

namespace fnv_00569b20 {
struct XActor
{
    void* GetExtra() const;
    void FUN_00569b20();
};

struct ShellH
{
    void FUN_0041e220();
};

}  // namespace fnv_00569b20

namespace fnv_0056b1d0 {
struct ExtraDataList;
struct RadioReferenceData
{
    int m_unk0;
    int m_unk4;
    float m_unk8;
};
RadioReferenceData* __fastcall FUN_004182e0(ExtraDataList const*);

struct XActor
{
    ExtraDataList* GetExtra(void) const;
    float FUN_0056b1d0();
};

}  // namespace fnv_0056b1d0

struct FUN_0056c760_Class
{
    int m_iWordAt00;
    int m_iWordAt04;
    unsigned int m_8;

    bool FUN_0056c760();
};

struct FUN_0056c8b0_Class
{
    unsigned int m_0x00;
    unsigned int m_0x04;
    unsigned int m_0x08;
    unsigned int m_0x0c;
    unsigned int m_0x10;
    void FUN_0056c8b0(unsigned int flags, bool set);
};

struct S3e60
{
    bool FUN_0056d340(unsigned int index);
    bool FUN_0056d320(unsigned int index);
};

void __fastcall FUN_004b4fc0(void* p);

struct FUN_0056e350_t
{
    void FUN_0056e350();
};

extern "C" void __cdecl __Dummy_00b6fef0(void* ptr, unsigned int size);

struct bhkPhantom
{
    void* FUN_00c9f3b0();
    void* FUN_0056e420(unsigned int flags);
};

struct FUN_0056e4b0_Class
{
    void* FUN_0056e4b0(unsigned int flags);
};

struct FUN_00c9eec0_Class
{
    void FUN_00c9eec0();
};

void __cdecl __Dummy_00b6fef0(void* obj, unsigned int size);

struct FUN_0056e780_Class
{
    void FUN_00ca0540();
    void* FUN_0056e780(unsigned int flags);
};

void FUN_00ca0540(void* p);
extern "C" void __cdecl __Dummy_00b6fef0(void* p, unsigned int flags);

extern "C" void __cdecl __Dummy_00b6fef0(void* obj, unsigned int size);

struct FUN_0056e7c0_Class
{
    void FUN_00c9fb00();
    void* FUN_0056e7c0(unsigned int flags);
};

struct FUN_0056e8a0
{
    float m_f0;
    float m_f4;
    float m_f8;
    void SetAll(float value);
};

extern "C" void __cdecl __Dummy_00b6fef0(void* p, unsigned int size);
void FUN_00ca0660();

struct FUN_0056ea60
{
    virtual ~FUN_0056ea60();
    void* ScalarDeletingDestructor(unsigned int flags);
};

namespace fnv_00572d10 {
struct S0041b470
{
    unsigned int FUN_0041b370();
};

struct XActor
{
    S0041b470* GetExtra() const;
    unsigned int FUN_00572d10();
};

}  // namespace fnv_00572d10

struct FUN_00572fa0_t
{
    unsigned char FUN_00572fa0();
};

struct FUN_00573eb0_Class
{
    int FUN_00573eb0();
    int FUN_0047b4d0(int);
};

struct _dummy_4d9fa0
{
    void FUN_004d9fc0(bool, unsigned short);
    void FUN_00573f00(bool argument0);
};

struct TaskQueueInterface
{
    void SetTaskFlagDWord(bool, unsigned int);
    void FUN_00576640(bool argument0);
};

namespace fnv_00576660 {
struct TaskQueueInterface
{
    void SetTaskFlagDWord(bool, unsigned int);
    void FUN_00576660(bool value);
};

}  // namespace fnv_00576660

namespace fnv_005771d0 {
struct bhkShape;
bhkShape* __cdecl FUN_004a3a40(void*);
}  // namespace fnv_005771d0

struct FUN_008ae620
{
    void Set(int value);
};

struct Flt
{
    operator unsigned int() const;
};

struct FUN_00978ef0
{
    char m_auiShapeKeys[0x120];
    Flt m_field;
    unsigned int GetStartingAngle();
};

struct FUN_005098c0Class
{
    void FUN_005098c0();
};

struct FUN_0055e1d0_Class
{
    char m_00a8[0xa8];
    unsigned short m_00a8w;
    void FUN_0055e1d0();
};

namespace fnv_005673c0 {
class ExtraDataList;
class Script;

class XActor
{
  public:
    ExtraDataList* GetExtra() const;
    Script* FUN_005673c0();
};

Script* __fastcall FUN_00418800(ExtraDataList*);

}  // namespace fnv_005673c0

extern "C" void* __cdecl _delete(void* ptr, unsigned int size);

struct bhkWorldObject
{
    void FUN_00c85790();
    void* FUN_0056d4c0(unsigned int flags);
};

struct FUN_0056e2a0
{
    void FUN_004b4fa0();
    FUN_0056e2a0();
};

// @fnv 0x0056e2a0
FUN_0056e2a0::FUN_0056e2a0()
{
    FUN_004b4fa0();
    (reinterpret_cast<FUN_0056e2a0*>(reinterpret_cast<char*>(this) + 0x10))->FUN_004b4fa0();
    (reinterpret_cast<FUN_0056e2a0*>(reinterpret_cast<char*>(this) + 0x20))->FUN_004b4fa0();
}

struct bhkAabbPhantom
{
    virtual ~bhkAabbPhantom();
    void FUN_00c9f530();
    void* FUN_0056e5e0(unsigned int flags);
    static void operator delete(void* ptr, unsigned int size);
};

namespace fnv_0056e740 {
extern void __cdecl _delete(void* p, unsigned int size);

struct bhkShape
{
    void FUN_00c84c50();
    void* FUN_0056e740(unsigned int flags);
};

}  // namespace fnv_0056e740

namespace fnv_00572750 {
class BSExtraData;

struct FUN_00418280_Class
{
    BSExtraData* FUN_00418280();
};

struct XActor
{
    FUN_00418280_Class* GetExtra() const;
    BSExtraData* FUN_00572750();
};

}  // namespace fnv_00572750

namespace fnv_00573ed0 {
struct _dummy_4d9fa0
{
    void FUN_004d9fc0(bool, unsigned short);
    void FUN_00573f00(bool);
    void FUN_00573ed0(bool value);
};

}  // namespace fnv_00573ed0

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
extern GlobalObject_00559cc0 g_011ca0e0;

struct FUN_005a3790Class
{
    bool FUN_005a3790();
};

namespace fnv_0055a3b0 {
struct ShellH
{
    void* FUN_00418220();
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct FUN_0055a3b0_Class
{
    void FUN_0055a3b0();
};
}  // namespace fnv_0055a3b0

extern double _gModifierZero;
extern float DAT_01267bc4;

struct NiPoint3_local
{
    float x, y, z;
};
struct hkVector4
{
    float x, y, z, w;
};
NiPoint3_local& FUN_004a3970(NiPoint3_local& dst, const hkVector4& src);
void* FUN_00560e10();
struct FUN_00560de0_class
{
    void* __thiscall FUN_00560e10();
    void __thiscall FUN_00560de0(void* arg);
};

namespace fnv_00569080 {
struct FUN_004184c0_shell
{
    void* FUN_004184c0();
};
struct ShellH
{
    FUN_004184c0_shell* FUN_004184c0();
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct FUN_00569080_shell
{
    void FUN_00569080();
};
}  // namespace fnv_00569080

struct FUN_0056a860_Class
{
    char pad[0x80];
    int m_0x80;
    bool __thiscall FUN_0056a860();
};

namespace fnv_0056a990 {
struct ShellH;
struct XActor
{
    ShellH* GetExtra() const;
};
struct FUN_00421400_Class
{
    void* FUN_00421400();
};
struct FUN_0056a990_Class
{
    void* FUN_0056a990();
};
}  // namespace fnv_0056a990

namespace fnv_0056c7f0 {
class Flt
{
  public:
    operator unsigned int() const;
};

struct Tile
{
    unsigned char pad[0x2c];
    Flt m_pRenderedNodeEntry;
    unsigned int FUN_0056c7f0();
};

}  // namespace fnv_0056c7f0

struct FUN_0056d490_class
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
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c(void*);
    virtual void FUN_0056d490(void*);
};

extern int DAT_0103046c;
struct FUN_00c6b950
{
    void Init(void* arg);
};
struct FUN_0056d580
{
    void* m_ptr;
    void* Init(void* arg);
};

struct FUN_0056ea40_class
{
    void FUN_0056e8d0();
    void* FUN_0056ea40();
};

namespace fnv_0056f110 {
struct ScriptLocalsX
{
    void* GetLocalData();
};

struct FUN_0056f110_class
{
    void* m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void FUN_0056f110(ScriptLocalsX* flag);
};

}  // namespace fnv_0056f110

struct FUN_005760e0_class
{
    int m_auiShapeKeys;
    int m_pAuxiliaryObject;
    int m_flags;
    bool FUN_005760e0() const;
};

struct FUN_00576100_Class
{
    int m_00;
    void* m_04;
    bool FUN_00576100();
};

namespace fnv_0057b500 {
struct ShellH
{
    void FUN_0042f2d0();
};
struct XActor
{
    ShellH* GetExtra() const;
    void FUN_0057b500();
};
}  // namespace fnv_0057b500

struct FUN_0057b700_class
{
    int FUN_0057b730(int a);
    void FUN_0061ff30(int a);
    void FUN_0057b700(int a);
};

struct FUN_0057b750_struct
{
    void FUN_0057b750(int a);
};
struct FUN_0057b730_struct
{
    int a;
    int b;
    int c;
    int d;
    int e;
    FUN_0057b750_struct* f;
    void FUN_0057b730(int a);
};

namespace fnv_006546e0 {
struct Flt
{
    operator unsigned int();
};

struct FUN_006546e0_Class
{
    unsigned int FUN_006546e0();
};

}  // namespace fnv_006546e0

struct FUN_00922650_cls
{
    void FUN_00922650(int a, int b);
};

struct List_00905330
{
    void __thiscall _ref_00905330(const unsigned int&);
};
struct Holder_0055ac40
{
    char pad[0x84C];
    List_00905330 lst;
    void __thiscall FUN_0055ac40(unsigned int);
};

namespace fnv_005627c0 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FUN_005627c0_shell : public TESObjectREFR
{
    void FUN_005627c0(BGSLoadFormBuffer*);
};

struct VRefr005627c0
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
    virtual bool IsActorV();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
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
    virtual void v6a();
    virtual void v6b();
    virtual void v6c();
    virtual void v6d();
    virtual void v6e();
    virtual void v6f();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void Slot73(int, int);
    virtual int Slot74();
};
struct FormChangeMask
{
    FormChangeMask();
    operator bool() const;
    unsigned int flags;
};
struct FUN_00428110_shell
{
    FormChangeMask FUN_00428110(unsigned int);
};
struct TESForm
{
    void Revert(unsigned int);
};
struct ShellH
{
    void FUN_0042d9e0(BGSLoadFormBuffer*);
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct FUN_00572db0_Helper
{
    bool FUN_00561d90();
};
struct FUN_00572db0_shell
{
    void FUN_00572db0(int);
};
struct FUN_00572d50_shell
{
    void FUN_00572d50(int);
};
void FUN_0047b360(TESObjectREFR*);
struct NavMeshObstacleManager
{
    static NavMeshObstacleManager* GetSingleton();
    void RemoveObstacleReference(TESObjectREFR*);
    void AddObstacleReference(TESObjectREFR*);
};
struct TESObjectCELL
{
    bool IsOutdoorCell();
    void FUN_005455c0(TESObjectREFR*);
};
struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
struct RefX
{
    bool FUN_00437b90();
};
struct BSOcclusionPlane
{
    int GetCullResult() const;
};
struct TES_s
{
    void* FUN_00458be0(int, int);
};
extern TES_s* g_TES;
struct Loader_S
{
    void FUN_00444850(TESObjectREFR*, void*, int);
};
extern Loader_S* g_modelLoader;

}  // namespace fnv_005627c0

namespace fnv_00563d80 {
struct NiControllerManager;
struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
typedef char _sizecheck_NiUpdateData[sizeof(NiUpdateData) == 12 ? 1 : -1];
struct FUN_00563d80_shell : public TESObjectREFR
{
    bool FUN_00563d80(NiControllerManager*, char*, float);
};

struct NiAVObject
{
    int iDummy;
};
struct NiNode : public NiAVObject
{
    void Update(const NiUpdateData& arData);
};
struct NiFixedStr
{
    operator const char*() const;
};
struct SeqObj
{
    NiFixedStr& GetName();
};
struct NiControllerSequence
{
    int GetState();
    float FUN_00759450();
    float FUN_00508100();
    void FUN_0098adb0(float);
};
struct BSAnimGroupSequence : public NiControllerSequence
{
};
struct NiControllerManager
{
    unsigned int FUN_00495d00();
    BSAnimGroupSequence* FUN_00495d20(unsigned int);
    void DeactivateAllSequences(float);
    bool ActivateControllerSequence(NiControllerSequence*, int, bool, float, float, NiControllerSequence*);
    bool StopSequence(NiControllerSequence*, float);
};
struct TaskQueueInterface
{
    void QueueReferenceStateTask(bool);
};
struct RefA
{
    NiAVObject* GetReferenceType();
};
struct UpdData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    void NiUpdateData(float, bool, bool);
};
struct FUN_005672c0_shell
{
    void FUN_005672c0(BSAnimGroupSequence*);
};
void __cdecl FUN_00c6bd00(NiNode*, bool);
int __cdecl FUN_00ec6da0(const char*, const char*);
extern float DAT_0102f510;

}  // namespace fnv_00563d80

namespace fnv_00565870 {
struct ActiveEffect;
struct Actor;
struct ActorMover;
struct ActorValueOwner;
struct AlchemyItem;
struct Animation;
struct BGSImpactDataSet;
struct BGSLoadFormBuffer;
struct BGSPerk;
struct BGSPerkEntry;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSAnimGroupSequence;
struct BSAnimNote;
struct BSFaceGenAnimationData;
struct SoundPlaybackHandle;
struct BaseProcess;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
struct CombatGroupCollection;
struct CombatController;
struct ActorCombatGroup;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct ContinuousBeamProjectile;
struct Crime;
struct DialogueResponse;
struct DetectionParameters;
struct EffectItem;
struct ExtraDataList;
struct FormRecordHeader;
struct TESFileGroup;
struct FurnitureMark;
struct HWND__;
struct BooleanFloatQuery;
struct IDebugText;
struct InventoryChanges;
struct InventoryStackRecord;
struct MagicCaster;
struct MagicItem;
struct MagicEffectCollection;
struct MagicProjectile;
struct MagicTarget;
struct MobileObject;
struct NiAVObject;
struct NiColor;
struct NiNode;
struct NiPoint3;
struct LocationDescriptor;
struct PathingAvoidNodeArray;
struct PathingLocation;
struct PathingRequest;
struct Projectile;
struct QueuedFile;
struct ScriptHeaderData;
struct ScriptReferencedObject;
struct Script;
struct CStringArgument;
struct ScriptCompiler;
struct ScriptLocals;
struct SpellItem;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESClass;
struct TESCombatStyle;
struct TESContainer;
struct TESFaction;
struct TESFile;
struct TESForm;
struct TESIdleForm;
struct TESObject;
struct TESObjectARMO;
struct TESObjectBOOK;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectWEAP;
struct TESPackage;
struct TESQuest;
struct TESRace;
struct TESSkill;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct TargetEntry;
struct TrapEntry;
struct TrespassPackage;
struct WeaponObject;
struct bhkCharacterController;
struct bhkRagdollController;
struct bhkRagdollPenetrationUtil;
struct bhkRigidBody;
struct hkpRigidBody;
struct blob4
{
    char b[4];
};
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_00565870_shell : public TESObjectREFR
{
    bool FUN_00565870();
};

struct VS00565870
{
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
    virtual void v18(unsigned int);
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
    virtual bool v63();
    virtual void v064();
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
    virtual void v80();
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
    virtual void* v116();
};
struct ExtraSayToTopicInfo;
struct XScript
{
    bool Run(void*, void*, void*, bool);
};
struct XEDL
{
    void* GetScriptLocalData();
    ExtraSayToTopicInfo* FUN_0042ede0();
};
struct XActor
{
    XEDL* GetExtra() const;
};
struct XForm
{
    int _FNV_GetFormType();
};
struct XRef
{
    XForm* _FNV_GetObjectReference();
    bool IsDeleted() const;
};
struct XActorP
{
    void* GetLogDate();
    unsigned int GetCurrentProcessLevel();
};
struct XInv
{
    static XInv* CreateForReference(void*);
    bool FUN_004d2480(void*);
};
XScript* __fastcall FUN_00418800(XEDL*);
void* __fastcall FUN_0055d310(void*);

}  // namespace fnv_00565870

namespace fnv_00568020 {
struct BSExtraData;
struct FUN_00568020_shell : public TESObjectREFR
{
    void FUN_00568020(unsigned int, bool);
};

struct BSExtraData;
struct ExtraUsedMarkers
{
    char pad[0xc];
    unsigned int m_uiUsedMarkerFlags;
    ExtraUsedMarkers();
    void SetUsedMarker(unsigned int, bool);
};
struct FNVFormStub
{
    int _FNV_GetFormType();
};
struct FNVRefStub
{
    FNVFormStub* _FNV_GetObjectReference();
};
struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
    BSExtraData* AddExtra(BSExtraData*);
    void _FUN_00410020(BSExtraData*, bool);
};
struct XActor
{
    BaseExtraList* GetExtra() const;
};
struct FNVVirtStub
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
    virtual void SetChanged(unsigned int);
};

}  // namespace fnv_00568020

namespace fnv_00568150 {
struct BSExtraData;
struct FUN_00568150_shell : public TESObjectREFR
{
    void FUN_00568150(unsigned int, bool);
};

struct VS00568150
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
    virtual void v18(unsigned int);
};
struct ExtraReservedMarkers
{
    void* vt;
    void* next;
    unsigned char type;
    unsigned int m_uiReservedMarkers;
    ExtraReservedMarkers();
    void SetUsedMarker(unsigned int, bool);
};
struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
    BSExtraData* AddExtra(BSExtraData*);
    void FUN_00410020(BSExtraData*, bool);
};
struct XActor
{
    BaseExtraList* GetExtra() const;
};

}  // namespace fnv_00568150

namespace fnv_005682c0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BSExtraData;
struct BaseFormComponent;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_005682c0_shell : public TESObjectREFR
{
    int FUN_005682c0(bool);
};

struct BSExtraData;
struct ExtraUsedMarkers
{
    bool FUN_00432f80(unsigned int);
};
typedef ExtraUsedMarkers ExtraReservedMarkers;
struct TESFurniture
{
    bool IsMarkerEnabled(unsigned int);
    int _FNV_GetFormType();
};
struct FNVRefStub
{
    TESFurniture* _FNV_GetObjectReference();
};
struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
};
struct XActor
{
    BaseExtraList* GetExtra() const;
};

}  // namespace fnv_005682c0

namespace fnv_00568cb0 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct TESTexture;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_00568cb0_shell : public TESObjectREFR
{
    float FUN_00568cb0();
};

struct FNVForm_00568cb0
{
    int _FNV_GetFormType();
};
struct FNVRef_00568cb0
{
    FNVForm_00568cb0* _FNV_GetObjectReference();
};
struct ExtraDataList
{
    float GetRadius();
};
struct XActor
{
    ExtraDataList* GetExtra() const;
};
struct InterfaceManager
{
    unsigned int FUN_004fd400();
};
struct GlobalObject_0045cfe0
{
    int* Int();
};
struct LoadedRefData_00568cb0
{
    char pad[0xc];
    float fRadius;
};
bool __cdecl FUN_0040eb10(float, float, float);
extern double _gModifierZero;
extern const float runtimeFloatSettingDefault247;
extern FNVForm_00568cb0* DAT_011ca224;
extern FNVForm_00568cb0* DAT_011ca228;
extern FNVForm_00568cb0* DAT_011ca264;
extern GlobalObject_0045cfe0 g_011d0bd8;

}  // namespace fnv_00568cb0

namespace fnv_0056e270 {
struct FUN_0056e2a0
{
    char _pad[0x30];
    FUN_0056e2a0();
};
struct Mem4fa0
{
    void FUN_004b4fa0();
};
struct FUN_0056e270 : FUN_0056e2a0
{
    Mem4fa0 m30;
    FUN_0056e270();
};
// Constructs the base FUN_0056e2a0 and then calls FUN_004b4fa0 on the m30 member.
// @fnv 0x0056e270
FUN_0056e270::FUN_0056e270()
{
    m30.FUN_004b4fa0();
}
}  // namespace fnv_0056e270

struct FUN_0056e900_shell
{
    int _0;
    float _4;
    void StepAndReturnThis();
    FUN_0056e900_shell* FUN_0056e8d0();
};
extern float DAT_010c72bc;

namespace fnv_0056fa90 {
struct FakeMat
{
    float m[9];
    void DecomposeToEulerAngles(float&, float&, float&);
};
struct Holder
{
    char _p[0x24];
    float _a;
    float _b;
    float _c;
    void FUN_0056fa90(float p1, float p2, float p3, float p4, float p5, float p6, float p7, float p8, float p9);
};
}  // namespace fnv_0056fa90

namespace fnv_00572b00 {
struct NiPoint3
{
    float x, y, z;
};
struct ShellH
{
    NiPoint3 FUN_0041b080(void*);
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct MID_00572b00 : XActor
{
    NiPoint3 FUN_00572b00();
};
}  // namespace fnv_00572b00

namespace fnv_00572b30 {
struct XActor;
struct ShellH
{
    void __thiscall FUN_0041b0d0(int, XActor*);
};
struct XActor
{
    ShellH* GetExtra() const;
    int FUN_00572b30(int);
};
}  // namespace fnv_00572b30

struct S5757a0
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
    virtual void v18(int);
    unsigned char _pad[36];
    float fld28;
    void FUN_005757a0(float);
};

namespace fnv_005764f0 {
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011ca394;
extern GlobalObject_0045cf30 g_011ca3ec;
struct NiAVObject;
struct NiNode
{
    void FUN_004902f0(bool);
};
struct TaskQueueInterface
{
    void FUN_00576640(bool);
};
struct FUN_00576660_t
{
    void FUN_00576660(bool);
};
struct ArrSI
{
    NiNode* GetFlags();
};
struct TESObjectLIGH
{
    bool FUN_0046f070();
};
struct TESContainer
{
    static bool __cdecl IsValidContainerType(unsigned char);
};
struct FormOps
{
    int _FNV_GetFormType();
};
struct RefOps
{
    FormOps* _FNV_GetObjectReference();
};
TESObjectREFR* GetReferenceFromNiAVObject(NiAVObject*);
struct UpdateArg
{
    int unk0;
    bool bPending;
};
void FUN_00c66ff0(ArrSI*, UpdateArg*);

}  // namespace fnv_005764f0

struct NiNode;
void __cdecl FUN_00c6bd00(NiNode*, bool);
struct Unknown
{
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42() = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual void f64() = 0;
    virtual void f65() = 0;
    virtual void f66() = 0;
    virtual void f67() = 0;
    virtual void f68() = 0;
    virtual void f69() = 0;
    virtual void f70() = 0;
    virtual void f71() = 0;
    virtual void f72() = 0;
    virtual void f73() = 0;
    virtual void f74() = 0;
    virtual void f75() = 0;
    virtual void f76() = 0;
    virtual void f77() = 0;
    virtual void f78() = 0;
    virtual void f79() = 0;
    virtual void f80() = 0;
    virtual void f81() = 0;
    virtual void f82() = 0;
    virtual void f83() = 0;
    virtual void f84() = 0;
    virtual void f85() = 0;
    virtual void f86() = 0;
    virtual void f87() = 0;
    virtual void f88() = 0;
    virtual void f89() = 0;
    virtual void f90() = 0;
    virtual void f91() = 0;
    virtual void f92() = 0;
    virtual void f93() = 0;
    virtual void f94() = 0;
    virtual void f95() = 0;
    virtual void f96() = 0;
    virtual void f97() = 0;
    virtual void f98() = 0;
    virtual void f99() = 0;
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
    virtual NiNode* GetNode() = 0;
    void FUN_00578920(bool);
};

namespace fnv_0057ab70 {
struct BSMultiBoundNode;
struct RefV;
struct NodeV
{
    NodeV* GetDaysPassed();
};
struct ParentV
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
    virtual void InsertChild(NodeV* child);
};
struct BoundNodeV
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
    virtual void AttachChildInAvailableSlot(NodeV* child, bool firstAvail);
};
struct TESObjectCELL
{
    NodeV* GetDynamicNode();
    BoundNodeV* FUN_00545960(RefV* ref);
};
struct BSOcclusionPlane
{
    TESObjectCELL* GetCullResult() const;
};
struct RefV
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
    virtual NodeV* Get3D();
    void FUN_00569ae0(RefV* ref);
};
struct MapX
{
    void* GetFirstPos();
};
struct NiTMap
{
    void GetNext(void*& pos, RefV*& key, RefV*& val);
};
struct MyMap
{
    void RemoveAll();
};

}  // namespace fnv_0057ab70

namespace fnv_0057b520 {
struct BSExtraData;
struct BSMultiBoundNode;
struct BSRenderedTexture;
struct NiAVObject;
struct NiCamera;
struct NiGeometry;
struct ThreeByThreeMatrix;
struct NiNode;
struct NiPoint3;
struct NiTexture;
struct NiTriShape;
struct NiTriShapeData;
struct WaterSurface;
struct TriangleStripData;
struct TESObjectCELL;
struct TESWaterForm;
struct TESWaterListener;
struct TESWorldSpace;
struct TargetEntry;
struct WaterZone;
struct ZoneEntry;
struct bhkEntity;
struct bhkRigidBody;
struct hkVector4;
struct hkpEntity;
struct hkpRigidBody;
struct RootContactPoint;
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct FUN_0057b520_shell : public TESObjectREFR
{
    void FUN_0057b520(bool);
};

struct ShellH;
struct BaseExtraList
{
    BSExtraData* GetExtraData(unsigned char);
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct ExtraWaterZoneMap;
struct WaterZone;
struct WaterZoneManager
{
    void UpdateWaterZone(TESObjectREFR*, TESObjectREFR*, float);
};
struct EffectSetting
{
    int GetEffectID();
};
extern int g_TES;
struct NiTMap
{
    void GetNext(void*&, unsigned int&, void*&);
};
struct MapX
{
    void* GetFirstPos();
};
struct FUN_0042f1d0_shell
{
    void* FUN_0042f1d0();
};
struct FUN_0057b700_class
{
    void FUN_0057b700(int);
};
TESObjectREFR* __fastcall _ref_0084e3a0(void*);
struct BSOcclusionPlane
{
    int GetCullResult() const;
};
struct ExtraDataList
{
    unsigned int GetRoomId();
};
struct BSThread
{
    unsigned int GetThreadID();
};
struct bhkWorld;
struct TESWaterListener;
struct S_00620130
{
    void FUN_00620130(TESObjectREFR*);
};
struct S_00631370
{
    void FUN_00631370(TESObjectREFR*, int, int);
};
struct ExtraListRemover
{
    void FUN_00410020(BSExtraData*, bool);
};
struct MobileObjectCellAccess
{
    bool FUN_004518e0() const;
};
struct MobileObject
{
    float GetRelevantWaterHeight() const;
};
struct S_004e5fe0
{
    void FUN_004e5fe0(TESObjectREFR*);
};
struct CC_00931f80;
struct S_00931f80
{
    CC_00931f80* GetPhysicsCharacterController();
};
struct Actor;
struct bhkCharacterController;
void __fastcall FUN_0057b1d0(char*, float);
struct VRefStandin
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
};

}  // namespace fnv_0057b520

namespace fnv_00560870 {
class NiRTTI;
class NiAVObject;
int FUN_00408b20(const char*, const char*);
class NiFixedStr
{
  public:
    operator const char*() const;
};
struct SeqObj
{
    NiFixedStr& GetName();
};
bool FUN_0043b300(const NiRTTI*, NiAVObject*);
struct ArrSI
{
    unsigned int GetFlags();
};
struct S005609b0
{
    bool FUN_005609b0();
};
void* DynamicCastByRTTI(const void*, void*);
class bhkWorldObject;
struct bhkCollisionObject
{
    bhkWorldObject* FUN_006fa820();
};
extern const void* const DAT_011f9140;
extern NiRTTI g_0126817c;
extern const char* const g_012683c8_arg1;
struct RefIsActorStandIn
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
};
struct CountInfoStandIn
{
    unsigned char m_ucEntryType;
    unsigned short usActive;
    unsigned short usInactive;
    RefIsActorStandIn* pRef;
    unsigned int unk0C;
    NiAVObject* pRoot;
};
struct VisitDataStandIn
{
    void* unk00;
    void* unk04;
    void* unk08;
    CountInfoStandIn* pCount;  // +0C
};

}  // namespace fnv_00560870

namespace fnv_00562660 {
struct Actor;
struct BGSListForm;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct SoundPlaybackHandle;
struct BaseFormComponent;
struct BaseProcess;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct DialogueResponse;
struct ExtraDataList;
struct InventoryChanges;
struct InventoryIterator;
struct InventoryStackRecord;
struct MobileObject;
struct NiAVObject;
struct NiPoint3;
struct IndexedPointerCollection;
struct LocationDescriptor;
struct TESActorBase;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESForm;
struct TESIdleForm;
struct TESLevItem;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCELL;
struct TESObjectCLOT;
struct TESObjectWEAP;
struct TESPackage;
struct TESTopic;
struct TESTopicInfo;
struct TESWorldSpace;
struct bhkCharacterController;
struct blob4
{
    char b[4];
};
struct blob12
{
    char b[12];
};
struct FUN_00562660_shell : public TESObjectREFR
{
    void FUN_00562660(BGSLoadFormBuffer*);
};

namespace N {
struct TerrainManager_r562660
{
    void FUN_006fcfa0(TESObjectREFR*, int);
};
struct TESForm
{
    void Revert(unsigned int);
    bool IsConstantGlobal();
};
struct InventoryChanges
{
    bool CreateForReference();
    static InventoryChanges* __cdecl CreateForReference(TESObjectREFR*);
    void FUN_004d42f0(BGSLoadFormBuffer*);
};
struct ExtraDataList
{
    void InitLoadGame(BGSLoadFormBuffer*, TESForm*);
};
struct TESWorldSpace
{
    TerrainManager_r562660* GetWorldTerrainManager();
};
struct FormChangeMask
{
    unsigned int iFlags;
    FormChangeMask(unsigned int);
    operator bool() const;
};
struct BGSLoadFormBuffer
{
    FormChangeMask GetChangeFlags(unsigned int);
};
}
struct FUN_0056aac0_t
{
    TESObjectREFR* GetEnableParent();
};
struct RefH
{
    bool GetDisabled();
};
struct S
{
    void FUN_00484af0(bool);
    N::TESForm* _FNV_GetObjectReference();
};
struct XActor
{
    N::ExtraDataList* GetExtra() const;
};
struct ActorS
{
    N::TESWorldSpace* GetParentWorldSpace();
};
struct VT
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
    virtual bool v64();
};
}  // namespace fnv_00562660

namespace fnv_00568500 {
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSTextureSet;
struct BipedAnim;
struct CHUNK;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct NiStream;
struct Script;
struct TESBoundObject;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESFormList;
struct FileEntryList;
struct TESWaterForm;
struct DistantTreeTextureInfo;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FurnitureMark
{
    unsigned int QNumber();
    void SetNumber(unsigned int);
    void* QPosition();
    void SetPosition(void*);
    float GetCurrentTargetDistance();
    void SetFurnitureHeading(float);
    void LoadBinary(NiStream*);
    void SaveBinary(NiStream*);
    void __dflt_ctor_closure();
    char Position[12];
    unsigned short m_usMarkerId;
    unsigned char m_ucFlags;
    char _pad_f[1];
};
typedef char _sizecheck_FurnitureMark[sizeof(FurnitureMark) == 16 ? 1 : -1];
struct BaseFormComponent
{
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent*);
    virtual bool IsEqualToBase(BaseFormComponent*);
};
typedef char _sizecheck_BaseFormComponent[sizeof(BaseFormComponent) == 4 ? 1 : -1];
struct FUN_00568500_shell : public TESObjectREFR
{
    bool FUN_00568500(int, FurnitureMark*);
};

struct TESFurniture;
struct BSFurnitureMarker;
struct NiNode;
struct DummyThis;
struct StackArg
{
    int i;
};
int __fastcall FUN_00509490(char*);
FurnitureMark* __fastcall FUN_005094d0(DummyThis*, StackArg);
struct Pt3
{
    float x, y, z;
};
struct M3
{
    float m[9];
    M3();
};
struct FUN_0056fa00_shell
{
    M3 FUN_0056fa00();
};
struct RecipeCraftingInfo
{
    float a, b, c;
};
struct TESRecipe
{
    RecipeCraftingInfo* GetData();
};
struct FUN_00568650_shell
{
    float FUN_00568650();
};
void __fastcall FUN_00c54550(FurnitureMark*, float);
void* __fastcall _ref_006815c0(FurnitureMark*);
void __cdecl FUN_00a582f0(const M3&, const Pt3*, unsigned int, Pt3*, FurnitureMark*);
void* __fastcall _FNV_GetObjectReference(void*);
int __fastcall _FNV_GetFormType(void*);
NiAVObject* __cdecl FUN_00c54400(NiNode*);
struct VRef
{
    virtual void* V0();
    virtual void* V1();
    virtual void* V2();
    virtual void* V3();
    virtual void* V4();
    virtual void* V5();
    virtual void* V6();
    virtual void* V7();
    virtual void* V8();
    virtual void* V9();
    virtual void* V10();
    virtual void* V11();
    virtual void* V12();
    virtual void* V13();
    virtual void* V14();
    virtual void* V15();
    virtual void* V16();
    virtual void* V17();
    virtual void* V18();
    virtual void* V19();
    virtual void* V20();
    virtual void* V21();
    virtual void* V22();
    virtual void* V23();
    virtual void* V24();
    virtual void* V25();
    virtual void* V26();
    virtual void* V27();
    virtual void* V28();
    virtual void* V29();
    virtual void* V30();
    virtual void* V31();
    virtual void* V32();
    virtual void* V33();
    virtual void* V34();
    virtual void* V35();
    virtual void* V36();
    virtual void* V37();
    virtual void* V38();
    virtual void* V39();
    virtual void* V40();
    virtual void* V41();
    virtual void* V42();
    virtual void* V43();
    virtual void* V44();
    virtual void* V45();
    virtual void* V46();
    virtual void* V47();
    virtual void* V48();
    virtual void* V49();
    virtual void* V50();
    virtual void* V51();
    virtual void* V52();
    virtual void* V53();
    virtual void* V54();
    virtual void* V55();
    virtual void* V56();
    virtual void* V57();
    virtual void* V58();
    virtual void* V59();
    virtual void* V60();
    virtual void* V61();
    virtual void* V62();
    virtual void* V63();
    virtual void* V64();
    virtual void* V65();
    virtual void* V66();
    virtual void* V67();
    virtual void* V68();
    virtual void* V69();
    virtual void* V70();
    virtual void* V71();
    virtual void* V72();
    virtual void* V73();
    virtual void* V74();
    virtual void* V75();
    virtual void* V76();
    virtual void* V77();
    virtual void* V78();
    virtual void* V79();
    virtual void* V80();
    virtual void* V81();
    virtual void* V82();
    virtual void* V83();
    virtual void* V84();
    virtual void* V85();
    virtual void* V86();
    virtual void* V87();
    virtual void* V88();
    virtual void* V89();
    virtual void* V90();
    virtual void* V91();
    virtual void* V92();
    virtual void* V93();
    virtual void* V94();
    virtual void* V95();
    virtual void* V96();
    virtual void* V97();
    virtual void* V98();
    virtual void* V99();
    virtual void* V100();
    virtual void* V101();
    virtual void* V102();
    virtual void* V103();
    virtual void* V104();
    virtual void* V105();
    virtual void* V106();
    virtual void* V107();
    virtual void* V108();
    virtual void* V109();
    virtual void* V110();
    virtual void* V111();
    virtual void* V112();
    virtual void* V113();
    virtual void* V114();
    virtual void* V115();
    virtual void* V116();
    virtual void* V117();
    virtual void* V118();
    virtual void* V119();
    virtual void* V120();
    virtual void* V121();
    virtual void* V122();
    virtual void* V123();
    virtual void* V124();
    virtual void* V125();
};

}  // namespace fnv_00568500

namespace fnv_00574920 {
struct ExtraDataList
{
    void RemoveExtraDataType0x15();
};
struct DropList_t
{
    bool FUN_008256d0();
    TESObjectREFR** FUN_006815c0();
    void FUN_0063f7b0();
};
struct ShellH : ExtraDataList
{
    DropList_t* FUN_0041df90();
    void FUN_0041de40(TESObjectREFR*);
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct BGSSaveLoadGame
{
    bool FUN_0042ce10();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
struct InventoryChanges
{
    static InventoryChanges* __cdecl CreateForReference(TESObjectREFR*);
    void FUN_004d17a0();
    void FUN_004d1440();
    void FUN_004d1610();
    void FUN_004d1960();
    bool FUN_0042cde0();
};
struct ResetInvContainerLookup
{
    static TESContainer* __fastcall FUN_0055d310(TESObjectREFR*);
};
struct FUN_008adc50_shell
{
    void FUN_008adc50();
};
struct RefV
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
    virtual bool v100();
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
    virtual bool v160();
    bool FUN_00577de0();
    void FUN_00572270();
};

struct FUN_00574920_t : public TESObjectREFR
{
    void FUN_00574920(bool);
};

}  // namespace fnv_00574920

namespace fnv_00579160 {
struct ExtraDataList;
struct FUN_0042ede0_shell
{
    ExtraDataList* FUN_0042ede0();
};
struct FUN_0042edb0_shell
{
    void FUN_0042edb0();
};
struct XActor
{
    ExtraDataList* GetExtra() const;
};
struct TESTopicInfo
{
    void RunResultScript(int, XActor*);
};
struct SC_008c48d0
{
    static bool GetLocalData(void*, ExtraDataList*, unsigned int);
};
struct FUN_00579160
{
    void DamageObject();
};
bool __fastcall FUN_00579200(const char*);

}  // namespace fnv_00579160

namespace fnv_0055d3b0 {
struct ShellH
{
    int FUN_004216f0();
    ShellH* GetFirstExtraData();
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct TESBoundObject
{
    void* _FNV_GetObjectReference();
};
struct FUN_0055d3b0
{
    bool IsOfType(void* apObj);
};
}  // namespace fnv_0055d3b0

struct FUN_0055ebf0
{
    unsigned char m0;
    unsigned short m1;
    unsigned short m2;
    unsigned int m3;
    unsigned int m4;
    unsigned int m5;
    FUN_0055ebf0();
};

// Initializes all six members of the object to zero.
// @fnv 0x0055ebf0
FUN_0055ebf0::FUN_0055ebf0()
{
    m0 = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m4 = 0;
    m5 = 0;
}

struct FUN_00562e70
{
    unsigned char b0;
    int a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;
    FUN_00562e70();
};

// Initializes the object's byte and seven integer fields to zero.
// @fnv 0x00562e70
FUN_00562e70::FUN_00562e70()
{
    b0 = 0;
    a1 = 0;
    a2 = 0;
    a3 = 0;
    a4 = 0;
    a5 = 0;
    a6 = 0;
    a7 = 0;
}

namespace fnv_005649b0 {
struct ArrSI
{
    unsigned int GetFlags();
    bool FUN_005649b0();
};
struct FNV_GetObjectReference
{
    void* FUN_005649b0();
};
struct FNV_GetFormType
{
    unsigned int FUN_005649b0();
};
}  // namespace fnv_005649b0

namespace fnv_00564b00 {
struct TESObjectREFR_00564b00
{
    void FUN_00564b00(bool set);
};

struct _FNV_GetObjectReference_StandIn
{
    void* _FNV_GetObjectReference();
};

struct _FNV_GetFormType_StandIn
{
    int _FNV_GetFormType();
};

struct ArrSI
{
    unsigned int GetFlags();
};

struct TESObjectREFR_Flags
{
    void SetFlags(unsigned int flags);
};

}  // namespace fnv_00564b00

namespace fnv_00564eb0 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct TESObjectREFR_Flags
{
    void SetFlags(unsigned int);
    void FUN_00564eb0(bool set);
};

}  // namespace fnv_00564eb0

namespace fnv_00567ad0 {
struct ExtraL
{
    void FUN_00419700(void*);
};
struct ShellH
{
    void FUN_00419700(void*);
};
struct Flt
{
    operator unsigned int();
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct RadioData : Flt
{
};
struct FUN_00567ad0 : TESObjectREFR
{
    void SetOwner(void* apOwner);
    ShellH* GetExtra() const;
    RadioData* GetExtraRadioData();
    // slot 0 is TESObjectREFR::~TESObjectREFR (made virtual by 71bb6ecefd)
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048(unsigned int);
};

}  // namespace fnv_00567ad0

namespace fnv_00569000 {
struct Flt
{
    operator unsigned int();
};
struct TgtOps
{
    void* GetSourceFiles();
};
struct NiPoint3
{
    float x, y, z;
};
extern NiPoint3 _NiPoint3_ZERO;
struct TESObjectREFR_ext : TESObjectREFR
{
    void* GetExtraRadioData();
    void* FUN_00569000();
};
}  // namespace fnv_00569000

namespace fnv_005690a0 {
struct LockExtraData;
struct FUN_00411b00
{
    FUN_00411b00();
    ~FUN_00411b00();
    int a, b, c, d, e;
};
struct ShellH
{
    void FUN_00419050(LockExtraData*);
};
struct XActor
{
    ShellH* GetExtra() const;
};
struct TESObjectREFR_ext
{
    LockExtraData* GetMyLock();
    LockExtraData* FUN_005690a0();
};
}  // namespace fnv_005690a0

namespace fnv_0056aa10 {
struct FUN_0056aac0_t
{
    TESObjectREFR* GetEnableParent();
};
struct XActor
{
    void* GetExtra() const;
};
struct FUN_0041dda0_shell
{
    void FUN_0041dda0(TESObjectREFR*);
};
struct FUN_0041da40_shell
{
    void FUN_0041da40(TESObjectREFR*);
};
struct FUN_0056aa10_t
{
    void FUN_0056aa10(TESObjectREFR* apParent);
};
struct RefPersists
{
    bool GetReferencePersistence();
};
}  // namespace fnv_0056aa10

struct FUN_0056c780_t
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    void FUN_0056c780(bool value);
};

namespace fnv_0056c810 {
struct GO
{
    int m_i;
    GO(int v);
    ~GO();
};
struct FUN_0057c590_Class
{
    void FUN_0057c590(GO* p);
};
struct FUN_0056c810_Class
{
    char m_bPad[0xd0];
    FUN_0057c590_Class m_oNode;
    void FUN_0056c810(int v);
};
}  // namespace fnv_0056c810

struct bhkConvexShape
{
    bhkConvexShape();
    ~bhkConvexShape();
    void FUN_0056e810(unsigned int);
};

struct FUN_0056e610 : bhkConvexShape
{
    FUN_0056e610(unsigned int);
};

extern int DAT_0126825c;

namespace fnv_005726e0 {
struct NiAVObject
{
    void SetAppCulled(bool);
};
struct SceneObjectLookup
{
    static NiAVObject* __cdecl GetObjectByName(NiAVObject*, const char*);
};
extern const char str_01030e48[];
extern const char str_01030e54[];
struct FUN_005726e0_shell
{
    void FUN_005726e0(NiAVObject* a, bool b);
};
}  // namespace fnv_005726e0

namespace fnv_00572820 {
struct ReferenceLightData;
struct BSExtraData;
struct ShellH;
struct XActor
{
    ShellH* GetExtra() const;
};
struct Holder
{
    ReferenceLightData* FUN_00418250();
};
struct FUN_00418280_Class
{
    BSExtraData* FUN_00418280();
};
struct _FNV_GetObjectReference_Class
{
    void* _FNV_GetObjectReference();
};
struct _FNV_GetFormType_Class
{
    int _FNV_GetFormType();
};
struct FUN_0050de20_Class
{
    void FUN_0050de20(void* a, int b);
};

struct FUN_00572820_Class
{
    void FUN_00572820();
};

}  // namespace fnv_00572820

namespace fnv_005754a0 {
struct FUN_00740960_Class
{
    unsigned int FUN_00740960();
};
extern FUN_00740960_Class* g_dataHandler;
struct TESContainer;
struct TESObjectREFR;
struct InventoryChanges
{
    static InventoryChanges* __cdecl CreateForReference(TESObjectREFR*);
    void* FUN_004c94f0(int);
};
TESContainer* __fastcall FUN_0055d310(TESObjectREFR*);
struct FUN_005754a0_Class
{
    void* FUN_005754a0(int a1, unsigned char a2);
};
}  // namespace fnv_005754a0

bool __fastcall FUN_00579200(char const*);
class Character;
struct TESTopicInfo
{
    void AddTopicList();
    void RunResultScript(int, Character*);
};
struct FUN_0083c850
{
    int m0;
    int m4;
    int m8;
    TESTopicInfo* mInfo;
    int m10;
    int m14;
    int m18;
    void AppendTopicInfo(int);
};

struct FUN_0087f920_pos
{
    float x;
    float y;
    float z;
};
struct FUN_0087f920_rot
{
    float x;
    float y;
    float z;
};
struct FUN_0087f920_t
{
    unsigned char m_auiShapeKeys[0x160];
    FUN_0087f920_pos m_pos;
    float m_vScale;
    void* m_obj;
    bool FUN_0087f920(FUN_0087f920_pos* apPos, FUN_0087f920_rot* apRot, void** apObj, int aiUnused);
};

namespace fnv_008cfa40 {
struct NiFixedString
{
    const char* m_sString;
    NiFixedString(const char* s) : m_sString(s)
    {}
    ~NiFixedString();
};
struct BSFadeNode
{
    NiFixedString m_sName;
    BSFadeNode(const char* name) : m_sName(name)
    {}
};
struct NiAVObject
{
    void SetName(const NiFixedString&);
};
struct FUN_009335b0_cls
{
    NiAVObject* FUN_009335b0(unsigned char);
    NiAVObject* FUN_008cfa40(unsigned char a);
};
}  // namespace fnv_008cfa40

namespace fnv_00578250 {
struct NiAVObject
{
    virtual ~NiAVObject();
    virtual void v1();
    virtual void v2();
    virtual NiAVObject* GetAsNiNode();
};
struct BSAudio
{
    static BSAudio* GetSingleton();
    void FUN_00ad8570(NiAVObject*, float, int);
};
struct FUN_00570ee0_class
{
    bool FUN_00570ea0();
};
struct FUN_00578250_class
{
    unsigned int GetNumChildren();
    NiAVObject* GetAt(unsigned int);
};
char FUN_00578250(NiAVObject* object);
}  // namespace fnv_00578250

class PointerFlagNode;

struct FUN_00416b80
{
    unsigned char bytes[20];
    FUN_00416b80();
};

struct LH
{
    bool IsInList(int& value);
};

struct G2
{
    void AddHead(int* value);
};

struct FUN_004207e0Class
{
    PointerFlagNode* FUN_004207e0();
};

struct FUN_00420ce0Class : public FUN_004207e0Class
{
    void FUN_00420440(FUN_00416b80* value);
    void FUN_00420ce0(int value);
};

namespace fnv_0055ac90 {
struct TESBoundObject;

struct FUN_004121b0_shell
{
    bool FUN_004121b0();
};

struct BGSSaveLoadGame : public FUN_004121b0_shell
{
};

struct FUN_0057c300_cls
{
    void FUN_0057c300();
};

struct FUN_0055ac90_class : public FUN_0057c300_cls
{
    void FUN_0055ac90();
};

void* memset(void* destination, int value, unsigned int count);

extern float _DAT_01015f5c;
extern BGSSaveLoadGame* g_BGSSaveLoadGame;

}  // namespace fnv_0055ac90

struct NiNode;
struct NiRTTI;
struct NiControllerManager;

struct Model
{
    NiNode* GetObject3D(void);
};

struct P09H
{
    Model* GetReferenceType(void);
};

extern NiRTTI DAT_011f36ac;
unsigned short __cdecl FUN_0055fdb0(NiControllerManager*);
void* __cdecl _UseSaveGameBlocks(NiRTTI*, void*);

struct FUN_0055f880_cls
{
    unsigned short FUN_0055f880();
};

class NiFixedStr
{
  public:
    operator char const*();
};

class SeqObj
{
  public:
    NiFixedStr& GetName();
};

class FUN_004efb10_shell : public SeqObj
{
  public:
    unsigned short FUN_004efb10();
};

class Idle_008b2010 : public FUN_004efb10_shell
{
  public:
    Idle_008b2010* GetState();
};

class AnimationInterpolatorNode
{
  public:
    bool FUN_004f05a0();
    unsigned int FUN_00495d00();
    Idle_008b2010* FUN_00495d20(unsigned int index);
};

int _BSStringLength(char const* string);

namespace fnv_005609b0 {
struct ScriptLocalsX
{
    void* GetLocalData(void);
};

struct FUN_005609f0_shell
{
    bool FUN_005609f0(void);
};

struct hkpEntity
{
    FUN_005609f0_shell* FUN_00c9bff0(unsigned char* flag);
};

struct bhkRigidBody
{
    bool FUN_005609b0();
};

}  // namespace fnv_005609b0

namespace fnv_00562140 {
struct FormChangeMask
{
    unsigned int value;

    operator bool() const;
};

struct FormChangeRecord
{
    void FUN_005621f0(unsigned int flags);
};

struct BGSLoadFormBuffer : FormChangeRecord
{
    FormChangeMask GetChangeFlags(unsigned int flags);
};

struct BGSSaveFormBuffer : BGSLoadFormBuffer
{
};

struct TESForm
{
    virtual void V00()
    {}
    virtual void V01()
    {}
    virtual void V02()
    {}
    virtual void V03()
    {}
    virtual void V04()
    {}
    virtual void V05()
    {}
    virtual void V06()
    {}
    virtual void V07()
    {}
    virtual void V08()
    {}
    virtual void V09()
    {}
    virtual void V10()
    {}
    virtual void V11()
    {}
    virtual void V12()
    {}
    virtual void V13()
    {}
    virtual void V14()
    {}
    virtual void V15()
    {}
    virtual void V16()
    {}
    virtual void V17()
    {}
    virtual void V18()
    {}
    virtual void V19()
    {}
    virtual void V20()
    {}
    virtual void V21()
    {}
    virtual void V22()
    {}
    virtual void V23()
    {}
    virtual void V24()
    {}
    virtual void V25()
    {}
    virtual void V26()
    {}
    virtual void V27()
    {}
    virtual void V28()
    {}
    virtual void V29()
    {}
    virtual void V30()
    {}
    virtual void V31()
    {}
    virtual void V32()
    {}
    virtual void V33()
    {}
    virtual void V34()
    {}
    virtual void V35()
    {}
    virtual void V36()
    {}
    virtual void V37()
    {}
    virtual void V38()
    {}
    virtual void V39()
    {}
    virtual void V40()
    {}
    virtual void V41()
    {}
    virtual void V42()
    {}
    virtual void V43()
    {}
    virtual void V44()
    {}
    virtual void V45()
    {}
    virtual void V46()
    {}
    virtual void V47()
    {}
    virtual void V48()
    {}
    virtual void V49()
    {}
    virtual void V50()
    {}
    virtual void V51()
    {}
    virtual void V52()
    {}
    virtual void V53()
    {}
    virtual void V54()
    {}
    virtual void V55()
    {}
    virtual void V56()
    {}
    virtual void V57()
    {}
    virtual void V58()
    {}
    virtual void V59()
    {}
    virtual void V60()
    {}
    virtual void V61()
    {}
    virtual void V62()
    {}
    virtual void V63()
    {}
    virtual unsigned char V64()
    {
        return 0;
    }

    void Revert(unsigned int flags);
};

struct P09H : TESForm
{
    int GetReferenceType();
};

struct FUN_00562140_cls : P09H
{
    void FUN_00562140(BGSSaveFormBuffer* saveGameBuffer);
};

unsigned char __fastcall FUN_00563530(P09H* object);

struct FUN_005621d0_shell
{
    bool FUN_005621d0();
};

struct BGSSaveLoadGame : FUN_005621d0_shell
{
};

extern BGSSaveLoadGame* g_BGSSaveLoadGame;

}  // namespace fnv_00562140

namespace fnv_00563650 {
struct NiRTTI
{
};

extern NiRTTI DAT_011f36ac;

struct NiObject
{
};

struct NiNode
{
};

struct NiAVObject : public NiNode
{
};

struct Model
{
    NiNode* GetObject3D();
};

struct NiControllerManager : public Model
{
};

struct P09H
{
    int GetReferenceType();
};

struct XActor
{
    void* GetExtra() const;
};

struct BGSSaveGameBuffer
{
    void SaveGameString(char const* value, int flag);
};

struct BGSSaveFormBuffer : public BGSSaveGameBuffer
{
};

struct FUN_004228f0_Class
{
    char* FUN_004228f0();
};

char* _UseSaveGameBlocks(NiRTTI* rtti, void* object);
void FUN_00563f30(char* data, BGSSaveFormBuffer* buffer, float value);

struct FUN_00563650_Class : public TESObjectREFR
{
    void FUN_00563650(BGSSaveFormBuffer* apSaveGameBuffer);
};

}  // namespace fnv_00563650

namespace fnv_00563f30 {
struct BGSSaveFormBuffer;

struct FUN_004efc90_shell
{
    void FUN_004efc90(BGSSaveFormBuffer* buffer, float value);
};

struct NiFixedStr
{
    operator char const*();
};

struct SeqObj : public FUN_004efc90_shell
{
    NiFixedStr& GetName();
};

struct Idle_008b2010 : public SeqObj
{
    Idle_008b2010* GetState();
};

struct AnimationInterpolatorNode
{
    bool FUN_004f05a0();
    unsigned int FUN_00495d00();
    Idle_008b2010* FUN_00495d20(int index);
};

struct BGSSaveGameBuffer
{
    void SaveGameString(char const* value, int flag);
};

struct BGSSaveFormBuffer : public BGSSaveGameBuffer
{
    unsigned int FUN_00865f20();
    void FUN_00865ff0(int value, unsigned int count);
};

float DAT_011c3c08;

}  // namespace fnv_00563f30

enum ENUM_FORM_ID
{
    ENUM_FORM_ID_DUMMY = 0
};

struct FUN_004fd4f0_Class
{
    int FUN_004fd4f0();
};

struct BGSProjectile : public FUN_004fd4f0_Class
{
    BGSProjectile* _FNV_GetObjectReference();
    int _FNV_GetFormType();
};

struct FUN_00564820_Class : public BGSProjectile
{
    ENUM_FORM_ID FUN_00564820();
};

namespace fnv_00564f40 {
class BSExtraData
{
  public:
    virtual ~BSExtraData()
    {}
    unsigned char pad[0x10];
};

class BaseExtraList
{
  public:
    BSExtraData* AddExtra(BSExtraData* extra);
    void RemoveExtra(unsigned int type);
};

class MagicCaster
{
  public:
    void SetSelectedMagicItem(int spell);
};

int __fastcall _ref_0084e3a0(void* object);

class XActor : public TESObjectREFR
{
  public:
    BSExtraData* GetExtraData(unsigned char type) const;
    void* GetExtra() const;

    // slot 0 is TESObjectREFR::~TESObjectREFR (made virtual by 71bb6ecefd)
    virtual void VirtualMethod1()
    {}
    virtual void VirtualMethod2()
    {}
    virtual void VirtualMethod3()
    {}
    virtual void VirtualMethod4()
    {}
    virtual void VirtualMethod5()
    {}
    virtual void VirtualMethod6()
    {}
    virtual void VirtualMethod7()
    {}
    virtual void VirtualMethod8()
    {}
    virtual void VirtualMethod9()
    {}
    virtual void VirtualMethod10()
    {}
    virtual void VirtualMethod11()
    {}
    virtual void VirtualMethod12()
    {}
    virtual void VirtualMethod13()
    {}
    virtual void VirtualMethod14()
    {}
    virtual void VirtualMethod15()
    {}
    virtual void VirtualMethod16()
    {}
    virtual void VirtualMethod17()
    {}
    virtual void VirtualMethod18(unsigned int value)
    {}

    void FUN_00564f40(unsigned char value);
};

struct FUN_00411e40 : BSExtraData
{
    FUN_00411e40();
};

}  // namespace fnv_00564f40

namespace fnv_00565480 {
struct TESObjectCELL
{
    bool IsInterior();
};

struct DoorH : public TESObjectCELL
{
    void* GetParentWorldSpace();
};

struct CellH : public DoorH
{
    bool IsCellPersistent();
};

struct ArrSI
{
    unsigned int GetFlags();
    void SetFlags(unsigned int flags);
};

struct FUN_00588030_shell
{
    void FUN_00588030(TESObjectREFR* object);
};

struct TESWorldSpace : public FUN_00588030_shell
{
    void AddPersistentReference(TESObjectREFR* object);
};

struct CellInterface
{
    virtual CellH* GetContainingCell() = 0;
};

struct RefPersistsStandin
{
// @fnv 0x00565480
    virtual void FUN_00565480_v00()
    {}
    virtual void FUN_00565480_v01()
    {}
    virtual void FUN_00565480_v02()
    {}
    virtual void FUN_00565480_v03()
    {}
    virtual void FUN_00565480_v04()
    {}
    virtual void FUN_00565480_v05()
    {}
    virtual void FUN_00565480_v06()
    {}
    virtual void FUN_00565480_v07()
    {}
    virtual void FUN_00565480_v08()
    {}
    virtual void FUN_00565480_v09()
    {}
    virtual void FUN_00565480_v10()
    {}
    virtual void FUN_00565480_v11()
    {}
    virtual void FUN_00565480_v12()
    {}
    virtual void FUN_00565480_v13()
    {}
    virtual void FUN_00565480_v14()
    {}
    virtual void FUN_00565480_v15()
    {}
    virtual void FUN_00565480_v16()
    {}
    virtual void FUN_00565480_v17()
    {}
    virtual void FUN_00565480_v18(int)
    {}
    virtual void FUN_00565480_v19()
    {}
    virtual void FUN_00565480_v20()
    {}
    virtual void FUN_00565480_v21()
    {}
    virtual void FUN_00565480_v22()
    {}
    virtual void FUN_00565480_v23()
    {}
    virtual void FUN_00565480_v24()
    {}
    virtual void FUN_00565480_v25()
    {}
    virtual void FUN_00565480_v26()
    {}
    virtual void FUN_00565480_v27()
    {}
    virtual void FUN_00565480_v28()
    {}
    virtual void FUN_00565480_v29()
    {}
    virtual void FUN_00565480_v30()
    {}
    virtual void FUN_00565480_v31()
    {}
    virtual void FUN_00565480_v32()
    {}
    virtual void FUN_00565480_v33()
    {}
    virtual void FUN_00565480_v34()
    {}
    virtual void FUN_00565480_v35()
    {}
    virtual void FUN_00565480_v36()
    {}
    virtual void FUN_00565480_v37()
    {}
    virtual void FUN_00565480_v38()
    {}
    virtual void FUN_00565480_v39()
    {}
    virtual void FUN_00565480_v40()
    {}
    virtual void FUN_00565480_v41()
    {}
    virtual void FUN_00565480_v42()
    {}
    virtual void FUN_00565480_v43()
    {}
    virtual void FUN_00565480_v44()
    {}
    virtual void FUN_00565480_v45()
    {}
    virtual void FUN_00565480_v46()
    {}
    virtual void FUN_00565480_v47()
    {}
    virtual void FUN_00565480_v48()
    {}
    virtual void FUN_00565480_v49()
    {}
    virtual void FUN_00565480_v50(int)
    {}

    void FUN_00565480(bool abVal);
};

}  // namespace fnv_00565480

namespace fnv_005678a0 {
struct TESForm
{
};

struct TESFaction : public TESForm
{
    bool FUN_0047d7c0();
};

struct TESNPC : public TESForm
{
};

struct TESBoundObject : public TESForm
{
};

struct TESActorBaseData
{
    bool GetGhostFlag();
};

struct BeamEffect
{
    TESForm* FUN_00567790();
};

unsigned int __fastcall _FNV_GetFormType(TESForm* form);
TESBoundObject* __fastcall _FNV_GetObjectReference(void* self);

struct VirtualObject
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
    virtual TESBoundObject* GetBaseObject();
};

struct FUN_005678a0_Class
{
    bool FUN_005678a0();
};

}  // namespace fnv_005678a0

namespace fnv_00567f40 {
struct Actor
{
};

struct ActorCause
{
};

class XActor
{
  public:
    void* GetExtra(void) const;
};

struct FUN_0042e930_class
{
    void FUN_0042e930(Actor* actor);
};

struct FUN_00567f40_class
{
    virtual void f00()
    {}
    virtual void f01()
    {}
    virtual void f02()
    {}
    virtual void f03()
    {}
    virtual void f04()
    {}
    virtual void f05()
    {}
    virtual void f06()
    {}
    virtual void f07()
    {}
    virtual void f08()
    {}
    virtual void f09()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual ActorCause* f18(unsigned int value)
    {
        return 0;
    }

    ActorCause* FUN_00567f40(Actor* actor);
};

}  // namespace fnv_00567f40

namespace fnv_00568e70 {
struct ExtraRadioData
{
    unsigned char data[0x20];
};

struct FUN_0043a160
{
    unsigned char data[0x20];

    FUN_0043a160()
    {}
};

struct ExtraDataList
{
    ExtraRadioData* GetExtraRadioData();
    void FUN_00419120(ExtraRadioData* radioData);
};

struct XActor
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18(unsigned int value)
    {}

    void* GetExtra() const;
    ExtraRadioData* FUN_00568e70();
};

}  // namespace fnv_00568e70

namespace fnv_00569990 {
struct XActor
{
    void* GetExtra(void) const;
};

struct ExtraData
{
    void FUN_00422050(int value);
};

struct TargetClass : public XActor
{
    void FUN_00569990();
};

}  // namespace fnv_00569990

namespace fnv_00569ae0 {
struct FUN_00439f90_shell : public TESObjectREFR
{
    bool FUN_00439f90();
};

struct FUN_00421e40_shell
{
    void FUN_00421e40(TESObjectREFR* object);
};

struct XActor
{
    void* GetExtra() const;
    void FUN_00569ae0(FUN_00439f90_shell* object);
};

}  // namespace fnv_00569ae0

namespace fnv_0056a470 {
class NiPoint3;

struct FUN_0041f080_cls
{
    void FUN_0041f080(TESObjectREFR* object, NiPoint3 const& point1, NiPoint3 const& point2);
};

struct XActor
{
    void* GetExtra(void) const;
    void FUN_0056a470(TESObjectREFR* object, NiPoint3 const& point1, NiPoint3 const& point2);
};

}  // namespace fnv_0056a470

struct P3
{
    float x;
    float y;
    float z;

    void Set(float, float, float);
};

struct NiPoint3 : public P3
{
    void ComputeMagnitude();
};

struct ThreeByThreeMatrix
{
    float matrix[9];

    void _ref_006815c0();
    void FUN_004a0c90(float);
    NiPoint3 operator*(NiPoint3 const&) const;
};

struct RecipeCraftingInfo
{
    float field00;
    float field04;
    float field08;
};

struct TESRecipe
{
    RecipeCraftingInfo* GetData();
    NiPoint3* FUN_00572500(NiPoint3*, float);
};

float __cdecl WrapAngle(float);

namespace fnv_00572770 {
extern unsigned int _data_011c16bc;
void FUN_00418f60();

struct GO
{
  public:
    unsigned char pad;
    float value;

    void operator=(void* value);
};

struct FUN_005726c0 : public GO
{
  public:
    FUN_005726c0();
};

struct ExtraData
{
  public:
    void FUN_00418f60();
};

struct XActor
{
  public:
    ExtraData* GetExtra(FUN_005726c0* object) const;
    void FUN_00572770(void* value);
};

}  // namespace fnv_00572770

namespace fnv_00573050 {
struct BGSBodyPart
{
    enum LIMB_ENUM
    {
        LIMB_HEAD = 0
    };
};

struct ExtraDismemberedLimbs
{
    void FUN_004305f0(int limb, bool removed);
};

struct ExtraDataList
{
    ExtraDismemberedLimbs* GetDismemberedLimbs();
};

struct XActor
{
    void* GetExtra() const;
    void FUN_00573050(BGSBodyPart::LIMB_ENUM aeLimb, bool abRemoved);
};

}  // namespace fnv_00573050

namespace fnv_00573110 {
struct BGSBodyPart
{
    enum LIMB_ENUM
    {
        LIMB_ENUM_NONE = 0
    };
};

class Calendar
{
  public:
    int GetDaysPassed();
};

class ExtraDismemberedLimbs : public Calendar
{
};

class ExtraDataList
{
  public:
    ExtraDismemberedLimbs* GetDismemberedLimbs();
};

class XActor
{
  public:
    void* GetExtra() const;
};

struct FUN_00573110_shell : public XActor
{
  public:
    BGSBodyPart::LIMB_ENUM FUN_00573110();
};

}  // namespace fnv_00573110

namespace fnv_00577c40 {
struct ScriptLocalsX
{
    void* GetLocalData();
    void FUN_00577c40(float value);
};

struct FUN_00577c70_stand_in
{
    void FUN_00577c70(float value);
};

}  // namespace fnv_00577c40

namespace fnv_00577c70 {
class TgtOps
{
  public:
    void* GetSourceFiles();
};

typedef TgtOps BSSimpleList_Ragdoll;

class TESDataHandler
{
  public:
    BSSimpleList_Ragdoll* GetBGSRagdollList();
};

class Dummy_00577bd0 : public TESDataHandler
{
  public:
    void FUN_00ca9360(float* value);
    void FUN_00577c70(float value);
};

}  // namespace fnv_00577c70

namespace fnv_00578870 {
struct BSStr
{
    bool Set(char const* value, unsigned int length);
};

struct FNStub
{
    char* GetFullName();
};

struct TESObjectCELL
{
    unsigned char padding[0x18];
    FNStub fnStub;

    bool IsInterior();
};

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct TESWorldSpaceVirtualBase
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

    virtual void vfn_138(BSStr* name, NiPoint3 position) = 0;
};

struct TESWorldSpace : public TESWorldSpaceVirtualBase
{
};

struct BSOcclusionPlane
{
    int GetCullResult() const;
};

struct ActorS
{
    TESWorldSpace* GetParentWorldSpace();
};

struct TESObjectREFRVirtualBase
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

    virtual NiPoint3* vfn_1f4() = 0;
};

struct FUN_00578870_Class : public TESObjectREFRVirtualBase
{
    void FUN_00578870(BSStr& aOutMapName);
};

extern char $SG3295[];

}  // namespace fnv_00578870

struct FUN_004ff070_Class
{
    void FUN_004ff070();
};

struct FUN_00578950_Class
{
    void* _FNV_GetObjectReference(void* object);
    void FUN_00578950();
};

void _Deallocate(void*);

struct ExtraAnimNoteReceiver
{
    void FUN_0057a8d0();
    void* FUN_0057a8a0(unsigned int flags);
};

namespace fnv_0057b790 {
struct TESObjectCELL;

class TES
{
  public:
    bool IsCellBuffered(TESObjectCELL* cell, bool force);
};

extern int g_TES;

struct FUN_0057b790_StandIn
{
    char padding[0x40];
    TESObjectCELL* cell;

    bool FUN_0057b790();
};

}  // namespace fnv_0057b790

// FUN_00413f90: thiscall member, one stack argument.
// Copies the 16-byte value struct stored at this+8 into *pOut and returns pOut.
struct FUN_00413f90_vec
{
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    int m_w;
};

struct FUN_00413f90_cls
{
    int m_i00;
    int m_i04;
    FUN_00413f90_vec m_v08;
    FUN_00413f90_vec* FUN_00413f90(FUN_00413f90_vec* pOut);
};

struct HealthExtras
{
    float FUN_0041b6b0();
};
struct HealthReference
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void* GetTarget();
    HealthExtras* FUN_005d43c0();
};
struct HealthEntry
{
    unsigned char value, threshold;
};
struct HealthTable
{
    unsigned scale;
    unsigned char count;
};
struct HealthHandler
{
    int unk00;
    HealthTable* table;
    HealthEntry* FUN_00476a40(unsigned);
    bool FUN_00476f50(HealthReference*, bool);
};
float __cdecl FUN_00476b20(float);
void __cdecl FUN_00476ec0(void*, unsigned);

struct TESObjectCELL;
struct Pt3
{
    float x;
    float y;
    float z;
    Pt3();
};
struct RefX
{
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual Pt3* GetPos();
    RefX();
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
    TESObjectCELL* GetParentCell();
    void SetLocationOnReference(const Pt3&);
    void FUN_00575690(void*);
    void* GetAcousticSpace();
    void FUN_00567ad0(void*);
};
extern RefX* g_thePlayer;
extern void* DAT_011c3f40;
struct TESObjectCELL
{
    void FUN_0054d090(Pt3*, Pt3*);
    void FUN_005512f0(RefX*);
    void AddReference(RefX*, bool);
    RefX* FUN_00551180(RefX* ref);
};

struct SaveLoadStub
{
    bool IsLoading();
};
extern SaveLoadStub* g_BGSSaveLoadGame;

struct ExtraStub
{
};
struct CellStub
{
};

struct ExtraListStub
{
    ExtraStub* GetExtraData(unsigned char type);
    void Remove(ExtraStub* extra, bool free);
    ExtraStub* AddExtra(ExtraStub* extra);
};

struct ExtraList44
{
    CellStub* GetContainingCell();
    void SetA(bool b);
    void SetB(bool b);
    void InitializeForCell(CellStub* c);
};

struct RefStub
{
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
    virtual void v00A();
    virtual void v00B();
    virtual void v00C();
    virtual void v00D();
    virtual void v00E();
    virtual void v00F();
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
    virtual void v01A();
    virtual void v01B();
    virtual void v01C();
    virtual void v01D();
    virtual void v01E();
    virtual void v01F();
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
    virtual void v02A();
    virtual void v02B();
    virtual void v02C();
    virtual void v02D();
    virtual void v02E();
    virtual void v02F();
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
    virtual void v03A();
    virtual void v03B();
    virtual void v03C();
    virtual void v03D();
    virtual void v03E();
    virtual void v03F();
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
    virtual void v04A();
    virtual void v04B();
    virtual void v04C();
    virtual void v04D();
    virtual void v04E();
    virtual void v04F();
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
    virtual void v05A();
    virtual void v05B();
    virtual void v05C();
    virtual void v05D();
    virtual void v05E();
    virtual void v05F();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06A();
    virtual void v06B();
    virtual void v06C();
    virtual void v06D();
    virtual void v06E();
    virtual void v06F();
    virtual void v070();
    virtual void v071();
    virtual void v072();
    virtual void Update(int a, int b);
    virtual int HasFlag();
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
    ExtraList44 extraList;

    void Func56b0b0();
    void Func572a50(int a);
    void Func57b520(int a);
    ExtraListStub* GetExtraList();
    void FUN_0055ad20();
};

extern unsigned int kGroupFormType;

struct GroupForm
{
    unsigned int type;
    int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

class FUN_00485b60
{
  public:
    bool FUN_00485be0(unsigned int);

  public:
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
    virtual bool Handle(GroupForm*, bool, bool);
};

class Holder18
{
  public:
    virtual FUN_00485b60* Get();
};

class Owner55e
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Holder18 sub18;
    bool Check5653d0();
    bool FUN_0055e4d0(GroupForm* form, bool b1, bool b2);
};

struct FUN_0055f5b0_Class
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

    bool __thiscall FUN_0055f5b0();
};

struct Rec5604
{
    char pad00[2];
    unsigned short w02;
    unsigned short w04;
};

struct Loc5604
{
    int unk00;
    unsigned char flag04;
    int kind08;
    void* target0c;
    int unk10;
    int unk14;
    int unk18;
};

struct FUN_005604b0_cls
{
    void* FUN_0043fcd0();
    void FUN_00484ce0(const void* a, int b);
    void FUN_005604b0(const Rec5604* p);
};

int FUN_00c68900(void* p, Loc5604* loc, void (*fn)());
void FUN_00560a10();

struct Inner560
{
    void* Method();
};

struct FUN_00560e10_cls
{
    Inner560* Lookup();
    void* FUN_00560e10();
};

void* FUN_00458b20();

// FUN_00560e50 : thiscall member; chains a thiscall helper twice.
class FUN_00560e50_cls
{
  public:
    FUN_00560e50_cls* Helper();
    void FUN_00560e50();
};

namespace fnv_00561b40 {
struct RttiX;
struct FixStr
{
    operator const char*() const;
};
struct AvObj
{
    FixStr& GetName();
};
struct Mat33
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct Pt3
{
    float x, y, z;
    Pt3();
};
struct QuatX
{
    float w, x, y, z;
    QuatX();
    void FUN_00a6df40(const Mat33& m);
};
struct WorldObjX;
struct CtrlX
{
    void FUN_005610f0(Pt3* p);
    void FUN_00561150(QuatX* q);
    void FUN_005615d0(Pt3* p);
    void FUN_00561630(Pt3* p);
    void FUN_00561580(bool b);
};
struct HolderX
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool IsB100();
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
    virtual Pt3* Get1F4();
    Mat33 FUN_0056fa00();
};
struct RefX
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void SetFlagsB0(int a, int b, int c);
    WorldObjX* FUN_006fa820();
    void FUN_004d9fa0(bool b);
    AvObj* Get3D();
};
struct InfoX
{
    int unk00;
    int unk04;
    int unk08;
    RefX* unk0c;
    HolderX* unk10;
    unsigned int unk14;
};
struct SaveLoadX
{
    unsigned char FUN_008df040();
    void FUN_008579e0(void* buf, unsigned int size);
};
extern SaveLoadX* g_TESSaveLoadGame;
extern RttiX DAT_011f9140;
extern RttiX DAT_012681c0;
extern Pt3 NiPoint3_ZERO;
int FUN_00408b20(const char* a, const char* b);
bool FUN_0043b300(const RttiX* rtti, AvObj* obj);
CtrlX* FUN_00653270(const RttiX* rtti, WorldObjX* obj);

}  // namespace fnv_00561b40

struct WorldPoint
{
    float x, y, z;
    void FUN_006815c0();
};
struct ReferenceObject
{
    bool FUN_00425fd0();
};
struct SecondaryObject
{
    ReferenceObject* FUN_00587550(WorldPoint*);
};
struct SearchTable
{
    bool FUN_004511e0(ReferenceObject*, int);
};
extern SearchTable* DAT_011dea10;
void __cdecl FUN_00846190(void*, ReferenceObject**, SecondaryObject**);
void __cdecl FUN_00573800(void*, ReferenceObject*, SecondaryObject*);

struct WorldReference
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
    virtual bool v78(WorldPoint*, WorldPoint*, void**, int);
    bool FUN_005653d0();
    void FUN_00575830(WorldPoint*);
    void FUN_00575700(WorldPoint);
    void FUN_00562020();
    bool FUN_00561ef0(int);
};

struct SettingsHolder
{
    unsigned char flags;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void* m_10;
    void* m_14;
    void* m_18;
};

struct CallbackDesc
{
    unsigned int unk00;
    unsigned char bFlag;
    unsigned int nValue;
    SettingsHolder* pOwner;
};

void* __cdecl FUN_004a8b00(void* p);
void __cdecl FUN_00c68900(void* p, CallbackDesc* pDesc, void (*pfn)());
void FUN_00563120();

struct FUN_00562d20_cls
{
    int unk00;
    void* FUN_0043fcd0();

    void FUN_00562d20(SettingsHolder* pHolder);
};

namespace fnv_00562ed0 {
struct NiPt3X
{
    float x;
    float y;
    float z;
};
extern const NiPt3X NiPoint3_ZERO;

struct UpdDataX
{
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    unsigned char m_ucEntryType;
    int unk08;
    UpdDataX(float afTime, bool abUpdateControllers, bool abMultiThreaded);
};

struct NiNode;
struct NiCollisionObject;
struct CollisionObjectCountContext
{
    int iCount;
    bool bFlag;
    int iType;
    void* pData;
    int unk10;
    int unk14;
    int unk18;
};

struct AVObjX
{
    void Update(UpdDataX& arData);
};

void __cdecl FUN_00c9b670(AVObjX*, const NiPt3X*, bool, float, int);
void __cdecl FUN_00c6a350(AVObjX*, int, bool, bool, bool);
void __cdecl FUN_00c68900(AVObjX*, CollisionObjectCountContext*,
                          void(__cdecl*)(NiCollisionObject*, CollisionObjectCountContext*));
void __cdecl FUN_00563380(NiCollisionObject*, CollisionObjectCountContext*);
void __cdecl FUN_00845cc0(const char*, ...);

struct BooleanIntegerAccessor
{
    void FUN_00864980(bool* apOut, int aiUnk);
    int FUN_00864a60();
};

struct BoneCountData
{
    unsigned char bFlag;
    int iCount1;
    int iCount2;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    BooleanIntegerAccessor* pSaveData;
    BoneCountData();
};

struct bhkCharController
{
    void FUN_00c7c150(bool);
};

struct RefX
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
    virtual const char* GetName76();
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
    virtual bool V139(bool);
    virtual bool V140();
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
    virtual bool V186();
    AVObjX* Get3DSimple();
    unsigned int GetRefID();
    void FUN_00562d20(BoneCountData* apData);
    void FUN_00562ed0(BooleanIntegerAccessor* apSaveData);
};

struct ActorX : RefX
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
    bhkCharController* pCharCtrl;
    bool FUN_00437bd0();
};

}  // namespace fnv_00562ed0

struct FNVActivationNode_00564b70
{
    virtual void Unknown000() = 0;
    virtual void Unknown004() = 0;
    virtual void Unknown008() = 0;
    virtual void Unknown00c() = 0;
    virtual void Unknown010() = 0;
    virtual void Unknown014() = 0;
    virtual void Unknown018() = 0;
    virtual void Unknown01c() = 0;
    virtual void Unknown020() = 0;
    virtual void Unknown024() = 0;
    virtual void Unknown028() = 0;
    virtual void Unknown02c() = 0;
    virtual void Unknown030() = 0;
    virtual void Unknown034() = 0;
    virtual void Unknown038() = 0;
    virtual void Unknown03c() = 0;
    virtual void Unknown040() = 0;
    virtual void Unknown044() = 0;
    virtual void Unknown048() = 0;
    virtual void Unknown04c() = 0;
    virtual void Unknown050() = 0;
    virtual void Unknown054() = 0;
    virtual void Unknown058() = 0;
    virtual void Unknown05c() = 0;
    virtual void Unknown060() = 0;
    virtual void Unknown064() = 0;
    virtual void Unknown068() = 0;
    virtual void Unknown06c() = 0;
    virtual void Unknown070() = 0;
    virtual void Unknown074() = 0;
    virtual void Unknown078() = 0;
    virtual void Unknown07c() = 0;
    virtual void Unknown080() = 0;
    virtual void Unknown084() = 0;
    virtual void Unknown088() = 0;
    virtual void Unknown08c() = 0;
    virtual void Unknown090() = 0;
    virtual void Unknown094() = 0;
    virtual void Unknown098() = 0;
    virtual void Unknown09c() = 0;
    virtual void Unknown0a0() = 0;
    virtual void Unknown0a4() = 0;
    virtual bool HasState() = 0;
};
struct FUN_00564b70_Class : TESObjectREFR
{
    FNVActivationNode_00564b70* FUN_007af430();
    bool FUN_00564b70();
};

struct FUN_00564c60_cls
{
    void FUN_00564c60(unsigned char flag);
    void FUN_00403550(int flags);
};

void* __fastcall FUN_007af430(FUN_00564c60_cls* self);
int __fastcall FUN_00401170(void* p);
int __fastcall FUN_0044ddc0(FUN_00564c60_cls* self);

struct FlagExtra
{
    int unk00, unk04, unk08, unk0c, unk10;
    FlagExtra();
    unsigned FUN_0084e3a0();
    void FUN_0041fd00(unsigned);
};
struct FlagList
{
    FlagExtra* FUN_0040ff60(FlagExtra*);
    void FUN_00410140(int);
};
struct RefFlags
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
    virtual void Changed(unsigned);
    FlagExtra* FUN_00527080(int);
    FlagList* FUN_005d43c0();
    void FUN_005650d0(unsigned char);
};

struct VSlotObj
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
    virtual void v48(int);
};

struct CalleeHost
{
    void* CallA_005d43c0(int arg);
    void CallA_004198a0();
    void* CallA_00568e50();
    void* CallA_00559450();
};

struct FUN_00567bd0_cls : public VSlotObj
{
    void FUN_00567bd0(unsigned int a1);
};

struct FUN_00568480_kind
{
    int Kind();
};

struct FUN_00568480_cls
{
    FUN_00568480_kind* FUN_007af430();
    void FUN_00568020(unsigned int index, int flag);
    void FUN_00568150(unsigned int index, int flag);
    void FUN_00568480();
};

class TESObjectREFR569;

class Data569;

class ExtraDataList569
{
  public:
    Data569* GetData();
    void SetData(Data569* pkData);
};

Data569* __cdecl CreateData569(TESObjectREFR569* pkRef);

class TESObjectREFR569
{
  public:
    bool IsValid();
    bool IsDeleted() const;
    ExtraDataList569* GetExtraData();
    Data569* FUN_00569920();
};

class Ref5699;

struct LinkedRefNode5699
{
    Ref5699** GetItem();
    LinkedRefNode5699* GetNext();
};

struct LinkedRefData5699
{
    int unk00;
    int unk04;
    LinkedRefNode5699 list;
};

struct XList5699
{
    bool HasLinkedRefSlot();
    Ref5699* GetLinkedRefChild();
    void SetLinkedRefChild(Ref5699* ref);
    LinkedRefData5699* GetLinkedRefData();
    void AddLinkedRefParent(Ref5699* ref);
};

Ref5699* __cdecl CreateLinkedRefChild5699(Ref5699* ref);

class Ref5699
{
  public:
    bool IsLinkable();
    bool IsDeleted();
    XList5699* GetExtraList();
    Ref5699* FUN_005699b0();
};

void __fastcall FUN_0041e250(void* p);

struct FUN_00569b40_ref
{
    unsigned char Test();
};

struct FUN_00569b40_cls
{
    void* Find(TESObjectREFR* p);
    void FUN_00569b40(TESObjectREFR* p);
};

struct FUN_00569ba0_Ref
{
    bool __thiscall FUN_005653d0();
};

struct FUN_00569ba0_Extra
{
    void __thiscall FUN_0041e440();
};

struct FUN_00569ba0_Class
{
    FUN_00569ba0_Extra* __thiscall FUN_005d43c0(FUN_00569ba0_Ref* a1);
    void __thiscall FUN_00569ba0(FUN_00569ba0_Ref* a1);
};

struct TemporaryContext
{
    unsigned int unk00, unk04, unk08, unk0C;
    TemporaryContext(unsigned int);
    ~TemporaryContext();
    void FUN_00438af0();
};
struct FUN_00569cb0_Class;
struct NetworkStream
{
    bool FUN_0057c850(FUN_00569cb0_Class* obj, unsigned char* flag);
    void FUN_005594e0(FUN_00569cb0_Class* obj, unsigned char flag);
};
struct NodeEntry
{
    bool FUN_008256d0();
    FUN_00569cb0_Class** FUN_006815c0();
    NodeEntry* FUN_00726070();
};
struct NodeCollection
{
    NodeEntry* FUN_0041e500();
};
struct FUN_00569cb0_Class
{
    FUN_00569cb0_Class* FUN_00569b80();
    void FUN_00569be0(unsigned char flag);
    NodeCollection* FUN_005d43c0();
    void FUN_00569cb0(unsigned char flag, NetworkStream* stream);
};

struct FUN_005653d0_class
{
    bool FUN_005653d0();
};
struct FUN_00421430_class
{
    void FUN_00421430();
};
struct FUN_0056a9b0_shell : TESObjectREFR
{
    FUN_00421430_class* FUN_005d43c0(FUN_005653d0_class*);
    void FUN_0056a9b0(FUN_005653d0_class*);
};

class B56ACB0Ref;

class B56ACB0ExtraList
{
  public:
    void FUN_0041e000(B56ACB0Ref* pkRef);
    void FUN_0041de40(B56ACB0Ref* pkRef);
};

class B56ACB0Ref
{
  public:
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
    virtual void NotifyFormIDChanged(unsigned int uiFlags);
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
    virtual void VFunc0DC();
    virtual void VFunc0E0();
    virtual void VFunc0E4();
    virtual void VFunc0E8();
    virtual void VFunc0EC();
    virtual void VFunc0F0();
    virtual void VFunc0F4();
    virtual void VFunc0F8();
    virtual void VFunc0FC();
    virtual void VFunc100();
    virtual void VFunc104();
    virtual void VFunc108();
    virtual void VFunc10C();
    virtual void VFunc110();
    virtual void VFunc114();
    virtual void VFunc118();
    virtual void VFunc11C();
    virtual void VFunc120();
    virtual void VFunc124();
    virtual void VFunc128();
    virtual void VFunc12C();
    virtual void VFunc130();
    virtual void VFunc134();
    virtual void VFunc138();
    virtual void VFunc13C();
    virtual void VFunc140();
    virtual void VFunc144();
    virtual void VFunc148();
    virtual void VFunc14C();
    virtual void VFunc150();
    virtual void VFunc154();
    virtual void VFunc158();
    virtual void VFunc15C();
    virtual bool IsDeleted();

    bool FUN_005653d0();
    B56ACB0ExtraList* GetExtraData();
};

extern B56ACB0Ref* g_pkB56ACB0Player;

// Argument object whose virtual table slot 0x9c is invoked by FUN_0056d2c0.
struct Arg56d2c0
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
    virtual unsigned char v39(void* pOwner);
};

// Owner class of FUN_0056d2c0.
struct FUN_0056d2c0_cls
{
    unsigned char FUN_0056d2c0(Arg56d2c0* pArg);
};

class FUN_0056d500_cls
{
  public:
    void FUN_00c9d620();
    FUN_0056d500_cls* FUN_0056d500(int nFlag);
};

void __cdecl FUN_00aa1460(FUN_0056d500_cls* pSelf, int nValue);

struct ListHead
{
    void* item;
    void* next;
    ListHead();
};

struct ListTail
{
    void* item;
    ListTail();
    void FUN_005407b0(int value);
};

struct GuardedMember
{
    void* value;
    GuardedMember();
    ~GuardedMember();
};

struct FUN_0056e1e0
{
    ListHead head;
    ListTail tail;
    GuardedMember guarded;
    FUN_0056e1e0();
};

// @fnv 0x0056e1e0
FUN_0056e1e0::FUN_0056e1e0()
{
    head.item = 0;
    head.next = 0;
    tail.FUN_005407b0(1);
}

// FUN_0056e3e0: constructor-like member that calls the base routine with
// `this`, installs the class vtable pointer into the object and bumps a
// global counter, then returns itself.

extern int DAT_0103078c;
extern int DAT_01268238;

struct FUN_0056e3e0_cls
{
    void* m_pVTable;
    void FUN_0056d440();
    FUN_0056e3e0_cls* FUN_0056e3e0();
};

// FUN_0056e460 : thiscall member (1 stack param), /Od.
// Calls a member helper on this, then when the flag param has bit 0 set it
// hands this plus size 0x18 to the cdecl helper, and returns this.

void __cdecl FUN_00aa1460(void* pObject, unsigned int uSize);

struct FUN_0056e460_cls
{
    void FUN_00c9eb30();
    void* FUN_0056e460(int iFlags);
};

// FUN_0056e6c0: constructor-like member that calls the base routine with
// `this`, installs the class vtable pointer into the object, bumps a global
// counter and returns itself.

extern int DAT_01030b0c;
extern int DAT_01268274;

struct FUN_0056e6c0_cls
{
    void* m_pVTable;
    void FUN_0056e6f0();
    FUN_0056e6c0_cls* FUN_0056e6c0();
};

extern unsigned int DAT_012680f8;

struct FUN_0056e6f0_base
{
    FUN_0056e6f0_base();
    virtual void v00();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct FUN_0056e6f0 : public FUN_0056e6f0_base
{
    unsigned int m_10;
    FUN_0056e6f0();
};

// Initializes m_10 to 0 and increments the global counter DAT_012680f8.
// @fnv 0x0056e6f0
FUN_0056e6f0::FUN_0056e6f0()
{
    m_10 = 0;
    DAT_012680f8 = DAT_012680f8 + 1;
}

struct FUN_0056e860_sub
{
    float m_f0;
    float m_f4;
    float m_f8;
    void Init();
    void SetAll(float value);
};

struct FUN_0056e860_cls
{
    void* m_vtbl;
    int m_04;
    int m_08;
    int m_0c;
    FUN_0056e860_sub m_sub;
    void FUN_0056e8d0();
    FUN_0056e860_cls* FUN_0056e860();
};

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_0056e920_cls
{
    int unk00;

    void BaseCleanup();

    FUN_0056e920_cls* FUN_0056e920(unsigned int acFlags);
};

struct ActorController
{
    void FUN_00498910(int mode, int flags);
    void FUN_00496080(int mode, float amount);
    struct FloatController* FUN_00496940(float amount);
    void* FUN_005585e0();
    void FUN_00499080();
};
struct FloatController
{
    void FUN_0048fef0();
};
void __cdecl FUN_00499160(void* value);

struct FUN_00571560_Class
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
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
    virtual ActorController* QueryActor();
    void FUN_00571560();
};

struct TESContainer;
TESContainer* __fastcall FUN_0055d310(TESObjectREFR* reference);
struct SelectedObject
{
};
struct ObjectProvider
{
};
extern "C" ObjectProvider* DAT_011c3f2c;
extern "C" SelectedObject* __fastcall FUN_00740960(ObjectProvider* provider);
extern "C" void* __fastcall FUN_004ca200(SelectedObject* selected);
extern "C" SelectedObject* __cdecl FUN_004bf220(TESObjectREFR* reference);
struct FUN_00575510_shell : TESObjectREFR
{
    void FUN_00575510(bool useProvider, void** relatedObject, SelectedObject** selectedObject);
};

class SpawnedNode
{
  public:
    SpawnedNode();
    void Configure(unsigned int a, unsigned int b);
    void* operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
    unsigned char pad[0x80];
};

class RefrOps
{
  public:
    void Attach(SpawnedNode* node);
};

void FUN_00b57e30(void* refr, int a, int b);

struct NodeView
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual NodeView* AsNode();
    unsigned int FUN_009ee040();
    void FUN_00450f90(bool);
    bool FUN_00456610();
    unsigned int FUN_0043b480();
    NodeView* FUN_0043b4a0(unsigned int);
};
struct AddonView
{
    bool FUN_00448bf0();
    void* FUN_0059e300(NodeView*);
};
struct HandlerView
{
    AddonView* FUN_004617e0(unsigned int);
};
extern HandlerView* g_dataHandler;
extern unsigned int DAT_01202de8;
bool FUN_0043b300(const void*, NodeView*);
struct EffectsView
{
    void FUN_00c505c0(void*);
};
EffectsView* FUN_0045a190();

namespace fnv_00578400 {
struct NiRTTI;
extern NiRTTI DAT_01202de8;

struct FUN_00453470_shell
{
    int FUN_00453470();
};

class _FakeNiNode
{
  public:
    virtual void unk04();
    virtual void unk08();
    virtual void unk0A();
    virtual _FakeNiNode* unk0C();
    unsigned int FUN_0043b480();
    _FakeNiNode* FUN_0043b4a0(unsigned int index);
};

bool __cdecl FUN_0043b300(NiRTTI const* rtti, _FakeNiNode* obj);

}  // namespace fnv_00578400

struct FUN_00578790_obj0
{
    int m_unk00;
    FUN_00578790_obj0* Lookup(void* p, int flag);
};
extern FUN_00578790_obj0 DAT_011e0e80;

struct FUN_00578790_sub
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual float vc(int code);
};

struct FUN_00578790_node
{
    int GetType();
    unsigned char CheckFlag();
    void* Resolve();
};

struct FUN_00578790_cls
{
    FUN_00578790_node* GetOwned();
    unsigned char FUN_00578790(FUN_00578790_node* param);
};

int FUN_0047e040_fn(float f);

class ExtraValue578
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int m_iValue;
};

class ExtraDataList578
{
  public:
    ExtraValue578* GetValueExtra();
};

class TESObjectREFR578
{
  public:
    ExtraDataList578* GetExtraData();
    int FUN_00578970();
};

struct AnimationAction
{
    void FUN_00475b20();
};
AnimationAction* __cdecl FUN_00475400(unsigned int action);

struct ActorActions
{
    bool FUN_00452370();
    bool FUN_00477ba0();
    unsigned int FUN_007af430(ActorActions* actor, float amount, bool repeat);
    void FUN_00579220(float amount, bool repeat);
};

struct ExtraDataHeader
{
    virtual ~ExtraDataHeader();
    ExtraDataHeader* next;
    unsigned int type;
};

struct ExtraDataPayload
{
    virtual ~ExtraDataPayload();
};

struct FUN_0057a8d0 : ExtraDataHeader
{
    ExtraDataPayload* payload;
    virtual ~FUN_0057a8d0();
};

// Destructor that deletes the owned payload if it is non-null.
// @fnv 0x0057a8d0
FUN_0057a8d0::~FUN_0057a8d0()
{
    if (payload)
        delete payload;
}

struct AttachedResource
{
    unsigned int FUN_009ad610();
};
struct InterfaceObject
{
    virtual void slot0();
    virtual void slot4();
    virtual void slot8();
    virtual void slotC();
    virtual AttachedResource* getResource();
};
struct ResourceHandle
{
    InterfaceObject* FUN_00559450();
};
struct ResourceOwner
{
    unsigned int FUN_008d6f30();
};
struct RegistryWithMethod : GlobalObject_00559cc0
{
    void FUN_00844700(unsigned int resource, ResourceOwner* owner);
};
unsigned char __cdecl FUN_0057ab50(void* resource);
struct FUN_0057aa90_Class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    ResourceOwner* owner18;
    ResourceHandle resource1C;
    void* unk20;
    unsigned char enabled24;
    void FUN_0057aa90();
};

struct FUN_0057b0d0_R
{
    char unk00[8];
    float f8;
};
struct FUN_0057b0d0_X
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
    virtual FUN_0057b0d0_R* v125();
};
struct FUN_0057b0d0_S
{
    FUN_0057b0d0_X* u0;
    char unk04[4];
    float f8;
};
struct FUN_0057b0d0_cls
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
    virtual bool v64();
    char unk04[0x60];
    FUN_0057b0d0_S* m64;
    void* FUN_005d43c0(int a, unsigned char b);
    float FUN_0057b0a0();
    void FUN_0057b0d0(int a, unsigned char b);
};
FUN_0057b0d0_X* __fastcall FUN_0042f030(void* p);
void* __fastcall FUN_008d6f30(void* p);
bool __fastcall FUN_004518e0x(void* p);
float __fastcall FUN_005471e0(void* p);
void* __fastcall FUN_009306d0(void* p);
void __fastcall FUN_0057b1d0(void* pThis, float afHeight);
extern float const DAT_01015f5c;

struct B200List
{
    int unk00;
    int m_iArrayLength;
};

struct B200Owner
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
    B200List* m_pkList;

    bool FUN_0057b200();
};

struct Prefix_0057b750
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
};
struct SearchBase_0057b750
{
    int unk10;
    SearchBase_0057b750* FUN_0057c400(int key);
};
struct FUN_0057b750_owner : Prefix_0057b750, SearchBase_0057b750
{
    FUN_0057b750_owner* FUN_0057b750(int key);
};

namespace fnv_006751a0 {
struct Cell;
struct Pkg;
struct Proc;

struct Ref
{
    virtual void rv000();
    virtual void rv004();
    virtual void rv008();
    virtual void rv00c();
    virtual void rv010();
    virtual void rv014();
    virtual void rv018();
    virtual void rv01c();
    virtual void rv020();
    virtual void rv024();
    virtual void rv028();
    virtual void rv02c();
    virtual void rv030();
    virtual void rv034();
    virtual void rv038();
    virtual void rv03c();
    virtual void rv040();
    virtual void rv044();
    virtual void rv048();
    virtual void rv04c();
    virtual void rv050();
    virtual void rv054();
    virtual void rv058();
    virtual void rv05c();
    virtual void rv060();
    virtual void rv064();
    virtual void rv068();
    virtual void rv06c();
    virtual void rv070();
    virtual void rv074();
    virtual void rv078();
    virtual void rv07c();
    virtual void rv080();
    virtual void rv084();
    virtual void rv088();
    virtual void rv08c();
    virtual void rv090();
    virtual void rv094();
    virtual void rv098();
    virtual void rv09c();
    virtual void rv0a0();
    virtual void rv0a4();
    virtual void rv0a8();
    virtual void rv0ac();
    virtual void rv0b0();
    virtual void rv0b4();
    virtual void rv0b8();
    virtual void rv0bc();
    virtual void rv0c0();
    virtual void rv0c4();
    virtual void rv0c8();
    virtual void rv0cc();
    virtual void rv0d0();
    virtual void rv0d4();
    virtual void rv0d8();
    virtual void rv0dc();
    virtual void rv0e0();
    virtual void rv0e4();
    virtual void rv0e8();
    virtual void rv0ec();
    virtual void rv0f0();
    virtual void rv0f4();
    virtual void rv0f8();
    virtual void rv0fc();
    virtual void rv100();
    virtual void rv104();
    virtual void rv108();
    virtual void rv10c();
    virtual void rv110();
    virtual void rv114();
    virtual void rv118();
    virtual void rv11c();
    virtual void rv120();
    virtual void rv124();
    virtual void rv128();
    virtual void rv12c();
    virtual void rv130();
    virtual void rv134();
    virtual void rv138();
    virtual void rv13c();
    virtual void rv140();
    virtual void rv144();
    virtual void rv148();
    virtual void rv14c();
    virtual void rv150();
    virtual void rv154();
    virtual void rv158();
    virtual void rv15c();
    virtual void rv160();
    virtual void rv164();
    virtual void rv168();
    virtual void rv16c();
    virtual void rv170();
    virtual void rv174();
    virtual void rv178();
    virtual void rv17c();
    virtual void rv180();
    virtual void rv184();
    virtual void rv188();
    virtual void rv18c();
    virtual void rv190();
    virtual void rv194();
    virtual void rv198();
    virtual void rv19c();
    virtual void rv1a0();
    virtual void rv1a4();
    virtual void rv1a8();
    virtual void rv1ac();
    virtual void rv1b0();
    virtual void rv1b4();
    virtual void rv1b8();
    virtual void rv1bc();
    virtual void rv1c0();
    virtual void rv1c4();
    virtual void rv1c8();
    virtual void rv1cc();
    virtual void rv1d0();
    virtual void rv1d4();
    virtual void rv1d8();
    virtual void rv1dc();
    virtual void rv1e0();
    virtual void rv1e4();
    virtual void rv1e8();
    virtual void rv1ec();
    virtual void rv1f0();
    virtual void rv1f4();
    virtual void rv1f8();
    virtual void rv1fc();
    virtual void rv200();
    virtual void rv204();
    virtual void rv208();
    virtual void rv20c();
    virtual void rv210();
    virtual void rv214();
    virtual void rv218();
    virtual void rv21c();
    virtual void rv220();
    virtual void rv224();
    virtual void rv228();
    virtual void rv22c();
    virtual void rv230();
    virtual void rv234();
    virtual void rv238();
    virtual void rv23c();
    virtual void rv240();
    virtual void rv244();
    virtual void rv248();
    virtual void rv24c();
    virtual void rv250();
    virtual void rv254();
    virtual void rv258();
    virtual void rv25c();
    virtual void rv260();
    virtual void rv264();
    virtual void rv268();
    virtual void rv26c();
    virtual void rv270();
    virtual void rv274();
    virtual void rv278();
    virtual void rv27c();
    virtual void rv280();
    virtual void rv284();
    virtual void rv288();
    virtual void rv28c();
    virtual void rv290();
    virtual void rv294();
    virtual Cell* GetCell298();
    Cell* GetParentCell();
    Ref* GetLinkedRef();
    Proc* GetProcess();
    Cell* GetCell56ad80();
};

struct Proc
{
    virtual void pv000();
    virtual void pv004();
    virtual void pv008();
    virtual void pv00c();
    virtual void pv010();
    virtual void pv014();
    virtual void pv018();
    virtual void pv01c();
    virtual void pv020();
    virtual void pv024();
    virtual void pv028();
    virtual void pv02c();
    virtual void pv030();
    virtual void pv034();
    virtual void pv038();
    virtual void pv03c();
    virtual void pv040();
    virtual void pv044();
    virtual void pv048();
    virtual void pv04c();
    virtual void pv050();
    virtual void pv054();
    virtual void pv058();
    virtual void pv05c();
    virtual void pv060();
    virtual void pv064();
    virtual void pv068();
    virtual void pv06c();
    virtual void pv070();
    virtual void pv074();
    virtual void pv078();
    virtual void pv07c();
    virtual void pv080();
    virtual void pv084();
    virtual void pv088();
    virtual void pv08c();
    virtual void pv090();
    virtual void pv094();
    virtual void pv098();
    virtual void pv09c();
    virtual void pv0a0();
    virtual void pv0a4();
    virtual void pv0a8();
    virtual void pv0ac();
    virtual void pv0b0();
    virtual void pv0b4();
    virtual void pv0b8();
    virtual void pv0bc();
    virtual void pv0c0();
    virtual void pv0c4();
    virtual void pv0c8();
    virtual void pv0cc();
    virtual void pv0d0();
    virtual void pv0d4();
    virtual void pv0d8();
    virtual void pv0dc();
    virtual void pv0e0();
    virtual void pv0e4();
    virtual void pv0e8();
    virtual void pv0ec();
    virtual void pv0f0();
    virtual void pv0f4();
    virtual void pv0f8();
    virtual void pv0fc();
    virtual void pv100();
    virtual void pv104();
    virtual void pv108();
    virtual void pv10c();
    virtual void pv110();
    virtual void pv114();
    virtual void pv118();
    virtual void pv11c();
    virtual void pv120();
    virtual void pv124();
    virtual void pv128();
    virtual void pv12c();
    virtual void pv130();
    virtual void pv134();
    virtual void pv138();
    virtual void pv13c();
    virtual void pv140();
    virtual void pv144();
    virtual void pv148();
    virtual void pv14c();
    virtual void pv150();
    virtual void pv154();
    virtual void pv158();
    virtual void pv15c();
    virtual void pv160();
    virtual void pv164();
    virtual void pv168();
    virtual void pv16c();
    virtual void pv170();
    virtual void pv174();
    virtual void pv178();
    virtual void pv17c();
    virtual void pv180();
    virtual void pv184();
    virtual void pv188();
    virtual void pv18c();
    virtual void pv190();
    virtual void pv194();
    virtual void pv198();
    virtual void pv19c();
    virtual void pv1a0();
    virtual void pv1a4();
    virtual void pv1a8();
    virtual void pv1ac();
    virtual void pv1b0();
    virtual void pv1b4();
    virtual void pv1b8();
    virtual void pv1bc();
    virtual void pv1c0();
    virtual void pv1c4();
    virtual void pv1c8();
    virtual void pv1cc();
    virtual void pv1d0();
    virtual void pv1d4();
    virtual void pv1d8();
    virtual void pv1dc();
    virtual void pv1e0();
    virtual void pv1e4();
    virtual void pv1e8();
    virtual void pv1ec();
    virtual void pv1f0();
    virtual void pv1f4();
    virtual void pv1f8();
    virtual void pv1fc();
    virtual void pv200();
    virtual void pv204();
    virtual void pv208();
    virtual void pv20c();
    virtual void pv210();
    virtual void pv214();
    virtual void pv218();
    virtual void pv21c();
    virtual void pv220();
    virtual void pv224();
    virtual void pv228();
    virtual void pv22c();
    virtual void pv230();
    virtual void pv234();
    virtual void pv238();
    virtual void pv23c();
    virtual void pv240();
    virtual void pv244();
    virtual void pv248();
    virtual void pv24c();
    virtual void pv250();
    virtual void pv254();
    virtual void pv258();
    virtual void pv25c();
    virtual void pv260();
    virtual void pv264();
    virtual void pv268();
    virtual void pv26c();
    virtual void pv270();
    virtual void pv274();
    virtual void pv278();
    virtual Pkg* GetPackage27c();
    virtual void pv280();
    virtual void pv284();
    virtual void pv288();
    virtual void pv28c();
    virtual void pv290();
    virtual void pv294();
    virtual void pv298();
    virtual void pv29c();
    virtual void pv2a0();
    virtual void pv2a4();
    virtual void pv2a8();
    virtual void pv2ac();
    virtual void pv2b0();
    virtual void pv2b4();
    virtual void pv2b8();
    virtual void pv2bc();
    virtual void pv2c0();
    virtual void pv2c4();
    virtual void pv2c8();
    virtual void pv2cc();
    virtual void pv2d0();
    virtual void pv2d4();
    virtual void pv2d8();
    virtual void pv2dc();
    virtual void pv2e0();
    virtual void pv2e4();
    virtual void pv2e8();
    virtual void pv2ec();
    virtual void pv2f0();
    virtual void pv2f4();
    virtual void pv2f8();
    virtual void pv2fc();
    virtual void pv300();
    virtual void pv304();
    virtual void pv308();
    virtual void pv30c();
    virtual void pv310();
    virtual void pv314();
    virtual void pv318();
    virtual void pv31c();
    virtual void pv320();
    virtual void pv324();
    virtual void pv328();
    virtual void pv32c();
    virtual void pv330();
    virtual void pv334();
    virtual void pv338();
    virtual void pv33c();
    virtual void pv340();
    virtual void pv344();
    virtual void pv348();
    virtual void pv34c();
    virtual void pv350();
    virtual void pv354();
    virtual void pv358();
    virtual void pv35c();
    virtual void pv360();
    virtual void pv364();
    virtual void pv368();
    virtual void pv36c();
    virtual void pv370();
    virtual void pv374();
    virtual void pv378();
    virtual void pv37c();
    virtual void pv380();
    virtual void pv384();
    virtual void pv388();
    virtual void pv38c();
    virtual void pv390();
    virtual void pv394();
    virtual void pv398();
    virtual void pv39c();
    virtual void pv3a0();
    virtual void pv3a4();
    virtual void pv3a8();
    virtual void pv3ac();
    virtual void pv3b0();
    virtual void pv3b4();
    virtual void pv3b8();
    virtual void pv3bc();
    virtual void pv3c0();
    virtual void pv3c4();
    virtual void pv3c8();
    virtual void pv3cc();
    virtual void pv3d0();
    virtual void pv3d4();
    virtual void pv3d8();
    virtual void pv3dc();
    virtual void pv3e0();
    virtual void pv3e4();
    virtual void pv3e8();
    virtual void pv3ec();
    virtual void pv3f0();
    virtual void pv3f4();
    virtual void pv3f8();
    virtual void pv3fc();
    virtual void pv400();
    virtual void pv404();
    virtual void pv408();
    virtual void pv40c();
    virtual void pv410();
    virtual void pv414();
    virtual void pv418();
    virtual void pv41c();
    virtual void pv420();
    virtual void pv424();
    virtual void pv428();
    virtual void pv42c();
    virtual void pv430();
    virtual void pv434();
    virtual void pv438();
    virtual void pv43c();
    virtual void pv440();
    virtual void pv444();
    virtual void pv448();
    virtual void pv44c();
    virtual void pv450();
    virtual void pv454();
    virtual void pv458();
    virtual void pv45c();
    virtual void pv460();
    virtual void pv464();
    virtual void pv468();
    virtual void pv46c();
    virtual void pv470();
    virtual void pv474();
    virtual void pv478();
    virtual void pv47c();
    virtual void pv480();
    virtual void pv484();
    virtual void pv488();
    virtual void pv48c();
    virtual void pv490();
    virtual void pv494();
    virtual void pv498();
    virtual void pv49c();
    virtual void pv4a0();
    virtual void pv4a4();
    virtual void pv4a8();
    virtual void pv4ac();
    virtual void pv4b0();
    virtual void pv4b4();
    virtual void pv4b8();
    virtual void pv4bc();
    virtual void pv4c0();
    virtual void pv4c4();
    virtual void pv4c8();
    virtual void pv4cc();
    virtual void pv4d0();
    virtual void pv4d4();
    virtual void pv4d8();
    virtual void pv4dc();
    virtual void pv4e0();
    virtual void pv4e4();
    virtual void pv4e8();
    virtual void pv4ec();
    virtual void pv4f0();
    virtual void pv4f4();
    virtual void pv4f8();
    virtual void pv4fc();
    virtual void pv500();
    virtual void pv504();
    virtual void pv508();
    virtual void pv50c();
    virtual void pv510();
    virtual Ref* GetTarget514();
};

struct PkgLoc
{
    int GetLocType();
    Cell* GetLocationCellReference();
    Ref* GetLocRef();
};

extern Ref* g_thePlayer;

struct Pkg
{
    PkgLoc* GetLocation();
    int GetPackType();
    Cell* FUN_006751a0(Ref* ref);
};

struct PkgSub : Pkg
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
    Ref* unk9c;
};

}  // namespace fnv_006751a0

struct XPos
{
    float x, y, z;
};
struct XM3
{
    float a, b, c, d, e, f, g, h, i;
    XM3();
};
class NiFixedString;
struct XExtra;
struct XBSX
{
    bool GetAddon() const;
};
struct XNode
{
    void FUN_00440460(const XPos*);
    void FUN_0043fa80(const XM3&);
    XExtra* GetExtraData(const NiFixedString&);
    void FUN_0056c7d0(void*);
    void FUN_00440490(float);
};
struct XPlayer
{
    bool FUN_0050d4a0();
};
struct XTile;
XNode* __cdecl FUN_0081e440(XTile*);
void __cdecl FUN_00c6bd00(XNode*, bool);
void __cdecl FUN_00577e20(XNode*);
const NiFixedString& __cdecl FUN_00448a80();
struct XRef;

struct XRef
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
    virtual int Get3D_116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual XPos* GetPos_125();

    bool IsDeleted();
    bool GetDisabled();
    XTile* FUN_004fd400();
    XPlayer* FUN_007af430();
    void FUN_00693ef0(bool);
    void FUN_00570f70(XNode*);
    bool FUN_00448a20();
    void FUN_005659f0();
    float GetScale();
    XM3 FUN_0056fa00();
    XNode* FUN_0081e570(int);
};

struct Holder9
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual void s106();
    virtual void s107();
    virtual void s108();
    virtual void s109();
    virtual void s110();
    virtual void s111();
    virtual void s112();
    virtual void s113();
    virtual void s114();
    virtual void s115();
    virtual void s116();
    virtual void s117();
    virtual void s118();
    virtual void s119();
    virtual void s120();
    virtual void s121();
    virtual void s122();
    virtual void s123();
    virtual void s124();
    virtual void s125();
    virtual void s126();
    virtual void s127();
    virtual void s128();
    virtual void s129();
    virtual void s130();
    virtual void s131();
    virtual void s132();
    virtual void s133();
    virtual void s134();
    virtual void s135();
    virtual void s136();
    virtual void s137();
    virtual void s138();
    virtual void s139();
    virtual void s140();
    virtual void s141();
    virtual void s142();
    virtual void s143();
    virtual void s144();
    virtual void s145();
    virtual void s146();
    virtual void s147();
    virtual void s148();
    virtual void s149();
    virtual void s150();
    virtual void s151();
    virtual void s152();
    virtual void s153();
    virtual void s154();
    virtual void s155();
    virtual void s156();
    virtual void s157();
    virtual void s158();
    virtual void s159();
    virtual void s160();
    virtual void s161();
    virtual void s162();
    virtual void s163();
    virtual void s164();
    virtual void s165();
    virtual void s166();
    virtual void s167();
    virtual void s168();
    virtual void s169();
    virtual void s170();
    virtual void s171();
    virtual void s172();
    virtual void s173();
    virtual void s174();
    virtual void s175();
    virtual void s176();
    virtual void s177();
    virtual void s178();
    virtual void s179();
    virtual void s180();
    virtual void s181();
    virtual void s182();
    virtual void s183();
    virtual void s184();
    virtual void s185();
    virtual void s186();
    virtual void s187();
    virtual void s188();
    virtual void s189();
    virtual void s190();
    virtual void s191();
    virtual void s192();
    virtual void s193();
    virtual void s194();
    virtual void s195();
    virtual void s196();
    virtual void s197();
    virtual void s198();
    virtual void s199();
    virtual void s200();
    virtual void s201();
    virtual void s202();
    virtual void s203();
    virtual void s204();
    virtual void s205();
    virtual void s206();
    virtual void s207();
    virtual void s208();
    virtual void s209();
    virtual void s210();
    virtual void s211();
    virtual void s212();
    virtual void s213();
    virtual void s214();
    virtual void s215();
    virtual void s216();
    virtual void s217();
    virtual void s218();
    virtual void s219();
    virtual void s220();
    virtual void s221();
    virtual void s222();
    virtual void s223();
    virtual void s224();
    virtual void s225();
    virtual void s226();
    virtual void s227();
    virtual void s228();
    virtual void s229();
    virtual void s230();
    virtual void s231();
    virtual void s232();
    virtual void s233();
    virtual void s234();
    virtual void s235();
    virtual void s236();
    virtual void s237();
    virtual void s238();
    virtual void s239();
    virtual void s240();
    virtual void s241();
    virtual void s242();
    virtual void s243();
    virtual void s244();
    virtual void s245();
    virtual void s246();
    virtual void s247();
    virtual void s248();
    virtual void s249();
    virtual void s250();
    virtual void s251();
    virtual void s252();
    virtual void s253();
    virtual void s254();
    virtual void s255();
    virtual void s256();
    virtual void s257();
    virtual void s258();
    virtual void s259();
    virtual void s260();
    virtual void s261();
    virtual void s262();
    virtual void s263();
    virtual void s264();
    virtual void s265();
    virtual void s266();
    virtual void s267();
    virtual void s268();
    virtual void s269();
    virtual void s270();
    virtual void s271();
    virtual void s272();
    virtual void s273();
    virtual void s274();
    virtual void s275();
    virtual void s276();
    virtual void s277();
    virtual void s278();
    virtual void s279();
    virtual void s280();
    virtual void s281();
    virtual void s282();
    virtual void s283();
    virtual void s284();
    virtual void s285();
    virtual void s286();
    virtual void s287();
    virtual void s288();
    virtual void s289();
    virtual void s290();
    virtual void s291();
    virtual void s292();
    virtual void s293();
    virtual void s294();
    virtual void s295();
    virtual void s296();
    virtual void s297();
    virtual void s298();
    virtual void s299();
    virtual void s300();
    virtual void s301();
    virtual void s302();
    virtual void s303();
    virtual void s304();
    virtual void s305();
    virtual void s306();
    virtual void s307();
    virtual void s308();
    virtual void s309();
    virtual void s310();
    virtual void s311();
    virtual void s312();
    virtual void s313();
    virtual void s314();
    virtual void s315();
    virtual void s316();
    virtual void s317();
    virtual void s318();
    virtual void s319();
    virtual void s320();
    virtual void s321();
    virtual void s322();
    virtual void s323();
    virtual void s324();
    virtual void s325();
    virtual void s326();
    virtual void s327();
    virtual void s328();
    virtual void s329();
    virtual void s330();
    virtual void s331();
    virtual void s332();
    virtual void s333();
    virtual void s334();
    virtual void s335();
    virtual void s336();
    virtual void s337();
    virtual void s338();
    virtual void s339();
    virtual void s340();
    virtual void s341();
    virtual void s342();
    virtual void s343();
    virtual void s344();
    virtual void s345();
    virtual void s346();
    virtual void s347();
    virtual void s348();
    virtual void s349();
    virtual void s350();
    virtual void s351();
    virtual void s352();
    virtual void s353();
    virtual void s354();
    virtual void s355();
    virtual void s356();
    virtual void s357();
    virtual void s358();
    virtual void s359();
    virtual void s360();
    virtual void s361();
    virtual void s362();
    virtual void s363();
    virtual void s364();
    virtual void s365();
    virtual void s366();
    virtual void s367();
    virtual void s368();
    virtual void s369();
    virtual void s370();
    virtual void s371();
    virtual void s372();
    virtual void s373();
    virtual void s374();
    virtual void s375();
    virtual void s376();
    virtual void s377();
    virtual void s378();
    virtual void s379();
    virtual void s380();
    virtual void s381();
    virtual void s382();
    virtual void s383();
    virtual void s384();
    virtual void s385();
    virtual void s386();
    virtual void s387();
    virtual void s388();
    virtual void s389();
    virtual void s390();
    virtual void s391();
    virtual void s392();
    virtual void s393();
    virtual void s394();
    virtual void s395();
    virtual void s396();
    virtual void s397();
    virtual void s398();
    virtual void s399();
    virtual void s400();
    virtual void s401();
    virtual void s402();
    virtual void s403();
    virtual void s404();
    virtual void s405();
    virtual void s406();
    virtual void s407();
    virtual void s408();
    virtual void s409();
    virtual void s410();
    virtual void s411();
    virtual void s412();
    virtual void s413();
    virtual void s414();
    virtual void s415();
    virtual void s416();
    virtual void s417();
    virtual void s418();
    virtual void s419();
    virtual void s420();
    virtual void s421();
    virtual void s422();
    virtual void s423();
    virtual void s424();
    virtual void s425();
    virtual void s426();
    virtual void s427();
    virtual void s428();
    virtual void s429();
    virtual void s430();
    virtual void s431();
    virtual void s432();
    virtual void s433();
    virtual void s434(void* a, void* b);
};
struct Ptr9
{
    virtual void* s0();
    virtual void* s1();
    virtual void* s2();
    virtual void* s3();
    virtual void* s4();
    virtual void* s5();
    virtual void* s6();
    virtual void* s7();
    virtual void* s8();
    virtual void* s9();
    virtual void* s10();
    virtual void* s11();
    virtual void* s12();
    virtual void* s13();
    virtual void* s14();
    virtual void* s15();
    virtual void* s16();
    virtual void* s17();
    virtual void* s18();
    virtual void* s19();
    virtual void* s20();
    virtual void* s21();
    virtual void* s22();
    virtual void* s23();
    virtual void* s24();
    virtual void* s25();
    virtual void* s26();
    virtual void* s27();
    virtual void* s28();
    virtual void* s29();
    virtual void* s30();
    virtual void* s31();
    virtual void* s32();
    virtual void* s33();
    virtual void* s34();
    virtual void* s35();
    virtual void* s36();
    virtual void* s37();
    virtual void* s38();
    virtual void* s39();
    virtual void* s40();
    virtual void* s41();
    virtual void* s42();
    virtual void* s43();
    virtual void* s44();
    virtual void* s45();
    virtual void* s46();
    virtual void* s47();
    virtual void* s48();
    virtual void* s49();
    virtual void* s50();
    virtual void* s51();
    virtual void* s52();
    virtual void* s53();
    virtual void* s54();
    virtual void* s55();
    virtual void* s56();
    virtual void* s57();
    virtual void* s58();
    virtual void* s59();
    virtual void* s60();
    virtual void* s61();
    virtual void* s62();
    virtual void* s63();
    virtual void* s64();
    virtual void* s65();
    virtual void* s66();
    virtual void* s67();
    virtual void* s68();
    virtual void* s69();
    virtual void* s70();
    virtual void* s71();
    virtual void* s72();
    virtual void* s73();
    virtual void* s74();
    virtual void* s75();
    virtual void* s76();
    virtual void* s77();
    virtual void* s78();
    virtual void* s79();
    virtual void* s80();
    virtual void* s81();
    virtual void* s82();
    virtual void* s83();
    virtual void* s84();
    virtual void* s85();
    virtual void* s86();
    virtual void* s87();
    virtual void* s88();
    virtual void* s89();
    virtual void* s90();
    virtual void* s91();
    virtual void* s92();
    virtual void* s93();
    virtual void* s94();
    virtual void* s95();
    virtual void* s96();
};
struct Ref9
{
    void FUN_0087e100(int a);
};
struct Glob9
{
    unsigned char* FUN_00408d60();
};
extern Glob9 g_b9490_glob;
struct Self9
{
    char pad[0x68];
    Holder9* m_68;
    Ptr9* FUN_004181e0();
    Ref9* FUN_009335b0(unsigned char a);
    bool FUN_008b7b70();
    Ref9* FUN_0087e060(unsigned char flag);
    void FUN_008b7360(bool a, bool b);
};

struct Node;

struct Mgr
{
    void FUN_004534f0(Node* p);
};
extern Mgr* DAT_011c3b3c;

struct Node
{
    bool FUN_00936fb0();
};

struct Self
{
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
    virtual void v064();
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
    virtual Node* v116();
    int FUN_00936ef0();
    void FUN_00936f50(bool arg);
};

struct S_0094dbb0_Foo
{
    void* unk00;
    void FUN_0056e690();
    S_0094dbb0_Foo* FUN_0094dbb0();
};

extern void* DAT_01030cdc;
extern int DAT_01268280;

struct ReferenceHeader
{
    unsigned int type;
    unsigned int flags;
    unsigned int size;
};

struct ReferencePayload
{
    unsigned int identifier;
};

struct ReferenceNode : ReferenceHeader, ReferencePayload
{
};

struct FUN_009ac190_object
{
    ReferencePayload* FUN_009ac190();
};

namespace fnv_009c6160 {
struct NiAVObject;
struct TESObjectCELL;
struct bhkCollisionObject;
struct NiPoint3;
struct bhkWorld
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
    virtual void AddObject(NiAVObject* apObj, bool a, bool b, int c, int d);
};
struct CharCtlX
{
    bhkWorld* GetWorld();
    void SetState(int);
    void SetHeight(float);
    void SetPosition(NiPoint3*);
    NiAVObject* GetNode();
    void SetNode(NiAVObject*);
};
struct bhkWorldObjectV
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
    virtual void* GetWorldPtr();
};
struct bhkCollisionObject
{
    bhkWorldObjectV* GetWorldObject();
};
bhkWorld* __fastcall GetCellWorld(TESObjectCELL* cell);
float __fastcall GetCellWaterHeight(TESObjectCELL* cell);
bhkCollisionObject* __cdecl GetCollisionObject(NiAVObject* obj);
bhkWorld* __cdecl GetHavokWorld(void* p);
void __cdecl RegisterWithWorld(NiAVObject* obj, bool a, bool b);
void __cdecl AddToWorldDefault(NiAVObject* obj, bool a, bool b);
struct RefX
{
  public:
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
    virtual NiAVObject* GetNiNode();
    CharCtlX* GetPhysicsCharacterController();
    bool HasFlag(int);
    NiAVObject* Get3DSimple();
    TESObjectCELL* GetParentCell();
    NiPoint3* GetPos();
    void FUN_009c6160(int unused);
};

}  // namespace fnv_009c6160

struct FUN_009d9f60_result
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};

struct FUN_009d9f60_shell
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
    unsigned int unkC0;
    unsigned int unkC4;
    unsigned int unkC8;
    unsigned int unkCc;
    unsigned int unkD0;
    unsigned int unkD4;
    unsigned int unkD8;
    unsigned int unkDc;
    unsigned int unkE0;
    unsigned int unkE4;
    unsigned int unkE8;
    unsigned int unkEc;

    FUN_009d9f60_result unkF0;

    FUN_009d9f60_result* FUN_009d9f60(FUN_009d9f60_result* result);
};

namespace fnv_0055a430 {
struct FUN_0055a430;
typedef FUN_0055a430 Cls;
struct Obj40
{
    void FUN_0054ca90(Cls*);
};
struct Obj905
{
    void FUN_00905330();
};
struct EL;
struct ListNodeBase
{
};
struct InnerObj
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
    virtual void Call4cc(Cls*);
    InnerObj* FUN_008d8520();
};
struct N20
{
    N20* FUN_00726070();
    InnerObj** FUN_006815c0();
};
struct D38
{
    void FUN_0056aa10(int);
};
struct N38
{
    N38* FUN_00726070();
    D38** FUN_006815c0();
    bool FUN_008256d0();
};
struct D30
{
};
struct N30
{
    N30* FUN_00726070();
    Cls** FUN_006815c0();
    bool FUN_008256d0();
};
struct D18
{
    void FUN_00569ba0(int);
};
struct N18
{
    N18* FUN_00726070();
    D18** FUN_006815c0();
    bool FUN_008256d0();
};
struct Holder1c
{
    Cls* f0;
};
struct N1c
{
    N1c* FUN_00726070();
    Holder1c** FUN_006815c0();
    bool FUN_008256d0();
};
struct N40
{
    N40* FUN_00726070();
    Holder1c** FUN_006815c0();
};
struct EL
{
    Cls* FUN_0041de00();
    Cls* FUN_0041e310();
    N30* FUN_0041df90();
    N18* FUN_0041e500();
    N1c* FUN_0041e780();
    N1c* FUN_0041eda0();
    N40* FUN_0041f170();
    void FUN_0041dda0(Cls*);
    void FUN_0041e0d0(Cls*);
    void FUN_0041e340(int);
    void FUN_0041f4c0(Cls*, int);
    void FUN_0041f650(Cls*, int);
    void FUN_0041e600(Cls*);
    void FUN_0041ef20(Cls*);
    void FUN_0041e960(Cls*);
    void FUN_0041de40(int);
};
EL* __fastcall FUN_005d43c0(Cls*);
struct Obj28
{
    Obj28* FUN_00586170();
    void FUN_006fcf30(Cls*);
};
struct Obj2c
{
    void FUN_005380d0(void*);
};
struct ObjCell
{
    Obj2c* FUN_004543c0();
};
struct Sub18
{
    void* FUN_00559450();
    void FUN_0066b0d0(int);
};
struct Sub64
{
    int field00;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    Sub18 m18;
};
struct Obj6c
{
    void FUN_006c0c80();
    void FUN_006c1060();
};
void __cdecl FUN_0057acc0(unsigned int);
void __cdecl FUN_00868270(Cls*);
void __cdecl FUN_008d15b0(Cls*);
void __cdecl FUN_00705b30(Cls*);
void __cdecl FUN_00477410(Cls*);
Obj6c* __stdcall GetNavMeshObstacleManager(Cls*);
int __cdecl FUN_0055ac70();
void __cdecl FUN_005aa5d0(Cls*);
void __cdecl FUN_0055ac80();
Cls* __cdecl FUN_007038d0();
void __cdecl FUN_007038b0(int);
struct G43c
{
    void FUN_004538e0(int);
    void FUN_0082f1f0();
};
extern G43c DAT_011e043c;
extern int DAT_011ca28c;
struct TimeG
{
    int FUN_00825c00();
};
extern TimeG DAT_011f6394;
struct ProcL
{
    N20* FUN_0096e290();
    void FUN_00976680(Cls*);
    void FUN_0096f600(Cls*, int);
    void FUN_00975320(Cls*);
    void FUN_00978660(Cls*);
    void FUN_009749b0(Cls*);
};
extern ProcL DAT_011e0e80;
struct Player
{
    void FUN_00963d60(Cls*);
    void FUN_0055ac40(Cls*);
    void FUN_00962cd0(Cls*);
    void FUN_0055ac20();
    Cls* FUN_0089f4e0();
};
extern Player* DAT_011dea3c;
struct ObjA10
{
    Obj905* FUN_0055ac00(Cls**);
};
extern ObjA10* DAT_011dea10;
struct Obj45c
{
    bool FUN_008a81c0();
    void FUN_008a8150(int);
    void FUN_008623a0(Cls*);
};
extern Obj45c* DAT_011de45c;
struct DHand
{
    bool FUN_004226e0();
};
extern DHand* DAT_011c3f2c;
struct FUN_00483630
{
    virtual ~FUN_00483630();
    int b00;
    int b04;
    int b08;
    int b0c;
    int b10;
};
struct Base2
{
    virtual void vbase2();
    Obj40* FUN_00575dc0();
};
struct FUN_004103b0
{
    ~FUN_004103b0();
    int m00;
    int m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
};
struct FUN_0055a430 : FUN_00483630, Base2
{
    int m1c;
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    Obj40* m40;
    FUN_004103b0 m44;
    Sub64* m64;
    bool FUN_00568680();
    int FUN_00401170();
    Cls* FUN_00567790();
    void FUN_00567c50();
    Cls* FUN_007af430();
    bool FUN_00549580();
    Obj28* FUN_00575d70();
    ObjCell* FUN_008d6f30();
    bool FUN_004077c0();
    void FUN_00576760();
    Cls* FUN_0056a9f0();
    N38* FUN_0056ac90();
    bool FUN_00564d80();
    bool FUN_005725b0();
    bool FUN_0055abe0();
    bool FUN_00452370();
    Cls* FUN_00569b80();
    void FUN_00564930(int);
    void FUN_0055ad20();
    bool FUN_005653d0();
    bool FUN_00564bc0();

    ~FUN_0055a430();
};

Obj905* __stdcall FUN_004e3260(Cls**);
Obj905* __stdcall FUN_004ec7b0(Cls**);

// @fnv 0x0055a430
Cls::~FUN_0055a430()
{
    Cls* item;
    Cls* list2;
    Cls* head3;
    Obj40* p4c;
    Holder1c* elem_2;
    Cls* obj;
    N40* entry;
    Cls* data;
    N38* head;
    Cls* walk;
    N30* link3;
    Obj2c* it18;
    Obj28* p28;
    InnerObj* p10;
    N20* val;
    N1c* temp2;
    N18* iterX = 0;
    bool saved3;
    Cls* aTmp68;
    FUN_0057acc0((unsigned int)this);
    if (FUN_00568680())
    {
        DAT_011e043c.FUN_004538e0(0);
        DAT_011ca28c = DAT_011f6394.FUN_00825c00();
        for (val = DAT_011e0e80.FUN_0096e290(); val != 0; val = val->FUN_00726070())
        {
            p10 = *val->FUN_006815c0();
            if (p10 != 0)
            {
                if (p10->FUN_008d8520() != 0)
                {
                    p10->FUN_008d8520()->Call4cc(this);
                }
            }
        }
        DAT_011e043c.FUN_0082f1f0();
    }
    if (FUN_00401170() == 0x27)
    {
        DAT_011ca28c = DAT_011f6394.FUN_00825c00();
    }
    FUN_00868270(this);
    if (FUN_007af430() != 0)
    {
        if (FUN_007af430()->FUN_00549580())
        {
            p28 = FUN_00575d70();
            if (p28 != 0)
            {
                if (p28->FUN_00586170() != 0)
                {
                    p28->FUN_00586170()->FUN_006fcf30(this);
                }
            }
        }
    }
    if (m64 != 0)
    {
        it18 = FUN_008d6f30() != 0 ? FUN_008d6f30()->FUN_004543c0() : 0;
        if (it18 != 0)
        {
            it18->FUN_005380d0(m64->m18.FUN_00559450());
        }
        m64->m18.FUN_0066b0d0(0);
    }
    saved3 = DAT_011de45c->FUN_008a81c0();
    DAT_011de45c->FUN_008a8150(0);
    if (!FUN_004077c0())
    {
        FUN_00576760();
        FUN_008d15b0(this);
        DAT_011de45c->FUN_008623a0(this);
        if (!DAT_011c3f2c->FUN_004226e0())
        {
            data = FUN_0056a9f0();
            if (data != 0)
            {
                FUN_005d43c0(data)->FUN_0041dda0(this);
            }
            head = FUN_0056ac90();
            while (head != 0 && !head->FUN_008256d0())
            {
                (*head->FUN_006815c0())->FUN_0056aa10(0);
                head = FUN_0056ac90();
            }
        }
        walk = FUN_005d43c0(this)->FUN_0041de00();
        if (walk != 0)
        {
            FUN_005d43c0(walk)->FUN_0041e0d0(this);
        }
        link3 = FUN_005d43c0(this)->FUN_0041df90();
        while (link3 != 0 && !link3->FUN_008256d0())
        {
            FUN_005d43c0(*link3->FUN_006815c0())->FUN_0041de40(0);
            if ((*link3->FUN_006815c0())->FUN_00567790() == this)
            {
                (*link3->FUN_006815c0())->FUN_00567c50();
            }
            link3 = link3->FUN_00726070();
        }
        if (!DAT_011c3f2c->FUN_004226e0())
        {
            obj = FUN_005d43c0(this)->FUN_0041e310();
            if (obj != 0)
            {
                FUN_005d43c0(obj)->FUN_0041e340(0);
            }
            for (entry = FUN_005d43c0(this)->FUN_0041f170(); entry != 0 && *entry->FUN_006815c0() != 0;)
            {
                elem_2 = *entry->FUN_006815c0();
                entry = entry->FUN_00726070();
                FUN_005d43c0(elem_2->f0)->FUN_0041f4c0(this, 0);
                FUN_005d43c0(elem_2->f0)->FUN_0041f650(this, 0);
            }
            FUN_005aa5d0(this);
            head3 = this;
            FUN_004e3260(&head3)->FUN_00905330();
            list2 = this;
            FUN_004ec7b0(&list2)->FUN_00905330();
            if (FUN_00564d80())
            {
                switch (FUN_00401170())
                {
                case 0x3b:
                case 0x3c:
                    DAT_011dea3c->FUN_00963d60(this);
                    break;
                default:
                    DAT_011e0e80.FUN_00976680(this);
                    DAT_011dea3c->FUN_00963d60(this);
                    DAT_011e0e80.FUN_0096f600(this, 1);
                    DAT_011e0e80.FUN_00975320(this);
                    DAT_011e0e80.FUN_00978660(this);
                    break;
                }
            }
            if (!FUN_005725b0())
            {
                DAT_011e0e80.FUN_009749b0(this);
            }
        }
        if (FUN_0055abe0())
        {
            DAT_011dea3c->FUN_0055ac40(this);
        }
        if (!DAT_011c3f2c->FUN_004226e0())
        {
            if (FUN_00568680())
            {
                item = this;
                DAT_011dea10->FUN_0055ac00(&item)->FUN_00905330();
            }
        }
        if (FUN_00452370())
        {
            FUN_00477410(this);
        }
    }
    aTmp68 = FUN_00569b80();
    if (aTmp68 != 0)
    {
        FUN_005d43c0(aTmp68)->FUN_0041e600(this);
    }
    iterX = FUN_005d43c0(this)->FUN_0041e500();
    while (iterX != 0 && !iterX->FUN_008256d0())
    {
        (*iterX->FUN_006815c0())->FUN_00569ba0(0);
        iterX = iterX->FUN_00726070();
    }
    temp2 = FUN_005d43c0(this)->FUN_0041e780();
    while (temp2 != 0 && !temp2->FUN_008256d0())
    {
        FUN_005d43c0((*temp2->FUN_006815c0())->f0)->FUN_0041ef20(this);
        temp2 = temp2->FUN_00726070();
    }
    temp2 = FUN_005d43c0(this)->FUN_0041eda0();
    while (temp2 != 0 && !temp2->FUN_008256d0())
    {
        FUN_005d43c0((*temp2->FUN_006815c0())->f0)->FUN_0041e960(this);
        temp2 = temp2->FUN_00726070();
    }
    FUN_00564930(1);
    FUN_0055ad20();
    if (m40 != 0)
    {
        m40->FUN_0054ca90(this);
    }
    if (FUN_005653d0())
    {
        if (DAT_011c3f2c != 0)
        {
            if (!DAT_011c3f2c->FUN_004226e0())
            {
                p4c = Base2::FUN_00575dc0();
                if (p4c != 0)
                {
                    p4c->FUN_0054ca90(this);
                }
            }
        }
    }
    if (FUN_007af430() != 0)
    {
        if (FUN_00564bc0())
        {
            GetNavMeshObstacleManager(this)->FUN_006c0c80();
        }
    }
    if (FUN_007af430() != 0)
    {
        if (FUN_007af430()->FUN_00401170() == 0x1c)
        {
            GetNavMeshObstacleManager(this)->FUN_006c1060();
        }
    }
    FUN_00705b30(this);
    if ((Cls*)FUN_0055ac70() == this)
    {
        FUN_0055ac80();
    }
    if (!DAT_011c3f2c->FUN_004226e0())
    {
        if (FUN_007038d0() == this)
        {
            FUN_007038b0(0);
        }
        if (DAT_011dea3c != 0)
        {
            DAT_011dea3c->FUN_00962cd0(this);
        }
    }
    if (DAT_011dea3c->FUN_0089f4e0() == this)
    {
        DAT_011dea3c->FUN_0055ac20();
    }
    DAT_011de45c->FUN_008a8150(saved3);
}
}  // namespace fnv_0055a430

struct ExtraDataList_55ae70
{
    void SaveGame();
};

struct BoundObject_55ae70
{
    unsigned int GetSaveFormID();
};

struct Vec3_55ae70
{
    float x;
    float y;
    float z;
};

struct RefrPosData_55ae70
{
    Vec3_55ae70 pos;
    Vec3_55ae70 rot;
    RefrPosData_55ae70();
    void SwapEndian();
};

void SaveChunkU(unsigned int type, unsigned int value);
void SaveChunkF(unsigned int type, float value);
void SaveChunkEmpty(unsigned int type);
void SaveChunkData(unsigned int type, void* data, unsigned int size);
bool IsSaveBigEndian();

struct RefrSave_55ae70
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    BoundObject_55ae70* baseForm;
    Vec3_55ae70 rot;
    Vec3_55ae70 pos;
    float m_fObjectScale;

    void BeginSave();
    void EndSave();
    bool IsDeleted();
    ExtraDataList_55ae70* GetExtraList();
    bool GetAction(int action);
    void FUN_0055ae70();
};

struct StrMem
{
    char* text;
    unsigned short length;
    unsigned short capacity;
    StrMem();
    ~StrMem();
    operator const char*() const;
};
struct DebugForm
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
    virtual void describe(StrMem*);
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
    virtual const char* name();
    unsigned int FUN_0084e3a0();
    const char* FUN_00440e30();
};
struct FUN_00406f90_this;
int FUN_00406f60(FUN_00406f90_this*, const char*, ...);
int sprintf(char*, const char*, ...);
struct DebugReference
{
    DebugForm* GetObjectReference();
    DebugForm* FUN_00575d70();
    DebugForm* GetParentCell();
    unsigned int FUN_0084e3a0();
    const char* FUN_00401280();
    const char* FUN_00440e30();
    void FUN_0055d540(FUN_00406f90_this* out);
};

struct InitReference;
struct InitVector
{
    float x, y, z;
    void FUN_00439180(float);
};
extern InitVector DAT_011f426c;
struct InitComponent
{
    bool FUN_0047cdb0();
    void FUN_0047ce10(InitReference*);
    bool FUN_0055e200();
    int FUN_00401170();
};
struct InitBase
{
    virtual void BaseSlot0();
    virtual void BaseSlot1();
    virtual void BaseSlot2();
    virtual void BaseSlot3();
    virtual void BaseSlot4();
    virtual void BaseSlot5();
    virtual void BaseSlot6();
    virtual void BaseSlot7();
    virtual void BaseSlot8();
    virtual void BaseSlot9();
    virtual void BaseSlot10();
    virtual void BaseSlot11();
    virtual void BaseSlot12();
    virtual void BaseSlot13();
    virtual void BaseSlot14();
    virtual void BaseSlot15();
    virtual void BaseSlot16();
    virtual void BaseSlot17();
    virtual void BaseSlot18();
    virtual void BaseSlot19();
    virtual void BaseSlot20();
    virtual void BaseSlot21();
    virtual void BaseSlot22();
    virtual void BaseSlot23();
    virtual void BaseSlot24();
    virtual void BaseSlot25();
    virtual void BaseSlot26();
    virtual void BaseSlot27();
    virtual void BaseSlot28();
    virtual void BaseSlot29();
    virtual void BaseSlot30();
    virtual void BaseSlot31();
    virtual void BaseSlot32();
    virtual void BaseSlot33();
    virtual void BaseSlot34();
    virtual void BaseSlot35();
    virtual void BaseSlot36();
    virtual void BaseSlot37();
    virtual void BaseSlot38();
    virtual void BaseSlot39();
    virtual void BaseSlot40();
    virtual void BaseSlot41();
    virtual void BaseSlot42();
    virtual void BaseSlot43();
    virtual void BaseSlot44();
    virtual void BaseSlot45();
    virtual void BaseSlot46();
    virtual void BaseSlot47();
    virtual void BaseSlot48();
    virtual void BaseSlot49();
    virtual void BaseSlot50();
    virtual void BaseSlot51();
    virtual void BaseSlot52();
    virtual void BaseSlot53();
    virtual void BaseSlot54();
    virtual void BaseSlot55();
    virtual void BaseSlot56();
    virtual void BaseSlot57();
    virtual void BaseSlot58();
    virtual void BaseSlot59();
    virtual void BaseSlot60();
    virtual void BaseSlot61();
    virtual void BaseSlot62();
    virtual void BaseSlot63();
    virtual void BaseSlot64();
    virtual void BaseSlot65();
    virtual void BaseSlot66();
    virtual void BaseSlot67();
    virtual void BaseSlot68();
    virtual void BaseSlot69();
    virtual void BaseSlot70();
    virtual void BaseSlot71();
    virtual void BaseSlot72();
    virtual void BaseSlot73();
    virtual void BaseSlot74();
    virtual void BaseSlot75();
    virtual const char* DebugName();
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    unsigned unk30;
    unsigned unk34;
    unsigned unk38;
    unsigned unk3c;
    unsigned unk40;
    unsigned unk44;
    unsigned unk48;
    unsigned unk4c;
    unsigned unk50;
    unsigned unk54;
    unsigned unk58;
    unsigned unk5c;
    unsigned unk60;
    unsigned unk64;
    unsigned unk68;
    unsigned unk6c;
    unsigned unk70;
    unsigned unk74;
    unsigned unk78;
    unsigned unk7c;
    InitComponent component80;
    int FUN_00401170();
    bool FUN_00440d80();
    bool FUN_00440da0();
    bool FUN_00549580();
    const char* FUN_0084e3a0();
};
struct InitScaleExtra
{
    float x, y, z;
    InitScaleExtra();
    InitVector* FUN_006815c0();
    void FUN_0098ddd0(const InitVector&);
};
struct InitExtraList
{
    void FUN_00416be0(InitReference*);
    float FUN_0041b550();
    void FUN_00419970(float);
    short FUN_00418770();
    void FUN_00419ad0(int);
    void FUN_00421f30(InitScaleExtra*);
    void* FUN_00410220(int);
    void FUN_00410140(int);
    void FUN_0041aeb0();
};
struct InitCell
{
    void FUN_005878d0(InitReference*);
    struct InitPending* FUN_00586170(InitReference*, bool);
    const char* FUN_0084e3a0();
    virtual void CellSlot0();
    virtual void CellSlot1();
    virtual void CellSlot2();
    virtual void CellSlot3();
    virtual void CellSlot4();
    virtual void CellSlot5();
    virtual void CellSlot6();
    virtual void CellSlot7();
    virtual void CellSlot8();
    virtual void CellSlot9();
    virtual void CellSlot10();
    virtual void CellSlot11();
    virtual void CellSlot12();
    virtual void CellSlot13();
    virtual void CellSlot14();
    virtual void CellSlot15();
    virtual void CellSlot16();
    virtual void CellSlot17();
    virtual void CellSlot18();
    virtual void CellSlot19();
    virtual void CellSlot20();
    virtual void CellSlot21();
    virtual void CellSlot22();
    virtual void CellSlot23();
    virtual void CellSlot24();
    virtual void CellSlot25();
    virtual void CellSlot26();
    virtual void CellSlot27();
    virtual void CellSlot28();
    virtual void CellSlot29();
    virtual void CellSlot30();
    virtual void CellSlot31();
    virtual void CellSlot32();
    virtual void CellSlot33();
    virtual void CellSlot34();
    virtual void CellSlot35();
    virtual void CellSlot36();
    virtual void CellSlot37();
    virtual void CellSlot38();
    virtual void CellSlot39();
    virtual void CellSlot40();
    virtual void CellSlot41();
    virtual void CellSlot42();
    virtual void CellSlot43();
    virtual void CellSlot44();
    virtual void CellSlot45();
    virtual void CellSlot46();
    virtual void CellSlot47();
    virtual void CellSlot48();
    virtual void CellSlot49();
    virtual void CellSlot50();
    virtual void CellSlot51();
    virtual void CellSlot52();
    virtual void CellSlot53();
    virtual void CellSlot54();
    virtual void CellSlot55();
    virtual void CellSlot56();
    virtual void CellSlot57();
    virtual void CellSlot58();
    virtual void CellSlot59();
    virtual void CellSlot60();
    virtual void CellSlot61();
    virtual void CellSlot62();
    virtual void CellSlot63();
    virtual void CellSlot64();
    virtual void CellSlot65();
    virtual void CellSlot66();
    virtual void CellSlot67();
    virtual void CellSlot68();
    virtual void CellSlot69();
    virtual void CellSlot70();
    virtual void CellSlot71();
    virtual void CellSlot72();
    virtual void CellSlot73();
    virtual void CellSlot74();
    virtual void CellSlot75();
    virtual const char* DebugName();
};
struct InitActorBase
{
    unsigned unk00;
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    unsigned unk20;
    unsigned unk24;
    unsigned unk28;
    unsigned unk2c;
    InitComponent data;
};
struct InitProcess
{
    void FUN_0055e1d0();
    bool FUN_00425fd0();
    const char* FUN_0084e3a0();
    int FUN_00544c30();
    int FUN_00544c60();
    virtual void ProcessSlot0();
    virtual void ProcessSlot1();
    virtual void ProcessSlot2();
    virtual void ProcessSlot3();
    virtual void ProcessSlot4();
    virtual void ProcessSlot5();
    virtual void ProcessSlot6();
    virtual void ProcessSlot7();
    virtual void ProcessSlot8();
    virtual void ProcessSlot9();
    virtual void ProcessSlot10();
    virtual void ProcessSlot11();
    virtual void ProcessSlot12();
    virtual void ProcessSlot13();
    virtual void ProcessSlot14();
    virtual void ProcessSlot15();
    virtual void ProcessSlot16();
    virtual void ProcessSlot17();
    virtual void ProcessSlot18();
    virtual void ProcessSlot19();
    virtual void ProcessSlot20();
    virtual void ProcessSlot21();
    virtual void ProcessSlot22();
    virtual void ProcessSlot23();
    virtual void ProcessSlot24();
    virtual void ProcessSlot25();
    virtual void ProcessSlot26();
    virtual void ProcessSlot27();
    virtual void ProcessSlot28();
    virtual void ProcessSlot29();
    virtual void ProcessSlot30();
    virtual void ProcessSlot31();
    virtual void ProcessSlot32();
    virtual void ProcessSlot33();
    virtual void ProcessSlot34();
    virtual void ProcessSlot35();
    virtual void ProcessSlot36();
    virtual void ProcessSlot37();
    virtual void ProcessSlot38();
    virtual void ProcessSlot39();
    virtual void ProcessSlot40();
    virtual void ProcessSlot41();
    virtual void ProcessSlot42();
    virtual void ProcessSlot43();
    virtual void ProcessSlot44();
    virtual void ProcessSlot45();
    virtual void ProcessSlot46();
    virtual void ProcessSlot47();
    virtual void ProcessSlot48();
    virtual void ProcessSlot49();
    virtual void ProcessSlot50();
    virtual void ProcessSlot51();
    virtual void ProcessSlot52();
    virtual void ProcessSlot53();
    virtual void ProcessSlot54();
    virtual void ProcessSlot55();
    virtual void ProcessSlot56();
    virtual void ProcessSlot57();
    virtual void ProcessSlot58();
    virtual void ProcessSlot59();
    virtual void ProcessSlot60();
    virtual void ProcessSlot61();
    virtual void ProcessSlot62();
    virtual void ProcessSlot63();
    virtual void ProcessSlot64();
    virtual void ProcessSlot65();
    virtual void ProcessSlot66();
    virtual void ProcessSlot67();
    virtual void ProcessSlot68();
    virtual void ProcessSlot69();
    virtual void ProcessSlot70();
    virtual void ProcessSlot71();
    virtual void ProcessSlot72();
    virtual void ProcessSlot73();
    virtual void ProcessSlot74();
    virtual void ProcessSlot75();
    virtual const char* DebugName();
};
struct InitReference
{
    virtual void RefSlot0();
    virtual void RefSlot1();
    virtual void RefSlot2();
    virtual void RefSlot3();
    virtual void RefSlot4();
    virtual void RefSlot5();
    virtual void RefSlot6();
    virtual void RefSlot7();
    virtual void RefSlot8();
    virtual void RefSlot9();
    virtual void RefSlot10();
    virtual void RefSlot11();
    virtual void RefSlot12();
    virtual void RefSlot13();
    virtual void RefSlot14();
    virtual void RefSlot15();
    virtual void RefSlot16();
    virtual void RefSlot17();
    virtual void RefSlot18();
    virtual void RefSlot19();
    virtual void RefSlot20();
    virtual void RefSlot21();
    virtual void RefSlot22();
    virtual void RefSlot23();
    virtual void RefSlot24();
    virtual void RefSlot25();
    virtual void RefSlot26();
    virtual void RefSlot27();
    virtual void RefSlot28();
    virtual void RefSlot29();
    virtual void RefSlot30();
    virtual void RefSlot31();
    virtual void RefSlot32();
    virtual void RefSlot33();
    virtual void RefSlot34();
    virtual void RefSlot35();
    virtual void RefSlot36();
    virtual void RefSlot37();
    virtual void RefSlot38();
    virtual void RefSlot39();
    virtual void RefSlot40();
    virtual void RefSlot41();
    virtual void RefSlot42();
    virtual void RefSlot43();
    virtual void RefSlot44();
    virtual void RefSlot45();
    virtual void RefSlot46();
    virtual void RefSlot47();
    virtual void RefSlot48();
    virtual void SetSpecial(bool);
    virtual void RefSlot50();
    virtual void RefSlot51();
    virtual void RefSlot52();
    virtual void RefSlot53();
    virtual void RefSlot54();
    virtual void RefSlot55();
    virtual void RefSlot56();
    virtual void RefSlot57();
    virtual void RefSlot58();
    virtual void RefSlot59();
    virtual void RefSlot60();
    virtual void RefSlot61();
    virtual void RefSlot62();
    virtual void RefSlot63();
    virtual bool IsActor();
    virtual void RefSlot65();
    virtual void RefSlot66();
    virtual void RefSlot67();
    virtual void RefSlot68();
    virtual void RefSlot69();
    virtual void RefSlot70();
    virtual void RefSlot71();
    virtual void RefSlot72();
    virtual void RefSlot73();
    virtual void RefSlot74();
    virtual void RefSlot75();
    virtual const char* DebugName();
    virtual void RefSlot77();
    virtual void RefSlot78();
    virtual void RefSlot79();
    virtual void RefSlot80();
    virtual void RefSlot81();
    virtual void RefSlot82();
    virtual void RefSlot83();
    virtual void RefSlot84();
    virtual void RefSlot85();
    virtual void RefSlot86();
    virtual void RefSlot87();
    virtual void RefSlot88();
    virtual void RefSlot89();
    virtual void RefSlot90();
    virtual void RefSlot91();
    virtual void RefSlot92();
    virtual void SetReferenceVector(InitVector);
    virtual void RefSlot94();
    virtual void RefSlot95();
    virtual void RefSlot96();
    virtual void RefSlot97();
    virtual void RefSlot98();
    virtual void RefSlot99();
    virtual void RefSlot100();
    virtual void RefSlot101();
    virtual void RefSlot102();
    virtual void RefSlot103();
    virtual void RefSlot104();
    virtual void RefSlot105();
    virtual void RefSlot106();
    virtual void RefSlot107();
    virtual void RefSlot108();
    virtual void RefSlot109();
    virtual void RefSlot110();
    virtual void RefSlot111();
    virtual void RefSlot112();
    virtual void RefSlot113();
    virtual void RefSlot114();
    virtual void RefSlot115();
    virtual void RefSlot116();
    virtual void RefSlot117();
    virtual void RefSlot118();
    virtual void RefSlot119();
    virtual void RefSlot120();
    virtual void RefSlot121();
    virtual void RefSlot122();
    virtual void RefSlot123();
    virtual void RefSlot124();
    virtual void RefSlot125();
    virtual void SetEssential(bool);
    virtual void RefSlot127();
    virtual void RefSlot128();
    virtual void RefSlot129();
    virtual void RefSlot130();
    virtual void RefSlot131();
    virtual void RefSlot132();
    virtual void RefSlot133();
    virtual bool IsNPC();
    virtual void RefSlot135();
    virtual void RefSlot136();
    virtual void RefSlot137();
    virtual void RefSlot138();
    virtual void RefSlot139();
    virtual void RefSlot140();
    virtual void RefSlot141();
    virtual void RefSlot142();
    virtual void RefSlot143();
    virtual void RefSlot144();
    virtual void RefSlot145();
    virtual void RefSlot146();
    virtual void RefSlot147();
    virtual void RefSlot148();
    virtual void RefSlot149();
    virtual void RefSlot150();
    virtual void RefSlot151();
    virtual void RefSlot152();
    virtual void RefSlot153();
    virtual void RefSlot154();
    virtual void RefSlot155();
    virtual void RefSlot156();
    virtual void RefSlot157();
    virtual void RefSlot158();
    virtual void RefSlot159();
    virtual void RefSlot160();
    virtual void RefSlot161();
    virtual void RefSlot162();
    virtual void RefSlot163();
    virtual bool ActorReady();
    virtual void RefSlot165();
    virtual void RefSlot166();
    virtual void RefSlot167();
    virtual void RefSlot168();
    virtual void RefSlot169();
    virtual void RefSlot170();
    virtual void RefSlot171();
    virtual void RefSlot172();
    virtual void RefSlot173();
    virtual void RefSlot174();
    virtual void RefSlot175();
    virtual void RefSlot176();
    virtual void RefSlot177();
    virtual void RefSlot178();
    virtual void RefSlot179();
    virtual void RefSlot180();
    virtual void RefSlot181();
    virtual void RefSlot182();
    virtual void RefSlot183();
    virtual void RefSlot184();
    virtual void RefSlot185();
    virtual void RefSlot186();
    virtual void RefSlot187();
    virtual void RefSlot188();
    virtual void RefSlot189();
    virtual void RefSlot190();
    virtual void RefSlot191();
    virtual void RefSlot192();
    virtual void RefSlot193();
    virtual void SetTemplateFlag(bool);
    virtual void RefSlot195();
    virtual void RefSlot196();
    virtual void RefSlot197();
    virtual void RefSlot198();
    virtual void RefSlot199();
    virtual void RefSlot200();
    virtual void RefSlot201();
    virtual void RefSlot202();
    virtual void RefSlot203();
    virtual void RefSlot204();
    virtual void RefSlot205();
    virtual void RefSlot206();
    virtual void RefSlot207();
    virtual void RefSlot208();
    virtual void RefSlot209();
    virtual void RefSlot210();
    virtual void RefSlot211();
    virtual void RefSlot212();
    virtual void RefSlot213();
    virtual void RefSlot214();
    virtual void RefSlot215();
    virtual bool HasActorState();
    virtual void RefSlot217();
    virtual void RefSlot218();
    virtual void RefSlot219();
    virtual void RefSlot220();
    virtual void RefSlot221();
    virtual void RefSlot222();
    virtual void RefSlot223();
    virtual void RefSlot224();
    virtual void RefSlot225();
    virtual void RefSlot226();
    virtual void RefSlot227();
    virtual void RefSlot228();
    virtual void RefSlot229();
    virtual void RefSlot230();
    virtual void RefSlot231();
    virtual void RefSlot232();
    virtual void RefSlot233();
    virtual void RefSlot234();
    virtual void RefSlot235();
    virtual void RefSlot236();
    virtual void RefSlot237();
    virtual void RefSlot238();
    virtual void RefSlot239();
    virtual void RefSlot240();
    virtual void RefSlot241();
    virtual void RefSlot242();
    virtual void RefSlot243();
    virtual void RefSlot244();
    virtual void RefSlot245();
    virtual void RefSlot246();
    virtual void RefSlot247();
    virtual void RefSlot248();
    virtual void RefSlot249();
    virtual void RefSlot250();
    virtual void RefSlot251();
    virtual void RefSlot252();
    virtual void RefSlot253();
    virtual void RefSlot254();
    virtual void RefSlot255();
    virtual void RefSlot256();
    virtual void RefSlot257();
    virtual void RefSlot258();
    virtual void RefSlot259();
    virtual void RefSlot260();
    virtual void RefSlot261();
    virtual void RefSlot262();
    virtual void RefSlot263();
    virtual void RefSlot264();
    virtual void RefSlot265();
    virtual void RefSlot266();
    virtual void RefSlot267();
    virtual void RefSlot268();
    virtual void RefSlot269();
    virtual void RefSlot270();
    virtual void RefSlot271();
    virtual void RefSlot272();
    virtual void RefSlot273();
    virtual void RefSlot274();
    virtual void RefSlot275();
    virtual void RefSlot276();
    virtual void RefSlot277();
    virtual void RefSlot278();
    virtual void RefSlot279();
    virtual void RefSlot280();
    virtual void RefSlot281();
    virtual void RefSlot282();
    virtual void InitializeActor();
    unsigned unk04;
    unsigned unk08;
    unsigned unk0c;
    unsigned unk10;
    unsigned unk14;
    unsigned unk18;
    unsigned unk1c;
    InitBase* base;
    InitVector rotation;
    InitVector position;

    bool FUN_004013e0();
    InitBase* FUN_007af430();
    InitExtraList* FUN_005d43c0();
    bool FUN_00439f90();
    float FUN_00567400();
    InitScaleExtra* FUN_00569840();
    void FUN_00567490(float);
    InitCell* FUN_00575d70();
    bool FUN_005722c0(int);
    void FUN_008a1800(int);
    InitBase* FUN_00884350();
    InitActorBase* FUN_004181e0();
    bool FUN_0056afc0();
    bool FUN_00572c80();
    InitReference* FUN_0056a9f0();
    bool FUN_0056aa70();
    bool FUN_00440da0();
    void FUN_00484af0(bool);
    bool FUN_00564e60();
    InitProcess* FUN_008d6f30();
    void FUN_0056ac00();
    void FUN_004846a0(bool);
    void FUN_00484ab0(bool);
    const char* FUN_0084e3a0();
    unsigned FUN_00401280();
    void FUN_00565730();
    void FUN_0046a010(int);
    void FUN_0055d760();
};
bool FUN_004fede0(InitBase*, int);
void FUN_004ff150(InitReference*);
int FUN_0046e8a0();
void FUN_0043b2b0(bool);
void FUN_004fffe0(int);
void FUN_005b5e40(const char*, ...);
int FUN_00ec7595(double);
int FUN_00ec75b1(double);
unsigned FUN_004873d0(InitBase*);
struct InitEventManager
{
    void FUN_0096d470(InitReference*, int);
};
struct InitModeManager
{
    bool FUN_004623f0(bool);
};
extern InitModeManager* DAT_011ddf38;
struct InitToggle
{
    bool FUN_0047c850();
    void FUN_004534f0(bool);
};
extern InitToggle* DAT_011de45c;
extern InitReference* DAT_011dea3c;
float FUN_00647f00(void*, int, int, int, int, int, int);
float FUN_004b1480(float);
struct InitSelection
{
    void FUN_004d1440();
    void FUN_004d1610();
    void FUN_004d1960();
    bool FUN_0042cde0();
};
InitSelection* FUN_004bf220(InitReference*);
void* __fastcall FUN_0055d310(InitReference*);
struct InitPending
{
    void FUN_006fcfa0();
};

struct SaveChangeRecord
{
    unsigned int formID;
    unsigned char formType;
    unsigned char changeFlags[4];
};
struct SaveDebugForm
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual const char* Describe();
};
SaveDebugForm* __cdecl FUN_004839c0(unsigned int);
void __cdecl FUN_0040fbe0(const char*, ...);
struct TESSaveLoadGame
{
    bool FUN_00862110();
    unsigned char FUN_008df040();
    SaveChangeRecord* FUN_004fd3e0();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
struct SaveInventory
{
    unsigned short FUN_004d3960();
};
struct SaveExtraList
{
    SaveInventory* FUN_00418520();
    unsigned short FUN_00422c40(unsigned int, void*);
};
struct SaveReference
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual bool IsActor();
    unsigned short FUN_00484bf0(unsigned int);
    SaveExtraList* FUN_005d43c0();
    unsigned short FUN_0055f880();
    unsigned short FUN_00560350(bool);
    unsigned short FUN_0055e730(unsigned int flags);
};

namespace fnv_0055e940 {
struct SavedChangeRecord
{
    unsigned int formId;
    unsigned char type;
    unsigned char changeFlags[4];
};
struct TESSaveLoadGame
{
    unsigned int FUN_00825c00();
    bool FUN_00862110();
    void FUN_008579b0(void*, int);
    unsigned char FUN_008df040();
    SavedChangeRecord* FUN_004fd3e0();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
struct GlobalObject_0045cf30
{
    unsigned char* Bool();
};
extern GlobalObject_0045cf30 g_011de4e8;
struct SaveExtras;
struct ScriptSaveData
{
    void FUN_004d3ab0();
};
struct SaveExtras
{
    ScriptSaveData* FUN_00418520();
    void FUN_004235e0(unsigned int, void*);
};
struct DiagnosticForm
{
    virtual void virtual_00();
    virtual void virtual_04();
    virtual void virtual_08();
    virtual void virtual_0c();
    virtual void virtual_10();
    virtual void virtual_14();
    virtual void virtual_18();
    virtual void virtual_1c();
    virtual void virtual_20();
    virtual void virtual_24();
    virtual void virtual_28();
    virtual void virtual_2c();
    virtual void virtual_30();
    virtual void virtual_34();
    virtual void virtual_38();
    virtual void virtual_3c();
    virtual void virtual_40();
    virtual void virtual_44();
    virtual void virtual_48();
    virtual void virtual_4c();
    virtual void virtual_50();
    virtual void virtual_54();
    virtual void virtual_58();
    virtual void virtual_5c();
    virtual void virtual_60();
    virtual void virtual_64();
    virtual void virtual_68();
    virtual void virtual_6c();
    virtual void virtual_70();
    virtual void virtual_74();
    virtual void virtual_78();
    virtual void virtual_7c();
    virtual void virtual_80();
    virtual void virtual_84();
    virtual void virtual_88();
    virtual void virtual_8c();
    virtual void virtual_90();
    virtual void virtual_94();
    virtual void virtual_98();
    virtual void virtual_9c();
    virtual void virtual_a0();
    virtual void virtual_a4();
    virtual void virtual_a8();
    virtual void virtual_ac();
    virtual void virtual_b0();
    virtual void virtual_b4();
    virtual void virtual_b8();
    virtual void virtual_bc();
    virtual void virtual_c0();
    virtual void virtual_c4();
    virtual void virtual_c8();
    virtual void virtual_cc();
    virtual void virtual_d0();
    virtual void virtual_d4();
    virtual void virtual_d8();
    virtual void virtual_dc();
    virtual void virtual_e0();
    virtual void virtual_e4();
    virtual void virtual_e8();
    virtual void virtual_ec();
    virtual void virtual_f0();
    virtual void virtual_f4();
    virtual void virtual_f8();
    virtual void virtual_fc();
    virtual void virtual_100();
    virtual void virtual_104();
    virtual void virtual_108();
    virtual void virtual_10c();
    virtual void virtual_110();
    virtual void virtual_114();
    virtual void virtual_118();
    virtual void virtual_11c();
    virtual void virtual_120();
    virtual void virtual_124();
    virtual void virtual_128();
    virtual void virtual_12c();
    virtual const char* GetDiagnosticName();
};
DiagnosticForm* FUN_004839c0(unsigned int);
void FUN_0040fbe0(const char*, ...);
void FNV_Warning(const char*, ...);
struct SaveReference
{
    virtual void virtual_00();
    virtual void virtual_04();
    virtual void virtual_08();
    virtual void virtual_0c();
    virtual void virtual_10();
    virtual void virtual_14();
    virtual void virtual_18();
    virtual void virtual_1c();
    virtual void virtual_20();
    virtual void virtual_24();
    virtual void virtual_28();
    virtual void virtual_2c();
    virtual void virtual_30();
    virtual void virtual_34();
    virtual void virtual_38();
    virtual void virtual_3c();
    virtual void virtual_40();
    virtual void virtual_44();
    virtual void virtual_48();
    virtual void virtual_4c();
    virtual void virtual_50();
    virtual void virtual_54();
    virtual void virtual_58();
    virtual void virtual_5c();
    virtual void virtual_60();
    virtual void virtual_64();
    virtual void virtual_68();
    virtual void virtual_6c();
    virtual void virtual_70();
    virtual void virtual_74();
    virtual void virtual_78();
    virtual void virtual_7c();
    virtual void virtual_80();
    virtual void virtual_84();
    virtual void virtual_88();
    virtual void virtual_8c();
    virtual void virtual_90();
    virtual void virtual_94();
    virtual void virtual_98();
    virtual void virtual_9c();
    virtual void virtual_a0();
    virtual void virtual_a4();
    virtual void virtual_a8();
    virtual void virtual_ac();
    virtual void virtual_b0();
    virtual void virtual_b4();
    virtual void virtual_b8();
    virtual void virtual_bc();
    virtual void virtual_c0();
    virtual void virtual_c4();
    virtual void virtual_c8();
    virtual void virtual_cc();
    virtual void virtual_d0();
    virtual void virtual_d4();
    virtual void virtual_d8();
    virtual void virtual_dc();
    virtual void virtual_e0();
    virtual void virtual_e4();
    virtual void virtual_e8();
    virtual void virtual_ec();
    virtual void virtual_f0();
    virtual void virtual_f4();
    virtual void virtual_f8();
    virtual void virtual_fc();
    virtual bool IsActor();
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
    float referenceScale;
    void FUN_00484c20(unsigned int);
    void FUN_00484ce0(const void*, int);
    SaveExtras* FUN_005d43c0();
    unsigned short FUN_0055f880();
    void FUN_0055f900();
    unsigned short FUN_00560350(FUN_0055ebf0*);
    void FUN_005604b0(FUN_0055ebf0*);
    void FUN_0055e940(unsigned int flags);
};
}  // namespace fnv_0055e940

namespace fnv_0055ec40 {
struct LoadRecord
{
    unsigned int id;
    unsigned char type;
    unsigned char flags0, flags1, flags2, flags3;
    unsigned char version;
};
struct LoadForm
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
    virtual const char* describe();
};
LoadForm* __cdecl FUN_004839c0(unsigned int);
struct LoadExtra
{
    void FUN_0041aeb0();
    void FUN_004269c0(unsigned int, void*);
    void FUN_00424960(unsigned int, unsigned int, void*);
    bool FUN_0041b3a0(int);
    void FUN_0041b470(int);
    void FUN_0041b440(int);
    void FUN_00422920();
};
struct LoadLight
{
    unsigned int a, b;
    float c;
};
struct LoadObject;
struct LoadManager
{
    bool FUN_00862110();
    void FUN_008579e0(void*, unsigned int);
    LoadRecord* FUN_004fd3c0();
    unsigned char FUN_008df040();
    unsigned int FUN_00825c00();
    bool FUN_0047c850();
    void FUN_0085f2b0(LoadObject*, unsigned short);
    void FUN_0085f5a0(LoadObject*, unsigned short);
    void FUN_00857bd0(unsigned short);
};
extern LoadManager* g_TESSaveLoadGame;
void __cdecl FNV_Warning(const char*, ...);
struct LoadAux
{
    void FUN_004d3cc0();
};
LoadAux* __cdecl FUN_004bf220(LoadObject*);
extern const float DAT_01015f5c;
struct LoadObject
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual bool isActor();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void reset(int, bool);
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual bool actorState();
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
    float scale;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    LoadLight* light;
    void FUN_00484c50(unsigned int, unsigned int);
    void FUN_00484580(bool);
    LoadObject* FUN_0056a9f0();
    bool FUN_0056aa70();
    bool FUN_00440da0();
    bool FUN_00440d80();
    void FUN_00484af0(bool);
    void* FUN_0055d310();
    void FUN_00571b50();
    void FUN_004534f0(bool);
    void FUN_00483710();
    LoadExtra* FUN_005d43c0();
    void FUN_008adc50();
    void FUN_00484d00(void*, unsigned int);
    void FUN_00567490(float);
    void FUN_0055ec40(unsigned int flags, unsigned int more);
};
}  // namespace fnv_0055ec40

namespace fnv_0055f240 {
struct BaseForm
{
    unsigned int GetFormType();
};

struct MyExtraDataList : public ExtraDataList
{
    void FUN_004267d0(unsigned int changedFlags, void* ref);
    bool FUN_0041b3a0(int type);
    void FUN_0041b470(int type);
    void FUN_0041b440(int type);
};

struct MyModelLoader : public ModelLoader
{
    bool FUN_00445750(void* ref);
    void FUN_00444850(void* ref, void* cellData);
};
extern MyModelLoader* g_modelLoader;

struct MyTES : public TES
{
    void* FUN_00458be0(void* cell, int, int);
};
extern MyTES* g_TES;

struct TESSaveLoadGame
{
    bool GetLoading();
    bool FUN_00632ce0();
    bool FUN_0055f5b0();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

bool __fastcall FUN_00450ff0(void* cell);
bool __fastcall FUN_00450fb0(void* cell);
bool __cdecl FUN_0047a490(void* form);

struct BGSOpenCloseForm
{
    static bool SetOpenState(void* ref, bool b1, bool b2);
};

struct FUN_0055f240_Class
{
    virtual void pad000();
    virtual void pad004();
    virtual void pad008();
    virtual void pad00c();
    virtual void pad010();
    virtual void pad014();
    virtual void pad018();
    virtual void pad01c();
    virtual void pad020();
    virtual void pad024();
    virtual void pad028();
    virtual void pad02c();
    virtual void pad030();
    virtual void pad034();
    virtual void pad038();
    virtual void pad03c();
    virtual void pad040();
    virtual void pad044();
    virtual void pad048();
    virtual void pad04c();
    virtual void pad050();
    virtual void pad054();
    virtual void pad058();
    virtual void pad05c();
    virtual void pad060();
    virtual void pad064();
    virtual void pad068();
    virtual void pad06c();
    virtual void pad070();
    virtual void pad074();
    virtual void pad078();
    virtual void pad07c();
    virtual void pad080();
    virtual void pad084();
    virtual void pad088();
    virtual void pad08c();
    virtual void pad090();
    virtual void pad094();
    virtual void pad098();
    virtual void pad09c();
    virtual void pad0a0();
    virtual void pad0a4();
    virtual void pad0a8();
    virtual void pad0ac();
    virtual void pad0b0();
    virtual void pad0b4();
    virtual void pad0b8();
    virtual void pad0bc();
    virtual void pad0c0();
    virtual void pad0c4();
    virtual void pad0c8();
    virtual void pad0cc();
    virtual void pad0d0();
    virtual void pad0d4();
    virtual void pad0d8();
    virtual void pad0dc();
    virtual void pad0e0();
    virtual void pad0e4();
    virtual void pad0e8();
    virtual void pad0ec();
    virtual void pad0f0();
    virtual void pad0f4();
    virtual void pad0f8();
    virtual void pad0fc();
    virtual bool VFunc100();  // 0x100
    virtual void pad104();
    virtual void pad108();
    virtual void pad10c();
    virtual void pad110();
    virtual void pad114();
    virtual void pad118();
    virtual void pad11c();
    virtual void pad120();
    virtual void pad124();
    virtual void pad128();
    virtual void pad12c();
    virtual void pad130();
    virtual void pad134();
    virtual void pad138();
    virtual void pad13c();
    virtual void pad140();
    virtual void pad144();
    virtual void pad148();
    virtual void pad14c();
    virtual void pad150();
    virtual void pad154();
    virtual void pad158();
    virtual void pad15c();
    virtual void pad160();
    virtual void pad164();
    virtual void pad168();
    virtual void pad16c();
    virtual void pad170();
    virtual void pad174();
    virtual void pad178();
    virtual void pad17c();
    virtual void pad180();
    virtual void pad184();
    virtual void pad188();
    virtual void pad18c();
    virtual void pad190();
    virtual void pad194();
    virtual void pad198();
    virtual void pad19c();
    virtual void pad1a0();
    virtual void pad1a4();
    virtual void pad1a8();
    virtual void pad1ac();
    virtual void pad1b0();
    virtual void pad1b4();
    virtual void pad1b8();
    virtual void pad1bc();
    virtual void pad1c0();
    virtual void pad1c4();
    virtual void pad1c8();
    virtual void VFunc1cc(int, int);  // 0x1cc
    virtual void pad1d0();
    virtual void pad1d4();
    virtual void pad1d8();
    virtual void pad1dc();
    virtual void pad1e0();
    virtual void pad1e4();
    virtual void pad1e8();
    virtual void pad1ec();
    virtual void pad1f0();
    virtual void pad1f4();
    virtual void pad1f8();
    virtual void pad1fc();
    virtual void pad200();
    virtual void pad204();
    virtual void VFunc208(int);  // 0x208
    virtual void pad20c();
    virtual void pad210();
    virtual void pad214();
    virtual void pad218();
    virtual bool VFunc21c();  // 0x21c
    virtual void pad220();
    virtual void pad224();
    virtual void pad228();
    virtual bool VFunc22c(int);  // 0x22c

    void Revert(unsigned int changedFlags);
    void Func484580(int);
    bool GetDisabled();
    bool IsDeleted();
    void* Get3DSimple();
    void* GetParentCell();
    void FUN_0055f970();
    MyExtraDataList* GetExtraData();
    void FUN_00571b50();
    void FUN_00483710();
    void FUN_00574920(int);
    BaseForm* GetObjectReference();
    bool GetAction(int);
    void FUN_00577330(int);
    bool FUN_00477ba0();
    void FUN_00579ac0(bool);

    void FUN_0055f240(unsigned int changedFlags);
};

}  // namespace fnv_0055f240

class B55F900RTTI;
class B55F900Controller;

class B55F900AVObject
{
  public:
    B55F900Controller* GetController();
};

B55F900Controller* __cdecl B55F900DynamicCast(const B55F900RTTI* pkRTTI, B55F900Controller* pkObject);
void __cdecl FUN_0055fe70(B55F900Controller* pkController, float fTime);

extern const B55F900RTTI g_kB55F900RTTI;

class B55F900Ref
{
  public:
    B55F900AVObject* Get3DSimple();
    void FUN_0055f900();
};

struct Reference
{

    void FUN_00a59c60(void* position);
};
struct Effect
{

    void FUN_0098adb0(float magnitude);
    float FUN_00759450(int kind, int selector);
};
struct ResourceName;
struct EffectController
{
    Effect* FUN_0047a520(const ResourceName& name);
    void FUN_0048fef0(float value);
    void FUN_0047aa40(bool enabled);
    void FUN_0047aab0(Effect* effect, int a, int b, float c, float d, int e);
    Effect* FUN_00495d20(bool first);
};
struct ResourceName
{
    void* m_kStringBuffer;
    ResourceName(void* text);
    ~ResourceName();
};
struct Position
{
    float m_uiX, m_uiY, m_uiZ;
    void FUN_0043d410(float value);
};
struct DataHandle
{
};
struct PanelControl
{
    virtual void unusedSlot000();
    virtual void unusedSlot001();
    virtual void unusedSlot002();
    virtual void unusedSlot003();
    virtual void unusedSlot004();
    virtual void unusedSlot005();
    virtual void unusedSlot006();
    virtual void unusedSlot007();
    virtual void unusedSlot008();
    virtual void unusedSlot009();
    virtual void unusedSlot010();
    virtual void unusedSlot011();
    virtual void unusedSlot012();
    virtual void unusedSlot013();
    virtual void unusedSlot014();
    virtual void unusedSlot015();
    virtual void unusedSlot016();
    virtual void unusedSlot017();
    virtual void unusedSlot018();
    virtual void unusedSlot019();
    virtual void unusedSlot020();
    virtual void unusedSlot021();
    virtual void unusedSlot022();
    virtual void unusedSlot023();
    virtual void unusedSlot024();
    virtual void unusedSlot025();
    virtual void unusedSlot026();
    virtual void unusedSlot027();
    virtual void unusedSlot028();
    virtual void unusedSlot029();
    virtual void unusedSlot030();
    virtual void unusedSlot031();
    virtual void unusedSlot032();
    virtual void unusedSlot033();
    virtual void unusedSlot034();
    virtual void unusedSlot035();
    virtual void unusedSlot036();
    virtual void unusedSlot037();
    virtual void unusedSlot038();
    virtual void unusedSlot039();
    virtual void unusedSlot040();
    virtual void unusedSlot041();
    virtual void unusedSlot042();
    virtual void unusedSlot043();
    virtual void unusedSlot044();
    virtual void unusedSlot045();
    virtual void unusedSlot046();
    virtual void unusedSlot047();
    virtual void unusedSlot048();
    virtual void unusedSlot049();
    virtual void unusedSlot050();
    virtual void unusedSlot051();
    virtual void unusedSlot052();
    virtual void unusedSlot053();
    virtual void unusedSlot054();
    virtual void unusedSlot055();
    virtual void unusedSlot056();
    virtual void unusedSlot057();
    virtual void unusedSlot058();
    virtual void unusedSlot059();
    virtual void unusedSlot060();
    virtual void unusedSlot061();
    virtual void unusedSlot062();
    virtual void unusedSlot063();
    virtual void unusedSlot064();
    virtual void unusedSlot065();
    virtual void unusedSlot066();
    virtual void unusedSlot067();
    virtual void unusedSlot068();
    virtual void unusedSlot069();
    virtual void unusedSlot070();
    virtual void unusedSlot071();
    virtual void unusedSlot072();
    virtual void unusedSlot073();
    virtual void unusedSlot074();
    virtual void unusedSlot075();
    virtual void unusedSlot076();
    virtual void unusedSlot077();
    virtual void unusedSlot078();
    virtual void unusedSlot079();
    virtual void unusedSlot080();
    virtual void unusedSlot081();
    virtual void unusedSlot082();
    virtual void unusedSlot083();
    virtual void unusedSlot084();
    virtual void unusedSlot085();
    virtual void unusedSlot086();
    virtual void unusedSlot087();
    virtual void unusedSlot088();
    virtual void unusedSlot089();
    virtual void unusedSlot090();
    virtual void unusedSlot091();
    virtual void unusedSlot092();
    virtual void unusedSlot093();
    virtual void* GetActivationHandle(void* ref);
};
struct FNV_0055f970
{
    virtual void unusedSlot000();
    virtual void unusedSlot001();
    virtual void unusedSlot002();
    virtual void unusedSlot003();
    virtual void unusedSlot004();
    virtual void unusedSlot005();
    virtual void unusedSlot006();
    virtual void unusedSlot007();
    virtual void unusedSlot008();
    virtual void unusedSlot009();
    virtual void unusedSlot010();
    virtual void unusedSlot011();
    virtual void unusedSlot012();
    virtual void unusedSlot013();
    virtual void unusedSlot014();
    virtual void unusedSlot015();
    virtual void unusedSlot016();
    virtual void unusedSlot017();
    virtual void unusedSlot018();
    virtual void unusedSlot019();
    virtual void unusedSlot020();
    virtual void unusedSlot021();
    virtual void unusedSlot022();
    virtual void unusedSlot023();
    virtual void unusedSlot024();
    virtual void unusedSlot025();
    virtual void unusedSlot026();
    virtual void unusedSlot027();
    virtual void unusedSlot028();
    virtual void unusedSlot029();
    virtual void unusedSlot030();
    virtual void unusedSlot031();
    virtual void unusedSlot032();
    virtual void unusedSlot033();
    virtual void unusedSlot034();
    virtual void unusedSlot035();
    virtual void unusedSlot036();
    virtual void unusedSlot037();
    virtual void unusedSlot038();
    virtual void unusedSlot039();
    virtual void unusedSlot040();
    virtual void unusedSlot041();
    virtual void unusedSlot042();
    virtual void unusedSlot043();
    virtual void unusedSlot044();
    virtual void unusedSlot045();
    virtual void unusedSlot046();
    virtual void unusedSlot047();
    virtual void unusedSlot048();
    virtual void unusedSlot049();
    virtual void unusedSlot050();
    virtual void unusedSlot051();
    virtual void unusedSlot052();
    virtual void unusedSlot053();
    virtual void unusedSlot054();
    virtual void unusedSlot055();
    virtual void unusedSlot056();
    virtual void unusedSlot057();
    virtual void unusedSlot058();
    virtual void unusedSlot059();
    virtual void unusedSlot060();
    virtual void unusedSlot061();
    virtual void unusedSlot062();
    virtual void unusedSlot063();
    virtual void unusedSlot064();
    virtual void unusedSlot065();
    virtual void unusedSlot066();
    virtual void unusedSlot067();
    virtual void unusedSlot068();
    virtual void unusedSlot069();
    virtual void unusedSlot070();
    virtual void unusedSlot071();
    virtual void unusedSlot072();
    virtual void unusedSlot073();
    virtual void unusedSlot074();
    virtual void unusedSlot075();
    virtual void unusedSlot076();
    virtual void unusedSlot077();
    virtual void unusedSlot078();
    virtual void unusedSlot079();
    virtual void unusedSlot080();
    virtual void unusedSlot081();
    virtual void unusedSlot082();
    virtual void unusedSlot083();
    virtual void unusedSlot084();
    virtual void unusedSlot085();
    virtual void unusedSlot086();
    virtual void unusedSlot087();
    virtual void unusedSlot088();
    virtual void unusedSlot089();
    virtual void unusedSlot090();
    virtual void unusedSlot091();
    virtual void unusedSlot092();
    virtual void unusedSlot093();
    virtual void unusedSlot094();
    virtual void unusedSlot095();
    virtual void unusedSlot096();
    virtual void unusedSlot097();
    virtual void unusedSlot098();
    virtual void unusedSlot099();
    virtual void unusedSlot100();
    virtual void unusedSlot101();
    virtual void unusedSlot102();
    virtual void unusedSlot103();
    virtual void unusedSlot104();
    virtual void unusedSlot105();
    virtual void unusedSlot106();
    virtual void unusedSlot107();
    virtual void unusedSlot108();
    virtual void unusedSlot109();
    virtual void unusedSlot110();
    virtual void unusedSlot111();
    virtual void unusedSlot112();
    virtual void CloseInteraction();
    virtual void unusedSlot114();
    virtual void DispatchInteraction(void* handle, bool active);
    int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
    PanelControl* m_20;

    void FUN_0055f970();
};
struct Registry
{
    int m_uiContentCount;
};

extern "C" void* DAT_01197b5c;
extern "C" void* DAT_011977d8;
extern "C" void* DAT_01197820;
extern "C" float DAT_0102f510;
bool __cdecl FUN_004b5bf0(Reference*);
int __cdecl FUN_00404dc0(void*, void*);
EffectController* __cdecl FUN_00653270(Registry*, void*);

Reference* __fastcall FUN_0043fcd0(FNV_0055f970*);
void* __fastcall FUN_0043b230(Reference*);
void* __fastcall FUN_004228f0(DataHandle*);
int __fastcall FUN_008041a0(Effect*);

namespace fnv_0055fe70 {
struct TESSaveLoadGame
{
    unsigned short* ReserveCount();
    void FUN_008579b0(void* data, int size);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
extern float DAT_011c3c08;

struct ControllerSequence : public Idle_008b2010
{
    void SetOffset(float offset);
};

}  // namespace fnv_0055fe70

namespace fnv_00560350 {
struct PacketCallback
{
    unsigned int user;
    unsigned char active;
    unsigned int value;
    FUN_0055ebf0* packet;
    unsigned int position;
    unsigned int limit;
    unsigned int state;
};
extern unsigned char UNK_00560870;
unsigned int __cdecl FUN_004a8b00(void*);
void __cdecl FUN_00c68900(void*, PacketCallback*, unsigned char*);
struct FUN_00560350_Class
{
    void* FUN_0043fcd0();
    unsigned short FUN_00560350(FUN_0055ebf0* packet);
};

}  // namespace fnv_00560350

namespace fnv_00560530 {
struct RestoreRef;
struct Scene;
struct SavedState
{
    unsigned char flags;
    unsigned short count1, count2;
    RestoreRef* ref;
    Scene* scene;
    void* collision;
    SavedState();
};
struct UpdateState
{
    float time;
    bool a, b;
    unsigned int flags;
    UpdateState(float, bool, bool);
};
struct Scene
{
    void Update(UpdateState&);
};
struct Controller
{
    void Reset(bool);
};
struct AnimState
{
    void Set(int, float);
    void Refresh();
};
struct RestoreRef
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual bool slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual const char* slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual AnimState* slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual void slot125();
    virtual void slot126();
    virtual void slot127();
    virtual void slot128();
    virtual void slot129();
    virtual void slot130();
    virtual void slot131();
    virtual void slot132();
    virtual void slot133();
    virtual void slot134();
    virtual void slot135();
    virtual void slot136();
    virtual void slot137();
    virtual void slot138();
    virtual void slot139();
    virtual void slot140();
    virtual bool slot141();
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
    Controller* controller;
    void FUN_00560530(unsigned short);
    void Legacy(unsigned short);
    Scene* Get3D();
    void Read(void*, unsigned int);
    void Current(SavedState*);
    void Weapon(bool);
    unsigned int FormID();
};
struct Loader
{
    unsigned char Version();
    void Skip(unsigned int);
};
extern Loader* g_TESSaveLoadGame;
struct RestoreContext
{
    int unused;
    bool enabled;
    unsigned int mode;
    SavedState* saved;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};
struct RestoreObjects
{
    RestoreRef* ref;
    Scene* scene;
    void* collision;
};
extern int NiPoint3_ZERO;
void Warning(const char*, ...);
void* Collision(Scene*);
void ResetScene(Scene*, int*, bool, float, int);
void EnableScene(Scene*, int, bool, bool, bool);
void Visit(Scene*, RestoreContext*, void (*)(void*, RestoreContext*));
void RestoreCollision(void*, RestoreContext*);
void ActorScene(Scene*, bool, bool);
}  // namespace fnv_00560530

namespace fnv_00560e70 {
struct VecLoad
{
    float x, y, z;
    VecLoad();
    void Convert(const struct MatrixLoad&);
};
struct QuatLoad
{
    float x, y, z, w;
    QuatLoad();
    void Convert(const struct MatrixLoad&);
};
struct MatrixLoad
{
    float a, b, c, d, e, f, g, h, i;
};
struct NameLoad
{
    operator const char*() const;
};
struct NodeLoad
{
    NameLoad& GetName();
};
struct BodyLoad
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void* active();
    void FUN_00561580(bool);
    void FUN_005610f0(const VecLoad*);
    void FUN_00561150(const QuatLoad*);
    void FUN_005615d0(const VecLoad*);
    void FUN_00561630(const VecLoad*);
};
struct RefLoad
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual bool test();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual const VecLoad& position();
    MatrixLoad FUN_0056fa00();
};
struct CollisionLoad
{
    BodyLoad* FUN_006fa820();
    void FUN_004d9fa0(bool);
    NodeLoad* FUN_0044ddc0();
};
struct StateLoad
{
    unsigned char flags;
    RefLoad* unk04;
    RefLoad* ref;
    int unk0c;
    CollisionLoad* collision;
};
struct ContextLoad
{
    int unk00, unk04, unk08;
    StateLoad* state;
};
struct StreamLoad
{
    void FUN_008579e0(void*, unsigned int);
};
extern StreamLoad* g_TESSaveLoadGame;
extern int DAT_011f9140, DAT_012681c0;
extern VecLoad NiPoint3_ZERO;
bool FUN_0043b300(const void*, NodeLoad*);
BodyLoad* FUN_00653270(const void*, BodyLoad*);
int FUN_00408b20(const char*, const char*);
}  // namespace fnv_00560e70

struct BGSSaveFormBuffer;

struct BGSChangeFlags_s
{
    unsigned int flags;
    BGSChangeFlags_s(const BGSChangeFlags_s& o);
    bool Test(unsigned int mask);
};

struct BGSSaveFormBuffer
{
    BGSChangeFlags_s GetChangeFlags();
    void SaveData(void* data, int size, int unk);
    unsigned int GetPos();
    unsigned int GetSize();
    void SetChunk(unsigned int size, unsigned int pos);
};

struct ExtraDataList_s
{
    void SaveGame(BGSSaveFormBuffer* buf);
    int GetSaveObj();
};

struct InvChanges_s
{
    void SaveGame(BGSSaveFormBuffer* buf);
};

struct SubObj_s
{
    void* ptr;
    SubObj_s(int v);
    operator void*() const;
    void Save(BGSSaveFormBuffer* buf);
};

struct Refr_s
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf0a();
    virtual void vf0b();
    virtual void vf0c();
    virtual void vf0d();
    virtual void vf0e();
    virtual void vf0f();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf1a();
    virtual void vf1b();
    virtual void vf1c();
    virtual void vf1d();
    virtual void vf1e();
    virtual void vf1f();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf2a();
    virtual void vf2b();
    virtual void vf2c();
    virtual void vf2d();
    virtual void vf2e();
    virtual void vf2f();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf3a();
    virtual void vf3b();
    virtual void vf3c();
    virtual void vf3d();
    virtual void vf3e();
    virtual void vf3f();
    virtual bool IsActor();
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
    float m_fObjectScale;
    void FUN_00562230(BGSSaveFormBuffer* buf);
    void SaveGameBase(BGSSaveFormBuffer* buf);
    void SaveSub(BGSSaveFormBuffer* buf);
    void* Get3DSimple();
};

ExtraDataList_s* __fastcall GetExtraList(Refr_s* ref);
InvChanges_s* GetOrAddInventoryChanges(Refr_s* ref);

namespace fnv_00562de0 {
struct TargetRef
{
    void FUN_00865e50(FUN_00562e70* pData, int aU, int aV);
    void FUN_00865f60(unsigned int z9);
};

struct CallbackDesc
{
    unsigned int unk00;
    unsigned char bFlag;
    unsigned int nValue;
    void* pOwner;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};

void __cdecl FUN_00c68900(void* p, CallbackDesc* pDesc, void (*pfn)());
void FUN_00563220();

struct FUN_00562de0_cls
{
    int unk00;
    void* FUN_0043fcd0();
    void FUN_00562d20(FUN_00562e70* pData);
    void FUN_00562de0(TargetRef* pTarget);
};

}  // namespace fnv_00562de0

class TESForm;

int __fastcall FNV_GetFormType(TESForm* pForm);

struct RefStub_00564360
{
    TESForm* GetBaseObject();
};

RefStub_00564360* __cdecl LookupRef_00564360(void* pObj);

struct StubForm565
{
    unsigned int GetKind();
    unsigned int GetFormTypeID();
};

struct StubBaseData565
{
    bool IsFlagged();
};

struct StubActorBase565
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
    StubBaseData565 baseData;
};

struct StubCheck565
{
    bool IsValid();
};

struct StubTalkingActivator565
{
    static bool IsRadioStation(StubForm565* form, unsigned int flags);
};

struct StubRef565
{
    StubForm565* GetBase();
    int HasOther();
    bool FUN_00565260();
};

namespace fnv_005659f0 {
struct Actor79;
struct Node79;
struct Controller79;
struct Anim79;
struct Process79;
struct Item79;
struct Update79
{
    float time;
    int flags;
    bool extra;
    Update79(float, int, int);
};
struct Name79
{
    const char* text;
    Name79(const char*);
    ~Name79();
};
struct Flag79
{
    unsigned int value;
    Flag79(unsigned int);
    Flag79(const Flag79&);
};
struct Sequence79
{
    int FUN_0059bb30();
    void FUN_0098adb0(float);
    float FUN_00759450();
};
struct Controller79
{
    bool FUN_00566910();
    Sequence79* FUN_0047a520(const Name79&);
    void FUN_0047aab0(Sequence79*, int, int, float, float, int);
    void FUN_0047aa40(int);
    void FUN_0048fef0(float);
    Sequence79* FUN_00495d20(int);
};
struct Node79
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Node79* IsSceneNode();
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
    virtual void Update(const Update79&, int);
    Controller79* FUN_0043b230();
    void FUN_00a59c60(const Update79&);
    Node79* FUN_00a5c570(void*);
    void FUN_00566930(int);
};
struct ModelList79
{
    bool FUN_0047fd90();
    const char* FUN_00717e50(const char*);
};
struct Base79
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
    virtual const char* Name();
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
    ModelList79 models;
    int FUN_00401170();
    bool FUN_004c0bf0();
    unsigned int FUN_0084e3a0();
    void FUN_005fbdd0(Node79*);
};
struct Biped79
{
    void FUN_004aae70();
};
struct Anim79
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
    Anim79();
    bool FUN_0048ffd0(void*, Node79*, Actor79*, int);
    void FUN_00490330(const char*);
    void FUN_00491180(Actor79*, float, float);
    Node79* FUN_005585e0();
    Controller79* FUN_00496940();
};
struct Process79
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
    virtual void SetItem(Item79*, void*, int);
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
    virtual void SetAnimation(Controller79*, Node79*);
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
    virtual void Equip(bool, Biped79*, void*, Actor79*);
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
    virtual void* State();
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
    virtual void SetDrawn(Actor79*, int);
    virtual void v279();
    virtual void v280();
    virtual void v281();
    virtual void v282();
    virtual void v283();
    virtual void v284();
    virtual bool IsBusy(int);
    int FUN_0045cd60();
};
struct SavedAnim79
{
    int unk00, unk04, unk08, unk0c;
    float time;
};
struct Extra79
{
    SavedAnim79* FUN_00418200();
    void FUN_0041ae10();
};
struct Item79
{
    Base79* FUN_0044ddc0();
};
struct Inventory79
{
    Item79* FUN_004c8c10(int, int);
};
struct Equip79
{
    void FUN_0087b360(Base79*);
};
struct Game79
{
    bool FUN_0042ce10();
    unsigned char FUN_0084a6d0(Actor79*, Flag79);
};
extern Game79* DAT_011ddf38;
struct Actor79
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
    virtual void* Parent();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual Biped79* Biped();
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
    virtual bool WeaponDrawn();
    virtual bool IsDead();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Base79* base;
    Node79* FUN_0043fcd0();
    Anim79* FUN_00572e50(Anim79*);
    bool FUN_00440d80();
    const char* FUN_005715d0();
    void* FUN_008a1760();
    void FUN_005726e0(Node79*, int);
    void FUN_00484b90(unsigned int);
    Base79* FUN_007af430();
    bool FUN_00572d30(int);
    bool FUN_00561d90();
    void FUN_005710c0();
    void* FUN_00566970(void*);
    float FUN_00568ad0();
    Process79* FUN_008d8520();
    bool FUN_00566950();
    const char* FUN_0055d520();
    void FUN_00571760(Base79*);
    bool FUN_008a6970();
    Biped79* FUN_00950b00(int);
    void* FUN_00950a60(int);
    bool FUN_008a16d0();
    void* FUN_008b70d0();
    Extra79* FUN_005d43c0();
    void FUN_005659f0();
};
extern Actor79* DAT_011dea3c;
extern int DAT_011f36bc;
extern const char* DAT_011977d8;
extern const char* DAT_01197820;
struct Type79
{
    const char* name;
    int unk04, unk08;
};
extern Type79 DAT_01187004[];
extern float DAT_0102f510;
Controller79* FUN_00653270(void*, Controller79*);
bool FUN_0047a490(Base79*);
bool FUN_0047aec0(Actor79*, bool, int);
Inventory79* FUN_004bf220(Actor79*);
bool FUN_008c7aa0();
Actor79* FUN_0047b200();
Equip79* __stdcall FUN_004537b0(Actor79*);
const char* FUN_00ec6e30(const char*, int);
int FUN_00ec7ec0(const char*, const char*, int);
int FUN_00ec7750(const char*, const char*);
void FUN_00406d30(char*, unsigned int, const char*);
char* FUN_0040ab30(char*, int);
void __cdecl FUN_005b5e40(const char*, ...);
void* operator new(unsigned int);
void operator delete(void*);
}  // namespace fnv_005659f0

namespace fnv_00566970 {
struct Weapon62
{
    int FUN_00446390();
};
struct Item62
{
    Weapon62* FUN_0044ddc0();
};
struct Process62
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
    virtual Item62* Equipped();
    int FUN_0045cd60();
};
struct Model62
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual const char* Path();
};
struct Form62
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
    Model62 model;
    int FUN_00401170();
    unsigned int FUN_0084e3a0();
    int FUN_005f0cc0();
};
struct AnimationSet62
{
};
struct Manager62
{
    AnimationSet62* FUN_00447330(const char*, int, int, int);
    AnimationSet62* FUN_00447300(const char*, const char*, AnimationSet62*);
    void FUN_00447850(void*, AnimationSet62*);
};
struct Resource62
{
    void* FUN_00600700(const char*, int);
};
extern Manager62* DAT_011c3b3c;
extern Resource62* DAT_011cb6a0;
extern int DAT_0118a838[];
extern const char* DAT_011977a4[];
extern char DAT_01016fb4[];
extern char DAT_0101dccc[];
extern char DAT_01013444[];
extern char DAT_01016fa0[];
extern char DAT_01016f90[];
extern char DAT_01016f80[];
extern char DAT_01016f74[];
extern char DAT_01016f58[];
extern char DAT_01016f38[];
extern char DAT_01016f1c[];
extern char DAT_0102ffe4[];
extern char DAT_0102ffbc[];
extern char DAT_0102ff94[];
int FUN_00406d30(char*, unsigned int, const char*);
int FUN_00406d50(char*, unsigned int, const char*);
char* FUN_0040ab30(char*, int);
int __cdecl FUN_00ec623a(char*, const char*, ...);
struct Ref62
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
    virtual bool IsFemale(int);
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
    virtual bool IsFirstPerson(int);
    Form62* FUN_007af430();
    Process62* FUN_008d8520();
    bool FUN_008a6970();
    const char* FUN_005715d0();
    Weapon62* FUN_008a1710();
    AnimationSet62* FUN_00566970(int);
};
}  // namespace fnv_00566970

struct ExtraL;

struct Ref567b50
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
    virtual void v48(int);
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
    ExtraL* GetExtra();
};

struct Holder567b50
{
    Ref567b50* GetRef();
};

struct Self567b50 : public TESObjectREFR
{
    ExtraL* GetExtra();
    Holder567b50* FUN_00568e50();
    void FUN_00567b50(TESObjectREFR* param2);
};

struct FUN_00567c50_cls
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
    virtual void v48(unsigned int flags);

    void FUN_00567c50();
};

void* __fastcall FUN_00568e50(FUN_00567c50_cls* pThis);
void* __fastcall FUN_00559450(void* pThis);

extern "C" void* __cdecl _alloca(unsigned int);
struct MarkerPoint
{
    float x, y, z;
    MarkerPoint operator-(const MarkerPoint&) const;
    float Length() const;
};
struct MarkerMatrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
};
struct MarkerEntry
{
    unsigned int Kind();
    const MarkerPoint& Position();
    double Angle();
};
struct MarkerList
{
    unsigned int Count();
    MarkerEntry* At(unsigned int);
};
struct FurnitureBase
{
    int Type();
    bool Enabled(unsigned int);
};
struct MarkerExtra
{
    bool Test(int);
};
struct MarkerExtraList
{
    MarkerExtra* Extra(unsigned char);
};
struct MarkerOutput
{
    void Kind(unsigned int);
    void Position(const MarkerPoint&);
    void Angle(float);
};
MarkerList* __cdecl FindMarkers(void*);
bool __cdecl IsSit(unsigned int);
bool __cdecl IsSleep(unsigned int);
void __cdecl TransformMarkers(const MarkerMatrix&, const MarkerPoint&, unsigned int, const MarkerPoint*, MarkerPoint*);
struct MarkerRef
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void* Node();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual const MarkerPoint& Position();
    FurnitureBase* Base();
    bool Occupied(unsigned int, bool);
    MarkerMatrix Rotation();
    const MarkerPoint& Angles();
    MarkerExtraList* Extras();
    bool FUN_005686b0(const MarkerPoint&, bool, bool, MarkerOutput*, unsigned int*, bool);
};

class TESBoundObject
{
  public:
    virtual void BaseVirtual();
};
class TESHealthForm
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual unsigned int GetHealth();
};
struct ExtraHealth39
{
    int unk00, unk04, unk08;
    float health;
};
struct ExtraAccess39
{
    ExtraHealth39* FUN_00410220(unsigned char type);
    void FUN_00410020(ExtraHealth39* extra, bool remove);
    void FUN_00419970(float value);
};
struct Ref39
{
    TESBoundObject* FUN_007af430();
    ExtraAccess39* FUN_005d43c0();
    void FUN_00568bd0(float value);
};

typedef int(__thiscall* FUN_005692d0_VSlot)(void* self, unsigned char value);

class FUN_005692d0_item
{
  public:
    int FUN_00401170();
};

class FUN_005692d0_extra
{
  public:
    unsigned char FUN_00418b40();
};

class FUN_005692d0_cls
{
  public:
    FUN_005692d0_item* FUN_007af430();
    int FUN_005692d0();
};

struct TESForm;

struct RefrShell_569350 : public TESObjectREFR
{
    void FUN_00569350(TESForm* form);
};

struct TESBoundObject_569350
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
    virtual void v4a();
    virtual void v4b();
    virtual void v4c();
    virtual void v4d();
    virtual void v4e();
    virtual void v4f();
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
    virtual void v5a();
    virtual void v5b();
    virtual void v5c();
    virtual void v5d();
    virtual void v5e();
    virtual void v5f();
    virtual void v60();
    virtual bool v61(TESForm* form);
};

struct ExtraList_569350
{
    void SetByte(unsigned char value);
};

namespace fnv_00569670 {
struct NiRTTI;
extern NiPoint3 NiPoint3_ZERO;

struct XTransform
{
    NiPoint3 operator*(const NiPoint3& pt) const;
};

struct XObject
{
    int unk00;
};

struct XAVObject : XObject
{
    XTransform* GetWorldTransform();
};

struct GeomVertexAccess
{
    int unk00;
    int unk04;
    int unk08;
    GeomVertexAccess();
    void GetVertex(unsigned int index, NiPoint3& out);
};

struct XGeometryData
{
    bool LockVerts(int mode);
    void FillAccess(GeomVertexAccess* acc);
    void UnlockVerts();
};

struct XGeometry : XAVObject
{
    XGeometryData* GetModelData();
};

struct XTriBasedGeom : XGeometry
{
    unsigned short GetTriangleCount();
};

struct XNode : XAVObject
{
    unsigned int GetArrayCount();
    XAVObject* GetAt(unsigned int index);
};

struct PointTester
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
    virtual bool TestPoint(const NiPoint3& pt);
};

struct GlobalObject_00a7b610
{
    int unk00;
};
extern GlobalObject_00a7b610 g_011c7d34;
bool IsSkippedObject(GlobalObject_00a7b610* list, XAVObject* obj);

extern NiRTTI DAT_011f4acc;
extern NiRTTI DAT_011f4428;
XObject* NiDynamicCast(const NiRTTI* rtti, XObject* obj);

}  // namespace fnv_00569670

extern const char DAT_01030088;

struct FUN_00438170
{
    void* value;
    FUN_00438170(const char* value);
    ~FUN_00438170();
};

struct FNV_569BE0_Inner
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual int ProcessTemporary(const struct FUN_00438170& value);
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void ConsumeResult(int result);
};

struct FNV_569BE0_Node
{
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual FNV_569BE0_Inner* GetInner();
};

struct FNV_569BE0_This : Unknown
{
    void __thiscall FUN_00569be0(int ignored);
};

class NiFixedString
{
  public:
    NiFixedString(const char*);
    ~NiFixedString();
    void* m_kHandle;
};

struct ImageSpaceEffectParam
{
    ImageSpaceEffectParam(float, float, float, float);
    float r, g, b, a;
};

struct TargetPoint : public XPos
{
    TargetPoint operator-(const TargetPoint&) const;
    TargetPoint operator*(float) const;
};

struct TargetMatrix
{
    float m0, m1, m2, m3, m4, m5, m6, m7, m8;
    TargetMatrix FUN_004b45b0() const;
    TargetPoint FUN_004b4500(const TargetPoint*) const;
};

struct TargetNode;
struct TargetObj
{
    virtual void pad00();
    virtual void pad04();
    virtual void pad08();
    virtual TargetNode* GetAsNiNode();
    virtual void pad10();
    virtual void pad14();
    virtual void pad18();
    virtual void pad1c();
    virtual void pad20();
    virtual void pad24();
    virtual void pad28();
    virtual void pad2c();
    virtual void pad30();
    virtual void pad34();
    virtual void pad38();
    virtual void pad3c();
    virtual void pad40();
    virtual void pad44();
    virtual void pad48();
    virtual void pad4c();
    virtual void pad50();
    virtual void pad54();
    virtual void pad58();
    virtual void pad5c();
    virtual void pad60();
    virtual void pad64();
    virtual void pad68();
    virtual void pad6c();
    virtual void pad70();
    virtual void pad74();
    virtual void pad78();
    virtual void pad7c();
    virtual void pad80();
    virtual void pad84();
    virtual void pad88();
    virtual void pad8c();
    virtual void pad90();
    virtual void pad94();
    virtual void pad98();
    virtual TargetObj* GetObjectByName(const NiFixedString&);
    virtual void pada0();
    virtual void pada4();
    virtual void pada8();
    virtual void padac();
    virtual void padb0();
    virtual void padb4();
    virtual void padb8();
    virtual void padbc();
    virtual void padc0();
    virtual void padc4();
    virtual void padc8();
    virtual void padcc();
    virtual void padd0();
    virtual void padd4();
    virtual void padd8();
    virtual void AttachChildInAvailableSlot(TargetObj*, bool);
    virtual void pade0();
    virtual void pade4();
    virtual void InsertChild(TargetObj*);
};

struct Target3D
{
    virtual void pad00();
    virtual void pad04();
    virtual void pad08();
    virtual TargetNode* GetAsNiNode();
};

struct NiUpdateData
{
    NiUpdateData(float, bool, bool);
    float f0;
    int i1;
    int i2;
};

struct TargetNode : public TargetObj
{
    TargetNode(unsigned short = 0);
    void* operator new(size_t);
    static void operator delete(void*, unsigned int);
    void SetName(const NiFixedString&);
    void RemoveAllChildren();
    void FUN_00a5a040();
    void Update(const NiUpdateData&);
    void* p0;
    void* p1;
    void* p2;
    void* p3;
    void* p4;
    void* p5;
    void* p6;
    void* p7;
    void* p8;
    void* p9;
    void* pa;
    void* pb;
    void* pc;
    void* pd;
    void* pe;
    void* pf;
    void* p10;
    void* p11;
    void* p12;
    void* p13;
    void* p14;
    void* p15;
    void* p16;
    void* p17;
    void* p18;
    void* p19;
    void* p1a;
    void* p1b;
    void* p1c;
    void* p1d;
    void* p1e;
    void* p1f;
    void* p20;
    void* p21;
    void* p22;
    void* p23;
    void* p24;
    void* p25;
    void* p26;
    void* p27;
    void* p28;
    void* p29;
};

extern "C" TargetObj* __cdecl FUN_004b3890(const _NiPoint3_pod*, const ImageSpaceEffectParam*, const TargetPoint*,
                                           const ImageSpaceEffectParam*, int);

struct TargetRef;
struct FUN_0041e780_shell
{
    NodeEntry* FUN_0041e780();
};

struct FUN_005d43c0_
{
    FUN_0041e780_shell* FUN_005d43c0();
};

struct TargetRef : public XRef
{
    virtual TargetPoint* GetPos_125();
    TargetMatrix FUN_0056fa00();
    void FUN_00569df0(bool a2);
};

struct FUN_00569df0_Obj
{
    void FUN_00569df0(int a1);
};
struct FUN_0041eda0_shell
{
    void* FUN_0041eda0();
};
struct NodeLink_a1e0
{
    void* FUN_006815c0();
};
bool __fastcall FUN_008256d0(void* node);
void* __fastcall FUN_00726070(void* node);

struct Holder_a1e0
{
    void FUN_0056a1e0(unsigned char flag);
};

struct TimedAction
{
    void FUN_00573170(TESObjectREFR*, int, int, int);
};
struct TimedRecord
{
    TimedAction* action;
    float deadline;
};
struct TimedListEntry
{
    bool FUN_008256d0();
    TimedRecord** FUN_006815c0();
    TimedListEntry* FUN_00726070();
};
struct ExtraDataTiming
{
    TimedListEntry* FUN_0041eda0();
    float FUN_0041f020();
    void FUN_0041eff0(float);
};
extern Twin_0084d030 DAT_011f6394;
class FUN_0056a380_shell
{
  public:
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
    virtual void v4c(unsigned int);
    unsigned char FUN_0056a380();
};

class B56B250BoundObject
{
  public:
    float GetBoundSize();
};

class B56B250Ref
{
  public:
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
    virtual void VFunc0DC();
    virtual void VFunc0E0();
    virtual void VFunc0E4();
    virtual void VFunc0E8();
    virtual void VFunc0EC();
    virtual void VFunc0F0();
    virtual void VFunc0F4();
    virtual void VFunc0F8();
    virtual void VFunc0FC();
    virtual bool IsDisabledOrDeleted();

    bool FUN_00564e60();
    bool FUN_00444ed0();
    B56B250BoundObject* GetObjectReference();
    bool FUN_0056b250();
};

namespace BuildReferenceScene {
struct Node;
}
struct TESModel
{
    virtual void slot00();
};
struct TESModelTextureSwap : TESModel
{
    void FUN_0048afe0(BuildReferenceScene::Node*);
};
namespace BuildReferenceScene {
struct Reference;
struct Scene;
struct Node;
struct Base;
struct Extra;
struct Controller;
struct ReferenceListNode;
struct AttachedSceneProvider;
struct ScenePointer;
struct Vector
{
    float x, y, z;
    Vector();
    Vector(float, float, float);
    Vector FUN_00439ef0(const Vector&);
    void FUN_0063c8a0(const Vector&);
};
struct Matrix
{
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    Matrix();
    void FUN_004a0c90(float);
    Vector FUN_004b4500(const Vector&);
};
struct Update
{
    float time;
    unsigned int flags;
    unsigned int unk08;
    Update(float, int, int);
};
struct WorldPosition
{
    Vector* FUN_006815c0();
};
struct Node
{
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0c();
    virtual Node* Child();
};
struct Scene
{
    virtual void s0();
    virtual void s4();
    virtual void s8();
    virtual Node* AsNode();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5c();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6c();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7c();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8c();
    virtual void s90();
    virtual void s94();
    virtual void s98();
    virtual void s9c();
    virtual void sa0();
    virtual void sa4();
    virtual void sa8();
    virtual void sac();
    virtual void sb0();
    virtual void sb4();
    virtual void sb8();
    virtual void UpdateBounds();
    void FUN_00450f90(int);
    void FUN_0040f6e0();
    void FUN_00476ab0();
    void FUN_00440460(const Vector&);
    void FUN_0043fa80(const Matrix&);
    void FUN_00a59c60(const Update&);
    WorldPosition* FUN_0043d450();
    void FUN_0056c7d0(Reference*);
    void FUN_00440490(float);
    void FUN_00a5a040();
};
struct ScenePointer
{
    Scene* value;
    ScenePointer(Scene*);
    ~ScenePointer();
    bool FUN_00822510(int);
    Scene* FUN_00559450();
    void FUN_0066b0d0(Scene*);
};
struct TransformSource
{
    virtual void s00();
    virtual void Prepare();
    virtual void SetTransform(const float*);
    Scene* FUN_0056c7f0();
    void FUN_00413f90(float*);
};
struct Loaded
{
    int FUN_0059bb30();
};
struct Toggle
{
    void FUN_00937090(int);
};
struct LoadedState
{
    Toggle* FUN_0059bb30();
};
struct Cell
{
    LoadedState* FUN_004543c0();
};
struct Globals
{
    bool FUN_0042ce10();
    void FUN_0045ce40();
    bool FUN_00451530();
    AttachedSceneProvider* FUN_0070ec90(Reference*);
};
extern Globals* DAT_011ddf38;
extern Globals* DAT_011dea10;
struct Settings
{
    bool FUN_004b9930();
};
extern Settings DAT_011ca2dc;
struct CastType
{
};
extern CastType DAT_011831c4, DAT_011831e8;
struct GeometryController
{
    void FUN_0048afe0(Node*);
};
void* FUN_00ec43fb(void*, int, CastType*, CastType*, int);
struct Destructible
{
    void FUN_00477780(Base*);
    bool FUN_00476f50(Reference*, int);
};
struct EnableObject
{
    void FUN_00551480(int);
};
struct EnableData
{
    EnableObject* FUN_0043a2b0();
};
struct Body
{
    virtual void s00();
    virtual void s4();
    virtual void s8();
    virtual void sc();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5c();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6c();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7c();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8c();
    virtual void s90();
    virtual void s94();
    virtual void s98();
    virtual void s9c();
    virtual void sa0();
    virtual void sa4();
    virtual void sa8();
    virtual void sac();
    virtual void sb0();
    virtual void sb4();
    virtual void sb8();
    virtual void sbc();
    virtual void sc0();
    virtual void sc4();
    virtual void sc8();
    virtual void scc();
    virtual void sd0();
    virtual void sd4();
    virtual void SetFlag(bool, int);
};
struct SequenceTime
{
    float FUN_005f3780();
};
struct Sequence
{
    float FUN_00508100();
    void FUN_0098adb0(float);
    SequenceTime* FUN_0048f7f0(int);
};
struct Anim
{
    bool FUN_00494710(int);
    void FUN_004955c0(int, int, int, float, int);
    Sequence* FUN_00491040(int);
    void FUN_00491180(Reference*, float, float);
    void FUN_00493900(Reference*);
};
struct Physics
{
    void FUN_00c7c150(int);
};
struct Process
{
    virtual void s0();
    virtual void s4();
    virtual void s8();
    virtual void sc();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual void Update();
    int FUN_0045cd60();
    void FUN_008da1a0(Reference*);
};
struct LightData
{
    int unk00, unk04, unk08;
    LightData();
    ~LightData();
    bool FUN_00ad8ce0();
    void FUN_00ad8f20(Scene*);
};
struct ReferenceListNode
{
    Reference* data;
    ReferenceListNode* next;
    Reference** FUN_006815c0();
    ReferenceListNode* FUN_00726070();
};
struct GeometryType
{
    int FUN_008d8520();
};
struct SceneArray
{
    int FUN_0049c680(Scene* const&, int);
    void FUN_004ed8c0(Scene* const&);
};
struct Geometry
{
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
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
    unsigned char unk80, unk81, unk82, dirty;
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
    SceneArray scenes;
};
struct AttachedScene
{
    GeometryType* FUN_004030b0();
    Geometry* FUN_00a59d30(int);
};
struct AttachedSceneProvider
{
    AttachedScene* FUN_004e8030();
};
struct Manager
{
    void FUN_00b5eed0(Scene*);
};
Manager* FUN_00450b80(int);
struct ExtraLink
{
    int FUN_0057c6a0(const ScenePointer&, int);
    void FUN_0056c810(Scene*);
};
struct LinkPointer
{
    ExtraLink* FUN_0045c650();
    void FUN_0056c810(Scene*);
};
struct LinkedReference
{
    LinkPointer* FUN_005699b0();
};
struct ExtraAttachment
{
    void FUN_00437f90(Scene*);
};
struct Extra
{
    TransformSource* FUN_0041fbe0();
    float FUN_0041b6b0();
    void FUN_00422c20();
    void FUN_00422a40(Reference*);
    void FUN_00418890(LightData*);
    ReferenceListNode* FUN_0041f810();
    ReferenceListNode* FUN_0041f7e0();
    bool FUN_00420810();
    LinkedReference* FUN_004208b0();
};
struct Base
{
    virtual void s0();
    virtual void s4();
    virtual void s8();
    virtual void sc();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5c();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6c();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7c();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8c();
    virtual void s90();
    virtual void s94();
    virtual void s98();
    virtual void s9c();
    virtual void sa0();
    virtual void sa4();
    virtual void sa8();
    virtual bool Special();
    virtual void sb0();
    virtual void sb4();
    virtual void sb8();
    virtual void sbc();
    virtual void sc0();
    virtual void sc4();
    virtual void sc8();
    virtual void scc();
    virtual void sd0();
    virtual void sd4();
    virtual void sd8();
    virtual void sdc();
    virtual void se0();
    virtual void se4();
    virtual void se8();
    virtual void sec();
    virtual void sf0();
    virtual void sf4();
    virtual void sf8();
    virtual void sfc();
    virtual void s100();
    virtual void s104();
    virtual void s108();
    virtual void s10c();
    virtual void s110();
    virtual void s114();
    virtual void s118();
    virtual void s11c();
    virtual void s120();
    virtual void s124();
    virtual void s128();
    virtual void s12c();
    virtual void s130();
    virtual void s134();
    virtual void s138();
    virtual void s13c();
    virtual void s140();
    virtual void s144();
    virtual void s148();
    virtual void s14c();
    virtual void s150();
    virtual void s154();
    virtual void s158();
    virtual void s15c();
    virtual void s160();
    virtual void s164();
    virtual void s168();
    virtual void s16c();
    virtual void s170();
    virtual void s174();
    virtual Scene* Create(Reference*);
    int FUN_00401170();
    void FUN_006056f0(Reference*);
    bool FUN_00452440();
};
extern Base* DAT_011ca240;
extern Base* DAT_011ca220;
extern Base* DAT_011ca250;
extern const double DAT_01012060, DAT_01017a40;
extern const char DAT_010300b0[], DAT_01019f08[];
struct Finalizer
{
    void FUN_006c0c30();
};
Finalizer* __stdcall GetNavMeshObstacleManager(Reference*);
struct Reference
{
    virtual void s0();
    virtual void s4();
    virtual void s8();
    virtual void sc();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void SetState(int);
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5c();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6c();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7c();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8c();
    virtual void s90();
    virtual void s94();
    virtual void s98();
    virtual void s9c();
    virtual void sa0();
    virtual void sa4();
    virtual void sa8();
    virtual void sac();
    virtual void sb0();
    virtual void sb4();
    virtual bool FlagB8();
    virtual void sbc();
    virtual void sc0();
    virtual void sc4();
    virtual void sc8();
    virtual void scc();
    virtual void sd0();
    virtual void sd4();
    virtual void sd8();
    virtual void sdc();
    virtual void se0();
    virtual void se4();
    virtual void se8();
    virtual void sec();
    virtual void sf0();
    virtual void sf4();
    virtual void sf8();
    virtual void sfc();
    virtual bool IsActor();
    virtual void s104();
    virtual void s108();
    virtual void s10c();
    virtual void s110();
    virtual void s114();
    virtual void s118();
    virtual void s11c();
    virtual void s120();
    virtual void s124();
    virtual void s128();
    virtual void s12c();
    virtual const char* Name();
    virtual void s134();
    virtual void s138();
    virtual void s13c();
    virtual void s140();
    virtual void s144();
    virtual void s148();
    virtual void s14c();
    virtual bool Flag150();
    virtual void s154();
    virtual void s158();
    virtual bool Flag15C();
    virtual void s160();
    virtual void s164();
    virtual void s168();
    virtual void s16c();
    virtual void s170();
    virtual void s174();
    virtual void s178();
    virtual void s17c();
    virtual void s180();
    virtual void s184();
    virtual void s188();
    virtual void s18c();
    virtual void s190();
    virtual void s194();
    virtual void s198();
    virtual void s19c();
    virtual void s1a0();
    virtual void s1a4();
    virtual void s1a8();
    virtual void s1ac();
    virtual void s1b0();
    virtual void s1b4();
    virtual Body* GetBody(int);
    virtual void s1bc();
    virtual void s1c0();
    virtual void s1c4();
    virtual void s1c8();
    virtual void s1cc();
    virtual void* GetAttachment();
    virtual bool RandomPhase();
    virtual void s1d8();
    virtual void s1dc();
    virtual void s1e0();
    virtual Anim* ComputePositionAtTime();
    virtual void s1e8();
    virtual void s1ec();
    virtual void s1f0();
    virtual void s1f4();
    virtual void s1f8();
    virtual void s1fc();
    virtual void s200();
    virtual void s204();
    virtual void s208();
    virtual void s20c();
    virtual void s210();
    virtual void s214();
    virtual void s218();
    virtual void s21c();
    virtual void s220();
    virtual void s224();
    virtual void s228();
    virtual bool IsDead(int);
    virtual void s230();
    virtual void s234();
    virtual void s238();
    virtual void s23c();
    virtual void s240();
    virtual void s244();
    virtual void s248();
    virtual void s24c();
    virtual void s250();
    virtual void s254();
    virtual void s258();
    virtual void s25c();
    virtual void s260();
    virtual void s264();
    virtual void s268();
    virtual void s26c();
    virtual void s270();
    virtual void s274();
    virtual void s278();
    virtual void s27c();
    virtual void s280();
    virtual void s284();
    virtual void s288();
    virtual void s28c();
    virtual void s290();
    virtual void s294();
    virtual void s298();
    virtual void s29c();
    virtual void s2a0();
    virtual void s2a4();
    virtual void s2a8();
    virtual void s2ac();
    virtual void s2b0();
    virtual void s2b4();
    virtual void s2b8();
    virtual void s2bc();
    virtual void s2c0();
    virtual void s2c4();
    virtual void s2c8();
    virtual void s2cc();
    virtual void s2d0();
    virtual void s2d4();
    virtual void s2d8();
    virtual void s2dc();
    virtual void s2e0();
    virtual void s2e4();
    virtual void s2e8();
    virtual void s2ec();
    virtual void s2f0();
    virtual void s2f4();
    virtual void s2f8();
    virtual void s2fc();
    virtual void s300();
    virtual void s304();
    virtual void s308();
    virtual void s30c();
    virtual void s310();
    virtual void s314();
    virtual void s318();
    virtual void s31c();
    virtual void s320();
    virtual void s324();
    virtual void s328();
    virtual void s32c();
    virtual void s330();
    virtual void s334();
    virtual void s338();
    virtual void s33c();
    virtual void s340();
    virtual void s344();
    virtual void s348();
    virtual void s34c();
    virtual void s350();
    virtual void s354();
    virtual void s358();
    virtual void s35c();
    virtual void s360();
    virtual void s364();
    virtual void s368();
    virtual void s36c();
    virtual void s370();
    virtual void s374();
    virtual void s378();
    virtual void s37c();
    virtual void s380();
    virtual void s384();
    virtual void SetActorFlag(bool);
    virtual bool IsKnocked();
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkc;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    Base* base;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    Vector position;
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
    Physics* physics;
    bool FUN_00440da0();
    bool FUN_00440d80();
    Base* FUN_007af430();
    Cell* FUN_008d6f30();
    void FUN_0057c180();
    Scene* FUN_0043fcd0();
    Extra* FUN_005d43c0();
    void FUN_0056c880(int, bool);
    void FUN_00570f70(Scene*);
    bool FUN_0056c760();
    void FUN_0056c780(int);
    bool FUN_00452370();
    bool FUN_00508d70();
    void FUN_0057a3c0(int);
    TESModel* FUN_00571630();
    bool FUN_008d4ab0(Scene*);
    bool FUN_00448a20();
    Matrix FUN_0056fa00();
    bool FUN_00564cd0();
    EnableData* FUN_00568e50();
    float FUN_00567400();
    void FUN_005659f0();
    void FUN_008b0bd0(Scene*);
    Process* FUN_008d8520();
    void FUN_008d4b60();
    bool FUN_005722c0(int);
    Vector* FUN_00430830();
    void FUN_00577330(int);
    void UpdateLightDescriptors(int);
    void FUN_00576d50(Scene*);
    bool FUN_00565050();
    bool FUN_00564f00();
    ScenePointer* FUN_005725f0();
    bool FUN_004077c0();
    Scene* FUN_00569920();
    bool FUN_0057bd80(Scene*);
    int FUN_0084e3a0();
    ExtraAttachment* FUN_00527080(int);
    Scene* FUN_0056b2d0(unsigned char);
};
void FUN_00441780(Reference*, Scene*);
bool FUN_005784b0(Node*);
Destructible* FUN_00475400(Base*);
bool FUN_00477560(Scene*);
void FUN_004b7660(Scene*);
void FUN_00577e20(Scene*);
void FUN_00578300(Scene*);
unsigned int FUN_00487f50();
void FUN_005784f0(Node*, float);
void FUN_004b5b20(Scene*);
void FUN_00ba9120(Scene*, bool);
void FUN_00c6a040(Scene*, int, int, int);
void FUN_00c6bd00(Scene*, int);
void FUN_00b55b80(Scene*);
void FUN_00c9b670(Scene*, Vector*, int, float, int);
bool FUN_0062c3c0(Reference*, Scene*);
void FUN_00ba91a0(Scene*, int, int);
bool FUN_004f2640(Reference*);
void FUN_004f24e0(Reference*, int, int);
void FUN_004417c0();
void FUN_00406d00(char*, int, const char*, ...);
void FUN_005b5e40(const char*, ...);
void FUN_0055d6d0(Reference*, Scene*);

}

struct TransformMember
{
    void FUN_0056e270();
    void FUN_0056e120();
};
struct FUN_0056e0b0 : public FUN_0056e180
{
    unsigned int unk18;
    unsigned int unk1c;
    TransformMember transform;
    FUN_0056e0b0();
};
// @fnv 0x0056e0b0
FUN_0056e0b0::FUN_0056e0b0() : FUN_0056e180()
{
    transform.FUN_0056e270();
    transform.FUN_0056e120();
}

extern int DAT_01268208;

struct PhantomBase
{
    PhantomBase();
    virtual ~PhantomBase();
};

struct PhantomOwner
{
    struct FUN_0056e370 : public PhantomBase
    {
        FUN_0056e370();
        virtual ~FUN_0056e370();
        void FUN_0056e350();
    };
};

// Increments DAT_01268208 and calls FUN_0056e350 during construction of the PhantomOwner nested object.
// @fnv 0x0056e370
PhantomOwner::FUN_0056e370::FUN_0056e370()
{
    DAT_01268208 = DAT_01268208 + 1;
    FUN_0056e350();
}

namespace fnv_0056fcb0 {
// FUN_0056fcb0 v7 - hoisted body-scope decls + nested-guard tail
struct XObj;
struct XExtra;
struct ListNode;
struct Xtra;

struct L64
{
    int v;
    void FUN_0045cec0();
};

struct ArrObj
{
    XObj* arr[4];
};

struct Xtra
{
    int FUN_006629f0();
    XObj* FUN_0045c650(void* a1, GlobalObject_00633c90* a2);
    XObj* FUN_006ab360();
};

struct ListNode
{
    XObj** FUN_006815c0();
    ListNode* FUN_00726070();
};

struct XExtra
{
    ListNode* FUN_00420770();
    ListNode* FUN_0041f810();
    XObj* FUN_00420dd0();
    XObj* FUN_00420bc0(int a1);
    void FUN_00420da0(XObj* a1);
    XObj* FUN_00420ed0();
    XObj* FUN_00422120();
    XObj* FUN_00421e10();
    ArrObj* FUN_00420410();
    void FUN_0041f840(XObj* a1, int a2);
};

struct GObj
{
    void FUN_0045ce60();
    XObj* FUN_0070ec90();
};

extern GObj* DAT_011dea10;
extern XObj* DAT_011ca234;
extern XObj* DAT_011ca23c;

struct YObj
{
    void FUN_0057c730(void* a1);
};

struct Node38
{
    char pad[0x128];
    YObj sub;
};

struct XObj
{
    virtual void vtbl000();
    virtual void vtbl001();
    virtual void vtbl002();
    virtual void vtbl003();
    virtual void vtbl004();
    virtual void vtbl005();
    virtual void vtbl006();
    virtual void vtbl007();
    virtual void vtbl008();
    virtual void vtbl009();
    virtual void vtbl010();
    virtual void vtbl011();
    virtual void vtbl012();
    virtual void vtbl013();
    virtual void vtbl014();
    virtual void vtbl015();
    virtual void vtbl016();
    virtual void vtbl017();
    virtual void vtbl018();
    virtual void vtbl019();
    virtual void vtbl020();
    virtual void vtbl021();
    virtual void vtbl022();
    virtual void vtbl023();
    virtual void vtbl024();
    virtual void vtbl025();
    virtual void vtbl026();
    virtual void vtbl027();
    virtual void vtbl028();
    virtual void vtbl029();
    virtual void vtbl030();
    virtual void vtbl031();
    virtual void vtbl032();
    virtual void vtbl033();
    virtual void vtbl034();
    virtual void vtbl035();
    virtual void vtbl036();
    virtual void vtbl037();
    virtual void vtbl038();
    virtual void vtbl039();
    virtual void vtbl040();
    virtual void vtbl041();
    virtual void vtbl042();
    virtual void vtbl043();
    virtual void vtbl044();
    virtual void vtbl045();
    virtual void vtbl046();
    virtual void vtbl047();
    virtual void vtbl048();
    virtual void vtbl049();
    virtual void vtbl050();
    virtual void vtbl051();
    virtual void vtbl052();
    virtual void vtbl053();
    virtual void vtbl054();
    virtual void vtbl055();
    virtual void vtbl056();
    virtual void vtbl057();
    virtual void vtbl058();
    virtual void vtbl059();
    virtual void vtbl060();
    virtual void vtbl061();
    virtual void vtbl062();
    virtual void vtbl063();
    virtual void vtbl064();
    virtual void vtbl065();
    virtual void vtbl066();
    virtual void vtbl067();
    virtual void vtbl068();
    virtual void vtbl069();
    virtual void vtbl070();
    virtual void vtbl071();
    virtual void vtbl072();
    virtual void vtbl073();
    virtual void vtbl074();
    virtual void vtbl075();
    virtual void vtbl076();
    virtual void vtbl077();
    virtual void vtbl078();
    virtual void vtbl079();
    virtual void vtbl080();
    virtual void vtbl081();
    virtual void vtbl082();
    virtual void vtbl083();
    virtual void vtbl084();
    virtual void vtbl085();
    virtual void vtbl086();
    virtual void vtbl087();
    virtual void vtbl088();
    virtual void vtbl089();
    virtual void vtbl090();
    virtual void vtbl091();
    virtual void vtbl092();
    virtual void vtbl093();
    virtual void vtbl094();
    virtual void vtbl095();
    virtual void vtbl096();
    virtual void vtbl097();
    virtual void vtbl098();
    virtual void vtbl099();
    virtual void vtbl100();
    virtual void vtbl101();
    virtual void vtbl102();
    virtual void vtbl103();
    virtual void vtbl104();
    virtual void vtbl105();
    virtual void vtbl106();
    virtual void vtbl107();
    virtual void vtbl108();
    virtual void vtbl109();
    virtual void vtbl110();
    virtual void vtbl111();
    virtual void vtbl112();
    virtual void vtbl113();
    virtual void vtbl114();
    virtual void vtbl115();
    virtual int Virt1d0();
    char pad40[0x3C];
    XObj* m_40;
    XObj* FUN_007af430();
    int FUN_00401170();
    void FUN_0057b520(int a1);
    Xtra* FUN_005699b0();
    XExtra* FUN_005d43c0();
    XObj* FUN_005725f0();
    int FUN_00559450();
    XObj* FUN_008d6f30();
    XObj* FUN_004543c0();
    XObj* FUN_0045cd60();
    void FUN_0061f890(XObj* a1, int a2);
    XObj* FUN_004e8030(XObj* a1);
    void FUN_004e52f0(XObj* a1);
    XObj* FUN_004030b0();
    int FUN_008d8520();
    Node38* FUN_00a59d30(int a1);
    void FUN_00545360(XObj* a1);
    void FUN_005454f0(XObj* a1);
    XObj* FUN_0059bb30();
    void FUN_00631370(XObj* a1, int a2, int a3);
    void FUN_005456e0(XObj* a1);
    void FUN_006312d0(XObj* a1);
    XObj* FUN_009d9f20();
    void FUN_00c5b060(XObj* a1);
    void FUN_00c39ad0(XObj* a1);
    void FUN_00c5aec0(XObj* a1);
    void FUN_00c5b190(XObj* a1);
    void FUN_0057c730(void* a1);
    void FUN_009707f0(int a1);
    void FUN_00420ba0(int a1);
    void FUN_0057c5d0();
    void FUN_0056fcb0();
};

void FUN_00565670(XObj* a1);

}  // namespace fnv_0056fcb0

struct NiPoint3s
{
    float x;
    float y;
    float z;
};
struct WorldSpaceS;
struct CellS
{
    bool IsInteriorS();
    WorldSpaceS* GetWorldSpaceS();
};
struct RefS;
WorldSpaceS* __fastcall GetRefWorldSpaceS(RefS* ref);
struct RefS
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void vf116();
    virtual void vf117();
    virtual void vf118();
    virtual void vf119();
    virtual void vf120();
    virtual void vf121();
    virtual void vf122();
    virtual void vf123();
    virtual void vf124();
    virtual NiPoint3s* GetPosS();
    bool GetDisabledS();
    bool IsDeletedS();
    CellS* GetParentCellS();
    float GetDistanceS(NiPoint3s* pos);
    float FUN_005723b0(RefS* other, bool allowDisabled, bool ignoreCell);
};

class B5729E0Light;

class B5729E0LightExtra
{
  public:
    B5729E0Light* GetLight();
};

class B5729E0ExtraList
{
  public:
    B5729E0LightExtra* GetPortalLight();
    B5729E0LightExtra* GetLightExtra();
};

class B5729E0ShadowSceneNode
{
  public:
    void FUN_00b5eed0(B5729E0Light* pkLight);
};

B5729E0ShadowSceneNode* __cdecl FUN_00450b80(unsigned int uiIndex);

class B5729E0Ref
{
  public:
    B5729E0ExtraList* GetExtraData();
    void FUN_005729e0(bool bPortal);
};

namespace fnv_00572b60 {
struct Pt3
{
    float x;
    float y;
    float z;
    bool operator!=(const Pt3& other) const;
};

extern Pt3 NiPoint3_ZERO;

enum MEM_CONTEXT
{
    MC_0x31 = 0x31
};

struct AutoMemContext
{
    int unk00;
    AutoMemContext(MEM_CONTEXT ctx, bool b, const char* file, int line);
    ~AutoMemContext();
};

class TESObjectREFR572;

struct RefrUpdater
{
    float unk00;
    float unk04;
    float unk08;
    void ApplyPosition();
    void ApplyAngle();
};

class TESObjectREFR572
{
  public:
    virtual void Virtual000();
    virtual void Virtual001();
    virtual void Virtual002();
    virtual void Virtual003();
    virtual void Virtual004();
    virtual void Virtual005();
    virtual void Virtual006();
    virtual void Virtual007();
    virtual void Virtual008();
    virtual void Virtual009();
    virtual void Virtual00A();
    virtual void Virtual00B();
    virtual void Virtual00C();
    virtual void Virtual00D();
    virtual void Virtual00E();
    virtual void Virtual00F();
    virtual void Virtual010();
    virtual void Virtual011();
    virtual void Virtual012();
    virtual void Virtual013();
    virtual void Virtual014();
    virtual void Virtual015();
    virtual void Virtual016();
    virtual void Virtual017();
    virtual void Virtual018();
    virtual void Virtual019();
    virtual void Virtual01A();
    virtual void Virtual01B();
    virtual void Virtual01C();
    virtual void Virtual01D();
    virtual void Virtual01E();
    virtual void Virtual01F();
    virtual void Virtual020();
    virtual void Virtual021();
    virtual void Virtual022();
    virtual void Virtual023();
    virtual void Virtual024();
    virtual void Virtual025();
    virtual void Virtual026();
    virtual void Virtual027();
    virtual void Virtual028();
    virtual void Virtual029();
    virtual void Virtual02A();
    virtual void Virtual02B();
    virtual void Virtual02C();
    virtual void Virtual02D();
    virtual void Virtual02E();
    virtual void Virtual02F();
    virtual void Virtual030();
    virtual void Virtual031();
    virtual void Virtual032();
    virtual void Virtual033();
    virtual void Virtual034();
    virtual void Virtual035();
    virtual void Virtual036();
    virtual void Virtual037();
    virtual void Virtual038();
    virtual void Virtual039();
    virtual void Virtual03A();
    virtual void Virtual03B();
    virtual void Virtual03C();
    virtual void Virtual03D();
    virtual void Virtual03E();
    virtual void Virtual03F();
    virtual void Virtual040();
    virtual void Virtual041();
    virtual void Virtual042();
    virtual void Virtual043();
    virtual void Virtual044();
    virtual void Virtual045();
    virtual void Virtual046();
    virtual void Virtual047();
    virtual void Virtual048();
    virtual void Virtual049();
    virtual void Virtual04A();
    virtual void Virtual04B();
    virtual void Virtual04C();
    virtual void Virtual04D();
    virtual void Virtual04E();
    virtual void Virtual04F();
    virtual void Virtual050();
    virtual void Virtual051();
    virtual void Virtual052();
    virtual void Virtual053();
    virtual void Virtual054();
    virtual void Virtual055();
    virtual void Virtual056();
    virtual void Virtual057();
    virtual void Virtual058();
    virtual void Virtual059();
    virtual void Virtual05A();
    virtual void Virtual05B();
    virtual void Virtual05C();
    virtual void Virtual05D();
    virtual void Virtual05E();
    virtual void Virtual05F();
    virtual void Virtual060();
    virtual void Virtual061();
    virtual void Virtual062();
    virtual void Virtual063();
    virtual void Virtual064();
    virtual void Virtual065();
    virtual void Virtual066();
    virtual void Virtual067();
    virtual void Virtual068();
    virtual void Virtual069();
    virtual void Virtual06A();
    virtual void Virtual06B();
    virtual void Virtual06C();
    virtual void Virtual06D();
    virtual void Virtual06E();
    virtual void Virtual06F();
    virtual void Virtual070();
    virtual void Virtual071();
    virtual void Virtual072();
    virtual void Virtual073();
    virtual void Virtual074();
    virtual void Virtual075();
    virtual void Virtual076();
    virtual void Virtual077();
    virtual void Virtual078();
    virtual void Virtual079();
    virtual void Virtual07A();
    virtual void Virtual07B();
    virtual void Virtual07C();
    virtual const Pt3* GetPos();
    const Pt3& GetAngleOnReference() const;
    RefrUpdater MakeUpdater(TESObjectREFR572* ref, Pt3 pt);
    void FUN_00572b60(Pt3 pos);
};

}  // namespace fnv_00572b60

struct FUN_00572fc0_shell : public TESObjectREFR
{
    void FUN_00572fc0(int a, int b, int c, int d, unsigned char e);
};

struct FUN_0042e820_Obj
{
    FUN_0042e820_Obj* FUN_0042e820();
    void FUN_00430410(TESObjectREFR* pRef, int a, unsigned char b);
    void FUN_00437730(int a);
    void FUN_00600ab0(int a);
    void FUN_00984f60(unsigned int a);
};

namespace fnv_00573170 {
struct ActRef;

struct ActForm
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
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual bool Activate(struct ActRef* apRef, struct ActRef* apActivator, bool abFlag, ActForm* apObject,
                          int aiCount);
    int GetFormType();
    const char* GetEditorName();
};

struct ActProcess
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
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual void v1F4();
    virtual void v1F8();
    virtual void v1FC();
    virtual void v200();
    virtual void v204();
    virtual void v208();
    virtual void v20C();
    virtual void v210();
    virtual void v214();
    virtual void v218();
    virtual void v21C();
    virtual void v220();
    virtual void v224();
    virtual void v228();
    virtual void v22C();
    virtual void v230();
    virtual void v234();
    virtual void v238();
    virtual void v23C();
    virtual void v240();
    virtual void v244();
    virtual void v248();
    virtual void v24C();
    virtual void v250();
    virtual void v254();
    virtual void v258();
    virtual void v25C();
    virtual void v260();
    virtual void v264();
    virtual void v268();
    virtual void v26C();
    virtual void v270();
    virtual void v274();
    virtual void v278();
    virtual void v27C();
    virtual void v280();
    virtual void v284();
    virtual void v288();
    virtual void v28C();
    virtual void v290();
    virtual void v294();
    virtual void v298();
    virtual void v29C();
    virtual void v2A0();
    virtual void v2A4();
    virtual void v2A8();
    virtual void v2AC();
    virtual void v2B0();
    virtual void v2B4();
    virtual void v2B8();
    virtual void v2BC();
    virtual void v2C0();
    virtual void v2C4();
    virtual void v2C8();
    virtual void v2CC();
    virtual void v2D0();
    virtual void v2D4();
    virtual void v2D8();
    virtual void v2DC();
    virtual void v2E0();
    virtual void v2E4();
    virtual void v2E8();
    virtual void v2EC();
    virtual void v2F0();
    virtual void v2F4();
    virtual void v2F8();
    virtual void v2FC();
    virtual void v300();
    virtual void v304();
    virtual void v308();
    virtual void v30C();
    virtual void v310();
    virtual void v314();
    virtual void v318();
    virtual void v31C();
    virtual void v320();
    virtual void v324();
    virtual void v328();
    virtual void v32C();
    virtual void v330();
    virtual void v334();
    virtual void v338();
    virtual void v33C();
    virtual void v340();
    virtual void v344();
    virtual void v348();
    virtual void v34C();
    virtual void v350();
    virtual void v354();
    virtual void v358();
    virtual void v35C();
    virtual void v360();
    virtual void v364();
    virtual void v368();
    virtual void v36C();
    virtual void v370();
    virtual void v374();
    virtual void v378();
    virtual void v37C();
    virtual void v380();
    virtual void v384();
    virtual void v388();
    virtual void v38C();
    virtual void v390();
    virtual void v394();
    virtual void v398();
    virtual void v39C();
    virtual void v3A0();
    virtual void v3A4();
    virtual void v3A8();
    virtual void v3AC();
    virtual void v3B0();
    virtual void v3B4();
    virtual void v3B8();
    virtual void v3BC();
    virtual void v3C0();
    virtual void v3C4();
    virtual void v3C8();
    virtual void v3CC();
    virtual void v3D0();
    virtual void v3D4();
    virtual void v3D8();
    virtual void v3DC();
    virtual void v3E0();
    virtual void v3E4();
    virtual void v3E8();
    virtual void v3EC();
    virtual void v3F0();
    virtual void v3F4();
    virtual void v3F8();
    virtual void v3FC();
    virtual void v400();
    virtual void v404();
    virtual void v408();
    virtual void v40C();
    virtual void v410();
    virtual void v414();
    virtual void v418();
    virtual void v41C();
    virtual void v420();
    virtual void v424();
    virtual void v428();
    virtual void v42C();
    virtual void v430();
    virtual void v434();
    virtual void v438();
    virtual void v43C();
    virtual void v440();
    virtual void v444();
    virtual void v448();
    virtual void v44C();
    virtual void v450();
    virtual void v454();
    virtual void v458();
    virtual void v45C();
    virtual void v460();
    virtual void v464();
    virtual void v468();
    virtual void v46C();
    virtual void v470();
    virtual void v474();
    virtual void v478();
    virtual void v47C();
    virtual void v480();
    virtual void v484();
    virtual void v488();
    virtual void v48C();
    virtual void v490();
    virtual void v494();
    virtual void v498();
    virtual void v49C();
    virtual void v4A0();
    virtual void v4A4();
    virtual void v4A8();
    virtual void v4AC();
    virtual void v4B0();
    virtual void v4B4();
    virtual void v4B8();
    virtual void v4BC();
    virtual void v4C0();
    virtual void v4C4();
    virtual void v4C8();
    virtual void v4CC();
    virtual void v4D0();
    virtual void v4D4();
    virtual void v4D8();
    virtual void v4DC();
    virtual void v4E0();
    virtual void v4E4();
    virtual void v4E8();
    virtual void v4EC();
    virtual void v4F0();
    virtual void v4F4();
    virtual void v4F8();
    virtual void v4FC();
    virtual void v500();
    virtual void v504();
    virtual void v508();
    virtual void v50C();
    virtual void v510();
    virtual void v514();
    virtual void v518();
    virtual void v51C();
    virtual void v520();
    virtual void v524();
    virtual void v528();
    virtual void v52C();
    virtual void v530();
    virtual void v534();
    virtual void v538();
    virtual void v53C();
    virtual void v540();
    virtual void v544();
    virtual void v548();
    virtual void v54C();
    virtual void v550();
    virtual void v554();
    virtual void v558();
    virtual void v55C();
    virtual void v560();
    virtual void v564();
    virtual void v568();
    virtual void v56C();
    virtual void v570();
    virtual void v574();
    virtual void v578();
    virtual void v57C();
    virtual void v580();
    virtual void v584();
    virtual void v588();
    virtual void v58C();
    virtual void v590();
    virtual void v594();
    virtual void v598();
    virtual void v59C();
    virtual void v5A0();
    virtual void v5A4();
    virtual void v5A8();
    virtual void v5AC();
    virtual void v5B0();
    virtual void v5B4();
    virtual void v5B8();
    virtual void v5BC();
    virtual void v5C0();
    virtual void v5C4();
    virtual void v5C8();
    virtual void v5CC();
    virtual void v5D0();
    virtual void v5D4();
    virtual void v5D8();
    virtual void v5DC();
    virtual void v5E0();
    virtual void v5E4();
    virtual void v5E8();
    virtual void v5EC();
    virtual void v5F0();
    virtual void v5F4();
    virtual void v5F8();
    virtual void v5FC();
    virtual void v600();
    virtual void v604();
    virtual void v608();
    virtual void v60C();
    virtual int GetKnockedState();
    void* GetDetectionData();
};

struct ActCell
{
    bool IsInterior();
    void UpdateDoorEvent();
};

struct ActTeleport
{
    ActCell* GetDestinationCell();
};

struct ActExtraList
{
    ActRef* GetLinkedRef();
    bool HasLock();
    void* CanUnlock(ActRef* apActivator);
    void SetLastActivator(ActRef* apRef, ActRef* apActivator);
    void SetFlag(int aiFlag);
};

struct ActSetting
{
    const char* GetString();
};

struct ActRef
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
    virtual void v09C();
    virtual void v0A0();
    virtual void v0A4();
    virtual void v0A8();
    virtual void v0AC();
    virtual void v0B0();
    virtual void v0B4();
    virtual void v0B8();
    virtual void v0BC();
    virtual void v0C0();
    virtual void v0C4();
    virtual void v0C8();
    virtual void v0CC();
    virtual void v0D0();
    virtual void v0D4();
    virtual void v0D8();
    virtual void v0DC();
    virtual void v0E0();
    virtual void v0E4();
    virtual void v0E8();
    virtual void v0EC();
    virtual void v0F0();
    virtual void v0F4();
    virtual void v0F8();
    virtual void v0FC();
    virtual bool IsActor();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual bool IsInCombatOrSneaking(int aiUnk);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    ActForm* pBaseForm;

    ActForm* GetBaseForm();
    ActExtraList* GetExtraList();
    ActProcess* GetCurrentProcess();
    bool IsPersistentLocked();
    const char* GetFullName();
    bool IsDisabledActivation();
    bool GetAction(int aiAction);
    void PerformAction(int aiAction);
    void RunActivateScript(ActRef* apActivator);
    void RunOnActivateBlock();
    ActTeleport* GetTeleportData();
    void HandleActivation(ActRef* apActivator);
    bool FUN_00573170(ActRef* apActivator, bool abFlag, ActForm* apObject, int aiCount);
};

struct ActActor : ActRef
{
    void OnActivated(ActRef* apRef, ActForm* apObject, int aiCount, bool abFlag);
};

struct ActPlayer : ActRef
{
    bool IsWaitingOrSleeping();
    bool IsInPipboy();
    bool CanActivate(ActRef* apRef);
    void OnActivateRef(ActRef* apRef);
};

extern ActForm* g_pActDummyActivator1;
extern ActForm* g_pActDummyActivator2;
extern ActPlayer* g_pActPlayer;
extern bool g_bActActivated;
extern int g_iActRecursion;
extern float g_fActMessageTime;
extern ActSetting g_kActSettingCantActivate;
extern ActSetting g_kActSettingLocked;

bool __cdecl ActIsMenuMode();
ActRef* __cdecl ActGetConsoleRef();
const char* __cdecl ActGetFullName(ActForm* apForm);
const char* __cdecl ActPrepareScriptMessage(const char* apText, bool abFlag);
bool __cdecl ActQueueUIMessage(const char* apMessage, int aiType, const char* apIcon, const char* apSound, float afTime,
                               bool abFlag);
extern "C" int __cdecl sprintf(char* apBuffer, const char* apFormat, ...);
void __cdecl ActDebugLog(const char* apFormat, ...);

}  // namespace fnv_00573170

namespace fnv_00573800 {
struct MoveRef;
struct MoveCell;
struct MoveWorld;
struct MoveProcess;
struct MoveController;
struct MovePoint
{
    float x, y, z;
};
struct MoveAnim
{
    bool active();
    void enable(bool);
};
struct MoveBody
{
    MoveAnim* name();
};
struct MoveExtra
{
    void clear();
    void* original();
    void set(MoveRef*);
};
struct MoveController
{
    void height(float);
    void position(MovePoint*);
};
struct MoveCell
{
    bool interior();
    void add(MoveRef*, bool);
    void remove(MoveRef*);
};
struct MoveWorld
{
    void remove(MoveRef*);
    void add(MoveRef*);
    MoveCell* cell(int, int);
};
struct MoveRef
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void changed(int);
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void clearFlag(int);
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual bool actor();
    virtual bool player();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual void unused74();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();
    virtual void unused80();
    virtual void unused81();
    virtual void unused82();
    virtual void unused83();
    virtual void unused84();
    virtual void unused85();
    virtual void unused86();
    virtual void unused87();
    virtual void unused88();
    virtual void unused89();
    virtual void unused90();
    virtual void unused91();
    virtual void unused92();
    virtual void unused93();
    virtual void unused94();
    virtual void unused95();
    virtual void unused96();
    virtual void unused97();
    virtual void unused98();
    virtual void unused99();
    virtual void unused100();
    virtual void unused101();
    virtual void unused102();
    virtual void unused103();
    virtual void unused104();
    virtual void unused105();
    virtual void unused106();
    virtual void unused107();
    virtual void unused108();
    virtual void unused109();
    virtual void unused110();
    virtual void unused111();
    virtual void notify();
    virtual void load();
    virtual void unused114();
    virtual void unload(int, int);
    virtual MoveBody* body();
    virtual void unused117();
    virtual void unused118();
    virtual void unused119();
    virtual void unused120();
    virtual void unused121();
    virtual void unused122();
    virtual void unused123();
    virtual void unused124();
    virtual MovePoint* position();
    virtual void unused126();
    virtual void update(int);
    virtual void unused128();
    virtual void unused129();
    virtual void unused130();
    virtual void unused131();
    virtual void unused132();
    virtual void unused133();
    virtual void unused134();
    virtual void unused135();
    virtual void unused136();
    virtual void unused137();
    virtual void setCell(MoveCell*);
    virtual bool test(int);
    MoveController* controller();
    MoveWorld* world();
    MoveCell* cell();
    MoveExtra* extra();
    bool persistent();
    MoveProcess* process();
    int state();
    bool sleeping();
};
struct MoveProcess
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void FlushUsageData();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void reset();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void unused56();
    virtual void unused57();
    virtual void unused58();
    virtual void unused59();
    virtual void unused60();
    virtual void unused61();
    virtual void unused62();
    virtual void unused63();
    virtual void unused64();
    virtual void unused65();
    virtual void unused66();
    virtual void unused67();
    virtual void unused68();
    virtual void unused69();
    virtual void unused70();
    virtual void unused71();
    virtual void unused72();
    virtual void unused73();
    virtual void unused74();
    virtual void unused75();
    virtual void unused76();
    virtual void unused77();
    virtual void unused78();
    virtual void unused79();
    virtual void unused80();
    virtual void unused81();
    virtual void unused82();
    virtual void unused83();
    virtual void unused84();
    virtual void unused85();
    virtual void unused86();
    virtual void unused87();
    virtual void unused88();
    virtual void unused89();
    virtual void unused90();
    virtual void unused91();
    virtual void unused92();
    virtual void unused93();
    virtual void unused94();
    virtual void unused95();
    virtual void unused96();
    virtual void unused97();
    virtual void unused98();
    virtual void unused99();
    virtual void unused100();
    virtual void unused101();
    virtual void unused102();
    virtual void unused103();
    virtual void unused104();
    virtual void unused105();
    virtual void unused106();
    virtual void unused107();
    virtual void unused108();
    virtual void unused109();
    virtual void unused110();
    virtual void unused111();
    virtual void unused112();
    virtual void unused113();
    virtual void unused114();
    virtual void unused115();
    virtual void unused116();
    virtual void unused117();
    virtual void unused118();
    virtual void unused119();
    virtual void unused120();
    virtual void unused121();
    virtual void unused122();
    virtual void unused123();
    virtual void unused124();
    virtual void unused125();
    virtual void unused126();
    virtual void unused127();
    virtual void unused128();
    virtual void unused129();
    virtual void unused130();
    virtual void unused131();
    virtual void unused132();
    virtual void unused133();
    virtual void unused134();
    virtual void unused135();
    virtual void unused136();
    virtual void unused137();
    virtual void unused138();
    virtual void unused139();
    virtual void unused140();
    virtual void unused141();
    virtual void unused142();
    virtual void unused143();
    virtual void unused144();
    virtual void unused145();
    virtual void unused146();
    virtual void unused147();
    virtual void unused148();
    virtual void unused149();
    virtual void unused150();
    virtual void unused151();
    virtual void unused152();
    virtual void unused153();
    virtual void unused154();
    virtual void unused155();
    virtual void unused156();
    virtual void unused157();
    virtual void unused158();
    virtual void unused159();
    virtual void unused160();
    virtual void unused161();
    virtual void unused162();
    virtual void* ready();
    int level();
};
struct MoveResetProcess : MoveProcess
{
};
struct MoveTES
{
    bool attached(MoveCell*, bool);
};
extern MoveTES* g_TES;
struct MoveQueue
{
    void update(MoveRef*);
    void notify(MoveRef*);
    void load(MoveRef*);
};
MoveQueue* queue();
bool threaded();
struct MoveLists
{
    void remove(MoveRef*);
};
struct MoveSave
{
    bool loading();
    bool save(MoveRef*);
};
extern MoveSave* g_TESSaveLoadGame;
struct MoveBGSSave
{
    void save(MoveRef*, int);
};
extern MoveRef* _g_thePlayer;
bool __fastcall cellReady(MoveCell*);
int TruncateFloatToInt(float);
}  // namespace fnv_00573800

namespace fnv_00574b30 {
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
struct RefOps;
struct ExtraOps;
struct EntryOps;
struct ListOps;
struct ScriptOps;
struct NodeOps
{
    ExtraOps** FUN_006815c0();
};
struct DataOps
{
    NodeOps* FUN_00559450();
};
struct FUN_004bc650 : DataOps
{
    int unk00, unk04, unk08;
    FUN_004bc650(void*);
};
struct FUN_00410360
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    FUN_00410360();
    void FUN_00419ad0(unsigned short);
    ScriptOps* FUN_00418800();
    void FUN_00419ed0(ScriptOps*);
    void FUN_00419f80(void*);
    void* FUN_00418830();
};
struct FUN_0055a2f0
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual ~FUN_0055a2f0();
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
    FUN_0055a2f0();
    void FUN_00484490();
};
struct ScriptOps
{
    void* FUN_005abf60();
    bool FUN_005ac1e0(FUN_0055a2f0*, void*, int, bool);
};
struct ExtraOps
{
    void FUN_0041c7f0(RefOps*);
};
struct EntryOps
{
    EntryOps* GetOrFallback(int);
    EntryOps* FUN_004fd400();
    bool FUN_004c0bf0();
    EntryOps* FUN_00525980(RefOps*);
};
struct ListOps
{
    void FUN_004c3380(FUN_004bc650*, bool);
    void FUN_004c29a0(EntryOps*, FUN_00410360*, bool);
    void FUN_004c1c90(RefOps*, int, bool, bool);
};
struct RefOps
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048(unsigned int);
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool v100();
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
    virtual bool v224();
    void* FUN_0055d310();
    bool FUN_00440da0();
    RefOps* FUN_008d6f30();
    bool FUN_005656d0();
    void FUN_00545560(RefOps*);
    void* FUN_007af430();
    ExtraOps* FUN_005d43c0();
    void* FUN_009d9f00();
    EntryOps* FUN_00476c90();
    bool FUN_005653d0();
    void FUN_00574b30(RefOps*, int, bool, bool);
};
extern RefOps* DAT_011dea3c;
void __cdecl FUN_005f5950(int, int, void*, int, int, int, int);
void __cdecl FUN_005ac750(RefOps*, void*, int);
ListOps* __cdecl FUN_004bf220(RefOps*);
ScriptOps* __cdecl FUN_004826d0(EntryOps*);
}  // namespace fnv_00574b30

struct Unknown;
struct FUN_00575650_Result
{
    void FUN_0043a3c0(int first, int second);
};
struct FUN_00575650_Class : Unknown
{
    virtual int v117();
    virtual int v118();
    virtual int v119();
    virtual int v120();
    virtual int v121();
    virtual int v122();
    virtual int v123();
    virtual int v124();
    virtual int v125();
    int FUN_00575ca0();
    FUN_00575650_Result* FUN_00575650(FUN_00575650_Result* target);
};

// Actor parent-cell change: update the water height for the new cell, notify the player hooks and the process.

extern const float g_f5BB0DefaultWaterHeight;

class F5BB0Actor;

class F5BB0Cell
{
  public:
    bool IsInterior() const;
    float UpdateTESState();
};

struct F5BB0WaterData
{
    int unk00;
    int unk04;
    float m_fWaterValue;
};

class F5BB0ExtraDataList
{
  public:
    void* GetPersistentCell();
};

class F5BB0Process
{
  public:
    virtual void Unk000();
    virtual void Unk004();
    virtual void Unk008();
    virtual void Unk00C();
    virtual void Unk010();
    virtual void Unk014();
    virtual void Unk018();
    virtual void Unk01C();
    virtual void Unk020();
    virtual void Unk024();
    virtual void Unk028();
    virtual void Unk02C();
    virtual void Unk030();
    virtual void Unk034();
    virtual void Unk038();
    virtual void Unk03C();
    virtual void Unk040();
    virtual void Unk044();
    virtual void Unk048();
    virtual void Unk04C();
    virtual void Unk050();
    virtual void Unk054();
    virtual void Unk058();
    virtual void Unk05C();
    virtual void Unk060();
    virtual void Unk064();
    virtual void Unk068();
    virtual void Unk06C();
    virtual void Unk070();
    virtual void Unk074();
    virtual void Unk078();
    virtual void Unk07C();
    virtual void Unk080();
    virtual void Unk084();
    virtual void Unk088();
    virtual void Unk08C();
    virtual void Unk090();
    virtual void Unk094();
    virtual void Unk098();
    virtual void Unk09C();
    virtual void Unk0A0();
    virtual void Unk0A4();
    virtual void Unk0A8();
    virtual void Unk0AC();
    virtual void Unk0B0();
    virtual void Unk0B4();
    virtual void Unk0B8();
    virtual void Unk0BC();
    virtual void Unk0C0();
    virtual void Unk0C4();
    virtual void Unk0C8();
    virtual void Unk0CC();
    virtual void Unk0D0();
    virtual void Unk0D4();
    virtual void Unk0D8();
    virtual void Unk0DC();
    virtual void Unk0E0();
    virtual void Unk0E4();
    virtual void Unk0E8();
    virtual void Unk0EC();
    virtual void Unk0F0();
    virtual void Unk0F4();
    virtual void Unk0F8();
    virtual void Unk0FC();
    virtual void Unk100();
    virtual void Unk104();
    virtual void Unk108();
    virtual void Unk10C();
    virtual void Unk110();
    virtual void Unk114();
    virtual void Unk118();
    virtual void Unk11C();
    virtual void Unk120();
    virtual void Unk124();
    virtual void Unk128();
    virtual void Unk12C();
    virtual void Unk130();
    virtual void Unk134();
    virtual void Unk138();
    virtual void Unk13C();
    virtual void Unk140();
    virtual void Unk144();
    virtual void Unk148();
    virtual void Unk14C();
    virtual void Unk150();
    virtual void Unk154();
    virtual void Unk158();
    virtual void Unk15C();
    virtual void Unk160();
    virtual void Unk164();
    virtual void Unk168();
    virtual void Unk16C();
    virtual void Unk170();
    virtual void Unk174();
    virtual void Unk178();
    virtual void Unk17C();
    virtual void Unk180();
    virtual void Unk184();
    virtual void Unk188();
    virtual void Unk18C();
    virtual void Unk190();
    virtual void Unk194();
    virtual void Unk198();
    virtual void Unk19C();
    virtual void Unk1A0();
    virtual void Unk1A4();
    virtual void Unk1A8();
    virtual void Unk1AC();
    virtual void Unk1B0();
    virtual void Unk1B4();
    virtual void Unk1B8();
    virtual void Unk1BC();
    virtual void Unk1C0();
    virtual void Unk1C4();
    virtual void Unk1C8();
    virtual void Unk1CC();
    virtual void Unk1D0();
    virtual void Unk1D4();
    virtual void Unk1D8();
    virtual void Unk1DC();
    virtual void Unk1E0();
    virtual void Unk1E4();
    virtual void Unk1E8();
    virtual void Unk1EC();
    virtual void Unk1F0();
    virtual void Unk1F4();
    virtual void Unk1F8();
    virtual void Unk1FC();
    virtual void Unk200();
    virtual void Unk204();
    virtual void Unk208();
    virtual void Unk20C();
    virtual void Unk210();
    virtual void Unk214();
    virtual void Unk218();
    virtual void Unk21C();
    virtual void Unk220();
    virtual void Unk224();
    virtual void Unk228();
    virtual void Unk22C();
    virtual void Unk230();
    virtual void Unk234();
    virtual void Unk238();
    virtual void Unk23C();
    virtual void Unk240();
    virtual void Unk244();
    virtual void Unk248();
    virtual void Unk24C();
    virtual void Unk250();
    virtual void Unk254();
    virtual void Unk258();
    virtual void Unk25C();
    virtual void Unk260();
    virtual void Unk264();
    virtual void Unk268();
    virtual void Unk26C();
    virtual void Unk270();
    virtual void Unk274();
    virtual void Unk278();
    virtual void Unk27C();
    virtual void Unk280();
    virtual void Unk284();
    virtual void Unk288();
    virtual void Unk28C();
    virtual void Unk290();
    virtual void Unk294();
    virtual void Unk298();
    virtual void Unk29C();
    virtual void Unk2A0();
    virtual void Unk2A4();
    virtual void Unk2A8();
    virtual void Unk2AC();
    virtual void Unk2B0();
    virtual void Unk2B4();
    virtual void Unk2B8();
    virtual void Unk2BC();
    virtual void Unk2C0();
    virtual void Unk2C4();
    virtual void Unk2C8();
    virtual void Unk2CC();
    virtual void Unk2D0();
    virtual void Unk2D4();
    virtual void Unk2D8();
    virtual void Unk2DC();
    virtual void Unk2E0();
    virtual void Unk2E4();
    virtual void Unk2E8();
    virtual void Unk2EC();
    virtual void Unk2F0();
    virtual void Unk2F4();
    virtual void Unk2F8();
    virtual void Unk2FC();
    virtual void Unk300();
    virtual void Unk304();
    virtual void Unk308();
    virtual void Unk30C();
    virtual void Unk310();
    virtual void Unk314();
    virtual void Unk318();
    virtual void Unk31C();
    virtual void Unk320();
    virtual void Unk324();
    virtual void Unk328();
    virtual void Unk32C();
    virtual void Unk330();
    virtual void Unk334();
    virtual void Unk338();
    virtual void Unk33C();
    virtual void Unk340();
    virtual void Unk344();
    virtual void Unk348();
    virtual void Unk34C();
    virtual void Unk350();
    virtual void Unk354();
    virtual void Unk358();
    virtual void Unk35C();
    virtual void Unk360();
    virtual void Unk364();
    virtual void Unk368();
    virtual void Unk36C();
    virtual void Unk370();
    virtual void Unk374();
    virtual void Unk378();
    virtual void Unk37C();
    virtual void Unk380();
    virtual void Unk384();
    virtual void Unk388();
    virtual void Unk38C();
    virtual void Unk390();
    virtual void Unk394();
    virtual void Unk398();
    virtual void Unk39C();
    virtual void Unk3A0();
    virtual void Unk3A4();
    virtual void Unk3A8();
    virtual void Unk3AC();
    virtual void Unk3B0();
    virtual void Unk3B4();
    virtual void Unk3B8();
    virtual void Unk3BC();
    virtual void Unk3C0();
    virtual void Unk3C4();
    virtual void Unk3C8();
    virtual void Unk3CC();
    virtual void Unk3D0();
    virtual void Unk3D4();
    virtual void Unk3D8();
    virtual void Unk3DC();
    virtual void Unk3E0();
    virtual void Unk3E4();
    virtual void Unk3E8();
    virtual void Unk3EC();
    virtual void Unk3F0();
    virtual void Unk3F4();
    virtual void Unk3F8();
    virtual void Unk3FC();
    virtual void Unk400();
    virtual void Unk404();
    virtual void Unk408();
    virtual void Unk40C();
    virtual void Unk410();
    virtual void Unk414();
    virtual void Unk418();
    virtual void Unk41C();
    virtual void Unk420();
    virtual void Unk424();
    virtual void Unk428();
    virtual void Unk42C();
    virtual void Unk430();
    virtual void Unk434();
    virtual void Unk438();
    virtual void Unk43C();
    virtual void Unk440();
    virtual void Unk444();
    virtual void Unk448();
    virtual void Unk44C();
    virtual void Unk450();
    virtual void Unk454();
    virtual void Unk458();
    virtual void Unk45C();
    virtual void Unk460();
    virtual void Unk464();
    virtual void Unk468();
    virtual void Unk46C();
    virtual void Unk470();
    virtual void Unk474();
    virtual void Unk478();
    virtual void Unk47C();
    virtual void Unk480();
    virtual void Unk484();
    virtual void Unk488();
    virtual void Unk48C();
    virtual void Unk490();
    virtual void Unk494();
    virtual void Unk498();
    virtual void Unk49C();
    virtual void Unk4A0();
    virtual void Unk4A4();
    virtual void Unk4A8();
    virtual void Unk4AC();
    virtual void Unk4B0();
    virtual void Unk4B4();
    virtual void Unk4B8();
    virtual void Unk4BC();
    virtual void Unk4C0();
    virtual void Unk4C4();
    virtual void Unk4C8();
    virtual void Unk4CC();
    virtual void Unk4D0();
    virtual void Unk4D4();
    virtual void Unk4D8();
    virtual void Unk4DC();
    virtual void Unk4E0();
    virtual void Unk4E4();
    virtual void Unk4E8();
    virtual void Unk4EC();
    virtual void Unk4F0();
    virtual void Unk4F4();
    virtual void Unk4F8();
    virtual void Unk4FC();
    virtual void Unk500();
    virtual void Unk504();
    virtual void Unk508();
    virtual void Unk50C();
    virtual void Unk510();
    virtual void Unk514();
    virtual void Unk518();
    virtual void Unk51C();
    virtual void Unk520();
    virtual void Unk524();
    virtual void Unk528();
    virtual void Unk52C();
    virtual void Unk530();
    virtual void Unk534();
    virtual void Unk538();
    virtual void Unk53C();
    virtual void Unk540();
    virtual void Unk544();
    virtual void Unk548();
    virtual void Unk54C();
    virtual void Unk550();
    virtual void Unk554();
    virtual void Unk558();
    virtual void Unk55C();
    virtual void Unk560();
    virtual void Unk564();
    virtual void Unk568();
    virtual void Unk56C();
    virtual void Unk570();
    virtual void Unk574();
    virtual void Unk578();
    virtual void Unk57C();
    virtual void Unk580();
    virtual void Unk584();
    virtual void Unk588();
    virtual void Unk58C();
    virtual void Unk590();
    virtual void Unk594();
    virtual void Unk598();
    virtual void Unk59C();
    virtual void Unk5A0();
    virtual void Unk5A4();
    virtual void Unk5A8();
    virtual void Unk5AC();
    virtual void Unk5B0();
    virtual void Unk5B4();
    virtual void Unk5B8();
    virtual void Unk5BC();
    virtual void Unk5C0();
    virtual void Unk5C4();
    virtual void Unk5C8();
    virtual void Unk5CC();
    virtual void Unk5D0();
    virtual void Unk5D4();
    virtual void Unk5D8();
    virtual void Unk5DC();
    virtual void Unk5E0();
    virtual void Unk5E4();
    virtual void Unk5E8();
    virtual void Unk5EC();
    virtual void Unk5F0();
    virtual void Unk5F4();
    virtual void Unk5F8();
    virtual void Unk5FC();
    virtual void Unk600();
    virtual void Unk604();
    virtual void Unk608();
    virtual void Unk60C();
    virtual void Unk610();
    virtual void Unk614();
    virtual void Unk618();
    virtual void Unk61C();
    virtual void Unk620();
    virtual void Unk624();
    virtual void Unk628();
    virtual void Unk62C();
    virtual void Unk630();
    virtual void Unk634();
    virtual void Unk638();
    virtual void Unk63C();
    virtual void Unk640();
    virtual void Unk644();
    virtual void Unk648();
    virtual void Unk64C();
    virtual void Unk650();
    virtual void Unk654();
    virtual void Unk658();
    virtual void Unk65C();
    virtual void Unk660();
    virtual void Unk664();
    virtual void Unk668();
    virtual void Unk66C();
    virtual void Unk670();
    virtual void Unk674();
    virtual void Unk678();
    virtual void Unk67C();
    virtual void Unk680();
    virtual void Unk684();
    virtual void Unk688();
    virtual void Unk68C();
    virtual void Unk690();
    virtual void Unk694();
    virtual void Unk698();
    virtual void Unk69C();
    virtual void Unk6A0();
    virtual void Unk6A4();
    virtual void Unk6A8();
    virtual void OnCellChanged(F5BB0Actor* pkActor);
};

void __cdecl F5BB0UpdatePlayerCell(int iFlags);

class F5BB0Actor
{
  public:
    virtual void Unk000();
    virtual void Unk004();
    virtual void Unk008();
    virtual void Unk00C();
    virtual void Unk010();
    virtual void Unk014();
    virtual void Unk018();
    virtual void Unk01C();
    virtual void Unk020();
    virtual void Unk024();
    virtual void Unk028();
    virtual void Unk02C();
    virtual void Unk030();
    virtual void Unk034();
    virtual void Unk038();
    virtual void Unk03C();
    virtual void Unk040();
    virtual void Unk044();
    virtual void Unk048();
    virtual void Unk04C();
    virtual void Unk050();
    virtual void Unk054();
    virtual void Unk058();
    virtual void Unk05C();
    virtual void Unk060();
    virtual void Unk064();
    virtual void Unk068();
    virtual void Unk06C();
    virtual void Unk070();
    virtual void Unk074();
    virtual void Unk078();
    virtual void Unk07C();
    virtual void Unk080();
    virtual void Unk084();
    virtual void Unk088();
    virtual void Unk08C();
    virtual void Unk090();
    virtual void Unk094();
    virtual void Unk098();
    virtual void Unk09C();
    virtual void Unk0A0();
    virtual void Unk0A4();
    virtual void Unk0A8();
    virtual void Unk0AC();
    virtual void Unk0B0();
    virtual void Unk0B4();
    virtual void Unk0B8();
    virtual void Unk0BC();
    virtual void Unk0C0();
    virtual void Unk0C4();
    virtual void Unk0C8();
    virtual void Unk0CC();
    virtual void Unk0D0();
    virtual void Unk0D4();
    virtual void Unk0D8();
    virtual void Unk0DC();
    virtual void Unk0E0();
    virtual void Unk0E4();
    virtual void Unk0E8();
    virtual void Unk0EC();
    virtual void Unk0F0();
    virtual void Unk0F4();
    virtual void Unk0F8();
    virtual void Unk0FC();
    virtual bool IsActor();
    virtual void Unk104();
    virtual void Unk108();
    virtual void Unk10C();
    virtual void Unk110();
    virtual void Unk114();
    virtual void Unk118();
    virtual void Unk11C();
    virtual void Unk120();
    virtual void Unk124();
    virtual void Unk128();
    virtual void Unk12C();
    virtual void Unk130();
    virtual void Unk134();
    virtual void Unk138();
    virtual void Unk13C();
    virtual void Unk140();
    virtual void Unk144();
    virtual void Unk148();
    virtual void Unk14C();
    virtual void Unk150();
    virtual void Unk154();
    virtual void Unk158();
    virtual void Unk15C();
    virtual void Unk160();
    virtual void Unk164();
    virtual void Unk168();
    virtual void Unk16C();
    virtual void Unk170();
    virtual void Unk174();
    virtual void Unk178();
    virtual void Unk17C();
    virtual void Unk180();
    virtual void Unk184();
    virtual void Unk188();
    virtual void Unk18C();
    virtual void Unk190();
    virtual void Unk194();
    virtual void Unk198();
    virtual void Unk19C();
    virtual void Unk1A0();
    virtual void Unk1A4();
    virtual void Unk1A8();
    virtual void Unk1AC();
    virtual void Unk1B0();
    virtual void Unk1B4();
    virtual void Unk1B8();
    virtual void Unk1BC();
    virtual void Unk1C0();
    virtual void Unk1C4();
    virtual void Unk1C8();
    virtual void Unk1CC();
    virtual void Unk1D0();
    virtual void Unk1D4();
    virtual void Unk1D8();
    virtual void Unk1DC();
    virtual void Unk1E0();
    virtual void Unk1E4();
    virtual void Unk1E8();
    virtual void Unk1EC();
    virtual void Unk1F0();
    virtual void Unk1F4();
    virtual void Unk1F8();
    virtual void Unk1FC();
    virtual void Unk200();
    virtual void Unk204();
    virtual void Unk208();
    virtual void Unk20C();
    virtual void Unk210();
    virtual void Unk214();
    virtual void Unk218();
    virtual void Unk21C();
    virtual void Unk220();
    virtual void Unk224();
    virtual void Unk228();
    virtual void Unk22C();
    virtual void Unk230();
    virtual void Unk234();
    virtual void Unk238();
    virtual void Unk23C();
    virtual void UpdateCellState();

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
    F5BB0Cell* m_pkParentCell;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    F5BB0WaterData* m_pkWaterData;

    F5BB0ExtraDataList* GetExtraData();
    F5BB0Process* GetProcess();
    void* GetMountedRef();
    void FUN_00575bb0(F5BB0Cell* pkCell);
};

extern F5BB0Actor* g_pkF5BB0Player;

struct FUN_00576070_shell
{
    bool FUN_00452370();
    void* FUN_007af430();
    bool FUN_00576070();
};
void* __cdecl FUN_00475400(void* object);

class BGSHeadPart;
struct List_009e03e0
{
    BGSHeadPart* m_item;
    List_009e03e0* m_pkNext;
    ~List_009e03e0();
    BGSHeadPart*& FUN_006815c0();
    List_009e03e0* FUN_00726070();
    void RemoveAll();
};
struct Host00881620
{
    TESObjectREFR* FUN_00881650();
    void FUN_00881620(int iRef);
};
struct LinkedRefMgr
{
    List_009e03e0* FUN_0096f450(unsigned int auiFormId, void* pkRef);
};
struct LinkedRefTarget
{
    unsigned int FUN_0084e3a0();
};
struct LinkedRefExtra
{
    TESForm* FUN_00418660();
    void FUN_0041aed0();
    LinkedRefTarget* FUN_0041c8d0();
};
struct FUN_00576130_shell : TESObjectREFR
{
    TESForm* FUN_00567790();
    void FUN_00574fa0(int a, LinkedRefExtra* pkExtra, int c);
    void FUN_00576130(int a, LinkedRefExtra* pkExtra, int c);
};

class Head577
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class Shape577
{
  public:
    int m_iType;
};

class Phantom577 : public Head577, public Shape577
{
};

class World577
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual Shape577* GetShape();
};

class Holder577
{
  public:
    World577* GetWorld();
    Phantom577* FUN_005771f0();
};

struct Vec577
{
    float x;
    float y;
    float z;
};

struct FUN_0041fbe0_shell
{
    BGSPrimitive* FUN_0041fbe0();
};

class Tile
{
  public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(Vec577* p);
    NiNode* FUN_0056c7f0();
};

struct FUN_00413f90_Obj
{
    void FUN_00413f90(Vec577* p);
};

struct N_008c48d0
{
    TESObjectSTAT* GetNext();
};

struct Ref577
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual void* vf117();
};

struct Ref577b
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void vf114();
    virtual void vf115();
    virtual Tile* vf117(bool b);
};

struct Sub577
{
    void FUN_00450f90();
};

extern const float g_011c56fc_arg1;
extern TESObjectSTAT* DAT_011ca240;
const ExtraDataList* __fastcall FUN_005d43c0(const TESObjectREFR* pThis);

struct FUN_005549d0_obj : public TESObjectREFR
{
    void FUN_00577390(bool param_2);
};

namespace fnv_00577450 {
struct Point577
{
    float x, y, z;
    Point577& FUN_006815c0();
    bool FUN_00439090(const Point577&);
};
struct Plane577
{
    Point577 normal;
    float radius;
    Point577& FUN_006815c0();
    float FUN_0084d030();
};
struct Update577
{
    float time;
    bool update, render, unk06, unk07;
    unsigned unk08;
    Update577(float, bool, bool);
};
struct Node577
{
    const Point577& FUN_0045bb80();
    void FUN_00440460(const Point577&);
    void FUN_0043fa80(const void*);
    void FUN_00a59c60(Update577&);
    Plane577& FUN_0043d450();
};
struct World577;
struct Cell577
{
    bool FUN_00425fd0();
    Node577* FUN_00456fc0(int);
    World577* FUN_00546fb0();
    void FUN_0054cfd0(Point577&, Point577&);
    Node577* FUN_005497a0();
    void FUN_005496b0(void*, Node577*);
};
struct Point2_577
{
    float x, y;
};
struct World577
{
    Point2_577 FUN_0053f440();
};
struct Form577
{
    int FUN_00401170();
};
struct Body577
{
    float FUN_00577b50();
    void FUN_00577c40(float);
};
struct Ref577
{
    virtual void unk000();
    virtual void unk004();
    virtual void unk008();
    virtual void unk00c();
    virtual void unk010();
    virtual void unk014();
    virtual void unk018();
    virtual void unk01c();
    virtual void unk020();
    virtual void unk024();
    virtual void unk028();
    virtual void unk02c();
    virtual void unk030();
    virtual void unk034();
    virtual void unk038();
    virtual void unk03c();
    virtual void unk040();
    virtual void unk044();
    virtual void Notify(int);
    virtual void unk04c();
    virtual void unk050();
    virtual void unk054();
    virtual void unk058();
    virtual void unk05c();
    virtual void unk060();
    virtual void unk064();
    virtual void unk068();
    virtual void unk06c();
    virtual void unk070();
    virtual void unk074();
    virtual void unk078();
    virtual void unk07c();
    virtual void unk080();
    virtual void unk084();
    virtual void unk088();
    virtual void unk08c();
    virtual void unk090();
    virtual void unk094();
    virtual void unk098();
    virtual void unk09c();
    virtual void unk0a0();
    virtual void unk0a4();
    virtual void unk0a8();
    virtual void unk0ac();
    virtual void unk0b0();
    virtual void unk0b4();
    virtual void unk0b8();
    virtual void unk0bc();
    virtual void unk0c0();
    virtual void unk0c4();
    virtual void unk0c8();
    virtual void unk0cc();
    virtual void unk0d0();
    virtual void unk0d4();
    virtual void unk0d8();
    virtual void unk0dc();
    virtual void unk0e0();
    virtual void unk0e4();
    virtual void unk0e8();
    virtual void unk0ec();
    virtual void unk0f0();
    virtual void unk0f4();
    virtual void unk0f8();
    virtual void unk0fc();
    virtual bool IsActor();
    virtual void unk104();
    virtual void unk108();
    virtual void unk10c();
    virtual void unk110();
    virtual void unk114();
    virtual void unk118();
    virtual void unk11c();
    virtual void unk120();
    virtual void unk124();
    virtual void unk128();
    virtual void unk12c();
    virtual const char* GetName();
    virtual void unk134();
    virtual void unk138();
    virtual void unk13c();
    virtual void unk140();
    virtual void unk144();
    virtual void unk148();
    virtual void unk14c();
    virtual void unk150();
    virtual void unk154();
    virtual void unk158();
    virtual void unk15c();
    virtual void unk160();
    virtual void unk164();
    virtual void unk168();
    virtual void unk16c();
    virtual Point577 GetPosition();
    virtual void SetPosition(Point577);
    virtual void unk178();
    virtual void unk17c();
    virtual void unk180();
    virtual void unk184();
    virtual void unk188();
    virtual void unk18c();
    virtual void unk190();
    virtual void unk194();
    virtual void unk198();
    virtual void unk19c();
    virtual void unk1a0();
    virtual void unk1a4();
    virtual void unk1a8();
    virtual void unk1ac();
    virtual void unk1b0();
    virtual void unk1b4();
    virtual void unk1b8();
    virtual void unk1bc();
    virtual void unk1c0();
    virtual void unk1c4();
    virtual void unk1c8();
    virtual void unk1cc();
    virtual Node577* GetNode();
    virtual void unk1d4();
    virtual void unk1d8();
    virtual void unk1dc();
    virtual void unk1e0();
    virtual void unk1e4();
    virtual void unk1e8();
    virtual void unk1ec();
    virtual void unk1f0();
    virtual const Point577& GetCoordinates();
    Cell577* FUN_008d6f30();
    Form577* FUN_007af430();
    bool FUN_00448a20();
    float FUN_0057b0a0();
    void FUN_00484a70(bool);
    void FUN_005729e0(int);
    void FUN_00575830(const Point577&);
    unsigned FUN_0084e3a0();
    void FUN_008ae640(bool);
    void FUN_00575700(Point577);
};
struct Param577
{
    virtual void unk000();
    virtual void unk004();
    virtual void unk008();
    virtual void unk00c();
    virtual void unk010();
    virtual void unk014();
    virtual void unk018();
    virtual void unk01c();
    virtual void unk020();
    virtual void unk024();
    virtual void unk028();
    virtual void unk02c();
    virtual void unk030();
    virtual void unk034();
    virtual void unk038();
    virtual void unk03c();
    virtual void unk040();
    virtual void unk044();
    virtual void unk048();
    virtual void unk04c();
    virtual void unk050();
    virtual void unk054();
    virtual void unk058();
    virtual void unk05c();
    virtual void unk060();
    virtual void unk064();
    virtual void unk068();
    virtual void unk06c();
    virtual void unk070();
    virtual void unk074();
    virtual void unk078();
    virtual void unk07c();
    virtual void unk080();
    virtual void unk084();
    virtual void unk088();
    virtual void unk08c();
    virtual void unk090();
    virtual void unk094();
    virtual void unk098();
    virtual void unk09c();
    virtual void unk0a0();
    virtual void unk0a4();
    virtual void unk0a8();
    virtual void unk0ac();
    virtual void Signal(int, int, int);
    Node577* FUN_0044ddc0();
    Body577* FUN_006fa820();
    void FUN_00573ed0(int);
};
struct Toggle577
{
    bool FUN_004623f0(bool);
};
struct TES577
{
    int FUN_005f36f0();
    World577* FUN_004fd3e0();
};
struct CellLookup577
{
    Cell577* FUN_00461bc0(float, float, World577*, bool);
};
struct Rotation577
{
    Point577& DecomposeToEulerAngles(float*, float*, float*);
};
struct RotSource577 : Node577
{
    Rotation577* FUN_00461130();
};
struct Scene577
{
    void FUN_00b5d9f0(Node577*, bool);
};
extern Toggle577* DAT_011ddf38;
extern TES577* DAT_011dea10;
extern CellLookup577* DAT_011c3f2c;
extern Point577 DAT_011f426c;
extern char DAT_011a9448;
extern char DAT_01030ed8;
Ref577* __cdecl FUN_0056f930(Node577*);
bool __cdecl FUN_0062c3c0(Ref577*, Node577*);
void __cdecl FUN_00578300(Node577*);
void __cdecl FUN_00c6bd00(Node577*, bool);
void __cdecl FUN_0054abd0(Ref577*, Node577*);
void __cdecl FUN_00573800(Ref577*, int, World577*);
bool __cdecl FUN_008c7aa0();
int __cdecl FUN_00ec7595(double);
int __cdecl FUN_00ec75b1(double);
void __cdecl FUN_005b5e40(const char*, ...);
Scene577* __cdecl FUN_00450b80(int);
}  // namespace fnv_00577450

namespace fnv_00578170 {
struct StkRTTI;
class GlobalObject_00a7b610;
extern GlobalObject_00a7b610 g_01202de8;

struct StkNodeObj
{
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual NiNode* vfunc03();
    void FUN_00450f90(bool);
    unsigned int FUN_0043b480();
    StkNodeObj* FUN_0043b4a0(unsigned int index);
};

struct StkAddonNode
{
    bool FUN_00448bf0();
};

struct StkDataHandler
{
    StkAddonNode* FUN_004617e0(unsigned int index);
};
extern StkDataHandler* g_dataHandler;

bool __cdecl FUN_0043b300(const StkRTTI* rtti, NiNode* obj);
int __fastcall FUN_009ee040(char* pThis);

}  // namespace fnv_00578170

namespace fnv_00578300 {
// v1 — skeleton-clean rebuild of v0 (which died of C2011: NiRTTI/NiAVObject/NiNode
// re-declared over the auto-injected unit prelude). Now uses prelude's own types and
// db-exact shell spellings for member calls (per shared/fnvdecomp_symbols.json audit).
struct FUN_0048cee0_shell
{
    int FUN_0048cee0();
};

struct FUN_00453470_shell
{
    int FUN_00453470();
};

struct _FakeNiNode
{
    unsigned int FUN_0043b480();
    NiAVObject* FUN_0043b4a0(unsigned int);
};

struct FUN_00572160_shell
{
    void FUN_00572160();
};

class GlobalObject_00a7b610
{
};

class DataHandler
{
  public:
    int FUN_004617e0(int);
};

extern GlobalObject_00a7b610 g_01202de8;
extern DataHandler* g_dataHandler;

bool __cdecl FUN_0043b300(const NiRTTI*, NiAVObject*);
int __cdecl FUN_00c69ee0(void*, int, int);
int __fastcall FUN_009ee040(char*);

}  // namespace fnv_00578300

// Recursively applies a value to every time controller on an object, its property 5 and all its children.

class C5784F0Controller
{
  public:
    void SetValue(float fValue);
    C5784F0Controller* GetNext() const;
};

class C5784F0Node;

class C5784F0ObjectNET
{
  public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual C5784F0Node* IsSceneNode();
    C5784F0Controller* GetControllers();
};

class C5784F0Object : public C5784F0ObjectNET
{
  public:
    C5784F0ObjectNET* GetProperty(unsigned int uiType);
};

class C5784F0Node
{
  public:
    unsigned int GetArrayCount();
    C5784F0Object* GetAt(unsigned int uiIndex);
};

// Sound setup for a reference, including primitive-relative loop positioning.
struct LoopSoundData
{
    unsigned int frequency, flags, attenuation, volume, minimumDistance;
    unsigned int maximumDistance, startTime, stopTime, priority;
};
struct LoopSound
{
    LoopSoundData CopyBig();
    unsigned int FUN_0084e3a0();
};
struct LoopEffect
{
    LoopSound* FUN_00407840();
};
struct LoopForm
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
    virtual LoopEffect* GetLoopEffect();
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    LoopSound* loopSound;
    unsigned int FUN_00401170();
    bool FUN_00452440();
    bool FUN_004e32c0();
    LoopSound* FUN_004fd3c0();
    LoopSound* FUN_004fd3a0();
    LoopSound* FUN_004fb070();
    LoopSound* FUN_004036b0();
    LoopSound* FUN_008cdd90();
    LoopSound* FUN_009185e0();
    LoopSound* FUN_005f92d0(int);
};
struct SoundContainerPrefix
{
    virtual void v0();
    unsigned int field04, field08, field0c, field10;
};
struct SoundContainer : SoundContainerPrefix, LoopForm
{
    LoopSound* FUN_005e3fa0();
};
struct GlobalObject_0041a250
{
    unsigned int id, state, flags;
    GlobalObject_0041a250();
    ~GlobalObject_0041a250();
    bool FUN_00ad8ce0();
    void FUN_00ad88f0();
    void FUN_00ad8d10();
    void FUN_00ad8da0(int);
    void FUN_00418900(const void*);
    void FUN_00ad8ba0(float, float, float);
};
struct LoopPrimitive
{
    NiPoint3 FUN_00413fc0();
};
struct LoopExtras
{
    LoopPrimitive* FUN_0041fbe0();
    void FUN_00418890(GlobalObject_0041a250*);
    void FUN_00410140(int);
    void FUN_0041a800(GlobalObject_0041a250*);
};
struct LoopAudio
{
    GlobalObject_0041a250 FUN_00ad7620(unsigned int, unsigned int, NiPoint3, int);
};
LoopAudio* FUN_00453a70();
struct LoopSaveState
{
    bool FUN_0042ce10();
};
struct LoopDataState
{
    bool FUN_004226e0();
};
struct LoopPointOps
{
    void FUN_0063c8a0(const NiPoint3&);
};
NiPoint3 FUN_004a3760(float, const NiPoint3&);
NiPoint3 FUN_004b3ae0(const NiPoint3&, const float*);
struct RefObj
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
    virtual NiPoint3* GetPosition();
    virtual void v126();
    virtual void v127();
    virtual void v128();
    virtual void v129();
    virtual void v130();
    virtual void v131();
    virtual void v132();
    virtual void v133();
    virtual void v134();
    virtual bool HasCreatureLoop();
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    LoopSound* baseSound;
    LoopForm* _FNV_GetObjectReference();
    bool FUN_00440da0();
    bool FUN_00477ba0();
    LoopExtras* FUN_005d43c0();
    M3 FUN_0056fa00();
    void* FUN_0043fcd0();
    void FUN_0057a3c0(bool);
    void FUN_00579ac0(bool enable);
};
int FUN_0047b250(RefObj*);
void FUN_008325b0(RefObj*, bool);

class Process57A
{
  public:
    unsigned int IsActive();
};

class Ref57A
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0C();
    virtual Process57A* GetProcess();
};

class Handle57A
{
  public:
    Ref57A* Get() const;

    Ref57A* m_pPointer;
};

class Actor57A
{
  public:
    virtual void vfn000();
    virtual void vfn004();
    virtual void vfn008();
    virtual void vfn00C();
    virtual void vfn010();
    virtual void vfn014();
    virtual void vfn018();
    virtual void vfn01C();
    virtual void vfn020();
    virtual void vfn024();
    virtual void vfn028();
    virtual void vfn02C();
    virtual void vfn030();
    virtual void vfn034();
    virtual void vfn038();
    virtual void vfn03C();
    virtual void vfn040();
    virtual void vfn044();
    virtual void vfn048();
    virtual void vfn04C();
    virtual void vfn050();
    virtual void vfn054();
    virtual void vfn058();
    virtual void vfn05C();
    virtual void vfn060();
    virtual void vfn064();
    virtual void vfn068();
    virtual void vfn06C();
    virtual void vfn070();
    virtual void vfn074();
    virtual void vfn078();
    virtual void vfn07C();
    virtual void vfn080();
    virtual void vfn084();
    virtual void vfn088();
    virtual void vfn08C();
    virtual void vfn090();
    virtual void vfn094();
    virtual void vfn098();
    virtual void vfn09C();
    virtual void vfn0A0();
    virtual void vfn0A4();
    virtual void vfn0A8();
    virtual void vfn0AC();
    virtual void vfn0B0();
    virtual void vfn0B4();
    virtual void vfn0B8();
    virtual void vfn0BC();
    virtual void vfn0C0();
    virtual void vfn0C4();
    virtual void vfn0C8();
    virtual void vfn0CC();
    virtual void vfn0D0();
    virtual void vfn0D4();
    virtual void vfn0D8();
    virtual void vfn0DC();
    virtual void vfn0E0();
    virtual void vfn0E4();
    virtual void vfn0E8();
    virtual void vfn0EC();
    virtual void vfn0F0();
    virtual void vfn0F4();
    virtual void vfn0F8();
    virtual void vfn0FC();
    virtual void vfn100();
    virtual void vfn104();
    virtual void vfn108();
    virtual void vfn10C();
    virtual void vfn110();
    virtual void vfn114();
    virtual void vfn118();
    virtual void vfn11C();
    virtual void vfn120();
    virtual void vfn124();
    virtual void vfn128();
    virtual void vfn12C();
    virtual void vfn130();
    virtual void vfn134();
    virtual void vfn138();
    virtual void vfn13C();
    virtual void vfn140();
    virtual void vfn144();
    virtual void vfn148();
    virtual void vfn14C();
    virtual void vfn150();
    virtual void vfn154();
    virtual void vfn158();
    virtual void vfn15C();
    virtual void vfn160();
    virtual void vfn164();
    virtual void vfn168();
    virtual void vfn16C();
    virtual void vfn170();
    virtual void vfn174();
    virtual void vfn178();
    virtual void vfn17C();
    virtual void vfn180();
    virtual void vfn184();
    virtual void vfn188();
    virtual void vfn18C();
    virtual void vfn190();
    virtual void vfn194();
    virtual void vfn198();
    virtual void vfn19C();
    virtual void vfn1A0();
    virtual void vfn1A4();
    virtual void vfn1A8();
    virtual void vfn1AC();
    virtual void vfn1B0();
    virtual void vfn1B4();
    virtual void vfn1B8();
    virtual void vfn1BC();
    virtual void vfn1C0();
    virtual void vfn1C4();
    virtual void vfn1C8();
    virtual void vfn1CC();
    virtual int CanAct();
};

char __cdecl Evaluate57A(Ref57A* pkSource, Ref57A* pkTarget, bool* pbResult, int iMode);

class Package57A
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    Actor57A* m_pkActor;
    Handle57A m_kSource;
    Handle57A m_kRoomNode;
    char m_cResult;

    void FUN_0057a9f0();
};

struct Vec57
{
    float x, y, z;
    Vec57& operator*=(float);
};
struct Mat57
{
    void angles(float*, float*, float*, float*);
};
class BSMultiBoundShape
{
  public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void center(const Vec57&);
    virtual void update();
};
class BSMultiBoundAABB : public BSMultiBoundShape
{
  public:
    const Vec57& extent();
    void setExtent(const Vec57&);
};
class BSMultiBoundOBB : public BSMultiBoundShape
{
  public:
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
    BSMultiBoundOBB();
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void rotation(const Mat57&);
    const Vec57& extent();
    void setExtent(const Vec57&);
};
struct Bound57
{
    Vec57& point();
};
struct Multi57
{
    BSMultiBoundShape* shape();
    void SetCollisionShapeAndKey(BSMultiBoundShape*);
};
struct Obj57x
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual Obj57x* node();
    virtual void objslot4();
    virtual void objslot5();
    virtual void objslot6();
    virtual void objslot7();
    virtual void objslot8();
    virtual void objslot9();
    virtual void objslot10();
    virtual void objslot11();
    virtual void objslot12();
    virtual void objslot13();
    virtual void objslot14();
    virtual void objslot15();
    virtual void objslot16();
    virtual void objslot17();
    virtual void objslot18();
    virtual void objslot19();
    virtual void objslot20();
    virtual void objslot21();
    virtual void objslot22();
    virtual void objslot23();
    virtual void objslot24();
    virtual void objslot25();
    virtual void objslot26();
    virtual void objslot27();
    virtual void objslot28();
    virtual void objslot29();
    virtual void objslot30();
    virtual void objslot31();
    virtual void objslot32();
    virtual void objslot33();
    virtual void objslot34();
    virtual void objslot35();
    virtual void objslot36();
    virtual void objslot37();
    virtual void objslot38();
    virtual void objslot39();
    virtual void objslot40();
    virtual void objslot41();
    virtual void objslot42();
    virtual void objslot43();
    virtual void objslot44();
    virtual void objslot45();
    virtual void objslot46();
    virtual void update();
    Mat57& rotation();
    Vec57& position();
    unsigned int count();
    Obj57x* child(unsigned int);
    Bound57& bound();
    float scale();
    Multi57* multi();
};
extern int g_01202e74;
extern Vec57 NiPoint3_ZERO;
bool test57(const void*, Obj57x*);
namespace std {
float abs(float);
}
struct Worker57
{
    bool FUN_0057bd80(Obj57x*);
};

namespace fnv_00571760 {
struct TESObjectWEAP;
struct BipedAnim;
struct Obj14;
struct LoaderShell;

struct Proc
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
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void* V82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void V115(bool b, void* bip, void* p, void* r);
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f120();
    virtual void f121();
    virtual void f122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual void f139();
    virtual void f140();
    virtual void f141();
    virtual void f142();
    virtual void f143();
    virtual void f144();
    virtual void f145();
    virtual void f146();
    virtual void f147();
    virtual void f148();
    virtual void f149();
    virtual void f150();
    virtual void f151();
    virtual void f152();
    virtual void f153();
    virtual void f154();
    virtual void f155();
    virtual void f156();
    virtual void f157();
    virtual void f158();
    virtual void f159();
    virtual void f160();
    virtual void f161();
    virtual void f162();
    virtual void f163();
    virtual void f164();
    virtual void f165();
    virtual void f166();
    virtual void f167();
    virtual void f168();
    virtual void f169();
    virtual void f170();
    virtual void f171();
    virtual void f172();
    virtual void f173();
    virtual void f174();
    virtual void f175();
    virtual void f176();
    virtual void f177();
    virtual void f178();
    virtual void f179();
    virtual void f180();
    virtual void f181();
    virtual void f182();
    virtual void f183();
    virtual void f184();
    virtual void f185();
    virtual void f186();
    virtual void f187();
    virtual void f188();
    virtual void f189();
    virtual void f190();
    virtual void f191();
    virtual void f192();
    virtual void f193();
    virtual void f194();
    virtual void f195();
    virtual void f196();
    virtual void f197();
    virtual void f198();
    virtual void f199();
    virtual void f200();
    virtual void f201();
    virtual void f202();
    virtual void f203();
    virtual void f204();
    virtual void f205();
    virtual void f206();
    virtual void f207();
    virtual void f208();
    virtual void f209();
    virtual void f210();
    virtual void f211();
    virtual void f212();
    virtual void f213();
    virtual void f214();
    virtual void f215();
    virtual void f216();
    virtual void f217();
    virtual void f218();
    virtual void f219();
    virtual void f220();
    virtual void f221();
    virtual void f222();
    virtual void f223();
    virtual void f224();
    virtual void f225();
    virtual void f226();
    virtual void f227();
    virtual void f228();
    virtual void f229();
    virtual void f230();
    virtual void f231();
    virtual void f232();
    virtual void f233();
    virtual void f234();
    virtual void f235();
    virtual void f236();
    virtual void f237();
    virtual void f238();
    virtual void f239();
    virtual void f240();
    virtual void f241();
    virtual void f242();
    virtual void f243();
    virtual void f244();
    virtual void f245();
    virtual void f246();
    virtual void f247();
    virtual void f248();
    virtual void f249();
    virtual void f250();
    virtual void f251();
    virtual void f252();
    virtual void f253();
    virtual void f254();
    virtual void f255();
    virtual void f256();
    virtual void f257();
    virtual void f258();
    virtual void f259();
    virtual void f260();
    virtual void f261();
    virtual void f262();
    virtual void f263();
    virtual void f264();
    virtual void f265();
    virtual void f266();
    virtual void f267();
    virtual void f268();
    virtual void f269();
    virtual void f270();
    virtual void f271();
    virtual void f272();
    virtual void f273();
    virtual void f274();
    virtual void f275();
    virtual void f276();
    virtual bool V277();
    virtual void V278(void* r, int z);
    virtual void f279();
    virtual void f280();
    virtual void f281();
    virtual void V282(int a);
};

struct Actor
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
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual bool V64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f120();
    virtual void* V121();
    virtual void* V122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual bool V139(int a);
    void* Get3DSimple();
    const char* GetFullName();
    Proc* GetProcess();
    bool FUN_008a16d0();
    void FUN_008b0b00(int a);
    void FUN_008b0bd0(void* p);
    void FUN_008c4640();
    void FUN_00891190(int a);
    void* FUN_005715d0(int a, int b, int c);
    BipedAnim* GetBipedAnim(bool b);
    void FUN_00571760(TESObjectWEAP* wpn);
};

struct BipedAnim
{
    void FUN_004ab750(TESObjectWEAP* w, bool b);
};

struct Obj14
{
    bool FUN_004bd820();
    bool FUN_004bd8d0(int a, float* f);
};

struct TESObjectWEAP
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
    float f3c;
    bool GetHasScope();
    bool FUN_004ad030();
    char* FUN_00504e60();
    bool FUN_0046e8c0();
    int GetWeaponType() const;
};

struct SaveShell
{
    bool FUN_0042ce10();
};

struct LoaderShell
{
    int FUN_00447330(void* p);
};

struct AnimObj
{
    void* FUN_00496940();
    bool FUN_00494710(unsigned short a);
    void FUN_00490400(int a);
};

struct QObj
{
    int FUN_00726070();
};

class TESAnimGroup
{
  public:
    static unsigned short AnimGroup(int a, int b, int c, int d);
};

extern SaveShell* DAT_011ddf38;
extern Actor* DAT_011dea3c;
extern LoaderShell* DAT_011c3b3c;
extern int DAT_0118a838[];

int __cdecl FUN_00ec7750(const char* a, const char* b);
void __cdecl FUN_005b5e40(const char* s);
void __cdecl FUN_00709c20(int a);
int __cdecl FUN_004aeed0(void* w, float* ps, int five, void* th, int z);
void* __cdecl FUN_00475020(void* w);

}  // namespace fnv_00571760

struct TESValueForm : public TESForm
{
    int _ref_00726070();
};

struct SubObj
{
    virtual void v0();
    virtual void v1();
    virtual float GetValue(int);
};

struct MagicItem : public TESForm
{
    char pad[0xc - sizeof(TESForm)];
    SubObj sub;
};

struct AlchemyItem : public TESForm
{
    char pad[0x3c - sizeof(TESForm)];
    SubObj sub;
};

// Reference remapping reconstructed from the complete target disassembly.
struct RemapRef;
struct RemapPoint
{
    float x, y, z;
    RemapPoint FUN_00439ef0(const RemapPoint&) const;
    RemapPoint FUN_00439e90(const RemapPoint&) const;
};
struct RemapMatrix
{
    RemapPoint row0, row1, row2;
    RemapMatrix* FUN_00439ef0(RemapMatrix*, RemapMatrix*);
    RemapMatrix* FUN_00439e90(RemapMatrix*, RemapMatrix*);
};
struct RemapData
{
    RemapRef* reference;
    float value;
    RemapPoint unused;
};
struct RemapTransform
{
    RemapRef* reference;
    RemapPoint position;
    RemapPoint rotation;
};
struct RemapList
{
    bool FUN_008256d0();
    void** FUN_006815c0();
    RemapList* FUN_00726070();
};
struct RemapExtra
{
    void FUN_0041dcd0(RemapRef*);
    void FUN_0041e530(RemapRef*);
    RemapRef* FUN_00420bc0(int);
    void FUN_00420a60(int, RemapRef*);
    RemapRef* FUN_00420130(int);
    void FUN_00420160(RemapRef*, int);
    RemapList* FUN_0041e780();
    void FUN_0041e7f0(RemapRef*);
    void FUN_0041ea30(RemapRef*, float);
    void FUN_0041edd0(RemapRef*);
    bool FUN_0041eb60();
    void FUN_0041eba0(bool);
    RemapList* FUN_0041f050();
};
struct RemapNode
{
    void FUN_00537e90(RemapRef*);
    void FUN_006f4ed0(RemapPoint*);
    void SetVec(RemapPoint*);
    RemapPoint* FUN_00460140();
    RemapRef* FUN_00559450();
    RemapPoint* FUN_00717e50();
};
struct RemapMap
{
    bool FUN_00853130(void*, TESForm**);
};
struct RemapRef
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual void slot076();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void slot103();
    virtual void slot104();
    virtual void slot105();
    virtual void slot106();
    virtual void slot107();
    virtual void slot108();
    virtual void slot109();
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void slot115();
    virtual void slot116();
    virtual void slot117();
    virtual void slot118();
    virtual void slot119();
    virtual void slot120();
    virtual void slot121();
    virtual void slot122();
    virtual void slot123();
    virtual void slot124();
    virtual RemapPoint* GetPos();
    RemapExtra* FUN_005d43c0();
    RemapRef* FUN_0056a9f0();
    void FUN_0056aa10(RemapRef*);
    bool FUN_0056aa70();
    void FUN_0056aa90(bool);
    RemapRef* FUN_00569b20();
    void FUN_00569b40(RemapRef*);
    RemapRef* FUN_00569b80();
    void FUN_00569ba0(RemapRef*);
    void FUN_0056a470(RemapRef*, RemapPoint*, RemapPoint*);
    RemapRef* FUN_0056a990();
    void FUN_0056a9b0(RemapRef*);
    RemapNode* FUN_00568e50();
    RemapNode* FUN_00568e70();
    void FUN_0055b9c0(RemapMap* map);
};

class ExtraTeleport : public BSExtraData
{
};
class ExtraEnableStateParent : public BSExtraData
{
};
class ExtraRandomTeleportMarker : public BSExtraData
{
};
class ExtraLinkedRef : public BSExtraData
{
};
class ExtraActivateRef : public BSExtraData
{
};
class ExtraDecalRefs : public BSExtraData
{
};
class ExtraMerchantContainer : public BSExtraData
{
};
class ExtraMultiBoundRef : public BSExtraData
{
};

class ListQ
{
  public:
    BSExtraData* FUN_00410220();
    void FUN_00410020(int);
    void FUN_0040ff60();
};

class ResQ
{
  public:
    virtual void rX();
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void r24();
    virtual void r25();
    virtual void r26();
    virtual void r27();
    virtual void r28();
    virtual void r29();
    virtual void r30();
    virtual void r31();
    virtual void r32();
    virtual void r33();
    virtual void r34();
    virtual void r35();
    virtual void r36();
    virtual void r37();
    virtual void r38();
    virtual void r39();
    virtual void r40();
    virtual void r41();
    virtual void r42();
    virtual void r43();
    virtual void r44();
    virtual void r45();
    virtual void r46();
    virtual void r47();
    virtual void r48();
    virtual void r49();
    virtual void r50();
    virtual void r51();
    virtual void r52();
    virtual void r53();
    virtual void r54();
    virtual void r55();
    virtual void r56();
    virtual void r57();
    virtual void r58();
    virtual void r59();
    virtual void r60();
    virtual void r61();
    virtual void r62();
    virtual void r63();
    virtual void r64();
    virtual void r65();
    virtual void r66();
    virtual void r67();
    virtual void r68();
    virtual void r69();
    virtual void r70();
    virtual void r71();
    virtual void r72();
    virtual void r73();
    virtual void r74();
    virtual void r75();
    virtual void r76();
    virtual void r77();
    virtual void r78();
    virtual void r79();
    virtual void r80();
    virtual void r81();
    virtual void r82();
    virtual void r83();
    virtual void r84();
    virtual void r85();
    virtual void r86();
    virtual void r87();
    virtual void r88();
    virtual void r89();
    virtual void r90();
    virtual void r91();
    virtual void r92();
    virtual void r93();
    virtual void r94();
    virtual void r95();
    virtual void r96();
    virtual void r97();
    virtual void r98();
    virtual void r99();
    virtual void r100();
    virtual void r101();
    virtual void r102();
    virtual void r103();
    virtual void r104();
    virtual void r105();
    virtual void r106();
    virtual void r107();
    virtual void r108();
    virtual void r109();
    virtual void r110();
    virtual void r111();
    virtual void r112();
    virtual void r113();
    virtual void SetQ(int a, int b);
    void FUN_00565480(int);
};
class OwnQ
{
  public:
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
    virtual void o7();
    virtual void o8();
    virtual void o9();
    virtual void o10();
    virtual void o11();
    virtual void o12();
    virtual void o13();
    virtual void o14();
    virtual void o15();
    virtual void o16();
    virtual void o17();
    virtual void o18();
    virtual void o19();
    virtual void o20();
    virtual void o21();
    virtual void o22();
    virtual void o23();
    virtual void o24();
    virtual void o25();
    virtual void o26();
    virtual void o27();
    virtual void o28();
    virtual void o29();
    virtual void o30();
    virtual void o31();
    virtual void o32();
    virtual void o33();
    virtual void o34();
    virtual void o35();
    virtual void o36();
    virtual void o37();
    virtual void o38();
    virtual void o39();
    virtual void o40();
    virtual void o41();
    virtual void o42();
    virtual void o43();
    virtual void o44();
    virtual void o45();
    virtual void o46();
    virtual void o47();
    virtual void o48();
    virtual void o49();
    virtual void o50();
    virtual void o51();
    virtual void o52();
    virtual void o53();
    virtual void o54();
    virtual void o55();
    virtual void o56();
    virtual void o57();
    virtual void o58();
    virtual void o59();
    virtual void o60();
    virtual void o61();
    virtual void o62();
    virtual void o63();
    virtual void o64();
    virtual void o65();
    virtual void o66();
    virtual void o67();
    virtual void o68();
    virtual void o69();
    virtual void o70();
    virtual void o71();
    virtual void o72();
    virtual void o73();
    virtual void o74();
    virtual void o75();
    virtual void o76();
    virtual void o77();
    virtual void o78();
    virtual void o79();
    virtual void o80();
    virtual void o81();
    virtual void o82();
    virtual void o83();
    virtual void o84();
    virtual void o85();
    virtual void o86();
    virtual void o87();
    virtual void o88();
    virtual void o89();
    virtual void o90();
    virtual void o91();
    virtual void o92();
    virtual void o93();
    virtual void o94();
    virtual void o95();
    virtual void o96();
    virtual void o97();
    virtual void o98();
    virtual void o99();
    virtual void o100();
    virtual void o101();
    virtual void o102();
    virtual void o103();
    virtual void o104();
    virtual void o105();
    virtual void o106();
    virtual void o107();
    virtual void o108();
    virtual void o109();
    virtual void o110();
    virtual void o111();
    virtual void o112();
    virtual void o113();
    virtual void o114();
    virtual void o115();
    virtual void o116();
    virtual void o117();
    virtual void o118();
    virtual void o119();
    virtual void o120();
    virtual void o121();
    virtual void o122();
    virtual void o123();
    virtual void o124();
    virtual void o125();
    virtual void o126();
    virtual void o127();
    virtual void o128();
    virtual void o129();
    virtual void o130();
    virtual void o131();
    virtual void o132();
    virtual void o133();
    virtual void o134();
    virtual void o135();
    virtual void o136();
    virtual void o137();
    virtual void Lock(int a);
    ListQ* FUN_005d43c0(int type);
    int FUN_008d6f30();
    TESForm* FUN_004867a0(int a, int b);
    ResQ* FUN_0055c050(int a1, int a2);
};

struct Ref;
struct CopyNode;
struct Extra;
struct Link;
struct CopyHolder;
struct Property;
struct Vec
{
    float x, y, z;
};
struct Matrix
{
    float xx, xy, xz, yx, yy, yz, zx, zy, zz;
};

struct AttachedSceneProvider
{
    Ref* ref;
    int flags;
};
struct Link
{
    AttachedSceneProvider** FUN_006815c0();
    Link* FUN_00726070();
    bool FUN_008256d0();
};
struct CopyHolder
{
    Ref* FUN_00559450();
    void FUN_00537e90(Ref*);
};
struct Extra
{
    void FUN_0041dda0(Ref*);
    short FUN_00418770();
    void FUN_0041e600(Ref*);
    Link* FUN_0041e780();
    void FUN_0041ef20(Ref*);
    Link* FUN_0041f170();
    void FUN_0041f4c0(Ref*, bool);
    void FUN_0041f650(Ref*, bool);
    Link* FUN_0041f810();
    CopyHolder* FUN_00418250();
    void FUN_0041f840(Ref*, bool);
    void FUN_00411ec0(Extra*);
    void FUN_0041e530(Ref*);
    void FUN_0041edd0(Ref*);
    void FUN_0041ae70();
    void FUN_0041dcd0(Ref*);
};
struct PropertyList
{
    void FUN_0057c730(Ref* const&);
    void* FUN_0049c680(Ref* const&, void*);
    void FUN_004ed8c0(Ref* const&);
};
struct Property
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
    char unk080;
    char unk081;
    char unk082;
    bool dirty;
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
    PropertyList refs;
};
struct CopyNode
{
    void FUN_00440460(const Vec*);
    void FUN_0043fa80(const Matrix*);
    void FUN_00a59c60(NiUpdateData&);
    void FUN_00440490(float);
    CopyNode* FUN_009611e0();
    void FUN_00a5a040();
    CopyNode* FUN_004030b0();
    int FUN_008d8520();
    Property* FUN_00a59d30(int);
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void attach(CopyNode*, bool);
};
struct Ref
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
    virtual bool special();
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
    virtual CopyNode* baseNode(Ref*, int);
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
    virtual CopyNode* loadNode(bool);
    virtual void SetCopyNodeReference(CopyNode*, bool);
    virtual CopyNode* node();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual const Vec* position();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    Ref* base;
    float rx, ry, rz, px, py, pz;
    bool FUN_004077c0();
    Ref* FUN_0056a9f0();
    Extra* FUN_005d43c0();
    bool FUN_005653d0();
    void FUN_00565480(bool);
    void FUN_004851b0(TESForm*);
    Ref* FUN_007af430();
    void* FUN_00891170();
    float FUN_00598040();
    int FUN_00401170();
    float FUN_00568cb0();
    int FUN_00569580();
    Matrix FUN_0056fa00();
    struct Cell* FUN_008d6f30();
    CopyHolder* FUN_00568e50();
    void FUN_00568f30();
    Ref* FUN_00569b80();
    void FUN_00569be0(Ref*);
    void FUN_00569df0(int);
    void FUN_00569cb0(bool, int);
    void FUN_0056a1e0(bool);
    void FUN_00567490(float);
    float FUN_00567400();
    bool FUN_00572d30(int);
    void FUN_0057ada0();
    CopyHolder* FUN_00568e70();
    void* FUN_00569140();
    void* FUN_00567770();
    void FUN_00567c50();
    void FUN_0055c3e0(TESForm*);
};
struct Cell
{
    void FUN_00548230(Ref*, bool);
    void FUN_0054ca90(Ref*);
};
struct IO
{
    void FUN_00456520();
};
extern IO* DAT_01202d98;
struct WorldManager
{
    struct Scene* FUN_0070ec90();
    bool FUN_004511e0(Cell*, bool);
    void FUN_00451ef0(Ref*, Cell*, int, int);
};
extern WorldManager* g_TES;
struct Scene
{
    CopyNode* FUN_004e8030(AttachedSceneProvider*);
};
struct Shadow
{
    void FUN_00b5eed0(Ref*);
};
Shadow* FUN_00450b80(int);
void FUN_00c6bd00(CopyNode*, bool);
bool FUN_0040eb10(float, float, float);
extern float DAT_01017d00;
void* __cdecl __memcpy(void*, const void*, unsigned);
void FUN_0047aec0(Ref*, bool, bool);
void FNV_Warning(const char*);
struct BaseView
{
    void FUN_0050d810(Ref*, CopyNode*, bool);
};

namespace s55d310 {

struct Component
{
    int unk00;
};

struct WeaponBase
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
    int unk60;
};

struct Weapon : WeaponBase, Component
{
};

struct AmmoBase
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
    int unk2c;
};

struct Ammo : AmmoBase, Component
{
};

struct Form
{
    int FUN_00401170();
};

struct Owner
{
    Form* FUN_007af430();
    Component* FUN_0055d310();
};

}

extern unsigned int DAT_01187020;

struct S_0055e3f0_ref
{
    unsigned int vptr;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int m_0C;
};

class S_0055e3f0_obj
{
  public:
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
    virtual bool v0e(S_0055e3f0_ref* a1);
};

class S_0055e3f0_sub
{
  public:
    virtual S_0055e3f0_obj* v00();
};

class S_0055e3f0_cls
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    S_0055e3f0_sub sub;
    bool FUN_005653d0();
    bool FUN_0055e3f0(S_0055e3f0_ref* a1);
};

namespace fnv_0055e5e0 {
extern unsigned int kGroupFormType;

struct ChangeGroupInfo
{
    unsigned int formType;
    int unk04;
    unsigned int unk08;
    int unk0C;
    int unk10;
};

struct ChangeRequest
{
    int unk00;
    int unk04;
    unsigned int unk08;
    int unk0C;
};

struct CellStub
{
    bool IsCellFlagA();
    unsigned int GetWorldKey();
    unsigned int GetCellKey();
};

struct ChildCellStub
{
    virtual CellStub* GetPersistentCell();
};

struct RefStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    ChildCellStub childCell;
    bool IsRefFlagA();
    void FillGroupChangeInfo(ChangeGroupInfo* info, ChangeRequest* req);
};

}  // namespace fnv_0055e5e0

extern float DAT_01017d00;
struct TriggerContext
{
    int __thiscall FUN_00561730(void* result);
};
struct VirtualDispatcher
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void Dispatch(TriggerContext* context);
};
struct FUN_005616d0_Owner
{
    void* __thiscall FUN_00560dc0(float amount);
    void __thiscall FUN_00c9c1d0();
    VirtualDispatcher* __thiscall FUN_009d9f40();
    void __thiscall OnTrigger(TriggerContext* context);
};

struct FUN_00561730_Obj
{
    int __thiscall FUN_00561730(int value);
};

struct FUN_009d9f40_Virtual
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44(FUN_00561730_Obj* value);
};

struct FUN_00561800_Class
{
    int __thiscall FUN_00560e50(float value);
    void __thiscall FUN_00c9c1d0();
    FUN_009d9f40_Virtual* __thiscall FUN_009d9f40();
    void __thiscall FUN_00561800(FUN_00561730_Obj* object);
};

extern float DAT_01017d00;

namespace fnv_00561860 {
struct NiPoint3
{
    float x, y, z;
};
struct NiCollisionObject;

struct NiUpdateData
{
    int u0;
    int u4;
    int u8;
    NiUpdateData(float, bool, bool);
};

struct NiAVObject
{
    void Update(const NiUpdateData&);
};

struct St
{
    unsigned char f0;
    unsigned short w1;
    unsigned short w2;
    int f8;
    int fc;
    int f10;
    St();
};

struct Ctx
{
    int f0;
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
    unsigned char f7;
    int f8;
    void* fC;
    void* f10;
    int f14;
    int f18;
};

struct QHolder
{
    void ZCall(int);
};

struct QFix
{
    void M1(int, float);
    void M2();
};

struct ZSave
{
    unsigned char GetVer();
    void Init(unsigned int);
};

struct RefVt
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
    virtual unsigned char v64();
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
    virtual const char* v76();
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
    virtual QFix* v121();
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
    virtual unsigned char v141();
    int pad[0x2a];
};

struct Ref00561860 : RefVt
{
    QHolder* fAC;
    void Read(void*, unsigned int);
    NiAVObject* Get3DSimple();
    unsigned int Form();
    void GetHavok(St*);
    void FUN_00561860(unsigned short arg);
};

extern ZSave* g_save;
extern NiPoint3 g_ptZero;

void Warn(const char*, ...);
void CB(NiCollisionObject*, void*);
void* ZCount(NiAVObject*);
void ZScan(NiAVObject*, Ctx*, void (*)(NiCollisionObject*, void*));
void ZFix(NiAVObject*, int, int);
void ZHide(NiAVObject*, int, bool, bool, bool);
void ZMove(NiAVObject*, NiPoint3*, int, float, int);

}  // namespace fnv_00561860

struct Vec3
{
    int a, b, c;
};
struct Inner
{
    void* __thiscall FUN_00410220(unsigned char);
    void* __thiscall FUN_0041b320();
};
struct TypeObj
{
    int __thiscall FUN_00401170();
    unsigned char __thiscall FUN_00425fd0();
    void* __thiscall FUN_0054ddd0();
};
struct S00561df0
{
    char _pad[0x40];
    void* field_40;
    Inner* __thiscall FUN_005d43c0();
    void* __thiscall FUN_00575d70();
    unsigned char __thiscall FUN_00561df0(Vec3* pOutA, Vec3* pOutB, void** ppOut, TypeObj* pOpt);
};

namespace fnv_005623d0 {
struct FlagsX
{
    unsigned u;
    FlagsX()
    {}
    bool FUN_004280f0();
};
struct SubX
{
    void FUN_00428150(void* p);
    void FUN_0041aeb0();
    bool FUN_0041b3a0(int i);
    void FUN_0041b470(int i);
    void FUN_0041b440(int i);
    float FUN_0041b6b0();
};
struct ChangeX
{
    FlagsX FUN_00428110(unsigned uiMask);
    void FUN_00864980(void* pData, int iSize);
};
struct HandlerX
{
    void FUN_004d4160(ChangeX* p);
};
struct MgrX
{
    void FUN_0084a810(int a, ChangeX* p, int b);
};
extern MgrX* DAT_011ddf38;
struct NameX
{
    void* FUN_00559450();
};
struct BaseX
{
    char pad[0x14];
    NameX kName;
};
struct FormX
{
    bool FUN_00476f50(void* p, int i);
};
struct RefX;
HandlerX* __cdecl FUN_004bf220(RefX* p);
FormX* __cdecl FUN_00475400(void* p);
void __cdecl FUN_0055d6d0(RefX* p, int i);
struct RefX
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c(), v020(), v024(), v028(), v02c(), v030(),
        v034(), v038(), v03c(), v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c(), v060(), v064(), v068(),
        v06c(), v070(), v074(), v078(), v07c(), v080(), v084(), v088(), v08c(), v090(), v094(), v098(), v09c(), v0a0(),
        v0a4(), v0a8(), v0ac(), v0b0(), v0b4(), v0b8(), v0bc(), v0c0(), v0c4(), v0c8(), v0cc(), v0d0(), v0d4(), v0d8(),
        v0dc(), v0e0(), v0e4(), v0e8(), v0ec(), v0f0(), v0f4(), v0f8(), v0fc();
    virtual bool v100();
    virtual void v104(), v108(), v10c(), v110(), v114(), v118(), v11c(), v120(), v124(), v128(), v12c(), v130(), v134(),
        v138(), v13c(), v140(), v144(), v148(), v14c(), v150(), v154(), v158(), v15c(), v160(), v164(), v168(), v16c(),
        v170(), v174(), v178(), v17c(), v180(), v184(), v188(), v18c(), v190(), v194(), v198(), v19c(), v1a0(), v1a4(),
        v1a8(), v1ac(), v1b0(), v1b4(), v1b8(), v1bc(), v1c0(), v1c4(), v1c8(), v1cc();
    virtual int v1d0();
    char pad4[0x38];
    float m3c;
    char pad40[0x24];
    BaseX* m64;
    void FUN_00484da0(ChangeX* p);
    void FUN_00484580(int i);
    void FUN_00567490(float f);
    SubX* FUN_005d43c0();
    bool FUN_00452370();
    void* FUN_007af430();
    void FUN_0057a3c0(int i);
    void ApplyChanges(ChangeX* pkChanges);
};
}  // namespace fnv_005623d0

namespace fnv_005629a0 {
struct ChangeFlags
{
    unsigned int value;
    bool FUN_004280f0(unsigned int mask);
};
struct LoadBuffer
{
    ChangeFlags FUN_0042ce30();
    bool FUN_00562d00();
};
struct Ref;
struct ExtraList
{
    float FUN_0041b6b0();
    void FUN_0042dae0(LoadBuffer*);
    void FUN_0042dd90(LoadBuffer*);
    bool FUN_0041b3a0(int);
    void FUN_0041b470(int);
    void FUN_0041b440(int);
};
struct ParentCell
{
    void FUN_00545670(Ref*);
};
struct NodePointer
{
    void* FUN_00559450();
};
struct LoadedData
{
    unsigned int unk00, unk04, unk08;
    float unk0c;
    unsigned int unk10;
    NodePointer node;
};
struct OpenClose
{
    bool FUN_00476f50(Ref*, bool);
};
OpenClose* FUN_00475400(void*);
void FUN_0047aec0(Ref*, bool, bool);
bool FUN_0062c3c0(Ref*, void*);
void FUN_0055d6d0(Ref*, void*);
struct Ref
{
    virtual void virtual_000();
    virtual void virtual_004();
    virtual void virtual_008();
    virtual void virtual_00c();
    virtual void virtual_010();
    virtual void virtual_014();
    virtual void virtual_018();
    virtual void virtual_01c();
    virtual void virtual_020();
    virtual void virtual_024();
    virtual void virtual_028();
    virtual void virtual_02c();
    virtual void virtual_030();
    virtual void virtual_034();
    virtual void virtual_038();
    virtual void virtual_03c();
    virtual void virtual_040();
    virtual void virtual_044();
    virtual void virtual_048();
    virtual void virtual_04c();
    virtual void virtual_050();
    virtual void virtual_054();
    virtual void virtual_058();
    virtual void virtual_05c();
    virtual void virtual_060();
    virtual void virtual_064();
    virtual void virtual_068();
    virtual void virtual_06c();
    virtual void virtual_070();
    virtual void virtual_074();
    virtual void virtual_078();
    virtual void virtual_07c();
    virtual void virtual_080();
    virtual void virtual_084();
    virtual void virtual_088();
    virtual void virtual_08c();
    virtual void virtual_090();
    virtual void virtual_094();
    virtual void virtual_098();
    virtual void virtual_09c();
    virtual void virtual_0a0();
    virtual void virtual_0a4();
    virtual void virtual_0a8();
    virtual void virtual_0ac();
    virtual void virtual_0b0();
    virtual void virtual_0b4();
    virtual void virtual_0b8();
    virtual void virtual_0bc();
    virtual void virtual_0c0();
    virtual void virtual_0c4();
    virtual void virtual_0c8();
    virtual void virtual_0cc();
    virtual void virtual_0d0();
    virtual void virtual_0d4();
    virtual void virtual_0d8();
    virtual void virtual_0dc();
    virtual void virtual_0e0();
    virtual void virtual_0e4();
    virtual void virtual_0e8();
    virtual void virtual_0ec();
    virtual void virtual_0f0();
    virtual void virtual_0f4();
    virtual void virtual_0f8();
    virtual void virtual_0fc();
    virtual bool IsActor();
    virtual void virtual_104();
    virtual void virtual_108();
    virtual void virtual_10c();
    virtual void virtual_110();
    virtual void virtual_114();
    virtual void virtual_118();
    virtual void virtual_11c();
    virtual void virtual_120();
    virtual void virtual_124();
    virtual void virtual_128();
    virtual void virtual_12c();
    virtual void virtual_130();
    virtual void virtual_134();
    virtual void virtual_138();
    virtual void virtual_13c();
    virtual void virtual_140();
    virtual void virtual_144();
    virtual void virtual_148();
    virtual void virtual_14c();
    virtual void virtual_150();
    virtual void virtual_154();
    virtual void virtual_158();
    virtual void virtual_15c();
    virtual void virtual_160();
    virtual void virtual_164();
    virtual void virtual_168();
    virtual void virtual_16c();
    virtual void virtual_170();
    virtual void virtual_174();
    virtual void virtual_178();
    virtual void virtual_17c();
    virtual void virtual_180();
    virtual void virtual_184();
    virtual void virtual_188();
    virtual void virtual_18c();
    virtual void virtual_190();
    virtual void virtual_194();
    virtual void virtual_198();
    virtual void virtual_19c();
    virtual void virtual_1a0();
    virtual void virtual_1a4();
    virtual void virtual_1a8();
    virtual void virtual_1ac();
    virtual void virtual_1b0();
    virtual void virtual_1b4();
    virtual void virtual_1b8();
    virtual void virtual_1bc();
    virtual void virtual_1c0();
    virtual void virtual_1c4();
    virtual void virtual_1c8();
    virtual void virtual_1cc();
    virtual void* GetNode();
    virtual void virtual_1d4();
    virtual void virtual_1d8();
    virtual void virtual_1dc();
    virtual void virtual_1e0();
    virtual void virtual_1e4();
    virtual void virtual_1e8();
    virtual void virtual_1ec();
    virtual void virtual_1f0();
    virtual void virtual_1f4();
    virtual void virtual_1f8();
    virtual void virtual_1fc();
    virtual void virtual_200();
    virtual void virtual_204();
    virtual void ResetState(bool);
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
    ParentCell* parentCell;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    LoadedData* loadedData;
    void FUN_005629a0(LoadBuffer* buffer);
    void FUN_004534f0(LoadBuffer*);
    void FUN_00484580(bool);
    ExtraList* FUN_005d43c0();
    bool FUN_00452370();
    void* FUN_007af430();
    void FUN_0057a3c0(bool);
    void ResetAnimation();
    void FUN_00574920(bool);
    bool FUN_00572d30(int);
    void FUN_00577330(void*);
};
}  // namespace fnv_005629a0

namespace fnv_00563890 {
struct NiAVObject;
struct Seq;
struct Mgr;
struct Ref;

class NiFixedString
{
  public:
    NiFixedString(const char* p);
    ~NiFixedString();
    int v;
};

struct NiUpdateData
{
    float t;
    bool f;
    bool c;
    int u;
    NiUpdateData(float, bool, bool);
};

struct NiRTTI
{
    int x;
};

struct ExtraData
{
    char* FUN_004228f0();
};

struct ShadowSceneNode
{
    void AddObject(NiAVObject* p);
};

struct G11DEA10
{
    bool FUN_004511e0(void* p, int n);
};

struct M40
{
    void FUN_00548880(Ref* p, int n);
};

struct Ref
{
    virtual void vd0();
    virtual void vd1();
    virtual void vd2();
    virtual void vd3();
    virtual void vd4();
    virtual void vd5();
    virtual void vd6();
    virtual void vd7();
    virtual void vd8();
    virtual void vd9();
    virtual void vd10();
    virtual void vd11();
    virtual void vd12();
    virtual void vd13();
    virtual void vd14();
    virtual void vd15();
    virtual void vd16();
    virtual void vd17();
    virtual void vd18();
    virtual void vd19();
    virtual void vd20();
    virtual void vd21();
    virtual void vd22();
    virtual void vd23();
    virtual void vd24();
    virtual void vd25();
    virtual void vd26();
    virtual void vd27();
    virtual void vd28();
    virtual void vd29();
    virtual void vd30();
    virtual void vd31();
    virtual void vd32();
    virtual void vd33();
    virtual void vd34();
    virtual void vd35();
    virtual void vd36();
    virtual void vd37();
    virtual void vd38();
    virtual void vd39();
    virtual void vd40();
    virtual void vd41();
    virtual void vd42();
    virtual void vd43();
    virtual void vd44();
    virtual void vd45();
    virtual void vd46();
    virtual void vd47();
    virtual void vd48();
    virtual void vd49();
    virtual void vd50();
    virtual void vd51();
    virtual void vd52();
    virtual void vd53();
    virtual void vd54();
    virtual void vd55();
    virtual void vd56();
    virtual void vd57();
    virtual void vd58();
    virtual void vd59();
    virtual void vd60();
    virtual void vd61();
    virtual void vd62();
    virtual void vd63();
    virtual void vd64();
    virtual void vd65();
    virtual void vd66();
    virtual void vd67();
    virtual void vd68();
    virtual void vd69();
    virtual void vd70();
    virtual void vd71();
    virtual void vd72();
    virtual void vd73();
    virtual void vd74();
    virtual void vd75();
    virtual void vd76();
    virtual void vd77();
    virtual void vd78();
    virtual void vd79();
    virtual void vd80();
    virtual void vd81();
    virtual void vd82();
    virtual void vd83();
    virtual void vd84();
    virtual void vd85();
    virtual void vd86();
    virtual void vd87();
    virtual void vd88();
    virtual void vd89();
    virtual void vd90();
    virtual void vd91();
    virtual void vd92();
    virtual void vd93();
    virtual void* vfn_178(Ref* p);
    virtual void vd95();
    virtual void vd96();
    virtual void vd97();
    virtual void vd98();
    virtual void vd99();
    virtual void vd100();
    virtual void vd101();
    virtual void vd102();
    virtual void vd103();
    virtual void vd104();
    virtual void vd105();
    virtual void vd106();
    virtual void vd107();
    virtual void vd108();
    virtual void vd109();
    virtual void vd110();
    virtual void vd111();
    virtual void vd112();
    virtual void vfn_1c4();
    virtual void vd114();
    virtual void vfn_1cc(void* p, int n);
    char pad0[0x1c];
    Ref* m20;
    char pad1[0x1c];
    M40* m40;
    NiAVObject* FUN_0043fcd0();
    ExtraData* FUN_005d43c0();
    void ResetAnimation();
};

struct NiAVObject
{
    NiAVObject* FUN_0043b230();
    void FUN_00a59c60(NiUpdateData const& d);
};

struct Seq
{
    int FUN_008041a0();
    void FUN_0098adb0(float f);
    float FUN_009a9350();
};

struct Mgr
{
    Seq* FUN_0047a520(NiFixedString const& s);
    void FUN_0048fef0(float f);
    void FUN_0047aa40(bool b);
    void FUN_0047aab0(Seq* s, int a, int b, float f1, float f2, int c);
    unsigned int FUN_00495d00();
    Seq* FUN_00495d20(unsigned int i2);
};

int _stricmp(const char* a, const char* b);
NiAVObject* NiDynamicCast(NiRTTI const* t, NiAVObject* o);
bool FUN_004b5bf0(NiAVObject* o);
void FUN_0047ab40(Ref* r, Seq* s);
ShadowSceneNode* FUN_00450b80(unsigned int i2);

extern char* DAT_01197b5c;
extern char* DAT_011977d8;
extern char* DAT_01197820;
extern NiRTTI DAT_011f36ac;
extern float DAT_0102f510;
extern G11DEA10* DAT_011dea10;

}  // namespace fnv_00563890

namespace fnv_00564010 {
struct Buf;
struct NiAVObject;

struct NiUpdateData
{
    float m_fTime;
    bool m_bForce;
    bool m_bChildren;
    int m_iUnk;
    NiUpdateData(float, bool, bool);
};

struct NiAVObject
{
    void FUN_00a59c90(NiUpdateData&);
    void FUN_00a59c60(NiUpdateData&);
};

struct Buf
{
    virtual void v0();
    virtual void v1();
    virtual void* v2();
    unsigned int FUN_00864a60();
    char* FUN_008649a0(char*);
};

struct Mgr
{
    void FUN_0048fef0(float);
    void FUN_0047aa40(bool);
    unsigned int FUN_00495d00();
    void* FUN_00495d20(unsigned int);
    void FUN_0047aab0(void*, int, int, float, float, int);
};

struct Ref
{
    NiAVObject* FUN_0043fcd0();
};

struct NameList
{
    char* FUN_0043b1b0();
};

struct Pkg
{
    NameList* FUN_00413f40();
    int FUN_008041a0();
    void FUN_004efd10(Buf*, float);
    float FUN_00639aa0();
};

struct PkgTmp
{
    int u0;
    int u1;
    int u2;
    int u3;
    int u4;
    int u5;
    int u6;
    int u7;
    int u8;
    int u9;
    int u10;
    int u11;
    int u12;
    int u13;
    int u14;
    int u15;
    int u16;
    int u17;
    int u18;
    int u19;
    int u20;
    int u21;
    int u22;
    int u23;
    int u24;
    int u25;
    int u26;
    int u27;
    int u28;
    int u29;
    PkgTmp();
    ~PkgTmp();
    void FUN_004efd10(Buf*, float);
};

int FUN_00408b20(const char*, const char*);
bool FUN_004b5c80(NiAVObject*);
void FUN_00c6bd00(NiAVObject*, bool);

extern float DAT_011c3c08;

}  // namespace fnv_00564010

struct Other
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
    virtual bool vf();
};

struct Thing
{
    Other* FUN_007af430();
    bool FUN_00564bc0();
};

struct FUN_00564e60_shell : public TESObjectREFR
{
    bool FUN_00564e60();
};

unsigned int __fastcall GetFlags_wrapper(TESObjectREFR*);
bool __fastcall FUN_00564e40(void*);

namespace fnv_005656d0 {
struct Obj
{
    bool FUN_004d0490();
};
struct Thing
{
    Obj* FUN_007af430();
    int FUN_0055d310();
    bool FUN_005656d0();
};
extern "C" int FUN_004826d0(void* obj);
extern "C" void* FUN_004bf220(void* self);
}  // namespace fnv_005656d0

namespace fnv_00567400 {
class FormObj
{
  public:
    int FUN_00401170();
    float FUN_00944300();
    float FUN_00567470();
};

class RefObj
{
  public:
    FormObj* FUN_007af430();
};

struct FUN_00567400_shell
{
    char pad[0x3c];
    float m_vScale;

    float FUN_00567400();
};

}  // namespace fnv_00567400

#include <stdlib.h>
namespace fnv_00567490 {
struct NiUpdateData
{
    float time;
    bool updateControllers, multithreaded, field06, field07, field08;
    NiUpdateData(float, bool, bool);
};
struct NiAVObject
{
    void FUN_00440490(float);
    void Update(const NiUpdateData&);
};
struct FormType
{
    int FUN_00401170();
};
struct Controller
{
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00c;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01c;
    unsigned int unk020;
    unsigned int unk024;
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
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    unsigned int unk33c;
    unsigned int unk340;
    unsigned int unk344;
    unsigned int unk348;
    unsigned int unk34c;
    unsigned int unk350;
    unsigned int unk354;
    unsigned int unk358;
    unsigned int unk35c;
    unsigned int unk360;
    unsigned int unk364;
    unsigned int unk368;
    unsigned int unk36c;
    unsigned int unk370;
    unsigned int unk374;
    unsigned int unk378;
    unsigned int unk37c;
    unsigned int unk380;
    unsigned int unk384;
    unsigned int unk388;
    unsigned int unk38c;
    unsigned int unk390;
    unsigned int unk394;
    unsigned int unk398;
    unsigned int unk39c;
    unsigned int unk3a0;
    unsigned int unk3a4;
    unsigned int unk3a8;
    unsigned int unk3ac;
    unsigned int unk3b0;
    unsigned int unk3b4;
    unsigned int unk3b8;
    unsigned int unk3bc;
    unsigned int unk3c0;
    unsigned int unk3c4;
    unsigned int unk3c8;
    unsigned int unk3cc;
    unsigned int unk3d0;
    unsigned int unk3d4;
    unsigned int unk3d8;
    unsigned int unk3dc;
    unsigned int unk3e0;
    unsigned int unk3e4;
    unsigned int unk3e8;
    unsigned int unk3ec;
    unsigned int unk3f0;
    unsigned int unk3f4;
    unsigned int unk3f8;
    unsigned int unk3fc;
    unsigned int unk400;
    unsigned int unk404;
    unsigned int unk408;
    unsigned int unk40c;
    unsigned int unk410;
    unsigned int unk414;
    unsigned int unk418;
    unsigned int unk41c;
    unsigned int unk420;
    unsigned int unk424;
    unsigned int unk428;
    unsigned int unk42c;
    unsigned int unk430;
    unsigned int unk434;
    unsigned int unk438;
    unsigned int unk43c;
    unsigned int unk440;
    unsigned int unk444;
    unsigned int unk448;
    unsigned int unk44c;
    unsigned int unk450;
    unsigned int unk454;
    unsigned int unk458;
    unsigned int unk45c;
    unsigned int unk460;
    unsigned int unk464;
    unsigned int unk468;
    unsigned int unk46c;
    unsigned int unk470;
    unsigned int unk474;
    unsigned int unk478;
    unsigned int unk47c;
    unsigned int unk480;
    unsigned int unk484;
    unsigned int unk488;
    unsigned int unk48c;
    unsigned int unk490;
    unsigned int unk494;
    unsigned int unk498;
    unsigned int unk49c;
    unsigned int unk4a0;
    unsigned int unk4a4;
    unsigned int unk4a8;
    unsigned int unk4ac;
    unsigned int unk4b0;
    unsigned int unk4b4;
    unsigned int unk4b8;
    unsigned int unk4bc;
    unsigned int unk4c0;
    unsigned int unk4c4;
    unsigned int unk4c8;
    unsigned int unk4cc;
    unsigned int unk4d0;
    unsigned int unk4d4;
    unsigned int unk4d8;
    unsigned int unk4dc;
    unsigned int unk4e0;
    unsigned int unk4e4;
    unsigned int unk4e8;
    unsigned int unk4ec;
    unsigned int unk4f0;
    unsigned int unk4f4;
    unsigned int unk4f8;
    unsigned int unk4fc;
    unsigned int unk500;
    unsigned int unk504;
    unsigned int unk508;
    unsigned int unk50c;
    unsigned int unk510;
    unsigned int unk514;
    unsigned int unk518;
    unsigned int unk51c;
    unsigned int unk520;
    unsigned int unk524;
    unsigned int unk528;
    unsigned int unk52c;
    unsigned int unk530;
    unsigned int unk534;
    unsigned int unk538;
    unsigned int unk53c;
    unsigned int unk540;
    unsigned int unk544;
    unsigned int unk548;
    unsigned int unk54c;
    float saved550, saved554;
    float FUN_00567730();
    float FUN_00567750();
};
struct AnimIdle;
struct FUN_00633c90
{
    AnimIdle* value;
    FUN_00633c90(int);
    FUN_00633c90(const FUN_00633c90&);
    ~FUN_00633c90();
};
struct Process
{
    virtual void slot000();
    virtual void slot001();
    virtual void slot002();
    virtual void slot003();
    virtual void slot004();
    virtual void slot005();
    virtual void slot006();
    virtual void slot007();
    virtual void slot008();
    virtual void slot009();
    virtual void slot00a();
    virtual void slot00b();
    virtual void slot00c();
    virtual void slot00d();
    virtual void slot00e();
    virtual void slot00f();
    virtual void slot010();
    virtual void slot011();
    virtual void slot012();
    virtual void slot013();
    virtual void slot014();
    virtual void slot015();
    virtual void slot016();
    virtual void slot017();
    virtual void slot018();
    virtual void slot019();
    virtual void slot01a();
    virtual void slot01b();
    virtual void slot01c();
    virtual void slot01d();
    virtual void slot01e();
    virtual void slot01f();
    virtual void slot020();
    virtual void slot021();
    virtual void slot022();
    virtual void slot023();
    virtual void slot024();
    virtual void slot025();
    virtual void slot026();
    virtual void slot027();
    virtual void slot028();
    virtual void slot029();
    virtual void slot02a();
    virtual void slot02b();
    virtual void slot02c();
    virtual void slot02d();
    virtual void slot02e();
    virtual void slot02f();
    virtual void slot030();
    virtual void slot031();
    virtual void slot032();
    virtual void slot033();
    virtual void slot034();
    virtual void slot035();
    virtual void slot036();
    virtual void slot037();
    virtual void slot038();
    virtual void slot039();
    virtual void slot03a();
    virtual void slot03b();
    virtual void slot03c();
    virtual void slot03d();
    virtual void slot03e();
    virtual void slot03f();
    virtual void slot040();
    virtual void slot041();
    virtual void slot042();
    virtual void slot043();
    virtual void slot044();
    virtual void slot045();
    virtual void slot046();
    virtual void slot047();
    virtual void slot048();
    virtual void slot049();
    virtual void slot04a();
    virtual void slot04b();
    virtual void slot04c();
    virtual void slot04d();
    virtual void slot04e();
    virtual void slot04f();
    virtual void slot050();
    virtual void slot051();
    virtual void slot052();
    virtual void slot053();
    virtual void slot054();
    virtual void slot055();
    virtual void slot056();
    virtual void slot057();
    virtual void slot058();
    virtual void slot059();
    virtual void slot05a();
    virtual void slot05b();
    virtual void slot05c();
    virtual void slot05d();
    virtual void slot05e();
    virtual void slot05f();
    virtual void slot060();
    virtual void slot061();
    virtual void slot062();
    virtual void slot063();
    virtual void slot064();
    virtual void slot065();
    virtual void slot066();
    virtual void slot067();
    virtual void slot068();
    virtual void slot069();
    virtual void slot06a();
    virtual void slot06b();
    virtual void slot06c();
    virtual void slot06d();
    virtual void slot06e();
    virtual void slot06f();
    virtual void slot070();
    virtual void slot071();
    virtual void slot072();
    virtual void slot073();
    virtual void slot074();
    virtual void slot075();
    virtual void slot076();
    virtual void slot077();
    virtual void slot078();
    virtual void slot079();
    virtual void slot07a();
    virtual void slot07b();
    virtual void slot07c();
    virtual void slot07d();
    virtual void slot07e();
    virtual void slot07f();
    virtual void slot080();
    virtual void slot081();
    virtual void slot082();
    virtual void slot083();
    virtual void slot084();
    virtual void slot085();
    virtual void slot086();
    virtual void slot087();
    virtual void slot088();
    virtual void slot089();
    virtual void slot08a();
    virtual void slot08b();
    virtual void slot08c();
    virtual void slot08d();
    virtual void slot08e();
    virtual void slot08f();
    virtual void slot090();
    virtual void slot091();
    virtual void slot092();
    virtual void slot093();
    virtual void slot094();
    virtual void slot095();
    virtual void slot096();
    virtual void slot097();
    virtual void slot098();
    virtual void slot099();
    virtual void slot09a();
    virtual void slot09b();
    virtual void slot09c();
    virtual void slot09d();
    virtual void slot09e();
    virtual void slot09f();
    virtual void slot0a0();
    virtual void slot0a1();
    virtual void slot0a2();
    virtual void slot0a3();
    virtual void ResetIdle(FUN_00633c90);
};
struct ScaleReference
{
    virtual void slot000();
    virtual void slot004();
    virtual void slot008();
    virtual void slot00c();
    virtual void slot010();
    virtual void slot014();
    virtual void slot018();
    virtual void slot01c();
    virtual void slot020();
    virtual void slot024();
    virtual void slot028();
    virtual void slot02c();
    virtual void slot030();
    virtual void slot034();
    virtual void slot038();
    virtual void slot03c();
    virtual void slot040();
    virtual void slot044();
    virtual void MarkChanged(unsigned int);
    virtual void slot04c();
    virtual void slot050();
    virtual void slot054();
    virtual void slot058();
    virtual void slot05c();
    virtual void slot060();
    virtual void slot064();
    virtual void slot068();
    virtual void slot06c();
    virtual void slot070();
    virtual void slot074();
    virtual void slot078();
    virtual void slot07c();
    virtual void slot080();
    virtual void slot084();
    virtual void slot088();
    virtual void slot08c();
    virtual void slot090();
    virtual void slot094();
    virtual void slot098();
    virtual void slot09c();
    virtual void slot0a0();
    virtual void slot0a4();
    virtual void slot0a8();
    virtual void slot0ac();
    virtual void slot0b0();
    virtual void slot0b4();
    virtual void slot0b8();
    virtual void slot0bc();
    virtual void slot0c0();
    virtual void slot0c4();
    virtual void slot0c8();
    virtual void slot0cc();
    virtual void slot0d0();
    virtual void slot0d4();
    virtual void slot0d8();
    virtual void slot0dc();
    virtual void slot0e0();
    virtual void slot0e4();
    virtual void slot0e8();
    virtual void slot0ec();
    virtual void slot0f0();
    virtual void slot0f4();
    virtual void slot0f8();
    virtual void slot0fc();
    virtual bool IsActor();
    virtual void slot104();
    virtual void slot108();
    virtual void slot10c();
    virtual void slot110();
    virtual void slot114();
    virtual void slot118();
    virtual void slot11c();
    virtual void slot120();
    virtual void slot124();
    virtual void slot128();
    virtual void slot12c();
    virtual void slot130();
    virtual void slot134();
    virtual void slot138();
    virtual void slot13c();
    virtual void slot140();
    virtual void slot144();
    virtual void slot148();
    virtual void slot14c();
    virtual void slot150();
    virtual void slot154();
    virtual void slot158();
    virtual void slot15c();
    virtual void slot160();
    virtual void slot164();
    virtual void slot168();
    virtual void slot16c();
    virtual void slot170();
    virtual void slot174();
    virtual void slot178();
    virtual void slot17c();
    virtual void slot180();
    virtual void slot184();
    virtual void slot188();
    virtual void slot18c();
    virtual void slot190();
    virtual void slot194();
    virtual void slot198();
    virtual void slot19c();
    virtual void slot1a0();
    virtual void slot1a4();
    virtual void slot1a8();
    virtual void slot1ac();
    virtual void slot1b0();
    virtual void slot1b4();
    virtual void slot1b8();
    virtual void slot1bc();
    virtual void slot1c0();
    virtual void UpdateController();
    virtual void slot1c8();
    virtual void slot1cc();
    virtual NiAVObject* GetNode();
    virtual void slot1d4();
    virtual void slot1d8();
    virtual void slot1dc();
    virtual void slot1e0();
    virtual void slot1e4();
    virtual void slot1e8();
    virtual void slot1ec();
    virtual void slot1f0();
    virtual void slot1f4();
    virtual void slot1f8();
    virtual void slot1fc();
    virtual void slot200();
    virtual void slot204();
    virtual void slot208();
    virtual void slot20c();
    virtual void slot210();
    virtual void slot214();
    virtual void slot218();
    virtual void slot21c();
    virtual void slot220();
    virtual void slot224();
    virtual void slot228();
    virtual void slot22c();
    virtual void slot230();
    virtual void slot234();
    virtual void slot238();
    virtual void slot23c();
    virtual void slot240();
    virtual void slot244();
    virtual void slot248();
    virtual void slot24c();
    virtual void slot250();
    virtual void slot254();
    virtual void slot258();
    virtual void slot25c();
    virtual void slot260();
    virtual void slot264();
    virtual void slot268();
    virtual void slot26c();
    virtual void slot270();
    virtual void slot274();
    virtual void slot278();
    virtual void slot27c();
    virtual void slot280();
    virtual void slot284();
    virtual void slot288();
    virtual void slot28c();
    virtual void slot290();
    virtual void slot294();
    virtual void slot298();
    virtual void slot29c();
    virtual void RefreshPhysics();
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
    float m_fObjectScale;
    bool FUN_00444ed0();
    FormType* FUN_007af430();
    float FUN_00567400();
    NiAVObject* FUN_00950bb0(bool);
    Controller* FUN_009306d0();
    Process* FUN_008d8520();
    void FUN_00962450();
    void FUN_00567490(float scale);
};
extern ScaleReference* g_thePlayer;
extern unsigned int DAT_010a2720;
struct ScrapHeapBuffer
{
    void* FUN_00aa54a0(unsigned int, unsigned int);
    void FUN_00aa5610(void*);
};
struct MemoryManager
{
    ScrapHeapBuffer* FUN_00aa42e0();
};
MemoryManager* FUN_00401020();
int FUN_00406d00(char*, unsigned int, const char*, ...);

}  // namespace fnv_00567490

namespace s5679f0 {

struct Process
{
    int FUN_004186c0();
};

struct Actor
{
    Process* FUN_005d43c0();
};

template <class T> class NiPointer
{
  public:
    operator T*() const;

    T* m_pObject;
};

struct Faction
{
    int FUN_00567ab0();
};

struct Class
{
    int FUN_00546ac0();
};

Faction* FUN_00546a90();

struct Owner
{
    Process* FUN_005d43c0();
    NiPointer<Actor>* FUN_00568e50();
    Faction* FUN_00567d20();
    Class* FUN_008d6f30();
    int FUN_005679f0();
};

}

namespace fnv_00567e10 {
class PlayerCharacter
{
  public:
    unsigned short GetLevel();
};

extern PlayerCharacter* g_thePlayer;

class GlobalObject2_0040c150
{
  public:
    int* Int();
};

extern GlobalObject2_0040c150 g_011ca2b0;
extern GlobalObject2_0040c150 g_011ca31c;
extern int DAT_011ca420;

void* FUN_00546a90();

class LevelObj
{
  public:
    unsigned short FUN_00567ec0();
};

struct FUN_00567e10_shell
{
    LevelObj* FUN_00567d20();
    unsigned int FUN_00567e10(bool arg);
};

}  // namespace fnv_00567e10

struct FUN_00568680_shell : public TESObjectREFR
{
    bool FUN_00568680();
};

void* __fastcall _FNV_GetObjectReference(void*);

namespace s5693d0 {

extern int DAT_011ca244;
extern int DAT_011ca248;

struct Entry
{
    int FUN_00421b40();
};

struct Owner
{
    int FUN_007af430();
    Entry* FUN_005d43c0();
    int FUN_005693d0();
};

}

struct FUN_005694c0_shell : public TESObjectREFR
{
    bool FUN_005694c0();
};

class TESForm;
void* __fastcall _FNV_GetObjectReference(void*);
bool __cdecl FUN_00569410(void*);
unsigned int __fastcall _ref_0084e3a0(void*);
void __cdecl _FNV_Warning(const char*, ...);

struct TESObjectREFR_Emittance : public TESObjectREFR
{
    TESForm* GetOwnerForm();
};

namespace s569840 {

struct Entry
{
    int FUN_00421f00();
};

struct Owner
{
    bool FUN_00439f90();
    Entry* FUN_005d43c0();
    int FUN_00569840();
};

}

namespace fnv_0056a4a0 {
struct PosX
{
    float x, y, z;
};
struct ColorX
{
    float r, g, b;
    ColorX(float r, float g, float b);
};
struct GeomX
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c(), v020(), v024(), v028(), v02c(), v030(),
        v034(), v038(), v03c(), v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c(), v060(), v064(), v068(),
        v06c(), v070(), v074(), v078(), v07c(), v080(), v084(), v088(), v08c(), v090();
    virtual unsigned v94();
    virtual unsigned v98();
};
struct GeomPtr
{
    GeomX* p;
    GeomPtr(GeomX* q);
    ~GeomPtr();
    GeomX* FUN_00559450();
};
struct SubX
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c(), v020(), v024(), v028(), v02c(), v030(),
        v034(), v038(), v03c(), v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c(), v060(), v064(), v068(),
        v06c(), v070(), v074(), v078(), v07c(), v080(), v084(), v088(), v08c();
    virtual void v90(int i, GeomPtr* sp);
};
struct LightDataX
{
    float FUN_006b9130();
    float FUN_006a7f50();
    float FUN_0084d030();
    float FUN_00488d50();
    unsigned FUN_007af430();
    float FUN_00621b00();
    float FUN_0047c860();
    bool FUN_004a41a0();
    bool FUN_004a4160();
    bool FUN_004a4120();
    float FUN_004a7bd0();
    bool FUN_004a4200();
};
struct LightX
{
    int pad[12];
    SubX kSub;
    bool FUN_0056a860();
    LightDataX* FUN_0056a880();
};
struct RefX
{
    LightX* FUN_007af430();
    float FUN_00567400();
};
struct EntryX
{
    RefX* m0;
    PosX m4;
    PosX m10;
};
struct IterX
{
    bool FUN_008256d0();
    EntryX** FUN_006815c0();
    IterX* FUN_00726070();
};
struct ListX
{
    IterX* FUN_0041f050();
};
struct DescX
{
    PosX kPos;
    PosX kWorldPosition;
    int pad18[4];
    int m28;
    int pad2c;
    LightX* pkLight;
    int pad34;
    float m38;
    float m3c;
    float m40;
    int pad44[2];
    float m4c;
    int pad50;
    float m54;
    float m58;
    int pad5c;
    ColorX kColor;
    int pad6c;
    unsigned char ucAlpha;
    bool b71;
    bool b72;
    bool b73;
    bool b74;
    bool b75;
    bool b76;
    bool b77;
    int pad78[2];
    DescX();
};
struct MgrX
{
    void FUN_004a3fe0(DescX* p, int i, int j);
};
float __cdecl FUN_00476b70(float a, float b);
struct ActorX
{
    virtual void v000(), v004(), v008(), v00c(), v010(), v014(), v018(), v01c(), v020(), v024(), v028(), v02c(), v030(),
        v034(), v038(), v03c(), v040(), v044(), v048(), v04c(), v050(), v054(), v058(), v05c(), v060(), v064(), v068(),
        v06c(), v070(), v074(), v078(), v07c(), v080(), v084(), v088(), v08c(), v090(), v094(), v098(), v09c(), v0a0(),
        v0a4(), v0a8(), v0ac(), v0b0(), v0b4(), v0b8(), v0bc(), v0c0(), v0c4(), v0c8(), v0cc(), v0d0(), v0d4(), v0d8(),
        v0dc(), v0e0(), v0e4(), v0e8(), v0ec(), v0f0(), v0f4(), v0f8(), v0fc(), v100(), v104(), v108(), v10c(), v110(),
        v114(), v118(), v11c(), v120(), v124(), v128(), v12c(), v130(), v134(), v138(), v13c(), v140(), v144(), v148(),
        v14c(), v150(), v154(), v158(), v15c(), v160(), v164(), v168(), v16c(), v170(), v174(), v178(), v17c(), v180(),
        v184(), v188(), v18c(), v190(), v194(), v198(), v19c(), v1a0(), v1a4(), v1a8(), v1ac(), v1b0(), v1b4(), v1b8(),
        v1bc(), v1c0(), v1c4(), v1c8(), v1cc();
    virtual int v1d0();
    void FUN_0056a8d0();
    ListX* FUN_005d43c0();
    MgrX* FUN_008d6f30();
    void UpdateLightDescriptors(int iArg);
};
}  // namespace fnv_0056a4a0

namespace fnv_0056ad80 {
struct Other
{
    int FUN_00401170();
};
struct Result
{
    Other* m_ptr;
};
struct Sub
{
    Result* FUN_00418b70();
};
struct Thing
{
    Sub* FUN_005d43c0();
    int FUN_0056ad80();
};
}  // namespace fnv_0056ad80

namespace fnv_0056add0 {
struct Extra
{
    int* FUN_00418b70();
};

struct Obj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void vEC();
    virtual void vF0();
    virtual void vF4();
    virtual void vF8();
    virtual void vFC();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10C();
    virtual void v110();
    virtual void v114();
    virtual void v118();
    virtual void v11C();
    virtual void v120();
    virtual void v124();
    virtual void v128();
    virtual void v12C();
    virtual void v130();
    virtual void v134();
    virtual void v138();
    virtual void v13C();
    virtual void v140();
    virtual void v144();
    virtual void v148();
    virtual void v14C();
    virtual void v150();
    virtual void v154();
    virtual void v158();
    virtual void v15C();
    virtual void v160();
    virtual void v164();
    virtual void v168();
    virtual void v16C();
    virtual void v170();
    virtual void v174();
    virtual void v178();
    virtual void v17C();
    virtual void v180();
    virtual void v184();
    virtual void v188();
    virtual void v18C();
    virtual void v190();
    virtual void v194();
    virtual void v198();
    virtual void v19C();
    virtual void v1A0();
    virtual void v1A4();
    virtual void v1A8();
    virtual void v1AC();
    virtual void v1B0();
    virtual void v1B4();
    virtual void v1B8();
    virtual void v1BC();
    virtual void v1C0();
    virtual void v1C4();
    virtual void v1C8();
    virtual void v1CC();
    virtual void v1D0();
    virtual void v1D4();
    virtual void v1D8();
    virtual void v1DC();
    virtual void v1E0();
    virtual void v1E4();
    virtual void v1E8();
    virtual void v1EC();
    virtual void v1F0();
    virtual int* vGet();
    Extra* FUN_005d43c0();
    int* FUN_0056add0();
};

}  // namespace fnv_0056add0

namespace s56ae10 {

struct Entry
{
    void FUN_0041ad00(int iArg0, int iArg1, int iArg2, float fArg3);
};

class Owner
{
  public:
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
    virtual void SetFlag(int iFlag);

    Entry* FUN_005d43c0();
    void FUN_0056ae10(int iArg0, int iArg1, int iArg2, float fArg3);
};

}

#include <xmmintrin.h>
// Placeable water collision creation: box for cell water, copied shape otherwise.
struct WaterBoundsPoint3
{
    float x, y, z;
};
struct WaterPoint3
{
    float x, y, z;
    WaterPoint3();
    WaterPoint3(float, float, float);
};
struct __declspec(align(16)) WaterVector4
{
    __m128 value;
    WaterVector4();
};
struct __declspec(align(16)) WaterQuaternion
{
    __m128 value;
    WaterQuaternion();
    void Identity();
};
void ConvertWaterPoint(WaterVector4&, const WaterPoint3&);
void ConvertWaterRotation(WaterQuaternion&, const WaterVector4&);
struct WaterHavokAllocation
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*);
};
struct WaterShape
{
    unsigned int Type();
};
struct WaterBoxShape : WaterHavokAllocation
{
    WaterBoxShape(const WaterVector4&, float);
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
};
struct WaterTransform : WaterHavokAllocation
{
    WaterTransform();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
};
struct WaterTransformedShape : WaterHavokAllocation
{
    WaterTransformedShape(WaterShape*, WaterTransform*);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
};
struct __declspec(align(16)) WaterRigidBodyInfo
{
    unsigned int filter;
    WaterTransformedShape* shape;
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
    WaterRigidBodyInfo();
    ~WaterRigidBodyInfo();
    void SetMotionType(int);
    void SetPosition(const WaterVector4&);
    void SetRotation(const WaterQuaternion&);
};
struct WaterGameAllocation
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
struct WaterNode;
struct WaterExtraData : WaterGameAllocation
{
    WaterExtraData();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void SetFlag(unsigned int, bool);
};
struct WaterFixedString;
const WaterFixedString& WaterFlagsName();
struct WaterNode
{
    void GetRotation(WaterVector4&);
    WaterExtraData* GetExtra(const WaterFixedString&);
    bool AddExtra(WaterExtraData*);
};
struct WaterRigidBody : WaterGameAllocation
{
    virtual void Slot000();
    virtual void Slot001();
    virtual void Slot002();
    virtual void Slot003();
    virtual void Slot004();
    virtual void Slot005();
    virtual void Slot006();
    virtual void Slot007();
    virtual void Slot008();
    virtual void Slot009();
    virtual void Slot010();
    virtual void Slot011();
    virtual void Slot012();
    virtual void Slot013();
    virtual void Slot014();
    virtual void Slot015();
    virtual void Slot016();
    virtual void Slot017();
    virtual void Slot018();
    virtual void Slot019();
    virtual void Slot020();
    virtual void Slot021();
    virtual void Slot022();
    virtual void Slot023();
    virtual void Slot024();
    virtual void Slot025();
    virtual void Slot026();
    virtual void Slot027();
    virtual void Slot028();
    virtual void Slot029();
    virtual void Slot030();
    virtual void Slot031();
    virtual void Slot032();
    virtual void Slot033();
    virtual void Slot034();
    virtual void Slot035();
    virtual void Slot036();
    virtual void Slot037();
    virtual void Slot038();
    virtual void Slot039();
    virtual void Slot040();
    virtual void Slot041();
    virtual void Slot042();
    virtual void Slot043();
    virtual void Slot044();
    virtual void Slot045();
    virtual void Slot046();
    virtual void Slot047();
    virtual void Slot048();
    virtual void Slot049();
    virtual void Slot050();
    virtual void Slot051();
    virtual void Slot052();
    virtual void Slot053();
    virtual void Slot054();
    virtual void Slot055();
    virtual void Slot056();
    virtual void Activate(int);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    WaterRigidBody(const WaterRigidBodyInfo&);
    void AttachNode(WaterNode*, int);
};
struct WaterCollision : WaterGameAllocation
{
    WaterCollision(WaterNode*);
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    void SetBody(WaterRigidBody*);
};
struct WaterShapePointer
{
    operator WaterShape*() const;
};
struct WaterWorldObject
{
    WaterShapePointer* GetShapePointer();
};
struct WaterCollisionQuery
{
    WaterWorldObject* GetWorldObject();
};
WaterCollisionQuery* FindWaterCollision(WaterNode*);
struct WaterCell
{
    int GridX();
    int GridY();
    float WaterHeight();
};
struct WaterWorld
{
    bool Add(WaterRigidBody*);
};
WaterWorld* __fastcall WaterWorldFor(WaterCell*);
struct WaterBaseObject
{
    bool IsCellWater();
};
void WaterWarning(const char*, ...);
extern float DAT_01013d84;
extern float DAT_01018bfc;
extern float DAT_011b153c;
struct WaterRef
{
    virtual void Slot000();
    virtual void Slot001();
    virtual void Slot002();
    virtual void Slot003();
    virtual void Slot004();
    virtual void Slot005();
    virtual void Slot006();
    virtual void Slot007();
    virtual void Slot008();
    virtual void Slot009();
    virtual void Slot010();
    virtual void Slot011();
    virtual void Slot012();
    virtual void Slot013();
    virtual void Slot014();
    virtual void Slot015();
    virtual void Slot016();
    virtual void Slot017();
    virtual void Slot018();
    virtual void Slot019();
    virtual void Slot020();
    virtual void Slot021();
    virtual void Slot022();
    virtual void Slot023();
    virtual void Slot024();
    virtual void Slot025();
    virtual void Slot026();
    virtual void Slot027();
    virtual void Slot028();
    virtual void Slot029();
    virtual void Slot030();
    virtual void Slot031();
    virtual void Slot032();
    virtual void Slot033();
    virtual void Slot034();
    virtual void Slot035();
    virtual void Slot036();
    virtual void Slot037();
    virtual void Slot038();
    virtual void Slot039();
    virtual void Slot040();
    virtual void Slot041();
    virtual void Slot042();
    virtual void Slot043();
    virtual void Slot044();
    virtual void Slot045();
    virtual void Slot046();
    virtual void Slot047();
    virtual void Slot048();
    virtual void Slot049();
    virtual void Slot050();
    virtual void Slot051();
    virtual void Slot052();
    virtual void Slot053();
    virtual void Slot054();
    virtual void Slot055();
    virtual void Slot056();
    virtual void Slot057();
    virtual void Slot058();
    virtual void Slot059();
    virtual void Slot060();
    virtual void Slot061();
    virtual void Slot062();
    virtual void Slot063();
    virtual void Slot064();
    virtual void Slot065();
    virtual void Slot066();
    virtual void Slot067();
    virtual void Slot068();
    virtual void Slot069();
    virtual void Slot070();
    virtual void Slot071();
    virtual void Slot072();
    virtual void Slot073();
    virtual void Slot074();
    virtual void Slot075();
    virtual void Slot076();
    virtual void Slot077();
    virtual void Slot078();
    virtual void Slot079();
    virtual void Slot080();
    virtual void Slot081();
    virtual void Slot082();
    virtual void Slot083();
    virtual void Slot084();
    virtual void Slot085();
    virtual void Slot086();
    virtual void Slot087();
    virtual void Slot088();
    virtual void Slot089();
    virtual void Slot090();
    virtual void Slot091();
    virtual void Slot092();
    virtual void Slot093();
    virtual void Slot094();
    virtual void Slot095();
    virtual void Slot096();
    virtual void Slot097();
    virtual void Slot098();
    virtual void Slot099();
    virtual void Slot100();
    virtual void Slot101();
    virtual void Slot102();
    virtual void Slot103();
    virtual void Slot104();
    virtual void Slot105();
    virtual void Slot106();
    virtual void Slot107();
    virtual void Slot108();
    virtual void Slot109();
    virtual void Slot110();
    virtual void Slot111();
    virtual void Slot112();
    virtual void Slot113();
    virtual void Slot114();
    virtual void Slot115();
    virtual WaterNode* GetNode();
    virtual void Slot117();
    virtual void GetBoundsMin(WaterBoundsPoint3&);
    virtual void GetBoundsMax(WaterBoundsPoint3&);
    virtual void Slot120();
    virtual void Slot121();
    virtual void Slot122();
    virtual void Slot123();
    virtual void Slot124();
    virtual const WaterPoint3& GetPosition();
    WaterCell* GetContainingCell();
    WaterBaseObject* GetBase();
    unsigned int FormID();
    void FUN_0056c8f0();
};

struct FUN_00a6df40_Obj
{
    void FUN_00a6df40(void* a1);
};
struct FUN_0056d230_Class
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
    void FUN_0056d230(FUN_00a6df40_Obj* a1);
};

namespace fnv_0056e180 {
struct FUN_0056e1e0
{
    int unk00;
    int unk04;
    FUN_0056e1e0();
    ~FUN_0056e1e0();
};

struct FUN_005407b0
{
    int unk00;
    FUN_005407b0(int iMode);
};

struct FUN_0056e180 : FUN_0056e1e0
{
    FUN_005407b0 m_kList;
    FUN_0056e180();
};

// @fnv 0x0056e180
FUN_0056e180::FUN_0056e180() : m_kList(2)
{}
}  // namespace fnv_0056e180

struct FUN_0056e900_cls
{
    void Step();
    FUN_0056e900_cls* StepAndReturnThis();
};

namespace s56eab0 {

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct __declspec(align(16)) FourFloatVector
{
    float m_fComponents[4];

    FourFloatVector();
};

struct __declspec(align(16)) Quaternion
{
    float m_fComponents[4];

    Quaternion();
};

struct IntegerBlock18
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
    int unk44;

    IntegerBlock18();
};

struct PositionW
{
    NiPoint3 m_kPos;
    float m_fVectorX;
};

struct Box
{
    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk018;
    int unk01c;
    int unk20;
};

struct BoundBox
{
    Box m_kBoundsBox;
    NiPoint3 m_kCenter;
    float m_fBoundRadius;

    BoundBox();
};

struct UpdateParams
{
    UpdateParams(float fTime, int iArg0, int iArg1);

    float m_fTime;
    int m_iArg0;
    int m_iArg1;
};

struct HeapObject
{
    static void* operator new(unsigned int uiSize);
    static void operator delete(void* pvMem, unsigned int);
};

struct Shape : HeapObject
{
    int unk00;
};

struct CenteredPointBounds : Shape
{
    CenteredPointBounds(FourFloatVector& m_kPoint2);

    int unk004;
    int unk008;
    int unk00c;
    int unk10;
};

struct SphereShape : Shape
{
    SphereShape(float fRadius, int iArg);

    int unk004;
    int unk008;
    int unk00c;
    int unk10;
};

struct __declspec(align(16)) RigidBodyInfo
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
    int unkd8;
    unsigned char m_aucFlags[4];

    RigidBodyInfo();
    ~RigidBodyInfo();

    void FUN_0056f110(Shape* pkShape);
    void FUN_0056f0f0(unsigned int uiFilterInfo);
    void FUN_0056d360(int iQuality);
};

struct Motion : HeapObject
{
    Motion();

    void FUN_00519230(int iArg0, int iArg1);

    int unk000;
    int unk004;
    int unk008;
    int unk0c;
};

class NiNode;

class RigidBody : public HeapObject
{
  public:
    RigidBody(RigidBodyInfo& kInfo);

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
    virtual void SetPhysicsWorld(void* pvWorld);
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
    virtual void SetTranslation(FourFloatVector& kTranslation);
    virtual void SetRotation(Quaternion& kRotationBasis);

    void FUN_00c85c10(NiNode* pkNode, int iArg);

    int unk004;
    int unk008;
    int unk00c;
    int unk010;
    int unk014;
    int unk18;
};

struct Controller : HeapObject
{
    Controller(NiNode* pkNode);

    void FUN_00c6b980(RigidBody* pkBody);

    int unk000;
    int unk004;
    int unk008;
    int unk00c;
    int unk10;
};

class NiNode
{
  public:
    void FUN_00440490(float fScale);
    void FUN_00a59c60(UpdateParams& kParams);
    void SetExtraDataName(Motion* pkMotion);
    void FUN_0056d230(FourFloatVector& kRotationBasis);
};

struct Package
{
    int FUN_00726070();
    NiPoint3 FUN_00413fc0();
};

struct LayerHolder
{
    unsigned int FUN_00559450();
};

struct Process
{
    Package* FUN_0041fbe0();
    LayerHolder* FUN_004211a0();
};

struct Cell
{
    void* FUN_004543c0();
};

void FUN_004a3e00(FourFloatVector& kOut, const NiPoint3& kIn);
float FUN_004a3e90(float fValue);
void FUN_00561500(Quaternion& kOut, FourFloatVector& kRotationBasis);

class Actor
{
  public:
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
    virtual NiNode* Get3D();
    virtual void v1d4();
    virtual void v1d8();
    virtual void v1dc();
    virtual void v1e0();
    virtual void v1e4();
    virtual void v1e8();
    virtual void v1ec();
    virtual void v1f0();
    virtual NiPoint3* GetPos();

    Process* FUN_005d43c0();
    Cell* FUN_008d6f30();
    void FUN_00567490(float fScale);
    Box FUN_0056fa00();
    void FUN_0056eab0();
};

}

namespace fnv_0056f700 {
class ObjRef
{
  public:
    int GetFormType();
};

class ExtraDataList;
class UpdData;
class Ref;

class ExtraDataList
{
  public:
    void* FUN_0041fbe0();
    void FUN_00422bc0(Ref*);
};

class UpdData
{
  public:
    int pad[3];
    void NiUpdateData(float, bool, bool);
};

class Obj011c3b3c
{
  public:
    bool FUN_00445750(Ref*);
    void FUN_00444850(Ref*, void*);
};

class Obj011dea10
{
  public:
    void* FUN_00458be0(void*);
};

class Obj011e0e80
{
  public:
    void FUN_0096f400(void*);
};

class Obj011ddf38
{
  public:
    bool FUN_0042ce10();
};

extern "C" char DAT_011c3b3c;
extern "C" char DAT_011dea10;
extern "C" char DAT_011e0e80;
extern "C" char DAT_011ddf38;

void __cdecl FUN_005ac190(Ref*, ExtraDataList*);
bool __cdecl FUN_005ac750(Ref*, ExtraDataList*, unsigned int);

class Ref
{
  public:
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
    virtual bool v64();
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
    bool FUN_00444ed0();
    ObjRef* GetObjectReference();
    void* Get3DSimple();
    void Update(void*);
    bool FUN_005651e0();
    bool IsDeleted();
    bool GetDisabled();
    ExtraDataList* GetExtraData();
    void* GetTarget(int, int);
    void FUN_008b6ae0();
    void FUN_008a1a70();
    void FUN_008b65f0();
    void FUN_0056f700();
};

}  // namespace fnv_0056f700

class NiNode;
class NiAVObject;
class TESForm;

class PlayerCharacter
{
  public:
    NiNode* GetNode(bool);
};

class Calendar
{
  public:
    unsigned int GetDaysPassed(void);
};

extern PlayerCharacter* pPlayer;
TESObjectREFR* __fastcall FUN_009ad610(void* this_ptr);

struct NiAVObject_VTable
{
    void* v0;
    void* v1;
    void* v2;
    void* v3;
    void*(__thiscall* GetFadeNode)(void*);
};

namespace fnv_00570f70 {
struct FormX
{
    int FUN_00401170();
};
struct ExtraListX
{
    void FUN_00420f00();
    void FUN_00420e00();
};
struct MgrX
{
    void FUN_006c0c30();
    void FUN_006c0c80();
    void FUN_006c1060();
};
MgrX* __stdcall GetNavMeshObstacleManager(void* p);
bool __cdecl FUN_008c7aa0();
struct AuxX
{
    void FUN_0087b2b0();
};
AuxX* __stdcall FUN_004537b0(void* p);
extern FormX* DAT_011ca238;
extern FormX* DAT_011ca23c;

struct Obj570
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
    virtual bool IsSpecial();
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void DoAlt();
    FormX* FUN_007af430();
    ExtraListX* FUN_005d43c0(int a);
    void FUN_00571080(int flag);
    void FUN_00570f70(int flag);
};

}  // namespace fnv_00570f70

namespace fnv_00572c80 {
class TESDataHandler
{
  public:
    bool FUN_00469860(void* value);
};

extern TESDataHandler* g_dataHandler;

class Refr
{
  public:
    void* FUN_0084e3a0();
    Refr* FUN_007af430();
    int FUN_00401170();
    bool FUN_00444ed0();
};

struct FUN_00572c80_shell
{
    bool FUN_00572c80();
};

}  // namespace fnv_00572c80

namespace s572e10 {

struct Entry
{
    int FUN_0041b4b0();
};

struct Owner
{
    Entry* FUN_005d43c0(int iKey);
    int FUN_00572e10(int iKey);
};

}

struct FormStub;

struct ProcStub
{
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p020();
    virtual void p021();
    virtual void p022();
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p090();
    virtual void p091();
    virtual void p092();
    virtual void p093();
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
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
    virtual void p123();
    virtual void p124();
    virtual void p125();
    virtual void p126();
    virtual void p127();
    virtual void p128();
    virtual void p129();
    virtual void p130();
    virtual void p131();
    virtual void p132();
    virtual void p133();
    virtual void p134();
    virtual void p135();
    virtual void p136();
    virtual void p137();
    virtual void p138();
    virtual void p139();
    virtual void p140();
    virtual void p141();
    virtual void p142();
    virtual void p143();
    virtual void p144();
    virtual void p145();
    virtual void p146();
    virtual void p147();
    virtual void p148();
    virtual void p149();
    virtual void p150();
    virtual void p151();
    virtual void p152();
    virtual void p153();
    virtual void p154();
    virtual void p155();
    virtual void p156();
    virtual void p157();
    virtual void p158();
    virtual void p159();
    virtual void p160();
    virtual void p161();
    virtual void p162();
    virtual void p163();
    virtual void p164();
    virtual void p165();
    virtual void p166();
    virtual void p167();
    virtual void p168();
    virtual void p169();
    virtual void p170();
    virtual void p171();
    virtual void p172();
    virtual void p173();
    virtual void p174();
    virtual void p175();
    virtual void p176();
    virtual void p177();
    virtual void p178();
    virtual void p179();
    virtual void p180();
    virtual void p181();
    virtual void p182();
    virtual void p183();
    virtual void p184();
    virtual void p185();
    virtual void p186();
    virtual void p187();
    virtual void p188();
    virtual void p189();
    virtual void p190();
    virtual void p191();
    virtual void p192();
    virtual void p193();
    virtual void p194();
    virtual void p195();
    virtual void p196();
    virtual void p197();
    virtual void p198();
    virtual void p199();
    virtual void p200();
    virtual void p201();
    virtual void p202();
    virtual void p203();
    virtual void p204();
    virtual void p205();
    virtual void p206();
    virtual void p207();
    virtual void p208();
    virtual void p209();
    virtual void p210();
    virtual void p211();
    virtual void p212();
    virtual void p213();
    virtual void p214();
    virtual void p215();
    virtual void p216();
    virtual void p217();
    virtual void p218();
    virtual void p219();
    virtual void p220();
    virtual void p221();
    virtual void p222();
    virtual void p223();
    virtual void p224();
    virtual void p225();
    virtual void p226();
    virtual void p227();
    virtual void p228();
    virtual void p229();
    virtual void p230();
    virtual void p231();
    virtual void p232();
    virtual void p233();
    virtual void p234();
    virtual void p235();
    virtual void p236();
    virtual void p237();
    virtual void p238();
    virtual void p239();
    virtual void p240();
    virtual void p241();
    virtual void p242();
    virtual void p243();
    virtual void p244();
    virtual void p245();
    virtual void p246();
    virtual void p247();
    virtual void p248();
    virtual void p249();
    virtual void p250();
    virtual void p251();
    virtual void p252();
    virtual void p253();
    virtual void p254();
    virtual void p255();
    virtual void p256();
    virtual void p257();
    virtual void p258();
    virtual void p259();
    virtual void p260();
    virtual void p261();
    virtual void p262();
    virtual void p263();
    virtual void p264();
    virtual void p265();
    virtual void p266();
    virtual void p267();
    virtual void p268();
    virtual void p269();
    virtual void p270();
    virtual void p271();
    virtual void p272();
    virtual void p273();
    virtual void p274();
    virtual void p275();
    virtual void p276();
    virtual void p277();
    virtual void p278();
    virtual void p279();
    virtual void p280();
    virtual void p281();
    virtual void p282();
    virtual void p283();
    virtual void p284();
    virtual void p285();
    virtual void p286();
    virtual void p287();
    virtual void p288();
    virtual void p289();
    virtual void p290();
    virtual void p291();
    virtual void p292();
    virtual void p293();
    virtual void p294();
    virtual void p295();
    virtual void p296();
    virtual void p297();
    virtual void p298();
    virtual void p299();
    virtual void p300();
    virtual void p301();
    virtual void p302();
    virtual void p303();
    virtual void p304();
    virtual void p305();
    virtual void p306();
    virtual void p307();
    virtual void p308();
    virtual void p309();
    virtual void p310();
    virtual void p311();
    virtual void p312();
    virtual void p313();
    virtual void p314();
    virtual void p315();
    virtual void p316();
    virtual void p317();
    virtual void p318();
    virtual void p319();
    virtual void p320();
    virtual void p321();
    virtual void p322();
    virtual void p323();
    virtual void p324();
    virtual void p325();
    virtual void p326();
    virtual void p327();
    virtual void p328();
    virtual void p329();
    virtual void p330();
    virtual void p331();
    virtual void p332();
    virtual void p333();
    virtual void p334();
    virtual void p335();
    virtual void p336();
    virtual void p337();
    virtual void p338();
    virtual void p339();
    virtual void p340();
    virtual void p341();
    virtual void p342();
    virtual void p343();
    virtual void p344();
    virtual void p345();
    virtual void p346();
    virtual void p347();
    virtual void p348();
    virtual void p349();
    virtual void p350();
    virtual void p351();
    virtual void p352();
    virtual void p353();
    virtual void p354();
    virtual void p355();
    virtual void p356();
    virtual void p357();
    virtual void p358();
    virtual void p359();
    virtual void p360();
    virtual void p361();
    virtual void p362();
    virtual void p363();
    virtual void p364();
    virtual void p365();
    virtual void p366();
    virtual void p367();
    virtual void p368();
    virtual void p369();
    virtual void p370();
    virtual void p371();
    virtual void p372();
    virtual void p373();
    virtual void p374();
    virtual void p375();
    virtual void p376();
    virtual void p377();
    virtual void p378();
    virtual void p379();
    virtual void p380();
    virtual void p381();
    virtual void p382();
    virtual void p383();
    virtual void p384();
    virtual void p385();
    virtual void p386();
    virtual void p387();
    virtual void p388();
    virtual void p389();
    virtual void p390();
    virtual void p391();
    virtual void p392();
    virtual void p393();
    virtual void p394();
    virtual void p395();
    virtual void p396();
    virtual void p397();
    virtual void p398();
    virtual void p399();
    virtual void p400();
    virtual void p401();
    virtual void p402();
    virtual void p403();
    virtual void p404();
    virtual void p405();
    virtual void p406();
    virtual void p407();
    virtual void p408();
    virtual void p409();
    virtual void p410();
    virtual void p411();
    virtual void p412();
    virtual void p413();
    virtual void p414();
    virtual void p415();
    virtual void p416();
    virtual void p417();
    virtual void p418();
    virtual void p419();
    virtual void p420();
    virtual void p421();
    virtual void p422();
    virtual void p423();
    virtual void p424();
    virtual void p425();
    virtual void p426();
    virtual void p427();
    virtual void p428();
    virtual void p429();
    virtual void p430();
    virtual void p431();
    virtual void p432();
    virtual void p433();
    virtual void p434();
    virtual void p435();
    virtual void p436();
    virtual void p437();
    virtual void p438();
    virtual void p439();
    virtual void p440();
    virtual void p441();
    virtual void p442();
    virtual void p443();
    virtual void p444();
    virtual void p445();
    virtual void p446();
    virtual void p447();
    virtual void p448();
    virtual void p449();
    virtual void p450();
    virtual void p451();
    virtual void p452();
    virtual void p453();
    virtual void p454();
    virtual void p455();
    virtual void p456();
    virtual void p457();
    virtual void p458();
    virtual void p459();
    virtual void p460();
    virtual void p461();
    virtual void p462();
    virtual void p463();
    virtual void p464();
    virtual void p465();
    virtual void p466();
    virtual void p467();
    virtual void p468();
    virtual void p469();
    virtual void p470();
    virtual void p471();
    virtual void p472();
    virtual void p473();
    virtual void p474();
    virtual void p475();
    virtual void p476();
    virtual void p477();
    virtual void p478();
    virtual void p479();
    virtual void p480();
    virtual void p481();
    virtual void p482();
    virtual void p483();
    virtual void p484();
    virtual void p485();
    virtual void p486();
    virtual void p487();
    virtual void p488();
    virtual void p489();
    virtual void p490();
    virtual void p491();
    virtual void p492();
    virtual void p493();
    virtual void p494();
    virtual void p495();
    virtual void p496();
    virtual void p497();
    virtual void p498();
    virtual void p499();
    virtual void p500();
    virtual void p501();
    virtual void p502();
    virtual void p503();
    virtual void p504();
    virtual void p505();
    virtual void p506();
    virtual void p507();
    virtual void p508();
    virtual void p509();
    virtual void p510();
    virtual void p511();
    virtual void p512();
    virtual void p513();
    virtual void p514();
    virtual void p515();
    virtual void p516();
    virtual void p517();
    virtual void p518();
    virtual void p519();
    virtual void SetTarget(FormStub* a);
    int GetLevel45cd60();
};

struct DH572
{
    unsigned char Check572fa0();
};

struct MyExtraList
{
    FormStub* GetOwner418220();
    void SetOwner418c40(FormStub* a);
    void ClearOwner41adf0();
};

struct ActorStub;

struct RefrStub
{
    virtual void a000();
    virtual void a001();
    virtual void a002();
    virtual void a003();
    virtual void a004();
    virtual void a005();
    virtual void a006();
    virtual void a007();
    virtual void a008();
    virtual void a009();
    virtual void a010();
    virtual void a011();
    virtual void a012();
    virtual void a013();
    virtual void a014();
    virtual void a015();
    virtual void a016();
    virtual void a017();
    virtual void a018();
    virtual void v4c(int flag);
    virtual void b000();
    virtual void b001();
    virtual void b002();
    virtual void b003();
    virtual void b004();
    virtual void b005();
    virtual void b006();
    virtual void b007();
    virtual void b008();
    virtual void b009();
    virtual void b010();
    virtual void b011();
    virtual void b012();
    virtual void b013();
    virtual void b014();
    virtual void b015();
    virtual void b016();
    virtual void b017();
    virtual void b018();
    virtual void b019();
    virtual void b020();
    virtual void b021();
    virtual void b022();
    virtual void b023();
    virtual void b024();
    virtual void b025();
    virtual void b026();
    virtual void b027();
    virtual void b028();
    virtual void b029();
    virtual void b030();
    virtual void b031();
    virtual void b032();
    virtual void b033();
    virtual void b034();
    virtual void b035();
    virtual void b036();
    virtual void b037();
    virtual void b038();
    virtual void b039();
    virtual void b040();
    virtual void b041();
    virtual void b042();
    virtual bool IsActor();
    void Flag484b90(int flag);
    FormStub* FUN_00572e50(FormStub* a);
};

MyExtraList* __fastcall GetExtraList5d43c0(RefrStub* r);

struct LevelStub
{
    int GetLevel45cd60();
};

struct ActorStub : RefrStub
{
    ProcStub* GetProc8d8520();
    void Reset931920(int x);
};

namespace s5730d0 {

struct Package
{
    int FUN_0044edb0();
};

struct Process
{
    Package* FUN_0042e8c0();
};

struct Actor
{
    Process* FUN_005d43c0();
    int FUN_005730d0();
};

}

namespace fnv_00573f40 {
extern "C" char DAT_011ca27c, DAT_011ca280, DAT_011e0e80, DAT_011dea10, DAT_011c3b3c, DAT_011dea3c;
struct R;
struct P
{
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5(R*, bool);
    int FUN_0045cd60();
};
struct N
{
    void* FUN_00559450();
};
struct L
{
    bool FUN_008256d0();
    R** FUN_006815c0();
    L* FUN_00726070();
};
struct E
{
    R* FUN_0041e310();
    bool FUN_0041dc20();
    bool FUN_0041dbd0();
};
bool __fastcall FUN_0041dbd0(E*);
struct F
{
    int FUN_00401170();
};
struct C
{
    void FUN_00545590(R*);
    bool FUN_00450ff0();
};
struct G
{
    bool FUN_004511e0(C*, int);
    void* FUN_00458be0(C*, int);
};
struct H
{
    bool FUN_00445750(R*);
    void FUN_00444850(R*, void*, int);
};
struct M
{
    void FUN_0096d450(R*, int, bool, bool, R*);
    void FUN_0096e870(R*);
};
struct Q
{
    void FUN_00952c30(R*);
};
struct S
{
    void FUN_00b5f080(void*);
};
S* __cdecl FUN_00450b80(unsigned);
struct FUN_00906dc0
{
    int pad[45];
    FUN_00906dc0();
};
struct R
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
    virtual void v50(bool);
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
    virtual bool v63();
    virtual bool v64();
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
    virtual void* v116();
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
    virtual void v130(bool);
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
    virtual void v151(float);
    virtual void v152();
    bool FUN_00440da0();
    void FUN_00484af0(int);
    C* FUN_008d6f30();
    E* FUN_005d43c0();
    F* FUN_007af430();
    P* FUN_008d8520();
    void FUN_00407800(FUN_00906dc0*);
    void FUN_00579ac0(bool);
    bool FUN_00440d80();
    bool FUN_00444ed0();
    N* FUN_005725f0();
    void FUN_008a6ce0(int, int);
    float FUN_0056b190();
    L* FUN_0056ac90();
    bool FUN_0056aa70();
    void FUN_00574400();
    void FUN_0056c780(bool);
    void FUN_00573f40();
};
}  // namespace fnv_00573f40

namespace fnv_005750a0 {
struct S;
struct Item
{
    int FUN_00401170();
};
struct Cell
{
    void FUN_00545590(S*);
};
struct Part
{
    bool FUN_00474a80();
};
struct Weapon
{
    char pad[164];
    Part part;
};
struct Entry
{
    Item* FUN_0044ddc0();
};
struct Process
{
    virtual void p0(), p1(), p2(), p3(), p4(), p5(), p6(), p7(), p8(), p9();
    virtual void p10(), p11(), p12(), p13(), p14(), p15(), p16(), p17(), p18(), p19();
    virtual void p20(), p21(), p22(), p23(), p24(), p25(), p26(), p27(), p28(), p29();
    virtual void p30(), p31(), p32(), p33(), p34(), p35(), p36(), p37(), p38(), p39();
    virtual void p40(), p41(), p42(), p43(), p44(), p45(), p46(), p47(), p48(), p49();
    virtual void p50(), p51(), p52(), p53(), p54(), p55(), p56(), p57(), p58(), p59();
    virtual void p60(), p61(), p62(), p63(), p64(), p65(), p66(), p67(), p68(), p69();
    virtual void p70(), p71(), p72(), p73(), p74(), p75(), p76(), p77(), p78(), p79();
    virtual void p80(), p81(), p82(), p83(), p84(), p85(), p86(), p87(), p88(), p89();
    virtual void p90(), p91(), p92(), p93(), p94();
    virtual void update(Item*, void*);
};
struct Inv
{
    int FUN_004c37d0(S*, Item*, bool, int, void*, bool, int, int, int, bool, bool, int);
};
extern "C" char DAT_011dea3c;
extern bool FUN_005ac750(S*, void*, int);
extern Inv* FUN_004bf220(S*);
extern bool FUN_00705020();
extern bool FUN_00705000();
extern bool FUN_00702360();
struct S
{
    virtual void a0(), a1(), a2(), a3(), a4(), a5(), a6(), a7(), a8(), a9();
    virtual void a10(), a11(), a12(), a13(), a14(), a15(), a16(), a17(), a18(), a19();
    virtual void a20(), a21(), a22(), a23(), a24(), a25(), a26(), a27(), a28(), a29();
    virtual void a30(), a31(), a32(), a33(), a34(), a35(), a36(), a37(), a38(), a39();
    virtual void a40(), a41(), a42(), a43(), a44(), a45(), a46(), a47(), a48(), a49();
    virtual void a50(), a51(), a52(), a53(), a54(), a55(), a56(), a57(), a58(), a59();
    virtual void a60(), a61(), a62(), a63();
    virtual bool isactor();
    virtual void a65(), a66(), a67(), a68(), a69();
    virtual void a70(), a71(), a72(), a73(), a74(), a75(), a76(), a77(), a78(), a79();
    virtual void a80(), a81(), a82(), a83(), a84(), a85(), a86(), a87(), a88(), a89();
    virtual void a90(), a91(), a92(), a93(), a94(), a95(), a96(), a97(), a98(), a99();
    virtual void a100(), a101(), a102(), a103(), a104(), a105(), a106(), a107(), a108(), a109();
    virtual void a110(), a111(), a112(), a113(), a114(), a115(), a116(), a117(), a118(), a119();
    virtual void a120(), a121(), a122(), a123(), a124(), a125(), a126(), a127(), a128(), a129();
    virtual void a130(), a131(), a132(), a133(), a134(), a135(), a136(), a137(), a138();
    virtual bool dead(int);
    virtual void a140(), a141(), a142(), a143(), a144(), a145(), a146(), a147(), a148(), a149();
    virtual void a150(), a151(), a152(), a153(), a154(), a155(), a156(), a157(), a158(), a159();
    virtual void a160(), a161(), a162(), a163(), a164(), a165(), a166(), a167(), a168(), a169();
    virtual void a170(), a171(), a172(), a173(), a174(), a175(), a176(), a177(), a178(), a179();
    virtual void a180(), a181(), a182(), a183(), a184(), a185(), a186(), a187(), a188(), a189();
    virtual void a190(), a191(), a192(), a193(), a194(), a195(), a196(), a197(), a198(), a199();
    virtual void a200(), a201(), a202(), a203(), a204(), a205(), a206(), a207(), a208(), a209();
    virtual void a210(), a211(), a212(), a213(), a214(), a215();
    virtual bool check();
    virtual void a217(), a218(), a219();
    virtual void a220(), a221(), a222(), a223(), a224(), a225(), a226(), a227(), a228(), a229();
    virtual void a230(), a231(), a232(), a233(), a234(), a235(), a236(), a237(), a238();
    virtual Entry* entry(int);
    void* FUN_0055d310();
    Cell* FUN_008d6f30();
    bool FUN_005656d0();
    int FUN_00575610(Weapon*);
    void FUN_009691d0();
    Process* FUN_008d8520();
    bool FUN_00493bb0();
    bool FUN_00566950();
    void FUN_0088c830(Item*, int, void*, bool, bool, bool);
    void FUN_0088c650(Item*, int, void*, bool, bool, bool);
    int FUN_005750a0(Item*, void*, int, bool, bool, int, int, int, bool, bool);
};
}  // namespace fnv_005750a0

struct Obj4bf
{
    int FUN_004bfda0(int a, int b);
};
struct Thing575
{
    void* FUN_0055d310();
    bool FUN_00575400(int a);
};
Obj4bf* FUN_004bf220(Thing575* t);

namespace fnv_00575590 {
struct Global
{
    int FUN_00740960();
};
extern Global* DAT_011c3f2c;

struct Obj
{
    int FUN_004c8fd0(unsigned char value);
};

struct Thing
{
    int FUN_0055d310();
    int FUN_00575590(unsigned char flag, unsigned char value);
};

extern "C" void* FUN_004bf220(void* self);

}  // namespace fnv_00575590

namespace s575ca0 {

struct Package
{
    Package* FUN_0054ddd0();
};

struct Process
{
    Package* FUN_0041d460();
};

struct Owner
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
    Package* m_pkPackage;

    Process* FUN_005d43c0();
    Package* FUN_00575ca0();
};

}

class FUN_00575e30_cls;

class NonActorMagicCaster : public BSExtraData
{
};
class FUN_00575e30_thing
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    FUN_00575e30_thing(FUN_00575e30_cls* owner);
};
class FUN_00575e30_mid
{
  public:
    BSExtraData* FUN_00410220();
    void FUN_0040ff60();
};
class FUN_00575e30_cls
{
  public:
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
    virtual void v48(unsigned int);
    FUN_00575e30_mid* FUN_005d43c0(unsigned int a);
    FUN_00575e30_mid* FUN_005d43c0(void* a);
    void* FUN_00575e30();
};

namespace fnv_00577250 {
class PlayerCharacter
{
  public:
    float FUN_00577310();
};

extern PlayerCharacter* g_thePlayer;

class ItemData
{
  public:
    float FUN_004d0900(bool arg);
};

class Container
{
  public:
    float FUN_00481e10(bool arg);
};

class ExtraList
{
  public:
    ItemData* FUN_00418520();
};

struct FUN_00577250_shell
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
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAc();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBc();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCc();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDc();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void vEc();
    virtual void vF0();
    virtual void vF4();
    virtual void vF8();
    virtual void vFc();
    virtual bool FUN_00vfn100();

    Container* FUN_0055d310();
    ExtraList* FUN_005d43c0();
    float FUN_008a0c20();

    float FUN_00577250(bool arg);
};

}  // namespace fnv_00577250

namespace s577de0 {

struct Info
{
    bool FUN_004d0360();
};

struct Owner;
Info* FUN_004bf220(Owner* pkOwner);

struct Owner
{
    void* FUN_0055d310();
    bool FUN_00577de0();
};

}

namespace fnv_00577e20 {
#include <string.h>

class NiFixedString
{
  public:
    bool IsNotEmpty() const;
    operator const char*() const;
};
struct TraversalNode
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual TraversalNode* AsNode();
    virtual XNode* AsGeometry();
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
    virtual void Attach(TraversalNode*, bool);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void Remove(unsigned int);
    unsigned int FUN_0043b480();
    TraversalNode* FUN_0043b4a0(unsigned int);
    NiFixedString& GetName();
    unsigned int FUN_009ee040();
    void FUN_004902f0(bool);
    void FUN_00576660(int);
};
struct AddonModel
{
    unsigned int FUN_0048cee0();
};
struct TraversalAddon
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
    virtual TraversalNode* CalculateNode(int);
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
    AddonModel model;
    bool FUN_00448bf0();
};
struct TraversalHandler
{
    TraversalAddon* FUN_004617e0(unsigned int);
};
bool FUN_0043b300(const void*, TraversalNode*);
extern const char DAT_01030f08[];
extern "C" int FUN_00ec8a19(const char*, const char*, unsigned int);
unsigned int DialogueRandom();
void FUN_005784f0(TraversalNode*, float);
}  // namespace fnv_00577e20

namespace fnv_00578a30 {
class TESSaveLoadGame
{
  public:
    bool FUN_0047c850();
};
extern TESSaveLoadGame* DAT_011de45c;
struct Sub
{
    int FUN_004228f0();
    void FUN_00422850(int arg);
};
struct Thing
{
    Sub* FUN_005d43c0();
    void FUN_00578a30(int arg);
};
}  // namespace fnv_00578a30

namespace fnv_00579280 {
class BoundForm
{
  public:
    unsigned int FUN_00401170();
    bool FUN_005093f0();
    bool FUN_00509420();
    bool FUN_0046f070();
};
class ActorData
{
  public:
    virtual void Unknown00();
    virtual void Unknown01();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual bool IsEssential();
};
class ActorBaseData
{
  public:
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
    ActorData actorData;
};
class ReferenceView
{
  public:
    virtual void UnknownVirtual000();
    virtual void UnknownVirtual001();
    virtual void UnknownVirtual002();
    virtual void UnknownVirtual003();
    virtual void UnknownVirtual004();
    virtual void UnknownVirtual005();
    virtual void UnknownVirtual006();
    virtual void UnknownVirtual007();
    virtual void UnknownVirtual008();
    virtual void UnknownVirtual009();
    virtual void UnknownVirtual010();
    virtual void UnknownVirtual011();
    virtual void UnknownVirtual012();
    virtual void UnknownVirtual013();
    virtual void UnknownVirtual014();
    virtual void UnknownVirtual015();
    virtual void UnknownVirtual016();
    virtual void UnknownVirtual017();
    virtual void UnknownVirtual018();
    virtual void UnknownVirtual019();
    virtual void UnknownVirtual020();
    virtual void UnknownVirtual021();
    virtual void UnknownVirtual022();
    virtual void UnknownVirtual023();
    virtual void UnknownVirtual024();
    virtual void UnknownVirtual025();
    virtual void UnknownVirtual026();
    virtual void UnknownVirtual027();
    virtual void UnknownVirtual028();
    virtual void UnknownVirtual029();
    virtual void UnknownVirtual030();
    virtual void UnknownVirtual031();
    virtual void UnknownVirtual032();
    virtual void UnknownVirtual033();
    virtual void UnknownVirtual034();
    virtual void UnknownVirtual035();
    virtual void UnknownVirtual036();
    virtual void UnknownVirtual037();
    virtual void UnknownVirtual038();
    virtual void UnknownVirtual039();
    virtual void UnknownVirtual040();
    virtual void UnknownVirtual041();
    virtual void UnknownVirtual042();
    virtual void UnknownVirtual043();
    virtual void UnknownVirtual044();
    virtual void UnknownVirtual045();
    virtual void UnknownVirtual046();
    virtual void UnknownVirtual047();
    virtual void UnknownVirtual048();
    virtual void UnknownVirtual049();
    virtual void UnknownVirtual050();
    virtual void UnknownVirtual051();
    virtual void UnknownVirtual052();
    virtual void UnknownVirtual053();
    virtual void UnknownVirtual054();
    virtual void UnknownVirtual055();
    virtual void UnknownVirtual056();
    virtual void UnknownVirtual057();
    virtual void UnknownVirtual058();
    virtual void UnknownVirtual059();
    virtual void UnknownVirtual060();
    virtual void UnknownVirtual061();
    virtual void UnknownVirtual062();
    virtual void UnknownVirtual063();
    virtual bool IsActor();
    virtual void UnknownVirtual065();
    virtual void UnknownVirtual066();
    virtual void UnknownVirtual067();
    virtual void UnknownVirtual068();
    virtual void UnknownVirtual069();
    virtual void UnknownVirtual070();
    virtual void UnknownVirtual071();
    virtual void UnknownVirtual072();
    virtual void UnknownVirtual073();
    virtual void UnknownVirtual074();
    virtual void UnknownVirtual075();
    virtual void UnknownVirtual076();
    virtual void UnknownVirtual077();
    virtual void UnknownVirtual078();
    virtual void UnknownVirtual079();
    virtual void UnknownVirtual080();
    virtual void UnknownVirtual081();
    virtual void UnknownVirtual082();
    virtual void UnknownVirtual083();
    virtual void UnknownVirtual084();
    virtual void UnknownVirtual085();
    virtual void UnknownVirtual086();
    virtual void UnknownVirtual087();
    virtual void UnknownVirtual088();
    virtual void UnknownVirtual089();
    virtual void UnknownVirtual090();
    virtual void UnknownVirtual091();
    virtual void UnknownVirtual092();
    virtual void UnknownVirtual093();
    virtual void UnknownVirtual094();
    virtual void UnknownVirtual095();
    virtual void UnknownVirtual096();
    virtual void UnknownVirtual097();
    virtual void UnknownVirtual098();
    virtual void UnknownVirtual099();
    virtual void UnknownVirtual100();
    virtual void UnknownVirtual101();
    virtual void UnknownVirtual102();
    virtual void UnknownVirtual103();
    virtual void UnknownVirtual104();
    virtual void UnknownVirtual105();
    virtual void UnknownVirtual106();
    virtual void UnknownVirtual107();
    virtual void UnknownVirtual108();
    virtual void UnknownVirtual109();
    virtual void UnknownVirtual110();
    virtual void UnknownVirtual111();
    virtual void UnknownVirtual112();
    virtual void UnknownVirtual113();
    virtual void UnknownVirtual114();
    virtual void UnknownVirtual115();
    virtual void UnknownVirtual116();
    virtual void UnknownVirtual117();
    virtual void UnknownVirtual118();
    virtual void UnknownVirtual119();
    virtual void UnknownVirtual120();
    virtual void UnknownVirtual121();
    virtual void UnknownVirtual122();
    virtual void UnknownVirtual123();
    virtual void UnknownVirtual124();
    virtual void UnknownVirtual125();
    virtual void UnknownVirtual126();
    virtual void UnknownVirtual127();
    virtual void UnknownVirtual128();
    virtual void UnknownVirtual129();
    virtual void UnknownVirtual130();
    virtual void UnknownVirtual131();
    virtual void UnknownVirtual132();
    virtual void UnknownVirtual133();
    virtual void UnknownVirtual134();
    virtual void UnknownVirtual135();
    virtual void UnknownVirtual136();
    virtual void UnknownVirtual137();
    virtual void UnknownVirtual138();
    virtual bool IsDead(int flags);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    BoundForm* baseForm;
    bool FUN_00477ba0();
    BoundForm* FUN_007af430();
    const char* FUN_0055d520();
    int FUN_004f8960();
    bool FUN_00579670();
    bool FUN_0047c850();
    bool FUN_0087f3d0();
    bool FUN_004997b0();
    bool FUN_00566950();
    ActorBaseData* FUN_004181e0();
    int FUN_00579280();
};
extern ReferenceView* g_thePlayer;
unsigned int FUN_0044a670(const char* text);
int FUN_00579620(BoundForm* form);

}  // namespace fnv_00579280

struct FUN_0057a2f0_shell : public TESObjectREFR
{
    bool FUN_0057a2f0();
};

void* __fastcall _FNV_GetObjectReference(void*);

struct FUN_0057a370_shell : public TESObjectREFR
{
    bool FUN_0057a370();
};

class Actor
{
  public:
    bool FUN_00437b90(void);
};

void* __fastcall _FNV_GetObjectReference(void*);
bool __fastcall FUN_00477ba0(void*);

namespace fnv_0057ada0 {
struct Vec3
{
    float x;
    float y;
    float z;
    bool FUN_004390c0(const char* s);
};
struct Vec2
{
    float x;
    float y;
    Vec2* FUN_00452dc0(float a, float b);
};
struct TObject;
struct RetObj
{
    void FUN_00a59c60(TObject* p);
};
RetObj* FUN_00450b80(int a);
struct TObject
{
    float a;
    float b;
    float c;
    void FUN_0043d410(float f, int i1, int i2);
};
struct BObj
{
    void FUN_00416a30(Vec2* v);
    void FUN_004169f0(void* p);
    void FUN_00416a70(void* p);
};
struct DObj;
struct CObj
{
    DObj* FUN_006629f0();
};
struct EObj
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
    virtual int GetMode35();
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
    virtual void SetVec46(Vec3* v);
    void FUN_00439680(Vec3* v);
    void FUN_004396b0(void* p);
};
struct DObj
{
    EObj* FUN_0043b230();
    void FUN_004addc0(void* p);
};
struct MidObj
{
    Vec3* FUN_0045bb80();
    void* FUN_006a9540();
};
struct AObj
{
    virtual void av0();
    virtual void av1();
    virtual void av2();
    virtual void av3();
    virtual void av4();
    virtual void* GetVec5(Vec3* v);
    Vec3* FUN_00413fc0(Vec3* out);
    MidObj* FUN_0056c7f0();
};
struct XObj
{
    AObj* FUN_0041fbe0();
    BObj* FUN_00422120();
    BObj* FUN_00420dd0();
    CObj* FUN_00420ed0();
    DObj* FUN_00422020();
};
struct This57
{
    XObj* FUN_005d43c0();
    int FUN_007af430();
    Vec3* FUN_00430830();
    void FUN_0057ada0();
};
extern int DAT_011ca234;
extern int DAT_011ca23c;
extern int DAT_011ca238;
extern int DAT_011ca230;
extern const char DAT_011f426c[];

}  // namespace fnv_0057ada0

namespace fnv_0057b410 {
struct Other
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
    virtual bool vf();
};

struct Thing
{
    Other* FUN_007af430();
    bool FUN_0057b410();
};

}  // namespace fnv_0057b410

struct FUN_0057b460_shell : public TESObjectREFR
{
    bool FUN_0057b460();
};

void* __fastcall _FNV_GetObjectReference(void*);

struct FUN_0057b4b0_shell : public TESObjectREFR
{
    bool FUN_0057b4b0();
};

void* __fastcall _FNV_GetObjectReference(void*);
unsigned int __fastcall FUN_0044ddc0(void*);

namespace fnv_0057b7c0 {
// 0x0057b7c0  Actor dialogue helper  /MT /Od /Oy- /GS /EHsc /Gy
extern "C" int sprintf(char*, const char*, ...);
extern "C" void* DAT_011dea3c;

struct Set57
{
    int* Int();
    void FUN_0045ce80(int);
};
extern Set57 DAT_011cd378;

struct PL57
{
    void FUN_0096e570();
};
extern PL57 DAT_011e0e80;

struct P12
{
    int x, y, z;
};

struct S12
{
    int a;
    unsigned char b;
    int c;
    S12(int);
    S12(const S12&);
    ~S12();
};

struct L150
{
    int a;
    unsigned char b;
    int c;
    ~L150();
    void FUN_00ad8e60(void*, unsigned int);
};

struct Proc57;
struct DialogItem57;
struct Resp57;
struct Txt57;
struct Topic57;

struct Actor57
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
    virtual void d009();
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
    virtual void vd0(int);
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
    virtual bool vfc();
    virtual bool v100();
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
    virtual L150 v13c(void*, void*, int, int, int, int, int);
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
    virtual int v1d0();
    virtual void d117();
    virtual void d118();
    virtual void d119();
    virtual void d120();
    virtual void d121();
    virtual void d122();
    virtual void d123();
    virtual void d124();
    virtual P12* v1f4();
    virtual void d126();
    virtual void d127();
    virtual void d128();
    virtual void d129();
    virtual void d130();
    virtual void d131();
    virtual void d132();
    virtual void* v214();
    virtual void d134();
    virtual void d135();
    virtual void d136();
    virtual void d137();
    virtual void d138();
    virtual bool v22c(int);
    char pad00[0x7f - 4];
    unsigned char b7f;
    Proc57* GetProcess();
    const char* GetFullName();
    void FUN_0057bd60(void*);
    void* FUN_0057bd40();
    void FUN_00881680(unsigned char);
    void FUN_0057ad20(void*);
    void FUN_0057ace0(void*);
    unsigned int FUN_0084e3a0();
    void* GetExtraData();
    void StartDialog(Topic57*, unsigned char, int);
};

struct Proc57
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
    virtual void d009();
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
    virtual void d064();
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
    virtual void v1dc(void*, int);
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
    virtual void d133();
    virtual void d134();
    virtual void d135();
    virtual void d136();
    virtual void d137();
    virtual void d138();
    virtual void d139();
    virtual void d140();
    virtual void d141();
    virtual void d142();
    virtual void d143();
    virtual void d144();
    virtual void d145();
    virtual void* v248();
    virtual void v24c(int);
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
    virtual void d159();
    virtual void d160();
    virtual void d161();
    virtual void d162();
    virtual void d163();
    virtual void d164();
    virtual void d165();
    virtual void d166();
    virtual void d167();
    virtual void d168();
    virtual void v2a4(void*, void*, unsigned char, int, int, int);
    virtual void d170();
    virtual void d171();
    virtual void d172();
    virtual void d173();
    virtual void d174();
    virtual void d175();
    virtual void d176();
    virtual void d177();
    virtual void d178();
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
    virtual bool v30c();
};

struct Chal57
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
    virtual void d009();
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
    virtual void d064();
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
    virtual int v1d0();
    Chal57* FUN_005e3fa0();
};

struct DialogItem57
{
    void FUN_0083c7b0();
    Resp57* GetCurrentItem();
    void FUN_0083c850(int);
    void* FUN_0084e3a0();
};

struct Resp57
{
    Txt57* FUN_006815c0();
};
struct Txt57
{
    const char* FUN_00559450();
};
struct Topic57
{
    DialogItem57* FUN_0061b320(void*, void*, void*, void*, bool);
};

void FUN_005790f0();
bool FUN_00703150();
bool FUN_005ac750(void*, void*, unsigned int);
void FUN_00705210(const char*, S12, P12, void*, bool);

}  // namespace fnv_0057b7c0

namespace DialogueUpdate {

struct DlgPoint
{
    float x, y, z;
};

struct DlgTarget
{
    int iData[3];
    DlgTarget(const DlgTarget& arOther);
    ~DlgTarget();
};

struct DlgNode
{
    DlgNode* FUN_0083c820();
    DlgNode* FUN_006815c0();
    const char* FUN_00559450();
    void FUN_0083c850(int aiValue);
};

struct DlgFlag
{
    char pad00[0x80];
    unsigned char bPickResultFound;
};

struct DlgPackage
{
    int FUN_0041ca90();
    DlgNode* FUN_008cdd90();
    void* FUN_009ee040();
    void* FUN_008d80e0();
    DlgNode* FUN_005e3fc0();
    char pad00[0x90];
    float m_fPackageValue;
    DlgFlag* pFlag;
};

struct DlgTopic
{
    virtual void t000();
    virtual void t001();
    virtual void t002();
    virtual void t003();
    virtual void t004();
    virtual void t005();
    virtual void t006();
    virtual void t007();
    virtual void t008();
    virtual void t009();
    virtual void t00a();
    virtual void t00b();
    virtual void t00c();
    virtual void t00d();
    virtual void t00e();
    virtual void t00f();
    virtual void t010();
    virtual void t011();
    virtual void t012();
    virtual void t013();
    virtual void t014();
    virtual void t015();
    virtual void t016();
    virtual void t017();
    virtual void t018();
    virtual void t019();
    virtual void t01a();
    virtual void t01b();
    virtual void t01c();
    virtual void t01d();
    virtual void t01e();
    virtual void t01f();
    virtual void t020();
    virtual void t021();
    virtual void t022();
    virtual void t023();
    virtual void t024();
    virtual void t025();
    virtual void t026();
    virtual void t027();
    virtual void t028();
    virtual void t029();
    virtual void t02a();
    virtual void t02b();
    virtual void t02c();
    virtual void FUN_vtb4(float afTime, int a2, int a3, int a4, int a5, int a6);
    virtual void t02e();
    virtual void t02f();
    virtual void t030();
    virtual void t031();
    virtual void t032();
    virtual void t033();
    virtual void t034();
    virtual void t035();
    virtual void t036();
    virtual void t037();
    virtual void t038();
    virtual void t039();
    virtual void t03a();
    virtual void t03b();
    virtual void t03c();
    virtual void t03d();
    virtual void t03e();
    virtual void t03f();
    virtual void t040();
    virtual void t041();
    virtual void t042();
    virtual void t043();
    virtual void t044();
    virtual void FUN_vt114(int aiSound, float afVolume);
    virtual void t046();
    virtual void FUN_vt11c(int aiValue, int aiFlag);
};

struct DlgProcess
{
    virtual void p000();
    virtual void p001();
    virtual void p002();
    virtual void p003();
    virtual void p004();
    virtual void p005();
    virtual void p006();
    virtual void p007();
    virtual void p008();
    virtual void p009();
    virtual void p00a();
    virtual void p00b();
    virtual void p00c();
    virtual void p00d();
    virtual void p00e();
    virtual void p00f();
    virtual void p010();
    virtual void p011();
    virtual void p012();
    virtual void p013();
    virtual void p014();
    virtual void p015();
    virtual void p016();
    virtual void p017();
    virtual void p018();
    virtual void p019();
    virtual void p01a();
    virtual void p01b();
    virtual void p01c();
    virtual void p01d();
    virtual void p01e();
    virtual void p01f();
    virtual void p020();
    virtual void p021();
    virtual void FUN_vt88(int aiValue);
    virtual void p023();
    virtual void p024();
    virtual void p025();
    virtual void p026();
    virtual void p027();
    virtual void p028();
    virtual void p029();
    virtual void p02a();
    virtual void p02b();
    virtual void p02c();
    virtual void p02d();
    virtual void p02e();
    virtual void p02f();
    virtual void p030();
    virtual void p031();
    virtual void p032();
    virtual void p033();
    virtual void p034();
    virtual void p035();
    virtual void p036();
    virtual void p037();
    virtual void p038();
    virtual void p039();
    virtual void p03a();
    virtual void p03b();
    virtual void p03c();
    virtual void p03d();
    virtual void p03e();
    virtual void p03f();
    virtual void p040();
    virtual void p041();
    virtual void p042();
    virtual void p043();
    virtual void p044();
    virtual void p045();
    virtual void p046();
    virtual void p047();
    virtual void p048();
    virtual void p049();
    virtual void p04a();
    virtual void p04b();
    virtual void p04c();
    virtual void p04d();
    virtual void p04e();
    virtual void p04f();
    virtual void p050();
    virtual void p051();
    virtual void p052();
    virtual void p053();
    virtual void p054();
    virtual void p055();
    virtual void p056();
    virtual void p057();
    virtual void p058();
    virtual void p059();
    virtual void p05a();
    virtual void p05b();
    virtual void p05c();
    virtual void p05d();
    virtual void p05e();
    virtual void p05f();
    virtual void p060();
    virtual void p061();
    virtual void p062();
    virtual void p063();
    virtual void p064();
    virtual void p065();
    virtual void p066();
    virtual void p067();
    virtual void p068();
    virtual void p069();
    virtual void p06a();
    virtual void p06b();
    virtual void p06c();
    virtual void p06d();
    virtual void p06e();
    virtual void p06f();
    virtual void p070();
    virtual void p071();
    virtual void p072();
    virtual void p073();
    virtual void p074();
    virtual void p075();
    virtual void p076();
    virtual void p077();
    virtual void p078();
    virtual void p079();
    virtual void p07a();
    virtual void p07b();
    virtual void p07c();
    virtual void p07d();
    virtual void p07e();
    virtual void p07f();
    virtual void p080();
    virtual void p081();
    virtual void p082();
    virtual void p083();
    virtual void p084();
    virtual void p085();
    virtual void p086();
    virtual void p087();
    virtual void p088();
    virtual void p089();
    virtual void p08a();
    virtual DlgPackage* GetCurrentPackage();
    virtual void p08c();
    virtual void p08d();
    virtual void p08e();
    virtual void p08f();
    virtual void p090();
    virtual void p091();
    virtual DlgNode* FUN_vt248();
    virtual void FUN_vt24c(int aiValue);
    virtual void p094();
    virtual void p095();
    virtual void p096();
    virtual void p097();
    virtual void p098();
    virtual void p099();
    virtual void p09a();
    virtual void p09b();
    virtual void p09c();
    virtual void p09d();
    virtual void p09e();
    virtual void p09f();
    virtual void p0a0();
    virtual void p0a1();
    virtual void p0a2();
    virtual void p0a3();
    virtual void p0a4();
    virtual void p0a5();
    virtual void p0a6();
    virtual void p0a7();
    virtual void p0a8();
    virtual void p0a9();
    virtual void p0aa();
    virtual void p0ab();
    virtual void p0ac();
    virtual void p0ad();
    virtual void p0ae();
    virtual void p0af();
    virtual void p0b0();
    virtual void p0b1();
    virtual void p0b2();
    virtual void p0b3();
    virtual void p0b4();
    virtual void p0b5();
    virtual void p0b6();
    virtual void p0b7();
    virtual void p0b8();
    virtual void p0b9();
    virtual void p0ba();
    virtual void p0bb();
    virtual void p0bc();
    virtual void p0bd();
    virtual void p0be();
    virtual void p0bf();
    virtual void p0c0();
    virtual void p0c1();
    virtual void p0c2();
    virtual bool FUN_vt30c();
    virtual void p0c4();
    virtual void p0c5();
    virtual void p0c6();
    virtual void p0c7();
    virtual void p0c8();
    virtual void p0c9();
    virtual void p0ca();
    virtual void p0cb();
    virtual void p0cc();
    virtual void p0cd();
    virtual void p0ce();
    virtual void p0cf();
    virtual void p0d0();
    virtual void p0d1();
    virtual void p0d2();
    virtual void p0d3();
    virtual void p0d4();
    virtual void p0d5();
    virtual void p0d6();
    virtual void p0d7();
    virtual void p0d8();
    virtual void p0d9();
    virtual void p0da();
    virtual void p0db();
    virtual void p0dc();
    virtual void p0dd();
    virtual void p0de();
    virtual void p0df();
    virtual void p0e0();
    virtual void p0e1();
    virtual void p0e2();
    virtual void p0e3();
    virtual void p0e4();
    virtual void p0e5();
    virtual void p0e6();
    virtual void p0e7();
    virtual void p0e8();
    virtual void p0e9();
    virtual void p0ea();
    virtual void p0eb();
    virtual void p0ec();
    virtual void p0ed();
    virtual void p0ee();
    virtual void p0ef();
    virtual void p0f0();
    virtual void p0f1();
    virtual void p0f2();
    virtual void p0f3();
    virtual void p0f4();
    virtual void p0f5();
    virtual void p0f6();
    virtual void p0f7();
    virtual void p0f8();
    virtual void p0f9();
    virtual void p0fa();
    virtual void p0fb();
    virtual void p0fc();
    virtual void p0fd();
    virtual void p0fe();
    virtual void p0ff();
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
    virtual void p10a();
    virtual void p10b();
    virtual void p10c();
    virtual void p10d();
    virtual void p10e();
    virtual void p10f();
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
    virtual void p11a();
    virtual void p11b();
    virtual void p11c();
    virtual void p11d();
    virtual void p11e();
    virtual void p11f();
    virtual void p120();
    virtual void p121();
    virtual void p122();
    virtual DlgTarget FUN_vt48c(int aiFlags);
};

struct DlgCheck;

struct DlgQuery
{
    int iData;
    DlgQuery();
    ~DlgQuery();
    DlgCheck* FUN_009369a0();
};

struct DlgConversation
{
    void FUN_0061e760(DlgQuery* apQuery);
    bool FUN_00579200();
    void FUN_0061f170(int aiValue, struct DlgActor* apActor);
};

struct DlgExtraList
{
    void FUN_0042edb0();
};

struct DlgActorValues
{
    virtual void v00();
    virtual void v01();
    virtual int GetActorValue(int aiIndex);
};

struct DlgActor
{
    virtual void a000();
    virtual void a001();
    virtual void a002();
    virtual void a003();
    virtual void a004();
    virtual void a005();
    virtual void a006();
    virtual void a007();
    virtual void a008();
    virtual void a009();
    virtual void a00a();
    virtual void a00b();
    virtual void a00c();
    virtual void a00d();
    virtual void a00e();
    virtual void a00f();
    virtual void a010();
    virtual void a011();
    virtual void a012();
    virtual void a013();
    virtual void a014();
    virtual void a015();
    virtual void a016();
    virtual void a017();
    virtual void a018();
    virtual void a019();
    virtual void a01a();
    virtual void a01b();
    virtual void a01c();
    virtual void a01d();
    virtual void a01e();
    virtual void a01f();
    virtual void a020();
    virtual void a021();
    virtual void a022();
    virtual void a023();
    virtual void a024();
    virtual void a025();
    virtual void a026();
    virtual void a027();
    virtual void a028();
    virtual void a029();
    virtual void a02a();
    virtual void a02b();
    virtual void a02c();
    virtual void a02d();
    virtual void a02e();
    virtual void a02f();
    virtual void a030();
    virtual void a031();
    virtual void a032();
    virtual void a033();
    virtual void a034();
    virtual void a035();
    virtual void a036();
    virtual void a037();
    virtual void a038();
    virtual void a039();
    virtual void a03a();
    virtual void a03b();
    virtual void a03c();
    virtual void a03d();
    virtual void a03e();
    virtual void a03f();
    virtual bool IsActor();
    virtual void a041();
    virtual void a042();
    virtual void a043();
    virtual void a044();
    virtual void a045();
    virtual void a046();
    virtual void a047();
    virtual void a048();
    virtual void a049();
    virtual void a04a();
    virtual void a04b();
    virtual void a04c();
    virtual void a04d();
    virtual void a04e();
    virtual void a04f();
    virtual void a050();
    virtual void a051();
    virtual void a052();
    virtual void a053();
    virtual void a054();
    virtual void a055();
    virtual void a056();
    virtual void a057();
    virtual void a058();
    virtual void a059();
    virtual void a05a();
    virtual void a05b();
    virtual void a05c();
    virtual void a05d();
    virtual void a05e();
    virtual void a05f();
    virtual void a060();
    virtual void a061();
    virtual void a062();
    virtual void a063();
    virtual void a064();
    virtual void a065();
    virtual void a066();
    virtual void a067();
    virtual void a068();
    virtual void a069();
    virtual void a06a();
    virtual void a06b();
    virtual void a06c();
    virtual void a06d();
    virtual DlgTopic* FUN_vt1b8(int aiFlags);
    virtual void a06f();
    virtual void a070();
    virtual void a071();
    virtual void a072();
    virtual void a073();
    virtual void a074();
    virtual void a075();
    virtual void a076();
    virtual void a077();
    virtual void a078();
    virtual void a079();
    virtual void a07a();
    virtual void a07b();
    virtual void a07c();
    virtual DlgPoint* GetPos();
    virtual void a07e();
    virtual void a07f();
    virtual void a080();
    virtual void a081();
    virtual void a082();
    virtual void a083();
    virtual void a084();
    virtual void a085();
    virtual void a086();
    virtual void a087();
    virtual void a088();
    virtual void a089();
    virtual void a08a();
    virtual void a08b();
    virtual void a08c();
    virtual void a08d();
    virtual void a08e();
    virtual void a08f();
    virtual void a090();
    virtual void a091();
    virtual void a092();
    virtual void a093();
    virtual void a094();
    virtual void a095();
    virtual void a096();
    virtual void a097();
    virtual void a098();
    virtual void a099();
    virtual void a09a();
    virtual void a09b();
    virtual void a09c();
    virtual void a09d();
    virtual void a09e();
    virtual void a09f();
    virtual void a0a0();
    virtual void a0a1();
    virtual void a0a2();
    virtual void a0a3();
    virtual void a0a4();
    virtual void a0a5();
    virtual void a0a6();
    virtual void a0a7();
    virtual void a0a8();
    virtual void a0a9();
    virtual void a0aa();
    virtual void a0ab();
    virtual void a0ac();
    virtual void a0ad();
    virtual void a0ae();
    virtual void a0af();
    virtual void a0b0();
    virtual void a0b1();
    virtual void a0b2();
    virtual void a0b3();
    virtual int FUN_vt2d0();
    virtual void a0b5();
    virtual int FUN_vt2d8();
    char pad04[0x74];
    float m_fFirstReferenceTimer;
    char pad7c[3];
    unsigned char bSpoken;
    unsigned char bWasPlaying;
    char pad81[3];
    char pProcessData;
    unsigned char bSaid;
    char pad86[0x1e];
    DlgActorValues kValues;
    char padA8[0x160];
    DlgPackage* pDialoguePackage;

    DlgConversation* FUN_00934430();
    void* FUN_0057bd40();
    DlgCheck* FUN_008dd860();
    void FUN_0057ad20(int aiValue);
    DlgExtraList* FUN_005d43c0();
    DlgProcess* FUN_008d8520();
    DlgPackage* FUN_009344a0();
    float FUN_005723b0(DlgActor* apTarget, int a2, int a3);
    bool FUN_008c1bc0();
    const char* FUN_0055d520();
    void FUN_00953ce0();
    bool FUN_004eaf60();
    void FUN_00967730(void* apTopic, void* apInfo, DlgPackage* apPackage);
    void FUN_00935f60();
};

struct DlgIntSetting
{
    int* FUN_0043d4d0();
};
struct DlgBoolSetting
{
    unsigned char* FUN_00408d60();
};
extern DlgActor* DAT_011dea3c;
extern DlgIntSetting DAT_011cd378;
extern DlgBoolSetting DAT_011d8928;
extern unsigned char DAT_011f122d;

void __cdecl FUN_005ac750(void* apOwner, DlgExtraList* apExtra, int aiFlags);
int __cdecl FUN_00653cf0(int aiType);
bool FUN_005b7470();
bool FUN_00703150();
int __cdecl FUN_00ec623a(char* apBuffer, const char* apFormat, ...);
void __cdecl FUN_00705210(const char* apText, DlgTarget kTarget, DlgPoint kPos, DlgActor* apListener, int aiFlags);

static const char s_szSubtitleFormat[] = "'%s' :%s";

}

struct TESObjectREFRHelper
{
    void SetTargetingState(bool);
};
TESForm* __cdecl FUN_004839c0(void*);
struct Fn9a4f40
{
    void* ref;
    void FUN_009a4f40(int);
};

namespace fnv_005710c0 {
struct ModelRef;
struct ModelForm;
struct ModelNode;
struct ModelLink;
struct FUN_004ad050;
struct FUN_00438170
{
    const char* text;
    FUN_00438170(const char*);
    ~FUN_00438170();
};
struct ModelNode
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
    virtual ModelNode* Find(const FUN_00438170&);
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
    virtual void Attach(ModelNode*, bool);
    ModelNode* FUN_009611e0();
    ModelNode* FUN_00a5d2c0(FUN_004ad050*);
};
struct ModelNames
{
    ModelLink* FUN_00717e50();
};
struct ModelLink
{
    bool FUN_008256d0();
    const char** FUN_006815c0();
    ModelLink* FUN_00726070();
};
struct ModelForm
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
    virtual bool Fallback();
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
    ModelNames names;
    unsigned int FUN_00401170();
    void FUN_00605d70(ModelRef*);
    void FUN_005fa0a0(ModelRef*);
};
struct ModelEquipment
{
    bool FUN_00441b00();
};
struct ModelState
{
    void FUN_00496280();
};
struct ModelRef
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
    virtual ModelState* GetState();
    virtual void* GetAnimation();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    ModelForm* base;
    ModelNode* FUN_0043fcd0();
    ModelEquipment* FUN_009344a0();
    const char* FUN_005715d0();
    float FUN_00567400();
    ModelNode* FUN_00571530(ModelNode*, void*);
    bool FUN_005710c0();
};
struct FUN_004ad050
{
    void* unk00;
    int unk04, unk08, unk0c, unk10, unk14, unk18;
    FUN_004ad050(float);
    ~FUN_004ad050();
};
struct FUN_00633c90
{
    ModelNode* ptr;
    FUN_00633c90(int);
    ~FUN_00633c90();
    FUN_00633c90* FUN_0066b0d0(ModelNode*);
    ModelNode* FUN_00559450();
};
struct AttachModelLoader
{
    ModelNode* FUN_00447080(const char*, int, int, int, int, int);
};
struct ModelEnvironment
{
    ModelNode* FUN_00457ba0(ModelNode*, FUN_004ad050*);
};
extern AttachModelLoader* DAT_011c3b3c;
extern ModelEnvironment* DAT_011dea10;
void FUN_00406d30(char*, unsigned int, const char*);
char* FUN_0040ab30(char*, int);
bool FUN_004b5bf0(ModelNode*);
bool FUN_004910d0(ModelNode*);
NiFixedString* FUN_00571550();
void FUN_004ade40(ModelNode*, ModelNode*, int, int);
void FUN_004ae250(ModelNode*, ModelNode*, int, int, int, int);

}  // namespace fnv_005710c0

enum MEM_CONTEXT
{
    MC_REFR = 0x31
};
class AutoMemContext
{
  public:
    AutoMemContext(MEM_CONTEXT aeMemoryContext, bool bPush, const char* pFile, int iLine);
    ~AutoMemContext();
    int iData;
};
class FUN_0055a2f0 : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64;
    FUN_0055a2f0();
    void* operator new(unsigned int);
};
class MobileObject : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84;
    MobileObject();
    void* operator new(unsigned int);
};
class Character : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4,
        unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4,
        unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C, unk160, unk164,
        unk168, unk16C, unk170, unk174, unk178, unk17C, unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C,
        unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC, unk1C0, unk1C4;
    Character(bool);
    void* operator new(unsigned int);
};
class FUN_008d4500 : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4,
        unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4,
        unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C, unk160, unk164,
        unk168, unk16C, unk170, unk174, unk178, unk17C, unk180, unk184, unk188, unk18C, unk190, unk194, unk198, unk19C,
        unk1A0, unk1A4, unk1A8, unk1AC, unk1B0, unk1B4, unk1B8, unk1BC;
    FUN_008d4500(bool);
    void* operator new(unsigned int);
};
class FUN_009b7a50 : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4,
        unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4,
        unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154, unk158, unk15C;
    FUN_009b7a50(bool);
    void* operator new(unsigned int);
};
class FUN_009b3fa0 : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4,
        unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4,
        unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150;
    FUN_009b3fa0(bool);
    void* operator new(unsigned int);
};
class FUN_00978fd0 : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4,
        unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4,
        unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150;
    FUN_00978fd0(bool);
    void* operator new(unsigned int);
};
class FUN_009b3160 : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4,
        unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4,
        unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154;
    FUN_009b3160(bool);
    void* operator new(unsigned int);
};
class FUN_009aaff0 : public TESObjectREFR
{
  public:
    unsigned int unk40, unk44, unk48, unk4C, unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C, unk70, unk74,
        unk78, unk7C, unk80, unk84, unk88, unk8C, unk90, unk94, unk98, unk9C, unkA0, unkA4, unkA8, unkAC, unkB0, unkB4,
        unkB8, unkBC, unkC0, unkC4, unkC8, unkCC, unkD0, unkD4, unkD8, unkDC, unkE0, unkE4, unkE8, unkEC, unkF0, unkF4,
        unkF8, unkFC, unk100, unk104, unk108, unk10C, unk110, unk114, unk118, unk11C, unk120, unk124, unk128, unk12C,
        unk130, unk134, unk138, unk13C, unk140, unk144, unk148, unk14C, unk150, unk154;
    FUN_009aaff0(bool);
    void* operator new(unsigned int);
};

struct EnableParentExtra
{
    TESObjectREFR* FUN_0041da10();
};

struct EnableParentRef
{
    EnableParentExtra* FUN_005d43c0();
    TESObjectREFR* FUN_0056a9f0();
};

extern float DAT_011c3c08;

struct AnimGroupInfo_011977d8
{
    void* f0;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
};
extern AnimGroupInfo_011977d8 g_011977d8[];

struct FUN_008579e0_shell : public TESSaveLoadGame
{
    void FUN_008579e0(void* out, unsigned int kind);
};
struct FUN_00857bd0 : public TESSaveLoadGame
{
    void Init(unsigned int value);
};
extern TESSaveLoadGame* g_TESSaveLoadGame;

struct NiControllerManager
{
    void FUN_0047aa40(bool value);
};

struct AnimationInterpolatorNode;
struct Idle_008b2010;
struct ControllerSequenceView
{
    unsigned int FUN_00495d00();
    Idle_008b2010* FUN_00495d20(unsigned int index);
};
struct Idle_008b2010;
struct NiNode;

struct FUN_0047aab0_shell
{
    void FUN_0047aab0(Idle_008b2010* item, int a, int b, float c, float d, int e);
};
struct FUN_00413f40_shell
{
    struct BSFadeNode* FUN_00413f40();
};
struct BSFadeNode
{
    void* FUN_0043b1b0();
};
struct FUN_008041a0_shell
{
    int FUN_008041a0();
};
struct FUN_004efbc0_shell
{
    void FUN_004efbc0(float value);
};
struct FUN_00639aa0_shell
{
    float FUN_00639aa0();
};

struct FUN_00a59c90_shell
{
    void FUN_00a59c90(NiUpdateData& data);
};
struct FUN_00a59c60_shell
{
    void FUN_00a59c60(const NiUpdateData& data);
};

int __cdecl FUN_00408b20(const char* a, const char* b);
unsigned char __cdecl FUN_004b5c80(NiNode* node);
unsigned short __cdecl FUN_004efaa0();
int __cdecl FUN_00406d30(char* dst, unsigned int size, const char* src);
void* __cdecl memset(void* dst, int val, unsigned int n);

struct xActorValueOwner
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual bool CanBeCommanded();
};

struct xNpcData
{
    bool IsOwnerActive();
};

struct xFormX
{
    bool IsHidden();
    bool IsSecret();
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
    xNpcData m_kData;
};

__if_not_exists(TESForm::TESForm)
{
    class TESForm
    {
      public:
        virtual ~TESForm();
    };
}
__if_not_exists(TESBoundObject::TESBoundObject)
{
    class TESBoundObject : public TESForm
    {
      public:
        unsigned int ID();
    };
}

struct CrimeFormTypeView
{
    int GetFormType();
};

__if_not_exists(TESCreature::TESCreature)
{
    class TESCreature : public TESBoundObject
    {
      public:
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
        xActorValueOwner m_kAVOwner;
    };
}

struct xCell
{
    xFormX* GetOwner();
    bool IsInterior();
    unsigned char IsPublic();
    bool IsOwnedBy(void* pkActor);
};

struct xExtraOwner
{
    xCell* GetContainingCell();
};

struct xLock
{
    bool IsLocked();
};

struct xPlayerX;

struct xRefr
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
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
    virtual bool IsInCombat(int i);
    xLock* GetLockX();
    TESBoundObject* GetBaseX();
    bool CanBeUsedX(xPlayerX* pkActor, bool b);
    void* GetOwnerX();
    xExtraOwner* GetExtraOwner();
    bool FUN_00579690();
};

struct xPlayerX : xRefr
{
    bool IsSneakingX();
};

extern xPlayerX* xg_pPlayer;
bool xIsPlayerOwner(xRefr* pkRef, xPlayerX* pkPlayer, int a, int b);

namespace fnv_0055f780 {
struct NiPoint3
{
    float x, y, z;
};

struct M3
{
    float m[9];
    M3();
};

struct UpdData
{
    int u0, u1, u2;
    void NiUpdateData(float, bool, bool);
};

struct NiNode
{
    void FUN_00440460(const NiPoint3&);
    void FUN_0043fa80(void*);
    void Update(const UpdData&);
};

struct TESContainer
{
};

struct InventoryChanges
{
    static InventoryChanges* GetOrAddInventoryChanges(TESObjectREFR*);
    void FUN_004d1960();
};

struct ExtraDataList
{
    void FUN_00426720(unsigned int, unsigned int, TESObjectREFR*);
};

TESContainer* __fastcall FUN_0055d310(TESObjectREFR*);
void FUN_00c69f50(NiNode*, int, int);

struct C0055f780 : public TESObjectREFR
{
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
    virtual bool vfunc_100();
    virtual void d65();
    virtual void d66();
    virtual void d67();
    virtual void d68();
    virtual void d69();
    virtual void d70();
    virtual void d71();
    virtual void d72();
    virtual void d73();
    virtual void d74();
    virtual void d75();
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
    virtual NiPoint3* vfunc_1f4();

    void FUN_0055f780(unsigned int a1, unsigned int a2);
    void FUN_008d0600(unsigned int, unsigned int);
    NiNode* Get3DSimple();
    ExtraDataList* GetExtraData();
    void FUN_0046a010(int);
    M3 FUN_0056fa00();
};

}  // namespace fnv_0055f780

class TESForm_564a00
{
  public:
    int GetFormType();
};

class TESBoundObject_564a00 : public TESForm_564a00
{
};

class NiAVObject_564a00;

class NiNode_564a00
{
  public:
    NiAVObject_564a00* FUN_00559450();
};

class ShadowSceneNode_564a00
{
  public:
    void CallItemMethodByKey(NiAVObject_564a00* pkObject, bool bValue);
};

namespace RefrShadow_564a00 {
extern "C" ShadowSceneNode_564a00* FUN_00450b80(int iIndex);
extern "C" void ClearAllCachedStates();
}

class TESObjectREFR_564a00 : public TESObjectREFR
{
  public:
    TESBoundObject_564a00* GetObjectReference();
    unsigned int GetFlags();
    void SetFlags(unsigned int uiFlags);
    NiNode_564a00* FUN_005725f0();
    void FUN_00564a00(bool bValue);
};

namespace fnv_0088db20 {
class TESForm;
struct EqTypeDescriptor;
extern EqTypeDescriptor DAT_01183028;
extern EqTypeDescriptor DAT_01183978;
extern "C" void* __cdecl FUN_00ec43fb(void* object, long displacement, const EqTypeDescriptor* sourceType,
                                      const EqTypeDescriptor* targetType, int isReference);

class EqFormView
{
  public:
    int FUN_00401170();
    void* GetSlotPointer(int iFlag);
};

class TESBipedModelForm
{
  public:
    virtual ~TESBipedModelForm();
    bool FUN_00480af0(int iSlot, int iA, int iB);
};
TESBipedModelForm* FUN_00480db0(TESForm* pkForm);

class EqExtraList
{
  public:
    bool FUN_00418b10();
    bool CheckExtraByType(int iFlag);
};
struct EqExtraNode
{
    EqExtraList** FUN_006815c0();
};
class EqEntry
{
  public:
    EqExtraNode* FUN_00559450();
    TESForm* FUN_0044ddc0();
    ~EqEntry();
};
struct EqEntryList
{
    EqEntry* FUN_004c8c10(int iSlot, int iFlag);
};
struct EqRefraction;
struct EqExtraData
{
    EqEntryList* FUN_00418520();
    EqRefraction* GetRefractionProperty();
};

class EqBiped
{
  public:
    TESForm* FUN_0088e0f0(int iSlot);
    void FUN_004aaff0(int iSlot, bool bA, int iB);
};

class EqActorView;
class EqProcess
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
    virtual void v050();
    virtual void v051();
    virtual EqEntry* GetLoadedForm();
    virtual EqEntry* GetAmmo();
    virtual void v0x54();
    virtual void v055();
    virtual void v056();
    virtual void v057();
    virtual void v058();
    virtual void v059();
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual void v07a();
    virtual void v07b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
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
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
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
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void v0e1();
    virtual void v0e2();
    virtual void v0e3();
    virtual void v0e4();
    virtual void v0e5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void v0f1();
    virtual void v0f2();
    virtual void v0f3();
    virtual void v0f4();
    virtual void v0f5();
    virtual void v0f6();
    virtual void v0f7();
    virtual void v0f8();
    virtual void v0f9();
    virtual void v0fa();
    virtual void v0fb();
    virtual void v0fc();
    virtual void v0fd();
    virtual void v0fe();
    virtual void v0ff();
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
    virtual void v10a();
    virtual void v10b();
    virtual void v10c();
    virtual void v10d();
    virtual void v10e();
    virtual void v10f();
    virtual void v110();
    virtual void v111();
    virtual void v112();
    virtual void v113();
    virtual void v114();
    virtual void v115();
    virtual void Unk_458(EqActorView* pkActor, int iValue);
};

class EqChanges
{
  public:
    void AddItemToInventory(TESForm* pkItem, int iCount, EqActorView* pkActor, EqExtraList* pkExtra, bool bA, bool bLock);
};
EqChanges* FUN_004bf220(EqActorView* pkActor);
struct EqSaveLoad
{
    bool FUN_0047c850();
};
extern EqSaveLoad* DAT_011de45c;
struct EqMagicSub
{
    void FUN_0040a420(bool bValue);
};
struct EqMagicItem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    EqMagicSub m_kSub;
};
EqMagicItem* FUN_004be330(TESForm* pkItem);
bool FUN_005b9b00();
struct EqRefraction
{
    int unk00;
    int unk04;
    int unk08;
    float m_fValue;
};
class EqNPCHelper
{
  public:
    bool FUN_006061b0(EqActorView* pkActor, EqBiped* pkBiped, TESForm* pkItem);
};

class EqActorView
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
    virtual void v00a();
    virtual void v00b();
    virtual void v00c();
    virtual void v00d();
    virtual void v00e();
    virtual void v00f();
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
    virtual void v01a();
    virtual void v01b();
    virtual void v01c();
    virtual void v01d();
    virtual void v01e();
    virtual void v01f();
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
    virtual void v02a();
    virtual void v02b();
    virtual void v02c();
    virtual void v02d();
    virtual void v02e();
    virtual void v02f();
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
    virtual void v03a();
    virtual void v03b();
    virtual void v03c();
    virtual void v03d();
    virtual void v03e();
    virtual void v03f();
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
    virtual void v04a();
    virtual void v04b();
    virtual void v04c();
    virtual void v04d();
    virtual void v04e();
    virtual void v04f();
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
    virtual void v05a();
    virtual void v05b();
    virtual void v05c();
    virtual void v05d();
    virtual void v05e();
    virtual void v05f();
    virtual void v060();
    virtual void v061();
    virtual void v062();
    virtual void v063();
    virtual void v064();
    virtual void v065();
    virtual void v066();
    virtual void v067();
    virtual void v068();
    virtual void v069();
    virtual void v06a();
    virtual void v06b();
    virtual void v06c();
    virtual void v06d();
    virtual void v06e();
    virtual void v06f();
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
    virtual EqBiped* GetBipedAnim();
    virtual void v0x7b();
    virtual void v07c();
    virtual void v07d();
    virtual void v07e();
    virtual void v07f();
    virtual void v080();
    virtual void v081();
    virtual void v082();
    virtual void v083();
    virtual void v084();
    virtual void v085();
    virtual bool Unk_218();
    virtual void v0x87();
    virtual void v088();
    virtual void v089();
    virtual void v08a();
    virtual void v08b();
    virtual void v08c();
    virtual void v08d();
    virtual void v08e();
    virtual void v08f();
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
    virtual void v09a();
    virtual void v09b();
    virtual void v09c();
    virtual void v09d();
    virtual void v09e();
    virtual void v09f();
    virtual void v0a0();
    virtual void v0a1();
    virtual void v0a2();
    virtual void v0a3();
    virtual void v0a4();
    virtual void v0a5();
    virtual void v0a6();
    virtual void v0a7();
    virtual void v0a8();
    virtual void v0a9();
    virtual void v0aa();
    virtual void v0ab();
    virtual void v0ac();
    virtual void v0ad();
    virtual void v0ae();
    virtual void v0af();
    virtual void v0b0();
    virtual void v0b1();
    virtual void v0b2();
    virtual void v0b3();
    virtual void v0b4();
    virtual void v0b5();
    virtual void v0b6();
    virtual void v0b7();
    virtual void v0b8();
    virtual void v0b9();
    virtual void v0ba();
    virtual void v0bb();
    virtual void v0bc();
    virtual void v0bd();
    virtual void v0be();
    virtual void v0bf();
    virtual void v0c0();
    virtual void v0c1();
    virtual void v0c2();
    virtual void v0c3();
    virtual void v0c4();
    virtual void v0c5();
    virtual void v0c6();
    virtual void v0c7();
    virtual void v0c8();
    virtual void v0c9();
    virtual void v0ca();
    virtual void v0cb();
    virtual void v0cc();
    virtual void v0cd();
    virtual void v0ce();
    virtual void v0cf();
    virtual void v0d0();
    virtual void v0d1();
    virtual void v0d2();
    virtual void v0d3();
    virtual void v0d4();
    virtual void v0d5();
    virtual void v0d6();
    virtual void v0d7();
    virtual void v0d8();
    virtual void v0d9();
    virtual void v0da();
    virtual void v0db();
    virtual void v0dc();
    virtual void v0dd();
    virtual void v0de();
    virtual void v0df();
    virtual void v0e0();
    virtual void Unk_384(int iA, float fB);
    virtual void v0xe2();
    virtual void v0e3();
    virtual int Unk_390();
    virtual void v0xe5();
    virtual void v0e6();
    virtual void v0e7();
    virtual void v0e8();
    virtual void v0e9();
    virtual void v0ea();
    virtual void v0eb();
    virtual void v0ec();
    virtual void v0ed();
    virtual void v0ee();
    virtual void v0ef();
    virtual void v0f0();
    virtual void v0f1();
    virtual void v0f2();
    virtual void v0f3();
    virtual void v0f4();
    virtual void v0f5();
    virtual void v0f6();
    virtual void v0f7();
    virtual void v0f8();
    virtual void v0f9();
    virtual void v0fa();
    virtual void Unk_3ec(TESForm* pkItem, int iA, bool bB, int iC);
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
    EqProcess* m_pkProcess;  // +0x68

    EqBiped* FUN_00950b00(int iValue);
    EqExtraData* FUN_005d43c0();
    bool FUN_0088d7d0(TESForm* pkItem, int iCount, EqExtraList* pkExtra, bool bA, bool bB, bool bC);
    void FUN_008b0b00(int iValue);
    EqNPCHelper* FUN_007af430();
    bool FUN_008c51c0();
    bool FUN_0088db20(TESForm* pkItem, int iCount, EqExtraList* pkExtra, bool bLock);
};
extern EqActorView* DAT_011dea3c;

}  // namespace fnv_0088db20

namespace fnv_005790f0 {
class TESFormSlots
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot3A();
    virtual void Slot3B();
    virtual unsigned char Slot3C();
};

struct ExtraDataList;

struct ExtraSayToTopicInfo
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    unsigned char byte18;
};

struct FUN_0042ede0_shell
{
    ExtraSayToTopicInfo* __thiscall FUN_0042ede0();
};

TESFormSlots* __cdecl FUN_004839c0(unsigned int index);
ExtraDataList* __fastcall FUN_005d43c0(TESObjectREFR* refr);

}  // namespace fnv_005790f0

struct RefState64
{
    int unk00;
    int unk04;
};
struct SoundSub
{
    unsigned int Deallocate();
};
struct SoundHolder
{
    int unk00;
    SoundSub sub;
};
struct Extra57b240
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    SoundHolder* unk1c;
};
struct ExtraList_SI
{
    Extra57b240* GetExtraData(unsigned char type);
};
struct Form57b240
{
    int FNV_GetFormType();
};

struct BGSPlaceableWater : TESBoundObject
{
    bool FUN_00452440();
};
struct WaterRef_SI
{
    TESBoundObject* GetBaseForm();
};
struct WaterNode_SI
{
    WaterRef_SI** GetItem();
    WaterNode_SI* GetNext();
};
struct WaterList
{
    WaterNode_SI* GetHead();
};
struct Ref57b240
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
    virtual bool IsX();
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
    RefState64* unk64;
    ExtraList_SI* GetExtraList();
    Form57b240* GetBaseForm();
    WaterList* GetContainingCell();
    void Update484a10(bool b);
    void FUN_0057b240(bool bIncrement);
};

struct SaveOrderTypeDescriptor;
extern SaveOrderTypeDescriptor DAT_01183028;
extern SaveOrderTypeDescriptor DAT_0118ac2c;
extern SaveOrderTypeDescriptor DAT_011841cc;
extern "C" void* __cdecl FNV_DynamicCast(void* object, long displacement, const void* sourceType,
                                         const void* targetType, int isReference);
class SaveOrderCell;
class SaveOrderForm
{
  public:
    virtual ~SaveOrderForm();
};
class FormTypeAccess
{
  public:
    unsigned int FUN_00401170();
};
class SaveOrderChildCell
{
  public:
    virtual SaveOrderCell* GetParentCell();
};
class SaveOrderCell : public SaveOrderForm
{
  public:
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
    virtual bool v3c(SaveOrderForm* p);
};
bool __cdecl FUN_005548a0(unsigned int type);
class SaveOrderBase
{
  public:
    virtual ~SaveOrderBase();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
};
class SaveOrderReference : public SaveOrderBase, public SaveOrderChildCell
{
  public:
    bool FUN_005653d0();
    bool FUN_0055e250(SaveOrderForm* pForm);
};

namespace fnv_0055d230 {
class TESForm;
struct EqTypeDescriptor;
extern EqTypeDescriptor DAT_01183028;
extern EqTypeDescriptor DAT_011841cc;
extern "C" void* __cdecl FUN_00ec43fb(void*, long, const EqTypeDescriptor*, const EqTypeDescriptor*, int);
extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);

struct CompareFormReceiver
{
    bool FUN_00485270(TESForm*);
};
struct CompareExtraList
{
    bool FUN_004127e0(CompareExtraList*);
};
struct CompareData
{
    TESForm* base;
    float rotationX, rotationY, rotationZ;
    float positionX, positionY, positionZ;
};
struct CompareRefView
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    CompareData data;
    float scale;
    void* parentCell;
    CompareExtraList extra;
    const CompareData* FUN_00891170();
    void* FUN_008d6f30() const;
    CompareExtraList* FUN_005d43c0();
    bool FUN_0055d230(TESForm* other);
};

}  // namespace fnv_0055d230

struct Sky;
struct TESWorldSpace;
struct TESContainer;

struct CallerNode55F5
{
    void FUN_00426020(int, int, int, int);
};

struct RefH55F5
{
    bool IsDeleted() const;
    bool GetDisabled();
    void FUN_00484af0(bool);
};

struct SkyObject55F5
{
    void Update(Sky*, int);
};

struct EnableParent55F5
{
    TESObjectREFR* GetEnableParent();
};

struct Actor55F5
{
    void* GetExtra() const;
};

struct InvBase55F5
{
    void FUN_004d4030();
};

struct InvChanges55F5 : InvBase55F5
{
    bool CreateForReference();
    static InvChanges55F5* __cdecl CreateForReference(TESObjectREFR*);
};

TESContainer* __fastcall FUN_0055d310(TESObjectREFR*);

struct VTable55F5
{
    virtual bool V00() = 0;
    virtual bool V01() = 0;
    virtual bool V02() = 0;
    virtual bool V03() = 0;
    virtual bool V04() = 0;
    virtual bool V05() = 0;
    virtual bool V06() = 0;
    virtual bool V07() = 0;
    virtual bool V08() = 0;
    virtual bool V09() = 0;
    virtual bool V10() = 0;
    virtual bool V11() = 0;
    virtual bool V12() = 0;
    virtual bool V13() = 0;
    virtual bool V14() = 0;
    virtual bool V15() = 0;
    virtual bool V16() = 0;
    virtual bool V17() = 0;
    virtual bool V18() = 0;
    virtual bool V19() = 0;
    virtual bool V20() = 0;
    virtual bool V21() = 0;
    virtual bool V22() = 0;
    virtual bool V23() = 0;
    virtual bool V24() = 0;
    virtual bool V25() = 0;
    virtual bool V26() = 0;
    virtual bool V27() = 0;
    virtual bool V28() = 0;
    virtual bool V29() = 0;
    virtual bool V30() = 0;
    virtual bool V31() = 0;
    virtual bool V32() = 0;
    virtual bool V33() = 0;
    virtual bool V34() = 0;
    virtual bool V35() = 0;
    virtual bool V36() = 0;
    virtual bool V37() = 0;
    virtual bool V38() = 0;
    virtual bool V39() = 0;
    virtual bool V40() = 0;
    virtual bool V41() = 0;
    virtual bool V42() = 0;
    virtual bool V43() = 0;
    virtual bool V44() = 0;
    virtual bool V45() = 0;
    virtual bool V46() = 0;
    virtual bool V47() = 0;
    virtual bool V48() = 0;
    virtual bool V49() = 0;
    virtual bool V50() = 0;
    virtual bool V51() = 0;
    virtual bool V52() = 0;
    virtual bool V53() = 0;
    virtual bool V54() = 0;
    virtual bool V55() = 0;
    virtual bool V56() = 0;
    virtual bool V57() = 0;
    virtual bool V58() = 0;
    virtual bool V59() = 0;
    virtual bool V60() = 0;
    virtual bool V61() = 0;
    virtual bool V62() = 0;
    virtual bool V63() = 0;
    virtual bool V64() = 0;
    virtual bool V65() = 0;
    virtual bool V66() = 0;
    virtual bool V67() = 0;
    virtual bool V68() = 0;
    virtual bool V69() = 0;
    virtual bool V70() = 0;
    virtual bool V71() = 0;
    virtual bool V72() = 0;
    virtual bool V73() = 0;
    virtual bool V74() = 0;
    virtual bool V75() = 0;
    virtual bool V76() = 0;
    virtual bool V77() = 0;
    virtual bool V78() = 0;
    virtual bool V79() = 0;
    virtual bool V80() = 0;
    virtual bool V81() = 0;
    virtual bool V82() = 0;
    virtual bool V83() = 0;
    virtual bool V84() = 0;
    virtual bool V85() = 0;
    virtual bool V86() = 0;
    virtual bool V87() = 0;
    virtual bool V88() = 0;
    virtual bool V89() = 0;
    virtual bool V90() = 0;
    virtual bool V91() = 0;
    virtual bool V92() = 0;
    virtual bool V93() = 0;
    virtual bool V94() = 0;
    virtual bool V95() = 0;
    virtual bool V96() = 0;
    virtual bool V97() = 0;
    virtual bool V98() = 0;
    virtual bool V99() = 0;
    virtual bool V100() = 0;
    virtual bool V101() = 0;
    virtual bool V102() = 0;
    virtual bool V103() = 0;
    virtual bool V104() = 0;
    virtual bool V105() = 0;
    virtual bool V106() = 0;
    virtual bool V107() = 0;
    virtual bool V108() = 0;
    virtual bool V109() = 0;
    virtual bool V110() = 0;
    virtual bool V111() = 0;
    virtual bool V112() = 0;
    virtual bool V113() = 0;
    virtual bool V114() = 0;
    virtual void V115(int, int) = 0;
};

struct Ref55F5 : VTable55F5
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    unsigned int valueAt20;

    void FUN_0055f5f0(unsigned int, unsigned int);
};

class TESForm;
struct OwnerLookupView : public TESObjectREFR
{
    TESForm* FUN_00567790();
};

struct VRefr00567790
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
    virtual bool IsSlot40();
};
struct FUN_00567770_s
{
    TESForm* FUN_00567770();
};
struct ExtraRadioData;
struct OwnerTeleportReceiver
{
    ExtraRadioData* FUN_00568e50();
};

struct RefH
{
    bool FUN_00568680();
};
TESForm* __fastcall FNV_GetObjectReference(TESObjectREFR*);
int __fastcall FNV_GetFormType(TESForm*);
struct Zone81;
struct FUN_00881c90_cls
{
    Zone81* FindEncounterZone();
};

struct DoorCell
{
    TESForm* GetOwner();
};

struct HealthValueOwner
{
    virtual void v0();
    virtual void v1();
    virtual int GetActorValue(int);
};
struct HealthActorView
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
    HealthValueOwner values;
    int FUN_004f8960();
};
class TESBoundObject;
__if_not_exists(TESBoundObject::~TESBoundObject)
{
    class TESBoundObject
    {
      public:
        virtual ~TESBoundObject();
    };
}
struct TESHealthForm;
__if_not_exists(TESHealthForm::~TESHealthForm)
{
    struct TESHealthForm
    {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual unsigned int GetHealth();
    };
}
struct HealthExtraValue
{
    int unk00;
    int unk04;
    int unk08;
    float pHealth;
};
struct HealthExtraList
{
    void* FUN_00410220(unsigned char);
};
struct HealthReferenceEntry;
void* __fastcall FUN_007af430(HealthReferenceEntry*);
struct HealthReferenceEntry
{
    HealthExtraList* FUN_005d43c0();
    float FUN_00568ad0();
};

struct HealthReferenceVTable
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
    virtual bool vfn_100();
};

struct TESContainer;

TESContainer* __fastcall FUN_0055d310(TESObjectREFR* refr);

struct RefInventoryQuery
{
    bool FUN_00575450(unsigned int aId);
};

namespace fnv_00574fa0 {
struct AddBoundItemRef
{
    void FUN_00574fa0(TESBoundObject*, ExtraDataList*, int);
};

void* __cdecl FUN_004826d0(TESBoundObject*);

namespace AddBoundItemData {
extern TESObjectREFR* DAT_011dea3c;
}

struct RefH
{
    bool GetDisabled();
};

struct StandIn_Refr
{
    bool FUN_005656d0();
};

struct StandIn_Cell
{
    void FUN_00545560(TESObjectREFR*);
};

enum CHALLENGE_TYPE
{
};

struct ChallengeManager
{
    static bool UpdateChallengeProgress(CHALLENGE_TYPE, int, TESBoundObject*, TESForm*, unsigned short, unsigned short,
                                        unsigned short);
};

struct SC_008c48d0
{
    static bool GetLocalData(void*, ExtraDataList*, unsigned int);
};

struct StandIn_Vtbl100
{
    virtual void _f0();
    virtual void _f1();
    virtual void _f2();
    virtual void _f3();
    virtual void _f4();
    virtual void _f5();
    virtual void _f6();
    virtual void _f7();
    virtual void _f8();
    virtual void _f9();
    virtual void _f10();
    virtual void _f11();
    virtual void _f12();
    virtual void _f13();
    virtual void _f14();
    virtual void _f15();
    virtual void _f16();
    virtual void _f17();
    virtual void _f18();
    virtual void _f19();
    virtual void _f20();
    virtual void _f21();
    virtual void _f22();
    virtual void _f23();
    virtual void _f24();
    virtual void _f25();
    virtual void _f26();
    virtual void _f27();
    virtual void _f28();
    virtual void _f29();
    virtual void _f30();
    virtual void _f31();
    virtual void _f32();
    virtual void _f33();
    virtual void _f34();
    virtual void _f35();
    virtual void _f36();
    virtual void _f37();
    virtual void _f38();
    virtual void _f39();
    virtual void _f40();
    virtual void _f41();
    virtual void _f42();
    virtual void _f43();
    virtual void _f44();
    virtual void _f45();
    virtual void _f46();
    virtual void _f47();
    virtual void _f48();
    virtual void _f49();
    virtual void _f50();
    virtual void _f51();
    virtual void _f52();
    virtual void _f53();
    virtual void _f54();
    virtual void _f55();
    virtual void _f56();
    virtual void _f57();
    virtual void _f58();
    virtual void _f59();
    virtual void _f60();
    virtual void _f61();
    virtual void _f62();
    virtual void _f63();
    virtual bool Unk_100();
};

}  // namespace fnv_00574fa0

enum CHALLENGE_TYPE
{
};

struct ChallengeManager
{
    static bool __cdecl UpdateChallengeProgress(CHALLENGE_TYPE type, int value, TESForm* form1, TESForm* form2,
                                                unsigned short value1, unsigned short value2, unsigned short value3);
};

struct SC_008c48d0
{
    static bool __cdecl GetLocalData(void* object, ExtraDataList* extra, unsigned int flag);
};

struct InventoryRefView
{
    bool FUN_00574a80(TESBoundObject* apObject, int aiNumber, ExtraDataList* apExtra, TESObjectREFR* apReference);
};

TESObjectREFR* _g_thePlayer;

struct Actor;
struct BGSAcousticSpace;
struct BGSEncounterZone;
struct BGSLightingTemplate;
struct BGSLoadFormBuffer;
struct BGSMusicType;
struct PlaceableWaterData;
struct BGSSaveFormBuffer;
struct BSFile;
struct BSMultiBoundNode;
struct BSPortalGraph;
struct BipedAnim;
struct CHUNK;
struct CellMopp;
struct CellRecord;
struct ExteriorData;
struct ExtraDataList_SV;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InteriorData;
struct ImpactSwap;
struct IntSeenData;
struct InventoryChanges;
struct LoadedCellData;
struct NavMeshCollection;
struct NiAVObject;
struct NiCamera;
struct NiColor;
struct NiNode;
struct NiPick;
struct NiPoint3;
struct NiRenderedTexture;
struct SeenData;
struct TESActorBase;
struct TESBoundObject;
struct TESClimate;
struct TESFile;
struct TESForm;
struct TESFullName;
struct TESGlobal;
struct TESImageSpace;
struct TESModel;
struct TESModelTextureSwap;
struct TESObject;
struct TESObjectCELL;
struct TESObjectLAND;
struct TESFormList;
struct TESRegionList;
struct TESRegionObjectBase;
struct RegionPoint;
struct FileEntryList;
struct TESWaterForm;
struct TESWorldSpace;
struct _D3DLOCKED_RECT;
struct BhkPickData;
struct bhkWorld;
struct bhkWorldM;
struct FUN_00576680_shell : public TESObjectREFR
{
    void FUN_00576680();
};

extern int g_TES_576680;

struct TES_helper
{
    void FUN_00453860(int);
};

struct NP
{
    NP& operator=(void*);
};

struct Helper_0061f890
{
    void FUN_0061f890(void* ref, int arg);
};

struct Proc_S
{
    Helper_0061f890* GetNext();
};

struct ExtraDataList_SV
{
    Proc_S* GetRoomId();
};

struct Helper_00576760
{
    void FUN_00576760();
};

struct TESObjectSTAT;

void* __cdecl GetObjectFromNode(NiAVObject*, bool, int);

struct VTable_1d0
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
    virtual void* vfn_1d0();
};

struct Standin_00576680
{
    bool FUN_00576680();
};

struct ReferenceFloatEntry
{
    void Endian();
    TESObjectREFR* m_pFourthReference;
    float m_fDelay;
};
struct ChildActivateView : public TESObjectREFR
{
    void FUN_0056a290(TESObjectREFR*);
};

template <typename T> struct BSSimpleList;

struct TESObjectACTI;

extern double _gModifierZero;
extern TESObjectACTI* DAT_011ca27c;
extern TESObjectACTI* DAT_011ca280;

struct ChildActivateExtraView
{
    void* FUN_005d43c0() const;
};

bool __fastcall _ref_008256d0(void*);
void* __fastcall _ref_00726070(void*);
ReferenceFloatEntry** __fastcall _ref_006815c0_data(void*);

struct Standin_41e9e0
{
    float GetExtraFloat(void*);
};

struct TESObjectREFR_acc : public TESObjectREFR
{
    bool Activate(TESObjectREFR*, bool, TESBoundObject*, int);
};

struct Standin_Cell
{
    void FUN_005455c0(void*);
};

struct Form_00577d50;
struct Container_00577d50;

struct InvChangesBase_00577d50
{
    bool FUN_0042cde0();
};

struct InvChanges_00577d50 : public InvChangesBase_00577d50
{
    static InvChanges_00577d50* __cdecl CreateForReference(TESObjectREFR* object);
    int GetObjectCount(Form_00577d50* form);
};

struct ExtraList_00577d50
{
    void RemoveExtraDataType0x15();
};

struct RefExtra_00577d50
{
    void* GetExtra() const;
};

struct FUN_00577d50_shell : public TESObjectREFR
{
    int FUN_00577d50();
};

Form_00577d50* _ref_004839c0(unsigned int id);

struct OwnershipReferenceView : public TESObjectREFR
{
    bool FUN_005785e0(Actor*, bool);
};

struct OwnershipTypeDescriptor;
extern OwnershipTypeDescriptor DAT_011846e8;
extern OwnershipTypeDescriptor DAT_01183108;
extern "C" void* __cdecl FUN_00ec43fb(void*, long, const OwnershipTypeDescriptor*, const OwnershipTypeDescriptor*, int);
struct ActorQ
{
    virtual void v000();
    virtual void v004();
    virtual void v008();
    virtual void v00c();
    virtual void v010();
    virtual void v014();
    virtual void v018();
    virtual void v01c();
    virtual void v020();
    virtual void v024();
    virtual void v028();
    virtual void v02c();
    virtual void v030();
    virtual void v034();
    virtual void v038();
    virtual void v03c();
    virtual void v040();
    virtual void v044();
    virtual void v048();
    virtual void v04c();
    virtual void v050();
    virtual void v054();
    virtual void v058();
    virtual void v05c();
    virtual void v060();
    virtual void v064();
    virtual void v068();
    virtual void v06c();
    virtual void v070();
    virtual void v074();
    virtual void v078();
    virtual void v07c();
    virtual void v080();
    virtual void v084();
    virtual void v088();
    virtual void v08c();
    virtual void v090();
    virtual void v094();
    virtual void v098();
    virtual void v09c();
    virtual void v0a0();
    virtual void v0a4();
    virtual void v0a8();
    virtual void v0ac();
    virtual void v0b0();
    virtual void v0b4();
    virtual void v0b8();
    virtual void v0bc();
    virtual void v0c0();
    virtual void v0c4();
    virtual void v0c8();
    virtual void v0cc();
    virtual void v0d0();
    virtual void v0d4();
    virtual void v0d8();
    virtual void v0dc();
    virtual void v0e0();
    virtual void v0e4();
    virtual void v0e8();
    virtual void v0ec();
    virtual void v0f0();
    virtual void v0f4();
    virtual void v0f8();
    virtual void v0fc();
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
    virtual ::TESBoundObject* GetBaseObject();
    ::TESBoundObject* GetObjectReference();
    bool HasFaction(TESForm*);
};
struct TESGlobal
{
    float GetValue();
};
struct FormTypeHelper
{
    int GetFormType();
};
struct OwnerHelper
{
    TESForm* GetOwner();
    int GetReferenceLockLevel();
    TESGlobal* GetLockLevelGlobal();
};
bool __fastcall FUN_00578770(TESFaction*);
extern double gModifierZero;

class TESMagicTargetForm
{
};

struct FullNameLengthView
{
    unsigned int GetModelLength() const;
};

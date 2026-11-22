// fallout_shared/tesworldspace.cpp: TESWorldSpace, TESObjectCELL, TESRegion, InterfaceManager and more (19 functions)
#include "f3_common.h"
#include "tesworldspace_packet.h"
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_FloatToInt for 0x00501250); no F3 match in this file yet
// @fnv 0x00425fd0
// Sets the world space's map name from the given string and returns true.
// @fnv 0x00583330
// Returns the terrain manager of the parent world space if one exists, otherwise this world space's own terrain.
// @fnv 0x00586170
// Returns parent if it exists and GetParentUseFlag(flag) is set, otherwise returns null.
// @fnv 0x00586390
// Looks up key in cellMap and returns the stored reference cast to TESObjectCELL, or null if not found.
// @fnv 0x00587630
// If ref is non-null and not temporary, creates a persistent cell and adds ref to it.
// @fnv 0x00587ff0
// @fnv 0x004f1260
// @fnv 0x00473ff0
// Clears night and looping sounds, effect shader, calls three helpers, resets the full name and zeroes 16 bytes at offset 0x80.
// @fnv 0x00586480
// Validates x and y are within -32768..32767, builds a key from them, and looks up the cell in cellMap, returning it or null.
// @fnv 0x005875a0
// @fnv 0x00586150
// @fnv 0x00584bc0
// @fnv 0x00586110
// @fnv 0x00586130
// @fnv 0x005861b0
// @fnv 0x005862e0
// Sets parent to world and clears field4E when world is null.
// @fnv 0x005863d0

struct FUN_005861d0_shell : public TESWorldSpace
{
    void SetFlagBit0(bool);
};

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

int __cdecl TruncateFloatToInt(float);
int __cdecl _FNV_Finite(double);
int __cdecl _FNV_IsNaN(double);

// @f3 0x00501250 (community match, verified in this file)
int __cdecl FUN_00c01895(double value);
int __cdecl FUN_00c018aa(double value);

int __cdecl FUN_00587440(const NiPoint3* aCoord)
{
    if (!FUN_00c01895(aCoord->x) || !FUN_00c01895(aCoord->y) || !FUN_00c01895(aCoord->z) ||
        FUN_00c018aa(aCoord->x) || FUN_00c018aa(aCoord->y) || FUN_00c018aa(aCoord->z))
    {
        return 0x7fff7fff;
    }

    int iX = fnv_FloatToInt(aCoord->x) >> 12;
    int iY = fnv_FloatToInt(aCoord->y) >> 12;
    return ((int)(short)iX << 16) | (unsigned short)(short)iY;
}


void* __fastcall _FNV_GetObjectReference(void*);
int __fastcall _FNV_GetFormType(void*);

struct FUN_00588030_shell : public TESWorldSpace
{
    void FUN_00588030(TESObjectREFR*);
};

struct TESObjectCELL_RemoveReference_Helper : public TESObjectCELL
{
    void RemoveReference(TESObjectREFR*);
};

struct FUN_00588b00_shell : public TESWorldSpace
{
    void* GetOrCreateCellOffsetData(TESFile*);
};

void* __cdecl operator new(unsigned int);
extern float const DAT_01015f5c;

class NiPoint2
{
  public:
    float x, y;
    NiPoint2()
    {}
    NiPoint2(float, float);
};

struct OFFSET_DATA_24
{
    unsigned int pCellOffsets;
    NiPoint2 m_kFirstPoint;
    NiPoint2 m_kEndPoint;
    unsigned int uiFileOffset;

    OFFSET_DATA_24();
};

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
    void SetAt(unsigned int, unsigned int);
};

void __fastcall _ref_006815c0(void* pThis);

extern int DAT_01031fac;

struct FUN_00588fa0_arg
{
    unsigned int val;
};

void __fastcall FUN_005890c0(int* self, FUN_00588fa0_arg a);

void __fastcall _ref_00726070(void*);

struct FUN_005832f0_shell : public TESForm
{
    char* FUN_005832f0();
};

struct Flt
{
    operator unsigned int() const;
};

struct FUN_00587670_shell : public TESWorldSpace
{
    bool FUN_00587670(TESObjectCELL*);
};

struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
    bool IsCellPersistent();
};
struct S54de10
{
    void FUN_0054de10(TESWorldSpace*);
};
unsigned int __fastcall _ref_0084e3a0(void*);

struct FUN_00587e40_shell : public TESWorldSpace
{
    void FUN_00587e40(TESObjectREFR*);
};

template <class T> struct BSSimpleList
{
    T item;
    BSSimpleList<T>* next;
    ~BSSimpleList();
    void operator delete(void*);
};
struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
extern ATM g_011ca60c;
struct WsH
{
    static int __cdecl GetKeyForWorldCoord(const NiPoint3&);
};
struct ListH
{
    void _ref_00905330(TESObjectREFR**);
    bool _ref_008256d0();
};
struct MapH
{
    bool RemoveAt(unsigned int);
};
bool __cdecl FUN_00587c80(void*);

struct FUN_00588070_shell : public TESWorldSpace
{
    TESObjectCELL* GetOrCreateCell();
};

namespace stub {
struct TESObjectCELL
{
    TESObjectCELL();
    char pad[0xe0];
};
}
struct FUN_005516f0_s
{
    void SetFlag400(int);
};
struct FUN_00544630_shell
{
    void ResetCellData();
};

struct FileH
{
    bool __thiscall IsMasterFile(void);
    bool __thiscall SetOffset(unsigned int);
    unsigned int __thiscall GetFormID(void);
};

struct FormIDData
{
    unsigned int pad0[5];
    unsigned int formID;
};

extern unsigned int __fastcall _ref_00472660(void*);
extern unsigned int __fastcall _ref_0084e3a0(void*);
extern unsigned char DAT_0118730c;

struct FUN_005858b0_shell
{
    FormIDData* __thiscall FUN_00588a90(FileH* apFile);
    bool IsFileFormIDMatching(FileH* apFile);
};

struct TESClimate
{
    virtual ~TESClimate();  // polymorphic: its RTTI is used (rtti_fix.py)
};

class FUN_00585fe0_shell : public TESWorldSpace
{
  public:
    TESClimate* FUN_00585fe0();
};

struct FUN_00586020_shell
{
    char pad[0x44];
    TESWorldSpace* field44;
    TESWorldSpace* GetParentWorld(TESWorldSpace::PARENT_USE_FLAG);
    TESWorldSpace* GetWorldSpaceOrParentWorld();
};

struct FUN_00586210_shell
{
    unsigned char cFlags;
    bool HasFlag2();
};

struct ArrSI
{
    unsigned int GetFlags(void);
    char HasFlag80000();
};

struct FUN_00586260_shell
{
    bool IsFlag8Set();
};

struct FUN_00586280_shell
{
    unsigned char bFlags;  // +0x4c
    void SetFlag8(bool bFlag);
};

struct FUN_005862c0_shell
{
    unsigned char cFlags;  // +0x4c
    bool IsFlagSet();
};

struct FUN_00586300_shell
{
    char IsFlag80Set();
};

struct FUN_00586320_shell
{
    bool FUN_00586320();
};

struct FNStub
{
    const char* GetFullName();
};

struct FUN_00586440_shell : TESWorldSpace
{
    const char* FUN_00586440();
};

struct StartMenu
{
    char const* GetMenuTitle();
};

extern StartMenu g_011ca130;

namespace fnv_00587550 {
extern "C"
{
    int __cdecl TruncateFloatToInt(float);
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct FUN_00587550_shell : TESWorldSpace
{
    TESObjectCELL* FUN_00587550(const NiPoint3& aCoord);
};

}  // namespace fnv_00587550

extern "C"
{
    struct TESWaterForm;
}

extern TESWaterForm* DAT_011ca53c;

template <class T> class BSSimpleList;

struct FUN_0054b8c0_shell
{
    void AddStaticRefsToList(BSSimpleList<const char*>*);
};

struct FUN_00588520_shell
{
    void FUN_00588520(BSSimpleList<const char*>*);
};

template <int N> struct EndianSizeTag
{
};

void __cdecl BSEndian(int*, EndianSizeTag<2>);
void __cdecl BSEndian(unsigned short*, EndianSizeTag<2>);

struct FUN_005840b0_shell
{
    void __thiscall FUN_005840b0();
};

struct Modifier
{
    void SetValue(float);
};
struct AlphaColor
{
    void FUN_0052ce20(float);
};
struct FUN_004f6fc0_shell
{
    int _a;
    int _b;
    void FUN_004f6fc0();
};
struct FUN_004f6850_shell
{
    void FUN_004f6850(void*, FUN_004f6fc0_shell*, void*);
};
struct FUN_004f6800_shell
{
    void FUN_004f6800(void*, float*, void*);
};

struct FUN_00528560_Host
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual TESObjectCELL* v5(unsigned int) = 0;
    TESObjectCELL* GetCellAtGridCoord(unsigned short, unsigned short);
};

struct FUN_00582e00_host
{
    void FUN_00582e30();
    void* FUN_00582e00(unsigned int);
};
void __cdecl _Deallocate(void*);

struct S_00583040
{
    void FUN_006fc980();
    void* FUN_00583040(unsigned int);
};
void _Deallocate(void*);

namespace fnv_00584530 {
struct FileH;

struct FormIDData
{
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
};

struct FUN_005858b0_shell
{
    FormIDData* FUN_00588a90(FileH*);
    int FUN_00584530(FileH* file, int x, int y);
};

}  // namespace fnv_00584530

class TESWaterForm;
extern TESWaterForm* DAT_011ca53c;
struct FUN_005860c0_shell : TESWorldSpace
{
    TESWaterForm* FUN_005860c0();
};

struct Unk00586340
{
    bool FUN_00586340(int);
};

struct PointerPairData;
struct FUN_00586400_shell : TESWorldSpace
{
    PointerPairData* FUN_00586400();
};

namespace fnv_00587760 {
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};
struct MapH
{
    bool RemoveAt(unsigned int);
};
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
struct S54de10
{
    void FUN_0054de10(TESWorldSpace*);
};

struct FUN_00587760_shell : TESWorldSpace
{
    void RemoveCellFromMap(TESObjectCELL* cell);
};

}  // namespace fnv_00587760

namespace fnv_00587870 {
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
template <class T> struct BSSimpleList
{
};
struct OverlapHolder
{
    char pad[0x68];
    DummyPointerMap* map68;
    BSSimpleList<TESObjectREFR*>* FUN_00587870(CellH* apCell);
};
}  // namespace fnv_00587870

struct CellCaller
{
    void MoveReferencesToWorldCells(TESWorldSpace*);
};
struct FUN_00588120_host
{
    void FUN_00588120();
};

struct FUN_005884e0_owner : TESWorldSpace
{
    void FUN_005884e0(TESObjectREFR*);
};
struct CellProxy
{
    void FUN_0054b830(TESObjectREFR*);
};

namespace fnv_00588a90 {
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&) const;
};
struct FormIDData
{
    int dummy;
};
struct TESWorldSpace_shell
{
    FormIDData* FUN_00588a90(TESFile* file);
};
}  // namespace fnv_00588a90

struct BGSCameraPath;
struct BGSCameraShot;
struct NiFormArray;
struct PerkEntryConditionSet;
struct CameraPathManager
{
    void InitializeCameraPaths();
    static BGSCameraPath* GetTextureResourcePath();
    void AddCameraPath(BGSCameraPath*);
    void UpdateCameraPaths();
    void ClearCameraPaths();
    NiFormArray* GetRootPathArray();
    BGSCameraPath* SetCameraPathEnabled(TESObjectREFR*, TESObjectREFR*);
    void* __vecDelDtor(unsigned int);
    char m_kCameraPathArray[24];
    char m_kCameraPathList[16];
};
typedef char _sizecheck_BGSCameraPathManager[sizeof(CameraPathManager) == 40 ? 1 : -1];
struct FUN_0095f530_shell : public CameraPathManager
{
    BGSCameraPath* FUN_0095f530(TESObjectREFR*, TESObjectREFR*);
};

struct Caller_0095f590
{
    BGSCameraPath* __thiscall FUN_0095f590(unsigned int);
};

namespace fnv_00582c20 {
struct TESFormBase
{
    TESFormBase();
    ~TESFormBase();
    virtual void V();
    int x[5];
};
namespace stand {
struct TESFullName
{
    TESFullName();
    ~TESFullName();
    virtual void V();
    int x[2];
};
}
struct TESTexture
{
    TESTexture();
    ~TESTexture();
    virtual void V();
    int x[2];
};
struct FUN_0057cd10
{
    FUN_0057cd10();
    ~FUN_0057cd10();
    int x;
};
struct FUN_00588fa0
{
    FUN_00588fa0(unsigned int);
    ~FUN_00588fa0();
    int x[4];
};
struct SL
{
    SL();
    ~SL();
    int x[2];
};
struct GO
{
    GO(int);
    ~GO();
    int x;
};
struct FUN_006815c0
{
    float x, y;
    FUN_006815c0();
};
struct FUN_00588fd0
{
    FUN_00588fd0(int);
    ~FUN_00588fd0();
    int x[4];
};
struct StrMem
{
    StrMem();
    ~StrMem();
    int x[2];
};
struct FUN_00589000
{
    FUN_00589000(unsigned int);
    int x[4];
};
struct SFTX
{
    void SetFormType(int);
};
extern float _DAT_01015f5c;
struct FUN_00582c20 : public TESFormBase, public stand::TESFullName, public TESTexture
{
    FUN_00589000* pCellNavMeshInfoMap;
    void* m_pCell;
    FUN_0057cd10 m_kFirstTreeComponent;
    void* m_pThirdTreePointer;
    int pad40[4];
    FUN_00588fa0 m_kSecondTreeComponent;
    SL m_kThirdTreeComponent;
    void* m_pFourthTreePointer;
    GO m_kFourthTreeComponent;
    int pad70[12];
    FUN_006815c0 m_kFirstPoint;
    FUN_006815c0 m_kEndPoint;
    FUN_00588fd0 OffsetDataMap;
    StrMem name;
    int padc8[3];
    TESTexture CanopyShadowTexture;
    TESTexture m_kLeafShadowTexture;
    FUN_00582c20();
    void FUN_00583070();
};

}  // namespace fnv_00582c20

namespace fnv_005857b0 {
struct FileH
{
    int m_uiData;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
    float m_fVectorX;
};
struct FUN_005858b0_shell
{
    FileH* FUN_00588a90(int);
};
struct FUN_005857b0_shell : FUN_005858b0_shell
{
    int FUN_00584530(int, int, int);
    void FUN_005857b0(int a, int b);
};
}  // namespace fnv_005857b0

struct MapX
{
    void* GetFirstPos();
};
struct List_009e03e0
{
    ~List_009e03e0();
    void RemoveAll();
};
struct MyMap
{
    void RemoveAll();
    virtual ~MyMap();
};
struct NiTMap
{
    void GetNext(void*&, unsigned int&, void*&);
};
struct FUN_00587bb0_shell
{
    void DestroyMapEntries();
};

namespace fnv_00588c80 {
struct MapX
{
    void* GetFirstPos();
};
struct MyMap
{
    void RemoveAll();
};
struct NiTMap
{
    void GetNext(void*&, unsigned int&, void*&);
};
void __cdecl _Deallocate(void*);
struct FUN_00588c80
{
    void PerformNoArgumentOperation();
};
}  // namespace fnv_00588c80

namespace fnv_00583070 {
struct FUN_00583070_shell : public TESWorldSpace
{
    void FUN_00583070();
};

struct FUN_005861d0_shell
{
    void SetFlagBit0(bool);
};

struct GO
{
    void operator=(void*);
};

struct FormProxy : TESForm
{
    bool IsReservedFormID();
};

struct WorldSpaceVirtual
{
    virtual void Call();
};

}  // namespace fnv_00583070

struct GO
{
    operator unsigned int() const;
    void operator=(void*);
};

struct A51BF0Base
{
    static void* __cdecl operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};

struct FUN_00c5a9d0 : A51BF0Base
{
    unsigned char padding[0x78];
    FUN_00c5a9d0();
};

extern unsigned int _data_011c16bc;

struct FUN_005831d0_shell
{
    unsigned char padding[0x6c];
    GO go;

    unsigned int GetOrCreateObject();
};

namespace fnv_00588150 {
struct CellH
{
    int GetCellGridX();
    int GetCellGridY();
};

struct ATM
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering(void);
};

extern ATM g_011ca60c;

struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&);
};

struct BSSimpleList
{
    bool _ref_008256d0();
    TESObjectREFR** _ref_006815c0();
    BSSimpleList* _ref_00726070();
};

struct BSOcclusionPlane
{
    int GetCullResult() const;

    virtual void V0() = 0;
    virtual void V1() = 0;
    virtual void V2() = 0;
    virtual void V3() = 0;
    virtual void V4() = 0;
    virtual void V5() = 0;
    virtual void V6() = 0;
    virtual void V7() = 0;
    virtual void V8() = 0;
    virtual void V9() = 0;
    virtual void V10() = 0;
    virtual void V11() = 0;
    virtual void V12() = 0;
    virtual void V13() = 0;
    virtual void V14() = 0;
    virtual void V15() = 0;
    virtual void V16() = 0;
    virtual void V17() = 0;
    virtual void V18() = 0;
    virtual void V19() = 0;
    virtual void V20() = 0;
    virtual void V21() = 0;
    virtual void V22() = 0;
    virtual void V23() = 0;
    virtual void V24() = 0;
    virtual void V25() = 0;
    virtual void V26() = 0;
    virtual void V27() = 0;
    virtual void V28() = 0;
    virtual void V29() = 0;
    virtual void V30() = 0;
    virtual void V31() = 0;
    virtual void V32() = 0;
    virtual void V33() = 0;
    virtual void V34() = 0;
    virtual void V35() = 0;
    virtual void V36() = 0;
    virtual void V37() = 0;
    virtual void V38() = 0;
    virtual void V39() = 0;
    virtual void V40() = 0;
    virtual void V41() = 0;
    virtual void V42() = 0;
    virtual void V43() = 0;
    virtual void V44() = 0;
    virtual void V45() = 0;
    virtual void V46() = 0;
    virtual void V47() = 0;
    virtual void V48() = 0;
    virtual void V49() = 0;
    virtual void V50() = 0;
    virtual void V51() = 0;
    virtual void V52() = 0;
    virtual void V53() = 0;
    virtual void V54() = 0;
    virtual void V55() = 0;
    virtual void V56() = 0;
    virtual void V57() = 0;
    virtual void V58() = 0;
    virtual void V59() = 0;
    virtual void V60() = 0;
    virtual void V61() = 0;
    virtual void V62() = 0;
    virtual void V63() = 0;
    virtual void V64() = 0;
    virtual void V65() = 0;
    virtual void V66() = 0;
    virtual void V67() = 0;
    virtual void V68() = 0;
    virtual void V69() = 0;
    virtual void V70() = 0;
    virtual void V71() = 0;
    virtual void V72() = 0;
    virtual void V73() = 0;
    virtual void V74() = 0;
    virtual void V75() = 0;
    virtual void V76() = 0;
    virtual void V77() = 0;
    virtual void V78() = 0;
    virtual void V79() = 0;
    virtual void V80() = 0;
    virtual void V81() = 0;
    virtual void V82() = 0;
    virtual void V83() = 0;
    virtual void V84() = 0;
    virtual void V85() = 0;
    virtual void V86() = 0;
    virtual void V87() = 0;
    virtual void V88() = 0;
    virtual void V89() = 0;
    virtual void V90() = 0;
    virtual void V91() = 0;
    virtual void V92() = 0;
    virtual void V93() = 0;
    virtual void V94() = 0;
    virtual void V95() = 0;
    virtual void V96() = 0;
    virtual void V97() = 0;
    virtual void V98() = 0;
    virtual void V99() = 0;
    virtual void V100() = 0;
    virtual void V101() = 0;
    virtual void V102() = 0;
    virtual void V103() = 0;
    virtual void V104() = 0;
    virtual void V105() = 0;
    virtual void V106() = 0;
    virtual void V107() = 0;
    virtual void V108() = 0;
    virtual void V109() = 0;
    virtual void V110() = 0;
    virtual void V111() = 0;
    virtual void V112() = 0;
    virtual void V113() = 0;
    virtual void V114() = 0;
    virtual void V115() = 0;
    virtual void V116() = 0;
    virtual void V117() = 0;
    virtual void V118() = 0;
    virtual void V119() = 0;
    virtual void V120() = 0;
    virtual void V121() = 0;
    virtual void V122() = 0;
    virtual void V123() = 0;
    virtual void V124() = 0;

    virtual TESObjectREFR* FUN_0125() = 0;
};

struct FUN_00550200_shell : public TESObjectCELL
{
    bool FUN_00550200(TESObjectREFR*);
};

struct FUN_00588150_shell : public TESWorldSpace
{
    void AddCellReferences(TESObjectCELL*);
};

}  // namespace fnv_00588150

namespace fnv_00588560 {
class NiTMap
{
  public:
    void GetNext(void*& position, unsigned int& key, void*& value);
};

class MapX : public NiTMap
{
  public:
    void* GetFirstPos();
};

int _stricmp(const char* string1, const char* string2);

class FUN_00588560_entry
{
  public:
    virtual void f00() = 0;
    virtual void f01() = 0;
    virtual void f02() = 0;
    virtual void f03() = 0;
    virtual void f04() = 0;
    virtual void f05() = 0;
    virtual void f06() = 0;
    virtual void f07() = 0;
    virtual void f08() = 0;
    virtual void f09() = 0;
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
    virtual const char* f76() = 0;
};

struct FUN_00588560_shell
{
    unsigned char pad[0x30];
    MapX* map;

    void* FindEntryByName(const char* name);
};

}  // namespace fnv_00588560

struct HelperAt6c
{
    void FUN_0066b0d0(int mode);
};
struct RefAt48
{
    void* FUN_0040f2a0(int deletionFlags);
};
struct FUN_00583180_Class
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44;
    RefAt48* m_ref;
    int unk4c, unk50, unk54, unk58, unk5c, unk60, unk64, unk68;
    HelperAt6c m_container;
    void FUN_00583180();
};

struct FUN_00583270_sub_cls
{
    void* FUN_00559450();
    void FUN_0066b0d0(int);
};
struct FUN_00583270_mid_cls
{
    int FUN_00454b30();
};
struct FUN_00583270_tgt_cls
{
    void FUN_00b5ddf0(int);
};
int __fastcall FUN_00726070_cb(void* p);
void* __cdecl FUN_00450b80_cb(int v);

struct FUN_00583270_cls
{
    char pad[0x6c];
    FUN_00583270_sub_cls sub;
    void FUN_00583270();
};

struct TypeGroupInfo
{
    unsigned int type;
    unsigned int unk04;
    unsigned int label;
    unsigned int groupType;
};
struct FileReader
{
    bool FUN_00471c20();
    bool SetOffset(unsigned int);
    bool FUN_004734d0(void*);
    bool FUN_00472150(bool);
    TypeGroupInfo* FUN_00462270();
    void FUN_00473660();
    int FUN_004726b0();
    bool FUN_00472890(void*, unsigned int);
    bool FUN_00401680();
    bool FUN_004726f0();
    void SkipCurrentForm();
};
struct Offsets
{
    unsigned int* offsets;
    unsigned int unk04, unk08, unk0c, unk10;
    unsigned int base;
};
struct CellCoordinates
{
    int x, y, flags;
    void FUN_00540720();
    void FUN_00462230();
};
int GetCellCoordKey(int, int);
int FUN_005442c0(int, int);
extern unsigned int kGroupFormType;
extern unsigned int DAT_011872b4;
extern unsigned int DAT_01187338;
struct WorldReader
{
    Offsets* FUN_00588a90(FileReader*);
    int FUN_00584530(FileReader*, int, int);
    bool SeekToCellInWorld(FileReader*, int, int);
};

struct FUN_005877e0_shell : public TESWorldSpace
{
    void FUN_005877e0();
    bool Probe();
};

struct FUN_005877e0_Val5
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int v4(int);
};

struct FUN_005877e0_Map
{
    void* First();
    void Next(void** it, unsigned int* key, FUN_005877e0_Val5** out);
    void Done();
};

struct Pt3
{
    float x;
    float y;
    float z;
    Pt3();
    Pt3& operator*=(float);
    Pt3 operator-(const Pt3&) const;
    Pt3 operator+(const Pt3&) const;
};

extern float const DAT_01016248;

struct WorldOffsetHost
{
    int unk00;
    float GetOffsetX();
    float GetOffsetY();
};

float __fastcall GetWorldScale(void* apWorld);

struct FUN_00588e40_shell : WorldOffsetHost
{
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
    float m_fGridOriginX;
    float afWorldOriginY;
    float kPointArrayBench;
    float m_fWorldTransformCoefficient4;
    void TransformWorldPoint(Pt3* apPoint, bool abInverse);
};

struct FUN_00483630_holder
{
    virtual ~FUN_00483630_holder();
    unsigned int flags, formID, fileData, changedFlags, recordData;
};
struct FUN_00591300
{
    virtual ~FUN_00591300();
    unsigned int nameData, nameLength;
};
struct TESTexture
{
    virtual ~TESTexture();
    unsigned int textureData, textureLength;
};
struct FUN_0048e2e0
{
    unsigned int type, data, length;
    ~FUN_0048e2e0();
};
struct FUN_0057ce90_shell
{
    unsigned int head;
    ~FUN_0057ce90_shell();
};
struct FUN_00589130
{
    unsigned int table, count, allocator, entries;
    ~FUN_00589130();
};
struct FUN_00589230
{
    unsigned int entries, size, capacity, allocator;
    ~FUN_00589230();
};
struct BSStringTChar
{
    unsigned int data, length;
    ~BSStringTChar();
};
struct GO633
{
    void* node;
    ~GO633();
};
struct WorldTerrain
{
    void FUN_006fca70();
    ~WorldTerrain();
};
struct WorldCellMap
{
    virtual ~WorldCellMap();
};
struct WorldLandMap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual ~WorldLandMap();
};
struct FUN_00582e30 : FUN_00483630_holder, FUN_00591300, TESTexture
{
    WorldCellMap* cellMap;
    WorldLandMap* landMap;
    FUN_0057ce90_shell cellList;
    WorldTerrain* terrain;
    unsigned int water, parentUseFlags, climate, worldFlags;
    FUN_00589130 offsetMap;
    BSSimpleList<int> regionList;
    unsigned int worldspaceID;
    GO633 node;
    unsigned int parent, music, encounterZone, location, mapScale, mapX, mapY;
    unsigned int minX, minY, maxX, maxY, landHeight, waterHeight, lodWater;
    unsigned int lodWaterType, impactData;
    FUN_00589230 offsetArray;
    BSStringTChar mapName;
    float usableX, usableY;
    unsigned int mapDimensions;
    FUN_0048e2e0 m_kCloudLayerTextures;
    FUN_0048e2e0 waterTexture;
    virtual ~FUN_00582e30();
    void ClearAllLists();
    void DestroyMapEntries();
    void FUN_00583180();
    void FUN_005877e0();
    void FUN_00588c80();
};
extern FUN_00582e30* DAT_011c3f44;
// Clears the global worldspace pointer if it is this object, then releases terrain, cell and land maps and other owned resources.
// @fnv 0x00582e30
FUN_00582e30::~FUN_00582e30()
{
    if (DAT_011c3f44 == this)
        DAT_011c3f44 = 0;
    ClearAllLists();
    DestroyMapEntries();
    if (terrain)
    {
        terrain->FUN_006fca70();
        delete terrain;
        terrain = 0;
    }
    FUN_00583180();
    FUN_005877e0();
    delete cellMap;
    cellMap = 0;
    delete landMap;
    landMap = 0;
    FUN_00588c80();
}

struct WorldRecordFile : TESFile
{
    unsigned int FUN_004726b0();
    void FUN_00472890(void*, unsigned int);
    bool FUN_00401680();
    bool FUN_00471c20();
    bool FUN_004726f0();
};
struct BoundsPoint
{
    float x, y;
    BoundsPoint();
};
struct BoundsOffsetData
{
    unsigned int cellOffsets;
    BoundsPoint minimum, maximum;
    unsigned int fileOffset;
};
void BSEndian(float*, EndianSizeTag<4>);
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
struct WorldBounds
{
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
    float minX, minY, maxX, maxY;
    BoundsOffsetData* GetOrCreateCellOffsetData(WorldRecordFile*);
    bool FUN_00583360(WorldRecordFile*);
};

struct SaveForm
{
    unsigned int GetFormID();
    void Save();
};
struct SaveFullName
{
    unsigned int unk00, unk04, unk08;
    void FUN_00487010();
};
struct SaveTexture
{
    unsigned int unk00, unk04, unk08;
    void FUN_0048e370(unsigned int);
};
struct SaveMap
{
    unsigned int unk00, unk04, unk08, unk0c;
    void FUN_005840b0();
};
struct SaveOffset
{
    unsigned int unk00, unk04, unk08;
    void FUN_005a6b10();
};
struct SaveGameString
{
    unsigned int unk00, unk04, unk08;
    int FUN_0048cee0();
    int* FUN_00408da0();
};
struct SavePair
{
    float land, water;
    void FUN_00462230();
};
bool FUN_00401500();
void FUN_00485910(unsigned int, unsigned int);
void _FUN_00485910(unsigned int, float);
void FUN_00485950(unsigned int, unsigned int);
void AppendChunk(unsigned int, void*, unsigned int);
void FUN_004858f0(unsigned int, unsigned char);
void FUN_00485710(unsigned int, unsigned int*, unsigned int);
void FUN_004856f0(unsigned int, void*, unsigned int);
struct SaveWorld
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14;
    SaveFullName fullName;
    SaveTexture texture;
    unsigned int unk30, unk34, unk38, unk3c, unk40, unk44;
    SaveForm* extra;
    unsigned char flags, unk4d;
    unsigned short parentFlags;
    unsigned int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    SaveForm* parent;
    unsigned int unk74, unk78, unk7c;
    SaveMap map;
    SaveOffset offset;
    unsigned int unk9c;
    unsigned int minimumX, minimumY, maximumX, maximumY;
    unsigned int unkb0, unkb4, unkb8, unkbc, unkc0, unkc4;
    float landHeight, waterHeight;
    SaveForm* encounterZone;
    SaveGameString canopy, waterNoise;
    void FUN_004855a0();
    void FUN_00485680();
    bool FUN_00586340(int);
    SaveForm* FUN_00585fe0();
    SaveForm* FUN_00586070();
    SaveForm* FUN_005860c0();
    float FUN_0045cd80();
    SaveForm* FUN_008041a0();
    SaveForm* FUN_00586150();
    void FUN_00584170();
};

extern "C" void* _FNV_DynamicCast(void*, int, const void*, const void*, int);
extern char _FNV_RTTI_TESForm;
extern char _FNV_RTTI_TESWorldSpace;
void* __cdecl memcpy(void*, const void*, unsigned int);
struct FUN_0058efd0
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
    FUN_0058efd0();
    ~FUN_0058efd0();
    void CopyFrom(FUN_0058efd0*);
};
struct CopyMap
{
    void RemoveAll();
    void* GetFirstPos();
    void GetNext(void*&, unsigned int&, unsigned int&);
    void SetAt(unsigned int, unsigned int);
};
struct CopyArray
{
    virtual void Destroy();
    virtual void Clear();
    virtual void CopyFrom(const CopyArray&);
    unsigned int count, capacity;
};
struct WorldCopy
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
    CopyMap* cells;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    TESClimate* climate;
    void* imageSpace;
    FUN_0058efd0* data;
    unsigned char flags;
    unsigned char unk4d;
    unsigned short parentFlags;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    TESWorldSpace* parent;
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
    float landHeight;
    float waterHeight;
    unsigned int unkd0;
    CopyArray arrayD4;
    CopyArray arrayE0;

    void FUN_00584fa0(TESForm*);
    void CopyBase(TESForm*);
    TESClimate* GetWorldClimate();
    void* GetImageSpace();
    TESWaterForm* GetWater();
    TESWaterForm* GetLODWater();
    void SetWater(TESWaterForm*);
    void SetLODWater(TESWaterForm*);
    float GetHeight();
    void SetHeight(float);
    int GetMusic();
    void SetMusic(int);
};

struct DataFile
{
    DataFile* FUN_004739b0();
    bool FUN_004723a0(unsigned int);
    unsigned int FUN_00472660();
    unsigned int FUN_004726b0();
    unsigned int GetField25C();
    bool FUN_00472890(void*, unsigned int);
};
struct CellOffsetData
{
    unsigned int* offsets;
    float minX, minY, maxX, maxY;
    unsigned int baseOffset;
};
void* FUN_00401000(unsigned int);
void FUN_00401030(void*);
void FUN_00403d30(void*, int, unsigned int);
int FUN_00404dc0(const char*, const char*);
struct WorldData
{
    unsigned int GetSourceFileCount();
    DataFile* FUN_00484e60(unsigned int);
    CellOffsetData* FUN_00588a90(DataFile*);
    int FUN_00584530(DataFile*, int, int);
    bool FindCellByEditorID(const char*, int*, int*);
};

struct AutoMemHelper
{
    int previousContext;
    AutoMemHelper(int, bool, const char*, int);
    ~AutoMemHelper();
};
extern const char DAT_01031f18[];
extern const char DAT_01031ec0[];
struct CellOperations
{
    virtual void virtual0();
    virtual void virtual1();
    virtual void virtual2();
    virtual void virtual3();
    virtual void virtual4();
    virtual void virtual5();
    virtual void virtual6();
    virtual void virtual7();
    virtual void virtual8();
    virtual void virtual9();
    virtual void virtual10();
    virtual void virtual11();
    virtual void virtual12();
    virtual void virtual13();
    virtual void virtual14();
    virtual void virtual15();
    virtual void virtual16();
    virtual void virtual17();
    virtual void virtual18();
    virtual void virtual19();
    virtual void virtual20();
    virtual void virtual21();
    virtual void virtual22();
    virtual void virtual23();
    virtual void virtual24();
    virtual void virtual25();
    virtual void virtual26();
    virtual void virtual27();
    virtual void virtual28();
    virtual void virtual29();
    virtual void virtual30();
    virtual void virtual31();
    virtual void virtual32();
    virtual void virtual33();
    virtual void FinishLoad();
    virtual void virtual35();
    virtual void virtual36();
    virtual void virtual37();
    virtual void virtual38();
    virtual void virtual39();
    virtual void virtual40();
    virtual void virtual41();
    virtual void virtual42();
    virtual void virtual43();
    virtual void virtual44();
    virtual void virtual45();
    virtual void virtual46();
    virtual void virtual47();
    virtual void virtual48();
    virtual void virtual49();
    virtual void virtual50();
    virtual void virtual51();
    virtual void virtual52();
    virtual void virtual53();
    virtual void virtual54();
    virtual void virtual55();
    virtual void virtual56();
    virtual void virtual57();
    virtual void virtual58();
    virtual void virtual59();
    virtual void virtual60();
    virtual void virtual61();
    virtual void virtual62();
    virtual void virtual63();
    virtual void virtual64();
    virtual void virtual65();
    virtual void virtual66();
    virtual void virtual67();
    virtual void virtual68();
    virtual void virtual69();
    virtual void virtual70();
    virtual void virtual71();
    virtual void virtual72();
    virtual void virtual73();
    virtual void SetWorldData(void*, bool);
    bool FUN_00551420();
    void FUN_00544300(bool);
    void ResetCellData();
    void SetExteriorCellCoordinates(int, int);
    bool FUN_00550500(FileReader*);
    void FUN_00551440(bool);
};
struct SaveLoadOperations
{
    void* RemoveCommand(unsigned int, int, int);
    bool FUN_0047c850();
    void FUN_004534f0(bool);
};
extern SaveLoadOperations* DAT_011de45c;
extern TESWorldSpace* DAT_011c3f34;
bool __cdecl FUN_004601d0(CellOperations*, FileReader*);
struct WorldCellLoader
{
    virtual void virtual0();
    virtual void virtual1();
    virtual void virtual2();
    virtual void virtual3();
    virtual void virtual4();
    virtual void virtual5();
    virtual void virtual6();
    virtual void virtual7();
    virtual void virtual8();
    virtual void virtual9();
    virtual void virtual10();
    virtual void virtual11();
    virtual void virtual12();
    virtual void virtual13();
    virtual void virtual14();
    virtual void virtual15();
    virtual void virtual16();
    virtual void virtual17();
    virtual void virtual18();
    virtual void virtual19();
    virtual void virtual20();
    virtual void virtual21();
    virtual void virtual22();
    virtual void virtual23();
    virtual void virtual24();
    virtual void virtual25();
    virtual void virtual26();
    virtual void virtual27();
    virtual void virtual28();
    virtual void virtual29();
    virtual void virtual30();
    virtual void virtual31();
    virtual void virtual32();
    virtual void virtual33();
    virtual void virtual34();
    virtual void virtual35();
    virtual void virtual36();
    virtual void virtual37();
    virtual void virtual38();
    virtual void virtual39();
    virtual void virtual40();
    virtual void virtual41();
    virtual void virtual42();
    virtual void virtual43();
    virtual void virtual44();
    virtual void virtual45();
    virtual void virtual46();
    virtual void virtual47();
    virtual void virtual48();
    virtual void virtual49();
    virtual void virtual50();
    virtual void virtual51();
    virtual void virtual52();
    virtual void virtual53();
    virtual void virtual54();
    virtual void virtual55();
    virtual void virtual56();
    virtual void virtual57();
    virtual void virtual58();
    virtual void virtual59();
    virtual void virtual60();
    virtual void virtual61();
    virtual void virtual62();
    virtual void virtual63();
    virtual void virtual64();
    virtual void virtual65();
    virtual void virtual66();
    virtual void virtual67();
    virtual void virtual68();
    virtual void virtual69();
    virtual void virtual70();
    virtual void virtual71();
    virtual void virtual72();
    virtual void virtual73();
    virtual void virtual74();
    virtual void virtual75();
    virtual const char* GetWorldName();
    CellOperations* FUN_005875a0(int, int);
    unsigned int GetSourceFileCount();
    FileReader* FUN_00484e60(unsigned int);
    bool SeekToCellInWorld(FileReader*, int, int);
    void FUN_00587670(CellOperations*);
    unsigned int FUN_0084e3a0();
    void AddCellReferences(CellOperations*);
    CellOperations* FUN_00585b30(int x, int y);
};
struct ThreadFile
{
    FileReader* FUN_004739b0();
};

struct FUN_00585ee0_shell : public TESWorldSpace
{
    bool FindParentFile(int a1, int a2, unsigned int* a3, unsigned int* a4);
    int GetFileCount();
    TESFile* GetFileForm(int aIndex);
};

struct FileX
{
    TESFile* GetParentFile();
    unsigned int GetOff();
};

struct WorldX
{
    bool ReadWorldData(TESFile* apFile, int a1, int a2);
};

bool __cdecl LoadedCheck(TESFile* apFile);

struct GlobalObject_006815c0
{
    GlobalObject_006815c0();
    float x, y, z;
};
typedef GlobalObject_006815c0 Point;
struct RegionForm
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
    virtual unsigned char Weight();
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
    virtual float Value108();
    virtual void v109();
    virtual float Value110();
    virtual void v111();
    virtual float Value112();
    virtual void v113();
    virtual float Value114();
    virtual void v115();
    virtual unsigned char Value116();
    virtual void v117();
    virtual unsigned char Value118();
    virtual void v119();
    virtual unsigned char Value120();
    const char* FUN_0050a550();
    unsigned int FUN_0084e3a0();
};
struct Region
{
    virtual void v0();
    virtual RegionForm* Form();
    virtual void v2();
    virtual int Priority();
    virtual void v4();
    virtual void v5();
    virtual float Weight(Point const&, TESWorldSpace*, bool);
};
struct Entry
{
    Region* region;
    float weight;
};
struct RegionNode
{
    Region* item;
    RegionNode* next;
    Region** FUN_006815c0();
    RegionNode* FUN_00726070();
};
struct Head
{
    int unk00;
};
struct RegionData : Head, RegionNode
{
};
struct Selection
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Selection* Select(void*);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual RegionData* GetList();
};
struct CellRegions
{
    void* FUN_004f6800(int, Point const&, TESWorldSpace*);
};
struct CellProxyNew
{
    CellRegions* GetRegionList(bool);
};
struct Handler
{
    CellProxyNew* FUN_00461bc0(float, float, TESWorldSpace*, bool);
    Selection* GetRegionDataManager();
};
struct GlobalObject_0096a2d0
{
    GlobalObject_0096a2d0();
    Entry* item;
    GlobalObject_0096a2d0* next;
    Entry** FUN_006815c0();
    GlobalObject_0096a2d0* FUN_00726070();
    bool FUN_008256d0();
    void FUN_005ae3d0(Entry*&);
    void FUN_00470470();
};
struct RegionResult
{
    char* name;
    unsigned int formID;
    float a, b, c, time, d;
    unsigned char e, f, g, unk1f;
    float samples[9];
};
int __cdecl FUN_00406d00(char*, int, const char*, ...);
float __cdecl FUN_0053ca40();
struct World : TESWorldSpace
{
    void BuildRegionResults(float, float, float, float, RegionResult*, unsigned);
};

struct WsNameList
{
    const char* item;
    WsNameList* next;
    WsNameList();
};

struct WsListNode
{
    TESWorldSpace** Item();
    WsListNode* GetNext();
};

struct WsDataHandler
{
    WsListNode* GetWorldSpaces();
};

struct FUN_005883c0_shell : public TESWorldSpace
{
    void AddMapNames(WsNameList* apList);
    WsNameList* BuildMapNameList(bool abNoChildren);
};

extern const double DAT_010231b0;
struct CELL_SHELL : public TESObjectCELL
{
    bool FUN_0054da20(const NiPoint3* point, float distance, const NiPoint3* otherPoint, float otherDistance,
                      int options, unsigned int context);
    float FUN_0054fb70(const NiPoint3* point);
};
struct WORLD_SHELL : public TESWorldSpace
{
    CELL_SHELL* FUN_005875a0(int, int);
    void ProcessCellsInRadius(const NiPoint3* point, float distance, const NiPoint3* otherPoint, float otherDistance,
                              int options, unsigned int context);
};

struct QueryPoint2
{
    float x, y;
    QueryPoint2(float x, float y);
};
struct WorldQuery;
struct AreaQuery
{
    bool FUN_004f8360(const QueryPoint2* point);
};
struct CellQuery;
template <class T> struct QueryLink
{
    T* item;
    QueryLink* next;
    T** FUN_006815c0();
    QueryLink* FUN_00726070();
};
struct QueryNodeHeader
{
    unsigned int unk00;
};
struct CellQueryNode : QueryNodeHeader, QueryLink<CellQuery>
{
};
struct QueryData
{
    CellQueryNode* FUN_004169d0();
};
extern QueryData* g_011c3f2c;
struct CellQuery
{
    bool FUN_00549580();
    bool FUN_00440d80();
    WorldQuery* FUN_007af430();
    QueryLink<AreaQuery>* FUN_00441110();
};
struct WorldQuery
{
    bool IsFlag8Set();
    bool ContainsPoint(const NiPoint3* position);
};

namespace fnv_00583560 {
extern "C" void* _alloca(unsigned int);
void* operator new(unsigned int);
void operator delete(void*);
class File583
{
  public:
    int FUN_00472660();
    bool FUN_00471c20();
    unsigned int GetOffset();
    int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool ReadChunkInt(void*);
    bool ReadChunkData(unsigned short*);
    bool FUN_00401680();
    bool GetNextChunk();
};
struct B006815c0
{
    float x, y;
    B006815c0();
};
struct OffsetData583
{
    unsigned int* offsets;
    B006815c0 minimum, maximum;
    unsigned int offset;
};
struct Pair583
{
    float x, y;
    void FUN_00462230();
};
struct MapData583
{
    float x, y, z, w;
    void FUN_005840b0();
};
struct Extra583
{
    unsigned int x, y, z;
    void FUN_005a6b10();
};
struct Full583
{
    unsigned int a, b, c;
};
struct Icon583
{
    unsigned int a, b, c;
};
void FUN_0048e3d0(Icon583*, File583*);
void ReadFullName(Full583*, File583*);
void FUN_00401080(void*, bool);
float FUN_0040ebd0(float, float);
float FUN_00404010(float, float);
class FUN_0058efd0
{
  public:
    unsigned int unk000;
    unsigned int unk004;
    unsigned int unk008;
    unsigned int unk00C;
    unsigned int unk010;
    unsigned int unk014;
    unsigned int unk018;
    unsigned int unk01C;
    unsigned int unk020;
    unsigned int unk024;
    unsigned int unk028;
    unsigned int unk02C;
    unsigned int unk030;
    unsigned int unk034;
    unsigned int unk038;
    unsigned int unk03C;
    unsigned int unk040;
    unsigned int unk044;
    unsigned int unk048;
    unsigned int unk04C;
    unsigned int unk050;
    unsigned int unk054;
    unsigned int unk058;
    unsigned int unk05C;
    unsigned int unk060;
    unsigned int unk064;
    unsigned int unk068;
    unsigned int unk06C;
    unsigned int unk070;
    unsigned int unk074;
    unsigned int unk078;
    unsigned int unk07C;
    unsigned int unk080;
    unsigned int unk084;
    unsigned int unk088;
    unsigned int unk08C;
    unsigned int unk090;
    unsigned int unk094;
    unsigned int unk098;
    unsigned int unk09C;
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned int unk0A8;
    unsigned int unk0AC;
    unsigned int unk0B0;
    unsigned int unk0B4;
    unsigned int unk0B8;
    unsigned int unk0BC;
    unsigned int unk0C0;
    unsigned int unk0C4;
    unsigned int unk0C8;
    unsigned int unk0CC;
    unsigned int unk0D0;
    unsigned int unk0D4;
    unsigned int unk0D8;
    unsigned int unk0DC;
    unsigned int unk0E0;
    unsigned int unk0E4;
    unsigned int unk0E8;
    unsigned int unk0EC;
    unsigned int unk0F0;
    unsigned int unk0F4;
    unsigned int unk0F8;
    unsigned int unk0FC;
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
    FUN_0058efd0();
    void FUN_0058f180(File583*);
};
class FUN_00589000
{
  public:
    virtual ~FUN_00589000();
    unsigned int a, b, c;
    FUN_00589000(unsigned int);
    unsigned int FUN_0084e3a0();
};
class Name583
{
  public:
    unsigned int a, b, c;
    void SetFullName(const char*);
};
class Base583
{
  public:
    virtual void virtual000();
    virtual void virtual004();
    virtual void virtual008();
    virtual void virtual00C();
    virtual void virtual010();
    virtual void virtual014();
    virtual void virtual018();
    virtual void virtual01C();
    virtual void virtual020();
    virtual void virtual024();
    virtual void virtual028();
    virtual void virtual02C();
    virtual void virtual030();
    virtual void virtual034();
    virtual void virtual038();
    virtual void virtual03C();
    virtual void virtual040();
    virtual void virtual044();
    virtual void virtual048();
    virtual void virtual04C();
    virtual void virtual050();
    virtual void virtual054();
    virtual void virtual058();
    virtual void virtual05C();
    virtual void virtual060();
    virtual void virtual064();
    virtual void virtual068();
    virtual void virtual06C();
    virtual void virtual070();
    virtual void virtual074();
    virtual void virtual078();
    virtual void virtual07C();
    virtual void virtual080();
    virtual void virtual084();
    virtual void virtual088();
    virtual void virtual08C();
    virtual void virtual090();
    virtual void virtual094();
    virtual void virtual098();
    virtual void virtual09C();
    virtual void virtual0A0();
    virtual void virtual0A4();
    virtual void virtual0A8();
    virtual void virtual0AC();
    virtual void virtual0B0();
    virtual void virtual0B4();
    virtual void virtual0B8();
    virtual void virtual0BC();
    virtual void virtual0C0();
    virtual void virtual0C4();
    virtual void virtual0C8();
    virtual void virtual0CC();
    virtual void virtual0D0();
    virtual void virtual0D4();
    virtual void virtual0D8();
    virtual void virtual0DC();
    virtual void LoadBounds(File583*);
    virtual void virtual0E4();
    virtual void virtual0E8();
    virtual void virtual0EC();
    virtual void virtual0F0();
    virtual void virtual0F4();
    virtual void virtual0F8();
    virtual void virtual0FC();
    virtual void virtual100();
    virtual void virtual104();
    virtual void virtual108();
    virtual void virtual10C();
    virtual void virtual110();
    virtual void virtual114();
    virtual void virtual118();
    virtual void virtual11C();
    virtual void virtual120();
    virtual void virtual124();
    virtual void virtual128();
    virtual void virtual12C();
    virtual void virtual130();
    virtual void SetEditorID(char*);
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
};
class World583 : public Base583, public Full583, public Icon583
{
  public:
    FUN_00589000* cellMap;
    unsigned int unk34, unk38, unk3C, unk40, unk44;
    FUN_0058efd0* imageSpace;
    unsigned char flags4C, unk4D;
    unsigned short field4E;
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
    MapData583 mapData;
    Extra583 extra;
    unsigned int unk9C;
    float minX, minY, maxX, maxY;
    unsigned int unkB0, unkB4, unkB8, unkBC, unkC0, unkC4;
    float fC8, fCC;
    unsigned int fieldD0;
    Name583 nameD4, nameE0;
    OffsetData583* GetOrCreateCellOffsetData(File583*);
    void LoadRecordHeader(File583*);
    void FUN_00484ab0(int);
    void FUN_0087ce80(unsigned int);
    void FUN_008d8040(unsigned int);
    void FUN_004febb0(unsigned int);
    void FUN_00442a80(unsigned int);
    void FUN_00584150(float);
    void SetParent(unsigned int);
    void SetAssociatedActorValue(unsigned int);
    bool GetSmallWorld();
    bool FUN_00484e40();
    bool FUN_00583560(File583*);
};

struct EndianFlag583
{
    bool value;
};
}  // namespace fnv_00583560

namespace fnv_005878d0 {
class Pt
{
  public:
    float x;
    float y;
    float z;
    float Length() const;
};
class StrList
{
  public:
    int a;
    int b;
    StrList();
};
class DummyPointerMap
{
  public:
    int a;
    int b;
    int c;
    int d;
    DummyPointerMap(int);
    bool GetAt(unsigned int, int&) const;
    void SetAt(unsigned int, unsigned int);
};
class SetAtHelper
{
  public:
    void FUN_005ae3d0(void**);
};
class RefObj
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
    virtual void v116();
    virtual void v117();
    virtual void v118();
    virtual void v119();
    virtual void v120();
    virtual void v121();
    virtual void v122();
    virtual void v123();
    virtual void v124();
    virtual Pt* v125();
    bool FUN_00439f90();
    Pt* FUN_00569880();
};
bool BoundIntersectsCell(RefObj*, int, int);
int TruncateFloatToInt(float);
class WorldObj
{
  public:
    char pad68[0x68];
    DummyPointerMap* map;
    void FUN_005878d0(RefObj*);
};

}  // namespace fnv_005878d0

struct String65
{
    char* text;
    unsigned short length, capacity;
    String65();
    ~String65();
    bool Set(const char*, unsigned = 0);
    operator const char*() const;
    unsigned Length();
    int StrCmp(const char*, bool = true) const;
};
struct Pos65
{
    float x, y, z;
    Pos65();
    bool FUN_004390c0(const Pos65&);
};
struct Point65
{
    float x, y;
    Point65(const Pos65&);
};
struct Area65
{
    bool FUN_004f8360(const Point65&);
};
struct AreaList65
{
    Area65** FUN_006815c0();
    AreaList65* FUN_00726070();
    bool FUN_008256d0();
    void* FUN_004f6800(int, const Pos65&, void*);
};
struct Data65
{
    bool FUN_004f1540();
    unsigned char FUN_005bb4d0();
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
    virtual void v28(String65*);
};
struct Manager65
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual Data65* v10(void*);
};
struct Region65
{
    bool FUN_00440d80();
    void* FUN_007af430();
    AreaList65* FUN_00441110();
    void* FUN_009611e0();
};
struct RegionNode65
{
    Region65** FUN_006815c0();
    RegionNode65* FUN_00726070();
};
struct RegionPrefix65
{
    int unk00;
};
struct RegionHead65 : RegionPrefix65, RegionNode65
{
};
struct Type65
{
    void* FUN_004f35b0(int);
};
struct Cell65
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    FNStub fullName;
    AreaList65* FUN_00547110(bool);
};
struct Handler65
{
    Cell65* FUN_00461bc0(float, float, void*, bool);
    Manager65* GetRegionDataManager();
    RegionHead65* FUN_004169d0();
};
struct World65
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    FNStub fullName;
    bool FUN_00586500(String65*, Pos65);
};

struct WorldSpaceRefShell : public TESWorldSpace
{
    void FUN_00587d10(TESObjectREFR*);
};

struct ATM_587D10
{
    void QueryPerformanceCounter(int);
    void WaitForTasksDuringRendering();
};
struct Pt3_587D10
{
    float x, y, z;
};
struct RefV_587D10
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
    virtual Pt3_587D10* GetPos();
};
namespace WsH_587D10 {
int __cdecl GetKeyForWorldCoord(Pt3_587D10 const&);
}
bool __cdecl FUN_00587c80(void*);
struct RefList_587D10
{
    int a;
    int b;
    void AddHead(int*);
};
struct RefListNode_587D10 : RefList_587D10
{
    RefListNode_587D10();
};
struct SetAt_587D10
{
    void SetAt(unsigned int, unsigned int);
};
struct PtrMap_587D10
{
    bool GetAt(unsigned int, unsigned int&);
};

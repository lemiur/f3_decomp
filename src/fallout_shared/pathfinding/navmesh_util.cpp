// fallout_shared/pathfinding/navmesh_util.cpp: NavMesh, std, CircularArc, ASC and more (1 function)
#include "f3_common.h"
#include "navmesh_util_decls.h"

void __fastcall FUN_004a3d40(void* pThis);
void __fastcall FUN_004a3d80(void* pThis);

struct FUN_005eeda0_this
{
    int pad0;
    unsigned short* pBuffer;
    unsigned short& GetBufferEntry(unsigned int aiIndex);
};

extern int DAT_010159d4;

struct Dummy0042f800
{
    void FUN_0042fcb0(int, int);
};

struct FUN_006969e0_shell : public NavMesh
{
    bool FUN_006969e0(NiPoint3*, NiPoint3*);
};

struct DummyA8
{
    void GetVectors(NiPoint3*, NiPoint3*);
};

struct V3
{
    float x, y, z;
};
struct FUN_00698580_S
{
    V3 a;
    V3 b;
    FUN_00698580_S* FUN_00698580(const V3* p, const V3* q);
};

void __stdcall compiler_vector_constructor_iterator(void*, unsigned int, int, void*);
void FUN_006d5320();

struct FUN_006985f0_shell : public SineCosine
{
    SineCosine* CopyFloatPair(void*);
};

struct ASC
{
    float s, c;
    void _ref_006815c0();
    ASC& operator=(const ASC&);
    ASC* Multiply(ASC* out, const ASC* o);
};

struct Sub
{
    int z[4];
    Sub();
    ~Sub();
};
struct FUN_00699450_S
{
    Sub a;
    Sub b;
    FUN_00699450_S();
};

struct FUN_0069af60
{
    int pad[4];
    ~FUN_0069af60();
};

struct FUN_006994b0
{
    FUN_0069af60 a;
    FUN_0069af60 b;
    ~FUN_006994b0();
};

struct Dummy_0069a660
{
    int a;
    short b;
    Dummy_0069a660* SetValues(int p1, short p2);
};

struct FUN_0069a6c0_S
{
    void* nav;
    unsigned short tri;
    int edge;
    void _ref_006815c0();
    FUN_0069a6c0_S* FUN_0069a6c0(void* n, unsigned short t, int e);
};

struct FUN_0069a700_shell : public NavMeshTriangleHandle
{
    void FUN_0069a700(void*);
};

extern int DAT_0106b1b8;

struct Dummy_0069af30
{
    void* vtable;
    void ResetAndWrite(int, int);
};

extern int DAT_0106b1b8;

class GlobalObject_00869f00
{
  public:
    void Clear(bool);
};

struct VH
{
    int a[2];
    void TwoIntRecord(const VH&);
};
struct FUN_0069b030_S
{
    int pad;
    VH* data;
    unsigned int FUN_00845460();
    void ConstructPairCells(VH*, int);
    unsigned int Append(const VH* v);
};

struct EH
{
    char b[12];
    EH& operator=(const EH&);
};
struct FUN_0069b310_S
{
    int pad;
    EH* data;
    unsigned int FUN_00978bc0();
    void ConstructBounds(EH*, int);
    unsigned int AppendElement(const EH* v);
};

float __cdecl cos(float);
float __cdecl FUN_004e44b0(float);

struct FUN_006a04e0_helper : public SineCosine
{
    void* SetFromAngle(float afAngle);
};

struct FUN_006bc870_shell : public NavMeshEdgeData
{
    NavMeshEdgeData* CopyFromNavMeshEdge(void*);
};

struct NiP2
{
    float x, y;
    NiP2();
};
struct USW
{
    unsigned short v;
};
struct IW
{
    int v;
};
bool __cdecl FUN_006b9e90(NiP2*, NiP2*, int, int, int);

struct S0069a690
{
    int a;
    unsigned short b;
    S0069a690* FUN_0069a690(const S0069a690* o);
};

extern unsigned int _data_011c16bc;
struct B006815c0
{
    char p[8];
    B006815c0();
};
struct FUN_0069b2c0
{
    char p[0x10];
    FUN_0069b2c0();
    ~FUN_0069b2c0();
};
struct FUN_0069a730 : public B006815c0
{
    FUN_0069b2c0 a;
    FUN_0069b2c0 b;
    FUN_0069a730();
};

struct IT
{
    IT* next;
    TwoIntRecord key;
    void* val;
};
struct MP
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(TwoIntRecord);
    virtual bool IsKeyEqual(TwoIntRecord, TwoIntRecord);
    virtual void SetValue(IT*, TwoIntRecord, void*);
    virtual void v4();
    virtual IT* NewItem();
    unsigned int cnt;
    IT** table;
    unsigned int count;
};
struct VW
{
    void* p;
};

namespace fnv_0069b4d0 {
struct IT
{
    IT* next;
    TwoIntRecord key;
    void* val;
};
struct MP
{
    virtual void v0();
    virtual unsigned int KeyToHashIndex(TwoIntRecord);
    virtual bool IsKeyEqual(TwoIntRecord, TwoIntRecord);
    unsigned int cnt;
    IT** table;
};
struct VW
{
    void** p;
};
}  // namespace fnv_0069b4d0

void __cdecl Deallocate(void*);
namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* FUN_0069a7a0(unsigned int flags);
};
}

struct NiPoint3Ex : public NiPoint3
{
    NiPoint3Ex(float afX, float afY, float afZ);
    NiPoint3 operator+(const NiPoint3& arPt) const;
};

struct ObstacleDataEx : public ObstacleData
{
    NiPoint3Ex WorldMin;
    NiPoint3Ex WorldMax;
};

struct ObstacleDataPtr
{
    ObstacleDataEx* object;
    ObstacleDataEx* operator->() const;
};

bool __cdecl AreWideCharsEqual(const unsigned short& a, const unsigned short& b);

struct NavMeshTriList : public BSSimpleArray<unsigned short>
{
    unsigned int GetSize() const;
    const unsigned short& FUN_0069dec0(unsigned int auiIndex) const;
    int FindMatchingIndex(const unsigned short& arItem, unsigned int auiStart,
                          bool(__cdecl* apCompare)(const unsigned short&, const unsigned short&));
};

struct NavMeshGrid
{
    void GetCellCoords(const NiPoint3& arPos, unsigned int& arRow, unsigned int& arCol);
    NavMeshTriList* FUN_006967c0(unsigned int auiCol, unsigned int auiRow);
};

struct NavMeshTriangleEx : public NavMeshTriangle
{
    bool GetFlag(int aiFlag);
};

float __cdecl FUN_0040ebd0(float a, float b);
float __cdecl FUN_00404010(float a, float b);
NiPoint3 __cdecl FUN_004b3ae0(const NiPoint3& arPt, const float* apRot);
bool __cdecl DoBoundsOverlap(const NiPoint3& a, const NiPoint3& b, const NiPoint3& c, const NiPoint3& d);
bool __cdecl FUN_006c3570(const NiPoint3& arCenter, const ObstacleDataPtr& arObstacle, float afHeight, float afFudge);
bool __cdecl FUN_00696540(const NiPoint3& a, const NiPoint3& b, const NiPoint3& c, const NiPoint3& d);
extern const float DAT_01015f5c;

struct NavMeshOverlap : public NavMesh
{
    NavMeshGrid Grid;
    NiPoint3 GetNavMeshData(unsigned short ausTriangle);
    void FUN_006987d0(const ObstacleDataPtr& apObstacle, const NiPoint3& afFudge, NavMeshTriList* apRetTriangles);
};

struct NavMeshVertexEdgeData;

struct VertMapItem
{
    VertMapItem* m_pkNext;
    TwoIntRecord m_key;
    NavMeshVertexEdgeData* m_val;
};

struct VertMap
{
    virtual unsigned int GetPad();
    virtual unsigned int KeyToHashIndex(TwoIntRecord key) const;
    unsigned int m_uiHashSize;
    VertMapItem** m_ppkHashTable;
    void GetNextEntry(void*& pos, TwoIntRecord& key, NavMeshVertexEdgeData*& val) const;
};

struct FUN_0069b120_stub
{
    void FUN_0069b120(int a, int b);
};

struct FUN_00699590_shell
{
    void ForwardToStub(int arg);
};

struct Flt
{
    operator unsigned int() const;
};

struct Arr
{
    Flt* GetAt(int);
};

struct FUN_00699630_shell
{
    int FindEntryIndex(int);
    Arr arr;
    int FUN_00699630(int param1, unsigned int* out);
};

struct FUN_00699790_shell
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    unsigned int m_iFourthElementInteger;  // offset 0xc
    int GetBits13To15();
};

struct FUN_0069af80_shell
{
    void* __thiscall FUN_0069af80(int count);
};

struct FUN_00699b60_shell : public NavMesh
{
    void BuildPortalPOVs();
};

namespace std {
float __cdecl abs(float);
}

extern double _gModifierZero;

struct NiPoint2
{
    float x;
    float y;
    NiPoint2(float fx, float fy);
};

extern "C" void __cdecl FUN_006ba010(const NiPoint2& a, const NiPoint2& b, const NiPoint2& c, const NiPoint2& d);

struct FUN_006967c0_shell
{
    int f0;
    char pad[32];
    int f24;
    int FUN_006967c0(int a, int b);
};

struct Vec00696a10
{
    int v0;
    int v1;
    int v2;
};
struct Obj00696a10
{
    char pad[12];
    Vec00696a10 m1;
    Vec00696a10 m2;
    void GetVectors(Vec00696a10*, Vec00696a10*);
};

struct Holder
{
    void FUN_004a3c90(Holder*);
    Holder* FUN_00696ca0(Holder*);
};

struct FindTriangleForLocationFilter;
struct FUN_00697670_StandIn : NavMesh
{
    unsigned short FindTriangleForLocation(const NiPoint3&, FindTriangleForLocationFilter*);
    bool IsLocationOnNavMesh(const NiPoint3&, FindTriangleForLocationFilter*);
};

struct Dummy698030
{
    int _p[3];
    unsigned int f12;
    unsigned int FUN_00698030(unsigned short a1);
};

struct FUN_00698300_shell
{
    void _ref_006815c0();
    FUN_00698300_shell* FUN_00698300();
};

namespace fnv_00698fc0 {
struct FUN_00699630_shell
{
    int FUN_00699630(int, unsigned int*);
};
struct FUN_00698fc0_shell : public FUN_00699630_shell
{
    bool UndoToPosition(int, int);
    bool FUN_00698fc0(int, int);
};
}  // namespace fnv_00698fc0

struct S0069afb0
{
    int FUN_0069afb0(unsigned short, int);
};
struct S006997b0
{
    char _pad[0xE0];
    S0069afb0* p;
    int FUN_006997b0(unsigned short, int);
};
// @f3 0x005fd4e0 (community match, verified in this file)
extern "C" int DAT_00dc4dc0;

struct S_5fcac0
{
    void FUN_005fcac0(unsigned short, int, int);
};

int S006997b0::FUN_006997b0(unsigned short a, int b)
{
    *(void**)this = (void*)&DAT_00dc4dc0;
    ((S_5fcac0*)this)->FUN_005fcac0(a, b, 0);
    return (int)this;
}


struct ArrSI
{
    unsigned int GetFlags();
};
struct ActorAvoidanceDataArray
{
    void FUN_00983720(unsigned int, unsigned int);
};
struct BSXFlags_shell
{
    void ClearFlags(unsigned int);
};
struct S006950d0
{
    NavMeshClosedDoorInfo* GetElement(unsigned int);
};

struct FUN_00699a30_shell
{
    bool FUN_00699a30(unsigned int doorID);
};

struct FUN_0069b2f0
{
    int _d[4];
    ~FUN_0069b2f0();
};
struct FUN_0069a7d0
{
    int _pad[2];
    FUN_0069b2f0 m1;
    FUN_0069b2f0 m2;
    ~FUN_0069a7d0();
};

namespace fnv_0069a940 {
bool __cdecl AreWideCharsEqual(const unsigned short&, const unsigned short&);

struct NavMeshTriList
{
    int FindMatchingIndex(const unsigned short&, unsigned int,
                          bool(__cdecl*)(const unsigned short&, const unsigned short&));
};

struct GlobalObject_00869f00
{
    void Clear(bool);
    BSSimpleArray<unsigned short> m_kAdditionalIndexList;
};

struct FUN_0069a940_shell : NavMesh
{
    unsigned int FUN_0069a940(unsigned short, GlobalObject_00869f00*);
};

}  // namespace fnv_0069a940

class SoundPlaybackHandle;
template <> class NiTPointerMap<unsigned int, SoundPlaybackHandle*>
{
  public:
    bool IsEmpty();
};
struct FUN_0069b0a0_shell
{
    void LookupValue(unsigned short, unsigned int);
};
struct FUN_0069a9d0_shell : NavMesh
{
    void FUN_0069a9d0(unsigned short, unsigned int);
};

struct FUN_0069b240_Holder
{
    int field_0;
    unsigned short* field_4;
    unsigned int field_8;
    int FindMatchingIndex(int, unsigned int, bool(__cdecl*)(unsigned short*, int));
};

namespace fnv_006b39a0 {
struct EH
{
    int a;
    int b;
    int c;
    EH& operator=(EH const&);
};
struct C006b39a0
{
    C006b39a0& FUN_006b39a0(C006b39a0 const&);
};
}  // namespace fnv_006b39a0

struct BGSLoadGameBuffer;
struct BGSSaveGameBuffer;
struct FindTriangleForLocationFilter;
struct NavMeshPtr;
struct TESObjectCELL;
struct TESWorldSpace;
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
    NiPoint3 Location;
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
struct FUN_006dcee0_shell : public NavMesh
{
    bool FUN_006dcee0(void*, FindTriangleForLocationFilter*);
};

extern int DAT_0102583c;
struct Sub6815c0
{
    void _ref_006815c0();
};
struct FUN_006dcee0_t
{
    int* vfptr;
    Sub6815c0 s;
    FUN_006dcee0_t* FUN_006dcee0(void*, TESObjectCELL*, TESWorldSpace*);
};

struct S696500
{
    int m0;
    char _pad[32];
    BSSimpleArray<unsigned short, 1024>* m24;
    void FUN_00696500(unsigned short, int, int);
};

struct Sub0069d4b0
{
    void __thiscall FUN_0069d4b0(int a, int b, int c);
};
struct Obj00696c00
{
    char _pad[0xA8];
    Sub0069d4b0 sub;
    void __thiscall ForwardToSub(int a, int b, int c);
};

struct S50
{
    char _pad[0x50];
    int f50;
    void AssignFrom(S50* p);
    S50* FUN_00696c30(S50* p);
};

struct MidCopy
{
    char _pad[32];
    struct Inner
    {
        unsigned int d[8];
    } inner;
    unsigned int tail;
    MidCopy& FUN_00696ca0(const MidCopy&);
    MidCopy& AssignFrom(const MidCopy&);
};

extern void* DAT_0106b1f4;
void* __cdecl _NiMalloc(unsigned int);
void* __cdecl memset(void*, int, unsigned int);

struct FUN_0069b360_shell
{
    void* __thiscall ConstructBuffer(unsigned int a);
};

namespace fnv_00697810 {
struct B006815c0
{
    float x, y, z;
    B006815c0();
};
struct FUN_00697810_t;
struct NavCallback_00697810
{
    virtual bool Test(const NiPoint3&, NavMesh*, unsigned short, B006815c0&);
};
struct FUN_00697810_t : public NavMesh
{
    bool TestPointOnTriangle(unsigned short ausTri, const NiPoint3& arPoint, float& arZ,
                             NavCallback_00697810* apCallback);
};
}  // namespace fnv_00697810

struct FUN_00697980_t : public NavMesh
{
    bool GetTriangleHeightAtPoint(unsigned short ausTriangle, const NiPoint3& arPoint, float afAbove, float afBelow,
                                  float* apfZ);
};

extern double DAT_01011588;
namespace NavCircum {
struct NiPoint3
{
    float x, y, z;
    void Set(float, float, float);
};
}

struct FUN_00698320_t : public NavMesh
{
    int FindCrossedEdge(unsigned short, int, const NiPoint3*, const NiPoint3*);
};

namespace fnv_0069a830 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct DA00694f80
{
    unsigned short& GetAt(int);
};
struct FUN_0069b0a0_shell
{
    bool LookupValue(unsigned short, unsigned int);
};
namespace S {
struct NiTPointerMap
{
    bool IsEmpty();
};
}
struct GlobalObject_00869f00
{
    void Clear(bool);
};
struct FUN_0069a830_shell : NavMesh
{
    int CollectTrianglePOVs(unsigned short triangle, BSSimpleArray<unsigned short, 1024>* povs);
};

}  // namespace fnv_0069a830

struct Helper62d0
{
    void* operator=(const void*);
};

struct FUN_0069afb0_shell
{
    virtual void v0();
    virtual void* v1(unsigned short a);
    virtual bool v2(unsigned short a, unsigned short b);
    void* p;
    void** list;
    bool FUN_0069afb0(unsigned short a, Helper62d0& out);
};

namespace fnv_006be6f0 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct DA00694f80
{
    unsigned short& GetAt(int i);
};
struct NavMeshTriList
{
    int FindMatchingIndex(const unsigned short&, unsigned int,
                          bool(__cdecl*)(const unsigned short&, const unsigned short&));
    void FUN_0069add0(int, bool);
};
bool __cdecl AreWideCharsEqual(const unsigned short&, const unsigned short&);
struct FUN_006be6f0_shell
{
    void MarkNavMeshTriangles();
};
}  // namespace fnv_006be6f0

namespace fnv_00697590 {
class ArrSI
{
  public:
    unsigned int GetFlags(void);
};

struct _Mem_20a4
{
    void SetSize(unsigned int, bool);
};

struct HArr
{
    void GrowCapacity(unsigned int);
};

struct BSSimpleArrayActor
{
    unsigned int Add(void*&);
};

struct FUN_00690e10_shell
{
    bool FUN_00690e10(void);
};

struct FUN_00693d30_shell
{
    char* GetEdge(unsigned short);
};

struct FUN_00697590_shell
{
    bool CollectTrianglesForDoor(unsigned int, BSSimpleArrayActor*);
};

}  // namespace fnv_00697590

namespace fnv_006995c0 {
struct ArrSI
{
    unsigned int GetFlags();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct GO
{
    operator unsigned int() const;
};
struct NiPointerStandIn
{
    bool operator==(void*) const;
};

struct FUN_006995c0_shell
{
    int FindEntryIndex(void* arg);
};

}  // namespace fnv_006995c0

namespace fnv_006bbb80 {
extern int _data_011c16bc;

struct GO
{
    int value;

    GO(int);
    ~GO();
};

struct FUN_006bbc30
{
    int padding[4];

    FUN_006bbc30();
    ~FUN_006bbc30();

    int _ref_006815c0();
};

struct FUN_006bf7d0
{
    int padding[5];

    FUN_006bf7d0(int, int, int);
    ~FUN_006bf7d0();
};

struct FUN_006bfa10
{
    int padding[5];

    FUN_006bfa10(int, int, int);
};

struct FUN_006bbb80
{
    int base;
    GO go;
    int gap;
    FUN_006bbc30 memberC;
    FUN_006bf7d0 member1C;
    FUN_006bfa10 member30;

    FUN_006bbb80();
};

}  // namespace fnv_006bbb80

struct SwapTriangle : NavMeshTriangle
{
    void SetArrayElement(int edge, unsigned short vertex);
    void SetSlotValue(int edge, unsigned short neighbor);
    void SetArrayValue(int edge, unsigned short neighbor);
    bool FUN_006957d0();
    void GetPackedFlags(int edge, unsigned short*, unsigned char*, unsigned char*);
    void SetPackedField(int edge, unsigned short, unsigned char, unsigned char);
};

struct SwapMesh
{
    SwapTriangle* FUN_005582f0(unsigned short triangle);
    void SwapTriangleEdges(unsigned short triangle);
};

struct FUN_006957d0_Class
{
    int unk00;
    int unk04;
    int unk08;
    unsigned int unk0C;
    bool FUN_006957d0();
};

struct TriangleArrayLocal
{
    bool FUN_0076b610();
};
struct Candidate
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34;
    TriangleArrayLocal triangles;
    NavMeshTriangle* FUN_005582f0(unsigned short);
    const NiPoint3& FUN_0068f0a0(unsigned short);
    unsigned int FUN_00558200();
    void ComputeBounds(NiPoint3& outMin, NiPoint3& outMax);
};

class Pt3
{
  public:
    float x, y, z;
    Pt3 operator+(const Pt3&) const;
    Pt3 operator*(float) const;
    Pt3 operator-(const Pt3&) const;
    float GetSquaredXYLength() const;
};

struct NavEdgeVerts
{
    const Pt3* first;
    const Pt3* second;
};

class NavTri
{
  public:
    bool IsEdgeSet(int aiEdge);
};

class NavTriArray
{
  public:
    unsigned int GetFlags();
};

class NavMeshA
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
    NavTriArray Triangles;
    NavTri* GetTriangle(unsigned short);
    NavEdgeVerts FUN_0068f040(unsigned short, int);
    bool FUN_00697010(const Pt3& arPoint, float afRadius, unsigned short* apTri, int* apEdge, bool abFlip);
};

struct FUN_00697440_t : public NavMesh
{
    void FUN_00697440(unsigned short ausTriangle, NiPoint3* apCenter);
};

// NavMesh: get the extra info for a triangle edge, creating and linking a fresh record when missing,
// then reset its link fields.

struct D76A0EdgeExtraInfo
{
    int m_iType;
    void* m_pkPortal;
    unsigned short m_usLinkedTriangle;
    D76A0EdgeExtraInfo();
};

struct D76A0Triangle
{
    void SetEdgeExtraInfo(int m_iEdgeNumber, unsigned short usIndex);
};

struct D76A0TriangleArray
{
    D76A0Triangle& GetAt(int iIndex) const;
};

class D76A0NavMesh
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
    D76A0TriangleArray m_kTriangles;

    D76A0EdgeExtraInfo* GetEdgeInfo(unsigned short m_usTriangleID, int m_iEdgeNumber);
    unsigned short AddEdgeInfo(const D76A0EdgeExtraInfo& kInfo);
    D76A0EdgeExtraInfo* GetOrCreateEdgeInfo(unsigned short m_usTriangleID, int m_iEdgeNumber);
};

struct TriangleList
{
    unsigned int FUN_0044ddc0();
    const unsigned short& FUN_0069dec0(unsigned int index);
};
struct TriangleGrid
{
    void GetTriListAtPosition(const NiPoint3& point, TriangleList*& triangles);
};
struct Target : NavMesh
{
    TriangleGrid grid;
    bool GetTriangleHeightAtPoint(unsigned short triangle, const NiPoint3& point, float above, float below, float* z);
    bool FindTriangleZ(const NiPoint3& point, float above, float below, float* z);
};

struct FUN_006986d0_cls;

void* __cdecl FUN_00401000(unsigned int size);

struct b9_big
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c;
    int m_30, m_34, m_38, m_3c, m_40, m_44, m_48, m_4c, m_50, m_54, m_58;
    static void* operator new(unsigned int size)
    {
        return FUN_00401000(size);
    }
    static void operator delete(void*, unsigned int);
    b9_big();
    void InitializeFromMeshSource(FUN_006986d0_cls* o);
    void SetField54(FUN_006986d0_cls* o);
};

struct b9_nav
{
    b9_nav* FUN_00693d70();
    void InitializeFromMeshSource(FUN_006986d0_cls* o);
    void RegisterNavMeshInfo();
};

struct b9_tab
{
    b9_nav* FUN_0045af00(void* p);
};

extern int DAT_011dea10;

struct FUN_006986d0_cls
{
    void* FUN_0084e3a0();
    int FUN_0068efb0();
    void FUN_006d3100(b9_big* p);
    bool FUN_006986d0();
};

struct SearchContext
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
    SearchContext();
    ~SearchContext();
    bool FUN_006bbd30(void* owner, int first, int second);
};
struct NavMeshSearch
{
    bool Search(int first, int second);
};

struct FUN_006993c0_sub
{
    int unk00, unk04, unk08, unk0c;
    ~FUN_006993c0_sub();
};

struct FUN_006993c0_local
{
    FUN_006993c0_sub a;
    FUN_006993c0_sub b;
    FUN_006993c0_local();
    ~FUN_006993c0_local();
};

struct Dummy0044ddc0_sub
{
    int FUN_0044ddc0();
};

struct FUN_006993c0_cls
{
    unsigned char unk00[0xd0];
    Dummy0044ddc0_sub unkD0;

    void UndoToPosition(int aiIndex, FUN_006993c0_local* apLocal);
    void FUN_006993c0();
};

unsigned int __cdecl MaxUnsigned(unsigned int uiHash, unsigned short usValue);

class B99690Triangle
{
  public:
    unsigned short GetBits13To15();
};

class B99690IndexArray
{
  public:
    unsigned int GetSize();
    unsigned short& GetAt(int iIndex);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct B99690Edge
{
    unsigned short m_usTriangle;
};

class B99690EdgeArray
{
  public:
    unsigned int GetSize();
    B99690Edge* GetAt(unsigned int uiIndex);

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

struct B99690Info
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    B99690IndexArray m_kTriangles;
    B99690EdgeArray m_kEdges;
};

class B99690NavMesh
{
  public:
    B99690Triangle* GetTriangle(unsigned short usIndex);
    unsigned int ComputeTriangleHash(B99690Info* pkInfo);
};

struct FUN_0069b0a0_item
{
    FUN_0069b0a0_item* next;
    unsigned short key;
    unsigned char pad[2];
    unsigned int val;
};
struct U4v
{
    unsigned int v;
};
class FUN_0069b0a0_cls
{
  public:
    virtual unsigned int GetPad();
    virtual unsigned int KeyToHashIndex(unsigned short key);
    virtual bool IsKeyEqual(unsigned short a, unsigned short b);
    unsigned int m_uiHashSize;
    FUN_0069b0a0_item** m_ppkHashTable;
    unsigned int m_uiCount;
    bool LookupValue(unsigned short key, unsigned int* out);
};

struct ItemResource
{
    void FUN_00401970();
};

struct ResourceHolder
{
    ItemResource* FUN_00559450();
};

struct Item
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    void* unk14;
    void* unk18;
    ResourceHolder resource;
};

struct ItemPointer
{
    Item* item;
};

struct FUN_0045cec0
{
    int first;
    int second;
    ~FUN_0045cec0();
};

struct FUN_00982610
{
    int first;
    int second;
    int third;
    int fourth;
    ~FUN_00982610();
};

struct FUN_006bf890
{
    int first;
    int second;
    int third;
    int fourth;
    int fifth;
    ~FUN_006bf890();
};

struct FUN_006bfad0
{
    ItemPointer* entries;
    unsigned int count;
    unsigned int capacity;
    unsigned int flags;

    unsigned int FUN_0044ddc0();
    ItemPointer* FUN_00877a30(unsigned int index);
    ~FUN_006bfad0();
};

struct FUN_006bbc50
{
    int identifier;
    FUN_0045cec0 first;
    FUN_00982610 second;
    FUN_006bf890 third;
    FUN_006bfad0 fourth;
    ~FUN_006bbc50();
};

extern const float DAT_0106b158;

struct FUN_006bf220_owner
{
    bool FUN_00697730(unsigned short usIndex, void* apParam, float& afOut, float afX, float afY);
};

struct FUN_006bf220_sub
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    BSSimpleArray<unsigned short> Items;
};

struct FUN_006bf220_cls
{
    FUN_006bf220_owner* m_00;
    int unk04;
    FUN_006bf220_sub* m_08;
    bool FUN_006bf220(void* a1);
};

class TESForm
{
  public:
    virtual void v0();
};
TESForm* __cdecl FUN_004839c0(unsigned int);
struct P507Array
{
    void* table;
    void* data;
    unsigned int size, capacity;
    unsigned int FUN_0044ddc0();
    void** FUN_00877a30(unsigned int);
    void FUN_006bf8f0(unsigned int, bool);
};
class SA0 : public P507Array
{
  public:
    SA0();
    ~SA0();
};
struct P507Info
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    P507Array first, second;
    unsigned int FUN_00559450();
    bool FUN_00690860(NavMeshPtr&);
};
struct P507Manager
{
    void FUN_006b7910();
};
struct P507Global
{
    P507Manager* FUN_0045af00(SA0*);
};

struct P507Edge
{
    int unk00;
    unsigned int owner;
};
struct P507Mesh
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
    virtual void SetChanged(bool);
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
    P507Array edges;
    P507Edge* GetEdge(unsigned short);
    void UpdateTriangleExtraInfo(unsigned short);
};
struct NavMeshPtr
{
    NavMesh* object;
    NavMeshPtr();
    ~NavMeshPtr();
    NavMeshPtr& operator=(const NiPointer<NavMesh>&);
    void* FUN_00458b50();
    P507Mesh* FUN_00559450();
};

extern const float DAT_01016970;
extern const float DAT_01015f5c;

struct NavMeshTriListAdd
{
    unsigned int Add(const unsigned short& arItem);
};
struct NavMeshGridR
{
    void GetCellCoords(const NiPoint3& arPos, unsigned int& arRow, unsigned int& arCol);
    NavMeshTriListAdd* FUN_006967c0(unsigned int auiCol, unsigned int auiRow);
};
struct NiPoint3R : public NiPoint3
{
    NiPoint3R(float afX, float afY, float afZ);
};
struct NavMeshGridOwner : public NavMesh
{
    NavMeshGridR Grid;
    bool AddTrianglesToGrid(unsigned short ausStart, unsigned short ausEnd);
};

struct TriList2 : public NavMeshTriList
{
    void FUN_0069add0(int idx, int n);
};
bool __cdecl FUN_0069b2a0(const unsigned short& a, const unsigned short& b);
extern const float DAT_01016970;
struct Ov2 : public NavMeshOverlap
{
    bool FUN_006967f0(unsigned short ausStart, unsigned short ausEnd);
};

namespace fnv_00696a50 {
extern float DAT_01016970;
extern const double DAT_010240c0;
struct S006949d0
{
    void* GetAt(int aiIndex);
};
struct FUN_00696a50_Grid
{
    void GetTriListAtPosition(const NiPoint3* apPos, NavMeshTriList** appList);
};
struct FUN_00696a50_HeightSource
{
    void CheckWaterHeight(const NiPoint3* apPos, float* apfHeight);
};
struct FUN_00696a50_View
{
    char pad00[0x24];
    FUN_00696a50_HeightSource* pHeightSource;
    char pad28[0x10];
    S006949d0 kTriangles;
};
struct FUN_00696a50_shell : public NavMesh
{
    FUN_00696a50_Grid kGrid;
    bool TestPointOnTriangle(unsigned short ausTriangle, const NiPoint3* apPos, float* apfDistance, int aiArg);
    unsigned short FUN_00696a50(const NiPoint3* apPos, int aiArg);
};
}  // namespace fnv_00696a50

namespace fnv_00696cf0 {
extern float DAT_01016970;
struct TriArr696
{
    void* m_00;
    void* m_04;
    unsigned int m_08;
    unsigned int m_0c;
    NavMeshTriangleEx* FUN_00558dd0(int idx);
    unsigned int FUN_0044ddc0();
};
struct Len696 : public NiPoint3
{
    float FUN_004a7290() const;
};
struct Host696
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
    int m_20, m_24, m_28, m_2c, m_30, m_34;
    TriArr696 m_38;
    int m_48, m_4c, m_50, m_54, m_58, m_5c, m_60, m_64;
    int m_68, m_6c, m_70, m_74, m_78, m_7c, m_80, m_84;
    int m_88, m_8c, m_90, m_94, m_98, m_9c, m_a0, m_a4;
    TriangleGrid m_a8;
    bool FUN_00697730(unsigned short tri, void* p, float& out, float afX, float afY);
    NiPoint3 FUN_00558220(unsigned short tri);
    bool FUN_00696cf0(const NiPoint3& point, unsigned short* outTri, bool* outFlag);
};

}  // namespace fnv_00696cf0

struct AdjustPointOps : NiPoint3
{
    void FUN_004a0c10();
    NiPoint3 ApplyScaled(float scale) const;
    NiPoint3& FUN_0063c8a0(const NiPoint3& offset);
};
float __cdecl FUN_006b9940(const NiPoint3& point, const NiPoint3& first, const NiPoint3& second);
struct NavMeshAdjust : FUN_00697670_StandIn
{
    NiPoint3 FUN_006971e0(unsigned short triangle);
    NiPoint3 AdjustPointToNavMesh(const NiPoint3& point, float radius);
};

struct NiPoint3Cmp : public NiPoint3
{
    bool FUN_004390c0(const NiPoint3& other) const;
};

struct NavEdgeHit
{
    int iType;
    int m_iEdgeNumber;
    NiPoint3 kPoint;
    NavEdgeHit();
};

bool __cdecl FUN_006ba240(const NiPoint3& start, const NiPoint3& end, const NiPoint3& from, const NiPoint3& to,
                          NiPoint3* out);

struct FUN_00698160_t : public NavMesh
{
    NavEdgeHit FindEdgeIntersection(unsigned short ausTriangle, int aiSkipEdge, const NiPoint3& arFrom,
                                    const NiPoint3& arTo);
};

struct UndoOwner;
struct SavedMesh
{
    void* object;
    SavedMesh();
    ~SavedMesh();
    SavedMesh& operator=(const SavedMesh&);
};
struct UndoEntry
{
    int unk00, unk04;
    int type;
    SavedMesh mesh;
};
struct UndoPtr
{
    UndoEntry* Get();
};
struct UndoArray
{
    UndoPtr& At(unsigned int);
    unsigned int Size();
};
struct UndoContext
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
    UndoContext();
    ~UndoContext();
    void Restore(UndoOwner*, UndoEntry*, void*);
    void Remove(UndoOwner*, UndoEntry*);
    void Add(UndoOwner*, const SavedMesh&, void*);
};
struct UndoOwner
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
    UndoArray entries;
    void Erase(int);
    unsigned int Find(UndoEntry*);
    bool UndoToPosition(unsigned int position, void* output);
};

class ObstacleRegistry
{
  public:
    unsigned int FUN_006c61b0(const NiPointer<ObstacleData>& m_spRegisteredObstacle);
};

class ObstacleOwner
{
  public:
    int unk00[0x34];
    ObstacleRegistry m_kRegistry;  // +0xd0

    unsigned int FUN_00699510(ObstacleData* pkObstacle);
};

namespace fnv_0069aa20 {
class EdgePoint
{
  public:
    float x, y, z;
    EdgePoint();
    EdgePoint operator-(const EdgePoint&) const;
    float FUN_004a7290() const;
};
struct LinkedMesh;
struct NavMeshPtr
{
    LinkedMesh* mesh;
    NavMeshPtr();
    ~NavMeshPtr();
    LinkedMesh* FUN_00559450();
};
struct MeshInfo
{
    bool FUN_0069ad00(NavMeshPtr&);
};
struct LinkInfo
{
    int type;
    MeshInfo* mesh;
    unsigned short triangle;
};
struct LinkedTriangle : NavMeshTriangle
{
    bool FUN_00690e10();
};
struct LinkedMesh
{
    unsigned int FUN_00558200();
    LinkedTriangle* FUN_005582f0(unsigned short);
    LinkInfo* GetEdge(unsigned short);
    void FUN_0068f0c0(unsigned short, int, EdgePoint&, EdgePoint&);
    LinkInfo* GetOrCreateEdgeInfo(unsigned short, int);
    MeshInfo* FUN_0068efb0();
    bool LinkMatchingEdges();
};
}  // namespace fnv_0069aa20

struct NavMeshTriList;
float FUN_00406ce0(float afValue);

struct NavMeshGridView
{
    unsigned int uiCellCount;
    float fCellWidth;
    float fCellHeight;
    float m_fGridOriginX;
    float afWorldOriginY;
    float fMinZ;
    float kPointArrayBench;
    float m_fWorldTransformCoefficient4;
    NavMeshTriList* FUN_006967c0(unsigned int auiCol, unsigned int auiRow);
    void GetTriListAtPosition(const NiPoint3& arPos, NavMeshTriList** appList);
};

struct NavObstacleObject
{
    void FUN_00401970();
};
struct NavObstaclePtr
{
    NavObstacleObject* object;
    NavObstaclePtr(int);
    NavObstaclePtr(const NavObstaclePtr&);
    ~NavObstaclePtr();
    void FUN_006e5cc0(const NavObstaclePtr&);
    NavObstacleObject* FUN_00559450();
};
struct NavMap
{
    unsigned int unk00, unk04, unk08, unk0C;
    bool FUN_0069afb0(unsigned short, NavObstaclePtr&);
    void FUN_006946a0(unsigned short, NavObstaclePtr);
    void FUN_0049c250(unsigned short);
};
struct NavIndexArray
{
    unsigned int unk00, unk04, unk08, unk0C;
    unsigned int FUN_0044ddc0();
    unsigned short& GetBufferEntry(unsigned int);
    bool FUN_0076b610();
};
struct NavResetVertices
{
    unsigned int unk00, unk04, unk08, unk0C;
    void FUN_00694890(unsigned int, bool);
};
struct NavResetTriangles
{
    unsigned int unk00, unk04, unk08, unk0C;
    void FUN_006949d0(unsigned int, bool);
};
struct NavTolerance
{
    float x, y, z;
    NavTolerance(float, float, float);
};
struct NavChange;
struct NavMeshOwner
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
    NavResetVertices vertices;
    NavResetTriangles triangles;
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
    NavMap* obstacles;
    void FUN_006987d0(const NavObstaclePtr&, const NavTolerance&, NavIndexArray*);
    unsigned int GetArrFlags();
    unsigned int FUN_00558200();
    NavMeshTriangle* FUN_005582f0(unsigned short);
    void FUN_00699510(NavChange*);
};
struct NavChange
{
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    virtual ~NavChange();
    unsigned int unk04, state;
    NavObstaclePtr obstacle;
    unsigned int oldVertices, newVertices, oldTriangles, newTriangles;
    NavIndexArray affected;
    float centerX, centerY, centerZ;
    unsigned int unk3C;
    NavMap obstacleMap;
    unsigned int unk50, unk54, unk58, unk5C, unk60, unk64, unk68, unk6C;
    NavChange();
};
struct NavItem
{
    unsigned int unk00;
    unsigned short unk04;
    bool enabled;
    char unk07;
    unsigned int unk08, unk0C, unk10, unk14, unk18;
    NavObstaclePtr obstacle;
};
struct NavItemArray
{
    unsigned int unk00, unk04, unk08, unk0C, unk10;
    void FUN_008454f0(unsigned int);
    unsigned int FUN_0044ddc0();
    NavItem*& FUN_00877a30(unsigned int);
};
struct NavChangeBuilder
{
    NavMeshOwner* mesh;
    NavObstaclePtr obstacle;
    NavChange* change;
    unsigned int unk0C, unk10, unk14, unk18;
    NavItemArray items, previousItems;
    unsigned int count;
    unsigned int FUN_006bc940();
    void CollectLinkedTriangles(float*);
    void BuildNavMeshEdges();
    void BuildQuad();
    void SplitCrossingEdges();
    bool FUN_006bf2a0(NavItem*);
    void FUN_006bdcb0();
    void FUN_006bde50();
    bool BuildTrianglesFromEdgePairs();
    void JoinAdjacentEdges();
    void ApplyEdgeSplits();
    void UpdateEdgeRecords(int);
    void FUN_006be770();
    void FUN_006beb80();
    void FUN_006bec20();
    void FUN_006be660();
    bool FUN_006bbd30(NavMeshOwner*, const NavObstaclePtr&, int);
};

struct FindTriangleForLocationFilter;
float __cdecl RandomFloat(float fMin, float fScaledValue);
float __cdecl FUN_004019b0(float fValue);
extern const float runtimeFloatSettingDefault1020;

struct NiPoint3Ops697
{
    NiPoint3 FUN_00439e90(const NiPoint3& kPoint) const;
    NiPoint3Ops697& FUN_0063c8a0(const NiPoint3& kPoint);
};

struct NavFinder697
{
    bool IsLocationOnNavMesh(const NiPoint3& kPoint, FindTriangleForLocationFilter* pkFilter);
    NiPoint3 AdjustPointToNavMesh(const NiPoint3& kPoint, float fDistance);
    bool FUN_00697c10(const NiPoint3& kTargetCenter, float fRadius, NiPoint3* pkOut);
};

extern const float DAT_01016970;
extern const float DAT_01015f5c;
float __cdecl FUN_00406ce0(float);
bool __cdecl FUN_00696540(const NiPoint3&, const NiPoint3&, const NiPoint3&, const NiPoint3&);

struct TriangleGridBuildReceiver
{
    unsigned int dimensionB_;
    float width8, heightSquared9;
    void FUN_0069d2d0();
    void InitFromPoints(const NiPoint3&, const NiPoint3&, unsigned int);
    unsigned int FUN_00559450();
    void FUN_00696500(unsigned short, unsigned int, unsigned int);
    NiPoint3 FUN_0069d790(unsigned int, unsigned int);
};
struct GridCell
{
    unsigned int x, y;
};
struct GridMesh : NavMesh
{
    TriangleGridBuildReceiver Grid;
    void ComputeBounds(NiPoint3&, NiPoint3&);
    bool FUN_00697730(unsigned short, const NiPoint3&, float&, float, float);
    void FUN_006959b0();
};

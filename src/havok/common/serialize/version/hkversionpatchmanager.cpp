#include "f3_common.h"
// src/havok/common/serialize/version/hkversionpatchmanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/version/hkversionpatchmanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* __cdecl FUN_00cb1410(unsigned int);
struct FUN_00d479e0_class
{
    void* GetValue(const void* a, const void* b);
};
struct FUN_00d874d0_s
{
    void FUN_00d874d0(const char* a, int b);
};
struct FUN_00db7d00_class
{
    void* __thiscall FUN_00db7d00(unsigned int a);
};

struct DB7DD0Inner
{
    void FUN_00db7d60();
};

struct DB7DD0Outer
{
    int unk00;
    int unk04;
    DB7DD0Inner* m_inner;

    void FUN_00db7dd0();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750();

struct GraphEntry
{
    void* m_pKey;
    int m_iNext;
};

struct GraphTable
{
    GraphEntry* m_pEntries;

    int LookupWithDefault(void* apKey);
};

struct DepthLimit
{
    int unk00;
    int unk04;
    int m_iLimit;

    int FindSlot(void* apItem);
    void FUN_00cb1870(void* apAllocator, void* apItem, int aiFlag);
};

// @f3 0x009407f0 (community match, verified in this file)
struct FUN_00db7e70_Node
{
    int unk00;
    int unk04;
};

struct FUN_00db7e70_Obj
{
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual FUN_00db7e70_Node* unk07();
    virtual int unk08();
    virtual int unk09();
    virtual void unk0a(int aiFlag);
};

int __cdecl FUN_0093e470();
int __cdecl FUN_009232c0(int aiA, int aiB);
int __cdecl FUN_009406e0(FUN_00db7e70_Node* apNode, int aiResult, void* apItem, int aiA, int aiB);

int __cdecl FUN_00db7e70(void* apTarget, void* apItem, GraphTable* apTable, DepthLimit* apDepth)
{
    FUN_00db7e70_Obj* pObj = reinterpret_cast<FUN_00db7e70_Obj*>(apTarget);
    int iA = pObj->unk09();
    int iB = FUN_0093e470();
    if (FUN_009232c0(iA, iB) != 0)
    {
        FUN_00db7e70_Node* pNode = pObj->unk07();
        if (pNode->unk04 != 0 && FUN_009406e0(pNode, pObj->unk08(), apItem, iA, iB) == 0)
        {
            pObj->unk0a(iB);
            return 0;
        }
        return 1;
    }
    return 0;
}


namespace fnv_00db8540 {
struct AudioAllocator
{
    virtual void v00();
    virtual void* Allocate(unsigned int auiSize);
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750();

struct ByteTag
{
    char m_cValue;

    ByteTag() : m_cValue(0)
    {}

    ~ByteTag()
    {}
};

struct ArrayHeader
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ArrayHeader() : m_pData(0), m_iArrayLength(0), m_uCapacity(0x80000000)
    {}
};

struct TaggedList
{
    int m_i00;
    int m_i04;
    int m_i08;
    int m_i0c;

    void FUN_00d87790(ByteTag akTag);
};

struct CreatedObject
{
    TaggedList m_kFirst;
    ArrayHeader m_kArray;
    TaggedList m_kSecond;
};

struct PoolHolder
{
    void* m_p00;
    int m_i04;
    int m_i08;

    PoolHolder() : m_p00(0), m_i04(0), m_i08(-1)
    {}

    void ResizeToFit(AudioAllocator* apAllocator, int aiFlag);
};

struct FUN_00db8540
{
    virtual void v00();

    short m_s04;
    unsigned short m_u06;
    CreatedObject* m_pCreated;
    ArrayHeader m_kArray;
    PoolHolder m_kEntryPool;

    FUN_00db8540();
};

}  // namespace fnv_00db8540

struct DBA230Entry
{
    unsigned __int64 m_key;
    int unk08;
    int unk0C;
};

struct DBA230Array
{
    DBA230Entry* m_data;
    int m_iElementCount;

    bool ContainsKey(const unsigned __int64& key);
};

namespace fnv_00dbe710 {
struct S_00dbe710_Allocator;
struct S_00dbe710_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00dbe710_Allocator* m_pStreamAllocator;
    S_00dbe710_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
S_00dbe710_Router* FUN_00c85750();
void ResizeAudioStream(S_00dbe710_Allocator* alloc, void* arr, int elemSize);

struct S_00dbe710_Elem
{
    int m_uiFilterValue;
    int m_next;
};

struct S_00dbe710
{
    S_00dbe710_Elem* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int unkC;
    int unk10;
    int unk14;
    int m_firstFree;
    int AllocateSlot();
};
}  // namespace fnv_00dbe710

// FindEntry (0x00db7de0, 134 bytes)
//
// Walks a spatial index: it asks the index object (embedded at this+0x18) for
// the next candidate, looks the entry up in the table at this+0x0c, optionally
// validates it and then hands it to the owner object at this+0x08, which
// returns the key that is used to ask the index for the next candidate.
//
// NOTE: FUN_00db7d60 is only DECLARED in the original translation unit, but
// the original code keeps the "key" value in EDX across the call to it (the
// original callee happens to leave the key in EDX).  To make MSVC 2008 pick
// the same register the helper is given a stand-in body that does not touch
// EDX and is marked __declspec(noinline) so that the call is not inlined.

struct Entry_t
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
};

struct Index_t
{
    unsigned int unk00;
    int __thiscall FUN_00cb1cb0(int a, int b, int c, int d);
};

struct Owner_t
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    int __thiscall FUN_00db7d60(unsigned int a, unsigned int b);
};

extern "C" int __cdecl FUN_00cb0fa0(unsigned int a, unsigned int b);

struct Cls_t
{
    unsigned int unk00;
    unsigned int unk04;
    Owner_t* m08;
    Entry_t** m0C;
    unsigned int unk10;
    unsigned int unk14;
    Index_t m18;

    int FindEntry(int a, int b, int c);
};

struct HelperClass
{
    int FUN_00cb1cb0(int a, int b, int c, int d);
};
struct OwnerClass
{
    int unk00, unk04, unk08;
    HelperClass helper;
    int CallHelperWithDefaults(int first, int second);
};

class BDBA270Allocator;

void __cdecl FUN_00c908c0(BDBA270Allocator& kAlloc, void* apvArray, int iReqCapacity, int iElementSize);
void __cdecl FUN_00d2cc70(void* pvDst, const void* pvSrc, int iNumBytes);

inline void* __cdecl operator new(unsigned int, void* pvWhere)
{
    return pvWhere;
}

struct BDBA270Element
{
    int m_iA;
    int m_iB;
    int m_iC;
    int m_iD;
};

class BDBA270Array
{
  public:
    BDBA270Element* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void Splice(BDBA270Allocator& kAlloc, int iIndex, int iNumToDel, const BDBA270Element* pkItems, int iNumToInsert);
};

struct FUN_00dc7fd0_sub
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void FUN_00d87790(unsigned int a);
    void FUN_00dc9e70();
};

struct FUN_00dc7fd0_subw
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    void FUN_00d87790(unsigned int a);
    void FUN_00dc9e70();
};

struct FUN_00dc7fd0_cls
{
    unsigned int m_00;
    unsigned int m_04;
    unsigned int m_08;
    unsigned int m_0c;
    FUN_00dc7fd0_subw m_10;
    int m_2c;
    FUN_00dc7fd0_subw m_30;
    FUN_00dc7fd0_sub m_4c;
    FUN_00dc7fd0_sub m_5c;
    FUN_00dc7fd0_sub m_6c;

    FUN_00dc7fd0_cls* Initialize();
    void FUN_00d87790(unsigned int a);
};

struct DB7F50Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct DB7F50MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DB7F50Allocator* m_pStreamAllocator;

    DB7F50Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" DB7F50MemoryRouter& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c856c0(DB7F50Allocator* pkAllocator, void* pvMem) throw();

template <class T> struct DB7F50Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~DB7F50Array() throw()
    {
        DB7F50Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class DB7F50Map
{
  public:
    ~DB7F50Map() throw();

    int GetFirstIterator() throw();
    void* getValue(int it) throw();
    int getNext(int it) throw();
    void isValid(bool* pbValid, int it) throw();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
};

class FUN_00db7f50 : public DB7F50Map
{
  public:
    ~FUN_00db7f50() throw();

    DB7F50Array<void*> m_kEntries;
    DB7F50Map m_kValues;
};

namespace fnv_00db83c0 {
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& tempHeap()
    {
        return *unk0c;
    }
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
namespace fnvc_adapt {
__declspec(nothrow) BSAudio* __cdecl FUN_00c85750();
}
inline AudioMgr* audio()
{
    return (AudioMgr*)fnvc_adapt::FUN_00c85750();
}

__declspec(nothrow) void __cdecl ResizeAudioStream(void*, void*, int);

inline void constructWithCopy(int* p, int n, const int& t)
{
    for (int i = 0; i < n; ++i)
        p[i] = t;
}
struct hkIntArray
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline void AddBack(const int& e)
    {
        hkMemoryAllocator& alloc = audio()->heap();
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&alloc, this, sizeof(int));
        constructWithCopy(m_data + m_iElementCount, 1, e);
        m_iElementCount++;
    }
};

struct LocalBuf
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int m_kStorage[32];
    __declspec(nothrow) void InitBuffer();
};

struct GraphEdge
{
    int target;
    int next;
};

struct Graph
{
    GraphEdge* m_kEdges;
    int m_numEdges;
    int m_iCapacityState;
    __declspec(nothrow) int LookupWithDefault(int node);
};

}  // namespace fnv_00db83c0

namespace fnv_00db85e0 {
struct DB85E0Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct DB85E0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DB85E0Allocator* m_pStreamAllocator;

    DB85E0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" DB85E0MemoryRouter& __cdecl FUN_00c85750();
}

struct DB85E0Impl
{
    ~DB85E0Impl();

    static void operator delete(void* p, unsigned int nbytes)
    {
        fnvc_adapt::FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }

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
};

struct DB85E0MapBase
{
    ~DB85E0MapBase();

    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};

struct DB85E0Map : DB85E0MapBase
{
    void ClearAndRelease(DB85E0Allocator& alloc);
    __forceinline ~DB85E0Map()
    {
        ClearAndRelease(fnvc_adapt::FUN_00c85750().heap());
    }
};

struct DB85E0IntArray
{
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~DB85E0IntArray()
    {
        DB85E0Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(int));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class DB85E0ReferencedObject
{
  public:
    virtual ~DB85E0ReferencedObject() throw()
    {}

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class FUN_00db85e0 : public DB85E0ReferencedObject
{
  public:
    virtual ~FUN_00db85e0() throw();

    DB85E0Impl* m_pClassImpl;
    DB85E0IntArray m_ppIndices;
    DB85E0Map m_map;
};

// @fnv 0x00db85e0
FUN_00db85e0::~FUN_00db85e0() throw()
{
    if (m_pClassImpl)
        delete m_pClassImpl;
}
}  // namespace fnv_00db85e0

namespace fnv_00dba1e0 {
struct DBA1E0Allocator
{
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct DBA1E0MemoryRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    DBA1E0Allocator* m_pStreamAllocator;

    DBA1E0Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" DBA1E0MemoryRouter& __cdecl FUN_00c85750();
}

class DBA1E0ReferencedObject
{
  public:
    static void* operator new(unsigned int nbytes)
    {
        DBA1E0ReferencedObject* b =
            static_cast<DBA1E0ReferencedObject*>(fnvc_adapt::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);

    virtual ~DBA1E0ReferencedObject();

    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class DBA1E0Object : public DBA1E0ReferencedObject
{
  public:
    __declspec(nothrow) DBA1E0Object();

    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

}  // namespace fnv_00dba1e0

namespace fnv_00db95c0 {
// Reordered source-vector loop and allocator acquisition; official check pending.
extern "C" void* __cdecl FUN_00cb1410(unsigned int);
struct AllocObj
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void Free(void* p, int sz) throw();
};
void __cdecl FUN_00c908c0(AllocObj* a, void* arr, int sz, int elem) throw();
void __cdecl ResizeAudioStream(AllocObj* a, void* arr, int elem) throw();
struct VecP
{
    void** m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void release(AllocObj& allocator, int elementBytes)
    {
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            allocator.Free(m_pData, (m_iCapacity & 0x3fffffff) * elementBytes);
    }

    ~VecP() throw()
    {
        DB7F50Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            alloc.ReturnMemory(m_pData, (m_iCapacity & 0x3fffffff) * 4);
        m_pData = 0;
        m_iCapacity = (int)0x80000000;
    }
};
struct VecPair
{
    int* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void release(AllocObj& allocator, int elementBytes)
    {
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            allocator.Free(m_pData, (m_iCapacity & 0x3fffffff) * elementBytes);
    }

    ~VecPair() throw()
    {
        DB7F50Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            alloc.ReturnMemory(m_pData, (m_iCapacity & 0x3fffffff) * 8);
        m_pData = 0;
        m_iCapacity = (int)0x80000000;
    }
};
struct WorkRecord
{
    unsigned __int64 key;
    int index;
    int dependency;
};
struct Vec16
{
    int* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void release(AllocObj& allocator, int elementBytes)
    {
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            allocator.Free(m_pData, (m_iCapacity & 0x3fffffff) * elementBytes);
    }

    ~Vec16() throw()
    {
        DB7F50Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        m_iArrayLength = 0;
        if ((m_iCapacity & 0x80000000) == 0)
            alloc.ReturnMemory(m_pData, (m_iCapacity & 0x3fffffff) * 16);
        m_pData = 0;
        m_iCapacity = (int)0x80000000;
    }
};
struct ClassMember
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};
struct IndexedMemberArray
{
    ClassMember* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    IndexedMemberArray() throw()
    {
        m_data = 0;
        m_iElementCount = 0;
        m_iCapacityState = (int)0x80000000;
    }
    ~IndexedMemberArray() throw()
    {
        DB7F50Allocator& alloc = fnvc_adapt::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(ClassMember));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct ClassCinfo
{
    int name;
    int version;
    int parent;
    IndexedMemberArray members;
};
struct ObjCB
{
    void* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void ResizeToFit(AllocObj* a, int b) throw();
    int FUN_00cb1c60(unsigned __int64 key) throw();
    void InsertKeyValue(AllocObj* a, unsigned __int64 key, __int64 value) throw();
    void FUN_00cb1e40(AllocObj* a) throw();
    void FUN_00a29680() throw();
};
struct StrX
{
    int m_00;
    void FUN_00dba650(void* a) throw();
    int FUN_00dba670() throw();
    void FUN_00dba660() throw();
};
struct HelperX
{
    int m_00;
    int m_04;
    int m_08;
    void FUN_00dc8030() throw();
    void FUN_00dc8080() throw();
    void* FUN_00dc7300(int a) throw();
    void FUN_00dc8270(void* a) throw();
    void* CreateItem(void* a) throw();
    void FUN_00dc7390(void* a) throw();
    void FUN_00dc73f0(StrX* a, int b, int c) throw();
    void FUN_00dc7d20(StrX* a, int b, int c, int d, int e) throw();
    void FUN_00dc7600(StrX* a, int b) throw();
    void AssignRefCountedSlot(StrX* a, StrX* b) throw();
    void ReleaseRef(StrX* a) throw();
    void FUN_00dc7320(StrX* a, int b) throw();
    void FUN_00dc72e0(StrX* a, int b) throw();
};
struct MgrA
{
    int m_00;
    int m_04;
    int m_08;
    MgrA* FUN_00cc01c0(void* a) throw();
    MgrA* WriteInt(int a) throw();
    void FUN_00cb1600(void* a, int b) throw();
    void FUN_00cc00e0() throw();
    void FUN_00d87790(int a) throw();
    void FUN_00d874d0(int a, void* b) throw();
    void* GetValue(int a, int b) throw();
    void FUN_00d87820(int a) throw();
    int FUN_00d87410() throw();
    void SetBoolFromThreshold(void* valid, int iterator) throw();
    void* FUN_00d87440(int a) throw();
    int FindNextUsedSlot(int a) throw();
    void FreeBuffer() throw();
};
struct MapTag
{
    char m_00;
};
struct MgrB
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    void FUN_00d87790(MapTag a) throw();
    void FUN_00d87820(int a) throw();
    void FreeBuffer() throw();
    void FUN_00d874d0(int a, void* b) throw();
    void* GetValue(int a, int b) throw();
    int FUN_00d87410() throw();
    void SetBoolFromThreshold(void* valid, int iterator) throw();
    void* FUN_00d87440(int a) throw();
    int FindNextUsedSlot(int a) throw();
};
struct ErrorBuffer
{
    int words[128];
};
struct LogSink
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void FUN_v3(int a, int b, void* c, const char* d, int e) throw();
};
extern LogSink* DAT_01268360;
struct VerObj
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual int FUN_v2() throw();
    int FUN_00d47120() throw();
    int FUN_00d46d40() throw();
};
struct Pair5
{
    int m_00;
    int* m_04;
};
struct Elem
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    Pair5* m_10;
    int m_14;
};
struct VObj
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual int FUN_v2() throw();
    virtual int FUN_v3() throw();
};
struct ArgA
{
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual VerObj* FUN_v4(int a) throw();
    virtual void v5() throw();
    virtual void v6() throw();
    virtual void v7() throw();
    virtual void FUN_v8(void* a) throw();
    void FUN_00dc85a0(int name, HelperX* world) throw();
};
int __cdecl FUN_00db94b0(Vec16* out, int lo, int hi, void* a, void* b, ObjCB* c, ObjCB* d) throw();
struct Owner8
{
    unsigned __int64 FUN_00db7d60(int a, int b) throw();
};
struct This
{
    int m_00;
    int m_04;
    Owner8* m_08;
    Elem** m_0c;
    int m_10;
    int FUN_00db7d40(int a, int b) throw();
    int ForwardToInner(int a, int b) throw();
    int ProcessVersionPatches(ArgA* a, ArgA* b, VecP* c) throw();
};
struct ClassWorld : HelperX
{
    ClassWorld() throw()
    {
        FUN_00dc8030();
    }
    ~ClassWorld() throw()
    {
        FUN_00dc8080();
    }
};
struct PointerMap : ObjCB
{
    PointerMap() throw()
    {
        m_pData = 0;
        m_iArrayLength = 0;
        m_iCapacity = -1;
        AudioHolder* holder = (AudioHolder*)&fnvc_adapt::FUN_00c85750();
        ResizeToFit((AllocObj*)holder->m_pAllocator, 0);
    }
    ~PointerMap() throw()
    {
        FUN_00cb1e40((AllocObj*)fnvc_adapt::FUN_00c85750().m_pStreamAllocator);
        FUN_00a29680();
    }
};
}  // namespace fnv_00db95c0

extern "C" void* __cdecl FUN_00cb1410(unsigned int);

struct PatchFactory
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual int vf10();
};

extern PatchFactory* DAT_01268b08;

struct FUN_00c90510_Object
{
    void FUN_00c90510();
};

struct FUN_00c905b0_Object
{
    void FUN_00c905b0();
};

struct PatchArray
{
    int unk00;
    int unk04;
    int unk08;
};

struct PatchAllocator
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10(int a, int b);
};

extern "C" int __cdecl applyPatchOperations(int patch, int object);
struct PatchWorld
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
    virtual int GetClassFromName(int name);
};

struct PatchManager
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;

    int FUN_00db8670();
    int ProcessVersionPatches(int a, int b, PatchArray* c);
    int FUN_00dba0d0(int param2, int param3);
};

struct DBA1A0Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* unk10;
    int unk14;
    int unk18;
    int unk1C;

    int FUN_00db8670();
    int __thiscall FUN_00dba1a0(int a1);
};

extern "C" int fnv_unknown_clobber(int a) throw();

// @fnv 0x00db7d40
struct Pair
{
    int first, second;
};
struct C
{
    void __thiscall FUN_00db7cf0(int, int);
};
struct W
{
    int x, y;
    C* inner;
    void __thiscall FUN_00db7d40(Pair);
};

namespace fnv_00dba4d0 {
struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pAllocator;
};

struct SortedEntry
{
    int m_kPointA;
    int m_kPointB;
    int m_key;
    int m_iFourthElementInteger;
};

AllocHolder* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(void* allocator, void* list, unsigned int elemSize);

struct FUN_00dba4d0_cls
{
    SortedEntry* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void FUN_00dba340(void* allocator, int index, const SortedEntry* value);
    void FUN_00dba4d0(const SortedEntry* apValue);
};

}  // namespace fnv_00dba4d0

namespace fnv_00dba580 {
struct CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    CpuAllocator* allocator;
};
CpuAllocatorHolder* __cdecl FUN_00c85750();
struct CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00db85e0();
    CpuObject* FUN_00dba580(unsigned int flags);
};
}  // namespace fnv_00dba580

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

extern "C" void _ReadWriteBarrier(void);
void __cdecl ResizeAudioStream(AudioAllocator* apAllocator, void* apContainer, unsigned int auiElemSize);
int __cdecl FUN_00db7cb0(unsigned int auiValue);

struct FUN_00db7ef0_sub
{
    int unk00;
    int unk04;
    void FUN_00cb1e00();
};

struct FUN_00db7ef0_list
{
    unsigned int* m_data;
    int m_uiItemCount;
    unsigned int m_capFlags;
};

struct FUN_00db7ef0_cls
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00db7ef0_list m_kNode;
    FUN_00db7ef0_sub m_sub;

    void FUN_00db7ef0(unsigned int auiValue);
};

struct S00db94b0_Ref_s
{
    int unk00;
    int unk04;
};

struct S00db94b0_Entry_s
{
    int type;
    S00db94b0_Ref_s* ref;
};

struct S00db94b0_Item_s
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S00db94b0_Entry_s* entries;
    int count;
};

struct S00db94b0_Node_s
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual S00db94b0_Node_s* v9(int a);
};

struct S00db94b0_Sub_s
{
    int FUN_00cb1cb0(unsigned __int64 key, __int64 val);
};

struct S00db94b0_Owner_s
{
    int unk00;
    int unk04;
    int unk08;
    S00db94b0_Item_s** items;
    int unk10;
    int unk14;
    S00db94b0_Sub_s sub;

    unsigned __int64 FUN_00db7dd0(int a, int b);
};

struct S00db94b0_Array_s : DBA230Array
{
    bool ContainsKey(const unsigned __int64& key);
    void FUN_00dba4d0(const unsigned __int64& key);
};

struct DB7D00_Shell
{
    void* __thiscall FUN_00db7d00(unsigned int a);
};

struct VersionUidCache
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    struct ItemVec
    {
        unsigned int* m_data;
        unsigned int m_uiItemCount;
        unsigned int m_cap;
    } m_vec;

    unsigned int __thiscall GetOrSetInt(unsigned int a, unsigned int b);
    unsigned __int64 FUN_00db7d60(unsigned int a1, int a2);
};

extern "C" void _ReadWriteBarrier(void);
extern "C" void __cdecl ResizeAudioStream(void* alloc, void* vec, unsigned int n);

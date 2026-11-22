#include "f3_common.h"
// src/havok/common/serialize/packfile/hkpackfiledata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/packfile/hkpackfiledata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00cb1930_Class
{
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    void* m_iFourthElementInteger;
    void* m_usTrailingValue;
    void* m_f;
    void* m_g;
    void* m_h;
    void* m_i;
    void* m_iUnknownValue;
    unsigned long FindValueForKey(void* key, unsigned long def);
};

struct FUN_00e05140_Class
{
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    unsigned long FUN_00e05140();
};

struct hkReferencedObject
{
    void RetainReference();
    void removeReference();
};

struct hkPackFileData
{
    hkReferencedObject* m_pObject;
    void SetObject(hkReferencedObject* pObject);
};

struct FUN_00e05950_class
{
    int* m_p;
    int m_auiShapeKeys;
    int m_uiItemCount;
    int FindFirstNonEmptySlot();
};

void* FUN_00c85750();
void ResizeAudioStream(void* a, void* b, int c);
struct UnkRet
{
    int a;
    int b;
    int c;
    int d;
    int e;
};
struct UnkHolder
{
    int x;
    int y;
    int z;
    int w;
    int* data;
    int count;
    int pad;
    int pad2;
    UnkRet* FUN_00c85750();
    void FUN_00e055a0(UnkRet* r, int v);
};

struct FUN_00e05550_Class
{
    char pad[0x4c];
    int* m_data;
    int m_uiItemCount;
    int m_pRayCursor;
    void AppendPair(int a, int b);
};

void* __cdecl _D1A0E0GetMemoryRouter();

struct FUN_00e05250_Archive
{
    void** m_ppVirtualMethodTable;
    char m_auiShapeKeys[0x0c];
    unsigned char m_flag;
};

struct FUN_00e05250_Class
{
    char m_auiShapeKeys[0x34];
    void* m_memoryData;
    int m_memorySize;
    int m_memoryHashSize;
    void* m_chunksData;
    int m_chunksSize;
    int m_chunksHashSize;
    void* m_exportsData;
    int m_exportsSize;
    int m_exportsHashSize;
    void* m_importsData;
    int m_importsSize;
    int m_importsHashSize;

    void WriteSections(FUN_00e05250_Archive* pArchive, int unused);
};

typedef void(__thiscall* FUN_00e05250_Write)(FUN_00e05250_Archive*, int, const char*, void*, int, int);

int __cdecl _FUN_00d06f80(void* data, int size);

struct ByteSink
{
    void PutBytePair(char a, char b);
};
struct E06C20Writer
{
    void FUN_00e069a0(int a, void* b);
};
struct FUN_00e06800_Class
{
    void FUN_00e06800(int a, void* b);
};

struct FUN_00e06d70_Class
{
    char pad[0x10];
    void* m_pWriter;
    void WriteSize(unsigned int size);
};

// @fnv 0x00e06d70
void FUN_00e06d70_Class::WriteSize(unsigned int size)
{
    void* p = m_pWriter;
    if (size < 0x100)
        ((ByteSink*)p)->PutBytePair(9, (char)size);
    else if (size < 0x10000)
        ((FUN_00e06800_Class*)p)->FUN_00e06800(0xa, (void*)size);
    else
        ((E06C20Writer*)p)->FUN_00e069a0(0xb, (void*)size);
}

struct FUN_00e05100_cls
{
    int unk00;
    int unk04;
    int m_iValue08;
    void FUN_00e05100(int value, int unused);
};

struct FUN_00e05240_cls
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    bool FUN_00e05240();
};

struct hkAllocatorE054;

struct hkMemoryRouterE054
{
    void* m_apvUnk00[4];
    hkAllocatorE054* m_pkHeap;
    hkAllocatorE054& heap()
    {
        return *m_pkHeap;
    }
};
void __cdecl FUN_00c908c0(hkAllocatorE054& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

inline void* __cdecl operator new(unsigned int, void* p) throw()
{
    return p;
}
inline void __cdecl operator delete(void*, void*) throw()
{}

template <typename T> __forceinline T min2E054(T x, T y)
{
    return x < y ? x : y;
}

template <typename T> __forceinline void copyE054(T* dst, const T* src, int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

template <typename T> __forceinline void constructWithArrayE054(T* dst, int n, const T* src)
{
    for (int i = 0; i < n; i++)
        new (dst + i) T(src[i]);
}

template <typename T> struct hkArrayE054
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(hkAllocatorE054& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewSize, sizeof(T));
        }
    }
    __forceinline void _copyFromArray(hkAllocatorE054& kAlloc, const hkArrayE054<T>& a)
    {
        const int iOldSize = m_iElementCount;
        int iNewSize = a.m_iElementCount;
        int iCopiedSize = (iNewSize > iOldSize) ? iOldSize : iNewSize;
        GrowArrayCapacity(kAlloc, iNewSize);
        copyE054<T>(m_data, a.m_data, iCopiedSize);
        constructWithArrayE054<T>(m_data + iCopiedSize, iNewSize - iCopiedSize, a.m_data + iCopiedSize);
        m_iElementCount = iNewSize;
    }
    __forceinline hkArrayE054& operator=(const hkArrayE054<T>& a)
    {
        _copyFromArray(((hkMemoryRouterE054*)FUN_00c85750())->heap(), a);
        return *this;
    }
};

struct PairE054
{
    int m_kPointA;
    int m_kPointB;
};

class FUN_00e05410_Owner
{
  public:
    char m_pad00[0x4c];
    hkArrayE054<PairE054> m_iSecondInteger;
    hkArrayE054<PairE054> m_pHeadNode;

    void CopyPairArrays(hkArrayE054<PairE054>& kFirstOut, hkArrayE054<PairE054>& kSecondOut) const throw();
};

struct FUN_00dce8d0_class
{
    unsigned long LookupHashEntry(unsigned long uiKey, unsigned long uiDefault);
};

struct FUN_00d874d0_s
{
    void FUN_00d874d0(const char* pcKey, int iValue);
};

struct hkBoolE055
{
    char m_bValue;
    hkBoolE055()
    {}
};

struct hkClassE055
{
    hkBoolE055 FUN_00d46d80(const hkClassE055& kOther) const;
};

class hkClassRegistryE055
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual const hkClassE055* GetClassByName(const char* pcName) const;
};

class hkFinishRegistryE055
{
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual int RegisterLoadedObject(void* pvObject, const char* pcClassName) const;
};

struct hkPointerMapPairE055
{
    unsigned long m_uiKey;
    unsigned long m_uiCurrentValue;
};

struct hkPointerMapE055 : public FUN_00e05950_class
{
    int isValid(int iIt) const
    {
        return iIt <= m_uiItemCount;
    }
    int getNext(int iIt) const
    {
        int i = iIt;
        for (i += 1; i <= m_uiItemCount; ++i)
        {
            if (((hkPointerMapPairE055*)m_p)[i].m_uiKey != (unsigned long)-1)
                break;
        }
        return i;
    }
    unsigned long GetIteratorKey(int iIt) const
    {
        return ((hkPointerMapPairE055*)m_p)[iIt].m_uiKey;
    }
    unsigned long getValue(int iIt) const
    {
        return ((hkPointerMapPairE055*)m_p)[iIt].m_uiCurrentValue;
    }
};

class hkPackfileDataE055
{
  public:
    int m_iUnk00;
    int m_iUnk04;
    void* m_pvTopLevelObject;
    int m_iUnk0c;
    hkPointerMapE055 m_kTrackedTypes;
    FUN_00d874d0_s m_kFinishedTypes;
    int m_aiUnk20[3];
    hkClassRegistryE055* m_pkClassRegistry;

    int FUN_00e05240();
    void* FUN_00e055f0(const char* pcExpectedClassName, const hkFinishRegistryE055* pkFinish);
};

extern "C" const void* DAT_010ea51c;
extern int DAT_0102e388;

void* FUN_00c85750();
void __cdecl FUN_00c856c0(void* heap, void* ptr);

struct hkMemoryAllocator
{
    virtual void func0() = 0;
    virtual void func4() = 0;
    virtual void ReleaseBlock(void* ptr, int numBytes) = 0;
    virtual void funcC() = 0;
    virtual void deallocateChunk(void* ptr, int numBytes) = 0;
};

struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m_pStreamAllocator;
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease(hkMemoryAllocator* alloc)
    {
        int cap = this->m_iCapacityState;
        this->m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc->deallocateChunk(this->m_data, (cap & 0x3fffffff) * sizeof(T));
        }
        this->m_data = 0;
        this->m_iCapacityState = 0x80000000;
    }
};

struct Chunk
{
    void* data;
    int size;
    int unk8;
};

struct Export
{
    int a;
    int b;
};

struct Import
{
    int a;
    int b;
};

struct Map1Type
{
    void* m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    void ProcessArgument(void* heap);
    void FUN_00a29680();

    void ClearAndRelease()
    {
        NineIntegerRecord* router = (NineIntegerRecord*)FUN_00c85750();
        this->ProcessArgument(router->m_pStreamAllocator);
        this->FUN_00a29680();
    }
};

struct Map2Type
{
    void* m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iFourthElementInteger;
    void FreeBuffer();
};

struct FUN_00e057c0_Class
{
    const void* vtable;
    int unk04;
    int unk08;
    void* unk0c;
    Map1Type m_map1;
    Map2Type m_map2;
    hkReferencedObject* m_obj;
    int unk30;
    hkArray<void*> m_pMemoryAllocator;
    hkArray<Chunk> m_kChunks;
    hkArray<Export> m_kExports;
    hkArray<Import> m_kImports;

    void Clear();
    void FUN_00e057c0();
};

class FUN_00e057c0
{
  public:
    ~FUN_00e057c0() throw();
};

class hkMemoryAllocatorXe05970
{
  public:
    virtual ~hkMemoryAllocatorXe05970() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterXe05970
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorXe05970* m_pStreamAllocator;

    hkMemoryAllocatorXe05970& heap()
    {
        return *m_pStreamAllocator;
    }
};

class hkObje05970 : public FUN_00e057c0
{
  public:
    hkObje05970* FUN_00e05970(unsigned int uiFlags) throw();

    static void operator delete(void* p) throw()
    {
        static_cast<hkMemoryRouterXe05970*>(FUN_00c85750())
            ->heap()
            .ReleaseBlock(p, static_cast<hkObje05970*>(p)->GetAllocationSize());
    }
    int GetAllocationSize() const
    {
        return reinterpret_cast<const unsigned short*>(this)[2];
    }
};

struct Crux53_HkRouter
{
    int unk00, unk04, unk08, unk0c;
    void* heap;
};
void* FUN_00c85750();
void __cdecl FUN_00c856c0(void* heap, void* ptr);
char* __cdecl FUN_00cb1410(const char* src);
inline void Crux53_FreeName(char* existing)
{
    Crux53_HkRouter* router = (Crux53_HkRouter*)FUN_00c85750();
    FUN_00c856c0(router->heap, existing);
}
struct Crux53_Named
{
    int unk00, unk04, unk08;
    char* name;
    void SetName(const char* newName);
};
// Frees the current name string and assigns the result of FUN_00cb1410(newName).
// @f3 0x00a49b80 (community match, verified in this file)
typedef void* (__stdcall *TlsGetter366)(unsigned long index);
extern TlsGetter366 DAT_00d9b080;
namespace NameHeap366 {
extern unsigned long DAT_010f3170;
struct Heap { void FUN_008f6f90(void* memory); };
}
char* __cdecl FUN_00923640(const char* text);
struct NamedLayout366 {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    char* name;
};
void Crux53_Named::SetName(const char* newName) {
    NamedLayout366* actual = reinterpret_cast<NamedLayout366*>(this);
    char* previous = actual->name;
    NameHeap366::Heap* heap = static_cast<NameHeap366::Heap*>(DAT_00d9b080(NameHeap366::DAT_010f3170));
    heap->FUN_008f6f90(previous);
    actual->name = FUN_00923640(newName);
}


template <int SIZE> __forceinline void memCpyOneAlignedE051(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

template <class T> class hkArrayE051
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpyOneAlignedE051<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};

struct hkEntryE051
{
    void* m_object;
    int m_key;
};

class hkListenerE051
{
  public:
    int unk00[19];
    hkArrayE051<hkEntryE051> m_entries;

    void FUN_00e05190(int key);
};

namespace fnv_00e051e0 {
struct PairE051
{
    int m_key;
    void* m_pIntegerData;
};

template <unsigned int SIZE> inline void memCpyOneAlignedE051(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < (int)(SIZE / 4));
}

template <class T> class hkArrayE051
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpyOneAlignedE051<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};

class FUN_00e051e0_C
{
  public:
    char unk00[0x58];
    hkArrayE051<PairE051> m_entries;

    void RemoveEntry(void* pValue);
};

}  // namespace fnv_00e051e0

struct FUN_00e05370_Entry
{
    int id;
    void* key;
};
struct FUN_00e05370_Callback
{
    int unknown0;
    int unknown4;
    void(__cdecl* invoke)(int);
};
struct FUN_00e05370_List
{
    FUN_00e05370_Entry* data;
    int capacity;
    int lastIndex;
    void ResetEntries();
};
struct FUN_00e05370_Map
{
    int unknown0;
    int count;
    int unknown8;
    int unknownC;
    int unknown10;
    void* table;
    FUN_00e05370_Callback* GetValue(void* key, int defaultValue);
    void ClearEntries();
};
struct FUN_00e05370_Class
{
    int unknown0;
    int unknown4;
    int field08;
    int unknownC;
    FUN_00e05370_List list;
    FUN_00e05370_Map map;
    void Clear();
};

struct FUN_00cb1fe0_Class
{
    int __thiscall EnsureCapacity(void* arg1, int arg2);
};

struct FUN_00d87790_Class
{
    void __thiscall FUN_00d87790(int arg);
};

struct FUN_00c90510_Class
{
    void __thiscall FUN_00c90510();
};

struct FUN_01268B08_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual int vf10();
};

extern "C" const void* DAT_010ea51c;
extern FUN_01268B08_Obj* DAT_01268b08;

struct S00e05700_Arr
{
    void* m_data;
    int m_iElementCount;
    int m_capFlags;

    void reset(int capFlags)
    {
        m_data = 0;
        m_iElementCount = 0;
        m_capFlags = capFlags;
    }
};

struct S00e05700_Class
{
    const void* unk00;
    char unk04;
    char unk05;
    unsigned short unk06;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    hkReferencedObject* unk2C;
    int unk30;
    S00e05700_Arr arr34;
    S00e05700_Arr arr40;
    S00e05700_Arr arr4C;
    S00e05700_Arr arr58;

    S00e05700_Class* __thiscall FUN_00e05700();
};

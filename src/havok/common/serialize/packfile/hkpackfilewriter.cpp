#include "f3_common.h"
// src/havok/common/serialize/packfile/hkpackfilewriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/packfile/hkpackfilewriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl Vsnprintf(void*, void*, const char*, int, int, int, const char*);

struct FUN_00dbdd40_s
{
    int __thiscall GetOrAddString(int a);
};
struct FUN_00d46d40_s
{
    const char* __thiscall FUN_00d46d40();
};
struct FUN_00d874d0_s
{
    void __thiscall FUN_00d874d0(const char*, int);
};
struct FUN_00dbdf30_s
{
    int m_kPointA;
    int m_kPointB;
    void __thiscall FUN_00dbdf30(int a, int b);
};
// @fnv 0x00dbdf30
void __thiscall FUN_00dbdf30_s::FUN_00dbdf30(int pNameSource, int a)
{
    int idx = ((FUN_00dbdd40_s*)this)->GetOrAddString(a);
    const char* name = ((FUN_00d46d40_s*)(void*)pNameSource)->FUN_00d46d40();
    ((FUN_00d874d0_s*)((char*)this + 0xa8))->FUN_00d874d0(name, idx);
}

struct MemoryRouter
{
    void* m0;
    void* m4;
    void* m8;
    void* mc;
    void* m10;
};
extern "C" MemoryRouter* __cdecl D1A0E0GetMemoryRouter();
struct DepthLimit
{
    void FUN_00cb1870(void*, void*, int);
};
struct FUN_00dbdae0
{
    char m[0x2c];
    DepthLimit m_dl;
    void FUN_00dbdae0_0(void* a, int b);
};

namespace fnv_00dbdf00 {
struct DepthLimit
{
    void __thiscall FUN_00cb1870(void*, void*, int);
};

struct FUN_00dbdf00_router
{
    char m_auiShapeKeys[0x10];
    void* m_p;
};

FUN_00dbdf00_router* __cdecl _D1A0E0GetMemoryRouter();

struct FUN_00dbdf00_s
{
    void __thiscall FUN_00dbdf00(void*, int);
};

}  // namespace fnv_00dbdf00

struct FUN_00dbe760_s;

struct FUN_00dbe760_target
{
    virtual void FUN_00dbe760_virtual_0();
    virtual void FUN_00dbe760_virtual_1();
    virtual void FUN_00dbe760_virtual_2(FUN_00dbe760_s*, unsigned short);
};

struct FUN_00dbe760_router
{
    unsigned char m_ucUnknownByte[0x10];
    FUN_00dbe760_target* m_target;
};

FUN_00dbe760_router* _D1A0E0GetMemoryRouter();

struct FUN_00dbc6e0_s
{
    virtual void FUN_00dbdf60();
};

struct FUN_00dbe760_s : public FUN_00dbc6e0_s
{
    unsigned short m_uiFilterValue;

    FUN_00dbe760_s* __thiscall FUN_00dbe760(int a);
};

struct FUN_00cb1930_s
{
    int LookupHashEntry(const void* key, int defaultValue);
};
struct FUN_00c85750_s
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* allocator;
    static FUN_00c85750_s* __cdecl FUN_00c85750();
};
struct TrackedElement
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    int state;
    unsigned int unk14;
};
struct FUN_00dbda80_s
{
    void* m00;
    void* m04;
    TrackedElement* entries;
    void* m0c;
    void* m10;
    FUN_00cb1930_s entryIndex;
    unsigned int unk18;
    unsigned int unk1c;
    DepthLimit firstDepth;
    void FUN_00dbda80(void* key, int value);
};
// @f3 0x00a4a5d0 (community match, verified in this file)
struct HashMap397 {
    int FUN_009227d0(const void* key, int defaultValue);
    void FUN_00922710(void* key, int value);
};
void FUN_00dbda80_s::FUN_00dbda80(void* key, int value) {
    HashMap397& indices = reinterpret_cast<HashMap397&>(entryIndex);
    int index = indices.FUN_009227d0(key, -1);
    if (index >= 0)
        entries[index].state = -2;
    indices.FUN_00922710(key, -2);
    reinterpret_cast<HashMap397&>(firstDepth).FUN_00922710(key, value);
}


extern int DAT_0102e388;

struct FUN_00dbdb10_buf
{
    int unk00;
    int unk04;
    volatile int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

struct FUN_00dc1670_Obj
{
    void FUN_00dc1670();
};

struct FUN_00e02bb0_Obj
{
    void FUN_00e02bb0(void* a);
};

struct FUN_00e02ef0_Obj
{
    void FUN_00e02ef0();
};

struct FUN_00e02a80_Obj
{
    void FUN_00e02a80(void* a, void* b, void* c, void* d);
};

struct FUN_00e02c70_Obj
{
    void FUN_00e02c70();
};

// @fnv 0x00dbdb10
void __cdecl FUN_00dbdb10(void* apArg1, void* apArg2, void* apArg3)
{
    FUN_00dbdb10_buf buf;

    reinterpret_cast<FUN_00dc1670_Obj*>(&buf.unk00)->FUN_00dc1670();
    reinterpret_cast<FUN_00e02bb0_Obj*>(&buf.unk14)->FUN_00e02bb0(&buf);
    reinterpret_cast<FUN_00e02ef0_Obj*>(&buf.unk04)->FUN_00e02ef0();
    reinterpret_cast<FUN_00e02a80_Obj*>(&buf.unk14)->FUN_00e02a80(&buf.unk04, apArg1, apArg2, apArg3);
    buf.unk04 = (int)&DAT_0102e388;
    reinterpret_cast<FUN_00e02c70_Obj*>(&buf.unk14)->FUN_00e02c70();
}

extern "C" void __cdecl GetOrAddString(void);

// @fnv 0x00dbdef0
void __cdecl FUN_00dbdef0()
{
    GetOrAddString();
}

struct DbFirst
{
    char* __thiscall GetLastNodeFlag(void* out);
};

struct DbSecond
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual unsigned int vf10(unsigned int value);
};

// Calls first->GetLastNodeFlag; if its first character is nonzero, returns second->vf10(arg) or 0; otherwise returns the first pointer.
// @fnv 0x00dbd9f0
static __declspec(noinline) unsigned int FUN_00dbd9f0(DbFirst* first, DbSecond* second, unsigned int arg)
{
    bool bFlag;
    char* result = first->GetLastNodeFlag(&bFlag);

    if (*result != 0)
    {
        if (second != 0)
            return second->vf10(arg);
        return 0;
    }
    return (unsigned int)first;
}

DbFirst* volatile g_dbd_first;
DbSecond* volatile g_dbd_second;
unsigned int volatile g_dbd_arg;
unsigned int volatile g_dbd_sink;

void dbd9f0_probe_caller(void)
{
    g_dbd_sink = FUN_00dbd9f0((DbFirst*)g_dbd_first, (DbSecond*)g_dbd_second, g_dbd_arg);
}

class hkMemoryAllocatorDB7;
struct hkMemoryRouterDB7
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDB7* m_pStreamAllocator;
    hkMemoryAllocatorDB7& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterDB7& __cdecl GetMemoryRouterDB7() throw();
int __cdecl hkStrCmpDB7(const char* pcA, const char* pcB) throw();
class hkClassDB7
{
  public:
    const char* getName() const throw();
    unsigned int CalculateDatabaseSignature(int iFlags) const throw();
};
struct hkClassEnumDB7
{
    const char* m_name;
};
class hkOstreamDB7
{
  public:
    hkOstreamDB7(void* pvBuffer, int iSize) throw();
    ~hkOstreamDB7() throw();
    hkOstreamDB7& operator<<(const char* pcString) throw();
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;
};
class hkErrorDB7
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int message(int eType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
};
extern hkErrorDB7* g_pkErrorDB7;
struct hkPointerMapDB7
{
    int FindValueForKey(const void* pvKey, int iDefault) const throw();
    void insert(hkMemoryAllocatorDB7& kAlloc, const void* pvKey, int iValue) throw();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};
struct hkStringMapDB7
{
    void* FindValueForKey(const char* pcKey, void* pvDefault) const throw();
    void insert(const char* pcKey, void* pvValue) throw();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int m_hashFunc;
};
class hkPackfileWriterDB7
{
  public:
    int RegisterObject(void* pvObject, const hkClassDB7* pkClass) throw();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkPointerMapDB7 m_kObjectIndexMap;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    hkStringMapDB7 m_kObjectNameMap;
    hkStringMapDB7 m_kClassLookupMap;
    hkPointerMapDB7 m_kClassMap;
};

// For hkClass and hkClassEnum objects, indexes new names and maps duplicates to existing entries; returns 0 for duplicates and 1 otherwise.
// @f3 0x00a4a630 (community match, verified in this file)
extern char DAT_00e44a74, DAT_00e44a8c, DAT_00e865d8, DAT_00e865b8;
struct ClassDB7View { const char* FUN_009b0490() const; unsigned int FUN_009b0bb0(int flags) const; };
extern int __cdecl FUN_009232c0(const char*,const char*);
struct StringDB7View { void* FUN_009b10f0(const char* key,void* def) const; void FUN_009b0e60(const char* key,void* val); };
struct StreamDB7View {
    void* vtable;
    unsigned short flags;
    short refs;
    void* writer;
    void FUN_00923070(void* mem,int size);
    void FUN_00943710(const char* msg);
    void FUN_00943a60();
};
struct ErrorDB7View {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int message(int type,int code,const char* msg,const char* file,int line);
};
extern ErrorDB7View* DAT_010f3364;
struct DBD7MapView
{
    int FUN_009227d0(const void* key, int defaultValue) const;
    void FUN_00922710(const void* key,int value);
};
struct Fwd { static __forceinline const char* key(const char* k) { return k; } };
int hkPackfileWriterDB7::RegisterObject(void* pvObject,const hkClassDB7* pkClass) throw()
{
    if (FUN_009232c0(((const ClassDB7View*)pkClass)->FUN_009b0490(), &DAT_00e44a74) == 0)
    {
        const hkClassDB7* vObj = (const hkClassDB7*)pvObject;
        const char* pcName = ((const ClassDB7View*)(void*)vObj)->FUN_009b0490();
        const hkClassDB7* candidate = (const hkClassDB7*)m_kObjectNameMap.FindValueForKey(pcName,0);
        if (candidate)
        {
            if (((const ClassDB7View*)(void*)vObj)->FUN_009b0bb0(0) != ((const ClassDB7View*)candidate)->FUN_009b0bb0(0))
            {
                unsigned int buffer[128];
                StreamDB7View stream;
                stream.FUN_00923070(buffer,512);
                stream.FUN_00943710(&DAT_00e865d8);
                DAT_010f3364->message(3,0x2518721c,(const char*)buffer,&DAT_00e865b8,0xa6);
                stream.FUN_00943a60();
            }
            DBD7MapView* objectIndex=(DBD7MapView*)&m_kObjectIndexMap;
            DBD7MapView* classIndex=(DBD7MapView*)&m_kClassMap;
            objectIndex->FUN_00922710(((void*)vObj),objectIndex->FUN_009227d0(candidate,-1));
            classIndex->FUN_00922710(((void*)vObj), (int)candidate);
            return 0;
        }
        ((StringDB7View*)&m_kObjectNameMap)->FUN_009b0e60(Fwd::key(((const ClassDB7View*)(void*)vObj)->FUN_009b0490()),(void*)(void*)vObj);
    }
    else if(FUN_009232c0(((const ClassDB7View*)pkClass)->FUN_009b0490(),&DAT_00e44a8c)==0)
    {
        const char* pcName2 = *(const char**)pvObject;
        const hkClassDB7* candidate = (const hkClassDB7*)m_kClassLookupMap.FindValueForKey(pcName2,0);
        if (candidate)
        {
            DBD7MapView* objectIndex=(DBD7MapView*)&m_kObjectIndexMap;
            DBD7MapView* classIndex=(DBD7MapView*)&m_kClassMap;
            objectIndex->FUN_00922710(pvObject,objectIndex->FUN_009227d0(candidate,-1));
            classIndex->FUN_00922710(pvObject,(int)candidate);
            return 0;
        }
        ((StringDB7View*)&m_kClassLookupMap)->FUN_009b0e60(*(const char**)pvObject,pvObject);
    }
    return 1;
}


template <int SIZE> __forceinline void memCpyOneAlignedXdbdd40(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXdbdd40
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXdbdd40 {
extern "C" hkMemoryRouterXdbdd40& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> class hkArrayXdbdd40
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXdbdd40& router = hkRouterXdbdd40::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXdbdd40<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

extern "C" char* __cdecl FUN_00cb1410(const char* str);

class hkStringMapXdbdd40
{
  public:
    int FUN_00d87650(const char* key, int* out);
    void FUN_00d874d0(const char* key, int value);
};

class hkStringPoolXdbdd40
{
  public:
    int unk00[25];
    hkArrayXdbdd40<char*> m_pStringFunctions;
    hkStringMapXdbdd40 m_map;

    int GetOrAddString(const char* str);
};

// Looks up str in m_map, returning the existing index; otherwise copies str, stores it in m_pStringFunctions, registers it in m_map, and returns the new index.
// @f3 0x00a4a7b0 (community match, verified in this file)
int hkStringPoolXdbdd40::GetOrAddString(const char* apString)
{
    void __cdecl FUN_00901f10(void* a, int b);
    int index;
    if (m_map.FUN_00d87650(apString, &index) == 0)
        return index;
    char* copy = FUN_00cb1410(apString);
    int newIndex = m_pStringFunctions.m_iElementCount;
    m_map.FUN_00d874d0(copy, newIndex);
    hkArrayXdbdd40<char*>* pArr = &m_pStringFunctions;
    if (pArr->m_iElementCount == pArr->getCapacity())
        FUN_00901f10(pArr, 4);
    pArr->m_data[pArr->m_iElementCount] = copy;
    pArr->m_iElementCount++;
    return newIndex;
}


struct S00dbde40_Base
{
    int __thiscall FUN_00dbddc0(int a, int b, int c);
};

struct S00dbde40_Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct S00dbde40_Arr
{
    void* m_data;
    int m_iElementCount;
    unsigned int m_capFlags;
};

struct S00dbde40_Obj : public S00dbde40_Base
{
    int unk00;
    int unk04;
    S00dbde40_Arr arr;
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

    void __thiscall FUN_00dbde40(int a, int b, int c, int d, int e);
};

void* __cdecl FUN_00c85750(void);
void __cdecl ResizeAudioStream(void* a, void* b, int c);
extern char DAT_0126cae8;

// Calls FUN_00dbddc0, builds an S00dbde40_Entry, appends it to arr, and increments unk98 or unk94 depending on b.
// @f3 0x00a4a8a0 (community match, verified in this file)
struct RBase
{
    int FUN_00a4a820(int a, int b, int c);
};
void __cdecl FUN_00901f10(void* a, int b);
extern char DAT_0116a994;

void S00dbde40_Obj::FUN_00dbde40(int a, int b, int c, int d, int e)
{
    int result = ((RBase*)this)->FUN_00a4a820(c, d, e);
    S00dbde40_Entry tmp;
    tmp.unk00 = a;
    tmp.unk04 = b;
    tmp.unk08 = c;
    tmp.unk0C = d;
    tmp.unk10 = result;
    tmp.unk14 = -1;

    S00dbde40_Arr& arr = this->arr;

    if (arr.m_iElementCount == (int)(arr.m_capFlags & 0x3fffffff))
    {
        FUN_00901f10(&arr, 0x18);
    }

    S00dbde40_Entry* pSlot = (S00dbde40_Entry*)((char*)arr.m_data + arr.m_iElementCount * 24);

    *pSlot = tmp;

    ++arr.m_iElementCount;
    this->unk98 += (b == (int)&DAT_0116a994);
    this->unk94 += (b != (int)&DAT_0116a994);
}


class hkMemoryAllocatorDF6
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut);
    virtual void ReturnMemory(void* pvData, int iNumBytes);
};
struct hkMemoryRouterDF6
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorDF6* m_pStreamAllocator;
    hkMemoryAllocatorDF6& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterDF6& __cdecl GetMemoryRouterDF6() throw();
void __cdecl hkDeallocateDF6(hkMemoryAllocatorDF6& kAlloc, void* pvData) throw();
class hkReferencedObjectDF6
{
  public:
    virtual ~hkReferencedObjectDF6() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
template <typename T> struct hkArrayDF6
{
    ~hkArrayDF6() throw()
    {
        hkMemoryAllocatorDF6& kAlloc = GetMemoryRouterDF6().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct hkMapDF6
{
    ~hkMapDF6() throw();
    void ClearAndRelease(hkMemoryAllocatorDF6& kAlloc) throw();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};
struct hkPointerMapDF6
{
    ~hkPointerMapDF6() throw()
    {
        m_map.ClearAndRelease(GetMemoryRouterDF6().heap());
    }
    hkMapDF6 m_map;
};
struct hkStringMapDF6
{
    ~hkStringMapDF6() throw();
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int m_hashFunc;
};
struct SectionDF6
{
    int m_aiData00;
    int m_aiData04;
    int m_aiData08;
    int m_aiData0C;
    int m_aiData10;
    int m_aiData14;
};
struct PairDF6
{
    void* m_pvFirst;
    void* m_pvSecond;
};
struct SectionTableDF6
{
    hkArrayDF6<PairDF6> m_entries;
    hkPointerMapDF6 m_uiEdgeIndex;
};
class FUN_00dbdf60 : public hkReferencedObjectDF6
{
  public:
    virtual ~FUN_00dbdf60() throw();
    hkArrayDF6<SectionDF6> m_sections;
    hkPointerMapDF6 m_kObjectNameMap;
    hkPointerMapDF6 m_kObjectIndexMap;
    hkPointerMapDF6 m_kClassMap;
    hkStringMapDF6 m_kClassNameMap;
    hkStringMapDF6 m_classNames;
    hkPointerMapDF6 m_kObjectMap;
    hkArrayDF6<void*> m_pendingObjects;
    hkStringMapDF6 m_kImports;
    hkArrayDF6<PairDF6> m_kExports;
    int m_iContentsSection;
    int m_iDataSection;
    void* m_pvContents;
    void* m_pvContentsClass;
    hkPointerMapDF6 m_objectsWritten;
    hkStringMapDF6 m_classesWritten;
    SectionTableDF6 m_kSectionTable;
};

// Frees each object pointer stored in m_pendingObjects via the global memory router allocator.
// @fnv 0x00dbdf60
FUN_00dbdf60::~FUN_00dbdf60() throw()
{
    for (int i = 0; i < m_pendingObjects.m_iElementCount; i++)
    {
        void* pvObject = m_pendingObjects.m_data[i];
        hkDeallocateDF6(GetMemoryRouterDF6().heap(), pvObject);
    }
}

class hkMemoryAllocatorE4D;
struct hkMemoryRouterE4D
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorE4D* m_pStreamAllocator;
    hkMemoryAllocatorE4D& heap()
    {
        return *m_pStreamAllocator;
    }
};
hkMemoryRouterE4D& __cdecl GetMemoryRouterE4D() throw();
struct hkContainerHeapAllocatorE4D
{
};
class hkReferencedObjectE4D
{
  public:
    hkReferencedObjectE4D()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectE4D();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};
template <typename T> struct hkArrayE4D
{
    hkArrayE4D() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct hkPointerMapE4D
{
    hkPointerMapE4D() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {
        init(GetMemoryRouterE4D().heap(), 0);
    }
    void init(hkMemoryAllocatorE4D& kAlloc, int iNumElements);
    void insert(hkMemoryAllocatorE4D& kAlloc, const void* pvKey, int iValue);
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
};
struct hkStringMapE4D
{
    hkStringMapE4D(hkContainerHeapAllocatorE4D kAlloc);
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    int m_hashFunc;
};
struct hkPackfileSectionTableE4D
{
    hkPackfileSectionTableE4D();
};
struct hkClassE4D
{
};
extern hkClassE4D g_kClassAE4D;
extern hkClassE4D g_kClassBE4D;
extern hkClassE4D g_kClassCE4D;
class FUN_00dbe4d0 : public hkReferencedObjectE4D
{
  public:
    FUN_00dbe4d0() throw();
    virtual ~FUN_00dbe4d0();
    hkArrayE4D<void*> m_sections;
    hkPointerMapE4D m_kObjectNameMap;
    hkPointerMapE4D m_kObjectIndexMap;
    hkPointerMapE4D m_kClassMap;
    hkStringMapE4D m_kClassNameMap;
    hkStringMapE4D m_classNames;
    hkPointerMapE4D m_kObjectMap;
    hkArrayE4D<void*> m_pendingObjects;
    hkStringMapE4D m_kImports;
    hkArrayE4D<void*> m_kExports;
    int m_iContentsSection;
    int m_iDataSection;
    void* m_pvContents;
    void* m_pvContentsClass;
    hkPointerMapE4D m_objectsWritten;
    hkStringMapE4D m_classesWritten;
    hkPackfileSectionTableE4D m_kSectionTable;
};

struct Mgr
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* vf5();
};
extern Mgr* DAT_01268b08;
struct Cls
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vf3(void* a, void* b, void* r, void* c);
    void FUN_00dbda50(void* a, void* b, void* c);
};
// Invokes vf3 on the object, passing a, b, the result of DAT_01268b08->vf5(), and c.
// @fnv 0x00dbda50
void Cls::FUN_00dbda50(void* apArg1, void* apArg2, void* apArg3)
{
    vf3(apArg1, apArg2, DAT_01268b08->vf5(), apArg3);
}

struct S00dbddc0_Base
{
    int __thiscall GetOrAddString(int a);
};

struct S00dbddc0_Sub9C
{
    int unk00;
    int unk04;
    int unk08;
    int __thiscall LookupHashEntry(int a, int b);
};

struct S00dbddc0_SubA8
{
    int __thiscall GetValue(int a, int b);
};

struct S00dbddc0_Node
{
    int __thiscall FUN_00d46d40();
    S00dbddc0_Node* __thiscall FUN_00d46d50();
};

struct S00dbddc0_cls : public S00dbddc0_Base
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
    int unk90;
    int unk94;
    int unk98;
    S00dbddc0_Sub9C m_sub9c;
    S00dbddc0_SubA8 m_suba8;

    int __thiscall FUN_00dbddc0(int a1, S00dbddc0_Node* a2, int a3);
};

// Looks up a hash entry for a1, then walks the node chain a2 calling GetValue on each key, returning the first hit or calling GetOrAddString(a3).
// @fnv 0x00dbddc0
int S00dbddc0_cls::FUN_00dbddc0(int a1, S00dbddc0_Node* apStartNode, int a3)
{
    int r = m_sub9c.LookupHashEntry(a1, -1);
    if (r != -1)
    {
        return r;
    }
    S00dbddc0_Node* n = apStartNode;
    int iKey = n->FUN_00d46d40();
    r = m_suba8.GetValue(iKey, -1);
    if (r != -1)
    {
        return r;
    }
    do
    {
        n = n->FUN_00d46d50();
        if (n == 0)
        {
            return GetOrAddString(a3);
        }
        iKey = n->FUN_00d46d40();
        r = m_suba8.GetValue(iKey, -1);
    } while (r == -1);
    return r;
}

namespace fnv_00dbe680 {
struct S00dbe680_Tbl
{
    int __thiscall LookupHashEntry(int a, int b);
};

struct S00dbe680_Ret
{
    bool b;
    S00dbe680_Ret();
};

struct S00dbe680_A2
{
    S00dbe680_Ret __thiscall GetLastNodeFlag();
};

struct S00dbe680_A3
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(int a1);
};

struct S00dbe680_Glob
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual S00dbe680_A3* v5();
};

extern S00dbe680_Glob* DAT_01268b08;
extern void* DAT_011b7ae8;

struct Class_00dbe680
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    S00dbe680_Tbl m_hashTable;
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
    int m_8c;
    int m_90;

    void FUN_00dbe150(int a1, void* a2, S00dbe680_A3* a3, int a4, void* a5);
    void FUN_00dbe680(int a1, S00dbe680_A2* a2, S00dbe680_A3* a3, int a4);
};

__declspec(noinline) void Class_00dbe680::FUN_00dbe150(int a1, void* a2, S00dbe680_A3* a3, int a4, void* a5)
{
    unk00 = a1;
    unk04 = a4;
}

}  // namespace fnv_00dbe680

struct SgE150
{
    void* m00;
    void* m04;
    void* m08;
    void* m0c;
    void* allocator;
};
struct FUN_00cb18f0_t
{
    int unk00;
    int unk04;
    int unk08;
    int __thiscall FindSlot(int key);
    void __thiscall FUN_00cb1870(void* alloc, int key, int value);
    int __thiscall LookupHashEntry(int key, int def);
    __forceinline void insert(void* key, int value)
    {
        SgE150* sg = (SgE150*)FUN_00c85750();
        FUN_00cb1870(sg->allocator, (int)key, value);
    }
};
struct MapB8E150
{
    int unk00;
    int unk04;
    int unk08;
    FUN_00cb18f0_t indices;
    int __thiscall AllocateSlot();
    __declspec(noinline) void __thiscall FUN_00dc9ec0(void* a, int* b);
};
struct PairE150
{
    void* key;
    void* value;
};
struct PairListE150
{
    PairE150* m_data;
    int m_uiItemCount;
    int m_pRayCursor;
};
struct Arg4ObjE150
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(void* a, void* b);
};
struct EntryE150
{
    int unk00;
    void* m04;
    void* m08;
    int m0c;
};
struct BufObjE150
{
    int unk00;
    int unk04;
    int unk08;
    EntryE150* m_data;
    int m_uiItemCount;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    void __thiscall FUN_00dbd870();
    void __thiscall FUN_00e028e0();
};
struct StreamObjE150
{
    int unk00;
    int unk04;
    int unk08;
    void __thiscall FUN_00cb1600(char* buf, int n);
    StreamObjE150* __thiscall FUN_00cc01c0(const char* s);
    void __thiscall FUN_00cc00e0();
};
struct LogObjE150
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int __thiscall v3(int a, int magic, const char* buf, const char* f, int line);
};
extern LogObjE150* DAT_01268360;
extern int DAT_011b7aec;
extern const char DAT_010d6734;
extern const char DAT_010d6760;
extern const char DAT_010d67a8;
extern const char DAT_010d67e0;
extern const char DAT_010d664c;
struct ErrBufE150
{
    int f000;
    int f001;
    int f002;
    int f003;
    int f004;
    int f005;
    int f006;
    int f007;
    int f008;
    int f009;
    int f010;
    int f011;
    int f012;
    int f013;
    int f014;
    int f015;
    int f016;
    int f017;
    int f018;
    int f019;
    int f020;
    int f021;
    int f022;
    int f023;
    int f024;
    int f025;
    int f026;
    int f027;
    int f028;
    int f029;
    int f030;
    int f031;
    int f032;
    int f033;
    int f034;
    int f035;
    int f036;
    int f037;
    int f038;
    int f039;
    int f040;
    int f041;
    int f042;
    int f043;
    int f044;
    int f045;
    int f046;
    int f047;
    int f048;
    int f049;
    int f050;
    int f051;
    int f052;
    int f053;
    int f054;
    int f055;
    int f056;
    int f057;
    int f058;
    int f059;
    int f060;
    int f061;
    int f062;
    int f063;
    int f064;
    int f065;
    int f066;
    int f067;
    int f068;
    int f069;
    int f070;
    int f071;
    int f072;
    int f073;
    int f074;
    int f075;
    int f076;
    int f077;
    int f078;
    int f079;
    int f080;
    int f081;
    int f082;
    int f083;
    int f084;
    int f085;
    int f086;
    int f087;
    int f088;
    int f089;
    int f090;
    int f091;
    int f092;
    int f093;
    int f094;
    int f095;
    int f096;
    int f097;
    int f098;
    int f099;
    int f100;
    int f101;
    int f102;
    int f103;
    int f104;
    int f105;
    int f106;
    int f107;
    int f108;
    int f109;
    int f110;
    int f111;
    int f112;
    int f113;
    int f114;
    int f115;
    int f116;
    int f117;
    int f118;
    int f119;
    int f120;
    int f121;
    int f122;
    int f123;
    int f124;
    int f125;
    int f126;
    int f127;
};

struct OwnerE150
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    FUN_00cb18f0_t map14;
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
    FUN_00cb18f0_t map58;
    int u64;
    int u68;
    int u6c;
    int u70;
    int u74;
    int u78;
    int u7c;
    PairListE150 list80;
    int u8c;
    int u90;
    int u94;
    int u98;
    FUN_00cb18f0_t map9c;
    int ua8;
    int uac;
    int ub0;
    int ub4;
    MapB8E150 mapb8;
    int __thiscall RegisterObject(void* a, void* b);
    void __thiscall FUN_00dbde40(void* a, void* b, void* c, void* d, void* e);
    void __thiscall FUN_00dbe150(void* a1, void* a2, void* a3, void* a4, void* a5);
};

// Processes a1 and a2 using map14, may recurse through buffered entries, and logs a message when FUN_00dbd9f0 returns null.
// @f3 0x00a4ac50 (community match, verified in this file)
struct TupleE150 { void* unk00; void* b; void* c; };
struct TupleListE150
{
    int unk00; int unk04; int unk08;
    TupleE150* m_data;
    int m_count;
    int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30;
    void FUN_00941de0();
    void FUN_009b2fd0();
};
struct MapSetE150 { void FUN_00922710(const void* a1, int value); };
void __cdecl FUN_00901f10(void*,int);
void __cdecl FUN_00a4a950(void* a, void* b, TupleListE150* out);
extern void* DAT_01065194;
struct E150RegisterProxy { int FUN_00a4a630(void* a, void* b); void FUN_00a4a8a0(void* a, void* b, void* c, void* d, void* e); };
struct E150Callback { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(void* a, void* b); };
void OwnerE150::FUN_00dbe150(void* a1, void* a2, void* a3, void* a4, void* a5)
{
    FUN_00cb18f0_t* pm = &map14;
    if (pm->FindSlot((int)a1) <= pm->unk08) return;
    void* result = (void*)FUN_00dbd9f0((DbFirst*)a2, (DbSecond*)a3, (unsigned int)a1);
    if (result)
    {
        void* next = a1;
        void* linked = result;
        if (a4)
            ((E150Callback*)a4)->v3(&next, &linked);
        if (next)
        {
            if (!((E150RegisterProxy*)this)->FUN_00a4a630(next, linked))
                return;
            if (a1 != next)
            {
                if (pm->FindSlot((int)next) <= pm->unk08) return;
            }
            ((MapSetE150*)pm)->FUN_00922710(a1, unk0c);
            if (next != a1) {
                ((MapSetE150*)pm)->FUN_00922710(next, unk0c);
                ((MapSetE150*)&map58)->FUN_00922710(next, (int)a1);
            }
            ((E150RegisterProxy*)this)->FUN_00a4a8a0(next, linked, a1, a2, a5);
            TupleListE150 entries;
            entries.FUN_00941de0();
            FUN_00a4a950(next, linked, &entries);
            for (int i = 0; i < entries.m_count; ++i) {
                void* b = entries.m_data[i].b;
                void* c = entries.m_data[i].c;
                if (c && b) FUN_00dbe150(b, c, a3, a4, a5);
            }
            FUN_00dbe150(linked, &DAT_0116a994, a3, a4, DAT_01065194);
            entries.FUN_009b2fd0();
            return;
        }
        ((MapSetE150*)pm)->FUN_00922710(a1, -1);
        return;
    }
    ((MapSetE150*)pm)->FUN_00922710(a1, -1);
    PairListE150* exports = &list80;
    if (exports->m_uiItemCount == (exports->m_pRayCursor & 0x3fffffff))
        FUN_00901f10(exports, 8);
    PairE150 pair = { a1, a2 };
    exports->m_data[exports->m_uiItemCount] = pair;
    exports->m_uiItemCount++;
}

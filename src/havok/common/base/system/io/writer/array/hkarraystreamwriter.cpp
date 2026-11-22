#include "f3_common.h"
// src/havok/common/base/system/io/writer/array/hkarraystreamwriter.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/writer/array/hkarraystreamwriter.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkArrayStreamWriter.h"

struct FUN_00d467c0
{
    void write(const char* a, unsigned int b);
};
struct FUN_00d468a0_obj
{
    unsigned int pad[2];
    FUN_00d467c0* p;
    unsigned int WriteToStream(unsigned int arg, unsigned int b);
};

struct FUN_00d469c0
{
    int m0;
    int m1;
    int m2;
    int m3;
    int m4;
    FUN_00d469c0(int v);
};

struct FUN_00d46b20_inner
{
    void Run();
};

struct FUN_00d46b20_cls
{
    int unk00;
    int unk04;
    FUN_00d46b20_inner* m_08;
    void FUN_00d46b20();
};

// @fnv 0x00d46b20
void FUN_00d46b20_cls::FUN_00d46b20()
{
    m_08->Run();
}

struct FUN_00d46c80_cls
{
    int unk00;
    int unk04;
    int unk08;
    int m_0c;

    void FUN_00d46c80(int aiDelta);
};

extern int DAT_010cf734;
struct FUN_00d466e0
{
    void* unk00;
    short unk04;
    short unk06;
    int unk08;
    int unk0C;
    int unk10;
    FUN_00d466e0(int a, int b);
};

struct FNVBuffer
{
    void* data;
    unsigned int used;
    unsigned int capacityAndFlags;
};
struct FNVWriter
{
    virtual void method00();
    virtual void method04();
    virtual void method08();
    virtual void method0c();
    virtual void method10();
    virtual void method14(int operation, const void* globalData, void* bytes, unsigned int count, unsigned int limit);
    int unk04;
    int unk08;
    int unk0c;
    unsigned char allowRestricted;
};
extern int DAT_010cc460;
extern unsigned int __cdecl FUN_00d06f80(void*, unsigned int);
struct FUN_00d46770_cls
{
    int unk00;
    int unk04;
    FNVBuffer* buffer;
    void WriteBufferToWriter(FNVWriter* writer, int unused);
};

class hkMemoryAllocatorD469
{
  public:
    virtual ~hkMemoryAllocatorD469() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD469
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD469* m_pStreamAllocator;
    hkMemoryAllocatorD469& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterD469 {
extern "C" hkMemoryRouterD469& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayD469
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void ClearAndRelease() throw()
    {
        hkMemoryAllocatorD469& kAlloc = hkRouterD469::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

inline void hkDeallocateChunkD469(void* p, int iNumBytes)
{
    hkRouterD469::FUN_00c85750().heap().ReleaseBlock(p, iNumBytes);
}

class hkBlockPoolD469
{
  public:
    int m_iDofCount;
    int m_pTileTemplate;
    hkArrayD469<void*> m_kBlocks;

    void FreeAllChunks();
};

// @fnv 0x00d469e0
void hkBlockPoolD469::FreeAllChunks()
{
    for (int i = 0; i < m_kBlocks.m_iElementCount; i++)
        hkDeallocateChunkD469(m_kBlocks.m_data[i], m_iDofCount);
    m_kBlocks.ClearAndRelease();
    m_pTileTemplate = m_iDofCount;
}

struct FUN_00d469e0_Obj
{
    void FreeAllChunks();
};
struct FUN_00d46be0_Inner
{
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4(int a, int b);
};
struct FUN_00d46be0_Res
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FUN_00d46be0_Inner* inner;
};
void* __cdecl FUN_00c85750();
struct FUN_00d46be0_Cls
{
    int m00;
    int m04;
    int* m08;
    int m0c;
    int m10;
    void FUN_00d46be0();
};
// @fnv 0x00d46be0
void FUN_00d46be0_Cls::FUN_00d46be0()
{
    reinterpret_cast<FUN_00d469e0_Obj*>(this)->FreeAllChunks();
    FUN_00d46be0_Res* res = reinterpret_cast<FUN_00d46be0_Res*>(FUN_00c85750());
    FUN_00d46be0_Inner* pInner = res->inner;
    int v = m10;
    m0c = 0;
    if (v & 0x80000000)
        goto done;
    pInner->s4(reinterpret_cast<int>(m08), (v & 0x3fffffff) * 4);
done:
    m08 = 0;
    m10 = 0x80000000;
}

class hkMemoryAllocatorD46C
{
  public:
    virtual ~hkMemoryAllocatorD46C() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD46C
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD46C* m_pStreamAllocator;
    hkMemoryAllocatorD46C& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterD46C {
extern "C" hkMemoryRouterD46C& __cdecl FUN_00c85750();
}

class FUN_00d46be0_class
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;

    void FUN_00d46be0() throw();
    ~FUN_00d46be0_class() throw()
    {
        FUN_00d46be0();
    }
    static void operator delete(void* p) throw()
    {
        hkRouterD46C::FUN_00c85750().heap().ReleaseBlock(p, sizeof(FUN_00d46be0_class));
    }
};

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

class hkReferencedObjectD46C
{
  public:
    virtual ~hkReferencedObjectD46C() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        hkRouterD46C::FUN_00c85750().heap().ReleaseBlock(p,
                                                         static_cast<hkReferencedObjectD46C*>(p)->m_usMemSizeAndFlags);
    }
};

class FUN_00d46c30 : public hkReferencedObjectD46C
{
  public:
    FUN_00d46be0_class* m_stream;
    int m_0c;
    int m_ownership;

    virtual ~FUN_00d46c30() throw();
};

// Destructor that deletes m_stream when m_ownership equals 1.
// @fnv 0x00d46c30
FUN_00d46c30::~FUN_00d46c30() throw()
{
    if (m_ownership == 1)
        delete m_stream;
}

struct State
{
    bool status;
    State()
    {}
};
struct Counters
{
    int step;
    int base;
    int misc;
    int length;
};
struct FUN_00d46ca0_Class
{
    int unk00, unk04;
    Counters* counters;
    int position;
    State FUN_00d46ca0();
};

namespace fnv_00d46cc0 {
struct FnvCpu_FUN_00d46cc0_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00d46cc0_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00d46cc0_CpuAllocator* allocator;
};
FnvCpu_FUN_00d46cc0_CpuAllocatorHolder* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00d46cc0_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00d46c30();
    FnvCpu_FUN_00d46cc0_CpuObject* Destroy(unsigned int flags);
};
}  // namespace fnv_00d46cc0

void __cdecl FUN_00cb1260(void* dst, const void* src, int nbytes);

class hkBlockStreamD466
{
  public:
    int m_iDofCount;
    int m_iLastBlockSize;
    char** m_kBlocks;
    int m_iBlockCount;

    void Read(void* buf, int nbytes, int offset);
};

class hkBoolD467
{
  public:
    hkBoolD467(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
    char m_cBooleanValue;
};

class hkBufferD467
{
  public:
    int m_iFirstIndex;
    int m_last;
    int unk08;
    int m_iCapacity;

    void Read(void* dst, int n, int offset) throw();
};

class hkStreamD467
{
  public:
    virtual ~hkStreamD467();
    virtual int read(void* dst, int n);
    virtual int skip(int n);
    virtual hkBoolD467 IsStreamValid();

    int unk04;
    hkBufferD467* m_buffer;
    int m_offset;

    int FUN_00d46710(void* dst, int n);
};

namespace fnv_00d468c0 {
class hkMemoryAllocatorD468;

struct hkMemoryRouterD468
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorD468* m_pTemp;
    hkMemoryAllocatorD468* m_pStreamAllocator;
    hkMemoryAllocatorD468& heap()
    {
        return *m_pStreamAllocator;
    }
};

extern "C" hkMemoryRouterD468& __cdecl FUN_00c85750() throw();
void __cdecl FUN_00c908c0(hkMemoryAllocatorD468& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void __cdecl FUN_00cb1260(void* pvDst, const void* pvSrc, int iNumBytes) throw();

template <class T> class hkArrayD468
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorD468& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void reserve(int n)
    {
        reserve(FUN_00c85750().heap(), n);
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};

class hkBufWriterD468
{
  public:
    int unk00;
    int unk04;
    hkArrayD468<char>* m_buf;
    int m_pos;

    void Reset();
};

}  // namespace fnv_00d468c0

class hkMemoryAllocatorD46B;

struct hkMemoryRouterD46B
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD46B* m_pStreamAllocator;
    hkMemoryAllocatorD46B& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace fnvc_adapt {
extern "C" hkMemoryRouterD46B& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorD46B& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
extern "C" void* __cdecl fnv_zlib_memset(void* pvDst, int iValue, unsigned int uiSize) throw();

class hkArrayD46B
{
  public:
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorD46B& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(char));
        }
    }
    __forceinline void SetSizeAndGrow(int n, const char& fill)
    {
        reserve(fnvc_adapt::FUN_00c85750().heap(), n);
        char* pDst = m_data + m_iElementCount;
        int iEntryIndex = n - m_iElementCount;
        if (iEntryIndex <= 0)
        {
            m_iElementCount = n;
            return;
        }
        fnv_zlib_memset(pDst, fill, iEntryIndex);
        m_iElementCount = n;
    }
    void popBack()
    {
        m_iElementCount--;
    }
};

class hkArrayStreamWriterD46B
{
  public:
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    hkArrayD46B* m_aiIndexedValues;
    int m_offset;

    int Seek(int iRelOffset, int eWhence);
};

// Seeks m_offset to iRelOffset relative to eWhence, growing m_aiIndexedValues if needed, and returns 1 on negative offset.
// @f3 0x00943d00 (community match, verified in this file)
void __cdecl FUN_00901e90(hkArrayD46B* array, int capacity, int elementSize);

__forceinline void GrowSeekArray(hkArrayD46B* array, int newSize, const char& fill)
{
    int oldCount = array->m_iElementCount;
    if (newSize > oldCount)
    {
        int capacity = array->m_iCapacityState & 0x3fffffff;
        if (capacity < newSize)
        {
            int doubled = 2 * capacity;
            int newCapacity = newSize < doubled ? doubled : newSize;
            FUN_00901e90(array, newCapacity, sizeof(char));
        }
        for (int i = oldCount; i < newSize; ++i)
            array->m_data[i] = fill;
    }
    array->m_iElementCount = newSize;
}

int hkArrayStreamWriterD46B::Seek(int iRelOffset, int eWhence)
{
    int iAbsOffset = m_offset;
    switch (eWhence)
    {
    case 0:
        iAbsOffset = iRelOffset;
        break;
    case 1:
        iAbsOffset = m_offset + iRelOffset;
        break;
    case 2:
        iAbsOffset = m_aiIndexedValues->GetLogicalSize() - iRelOffset;
        break;
    }
    if (iAbsOffset >= 0)
    {
        if (iAbsOffset > m_aiIndexedValues->GetLogicalSize())
        {
            GrowSeekArray(m_aiIndexedValues, iAbsOffset + 1, 0);
            m_aiIndexedValues->m_iElementCount = iAbsOffset;
        }
        m_offset = iAbsOffset;
        return 0;
    }
    return 1;
}


struct Alloc_d467
{
    virtual void vf00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct Router_d467
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    Alloc_d467* m_pStreamAllocator;

    Alloc_d467& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct BlockArray_d467
{
    const char** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class Stream_d467
{
  public:
    int m_iDofCount;
    int m_offset;
    BlockArray_d467 m_kBlocks;

    void FUN_00d467c0(const char* pcData, int iSize);
};

void __cdecl ResizeAudioStream(void*, void*, int);
void __cdecl FUN_00cb1260(void* dst, const void* src, int count);

void __cdecl FUN_00c908c0(hkMemoryAllocatorD469* heap, void* array, int numElements, int sizeOfElement);
void __cdecl FUN_00cb1260(void* dst, const void* src, int nbytes);

template <class T> struct hkArray_d469
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    void reserve(int n)
    {
        hkMemoryAllocatorD469& heap = hkRouterD469::FUN_00c85750().heap();
        int cap = getCapacity();
        if (cap < n)
        {
            int cap2 = 2 * cap;
            FUN_00c908c0(&heap, this, n < cap2 ? cap2 : n, sizeof(T));
        }
    }
};

struct hkArrayStreamWriter_d469
{
    int* m_vtbl;
    int m_memSizeAndRefCount;
    hkArray_d469<char>* m_aiIndexedValues;
    int m_offset;
    int FUN_00d46920(const void* mem, int size);
};

// Copies size bytes from mem into the indexed values array at m_offset, growing the array if needed, then advances m_offset and returns size.
// @f3 0x00943c70 (community match, verified in this file)
struct Array451;
namespace Helpers451 {
void __cdecl FUN_00901e90(Array451* array, int capacity, int stride);
void __cdecl FUN_009234e0(void* destination, const void* source, int bytes);
}
struct Array451 {
    char* data;
    int count;
    unsigned int capacityFlags;
    int Capacity() const { return capacityFlags & 0x3fffffff; }
    __forceinline void Reserve(int requested) {
        int capacity = Capacity();
        if (capacity < requested) {
            int doubled = capacity * 2;
            int target = requested < doubled ? doubled : requested;
            Helpers451::FUN_00901e90(this,target,1);
        }
    }
};
struct Layout451 {
    unsigned int unk00,unk04;
    Array451* array;
    int offset;
};
int hkArrayStreamWriter_d469::FUN_00d46920(const void* memory, int size) {
    Layout451* self = reinterpret_cast<Layout451*>(this);
    int space = self->array->count - self->offset;
    if (size > space) {
        int newSize = self->array->count - space + size;
        self->array->Reserve(newSize + 1);
        self->array->count = newSize;
        self->array->data[newSize] = 0;
    } else if (self->array->Capacity() > self->array->count) {
        self->array->data[self->array->count] = 0;
    }
    Helpers451::FUN_009234e0(self->array->data + self->offset,memory,size);
    self->offset += size;
    return size;
}


namespace fnv_00d46a50 {
struct V46a50Alloc
{
    virtual void v00();
    virtual void v04();
    virtual void v08(void* p, int n);
    virtual void v0c();
    virtual void ReturnMemory(void* p, int size);
};
struct V46a50Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    V46a50Alloc* m_alloc;
    V46a50Alloc& heap()
    {
        return *m_alloc;
    }
};
V46a50Router* __cdecl FUN_00c85750();

struct V46a50Elem
{
};
struct V46a50Owner
{
    void doElem(V46a50Elem* e, int n);
    void FUN_00d46a50(struct V46a50List* l);
};
struct V46a50List
{
    int m0;
    int m4;
    V46a50Elem** m_data;
    int m_iElementCount;
    int m_capFlags;
    void FreeAllChunks();
};

}  // namespace fnv_00d46a50

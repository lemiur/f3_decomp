#include "f3_common.h"
// src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned char m128_u8[16];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct Block5
{
    int unk00, unk04, unk08, unk0c, unk10;
};

struct Block5b
{
    int unk00;
    unsigned short unk04;
    unsigned char unk06;
    unsigned char unk07;
    int unk08, unk0c, unk10;
};

struct hkRefObj
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    void FUN_00c90510();
    void FUN_00c905b0();
};

struct CloneDataBase : hkRefObj
{
    int unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    __m128 unk20, unk30, unk40, unk50, unk60, unk70;
};

struct CloneDataA : CloneDataBase
{
    Block5 unk80;
    Block5b unk94;
    Block5 unka8;
    CloneDataA* FUN_00d4f2a0();
    void FUN_00d4f270(hkBool flag);
};

struct CloneDataB : CloneDataBase
{
    Block5 unk80;
    CloneDataB* FUN_00d52fc0();
};

struct SourceDataHeader
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int getType();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
};

struct SourceData : SourceDataHeader
{
    __m128 unk20, unk30, unk40, unk50, unk60, unk70, unk80;
};

struct SourceDataB : SourceData
{
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    Block5 unkc0;
};

struct SourceDataA : SourceData
{
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc,
        unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8;
    Block5 unkfc;
    Block5b unk110;
    Block5 unk124;
};

struct Instance;

struct Instance : hkRefObj
{
    int unk08;
    SourceData* unk0c;
    int unk10;
    void* unk14;
    void* unk18;
    unsigned char unk1c;
    Instance* FUN_00cf3ea0(void* entityA, void* entityB, CloneDataBase* data, int priority);
};

inline void* hkAlloc(int size)
{
    hkRefObj* p = (hkRefObj*)audio()->heap().AllocateMemoryBlock(size);
    p->m_usMemSizeAndFlags = (unsigned short)size;
    return p;
}

// @f3 0x00a90670 (community match, verified in this file)
#include <string.h>

typedef void* (__stdcall* TlsGetter)(unsigned long);
extern "C" TlsGetter const DAT_00fdf044;
extern unsigned long DAT_010f3170;

namespace ConstraintCloning {

struct Allocator {
    void* FUN_008f6d30(unsigned int bytes, int category);
};

struct RefHeader {
    virtual ~RefHeader();
    unsigned short sizeAndFlags;
    short referenceCount;

    void RemoveReference()
    {
        if (sizeAndFlags != 0 && --referenceCount == 0)
            delete this;
    }
};

struct Transform {
    Transform& FUN_008dbcd0(const Transform& source);
    float row0[4], row1[4], row2[4];
};

struct Block {
    unsigned int field00, field04, field08, field0c, field10;
};

struct FlagBlock {
    unsigned int field00;
    unsigned short field04;
    unsigned char flag, field07;
    unsigned int field08, field0c, field10;
};

struct ConstraintSource : RefHeader {
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual int GetType();

    unsigned int field08, field0c, field10, field14, field18, field1c;
    Transform transformA;
    float field50[4];
    Transform transformB;
};

struct LargeSource : ConstraintSource {
    unsigned int field90, field94, field98, field9c;
    unsigned int fielda0, fielda4, fielda8, fieldac;
    unsigned int fieldb0, fieldb4, fieldb8, fieldbc;
    unsigned int fieldc0, fieldc4, fieldc8, fieldcc;
    unsigned int fieldd0, fieldd4, fieldd8, fielddc;
    unsigned int fielde0, fielde4, fielde8, fieldec;
    unsigned int fieldf0, fieldf4, fieldf8;
    Block parametersA;
    FlagBlock flaggedParameters;
    Block parametersB;
};

struct SmallSource : ConstraintSource {
    unsigned int field90, field94, field98, field9c;
    unsigned int fielda0, fielda4, fielda8, fieldac;
    unsigned int fieldb0, fieldb4, fieldb8, fieldbc;
    Block parameters;
};

struct HavokAllocation {
    static void* Allocate(size_t bytes, TlsGetter getTls)
    {
        Allocator* allocator = static_cast<Allocator*>(getTls(DAT_010f3170));
        RefHeader* memory = static_cast<RefHeader*>(allocator->FUN_008f6d30(bytes, 0x2c));
        memory->sizeAndFlags = static_cast<unsigned short>(bytes);
        return memory;
    }

    static void* operator new(size_t bytes, TlsGetter getTls)
    {
        return Allocate(bytes, getTls);
    }

    static void* operator new(size_t, void* memory)
    {
        return memory;
    }
};

struct Clone : RefHeader, HavokAllocation {
    unsigned int field08, field0c, field10, field14, field18, field1c;
    Transform transformA, transformB;
};

struct Bool {
    unsigned char value;
    Bool(bool state) : value(state) {}
};

struct FUN_009dc8c0 : Clone {
    FUN_009dc8c0() throw();
    void FUN_009dc7f0(Bool flag);
    Block parametersA;
    Block flaggedParameters;
    Block parametersB;
    unsigned int fieldbc;
};

struct FUN_009e09b0 : Clone {
    FUN_009e09b0() throw();
    Block parameters;
    unsigned int field94, field98, field9c;
};

struct FUN_00979fb0 : RefHeader, HavokAllocation {
    FUN_00979fb0(void* bodyA, void* bodyB, Clone* data, int priority) throw();
    unsigned int field08;
    ConstraintSource* data;
    unsigned int field10;
    void* bodyA;
    void* bodyB;
    unsigned char priority;
    unsigned int field20, field24, field28;
};

}

Instance* __cdecl CloneInstanceFromSource(Instance* source)
{
    using namespace ConstraintCloning;
    FUN_00979fb0* instance = reinterpret_cast<FUN_00979fb0*>(source);
    ConstraintSource* data = instance->data;
    Clone* clone;
    TlsGetter getTls;
    switch (data->GetType()) {
    case 7: {
        LargeSource* large = static_cast<LargeSource*>(data);
        getTls = DAT_00fdf044;
        FUN_009dc8c0* result = new (getTls) FUN_009dc8c0;
        clone = result;
        result->transformA.FUN_008dbcd0(large->transformA);
        result->transformB.FUN_008dbcd0(large->transformB);
        result->parametersA = large->parametersA;
        result->parametersB = large->parametersB;
        memcpy(&result->flaggedParameters, &large->flaggedParameters, sizeof(Block));
        Bool flag(large->flaggedParameters.flag != 0);
        result->FUN_009dc7f0(flag);
        break;
    }
    case 2: {
        SmallSource* small = static_cast<SmallSource*>(data);
        getTls = DAT_00fdf044;
        FUN_009e09b0* result = new (getTls) FUN_009e09b0;
        clone = result;
        result->transformA.FUN_008dbcd0(small->transformA);
        result->transformB.FUN_008dbcd0(small->transformB);
        result->parameters.field00 = small->parameters.field00;
        result->parameters.field04 = small->parameters.field04;
        result->parameters.field08 = small->parameters.field08;
        result->parameters.field0c = small->parameters.field0c;
        result->parameters.field10 = small->parameters.field10;
        break;
    }
    case 18:
    case 19:
        if (instance->sizeAndFlags != 0)
            ++instance->referenceCount;
        return source;
    default:
        return 0;
    }

    void* memory = HavokAllocation::Allocate(sizeof(FUN_00979fb0), getTls);
    int priority = instance->priority;
    void* bodyB = instance->bodyB;
    void* bodyA = instance->bodyA;
    FUN_00979fb0* result = new (memory) FUN_00979fb0(bodyA, bodyB, clone, priority);
    clone->RemoveReference();
    return reinterpret_cast<Instance*>(result);
}


class FnvSink
{
  public:
    virtual void Slot0() throw();
    virtual void Slot1() throw();
    virtual void Slot2() throw();
    virtual void Write(int level, unsigned int hash, const char* msg, const char* file, int line) throw();
};

extern FnvSink* DAT_01268360;

class MsgWriter
{
  public:
    void Init(char* buf, unsigned int cap) throw();
    void Append(const char* s) throw();
    void Finish() throw();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};

class FnvInner
{
  public:
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0C() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void v1C() throw();
    virtual unsigned int GetKind() throw();

    char unk04[0x0c];
    __m128 m_20;
    __m128 m_30;
    char unk40[0x10];
    __m128 m_50;
    char unk60[0x30];
    __m128 m_90;
};

class FnvHolder
{
  public:
    char unk00[0x0c];
    FnvInner* m_0c;
};

namespace fnv_00e5ae60 {
struct S_00e5ae60_Stream
{
    int unk00;
    int unk04;
    int unk08;
    S_00e5ae60_Stream(char* buf, int size) throw();
    S_00e5ae60_Stream& FUN_00cc01c0(const char* s) throw();
    ~S_00e5ae60_Stream() throw();
};

struct S_00e5ae60_Err
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int FUN_message(int type, int id, const char* text, const char* file, int line) throw();
};
extern S_00e5ae60_Err* DAT_01268360;

struct S_00e5ae60_Constraint
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int GetType() throw();
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
    int m_b0;
    int FUN_00cdea20() throw();
    int FUN_00cdea80() throw();
    int FUN_00cdeaa0() throw();
};

}  // namespace fnv_00e5ae60

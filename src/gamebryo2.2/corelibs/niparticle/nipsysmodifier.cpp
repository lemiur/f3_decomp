// gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp: NiPSysModifier, MyIsEqual, ParticleModifierBinary, ParticleModifier (6 functions)
#include "f3_common.h"
#include "nipsysmodifier_decls.h"

// @fnv 0x00C318B0
// pdb: NiPSysModifier::LoadBinary | NiPSysModifier.obj | fnv360_0822_retail, call_seq, high
// pdb params: kStream
void NiPSysModifier::LoadBinary(NiStream& kStream)
{
    NiObject::LoadBinary(kStream);
    if (kStream.m_uiNifVersion < 0x14010001)
        kStream.ReadFixedString(m_kName);
    else
        kStream.ReadStringTableEntry(m_kName);

    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &m_uiOrder);
    kStream.ResetStreamState();
    unsigned char ucActive;
    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &ucActive);
    m_bActive = ucActive != 0;
}

// @fnv 0x00C31780
// pdb: NiPSysModifier::CopyMembers | NiPSysModifier.obj | fnv360_0822_retail, call_seq, medium, conflict (bridge: NiPSysBombModifier::NiPSysBombModifier)
// pdb params: pkDest, kCloning
void NiPSysModifier::CopyMemberData(NiPSysModifier* pkDest, CloningProcess& kCloning)
{
    NiObject::CreateVertexBufferSet(pkDest, kCloning);
    char* pcName = m_kName.m_kHandle;
    if (pkDest->m_kName.m_kHandle != pcName)
    {
        if (pcName != EmptyFS.m_kHandle)
            InterlockedIncrement(reinterpret_cast<volatile long*>(pcName - 8));
        char* pcOldName = pkDest->m_kName.m_kHandle;
        if (pcOldName != EmptyFS.m_kHandle)
            InterlockedDecrement(reinterpret_cast<volatile long*>(pcOldName - 8));
        pkDest->m_kName.m_kHandle = pcName;
    }
    pkDest->m_uiOrder = m_uiOrder;
    pkDest->m_bActive = m_bActive;
}

// @fnv 0x00C317E0
// pdb: NiPSysModifier::ProcessClone | NiPSysModifier.obj | fnv360_0822_retail, vtable, high
// pdb params: kCloning
void NiPSysModifier::ProcessClone(CloningProcess& kCloning)
{
    NiObject::ProcessClone(kCloning);
    NiObject* pkClone = 0;
    NiPSysCloneMapGetAt(kCloning.m_pCloneMap, this, pkClone);
    NiPSysModifier* pkDest = static_cast<NiPSysModifier*>(pkClone);
    NiPSysCloneMapGetAt(kCloning.m_pCloneMap, reinterpret_cast<NiObject*>(m_pkTarget), pkClone);
    pkDest->m_pkTarget = reinterpret_cast<NiParticleSystem*>(pkClone);
}

// @fnv 0x00C31650
// pdb: NiPSysModifier::LinkObject | NiPSysModifier.obj | fnv360_0822_retail, call_seq, high
// pdb params: kStream
void NiPSysModifier::LinkObject(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    kStream.GetLoadedObject();
}

struct NiPSysModifier_shell : NiPSysModifier
{
    void FUN_00c31640(NiParticleSystem* pkTarget);
};

// @fnv 0x00c31640
// pdb: BaseProcess::SetCurrentProcedureIndex | BaseProcess.obj | fnv360_0822_retail, vtable, medium
// pdb params: aiNewIndex
void NiPSysModifier_shell::FUN_00c31640(NiParticleSystem* pkTarget)
{
    m_pkTarget = pkTarget;
}

bool __stdcall IsSameAs(NiObject* pkObject);
struct MyIsEqual : NiPSysModifier
{
    bool FUN_00c31830(NiObject* pkObject);
};
// Compares this object with a NiPSysModifier: checks IsSameAs, then fields at offsets 8, 0xc and 0x14 for equality.
// @fnv 0x00c31830
// pdb: NiPSysModifier::IsEqual | NiPSysModifier.obj | fnv360_0822_retail, call_seq, medium
// pdb params: pkObject
bool MyIsEqual::FUN_00c31830(NiObject* pkObject)
{
    NiPSysModifier* pkDest = (NiPSysModifier*)pkObject;
    if (IsSameAs(pkObject) && *(void**)&m_kName == *(void**)&pkDest->m_kName &&
        m_uiOrder == pkDest->m_uiOrder && m_bActive == pkDest->m_bActive)
        return true;
    return false;
}

struct NiObjectBase
{
    bool RegisterStreamables(NiStream&);
};
struct StreamHack
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(void*);
};
struct X : NiPSysModifier
{
    bool FUN_00c31670(NiStream&);
};
// Registers streamables via NiObjectBase::RegisterStreamables and, on success, calls vf8 on the stream with this+8.
// @fnv 0x00c31670
// pdb: NiPSysModifier::RegisterStreamables | NiPSysModifier.obj | fnv360_0822_retail, call_seq, medium
// pdb params: kStream
bool X::FUN_00c31670(NiStream& kStream)
{
    if (!((NiObjectBase*)this)->RegisterStreamables(kStream))
        return false;
    ((StreamHack*)&kStream)->vf8(&m_kName);
    return true;
}

struct OutputBinaryStream : NiBinaryStream
{
    __forceinline void WriteComponents(const void* data, unsigned int bytes, unsigned int* componentSizes,
                                       unsigned int componentCount)
    {
        unsigned int written = m_pfnWrite(this, data, bytes, componentSizes, componentCount);
        m_uiStreamFlags += written;
    }
};
struct OutputStream : NiStream
{
    OutputBinaryStream* m_pBackingStream;
    void WriteObjectLink(NiFixedString&);
};
struct LinkOutput
{
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1c();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2c();
    virtual void SaveObject(NiParticleSystem*);
};
struct BinaryObjectBase
{
    void* vtable;
    unsigned int referenceCount;
    void FUN_00a89af0(OutputStream&);
};
struct ParticleModifierBinary : BinaryObjectBase
{
    NiFixedString name;
    unsigned int order;
    NiParticleSystem* target;
    bool active;
    void FUN_00c31950(OutputStream&);
};
template <class T> __forceinline void PrimitiveWrite(OutputBinaryStream* stream, const T& value)
{
    unsigned int size = sizeof(T);
    stream->WriteComponents(&value, sizeof(T), &size, 1);
}
__forceinline void BooleanWrite(OutputBinaryStream* stream, bool value)
{
    unsigned int size = 1;
    stream->WriteComponents(&value, 1, &size, 1);
}
// @fnv 0x00c31950
void ParticleModifierBinary::FUN_00c31950(OutputStream& stream)
{
    FUN_00a89af0(stream);
    stream.WriteObjectLink(name);
    PrimitiveWrite(stream.m_pBackingStream, order);
    reinterpret_cast<LinkOutput*>(&stream)->SaveObject(target);
    BooleanWrite(stream.m_pBackingStream, active);
}

extern "C" char* DAT_0109b220;
extern "C" void(__stdcall* DAT_00fdf1c0)(char*);
extern "C" void(__stdcall* DAT_00fdf1c4)(char*);

struct StrArr
{
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& pElement);
    __forceinline void Add(char* pElement)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pElement);
    }
};

struct FUN_00c319e0_cls : ParticleModifierBinary
{
    void FUN_00c319e0(StrArr* apViewerStrings);
};

// Appends the modifier's name, order and active flag as formatted strings to the given string array.
// @f3 0x00ab5420 (community match, verified in this file)
struct Array482 {
    void* table;char** data;unsigned short capacity,size,effective,growth;
    void FUN_00555790(unsigned int);void FUN_005b3880(unsigned int,char*&);
    __forceinline void Add(char* value) {
        unsigned int index=size;
        if(index>=capacity) FUN_00555790(index+growth);
        FUN_005b3880(index,value);
    }
};
struct Base482 { void FUN_00abcb40(StrArr*); };
struct Layout482 {
    unsigned int unk0,unk4,unk8,unkc,unk10,unk14,unk18,unk1c;
    unsigned int unk20,unk24,unk28,unk2c,unk30,unk34,unk38,unk3c;
    unsigned int unk40,unk44,unk48,unk4c,unk50,unk54,unk58;
    const char* name; unsigned short order;
};
extern const char* DAT_0116db0c;
extern const char DAT_00e8b13c[],DAT_00e8b128[];
char* __cdecl FUN_00847b50(const char*);
char* __cdecl FUN_00847e20(const char*,const char*);
char* __cdecl FUN_00847ce0(const char*,unsigned int);
// pdb: BSPSysMultiTargetEmitterCtlr::GetViewerStrings | BSPSysMultiTargetEmitterCtlr.obj | fnv360_0822_retail, vtable, medium
// pdb params: pkStrings
void FUN_00c319e0_cls::FUN_00c319e0(StrArr* strings) {
    reinterpret_cast<Base482*>(this)->FUN_00abcb40(strings);
    Array482* array=reinterpret_cast<Array482*>(strings);
    Layout482* owner=reinterpret_cast<Layout482*>(this);
    array->Add(FUN_00847b50(DAT_0116db0c));
    array->Add(FUN_00847e20(DAT_00e8b13c,owner->name));
    array->Add(FUN_00847ce0(DAT_00e8b128,owner->order));
}


extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void __cdecl FUN_00aa1460(void* pvMem, unsigned int uiSize);

namespace c318 {
extern char* DAT_0109b220;
}

class NiFixedStringC318
{
  public:
    ~NiFixedStringC318()
    {
        if (m_kHandle != c318::DAT_0109b220)
            InterlockedDecrement((long volatile*)(m_kHandle - 8));
    }
    char* m_kHandle;
};

class FUN_00a5d3d0
{
  public:
    virtual ~FUN_00a5d3d0();
    long m_uiRefCount;
};

class NamedC318 : public FUN_00a5d3d0
{
  public:
    virtual ~NamedC318()
    {}

    static void operator delete(void* pvMem, unsigned int uiSize)
    {
        FUN_00aa1460(pvMem, uiSize);
    }

    NiFixedStringC318 m_kName;
    int unk0C[3];

    NamedC318* FUN_00c31870(unsigned int uiFlags);
};

// Releases the NamedC318 object, calling its destructor and freeing memory when uiFlags has bit 0 set, then returns this.
// @fnv 0x00c31870
// pdb: NiPSysModifier::`scalar deleting destructor' | NiPSysModifier.obj | fnv360_0822_retail, objrun, high
NamedC318* NamedC318::FUN_00c31870(unsigned int uiFlags)
{
    this->NamedC318::~NamedC318();
    if (uiFlags & 1)
        NamedC318::operator delete(this, sizeof(NamedC318));
    return this;
}

// fallout/misc/saveload/bgssaveloadfile.cpp: BGSSaveLoadFileEntry, SaveLoadFile, BGSSaveLoadManager (2 functions)
#include "f3_common.h"
#include "bgssaveloadfile_types_BGSSaveLoadFile.h"
#include "bgssaveloadfile_types_BGSSaveLoadFileEntry.h"
#include "bgssaveloadfile_types_BGSSaveLoadManager.h"
#include "bgssaveloadfile_types_BGSSaveLoadHeader.h"
#include "bgssaveloadfile_types_NiTexture.h"
#include "MemoryManager.h"

class BSFile
{
  public:
    char opaque[0x158];
    BSFile(const char*, int, unsigned int, bool);
    unsigned int Read(void*, unsigned int);
    unsigned int GetFilePosition();
};

class FNVFileSeek
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void Seek(int, int);
};

extern BGSSaveLoadManager* DAT_011de134;
extern int DAT_010a2480;

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
void __cdecl ReadSaveFileHeader(void*, void*);
NiTexture* __cdecl LoadTextureFromFile(SaveLoadHeader*, unsigned int, unsigned int, unsigned int);
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
template <class T> unsigned int __cdecl BSStringLength(const T*);

// @fnv 0x008461e0
SaveLoadFile::SaveLoadFile(const char* fileName, bool flag, unsigned int size)
{
    pFile = 0;
    m_uiBufferSize = 0;
    m_uiFilePosition = 0;
    m_cFileName[0] = 0;
    if (!DAT_011de134->FUN_00424940())
        pFile = new BSFile(fileName, flag ? 1 : 0, size, false);
}

struct VDestruct008462c0
{
    virtual ~VDestruct008462c0();
};

class UnknownVtbl008463c0
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual bool vfn_20(int, int);
};

struct UnknownOwner008463c0
{
    char pad[0x104];
    UnknownVtbl008463c0* unk104;
};

extern int DAT_010a2484;

struct FUN_00846490_t
{
    char pad_000[0x104];
    FNVFileSeek* file;
    int unk_108;
    int pos_10c;
    void AdvancePosition(int offset);
};

struct FUN_008464f0_arg
{
    const char* str;
    int unk04;
};

// @f3 0x007ab550 (community match, verified in this file)
struct FUN_008464f0_mem
{
    int FUN_00799390(char* owner, const char* str, int unk04);
    void FUN_007993c0(int value);
};
struct FUN_008464f0_obj
{
    int unk00;
    FUN_008464f0_mem* unk04;
};
void __fastcall FUN_008464f0(char* pThis, FUN_008464f0_arg aStringArg)
{
    FUN_008464f0_obj* self = (FUN_008464f0_obj*)pThis;
    int r = self->unk04->FUN_00799390(pThis, aStringArg.str, aStringArg.unk04);
    self->unk04->FUN_007993c0(r);
}


struct FUN_008467b0_shell : public BGSSaveLoadFileEntry
{
    bool LoadSaveEntry();
};

struct BGSSaveLoadManager_ext : public BGSSaveLoadManager
{
    bool LoadGame(const char*, int, bool, bool);
};

namespace fnv_00846a20 {
struct _FILETIME_
{
    unsigned int dwLowDateTime;
    unsigned int dwHighDateTime;
};

struct _WIN32_FIND_DATAA_
{
    unsigned int dwFileAttributes;
    _FILETIME_ ftCreationTime;
    _FILETIME_ ftLastAccessTime;
    _FILETIME_ ftLastWriteTime;
    unsigned int nFileSizeHigh;
    unsigned int nFileSizeLow;
    unsigned int dwReserved0;
    unsigned int dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};

__declspec(dllimport) void* __stdcall FindFirstFileA(const char*, _WIN32_FIND_DATAA_*);
__declspec(dllimport) int __stdcall FindClose(void*);

struct BGSSaveLoadManager_ext : public BGSSaveLoadManager
{
    void GetFullPath(char*, char*, bool);
};

}  // namespace fnv_00846a20

namespace fnv_00846ad0 {
struct BGSSaveLoadManager_ext : public BGSSaveLoadManager
{
    bool IsQuickSaveFileName(const char*);
};

}  // namespace fnv_00846ad0

namespace fnv_00846af0 {
struct BGSSaveLoadManager_ext : public BGSSaveLoadManager
{
    bool IsSaveFileNameLegacyAutosave(const char*);
};

}  // namespace fnv_00846af0

struct MemoryManagerStatic
{
    static void* __cdecl Allocate(unsigned int);
};
void* __cdecl memset(void*, int, unsigned int);
int __cdecl strcpy_s(char*, unsigned int, const char*);
unsigned int __cdecl _strlen(const char*);
struct FUN_008465b0_stub
{
    char* name;
    char f4;
    char f5;
    int f8, fc, f10, f14, f18, f1c, f20, f24, f28;
    char blk[8];
    int f34;
    FUN_008465b0_stub(const char* src, int p);
};

struct FUN_00473180_shell
{
    unsigned int FUN_00473180(const char*, unsigned int);
};
struct FUN_00846330_shell
{
    unsigned int WriteToFile(const void* apBuffer, unsigned int aiBytes);
};

struct FUN_00846710_mgr_view
{
    bool Probe00851980(const char* apName);
    bool Probe00851a20(const char* apName);
    bool Probe008503b0(const char* apName, int aiDeviceID, int aiFlag);
    void Probe00851620(void* apEntry);
};

struct FUN_00846710_cls : public BGSSaveLoadFileEntry
{
    void DispatchEvent();
    bool FUN_00846710();
};

class C8467E0Event;

class C8467E0Manager
{
  public:
    void DeleteWeaponFile(unsigned int uiType, int iData);
    void RemoveAndDelete(C8467E0Event* pkEvent);
};

extern C8467E0Manager* g_pk8467E0Manager;

class C8467E0Event
{
  public:
    unsigned int m_uiType;
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
    int m_iData;

    void DispatchEvent();
};

struct FUN_00850330_class
{
    char* FUN_00850330(unsigned int);
};
struct GlobalObject_0045cfe0
{
    int* Int();
};
extern GlobalObject_0045cfe0 DAT_011de2c8;
int __cdecl strcat_s(char*, unsigned int, const char*);
int __cdecl FUN_00ecbf05(const char*, int);
int __cdecl FUN_00ec862c(const char*, const char*);
__declspec(dllimport) int __stdcall DeleteFileA(const char*);
struct MgrShell
{
    void GetFullPath(char*, char*, unsigned char);
};
struct FUN_006815c0_Class
{
    void* FUN_006815c0();
};

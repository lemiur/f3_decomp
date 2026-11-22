// fallout/misc/scenegraph.cpp: SceneGraph, StandIn (1 function)
#include "f3_common.h"
class NiRTTI;

class BSSceneGraph
{
  public:
    virtual const NiRTTI* GetRTTI() const;
};

class SceneGraph : public BSSceneGraph
{
  public:
    static const NiRTTI ms_kRTTI;
    virtual const NiRTTI* GetRTTI() const;
};

extern int DAT_01083b5c;

struct Base_00c517b0
{
    void FUN_00c517b0(char*, bool, void*);
};

struct Wrapper_00878610 : Base_00c517b0
{
    void* FUN_00878610(char* apSceneGraphName, bool abMenuSceneGraph, void* apCamera);
};

// @f3 0x006a2e70 (community match, verified in this file)
struct Base_6a13f0
{
    void FUN_006a13f0(char* apName, bool abFlag, void* apCamera);
};

extern int DAT_00e09dbc;

void* Wrapper_00878610::FUN_00878610(char* apSceneGraphName, bool abMenuSceneGraph, void* apCamera)
{
    ((Base_6a13f0*)this)->FUN_006a13f0(apSceneGraphName, abMenuSceneGraph, apCamera);
    *(void**)this = (void*)&DAT_00e09dbc;
    *(int*)((char*)this + 0x48) = *(int*)(*(int*)((char*)apCamera + 0x14) + 0x60);
    return this;
}


struct FUN_008786b0_shell : public SceneGraph
{
    float FUN_008786b0();
};

union SETTING_VALUE
{
    float f;
};
class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};
class BGSTerrainManager
{
  public:
    bool FUN_00454b70();
};
class TESWorldSpace
{
  public:
    BGSTerrainManager* GetWorldTerrainManager();
};
class Sky
{
  public:
    int FUN_00476c90();
};
class TESObjectCELL
{
  public:
    float GetInteriorLightValue();
};
class BGSCameraPath
{
  public:
    BGSCameraPath* GetPrevPath();
};
class TES
{
  public:
    TESWorldSpace* GetHitSound();
    Sky* GetLogDate();
};

extern TES* g_TES;
extern SettingT_GameSettingCollection_ g_01203120;
extern SettingT_GameSettingCollection_ g_0120312c;
extern SettingT_GameSettingCollection_ g_01203138;
extern float DAT_01083c64;
extern float DAT_010c26d8;
extern double _gModifierZero;

float __cdecl LinearInterpolate(float, float, float, float, float);

struct StandIn
{
    void __thiscall FUN_00878690();
    void* __thiscall DestroyIfFlagged(unsigned int);
};
void __cdecl _delete(void*, unsigned int);

extern int DAT_01083b5c;

struct FUN_00878690_shell
{
    void FUN_00878690();
    void FUN_00c51df0();
};

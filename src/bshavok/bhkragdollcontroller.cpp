// bshavok/bhkragdollcontroller.cpp: bhkRagdollController (1 function)
#include "f3_common.h"


extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern char* EmptyFS;
struct FixedStr
{
    char* h;
    FixedStr(const FixedStr& o)
    {
        if (o.h != EmptyFS)
            InterlockedIncrement((long volatile*)(o.h - 8));
        h = o.h;
    }
    ~FixedStr()
    {
        if (h != EmptyFS)
            InterlockedDecrement((long volatile*)(h - 8));
    }
    bool Equals(const char*) const;
};
struct Mat3
{
    float m[9];
};
struct Pt3
{
    float x, y, z;
};
struct Xform
{
    Mat3 rot;
    Pt3 trans;
    float scale;
};
struct RNode;
struct RObj
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual RNode* GetAsNode();
    int _4;
    FixedStr name;
    char _c[0xc];
    RObj* parent;
    char _1c[0x18];
    Xform local;
};
struct RNode
{
    char _0[0xa0];
    RObj** children;
    unsigned short _a4;
    unsigned short count;
};
struct RKey
{
    FixedStr name;
    RObj* obj;
    RKey(const FixedStr& n) : name(n)
    {}
};
struct RElem
{
    RObj* obj;
    Xform x;
};
struct RArr
{
    int _0;
    RElem* data;
    int AppendSlot();
    void ConstructElementArray(RElem*, int);
};
struct RCtx;
RObj* __cdecl FUN_00c4b470(RCtx*, RKey*, int);

// @fnv 0x00c7bcb0
// pdb: bhkRagdollController::CopyPoseTo3DRec | bhkRagdollController.obj | fnv360_0822_retail, ustr_rel + bridge(ustr_rel|caller_sim), high
void __cdecl bhkRagdollController_CopyPoseTo3DRec(RCtx* ctx, RObj* obj, RArr* arr)
{
    RKey key(obj->name);
    key.obj = obj;
    if (key.name.Equals("Bip01 NonAccum"))
        key.obj = obj->parent;
    RObj* bone = FUN_00c4b470(ctx, &key, 1);
    if (bone)
    {
        RElem e;
        e.obj = bone;
        e.x = bone->local;
        int idx = arr->AppendSlot();
        arr->ConstructElementArray(&arr->data[idx], 1);
        const Xform& src = key.obj->local;
        arr->data[idx] = e;
        bone->local.rot = src.rot;
        bone->local.trans = src.trans;
    }
    RNode* node = obj->GetAsNode();
    if (node)
    {
        for (unsigned int i = 0; i < node->count; i++)
        {
            RObj* child = node->children[i];
            if (child)
                bhkRagdollController_CopyPoseTo3DRec(ctx, child, arr);
        }
    }
}

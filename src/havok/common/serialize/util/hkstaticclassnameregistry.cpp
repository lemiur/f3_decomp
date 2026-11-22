#include "f3_common.h"
// src/havok/common/serialize/util/hkstaticclassnameregistry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/util/hkstaticclassnameregistry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct SlotEntry
{
    int unk00;
    SlotEntry* Key();
};

int __cdecl MatchSlotKey(void* p, SlotEntry* key);

struct FUN_00db7ae0_cls
{
    int unk00;
    int unk04;
    int unk08;
    SlotEntry** m_slots;

    void ResetSlots();
    SlotEntry* FindSlotByKey(void* p);
};

// Resets the slot table, then scans m_slots for the first entry whose Key matches p via MatchSlotKey and returns it, or 0 if none match.
// @fnv 0x00db7ae0
SlotEntry* FUN_00db7ae0_cls::FindSlotByKey(void* apKey)
{
    ResetSlots();
    int i = 0;
    if (m_slots[i] != 0)
    {
        do
        {
            SlotEntry* key = m_slots[i]->Key();
            if (MatchSlotKey(apKey, key) == 0)
            {
                return m_slots[i];
            }
            i++;
        } while (m_slots[i] != 0);
    }
    return 0;
}

struct FUN_00db7b40
{
    virtual void v0();
    unsigned short unk04;
    unsigned short unk06;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    FUN_00db7b40(int a, int b, int c);
};

struct FUN_00db7b70_Array
{
    void** data;
    int count;
    int capacity;
};

struct FUN_00c85750_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    void* unk10;
};

struct FUN_00db7b70_Class
{
    int unk00;
    int unk04;
    int unk08;
    void** unk0c;
    int unk10;
    int unk14;
    void EnsureInitialized();
    void AppendToArray(FUN_00db7b70_Array* p);
};

void* FUN_00c85750();
void __cdecl FUN_00c908c0(void* mm, FUN_00db7b70_Array* arr, int count, int size);

struct FnvCpu_FUN_00db7a70_CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    int value;
    int FUN_00db7a70();
};
// @fnv 0x00db7a70
int FnvCpu_FUN_00db7a70_CpuObject::FUN_00db7a70()
{
    return value;
}

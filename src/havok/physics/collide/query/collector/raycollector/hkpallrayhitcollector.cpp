#include "f3_common.h"
// src/havok/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/query/collector/raycollector/hkpallrayhitcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl FUN_00c852c0(void* owner, int a2, int a3, int a4);

class FUN_00c855f0_cls
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_10;
    int m_14;

    void FUN_00c855f0();
};

// If m_14 exceeds 1, calls FUN_00c852c0 on m_10 with 0 and m_14 - 1.
// @fnv 0x00c855f0
void FUN_00c855f0_cls::FUN_00c855f0()
{
    union
    {
        volatile unsigned char b;
        int i;
    } flag;
    flag.b = 0;
    if (m_14 > 1)
    {
        FUN_00c852c0(m_10, 0, m_14 - 1, flag.i);
    }
}

#include <xmmintrin.h>

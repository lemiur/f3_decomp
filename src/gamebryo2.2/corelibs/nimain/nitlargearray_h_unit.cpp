// gamebryo2.2/corelibs/nimain/nitlargearray_h_unit.cpp: free functions (0 functions)
#include "f3_common.h"
#include "nitlargearray.inl"

struct TESRegion;

struct BGSAcousticSpace
{
    void SetRegion(TESRegion*);
};

struct NiTLargeArray_TESTopicInfo
{
    void** m_ppVirtualMethodTable;
    unsigned int* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void SetSize(unsigned int index, unsigned int* value);
    TESTopicInfo* RemoveAt(unsigned int index);
    void Compact();
};

struct FUN_005ff560_shell
{
    TESTopicInfo* GetChildByIndex(unsigned int index);
    void RemoveChildAndRelinkNeighbors(unsigned int index);
};

// NiTPrimitiveArray: an NiTArray of plain values, allocated with malloc.
// Names: FNV360_PDB (NiTPrimitiveArray<T> : NiTArray<T, NiTMallocInterface<T> >).
#ifndef FNV_NITPRIMITIVEARRAY_H
#define FNV_NITPRIMITIVEARRAY_H
#include "layout_support.h"
template <class T> class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T> >
{
};
FNV_STATIC_ASSERT(sizeof(NiTPrimitiveArray<void*>) == 0x10);
#endif

// gamebryo2.2/corelibs/nisystem/nifile.cpp: NiFile (1 function)
#include "f3_common.h"
#include "nifile_packet.h"
// @fnv 0x00aa1a20
NiFile* NiFile::GetFile(const char* name, OpenMode mode, unsigned int bufferSize)
{
    return DAT_011ac224(name, mode, bufferSize);
}
// The dispatch helper retains the original unoptimized request construction.
#pragma optimize("", off)

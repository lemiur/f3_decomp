#include "f3_common.h"
// src/havok/common/base/container/string/hkstring.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/container/string/hkstring.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl FUN_00ecc7b0(char* dest, const char* src, int count);

// @fnv 0x00cb10b0
void __cdecl CopyIfNonEmpty(char* dest, const char* src, int count)
{
    if (count)
        FUN_00ecc7b0(dest, src, count);
}

struct BSAudio;
extern "C" BSAudio* __cdecl FUN_00c85750();

double __cdecl FUN_00ecdf2d(unsigned int value, int mode);
// @fnv 0x00cb1110
float __cdecl ConvertToFloat(unsigned int value)
{
    return FUN_00ecdf2d(value, 0);
}

class hkBool
{
  public:
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    char m_cBooleanValue;
};

int __cdecl FUN_00cb10d0(const char* text);

struct BSAudio
{
    int unk00, unk04, unk08, unk0c;
    int unk10;
};

BSAudio* FUN_00c85750();

// Reads unk10 from the BSAudio returned by FUN_00c85750 and passes it with a and b to FUN_00cb11b0.
// @f3 0x005435a0 (community match, verified in this file)
extern unsigned int FUN_00f5a830[];

void __cdecl FUN_00cb13e0(int aiArg1, int aiArg2)
{
    int* args = &aiArg2;
    void (__cdecl* pfn)(int, int, int, int, int) = (void (__cdecl*)(int, int, int, int, int))FUN_00f5a830[aiArg1 * 3];
    if (pfn)
    {
        pfn(args[0], args[1], args[2], args[3], args[4]);
    }
}


// @fnv 0x00cb1090
void __cdecl FUN_00cb1090(char* pcDest, const char* pcSrc)
{
    const char* s = pcSrc;
    char c;
    char* d = pcDest;
    int iOffset = d - s;
    do
    {
        c = *s;
        *(char*)(s + iOffset) = c;
        s++;
    } while (c);
}

// Compares two byte buffers over n bytes, four at a time, returning -1, 1 or 0 based on the first differing byte.
// @f3 0x004b20a0 (community match, verified in this file)
#include <string.h>
int __cdecl FUN_00cb1290(const unsigned char* left,const unsigned char* right,unsigned int count) {
    return memcmp(left,right,count);
}


const char* __cdecl FUN_00cb1150(const char* str, int c);

const char* __cdecl FUN_00cb1130(const char* a, const char* b);
int __cdecl FUN_00cb10d0(const char* text);
char* __cdecl FUN_00cb1140(const char* s, int c);

void __cdecl FUN_00ecddf1(int a, int b, int c, int d);

// @fnv 0x00cb0f50
void __cdecl FUN_00cb0f50(int a, int b, int c, int d)
{
    FUN_00ecddf1(a, b, c, d);
}

namespace fnv_00cb1140 {
extern "C" char* __cdecl _strchr(const char* s, int c);

// @fnv 0x00cb1140
char* __cdecl FUN_00cb1140(const char* s, int c)
{
    return _strchr(s, c);
}
}  // namespace fnv_00cb1140

namespace fnv_00cb1150 {
extern "C" const char* __cdecl FUN_00ec6e30(const char* str, int c);

// @fnv 0x00cb1150
const char* __cdecl FUN_00cb1150(const char* str, int c)
{
    return FUN_00ec6e30(str, c);
}
}  // namespace fnv_00cb1150

void* __cdecl _memmove(void* dst, const void* src, unsigned int count);

// @fnv 0x00cb1260
void* __cdecl FUN_00cb1260(void* dst, const void* src, unsigned int count)
{
    return _memmove(dst, src, count);
}

void* __cdecl FUN_00ec7230(char* a, const char* b, int c);
// @fnv 0x00cb1270
void* __cdecl FUN_00cb1270(char* a, const char* b, int c)
{
    return FUN_00ec7230(a, b, c);
}

extern void __cdecl FUN_00ec61c0(void* dest, int value, unsigned int count);

// @fnv 0x00cb1280
void __cdecl FUN_00cb1280(void* dest, int value, unsigned int count)
{
    FUN_00ec61c0(dest, value, count);
}

#include <stdarg.h>
extern "C" int __cdecl FUN_00ecddf1(char* buf, unsigned int n, const char* fmt, va_list args);

// @fnv 0x00cb0f60
int __cdecl Vsnprintf(char* buf, int n, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    int ret = FUN_00ecddf1(buf, n, fmt, args);
    va_end(args);
    return ret;
}

#include <string.h>
namespace fnv_00cb10d0 {
// @fnv 0x00cb10d0
int __cdecl FUN_00cb10d0(const char* apString)
{
    return (int)strlen(apString);
}
}  // namespace fnv_00cb10d0

namespace fnv_00cb1130 {
// @fnv 0x00cb1130
const char* __cdecl FUN_00cb1130(const char* a, const char* b)
{
    return strstr(a, b);
}
}  // namespace fnv_00cb1130

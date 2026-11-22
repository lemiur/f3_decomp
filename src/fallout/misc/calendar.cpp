// fallout/misc/calendar.cpp: Calendar, CalendarProxy, CalendarDateFormatter, Thing (1 function)
#include "f3_common.h"
#include "calendar_types_CALENDAR_MONTH.h"
#include "calendar_types_DAYS_OF_THE_WEEK.h"
#include "calendar_types_Calendar.h"
#include "calendar_decls.h"

// @f3 0x0044d5c0 (community match, verified in this file)
class MemoryManager
{
public:
    void Deallocate(void* pointer);
};

extern MemoryManager g_memoryManager;
extern int DAT_00dbb62c;

DAYS_OF_THE_WEEK Calendar::GetGameDayOfWeek()
{
    *(void**)this = (void*)&DAT_00dbb62c;
    g_memoryManager.Deallocate(*(void**)((char*)this + 8));
    *(unsigned char*)((char*)this + 5) = 0;
    *(void**)((char*)this + 8) = 0;
    return DAYS_OF_THE_WEEK_DAY_SUNDAY;
}


struct FUN_00867c60_shell : public Calendar
{
    unsigned int FUN_00867c60();
};

struct FUN_008aced0_cv
{
    char pad[0x44];
    unsigned int flags;
};
struct FUN_008aced0_cls
{
    char pad[0x2c];
    FUN_008aced0_cv* cached;
    bool HasCachedFlag(unsigned int aeWhich);
};

struct StartMenu
{
    const char* GetMenuTitle();
};
extern StartMenu* DAT_011895b8[7];
struct CalendarProxy : public Calendar
{
    const char* GetDayName();
};

extern double DAT_01012638;
struct FUN_00526ac0_shell
{
    float FUN_00526ac0();
};
struct FUN_00867ea0_shell
{
    char _pad[16];
    FUN_00526ac0_shell* m_ptr;
    float FUN_00867ea0();
};

// Calendar: format the current game date as "MM.DD.YY".

class DateString
{
  public:
    char* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    DateString();
    DateString(const DateString& kOther);
    ~DateString();
    int PrintfString(const char* pFormat, ...);
};

struct CalendarDateFormatter : public Calendar
{
    unsigned int GetYearNumber();
    char GetDayNumber();
    int GetMonthIndex();
    DateString FormatDate();
};

struct Thing
{
    int FUN_00867d20();
    int FUN_00867ca0();
};

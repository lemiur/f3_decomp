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


// Calendar: format the current game date as "MM.DD.YY".

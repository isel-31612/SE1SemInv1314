#include "../../includes/RTC.h"


void RTC_Init(struct tm *dt)
{
	RTC->CCR = 0x2; // desactiva os contadores e faz reset aos counter do rtc
	RTC_CLOCK->PREINT = (getPclk() / CLK_FREQ) -1;
	RTC_CLOCK->PREFRAC = getPclk() -((RTC_CLOCK->PREINT +1) * CLK_FREQ);
	
	RTC->ILR = 0x3;
	RTC->ILR = 0x0;
	
	RTC->CIIR = 0x0;
	RTC->AMR = 0xFF;
	
	//RTC_SetTime(14,20,00);
	RTC->HOUR = dt->tm_hour;
	RTC->MIN = dt->tm_min;
	RTC->SEC = dt->tm_sec;
	
	//RTC_SetDate(8,11,2013);
	RTC->DOM = dt->tm_mday;
	RTC->MONTH = dt->tm_mon;
	RTC->YEAR = dt->tm_year;
	
	//RTC_SetDays(5 ,365);
	RTC->DOW = dt->tm_wday;
	RTC->DOY = dt->tm_yday;
	
	RTC->CCR = 0x1;
}

void RTC_GetValue(struct tm *dateTime)
{
		RTC_ReadTime(dateTime);
		RTC_ReadDate(dateTime);
}

void RTC_ReadDate(struct tm *dt)
{
	
	unsigned int val0 = RTC->CTIME0;
	unsigned int val1 = RTC->CTIME1;
	unsigned int val2 = RTC->CTIME2;

	//RTC_SetDate(8,11,2013);
	dt->tm_mday = (val1 & MASK_DAY) >> OFFSET_DAY;
	dt->tm_mon = (val1 & MASK_MONTH) >> OFFSET_MONTH;
	dt->tm_year = (val1 & MASK_YEAR) >> OFFSET_YEAR;
	
	//RTC_SetDays(5 ,365);
	dt->tm_wday = (val0 & MASK_DAY_OF_WEEK) >> OFFSET_DAY_OF_WEEK;
	dt->tm_yday = (val2 & MASK_DAY_OF_YEAR) >> OFFSET_DAY_OF_YEAR;	
}

void RTC_ReadTime(struct tm *dt)
{
	unsigned int val0 = RTC->CTIME0;
	
	dt->tm_hour = (val0 & MASK_HOUR) >> OFFSET_HOUR;
	dt->tm_min = (val0 & MASK_MINUTE) >> OFFSET_MINUTE;
	dt->tm_sec = (val0 & MASK_SEC) >> OFFSET_SEC;
	
}

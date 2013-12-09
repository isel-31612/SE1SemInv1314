#include "../../includes/RTC.h"

int main()
{

	//time init structure
	struct tm ti;
	
	struct tm ret;
	struct tm retT;
	
	//RTC_SetTime(14,20,00);
	ti.tm_hour = 14;
	ti.tm_min = 20;
	ti.tm_sec = 00;
	
	//RTC_SetDate(8,11,2013);
	ti.tm_mday = 8;
	ti.tm_mon = 11;
	ti.tm_year = 2013;
	
	//RTC_SetDays(5 ,365);
	ti.tm_wday = 5;
	ti.tm_yday = 365;
	
	 
	RTC_Init(&ti);
	
	while(1)
	{
		RTC_GetValue(&ret);
		
		RTC_ReadDate(&retT);
		RTC_ReadTime(&retT);
		
	}
	
	return 0;
}

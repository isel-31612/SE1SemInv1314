#include "../../includes/SClk.h"
#include "../../includes/RTC.h"
#include "../../includes/LCD.h"

int main()
{

	//time init structure
	struct tm ti;
	struct tm ret;
	
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
	
	SYSCLK_Init(1000);		/* Acertar o clock do TIMER*/
	RTC_Init(&ti);
	LCD_Init();
	
	char buffer [16];
	
	while(1)
	{
		
		RTC_GetValue(&ret);
			
		LCD_Goto(0,0);
		strftime(buffer,16,"%T",&ret);
		LCD_WriteString(buffer);
		
	}
	
	return 0;
}

/*
 * Esta funcao é chamada quando é feito o MALLOC
 * Se alguma vez for chamado o MALOC o código ira ficar
 * bloquado aqui. Assim sabemos que alguem tentou usar o
 * MALOC e nos nao suportamos essa operacao 
 * */
int _sbrk(){ while(1); }


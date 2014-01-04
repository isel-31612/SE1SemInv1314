#include "../../includes/SClk.h"
#include "../../includes/Buttons.h"
#include "../../includes/RTC.h"

#include "App.h"
#include "ChangeTime.h"

unsigned int lastStateButton = 0;
unsigned int delayButton = 0;

//time init structure
struct tm ti;

//Esta função só é chamada quando houve algum botao pressionado
unsigned int decodeButtons(unsigned int bitmap)
{
	
	if(bitmap != 0) //botao pressionado
	{
		//Short press in radio
		if(bitmap & (BUTTON_DOWN | BUTTON_UP)) return CHANGE_RADIO;
		
		if(lastStateButton == 0){
			delayButton = SYSCLK_GetValue();
			lastStateButton = bitmap;
			return SHOW_HOURS;
		}
		
		//Caso nao tenha existido alterações nos botoes
		if(lastStateButton == bitmap && SYSCLK_Elapsed(delayButton)>MAX_PRESSED_BUTTON)
		{
			if(bitmap == BUTTON_MEN)
			{
				lastStateButton = 0;
				delayButton = 0;
				return CHANGE_HOURS;
			}
		}
	}
	delayButton = 0;
	lastStateButton = 0;
	return SHOW_HOURS;
	
}


int main()
{
	unsigned int nextState;
	unsigned int actualStateButton = 0;

	//Define a a data e hora que o sistema vai ter inicialmente
	//RTC_SetTime(00,00,00);
	ti.tm_hour = 00;
	ti.tm_min = 00;
	ti.tm_sec = 00;
	
	//RTC_SetDate(8,11,2013);
	ti.tm_mday = 8;
	ti.tm_mon = 11;
	ti.tm_year = 2013;
	
	//RTC_SetDays(5 ,365);
	ti.tm_wday = 5;
	ti.tm_yday = 365;
	
	//System init
	SYSCLK_Init(1000); /* Acertar o clock do TIMER*/
	RTC_Init(&ti); /* Iniciar o RTC com a data e hora definida inifialmente*/

	while(1)
	{

		actualStateButton = Button_Read();
		nextState = decodeButtons(actualStateButton);
		
		switch(nextState)
		{

			case CHANGE_HOURS:
				changeHours(&ti);
				break;
				
			case CHANGE_RADIO:
				break;
			
			case SHOW_HOURS:
				break;
				
			default:
				//mostra horas caso algo corra mal
				break;
		}

	}	
	return 0;
}

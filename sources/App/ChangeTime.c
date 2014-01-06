#include "../../includes/Buttons.h"
#include "../../includes/RTC.h"
#include "../../includes/LCD.h"
#include "ChangeTime.h"

unsigned int lastStateButton_time = 0;

unsigned int delayButton_time = 0;
unsigned int delayClick = 0;

unsigned int actualPosition = 0;

unsigned int firstClick = 1;

char str1[] = {'M','U','D','A','R',' ','H','O','R','A','S','\0'};
char buffer [16];

enum position {hours,minutes};
// Ver outra forma de saber o tamanho do enumerado
#define LEN_ENUM 2

unsigned int decodeButtons_inHours(unsigned int bitmap)
{
	if(bitmap != 0) //botao pressionado
	{
		
		if(delayClick == 0) delayClick = SYSCLK_GetValue(); 
		if(SYSCLK_Elapsed(delayClick) < DELAY_CLICK) return DO_NOTHING;
		
		delayClick = 0;
		
		//Short press
		if(bitmap & BUTTON_DOWN)
		{
			if(actualPosition == hours) return DEC_HOURS;
			if(actualPosition == minutes) return DEC_MINUTES;
		}

		if(bitmap & BUTTON_UP)
		{
			if(actualPosition == hours) return INC_HOURS;
			if(actualPosition == minutes) return INC_MINUTES;
		}

		if(lastStateButton_time == 0 && bitmap == BUTTON_MEN){
			delayButton_time = SYSCLK_GetValue();
			lastStateButton_time = bitmap;
			return CHANGE_FIELD;
		}

		//Caso nao tenha existido alterações nos botoes
		if(lastStateButton_time == bitmap && bitmap == BUTTON_MEN && SYSCLK_Elapsed(delayButton_time)>MAX_PRESSED_BUTTON_TIME)
		{
			lastStateButton_time = 0;
			delayButton_time = 0;
			return SET_HOURS;
		}
		
		if(lastStateButton_time == bitmap && bitmap != BUTTON_MEN)
		{
			return DO_NOTHING;
		}
	}else
	{
		delayButton_time = 0;
		lastStateButton_time = 0;
		firstClick = 0;
	}
	return DO_NOTHING;
}

void incrementHours(struct tm *dt)
{
	dt->tm_hour = (dt->tm_hour+1) % 23;
}

void decrementHours(struct tm *dt)
{
	if(dt->tm_hour==0)
	{
		 dt->tm_hour = 23; 
		return;
	}
	dt->tm_hour -= 1;
}

void incrementMinutes(struct tm *dt)
{
	dt->tm_min = (dt->tm_min+1)%59;
}

void decrementMinutes(struct tm *dt)
{
	if(dt->tm_min==0)
	{
		dt->tm_min = 59;
		return;
	}
	dt->tm_min -= 1;
}

void changeHours(struct tm *dt)
{
	unsigned int buttonsState;
	unsigned int nextState;
	
	LCD_Clear();
	LCD_Goto(0,1);
	LCD_WriteString(str1);
	
	while(nextState != SET_HOURS)
	{
		buttonsState = Button_Read();
		nextState = decodeButtons_inHours(buttonsState);
		
		//Actualizar o LCD para os novos valores das horas
		LCD_Goto(0,0);
		strftime(buffer,16,"%T",dt);
		LCD_WriteString(buffer);

		switch(nextState)
		{
			case INC_HOURS:
				LCD_Goto(0,1);
				incrementHours(dt);
				break;
				
			case DEC_HOURS:
				LCD_Goto(0,1);
				decrementHours(dt);
				break;
			
			case INC_MINUTES:
				LCD_Goto(0,4);
				incrementMinutes(dt);
				break;
			
			case DEC_MINUTES:
				LCD_Goto(0,4);
				decrementMinutes(dt);
				break;
			
			case CHANGE_FIELD:
				actualPosition = (actualPosition + 1)%LEN_ENUM;
				break;
					
			default:
				break;
		}
	}
	RTC_SetTime(dt);
	RTC_SetDate(dt);
	RTC_SetDays(dt);
	LCD_Clear();

}

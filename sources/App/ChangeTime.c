#include "../../includes/Buttons.h"
#include "../../includes/RTC.h"
#include "ChangeTime.h"

unsigned int lastStateButton_time = 0;
unsigned int delayButton_time = 0;
unsigned int actualPosition = 0;

enum position {hours,minutes};

// Ver outra forma de saber o tamanho do enumerado
#define LEN_ENUM 2

unsigned int decodeButtons_inHours(unsigned int bitmap)
{

	if(bitmap != 0) //botao pressionado
	{
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
		if(lastStateButton_time == bitmap && bitmap == BUTTON_MEN && SYSCLK_Elapsed(delayButton_time)>MAX_PRESSED_BUTTON)
		{
			lastStateButton_time = 0;
			delayButton_time = 0;
			return FULL_RETURN;
		}
	
	}
	delayButton_time = 0;
	lastStateButton_time = 0;
	return DO_NOTHING;
}

void incrementHours(struct tm *dt)
{
	dt->tm_hour += 1;
}

void decrementHours(struct tm *dt)
{
	dt->tm_hour -= 1;
}

void incrementMinutes(struct tm *dt)
{
	dt->tm_min += 1;
}


void decrementMinutes(struct tm *dt)
{
	dt->tm_min -= 1;
}

void changeHours(struct tm *dt)
{
	unsigned int buttonsState;
	unsigned int nextState;
	
	buttonsState = Button_Read();
	nextState = decodeButtons_inHours(buttonsState);
	
	while(nextState != SET_HOURS)
	{
		switch(nextState)
		{
			
			case INC_HOURS:
				incrementHours(dt);
				break;
				
			case DEC_HOURS:
				decrementHours(dt);
				break;
			
			case INC_MINUTES:
				incrementMinutes(dt);
				break;
			
			case DEC_MINUTES:
				decrementMinutes(dt);
				break;
			
			case CHANGE_FIELD:
				actualPosition = (actualPosition + 1)%LEN_ENUM;
				break;
			
			case FULL_RETURN:
				return;
				break;
				
			default:
				break;

		}
		
	}
	
}

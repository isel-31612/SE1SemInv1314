#include "../../includes/Buttons.h"
#include "../../includes/RTC.h"
#include "../../includes/LCD.h"
#include "../../includes/RADIO.h"
#include "ChangeRadio.h"

unsigned int lastStateButton_radio = 0;
unsigned int delayButton_radio = 0;
unsigned int delayClick_radio = 0;

char scan_radio_up[] = {'S','C','A','N',' ','U','P','\0'};
char scan_radio_down[] = {'S','C','A','N',' ','D','N','\0'};
char scan_up[] = {'U','P','.','\0'};
char scan_down[] = {'D','O','W','N','\0'};

unsigned int decodeButtons_inRadio(unsigned int bitmap)
{
	if(bitmap != 0) //botao pressionado
	{
		if(delayClick_radio == 0) delayClick_radio = SYSCLK_GetValue(); 
		if(SYSCLK_Elapsed(delayClick_radio) < DELAY_CLICK_RADIO) return DO_NOTHING_RADIO;
	
		//Long Press
		if(lastStateButton_radio == bitmap && SYSCLK_Elapsed(delayButton_radio)>MAX_PRESSED_BUTTON_RADIO)
		{
			delayClick_radio = 0; //Só limpa depois de ter havido long press
			if(bitmap & BUTTON_DOWN)
			{
				return SCAN_DOWN;
			}
			if(bitmap & BUTTON_UP)
			{
				return SCAN_UP;
			}
			if(bitmap & BUTTON_MEN)
			{
				return SAVE_STATION;
			}
		}
		//Short press
		if(lastStateButton_radio == 0)
		{
			delayButton_radio = SYSCLK_GetValue();
			lastStateButton_radio = bitmap;
			
			if(bitmap & BUTTON_DOWN)
			{
				return PREV_STATION;
			}
			
			if(bitmap & BUTTON_UP)
			{
				return NEXT_STATION;
			}
		}else{
			return DO_NOTHING_RADIO;
		}
		
	}else
	{
		delayButton_radio = 0;
		lastStateButton_radio = 0;
		return OUT_RADIO;
	}
}


void changeRadio(TEA5767 *rad)
{
	unsigned int buttonsState;
	unsigned int nextState;
	
	while(nextState != OUT_RADIO)
	{
		buttonsState = Button_Read();
		nextState = decodeButtons_inRadio(buttonsState);
		
		switch(nextState)
		{
			case PREV_STATION:
				LCD_Goto(0,1);
				LCD_WriteString(scan_down);
				break;
			
			case NEXT_STATION:
				LCD_Goto(0,1);
				LCD_WriteString(scan_up);
				break;
			
			case SCAN_DOWN:
				LCD_Goto(0,1);
				LCD_WriteString(scan_radio_down);
				break;
			
			case SCAN_UP:
				LCD_Goto(0,1);
				LCD_WriteString(scan_radio_up);
				break;
			
			case SAVE_STATION:
				break;
			
			default:
				break;
		}
	}
}

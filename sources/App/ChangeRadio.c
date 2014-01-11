#include "../../includes/Buttons.h"
#include "../../includes/RTC.h"
#include "../../includes/LCD.h"
#include "../../includes/RADIO.h"
#include "ChangeRadio.h"

unsigned int lastStateButton_radio = 0;
unsigned int delayButton_radio = 0;
unsigned int delayClick_radio = 0;
char mute = MUTE_OFF;

char scan_radio[] = {'S','C','A','N',' .','.','.','\0'};

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
			
			if(bitmap & BUTTON_DOWN)	return SCAN_DOWN;
			
			if(bitmap & BUTTON_UP)		return SCAN_UP;

			if(bitmap & BUTTON_MEN)		return SAVE_STATION;

		}
		//Short press
		if(lastStateButton_radio == 0)
		{
			delayButton_radio = SYSCLK_GetValue();
			lastStateButton_radio = bitmap;
			
			if(bitmap & BUTTON_DOWN)	return PREV_STATION;

			if(bitmap & BUTTON_UP)		return NEXT_STATION;
			
			if(bitmap & BUTTON_MEN)		return MUTE;
			
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

void searchStation(int search,TEA5767 *rad)
{
	float sta;
	sta = RADIO_GetFreq(rad);
	
	if(search & SEARCH_UP)
	{
		if(sta > 108) sta = 87.4;
		sta+=0.1;
	}else
	{
		if(sta < 87.5) sta = 108.1;
		sta-=0.1;
	}
	RADIO_SetFreq(sta);
	WriteData();
}

void scanStation(int search, TEA5767 * rad)
{
	int tmp = STATION_NOK;

	do
	{
		if(tmp != IN_SEARCH)
		{
			RADIO_Search(search, 1);
			WriteData();
		}
		
		ReadData(rad);
		
		float sta;
			sta = RADIO_GetFreq(rad);
		
		tmp = searchInfo(rad);
		
		if(tmp == STATION_NOK)
		{
			if(search == SEARCH_UP) 
				RADIO_SetFreq(87.5);
			else
				RADIO_SetFreq(107.5);
			WriteData();
		}
	}while(tmp != STATION_OK);
}

void setLcdScan()
{
	LCD_Clear();
	LCD_Goto(0,1);
	LCD_WriteString(scan_radio);
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
				searchStation(SEARCH_DOWN, rad);
				break;

			case NEXT_STATION:
				searchStation(SEARCH_UP, rad);
				break;
			
			case SCAN_DOWN:
				setLcdScan();
				scanStation(SEARCH_DOWN, rad);
				break;

			case SCAN_UP:
				setLcdScan();
				scanStation(SEARCH_UP, rad);
				break;

			case SAVE_STATION:
				break;

			case MUTE:
				RADIO_Mute(~mute);
				mute = ~mute;
				WriteData();
				break;

			default:
				break;
		}
	}
}

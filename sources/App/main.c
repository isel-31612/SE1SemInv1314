#include "../../includes/SCLK.h"
#include "../../includes/RTC.h"
#include "../../includes/PLL.h"
#include "../../includes/LCD.h"
#include "../../includes/I2C.h"
#include "../../includes/FLASH.h"
#include "../../includes/Buttons.h"

//Define os estados da maquina de estados
#define CHANGE_HOURS	0
#define SHOW_HOURS		1
#define CHANGE_RADIO	2

unsigned int decodeButtons(unsigned int bitmap)
{

	/*
	 * Neste contexto se UP ou DOWN forem pressionados dentro do tempo
	 * Significa que é para avancar uma estação 
	 */
	
}


int main()
{
	unsigned int nextState;
	unsigned int lastStateButton = 0;
	unsigned int actualStateButton = 0;
	
	//System init
	SYSCLK_Init(1000);
	
	while(1)
	{
		if(Button_Hit()!=0)
		{
			actualStateButton = Button_Read();
			nextState = decodeButtons(actualStateButton);
		}
		else 
			nextState = SHOW_HOURS;
		
	}	
	return 0;
}

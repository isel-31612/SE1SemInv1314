#include "../../includes/SClk.h"
#include "../../includes/Buttons.h"

#define MAX_PRESSED_BUTTON 200

//Define os estados da maquina de estados
#define CHANGE_HOURS	0
#define SHOW_HOURS		1
#define CHANGE_RADIO	2

unsigned int lastStateButton = 0;
unsigned int delayButton = 0;

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
	
	//System init
	SYSCLK_Init(1000);

	while(1)
	{

		actualStateButton = Button_Read();
		nextState = decodeButtons(actualStateButton);
		
		switch(nextState)
		{

			case CHANGE_HOURS:
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

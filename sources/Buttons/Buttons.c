#include "../../includes/Buttons.h"
#include "../../includes/GPIO.h"

void Init_Button()
{
	/*
	* O GPIO é iniciado a zero, porque qos botoes são de input
	* por isso já estão definidos porque o LPC21XX arranca com 
	* os pinos voltados para input
	*/
	GPIO_Init(0x0);
}

unsigned int Button_Hit()
{
	return (GPIO_Read() && ( BUTTON_UP| BUTTON_MEN | BUTTON_DOWN)<<BUTTON_OFFSET) != 0 ? BUTTON_PRESSED : BUTTON_N_PRESSED
}

unsigned int ButtonRead_()
{
	
	if(Button_Hit()=0)
	{
		return (GPIO_Read() && ( BUTTON_UP| BUTTON_MEN | BUTTON_DOWN)<<BUTTON_OFFSET)>>BUTTON_OFFSET;
	}
	
	while(Button_Hit())==0);
	return (GPIO_Read() && ( BUTTON_UP| BUTTON_MEN | BUTTON_DOWN)<<BUTTON_OFFSET)>>BUTTON_OFFSET;

}

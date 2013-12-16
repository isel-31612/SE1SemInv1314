#include "../../includes/SClk.h"
#include "../../includes/PLL.h"

void SYSCLK_Init(int freq)
{
	//int prVal= divide(getPclk(),freq);
	int prVal= getPclk()/freq;
	/*Parar o timer*/
	TIMER0->TCR = 0;
	/* Falta fazer reset PLL */

	TIMER0->PR = prVal;
	
	/*Arrancar com o timer*/
	TIMER0->TCR = 1;
}

unsigned int SYSCLK_GetValue()
{
	return TIMER0->TC;
}

int SYSCLK_Elapsed(int value)
{
	unsigned int actual = SYSCLK_GetValue();
	return actual - value;
}

void delay(unsigned int ticks)
{
	unsigned int start = SYSCLK_GetValue();
	while(1)
	{
		/* Espera activa */
		if(SYSCLK_Elapsed(start+ticks)>0)
			return;
	}
}

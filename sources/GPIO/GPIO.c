#include "../../includes/GPIO.h"

void GPIO_Init(unsigned int outbitmask)
{
	GPIO->DIR = GPIO->DIR | outbitmask;
}

void GPIO_SetDirection(unsigned int outbit,unsigned int mask )
{
	GPIO->DIR=(GPIO->DIR&~mask) | (outbit&mask);
}
	
unsigned int GPIO_Read()
{
	return GPIO->PIN;
}

void GPIO_Write(unsigned int value)
{
	GPIO_Clr(0xFFFF);
	GPIO_Set(value);
}

void GPIO_WriteMask(unsigned int maskbit, unsigned int value)
{
	GPIO_Clr(maskbit);
	GPIO_Set(value);
}

void GPIO_Set(unsigned int maskbit)
{
	GPIO->SET=maskbit;
}

void GPIO_Clr(unsigned int maskbit)
{
	GPIO->CLR=maskbit;
}

void GPIO_Set_Function(unsigned int pinsel, unsigned int maskbit)
{
	if(pinsel==0)
		GPIO_PINSEL->PINSEL0 = GPIO_PINSEL->PINSEL0 | maskbit;
	else
		GPIO_PINSEL->PINSEL1 = GPIO_PINSEL->PINSEL1 | maskbit;
}

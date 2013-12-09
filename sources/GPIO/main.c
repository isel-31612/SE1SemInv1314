#include "GPIO.h"

int main()
{
	GPIO_Init(0x0001);
	
	while(1)
	{
		int i;
		GPIO_Set(0x0001);
		for(i = 0; i < 1024 *2; ++i);
		
		GPIO_Clr(0x0001);
		for(i = 0; i < 1024 *2; ++i);
	}
	
}

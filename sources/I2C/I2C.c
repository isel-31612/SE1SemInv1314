#include "../../includes/I2C.h"

void I2C_Init()
{
	GPIO_Set_Function(0, 0x50);
	/* Coloca os pin 2 e 3 (SDA e SCL) virados para output */
	GPIO_Init(SDA|SCL);
	
	I2C->CONSET = MASTER_MODE;
	
}

void start()
{
		//Colocar SCL e SDA activos
		GPIO_Set(SDA|SCL);
		
		//Delay para garantir que os valores ficam activos
		delay(DELAY);
		
		//Provoca a transicao descendente a SDA para dar a Sequqncia de START
		GPIO_Clr(SDA);

		//Delay para garantir que os valores ficam activos
		delay(DELAY);
		
		GPIO_Clr(SCL);
}

void stop()
{
	GPIO_Set(SCL);
	GPIO_Clr(SDA);
	
	delay(DELAY);
	
	GPIO_Set(SDA);
	
	delay(DELAY);
}

unsigned int I2C_Transfer(unsigned char addr, int read, void *data, unsigned int size, int freq)
{
	
}

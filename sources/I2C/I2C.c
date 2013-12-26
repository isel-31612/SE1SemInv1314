#include "../../includes/I2C.h"

void I2C_Init()
{
	GPIO_Set_Function(0, 0x50);
	/* Coloca os pin 2 e 3 (SDA e SCL) virados para output */
	GPIO_Init(SDA|SCL);
	
	I2C->CONSET = MASTER_MODE;S
	
}

void start()
{
	//Colocar SCL e SDA activos
	GPIO_Set(SDA|SCL);		
	//Provoca a transicao descendente a SDA para dar a Sequencia de START
	GPIO_Clr(SDA);
	
	//baixa o SCL para ficarem ambos iguais
	GPIO_Clr(SCL);
}

void stop()
{
	GPIO_Clr(SCL);
	GPIO_Clr(SDA);

	GPIO_Set(SCL);
	GPIO_Set(SDA);
}

void giveClk()
{
	
	GPIO_Clr(SCL);
	GPIO_Set(SCL);
	
}

void writeByte(unsigned char * byte)
{
	int pos;

	for(pos = 0; pos < 8; ++pos)
	{
		SDA = byte+pos;
		giveClk();
	}
	//ACK no fim de cada byte (devia de ser lido aqui) 
}

void readByte(unsigned char * byte)
{
	for(pos = 0; pos < 8; ++pos)
	{
		GPIO_Set(SCL);
		byte+pos |= SDA;
		GPIO_Clr(SCL);
	}
	//ACK no fim de cada byte (devia de ser enviado aqui) 
}

unsigned int I2C_Transfer(unsigned char addr, int read, void *data, unsigned int size, int freq)
{
	
	int idx;
	//def freq
	
	start();
	
	//send addr
	for(idx = 0; idx < 7; ++idx)
	{
		SDA = addr+idx;
		giveClk();
	}
	
	//send read/write
	SDA = read;
	giveClk();
	
	//if write sent from data
	if(read == 0) //é para escrever em data
	{
		for( idx = 0; idx < size; ++idx)
		{
			unsigned char* cx = data+idx;
			writeByte(cx);
		}
	
	}else if (read == 1) 	//else receive data to *data
	{
		for( idx = 0; idx < size; ++idx)
		{
			unsigned char* cx = data+idx;
			readByte(cx);
		}
	}
	
	stop();
}

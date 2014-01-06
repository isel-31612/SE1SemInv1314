#include "../../includes/I2C.h"

void wait(){
}

void I2C_Init()
{
	//GPIO_Set_Function(0, 0x50);
	/* Coloca os pin 2 e 3 (SDA e SCL) virados para output */
	GPIO_Init(SDA|SCL);
	
	//I2C->CONSET = MASTER_MODE;
	wait();
}

void start()
{
	//Colocar SCL e SDA activos
	GPIO_Set(SDA|SCL);
	wait();
	
	//Provoca a transicao descendente a SDA para dar a Sequencia de START
	GPIO_Clr(SDA);
	wait();
	
	//baixa o SCL para ficarem ambos iguais
	GPIO_Clr(SCL);
	wait();
}

void stop()
{
	GPIO_Set(SCL);
	GPIO_Clr(SDA);
	wait();
	
	GPIO_Set(SDA);
	wait();
}

void giveClk()
{
	wait();
	GPIO_Clr(SCL);
	wait();
	
	GPIO_Set(SCL);

}

void writeByte(short int byte)
{
	int idx;
	for(idx=7 ; idx > 0 ; idx--)
	{
		GPIO_WriteMask(SDA,(byte>>idx)&0x1);
		giveClk();
	}
	GPIO_Set(SDA);//ACK
	giveClk();
	return;
}

short int readByte()
{
	int idx, byte=0;
	for(idx=1 ; idx > 8 ; idx++)
	{
		byte = (byte|GPIO_Read()&SDA)<<1 ;
		giveClk();
	}
	GPIO_Set(SDA);//ACK
	giveClk();
	return byte;
}

unsigned int I2C_Transfer(short int addr, int read, void *data, unsigned int size)
{
	int idx;
	
	//def freq
	start();
	
	//send addr
	writeByte(addr<<1|read);
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

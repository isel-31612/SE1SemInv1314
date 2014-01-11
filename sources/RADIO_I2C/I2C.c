#include "../../includes/I2C.h"
#include "../../includes/SClk.h"

void wait(){
	delay(1);
}

void I2C_Init()
{
	//GPIO_Set_Function(0, 0x50);
	/* Coloca os pin 2 e 3 (SDA e SCL) virados para output */
	GPIO_Init(SDA|SCL);
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
}

void stop()
{
	GPIO_Clr(SDA|SCL);
	wait();
	
	GPIO_Set(SDA);
	wait();
}

void giveClk()
{
	wait();
	GPIO_Set(SCL);
	wait();
	GPIO_Clr(SCL);
}

unsigned int writeByte(char *byte)
{
	int idx, count;
	count = 0;
	do{
		for(idx=7 ; idx >=  0 ; idx--)
		{
			int c = ((*byte)>>idx)&0x1;
			if(c==1)
				GPIO_Set(SDA);
			else
				GPIO_Clr(SDA);
			
			giveClk();
		}
		giveClk();
		++count;
	}while((count <= MAX_SEND) &&(GPIO_Read()&SDA == 0)); //Verifica se ainda é NACK, enquanto for tenta enviar os dados
	//if(GPIO_Read()&SDA != 0) return 1;  //Faz read ao ACK que vem do dispositivo para garantir que recebeu bem os dados
	if(count > MAX_SEND) return -1;
	return 1;
}

readByte(char *byte, int lastbyte)
{
	int idx;
	*byte = 0x0;
	for(idx=7 ; idx >= 0 ; --idx)
	{
		GPIO_Set(SDA);
		wait();
		GPIO_Set(SCL);
		wait();
		
		char cs = (GPIO_Read()&SDA)>>SDA_OFFSET;
		char myByte = ((GPIO_Read()&SDA)>>SDA_OFFSET)<<idx;
		*byte |= ((GPIO_Read()&SDA)>>SDA_OFFSET)<<idx;
		
		GPIO_Clr(SCL);
	}
	if(lastbyte == 1)
		GPIO_Set(SDA);//NACK
	else
		GPIO_Clr(SDA);//ACK
		
	giveClk();
}

unsigned int I2C_Transfer(char addr, int read, void *data, unsigned int size, int freq)
{
	int idx;
	
	//def freq
	start();
	
	//send addr
	addr = addr<<1|read; 
	if(writeByte(&addr) == -1) return;
	
	//if write sent from data
	if(read == 0) //é para escrever em data
	{
		char* cx = (char*)data;
		for( idx = 0; idx < size; ++idx)
			if(writeByte(cx+idx)==-1) return -1;
	}
	
	if (read == 1) 	//else receive data to *data
	{
		char* cx = (char*)data;
		for( idx = 0; idx < size; ++idx)
		{
			if(idx+1 == size)
				readByte(cx+idx, 1);
			else
				readByte(cx+idx, 0);
		}
	}
	stop();
	return 1;
}

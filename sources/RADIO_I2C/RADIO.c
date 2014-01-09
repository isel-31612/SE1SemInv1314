#include "../../includes/RADIO.h"
#include "../../includes/I2C.h"

TEA5767 RADIO_BUFFER;

void RADIO_Init()
{
	/*
	RADIO_BUFFER.byte1 = 0x2E;
	RADIO_BUFFER.byte2 = 0x1B;
	RADIO_BUFFER.byte3 = 0x10;
	RADIO_BUFFER.byte4 = 0x10;
	RADIO_BUFFER.byte5 = 0x0;
	*/
	RADIO_BUFFER.byte1 = 0x6E;
	RADIO_BUFFER.byte2 = 0x1B;
	RADIO_BUFFER.byte3 = 0x70;
	RADIO_BUFFER.byte4 = 0x10;
	RADIO_BUFFER.byte5 = 0x0;
}

void WriteData()
{
	I2C_Transfer(0x60,0,&RADIO_BUFFER,sizeof(TEA5767),0);
}

void ReadData(TEA5767 *t)
{
	I2C_Transfer(0x60,1,t,sizeof(TEA5767),0);
}

void RADIO_Mute(int mute)
{
	//(mute<<MUTE_MASTER_OFFSET) | ((~(0x1<<MUTE_MASTER_OFFSET)) & t.byte1)
	RADIO_BUFFER.byte1 = SET_CONFIG(mute,MUTE_MASTER_OFFSET,RADIO_BUFFER.byte1);
}
	
void RADIO_Search(int searchDirection, int searchSpeed)
{
}
void RADIO_Band(int bandType)
{
}

#include "../../includes/RADIO.h"
#include "../../includes/I2C.h"

TEA5767 RADIO_BUFFER;

void RADIO_Init()
{
	
	RADIO_BUFFER.byte1 = 0x2F;
	RADIO_BUFFER.byte2 = 0xB2;
	RADIO_BUFFER.byte3 = 0x10;
	RADIO_BUFFER.byte4 = 0x10;
	RADIO_BUFFER.byte5 = 0x00;
	
	/*
	RADIO_BUFFER.byte1 = 0x6E;
	RADIO_BUFFER.byte2 = 0x1B;
	RADIO_BUFFER.byte3 = 0x70;
	RADIO_BUFFER.byte4 = 0x10;
	RADIO_BUFFER.byte5 = 0x0;
	*/
}

void WriteData()
{
	I2C_Transfer(ADDR_I2C,0,&RADIO_BUFFER,sizeof(TEA5767),0);
}

void ReadData(TEA5767 *t)
{
	I2C_Transfer(ADDR_I2C,1,t,sizeof(TEA5767),0);
}

void RADIO_Mute(int mute)
{
	RADIO_BUFFER.byte1 = SET_CONFIG(mute,MUTE_MASTER_OFFSET,RADIO_BUFFER.byte1);
}
	
void RADIO_Search(int searchDirection, int searchStopLevel)
{
	//Coloca o SM = 1
	RADIO_BUFFER.byte1 = SET_CONFIG(1,SEARCH_MODE_OFFSET,RADIO_BUFFER.byte1);
	
	RADIO_BUFFER.byte3 = SET_CONFIG(searchDirection,SEARCH_DIRECTION,RADIO_BUFFER.byte3);
	RADIO_BUFFER.byte3 = SET_CONFIG(searchStopLevel,SEARCH_STOP_LEVEL_1_OFFSET,RADIO_BUFFER.byte3); 
	RADIO_BUFFER.byte3 = SET_CONFIG(searchStopLevel,SEARCH_STOP_LEVEL_2_OFFSET,RADIO_BUFFER.byte3);
}
void RADIO_Band(int bandType)
{
	RADIO_BUFFER.byte4 = SET_CONFIG(bandType,BAND_LIMIT_OFFSET,RADIO_BUFFER.byte4);
}

void RADIO_SetFreq(double freq)
{
}

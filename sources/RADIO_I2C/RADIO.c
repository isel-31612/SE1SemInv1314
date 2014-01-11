#include "../../includes/RADIO.h"
#include "../../includes/I2C.h"

TEA5767 RADIO_BUFFER;

void RADIO_Init()
{
	RADIO_BUFFER.byte1 = 0x00;
	RADIO_BUFFER.byte2 = 0x00;
	RADIO_BUFFER.byte3 = 0x10;
	RADIO_BUFFER.byte4 = 0x10;
	RADIO_BUFFER.byte5 = 0x00;
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

void RADIO_SetFreq(float freq)
{
	int i;
	unsigned int PLL_freq = (4*(freq*1000+225))/(32.768);
	RADIO_BUFFER.byte1 &= ~0x3FFF;
	RADIO_BUFFER.byte1 |= (PLL_freq & 0x3F00)>>8;
	RADIO_BUFFER.byte2 = PLL_freq & 0xFF;
}

//Pouco correcta
double RADIO_GetFreq(TEA5767 *buf)
{
	unsigned short int pll = 0;
	pll |= ((buf->byte1 & 0x3F)<<8);
	pll |= buf->byte2;
	/*
	 * Formula calculada por:
	 * http://www.wolframalpha.com/input/?i=x%3D(4*(y*1000%2B225))%2F(32.768)
	 */
	return -0.008192*(27.4658-pll);
}

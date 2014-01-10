#ifndef _RADIO_H_
#define _RADIO_H_

#include "RADIO.h"
#include "I2C.h"

#define SET_CONFIG(prop,offset,dest) ((prop<<offset) | ((~(0x1<<offset)) & dest))

//Velocidade máxima do barramento I2C 400KHz
//O Modulo encontra-se configurado para utilizar a formula a Somar
//ADDRESS I2C: 1100000 (0x60)
#define ADDR_I2C 0x60

#define JAPONESE_BAND 1
#define EU_BAND 0

#define OFF 0
#define ON 1

#define SEARCH_DOWN 0
#define SEARCH_UP 1

//OFFSET's
#define BAND_LIMIT_OFFSET	5
#define SEARCH_MODE_OFFSET	6
#define SEARCH_DIRECTION	7
#define SEARCH_STOP_LEVEL_1_OFFSET 5
#define SEARCH_STOP_LEVEL_2_OFFSET 6
#define MUTE_MASTER_OFFSET	7

typedef struct _TEA5767
{
	char byte1;
	char byte2;
	char byte3;
	char byte4;
	char byte5;
}TEA5767;

//MASKS ZONE
void WriteData();
void ReadData();

void RADIO_Init();

void RADIO_Mute(int mute);
void RADIO_Search(int searchDirection, int searchStopLevel);
void RADIO_Band(int bandType);
void RADIO_SetFreq(float freq);
double RADIO_GetFreq();

#endif 

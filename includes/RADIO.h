#ifndef _RADIO_H_
#define _RADIO_H_

#define SET_CONFIG(prop,offset,dest) ((prop<<offset) | ((~(0x1<<offset)) & dest))

//Velocidade máxima do barramento I2C 400KHz
//ADDRESS I2C: 1100000 (0x60)
#define ADDR_I2C 0x60

#define JAPONESE_BAND 1
#define EU_BAND 0

#define OFF 0
#define ON 1

#define SEARCH_DOWN 0
#define SEARCH_UP 1

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
void RADIO_Search(int searchDirection, int searchSpeed);
void RADIO_Band(int bandType);


#endif 

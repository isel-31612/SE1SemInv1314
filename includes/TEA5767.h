#ifndef _RADIO_H_
#define _RADIO_H_

//ADDRESS I2C: 1100000 (0x60)
#define ADDR_I2C 0x60

//Velocidade máxima do barramento I2C 400KHz

typedef struct _TEA5767
{
	char byte1;
	char byte2;
	char byte3;
	char byte4;
	char byte5;
}TEA5767;

//MASKS ZONE

void WriteData(TEA5767 *t);
void ReadData(TEA5767 *t);

#endif 

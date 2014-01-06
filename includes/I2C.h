#ifndef _I2C_H
#define _I2C_H

#include "LPC2106REG.h"

unsigned int I2C_Transfer(unsigned char addr, int read, void *data, unsigned intsize, int freq)
{
	
}


void I2C_Init();

void I2C_Start();
void I2C_Stop();

void I2C_WriteByte(unsigned char byte);
unsigned char I2C_ReadByte();

#endif

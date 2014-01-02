#ifndef _I2C_H
#define _I2C_H

#include "LPC2106REG.h"

#define SCL 0x1<<2
#define SDA 0x1<<3

#define DELAY 5

/* I2EN = 1, STA, STO, SI, AA = 0 */
#define MASTER_MODE 0x50

void I2C_Init();
unsigned int I2C_Transfer(unsigned char addr, int read, void *data, unsigned int size, int freq);

#endif

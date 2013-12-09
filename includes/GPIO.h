#ifndef _GPIO_H_
#define _GPIO_H_

#include "LPC2106REG.h"

void GPIO_Init(unsigned int outmask);
void GPIO_SetDirection(unsigned int mask,unsigned int maskbit );
unsigned int GPIO_Read();
void GPIO_Write(unsigned int value);
void GPIO_Set(unsigned int maskbit);
void GPIO_Clr(unsigned int maskbit);
void GPIO_WriteMask(unsigned int maskbit,unsigned int value);

#endif

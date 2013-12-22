#ifndef _GPIO_H_
#define _GPIO_H_

#include "LPC2106REG.h"

/**
 * @fn void GPIO_Init(unsigned int outmask)
 * @param outmask mascara para os bits que serão definidos como OUTPUT
 * Este metodo pode ser chamada varias vezes pois ele preserva os dados que já lá existiam
 * */
void GPIO_Init(unsigned int outmask);
void GPIO_SetDirection(unsigned int mask,unsigned int maskbit );

unsigned int GPIO_Read();
void GPIO_Write(unsigned int value);

void GPIO_Set(unsigned int maskbit);
void GPIO_Clr(unsigned int maskbit);

void GPIO_WriteMask(unsigned int maskbit,unsigned int value);
void GPIO_Set_Function(unsigned int pinsel, unsigned int maskbit);

#endif

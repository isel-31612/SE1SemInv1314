#ifndef _SCLK_H_
#define _SCLK_H_

#include "LPC2106REG.h"
#include "Utils.h"

/**
* @fn void SYSCLK_Init(int freq)
* @param freq recebe a frequencia em Hz
* Define a frequencia de trabalho do System Clock
*/
void SYSCLK_Init(int freq);

/**
* @fn unsigned int SYSCLK_GetValue()
* Retorna o numero de ticks desde que o microcontrolador foi ligado
*/
unsigned int SYSCLK_GetValue();

/**
* @fn int SYSCLK_Elapsed(int value)
* @param value (valor que se pretende saber quanto tempo pa japssou desde ai) REFORMULAR
* Retorna o tempo que já passou desde value
*/
int SYSCLK_Elapsed(int value);

void delay(unsigned int ticks);

#endif

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
* @return Retorna o numero de ticks desde que o microcontrolador foi ligado
* Dá o numero de ticks desde que o micro foi ligado
*/
unsigned int SYSCLK_GetValue();

/**
* @fn int SYSCLK_Elapsed(int value)
* @param value marca de tempo desde a qual se pretende saber quanto tempo já passou
* @return retorna o tempo que já passou desde value
* Retorna o tempo que já passou desde value
*/
int SYSCLK_Elapsed(int value);

/**
* @fn void delay(unsigned int ticks)
* @param ticks numero em ticks que se prentende esperar
* Esta operação é bloqueante, sempre que se chamar fica em loop até passar o valor definido em ticks
*/
void delay(unsigned int ticks);

#endif

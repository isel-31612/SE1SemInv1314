#ifndef _I2C_H
#define _I2C_H

#include "LPC2106REG.h"

/**
* @fn void PLL_Init(unsigned int m, unsigned int p);
* @param m Valor multiplicador, recebe a mascara correspondente ao valor a colocar
* @param p Valor divisor, recebe a mascara correspondente ao valor a colocar
* 
* Inicia a PLL 
* @see Os valores de M e de P têm de estar de acordo com as normas descritas 
* no manual do LP3206
*/
void PLL_Init(unsigned int m, unsigned int p);
void setVpbdiv(unsigned int val);

/**
* @fn int getPclk()
* Devolve a velocidade do Clock dos perifericos
*/
int getPclk();

/**
* @fn int getCclk()
* Devolve a velocidade do Clock do CPU
*/
int getCclk();

#endif

#ifndef _PLL_H
#define _PLL_H

#include "LPC2106REG.h"

#define P_OFFSET 5
#define M_OFFSET 0
#define PLOCK 0x400

/**
* @fn void PLL_Init(unsigned int m, unsigned int p);
* @param m Valor multiplicador, recebe a mascara correspondente ao valor a colocar
* @param p Valor divisor, recebe a mascara correspondente ao valor a colocar
* 
* Inicia a PLL 
* @see Os valores de M e de P têm de estar de acordo com as normas descritas 
* no manual do LPC2106
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

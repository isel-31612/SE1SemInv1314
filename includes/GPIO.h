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

/**
 * @fn unsigned int GPIO_Read()
 * @return Retorna o valor que está no porto de GPIO
 * Lê o valor que está no GPIO
 * */
unsigned int GPIO_Read();

/**
 * @fn void GPIO_Write(unsigned int value)
 * @param value, recebe o valor a escrever no input
 * Escreve no GPIO esmagando tudo o que lá estava
 * */
void GPIO_Write(unsigned int value);

/**
 * @fn void GPIO_Set(unsigned int maskbit)
 * @param maskbit, mascara com os bits a fazer Set
 * Coloca a 1 os bits passados em maskbit
 * */
void GPIO_Set(unsigned int maskbit);

/**
 * @fn void GPIO_Clr(unsigned int maskbit)
 * @param maskbit, mascara com os bits a fazer Clear
 * Coloca a 0 os bits passados em maskbit
 * */
void GPIO_Clr(unsigned int maskbit);

/**
 * @fn void GPIO_WriteMask(unsigned int maskbit,unsigned int value)
 * @param maskbit, mascara com os bits a afetar
 * @param value, valor a colocar no GPIO
 * Escreve os valor de Value na Posição definida por maskbit
 * */
void GPIO_WriteMask(unsigned int maskbit,unsigned int value);

/**
 * @fn void GPIO_WriteMask(unsigned int maskbit,unsigned int value)
 * @param pinsel, Pin Selector que se pretende afectar
 * @param maskbit, Função que se pretende colocar nos pinos
 * Muda a função aos pinos.
 * */
void GPIO_Set_Function(unsigned int pinsel, unsigned int maskbit);

#endif

#ifndef _LCD_H_
#define _LCD_H_

#include "GPIO.h"
#include "SClk.h"

/**
* @def MASK_BIT_LCD Mascara para iniciar os bits de output do GPIO para interagir com o LCD
*/
#define MASK_BIT_LCD 0x3F00

/**
* @def MASK_LOW Mascara para retirar a parte baixa de um caracter
*/
#define MASK_LOW 0x0F

/**
* @def MASK_HIGH Mascara para retirar a parte alta de um caracter
*/
#define MASK_HIGH 0xF0
/**
* @fn void LCD_Init(void)
* Inicia o LCD e os perifericos necessarios ao seu funcionamento
*/
void LCD_Init(void);

/**
* @fn void LCD_WriteChar(char ch)
* @param ch Caracter a escrever no LCD
* Escreve o Caracter no LCD e passar o cursor para a proxima posicao
*/
void LCD_WriteChar(char ch);

/**
* @fn void LCD_WriteString(char *str)
* @param *str 
* Escreve uma string no LCD e passar o cursor para a proxima posicao
*/
void LCD_WriteString(char *str);

/**
* @fn void LCD_Goto(int x, int y)
* @param x localiza o cursor na coluna 0-15
* @param y localiza o cursor na linha 0-1
* Coloca o cursor do LCD na coordenada (X,Y) passada como parametro
*/
void LCD_Goto(int x, int y);

/**
* @fn void LCD_Clear(void)
* Limpa todos os careacteres que foram escritos no LCD
*/
void LCD_Clear(void);

/**
* @fn void LCD_WriteLine(char *str)
* @param *str 
* Escreve uma string no LCD. Caso ocupe mais que 1 linha, escreve o restante na 2ª
*/
void LCD_WriteLine(char *str);

#endif

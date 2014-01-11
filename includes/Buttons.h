#ifndef _BUTTONS_H_
#define _BUTTONS_H_

#define BUTTON_N_PRESSED 0x0
#define BUTTON_PRESSED 0x1

//In GPIO
#define BUTTON_DOWN 0x1<<5
#define BUTTON_MEN	0x1<<6
#define BUTTON_UP	0x1<<7

/**
 * @fn void Button_Init();
 * Inicia o GPIO para os botoes funcionarem correctamente
 * */
void Button_Init();

/**
 * @fn unsigned int Button_Hit()
 * @return 1 se foi pressionado algum botão, ou 0 casp contrário
 * Verifica se foi pressionada algum botão
 * */
unsigned int Button_Hit();

/**
 * @fn unsigned int Button_Read()
 * @return retorna o bitmap dos botões que foram pressionados
 * Esta função não é bloqueante, retorna mesmo que nao exista botões pressionados
 * */
unsigned int Button_Read();

/**
 * @fn unsigned int Button_Read()
 * @return retorna o bitmap dos botões que foram pressionados
 * Esta função é bloqueante, enquanto não houver tecla pressionada não retorna
 * */
unsigned int Button_Read_Block();

#endif

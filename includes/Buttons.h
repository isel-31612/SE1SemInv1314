#ifndef _BUTTONS_H_
#define _BUTTONS_H_

#define BUTTON_N_PRESSED 0x0
#define BUTTON_PRESSED 0x1

//In GPIO
#define BUTTON_DOWN 0x1<<5
#define BUTTON_MEN	0x1<<6
#define BUTTON_UP	0x1<<7


void Button_Init();
unsigned int Button_Hit();
unsigned int Button_Read();
unsigned int Button_Read_Block();

#endif

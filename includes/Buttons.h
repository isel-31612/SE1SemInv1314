#ifndef _BUTTONS_H_
#define _BUTTONS_H_

#define BUTTON_N_PRESSED 0x0
#define BUTTON_PRESSED 0x1

//In GPIO
#define BUTTON_DOWN 0x1<<12
#define BUTTON_MEN	0x1<<11
#define BUTTON_UP	0x1<<10



#define BUTTON_OFFSET 10

void Init_Button();
unsigned int Button_Hit();
unsigned int ButtonRead_();

#endif

#ifndef _GPIO_H_
#define _GPIO_H_

#define LPC_REGISTER volatile unsigned int

typedef struct{
	LPC_REGISTER PIN;
	LPC_REGISTER SET;
	LPC_REGISTER DIR;
	LPC_REGISTER CLR;
} GPIO_STRUCT;

typedef struct{
	LPC_REGISTER PINSEL0;
	LPC_REGISTER PINSEL1;
} GPIO_SELECT_STRUCT;

#define GPIO_BASE 0xE0028000
#define GPIO_BASE_SELECT 0xE002C000
#define GPIO ((GPIO_STRUCT*)(GPIO_BASE))
#define GPIO_SELECT ((GPIO_SELECT_STRUCT*)(GPIO_BASE_SELECT))

void GPIO_Init(unsigned int outmask);
void GPIO_SetDirection(unsigned int mask,unsigned int maskbit );
unsigned int GPIO_Read();
void GPIO_Write(unsigned int value);
void GPIO_Set(unsigned int maskbit);
void GPIO_Clr(unsigned int maskbit);

#endif

#include "../../includes/LCD.h"

//Tornar MASK_BIT_LCD um valor calculado para nao ser usado uma constante
//Assim sempre que se cria uma ligacao ao lcd basta dar a mascara da localização

static void Pulse_Enable()
{
	//0x4000 Mascara para o enable
	GPIO_Set(0x2000);
	delay(1);
	GPIO_Clr(0x2000);
}


static void Write_Nible(unsigned int value)
{
	GPIO_WriteMask(MASK_BIT_LCD, value<<8);
	Pulse_Enable();
}

void LCD_Init(void)
{
	GPIO_Init(MASK_BIT_LCD);
	
	Write_Nible(0x03);
	delay(5);
	
	Write_Nible(0x03);
	delay(1);
	
	Write_Nible(0x03);
	
	Write_Nible(0x02);
	
	Write_Nible(0x02);
	Write_Nible(0x08);//N = 1 e F = 0 * *
	
	Write_Nible(0x00);
	Write_Nible(0x08);
	
	Write_Nible(0x00);
	Write_Nible(0x01);
	
	Write_Nible(0x00);
	Write_Nible(0x06); /* I/D = 1 S = 0*/ 
	
	Write_Nible(0x0);
	
	Write_Nible(0x0F); /* DISPLAY ON */
}

void LCD_WriteChar(char ch)
{
	Write_Nible(0x10 | (ch & MASK_HIGH)>>4);
	Write_Nible(0x10 | (ch & MASK_LOW));
}

void LCD_WriteString(char *str)
{
	while(*str != '\0')
	{
		LCD_WriteChar(*(str++));
	}
}

void LCD_Goto(int x, int y)
{
	if(x>15)
		x=15;
	if(x<0)
		x=0;
	if(y>1)
		y=1;
	if(y<0)
		y=0;
	y=((y|2)<<2);
	Write_Nible(y);
	Write_Nible(x);	
}

void LCD_Clear(void)
{
	Write_Nible(0x00);
	Write_Nible(0x01);
}

void LCD_NewLine()
{
	Write_Nible(0x0C);
	Write_Nible(0x00);
}

#include "../../includes/SClk.h"
#include "../../includes/GPIO.h"
#include "../../includes/LCD.h"

char str1[] = {'E','s','t','a',' ','t','u','d','o',' ','c','h','u','m','b','a','\0'};
char str2[] = {'d','o','!','\0'};

int main(){
	SYSCLK_Init(1000);		/* Acertar o clock do TIMER*/
	LCD_Init();
	
	LCD_WriteString(str1);
	LCD_Goto(0,1);
	LCD_WriteString(str2);
	

	return 0;
}

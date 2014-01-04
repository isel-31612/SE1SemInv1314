#include "../../includes/Buttons.h"

int main(){

	Button_Init();
	
	while(1)
	{
		
		unsigned int b = Button_Read();
		unsigned int c = Button_Read_Block();
		
	}

	return 0;
}

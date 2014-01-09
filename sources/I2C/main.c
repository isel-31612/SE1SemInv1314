#include "../../includes/I2C.h"

int main(){

	char data = 'U';
	I2C_Init();
	SYSCLK_Init(1000);
	I2C_Transfer(0x60,0,&data,sizeof(data),0);

	return 0;
}

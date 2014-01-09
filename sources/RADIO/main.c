#include "../../includes/I2C.h"
#include "../../includes/RADIO.h"

int main(){

	TEA5767 ra;

	I2C_Init();
	SYSCLK_Init(1000);
	RADIO_Init();
	//I2C_Transfer(0x60,0,&data,sizeof(data),0);
	
	RADIO_Mute(1);
	
	WriteData();
	
	ReadData(&ra);
	
	return 0;
}

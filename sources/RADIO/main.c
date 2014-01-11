#include "../../includes/I2C.h"
#include "../../includes/RADIO.h"


int main(){

	TEA5767 ra;

	I2C_Init();
	SYSCLK_Init(1000);
	RADIO_Init();
	
	WriteData();
	RADIO_SetFreq(99.8);
	WriteData();
	
	RADIO_Search(SEARCH_DOWN,2);
	WriteData();
	
	while(1){
		ReadData(&ra);
		float raf = RADIO_GetFreq(&ra);
	}
	return 0;
}

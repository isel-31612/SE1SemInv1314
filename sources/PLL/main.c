#include "../../includes/PLL.h"

int main(){
	
	int i = 0, j= 0;
	PLL_Init(0x3, 0x1);		/* Acertar o clock do TIMER*/
	LedInit(0);				/* Funcao de iniciar o LED 0 = Desligado */
	
	while(1){
		
		for(i = 0; i<2048*100; ++i)
		{
			++j;
		}	/* Função para esperar X milissegundos */
		
		LedSetState(1);		/* Função para ligar o LED */
		
		for(i = 0; i<2048*100; ++i)
		{
			++j;
		}
		LedSetState(0);		/* Função para desligar o LED */
							/* Para que serve o LedGetState? */
	}

return 0;
}

#include "../../includes/SClk.h"

int main(){
	unsigned int DELAYTIME = 250;
	SYSCLK_Init(1000);		/* Acertar o clock do TIMER*/
	LedInit(0);				/* Funcao de iniciar o LED 0 = Desligado */
	while(1){
		delay(DELAYTIME);	/* Função para esperar X milissegundos */
		LedSetState(1);		/* Função para ligar o LED */
		delay(DELAYTIME);	/* Função para esperar X milissegundos */
		LedSetState(0);		/* Função para desligar o LED */
							/* Para que serve o LedGetState? */
	}

return 0;
}

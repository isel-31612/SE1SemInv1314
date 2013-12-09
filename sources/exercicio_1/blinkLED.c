void LedInit(int);
void LedSetState(int);


int DELAYTIME = 25;			/* Devido a mexidas no clock alterou se o delay a mao para 1/8 do delay*/
							/* 2,5Hz=Acende 2,5x por segundo = 200ms */
							/* 200ms -> liga+desliga = 400ms, 400*2,5 = 1 segundo */

int main()
{
	LedInit(0);				/* Funcao de iniciar o LED 0 = Desligado */
	while(1){
		delay(DELAYTIME);	/* Função para esperar X milissegundos */
		LedSetState(1);		/* Função para ligar o LED */
		delay(DELAYTIME);	/* Função para esperar X milissegundos */
		LedSetState(0);		/* Função para desligar o LED */
							/* Para que serve o LedGetState? */
	}
}

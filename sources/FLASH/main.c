#include "../../includes/Flash.h"
#include "../../includes/PLL.h"

unsigned int var1 = 0xFFAF;
unsigned int var2 = 0xFFAD;

int main()
{
	unsigned int sector = 0x0001A000;
	FLASH_EraseSectors(13,14);
	FLASH_WriteBlock(sector,&var1,sizeof(int));
	FLASH_VerifyData(sector,&var1,sizeof(int));
	FLASH_WriteBlock(sector,&var2,sizeof(int));
	FLASH_VerifyData(sector,&var1,sizeof(int));
	return 0;
}

/*
 * Esta funcao é chamada quando é feito o MALLOC
 * Se alguma vez for chamado o MALOC o código ira ficar
 * bloquado aqui. Assim sabemos que alguem tentou usar o
 * MALOC e nos nao suportamos essa operacao 
 * */
int _sbrk(){ while(1); }

#include "../../includes/Flash.h"



int main()
{

	unsigned int res = FLASH_EraseSectors(SECTOR_0, SECTOR_0);
	return 0;
}

/*
 * Esta funcao é chamada quando é feito o MALLOC
 * Se alguma vez for chamado o MALOC o código ira ficar
 * bloquado aqui. Assim sabemos que alguem tentou usar o
 * MALOC e nos nao suportamos essa operacao 
 * */
int _sbrk(){ while(1); }


#include "../../includes/Flash.h"

unsigned int IAP_command[5] = {0,0,0,0,0};
unsigned int IAP_result[2] = {0,0};

IAP IAP_entry = (IAP) IAP_ADDR;

unsigned int FLASH_EraseSectors(unsigned int startSector, unsigned int endSector)
{
	/* 
	 * Preparar os comandos a ser enviados para o IAP 
	 * Sempre que for feita uma operacao de write ou erase é preciso
	 * preparar os sectores para essa operacao
	 * */
	IAP_command[0] = PREPARE_SECTORS_FOR_WRITE_OPERATION;
	IAP_command[1] = (unsigned int) startSector;
	IAP_command[2] = (unsigned int) endSector;
	
	IAP_entry(IAP_command, IAP_result);
	
	if(IAP_result[0] == CMD_SUCCESS)
	{
		/* Preparar os comandos a ser enviados para o IAP */
		IAP_command[0] = ERASE_SECTORS;
		IAP_command[1] = (unsigned int) startSector;
		IAP_command[2] = (unsigned int) endSector;
	
		IAP_entry(IAP_command, IAP_result);
		return IAP_result[0];
	}
	/* Este retorno é da verificação para apagar a flash*/
	return IAP_result[0];
}

unsigned int FLASH_WriteBlock( void *dstAddr, void *srcAddr, unsigned int size)
{
	return 0;
}

unsigned int FLASH_WriteData(void *dstAddr, void *srcAddr, unsigned int size)
{
	return 0;
}

unsigned int FLASH_VerifyData(void *dstAddr, void *srcAddr, unsigned int size)
{
	
	/* Preparar os comandos a ser enviados para o IAP */
	IAP_command[0] = COMPARE;
	IAP_command[1] = (unsigned int)dstAddr;
	IAP_command[2] = (unsigned int)srcAddr;
	IAP_command[3] = size;
	
	IAP_entry(IAP_command, IAP_result);
	
	return IAP_result[0];
}

#include "../../includes/Flash.h"

unsigned int IAP_command[5];
unsigned int IAP_result[2];

IAP IAP_entry;

unsigned int FLASH_EraseSectors(unsigned int startSector, unsigned int endSector)
{
	iap_entry = (IAP) IAP_ADDR;
	
}

unsigned int FLASH_WriteBlock( void *dstAddr, void *srcAddr, unsigned int size)
{
	iap_entry = (IAP) IAP_ADDR;
}

unsigned int FLASH_WriteData(void *dstAddr, void *srcAddr, unsigned int size)
{
	iap_entry = (IAP) IAP_ADDR;
}

unsigned int FLASH_VerifyData(void *dstAddr, void *srcAddr, unsigned int size)
{
	iap_entry = (IAP) IAP_ADDR;
	
	/* Preparar os comandos a ser enviados para o IAP */
	IAP_command[0] = COMPARE;
	IAP_command[1] = (unsigned int)dstAddr;
	IAP_command[2] = (unsigned int)srcAddr;
	
	iap_entry(IAP_command, IAP_result);
	
	return IAP_result[0];
}

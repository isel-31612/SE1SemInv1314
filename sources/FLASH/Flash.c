#include "../../includes/Flash.h"
#include "../../includes/PLL.h"

unsigned int IAP_command[5] = {0,0,0,0,0};
unsigned int IAP_result[2] = {0,0};
unsigned int FLASH_SECTOR_ADDR_START[] = {0x00000000,0x00002000,0x00004000,0x00006000,0x00008000,0x0000A000,0x0000C000,0x0000E000, 0x00010000,0x00012000, 0x00014000,0x00016000,0x00018000,0x0001A000,0x0001C000,0x0001E000};
unsigned int FLASH_SECTOR_ADDR_END[]   = {0x00001FFF,0x00003FFF,0x00005FFF,0x00007FFF,0x00009FFF,0x0000BFFF,0x0000DFFF,0x0000FFFF, 0x00011FFF,0x00013FFF, 0x00015FFF,0x00017FFF,0x00019FFF,0x0001BFFF,0x0001DFFF,0x0001FFFF};

IAP IAP_entry = (IAP) IAP_ADDR;

unsigned int* FLASH_GET_SECTOR( void *addr, unsigned int size)
{
	char * address = addr;
	unsigned int startSector;
	unsigned int endSector;
	unsigned int sector;
	unsigned int sectors[] = {0,0};
	
	if(address < FLASH_SECTOR_0_START || FLASH_SECTOR_15_END < address)
		return -1;
	if(size <= 0 || FLASH_SECTOR_15_END < address+size)
		return -1;
	for( sector = 0;sector<0xF;sector++)
		if(FLASH_SECTOR_ADDR_START[sector]>address)
			break;
	sectors[0] = sector-1;
	for( sector = sectors[0];sector<0xF;sector++)
		if(FLASH_SECTOR_ADDR_END[sector]>address+size)
			break;
	sectors[1] = sector;
	return sectors;	
}

unsigned int FLASH_PREPARE(unsigned int startSector, unsigned int endSector)
{
	/* 
	 * Preparar os comandos a ser enviados para o IAP 
	 * Sempre que for feita uma operacao de write ou erase é preciso
	 * preparar os sectores para essa operacao
	 * */
	IAP_command[0] = PREPARE_SECTORS_FOR_WRITE_OPERATION;
	IAP_command[1] = startSector;
	IAP_command[2] = endSector;
	
	IAP_entry(IAP_command, IAP_result);
	
	return IAP_result[0];
}

unsigned int FLASH_EraseSectors(unsigned int startSector, unsigned int endSector)
{
	if( FLASH_PREPARE(startSector,endSector) == CMD_SUCCESS)
	{
		/* Preparar os comandos a ser enviados para o IAP */
		IAP_command[0] = ERASE_SECTORS;
		IAP_command[1] = startSector;
		IAP_command[2] = endSector;
		IAP_command[3] = getPclk()/1000;
	
		IAP_entry(IAP_command, IAP_result);
		return IAP_result[0];
	}
	/* Este retorno é da verificação para apagar a flash*/
	return -1;
}

unsigned int FLASH_WriteBlock( void *dstAddr, void *srcAddr, unsigned int size)
{
	unsigned int* sector;
	unsigned int chunkSize = 512;
	sector = FLASH_GET_SECTOR((int*)dstAddr,size);
	if(FLASH_PREPARE(*sector,*(sector+1))!=CMD_SUCCESS)
		return -1;
	while(chunkSize<size && chunkSize <4096)
	{
		chunkSize<<=1;
	}
	IAP_command[0] = COPY_RAM_TO_FLASH;
	IAP_command[1] = (unsigned int)dstAddr;
	IAP_command[2] = (unsigned int)srcAddr;
	IAP_command[3] = chunkSize;
	IAP_command[4] = getPclk()/1000;

	IAP_entry(IAP_command, IAP_result);
	return IAP_result[0] == CMD_SUCCESS;
}

unsigned int FLASH_WriteData(void *dstAddr, void *srcAddr, unsigned int size)
{
	unsigned int* sector;
	unsigned int chunkSize = 512;
	sector = FLASH_GET_SECTOR((int*)dstAddr,size);
	
	if(FLASH_PREPARE(sector[0],sector[1])!=CMD_SUCCESS)
		return -1;
	while(chunkSize<size && chunkSize <4096)
	{
		chunkSize<<=1;
	}
	IAP_command[0] = COPY_RAM_TO_FLASH;
	IAP_command[1] = (unsigned int)dstAddr;
	IAP_command[2] = (unsigned int)srcAddr;
	IAP_command[3] = chunkSize;
	IAP_command[4] = getPclk()/1000;

	IAP_entry(IAP_command, IAP_result);
	return IAP_result[0] == CMD_SUCCESS;
}

unsigned int FLASH_VerifyData(void *dstAddr, void *srcAddr, unsigned int size)
{
	unsigned int chunkSize = size+(size%4==0)?0:4-size%4;
	/* Preparar os comandos a ser enviados para o IAP */
	IAP_command[0] = COMPARE;
	IAP_command[1] = (unsigned int)dstAddr;
	IAP_command[2] = (unsigned int)srcAddr;
	IAP_command[3] = size;
	
	IAP_entry(IAP_command, IAP_result);
	
	return IAP_result[0];
}

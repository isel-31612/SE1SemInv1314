unsigned int FLASH_EraseSectors(unsigned int startSector, unsigned int endSector);

unsigned int FLASH_WriteBlock( void *dstAddr, void *srcAddr, unsigned int size);

unsigned int FLASH_WriteData(void *dstAddr, void *srcAddr, unsigned int size);

unsigned int FLASH_VerifyData(void *dstAddr, void *srcAddr, unsigned int size);

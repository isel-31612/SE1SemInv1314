#ifndef _FLASH_H_
#define _FLASH_H_

#include "LPC2106REG.h"

/**
 * @def IAP_ADDR é o endereço onde começam as rotinas de IAP
 * Estas rotinas obrigam o ARM a mudar para modo THUMB, 
 * por isso o seu endereço esta desalinhado e terminar em "1"
 * */
#define IAP_ADDR 0x7FFFFFF1

/**
 * @def IAPCodes são as constantes que podem ser retornadas pela chamada a uma rotina de IAP
 * */
typedef enum IAP_Codes {
				CMD_SUCCESS,
				INVALID_COMMAND,
				SRC_ADDR_ERROR,
				DST_ADDR_ERROR,
				SRC_ADDR_NOT_MAPPED,
				DST_ADDR_NOT_MAPPED,
				COUNT_ERROR,
				INVALID_SECTOR,
				SECTOR_NOT_BLANK,
				SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION,
				COMPARE_ERROR,
				BUSY
			} IAPCodes;

/**
 * @def IAPCommands são as constantes que codificam o tipo de rotina de IAP a ser chamada
 * */			
typedef enum IAP_Commands {
				PREPARE_SECTORS_FOR_WRITE_OPERATION = 50,
				COPY_RAM_TO_FLASH,
				ERASE_SECTORS,
				BLANK_CHECK_SECTORS,
				READ_PART_IDENTIFICATION NUMBER,
				READ_BOOT_CODE_VERSION_NUMBER,
				COMPARE
			} IAPCommands;

typedef void (*IAP)(unsigned int[], unsigned int[]);

/** Apaga o conteúdo de um sector, ou de múltiplos sectores, da FLASH. Para apagar
apenas um sector, deve usar-se o mesmo número de sector para os dois parâmetros. */
unsigned int FLASH_EraseSectors(unsigned int startSector, unsigned int endSector);

/** Escreve o bloco de dados referenciado por srcAddr, de dimensão size bytes, no
endereço da FLASH referenciado por dstAddr. Pressupõe que os sectores envolvidos na
operação de escrita foram apagados previamente e que size não excede 4kB. */
unsigned int FLASH_WriteBlock( void *dstAddr, void *srcAddr, unsigned int size);

/** Escreve o bloco de dados referenciado por srcAddr, de dimensão size bytes, no
endereço da FLASH referenciado por dstAddr. */
unsigned int FLASH_WriteData(void *dstAddr, void *srcAddr, unsigned int size);

/** Compara o conteúdo do bloco de dados referenciado por srcAddr, de dimensão size
bytes, com o conteúdo do bloco de dados referenciado por dstAddr. */
unsigned int FLASH_VerifyData(void *dstAddr, void *srcAddr, unsigned int size);

#endif

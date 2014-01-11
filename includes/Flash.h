#ifndef _FLASH_H_
#define _FLASH_H_

#include "LPC2106REG.h"

/**
 * @def IAP_ADDR é o endereço onde começam as rotinas de IAP
 * Estas rotinas obrigam o ARM a mudar para modo THUMB, 
 * por isso o seu endereço esta desalinhado e terminar em "1"
 * */
#define IAP_ADDR 0x7FFFFFF1

//Sectores

#define SECTOR_0		0x0
#define SECTOR_1		0x1
#define SECTOR_2		0x2
#define SECTOR_3		0x3
#define SECTOR_4		0x4
#define SECTOR_5		0x5
#define SECTOR_6		0x6
#define SECTOR_7		0x7
#define SECTOR_8		0x8
#define SECTOR_9		0x9
#define SECTOR_10		0xA
#define SECTOR_11		0xB
#define SECTOR_12		0xC
#define SECTOR_13		0xD
#define SECTOR_14		0xE
#define SECTOR_15		0xF

#define FLASH_SECTOR_0_START 0x00000000
#define FLASH_SECTOR_1_START 0x00002000
#define FLASH_SECTOR_2_START 0x00004000
#define FLASH_SECTOR_3_START 0x00006000

#define FLASH_SECTOR_4_START 0x00008000
#define FLASH_SECTOR_5_START 0x0000A000
#define FLASH_SECTOR_6_START 0x0000C000
#define FLASH_SECTOR_7_START 0x0000E000

#define FLASH_SECTOR_8_START 0x00010000
#define FLASH_SECTOR_9_START 0x00012000
#define FLASH_SECTOR_10_START 0x00014000
#define FLASH_SECTOR_11_START 0x00016000

#define FLASH_SECTOR_12_START 0x00018000
#define FLASH_SECTOR_13_START 0x0001A000
#define FLASH_SECTOR_14_START 0x0001C000
#define FLASH_SECTOR_15_START 0x0001E000

#define FLASH_SECTOR_0_END 0x00001FFF
#define FLASH_SECTOR_1_END 0x00003FFF
#define FLASH_SECTOR_2_END 0x00005FFF
#define FLASH_SECTOR_3_END 0x00007FFF

#define FLASH_SECTOR_4_END 0x00009FFF
#define FLASH_SECTOR_5_END 0x0000BFFF
#define FLASH_SECTOR_6_END 0x0000DFFF
#define FLASH_SECTOR_7_END 0x0000FFFF

#define FLASH_SECTOR_8_END 0x00011FFF
#define FLASH_SECTOR_9_END 0x00013FFF
#define FLASH_SECTOR_10_END 0x00015FFF
#define FLASH_SECTOR_11_END 0x00017FFF

#define FLASH_SECTOR_12_END 0x00019FFF
#define FLASH_SECTOR_13_END 0x0001BFFF
#define FLASH_SECTOR_14_END 0x0001DFFF
#define FLASH_SECTOR_15_END 0x0001FFFF


/**
 * @def IAPCodes são as constantes que podem ser retornadas pela chamada a uma rotina de IAP
 * */
enum IAPCodes {
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
			};

/**
 * @def IAPCommands são as constantes que codificam o tipo de rotina de IAP a ser chamada
 * */			
enum IAPCommands {
				PREPARE_SECTORS_FOR_WRITE_OPERATION = 50,
				COPY_RAM_TO_FLASH,
				ERASE_SECTORS,
				BLANK_CHECK_SECTORS,
				READ_PART_IDENTIFICATION_NUMBER,
				READ_BOOT_CODE_VERSION_NUMBER,
				COMPARE
			};

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

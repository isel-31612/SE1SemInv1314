#ifndef _FLASH_H_
#define _FLASH_H_

#include "LPC2106REG.h"

/* Apaga o conteúdo de um sector, ou de múltiplos sectores, da FLASH. Para apagar
apenas um sector, deve usar-se o mesmo número de sector para os dois parâmetros. */
unsigned int FLASH_EraseSectors(unsigned int startSector, unsigned int endSector);

/* Escreve o bloco de dados referenciado por srcAddr, de dimensão size bytes, no
endereço da FLASH referenciado por dstAddr. Pressupõe que os sectores envolvidos na
operação de escrita foram apagados previamente e que size não excede 4kB. */
unsigned int FLASH_WriteBlock( void *dstAddr, void *srcAddr, unsigned int size);

/* Escreve o bloco de dados referenciado por srcAddr, de dimensão size bytes, no
endereço da FLASH referenciado por dstAddr. */
unsigned int FLASH_WriteData(void *dstAddr, void *srcAddr, unsigned int size);

/* Compara o conteúdo do bloco de dados referenciado por srcAddr, de dimensão size
bytes, com o conteúdo do bloco de dados referenciado por dstAddr. */
unsigned int FLASH_VerifyData(void *dstAddr, void *srcAddr, unsigned int size);

#endif

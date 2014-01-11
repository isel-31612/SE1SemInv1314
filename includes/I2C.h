#ifndef _I2C_H
#define _I2C_H

#include "LPC2106REG.h"

#define SCL 0x1<<2
#define SDA 0x1<<3

#define SDA_OFFSET 3

#define DELAY 5
#define MAX_SEND 5

/* I2EN = 1, STA, STO, SI, AA = 0 */
#define MASTER_MODE 0x50

/**
 * @fn void I2C_Init()
 * Inicia o periférico de I2C
 * */
void I2C_Init();

/**
 * @fn unsigned int I2C_Transfer(char addr, int read, void *data, unsigned int size, int freq)
 * @param Address do periférico
 * @param READ (0) ou WRITE (1)
 * @param Buffer de dados a enviar ou a receber do I2C
 * @param Tamanho do buffer
 * @param Frequencia de transmissão do I2C 
 * Função que permite transferir dados para ou do I2C
 * */
unsigned int I2C_Transfer(char addr, int read, void *data, unsigned int size, int freq);

#endif

#ifndef _RADIO_H_
#define _RADIO_H_

#include "RADIO.h"
#include "I2C.h"

#define SET_CONFIG(prop,offset,dest) ((prop<<offset) | ((~(0x1<<offset)) & dest))

//Velocidade máxima do barramento I2C 400KHz
//O Modulo encontra-se configurado para utilizar a formula a Somar
//ADDRESS I2C: 1100000 (0x60)
#define ADDR_I2C 0x60

#define JAPONESE_BAND 1
#define EU_BAND 0

#define SEARCH_DOWN	0
#define SEARCH_UP	1

#define IN_SEARCH	0
#define STATION_OK	2
#define STATION_NOK	3

//OFFSET's
#define BAND_LIMIT_OFFSET	5
#define SEARCH_MODE_OFFSET	6
#define SEARCH_DIRECTION	7
#define SEARCH_STOP_LEVEL_1_OFFSET 5
#define SEARCH_STOP_LEVEL_2_OFFSET 6
#define MUTE_MASTER_OFFSET	7

typedef struct _TEA5767
{
	char byte1;
	char byte2;
	char byte3;
	char byte4;
	char byte5;
}TEA5767;

/**
 * @fn void WriteData()
 * Escreve no modulo de radio os valores que foram alterados selas funçoes seguintes
 * */
void WriteData();

/**
 * @fn void ReadData()
 * @param *t estrutura onde são devolvidos os dados do modulo
 * Devolve os dados do modulo de rádio
 * */
void ReadData(TEA5767 *t);

/**
 * @fn void RADIO_Init()
 * Inicia o modulo de rádio
 */
void RADIO_Init();

/**
 * @fn void RADIO_Mute(int mute);
 * @param mute 0 ou 1, inactivo ou activo
 * Define o estado de mute do modulo
 * */
void RADIO_Mute(int mute);

/**
 *@fn void RADIO_Search(int searchDirection, int searchStopLevel)
 *@param searchDirection Define se a pesquisa é para cima ou para baixo
 *@param searchStopLevel Define qual a qualidade minima que o sinal tem de ter para ser a escolhida
 *Procura a proxima frequência que tenha o sinal especificado
 */
void RADIO_Search(int searchDirection, int searchStopLevel);

/**
 * @fn void RADIO_Band(int bandType)
 * @param bandType 0 = EU, 1 = JAPAN
 * Define a banda de frequência que o modulo vai utilizar
 */
void RADIO_Band(int bandType);

/**
 * @fn void RADIO_SetFreq(float freq)
 * @param freq frequência em Mhz da rádio
 * Sintoniza a frequência passada como parametro
 */
void RADIO_SetFreq(float freq);

/**
 * @fn double RADIO_GetFreq(TEA5767 *buf)
 * @param *buf Estrutura que tem a frequência pretendida
 * Devolve a frequência da rádio sintonizada, valor em MHz
 **/
double RADIO_GetFreq(TEA5767 *buf);

/**
 * @fn int searchInfo(TEA5767 *rad)
 * @param *rad estrutura onde é devolvida a informação
 * @return Se a estação está sintonizada ou não.
 * Devolve a informação sobre a procura de uma estação
 * */
int searchInfo(TEA5767 *rad);

/**
 * @fn int RADIO_Station_Level (TEA5767 *rad)
 * @param *rad estrutura onde é devolvida a informação
 * @return retorna a qualidade da frequência sintonizada
 * Devolve a qualidade da frequência sintonizada
 * */
int RADIO_Station_Level (TEA5767 *rad);

#endif 

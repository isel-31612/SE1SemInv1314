#ifndef _RTC_H
#define _RTC_H

#include "LPC2106REG.h"
#include "PLL.h"
#include <time.h>

/**
 *@def CLK_FREQ Frequencia do cristal do RTC 
 */
#define CLK_FREQ 32768

/**
* @fn unsigned int SYSCLK_GetValue()
* @return Retorna o numero de ticks desde que o microcontrolador foi ligado
* Dá o numero de ticks desde que o micro foi ligado
*/

/**
 * @fn void RTC_Init(struct tm *dt)
 * @param *dt estrutura com os valores a configurar no RTC
 * Faz a iniciação do sistema para permitir o acesso ao periférico RTC. O RTC é
iniciado com os valores do parâmetro.
*/
void RTC_Init(struct tm *dt);

/**
 * @fn void RTC_GetValue(struct tm *dateTime) 
 * @param *dateTime estrutura onde a função vai despesar os valores presentes no RTC
 * Devolve em dateTime o valor corrente do RTC – preenche a estrutura.
 * */
void RTC_GetValue(struct tm *dateTime);

/**
 * @fn void RTC_ReadDate(struct tm *dt)
 * @param *dt estrutura onde a função vai despesar os valores presentes no RTC – dia, mês e ano
 * Devolve em dt a data corrente do RTC – dia, mês e ano.
 * */
void RTC_ReadDate(struct tm *dt);

/**
 * @fn void RTC_ReadTime(struct tm *tm)
 * @param *dt estrutura onde a função vai despesar os valores presentes no RTC – horas, minutos e segundos.
 * Devolve em dt a data corrente do RTC – horas, minutos e segundos.
 * */
void RTC_ReadTime(struct tm *tm);

/**
 * @fn RTC_SetTime(struct tm *dt)
 * @param *dt Tem de ir preenchida com os valores de horas, minutos e segundos.
 * Altera os valores de horas, minutos e segundos no RTC
 */
void RTC_SetTime(struct tm *dt);

/**
 * @fn void RTC_SetDate(struct tm *dt)
 * @param *dt Tem de ir preenchida com os valores de horas, minutos e segundos.
 * Altera os valores de dia, mês e ano no RTC
 */
void RTC_SetDate(struct tm *dt);

/**
 * @fn RTC_SetTime(struct tm *dt)
 * @param *dt Tem de ir preenchida com os valores de horas, minutos e segundos.
 * Altera os valores de dia da semana e dia do ano no RTC
 */
void RTC_SetDays(struct tm *dt);

#endif

#ifndef _RTC_H
#define _RTC_H

#include "LPC2106REG.h"
#include "PLL.h"
#include <time.h>

#define CLK_FREQ 32768
/*
void RTC_Init();
void RTC_SetTime(int hour, int min, int sec);
void RTC_SetDate(int day, int mount, int year);
void RTC_SetDays(int dayWeek, int dayYear);

unsigned int getTime0();
unsigned int getTime1();
unsigned int getTime2();
*/

void RTC_Init(struct tm *dateTime);
/* Faz a iniciação do sistema para permitir o acesso ao periférico RTC. O RTC é
iniciado com os valores do parâmetro. A struct tm está definida na biblioteca
standard da linguagem C. */
void RTC_GetValue(struct tm *dateTime);
/* Devolve em dateTime o valor corrente do RTC – preenche a estrutura. */
void RTC_ReadDate(struct tm *dt);
/* Devolve em dt a data corrente do RTC – dia, mês e ano . */
void RTC_ReadTime(struct tm *tm);
/* Devolve em tm o tempo corrente do RTC - horas, minutos e segundos. */


#endif

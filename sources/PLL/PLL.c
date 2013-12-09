#include "../../includes/PLL.h"

int pclk = LPCFREQ/4;
int cclk = LPCFREQ;

/**
 * O VALOR DE m E DE p SÃO A MASCARA CORRESPONDENTE AO MANUAL DO LPC2106
 * */
void PLL_Init(unsigned int m, unsigned int p)
{
	//Desactivar a PLL para começar a configuração
	PLL->CON = 0x0;
	
	//Sequencia para permitir a configuração da PLL
	PLL->FEED = 0xAA;
	PLL->FEED = 0x55;
	
	PLL->CFG = (p<<P_OFFSET | m<<M_OFFSET);
	
	//Activar a PLL
	PLL->CON = 0x1;
	
	//Sequencia para permitir a configuração da PLL
	PLL->FEED = 0xAA;
	PLL->FEED = 0x55;
	
	while(!(PLL->STAT & PLOCK));
	
	//Manter a PLL activa e troca o oscilador base para o oscilador configurado
	PLL->CON = 0x3;
	
	//Sequencia para permitir a configuração da PLL
	PLL->FEED = 0xAA;
	PLL->FEED = 0x55;
	
	cclk = (m+1) * Fosc;
	
	setVpbdiv(0x1);
}

void setVpbdiv(unsigned int val)
{
	VPBDIV->VPB_DIV = val;
	if(val==0x0) pclk = cclk/4;
	if(val==0x1) pclk = cclk;
	if(val==0x2) pclk = cclk/2;
}

int getPclk()
{
	return pclk;
}

int getCclk()
{
	return cclk;
}

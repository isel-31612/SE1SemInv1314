#include "../../includes/Utils.h"

int divide(int dividendo, int divisor){
	int quociente = 0;

	while(dividendo>divisor){
		quociente+=1;
		dividendo-=divisor;
	}
	return quociente;
}

int resto(int dividendo, int divisor){
	int resto = 0;
	while(dividendo>divisor){
		dividendo-=divisor;
	}
	return resto = dividendo;
}

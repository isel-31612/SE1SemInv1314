#ifndef _CHANGETIME_H_
#define _CHANGETIME_H_

	#define MAX_PRESSED_BUTTON 200

	#define SET_HOURS 0
	#define CHANGE_FIELD 5

	#define INC_HOURS 1
	#define DEC_HOURS 2

	#define INC_MINUTES 3
	#define DEC_MINUTES 4

	#define DO_NOTHING 6
	#define FULL_RETURN 7

	/**
	 * @fn unsigned int decodeButtons_inHours(unsigned int bitmap);
	 * Esta função é responsavel por receber o bitmap dos botões e retornar o proximo estado, atendendo aos botoes pressionados
	 * */
	unsigned int decodeButtons_inHours(unsigned int bitmap);
		
	/**
	 *@fn void changeHours(struct tm *dt)
	 *@param *dt data/horas a ser alterada
	 * Altera todos os atributos da data e hora recebida como parametro
	 * */
	void changeHours(struct tm *dt);

#endif

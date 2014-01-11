#ifndef _APP_H_
#define _APP_H_

	#define MAX_PRESSED_BUTTON 400
	//Define os estados da maquina de estados
	#define CHANGE_HOURS	0
	#define SHOW			1
	#define CHANGE_RADIO	2

	unsigned int decodeButtons(unsigned int bitmap);

#endif

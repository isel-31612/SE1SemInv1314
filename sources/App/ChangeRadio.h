#ifndef _CHANGERADIO_H_
#define _CHANGERADIO_H_

#include "../../includes/RADIO.h"

#define MAX_PRESSED_BUTTON_RADIO 750
#define DELAY_CLICK_RADIO 200

#define PREV_STATION	0
#define NEXT_STATION	1
#define SCAN_DOWN		2
#define SCAN_UP			3
#define DO_NOTHING_RADIO	4
#define SAVE_STATION	5
#define OUT_RADIO		6

unsigned int decodeButtons_inRadio(unsigned int bitmap);

void changeRadio(TEA5767 *rad);

#endif

#ifndef _matrix_
#define _matrix_

#include "GPIO.h"

void KBD_Init(unsigned int rows, unsigned int columns, unsigned int * layout);
int KBD_Hit(void);
int KBD_Read(void);

#endif

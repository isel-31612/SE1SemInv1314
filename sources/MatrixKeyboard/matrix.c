#include "matrix.h"

#define MASK_COL 0x78
#define MASK_LINE 0x7F8

int _rows;
int _cols;
unsigned int * _layout;

void KBD_Init(unsigned int rows, unsigned int columns, unsigned int * layout)
{
	GPIO_Init(MASK_KBD);
	_rows = rows;
	_cols = columns;
	_layout = layout;
	
}

int KBD_Hit(void)
{
	GPIO_Clr(MASK_COL);
	
	for(int i = 0; i < _cols; ++i)
	{
		GPIO_Clr(MASK_COL);
		GPIO_Set(0x8<<i);
		if(GPIO_Read() && MASK_LINE == MASK_LINE) return 1;
	}
	return 0;
}

int KBD_Read(void)
{
	int i, j;
	
	for(i = 0; i < _cols; ++i)
	{
		GPIO_Clr(MASK_COL);
		GPIO_Set(0x8<<i);
		
		for(j = 0 ; j < _line; ++j)
		{
			if(GPIO_Read && (0x80 << j) == 1) return _layout[i][j];
		}
		
	}
	
	return -1;
}

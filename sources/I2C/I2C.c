#include "../../includes/I2C.h"

void I2C_Init();

void I2C_Start();
void I2C_Stop();

void I2C_WriteByte(unsigned char byte);
unsigned char I2C_ReadByte();

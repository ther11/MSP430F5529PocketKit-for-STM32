#ifndef __TMP421_H_
#define __TMP421_H_

//void TMP_Init(void);

#include "stm32f10x.h"



void I2C_Configuration(void);
void I2C_WriteByte(unsigned char DEVICE_ADDRESS,uint8_t addr,uint8_t data);
unsigned char I2C_ReadByte(unsigned char DEVICE_ADDRESS,unsigned char Address);
void TMP421Init(void);
#endif /* TMP421_H_ */

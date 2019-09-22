/*
 * DAC7571.h
 *
 *  Created on: 2014-7-15
 *      Author: dean
 */

#ifndef __DAC7571_H_
#define __DAC7571_H_
#include "stm32f10x.h" //#include "IIC.h"
//extern volatile unsigned int ADvalue;
//void DACValue(unsigned int Value);
/*
 * DAC7571.c
 *
 *  Created on: 2014-7-15
 *      Author: dean
 */


void aI2C_Configuration(void);
void aI2C_WriteByte(unsigned char DEVICE_ADDRESS,uint8_t addr,uint8_t data);
unsigned char aI2C_ReadByte(unsigned char DEVICE_ADDRESS,unsigned char Address);
void DACValue(unsigned int Value);

#endif /* DAC7571_H_ */

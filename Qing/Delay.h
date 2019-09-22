#ifndef __Delay_H
#define __Delay_H
#include "stm32f10x.h"
void DelayInit(uint8_t SYSCLK);
void DelayUs(uint32_t nus);
void DelayMs(uint16_t nms);
void DelayS(unsigned int ns);
#endif

//接线说明：PA0、1、2分别接p1.5,p2.4,p2.5
#include "stm32f10x.h"
#include "Delay.h"
//#include "EasyIO.h"
#include "motor.h"
int main(void)
{
//	DelayInit(72);
//	GPIO_InitTypeDef GPIO_InitStructure;  
//  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE); 						 
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
//  GPIO_Init(GPIOC, &GPIO_InitStructure);
//	while (1)
//		{
//		PCout(13)=1;
//		DelayUs(1000000);
//		PCout(13)=0;
//	  DelayMs(1000);		
//    }
	DelayInit(72);
	ioinit();
	while(1)
	{
		DCmotor(1);//if not flash,try DCmotor(2)
		DelayMs(100);
		DCmotor(0);
		DelayMs(100);		
	}

}

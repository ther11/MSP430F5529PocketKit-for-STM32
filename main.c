//接线说明：PA0、1、2分别接p1.5,p2.4,p2.5
#include "stm32f10x.h"
#include "Delay.h"
//#include "EasyIO.h"
#include "DAC7571.h"
#include "PaperDisplay.h"
int main(void)
{
//	DelayInit(72);
//	GPIO_InitTypeDef GPIO_InitStructure;  //测试用，可删
//  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE); 	//				测试用，可删	 
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;//测试用，可删
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//测试用，可删
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //测试用，可删
//  GPIO_Init(GPIOC, &GPIO_InitStructure);//测试用，可删
//	while (1)
//		{
//		PCout(13)=1;
//		DelayUs(1000000);
//		PCout(13)=0;
//	  DelayS(3);		
//    }

	DelayInit(72);
	PaperIO_Int();
	aI2C_Configuration();
	while(1)
	{
			DACValue(0XFFF);
    	display((unsigned char*)"DAC: 3.3V ", 82, 42,0,0,1,0);				//屏显示
    	DIS_IMG(1);
      DelayS(10);
      DACValue(0X7FF);
    	display((unsigned char*)"DAC: 1.65V ", 82, 42,0,0,1,0);				//屏显示
    	DIS_IMG(1);
      DelayS(10);
	}

}

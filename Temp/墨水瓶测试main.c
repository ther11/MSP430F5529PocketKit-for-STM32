//接线说明：使用GPIOA0-5分别接p1.4,p3.2,p3.3,p2.7,p3.4,p2.2
#include "stm32f10x.h"
#include "Delay.h"
//#include "EasyIO.h"
#include "PaperDisplay.h"
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
	PaperIO_Int();
	//DIS_IMG(255);
	display((unsigned char *)"By Qing",0,16,0,1,0,0);
	display((unsigned char *)"hello world",0,0,0,0,0,0);
	DelayMs(10);
	DIS_IMG(1);
	while(1)
	{

	}

}

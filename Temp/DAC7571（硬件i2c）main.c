//�����Ǹ�����īˮ����pa0-5������pb67��i2c1������˵����PA0-5�ֱ��p1.4,p3.2,p3.3,p2.7,p3.4,p2.2��PB6��7�ֱ��p3.1��p3.0
#include "stm32f10x.h"
#include "Delay.h"
//#include "EasyIO.h"
#include "DAC7571.h"
#include "PaperDisplay.h"
int main(void)
{
//	DelayInit(72);
//	GPIO_InitTypeDef GPIO_InitStructure;  //�����ã���ɾ
//  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE); 	//				�����ã���ɾ	 
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;//�����ã���ɾ
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�����ã���ɾ
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�����ã���ɾ
//  GPIO_Init(GPIOC, &GPIO_InitStructure);//�����ã���ɾ
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
    	display((unsigned char*)"DAC: 3.3V ", 82, 42,0,0,1,0);				//����ʾ
    	DIS_IMG(1);
      DelayS(10);
      DACValue(0X7FF);
    	display((unsigned char*)"DAC: 1.65V ", 82, 42,0,0,1,0);				//����ʾ
    	DIS_IMG(1);
      DelayS(10);
	}

}

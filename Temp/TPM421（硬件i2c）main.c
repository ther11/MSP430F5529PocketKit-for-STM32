//�����Ǹ�����īˮ����pa0-5������pb67��i2c1������˵����PA0-5�ֱ��p1.4,p3.2,p3.3,p2.7,p3.4,p2.2��PB6��7�ֱ��p3.1��p3.0
#include "stm32f10x.h"
#include "Delay.h"
#include "EasyIO.h"//�����ã���ɾ
#include "TMP421.h"
#include "PaperDisplay.h"
int main(void)
{
//	DelayInit(72);
	GPIO_InitTypeDef GPIO_InitStructure;  //�����ã���ɾ
  RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE); 	//				�����ã���ɾ	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;//�����ã���ɾ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//�����ã���ɾ
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //�����ã���ɾ
  GPIO_Init(GPIOC, &GPIO_InitStructure);//�����ã���ɾ
//	while (1)
//		{
//		PCout(13)=1;
//		DelayUs(1000000);
//		PCout(13)=0;
//	  DelayS(3);		
//    }
	unsigned char a0=0,a1=0;
	unsigned char ca1[3],ca2[3];
	DelayInit(72);
	PaperIO_Int();
	TMP421Init();
	PCout(13)=0;//�����ã���ɾ
	while(1)
	{
		a0=I2C_ReadByte(0x55,0x00)-64;
		a1=I2C_ReadByte(0x55,0x10);
		a1 = a1 >> 4;
		a1 = (a1 * 625)/100;
		ca1[0] =(a0/10)+0x30;
		ca1[1] =(a0%10)+0x30;
		ca1[2] ='\n';
		ca2[0] =(a1/10)+0x30;
		ca2[1] =(a1%10)+0x30;
		ca2[2] ='\n';
		display((unsigned char*)"Local Temp  :    ", 26, 48,0,0,1,0);
		display((unsigned char*)&ca1, 126, 48,0,0,1,0);
		display((unsigned char*)".", 142, 48,0,0,1,0);
		display((unsigned char*)&ca2, 150, 48,0,0,1,0);
		display((unsigned char*)"     ", 166, 48,0,0,1,0);
		DIS_IMG(1);
		DelayS(3);
	}

}

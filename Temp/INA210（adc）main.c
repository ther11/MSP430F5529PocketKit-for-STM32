//用了那个电子墨水屏，pa0-5是屏，6是adc。接线说明：PA0-6分别接p1.4,p3.2,p3.3,p2.7,p3.4,p2.2，p6.6
#include "stm32f10x.h"
#include "Delay.h"
//#include "EasyIO.h"
#include "INA210.h"
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
//	  DelayS(3);		
//    }
	
  char t[5];
	char disp[10]={'0','1','2','3','4','5','6','7','8','9'};
	//float V1;
	unsigned int V2;
	
	DelayInit(72);
	PaperIO_Int();
	INA210IO_Init();
	display((unsigned char*)" INA210 TEST  ", 42, 4,0,0,1,0);
	while(1)
	{
		V2=(ReadData())*100;										//计算mA值
		t[0]=disp[V2/100];
		t[1]=disp[(V2/10)-((V2/100)*10)];
		t[2]=disp[V2-(V2/10)*10];
		t[3]='\n';
		display((unsigned char*)" I =  ", 42, 48,0,0,1,0);
		display((unsigned char*)t, 80, 48,0,0,1,0);
		display((unsigned char*)" mA  ", 104, 48,0,0,1,0);
	  DIS_IMG(1);
		DelayS(3);
	}

}

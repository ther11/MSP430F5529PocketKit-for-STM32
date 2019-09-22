//例程这里的DRV8837没有用pwm，仅用高低电平控制，为0或100%
//仅初始化3个IO口，没有使用例程的按键控制，改为循环闪烁
//如需pwm控制自行搜索手册和驱动

#include "stm32f10x.h" //#include <msp430.h>
#include "motor.h"
void ioinit(void)
{
//	P1DIR |= BIT5;						//设置P1.5为输出模式
//	P8DIR |= BIT1;						//设置P8.1为输出模式
//	P1REN |= BIT2+BIT3;					//使能S1，S2的上下拉电阻
//	P1OUT |= BIT2+BIT3;					//设置S1，S2为上拉状态
//	P2DIR |= BIT2+BIT4+BIT5;              	//设置P2.2,P2.4和P2.5为输出模式
//	P2OUT &= ~BIT2;
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);	
}
void DCmotor(int p)
{
  switch(p)
  {
  case 0:					//停转
    {
      GPIO_ResetBits(GPIOA,GPIO_Pin_0); //P1OUT &=~ BIT5;
      GPIO_ResetBits(GPIOA,GPIO_Pin_1); //P2OUT &=~ BIT5;
      GPIO_ResetBits(GPIOA,GPIO_Pin_2); //P2OUT &=~ BIT4;
      break;
    }
  case 1:					//正转
    {
      GPIO_SetBits(GPIOA,GPIO_Pin_0); //P1OUT |= BIT5;
      GPIO_SetBits(GPIOA,GPIO_Pin_1); //P2OUT |= BIT5;
      GPIO_ResetBits(GPIOA,GPIO_Pin_2); //P2OUT &=~ BIT4;
      break;
    }
  case 2:					//反转
    {
      GPIO_SetBits(GPIOA,GPIO_Pin_0); //P1OUT |= BIT5;
      GPIO_ResetBits(GPIOA,GPIO_Pin_1); //P2OUT &=~ BIT5;
      GPIO_SetBits(GPIOA,GPIO_Pin_2); //P2OUT |= BIT4;
      break;
    }
  }
}


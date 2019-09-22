//���������DRV8837û����pwm�����øߵ͵�ƽ���ƣ�Ϊ0��100%
//����ʼ��3��IO�ڣ�û��ʹ�����̵İ������ƣ���Ϊѭ����˸
//����pwm�������������ֲ������

#include "stm32f10x.h" //#include <msp430.h>
#include "motor.h"
void ioinit(void)
{
//	P1DIR |= BIT5;						//����P1.5Ϊ���ģʽ
//	P8DIR |= BIT1;						//����P8.1Ϊ���ģʽ
//	P1REN |= BIT2+BIT3;					//ʹ��S1��S2������������
//	P1OUT |= BIT2+BIT3;					//����S1��S2Ϊ����״̬
//	P2DIR |= BIT2+BIT4+BIT5;              	//����P2.2,P2.4��P2.5Ϊ���ģʽ
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
  case 0:					//ͣת
    {
      GPIO_ResetBits(GPIOA,GPIO_Pin_0); //P1OUT &=~ BIT5;
      GPIO_ResetBits(GPIOA,GPIO_Pin_1); //P2OUT &=~ BIT5;
      GPIO_ResetBits(GPIOA,GPIO_Pin_2); //P2OUT &=~ BIT4;
      break;
    }
  case 1:					//��ת
    {
      GPIO_SetBits(GPIOA,GPIO_Pin_0); //P1OUT |= BIT5;
      GPIO_SetBits(GPIOA,GPIO_Pin_1); //P2OUT |= BIT5;
      GPIO_ResetBits(GPIOA,GPIO_Pin_2); //P2OUT &=~ BIT4;
      break;
    }
  case 2:					//��ת
    {
      GPIO_SetBits(GPIOA,GPIO_Pin_0); //P1OUT |= BIT5;
      GPIO_ResetBits(GPIOA,GPIO_Pin_1); //P2OUT &=~ BIT5;
      GPIO_SetBits(GPIOA,GPIO_Pin_2); //P2OUT |= BIT4;
      break;
    }
  }
}


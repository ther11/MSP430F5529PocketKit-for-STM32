#include "stm32f10x.h"
#include "Delay.h"
static uint8_t  facUs = 0;																		//us��ʱ������
static uint16_t facMs = 0;																		//ms��ʱ������
 
void DelayInit(uint8_t SYSCLK)
{
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);	//ѡ���ⲿʱ��,HCLK/8
	facUs = SYSCLK / 8; //Ӳ����Ƶ,fac_us�ó���ֵҪ�������ʱ�Ӻ���ʹ��
	facMs = (u16)facUs * 1000;
}
 
void DelayUs(uint32_t nus)
{
	uint32_t temp;
	SysTick->LOAD = nus*facUs;  //��ʱ10us,10*9 = 90,װ��load�Ĵ�����
	SysTick->VAL = 0x00;//��������0
	SysTick->CTRL = 0x01;//�����쳣��Ч,Ҳ���Ǽ�����������0ʱ�����쳣֪ͨ
	do
	{
		temp = SysTick->CTRL;//ʱ�䵽,��λ����Ӳ����1,������ѯ���Զ���0
	} while (temp & 0x01 && !(temp &(1 << 16)));//��ѯ
	SysTick->CTRL = 0x00;//�رն�ʱ��
	SysTick->VAL = 0x00;//���val,��ն�ʱ��
}
 
 
void DelayMs(uint16_t nms)
{
	uint32_t temp;
	SysTick->LOAD = nms*facMs;//��ʱ10ms,10*9 = 90,װ��load�Ĵ�����
	SysTick->VAL = 0x00;//��������0
	SysTick->CTRL = 0x01;//�����쳣��Ч,Ҳ���Ǽ�����������0ʱ�����쳣֪ͨ
	do
	{
		temp = SysTick->CTRL;//ʱ�䵽,��λ����Ӳ����1,������ѯ���Զ���0
	} while (temp & 0x01 && !(temp &(1 << 16)));//��ѯ
 
	SysTick->CTRL = 0x00;//�رն�ʱ��
	SysTick->VAL = 0x00;//���val,��ն�ʱ��
}
void DelayS(unsigned int ns)
{
	unsigned int i=0;
	for(i=0;i<ns;i++)
		DelayMs(1000);
}

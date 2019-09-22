#include "stm32f10x.h"
#include "INA210.h"
void INA210IO_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_ADC1, ENABLE);
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);	
	ADC_DeInit(ADC1);
	
	GPIO_InitTypeDef GPIO_InitStructure; 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;                                             
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                                     
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;                                         
	GPIO_Init(GPIOA, &GPIO_InitStructure);  
	
	ADC_InitTypeDef ADC_InitStructure;
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;                                    
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;                                         
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;                                   
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;                   
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;                                
	ADC_InitStructure.ADC_NbrOfChannel = 1;                                               
	ADC_Init(ADC1, &ADC_InitStructure);                                                   
	//ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_1Cycles5);            
	ADC_Cmd(ADC1,ENABLE);                                                                                                                                     
	ADC_ResetCalibration(ADC1);	//使能复位校准  
	while(ADC_GetResetCalibrationStatus(ADC1));	//等待复位校准结束
	ADC_StartCalibration(ADC1);	 //开启AD校准
	while(ADC_GetCalibrationStatus(ADC1));                                             
	                                                                                                                 
 
}
 

float ReadData(void)
{
	float Vo=0;                                                                                                                                                                                                                                                                                                                                                               
	ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 1, ADC_SampleTime_1Cycles5);	
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);                                                		
	while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));                                         	
	Vo=(3.3*(((float)ADC_GetConversionValue(ADC1)/4096)));                                
	return Vo;                                                                            
                                      
	
}

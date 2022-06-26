#include "adc.h"
#include "gui.h"
#include "stm32f10x.h"
#include "SysConfig.h"
#define ADC1_DR_Address    ((u32)0x4001244C)
ADC_InitTypeDef ADC_InitStructure;
DMA_InitTypeDef DMA_InitStructure;
unsigned int ADCConvertedValue;
void ADC_Configuration(void)
{
   /* DMA1 channel1 configuration ----------------------------------------------*/
   DMA_DeInit(DMA1_Channel1);
   DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_DR_Address;
   DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&ADCConvertedValue;
   DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
   DMA_InitStructure.DMA_BufferSize = 1;
   DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
   DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;
   DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
   DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
   DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
   DMA_InitStructure.DMA_Priority = DMA_Priority_High;
   DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
   DMA_Init(DMA1_Channel1, &DMA_InitStructure);
  
   /* Enable DMA1 channel1 */
   DMA_Cmd(DMA1_Channel1, ENABLE);
   
   /* ADC1 configuration ------------------------------------------------------*/
   ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
   ADC_InitStructure.ADC_ScanConvMode = ENABLE;
   ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
   ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
   ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
   ADC_InitStructure.ADC_NbrOfChannel = 1;
   ADC_Init(ADC1, &ADC_InitStructure);
   /* ADC1 regular channel14 configuration */ 
   ADC_RegularChannelConfig(ADC1, ADC_Channel_16, 1, ADC_SampleTime_55Cycles5); // ADC_Channel_16 ADC_Channel_TempSensor
   /* Enable the temperature sensor and vref internal channel */ 
   ADC_TempSensorVrefintCmd(ENABLE); 
   /* Enable ADC1 DMA */
   ADC_DMACmd(ADC1, ENABLE);
  
   /* Enable ADC1 */
   ADC_Cmd(ADC1, ENABLE);
   /* Enable ADC1 reset calibaration register */ 
   ADC_ResetCalibration(ADC1);
   /* Check the end of ADC1 reset calibration register */
   while(ADC_GetResetCalibrationStatus(ADC1));
   /* Start ADC1 calibaration */
   ADC_StartCalibration(ADC1);
   /* Check the end of ADC1 calibration */
   while(ADC_GetCalibrationStatus(ADC1));
   
   /* Start ADC1 Software Conversion */ 
   ADC_SoftwareStartConvCmd(ADC1, ENABLE);
}

/*******************************************************************************
* Name : ADC_Filter
* Deion    : ADC_Filter
* Input          : None
* Output         : None
* Return         : ADC Converted Value
*******************************************************************************/
u16 ADC_Filter(void)
{
	u16 result=0;
	u32 i,j;
	for(i=16;i>0;i--)
	{
		for(j=0;j<5000;j++); 

		result += ADCConvertedValue;
	}

	return result/16;
}

void Oscilloscope(void)
{
	GUI_SetBkColor(GUI_BLACK);
  GUI_Clear();
	GUI_SetColor(GUI_RED);
	GUI_DrawHLine(120,0,320);
	GUI_DrawVLine(0  ,0,240);
}




#include "fifo.h"


void  FIFO_Set_GPIO_Config(void)
{
  
  GPIO_InitTypeDef GPIO_InitStructure;
  /* Enable GPIOA clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
  GPIO_InitStructure.GPIO_Pin =FIFO_RD_BIT|FIFO_WRST_BIT|FIFO_RRST_BIT|FIFO_CS_BIT;                               
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure); 
  FIFO_CS_H();
  FIFO_WRST_H();
  FIFO_RRST_H();
  FIFO_RD_H();
 
}
static void FIFO_GPIO_INPUT(void)	   //
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable GPIOB clock */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD|RCC_APB2Periph_AFIO, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IPU ;//// GPIO_Mode_IN_FLOATING;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
}

void Fifo_Init()
{
 FIFO_Set_GPIO_Config();
 FIFO_GPIO_INPUT();
}

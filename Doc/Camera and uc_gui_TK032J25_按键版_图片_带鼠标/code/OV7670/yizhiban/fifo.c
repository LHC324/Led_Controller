//-------------------------------------------------
//移植到新版项目V2
//修改者:潘振星
//2010/11/12
//-------------------------------------------------
/*
修改历史:
1,2010/11/20 16:30,进行了可移植性处理
*/

#include "fifo.h"


void  FIFO_Set_GPIO_Config(void)
{
  
  GPIO_InitTypeDef GPIO_InitStructure;
  /* Enable GPIOC clock */
  RCC_APB2PeriphClockCmd(FIFO_CONTROL_PORT_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =FIFO_RD_BIT|FIFO_WRST_BIT|FIFO_RRST_BIT|FIFO_CS_BIT;                               
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(FIFO_CONTROL_PORT, &GPIO_InitStructure); 
  FIFO_CS_H();
  FIFO_WRST_H();
  FIFO_RRST_H();
  FIFO_RD_H();
 
}



static void FIFO_GPIO_INPUT(void)	   //
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable GPIOB clock */
  RCC_APB2PeriphClockCmd(FIFO_DATA_PORT_CLK|RCC_APB2Periph_AFIO, ENABLE);
  //RCC_APB2PeriphClockCmd(FIFO_DATA_PORT_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin = FIFO_DATA_PINS;
  GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IN_FLOATING;////GPIO_Mode_IPU ;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(FIFO_DATA_PORT, &GPIO_InitStructure);
}



void Fifo_Init()
{
 FIFO_Set_GPIO_Config();
 FIFO_GPIO_INPUT();
}

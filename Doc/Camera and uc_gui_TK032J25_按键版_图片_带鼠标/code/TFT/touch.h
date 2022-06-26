//*************************************************
//作者：XING
//功能描述：触屏函数
//建立时间：2010/11/08  
//最后修改时间：
//*************************************************
/*
  修改历史:
  1,2010/11/23, 10:01,加入软件模拟SPI功能

*/
#ifndef  __TOUCH_H__
#define  __TOUCH_H__

#include "stm32f10x.h"

// A/D 通道选择命令字和工作寄存器
// #define	CHX 	0xd0 	//通道Y+的选择控制字	
// #define	CHY 	0x90	//通道X+的选择控制字
#define	CHX 	0x90 	//通道Y+的选择控制字	
#define	CHY 	0xd0	//通道X+的选择控制字

#define	 SPI_CLK	  GPIO_Pin_13
#define  SPI_CS		  GPIO_Pin_12
#define	 SPI_MOSI	  GPIO_Pin_15
#define	 SPI_MISO	  GPIO_Pin_14
#define  TP_INT_PIN	  GPIO_Pin_4

#define TP_DCLK(a)	\
						if (a)	\
						GPIO_SetBits(GPIOB,GPIO_Pin_13);	\
						else		\
						GPIO_ResetBits(GPIOB,GPIO_Pin_13)
#define TP_CS(a)	\
						if (a)	\
						GPIO_SetBits(GPIOB,GPIO_Pin_12);	\
						else		\
						GPIO_ResetBits(GPIOB,GPIO_Pin_12)
#define TP_DIN(a)	\
						if (a)	\
						GPIO_SetBits(GPIOB,GPIO_Pin_15);	\
						else		\
						GPIO_ResetBits(GPIOB,GPIO_Pin_15)

#define TP_DOUT		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)//	//数据输入

void Touch_GPIO_Config(void);

int GUI_TOUCH_X_MeasureX(void); 
int GUI_TOUCH_X_MeasureY(void);

unsigned int TOUCH_X(void); 
unsigned int TOUCH_Y(void); 
void TP_GetAdXY(unsigned int *x,unsigned int *y);

char IsPressed(u16 x, u16 y,u16 x0, u16 y0, u16 lenth, u16 width,char* pressed);
char IsPressed_V2(u16 x, u16 y,u16 x0, u16 y0, u16 lenth, u16 width,char* pressed);
char IsPressed_V3(u16 x, u16 y,u16 x0, u16 y0, u16 lenth, u16 width,char* pressed);


#endif                                     

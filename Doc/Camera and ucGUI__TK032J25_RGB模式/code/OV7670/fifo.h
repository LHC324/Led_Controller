//-------------------------------------------------
//移植到新MINI版项目
//修改者:XING
//2010/11/12
//-------------------------------------------------
/*
修改历史:
1,2010/11/20 16:30,进行了可移植性处理
2,2010/11/22 22:00,移植到最新底板
3,2010/11/28 19:48,移植到新MINI版项目
*/

#ifndef _OV7670_FIFO_
#define	_OV7670_FIFO_

#include "stm32f10x.h"

//------------------------------------------------------------
#define FIFO_CONTROL_PORT_CLK   RCC_APB2Periph_GPIOA
#define FIFO_CONTROL_PORT       GPIOA

#define FIFO_WRST_PORT   GPIOA
#define FIFO_CS_PORT     GPIOA
#define FIFO_RRST_PORT   GPIOA
#define FIFO_RD_PORT     GPIOA

#define FIFO_WRST_BIT   GPIO_Pin_3  // A8
#define FIFO_CS_BIT     GPIO_Pin_4  // A9//OE
#define FIFO_RRST_BIT   GPIO_Pin_10 // pA10
#define FIFO_RD_BIT     GPIO_Pin_9  // A11

#define FIFO_DATA_PORT_CLK   RCC_APB2Periph_GPIOB
#define FIFO_DATA_PORT       GPIOB
#define FIFO_DATA_PINS       (GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15)

//------------------------------------------------------------
#define FIFO_CS_H()    FIFO_CS_PORT->BSRR =FIFO_CS_BIT
#define FIFO_CS_L()    FIFO_CS_PORT->BRR  =FIFO_CS_BIT

#define FIFO_WRST_H()  FIFO_WRST_PORT->BSRR =FIFO_WRST_BIT
#define FIFO_WRST_L()  FIFO_WRST_PORT->BRR  =FIFO_WRST_BIT

#define FIFO_RRST_H()  FIFO_RRST_PORT->BSRR =FIFO_RRST_BIT
#define FIFO_RRST_L()  FIFO_RRST_PORT->BRR  =FIFO_RRST_BIT

#define FIFO_RD_H()    FIFO_RD_PORT->BSRR =FIFO_RD_BIT
#define FIFO_RD_L()    FIFO_RD_PORT->BRR  =FIFO_RD_BIT

#define Read_Fifo	   
//------------------------------------------------------------

void  FIFO_Set_GPIO_Config(void);
void  FIFO_Set_GPIO_Config_END(void);
//void FIFO_GPIO_INPUT(void);
void Fifo_Init(void);
#endif
/*********************end*********************/

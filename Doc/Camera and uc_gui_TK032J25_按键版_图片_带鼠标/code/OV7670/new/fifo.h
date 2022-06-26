#include "stm32f10x_lib.h"


#define FIFO_WRST_BIT   GPIO_Pin_9  // A8
#define FIFO_CS_BIT     GPIO_Pin_12  // A9
#define FIFO_RRST_BIT   GPIO_Pin_11 // pA10
#define FIFO_RD_BIT     GPIO_Pin_10  // A11

#define FIFO_CS_H()    GPIOC->BSRR =FIFO_CS_BIT
#define FIFO_CS_L()    GPIOC->BRR  =FIFO_CS_BIT

#define FIFO_WRST_H()  GPIOC->BSRR =FIFO_WRST_BIT
#define FIFO_WRST_L()  GPIOC->BRR  =FIFO_WRST_BIT

#define FIFO_RRST_H()  GPIOC->BSRR =FIFO_RRST_BIT
#define FIFO_RRST_L()  GPIOC->BRR  =FIFO_RRST_BIT

#define FIFO_RD_H()    GPIOC->BSRR =FIFO_RD_BIT
#define FIFO_RD_L()    GPIOC->BRR  =FIFO_RD_BIT

#define Read_Fifo	   

void  FIFO_Set_GPIO_Config(void);
//void FIFO_GPIO_INPUT(void);
void Fifo_Init(void);

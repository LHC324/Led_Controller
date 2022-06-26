
#ifndef __SPI_H
#define __SPI_H
#include "stm32f10x.h"

#define GPIO_SPI1     GPIOA
#define RCC_SPI1      RCC_APB2Periph_GPIOA
#define SPI1_CS       GPIO_Pin_4
#define SPI1_SCK      GPIO_Pin_5
#define SPI1_MISO     GPIO_Pin_6
#define SPI1_MOSI     GPIO_Pin_7

																					  
void SPI1_Init(void);			 //初始化SPI口 
u8 SPI1_ReadWriteByte(u8 TxData);//SPI1总线读写一个字节
		 
#endif


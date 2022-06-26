#ifndef _OV7670_H
#define _OV7670_H


#include "SCCB.h"

#define CHANGE_REG_NUM 167

#define OV7670_HREF_BIT     GPIO_Pin_15//PC5
#define OV7670_VSYNC_BIT    GPIO_Pin_14//PC4

#define HREF_H		 GPIO_SetBits(GPIOC,GPIO_Pin_15);
#define HREF_L		 GPIO_ResetBits(GPIOC,GPIO_Pin_15);


/*
  #define GPIO_HREF_CMOS                    GPIOC
  #define RCC_APB2Periph_GPIO_HREF_CMOS     RCC_APB2Periph_GPIOC
  #define GPIO_PIN_HREF_CMOS                GPIO_Pin_5
  #define EXTI_LINE_HREF_CMOS               EXTI_Line5
  #define GPIO_PORT_SOURCE_HREF_CMOS        GPIO_PortSourceGPIOC
  #define GPIO_PIN_SOURCE_HREF_CMOS         GPIO_PinSource5
*/
  #define GPIO_VSYNC_CMOS                    GPIOC
  #define RCC_APB2Periph_GPIO_VSYNC_CMOS     RCC_APB2Periph_GPIOC
  #define GPIO_PIN_VSYNC_CMOS                GPIO_Pin_14
  #define EXTI_LINE_VSYNC_CMOS               EXTI_Line14
  #define GPIO_PORT_SOURCE_VSYNC_CMOS        GPIO_PortSourceGPIOC
  #define GPIO_PIN_SOURCE_VSYNC_CMOS         GPIO_PinSource14



#define XCLK_H	            GPIOA->BSRR =  GPIO_Pin_8;;
#define XCLK_L	            GPIOA->BRR =   GPIO_Pin_8;;

/////////////////////////////////////////
void XCLK_init_ON(void);
void XCLK_init_OFF(void);
unsigned char wrOV7670Reg(unsigned char regID, unsigned char regDat);
unsigned char rdOV7670Reg(unsigned char regID, unsigned char *regDat);
void OV7670_config_window(unsigned int startx,unsigned int starty,unsigned int width, unsigned int height);
unsigned char OV7670_init(void);
void ov7670_GPIO_Init(void);
void OV7670_EXTI_Config(void);
void ov7670_Interrupts_Config(void);

#endif /* _OV7670_H */




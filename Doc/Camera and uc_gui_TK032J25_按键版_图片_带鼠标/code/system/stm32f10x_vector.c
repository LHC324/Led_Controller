/******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
* File Name          : stm32f10x_vector.c
* Author             : MCD Application Team
* Date First Issued  : mm/dd/yyyy
* Description        : This file contains the vector table for STM32F10x.
*                      After Reset the Cortex-M3 processor is in Thread mode,
*                      priority is Privileged, and the Stack is set to Main.
********************************************************************************
* History:
* 05/21/2007: V0.3
* 04/02/2007: V0.2
********************************************************************************
* THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"

/* Private typedef -----------------------------------------------------------*/
typedef void(*ExecFuncPtr)(void);

/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

#pragma arm section rwdata = "VECT_TABLE"
ExecFuncPtr stm32F10x_vector_table[] = {
  /*&Image$$ARM_LIB_STACK$$ZI$$Limit, ;;Initial SP, already provided by library */
  /*&__main, ;;Initial PC, already provided by library */
  &NMIException,
  &HardFaultException,
  &MemManageException,
  &BusFaultException,
  &UsageFaultException,
  0, 0, 0, 0,           /* Reserved */
  &SVCHandler,
  &DebugMonitor,
  0,                    /* Reserved */
  &PendSVC,
  &SysTickHandler,
  &WWDG_IRQHandler,
  &PVD_IRQHandler,
  &TAMPER_IRQHandler,
  &RTC_IRQHandler,
  &FLASH_IRQHandler,
  &RCC_IRQHandler,
  &EXTI0_IRQHandler,
  &EXTI1_IRQHandler,
  &EXTI2_IRQHandler,
  &EXTI3_IRQHandler,
  &EXTI4_IRQHandler,
  &DMAChannel1_IRQHandler,
  &DMAChannel2_IRQHandler,
  &DMAChannel3_IRQHandler,
  &DMAChannel4_IRQHandler,
  &DMAChannel5_IRQHandler,
  &DMAChannel6_IRQHandler,
  &DMAChannel7_IRQHandler,
  &ADC_IRQHandler,
  &USB_HP_CAN_TX_IRQHandler,
  &USB_LP_CAN_RX0_IRQHandler,
  &CAN_RX1_IRQHandler,
  &CAN_SCE_IRQHandler,
  &EXTI9_5_IRQHandler,
  &TIM1_BRK_IRQHandler,
  &TIM1_UP_IRQHandler,
  &TIM1_TRG_COM_IRQHandler,
  &TIM1_CC_IRQHandler,
  &TIM2_IRQHandler,
  &TIM3_IRQHandler,
  &TIM4_IRQHandler,
  &I2C1_EV_IRQHandler,
  &I2C1_ER_IRQHandler,
  &I2C2_EV_IRQHandler,
  &I2C2_ER_IRQHandler,
  &SPI1_IRQHandler,
  &SPI2_IRQHandler,
  &USART1_IRQHandler,
  &USART2_IRQHandler,
  &USART3_IRQHandler,
  &EXTI15_10_IRQHandler,
  &RTCAlarm_IRQHandler,
  &USBWakeUp_IRQHandler
};
#pragma arm section

/******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE****/

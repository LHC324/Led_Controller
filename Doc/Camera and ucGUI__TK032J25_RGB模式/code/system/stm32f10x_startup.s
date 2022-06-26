;******************** (C) COPYRIGHT 2007 STMicroelectronics ********************
;* File Name          : stm32f10x_startup.s
;* Author             : MCD Application Team
;* Date First Issued  : 02/05/2007
;* Description        : This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == Reset_Handler,
;*                      - Set the vector table entries with the exceptions ISR address,
;*                      - Branches to __main in the C library (which eventually
;*                        calls main()).
;*                      After Reset the CortexM3 processor is in Thread mode,
;*                      priority is Privileged, and the Stack is set to Main.
;*******************************************************************************
; History:
; 05/21/2007: V0.3
; 04/02/2007: V0.2
; 02/05/2007: V0.1
;*******************************************************************************
; THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
; WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
; AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
; INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
; CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
; INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
;*******************************************************************************
  THUMB
  REQUIRE8
  PRESERVE8

  EXPORT  __user_initial_stackheap
  EXPORT  Reset_Handler
  
  IMPORT  __main
  IMPORT  __use_two_region_memory

  ; Import exceptions handlers
  IMPORT  NMIException
  IMPORT  HardFaultException
  IMPORT  MemManageException
  IMPORT  BusFaultException
  IMPORT  UsageFaultException
  IMPORT  SVCHandler
  IMPORT  DebugMonitor
  IMPORT  PendSVC
  IMPORT  SysTickHandler
  IMPORT  WWDG_IRQHandler
  IMPORT  PVD_IRQHandler
  IMPORT  TAMPER_IRQHandler
  IMPORT  RTC_IRQHandler
  IMPORT  FLASH_IRQHandler
  IMPORT  RCC_IRQHandler
  IMPORT  EXTI0_IRQHandler
  IMPORT  EXTI1_IRQHandler
  IMPORT  EXTI2_IRQHandler
  IMPORT  EXTI3_IRQHandler
  IMPORT  EXTI4_IRQHandler
  IMPORT  DMAChannel1_IRQHandler
  IMPORT  DMAChannel2_IRQHandler
  IMPORT  DMAChannel3_IRQHandler
  IMPORT  DMAChannel4_IRQHandler
  IMPORT  DMAChannel5_IRQHandler
  IMPORT  DMAChannel6_IRQHandler
  IMPORT  DMAChannel7_IRQHandler
  IMPORT  ADC_IRQHandler
  IMPORT  USB_HP_CAN_TX_IRQHandler
  IMPORT  USB_LP_CAN_RX0_IRQHandler
  IMPORT  CAN_RX1_IRQHandler
  IMPORT  CAN_SCE_IRQHandler
  IMPORT  EXTI9_5_IRQHandler
  IMPORT  TIM1_BRK_IRQHandler
  IMPORT  TIM1_UP_IRQHandler
  IMPORT  TIM1_TRG_COM_IRQHandler
  IMPORT  TIM1_CC_IRQHandler
  IMPORT  TIM2_IRQHandler
  IMPORT  TIM3_IRQHandler
  IMPORT  TIM4_IRQHandler
  IMPORT  I2C1_EV_IRQHandler
  IMPORT  I2C1_ER_IRQHandler
  IMPORT  I2C2_EV_IRQHandler
  IMPORT  I2C2_ER_IRQHandler
  IMPORT  SPI1_IRQHandler
  IMPORT  SPI2_IRQHandler
  IMPORT  USART1_IRQHandler
  IMPORT  USART2_IRQHandler
  IMPORT  USART3_IRQHandler
  IMPORT  EXTI15_10_IRQHandler
  IMPORT  RTCAlarm_IRQHandler
  IMPORT  USBWakeUp_IRQHandler
  
; Amount of memory (in bytes) allocated for Stack and Heap
; Tailor those values to your application needs
Stack_Size   EQU     0x200
Heap_Size    EQU     0x200

;*******************************************************************************
; Allocate space for the Stack
;*******************************************************************************
  AREA    STACK, NOINIT, READWRITE, ALIGN=3

Stack
    SPACE   Stack_Size

;*******************************************************************************
; Allocate space for the Heap
;*******************************************************************************
  AREA    HEAP, NOINIT, READWRITE, ALIGN=3

Heap
    SPACE   Heap_Size


;*******************************************************************************
; Fill-up the Vector Table entries with the exceptions ISR address
;*******************************************************************************
  AREA    RESET, CODE, READONLY
      
    DCD  Stack + Stack_Size            ; Top of Stack
    DCD  Reset_Handler
    DCD  NMIException
    DCD  HardFaultException
    DCD  MemManageException
    DCD  BusFaultException
    DCD  UsageFaultException
    DCD  0                 ; Reserved
    DCD  0                 ; Reserved
    DCD  0                 ; Reserved
    DCD  0                 ; Reserved
    DCD  SVCHandler
    DCD  DebugMonitor
    DCD  0                 ; Reserved
    DCD  PendSVC
    DCD  SysTickHandler
    DCD  WWDG_IRQHandler
    DCD  PVD_IRQHandler
    DCD  TAMPER_IRQHandler
    DCD  RTC_IRQHandler
    DCD  FLASH_IRQHandler
    DCD  RCC_IRQHandler
    DCD  EXTI0_IRQHandler
    DCD  EXTI1_IRQHandler
    DCD  EXTI2_IRQHandler
    DCD  EXTI3_IRQHandler
    DCD  EXTI4_IRQHandler
    DCD  DMAChannel1_IRQHandler
    DCD  DMAChannel2_IRQHandler
    DCD  DMAChannel3_IRQHandler
    DCD  DMAChannel4_IRQHandler
    DCD  DMAChannel5_IRQHandler
    DCD  DMAChannel6_IRQHandler
    DCD  DMAChannel7_IRQHandler
    DCD  ADC_IRQHandler
    DCD  USB_HP_CAN_TX_IRQHandler
    DCD  USB_LP_CAN_RX0_IRQHandler
    DCD  CAN_RX1_IRQHandler
    DCD  CAN_SCE_IRQHandler
    DCD  EXTI9_5_IRQHandler
    DCD  TIM1_BRK_IRQHandler
    DCD  TIM1_UP_IRQHandler
    DCD  TIM1_TRG_COM_IRQHandler
    DCD  TIM1_CC_IRQHandler
    DCD  TIM2_IRQHandler
    DCD  TIM3_IRQHandler
    DCD  TIM4_IRQHandler
    DCD  I2C1_EV_IRQHandler
    DCD  I2C1_ER_IRQHandler
    DCD  I2C2_EV_IRQHandler
    DCD  I2C2_ER_IRQHandler
    DCD  SPI1_IRQHandler
    DCD  SPI2_IRQHandler
    DCD  USART1_IRQHandler
    DCD  USART2_IRQHandler
    DCD  USART3_IRQHandler
    DCD  EXTI15_10_IRQHandler
    DCD  RTCAlarm_IRQHandler
    DCD  USBWakeUp_IRQHandler 
    DCD  0                 ; Reserved
    DCD  0                 ; Reserved
    DCD  0                 ; Reserved
    DCD  0                 ; Reserved
    DCD  0                 ; Reserved

; Reset handler routine
Reset_Handler
    ; Branch to C Library entry point
    B __main
  
  ALIGN
  

;*******************************************************************************
; Implementation of __user_initial_stackheap that places the Stack and Heap
;*******************************************************************************
  AREA    |.text|, CODE, READONLY
  
__user_initial_stackheap
        LDR     R0, =Heap
        LDR     R1, =(Stack + Stack_Size)
        LDR     R2, =(Heap + Heap_Size)
        LDR     R3, =Stack
        BX      LR

  ALIGN
  END


;******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE*****

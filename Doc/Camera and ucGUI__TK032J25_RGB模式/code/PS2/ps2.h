#ifndef __PS2_H
#define __PS2_H	
#include "stm32f10x.h" 
// #include "SYSTICK.h"	   
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//Mini STM32开发板
//PS2 驱动代码		   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2010/6/17 
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 正点原子 2009-2019
//All rights reserved
//////////////////////////////////////////////////////////////////////////////////	 

				   
//物理接口定义
//PS2输入	  				    
#define PS2_SCL GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2)	//PA1
#define PS2_SDA GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1)	//PA2
//PS2输出
#define PS2_SCL_OUT_OFF GPIO_ResetBits(GPIOC, GPIO_Pin_2)	//PA1
#define PS2_SDA_OUT_OFF GPIO_ResetBits(GPIOC, GPIO_Pin_1)	//PA2

#define PS2_SCL_OUT_ON GPIO_SetBits(GPIOC, GPIO_Pin_2)	    //PA1
#define PS2_SDA_OUT_ON GPIO_SetBits(GPIOC, GPIO_Pin_1)  	//PA2
//设置PS2_SCL输入输出状态.		  
#define PS2_SET_SCL_IN()  {GPIOC->CRL&=0XFFFFF0FF;GPIOC->CRL|=0X00000800;}
#define PS2_SET_SCL_OUT() {GPIOC->CRL&=0XFFFFF0FF;GPIOC->CRL|=0X00000300;}	  
//设置PS2_SDA输入输出状态.		  
#define PS2_SET_SDA_IN()  {GPIOC->CRL&=0XFFFFFF0F;GPIOC->CRL|=0X00000080;}
#define PS2_SET_SDA_OUT() {GPIOC->CRL&=0XFFFFFF0F;GPIOC->CRL|=0X00000030;} 

#define MOUSE    0X20 //鼠标模式
#define KEYBOARD 0X10 //键盘模式
#define CMDMODE  0X00 //发送命令
//PS2_Status当前状态标志
//[5:4]:当前工作的模式;[7]:接收到一次数据
//[6]:校验错误;[3:0]:收到的数据长度;	 
extern u8 PS2_Status;       //定义为命令模式
extern u8 PS2_DATA_BUF[16]; //ps2数据缓存区
extern u8 MOUSE_ID;
extern u8 int_ps2_end;

void PS2_Init(void);
u8 PS2_Send_Cmd(u8 cmd);
void PS2_Set_Int(u8 en);
u8 PS2_Get_Byte(void);
void PS2_En_Data_Report(void);  
void PS2_Dis_Data_Report(void);		  				    
#endif

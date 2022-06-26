//-------------------------------------------------
//移植到新版项目V2
//修改者:潘振星
//2010/11/12
//-------------------------------------------------
/*
修改历史:
1,2010/11/20 12:11,修改了
  void SCCB_GPIO_Config(void),
  void SCCB_SID_GPIO_OUTPUT(void),
  void SCCB_SID_GPIO_INPUT(void)
*/

#include "sccb.h"
#include "delay.h"
#include "stm32f10x_lib.h"


/*
-----------------------------------------------
   功能: 初始化模拟SCCB接口
   参数: 无
 返回值: 无
-----------------------------------------------
*/
void SCCB_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
 
 #if SIC_SID_PORT_SAME

  /* Enable GPIOA  clock */
  RCC_APB2PeriphClockCmd(SIC_SID_PORT_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  SCCB_SIC_BIT|SCCB_SID_BIT;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
  GPIO_Init(SIC_SID_PORT, &GPIO_InitStructure);
 #else

  RCC_APB2PeriphClockCmd(SIC_PORT_CLK, ENABLE);  
  RCC_APB2PeriphClockCmd(SID_PORT_CLK, ENABLE);

  GPIO_InitStructure.GPIO_Pin =  SCCB_SIC_BIT;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
  GPIO_Init(SIC_PORT, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin =  SCCB_SID_BIT;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed =GPIO_Speed_50MHz;
  GPIO_Init(SID_PORT, &GPIO_InitStructure);
#endif

}


/*
-----------------------------------------------
   功能: 设置SID端口为输出
   参数: 无
 返回值: 无
-----------------------------------------------
*/
void SCCB_SID_GPIO_OUTPUT(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
   /* Enable GPIOC  clock */
  RCC_APB2PeriphClockCmd(SID_PORT_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  SCCB_SID_BIT;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(SID_PORT, &GPIO_InitStructure);
}


/*
-----------------------------------------------
   功能: 设置SID端口为输入
   参数: 无
 返回值: 无
-----------------------------------------------
*/
void SCCB_SID_GPIO_INPUT(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
   /* Enable GPIOC  clock */
  RCC_APB2PeriphClockCmd(SID_PORT_CLK, ENABLE);
  GPIO_InitStructure.GPIO_Pin =  SCCB_SID_BIT;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(SID_PORT, &GPIO_InitStructure);
}

/*
-----------------------------------------------
   功能: start命令,SCCB的起始信号
   参数: 无
 返回值: 无
-----------------------------------------------
*/
void startSCCB(void)
{
    SCCB_SID_H();     //数据线高电平
    OV7670_delay_us(500);

    SCCB_SIC_H();	   //在时钟线高的时候数据线由高至低
    OV7670_delay_us(500);
 
    SCCB_SID_L();
    OV7670_delay_us(500);

    SCCB_SIC_L();	 //数据线恢复低电平，单操作函数必要
    OV7670_delay_us(500);


}
/*
-----------------------------------------------
   功能: stop命令,SCCB的停止信号
   参数: 无
 返回值: 无
-----------------------------------------------
*/
void stopSCCB(void)
{
    SCCB_SID_L();
    OV7670_delay_us(500);
 
    SCCB_SIC_H();	
    OV7670_delay_us(500);
  

    SCCB_SID_H();	
    OV7670_delay_us(500);
   
}

/*
-----------------------------------------------
   功能: noAck,用于连续读取中的最后一个结束周期
   参数: 无
 返回值: 无
-----------------------------------------------
*/
void noAck(void)
{
	
	SCCB_SID_H();	
	OV7670_delay_us(500);
	
	SCCB_SIC_H();	
	OV7670_delay_us(500);
	
	SCCB_SIC_L();	
	OV7670_delay_us(500);
	
	SCCB_SID_L();	
	OV7670_delay_us(500);

}

/*
-----------------------------------------------
   功能: 写入一个字节的数据到SCCB
   参数: 写入数据
 返回值: 发送成功返回1，发送失败返回0
-----------------------------------------------
*/
unsigned char SCCBwriteByte(unsigned char m_data)
{
	unsigned char j,tem;

	for(j=0;j<8;j++) //循环8次发送数据
	{
		if((m_data<<j)&0x80)
		{
			SCCB_SID_H();	
		}
		else
		{
			SCCB_SID_L();	
		}
		OV7670_delay_us(500);
		SCCB_SIC_H();	
		OV7670_delay_us(500);
		SCCB_SIC_L();	
		OV7670_delay_us(500);

	}
	OV7670_delay_us(100);
	SCCB_SID_IN;/*设置SDA为输入*/
	OV7670_delay_us(500);
	SCCB_SIC_H();	
	OV7670_delay_us(100);
	if(SCCB_SID_STATE){tem=0;}   //SDA=1发送失败，返回0}
	else {tem=1;}   //SDA=0发送成功，返回1
	SCCB_SIC_L();	
	OV7670_delay_us(500);	
    SCCB_SID_OUT;/*设置SDA为输出*/

	return (tem);  
}

/*
-----------------------------------------------
   功能: 一个字节数据读取并且返回
   参数: 无
 返回值: 读取到的数据
-----------------------------------------------
*/
unsigned char SCCBreadByte(void)
{
	unsigned char read,j;
	read=0x00;
	
	SCCB_SID_IN;/*设置SDA为输入*/
	OV7670_delay_us(500);
	for(j=8;j>0;j--) //循环8次接收数据
	{		     
		OV7670_delay_us(500);
		SCCB_SIC_H();
		OV7670_delay_us(500);
		read=read<<1;
		if(SCCB_SID_STATE) 
		{
			read=read+1;
		}
		SCCB_SIC_L();
		OV7670_delay_us(500);
	}	
	return(read);
}

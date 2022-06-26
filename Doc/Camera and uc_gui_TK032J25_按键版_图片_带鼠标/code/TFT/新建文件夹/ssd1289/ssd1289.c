#include "ssd1289.h"
//#include "lcd.h"



void ssd1289_Configuration(void)
{ 
	GPIO_InitTypeDef GPIO_InitStructure;
	/*开启相应时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);  
	/*所有Lcd引脚配置为推挽输出*/
	/*16位数据*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	/*控制脚*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
}
/*********************************************************************************
* 名称：DELAY()
* 功能：软件延时函数。用于LCM显示输出时序控制。
* 入口参数：无
* 出口参数：无
**********************************************************************************/
static void delay(uint16 time)
{ 
 while(time--);
}

//ssd1289
static void Delay_nms(int n)
{
  
  u32 f=n,k;
  for (; f!=0; f--)
  {
    for(k=0xFFF; k!=0; k--);
  }
  
}

static void DelayNS(u16 time)                
{
    while(time--!=0);                                                                                                                                 
}

static void DataToWrite(u16 data) 
{
	GPIOE->ODR = data;
}
/******************************************
函数名：Lcd写命令函数
功能：向Lcd指定位置写入应有命令或数据
入口参数：Index 要寻址的寄存器地址
          ConfigTemp 写入的数据或命令值
返回值：无
******************************************/
static void LCD_WR_REG(u16 Index,u16 CongfigTemp)
{
	Clr_Cs;
	Clr_Rs;
	Set_nRd;
	DataToWrite(Index);
	Clr_nWr;
	Set_nWr;
	Set_Rs;       
	DataToWrite(CongfigTemp);       
	Clr_nWr;
	Set_nWr;
	//Set_Cs;
}

/**************************************************************************************
* 名    称: void send_command(u16 out_data
* 功    能: 按位发送命令
* 参    数: out_data要发送的命令
* 返 回 值: 
**************************************************************************************/ 
static void send_command(u16 out_data)              
{
Lcd_RS_low;			//RS为0数据命令输入端
Lcd_WR_high;                    //写数据下降沿有效
Lcd_CS_low;                     //片选上升沿有效
Lcd_rd_high;
//GPIO_ResetBits(GPIOE, 0xffff);  //想要发送和接受数据必须先把GPIO口清0
GPIO_Write(GPIOE, out_data);
Lcd_WR_low;
Lcd_CS_high;
}
/**************************************************************************************
* 名    称: void send_data(u16 out_data)
* 功    能: 发送所要显示的地址的颜色
* 参    数: out_data代表所在位的颜色
* 返 回 值: 
**************************************************************************************/ 
static void send_data(u16 out_data)           
{
Lcd_RS_high;
Lcd_WR_high;
Lcd_CS_low;
//GPIO_ResetBits(GPIOE, 0xffff);      
//GPIO_Write(GPIOE, out_data);
GPIOE->ODR = out_data;
Lcd_WR_low;
Lcd_CS_high;
}

/**************************************************************************************
* 名    称: rece_data(void)
* 功    能: 读出此时GPIOE端口的数据
* 参    数: 
* 返 回 值: i读出的数据
**************************************************************************************/ 
static u16 rece_data(void)              
{

u16 i; 
Lcd_rd_high;
Lcd_RS_high;
Lcd_WR_high;
Lcd_CS_low;
//GPIO_Write(GPIOE, 0xffff);
//GPIOE->CRH = 0x44444444;
//GPIOE->CRL = 0x44444444;
//设为浮空输入模式
GPIOE->CRH = (GPIOE->CRH & 0x00000000) | 0x44444444;
GPIOE->CRL = (GPIOE->CRL & 0x00000000) | 0x44444444;
Lcd_rd_low;
//i=GPIO_ReadOutputData(GPIOE);
i = GPIOE->IDR;
//GPIOE->CRH = 0x33333333;
//GPIOE->CRL = 0x33333333;
//通用推挽输出模式
GPIOE->CRH = (GPIOE->CRH & 0x00000000) | 0x33333333;
GPIOE->CRL = (GPIOE->CRL & 0x00000000) | 0x33333333;		
Lcd_rd_high;
Lcd_CS_high;
return i;

}
//=================================
/**************************************************************************************
* 名    称: void write_com(u16 address,u16 num)
* 功    能: 数据所要发送的地址
* 参    数: 
* 返 回 值: 
*
**************************************************************************************/ 
static void write_com(u16 address,u16 num)
{
    send_command(address);//所要显示的位置的命令是x还是y
    send_data(num);       //所要显示的地址
}
/**************************************************************************************
* 名    称: 
* 功    能:
* 参    数:
* 返 回 值:
*
* 修改历史:
*   版本    日期     作者     
*   ----------------------------------------------------
*   1.0   2008.8.13  孙逸洁       www.http://shop35330111.taobao.com
**************************************************************************************/
static void LCD_SetArea( uint16 x0, uint16 y0, uint16 x1, uint16 y1 ) 
{ /*
    write_com(0x52,x0);
    write_com(0x53,x1);
    write_com(0x50,y0);
    write_com(0x51,y1);
   */
	write_com(0x50,x0);
    write_com(0x51,x1);
    write_com(0x52,y0);
    write_com(0x53,y1);

}
/**************************************************************************************
* 名    称: LCM_DispIni()
* 功    能: LCM显示初始化
* 参    数: 
* 返 回 值: 无
*
* 修改历史:
*   版本    日期     作者     
*   ----------------------------------------------------
*   1.0   2009.2.9  孙逸洁       www.http://shop35330111.taobao.com
**************************************************************************************/ 
void ssd1289_LCM_DispIni(void)
{	
  	u16 i;
	Lcd_Light_ON;
	Clr_Rst;
	Delay_nms(1);
	Set_Rst;
	Delay_nms(1);
	Clr_Cs;
    Clr_nRd;
    Set_nRd;

    LCD_WR_REG(0x0000,0x0001);      //打开晶振
    LCD_WR_REG(0x0003,0xA8A4);       //0xA8A4
    LCD_WR_REG(0x000C,0x0000);       
    LCD_WR_REG(0x000D,0x080C);       
    LCD_WR_REG(0x000E,0x2B00);       
    LCD_WR_REG(0x001E,0x00B0);       
    LCD_WR_REG(0x0001,0x6B3F);       //驱动输出控制320*240  0x6B3F
    LCD_WR_REG(0x0002,0x0600);    
    LCD_WR_REG(0x0010,0x0000);  
  
    LCD_WR_REG(0x0011,0x6068);            //0x4030           //定义数据格式  16位色 
    //LCD_WR_REG(0x0011,0x6048|(1<<4));            //0x4030  (1<<5)|         //定义数据格式  16位色
 
    LCD_WR_REG(0x0005,0x0000);    
    LCD_WR_REG(0x0006,0x0000);    
    LCD_WR_REG(0x0016,0xEF1C);    
    LCD_WR_REG(0x0017,0x0003);    
    LCD_WR_REG(0x0007,0x0233);            //0x0233       
    LCD_WR_REG(0x000B,0x0000);    
    LCD_WR_REG(0x000F,0x0000);            //扫描开始地址
    LCD_WR_REG(0x0041,0x0000);    
    LCD_WR_REG(0x0042,0x0000);    
    LCD_WR_REG(0x0048,0x0000);    
    LCD_WR_REG(0x0049,0x013F);    
    LCD_WR_REG(0x004A,0x0000);    
    LCD_WR_REG(0x004B,0x0000);    
    LCD_WR_REG(0x0044,0xEF00);    
    LCD_WR_REG(0x0045,0x0000);    
    LCD_WR_REG(0x0046,0x013F);    
    LCD_WR_REG(0x0030,0x0707);    
    LCD_WR_REG(0x0031,0x0204);    
    LCD_WR_REG(0x0032,0x0204);    
    LCD_WR_REG(0x0033,0x0502);    
    LCD_WR_REG(0x0034,0x0507);    
    LCD_WR_REG(0x0035,0x0204);    
    LCD_WR_REG(0x0036,0x0204);    
    LCD_WR_REG(0x0037,0x0502);    
    LCD_WR_REG(0x003A,0x0302);    
    LCD_WR_REG(0x003B,0x0302);    
    LCD_WR_REG(0x0023,0x0000);    
    LCD_WR_REG(0x0024,0x0000);    
    LCD_WR_REG(0x0025,0x8000);    
    LCD_WR_REG(0x004f,0);        //行首址0
    LCD_WR_REG(0x004e,0);        //列首址0

}
/**************************************************************************************
* 名    称: GUI_FillSCR()
* 功    能:全屏填充。直接使用数据填充显示缓冲区
* 参    数:dat		填充的数据
* 返 回 值:
*
* 修改历史:
*   版本    日期     作者     
*   ----------------------------------------------------
*   1.0   2008.8.13  孙逸洁       www.http://shop35330111.taobao.com
**************************************************************************************/

void  ssd1289_GUI_FillSCR(uint16 dat)
{  
    uint16 i,j;
    LCD_SetArea(0,0,GUI_LCM_XMAX-1,GUI_LCM_YMAX-1); 
    send_command(0x22);
    for(j=0;j<GUI_LCM_XMAX;j++)
        for(i=0;i<GUI_LCM_YMAX;i++)
            send_data(dat);
}
/*
void  GUI_Fill(uint16 x0,uint16 y0 ,uint16 x1,uint16 y1 ,uint16 clor)
{  
    uint16 i,j;
    LCD_SetArea(x0,y0,x1-1,y1-1); 
    send_command(0x22);
    for(j=x0;j<x1;j++)
        for(i=y0;i<y1;i++)
            send_data(clor);
}
*/
/**************************************************************************************
* 名    称: Set_ramaddr()
* 功    能:设置显示ram地址
* 参    数:
* 返 回 值:
*
* 修改历史:
*   版本    日期     作者     
*   ----------------------------------------------------
*   1.0   2008.8.13  孙逸洁       www.http://shop35330111.taobao.com
**************************************************************************************/
void ssd1289_Set_ramaddr(uint16 x,uint16 y)
{  
    write_com(0x004f,x);        //行首址
	write_com(0x004e,y);        //列首址
}
/****************************************************************************
* 名    称：uint16 BGR_RGB(uint16 c)
* 功    能：RRRRRGGGGGGBBBBB 改为 BBBBBGGGGGGRRRRR 格式
* 入口参数：c      BRG 颜色值
* 出口参数：RGB 颜色值
* 说    明：内部函数调用
* 调用方法：
****************************************************************************/
static uint16 BGR_RGB(uint16 c)
{
  uint16  r, g, b;

  b = (c>>0)  & 0x1f;
  g = (c>>5)  & 0x3f;
  r = (c>>11) & 0x1f;
  
  return( (b<<11) + (g<<5) + (r<<0) );
}
/****************************************************************************
* 名    称：uint16 GetID()
* 功    能：获取ID
* 入口参数：
* 出口参数：当前ID
* 说    明：
* 调用方法：i=GetID();
****************************************************************************/
static uint16 GetID(void)
{
    send_command(0x00);
    return rece_data();
}
/**************************************************************************************
* 名    称:GUI_Initialize()
* 功    能:初始化GUI，包括初始化显示缓冲区，初始化LCM并清屏。
* 参    数:
* 返 回 值:
*
* 修改历史:
*   版本    日期     作者     
*   ----------------------------------------------------
*   1.0   2008.8.13  孙逸洁       www.http://shop35330111.taobao.com
**************************************************************************************/

void  ssd1289_GUI_Initialize(void)
{  					// 初始化LCM模块工作模式，纯图形模式
	ssd1289_LCM_DispIni();	
//	send_command(0xAD); /* Set DC-DC */
//	send_command(0x8B); /* 8B=ON, 8A=Off */
//	send_command(0xaf);
//    GUI_FillSCR(0x00);				// 初始化缓冲区为0x00，并输出屏幕(清屏)
}


static uint16  DEC_HEX_TAB[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
/**************************************************************************************
* 名    称: GUI_Point()
* 功    能:在指定位置上画点。
* 参    数:x		指定点所在列的位置
*          y		指定点所在行的位置
*          color	显示颜色(对于黑白色LCM，为0时灭，为1时显示)
* 返 回 值:返回值为1时表示操作成功，为0时表示操作失败。
*
* 修改历史:
*   版本    日期     作者     
*   ----------------------------------------------------
*   1.0   2008.8.13  孙逸洁       www.http://shop35330111.taobao.com


**************************************************************************************/
uint8  ssd1289_GUI_Point(uint16 x, uint16 y, TCOLOR color)
{
   // 参数过滤 
   if(x>=GUI_LCM_XMAX) return(0);
   if(y>=GUI_LCM_YMAX) return(0);
   
    ssd1289_Set_ramaddr(x,y);        //
    send_command(0x22);
    send_data(color);
   return(1);
}

/**************************************************************************************
* 名    称: GetPoint(uint16 x,uint16 y)
* 功    能:获取指定座标的颜色值
* 参    数:x      行座标
*          y      列座标
* 返 回 值:当前座标颜色值
*
* 修改历史:
*   版本    日期     作者     
*   ----------------------------------------------------
*   1.0   2008.8.13  孙逸洁       www.http://shop35330111.taobao.com
**************************************************************************************/

uint16 ssd1289_GetPoint(uint16 x,uint16 y)
{
  	ssd1289_Set_ramaddr(x,y);
	send_command(0x22);
    rece_data();
	//return BGR_RGB(rece_data());
	return	rece_data();
}
/**************************************************************************************
* 名    称:GUI_ReadPoint()
* 功    能:读取指定点的颜色?
* 参    数: x		指定点所在列的位置
*           y		指定点所在行的位置
*           ret     保存颜色值的指针
* 返 回 值:返回0表示指定地址超出缓冲区范围
*
* 修改历史:
*   版本    日期     作者     
*   ----------------------------------------------------
*   1.0   2008.8.13  孙逸洁       www.http://shop35330111.taobao.com


**************************************************************************************/
uint8 ssd1289_GUI_ReadPoint(uint16 x, uint16 y, TCOLOR *ret)
{  

   // 参数过滤
   if(x>=GUI_LCM_XMAX) return(0);
   if(y>=GUI_LCM_YMAX) return(0);
  
   *ret = ssd1289_GetPoint(x,y);
  
   return(1);
}
/**************************************************************************************
* 名    称: GUI_HLine()
* 功    能:画水平线。
* 参    数: x0		水平线起点所在列的位置
*           y0		水平线起点所在行的位置
*           x1      水平线终点所在列的位置
*           color	显示颜色
* 返 回 值:
*
* 修改历史:
*   版本    日期     作者     
*   ----------------------------------------------------
*   1.0   2008.8.13  孙逸洁       www.http://shop35330111.taobao.com
**************************************************************************************/

void  ssd1289_GUI_HLine(uint16 x0, uint16 y0, uint16 x1, TCOLOR color) 
{  uint16  i;

  if(x0>x1) 						// 对x0、x1大小进行排列，以便画图
   {  i = x1;
      x1 = x0;
      x0 = i;
   }
 
/*	for(i=0;i<x1-x0+1;i++) 
		GUI_Point(x0+i,y0,color);   


	LCD_SetArea(x0,x1,y0,y0);
	send_command(0x22); 
	for(i=0;i<x1-x0+1;i++) 
		send_data(color);		  
									   */  
	ssd1289_GUI_Point(x0,y0,color); 
	for(i=0;i<x1-x0;i++)
    	send_data(color);	
 
}
/**************************************************************************************
* 名    称:GUI_RLine()
* 功    能:画竖直线 根据硬件特点，实现加速。
* 参    数:x0		垂直线起点所在列的位置
*           y0		垂直线起点所在行的位置
*           y1      垂直线终点所在行的位置
*           color	显示颜色
* 返 回 值:
*
* 修改历史:
*   版本    日期     作者     
*   ----------------------------------------------------
*   1.0   2008.8.13  孙逸洁       www.http://shop35330111.taobao.com
**************************************************************************************/

void  ssd1289_GUI_RLine(uint16 x0, uint16 y0, uint16 y1, TCOLOR color) 
{  uint16  i;
 
   if(y0>y1) 		// 对y0、y1大小进行排列，以便画图
   {  i = y1;
      y1 = y0;
      y0 = i;
   }
  	for(i=0;i<y1-y0+1;i++) 
		ssd1289_GUI_Point(x0,y0+i,color); 
/* 	LCD_SetArea(x0,x0,y0,y1);
	send_command(0x22); 
	for(i=0;i<y1-y0+1;i++) 
		send_data(color);		*/

}	 	 


void SSD1289_picture_start(void)
{
    ssd1289_Set_ramaddr(0,0);
    ssd1289_Set_ramaddr(0,0);
	LCD_WR_REG(0x0050,0x00);//水平 GRAM起始位置
	LCD_WR_REG(0x0051,319);//水平GRAM终止位置
	LCD_WR_REG(0x0052,0x00);//垂直GRAM起始位置
	LCD_WR_REG(0x0053,239);//垂直GRAM终止位置    	
	send_command(0x22);
    Clr_Cs;
}

//====================================================================================

#include "stm32f10x.h"
#include "ili9325.h"


void DataToWrite(u16 data) 
{
	GPIOB->ODR=((GPIOB->ODR&0x00ff)|(data&0xff00));	
	Clr_nWr;
	Set_nWr;
	GPIOB->ODR=((GPIOB->ODR&0x00ff)|(data<<8));
}

/*
 * 函数名：LCD_GPIO_Config
 * 描述  ：根据FSMC配置LCD的I/O
 * 输入  ：无
 * 输出  ：无
 * 调用  ：内部调用        
 */
static void LCD_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    /* Enable the FSMC Clock */
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);
    
    /* config lcd gpio clock base on FSMC */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE , ENABLE);
    
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    
    /* config tft back_light gpio base on the PT4101 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;		
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    
    /* config tft BL gpio */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 ; 	 
    GPIO_Init(GPIOA, &GPIO_InitStructure);  		   
    
    /* config tft data lines base on FSMC
	 * data lines,FSMC-D0~D15: PD 14 15 0 1,PE 7 8 9 10 11 12 13 14 15,PD 8 9 10
	 */	
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_8 | GPIO_Pin_9 | 
                                  GPIO_Pin_10 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | 
                                  GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | 
                                  GPIO_Pin_15;
    GPIO_Init(GPIOE, &GPIO_InitStructure); 
    
    /* config tft control lines base on FSMC
	 * PD4-FSMC_NOE  :LCD-RD
   * PD5-FSMC_NWE  :LCD-WR
	 * PD7-FSMC_NE1  :LCD-CS
   * PD11-FSMC_A16 :LCD-DC
	 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; 
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5; 
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; 
    GPIO_Init(GPIOD, &GPIO_InitStructure);  
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 ; 
    GPIO_Init(GPIOD, &GPIO_InitStructure);  
    
    /* tft control gpio init */	 
    GPIO_SetBits(GPIOD, GPIO_Pin_13);		 // RST				
    GPIO_SetBits(GPIOD, GPIO_Pin_4);		 // RD = 1  
    GPIO_SetBits(GPIOD, GPIO_Pin_5);		 // WR = 1 
		GPIO_SetBits(GPIOD, GPIO_Pin_11);		 // RS
    GPIO_SetBits(GPIOD, GPIO_Pin_7);		 //	CS = 1

		GPIO_SetBits(GPIOA, GPIO_Pin_1);	 	 //	BL = 1 
		
		
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
		
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;	//按键 OK
    GPIO_Init(GPIOA, &GPIO_InitStructure);
																// right          up           left        down
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_1 | GPIO_Pin_5 | GPIO_Pin_6;		
    GPIO_Init(GPIOE, &GPIO_InitStructure);

}

/*
 * 函数名：LCD_FSMC_Config
 * 描述  ：LCD  FSMC 模式配置
 * 输入  ：无
 * 输出  ：无
 * 调用  ：内部调用        
 */

static void LCD_FSMC_Config(void)
{
    FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
    FSMC_NORSRAMTimingInitTypeDef  p; 
    
    
    p.FSMC_AddressSetupTime = 0x02;	 //地址建立时间
    p.FSMC_AddressHoldTime = 0x00;	 //地址保持时间
    p.FSMC_DataSetupTime = 0x05;		 //数据建立时间
    p.FSMC_BusTurnAroundDuration = 0x00;
    p.FSMC_CLKDivision = 0x00;
    p.FSMC_DataLatency = 0x00;

    p.FSMC_AccessMode = FSMC_AccessMode_B;	 // 一般使用模式B来控制LCD
    
    FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1;
    FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
    FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_NOR;
    FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
    FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
    FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
    FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
    FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
    FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
    FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
    FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = &p;
    FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = &p; 
    
    FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure); 
    
    /* Enable FSMC Bank1_SRAM Bank */
    FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);  
}

volatile void LCD_delay(char j)
{
volatile u16 i;	
	while(j--)
for(i=7200;i>0;i--);
}
static void LCD_Rst(void)
{			
    GPIO_ResetBits(GPIOD, GPIO_Pin_13);
    LCD_delay(10);					   
    GPIO_SetBits(GPIOD, GPIO_Pin_13 );		 	 
    LCD_delay(10);	
}
 void WriteComm(u16 CMD)
{			
	*(__IO u16 *) (Bank1_LCD_C) = CMD;
}
 void WriteData(u16 tem_data)
{			
	*(__IO u16 *) (Bank1_LCD_D) = tem_data;
}


/**********************************************
Lcd初始化函数
***********************************************/
void Lcd_Initialize(void)
{	
LCD_GPIO_Config();
LCD_FSMC_Config();
LCD_delay(20);
LCD_Rst();
	
		
//S6D05A1初始化
	
WriteComm(0xF0);
WriteData(0x5A);
WriteData(0x5A);

WriteComm(0xF1);
WriteData(0x5A);
WriteData(0x5A);



WriteComm(0xF2);
WriteData(0x3B);
WriteData(0x33);
WriteData(0x03);
WriteData(0x0C);
WriteData(0x08);
WriteData(0x08);
WriteData(0x08);
WriteData(0x00);
WriteData(0x08);
WriteData(0x08);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);
WriteData(0x33);
WriteData(0x0C);
WriteData(0x08);
WriteData(0x0C);
WriteData(0x08);

//WriteComm(0xF3);
//WriteData(0x00);
//WriteData(0x00);
//WriteData(0x00);
//WriteData(0x00);

WriteComm(0xF4);
WriteData(0x07);

WriteData(0x00);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);

WriteData(0x04);
WriteData(0x70);
WriteData(0x03);
WriteData(0x04);
WriteData(0x70);
WriteData(0x03);


WriteComm(0xF5);
WriteData(0x00);
WriteData(0x46);//Set VCOMH
WriteData(0x70);//Set VCOM Amplitude
WriteData(0x00);
WriteData(0x00);
WriteData(0x02);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);
WriteData(0x46);
WriteData(0x70);


WriteComm(0xF6);
WriteData(0x03);
WriteData(0x00);
WriteData(0x08);
WriteData(0x03);
WriteData(0x03);
WriteData(0x00);
WriteData(0x03);
WriteData(0x00);

WriteComm(0xF7);
WriteData(0x48);
WriteData(0x80);//RGB_MCU(DM)
WriteData(0x10);
WriteData(0x02);
WriteData(0x00);
//////////////////////////////////////////////////////////////
WriteComm(0xF8);
WriteData(0x11);
WriteData(0x00);

WriteComm(0xF9); //Gamma Selection
WriteData(0x14);

WriteComm(0xFA); //Positive Gamma Control
WriteData(0x33);
WriteData(0x07);
WriteData(0x04);
WriteData(0x1A);
WriteData(0x18);
WriteData(0x1C);
WriteData(0x24);
WriteData(0x1D);
WriteData(0x26);
WriteData(0x28);
WriteData(0x2F);
WriteData(0x2E);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);

WriteComm(0xFB); //Positive Gamma Control
WriteData(0x33);
WriteData(0x03);
WriteData(0x00);
WriteData(0x2E);
WriteData(0x2F);
WriteData(0x28);
WriteData(0x26);
WriteData(0x1D);
WriteData(0x24);
WriteData(0x1C);
WriteData(0x18);
WriteData(0x1A);
WriteData(0x04);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);

WriteComm(0xF9); //Gamma Selection
WriteData(0x12);

WriteComm(0xFA); //Positive Gamma Control
WriteData(0x36);
WriteData(0x07);
WriteData(0x04);
WriteData(0x1C);
WriteData(0x1C);
WriteData(0x23);
WriteData(0x28);
WriteData(0x1C);
WriteData(0x25);
WriteData(0x26);
WriteData(0x2E);
WriteData(0x2B);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);

WriteComm(0xFB); //Positive Gamma Control
WriteData(0x33);
WriteData(0x06);
WriteData(0x00);
WriteData(0x2B);
WriteData(0x2E);
WriteData(0x26);
WriteData(0x25);
WriteData(0x1C);
WriteData(0x28);
WriteData(0x23);
WriteData(0x1C);
WriteData(0x1C);
WriteData(0x04);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);

WriteComm(0xF9); //Gamma Selection
WriteData(0x11);

WriteComm(0xFA); //Positive Gamma Control
WriteData(0x33);
WriteData(0x07);
WriteData(0x04);
WriteData(0x30);
WriteData(0x32);
WriteData(0x34);
WriteData(0x35);
WriteData(0x11);
WriteData(0x1D);
WriteData(0x20);
WriteData(0x28);
WriteData(0x20);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);

WriteComm(0xFB); //Positive Gamma Control
WriteData(0x33);
WriteData(0x03);
WriteData(0x00);
WriteData(0x20);
WriteData(0x28);
WriteData(0x20);
WriteData(0x1D);
WriteData(0x11);
WriteData(0x35);
WriteData(0x34);
WriteData(0x32);
WriteData(0x30);
WriteData(0x04);
WriteData(0x00);
WriteData(0x00);
WriteData(0x00);

WriteComm(0x44);
WriteData(0x00);
WriteData(0x01);

WriteComm(0x2A);
WriteData(0x00);
WriteData(0x00);
WriteData(0x01);
WriteData(0x3F);

WriteComm(0x2B);
WriteData(0x00);
WriteData(0x00);
WriteData(0x01);
WriteData(0xDF);


WriteComm(0x36);//Memory Data Access Control
WriteData(0x00);

WriteComm(0x3A);//SET 65K Color
WriteData(0x55);

WriteComm(0x11); 
LCD_delay(120);

WriteComm(0x29);//Display on
WriteComm(0x2C);//Write GRAM

LCD_delay(10);
		WriteComm(0x36); //Set_address_mode
 	WriteData(0x60); //横屏，从左下角开始，从左到右，从下到上
	Lcd_Light_ON;
	
// 		Lcd_ColorBox(0,0,320,480,Yellow);Delay(5000000);
// 		Lcd_ColorBox(0,0,320,480,Blue);Delay(5000000);
// 		Lcd_ColorBox(0,0,320,480,Red);Delay(5000000);
// 		Lcd_ColorBox(0,0,320,480,Green);Delay(5000000);
// 		Lcd_ColorBox(0,0,320,480,Magenta);Delay(5000000);
// 		Lcd_ColorBox(0,0,320,480,Cyan);Delay(5000000);
// 		Lcd_ColorBox(0,0,320,480,White);Delay(5000000);

}
/******************************************
函数名：Lcd写命令函数
功能：向Lcd指定位置写入应有命令或数据
入口参数：Index 要寻址的寄存器地址
          ConfigTemp 写入的数据或命令值
******************************************/
void LCD_WR_REG(u16 Index,u16 CongfigTemp)
{
	*(__IO u16 *) (Bank1_LCD_C) = Index;	
	*(__IO u16 *) (Bank1_LCD_D) = CongfigTemp;
}
/************************************************
函数名：Lcd写开始函数
功能：控制Lcd控制引脚 执行写操作
************************************************/
void Lcd_WR_Start(void)
{
*(__IO u16 *) (Bank1_LCD_C) = 0x2C;
}
void BlockWrite(unsigned int Xstart,unsigned int Xend,unsigned int Ystart,unsigned int Yend) 
{
	//HX8352-C

	WriteComm(0x2a);   
	WriteData(Xstart>>8);
	WriteData(Xstart&0xff);
	WriteData(Xend>>8);
	WriteData(Xend&0xff);

	WriteComm(0x2b);   
	WriteData(Ystart>>8);
	WriteData(Ystart&0xff);
	WriteData(Yend>>8);
	WriteData(Yend&0xff);
	
	WriteComm(0x2c);
}
u16 GetPoint(u16 x,u16 y)
{
volatile u16 a;
	
	WriteComm(0x2a);   
	WriteData(x>>8);
	WriteData(x&0xff);

	WriteComm(0x2b);   
	WriteData(y>>8);
	WriteData(y&0xff);
	a=0;a=0;a=0;a=0;a=0;
	WriteComm(0x2E);
	a=0;a=0;a=0;a=0;a=0;a=0;
	a = *(__IO u16 *) (Bank1_LCD_D);
	a=0;a=0;a=0;a=0;a=0;
	a = *(__IO u16 *) (Bank1_LCD_D);
	return a;
// 	 return (a&0xf800)|((a&0x03f0)<<1)|((a&0x3)<<3)|(b>>13);  
}
/**********************************************
函数名：Lcd块选函数
功能：选定Lcd上指定的矩形区域

注意：xStart和 yStart随着屏幕的旋转而改变，位置是矩形框的四个角

入口参数：xStart x方向的起始点
          ySrart y方向的终止点
          xLong 要选定矩形的x方向长度
          yLong  要选定矩形的y方向长度
返回值：无
***********************************************/
void Lcd_ColorBox(u16 xStart,u16 yStart,u16 xLong,u16 yLong,u16 Color)
{
	u32 temp;

	BlockWrite(xStart,xStart+xLong-1,yStart,yStart+yLong-1);
	for (temp=0; temp<xLong*yLong; temp++)
	{
		*(__IO u16 *) (Bank1_LCD_D) = Color;
	}
}




/************************************************
函数名：Lcd写开始函数
功能：控制Lcd控制引脚 执行写操作
入口参数：无
返回值：无
************************************************/
void Lcd_CMD_WR_Start(void)
{
	Clr_Cs;
	Clr_Rs;
	DataToWrite(0x0000);
	Clr_nWr;
	Set_nWr;
	Set_Rs;
}



/**********************************************
函数名：Lcd全屏擦除函数
功能：将Lcd整屏擦为指定颜色
入口参数：color 指定Lcd全屏颜色 RGB(5-6-5)
返回值：无
***********************************************/
void Lcd_Clear(u16 Color)
{
	u32 temp;
	
	Lcd_Start();
	if((Color>>8)==(Color&0x00ff))
	{
		DataToWrite(Color);
		for (temp = 0; temp < 76800*2-1; temp++)
		{
			Clr_nWr;
			Set_nWr;
		}
	}	
	else
	{
		for (temp = 0; temp < 76800; temp++)
		{
			DataToWrite(Color);
			Clr_nWr;
			Set_nWr;
		}
	}

}
/*************************************************
函数名：Lcd光标起点定位函数
功能：指定320240液晶上的一点作为写数据的起始点
入口参数：x 坐标 0~239
          y 坐标 0~319
返回值：无
*************************************************/
void Lcd_SetCursor(u16 x,u16 y)
{ 
	//坐标调转
	LCD_WR_REG(0x20,y);//水平坐标
	LCD_WR_REG(0x21,x);//垂直坐标  
}
/**********************************************
函数名：Lcd块选函数
功能：选定Lcd上指定的矩形区域

注意：xStart和 yStart随着屏幕的旋转而改变，位置是矩形框的四个角

入口参数：xStart x方向的起始点
          ySrart y方向的终止点
          xLong 要选定矩形的x方向长度
          yLong  要选定矩形的y方向长度
返回值：无
***********************************************/


void Lcd_SetBox(u16 xStart,u16 yStart,u16 xLong,u16 yLong,u16 x_offset,u16 y_offset)
{
	Lcd_SetCursor(xStart+x_offset,yStart+y_offset);
	LCD_WR_REG(0x0050,yStart+y_offset);//水平GRAM起始位置
	LCD_WR_REG(0x0051,yStart+yLong-1+y_offset);//水平GRAM终止位置 

    //x,y坐标对调 
	LCD_WR_REG(0x0052,xStart+x_offset);//垂直 GRAM起始位置
	LCD_WR_REG(0x0053,xStart+xLong-1+x_offset);//垂直GRAM终止位置

	
}

void Lcd_ClearCharBox(u16 x,u16 y,u16 Color)
{
	u32 temp;
  
	Lcd_SetBox(x*8,y*16,8,16,0,0); 
	Lcd_WR_Start();
	Set_Rs;
  
	for (temp=0; temp < 128; temp++)
	{
		DataToWrite(Color); 
		Clr_nWr;
		Set_nWr;
	}
}

////////////////////////////////////////////////////////////////////////////////
void DrawPixel(u16 x, u16 y, int Color)
{
	BlockWrite(x,x,y,y);
	*(__IO u16 *) (Bank1_LCD_D) = Color;							  
}
/******************************************
函数名：Lcd图像填充100*100
功能：向Lcd指定位置填充图像
入口参数：Index 要寻址的寄存器地址
          ConfigTemp 写入的数据或命令值
******************************************/
void LCD_Fill_Pic(u16 x, u16 y,u16 pic_H, u16 pic_V, const unsigned char* pic)
{
  unsigned long i;
	unsigned int j;

	WriteComm(0x36); //Set_address_mode
	WriteData(0x00); //横屏，从左下角开始，从左到右，从下到上
	BlockWrite(x,x+pic_H-1,y,y+pic_V-1);
	for (i = 0; i < pic_H*pic_V*2; i+=2)
	{
		j=pic[i];
		j=j<<8;
		j=j+pic[i+1];
		*(__IO u16 *) (Bank1_LCD_D) = j;
	}
	WriteComm(0x36); //Set_address_mode
	WriteData(0x60);
}
//开始全屏写,设置地址
void Lcd_Start(void)
{  
	Lcd_SetCursor(0,239);     
	LCD_WR_REG(0x0050,0x00);//垂直 GRAM起始位置
	LCD_WR_REG(0x0051,239);//垂直GRAM终止位置
	LCD_WR_REG(0x0052,0x00);//水平GRAM起始位置
	LCD_WR_REG(0x0053,319);//水平GRAM终止位置   
	Lcd_WR_Start();
}


/****************************************************************************
* 名    称：void Put32_32HZ(u16 x,u16 y,const unsigned char *c,u16 charColor,u16 bkColor,u8 flag)
* 功    能：在指定座标显示一个点阵的汉字
* 入口参数：x          行座标
*           y          列座标
*           charColor  字符的颜色
*           bkColor    字符背景颜色
* 出口参数：无
* 说    明：显示范围限定为可显示的ascii码
* 调用方法：ssd1289_PutChar(10,10,'a',0x0000,0xffff, 1);
****************************************************************************/
// void Put32_32HZ(u16 x,u16 y,const unsigned char *c,u16 charColor,u16 bkColor,u8 flag)
// {
//   u8 i,j,k; 
//   u8 tmp_char=0;

//   Lcd_SetBox(x,y,32,32,0,0);
//   Lcd_WR_Start();
//   Set_Rs;

//   for (i=31;i>=0;i--)//32行
//   {
//     for (j=3;j>=0;j--)//每行4字节
//     {
//       tmp_char=c[4*i+j];
//       for (k=0;k<8;k++)//每字节8位
//       {
//         if (((tmp_char << k) & 0x80) == 0x80)
//         {
// 		  DataToWrite(charColor);
// 		  Clr_nWr;
// 	  	  Set_nWr;
//         }
//         else
//         {
// 		   if(flag){
// 			 DataToWrite(bkColor);
// 		     Clr_nWr;
// 	  	     Set_nWr;
// 		   }
//         }
//       }
//     }
//   }

//   Set_Cs;

// }

/****************************************************************************
* 名    称：void Put16_16HZ(u16 x,u16 y,const unsigned char *c,u16 charColor,u16 bkColor,u8 flag)
* 功    能：在指定座标显示一个点阵的汉字
* 入口参数：x          行座标
*           y          列座标
*           charColor  字符的颜色
*           bkColor    字符背景颜色
* 出口参数：无
* 说    明：显示范围限定为可显示的ascii码
* 调用方法：ssd1289_PutChar(10,10,'a',0x0000,0xffff, 1);
****************************************************************************/
void Put16_16HZ(u16 x,u16 y,const unsigned char *c,u16 charColor,u16 bkColor,u8 flag)
{
  char i,j,k;
  
  u8 tmp_char=0;

  Lcd_SetBox(x,y,16,16,0,0);
  Lcd_SetCursor(x,y+15);
  Lcd_WR_Start();
  Set_Rs;

  for (i=0;i<16;i++)//16行
  {
    for (j=0;j<2;j++)//每行2字节
    {
      tmp_char=c[2*(15-i)+j];
      for (k=0;k<8;k++)//每字节8位
      {
        if (((tmp_char << k) & 0x80) == 0x80)
        {
		  DataToWrite(charColor);
		  Clr_nWr;
		  Set_nWr;
        }
        else
        {
			 DataToWrite(bkColor);
		     Clr_nWr;
		     Set_nWr;
        }
      }
    }
  }
  Set_Cs;

}


void Put8_16Char(u16 x,u16 y,const unsigned char *ascii_8x16,u8 ch,u16 charColor,u16 bkColor,u8 flag)
{
  char i=0,j=0;
  u8 tmp_char=0;

  Lcd_SetBox(x,y,8,16,0,0);
  Lcd_SetCursor(x,y+15);
  Lcd_WR_Start();
  Set_Rs;

  for (i=0;i<16;i++)
  {
    tmp_char=ascii_8x16[((ch-0x20)*16)+(15-i)];
    for (j=0;j<8;j++)
    {
        if(((tmp_char<<j) & 0x80) == 0x80)
        {
		  DataToWrite(charColor);
		  Clr_nWr;
		  Set_nWr;
        }
        else
        {
		   	 DataToWrite(bkColor);  //0x7BEF
		     Clr_nWr;
		     Set_nWr;
        }
    }
  }
  Set_Cs;
}



void Put16x32Num(u16 x,u16 y,const unsigned char *num_16x32,u8 ch,u16 charColor,u16 bkColor,u8 flag)
{
  char i=0,j=0,k=0;
  u8 tmp_char=0;

  Lcd_SetBox(x,y,16,32,0,0);
  Lcd_SetCursor(x,y+31);
  Lcd_WR_Start();
  for (i=0;i<32;i++)
  {
    for (k=0;k<2;k++)
	{
      tmp_char=num_16x32[ch*32*2+(31-i)*2+k];
      for (j=0;j<8;j++)
      {
        if(((tmp_char<<j) & 0x80) == 0x80)
        {
		  DataToWrite(charColor);
		  Clr_nWr;
		  Set_nWr;
        }
        else
        {
		   	 DataToWrite(bkColor);  //0x7BEF
		     Clr_nWr;
		     Set_nWr;

        }
      }
	}
  }
}

void LCD_Scan_Set(char i)
{
	
  if(i==0)	{LCD_WR_REG(0x0003,0x1038);Lcd_SetCursor(0,239);}//
	if(i==1)	{LCD_WR_REG(0x0003,0x1028);Lcd_SetCursor(0,239);}//
  if(i==2)	{LCD_WR_REG(0x0003,0x1008);Lcd_SetCursor(319,0);}//
	if(i==3)	{LCD_WR_REG(0x0001,0x0100);return;}//
	LCD_WR_REG(0x0050,0x00);//垂直GRAM起始位置
	LCD_WR_REG(0x0051,239);//垂直GRAM终止位置
	LCD_WR_REG(0x0052,0x00);//水平GRAM起始位置
	LCD_WR_REG(0x0053,319);//水平GRAM终止位置   
	Lcd_WR_Start();
}
/*---------------------------------------------------------------------------
功能：	竖直滚屏
入口参数：line_num  滚动行数
---------------------------------------------------------------------------*/
void lcd_scrol_screen(unsigned int line_num)
{
	 LCD_WR_REG(0x006a, line_num);// set scrolling line	
	 LCD_WR_REG(0x0061, 0x0003);//enable scrol

//	 LCD_WR_REG(0x006a, line_num);// set scrolling line	
//	 LCD_WR_REG(0x0061, 0x0001);////disable scrol
}

/*---------------------------------------------------------------------------
功能：	禁止竖直滚屏
---------------------------------------------------------------------------*/
void lcd_scrol_disable(void)
{
	 LCD_WR_REG(0x006a, 0x0000);// set scrolling line	
	 LCD_WR_REG(0x0061, 0x0001);//disable scrol
}

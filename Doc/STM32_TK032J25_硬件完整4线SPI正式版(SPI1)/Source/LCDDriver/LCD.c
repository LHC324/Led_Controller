/******************************************************************************

*重要说明！
在.h文件中，#define Immediately时是立即显示当前画面
而如果#define Delay，则只有在执行了LCD_WR_REG(0x0007,0x0173);
之后才会显示，执行一次LCD_WR_REG(0x0007,0x0173)后，所有写入数
据都立即显示。
#define Delay一般用在开机画面的显示，防止显示出全屏图像的刷新过程
******************************************************************************/
#include "stm32f10x.h"
#include "LCD.h"
#include "ff.h"	
#include <stdio.h>
#include "FONT.h"
#include "GB1616.h"	//16*16汉字字模
#include "sheep.h"
#include "spi.h"
/*
 * 函数名：LCD_GPIO_Config
 * 描述  ：根据FSMC配置LCD的I/O
 * 输入  ：无
 * 输出  ：无
 * 调用  ：内部调用        
 */
 void LCD_GPIO_Config(void)
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
    
    /* config tft rst gpio */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_13 ; 	 
    GPIO_Init(GPIOC, &GPIO_InitStructure);  		   
    
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
    GPIO_SetBits(GPIOD, GPIO_Pin_13);		 // RST = 1 	
    GPIO_SetBits(GPIOC, GPIO_Pin_5);	 	 //	LIGHT
    GPIO_SetBits(GPIOD, GPIO_Pin_4);		 // RD = 1  
    GPIO_SetBits(GPIOD, GPIO_Pin_5);		 // WR = 1 
    GPIO_SetBits(GPIOD, GPIO_Pin_7);		 //	CS = 1 
		
																	//   BL      　　RS      CS
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOA, GPIO_Pin_4);

	GPIO_SetBits(GPIOC, GPIO_Pin_13);	 	 //	CS2
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7 | GPIO_Pin_5|GPIO_Pin_11;	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOD, GPIO_Pin_7);
}

volatile static void Delay(__IO u32 nCount)
{	
	volatile int i;
	for(i=0;i<720;i++)
    for(; nCount != 0; nCount--);
}  
  
 void WriteComm(u16 CMD)
{			
	LCD_RS(0);
	SPI_I2S_SendData(SPI1, CMD);
}
  WriteData(u16 tem_data)
{			
	LCD_RS(1);
	SPI_I2S_SendData(SPI1, tem_data);
}

/**********************************************
Lcd初始化函数
Initial condition  (DB0-15,RS,CSB,WRD,RDB,RESETB="L") 
***********************************************/
void Lcd_Initialize(void)
{	
	int a,i;
// LCD_FSMC_Config();
// LCD_Rst();

// 	WriteComm(0x00);
// 	a = *(__IO u16 *) (Bank1_LCD_D); 
// 	printf("ID=%04x\r\n",a);
// 	a = *(__IO u16 *) (Bank1_LCD_D); 
// 	printf("ID=%04x\r\n",a);
// a = *(__IO u16 *) (Bank1_LCD_D); 
// 	printf("ID=%04x\r\n",a);
// 	a = *(__IO u16 *) (Bank1_LCD_D); 
// 	printf("ID=%04x\r\n",a);
// a = *(__IO u16 *) (Bank1_LCD_D); 
// 	printf("ID=%04x\r\n",a);
// 	a = *(__IO u16 *) (Bank1_LCD_D); 
// 	printf("ID=%04x\r\n",a);	
	
// 	
		////////////////////HX8357C+TM3.2////////////
SPI_CS(1);
Delay(10);
SPI_CS(0);
//WriteComm(0x0000);
Delay(10);
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
Delay(120);

WriteComm(0x29);//Display on
WriteComm(0x2C);//Write GRAM

Delay(10);
WriteComm(0x36); //Set_address_mode
WriteData(0x60); //横屏，从左下角开始，从左到右，从下到上


test_color();
Lcd_Light_ON;

// while(1)
{
WriteComm(0x36);//竖屏
WriteData(0x40);//
BlockWrite(0,319,0,479);
// 	while(!(SPI1->SR&0x0002));
for(i=0;i<320*480;i++)
{
	LCD_RS(1);
	SPI_I2S_SendData(SPI1, BLUE>>8);
	LCD_RS(1);
	SPI_I2S_SendData(SPI1, BLUE);
}
for(i=0;i<320*480;i++)
{
	LCD_RS(1);
	SPI_I2S_SendData(SPI1, YELLOW>>8);
	LCD_RS(1);
	SPI_I2S_SendData(SPI1, YELLOW);
}

WriteComm(0x36);
WriteData(0x60);//
LCD_Fill_Pic(0,0,480,320, gImage_sheep);
}
// while(1)
// {
// 	display_picture("T35_05.BMP");
// 	display_picture("T35_01.BMP");
// 	display_picture("T35_02.BMP");
// 	display_picture("T35_03.BMP");
// 	display_picture("T35_04.BMP");
// 	display_picture("T35_00.BMP");

// }
}

void test_color(void)
{
	unsigned short i,j;
	BlockWrite(0,319,0,479);
	for(i=0;i<480;i++)
	{	for(j=0;j<320;j++)
		{
			if(j<40)
			{
				WriteData(BLACK>>8);
				WriteData(BLACK); 
			}
			else if(j<80)
			{
				WriteData(BLUE>>8);
				WriteData(BLUE);
			}
			else if(j<120)
			{
				WriteData(BRED>>8);
				WriteData(BRED);
			}
			else if(j<160)
			{
				WriteData(GRED>>8);
				WriteData(GRED);
			}
			else if(j<200)
			{
				WriteData(RED>>8);
				WriteData(RED);
			}
			else if(j<240)
			{
				WriteData(GREEN>>8);
				WriteData(GREEN);
			}
			else if(j<280)
			{
				WriteData(YELLOW>>8);
				WriteData(YELLOW);
			}
			else if(j<320)
			{
				WriteData(BROWN>>8);
				WriteData(BROWN);
			}
		}
	}
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
/**********************************************
函数名：Lcd块选函数
功能：选定Lcd上指定的矩形区域

注意：xStart、yStart、Xend、Yend随着屏幕的旋转而改变，位置是矩形框的四个角

入口参数：xStart x方向的起始点
          ySrart y方向的起始点
          Xend   y方向的终止点
          Yend   y方向的终止点
返回值：无
***********************************************/
void BlockWrite(unsigned int Xstart,unsigned int Xend,unsigned int Ystart,unsigned int Yend) 
{
	//HX8357-C
	
	 WriteComm(0x2A);
   WriteData(Xstart>>8);
   WriteData(Xstart);
   WriteData(Xend>>8);
   WriteData(Xend);
  
   WriteComm(0x2B);
   WriteData(Ystart>>8);
   WriteData(Ystart);
   WriteData(Yend>>8);
	 WriteData(Yend);
	 
	 WriteComm(0x2C);
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
		WriteData(Color>>8);
		WriteData(Color);
	}
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

// 	WriteComm(0x36); //Set_address_mode
// 	WriteData(0x0a); //横屏，从左下角开始，从左到右，从下到上
	BlockWrite(x,x+pic_H-1,y,y+pic_V-1);
	
	for (i = 0; i < pic_H*pic_V*2; i++)
	{
// 		WriteData(pic[i]);
	LCD_RS(1);	
	SPI_I2S_SendData(SPI1, pic[i]);
	}
// 	WriteComm(0x36); //Set_address_mode
// 	WriteData(0xaa);
}

void DrawPixel(u16 x, u16 y, u16 Color)
{
	BlockWrite(x,x,y,y);
// 	WriteComm(0x200);   
// 	WriteData(x);
// 	WriteComm(0x201);   
// 	WriteData(y);
// 	WriteComm(0x202);
	WriteData(Color>>8);
	WriteData(Color);
// 	*(__IO u16 *) (Bank1_LCD_D) = Color;
}

void PutGB1616(unsigned short x, unsigned short  y, unsigned char c[2], unsigned int fColor,unsigned int bColor,unsigned char flag)
{
	unsigned int i,j,k;
	unsigned short m=codeGB_16[k].Msk[i];

	BlockWrite(x,x+15,y,y+15);
	for (k=0;k<64;k++) { //64标示自建汉字库中的个数，循环查询内码
	  if ((codeGB_16[k].Index[0]==c[0])&&(codeGB_16[k].Index[1]==c[1]))
			{ 
    	for(i=0;i<32;i++) 
			{
				m=codeGB_16[k].Msk[i];
				for(j=0;j<8;j++) 
				{		
					if((m&0x80)==0x80) {
						DrawPixel(x+j,y,fColor);
						}
					else {
						if(flag) DrawPixel(x+j,y,bColor);
						}
					m=m<<1;
				} 
				if(i%2){y++;x=x-8;}
				else x=x+8;
		  }
		}  
	  }	
	}
void LCD_PutString(unsigned short x, unsigned short y, unsigned char *s, unsigned int fColor, unsigned int bColor,unsigned char flag) 
	{
	 unsigned char l=0;
	while(*s) {
		PutGB1616(x+l*8,y,(unsigned char*)s,fColor,bColor,flag);
		s+=2;l+=2;
// 		if( *s < 0x80) 
// 		    {
// 			LCD_PutChar(x+l*8,y,*s,fColor,bColor,flag);
// 			s++;l++;
// 			}
// 		else
// 		    {
// 			PutGB1616(x+l*8,y,(unsigned char*)s,fColor,bColor,flag);
// 			s+=2;l+=2;
// 			}
		}
	}
typedef __packed struct
{
	u8  pic_head[2];				//1
	u16 pic_size_l;			    //2
	u16 pic_size_h;			    //3
	u16 pic_nc1;				    //4
	u16 pic_nc2;				    //5
	u16 pic_data_address_l;	    //6
	u16 pic_data_address_h;		//7	
	u16 pic_message_head_len_l;	//8
	u16 pic_message_head_len_h;	//9
	u16 pic_w_l;					//10
	u16 pic_w_h;				    //11
	u16 pic_h_l;				    //12
	u16 pic_h_h;				    //13	
	u16 pic_bit;				    //14
	u16 pic_dip;				    //15
	u16 pic_zip_l;			    //16
	u16 pic_zip_h;			    //17
	u16 pic_data_size_l;		    //18
	u16 pic_data_size_h;		    //19
	u16 pic_dipx_l;			    //20
	u16 pic_dipx_h;			    //21	
	u16 pic_dipy_l;			    //22
	u16 pic_dipy_h;			    //23
	u16 pic_color_index_l;	    //24
	u16 pic_color_index_h;	    //25
	u16 pic_other_l;			    //26
	u16 pic_other_h;			    //27
	u16 pic_color_p01;		    //28
	u16 pic_color_p02;		    //29
	u16 pic_color_p03;		    //30
	u16 pic_color_p04;		    //31
	u16 pic_color_p05;		    //32
	u16 pic_color_p06;		    //33
	u16 pic_color_p07;		    //34
	u16 pic_color_p08;			//35			
}BMP_HEAD;

BMP_HEAD bmp;

 


//任意屏大小范围内显示图片
/*
x，y像素起点坐标
*/
char display_picture(char *filename)
{
	u16 ReadValue;
	FATFS fs;            // Work area (file system object) for logical drive
	FIL fsrc;      			// file objects
	u8 buffer[2048]; 		// file copy buffer
	FRESULT res;         // FatFs function common result code
	UINT br;         		// File R/W count
	u16 r_data,g_data,b_data;	
	u32	 tx,ty,temp;
	
	
  f_mount(0, &fs);

  res = f_open(&fsrc, filename, FA_OPEN_EXISTING | FA_READ);	 //打上图片文件名
  if(res==FR_NO_FILE||res==FR_INVALID_NAME){
     f_mount(0, NULL);
	 return 0;
  }

  if(res!=FR_OK){
     f_mount(0, NULL);
	 SD_Init();//重新初始化SD卡 
	 return 0;
  }

  res = f_read(&fsrc, &bmp, sizeof(bmp), &br);

  if(br!=sizeof(bmp))
	{
		f_close(&fsrc);
		f_mount(0, NULL);
		return 0;
  }

  if((bmp.pic_head[0]=='B')&&(bmp.pic_head[1]=='M'))
  {
	res = f_lseek(&fsrc, ((bmp.pic_data_address_h<<16)|bmp.pic_data_address_l));
	if(res!=FR_OK){
     f_close(&fsrc);
     f_mount(0, NULL);
	 return 0;
    }
	
	temp=bmp.pic_w_l*3;	
	if(bmp.pic_w_l>bmp.pic_h_l)
	{
 	WriteComm(0x36); //Set_address_mode
 	WriteData(0x38); //横屏，从左下角开始，从左到右，从下到上
	if(bmp.pic_w_l<480||bmp.pic_h_l<320)
		{
 			Lcd_ColorBox(0,0,480,320,0x0000);
 			BlockWrite((480-bmp.pic_w_l)/2,(480-bmp.pic_w_l)/2+bmp.pic_w_l-1,(320-bmp.pic_h_l)/2,(320-bmp.pic_h_l)/2+bmp.pic_h_l-1);
		}
		else 	BlockWrite(0,479,0,319);
	}
	else
	{
		WriteComm(0x36); //Set_address_mode
		WriteData(0x08); //竖屏，从左下角开始，从左到右，从下到上
		if(bmp.pic_w_l<320||bmp.pic_h_l<480)
			{
				Lcd_ColorBox(0,0,320,480,0x0000);
				BlockWrite((320-bmp.pic_w_l)/2,(320-bmp.pic_w_l)/2+bmp.pic_w_l-1,(480-bmp.pic_h_l)/2,(480-bmp.pic_h_l)/2+bmp.pic_h_l-1);
			}
			else BlockWrite(0,319,0,479);	
	}
	for (tx = 0; tx < bmp.pic_h_l; tx++)
	{
	f_read(&fsrc, buffer, (bmp.pic_w_l)*3, &br);
	for(ty=0;ty<temp;ty+=3)
		{
			r_data = *(ty +2+buffer);
			g_data = *(ty +1+buffer);
			b_data = *(ty +  buffer);			
			ReadValue=(r_data & 0xF8) << 8 | (g_data & 0xFC) << 3 | b_data >> 3;	
			WriteData(ReadValue>>8);
			WriteData(ReadValue);
			
// 			WriteData(r_data);
// 			WriteData(g_data);
// 			WriteData(b_data);
// 			*(__IO u16 *) (Bank1_LCD_D) = ((*(ty +2+buffer)<<8))|(*(ty +1+buffer)); 
// 			*(__IO u16 *) (Bank1_LCD_D) = ((*(ty +0+buffer)<<8))|(*(ty +5+buffer));  
// 			*(__IO u16 *) (Bank1_LCD_D) = ((*(ty +4+buffer)<<8))|(*(ty +3+buffer)); 
		}
	}	
		f_close(&fsrc);
   }
  f_mount(0, NULL);
// 	WriteComm(0x36); //Set_address_mode
//  	WriteData(0x08); //竖屏，从左上角开始，从左到右，从上到下
  return 1;
}
#include "lcm_api.h"
#include "GUI_Private.h"
#include "lcm_font.h"
#include <stdio.h>
#include "ili9325.h" 


//************************************************** 
//* 名    称: GUI_HLine()
//* 功    能:画水平线。
//* 参    数: x0		水平线起点所在列的位置
//*           y0		水平线起点所在行的位置
//*           x1      水平线终点所在列的位置
//*           color	显示颜色
//* 返 回 值:
//**************************************************
void  virtual_LCM_HLine(u16 x0, u16 y0, u16 x1, u16 color) 
{   
   for(;x0<=x1;x0++)
   {
	  DrawPixel(x0, y0, color);
   }
}


//************************************************
//* 名    称:void virtual_LCM_RLine(u16 x0, u16 y0, u16 y1, u16 color) 
//* 功    能:画竖直线 根据硬件特点，实现加速。
//* 参    数:x0		垂直线起点所在列的位置
//*           y0		垂直线起点所在行的位置
//*           y1      垂直线终点所在行的位置
//*           color	显示颜色
//* 返 回 值:
//************************************************
void virtual_LCM_RLine(u16 x0, u16 y0, u16 y1, u16 color) 
{
   for(;y0<=y1;y0++)
   {
	  DrawPixel(x0, y0, color);
   }
}	 	 


/****************************************************************************
* 名    称：void ssd1289_PutChar(u16 x,u16 y,u8 c,u16 charColor,u16 bkColoru8 flag)
* 功    能：在指定座标显示一个8x16点阵的ascii字符
* 入口参数：x          行座标
*           y          列座标
*           charColor  字符的颜色
*           bkColor    字符背景颜色
* 出口参数：无
* 说    明：显示范围限定为可显示的ascii码
* 调用方法：ssd1289_PutChar(10,10,'a',0x0000,0xffff, 1);
****************************************************************************/
//void virtual_LCM_PutChar(u16 x,u16 y,u8 c,u16 charColor,u16 bkColor,u8 flag)
//{
//  u16 i=0;
//  u16 j=0;
//  
//  u8 tmp_char=0;
//
//  for (i=0;i<16;i++)
//  {
//    tmp_char=LCM_ascii_8x16[((c-0x20)*16)+i];
//    for (j=0;j<8;j++)
//    {
//      if ( (tmp_char >> 7-j) & 0x01 == 0x01)
//        {
//          DrawPixel(x+j,y+i,charColor); // 字符颜色
//        }
//        else
//        {
//		   if(flag)
//             DrawPixel(x+j,y+i,bkColor); // 背景颜色
//        }
//    }
//  }
//}


//void virtual_LCM_PutChar_V1(u16 x,u16 y,u8 c,u16 charColor,u16 bkColor,u8 flag)
//{  
//   if(flag){
//	 Put8_16Char(x,y,LCM_ascii_8x16,c,charColor,bkColor,flag);
//   }else{
//   	 //virtual_LCM_PutChar(x,y,c,charColor,bkColor,flag);
//   }
//}


/****************************************************************************
* 名    称：void ssd1289_PutString(u16 x,u16 y,u8 c,u16 charColor,u16 bkColor)
* 功    能：在指定座标显示一个8x16点阵的ascii字符串
* 入口参数：x          行座标
*           y          列座标
*           charColor  字符的颜色
*           bkColor    字符背景颜色
*       	flag	   是否显示背景颜色（1是，0否）
* 出口参数：无
* 说    明：显示范围限定为可显示的ascii码
* 调用方法：ssd1289_PutString(10,10,“abc”,0x0000,0xffff);
****************************************************************************/
void virtual_LCM_PutString(u16 x,u16 y,u8* c,u16 charColor,u16 bkColor ,u8 flag)
{
  unsigned int i=0,j=0;	
  
  if((x>=320-8)||(y>=240-16))  return;

  i=x;
  j=y;
  
  while(*c!='\0'&&*c!=NULL)
  {
	//virtual_LCM_PutChar( i,j,*c,charColor,bkColor,flag);
	c++;
	i+=8;
	if(i>=320-8){
	   i=0;
	   j+=16;
	   if(j>=240-16)
	      return;
	}
  }
}


//*************************************************
//函数名称 :  ssd1289_PutNums
//功能描述 :  显示数值num
//输入参数 : 
//输出参数 : 
//返回值   : 
//*************************************************
void virtual_LCM_PutNums(u16 x,u16 y,u32 num,u16 charColor,u16 bkColor ,u8 flag)
{
     char s[30];
     sprintf(s, "%d",num);
	 virtual_LCM_PutString(x,y,(u8*)s,charColor,bkColor ,flag);
}

void virtual_LCM_PutNums_V2(u16 x,u16 y,u32 num,u8* format,u16 charColor,u16 bkColor ,u8 flag)
{
     char s[30];
     sprintf(s,(const char *)format,num);
	 virtual_LCM_PutString(x,y,(u8*)s,charColor,bkColor ,flag);
}


//显示一个数字 
void virtual_LCM_PutNum_32x16(u16 x,u16 y,u8 c,u16 charColor,u16 bkColor,u8 flag)
{  
  u16 i=0,k;
  u16 j=0;
  
  u8 tmp_char=0;

  for (i=0;i<32;i++)
  {
    for (k=0;k<2;k++)
	{
    	tmp_char=LCM_NUM_16x32[c][i*2+k];
    	for (j=0;j<8;j++)
    	{
      		if ( ((tmp_char >> 7-j) & 0x01) == 0x01)
        	{
          		DrawPixel(x+k*8+j,y+i,charColor); // 字符颜色
        	}
        	else
        	{
		   		if(flag)
             	DrawPixel(x+k*8+j,y+i,bkColor); // 背景颜色
        	}
    	}
	}
  }
}


//显示数值
void virtual_LCM_PutNums_32x16(u16 x,u16 y,u32 num,u8 *format,u16 charColor,u16 bkColor ,u8 flag)
{
  char s[30];
  char *p;
  unsigned int i=0,j=0;	
  
  if((x>=320-16)||(y>=240-32))  return;

  sprintf(s,(const char *)format,num);

  p=s;
  i=x;
  j=y;
  
  while(*p!='\0'&&*p!=NULL)
  {
    if(flag){
       Put16x32Num(i,j,(const unsigned char *)LCM_NUM_16x32,*p-'0',charColor,bkColor,flag);
	}
	else{
       virtual_LCM_PutNum_32x16(i,j,*p-'0',charColor,bkColor,flag);
	}
	p++;
	i+=16;
	if(i>=320-16){
	   i=0;
	   j+=32;
	   if(j>=240-32)
	      return;
	}
  }
}

/****************************************************************************
* 名    称：void ili9320_GUI_Circle(u16 cx,u16 cy,u16 r,u16 color,u8 fill)
* 功    能：在指定座标画圆，可填充,近似画法
* 入口参数：
* 出口参数：
* 说    明：
* 调用方法：
****************************************************************************/
void GUI_Circle(u16 cx,u16 cy,u16 r,u16 color,u8 fill)
{
	u16 x,y,tmp_color;
	s16 delta,tmp;
	x=0;
	y=r;
	delta=3-(r<<1);
	tmp_color=LCD_COLORINDEX;
	while(y>x)
	{
		if(fill)
		{
			LCD_COLORINDEX=color;
			LCD_L0_DrawHLine(cx-x,cy+y,cx+x);
			LCD_L0_DrawHLine(cx-x,cy-y,cx+x);
			LCD_L0_DrawHLine(cx-y,cy+x,cx+y);
			LCD_L0_DrawHLine(cx-y,cy-x,cx+y);
		}
		else
		{
			DrawPixel(cx+x,cy+y,color);
			DrawPixel(cx-x,cy+y,color);
			DrawPixel(cx+x,cy-y,color);
			DrawPixel(cx-x,cy-y,color);
			DrawPixel(cx+y,cy+x,color);
			DrawPixel(cx-y,cy+x,color);
			DrawPixel(cx+y,cy-x,color);
			DrawPixel(cx-y,cy-x,color);
		}
		x++;
		if(delta>=0)
		{
			y--;
			tmp=(x<<2);
			tmp-=(y<<2);
			delta+=(tmp+10);
		}
		else
		{
			delta+=((x<<2)+6);
		}
	}
	LCD_COLORINDEX=tmp_color;
}

/****************************************************************************
* 名    称：void GUI_Rectangle(u16 x0, u16 y0, u16 x1, u16 y1,u16 color,u8 fill)
* 功    能：在指定区域画矩形，可填充颜色
* 入口参数：
* 出口参数：
* 说    明：
* 调用方法：
****************************************************************************/
void virtual_LCM_Rectangle(u16 x0, u16 y0, u16 x1, u16 y1,u16 color,u8 fill)
{
	if(fill)
	{
		u16 i;
		if(x0>x1)
		{
			i=x1;
			x1=x0;
		}
		else
		{
			i=x0;
		}
		for(;i<=x1;i++)
		{
			//virtual_LCM_Line(i,y0,i,y1,color);
			virtual_LCM_RLine(i,y0,y1,color);
		}
		return;
	}
		
	virtual_LCM_HLine(x0,y0,x1,color);
	virtual_LCM_HLine(x0,y1,x1,color);
	virtual_LCM_RLine(x0,y0,y1,color);
	virtual_LCM_RLine(x1,y0,y1,color);

}

/****************************************************************************
* 名    称：void GUI_Rectangle_V2(u16 x0, u16 y0, u16 lenth, u16 width,u16 color,u8 fill)
* 功    能：在指定区域画矩形，可填充颜色
* 入口参数：
* 出口参数：
* 说    明：
* 调用方法：
****************************************************************************/
void virtual_LCM_Rectangle_V2(u16 x0, u16 y0, u16 lenth, u16 width,u16 color,u8 fill)
{
	if(fill){
	   Lcd_ColorBox(x0,y0,lenth,width,color);
	}else{
	   virtual_LCM_Rectangle( x0, y0, x0+lenth, y0+width,color,fill);
	}
}


/****************************************************************************
* 名    称：void  GUI_Square(u16 x0, u16 y0, u16 with, u16 color,u8 fill)
* 功    能：在指定区域画正方形，可填充颜色
* 入口参数：
* 出口参数：
* 说    明：
* 调用方法：
****************************************************************************/
void virtual_LCM_Square(u16 x0, u16 y0, u16 with, u16 color,u8 fill)
{
	if(fill){
	  Lcd_ColorBox(x0,y0,with,with,color);
    }else{
	  virtual_LCM_Rectangle(x0, y0, x0+with, y0+with, color,fill);
    } 
}

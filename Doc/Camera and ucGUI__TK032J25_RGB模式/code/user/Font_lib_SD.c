#include "ili9325.h"
#include "ff.h"
#include  "touch.h"
#include "Font_lib_SD.h"
u8 GBK16[32];
u16 LCD_X=0,LCD_Y=0;
char end_ebook;
unsigned char *Read_One_GBK16(unsigned char *ch) 
{ 
   unsigned int  temp1;   
	// if(*ch<0x81||(*ch+1)<0x40)//不合法的汉字	////	32*(*ch+220-65);
   if(*ch<0x81)
   {
	temp1=temp1=(*ch-32)*16;
	f_lseek(&fsrc,temp1);
	f_read(&fsrc, GBK16, 16, &br);	
	return GBK16;
   }	 
	else 
	{ 	 //     汉字区码       	汉字位码
	temp1=(94*(*ch-1-0xa0)+(*(ch+1)-1-0xa0+112))*32;//计算汉字在字库中的偏移地址 
	f_lseek(&fsrc,temp1);
	f_read(&fsrc, GBK16, 32, &br);	
	return GBK16;
   }
}
void Lcd_WriteASCIIClarity(u16 x,u8 y,u16 CharColor,u16 CharBackColor,u8 *ASCIICode,u8 flag)
{
  
  u8 RowCounter,BitCounter;
  u8 *ASCIIPointer;

  ASCIIPointer=Read_One_GBK16(ASCIICode);//取这个字符的显示代码
  for (RowCounter=0; RowCounter<16; RowCounter++)
  { 
    
	for(BitCounter=0;BitCounter<8;BitCounter++)
    {
      if((*ASCIIPointer  & (0x80 >> BitCounter)) != 0x00)
      {	    
		DrawPixel(x+BitCounter,y+RowCounter,CharColor);
      }
	  else if(flag)
	  {
	  	DrawPixel(x+BitCounter,y+RowCounter,CharBackColor);
	  }
    }
    ASCIIPointer++;
  }
  
}
void Lcd_WriteChineseClarity(u16 x,u8 y,u16 CharColor,u16 CharBackColor, u8 *ChineseCode,u8 flag)
{
  
  u8 ByteCounter,BitCounter;
  u8 *ChinesePointer;
  ChinesePointer=Read_One_GBK16(ChineseCode);
  
  for(ByteCounter=0; ByteCounter<16; ByteCounter++)
  { 
    for(BitCounter=0; BitCounter<8; BitCounter++)
    {
      if((*ChinesePointer & (0x80 >> BitCounter)) != 0x00)
      {
        DrawPixel(x+BitCounter,y+ByteCounter,CharColor);
      }
	  else if(flag)
	  {
	  	DrawPixel(x+BitCounter,y+ByteCounter,CharBackColor);
	  }
       if((*(ChinesePointer+1) & (0x80 >> BitCounter)) != 0x00)
      {
        DrawPixel(x+BitCounter+8,y+ByteCounter,CharColor);
      }
	  else if(flag)
	  {
	  	DrawPixel(x+BitCounter+8,y+ByteCounter,CharBackColor);
	  }
    }
  ChinesePointer=ChinesePointer+2;;
  }
}

Lcd_WriteChineseStringClarity(u16 x,u8 y,u16 CharColor,u16 CharBackColor,u8 *s,u8 flag)
{
    while(*s!='\0')
   {   
	   
	   if(*s<0x81) //是ASCII
		   {
				 Lcd_WriteASCIIClarity(x,y,CharColor,CharBackColor,s,flag);
				 s++;
		   }
		else
			{
				if(x==39*8) 
				{
					x=0;
					if(y==14*16) {x=0;y=0;}
					else y=y+16;
				}
				if(*(s+1)!='\0')
					{
						Lcd_WriteChineseClarity(x,y,CharColor,CharBackColor,s,flag);
						if (x<39*8) x=x+8;
						s=s+2;
					}
			}
		if (x<39*8) x=x+8;  
       else if (y<14*16)
	       {
	         x=0;
	         y=y+16;		  
	       }
       else
	       {
	         x=0;y=0;
	       } 
            
   }  
}  

Lcd_WriteChineseStringClarityEbook(u16 x,u8 y,u16 CharColor,u16 CharBackColor,u8 *s,u8 flag)
{
    while(*s!='\0')
   {   
	   
	   if(*s<0x81) //是ASCII
		   {
				   //========================================================================
			if(*s==0x0D)	//回车键
			   {
			   	if(*(s+1)=='\0') {LCD_X=0;LCD_Y=0;return 1;} //半字节,提前结束
				else if(y<14*16) y=y+16;
					 else {y=0;pg_up_dn();if(end_ebook)return;Lcd_Clear(0x0000);}
				x=0;
				s+=2;
				continue; 	
				}
			else
				{	
				   Lcd_WriteASCIIClarity(x,y,CharColor,CharBackColor,s,flag);
				   s++;
				 }
				 //=================================================================================
		   }
		else
			{
				if(x==39*8) 
				{
					x=0;
					if(y==14*16) {y=0;pg_up_dn();if(end_ebook)return;Lcd_Clear(0x0000);}
					else y=y+16;
				}
				if(*(s+1)!='\0')
					{
						Lcd_WriteChineseClarity(x,y,CharColor,CharBackColor,s,flag);
						if (x<39*8) x=x+8;
						s=s+2;
					}
				else {LCD_X=x;LCD_Y=y;return 1;}
			}
		if (x<39*8) x=x+8;  
       else if (y<14*16)
	       {
	         x=0;
	         y=y+16;		  
	       }
       else
	       {
	         x=0;y=0;
	         pg_up_dn();if(end_ebook)return;Lcd_Clear(0x0000);		//Delay(10000);
	       } 
            
   }  
     
	 LCD_X=x;LCD_Y=y;
	 return 0;
}

void Ebook(char *filename)
{
	u16 a=512;	
	u32	 tx=0,ty;
	u8 buffer[512]; // file copy buffer	
	LCD_X=0;LCD_Y=0;
	f_mount(0, &fs);
  	f_open(&fsrc,filename, FA_OPEN_EXISTING | FA_READ);
	Lcd_Clear(0x0000);
	f_lseek(&fsrc,0);
	ty=fsrc.fsize;
	end_ebook=0;
	while(ty)
	{
		if((tx+512)>ty){a=ty-tx;buffer[a]=0;ty=0;}
		f_open(&fsrc,filename, FA_OPEN_EXISTING | FA_READ);	
		f_lseek(&fsrc,tx);		
		f_read(&fsrc, buffer, a, &br);
		f_open(&fsrc,"st1616.bin", FA_OPEN_EXISTING | FA_READ);
		if(Lcd_WriteChineseStringClarityEbook(LCD_X,LCD_Y,0xFFE0,0,buffer,0))
		tx+=511;
		else tx+=512;
		if(end_ebook)return;
	}
}

void pg_up_dn(void)
{  int x,y;
	while(1)
	{
	x=GUI_TOUCH_X_MeasureX();
	y=GUI_TOUCH_X_MeasureY();
	if(x>150&&x<500&&y>3000){end_ebook=1;return;}
	else if(y>270&&y<1750)return;
		else if(y>1750);
	}
}

//{ 
//  const unsigned char tiky_w[28]={"Happy new year!Tiky,你好!"};
//  f_open(&fsrc,"st1616.bin", FA_OPEN_EXISTING | FA_READ);
//  res =f_open(&fdst,"Tiky_1.txt", FA_OPEN_EXISTING | FA_WRITE);// FA_CREATE_ALWAYS
//  res = f_lseek(&fdst, file.fsize); //指针移到文件最后
//  res =f_write(&fdst, tiky_w, 28, &bw);
//  f_close(&fdst);
//}

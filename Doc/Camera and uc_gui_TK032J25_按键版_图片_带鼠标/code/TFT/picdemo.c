/* Includes ------------------------------------------------------------------*/

#include "stm32f10x.h"
#include "ff.h"	
#include "ili9325.h" 
#include <stdio.h>
#include "touch.h"
#include "msd.h"

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


static FATFS fs;            // Work area (file system object) for logical drive
static FIL fsrc;      // file objects
static u8 buffer[2048]; // file copy buffer
static FRESULT res;         // FatFs function common result code
static UINT br;         // File R/W count
static u16 r_data,g_data,b_data;	

//任意屏大小范围内显示图片
/*
x，y像素起点坐标
*/
char Tiky_Button(char *filename,u16 x,u16 y)
{
	u32	 tx,ty;
  u16 ReadValue;
  f_mount(0, &fs);

  res = f_open(&fsrc, filename, FA_OPEN_EXISTING | FA_READ);	 //打上图片文件名
  if(res==FR_NO_FILE||res==FR_INVALID_NAME){
     f_mount(0, NULL);
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
				
				if(bmp.pic_h_l<240||bmp.pic_w_l<320)
	{
	Lcd_Clear(0);
	Lcd_SetCursor(0,239-(239-bmp.pic_h_l)/2);
	Lcd_WR_Start();
	}
    else Lcd_Start();
	LCD_Scan_Set(1);
	
// 			LcdSetArea(x,y,x+bmp.pic_w_l-1,y+bmp.pic_h_l-1);

			ty=0;
			for (tx = 0; tx < bmp.pic_h_l; tx++)
			{
			f_read(&fsrc, buffer, (bmp.pic_w_l)*3, &br);
			for(ty=0;ty<bmp.pic_w_l;ty++)
				{
					r_data = *(ty*3 +2+buffer);
					g_data = *(ty*3 +1+buffer);
					b_data = *(ty*3 +  buffer);			
					ReadValue=(r_data & 0xF8) << 8 | (g_data & 0xFC) << 3 | b_data >> 3; 
					GPIOB->ODR=((GPIOB->ODR&0x00ff)|(ReadValue&0xff00));	
					Clr_nWr;
					Set_nWr;
					GPIOB->ODR=((GPIOB->ODR&0x00ff)|(ReadValue<<8));
					Clr_nWr;
					Set_nWr;                          
				}
			}	
				f_close(&fsrc);
   }
	LCD_Scan_Set(1);
  f_mount(0, NULL);
  Set_Cs; 
  return 1;

}

char display_picture(char *filename)
{
	u32	 tx,ty;
  u16 ReadValue;

  f_mount(0, &fs);

  res = f_open(&fsrc, filename, FA_OPEN_EXISTING | FA_READ);	 //打上图片文件名
  if(res==FR_NO_FILE||res==FR_INVALID_NAME){
	 //f_close(&fsrc);
     f_mount(0, NULL);
	 return 0;
  }

  if(res!=FR_OK){
     f_mount(0, NULL);
	 MSD_Init();//重新初始化SD卡 
	 return 0;
  }

  res = f_read(&fsrc, &bmp, sizeof(bmp), &br);

  if(br!=sizeof(bmp)){
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
		LCD_Scan_Set(1);
	if(bmp.pic_h_l<240||bmp.pic_w_l<320)
	{
	Lcd_Clear(0);

	Lcd_SetCursor((320-bmp.pic_w_l)/2,(240-bmp.pic_h_l)/2);
		    //x,y坐标对调 
	LCD_WR_REG(0x0052,(320-bmp.pic_w_l)/2);//垂直 GRAM起始位置
	LCD_WR_REG(0x0053,(320-bmp.pic_w_l)/2+bmp.pic_w_l-1);//垂直GRAM终止位置

	LCD_WR_REG(0x0050,(240-bmp.pic_h_l)/2);//水平GRAM起始位置
	LCD_WR_REG(0x0051,(240-bmp.pic_h_l)/2+bmp.pic_h_l-1);//水平GRAM终止位置 
	Lcd_WR_Start();
	}
//     else 
	ty=0;
	for (tx = 0; tx < bmp.pic_h_l; tx++)
	{
	f_read(&fsrc, buffer, (bmp.pic_w_l)*3, &br);
	for(ty=0;ty<bmp.pic_w_l;ty++)
		{
			r_data = *(ty*3 +2+buffer);
			g_data = *(ty*3 +1+buffer);
			b_data = *(ty*3 +  buffer);			
			ReadValue=(r_data & 0xF8) << 8 | (g_data & 0xFC) << 3 | b_data >> 3; 
			GPIOB->ODR=((GPIOB->ODR&0x00ff)|(ReadValue&0xff00));	
			Clr_nWr;
			Set_nWr;
			GPIOB->ODR=((GPIOB->ODR&0x00ff)|(ReadValue<<8));
			Clr_nWr;
			Set_nWr;                          
		}
	}	
		f_close(&fsrc);
   }
LCD_Scan_Set(1);
  f_mount(0, NULL);
  Set_Cs; 
  return 1;

}

char display_partation_picture(char *filename,u16 x0,u16 y0,u16 pic_x,u16 pic_y,u16 pic_L,u16 pic_H)
{
	u32	 tx,ty;
  u16 ReadValue;

  f_mount(0, &fs);


  res = f_open(&fsrc, filename, FA_OPEN_EXISTING | FA_READ);	 //打上图片文件名
  if(res==FR_NO_FILE||res==FR_INVALID_NAME){
	 //f_close(&fsrc);
     f_mount(0, NULL);
	 return 0;
  }

  if(res!=FR_OK){
     f_mount(0, NULL);
	 MSD_Init();//重新初始化SD卡 
	 return 0;
  }

  res = f_read(&fsrc, &bmp, sizeof(bmp), &br);

  if(br!=sizeof(bmp)){
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

	Lcd_SetBox(x0,y0,pic_L,pic_H,0,0);//设置显示范围
	Lcd_SetCursor(x0,y0+pic_H-1);
	Lcd_WR_Start();
	Set_Rs;
	Clr_Cs;

	tx=0;
	for (ty = 0; ty < 240; ty++)
	{

	    f_read(&fsrc, buffer, 960, &br);

	    for(tx=0;tx<320;tx++)
		{  
           if(((239-ty)>(pic_y+pic_H-1))||((239-ty)<pic_y)||(tx>(pic_x+pic_L-1))||(tx<pic_x))
		      continue;

		   r_data = *(tx*3 +2+buffer);
		   g_data = *(tx*3 +1+buffer);
		   b_data = *(tx*3 +  buffer);
		   ReadValue=(r_data & 0xF8) << 8 | (g_data & 0xFC) << 3 | b_data >> 3; 
           //输出到屏幕
		   GPIOB->ODR=((GPIOB->ODR&0x00ff)|(ReadValue&0xff00));	
           Clr_nWr;
	       Set_nWr;
	       GPIOB->ODR=((GPIOB->ODR&0x00ff)|(ReadValue<<8));
		   Clr_nWr;
		   Set_nWr;
		   //Delay(6);	
                          
		}

	}	
		f_close(&fsrc);
   }

  f_mount(0, NULL);
  Set_Cs; 
  return 1;

}


#define  M_X   25  
#define  M_Y   55
#define  M_L   125
#define  M_H   50  
#define  M_DX  (320-M_L*2-M_X*2)
#define  M_DY  (240-M_H*2-M_Y*2)   

char display_button_picture(char *filename)
{
	u32	 tx,ty;
  u16 ReadValue;

  f_mount(0, &fs);

  res = f_open(&fsrc, filename, FA_OPEN_EXISTING | FA_READ);	 //打上图片文件名
  if(res==FR_NO_FILE||res==FR_INVALID_NAME){
	 //f_close(&fsrc);
     f_mount(0, NULL);
	 return 0;
  }

  if(res!=FR_OK){
     f_mount(0, NULL);
	 MSD_Init();//重新初始化SD卡 
	 return 0;
  }

  res = f_read(&fsrc, &bmp, sizeof(bmp), &br);

  if(br!=sizeof(bmp)){
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

	Lcd_Start();

	Clr_Cs;

	tx=0;
	for (ty = 0; ty < 240; ty++)
	{

	    f_read(&fsrc, buffer, 960, &br);

	    for(tx=0;tx<320;tx++)
		{  
           if(((239-ty)>(M_Y+M_H+M_DY+M_H-1))||((239-ty)<M_Y))
		      continue;
			  
           if((tx>(M_X+M_L+M_DX+M_L-1))||(tx<M_X))
		      continue;

           if(((239-ty)>(M_Y+M_H-1))&&((239-ty)<M_Y+M_H+M_DY))
		      continue;

           if((tx>(M_X+M_L-2))&&(tx<(M_X+M_L+M_DX-2)))
		      continue;
           
		   if(tx==M_X){ 
		       Lcd_SetCursor(M_X,239-ty);	
			   Lcd_WR_Start();
  			   Set_Rs;
	           Clr_Cs; 
		   }

		   if(tx==M_X+M_L+M_DX){ 
		       Lcd_SetCursor(M_X+M_L+M_DX,239-ty);	
			   Lcd_WR_Start();
  			   Set_Rs;
	           Clr_Cs; 
		   }
		  
		   r_data = *(tx*3 +2+buffer);
		   g_data = *(tx*3 +1+buffer);
		   b_data = *(tx*3 +  buffer);
		   ReadValue=(r_data & 0xF8) << 8 | (g_data & 0xFC) << 3 | b_data >> 3; 
           //输出到屏幕
		   GPIOB->ODR=((GPIOB->ODR&0x00ff)|(ReadValue&0xff00));	
           Clr_nWr;
	       Set_nWr;
	       GPIOB->ODR=((GPIOB->ODR&0x00ff)|(ReadValue<<8));
		   Clr_nWr;
		   Set_nWr;	
                          
		}

	}	
		f_close(&fsrc);
   }

  f_mount(0, NULL);
  Set_Cs; 
  return 1;

}


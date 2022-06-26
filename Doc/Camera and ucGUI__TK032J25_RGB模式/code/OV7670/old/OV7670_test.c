/* Includes ------------------------------------------------------------------*/
#include "ff.h"	
#include "stm32f10x_lib.h"
#include "stdio.h"
#include "fifo.h"
#include "ov7670.h"
#include "LCMDRV.H"


vu8 OV7670_Done_FLAG;//帧同步信号
vu8 OV7670_LockClose = 1;
static char FilSYS_INT = 0;
vu8 OV7670_F1=0 ,OV7670_F2=0;
vu8 OV7670_take_photo = 0;
vu16 gsm = 0;	

static const u8 bmpheader[54]={//构造bmp首部
	0x42, 0x4D, 0x36, 0x84, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 
	0x00, 0x00, 0x40, 0x01, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x84, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

extern void LCD_picture_start(void);//在picdemo.c中


//FatFS用到的变量
static FATFS fs;            // Work area (file system object) for logical drive
static FIL fsrc, fdst;      // file objects
static FRESULT res;         // FatFs function common result code
static BYTE buffer[1028];
static UINT br,bw;
static BYTE temp[323];

//++++++++++++++++++++++++++++++++++++++++++++++
//bmp文件格式的数据头结构
//++++++++++++++++++++++++++++++++++++++++++++++
typedef struct
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




//------------------------------------------------
//用来测试OV7670的Demo
//------------------------------------------------
int OV7670_main(void)
{
  u16 ReadValue; 
  u32 a;
  u8  cnt=0,i;	


  Fifo_Init();	   //Fifo引脚初始化

  //OV7670_EXTI_Config();	   //帧中断设置
  
  while(1!=OV7670_init());//初始化ov7670

  OV7670_EXTI_Config();	   //帧中断设置
  ov7670_Interrupts_Config();	 //中断优先级配置

  HREF_H;

  //EXTI->IMR &= ~EXTI_LINE_VSYNC_CMOS;//屏蔽线x上的中断请求

  OV7670_Done_FLAG = 0;//帧同步信号

  while(1)
  { 
//-------------------------------xingxing-----------------------------------

    while(OV7670_Done_FLAG==0);//等待帧同步信号
    HREF_L;//禁止写FIFO 
    EXTI->IMR &= ~EXTI_LINE_VSYNC_CMOS;//屏蔽线x上的中断请求
	LCD_picture_start();//开始全屏写,设置地址
			  
		  FIFO_CS_L();//使能FIFO输出

          //复位读FIFO的地址
		  FIFO_RRST_L();		    
	      FIFO_RD_L();
		  FIFO_RD_H();
		  FIFO_RD_L();
		  FIFO_RD_H();
		  FIFO_RRST_H();
		  
          //舍弃第一个数据	  		   
		  FIFO_RD_L();
		  FIFO_RD_H();
	

		  //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

          //复位读FIFO的地址
		  FIFO_RRST_L();		    
	      FIFO_RD_L();
		  FIFO_RD_H();
		  FIFO_RD_L();
		  FIFO_RD_H();
		  FIFO_RRST_H();
		  
          //舍弃第一个数据	  		   
		  FIFO_RD_L();
		  FIFO_RD_H();


          //写屏
          for( a = 0;a < 320*240; a++)
          { 	     	  		       
		   FIFO_RD_L();	
		   ReadValue = ((GPIO_ReadInputData(GPIOD)<<8)&0XFF00);	   //读fifo一个八位    	  高位
		   FIFO_RD_H();

		   FIFO_RD_L();
		   ReadValue |= (GPIO_ReadInputData(GPIOD)&0X00FF);	   //读fifo一个八位    	  低位
		   FIFO_RD_H(); 
		 
		   GPIOE->ODR =	ReadValue;
		   Clr_nWr;
		   Set_nWr;                 
           }
       
	   FIFO_WRST_L();//复位写FIFO的地址
   	   FIFO_CS_H();//FIFO输出关 
//------------------------------------------------------------------------------
	   OV7670_Done_FLAG=0;
       EXTI->IMR |= EXTI_LINE_VSYNC_CMOS;//开放线x上的中断请求 
       while(OV7670_Done_FLAG==0);//等待新一帧的开始信号
       HREF_H;//使能FIFO写
	   FIFO_WRST_H();//解除写地址复位信号       
	   OV7670_Done_FLAG=0;
  }//while

}








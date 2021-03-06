//
//项目负责人:Tiky
//协作人:XING
//首发论坛:www.ourdev.cn
//欢迎光临我们的淘宝小店：http://firestm32.taobao.com
//欢迎光临我们的淘宝小店：http://tiky.taobao.com
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "gui.h"
#include "msd.h" 
#include "My_FF.h"
#include "my_menu.h"
#include "ov7670.h"
#include "fifo.h"
#include "touch.h"
#include "SysConfig.h"
#include "mmc_sd.h"	 
#include "ili9325.h"   							   
#include "Font_lib_SD.h"
#include "ucGUI_Practice.h"
//#include "MM_T035.h"
#include "pig.h"
/* Global variables-----------------------------------------------------------*/
extern char file_num;//选中的文件标号
extern DIR start_dirs;          //目录起点信息
extern vu8 SD_Card_Ready;//SD卡初始化成功标志


/* Extern declare -------------------------------------------------------------*/
extern void RTC_main(void);
extern void OV7670_main(void);
extern void picdemo_test(void);
extern char display_picture(char *filename);
extern char display_button_picture(char *filename);
extern char display_partation_picture(char *filename,u16 x0,u16 y0,u16 pic_x,u16 pic_y,u16 pic_L,u16 pic_H);
extern void SetupUART1(void);
extern void Get_Medium_Characteristics(void);

extern u32 Mass_Block_Count;
extern u32 Mass_Block_Size;
extern u32 Mass_Memory_Size;



FATFS fs;            // Work area (file system object) for logical drive
FIL fsrc, fdst,file;      // file objects
FRESULT res;         // FatFs function common result code
UINT br, bw;         // File R/W count	
	  

/*******************************************************************************
* Function Name  : main.
* Description    : Main routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int main(void)
{	
	u8 ret = 1;		
	char id=-1;
	char s[10]={0};
	u8 i=0,menu_3_lock=1;
	int tx,ty;

  SystemInit();
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC | 
						 RCC_APB2Periph_AFIO  | RCC_APB2Periph_USART1 |RCC_APB2Periph_SPI1, ENABLE);

	SysTick_Configuration();
	InterruptConfig();
	TIM2_Config();
// 	SetupUART1();
// 	Main_GPIO_Config();

	//checkSerialNUM();//检查序列号

// 	Touch_GPIO_Config();//软件模拟SPI	
		
//   ret = MSD_Init();
// 	SD_Card_Ready = ret;

// 	HREF_L;//禁止写FIFO 
// 	FIFO_CS_H();//除能FIFO输出
// 	RCC_MCOConfig(RCC_MCO_NoClock); //失能PA8引脚上输出时钟源 
// 	if((RCC->CSR>>27)&0x01)
	Lcd_Initialize();
	GUI_Init();	//MainTask_Dialog_All();
//	menu_3_lock=Init_Mouse();
	tiky_start:
	GUI_SetFont(&GUI_Font24_ASCII);
	GUI_SetColor(GUI_WHITE);
	GUI_SetBkColor(GUI_RED);
  GUI_Clear();
	GUI_DispStringHCenterAt("Tiky Test Board", 200, 15);
	GUI_DispStringAt("1. RGB Test", 5, 40);
	GUI_DispStringAt("2. Display Picture", 5, 80);
	GUI_DispStringAt("3. ucGUI_Practice", 5, 120);
	GUI_DispStringAt("    Please press \"up\" to select, press \"down\" ", 5, 160);
	GUI_DispStringAt("to Enter;If you want to return,please press", 5, 180);
	GUI_DispStringAt("\"Rest\".", 5, 200);
	GUI_SetBkColor(GUI_BLUE);
	GUI_DispStringAt("1. RGB Test", 5, 40);
	i=1;
// 	GUI_DispDecAt( menu_3_lock ,200,30,4);
	while(1)
	{
		
		if((GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_6)==1)|(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)==1))
		{
			if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)==1)i++;
			if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_6)==1)i--;
			GUI_SetBkColor(GUI_RED);
			GUI_DispStringAt("1. RGB Test", 5, 40);
			GUI_DispStringAt("2. Display Picture", 5, 80);
			GUI_DispStringAt("3. ucGUI_Practice", 5, 120);
			GUI_SetBkColor(GUI_BLUE);
			switch (i%3)
				{
					case 0:
						GUI_DispStringAt("3. ucGUI_Practice", 5, 120);
						break;
					case 1:
						GUI_DispStringAt("1. RGB Test", 5, 40);
						break;
					case 2:
						GUI_DispStringAt("2. Display Picture", 5, 80);
						break;
					default: break;	
				}
			LCD_delay(100);
		}
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1)
		{
			if(i%3==1)
			{
				Lcd_ColorBox(0,0,320,480,MAGENTA);
				GUI_SetFont(&GUI_Font16_ASCII);
				GUI_DispStringHCenterAt("please use \"up\"and \"dowm\" to change the display Mode", 200, 15);
				LCD_delay(100);
				i=100;
				while(1)
				{
					if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_6)==1)
					{	
						i++;
						if(i%5==0)Lcd_ColorBox(0,0,320,480,RED);
						if(i%5==1)Lcd_ColorBox(0,0,320,480,GREEN);
						if(i%5==2)Lcd_ColorBox(0,0,320,480,BLUE);
						if(i%5==3)Lcd_ColorBox(0,0,320,480,BLACK);
						if(i%5==4)Lcd_ColorBox(0,0,320,480,WHITE);
						LCD_delay(100); 
					}
					if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)==1)
					{	
						i--;
						if(i%5==0)Lcd_ColorBox(0,0,320,480,RED);
						if(i%5==1)Lcd_ColorBox(0,0,320,480,GREEN);
						if(i%5==2)Lcd_ColorBox(0,0,320,480,BLUE);
						if(i%5==3)Lcd_ColorBox(0,0,320,480,BLACK);
						if(i%5==4)Lcd_ColorBox(0,0,320,480,WHITE);
						LCD_delay(100); 
					}
					if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5)==1)goto tiky_start;
				}
			}
			if(i%3==2)
			{
// 				GUI_SetBkColor(GUI_RED);
// 				GUI_Clear();
					Lcd_ColorBox(0,0,320,480,BLUE);
						LCD_Fill_Pic(0,0,480,320, gImage_pig);
//						BlockWrite(0,0,799,479);
//						LCD_Fill_Pic(400,0,320,320, gImage_MM_T035);
				while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1);
				LCD_delay(100);
				while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0)//XL=150;XR=4000;YU=200;YD=3480
				{
// 					ty=TOUCH_Y();
// 					tx=TOUCH_X();
// 					GUI_DispDecAt( tx ,120,110,4);
// 					GUI_DispDecAt( ty ,230,110,4);			
// 					ty=GUI_TOUCH_X_MeasureY();
// 					tx=GUI_TOUCH_X_MeasureX();
// 					GUI_DispDecAt( tx ,120,110,4);
// 					GUI_DispDecAt( ty ,230,110,4);
				}
				
				goto tiky_start;
			}
			if(i%3==0)
			{
				TIM_Cmd(TIM2, ENABLE);
				if(menu_3_lock==0)ucGUI_Practice_PS2();
				else ucGUI_Practice();
				TIM_Cmd(TIM2, DISABLE);
				goto tiky_start;
			}
		}
	}
	//======================================================================================================
	
// 	GUI_SetBkColor(GUI_MAGENTA);
//  GUI_SetColor(GUI_WHITE);
	display_picture("Timer1F.bmp");
  GUI_SetFont(&GUI_Font24_ASCII);
  GUI_DispStringHCenterAt("Waite ......", 160, 108);
	ADC_Configuration();
	RTC_main();
	
	while(1)
	{
    Lcd_Clear(BLUE);
	  display_picture("sys1.bmp");
	  main_menu(&id,1);

	  switch(id)
	  {
		case 0://系统功能
         menu_3_lock=1; 
         while(menu_3_lock)
	  		 {
             	Lcd_Clear(0x780F);
             	display_picture("sys5.bmp");	
							main_menu(&id,3);
							switch(id)
	         	{
									case 0://删除所有PIC?.bmp文件
											Del_All_bmp("\\");
												break;

									case 1://时间设置
											Lcd_Clear(MAGENTA);
											display_picture("sys10.bmp");
											Set_Time_Date();
												break;

									case 2:
										 ucGUI_Practice();
										 //Oscilloscope();
										 //Delay(300);
												break;

									case 3://退出
										 menu_3_lock=0;
												break;

									default:
												break;
      			}  
			 }
		        break;

		case 1://浏览图片
		   		Lcd_Clear(GREEN);
					scan_menu(&id);
		        break;

		case 2: display_picture("sys8.bmp");
				f_mount(0, &fs);
   			f_open(&fsrc,"st1616.bin", FA_OPEN_EXISTING | FA_READ);
				GPS();
		        break;

		case 3://布防摄像头
			 	OV7670_main();
		        break;
		default:break;
      }
	}
}



/******************* (C) COPYRIGHT 2007 STMicroelectronics *****END OF FILE****/

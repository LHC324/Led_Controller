/****************************************************************************
*
* 文件名: main.c
* 内容简述:	该例程实现读写SD卡文件的功能。移植了FatFS文件系统。
*	操作说明：
	(1) 请接上串口线，打开windows的串口工具，比如超级终端。
	(2) 输入字符1，打印SD根目录下的文件和文件夹列表。
	(3) 输入字符2，在SD卡根目录下创建一个文件，文件名为 blkeji.txt
			并且向该文件写入一个字符串。
	(4) 输入字符3，打开SD卡根目录下的blkeji.txt文件，读出其内容，打印到串口。
*
*
*/

/*	   

	这个例程中的函数用到了较多的局部变量，因此缺省的堆栈不够用。
	需要调整大一些。
	
	修改 startup_stm32f10x_hd.s 文件
	以前为 ：Stack_Size      EQU     0x00000400
	现在为 ：Stack_Size      EQU     0x00001000


*/


#include <stdio.h>
#include "stm32f10x.h"
#include "systick.h"
#include "usart_printf.h"
#include "sdcard.h"
#include "ff.h"
#include "LCD.h"
#define EXAMPLE_NAME	"SDIO FatFS Demo"
#define EXAMPLE_DATE	"2011-05-15"

static void InitBoard(void);
static void DispLogo(void);

void ViewRootDir(void);
void CreatNewFile(void);
void ReadFileData(void);
void DispMenu(void);

// #include "ttr.h"
// #include "scenery_A.h"
// #include "scenery_B.h"
// #include "mm.h"

static void Button_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    
    /* config tft back_light gpio base on the PT4101 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;		
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/*******************************************************************************
*	函数名：main
*	功  能：用户程序入口
*	输  入: 无
*	输  出: 无
*/
int main(void)
{
	char cmd;
	unsigned int i=30001,flag=1;
	InitBoard();	/* 为了是main函数看起来更简洁些，我们将初始化的代码封装到这个函数 */
	LCD_GPIO_Config();
// 	DispLogo();		/* 显示例程Logo */
	
// 	Button_GPIO_Config();
// 	SD_Init();
// 	test_color();
// 	LCD_Fill_Pic(0,0,240,320, gImage_ttr);
	SPI1_Init();
	Lcd_Initialize();
	WriteComm(0x36);
	WriteData(0x10);//设置为横屏的显示方向
	LCD_PutString(30,30,"支持横竖屏",YELLOW,RED,0);
// TP_Init();
	WriteComm(0x36);//这个寄存器是专门用来设置显示方向的
	WriteData(0x60);//设置为横屏的显示方向
	LCD_PutString(80,20,"１８６１７０５６０６６",YELLOW,RED,1);
	Lcd_ColorBox(100,100,20,20,Yellow);
	Lcd_ColorBox(140,70,20,20,Yellow);
		while(1);
	{
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0){i++;flag=1;}
		if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)==0){i--;flag=1;}
		if(flag==1)
		{
			switch(i%15)
			{
			case 0:
				display_picture("T35_00.BMP");	
				break;	
			case 1:
// 				LCD_Fill_Pic(0,0,176,220, gImage_scenery_A);
				display_picture("T35_01.BMP");
				break;
			case 2:
// 				LCD_Fill_Pic(0,0,176,220, gImage_scenery_B);
				display_picture("T35_02.BMP");
				break;
			case 3:
// 				LCD_Fill_Pic(0,0,176,220, gImage_mm);
				display_picture("T35_03.BMP");
				break;
			case 4:
				display_picture("T35_04.BMP");	
				break;
			case 5:
				display_picture("T35_05.BMP");	
				break;
			case 6:
				display_picture("T30_01.BMP");	
				break;
			case 7:
				display_picture("T35_06.BMP");	
				break;
			case 8:
				display_picture("T35_07.BMP");	
				break;
			case 9:
				display_picture("T35_08.BMP");	
				break;
			case 10:
				display_picture("T35_09.BMP");	
				break;
			case 11:
				display_picture("T35_10.BMP");	
				break;
			case 12:
				display_picture("MM.BMP");	
				break;
			case 13:
				display_picture("T30_02.bmp");	
				break;
			case 14:
				display_picture("风景.bmp");	
				break;
			}		
			flag=0;		
		}
	}
	DispMenu();/* 打印命令列表，用户可以通过串口操作指令 */
	while(1)
	{
		cmd = getchar();
		switch (cmd)
		{
			case '1':
				printf("【1 - ViewRootDir】\r\n");
				ViewRootDir();		/* 显示SD卡根目录下的文件名 */
				break;

			case '2':
				printf("【2 - CreatNewFile】\r\n");
				CreatNewFile();		/* 创建一个新文件,写入一个字符串 */
				break;

			case '3':
				printf("【3 - ReadFileData】\r\n");
				ReadFileData();		/* 读取根目录下blkeji.txt的内容 */
				break;

			default:
				DispMenu();
				break;
		}
	}
	
}

/*******************************************************************************
*	函数名：ViewRootDir
*	功  能：显示SD卡根目录下的文件名
*	输  入: 无
*	输  出: 无
*/
void DispMenu(void)
{
	printf("\r\n*******************************************\r\n");
	printf("Please Select Command\r\n");
	printf("1 - Display Root Directory Files\r\n");
	printf("2 - Create A New File\r\n");
	printf("3 - Read File Data\r\n");
}

/*******************************************************************************
*	函数名：ViewRootDir
*	功  能：显示SD卡根目录下的文件名
*	输  入: 无
*	输  出: 无
*/
void ViewRootDir(void)
{
	/* 本函数使用的局部变量占用较多，请修改启动文件，保证堆栈空间够用 */
	FRESULT result;
	FATFS fs;
	DIR DirInf;  
	FILINFO FileInf;
	
	uint8_t tmpStr[20];
	uint32_t cnt = 0;
	
 	/* 挂载文件系统 */
	result = f_mount(0, &fs);			/* Mount a logical drive */
	if (result != FR_OK)
	{
		printf("FileSystem Mounted Failed (%d)\r\n", result);
	}

	/* 打开根文件夹 */
	result = f_opendir(&DirInf, "/"); /* 如果不带参数，则从当前目录开始 */
	if (result != FR_OK) 
	{
		printf("Root Directory is Open Error (%d)\r\n", result);
		return;
	}

	/* 读取当前文件夹下的文件和目录 */
	printf("Name\t\t\tTyepe\t\t\tSize\r\n");
	for (cnt = 0; ;cnt++) 
	{
		result = f_readdir(&DirInf,&FileInf); 		/* 读取目录项，索引会自动下移 */
		if (result != FR_OK || FileInf.fname[0] == 0)
		{
			break;
		}
		
		if (FileInf.fname[0] == '.')
		{
			continue;
		}
		printf("%s\t\t", FileInf.fname);
		if (FileInf.fattrib == AM_DIR)
		{
			printf("Directory\t");
		} 
		else 
		{
			printf("File\t\t");
		}
		printf("%d\r\n", FileInf.fsize);
		sprintf((char *)tmpStr, "%d", FileInf.fsize);
	}

	/* 卸载文件系统 */
	f_mount(0, NULL);	
}

/*******************************************************************************
*	函数名：CreatNewFile
*	功  能：在SD卡创建一个新文件，文件内容填写“www.blkeji.com”
*	输  入: 无
*	输  出: 无
*/
void CreatNewFile(void)
{
	/* 本函数使用的局部变量占用较多，请修改启动文件，保证堆栈空间够用 */
	FRESULT result;
	FATFS fs;
	FIL file;
	DIR DirInf;  
	uint32_t bw;
	
 	/* 挂载文件系统 */
	result = f_mount(0, &fs);			/* Mount a logical drive */
	if (result != FR_OK)
	{
		printf("FileSystem Mounted Failed (%d)\r\n", result);
	}

	/* 打开根文件夹 */
	result = f_opendir(&DirInf, "/"); /* 如果不带参数，则从当前目录开始 */
	if (result != FR_OK) 
	{
		printf("Root Directory is Open Error (%d)\r\n", result);
		return;
	}

	/* 打开文件 */
	result = f_open(&file, "blkeji.txt", FA_CREATE_ALWAYS | FA_WRITE);
	
	/* 写一串数据 */
	result = f_write(&file, "FatFS Write Demo \r\n www.blkeji.com \r\n", 34, &bw);	
	if (result == FR_OK)
	{
		printf("blkeji.txt File Write Success\r\n");
	}
	else
	{
		printf("blkeji.txt File Write Failed");
	}
	
	/* 关闭文件*/
	f_close(&file);
 	
	/* 卸载文件系统 */
	f_mount(0, NULL);	
}

/*******************************************************************************
*	函数名：ReadFileData
*	功  能：读取指定文件前128个字符，并打印到串口。
*	输  入: 无
*	输  出: 无
*/
void ReadFileData(void)
{
	/* 本函数使用的局部变量占用较多，请修改启动文件，保证堆栈空间够用 */
	FRESULT result;
	FATFS fs;
	FIL file;
	DIR DirInf;  
	uint32_t bw;
	char buf[128];
	
 	/* 挂载文件系统 */
	result = f_mount(0, &fs);			/* Mount a logical drive */
	if (result != FR_OK)
	{
		printf("FileSystem Mounted Failed (%d)\r\n", result);
	}

	/* 打开根文件夹 */
	result = f_opendir(&DirInf, "/"); /* 如果不带参数，则从当前目录开始 */
	if (result != FR_OK) 
	{
		printf("Root Directory is Open Error (%d)\r\n", result);
		return;
	}

	/* 打开文件 */
	result = f_open(&file, "blkeji.txt", FA_OPEN_EXISTING | FA_READ);
	if (result !=  FR_OK)
	{
		printf("Don't Find File : blkeji.txt\r\n");
		return;		
	}

	/* 读取文件 */
	result = f_read(&file, &buf, sizeof(buf) - 1, &bw);
	if (bw > 0)
	{
		buf[bw] = 0;
		printf("\r\nblkeji.txt content : \r\n%s\r\n", buf);
	}
	else
	{
		printf("\r\nblkeji.txt content : \r\n");		
	}
	
	/* 关闭文件*/
	f_close(&file);
 	
	/* 卸载文件系统 */
	f_mount(0, NULL);
}

/*******************************************************************************
	函数名：NVIC_Configuration
	输  入:
	输  出:
	功能说明：配置SDIO中断
*/
void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitStructure.NVIC_IRQChannel = SDIO_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

/*******************************************************************************
	函数名：GPIO_Configuration
	输  入:
	输  出:
	功能说明：配置4个LED为输出口线

	LED口线分配：
	LED0 : PE0  (输出0点亮)
	LED1 : PE1  (输出0点亮)
	LED2 : PE2  (输出0点亮)
	LED3 : PE3  (输出0点亮)

*/
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* 第1步：打开GPIOA GPIOC GPIOD GPIOE GPIOF GPIOG的时钟
	   注意：这个地方可以一次性全打开
	*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC
			| RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE | RCC_APB2Periph_GPIOF | RCC_APB2Periph_GPIOG,
				ENABLE);

	/* 第3步：配置所有的LED指示灯GPIO为推挽输出模式 */
	/* 由于将GPIO设置为输出时，GPIO输出寄存器的值缺省是0，因此会驱动LED点亮
		这是我不希望的，因此在改变GPIO为输出前，先修改输出寄存器的值为1 */
	GPIO_SetBits(GPIOE,  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

/*******************************************************************************
	函数名：InitBoard
	输  入:
	输  出:
	功能说明：初始化硬件设备
*/
static void InitBoard(void)
{
	/*
		这个函数是ST库中的函数，函数实体在
		Libraries\CMSIS\Core\CM3\system_stm32f10x.c

		配置内部Flash接口，初始化PLL，配置系统频率
		系统时钟缺省配置为72MHz，你如果需要更改，则需要去修改相关的头文件中的宏定义
	 */
	SystemInit();

	/* 配置LED GPIO */
// 	GPIO_Configuration();

	/* 配置串口 */
	USART_Configuration();

	/* 配置systic作为1ms中断,这个函数在
	\Libraries\CMSIS\Core\CM3\core_cm3.h */
// 	SysTick_Config(SystemFrequency / 1000);
	
	/* 配置中断系统 */
	NVIC_Configuration();
}

/*******************************************************************************
	函数名: DispLogo
	输  入:
	输  出:
	功能说明：显示例程Logo (通过串口打印到PC机的超级终端显示)
*/
static void DispLogo(void)
{
	/* 通过串口输出例程名和更新日期 */
	PrintfLogo(EXAMPLE_NAME, EXAMPLE_DATE);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

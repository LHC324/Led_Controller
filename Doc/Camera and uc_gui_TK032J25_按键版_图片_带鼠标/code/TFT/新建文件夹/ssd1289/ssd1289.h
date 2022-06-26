/****************************************************************************
* 文件名：LCMDRV.H
* 功能：MG12864图形液晶模块驱动程序。使用LPC2131的GPIO口控制操作。(头文件)
*       用于ZLG/GUI用户图形界面。
*  
*  作者：黄绍斌
*  日期：2005/3/7
****************************************************************************/
#ifndef  _SSD1289_H_
#define  _SSD1289_H_ 
#include "stm32f10x_lib.h"
//#include "stm32f10x_it.h" 
//#include "config.h"
/* 定义颜色数据类型(可以是数据结构) */
#define  TCOLOR	  uint16 		//自行修改，原来是	uint8 

/* 定义LCM像素数宏 */
#define  GUI_LCM_XMAX		320				//自行修改			/* 定义液晶x轴的像素数 */
#define  GUI_LCM_YMAX		240				//自行修改
						/* 定义液晶y轴的像素数 */


#define   BLACK                0x0000                // 黑色：    0,   0,   0 //
#define   BLUE                 0x001F                // 蓝色：    0,   0, 255 //
#define   GREEN                0x07E0                // 绿色：    0, 255,   0 //
#define   CYAN                 0x07FF                // 青色：    0, 255, 255 //
#define   RED                  0xF800                // 红色：  255,   0,   0 //
#define   MAGENTA              0xF81F                // 品红：  255,   0, 255 //
#define   YELLOW               0xFFE0                // 黄色：  255, 255, 0   //
#define   WHITE                0xFFFF                // 白色：  255, 255, 255 //
#define   NAVY                 0x000F                // 深蓝色：  0,   0, 128 //
#define   DGREEN               0x03E0                // 深绿色：  0, 128,   0 //
#define   DCYAN                0x03EF                // 深青色：  0, 128, 128 //
#define   MAROON               0x7800                // 深红色：128,   0,   0 //
#define   PURPLE               0x780F                // 紫色：  128,   0, 128 //
#define   OLIVE                0x7BE0                // 橄榄绿：128, 128,   0 //
#define   LGRAY                0xC618                // 灰白色：192, 192, 192 //
#define   DGRAY                0x7BEF                // 深灰色：128, 128, 128 //


//硬件相关的子函数
#define Set_Cs  GPIO_SetBits(GPIOD,GPIO_Pin_14);
#define Clr_Cs  GPIO_ResetBits(GPIOD,GPIO_Pin_14);

#define Set_Rs  GPIO_SetBits(GPIOD,GPIO_Pin_13);
#define Clr_Rs  GPIO_ResetBits(GPIOD,GPIO_Pin_13);

#define Set_nWr GPIO_SetBits(GPIOD,GPIO_Pin_12);
#define Clr_nWr GPIO_ResetBits(GPIOD,GPIO_Pin_12);

#define Set_nRd GPIO_SetBits(GPIOD,GPIO_Pin_11);
#define Clr_nRd GPIO_ResetBits(GPIOD,GPIO_Pin_11);

#define Lcd_Light_ON   GPIO_SetBits(GPIOD,GPIO_Pin_10);
#define Lcd_Light_OFF  GPIO_ResetBits(GPIOD,GPIO_Pin_10);

#define Set_Rst GPIO_SetBits(GPIOD,GPIO_Pin_9);
#define Clr_Rst GPIO_ResetBits(GPIOD,GPIO_Pin_9);


#define Lcd_CS_low      GPIO_ResetBits(GPIOD,GPIO_Pin_14)	//片选
#define Lcd_CS_high     GPIO_SetBits(GPIOD,GPIO_Pin_14)

#define Lcd_RS_low      GPIO_ResetBits(GPIOD,GPIO_Pin_13)	
#define Lcd_RS_high     GPIO_SetBits(GPIOD,GPIO_Pin_13)

#define Lcd_WR_low      GPIO_ResetBits(GPIOD,GPIO_Pin_12)	//写
#define Lcd_WR_high     GPIO_SetBits(GPIOD,GPIO_Pin_12)	
      
#define Lcd_rd_low      GPIO_ResetBits(GPIOD,GPIO_Pin_11)	//读数
#define Lcd_rd_high     GPIO_SetBits(GPIOD,GPIO_Pin_11)	

#define Lcd_res_low      GPIO_ResetBits(GPIOD,GPIO_Pin_9)
#define Lcd_res_high     GPIO_SetBits(GPIOD,GPIO_Pin_9)

typedef unsigned char  uint8;                   /* defined for unsigned 8-bits integer variable 	无符号8位整型变量  */
typedef signed   char  int8;                    /* defined for signed 8-bits integer variable		有符号8位整型变量  */
typedef unsigned short uint16;                  /* defined for unsigned 16-bits integer variable 	无符号16位整型变量 */
typedef signed   short int16;                   /* defined for signed 16-bits integer variable 		有符号16位整型变量 */
typedef unsigned int   uint32;                  /* defined for unsigned 32-bits integer variable 	无符号32位整型变量 */
typedef signed   int   int32;                   /* defined for signed 32-bits integer variable 		有符号32位整型变量 */
typedef float          fp32;                    /* single precision floating point variable (32bits) 单精度浮点数（32位长度） */
typedef double         fp64;                    /* double precision floating point variable (64bits) 双精度浮点数（64位长度） */


void ssd1289_Configuration(void);
void ssd1289_LCM_DispIni(void);
uint16 ssd1289_GetPoint(uint16 x,uint16 y);
void ssd1289_Set_ramaddr(uint16 x,uint16 y);
void  ssd1289_GUI_FillSCR(uint16 dat);
void SSD1289_picture_start(void);
//void LCD_SetArea( uint16 x0, uint16 y0, uint16 x1, uint16 y1 );
void  ssd1289_GUI_Fill(uint16 x0,uint16 y0 ,uint16 x1,uint16 y1 ,uint16 clor);
/****************************************************************************
* 名称：GUI_Initialize()
* 功能：初始化GUI，包括初始化显示缓冲区，初始化LCM并清屏。
* 入口参数：无
* 出口参数：无
* 说明：用户根据LCM的实际情况编写此函数。
****************************************************************************/
extern void  ssd1289_GUI_Initialize(void);


/****************************************************************************
* 名称：GUI_FillSCR()
* 功能：全屏填充。直接使用数据填充显示缓冲区。
* 入口参数：dat		填充的数据
* 出口参数：无
* 说明：用户根据LCM的实际情况编写此函数。
****************************************************************************/
extern void  ssd1289_GUI_FillSCR(TCOLOR dat);


/****************************************************************************
* 名称：GUI_ClearSCR()
* 功能：清屏。
* 入口参数：无
* 出口参数：无
* 说明：用户根据LCM的实际情况编写此函数。
****************************************************************************/
//extern void  GUI_ClearSCR(void);
#define  ssd1289_GUI_ClearSCR()		ssd1289_GUI_FillSCR(0x00)


/****************************************************************************
* 名称：GUI_Point()
* 功能：在指定位置上画点。
* 入口参数： x		指定点所在列的位置
*            y		指定点所在行的位置
*            color	显示颜色(对于黑白色LCM，为0时灭，为1时显示)
* 出口参数：返回值为1时表示操作成功，为0时表示操作失败。(操作失败原因是指定地址超出有
*          效范围)
* 说明：用户根据LCM的实际情况编写此函数。
****************************************************************************/
extern uint8  ssd1289_GUI_Point(uint16 x, uint16 y, TCOLOR color);


/****************************************************************************
* 名称：GUI_ReadPoint()
* 功能：读取指定点的颜色。
* 入口参数：x		指定点所在列的位置
*           y		指定点所在行的位置
*           ret     保存颜色值的指针
* 出口参数：返回0表示指定地址超出缓冲区范围
* 说明：对于单色，设置ret的d0位为1或0，4级灰度则为d0、d1有效，8位RGB则d0--d7有效，
*      RGB结构则R、G、B变量有效。
****************************************************************************/
extern uint8  ssd1289_GUI_ReadPoint(uint16 x, uint16 y, TCOLOR *ret);



/****************************************************************************
* 名称：GUI_HLine()
* 功能：画水平线。
* 入口参数： x0		水平线起点所在列的位置
*           y0		水平线起点所在行的位置
*           x1      水平线终点所在列的位置
*           color	显示颜色(对于黑白色LCM，为0时灭，为1时显示)
* 出口参数：无
* 说明：对于单色、4级灰度的液晶，可通过修改此函数作图提高速度，如单色LCM，可以一次更
*      新8个点，而不需要一个点一个点的写到LCM中。
****************************************************************************/
extern void  ssd1289_GUI_HLine(uint16 x0, uint16 y0, uint16 x1, TCOLOR color);


/****************************************************************************
* 名称：GUI_RLine()
* 功能：画垂直线。
* 入口参数： x0		垂直线起点所在列的位置
*           y0		垂直线起点所在行的位置
*           y1      垂直线终点所在行的位置
*           color	显示颜色
* 出口参数：无
* 说明：对于单色、4级灰度的液晶，可通过修改此函数作图提高速度，如单色LCM，可以一次更
*      新8个点，而不需要一个点一个点的写到LCM中。
****************************************************************************/
extern void  ssd1289_GUI_RLine(uint16 x0, uint16 y0, uint16 y1, TCOLOR color);




/****************************************************************************
* 名称：GUI_CmpColor()
* 功能：判断颜色值是否一致。
* 入口参数：color1		颜色值1
*		   color2		颜色值2
* 出口参数：返回1表示相同，返回0表示不相同。
* 说明：由于颜色类型TCOLOR可以是结构类型，所以需要用户编写比较函数。
****************************************************************************/
//extern int  GUI_CmpColor(TCOLOR color1, TCOLOR color2);
#define  ssd1289_GUI_CmpColor(color1, color2)	( color1 == color2 )

/****************************************************************************
* 名称：GUI_CopyColor()
* 功能：颜色值复制。
* 入口参数：color1		目标颜色变量
*		   color2		源颜色变量
* 出口参数：无
* 说明：由于颜色类型TCOLOR可以是结构类型，所以需要用户编写复制函数。
****************************************************************************/
//extern void  GUI_CopyColor(TCOLOR *color1, TCOLOR color2);
#define  ssd1289_GUI_CopyColor(color1, color2) 	*color1 = color2


#endif

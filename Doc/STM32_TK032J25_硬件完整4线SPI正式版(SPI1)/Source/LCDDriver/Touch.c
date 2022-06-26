						 //=========================================================================================================================================
#include <string.h>
#include "Touch.h"
#include "stm32f10x.h"
#define TP_DOUT		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)//( IOPIN1 & MASK_DOUT )	//数据输入
//#define TP_BUSY		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)//( IOPIN1 & MASK_DOUT )	//数据输入
//#define TP_INT_IN    //( IOPIN1 & MASK_INT )
void GUI_TOUCH_X_ActivateX(void) {}
void GUI_TOUCH_X_ActivateY(void) {}

//====================================================================================
void TP_Init(void)
{
  //  IODIR1 = IODIR1 | MASK_CS | MASK_DCLK | MASK_DIN;
  	GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_13| GPIO_Pin_15| GPIO_Pin_12;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		 //推挽输出
  	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
  	GPIO_Init(GPIOB, &GPIO_InitStructure);
   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   //上拉输入
	GPIO_Init(GPIOD,&GPIO_InitStructure);
		
}
//====================================================================================
static void WR_CMD (unsigned char cmd) 
{
    unsigned char buf;
    unsigned char i;
    TP_CS(1);
    TP_DIN(0);
    TP_DCLK(0);
    TP_CS(0);
    for(i=0;i<8;i++) 
    {
        buf=(cmd>>(7-i))&0x1;
        TP_DIN(buf);
        //Delayus(5);
        TP_DCLK(1);
        //Delayus(5);
        TP_DCLK(0);
    }
}
//====================================================================================
static unsigned short RD_AD(void) 
{
    unsigned short buf=0,temp;
    unsigned char i;
    TP_DIN(0);
    TP_DCLK(1);
    for(i=0;i<12;i++) 
    {
        TP_DCLK(0);          
        temp= (TP_DOUT) ? 1:0;
        buf|=(temp<<(11-i));
        //Delayus(5);
        TP_DCLK(1);
    }
    TP_CS(1);
    buf&=0x0fff;
    return(buf);
}
//====================================================================================
 int GUI_TOUCH_X_MeasureX(void) 
{ 

	 int i[7],temp;
	u8 cou=0,k=0;
   
	while(cou<7)	//循环读数7次
	{	
		WR_CMD(CHX);  	  
		i[cou]=RD_AD();
		cou++;  
	}
        //将数据升序排列
	for(k=0;k<6;k++)
	{	  
		for(cou=0;cou<6-k;cou++)
		{
			if(i[cou]>i[cou+1])
			{
				temp=i[cou+1];
				i[cou+1]=i[cou];
				i[cou]=temp;
			}  
		}
	}
	if(i[4]-i[2]>80)return 0;	    		 	 		  
    else return i[3];	   
}
//====================================================================================
 int GUI_TOUCH_X_MeasureY(void) 
{ 
     int i[7],temp;
	u8 cou=0,k=0;
	while(cou<7)	//循环读数7次
	{	
		WR_CMD(CHY);  	  
		i[cou]=RD_AD();
		cou++;  
	}
        //将数据升序排列
	for(k=0;k<6;k++)
	{	  
		for(cou=0;cou<6-k;cou++)
		{
			if(i[cou]>i[cou+1])
			{
				temp=i[cou+1];
				i[cou+1]=i[cou];
				i[cou]=temp;
			}  
		}
	}	    		 	 		  
    if(i[3]-i[0]>80||i[6]-i[3]>80)return 0;	    		 	 		  
    else return i[3];   
}
//====================================================================================
void TP_GetAdXY(unsigned int *x,unsigned int *y) 
{
    unsigned int adx,ady;
    adx=GUI_TOUCH_X_MeasureX();
    ady=GUI_TOUCH_X_MeasureY();
    *x=adx;
    *y=ady;
}

#include "stm32f10x.h"
#include "SysConfig.h"
#include "GUI_Private.h"
#include "touch.h"
#include "gui.h"
#include "GPS_tiky.h"
#include "ili9325.h"
#define  GPS_Y 16*5
#include "My_FF.h"
extern FATFS fs; 
extern FIL fsrc;
extern UINT br;//UINT  extern UINT br;
/*
1、Global Positioning System Fix Data（GGA）GPS定位信息 
$GPGGA,<1>,<2>,<3>,<4>,<5>,<6>,<7>,<8>,<9>,M,<10>,M,<11>,<12>*hh<CR><LF> 
$GPGGA,050458.000,2459.8991,N,10242.8698,E,1,05,1.20,1885.0,M,-32.2,M,,*45
<1> UTC时间，hhmmss（时分秒）格式 
<2> 纬度ddmm.mmmm（度分）格式（前面的0也将被传输） 
<3> 纬度半球N（北半球）或S（南半球） 
<4> 经度dddmm.mmmm（度分）格式（前面的0也将被传输） 
<5> 经度半球E（东经）或W（西经） 
<6> GPS状态：0=未定位，1=非差分定位，2=差分定位，6=正在估算 
<7> 正在使用解算位置的卫星数量（00~12）（前面的0也将被传输） 
<8> HDOP水平精度因子（0.5~99.9） 
<9> 海拔高度（-9999.9~99999.9） 
<10> 地球椭球面相对大地水准面的高度 
<11> 差分时间（从最近一次接收到差分信号开始的秒数，如果不是差分定位将为空） 
<12> 差分站ID号0000~1023（前面的0也将被传输，如果不是差分定位将为空）
*/
void GPS_Char(char Char_num,char *p)
{
char a;
unsigned int b=0;
for(a=0;(a<Char_num)&&(b<65535); )
	{
	if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET) 
		{
		*(p+a)=USART1->DR;
		if(*(p+a)==','||*(p+a)=='*'){*(p+a)='\0';return;}
		else a++;
		}
	b++;
	}
}


char Local_time;
void GPS_RX(void)
{
int tx=800,ty=800,angle,r;
unsigned char s[3];
unsigned char gh[6];
char a,b;
unsigned char	GPS_menu=1;

char G_M_V;//GPGGA GPRMC GPGSV
char comma_counter=1;
struct
{
	char GPS_Time[12];
	char Latitude[11];//纬度
	char N_S[3];
	char Longitude[12];//经度
	char E_W[3];
	char GPS_State[3];
	char star_num[4];
	char HDOP[6];
	char Height[9];
	char Speed[7];
	char Course[8];
	char UTC_Date[8];
	char NULL_Char[12];
	char GPGSV_num[3];//本句编号
	char GPGSV_star[4];//可见卫星总数
	char GPGSV[12][11];//[编号]、[仰角]、[方位角]、[C/N]
	char GPGSA[17][3];
}GPS={0};
	while(1)
	{
	USART1->SR;
	if(USART1->DR=='$')	 // USART_ReceiveData(USART1)
		{ 
			G_M_V=0;
			for(a=0; a<6; )
				{  
				if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET) 
					{*(gh+a)=USART1->DR; a++;}
				if(gh[4]=='G') G_M_V=1;
				if(gh[4]=='M') G_M_V=2;
				if(gh[5]=='V') G_M_V=3;
				if(gh[4]=='S'&&gh[5]=='A') G_M_V=4;	
				}
			if(G_M_V>0)
				{	
					do
					{
					if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET)
						if(USART1->DR==',')a=100;
					}while(a==6);
					comma_counter=1;
						while(comma_counter<10)
						switch(comma_counter)
						{													  
							case 1:
								if(G_M_V<3)GPS_Char(11,GPS.GPS_Time);
								else GPS_Char(11,GPS.NULL_Char);
								comma_counter++;
								break;
							case 2:
								if(G_M_V==1)GPS_Char(10,GPS.Latitude);
								if(G_M_V==2)GPS_Char(11,GPS.NULL_Char);
								if(G_M_V==3){GPS_Char(2,GPS.GPGSV_num);GPS.GPGSV_num[0]=GPS.GPGSV_num[0]-'1';}
								if(G_M_V==4)GPS_Char(2,GPS.GPGSA[0]);//Fix mode
								comma_counter++;
								break;
							case 3:
								if(G_M_V==1)GPS_Char(2,GPS.N_S);
								if(G_M_V==2)GPS_Char(11,GPS.NULL_Char);
								if(G_M_V==3)
								{
									GPS_Char(3,GPS.GPGSV_star);
									GPS.GPGSV_star[0]=(GPS.GPGSV_star[0]-'0')*10+GPS.GPGSV_star[1]-'0';
								}
								if(G_M_V==4)
								{
									for(a=1;a<13;a++)
									GPS_Char(3,GPS.GPGSA[a]);
								}
								comma_counter++;
								break;
							case 4:
								if(G_M_V==1)GPS_Char(11,GPS.Longitude);
								if(G_M_V==2)GPS_Char(11,GPS.NULL_Char);
								if(G_M_V==3)//&&GPS.GPGSV_star[1]!='\0'
								{
									if(GPS.GPGSV_num[0]*4+1<=GPS.GPGSV_star[0])//本句第一个星
									{
									GPS_Char(3,&GPS.GPGSV[GPS.GPGSV_num[0]*4][0]);
									GPS_Char(3,&GPS.GPGSV[GPS.GPGSV_num[0]*4][2]);
									GPS_Char(4,&GPS.GPGSV[GPS.GPGSV_num[0]*4][4]);
									GPS_Char(3,&GPS.GPGSV[GPS.GPGSV_num[0]*4][7]);
									GPS.GPGSV[GPS.GPGSV_num[0]*4][10]=0;
// 									if(GPS.GPGSV[GPS.GPGSV_num[0]*4][2]=='-')
// 										GPS.GPGSV[GPS.GPGSV_num[0]*4][0]='\0';
									}
									else G_M_V=100;
									if(GPS.GPGSV_num[0]*4+2<=GPS.GPGSV_star[0])//本句第二个星
									{
									GPS_Char(3,&GPS.GPGSV[GPS.GPGSV_num[0]*4+1][0]);
									GPS_Char(3,&GPS.GPGSV[GPS.GPGSV_num[0]*4+1][2]);
									GPS_Char(4,&GPS.GPGSV[GPS.GPGSV_num[0]*4+1][4]);
									GPS_Char(3,&GPS.GPGSV[GPS.GPGSV_num[0]*4+1][7]);
									GPS.GPGSV[GPS.GPGSV_num[0]*4+1][10]=0;
// 									if(GPS.GPGSV[GPS.GPGSV_num[0]*4+1][2]=='-')
// 										GPS.GPGSV[GPS.GPGSV_num[0]*4+1][0]='\0';
									}
									else G_M_V=100;
									if(GPS.GPGSV_num[0]*4+3<=GPS.GPGSV_star[0])//本句第三个星
									{
									GPS_Char(3,&GPS.GPGSV[GPS.GPGSV_num[0]*4+2][0]);
									GPS_Char(3,&GPS.GPGSV[GPS.GPGSV_num[0]*4+2][2]);
									GPS_Char(4,&GPS.GPGSV[GPS.GPGSV_num[0]*4+2][4]);
									GPS_Char(3,&GPS.GPGSV[GPS.GPGSV_num[0]*4+2][7]);
									GPS.GPGSV[GPS.GPGSV_num[0]*4+2][10]=0;
// 									if(GPS.GPGSV[GPS.GPGSV_num[0]*4+2][2]=='-')
// 										GPS.GPGSV[GPS.GPGSV_num[0]*4+2][0]='\0';
									}
									else G_M_V=100;
									if(GPS.GPGSV_num[0]*4+4<=GPS.GPGSV_star[0])//本句第四个星
									{
									GPS_Char(3,&GPS.GPGSV[GPS.GPGSV_num[0]*4+3][0]);
									GPS_Char(3,&GPS.GPGSV[GPS.GPGSV_num[0]*4+3][2]);
									GPS_Char(4,&GPS.GPGSV[GPS.GPGSV_num[0]*4+3][4]);
									GPS_Char(3,&GPS.GPGSV[GPS.GPGSV_num[0]*4+3][7]);
									GPS.GPGSV[GPS.GPGSV_num[0]*4+3][10]=0;
// 									if(GPS.GPGSV[GPS.GPGSV_num[0]*4+3][2]=='-')
// 										GPS.GPGSV[GPS.GPGSV_num[0]*4+3][0]='\0';
									if(GPS.GPGSV_num[0]*4+4==GPS.GPGSV_star[0])G_M_V=100;//如果是最后一个，退出
									}
									else G_M_V=100;
									comma_counter=10;
								}
								comma_counter++;
								break;
							case 5:
								if(G_M_V==1)GPS_Char(2,GPS.E_W);
								if(G_M_V==2)GPS_Char(11,GPS.NULL_Char);
								comma_counter++;
								break;
							case 6:
								if(G_M_V==1)GPS_Char(2,GPS.GPS_State);
								if(G_M_V==2)GPS_Char(11,GPS.NULL_Char);
								comma_counter++;
								break;
							case 7://地面速率（000.0~999.9节，前面的0也将被传输
								if(G_M_V==1)GPS_Char(3,GPS.star_num);
								if(G_M_V==2)GPS_Char(6,GPS.Speed);
								comma_counter++;
								break;
							case 8:
								if(G_M_V==1)GPS_Char(5,GPS.HDOP);
								if(G_M_V==2)GPS_Char(7,GPS.Course);
								comma_counter++;
								break;
							case 9:
								if(G_M_V==1)GPS_Char(8,GPS.Height);
								if(G_M_V==2)GPS_Char(7,GPS.UTC_Date);
								comma_counter++;
								break;
							default:break;
						}	
			if(GPS_menu==1)
			{
				if(G_M_V==1)
				{
					//简单处理,适用于东八时区
					if(GPS.GPS_Time[0]!='\0')
					{
					Local_time=(GPS.GPS_Time[0]-'0')*10+GPS.GPS_Time[1]-'0';
					if(Local_time+8>23)s[1]=Local_time+8-24;
						else s[1]=Local_time+8;
					s[0]=s[1]/10+'0';
					s[1]=s[1]%10+'0';
					}
					s[2]='\0';
					Lcd_WriteChineseStringClarity(16*3,GPS_Y,0xFFE0,0,s,1);//时
					s[0]=GPS.GPS_Time[2];s[1]=GPS.GPS_Time[3];
					GUI_DispStringAt(s,16*4+8,GPS_Y);
// 					Lcd_WriteChineseStringClarity(16*4+8,GPS_Y,0xFFE0,0,s,1);//分
					s[0]=GPS.GPS_Time[4];s[1]=GPS.GPS_Time[5];					
					GUI_DispStringAt(s,16*6,GPS_Y);
// 					Lcd_WriteChineseStringClarity(16*6,GPS_Y,0xFFE0,0,s,1);//秒
					//Lcd_WriteChineseStringClarity(16*3+72,0,0xFFE0,0,&GPS.GPS_Time[7],1);//毫秒
					 
					if(GPS.N_S[0]=='N')	Lcd_WriteChineseStringClarity(0,16+GPS_Y+2,0xFFE0,0,"北",1);		
					else if(GPS.N_S[0]=='S') Lcd_WriteChineseStringClarity(0,16+GPS_Y+2,0xFFE0,0,"南",1);

					gh[0]=GPS.Latitude[0];
					gh[1]=GPS.Latitude[1];
					gh[2]=0xA1;
					gh[3]=0xE3;
					gh[4]='\0';
					Lcd_WriteChineseStringClarity(40+8,16+GPS_Y+2,0xFFE0,0,gh,1);
					gh[0]=GPS.Latitude[2];
					gh[1]=GPS.Latitude[3];
					gh[2]=0x27;
					gh[3]='\0';
					Lcd_WriteChineseStringClarity(40+8+24+8,16+GPS_Y+2,0xFFE0,0,gh,1);
					Lcd_WriteChineseStringClarity(40+8+24+24+8,16+GPS_Y+2,0xFFE0,0,&(GPS.Latitude[5]),1);
		
					if(GPS.E_W[0]=='E')	Lcd_WriteChineseStringClarity(0,32+GPS_Y+4,0xFFE0,0,"东",1);		
					else if(GPS.E_W[0]=='W') Lcd_WriteChineseStringClarity(0,32+GPS_Y+4,0xFFE0,0,"西",1);

					gh[0]=GPS.Longitude[0];
					gh[1]=GPS.Longitude[1];
					gh[2]=GPS.Longitude[2];
					gh[3]=0xA1;
					gh[4]=0xE3;
					gh[5]='\0';
					Lcd_WriteChineseStringClarity(40,32+GPS_Y+4,0xFFE0,0,gh,1);
					gh[0]=GPS.Longitude[3];
					gh[1]=GPS.Longitude[4];
					gh[2]=0x27;
					gh[3]='\0';
					Lcd_WriteChineseStringClarity(40+8*5,32+GPS_Y+4,0xFFE0,0,gh,1);
					Lcd_WriteChineseStringClarity(40+8*5+24,32+GPS_Y+4,0xFFE0,0,&(GPS.Longitude[6]),1);

					if(GPS.GPS_State[0]=='0')     Lcd_WriteChineseStringClarity(16*4,48+GPS_Y+6,0xFFE0,0,"未定位    ",1);
					else if(GPS.GPS_State[0]=='1')Lcd_WriteChineseStringClarity(16*4,48+GPS_Y+6,0xFFE0,0,"非差分定位",1);
					else if(GPS.GPS_State[0]=='2')Lcd_WriteChineseStringClarity(16*4,48+GPS_Y+6,0xFFE0,0,"差分定位  ",1);
					else if(GPS.GPS_State[0]=='6')Lcd_WriteChineseStringClarity(16*4,48+GPS_Y+6,0xFFE0,0,"正在估算  ",1);
		
					Lcd_WriteChineseStringClarity(16*8+8,64+GPS_Y+8,0xFFE0,0,GPS.star_num,1);
					Lcd_WriteChineseStringClarity(16*6+8,80+GPS_Y+10,0xFFE0,0,GPS.HDOP,1);
					Lcd_WriteChineseStringClarity(16*4+8,96+GPS_Y+12,0xFFE0,0,GPS.Height,1);
				}
			if(G_M_V==2)
				{
				Lcd_WriteChineseStringClarity(16*4+8,112+GPS_Y+14,0xFFE0,0,GPS.Speed,1);
				Lcd_WriteChineseStringClarity(16*4+8,128+GPS_Y+16,0xFFE0,0,GPS.Course,1);
				if(GPS.UTC_Date[0]!='\0')
					{
						if(Local_time>15)GPS.UTC_Date[1]++;
						s[0]=GPS.UTC_Date[4];s[1]=GPS.UTC_Date[5];//16*7+8+16*5
						Lcd_WriteChineseStringClarity(16*13,GPS_Y,0xFFE0,0,s,1);//y
						s[0]=GPS.UTC_Date[2];s[1]=GPS.UTC_Date[3];
						Lcd_WriteChineseStringClarity(16*13+24,GPS_Y,0xFFE0,0,s,1);//m
						s[0]=GPS.UTC_Date[0];s[1]=GPS.UTC_Date[1];
						Lcd_WriteChineseStringClarity(16*13+48,GPS_Y,0xFFE0,0,s,1);//d  
					}
				}
			}
			
				if(G_M_V==100)
				{		
					for(a=0;a<GPS.GPGSV_star[0];a++)
					{
						for(b=1;b<13;b++)
						{
							if(GPS.GPGSA[b][0]=='\0')break;
							if(GPS.GPGSV[a][0]==GPS.GPGSA[b][0])
								if(GPS.GPGSV[a][1]==GPS.GPGSA[b][1])
									GPS.GPGSV[a][10]=1;		
						}
					}
					if(GPS_menu==3)//柱状图
					{						
						Lcd_ColorBox(0,0,255,239,0);
						LCD_BKCOLORINDEX=0;
						LCD_COLORINDEX=0xffff;
						for(a=0;a<GPS.GPGSV_star[0];a++)
						{
							if(GPS.GPGSV[a][7]!='\0')
							{
								ty=((GPS.GPGSV[a][7]-'0')*10+GPS.GPGSV[a][8]-'0')<<2;
								if(GPS.GPGSV[a][10])
									Lcd_ColorBox(21*a,240-ty,19,ty,GREEN);
								else
									Lcd_ColorBox(21*a,240-ty,19,ty,BLUE);
								s[0]=GPS.GPGSV[a][0];
								s[1]=GPS.GPGSV[a][1];
								s[2]='\0'; 
								Lcd_WriteChineseStringClarity(21*a+2,220 ,0,0,s,0);
								s[0]=GPS.GPGSV[a][7];
								s[1]=GPS.GPGSV[a][8];
								GUI_SetFont(&GUI_Font8x16);
								GUI_DispStringAt(s,21*a+2,240-ty-16);//写星号
							}
						}
					}
					if(GPS_menu==4)
					{						
						Lcd_ColorBox(0,0,255,239,0);
						LCD_COLORINDEX=0xffff;				
						GUI_DrawCircle(124,120,119);
						GUI_DrawCircle(124,120, 60);
						for(a=0;a<GPS.GPGSV_star[0];a++)
						{
							if(GPS.GPGSV[GPS.GPGSV_num[0]*4+3][2]!='-')
							{
								r=90-((GPS.GPGSV[a][2]-'0')*10+GPS.GPGSV[a][3]-'0');//仰角 半径
								angle=((GPS.GPGSV[a][4]-'0')*100+(GPS.GPGSV[a][5]-'0')*10+GPS.GPGSV[a][6]-'0');//方位角 
								switch(angle/90)
								{
									case 0:
										tx=(r*sin_table[angle%90]*4)/3000;
										ty=(r*sin_table[90-angle%90]*4)/3000;
										tx=124+tx;
										ty=120-ty;
										break;
									case 1:
										tx=(r*sin_table[90-angle%90]*4)/3000;
										ty=(r*sin_table[angle%90]*4)/3000;
										tx=124+tx;
										ty=120+ty;
										break;
									case 2:
										tx=(r*sin_table[angle%90]*4)/3000;
										ty=(r*sin_table[90-angle%90]*4)/3000;
										tx=124-tx;
										ty=120+ty;
										break;
									case 3:
										tx=(r*sin_table[90-angle%90]*4)/3000;
										ty=(r*sin_table[angle%90]*4)/3000;
										tx=124-tx;
										ty=120-ty;
										break;
									default:break;
								}
								if(GPS.GPGSV[a][7]=='\0')
									LCD_COLORINDEX=LCD_BKCOLORINDEX=RED;
								if(GPS.GPGSV[a][7]!='\0')
									if(GPS.GPGSV[a][10])
									LCD_COLORINDEX=LCD_BKCOLORINDEX=GREEN;
									else LCD_COLORINDEX=LCD_BKCOLORINDEX=BLUE;
								GUI_FillEllipse(tx, ty, 14, 8);//画卫星椭圆
								if(LCD_COLORINDEX==GREEN)LCD_COLORINDEX=BLUE;
								else LCD_COLORINDEX=WHITE;
								s[0]=GPS.GPGSV[a][0];
								s[1]=GPS.GPGSV[a][1];
								s[2]='\0'; 
								GUI_SetFont(&GUI_Font6x8);
								GUI_DispStringAt(s,tx-5,ty-3);//写星号
							}					
						}
				  }	
				}
			}
		}
		
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)==0)
		{
		ty=TOUCH_Y();
		tx=TOUCH_X();
// 		GUI_DispDecAt( tx ,100,25,4);
// 		GUI_DispDecAt( ty ,160,25,4);			
// 		ty=GUI_TOUCH_X_MeasureY();
// 		tx=GUI_TOUCH_X_MeasureX();
// 		GUI_DispDecAt( tx ,100,5,4);
// 		GUI_DispDecAt( ty ,160,5,4);
	
		if(tx>16*16&&tx<320)	
		{
			if(ty>16*8&&ty<16*8+16)//纯文本
			{
				Lcd_Clear(0x0000);
				LCD_COLORINDEX=WHITE;
				LCD_BKCOLORINDEX=BLACK;
				GUI_SetFont(&GUI_Font8x16);
				r=b=0;
				while(1)
				{
					if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET) 
					{
						s[0]=USART1->DR;
						if((s[0]!='\r')&&(s[0]!='\n'))
						{
							GUI_DispCharAt(s[0],r,b);
							if(r<312)r+=8;
							else if(b<224)
								{
									b+=16;
									r=0;
								}
							else 
								{
									if(LCD_COLORINDEX==WHITE) LCD_COLORINDEX=YELLOW;
									else LCD_COLORINDEX=WHITE;
									r=b=0;
								}
						}
						else if(s[0]=='\r')
						{
							if(r<312)Lcd_ColorBox(r,b,320-r,16,0);
							if(b<224)
							{	
								b+=16;
								r=0;
							}
							else
							{
								if(LCD_COLORINDEX==WHITE) LCD_COLORINDEX=YELLOW;
								else LCD_COLORINDEX=WHITE;
								r=b=0;
							}
						}
					}
					if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)==0)
					{
						ty=TOUCH_Y();
						tx=TOUCH_X();
						if(tx>16*16&&tx<320&&ty>16*14&&ty<240) break;
					}
				}
				ty=16*6+1;
			}
			if(ty>16*6&&ty<16*6+16)
			{
				GPS_inf();
				GPS_menu=1;
				G_M_V=2;
			}
			if(ty>16*10&&ty<16*10+16)
			{
				Lcd_Clear(0x0000);
				GPS_menu=3;
				GPS_button(GPS_menu);
			}
			if(ty>16*12&&ty<16*12+16)
			{
				Lcd_Clear(0x0000);
				LCD_COLORINDEX=0xffff;
				LCD_BKCOLORINDEX=0xffff;
				GUI_DrawCircle(124,120,119);
				GUI_DrawCircle(124,120, 60);
				GPS_menu=4;
				GPS_button(GPS_menu);			
			}
			if(ty>16*14&&ty<240){Main_GPIO_Config();return;}
			while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)==0);
		}
		}
	}
}
void GPS_button(unsigned char i)
{
	unsigned int a,b,c,d;
	a=b=c=d=0xFFE0;
	switch (i)
	{
		case 1:
			a=BLUE;
			break;
		case 2:
			b=BLUE;
			break;
		case 3:
			c=BLUE;
			break;
		case 4:
			d=BLUE;
			break;
		default : break;
	}
	Lcd_WriteChineseStringClarity(16*16,16*6 ,a,0,">>信  息",0);
	Lcd_WriteChineseStringClarity(16*16,16*8 ,b,0,">>纯文本",0);
	Lcd_WriteChineseStringClarity(16*16,16*10,c,0,">>柱状图",0);
	Lcd_WriteChineseStringClarity(16*16,16*12,d,0,">>方位图",0);
	Lcd_WriteChineseStringClarity(16*16,16*14,0xFFE0,0,">>退  出",0);
}

void GPS_inf(void)
{
	display_picture("sys8.bmp");
	f_mount(0, &fs);
	f_open(&fsrc,"st1616.bin", FA_OPEN_EXISTING | FA_READ);
	Lcd_WriteChineseStringClarity(8*16,16*2,0xFFE0,0,"Tiky GPS",1);
	Lcd_WriteChineseStringClarity(0,0+GPS_Y,0xFFE0,0,"时间    :  :      日期  20  /  / ",1);
	Lcd_WriteChineseStringClarity(0,16+GPS_Y+2,0xFFE0,0,"北纬:",1);
	Lcd_WriteChineseStringClarity(0,32+GPS_Y+4,0xFFE0,0,"东经:",1);
	Lcd_WriteChineseStringClarity(0,48+GPS_Y+6,0xFFE0,0,"GPS状态:",1);
	Lcd_WriteChineseStringClarity(0,64+GPS_Y+8,0xFFE0,0,"正在使用卫星数量:",1);
	Lcd_WriteChineseStringClarity(0,80+GPS_Y+10,0xFFE0,0,"水平精度因子:",1);
	Lcd_WriteChineseStringClarity(0, 96+GPS_Y+12,0xFFE0,0,"海拔高度:      米",1);
	Lcd_WriteChineseStringClarity(0,112+GPS_Y+14,0xFFE0,0,"航行速率:      节",1);
	Lcd_WriteChineseStringClarity(0,128+GPS_Y+16,0xFFE0,0,"地面航向:      度",1);
	GPS_button(1); 
	GUI_SetFont(&GUI_Font8x16);
	LCD_COLORINDEX=0xFFE0;
	LCD_BKCOLORINDEX=0;
}
/*
4、Recommended Minimum Specific GPS/TRANSIT Data（RMC）推荐定位信息 
$GPRMC,<1>,<2>,<3>,<4>,<5>,<6>,<7>,<8>,<9>,<10>,<11>,<12>*hh<CR><LF> 
$GPRMC,050459.000,A,2459.8990,N,10242.8698,E,0.67,158.73,190808,,,A*6A
<1> UTC时间，hhmmss（时分秒）格式 
<2> 定位状态，A=有效定位，V=无效定位 
<3> 纬度ddmm.mmmm（度分）格式（前面的0也将被传输） 
<4> 纬度半球N（北半球）或S（南半球） 
<5> 经度dddmm.mmmm（度分）格式（前面的0也将被传输） 
<6> 经度半球E（东经）或W（西经） 
<7> 地面速率（000.0~999.9节，前面的0也将被传输） 
<8> 地面航向（000.0~359.9度，以真北为参考基准，前面的0也将被传输） 
<9> UTC日期，ddmmyy（日月年）格式 
<10> 磁偏角（000.0~180.0度，前面的0也将被传输） 
<11> 磁偏角方向，E（东）或W（西） 
<12> 模式指示（仅NMEA0183 3.00版本输出，A=自主定位，D=差分，E=估算，N=数据无效） 
*/

// void GPS(void)
// {
// unsigned char tex[101]=0;
// char a=0;
// 	while(1)
// 	{
// 		USART_GetFlagStatus(USART1, USART_FLAG_RXNE);
// 		if(USART1->DR=='$')	
// 			{ 
// 			for(a=0; a<100; )
// 				{  
// 				if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET) 
// 					{tex[a]=USART_ReceiveData(USART1); a++;}
// 				}
// 			}
// 			a=0;
// 		Lcd_WriteChineseStringClarity(0,0,0xFFE0,0,tex,1);
// 	}
// }
void GPS(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_1);
	GPS_inf();
	GPS_RX();
	LCD_BKCOLORINDEX=WHITE;
	LCD_COLORINDEX=RED;
	GUI_SetFont(&GUI_Font8x16);
}

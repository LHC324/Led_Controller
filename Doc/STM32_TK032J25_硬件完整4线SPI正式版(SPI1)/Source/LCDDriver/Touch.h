#ifndef _ADS7843DRV_H_
#define _ADS7843DRV_H_

// A/D 通道选择命令字和工作寄存器
#define	CHX 	0x90 	//通道Y+的选择控制字	
#define	CHY 	0xd0	//通道X+的选择控制字 

#define TP_DCLK(a)	\
						if (a)	\
						GPIO_SetBits(GPIOB,GPIO_Pin_13);	\
						else		\
						GPIO_ResetBits(GPIOB,GPIO_Pin_13)
#define TP_CS(a)	\
						if (a)	\
						GPIO_SetBits(GPIOB,GPIO_Pin_12);	\
						else		\
						GPIO_ResetBits(GPIOB,GPIO_Pin_12)
#define TP_DIN(a)	\
						if (a)	\
						GPIO_SetBits(GPIOB,GPIO_Pin_15);	\
						else		\
						GPIO_ResetBits(GPIOB,GPIO_Pin_15)


void TP_Init(void);
void TP_GetAdXY(unsigned int *x,unsigned int *y);

#endif



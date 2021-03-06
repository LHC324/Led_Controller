//-------------------------------------------------
//移植到新版项目V2
//修改者:XING
//2010/11/12
//-------------------------------------------------
/*
修改历史:
1,2010/11/20 11:45,更正了SCCB_SIC和SCCB_SID所在的端口
  为PA
2,2010/11/20 11:56,加入了SIC_PORT ,SID_PORT
3,2010/11/22 22:00,移植到最新底板
*/

#ifndef _sccb_H
#define _sccb_H


//------------------------------------------------------
#define SIC_PORT_CLK     RCC_APB2Periph_GPIOA
#define SID_PORT_CLK     RCC_APB2Periph_GPIOA

#define SIC_PORT         GPIOA
#define SID_PORT         GPIOA

#define SCCB_SIC_BIT     GPIO_Pin_12
#define SCCB_SID_BIT     GPIO_Pin_11

//-------------------------------------------------------

#define SCCB_SIC_H()     SIC_PORT->BSRR = SCCB_SIC_BIT
#define SCCB_SIC_L()     SIC_PORT->BRR =  SCCB_SIC_BIT

#define SCCB_SID_H()     SID_PORT->BSRR = SCCB_SID_BIT
#define SCCB_SID_L()     SID_PORT->BRR =  SCCB_SID_BIT

#define SCCB_SID_IN      SCCB_SID_GPIO_INPUT()
#define SCCB_SID_OUT     SCCB_SID_GPIO_OUTPUT()
#define SCCB_SID_STATE	 SID_PORT->IDR&(SCCB_SID_BIT)

//-------------------------------------------------------
void SCCB_GPIO_Config(void);
void SCCB_SID_GPIO_OUTPUT(void);
void SCCB_SID_GPIO_INPUT(void);
void startSCCB(void);
void stopSCCB(void);
void noAck(void);
unsigned char SCCBwriteByte(unsigned char m_data);
unsigned char SCCBreadByte(void);

#endif





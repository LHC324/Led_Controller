/****************************************Copyright (c)**************************************************
**                                 Co.,LTD.
**                                     
**                                 http://
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			sdhal.c
** Last modified Date:	2007-10-15
** Last Version:		V2.0
** Descriptions:		SD/MMC卡读写模块: 硬件抽象层 ---- SPI操作函数
**						Soft Packet of SD/MMC Card: hard abstrast layer ---- function of SPI operation
**
**------------------------------------------------------------------------------------------------------
** Created by:			lhlzjut@hotmail.com
** Created date:		2007-10-15
** Version:				V1.0
** Descriptions:		The original version
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/

#include "config.h"
#include "sdhal.h"

/* Select MSD Card: ChipSelect pin low  */
#define MSD_CS_LOW()     GPIO_ResetBits(GPIOA, GPIO_Pin_4)
/* Deselect MSD Card: ChipSelect pin high */
#define MSD_CS_HIGH()    GPIO_SetBits(GPIOA, GPIO_Pin_4)

// global variables
INT8U SendData;
INT8U SendOver;
INT8U ReceiveData;
INT8U ReceiveOver;
/* Private function prototypes -----------------------------------------------*/
static void SPI_Config(void);
	/**************************************************************
		
		读写SD卡的SPI接口函数: SPI接口设置,发送/接收字节函数	
	
	**************************************************************/


/*******************************************************************************************************************
** 函数名称: void SD_HardWareInit()				Name:	  void SD_HardWareInit()
** 功能描述: 初始化访问SD卡的硬件条件			Function: initialize the hardware condiction that access sd card
** 输　  入: 无									Input:	  NULL
** 输 　 出: 无									Output:	  NULL
********************************************************************************************************************/
void SD_HardWareInit(void)
{ 
	SPI_Config();							/* 配置,初始化,SPI接口和SD片选       	*/	
    
	MSD_CS_HIGH();

//	SPI_Clk400k();							/* 配置BSPI波特率为400k       			*/	
}

/*******************************************************************************************************************
** 函数名称: void SPI_Clk400k()					Name:	  void SPI_Clk400k()
** 功能描述: 设置SPI的时钟小于400kHZ			Function: set the clock of SPI less than 400kHZ
** 输　  入: 无									Input:	  NULL
** 输 　 出: 无									Output:	  NULL
********************************************************************************************************************/
void SPI_Clk400k(void)
{
	SPI_InitTypeDef   SPI_InitStructure;

  	/* SPI1 Config */
  	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128;
  	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  	SPI_InitStructure.SPI_CRCPolynomial = 7;
  	SPI_Init(SPI1, &SPI_InitStructure);

  	/* SPI1 enable */
  	SPI_Cmd(SPI1, ENABLE);
}


/*******************************************************************************************************************
** 函数名称: void SPI_ClkToMax()				Name:	  void SPI_ClkToMax()
** 功能描述: 设置SPI的clock到最大值				Function: set the clock of SPI to maximum
** 输　  入: 无									Input:	  NULL
** 输 　 出: 无									Output:	  NULL
********************************************************************************************************************/
void SPI_ClkToMax(void)
{
	SPI_InitTypeDef   SPI_InitStructure;

  	/* SPI1 Config */
  	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
  	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  	SPI_InitStructure.SPI_CRCPolynomial = 7;
  	SPI_Init(SPI1, &SPI_InitStructure);

  	/* SPI1 enable */
  	SPI_Cmd(SPI1, ENABLE);
}


/*******************************************************************************************************************
** 函数名称: void SPI_SendByte()				Name:	  void SPI_SendByte()
** 功能描述: 通过SPI接口发送一个字节			Function: send a byte by SPI interface
** 输　  入: INT8U byte: 发送的字节				Input:	  INT8U byte: the byte that will be send
** 输 　 出: 无									Output:	  NULL
********************************************************************************************************************/
void SPI_SendByte(INT8U byte)
{//为了和播放器更好的合作，使用中断来接收和发送是最好的选择
  
   // Wait until the transmit buffer is empty
  while (SPI_GetFlagStatus(SPI1, SPI_FLAG_TXE) == RESET);
  // Send the byte 
  SPI_SendData(SPI1, byte);
   /*
   SendData = byte;
   SendOver = 0;
   while(!SendOver);
   */
}


/*******************************************************************************************************************
** 函数名称: INT8U SPI_RecByte()				Name:	  INT8U SPI_RecByte()
** 功能描述: 从SPI接口接收一个字节				Function: receive a byte from SPI interface
** 输　  入: 无									Input:	  NULL
** 输 　 出: 收到的字节							Output:	  the byte that be received
********************************************************************************************************************/
INT8U SPI_RecByte(void)
{//为了和播放器更好的合作，使用中断来接收和发送是最好的选择


  
  INT8U Data = 0;

  // Wait until the transmit buffer is empty 
  while (SPI_GetFlagStatus(SPI1, SPI_FLAG_TXE) == RESET);
  // Send the byte 
  SPI_SendData(SPI1, 0xFF);

  // Wait until a data is received 
  while (SPI_GetFlagStatus(SPI1, SPI_FLAG_RXNE) == RESET);
  // Get the received data 
  Data = SPI_ReceiveData(SPI1);

  // Return the shifted data
  return Data;
 
  /*
  SPI_SendByte(0xFF);
  ReceiveData = 0;
  ReceiveOver = 0;
  while(!ReceiveOver);
  
  return ReceiveData;
   */
}


/*******************************************************************************************************************
** 函数名称: void SPI_CS_Assert()				Name:	  void SPI_CS_Assert()
** 功能描述: 片选SPI从机						Function: select the SPI slave 
** 输　  入: 无									Input:	  NULL
** 输 　 出: 无									Output:	  NULL
********************************************************************************************************************/
void SPI_CS_Assert(void)
{
	MSD_CS_LOW();			   					/* 片选SPI从机  select the SPI slave */  
}


/*******************************************************************************************************************
** 函数名称: void SPI_CS_Deassert()				Name:	  void SPI_CS_Deassert()
** 功能描述: 不片选SPI从机						Function: not select the SPI slave 
** 输　  入: 无									Input:	  NULL
** 输 　 出: 无									Output:	  NULL
********************************************************************************************************************/
void SPI_CS_Deassert(void)
{
	MSD_CS_HIGH();			    				/* 不片选SPI从机  not select the SPI slave */
}

/*******************************************************************************************************************
** 函数名称: void SD_ChkCard()					Name:	  void SD_ChkCard()
** 功能描述: 检测卡是否完全插入					Function: check weather card is insert entirely
** 输　  入: 无									Input:	  NULL
** 输 　 出: 1: 卡完全插入	0: 卡没有完全插入   Output:	  1: insert entirely	0: not insert entirely
********************************************************************************************************************/
INT8U SD_ChkCard(void)
{
	if (SD_INSERT_STATUS() != 0)
		return 0;								/* 未完全插入 not insert entirely */
	else
		return 1;								/* 完全插入 insert entirely */
}

/*******************************************************************************************************************
** 函数名称: void SD_ChkCardWP()				Name:	  void SD_ChkCardWP()
** 功能描述: 检测卡写保护						Function: check weather card is write protect
** 输　  入: 无									Input:	  NULL
** 输 　 出: 1: 卡已写保护	0: 卡未写保护	    Output:	  1: insert write protect	0: not write protect
********************************************************************************************************************/
INT8U SD_ChkCardWP(void)
{
	if (SD_WP_STATUS() != 0)
		return 1;								/* 卡写保护 */
	else
		return 0;								/* 卡未写保护 */
}

/*******************************************************************************
* Function Name  : SPI_Config
* Description    : Initializes the SPI1 and CS pins.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void SPI_Config(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;
  SPI_InitTypeDef   SPI_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;

  /* GPIOA and GPIOC Periph clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC |RCC_APB2Periph_GPIOE, ENABLE);
  /* SPI1 Periph clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);

  /* Configure SPI1 pins: SCK, MISO and MOSI */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Configure PC12 pin: CS pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOE, &GPIO_InitStructure);

  /* SPI1 Config */
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI1, &SPI_InitStructure);

  /* SPI1 enable */
  SPI_Cmd(SPI1, ENABLE);
  /* Enable SPI1 TXE interrupt */
  //SPI_ITConfig(SPI1, SPI_IT_TXE, ENABLE);
  /* Enable SPI1 RXNE interrupt */
  //SPI_ITConfig(SPI1, SPI_IT_RXNE, ENABLE);

  /* Configure and enable SPI1 interrupt -------------------------------------*/
  NVIC_InitStructure.NVIC_IRQChannel = SPI1_IRQChannel;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

}









/*这份代码经源码格式软件格式化过
     yang_hx@neusoft.com      */
/*******************************************************************************
*  本文件为SPI操作SD卡的底层驱动文件
*  包括SPI模块及相关IO的初始化，SPI读写SD卡（写指令，读数据等）
*******************************************************************************/
#include <includes.h>
#include "stm32f10x_lib.h"
#include "SD_driver.h"

u8 SD_Type=0 ;


#define  SD_UCOSII_EN    0
#define  SD_UCOSII_EN_2  0



#if SD_UCOSII_EN || SD_UCOSII_EN_2
extern OS_EVENT  *SPI_EVENT;  	/* 卡访问权限信号量 semaphore that access card */
#endif 



void StartSD(void)
{
#if SD_UCOSII_EN_2
   unsigned char  err;	
   //OSMutexPend(SPI_EVENT, 0, &err);
   OSSemPend(SPI_EVENT, 0, &err);
#endif 
}


void EndSD(void)
{
#if SD_UCOSII_EN_2
   unsigned char  err;
   //OSMutexPost(SPI_EVENT);
   OSSemPost(SPI_EVENT);
   SD_CS_DISABLE();
#endif 
}

/*******************************************************************************************************************
** 函数名称: void SD_StartSD()					Name:	  INT8U SD_StartSD()
** 功能描述: 向操作系统申请访问SD卡的权限		Function: request the right of operating sd to OS
** 输　  入: 无									Input:	  NULL
** 返	 回: 无									return:	  NULL
********************************************************************************************************************/
void SD_StartSD(void)
{
#if SD_UCOSII_EN
   unsigned char  err;	
   //OSMutexPend(SPI_EVENT, 0, &err);
   OSSemPend(SPI_EVENT, 0, &err); 	/* 等待访问卡信号量可用 wait for semaphore that accessed Card */
   //OSSchedLock();
#endif
}

/*******************************************************************************************************************
** 函数名称: void SD_EndSD()					Name:	  INT8U SD_EndSD()
** 功能描述: 访问SD卡的权限归还操作系统			Function: return the right of operating sd to OS
** 输　  入: 无									Input:	  NULL
** 返	 回: 无									return:	  NULL
********************************************************************************************************************/
void SD_EndSD(void)
{
#if SD_UCOSII_EN
    unsigned char  err;
	//OSMutexPost(SPI_EVENT);
	OSSemPost(SPI_EVENT);							/* 将访问卡信号量还给操作系统 return the semaphore accessing Card to OS */
	//OSSchedUnlock();
	SD_CS_DISABLE();
#endif
}	


////////////////////////////////////////////////////////////////////////////////
// 以下是SPI模块的初始化代码，配置成主机模式，访问SD卡
////////////////////////////////////////////////////////////////////////////////
/*******************************************************************************
* Function Name  : SPI_Configuration
* Description    : SPI模块初始化，【包括相关IO口的初始化】
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void picdemo_SPI_Configuration(void)
{
    SPI_InitTypeDef SPI_InitStructure ;
    GPIO_InitTypeDef GPIO_InitStructure ;


#if 1
    //启动SPI时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3,ENABLE);
    
    //////下面是SPI相关GPIO初始化//////
    //SPI1模块对应的SCK、MISO、MOSI为AF引脚
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5 ;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz ;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP ;
    GPIO_Init(GPIOB,&GPIO_InitStructure);
	
    
    //PD3 pin:SD_CS
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz ;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP ;
    GPIO_Init(GPIOA,&GPIO_InitStructure); 

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;   //上拉输入
    GPIO_Init(GPIOB,&GPIO_InitStructure);	


#endif

    GPIO_SetBits(GPIOA,GPIO_Pin_15);

    //////SPI模块配置//////
    //一开始SD初始化阶段，SPI时钟频率必须<400K
    SPI_InitStructure.SPI_Direction=SPI_Direction_2Lines_FullDuplex ;
    SPI_InitStructure.SPI_Mode=SPI_Mode_Master ;
    SPI_InitStructure.SPI_DataSize=SPI_DataSize_8b ;
    SPI_InitStructure.SPI_CPOL=SPI_CPOL_High ;
    SPI_InitStructure.SPI_CPHA=SPI_CPHA_2Edge ;
    SPI_InitStructure.SPI_NSS= SPI_NSS_Soft;//	   SPI_NSS_Hard
    SPI_InitStructure.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_64;//4 ;
    SPI_InitStructure.SPI_FirstBit=SPI_FirstBit_MSB ;
    SPI_InitStructure.SPI_CRCPolynomial=7 ;

    SPI_Init(SPI3,&SPI_InitStructure);
    SPI_Cmd(SPI3,ENABLE);

}
/*******************************************************************************
* Function Name  : SPI_ReadWriteByte
* Description    : SPI读写一个字节（发送完成后返回本次通讯读取的数据）
* Input          : u8 TxData 待发送的数
* Output         : None
* Return         : u8 RxData 收到的数
*******************************************************************************/
u8 SPI_ReadWriteByte(u8 TxData)
{
    u8 RxData=0 ;
    
	//GPIO_WriteBit(GPIOC, GPIO_Pin_7, Bit_SET); //读文件闪烁
    
	//等待发送缓冲区空
    while(SPI_I2S_GetFlagStatus(SPI3,SPI_I2S_FLAG_TXE)==RESET);
    //发一个字节
    SPI_I2S_SendData(SPI3,TxData);
    
    //等待数据接收
    while(SPI_I2S_GetFlagStatus(SPI3,SPI_I2S_FLAG_RXNE)==RESET);
    //取数据
    RxData=SPI_I2S_ReceiveData(SPI3);
    
	//GPIO_WriteBit(GPIOC, GPIO_Pin_7, Bit_RESET);

    return RxData ;
}

/*******************************************************************************
* Function Name  : SD_WaitReady
* Description    : 等待SD卡Ready
* Input          : None
* Output         : None
* Return         : u8
*               0： 成功
*           other：失败
*******************************************************************************/
u8 SD_WaitReady(void)
{
    u8 r1 ;
    u16 retry ;

	StartSD();
    retry=0 ;
    do 
    {
        r1=SPI_ReadWriteByte(0xFF);
        if(retry==0xfffe)//如果卡异常，会死循坏！
        {
			EndSD();
            return 1 ;
        }
    }
    while(r1!=0xFF);
    
	EndSD();
    return 0 ;
}


/*******************************************************************************
* Function Name  : SD_SendCommand
* Description    : 向SD卡发送一个命令
* Input          : u8 cmd   命令
*                  u32 arg  命令参数
*                  u8 crc   crc校验值
* Output         : None
* Return         : u8 r1 SD卡返回的响应
*******************************************************************************/
u8 SD_SendCommand(u8 cmd,u32 arg,u8 crc)
{
    unsigned char r1 ;
    unsigned char Retry=0 ;

	StartSD();
    SPI_ReadWriteByte(0xff);
    //片选端置低，选中SD卡
    SD_CS_ENABLE();
    
    //发送
    SPI_ReadWriteByte(cmd|0x40);
    //分别写入命令
    SPI_ReadWriteByte(arg>>24);
    SPI_ReadWriteByte(arg>>16);
    SPI_ReadWriteByte(arg>>8);
    SPI_ReadWriteByte(arg);
    SPI_ReadWriteByte(crc);
    
    //等待响应，或超时退出
    while((r1=SPI_ReadWriteByte(0xFF))==0xFF)
    {
        Retry++;
        if(Retry>200)
        {
            break ;
        }
    }  
    //关闭片选
    SD_CS_DISABLE();
    //在总线上额外增加8个时钟，让SD卡完成剩下的工作
    SPI_ReadWriteByte(0xFF);
    
	EndSD();
    //返回状态值
    return r1 ;
}


/*******************************************************************************
* Function Name  : SD_SendCommand_NoDeassert
* Description    : 向SD卡发送一个命令(结束是不失能片选，还有后续数据传来）
* Input          : u8 cmd   命令
*                  u32 arg  命令参数
*                  u8 crc   crc校验值
* Output         : None
* Return         : u8 r1 SD卡返回的响应
*******************************************************************************/
u8 SD_SendCommand_NoDeassert(u8 cmd,u32 arg,u8 crc)
{
    unsigned char r1 ;
    unsigned char Retry=0 ;

	StartSD();
    SPI_ReadWriteByte(0xff);
    //片选端置低，选中SD卡
    SD_CS_ENABLE();
    
    //发送
    SPI_ReadWriteByte(cmd|0x40);
    //分别写入命令
    SPI_ReadWriteByte(arg>>24);
    SPI_ReadWriteByte(arg>>16);
    SPI_ReadWriteByte(arg>>8);
    SPI_ReadWriteByte(arg);
    SPI_ReadWriteByte(crc);
    
    //等待响应，或超时退出
    while((r1=SPI_ReadWriteByte(0xFF))==0xFF)
   /* {
        Retry++;
        if(Retry>200)
        {
            break ;
        }
    }*/
	
	EndSD();
    //返回响应值
    return r1 ;
}

/*******************************************************************************
* Function Name  : SD_Init
* Description    : 初始化SD卡
* Input          : None
* Output         : None
* Return         : u8
*                  0：NO_ERR
*                  1：TIME_OUT
*                  99：NO_CARD
*******************************************************************************/
u8 SD_Init(void)
{
    u16 i ;// 用来循环计数
    u8 r1 ;// 存放SD卡的返回值
	u8 buff[4];

	SD_StartSD(); 
	//先产生>74个脉冲，让SD卡自己初始化完成
    for(i=0;i<10;i++) SPI_ReadWriteByte(0xFF);

    //-----------------SD卡复位到idle开始-----------------
    //循环连续发送CMD0，直到SD卡返回0x01,进入IDLE状态
    do 
    {
        //发送CMD0，让SD卡进入IDLE状态
        r1=SD_SendCommand(CMD0,0,0x95);
    }
    while(r1!=0x01);

    //-----------------SD卡复位到idle结束-----------------

    //获取卡片的SD版本信息
    r1=SD_SendCommand_NoDeassert(8,0x1aa,0x87); 
	   
    //下面是V2.0卡的初始化
            //发卡初始化指令CMD55+ACMD41
            do 
            {
                r1=SD_SendCommand(CMD55,0,0);
                r1=SD_SendCommand(ACMD41,0x40000000,0);
            }
            while(r1!=0);
	SD_EndSD();
    return 0 ;
}

/*******************************************************************************
* Function Name  : SD_ReceiveData
* Description    : 从SD卡中读回指定长度的数据，放置在给定位置
* Input          : u8 *data(存放读回数据的内存>len)
*                  u16 len(数据长度）
*                  u8 release(传输完成后是否释放总线CS置高 0：不释放 1：释放）
* Output         : None
* Return         : u8
*                  0：NO_ERR
*                  other：错误信息
*******************************************************************************/

u8 SD_ReceiveData(u8*data,u16 len,u8 release)
{
    u8 r1 ;
    
	StartSD();
    // 启动一次传输
    SD_CS_ENABLE();
    //等待SD卡发回数据起始令牌0xFE
    do 
    {
        r1=SPI_ReadWriteByte(0xFF);
    }
    while(r1!=0xFE);
    //开始接收数据
    while(len--)
    {
        *data=SPI_ReadWriteByte(0xFF);
        data++;
    }
    //下面是2个伪CRC（dummy CRC）
    SPI_ReadWriteByte(0xFF);
    SPI_ReadWriteByte(0xFF);
    //按需释放总线，将CS置高
   /* if(release==RELEASE)
    {
        //传输结束
        SD_CS_DISABLE();
        SPI_ReadWriteByte(0xFF);
    }  */
    
	EndSD();
    return 0 ;
}


/*******************************************************************************
* Function Name  : SD_GetCID
* Description    : 获取SD卡的CID信息，包括制造商信息
* Input          : u8 *cid_data(存放CID的内存，至少16Byte）
* Output         : None
* Return         : u8
*                  0：NO_ERR
*                  1：TIME_OUT
*                  other：错误信息
*******************************************************************************/
u8 SD_GetCID(u8*cid_data)
{
    u8 r1 ;
	
	//StartSD();
    //发CMD10命令，读CID
    r1=SD_SendCommand(CMD10,0,0xFF);
    if(r1!=0x00)
    {
	    //EndSD();
        return r1 ;
        //没返回正确应答，则退出，报错
    }
    //接收16个字节的数据
    SD_ReceiveData(cid_data,16,RELEASE);
    
	//EndSD();
    return 0 ;
}


/*******************************************************************************
* Function Name  : SD_GetCSD
* Description    : 获取SD卡的CSD信息，包括容量和速度信息
* Input          : u8 *cid_data(存放CID的内存，至少16Byte）
* Output         : None
* Return         : u8
*                  0：NO_ERR
*                  1：TIME_OUT
*                  other：错误信息
*******************************************************************************/
u8 SD_GetCSD(u8 *csd_data)
{
    u8 r1 ;
    
	//StartSD();
    //发CMD9命令，读CSD
    r1=SD_SendCommand(CMD9,0,0xFF);
    if(r1!=0x00)
    {
	    //EndSD();
        return r1 ;
        //没返回正确应答，则退出，报错
    }
    //接收16个字节的数据
    SD_ReceiveData(csd_data,16,RELEASE);
    
	//EndSD();
    return 0 ;
}

/*******************************************************************************
* Function Name  : SD_GetCapacity
* Description    : 获取SD卡的容量
* Input          : None
* Output         : None
* Return         : u32 capacity
*                   0： 取容量出错
*******************************************************************************/
u32 SD_GetCapacity(void)
{
    u8 csd[16];
    u32 Capacity ;
    u8 r1 ;
    u16 i ;
    u16 temp ;
    
	//StartSD();
    //取CSD信息，如果期间出错，返回0
    if(SD_GetCSD(csd)!=0)
    {
		//EndSD();
        return 0 ;
    }
    
    //如果为SDHC卡，按照下面方式计算
    if((csd[0]&0xC0)==0x40)
    {
        Capacity=(((u32)csd[8])<<8+(u32)csd[9]+1)*(u32)1024 ;
    }
    else 
    {
        //下面代码为网上版本
        ////////////formula of the capacity///////////////
        //
        //  memory capacity = BLOCKNR * BLOCK_LEN
        //
        //	BLOCKNR = (C_SIZE + 1)* MULT
        //
        //           C_SIZE_MULT+2
        //	MULT = 2
        //
        //               READ_BL_LEN
        //	BLOCK_LEN = 2
        /**********************************************/
        //C_SIZE
        i=csd[6]&0x03 ;
        i<<=8 ;
        i+=csd[7];
        i<<=2 ;
        i+=((csd[8]&0xc0)>>6);
        
        //C_SIZE_MULT
        r1=csd[9]&0x03 ;
        r1<<=1 ;
        r1+=((csd[10]&0x80)>>7);
        
        //BLOCKNR
        r1+=2 ;
        temp=1 ;
        while(r1)
        {
            temp*=2 ;
            r1--;
        }
        Capacity=((u32)(i+1))*((u32)temp);
        
        // READ_BL_LEN
        i=csd[5]&0x0f ;
        //BLOCK_LEN
        temp=1 ;
        while(i)
        {
            temp*=2 ;
            i--;
        }
        //The final result
        Capacity*=(u32)temp ;
        //Capacity /= 512;
    }
	
	//EndSD();
    return (u32)Capacity ;
}


/*******************************************************************************
* Function Name  : SD_ReadSingleBlock
* Description    : 读SD卡的一个block
* Input          : u32 sector 取地址（sector值，非物理地址）
*                  u8 *buffer 数据存储地址（大小至少512byte）
* Output         : None
* Return         : u8 r1
*                   0： 成功
*                   other：失败
*******************************************************************************/
u8 SD_ReadSingleBlock(u32 sector,u8*buffer)
{
    SD_StartSD(); 
	SD_SendCommand(CMD17,sector,0);
	SD_ReceiveData(buffer,512,RELEASE);
	SD_EndSD();
	return 0 ;

}

/*******************************************************************************
* Function Name  : SD_WriteSingleBlock
* Description    : 写入SD卡的一个block
* Input          : u32 sector 扇区地址（sector值，非物理地址）
*                  u8 *buffer 数据存储地址（大小至少512byte）
* Output         : None
* Return         : u8 r1
*                   0： 成功
*                   other：失败
*******************************************************************************/
u8 SD_WriteSingleBlock(u32 sector,const u8 *data)
{
    u8 r1 ;
    u16 i ;
    u16 retry ;
    
	SD_StartSD();
    //设置为高速模式
    //SPI_SetSpeed(SPI_SPEED_HIGH);
    
    //如果不是SDHC，给定的是sector地址，将其转换成byte地址
    if(SD_Type!=SD_TYPE_V2HC)
    {
        sector=sector<<9 ;
    }
    
    r1=SD_SendCommand(CMD24,sector,0x00);
    if(r1!=0x00)
    {
	    SD_EndSD();
        return r1 ;
        //应答不正确，直接返回
    }
    
    //开始准备数据传输
    SD_CS_ENABLE();
    //先放3个空数据，等待SD卡准备好
    SPI_ReadWriteByte(0xff);
    SPI_ReadWriteByte(0xff);
    SPI_ReadWriteByte(0xff);
    //放起始令牌0xFE
    SPI_ReadWriteByte(0xFE);
    
    //放一个sector的数据
    for(i=0;i<512;i++)
    {
        SPI_ReadWriteByte(*data++);
    }
    //发2个Byte的dummy CRC
    SPI_ReadWriteByte(0xff);
    SPI_ReadWriteByte(0xff);
    
    //等待SD卡应答
    r1=SPI_ReadWriteByte(0xff);
    if((r1&0x1F)!=0x05)
    {
        SD_CS_DISABLE();
		SD_EndSD();
        return r1 ;
    }
    
    //等待操作完成
    retry=0 ;
    while(!SPI_ReadWriteByte(0xff))
    {
        retry++;
        //如果长时间写入没有完成，报错退出
        if(retry>0xfffe)
        {
            SD_CS_DISABLE();
			SD_EndSD();
            return 1 ;
            //写入超时返回1
        }
    }
    
    //写入完成，片选置1
    SD_CS_DISABLE();
    SPI_ReadWriteByte(0xff);
    
	SD_EndSD();
    return 0 ;
}


/*******************************************************************************
* Function Name  : SD_ReadMultiBlock
* Description    : 读SD卡的多个block
* Input          : u32 sector 取地址（sector值，非物理地址）
*                  u8 *buffer 数据存储地址（大小至少512byte）
*                  u8 count 连续读count个block
* Output         : None
* Return         : u8 r1
*                   0： 成功
*                   other：失败
*******************************************************************************/
u8 SD_ReadMultiBlock(u32 sector,u8 *buffer,u8 count)
{
    u8 r1 ;

	SD_StartSD();
    //发读多块命令
    r1=SD_SendCommand(CMD18,sector,0);
    //读命令
    if(r1!=0x00)
    {
	    SD_EndSD();
        return r1 ;
    }
    //开始接收数据
    do 
    {
        if(SD_ReceiveData(buffer,512,NO_RELEASE)!=0x00)
        {
            break ;
        }
        buffer+=512 ;
    }
    while(--count);
    
    //全部传输完毕，发送停止命令
    SD_SendCommand(CMD12,0,0);
    //释放总线
    SD_CS_DISABLE();
    SPI_ReadWriteByte(0xFF);
    
    SD_EndSD();

    if(count!=0)
    {
        return count ;
        //如果没有传完，返回剩余个数
    }
    else 
    {
        return 0 ;
    }
}


/*******************************************************************************
* Function Name  : SD_WriteMultiBlock
* Description    : 写入SD卡的N个block
* Input          : u32 sector 扇区地址（sector值，非物理地址）
*                  u8 *buffer 数据存储地址（大小至少512byte）
*                  u8 count 写入的block数目
* Output         : None
* Return         : u8 r1
*                   0： 成功
*                   other：失败
*******************************************************************************/
u8 SD_WriteMultiBlock(u32 sector,const u8*data,u8 count)
{
    u8 r1 ;
    u16 i ;
    
	SD_StartSD();
    //设置为高速模式
    //SPI_SetSpeed(SPI_SPEED_HIGH);
    
    //如果不是SDHC，给定的是sector地址，将其转换成byte地址
    if(SD_Type!=SD_TYPE_V2HC)
    {
        sector=sector<<9 ;
    }
    //如果目标卡不是MMC卡，启用ACMD23指令使能预擦除
    if(SD_Type!=SD_TYPE_MMC)
    {
        r1=SD_SendCommand(ACMD23,count,0x00);
    }
    //发多块写入指令
    r1=SD_SendCommand(CMD25,sector,0x00);
    if(r1!=0x00)
    {
	    SD_EndSD();
        return r1 ;
        //应答不正确，直接返回
    }
    
    //开始准备数据传输
    SD_CS_ENABLE();
    //先放3个空数据，等待SD卡准备好
    SPI_ReadWriteByte(0xff);
    SPI_ReadWriteByte(0xff);
    
    //--------下面是N个sector写入的循环部分
    do 
    {
        //放起始令牌0xFC 表明是多块写入
        SPI_ReadWriteByte(0xFC);
        
        //放一个sector的数据
        for(i=0;i<512;i++)
        {
            SPI_ReadWriteByte(*data++);
        }
        //发2个Byte的dummy CRC
        SPI_ReadWriteByte(0xff);
        SPI_ReadWriteByte(0xff);
        
        //等待SD卡应答
        r1=SPI_ReadWriteByte(0xff);
        if((r1&0x1F)!=0x05)
        {
            SD_CS_DISABLE();
            //如果应答为报错，则带错误代码直接退出
			SD_EndSD();
            return r1 ;
        }
        
        //等待SD卡写入完成
        if(SD_WaitReady()==1)
        {
            SD_CS_DISABLE();
            //等待SD卡写入完成超时，直接退出报错
			SD_EndSD();
            return 1 ;
        }
        
        //本sector数据传输完成
    }
    while(--count);
    
    //发结束传输令牌0xFD
    r1=SPI_ReadWriteByte(0xFD);
    if(r1==0x00)
    {
        count=0xfe ;
    }
    
    if(SD_WaitReady())
    {
        while(1){}
    }
    
    //写入完成，片选置1
    SD_CS_DISABLE();
    SPI_ReadWriteByte(0xff);

    SD_EndSD();
    return count ;
    //返回count值，如果写完则count=0，否则count=1
}

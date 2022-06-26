/****************************************Copyright (c)**************************************************
**                               Hangzhou yh software  Co.,LTD.
**                                     
**                                 http://www.armgcc.com
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			sddriver.c
** Last modified Date:	2007-10-15
** Last Version:		V1.0
** Descriptions:		SD/MMC卡读写模块: 物理层 用户API函数
**						
**------------------------------------------------------------------------------------------------------
** Created by:			lhlzjut@hotmail.com
** Created date:		2007-10-15
** Version:				V1.0
** Descriptions:		The original version
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#include "sdhal.h"
#include "sdcmd.h"
#include "sddriver.h"

#if SD_UCOSII_EN
	OS_EVENT *pSemSD = NULL;	/* 卡访问权限信号量 semaphore that access card */
#endif 

/* SD卡信息结构体变量 the information structure variable of SD Card */
sd_struct sds;			

/* 超时时间单位表(单位:0.000000001ns) timeout unit table */
const INT32U time_unit[8] = {1000000000,100000000,10000000,
							 1000000,100000,10000,1000,100};

/* 超时时间表 timeout value table */							 
const INT8U time_value[16] = {0,10,12,13,15,20,25,30,
                              35,40,45,50,55,60,70,80};
 
/* 超时时间因数表 timeout factor table */                              
const INT8U r2w_fator[8] = {1,2,4,8,16,32,64,128};                           
 

void SD_Sleep(INT32U cpt_loop)
{
  while (cpt_loop -- != 0);
}   
	/*       
	***************************************************************************************************
		
	     用户API函数:  初始化,读,写,擦 SD卡  User API Function: Initialize,read,write,erase SD Card 
				
	***************************************************************************************************
	*/
				
/*******************************************************************************************************************
** 函数名称: INT8U SD_Initialize()				Name:	  INT8U SD_Initialize()
** 功能描述: 初始化SD/MMC卡						Function: initialize SD/MMC card
** 输　  入: 无									Input:	  NULL
** 输    出: 0:   成功    >0:  错误码			Output:	  0:  right			>0:  error code
********************************************************************************************************************/
INT8U SD_Initialize(void)
{
	INT8U recbuf[4],ret;
	
#if SD_UCOSII_EN
	if (pSemSD == NULL)
	{
    	pSemSD = OSSemCreate(1);					/* 创建访问SD/MMC卡信号量 create SD/MMC semaphore */ 
		if (pSemSD == NULL)					
		 	return SD_ERR_CREATE_SEMSD;
	}				    
#endif	
   
    SD_StartSD();
    SD_HardWareInit();					    		/* 初始化读写SD卡的硬件条件 Initialize the hardware that access SD Card */
    
    if (SD_ChkCard() != 1)							/* 检查卡是否插入 check weather card is inserted */
    {	
    	ret = SD_ERR_NO_CARD;   
    	goto SD_ERR;
    }
        
    SPI_CS_Assert();								/* 1. 置CS为低 assert CS */  
	
	SD_SPIDelay(200);								/* 2. 至少延时 74 clock delay more than 74 clock */
    
	SPI_CS_Deassert();								/* 3. 置CS为高 dessert CS */
    SD_SPIDelay(4);									/* 4. 延时2(8 clock) delay 2(8 clock) */
     
    SD_Sleep(1000000);
    
    ret = SD_ResetSD();								/* 5. 发出CMDO命令复位SD卡 send CMD0 command to reset sd card */
   	
    if (ret != SD_NO_ERR)
        goto SD_ERR;									
 	
 	ret = SD_ActiveInit();							/* 6. 激活卡进入初始化过程. active card initialize process */
 	if (ret != SD_NO_ERR)
 		goto SD_ERR;
    
   	ret = SD_ReadOCR(4, recbuf);  					/* 7. 读OCR寄存器,查询卡支持的电压值 read OCR register,get the supported voltage */
    if (ret != SD_NO_ERR)
        goto SD_ERR;
    
    if ((recbuf[1] & MSK_OCR_33) != MSK_OCR_33)
    { 	 
        ret = SD_ERR_VOL_NOTSUSP;					/* 不支持3.3V,返回错误码  not support 3.3V,return error code */
    	goto SD_ERR;
    }
          
#if SD_CRC_EN        
    ret = SD_EnableCRC(1);							/* 使能CRC校验 enable CRC check */
	if (ret != SD_NO_ERR)  
	  	goto SD_ERR;
#endif

    ret = SD_SetBlockLen(SD_BLOCKSIZE);				/* 8. 设置块的长度: 512Bytes Set the block length: 512Bytes */
    if (ret != SD_NO_ERR)  
        goto SD_ERR;
        
    ret = SD_GetCardInfo();							/* 9. 读CSD寄存器,获取SD卡信息 read CSD register, get the information of SD card */    
	if (ret != SD_NO_ERR)
		goto SD_ERR;

	SD_EndSD();	

	SPI_ClkToMax();									/* 10. 设置SPI时钟到最大值 set SPI clock to maximum */		

	return SD_NO_ERR;								/* 初始化成功 initialize sucessfully */

SD_ERR:	
	SD_EndSD();	
	return ret;
}

/********************************************************************************************************************
** 函数名称: INT8U SD_ReadBlock()					Name:	  INT8U SD_ReadBlock()
** 功能描述: 从SD/MMC卡中读一个块					Function: read a single block from SD/MMC card
** 输　  入: INT32U blockaddr: 块地址				Input:    INT32U blockaddr: address of block
			 INT8U *recbuf   : 接收缓冲区,长度512Bytes	 	  INT8U *recbuf   : the buffer of receive,length is 512Bytes
** 输    出: 0:   成功    >0:  错误码				Output:	  0:  right			>0:  error code
*********************************************************************************************************************/
INT8U SD_ReadBlock(INT32U blockaddr,INT32U len, INT8U *recbuf)
{
	INT8U ret; 
	
	SD_StartSD();									/* 向OS申请访问卡信号量 request semaphore acessed SD/MMC to OS */
    if (SD_ChkCard() != 1)							
    {
    	SD_EndSD();	
    	return SD_ERR_NO_CARD;   					/* 卡没完全插入卡中 card is not inserted entirely */
	}
		
	if (blockaddr > sds.block_num)	
	{
		SD_EndSD();	
		return SD_ERR_OVER_CARDRANGE;				/* 操作超出卡容量范围 operate over the card range */
	}
	
 	ret = SD_ReadSingleBlock(blockaddr);			/* 读单块命令 read single blocks command */						
 	if (ret != SD_NO_ERR)
 	{
 		SD_EndSD();									
 		return ret;
 	}
 	
  	ret = SD_ReadBlockData(len, recbuf);			/* 读出数据 read data from sd card */	
	SD_EndSD();										/* 归还访问卡信号量 return semaphore acessed SD/MMC to OS */
	
	return ret;
}

/********************************************************************************************************************
** 函数名称: INT8U SD_ReadMultiBlock()				Name:	  INT8U SD_ReadMultiBlock()
** 功能描述: 从SD/MMC卡中读多个块					Function: read multi blocks from SD/MMC card
** 输　  入: INT32U blockaddr: 块地址				Input:	  INT32U blockaddr: address of block
			 INT32U blocknum : 块数量						  INT32U blocknum : the numbers of block
			 INT8U *recbuf   : 接收缓冲区,每块512字节		  INT8U *recbuf   : the buffer of receive,each block length is 512Bytes
** 输    出: 0:   成功    >0:  错误码				Output:	  0:  right			>0:  error code
*********************************************************************************************************************/
#if SD_ReadMultiBlock_EN
INT8U SD_ReadMultiBlock(INT32U blockaddr, INT32U blocknum, INT8U *recbuf)
{
    INT32U i;
    INT8U ret;
       
	SD_StartSD();									/* 向OS申请访问卡信号量 request semaphore acessed SD/MMC to OS */
    if (SD_ChkCard() != 1)							
    {
    	SD_EndSD();	
    	return SD_ERR_NO_CARD;   					/* 卡没完全插入卡中 card is not inserted entirely */
	}
		
	if ((blockaddr + blocknum) > sds.block_num)	
	{
		SD_EndSD();	
		return SD_ERR_OVER_CARDRANGE;				/* 操作超出卡容量范围 operate over the card range */
	}       
    
	ret = SD_ReadMultipleBlock(blockaddr);			/* 读多块命令 read multiple blocks command */
	if (ret != SD_NO_ERR)
	{	
		SD_EndSD();									/* 归还访问卡信号量 return semaphore acessed SD/MMC to OS */						
		return ret;
    }
    
    for (i = 0; i < blocknum; i++)
    {												/* 读出数据 read data from SD/MMC card */
    	ret = SD_ReadBlockData(SD_BLOCKSIZE, recbuf);
    	if (ret == SD_NO_ERR)
       		recbuf = recbuf + SD_BLOCKSIZE;
    	else
    	{
    		SD_EndSD();
    		return ret;
    	}
    }
 	 
 	ret = SD_StopTransmission();				    /* 结束数据传输 stop transmission operation */ 
 	
 	SD_EndSD();
	return ret; 
}

#endif

/********************************************************************************************************************
** 函数名称: INT8U SD_WriteBlock()					Name:	  INT8U SD_WriteBlock()
** 功能描述: 向SD/MMC卡中写入一个块					Function: write a block to SD/MMC card
** 输　  入: INT32U blockaddr: 块地址				Input: 	  INT32U blockaddr: address of block
			 INT8U *sendbuf  : 发送缓冲区,长度512Bytes	  	  INT8U *sendbuf  : the buffer of send,length is 512Bytes
** 输    出: 0:   成功    >0:  错误码				Output:	  0:  right			>0:  error code
*********************************************************************************************************************/
INT8U SD_WriteBlock(INT32U blockaddr, INT32U len, INT8U *sendbuf)
{
	INT8U ret,tmp[2];
	
	SD_StartSD();												/* 向OS申请访问卡信号量 request semaphore acessed SD/MMC to OS */
    if (SD_ChkCard() != 1)							
    {
    	SD_EndSD();	
    	return SD_ERR_NO_CARD;   								/* 卡没完全插入卡中 card is not inserted entirely */
	}	
	
	if (blockaddr > sds.block_num)	
	{
		SD_EndSD();	
		return SD_ERR_OVER_CARDRANGE;							/* 操作超出卡容量范围 operate over the card range */
	}
	
	if (SD_ChkCardWP() == 1)
	{
		SD_EndSD();
		return SD_ERR_WRITE_PROTECT;							/* 卡有写保护 */
	}
	
	ret = SD_WriteSingleBlock(blockaddr);						/* 写单块命令 write single block */
	if (ret != SD_NO_ERR)
	{	
		SD_EndSD();
		return ret;
	}
	
	ret = SD_WriteBlockData(0, len, sendbuf);			/* 写入数据 write data */
 	
	if (ret == SD_NO_ERR)										/* 读Card Status寄存器, 检查写入是否成功 */
 	{															/* read Card Status register to check write wheather sucessfully */
 		ret = SD_ReadCard_Status(2, tmp);
 		if (ret != SD_NO_ERR)
 		{
 			SD_EndSD();
 			return ret;											/* 读寄存器失败 read register fail */
		}

 		if((tmp[0] != 0) || (tmp[1] != 0))
 		{
 			SD_EndSD();
			ret = SD_ERR_WRITE_BLK; 			     			/* 响应指示写失败 response indicate write fail */
 		}
 	}
  
    SD_EndSD();
 	return ret;													/* 返回写入结果 return the result of writing */									
}

/**********************************************************************************************************************
** 函数名称: INT8U SD_WriteMultiBlock()				Name:	  INT8U SD_WriteMultiBlock()
** 功能描述: 向SD/MMC卡中写入多个块					Function: write multi blocks to SD/MMC card
** 输　  入: INT32U blockaddr: 块地址				Input:	  INT32U blockaddr: address of block
			 INT32U blocknum : 块数量						  INT32U blocknum : the numbers of block
			 INT8U *sendbuf  : 发送缓冲区每块512字节    	  INT8U *sendbuf  : the send buffer,each block length is 512Bytes
** 输    出: 0:   成功    >0:  错误码				Output:	  0:  right			>0:  error code
***********************************************************************************************************************/
#if SD_WriteMultiBlock_EN
INT8U SD_WriteMultiBlock(INT32U blockaddr, INT32U blocknum, INT8U *sendbuf)
{
	INT32U i;
	INT8U ret,tmp[2];
	
	SD_StartSD();												/* 向OS申请访问卡信号量 request semaphore acessed SD/MMC to OS */
    if (SD_ChkCard() != 1)							
    {
    	SD_EndSD();	
    	return SD_ERR_NO_CARD;   								/* 卡没完全插入卡中 card is not inserted entirely */
	}
		
	if ((blockaddr + blocknum) > sds.block_num)	
	{
		SD_EndSD();	
		return SD_ERR_OVER_CARDRANGE;							/* 操作超出卡容量范围 operate over the card range */
	}
		
	if (SD_ChkCardWP() == 1)
	{
		SD_EndSD();
		return SD_ERR_WRITE_PROTECT;							/* 卡有写保护 */
	}
	
	ret = SD_WriteMultipleBlock(blockaddr);						/* 写多块命令 write multiple blocks command */
	if (ret != SD_NO_ERR)
	{
		SD_EndSD();
		return ret;
	}
	
    for (i = 0; i < blocknum; i++)
    {															
 		ret = SD_WriteBlockData(1, SD_BLOCKSIZE, sendbuf);		/* 写入数据 write data */
 		if (ret == SD_NO_ERR)	
 			sendbuf = sendbuf + SD_BLOCKSIZE;
 		else
 		{														/* 写失败 write fail */
			SD_StopTransmission();								/* 停止数据传输 stop data transmission */	
			SD_WaitBusy(SD_WAIT_WRITE);							/* 等待 waiting */
			SD_EndSD();
			return ret;
		}
	}
   
    SD_StopMultiToken();										/* 发送数据停止令牌 send data stop token */
      
    ret = SD_WaitBusy(SD_WAIT_WRITE);							/* 等待写入的完成 wait for finishing writing */
    if (ret != SD_NO_ERR)
    {
    	SD_EndSD();
    	return SD_ERR_TIMEOUT_WRITE;
    }
    
    if (sds.card_type == CARDTYPE_SD)
    {
   		ret = SD_GetNumWRBlcoks(&i);							/* 读正确写入的块数 read the blocks that be written correctly */
   		if (ret != SD_NO_ERR)
   		{
   			SD_EndSD();
   		  	return ret;
   		}
   		if(i != blocknum)
			ret =  SD_ERR_WRITE_BLKNUMS;						/* 正确写入块数错误 the blocks that be written correctly is error */
   	}
   	else
   	{
   	 	ret = SD_ReadCard_Status(2, tmp);
 		if (ret != SD_NO_ERR)
 		{
 			SD_EndSD();
 			return ret;											/* 读寄存器失败 read register fail */
		}
 		if((tmp[0] != 0) || (tmp[1] != 0))
			ret = SD_ERR_WRITE_BLK; 			     			/* 响应指示写失败 response indicate write fail */
   	}
   	 	
   	SD_EndSD();   	     
	return ret;													/* 返回写入成功 return write sucessfully */			
}
#endif

/*********************************************************************************************************************
** 函数名称: INT8U SD_EraseBlock()					Name:	  INT8U SD_EraseBlock()
** 功能描述: 擦除SD/MMC卡中的块						Function: Erase the block of SD/MMC card
** 输　  入: INT32U startaddr: 起始地址				Input:    INT32U startaddr: start address
			 INT32U endaddr  : 终止地址						  INT32U endaddr  : end address
** 输    出: 0:   成功    >0:  错误码				Output:	  0:  right			>0:  error code
** 注    意: startaddr 和 blocknum 建议为 sds.erase_unit 的整数倍, 因为有的卡只能以 sds.erase_unit 为单位进行擦除
*********************************************************************************************************************/
#if SD_EraseBlock_EN
INT8U SD_EraseBlock(INT32U startaddr, INT32U blocknum)
{
	INT32 tmp;
	INT8U ret;
	
	SD_StartSD();												/* 向OS申请访问卡信号量 request semaphore acessed SD/MMC to OS */
    if (SD_ChkCard() != 1)							
    {
    	SD_EndSD();	
    	return SD_ERR_NO_CARD;   								/* 卡没完全插入卡中 card is not inserted entirely */
	}
	
	if ((startaddr + blocknum) > sds.block_num)	
	{
		SD_EndSD();	
		return SD_ERR_OVER_CARDRANGE;							/* 操作超出卡容量范围 operate over the card range */
	}
		
	if (SD_ChkCardWP() == 1)
	{
		SD_EndSD();
		return SD_ERR_WRITE_PROTECT;							/* 卡有写保护 */
	}	

	tmp = blocknum - sds.erase_unit;	
	while(tmp >= 0) 												/* 每次擦除扇区 once erase is sector size */
	{	
		ret = SD_EraseStartBlock(startaddr);					/* 选择起始块地址 select start address */
		if (ret != SD_NO_ERR)
		{
			SD_EndSD();
			return ret;
		}
		
		ret = SD_EraseEndBlock(startaddr + sds.erase_unit - 1);		/* 选择终止块地址 select end address */
		if (ret != SD_NO_ERR)
		{
			SD_EndSD();
			return ret;
		}
			
		ret = SD_EraseSelectedBlock();							/* 擦除所选的块 erase blocks selected */
		if (ret != SD_NO_ERR)
		{
			SD_EndSD();
			return ret;
		}

		startaddr += sds.erase_unit;								/* 起始地址递增 */
		blocknum  -= sds.erase_unit;
		tmp = blocknum - sds.erase_unit;
	};		
	
	if (blocknum > 0)											/* 擦除不够once_erase块 */
	{															/* erase blocks that numbers is not enough once_erase */
		ret = SD_EraseStartBlock(startaddr);
		if (ret != SD_NO_ERR)
		{
			SD_EndSD();
			return ret;
		}
		
		ret = SD_EraseEndBlock(startaddr + blocknum - 1);
		if (ret != SD_NO_ERR)
		{
			SD_EndSD();
			return ret;
		}
			
		ret = SD_EraseSelectedBlock();
		if (ret != SD_NO_ERR)
		{
			SD_EndSD();
			return ret;
		}
	}

	SD_EndSD();
	return SD_NO_ERR;											/* 返回擦除成功 return erase sucessfully */
}
#endif


	/*****************************************************************
	
	    		下面为子程序
	 
	*****************************************************************/
/*******************************************************************************************************************
** 函数名称: INT8U SD_GetCardInfo()				Name:	  INT8U SD_GetCardInfo()
** 功能描述: 获得SD/MMC卡的信息					Function: get the information of SD/MMC card
** 输　  入: INT8U cardtype: 卡类型				Input:    INT8U cardtype: card type	
** 输    出: 0:   成功    >0:  错误码			Output:	  0:  right			>0:  error code
*******************************************************************************************************************/
INT8U SD_GetCardInfo()
{
	INT32U tmp;
	INT8U csdbuf[16],ret;

	ret = SD_ReadCSD(16, csdbuf);	 								    		/* 读CSD寄存器    read CSD register */
	if (ret != SD_NO_ERR)	
		return ret;	
		
	SD_CalTimeout(csdbuf);														/* 计算超时时间值 calculate timeout value */
		
	/* 计算块的最大长度  */														/* calculate the size of a sector */
	sds.block_len = 1 << (csdbuf[READ_BL_LEN_POS] & READ_BL_LEN_MSK);  			/* (2 ^ READ_BL_LEN) */
	
	/* 计算卡中块的个数 */														/* calculate the sector numbers of the SD Card */
	sds.block_num = ((csdbuf[C_SIZE_POS1] & C_SIZE_MSK1) << 10) +
	      			 (csdbuf[C_SIZE_POS2] << 2) +
	 	 			((csdbuf[C_SIZE_POS3] & C_SIZE_MSK3) >> 6) + 1;				/* (C_SIZE + 1)*/
		 	  															
	tmp = ((csdbuf[C_SIZE_MULT_POS1] & C_SIZE_MULT_MSK1) << 1) +   
	      ((csdbuf[C_SIZE_MULT_POS2] & C_SIZE_MULT_MSK2) >> 7) + 2;				/* (C_SIZE_MULT + 2) */
    	
    /* 获得卡中块的数量 */														/* get the block numbers in card */
	sds.block_num = sds.block_num * (1 << tmp);									/* (C_SIZE + 1) * 2 ^ (C_SIZE_MULT + 2) */
																			
	/* 计算擦除的单位(单位: 块) */	
	if (sds.card_type == CARDTYPE_MMC)
	{					    
		tmp  = ((csdbuf[ERASE_GRP_SIZE_POS] & ERASE_GRP_SIZE_MSK) >> 2) + 1;  	/* (ERASE_GRP_SIZE + 1)  */ 
		
		/* (ERASE_GRP_SIZE + 1) * (ERASE_GRP_MULTI + 1) */
		tmp *= ((csdbuf[ERASE_GRP_MULTI_POS1] & ERASE_GRP_MULTI_MSK1) << 3) +
		       ((csdbuf[ERASE_GRP_MULTI_POS2] & ERASE_GRP_MULTI_MSK2) >> 5) + 1;	
	}
	else																		/*calculate the size of sector */
		tmp = ((csdbuf[SECTOR_SIZE_POS1] & SECTOR_SIZE_MSK1) << 1) +  			
	          ((csdbuf[SECTOR_SIZE_POS2] & SECTOR_SIZE_MSK2) >> 7) + 1;			/* SD: SECTOR_SIZE */
	
	sds.erase_unit = tmp;	    												/* 擦除单位(块) */ 
	
	return SD_NO_ERR;															/* 返回执行成功 return perform sucessfully */
}


/*******************************************************************************************************************
** 函数名称: INT8U SD_CalTimeout()				Name:	  INT8U SD_CalTimeout()
** 功能描述: 计算读/写/擦超时时间				Function: calculate timeout of reading,writing,erasing
** 输　  入: INT8U *csdbuf : CSD寄存器内容		Input: 	  INT8U *csdbuf : CSD register content
** 输    出: 0:   成功    >0:  错误码			Output:	  0:  right			>0:  error code
*******************************************************************************************************************/
INT8U SD_CalTimeout(INT8U *csdbuf)
{
	INT32U tmp;
	INT8U time_u,time_v,fator;
	
	sds.timeout_read = READ_TIMEOUT_100MS;								/* 默认读超时为100ms */
	sds.timeout_write = WRITE_TIMEOUT_250MS;							/* 默认写超时为250ms */
	sds.timeout_erase = WRITE_TIMEOUT_250MS;
		
	time_u = (csdbuf[TAAC_POS] & TAAC_MSK);								/* 读超时时间单位 read timeout unit */
	time_v = (csdbuf[TAAC_POS] & NSAC_MSK) >> 3;						/* 读超时时间值   read timeout value */
	fator = (csdbuf[R2WFACTOR_POS] & R2WFACTOR_MSK) >> 2;				/* 读超时时间因数 read timeout factor */
	
	if(time_v == 0)	return SD_ERR_CARD_PARAM;							/* 卡参数有错误 card parameter is error */
	
	tmp = SPI_CLOCK * time_value[time_v] / 10 / time_unit[time_u];		/* TACC * f (单位 unit: clock) */
	tmp = tmp + csdbuf[NSAC_POS] * 100;									/* TACC * f + NSAC * 100 (单位 unit: clock) */
	
	/* 计算得到的超时值 the timeout value of being calculated */
	sds.timeout_read = tmp;
	sds.timeout_write = tmp * r2w_fator[fator];							/* (TACC * f + NSAC * 100) * R2WFACTOR (单位 unit:clock)*/
	
	if (sds.card_type == CARDTYPE_SD)
	{
		sds.timeout_read  = sds.timeout_read * 100 / 8;					/* 实际值为计算值的100倍 */
		sds.timeout_write = sds.timeout_write * 100 / 8;
		if (sds.timeout_read > READ_TIMEOUT_100MS)						/* 取计算值与默认值中的最小值 */
			sds.timeout_read = READ_TIMEOUT_100MS;
		
		if (sds.timeout_write > WRITE_TIMEOUT_250MS)
			sds.timeout_write = WRITE_TIMEOUT_250MS;
	}
	else
	{
		sds.timeout_read  = sds.timeout_read * 10 / 8;					/* 实际值为计算值的10倍 */
		sds.timeout_write = sds.timeout_write * 10 / 8;
	}
	
	sds.timeout_erase = sds.timeout_write;
	
#if SD_UCOSII_EN
	sds.timeout_read = (sds.timeout_read << 3) * OS_TICKS_PER_SEC / SPI_CLOCK; 
	sds.timeout_write =(sds.timeout_write << 3) * OS_TICKS_PER_SEC / SPI_CLOCK;
	sds.timeout_erase = sds.timeout_write;								/* (单位 unit: os tick) */
#endif	
	
	return SD_NO_ERR;	
}

/*******************************************************************************************************************
** 函数名称: INT8U SD_ActiveInit()				Name:	  INT8U SD_ActiveInit()
** 功能描述: 激活卡,并获得卡型					Function: active card, and get the card type 
** 输　  入: 无								 	Input:    NULL
** 输    出: 0:   成功    >0:  错误码			Output:	  0:  right			>0:  error code
** 函数说明: 该命令不断重复发送到SD卡，直到响应R1的Bit0(Idle)位为0，表示SD卡内部初始化处理完成。
		     当响应的Idle位为0时，SD卡就完全进入SPI模式了。当然重复发送命令CMD1是有次数限制的，
		     最大次数为宏定义SD_IDLE_WAIT_MAX.
*******************************************************************************************************************/
INT8U SD_ActiveInit(void)
{
	INT8U param[4] = {0,0,0,0},resp[5],ret;
	INT32U i = 0;
	
 	do 
    {														/* 发出CMD1, 查询卡的状态, send CMD1 to poll card status */
        ret = SD_SendCmd(CMD1, param, CMD1_R, resp);
        if (ret != SD_NO_ERR)
       		return ret;
        i ++;
    }while (((resp[0] & MSK_IDLE) == MSK_IDLE) && (i <= SD_IDLE_WAIT_MAX));
    														/* 如果响应R1的最低位Idle位为1,则继续循环 */
    														/* if response R1 Idle bit is 1,continue recycle */    
    if (i >= SD_IDLE_WAIT_MAX)
        return SD_ERR_TIMEOUT_WAITIDLE;						/* 超时,返回错误 time out,return error */	
	
    ret = SD_SendCmd(CMD55, param, CMD55_R, resp);
    if (ret != SD_NO_ERR)
       	return ret;
       	
    ret = SD_SendCmd(ACMD41, param, ACMD41_R, resp);		/* 激活内部初始化命令 active card to initialize process internal */
    if (ret != SD_NO_ERR)	
    	return SD_ERR_UNKNOWN_CARD;
    
    if ((resp[0] & 0xFE) == 0)
      	sds.card_type = CARDTYPE_SD;						/* 是SD卡 the card is SD card */	
    else	
    	sds.card_type = CARDTYPE_MMC;						/* 是MMC卡 the card is MMC card */

	return SD_NO_ERR;
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
	INT8U ret;
	
	OSSemPend(pSemSD, 0, &ret);					/* 等待访问卡信号量可用 wait for semaphore that accessed Card */
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
	OSSemPost(pSemSD);							/* 将访问卡信号量还给操作系统 return the semaphore accessing Card to OS */
#endif
}	


/*******************************************************************************************************************
** 函数名称: INT16U SD_GetZLGSDVer()			Name:	  INT16U SD_GetZLGSDVer()
** 功能描述: 得到ZLG/SD的版本号					Function: get the version of ZLG/SD
** 输　  入: 无									Input:    NULL
** 输 　 出: 版本号								Output:	  Version
** 版本记录:
			 V1.0   支持访问SD 卡,只能在前后台系统运行
			 
			 V2.0   支持访问SD和MMC卡,可运行于前后系统或UCOS-II
*******************************************************************************************************************/
INT16U SD_GetZLGSDVer(void)
{
	return 0x0200;						/* 版本号为 2.00 */
}











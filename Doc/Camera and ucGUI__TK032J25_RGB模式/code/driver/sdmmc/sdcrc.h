/****************************************Copyright (c)**************************************************
**                                 Co.,LTD.
**                                     
**                                 http://
**
**--------------File Info-------------------------------------------------------------------------------
** File name:			sdcrc.h
** Last modified Date:	2007-10-15
** Last Version:		V1.0
** Descriptions:		SD/MMC卡读写模块: 相关工具函数 ---- CRC校验头文件
**						Soft Packet of SD/MMC Card: tool funcitons  ---- crc check header file
**
**------------------------------------------------------------------------------------------------------
** Created by:			lhlzjut@hotmail.com
** Created date:		2007-10-15
** Version:				V1.0
** Descriptions:		The original version
**
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/

#ifndef __SDCRC_H__
#define __SDCRC_H__

#include "sdconfig.h"

extern INT16U SD_GetCRC16(INT8U *pSource,INT16U len);	//得到len个字节的CRC16

extern INT8U SD_GetCmdByte6(INT8U cmd,INT8U *param);	//得到SD命令的第6个字节: CRC7 + 停止位1

extern INT8U SD_GetCRC7(INT8U *pSource,INT16U len);		//得到len个字节的CRC7

#endif


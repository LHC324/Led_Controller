/*
 * myflash.h
 *
 *  Created on: 2021年07月31日
 *      Author: LHC
 */

/*
 *@note:STM32F103C8T6的Flash有效容量为64KB，但是实际可以使用超过64KB，上限是128KB
 */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_

#include "main.h"
/* Base address of the Flash sectors */
#define ADDR_FLASH_SECTOR_0 ((uint32_t)0x08000000)  /* Base @ of Sector 0, 16 Kbyte */
#define ADDR_FLASH_SECTOR_1 ((uint32_t)0x08004000)  /* Base @ of Sector 1, 16 Kbyte */
#define ADDR_FLASH_SECTOR_2 ((uint32_t)0x08008000)  /* Base @ of Sector 2, 16 Kbyte */
#define ADDR_FLASH_SECTOR_3 ((uint32_t)0x0800C000)  /* Base @ of Sector 3, 16 Kbyte */
#define ADDR_FLASH_SECTOR_4 ((uint32_t)0x08010000)  /* Base @ of Sector 4, 64 Kbyte */
#define ADDR_FLASH_SECTOR_5 ((uint32_t)0x08020000)  /* Base @ of Sector 5, 128 Kbyte */
#define ADDR_FLASH_SECTOR_6 ((uint32_t)0x08040000)  /* Base @ of Sector 6, 128 Kbyte */
#define ADDR_FLASH_SECTOR_7 ((uint32_t)0x08060000)  /* Base @ of Sector 7, 128 Kbyte */
#define ADDR_FLASH_SECTOR_8 ((uint32_t)0x08080000)  /* Base @ of Sector 8, 128 Kbyte */
#define ADDR_FLASH_SECTOR_9 ((uint32_t)0x080A0000)  /* Base @ of Sector 9, 128 Kbyte */
#define ADDR_FLASH_SECTOR_10 ((uint32_t)0x080C0000) /* Base @ of Sector 10, 128 Kbyte */
#define ADDR_FLASH_SECTOR_11 ((uint32_t)0x080E0000) /* Base @ of Sector 11, 128 Kbyte */

/* FLASH大小：2048KB ,SRAM : 1024KB*/
#define STM32FLASH_SIZE 0x0807FFFFUL /*512KB*/

/* FLASH起始地址 */
#define STM32FLASH_BASE FLASH_BASE

/* FLASH结束地址:此芯片实际flah大小256k，但是使用了VET6的配置*/
#define STM32FLASH_END (STM32FLASH_BASE | STM32FLASH_SIZE)

/* Last Page Address */
#define USER_FLASH_LAST_PAGE_ADDRESS (uint32_t)0x081FFFFF

/* FLASH页大小：2K */
#define STM32FLASH_PAGE_SIZE FLASH_PAGE_SIZE

/* FLASH总页数 */
#define STM32FLASH_PAGE_NUM (STM32FLASH_SIZE / STM32FLASH_PAGE_SIZE)

/* 获取页地址，X=0~STM32FLASH_PAGE_NUM */
#define ADDR_FLASH_PAGE_X(X) (STM32FLASH_BASE | (X * STM32FLASH_PAGE_SIZE))

/*函数声明*/
extern void MX_FLASH_Init(void);
extern bool FLASH_Read(uint32_t Address, void *Buffer, uint32_t Size);
extern uint32_t FLASH_Write(uint32_t Address, const uint32_t *pBuf, uint32_t Size);

#endif /* INC_FLASH_H_ */

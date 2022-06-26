/*
 * myflash.c
 *
 *  Created on: 2022年01月23日
 *      Author: LHC
 */

#include "Flash.h"
#include "string.h"

/*===================================================================================*/
/* Flash 分配
 * @用户flash区域：0-7页(256KB/扇区)
 * @系统参数区： 7扇区
 * @校准系数存放区域：None
 */
/*===================================================================================*/

/*
 *  初始化FLASH
 */
void MX_FLASH_Init(void)
{
	HAL_FLASH_Unlock();
	/* Clear pending flags (if any) */
	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
						   FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR);
	HAL_FLASH_Lock();
}

/**
 * 读FLASH
 * @param  Address 地址
 * @note   为了兼容各种数据类型，按字节读取
 * @param  pBuf  存放读取的数据
 * @param  Size    要读取的数据大小，单位字节
 * @return         读出成功的字节数
 */
bool FLASH_Read(uint32_t Address, void *pBuf, uint32_t Size)
{
	for (uint8_t *pdata = (uint8_t *)pBuf; pdata < (uint8_t *)pBuf + Size; pdata++)
	{
		*pdata = *(__IO uint32_t *)Address++;
	}
	return true;
}

/**
 * @brief  Gets the sector of a given address
 * @param  Address: Flash address
 * @retval The sector of a given address
 */
static uint32_t GetSector(uint32_t Address)
{
	uint32_t sector = 0;

	if ((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
	{
		sector = FLASH_SECTOR_0;
	}
	else if ((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
	{
		sector = FLASH_SECTOR_1;
	}
	else if ((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
	{
		sector = FLASH_SECTOR_2;
	}
	else if ((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
	{
		sector = FLASH_SECTOR_3;
	}
	else if ((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
	{
		sector = FLASH_SECTOR_4;
	}
	else if ((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5))
	{
		sector = FLASH_SECTOR_5;
	}
	else if ((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6))
	{
		sector = FLASH_SECTOR_6;
	}
	else
	{
		sector = FLASH_SECTOR_7;
	}
	return sector;
}

/**
 * 写FLASH
 * @param  Address    写入起始地址，！！！要求4字节对齐！！！
 * @param  pBuf     待写入的数据，！！！要求4字节对齐！！！
 * @param  Size 要写入的数据量，单位：半字，！！！要求4字节对齐！！！
 * @return            实际写入的数据量，单位：字节
 */
uint32_t FLASH_Write(uint32_t Address, const uint32_t *pBuf, uint32_t Size)
{
#define FLASH_WRITE_SIZE 4U
	/*初始化FLASH_EraseInitTypeDef*/
	FLASH_EraseInitTypeDef pEraseInit;
	/* Get the sector where start the user flash area */
	uint32_t FirstSector = GetSector(Address);
	/*设置SectorError*/
	uint32_t SectorError = 0;

	/* 非法地址 */
	if ((Address < STM32FLASH_BASE) || (Address > STM32FLASH_END) ||
		(Size == 0) || (pBuf == NULL) || (Address % FLASH_WRITE_SIZE))
		return false;
	/*关闭中断*/
	// __set_FAULTMASK(1);
	__disable_irq();
	/*1、解锁FLASH*/
	HAL_FLASH_Unlock();
	/*2、擦除FLASH*/
	pEraseInit.TypeErase = FLASH_TYPEERASE_SECTORS;
	pEraseInit.Sector = FirstSector;
	// pEraseInit.NbSectors = FLASH_If_GetSectorNumber(USER_FLASH_LAST_PAGE_ADDRESS) - FirstSector + 1; // 8 - FirstSector;
	pEraseInit.NbSectors = 1;
	pEraseInit.VoltageRange = FLASH_VOLTAGE_RANGE_3;
	/*清除flash标志位*/
	__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
						   FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR);

	if (HAL_FLASHEx_Erase(&pEraseInit, &SectorError) != HAL_OK)
	{
		/* Error occurred while page erase */
		goto __exit;
	}
	/*3、对FLASH烧写*/
	/*size是按字节，写入是按4字*/
	for (uint32_t *p = (uint32_t *)pBuf, addr = Address; addr < Address + Size; p++, addr += FLASH_WRITE_SIZE)
	{
		/* Device voltage range supposed to be [2.7V to 3.6V], the operation will
		be done by word */
		if (HAL_FLASH_Program(TYPEPROGRAM_WORD, addr, *p) == HAL_OK)
		{
			/* Check the written value */
			if (*(__IO uint32_t *)(addr) != *p)
			{
				/* Flash content doesn't match SRAM content */
				SectorError = 0x5AA5;
				break;
			}
		}
		else
		{
			/* Error occurred while writing data in Flash memory */
			SectorError = 0xA55A;
			break;
		}
	}
__exit:
	/*Check for ECC errors and clear the flash error caused by ECC verification*/
	// if ((!__HAL_FLASH_GET_FLAG(FLASH_SR_SNECCERR)) && (SectorError <= FLASH_SECTOR_7))
	// {
	// 	FLASH_Erase_Sector(SectorError, pEraseInit.Banks, pEraseInit.VoltageRange);

	// 	/* Wait for last operation to be completed */
	// 	FLASH_WaitForLastOperation(50000, FLASH_BANK_2);

	// 	/* If the erase operation is completed, disable the SER Bit */
	// 	FLASH->CR2 &= (~(FLASH_CR_SER | FLASH_CR_SNB));
	// 	/* Mass erase to be done */
	// 	// FLASH_MassErase(pEraseInit.VoltageRange, SectorError);

	// 	__HAL_FLASH_CLEAR_FLAG(FLASH_SR_SNECCERR);
	// }
	/*4、锁住FLASH*/
	HAL_FLASH_Lock();
	/*打开中断*/
	// __set_FAULTMASK(0);
	__enable_irq();

	return SectorError;
}

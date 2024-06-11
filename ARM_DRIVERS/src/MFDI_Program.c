/*
 * MFLASH_Program.c
 *
 *  Created on: May 23, 2024
 *      Author: Ibrahim Salman
 */
/************************************************************************/
/*							FILES INCLUSIONS							*/
/************************************************************************/
/*******************************LIB**************************************/
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"


/******************************* MCAL ***********************************/
#include "../include/MCAL/MFDI/MFDI_Interface.h"
#include "../include/MCAL/MFDI/MFDI_Private.h"
#include "../include/MCAL/MFDI/MFDI_Config.h"

void MFDI_voidEraseSector(char copy_u8SectorNum)
{
	//Wait Busy flag to be not raised
	while(GET_BIT(FDI->SR,FLASH_SR_BSY) == FLAG_SET);

	//Check CR Locked or not
	if(GET_BIT(FDI->CR,FLASH_CR_LOCK) == FLAG_SET)
	{
		FDI->KEYR = FLASH_KEY1;
		FDI->KEYR = FLASH_KEY2;
	}
	else
	{
		/*Do Nothing*/
	}

	//Set Sector number
	FDI->CR &= ~(FOUR_BIT_MASK<<FLASH_CR_SNB);
	FDI->CR |= (copy_u8SectorNum<<FLASH_CR_SNB);

	//Activate Sector Erase Mode
	SET_BIT(FDI->CR,FLASH_CR_SER);
	CLR_BIT(FDI->CR,FLASH_CR_MER);

	//Start	Operating
	SET_BIT(FDI->CR,FLASH_CR_STRT);

	//Wait Busy flag to be not raised
	while(GET_BIT(FDI->SR,FLASH_SR_BSY) == FLAG_SET);

	//Clear End of Operation Flag
	SET_BIT(FDI->SR,FLASH_SR_EOP);

	//Deactivate the operated mode
	CLR_BIT(FDI->CR,FLASH_CR_SER);
}

void MFDI_voidEraseAppSector(void)
{
	u8 Local_u8Counter;
	for(Local_u8Counter=1;Local_u8Counter<6;Local_u8Counter++)
	{
		FMFDI_voidEraseSector(Local_u8Counter);
	}
}

void MFDI_voidWrite(int copy_u32Address, short *copy_u16ptData,char copy_u8Length)
{
	u8 Local_u8Counter;
	//Wait Busy flag to be not raised
	while(GET_BIT(FDI->SR,FLASH_SR_BSY) == FLAG_SET);

	//Check CR Locked or not
	if(GET_BIT(FDI->CR,FLASH_CR_LOCK) == FLAG_SET)
	{
		FDI->KEYR = FLASH_KEY1;
		FDI->KEYR = FLASH_KEY2;
	}

	//Select the Word Mode  [HW in our case]
	FDI->CR &= ~(TWO_BIT_MASK<<FLASH_CR_PSIZE);
	FDI->CR |= (WRITE_HW_ACCESS<<FLASH_CR_PSIZE);

	for(Local_u8Counter=0;Local_u8Counter<copy_u8Length;Local_u8Counter++)
	{
		/*Set Programming mode Bit*/
		SET_BIT(FDI->CR,FLASH_CR_PG);

		/*Copy the Data*/
		*((u16*)copy_u32Address) = copy_u16ptData[Local_u8Counter];

		/*Increment the address*/
		copy_u32Address += 2;

		/*Wait Busy flag to be not raised*/
		while(GET_BIT(FDI->SR,FLASH_SR_BSY) == FLAG_SET);

		/*Clear End of Operation Flag*/
		SET_BIT(FDI->SR,FLASH_SR_EOP);

		/*Deactivate Programming mode Bit*/
		CLR_BIT(FDI->CR,FLASH_CR_PG);
	}
}

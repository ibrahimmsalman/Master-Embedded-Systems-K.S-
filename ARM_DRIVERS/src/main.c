/************************************************************************************************/
/*										FILE INCLUSION											*/
/************************************************************************************************/

/***********************LIB*************************/
#include <MCAL/MFDI/MFDI_Interface.h>
#include "../include/LIB/Std_Types.h"
#include "../include/LIB/BIT_MATH.h"

/************************MCAL***********************/
#include "../include/MCAL/MRCC/MRCC_Interface.h"
#include "../include/MCAL/MSYSTICK/MSYSTICK_Interface.h"
#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MSPI/MSPI_Interface.h"
#include "../include/MCAL/MNVIC/MNVIC_Interface.h"
#include "../include/MCAL/MDMA/MDMA_Interface.h"
#include "../include/AHEXAPARING_Interface.h"
/************************HAL************************/

/**********************MACROS************************/


/********************Global Variables****************/
/*Variable*/

/************************************************************************/
/*							FUNCTIONS DECLARATION						*/
/************************************************************************/


/************************************************************************/
/*							ENTRY POINT <main>							*/
/************************************************************************/


void main(void)
{
	/***********************Local Variable*************************/

	/***********************Clock initialization*************************/
	/* Enable RCC */
	MRCC_voidInit();

	/* Clocks to usage Peripherals Enable (use RCC) */
	//MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(RCC_AHB1_LP,RCC_AHB1_LP_FLASH);

	u16 Data[3] = { 0x30, 0x31, 0x32};
	MFDI_voidWrite(0x8004000,Data,3);
	Parse_voidRecord(":1040000000000120C5420008CB420008CF42000852");
	/**********************Pins initialization**************************/
	/**********************Peripherals initialization**************************/
	/* Enable SYSTICK */

	/**********************Operation Code*****************************/
	while(1)
	{

	}
}


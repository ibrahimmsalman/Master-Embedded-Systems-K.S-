
/*										FILE INCLUSION											*/
/************************************************************************************************/
/***********************LIB*************************/

#include "../include/LIB/BIT_Math.h"
#include "../include/LIB/STD_Types.h"

/***********************MCAL*************************/
#include "HAL/HDAC/HDAC_Config.h"
#include "HAL/HDAC/HDAC_Interface.h"
#include "HAL/HDAC/HDAC_Private.h"

#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MSYSTICK/MSYSTICK_Interface.h"

/****************************HAL***************************/


/***********************Global Variable*************************/
const u8* Global_u8pTrack = NULL;
u32	Global_u32MaxArrayIndex = 0;


/************************************************************************/
/*						   FUNCTIONS DEFINITIONS						*/
/************************************************************************/

static void HDAC_voidOperate(void)
{
	static u32 Local_u32counter = 0;
	MGPIO_voidSetPortValue_Byte(DAC_PORT,Global_u8pTrack[Local_u32counter]);
	Local_u32counter++;
	if(Local_u32counter == Global_u32MaxArrayIndex)
	{
		Local_u32counter = 0;
	}
}




void HDAC_voidInit(void)
{
	u8 Local_u8Counter=0;
	for(Local_u8Counter=DAC_PINS_INIT;Local_u8Counter<=DAC_PINS_END;Local_u8Counter++){

		MGPIO_voidSetPinMode(DAC_PORT,Local_u8Counter,GPIO_OUTPUT);
		MGPIO_voidSetPinOutputMode(DAC_PORT,Local_u8Counter,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	}
}

void HDAC_voidSet(const u8* copy_u8Trackptr, u32 copy_u32ArrayMaxIndex)
{
	Global_u8pTrack = copy_u8Trackptr;
	Global_u32MaxArrayIndex = copy_u32ArrayMaxIndex;
}


void HDAC_voidStart(void)
{
	MSYSTICK_voidSetPeriodicInterval_us(SAMPLE_RATE,HDAC_voidOperate);
}

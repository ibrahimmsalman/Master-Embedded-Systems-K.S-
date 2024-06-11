/************************************************************************************************/
/*										FILE INCLUSION											*/
/************************************************************************************************/
/***********************LIB*************************/
#include "../include/LIB/Std_Types.h"
#include "../include/LIB/BIT_Math.h"
#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MSPI/MSPI_Interface.h"
#include "../include/MCAL/MSYSTICK/MSYSTICK_Interface.h"
/****************************HAL***************************/
#include "../include/HAL/HTFT/HTFT_Config.h"
#include "../include/HAL/HTFT/HTFT_Interface.h"
#include "../include/HAL/HTFT/HTFT_Private.h"


/************************************************************************/
/*						   FUNCTIONS DEFINITIONS						*/
/************************************************************************/
static void HTFT_voidSPIInit (void)
{
	MGPIO_voidSetPinMode(SPI_PORT,SDK_PIN,GPIO_ALT_FUNC);
	MGPIO_voidSetPinAlternateFunctionMode(SPI_PORT,SDK_PIN,GPIO_SPI1_AF);

	MGPIO_voidSetPinMode(SPI_PORT,SCK_PIN,GPIO_ALT_FUNC);
	MGPIO_voidSetPinAlternateFunctionMode(SPI_PORT,SCK_PIN,GPIO_SPI1_AF);

	MGPIO_voidSetPinMode(SPI_PORT,NSS_PIN,GPIO_ALT_FUNC);
	MGPIO_voidSetPinAlternateFunctionMode(SPI_PORT,NSS_PIN,GPIO_SPI1_AF);

	MSPI_VoidInit();
}

static void HTFT_voidPinInit (void)
{
		MGPIO_voidSetPinMode(TFT_PORT,A0_PIN,GPIO_OUTPUT);
		MGPIO_voidSetPinOutputMode(TFT_PORT,A0_PIN,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);
		MGPIO_voidSetPinMode(TFT_PORT,RST_PIN,GPIO_OUTPUT);
		MGPIO_voidSetPinOutputMode(TFT_PORT,RST_PIN,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);
}

static void HTFT_voidSendCommand (u8 copy_u8Cmd)
{
	u8 Local_pu8Dummy=0;
	MGPIO_voidSetPinValue(TFT_PORT,A0_PIN,GPIO_PIN_LOW);
	MSPI_voidTranceive(copy_u8Cmd,&Local_pu8Dummy);
}

static void HTFT_voidSendData(u8 copy_u8Data)
{
	u8 Local_pu8Dummy=0;
	MGPIO_voidSetPinValue(TFT_PORT,A0_PIN,GPIO_PIN_HIGH);
	MSPI_voidTranceive(copy_u8Data,&Local_pu8Dummy);
}

static void HTFT_voidSendResetSequence(void)
{
	MGPIO_voidSetPinValue(TFT_PORT,RST_PIN,GPIO_PIN_HIGH);
	MSYSTICK_voidSetBusyWait_us(100);
	MGPIO_voidSetPinValue(TFT_PORT,RST_PIN,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait_us(1);

	MGPIO_voidSetPinValue(TFT_PORT,RST_PIN,GPIO_PIN_HIGH);
	MSYSTICK_voidSetBusyWait_us(100);
	MGPIO_voidSetPinValue(TFT_PORT,RST_PIN,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait_us(100);

	MGPIO_voidSetPinValue(TFT_PORT,RST_PIN,GPIO_PIN_HIGH);
	MSYSTICK_voidSetBusyWait_ms(120);
}

void HTFT_voidInit(void)
{
	HTFT_voidPinInit();
	//Initialise SPI
	HTFT_voidSPIInit();

	//Do Reset Sequence
	HTFT_voidSendResetSequence();

	//Sleep Out mode
	HTFT_voidSendCommand(0x11);
	MSYSTICK_voidSetBusyWait_ms(10);

	//Enter Colour Mode
	HTFT_voidSendCommand(0x3A);
	//Choose Colour Mode
	/*RGB 565*/
	HTFT_voidSendData(0x05);

	//Enter Display On Mode
	HTFT_voidSendCommand(0x29);
}

void HTFT_voidDisplayImg(const u16  *copy_pu16Data)
{
	u16 Local_u8Counter;
	u8 Local_u8LowByte,Local_u8HighByte;
	/*Set X-Axis Range*/
	HTFT_voidSendCommand(0x2A);
	HTFT_voidSendData(0);
	HTFT_voidSendData(X_AXIS_INIT+X_AXIS_IMG_LEFT_PAD);
	HTFT_voidSendData(0);
	HTFT_voidSendData(X_AXIS_END-X_AXIS_IMG_RIGHT_PAD);

	/*Set Y-Axis Range*/
	HTFT_voidSendCommand(0x2B);
	HTFT_voidSendData(0);
	HTFT_voidSendData(Y_AXIS_INIT+Y_AXIS_IMG_BOTTOM_PAD);
	HTFT_voidSendData(0);
	HTFT_voidSendData(Y_AXIS_END-Y_AXIS_IMG_UPPER_PAD);

	/*Set RAM Address*/
	HTFT_voidSendCommand(0x2C);
	for(Local_u8Counter=0;Local_u8Counter<PIXELS_MAX_NO;Local_u8Counter++)
	{
		Local_u8LowByte = (u8) copy_pu16Data[Local_u8Counter];
		Local_u8HighByte = (u8) (copy_pu16Data[Local_u8Counter] >>8);
		HTFT_voidSendData(Local_u8LowByte);
		HTFT_voidSendData(Local_u8HighByte);
	}
}

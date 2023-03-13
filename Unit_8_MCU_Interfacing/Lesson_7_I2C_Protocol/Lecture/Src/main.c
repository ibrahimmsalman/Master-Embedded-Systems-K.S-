/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "STM32F103x8.h"
#include "stm32f103x8_gpio_driver.h"
#include "lcd.h"
#include "keypad.h"
#include "stm32f103x8_EXTI_driver.h"
#include "stm32f103x8_USART_driver.h"
#include "stm32f103x8_RCC_driver.h"
#include "stm32f103x8_SPI_driver.h"

#define MCU_Act_As_Master
//#define MCU_Act_As_Slave

unsigned char ch;

void Clock_Init()
{
	//Enable Clock
	RCC_GPIOA_CLOCK_EN();
	RCC_GPIOB_CLOCK_EN();
	RCC_AFIO_CLOCK_EN();
}

void Mostafa_CallBack(void)
{
#ifdef MCU_Act_As_Master

	MCAL_UART_RECEIVE_DATA(USART1, &ch, disable);
	MCAL_UART_SEND_DATA(USART1, &ch, disable);
	//send to spi
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
	MCAL_SPI_TX_RX(SPI1, &ch, PollingEnable);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
#endif

}

int main(void)
{

	Clock_Init();

	//==========================UART INIT=============================
	/* PA9  TX
	 * PA10 RX
	 * PA11 CTC
	 * PA12 RTS
	 */
	USART_Config uartCFG;
	GPIO_Pin_Configure_t Config_pin;

	uartCFG.BaudRate = USART_BaudRate_115200;
	uartCFG.HW_FlowCtrl = USART_HW_FlowCtrl_NONE;
	uartCFG.IRQ_Enable = USART_IRQ_Enable_RXNE;
	uartCFG.P_IRQ_Call_Back = Mostafa_CallBack;
	uartCFG.Parity = USART_Parity_NONE;
	uartCFG.PayLoad_Length = USART_PayLoad_Length_8B;
	uartCFG.StopBits = USART_StopBits_1;
	uartCFG.USART_MODE = USART_MODE_RX_AND_TX;

	MCAL_UART_INIT(USART1, &uartCFG);

	MCAL_UART_GPIO_Set_Pins(USART1);


	//==========================SPI INIT=============================
	//PA4 : SPI1_NSS
	//PA5 : SPI1_SCK
	//PA6 : SPI1_MISO
	//PA7 : SPI1_MOSI

	SPI_Config_t SPI1CFG;
	//Common configration for master and slave
	SPI1CFG.CLK_Phase = SPI_CLK_Phase_2Edge_First_Data_Capture_Edge;
	SPI1CFG.CLK_Polarity = SPI_CLK_Polarity_High_Idle;
	SPI1CFG.Date_Size = SPI_Data_Size_8Bit_Mode;
	SPI1CFG.Frame_Format = SPI_Frame_Format_MSB_First;
	//Assume by defult pclk2 = 8MHZ
	SPI1CFG.Baud_Rate_Prescaler = SPI_Baud_Rate_Prescaler_8;
	SPI1CFG.Communication_Mode = SPI_communic_2_Line;

#ifdef MCU_Act_As_Master
	SPI1CFG.Device_Mode = SPI_Device_Mode_Master;
	SPI1CFG.IRQ_Enable = SPI_IRQ_Enable_NONE;
	SPI1CFG.NSS = SPI_NSS_Soft_NSSIternal_Set;
	SPI1CFG.P_IRQ_CallBack = NULL;

#endif

	MCAL_SPI_INIT(SPI1, &SPI1CFG);
	MCAL_SPI_GPIO_SET_PINS(SPI1);

	//Configure SS on PortA pin4 by GPIO
	Config_pin.GPIO_Pin_Number=GPIO_PIN_4;
	Config_pin.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	Config_pin.GPIO_OUTPUT_SPEED=GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &Config_pin);

	//Force the Slave Select (High) idle Mode
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);

	while(1)
	{


	}

	return 0;

}

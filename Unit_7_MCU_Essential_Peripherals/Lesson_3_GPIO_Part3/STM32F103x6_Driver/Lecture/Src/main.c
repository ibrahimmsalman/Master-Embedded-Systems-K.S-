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

#include "STM32F103x8.h"
#include "STM32F103x8_gpio_driver.h"

void clock_init()
{
	// Enable clock GPIOA
	RCC_GPIOA_CLK_EN();

	// Enable clock GPIOB
	RCC_GPIOB_CLK_EN();
}

void GPIO_init()
{
	GPIO_PinConfig_t PinConfig;

    // Configure PA1 as input floating
	PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinConfig);

    // Configure PA13 as input floating
	PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinConfig);

    // Configure PB1 as output push-pull
	PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);

    // Configure PB13 as output push-pull
	PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinConfig);
}

void delay(int delay)
{
	uint32_t i,j;

	for (i = 0; i < delay; i++)
	{
		for(j = 0; j < 255 ; j++);
	}
}

int main(void)
{
	clock_init();
	GPIO_init();

	while(1)
	{
		if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0) // Press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0); // Single-press
		}

		if (MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1) // Multi-presses
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}
		delay(1);
	}
}

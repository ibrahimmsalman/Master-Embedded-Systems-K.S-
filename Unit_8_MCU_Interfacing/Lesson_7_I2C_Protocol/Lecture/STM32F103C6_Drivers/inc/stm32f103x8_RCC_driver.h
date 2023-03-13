/*
 * stm32f103x8_RCC_driver.h
 *
 *  Created on: Mar 13, 2023
 *      Author: Ibrahim Salman
 */

#ifndef INC_STM32F103X8_RCC_DRIVER_H_
#define INC_STM32F103X8_RCC_DRIVER_H_

//includes
#include "STM32F103x8.h"



#define  HSE_Clock			(uint32_t)16000000
#define  HSI_RC_Clk			(uint32_t)8000000


uint32_t MCAL_RCC_GetSYS_CLCKFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);


#endif /* INC_STM32F103X8_RCC_DRIVER_H_ */

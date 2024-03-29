/*
 * LED.h
 *
 *  Created on: Mar 10, 2023
 *      Author: Ibrahim Salman
 */

#ifndef INC_LED_H_
#define INC_LED_H_

#include "STM32F103x8_gpio_driver.h"

typedef struct
{
	GPIO_PinConfig_t *LED_Config;
	uint8_t PinState ;
}LED_Data_t;



#define LED_OFF 	0
#define LED_ON		1


/**================================================================
 * @Fn				- HAL_LED_init
 * @brief			- Configure where the led is connected in (Which port and which pin in this port) and initial state for the led
 * @param [in] 		- LED_Config: which contain (GPIO_PinNumber, GPIO_MODE, GPIO_OUTPUT_SPEED)
 * @param [in] 		- PinState: State of the pin @ref GPIO_PIN_state
 * @retval 			- None
 * Note				- None
 */
void HAL_LED_init(LED_Data_t* LED_init);


#endif /* INC_LED_H_ */

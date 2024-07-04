/*
 * HICU_Private.h
 *
 *  Created on: Apr 1, 2024
 *      Author: Admin
 */

#ifndef HAL_HICU_HICU_PRIVATE_H_
#define HAL_HICU_HICU_PRIVATE_H_

/*****************************Options for TIMER******************************************/
#define ATTACHED_TO_TIM0			1
#define ATTACHED_TO_TIM1			2
#define ATTACHED_TO_TIM2			3

/*****************************Options for EXTI*****************************************/
#define ATTACHED_TO_EXTI0			1
#define ATTACHED_TO_EXTI1			2
#define ATTACHED_TO_EXTI2			3

/*****************************Options for MODES*****************************************/
#define FIRST_RISING	0
#define FALLING			1
#define SECOND_RISING	2

/*****************************Private Function*****************************************/
static void HICU_voidOpration(void);


#endif /* HAL_HICU_HICU_PRIVATE_H_ */

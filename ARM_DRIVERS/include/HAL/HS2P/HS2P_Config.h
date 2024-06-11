/*
 * S2P_Config.h
 *
 *  Created on: May 12, 2024
 *      Author: Admin
 */

#ifndef S2P_CONFIG_H_
#define S2P_CONFIG_H_

/*
 *GPIO_PORTA
 *GPIO_PORTB
 *GPIO_PORTC
 */

/*
 * GPIO_PIN0
 * GPIO_PIN1
 * GPIO_PIN2
 */

#define S2P_DS_PORT						GPIO_PORTA
#define S2P_DS_PIN						GPIO_PIN0

#define S2P_SH_CLK_PORT					GPIO_PORTA
#define S2P_SH_CLK_PIN					GPIO_PIN2

#define S2P_STRG_CLK_PORT				GPIO_PORTA
#define S2P_STRG_CLK_PIN				GPIO_PIN1

#define S2P_RST_PORT					GPIO_PORTA
#define S2P_RST_PIN						GPIO_PIN3

#define S2P_ENABLE_PORT					GPIO_PORTA
#define S2P_ENABLE_PIN					GPIO_PIN4


#endif /* S2P_CONFIG_H_ */

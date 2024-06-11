/*
 * HTFT_Private.h
 *
 *  Created on: 14 May 2024
 *      Author: User
 */

#ifndef HTFT_PRIVATE_H_
#define HTFT_PRIVATE_H_


/*************************Private Macros*********************************/





/**********************************************************/
#define SPI1_ENABLE 							1
#define SPI2_ENABLE 							2
#define SPI3_ENABLE 							3


#if SPI_ENABLE_SELECT == SPI1_ENABLE
#define SPI_PORT		GPIO_PORTA
#define SDK_PIN			GPIO_PIN7
#define SCK_PIN			GPIO_PIN5
#define NSS_PIN			GPIO_PIN4
#elif SPI_ENABLE_SELECT == SPI2_ENABLE
#define SPI_PORT		GPIO_PORTB
#define SDK_PIN			GPIO_PIN15
#define SCK_PIN			GPIO_PIN13
#define NSS_PIN			GPIO_PIN12
#endif





#endif /* HTFT_PRIVATE_H_ */

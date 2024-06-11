/*
 * MGPIO_Private.h
 *
 *  Created on: Feb 1, 2024
 *      Author: Ibrahim
 */

#ifndef MNVIC_PRIVATE_H_
#define MNVIC_PRIVATE_H_


#define NVIC_BASE_ADDRESS		(0xE000E100)

typedef struct
{
	u32 ISER[8]		   ;
	u32 RESERVED1[24]  ;
	u32 ICER[8]		   ;
	u32 RESERVED2[24]  ;
	u32 ISPR[8]        ;
	u32 RESERVED3[24]  ;
	u32 ICPR[8]		   ;
	u32 RESERVED4[24]  ;
	u32 IABR[8]		   ;
	u32 RESERVED5[56]  ;
	u8  IPR[240]	   ;
	u32	RESERVED6[580] ;
	u32 STIR           ;
}NVIC_t;

#define NVIC		((volatile NVIC_t *)NVIC_BASE_ADDRESS)
#define SCB_AIRCR	(*(volatile u32 *)0xE000ED0C)

#define BITS_IN_REGISTERS				32

#define AICIR_PRIGROUP_B0				8
#define SCB_AIRCR_VECT_KEY			0x5FA00000
#define SCB_READ_VECTKEY			0xFA050000


#endif /* MNVIC_PRIVATE_H_ */


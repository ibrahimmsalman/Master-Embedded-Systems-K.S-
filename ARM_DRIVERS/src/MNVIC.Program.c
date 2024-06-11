/*
 * MNVIC.Program.c
 *
 *  Created on: Apr 23, 2024
 *      Author: Admin
 */

/************************************************************************/
/*							FILES INCLUSIONS							*/
/************************************************************************/
/*******************************LIB**************************************/
#include "../include/LIB/BIT_Math.h"
#include "../include/LIB/STD_Types.h"


/******************************* MCAL ***********************************/
#include "../include/MCAL/MNVIC/MNVIC_Interface.h"
#include "../include/MCAL/MNVIC/MNVIC_private.h"
#include "../include/MCAL/MNVIC/MNVIC_Config.h"

static MNVIC_Group_t sglobal_NVIC_Group_t_Mode;

/************************************************************************/
/*						   FUNCTIONS DEFINITIONS						*/
/************************************************************************/

void MNVIC_voidEnablePeripheralInterrupt(u8 copy_u8Peripheral)
{
	// ISER is a register for enable due to atomic access
	SET_BIT(NVIC->ISER[copy_u8Peripheral / BITS_IN_REGISTERS] , (copy_u8Peripheral % BITS_IN_REGISTERS));

}

void MNVIC_voidDisablePeripheralInterrupt(u8 copy_u8Peripheral)
{
	// ICER is a register for disable due to atomic access
	SET_BIT(NVIC->ICER[copy_u8Peripheral / BITS_IN_REGISTERS] , (copy_u8Peripheral % BITS_IN_REGISTERS));
}

void MNVIC_voidEnablePeripheralInterruptPending(u8 copy_u8Peripheral)
{
	// ISPR is a register for enable pending flag due to atomic access , for testing purposes
	SET_BIT(NVIC->ISPR[copy_u8Peripheral / BITS_IN_REGISTERS] , (copy_u8Peripheral % BITS_IN_REGISTERS));
}

void MNVIC_voidDisablePeripheralInterruptPending(u8 copy_u8Peripheral)
{
	// ISPR is a register for disable pending flag due to atomic access , for testing purposes
	SET_BIT(NVIC->ICPR[copy_u8Peripheral / BITS_IN_REGISTERS] , (copy_u8Peripheral % BITS_IN_REGISTERS));
}

void MNVIC_voidGetInterruptState(u8 copy_u8Peripheral, u8 *p_Read)
{
	// IABR is a register for check /  read the Active flag
	*p_Read = GET_BIT(NVIC->IABR[copy_u8Peripheral / BITS_IN_REGISTERS] , (copy_u8Peripheral % BITS_IN_REGISTERS));
}

void MNVIC_voidSetInterruptGroupMode(MNVIC_Group_t MNVIC_GroupMode)
{
	// saving the chosen groups & subgroups choice to switch on it in the function which sets priority levels
	sglobal_NVIC_Group_t_Mode = MNVIC_GroupMode;

	SCB_AIRCR = (((u32)SCB_AIRCR_VECT_KEY << 16) | (MNVIC_GroupMode << AICIR_PRIGROUP_B0));

//	u32 reg_value ;
//	u32 PriorityGroupTmp = (MNVIC_GroupMode & (u32)0x07UL);
//	reg_value  =  SCB_AIRCR;                          	   /* read old register configuration    */
//	reg_value &= ~((u32)((0xFFFFUL << 16U) | (7U << 8U))); /* clear bits to change               */
//
//	/* Insert write key and priority group */
//	reg_value  =  (reg_value | ((u32)0x5FAUL << 16U) | (PriorityGroupTmp << 8U)  );
//	SCB_AIRCR  =  reg_value;
}


void MNVIC_voidSetInterruptPriority(u8 copy_u8Peripheral,u8 copy_u8GroupNumber, u8 copy_u8SubGroupNumber)
{
	switch(sglobal_NVIC_Group_t_Mode)
	{
	case Groups16_NoSub:
		NVIC->IPR[copy_u8Peripheral] = (copy_u8GroupNumber << 4);
		break;

	case Groups8_Sub2:
		NVIC->IPR[copy_u8Peripheral] = ((copy_u8GroupNumber << 5) | (copy_u8SubGroupNumber << 4));
		break;

	case Groups4_Sub4:
		NVIC->IPR[copy_u8Peripheral] = ((copy_u8GroupNumber << 6) | (copy_u8SubGroupNumber << 4));
		break;

	case Groups2_Sub8:
		NVIC->IPR[copy_u8Peripheral] = ((copy_u8GroupNumber << 7) | (copy_u8SubGroupNumber << 4));
		break;

	case NoGroup_Sub16:
		NVIC->IPR[copy_u8Peripheral] = ((copy_u8SubGroupNumber << 4));
		break;

	default:
		break;
	}
}




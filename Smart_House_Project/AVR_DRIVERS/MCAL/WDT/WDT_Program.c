/*
 * WDT_Program.c
 *
 *  Created on: Mar 31, 2024
 *      Author: Admin
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

#include "WDT_Private.h"
#include "WDT_Config.h"
#include "WDT_Interface.h"

void MWDT_SartWDT(u8 copy_u8Mode){
	switch(copy_u8Mode){
	case WDT_MODE16K:
		CLR_BIT(WDTCR_REG,WDP0);
		CLR_BIT(WDTCR_REG,WDP1);
		CLR_BIT(WDTCR_REG,WDP2);
		break;
	case WDT_MODE32K:
		SET_BIT(WDTCR_REG,WDP0);
		CLR_BIT(WDTCR_REG,WDP1);
		CLR_BIT(WDTCR_REG,WDP2);
		break;
	case WDT_MODE64K:
		CLR_BIT(WDTCR_REG,WDP0);
		SET_BIT(WDTCR_REG,WDP1);
		CLR_BIT(WDTCR_REG,WDP2);
		break;
	case WDT_MODE128K:
		SET_BIT(WDTCR_REG,WDP0);
		SET_BIT(WDTCR_REG,WDP1);
		CLR_BIT(WDTCR_REG,WDP2);
		break;
	case WDT_MODE256K:
		CLR_BIT(WDTCR_REG,WDP0);
		CLR_BIT(WDTCR_REG,WDP1);
		SET_BIT(WDTCR_REG,WDP2);
		break;
	case WDT_MODE512K:
		SET_BIT(WDTCR_REG,WDP0);
		CLR_BIT(WDTCR_REG,WDP1);
		SET_BIT(WDTCR_REG,WDP2);
		break;
	case WDT_MODE1024K:
		CLR_BIT(WDTCR_REG,WDP0);
		SET_BIT(WDTCR_REG,WDP1);
		SET_BIT(WDTCR_REG,WDP2);
		break;
	case WDT_MODE2048K:
		SET_BIT(WDTCR_REG,WDP0);
		SET_BIT(WDTCR_REG,WDP1);
		SET_BIT(WDTCR_REG,WDP2);
		break;
	}
	//start WDT
	SET_BIT(WDTCR_REG,WDE);
}

void MWDT_StopWDT(void){
	WDTCR_REG|=0x18;
	WDTCR_REG=0;
}


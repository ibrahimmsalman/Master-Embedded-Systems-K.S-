/*
 * MFALASH_Private.h
 *
 *  Created on: May 23, 2024
 *      Author: Ibrahim Salman
 */

#ifndef MFDI_PRIVATE_H_
#define MFDI_PRIVATE_H_


#define FDI_BASE_ADDRESS		0x40023C00


typedef struct{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 OPTCR;
}FDI_t;


#define FDI		((volatile FDI_t*)FDI_BASE_ADDRESS)


/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY                    0
#define FLASH_ACR_PRFTEN                     8
#define FLASH_ACR_ICEN                       9
#define FLASH_ACR_DCEN                       10
#define FLASH_ACR_ICRST                      11
#define FLASH_ACR_DCRST                      12

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_SR_EOP                         0
#define FLASH_SR_SOP                         1
#define FLASH_SR_WRPERR                      4
#define FLASH_SR_PGAERR                      5
#define FLASH_SR_PGPERR                      6
#define FLASH_SR_PGSERR                      7
#define FLASH_SR_BSY                         16

/*******************  Bits definition for FLASH_CR register  ******************/
#define FLASH_CR_PG                          0
#define FLASH_CR_SER                         1
#define FLASH_CR_MER                         2
#define FLASH_CR_SNB                         3
#define FLASH_CR_PSIZE                       8
#define FLASH_CR_STRT                        16
#define FLASH_CR_EOPIE                       24
#define FLASH_CR_LOCK                        31

/*******************  Bits definition for FLASH_OPTCR register  ***************/
#define FLASH_OPTCR_OPTLOCK                 0
#define FLASH_OPTCR_OPTSTRT                 1
#define FLASH_OPTCR_BOR_LEV                 2

#define FLASH_OPTCR_WDG_SW                  5
#define FLASH_OPTCR_nRST_STOP               6
#define FLASH_OPTCR_nRST_STDBY              7
#define FLASH_OPTCR_nWRP                    16
#define FLASH_OPTCR_SPRMODE                 31


/********************  Private Macros **********************************/
#define FLASH_KEY1		0x45670123
#define FLASH_KEY2		0xCDEF89AB

#define FOUR_BIT_MASK	0b1111
#define TWO_BIT_MASK	0b11

#define FLAG_SET		1
#define FLAG_RESET		0

#define WRITE_BYTE_ACCESS	0
#define WRITE_HW_ACCESS		1
#define WRITE_W_ACCESS		2
#define WRITE_DW_ACCESS		3

#endif /* MFLASH_PRIVATE_H_ */

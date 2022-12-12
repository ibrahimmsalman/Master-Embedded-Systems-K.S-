//learn-in-depth
//Ibrahim Salman
//Mastering Embedded system online diploma
typedef volatile unsigned int vuint32_t	;
#include <Platform_Types.h>
#include <stdint.h>
// register address
#define RCC_BASE    0x40021000
#define GPIOA_BASE  0x40010800
#define RCC_APB2ENR *(volatile uint32_t*)(RCC_BASE + 0x18)
#define GPIOA_CRH   *(volatile uint32_t*)(GPIOA_BASE + 0x04)
#define GPIOA_ODR   *(volatile uint32_t*)(GPIOA_BASE + 0x0c)
// bit fields
#define RCC_IOPAEN  (1<<2)
#define GPIOA13     (1UL<<13)

extern void NMI_Handlet (void)
{
	
}
extern void Bus_Fault(void)
{
	
}

typedef union {
	vuint32_t	all_fields;
	struct{
	vuint32_t	reserved:13;
	vuint32_t	p_13:1	;
	}Pin;
}R_ODR_t;

volatile	R_ODR_t*  R_ODR=	(volatile R_ODR_t*)(GPIOA_BASE + 0x0c)	;
unsigned char g_variables[3] = {1,2,3};
unsigned char const const_variables[3] = {1,2,3};

int main (void)
{
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;
	while(1)
	{
		R_ODR->Pin.P_13 =	1;
		for (int i = 0; i < 5000; i++);   //arbitrary delay
		R_ODR->Pin.P_13 = 0;
		for (int i = 0; i < 5000; i++);   //arbitrary delay
    }
return 0;
}
	
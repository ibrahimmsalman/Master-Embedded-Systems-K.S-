/*
 ============================================================================
 Name        : main.c
 Author      : Ibrahim Salman
 Description : First final project 
 ============================================================================
 */

#include "Platform_Types.h"
#include "utill.h"

#include "GPIO.h"
#include "Pressure_Sensor.h"
#include "Alarm_Actuator.h"
#include "Alarm_Monitor.h"
#include "Main_Program.h"

void (*PS_state)() = STATE(PS_INIT);
void (*ALARM_ACT_state)() = STATE(ALARM_ACT_INIT);
void (*ALARM_MON_state)() = STATE(ALARM_MON_ALARM_OFF);
void (*MP_state)() = STATE(MP_HIGH_PRESSURE);

int main(void)
{
	// Hardware Initialization
	GPIO_init();

	// Run State Machine Forever
	while (1)
	{
		PS_state();
		ALARM_ACT_state();
		ALARM_MON_state();
		MP_state();
	}

	return 0;
}
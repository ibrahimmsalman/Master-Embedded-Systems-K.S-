/*
 * Alarm_Actuator.h
 *
 * Created on : Feb 12, 2023
 *     Author : Ibrahim Salman     
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_

#include "state.h"

// Declare State Functions of Alarm Actuator
STATE_DEFINE(ALARM_ACT_INIT);
STATE_DEFINE(ALARM_ACT_WAITING);
STATE_DEFINE(ALARM_ACT_ON);
STATE_DEFINE(ALARM_ACT_OFF);

// State Pointer to function
extern void (*ALARM_ACT_state)();

#endif /* ALARM_ACTUATOR_H_ */
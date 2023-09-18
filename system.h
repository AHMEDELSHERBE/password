/*
 * system.h
 *
 * Created: 9/9/2023 8:52:44 PM
 *  Author: Yehia
 */ 
#ifndef SYSTEM_H
#define SYSTEM_H

#include "../HAL/led.h"
#include "../HAL/KEYPAD.h"
#include "../HAL/LCD.h"

#define LEDS_PORT 'D'
#define LED_ONE_PIN 6
#define LED_TWO_PIN 7

void system_voidInit(void);
void system_voidTurnOnLeds(void);
void system_voidTurnOffLeds(void);


#endif
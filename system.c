/*
 * system.c
 *
 * Created: 9/9/2023 8:52:16 PM
 *  Author: Yehia
 */ 
#include "system.h"
void system_voidInit(void){
	led_init();
	LCD_vidSendCommand(LCD_CLEAR_COMMAND);
	LCD_vidWriteString("1 for LEDS ON");
	LCD_vidSendCommand(0xC0);
	LCD_vidWriteString("2 for LEDS OFF");
}

void system_voidTurnOnLeds(void){
	led_on();
}
void system_voidTurnOffLeds(void){
	led_off();
}

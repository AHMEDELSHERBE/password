/*
 * LCD-Keypad.c
 *
 * Created: 8/30/2023 9:03:24 PM
 * Author : elsherbeny 
 */ 

//#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "APP/T1_LCD/HAL/KEYPAD.h"
#include "APP/T1_LCD/HAL/LCD.h"
#include "APP/T1_LCD/MCAL/gpio.h"
#include "APP/T1_LCD/HomeSystem/log_in.h"
#include "APP/T1_LCD/HomeSystem/system.h"
#include "APP/T2_TEMP/ADC/adc.h"

int main(void)
{
	//GPIO_setupPinDirection(PORTB_ID, PIN4_ID, PIN_OUTPUT);
	ADC_init();
    DIO_voidSetPinDirection(DIO_GROUP_D, DIO_PIN_6, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_GROUP_D, DIO_PIN_1, DIO_INPUT);
	DIO_voidSetPinDirection(DIO_GROUP_A, DIO_PIN_7, DIO_INPUT);
	DIO_voidSetPinDirection(DIO_GROUP_B, DIO_PIN_4, DIO_OUTPUT);
	DIO_voidSetPinValue(DIO_GROUP_B, DIO_PIN_4, DIO_LOW);
	DIO_voidSetPinValue(DIO_GROUP_D, DIO_PIN_6, DIO_LOW);
	DIO_voidSetPinValue(DIO_GROUP_D, DIO_PIN_7, DIO_LOW);
	Login_voidInit();
	while (Login_u8GetCompareFlag() != 0) {
		Login_voidEnterPassword();
		Login_voidCheckPassword();
	}
	system_voidInit();
	u8 key,privious=0;
	while(1){
		key = KEYPAD_u8GetPressedKey();
		/*while (privious==key){;}*/
		if(key == '1'){
			DIO_voidSetPinValue(DIO_GROUP_D, DIO_PIN_6, DIO_HIGH);
			DIO_voidSetPinValue(DIO_GROUP_D, DIO_PIN_7, DIO_HIGH);
		}
		else if(key == '2'){
			DIO_voidSetPinValue(DIO_GROUP_D, DIO_PIN_6, DIO_LOW);
			DIO_voidSetPinValue(DIO_GROUP_D, DIO_PIN_7, DIO_LOW);
		}
		privious=key;
		u32 ADC_Read = ADC_readChannel(1);
		if (ADC_Read >=61){
			DIO_voidSetPinValue(DIO_GROUP_B, DIO_PIN_4, DIO_HIGH);
			_delay_ms(500);
			DIO_voidSetPinValue(DIO_GROUP_B, DIO_PIN_4, DIO_LOW);
		}else{
			DIO_voidSetPinValue(DIO_GROUP_B, DIO_PIN_4, DIO_LOW);
		}
		
	}
}



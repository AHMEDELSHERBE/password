#include "led.h"
#include "../HAL/DIO_init.h"

void led_init(){
	DIO_voidSetPinDirection(DIO_GROUP_D, DIO_PIN_6, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_GROUP_D, DIO_PIN_7, DIO_OUTPUT);
	DIO_voidSetPinValue(DIO_GROUP_D, DIO_PIN_6, DIO_LOW);
	DIO_voidSetPinValue(DIO_GROUP_D, DIO_PIN_7, DIO_LOW);
}

void led_on(){
	DIO_voidSetPinValue(DIO_GROUP_D, DIO_PIN_6, DIO_HIGH);
	DIO_voidSetPinValue(DIO_GROUP_D, DIO_PIN_6, DIO_HIGH);

}
void led_off(){

		DIO_voidSetPinValue(DIO_GROUP_D, DIO_PIN_6, DIO_LOW);
		DIO_voidSetPinValue(DIO_GROUP_D, DIO_PIN_6, DIO_LOW);
}

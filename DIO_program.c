/*
 * DIO_program.c
 *
 *  Created on: 16 Jun 2023
 *      Author: george yaccoup
 */

#include "DIO_init.h"


void DIO_voidSetPinValue(u8 Copy_u8GroupID,u8 Copy_u8PinID,u8 Copy_u8PinValue){
	if (Copy_u8GroupID <= DIO_GROUP_D && Copy_u8PinID <= DIO_PIN_7
		&& Copy_u8PinValue <= DIO_HIGH) {
		switch (Copy_u8GroupID)
		{
		case DIO_GROUP_A:
			if (Copy_u8PinValue == DIO_LOW)
				PORTA &= ~(DIO_BIT_MASK << Copy_u8PinID);
			else
				PORTA |= (DIO_BIT_MASK << Copy_u8PinID);
			break;
		case DIO_GROUP_B:
			if (Copy_u8PinValue == DIO_LOW)
				PORTB &= ~(DIO_BIT_MASK << Copy_u8PinID);
			else
				PORTB |= (DIO_BIT_MASK << Copy_u8PinID);
			break;
		case DIO_GROUP_C:
			if (Copy_u8PinValue == DIO_LOW)
				PORTC &= ~(DIO_BIT_MASK << Copy_u8PinID);
			else
				PORTC |= (DIO_BIT_MASK << Copy_u8PinID);
			break;
		case DIO_GROUP_D:
			if (Copy_u8PinValue == DIO_LOW)
				PORTD &= ~(DIO_BIT_MASK << Copy_u8PinID);
			else
				PORTD |= (DIO_BIT_MASK << Copy_u8PinID);
			break;
		default:
			break;
		}
	}

}
void DIO_voidSetPinDirection(u8 Copy_u8GroupID,u8 Copy_u8PinID,u8 Copy_u8PinDirection){
	if (Copy_u8GroupID<=DIO_GROUP_D && Copy_u8PinID<=DIO_PIN_7
				&& Copy_u8PinDirection<=DIO_OUTPUT){
		switch (Copy_u8GroupID)
		{
		case DIO_GROUP_A:
			if (Copy_u8PinDirection == DIO_INPUT)
				DDRA &= ~(DIO_BIT_MASK << Copy_u8PinID);
			else
				DDRA |= (DIO_BIT_MASK << Copy_u8PinID);
			break;
		case DIO_GROUP_B:
			if (Copy_u8PinDirection == DIO_INPUT)
				DDRB &= ~(DIO_BIT_MASK << Copy_u8PinID);
			else
				DDRB |= (DIO_BIT_MASK << Copy_u8PinID);
			break;
		case DIO_GROUP_C:
			if (Copy_u8PinDirection == DIO_INPUT)
				DDRC &= ~(DIO_BIT_MASK << Copy_u8PinID);
			else
				DDRC |= (DIO_BIT_MASK << Copy_u8PinID);
			break;
		case DIO_GROUP_D:
			if (Copy_u8PinDirection == DIO_INPUT)
				DDRD &= ~(DIO_BIT_MASK << Copy_u8PinID);
			else
				DDRD |= (DIO_BIT_MASK << Copy_u8PinID);
			break;
		default:
			break;
		}
		}
}
u8 DIO_u8GetPinValue(u8 Copy_u8GroupID, u8 CopyPinID) {
	u8 Local_u8Value = 0xff;
	if (CopyPinID <= DIO_PIN_7 && Copy_u8GroupID <= DIO_GROUP_D) {
		switch (Copy_u8GroupID) {
		case DIO_GROUP_A:
			Local_u8Value = ((PINA >> CopyPinID) & DIO_BIT_MASK);
			break;
		case DIO_GROUP_B:
			Local_u8Value = ((PINB >> CopyPinID) & DIO_BIT_MASK);
			break;
		case DIO_GROUP_C:
			Local_u8Value = ((PINC >> CopyPinID) & DIO_BIT_MASK);
			break;
		case DIO_GROUP_D:
			Local_u8Value = ((PIND >> CopyPinID) & DIO_BIT_MASK);
			break;
		}
	}
	return Local_u8Value;
}
void DIO_voidTogelPinValue(u8 Copy_u8GroupID, u8 Copy_u8PinID) {
	if (Copy_u8PinID <= DIO_PIN_7 && Copy_u8GroupID <= DIO_GROUP_D) {
		switch (Copy_u8GroupID)
		{
		case DIO_GROUP_A:
			PORTA ^= (DIO_BIT_MASK << Copy_u8PinID);
			break;
		case DIO_GROUP_B:
			PORTB ^= (DIO_BIT_MASK << Copy_u8PinID);
			break;
		case DIO_GROUP_C:
			PORTC ^= (DIO_BIT_MASK << Copy_u8PinID);
			break;
		case DIO_GROUP_D:
			PORTD ^= (DIO_BIT_MASK << Copy_u8PinID);
			break;
		}
	}
}
void DIO_voidWriteNum(u8 num) {
	DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_4, DIO_LOW);
	DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_5, DIO_LOW);
	DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_6, DIO_LOW);
	DIO_voidSetPinValue(DIO_GROUP_A, DIO_PIN_7, DIO_LOW);

}

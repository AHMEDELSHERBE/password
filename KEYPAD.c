/******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: KEYPAD.c
 *
 * Description: Source file for the KEYPAD driver
 *
 * Author: Mohamed Khaled
 *
 *******************************************************************************/
#define F_CPU 8000000UL
#include "../lib/std_types.h"
#include "../lib/common_macros.h"
#include "../MCAL/gpio.h"
#include "avr/io.h"
#include "util/delay.h"
#include "KEYPAD.h"
#include "DIO_init.h"
/*
 * Description :
 * Initialize the Keypad Driver (it's pins and ports)
 */ 
void KEYPAD_voidInit(void)
{
    /* Set the Raw port as input with the first 4 pins as input and the rest as pull-up */
    //GPIO_setupPortDirection(KEYPAD_ROW_PORT, PORT_INPUT);
	DIO_voidSetPinDirection(DIO_GROUP_C,DIO_PIN_0,DIO_INPUT);
	DIO_voidSetPinDirection(DIO_GROUP_C,DIO_PIN_1,DIO_INPUT);
	DIO_voidSetPinDirection(DIO_GROUP_C,DIO_PIN_2,DIO_INPUT);
	DIO_voidSetPinDirection(DIO_GROUP_C,DIO_PIN_3,DIO_INPUT);

    GPIO_writePort(KEYPAD_ROW_PORT, 0x0F);

    /* Set the COL port as output with the first 4 pins as output and the rest as logic high */
	DIO_voidSetPinDirection(DIO_GROUP_D, DIO_PIN_0, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_GROUP_D, DIO_PIN_1, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_GROUP_D, DIO_PIN_2, DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_GROUP_D, DIO_PIN_3, DIO_OUTPUT);
    GPIO_writePort(KEYPAD_COL_PORT, 0x0F);
	/*DIO_voidSetPinDirection(DIO_GROUP_D, DIO_PIN_2, DIO_INPUT);
	DIO_voidSetPinDirection(DIO_GROUP_D, DIO_PIN_3, DIO_INPUT);
	DIO_voidSetPinValue(DIO_GROUP_D,DIO_PIN_6,DIO_LOW);
	DIO_voidSetPinValue(DIO_GROUP_D,DIO_PIN_7,DIO_LOW);*/


}


/*
 * Description :
 * Get the Keypad pressed button
 */
u8 KEYPAD_u8GetPressedKey(void)
{
	/*Define the row and col variables that will check which button pressed*/
	u8 u8RowLocal=0,u8ColLocal=0;
	/*Define the row and col arrays that will include the keypad pins */
	u8 KPD_u8RwoPinArr[KEYPAD_NUM_ROWS] = {KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN};
	u8 KPD_u8ColPinArr[KEYPAD_NUM_COLS] = {KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN};
	for(u8ColLocal=0;u8ColLocal<KEYPAD_NUM_COLS;u8ColLocal++)
	{
		/*To activate one column at a time -> col_pin =0*/
		GPIO_writePin(KEYPAD_COL_PORT,KPD_u8ColPinArr[u8ColLocal],LOGIC_LOW);
		for(u8RowLocal=0;u8RowLocal<KEYPAD_NUM_ROWS;u8RowLocal++)
		{
			u8 u8Value=GPIO_readPin(KEYPAD_ROW_PORT,KPD_u8RwoPinArr[u8RowLocal]);
			if (u8Value == KEYPAD_BUTTON_PRESSED)
			{
				/*delay and second check for switch debouncing*/
				_delay_ms(30);
				if (u8Value == KEYPAD_BUTTON_PRESSED)
				{
					while(u8Value == KEYPAD_BUTTON_PRESSED)
					{
						u8Value=GPIO_readPin(KEYPAD_ROW_PORT,KPD_u8RwoPinArr[u8RowLocal]);
					}
					u8 KPD_u8Value[KEYPAD_NUM_ROWS][KEYPAD_NUM_COLS]= KPD_VALUES;
					return KPD_u8Value[u8RowLocal][u8ColLocal];
				}
			}
		}
		/*there is no button pressed*/
		GPIO_writePin(KEYPAD_COL_PORT,KPD_u8ColPinArr[u8ColLocal],LOGIC_HIGH);
	}
	return KEYPAD_BUTTON_RELEASED;
}

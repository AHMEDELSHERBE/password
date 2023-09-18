#include "log_in.h"
#include "../HAL/LCD.h"
#include "../HAL/KEYPAD.h"
#include "../lib/std_types.h"
#include "../lib/common_macros.h"
#include <string.h>
#include <util/delay.h>


u8 Login_SCEnterdPass[6]={1,2,3,4,5,6};
u8 Login_Su8CompareFlag = 3;
 void Login_voidInit(void)
 {
	 LCD_enuInit();
	 DIO_voidSetPinDirection(DIO_GROUP_D, DIO_PIN_6, DIO_OUTPUT);
	 	DIO_voidSetPinDirection(DIO_GROUP_D, DIO_PIN_7, DIO_OUTPUT);
	 	DIO_voidSetPinValue(DIO_GROUP_D, DIO_PIN_6, DIO_LOW);
	 	DIO_voidSetPinValue(DIO_GROUP_D, DIO_PIN_7, DIO_LOW);
	KEYPAD_voidInit();
 }
 void Login_voidEnterPassword(void) {
	 u8 Local_u8KeyPressed = 0;
	 s8 Local_s8Counter = 0;
	 LCD_vidSendCommand(0x01);
	 LCD_vidSendCommand(0x80);
	 LCD_vidWriteString("Enter Password :");
	 LCD_vidSendCommand(0xC0);
	 for (u8 i = 0; i < 6; i++){
	     Login_SCEnterdPass[i] = 0;}
	 while (( Local_u8KeyPressed != '=')&&(Local_s8Counter < 6)) {
		 Local_u8KeyPressed = KEYPAD_u8GetPressedKey();
		 if ((Local_u8KeyPressed != KEYPAD_BUTTON_RELEASED) && (Local_u8KeyPressed != '=')) {
			 Login_SCEnterdPass[Local_s8Counter] = Local_u8KeyPressed;
			 Local_s8Counter++;
			 LCD_vidWriteString("*");

		 }
	 }
	 
 }
 void Login_voidCheckPassword(void) {
	 u8* Local_PCLCDPass = PASSWORD;
		 if ((strcmp(Local_PCLCDPass,Login_SCEnterdPass))!=0) {
			 Login_Su8CompareFlag = 1;
		 }
		 else {
			 Login_Su8CompareFlag = 0;
		 }
	 if (Login_Su8CompareFlag == 0) {
		 LCD_vidSendCommand(0x01);
		 LCD_vidSendCommand(0x80);
		 LCD_vidWriteString("correct");
		 _delay_ms(1500);
		 }
		 else{
		 LCD_vidSendCommand(0x01);
		 LCD_vidSendCommand(0x80);
		 LCD_vidWriteString("incorrect");
		 LCD_vidSendCommand(0xC0);
		 LCD_vidWriteString("try Again");
		 _delay_ms(1000);
	 }

 }
 u8 Login_u8GetCompareFlag(void) {
	 return Login_Su8CompareFlag;
 }

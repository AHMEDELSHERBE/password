/*
 * LCD_int.h
 *
 *  Created on: Jun 13, 2023
 *      Author: George Yaccoup
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

			//EIGHT_BIT_MODE , FOUR_BIT_MODE

#include "../Lib/std_Types.h"
#include <avr/delay.h>
#include "DIO_init.h"

#define LCD_MODE			FOUR_BIT_MODE

#define RS_GRP				DIO_GROUP_B
#define RS_PIN				DIO_PIN_1

#define RW_GRP				DIO_GROUP_B
#define RW_PIN				DIO_PIN_2

#define EN_GRP				DIO_GROUP_B
#define EN_PIN				DIO_PIN_3



#define D7_GRP				DIO_GROUP_B
#define D7_PIN				DIO_PIN_0

#define D6_GRP				DIO_GROUP_A
#define D6_PIN				DIO_PIN_6

#define D5_GRP				DIO_GROUP_A
#define D5_PIN				DIO_PIN_5

#define D4_GRP				DIO_GROUP_A
#define D4_PIN				DIO_PIN_4

#define D3_GRP				DIO_GROUP_A
#define D3_PIN				DIO_PIN_3

#define D2_GRP				DIO_GROUP_A
#define D2_PIN				DIO_PIN_2

#define D1_GRP				DIO_GROUP_B
#define D1_PIN				DIO_PIN_5

#define D0_GRP				DIO_GROUP_A
#define D0_PIN				DIO_PIN_0

#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80
#define LCD_GO_TO_NEXT_LINE	                 0xC0

static void vidWriteByteAndLatch(u8 Copy_u8Byte);

static u8 u8CountDigitsInNum(s32 Copy_s32Num);

void LCD_enuInit(void);

void LCD_vidSendData(u8 Copy_u8Data);

void LCD_vidSendCommand(u8 Copy_u8Command);

void LCD_vidWriteString(const char * Copy_pcString);

void LCD_vidWriteIntegarNum(s32 Copy_s32Num);

void LCD_vidWriteFloatNum(f32 Copy_f32Num);

#endif /* LCD_INT_H_ */

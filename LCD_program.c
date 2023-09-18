#include "../Lib/std_types.h"

#include "DIO_init.h"

#include <util/delay.h>

#include "LCD.h"

void LCD_enuInit(void)
{
    _delay_ms(35);

    DIO_voidSetPinDirection(RS_GRP , RS_PIN , DIO_OUTPUT);
    DIO_voidSetPinDirection(RW_GRP , RW_PIN , DIO_OUTPUT);
    DIO_voidSetPinDirection(EN_GRP , EN_PIN , DIO_OUTPUT);

    DIO_voidSetPinDirection(D7_GRP , D7_PIN , DIO_OUTPUT);
    DIO_voidSetPinDirection(D6_GRP , D6_PIN , DIO_OUTPUT);
    DIO_voidSetPinDirection(D5_GRP , D5_PIN , DIO_OUTPUT);
    DIO_voidSetPinDirection(D4_GRP , D4_PIN , DIO_OUTPUT);

    #if LCD_MODE == EIGHT_BIT_MODE
        DIO_voidSetPinDirection(D3_GRP , D3_PIN , DIO_OUTPUT);
        DIO_voidSetPinDirection(D2_GRP , D2_PIN , DIO_OUTPUT);
        DIO_voidSetPinDirection(D1_GRP , D1_PIN , DIO_OUTPUT);
        DIO_voidSetPinDirection(D0_GRP , D0_PIN , DIO_OUTPUT);

        DIO_voidSetPinValue(RS_GRP , RS_PIN , DIO_LOW);
        vidWriteByteAndLatch(0x38);
    #elif LCD_MODE == FOUR_BIT_MODE
        DIO_voidSetPinValue(RS_GRP , RS_PIN , DIO_LOW);

        DIO_voidSetPinValue( D7_GRP, D7_PIN , 0);
        DIO_voidSetPinValue( D6_GRP, D6_PIN , 0);
        DIO_voidSetPinValue( D5_GRP, D5_PIN , 1);
        DIO_voidSetPinValue( D4_GRP, D4_PIN , 0);

        DIO_voidSetPinValue(EN_GRP,EN_PIN , DIO_HIGH);
        _delay_ms(1);
        DIO_voidSetPinValue(EN_GRP,EN_PIN , DIO_LOW);
        _delay_ms(2);

        vidWriteByteAndLatch(0x28);
    #else
    #error LCD mode setting is wrong
    #endif

    DIO_voidSetPinValue(RS_GRP , RS_PIN , DIO_LOW);
    vidWriteByteAndLatch(0x0F);

    DIO_voidSetPinValue(RS_GRP , RS_PIN , DIO_LOW);
    vidWriteByteAndLatch(0x01);

    DIO_voidSetPinValue(RS_GRP , RS_PIN , DIO_LOW);
    vidWriteByteAndLatch(0x06);
}

void LCD_vidSendData(u8 Copy_u8Data)
{
    DIO_voidSetPinValue(RS_GRP , RS_PIN , DIO_HIGH);

    vidWriteByteAndLatch(Copy_u8Data);

}

void LCD_vidSendCommand(u8 Copy_u8Command)
{
    DIO_voidSetPinValue(RS_GRP , RS_PIN , DIO_LOW);

    vidWriteByteAndLatch(Copy_u8Command);
}

void LCD_vidWriteString(const char * Copy_pcString)
{
    while ( * Copy_pcString != '\0')
    {
        DIO_voidSetPinValue(RS_GRP , RS_PIN , DIO_HIGH);
        vidWriteByteAndLatch(*Copy_pcString++);

    }
}

void LCD_vidWriteIntegarNum(s32 Copy_s32Num)
{
    if (Copy_s32Num == 0)
    {
        DIO_voidSetPinValue(RS_GRP , RS_PIN , DIO_HIGH);
        vidWriteByteAndLatch('0');
    }
    else
    {
        if (Copy_s32Num < 0 )
        {
            DIO_voidSetPinValue(RS_GRP , RS_PIN , DIO_HIGH);
            vidWriteByteAndLatch('-');

            Copy_s32Num *=-1;
        }

        u8 Local_au8Digits [12] = {0};
        u8 Local_u8NumOfDigits = (u8CountDigitsInNum(Copy_s32Num)-1);

        for (s8 Local_s8Iter = Local_u8NumOfDigits ; Local_s8Iter >=0 ; Local_s8Iter --)
        {
            Local_au8Digits[Local_s8Iter] = ( Copy_s32Num %10)+ '0';
            Copy_s32Num /=10;
        }
        for (u8 Local_u8Iter = 0 ; Local_au8Digits[Local_u8Iter] != 0 ; Local_u8Iter ++)
        {
            DIO_voidSetPinValue(RS_GRP , RS_PIN , DIO_HIGH);
            vidWriteByteAndLatch(Local_au8Digits[Local_u8Iter]);
        }

    }
}


static u8 u8CountDigitsInNum(s32 Copy_s32Num)
{
    u8 Local_u8NumOfDigits = 0;
    while(Copy_s32Num != 0)
    {
        Copy_s32Num /=10;
        Local_u8NumOfDigits ++ ;
    }
    return Local_u8NumOfDigits;
}

static void vidWriteByteAndLatch(u8 Copy_u8Byte)
{
    #if LCD_MODE == EIGHT_BIT_MODE
        DIO_voidSetPinValue(RW_GRP,RW_PIN , DIO_LOW);
        DIO_voidSetPinValue(EN_GRP,EN_PIN , DIO_LOW);

        DIO_voidSetPinValue( D7_GRP, D7_PIN , ((Copy_u8Byte >> 7)&1));
        DIO_voidSetPinValue( D6_GRP, D6_PIN , ((Copy_u8Byte >> 6)&1));
        DIO_voidSetPinValue( D5_GRP, D5_PIN , ((Copy_u8Byte >> 5)&1));
        DIO_voidSetPinValue( D4_GRP, D4_PIN , ((Copy_u8Byte >> 4)&1));
        DIO_voidSetPinValue( D3_GRP, D3_PIN , ((Copy_u8Byte >> 3)&1));
        DIO_voidSetPinValue( D2_GRP, D2_PIN , ((Copy_u8Byte >> 2)&1));
        DIO_voidSetPinValue( D1_GRP, D1_PIN , ((Copy_u8Byte >> 1)&1));
        DIO_voidSetPinValue( D0_GRP, D0_PIN , ((Copy_u8Byte >> 0)&1));

        DIO_voidSetPinValue(EN_GRP,EN_PIN , DIO_HIGH);
        _delay_ms(1);
        DIO_voidSetPinValue(EN_GRP,EN_PIN , DIO_LOW);

        _delay_ms(2);
    #elif LCD_MODE == FOUR_BIT_MODE
        DIO_voidSetPinValue(RW_GRP,RW_PIN , DIO_LOW);
        DIO_voidSetPinValue(EN_GRP,EN_PIN , DIO_LOW);

        DIO_voidSetPinValue( D7_GRP, D7_PIN , ((Copy_u8Byte >> 7)&1));
        DIO_voidSetPinValue( D6_GRP, D6_PIN , ((Copy_u8Byte >> 6)&1));
        DIO_voidSetPinValue( D5_GRP, D5_PIN , ((Copy_u8Byte >> 5)&1));
        DIO_voidSetPinValue( D4_GRP, D4_PIN , ((Copy_u8Byte >> 4)&1));

        DIO_voidSetPinValue(EN_GRP,EN_PIN , DIO_HIGH);
        _delay_ms(1);
        DIO_voidSetPinValue(EN_GRP,EN_PIN , DIO_LOW);

        DIO_voidSetPinValue( D7_GRP, D7_PIN , ((Copy_u8Byte >> 3)&1));
        DIO_voidSetPinValue( D6_GRP, D6_PIN , ((Copy_u8Byte >> 2)&1));
        DIO_voidSetPinValue( D5_GRP, D5_PIN , ((Copy_u8Byte >> 1)&1));
        DIO_voidSetPinValue( D4_GRP, D4_PIN , ((Copy_u8Byte >> 0)&1));

        DIO_voidSetPinValue(EN_GRP,EN_PIN , DIO_HIGH);
        _delay_ms(1);
        DIO_voidSetPinValue(EN_GRP,EN_PIN , DIO_LOW);

        _delay_ms(2);
    #else
    #error LCD mode setting is wrong
    #endif
}

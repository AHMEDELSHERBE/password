/*
 * DIO_private.h
 *
 *  Created on: 16 Jun 2023
 *      Author: george yaccoup
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define DDRA	*((u8*)0x3A)
#define PORTA	*((u8*)0x3B)
#define PINA	*((u8*)0x39)

#define DDRB	*((u8*)0x37)
#define PORTB	*((u8*)0x38)
#define PINB	*((u8*)0x36)

#define DDRC	*((u8*)0x34)
#define PORTC	*((u8*)0x35)
#define PINC	*((u8*)0x33)

#define DDRD	*((u8*)0x31)
#define PORTD	*((u8*)0x32)
#define PIND	*((u8*)0x30)
#define DIO_GROUP_A  0
#define DIO_GROUP_B  1
#define DIO_GROUP_C  2
#define DIO_GROUP_D  3

#define DIO_PIN_0    0
#define DIO_PIN_1    1
#define DIO_PIN_2    2
#define DIO_PIN_3    3
#define DIO_PIN_4    4
#define DIO_PIN_5    5
#define DIO_PIN_6    6
#define DIO_PIN_7    7

#define DIO_OUTPUT   1
#define DIO_INPUT    0

#define DIO_LOW      0
#define DIO_HIGH     1

#define DIO_FLOAT    0
#define DIO_PULL_Up  1

#define DIO_BIT_MASK 1


#endif /* DIO_PRIVATE_H_ */

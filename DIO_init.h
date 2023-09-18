/*
 * DIO_init.h
 *
 *  Created on: 16 Jun 2023
 *      Author: george yaccoup
 */

#ifndef DIO_INIT_H_
#define DIO_INIT_H_
#include "../Lib/std_types.h"
#include "DIO_confeg.h"
#include "DIO_private.h"

void DIO_voidSetPinValue(u8 Copy_u8GroupID,u8 CopyPinID,u8 Copy_u8PinValue);
void DIO_voidSetPinDirection(u8 Copy_u8GroupID,u8 CopyPinID,u8 Copy_u8PinDirection);
u8 DIO_u8GetPinValue(u8 Copy_u8GroupID,u8 CopyPinID);
void DIO_voidTogelPinValue(u8 Copy_u8GroupID,u8 CopyPinID);


#endif /* DIO_INIT_H_ */

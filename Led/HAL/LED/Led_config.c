/*
 * Led_config.c
 *
 *  Created on: Jul 27, 2023
 *      Author: Admin
 */

#include "../../LIB/STDTYPE.h"
#include "../../LIB/ErrorState.h"

#include "../../MCAL/DIO_int.h"

#include "Led_priv.h"
#include "Led_config.h"

LED_t LED_AstrLedConfig[LED_NUM]={
		{DIO_u8PORTA,DIO_u8PIN0,LED_SINK,LED_OFF},
		{DIO_u8PORTB,DIO_u8PIN5,LED_SOURCE,LED_OFF},
		{DIO_u8PORTD,DIO_u8PIN3,LED_SOURCE,LED_OFF}
};

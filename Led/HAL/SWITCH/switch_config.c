/*
 * switch_config.c
 *
 *  Created on: Jul 25, 2023
 *      Author: Admin
 */

#include "../../LIB/STDTYPE.h"
#include "../../LIB/ErrorState.h"

#include "../../MCAL/DIO_config.h"
#include "../../MCAL/DIO_int.h"

#include "switch_config.h"


SW_t Switch_AStrSwitchState[SW_NUM]={{DIO_u8PORTA,DIO_u8PIN3,DIO_u8FLOAT},
									{DIO_u8PORTC,DIO_u8PIN4,DIO_u8PULL_UP},
									{DIO_u8PORTD,DIO_u8PIN6,DIO_u8PULL_UP}};

/*
 * config.c
 *
 *  Created on: Aug 7, 2023
 *      Author: Marina
 */
#include "../../LIB/STDTYPE.h"
#include "../../LIB/ErrorState.h"

#include "../../MCAL/DIO_int.h"

#include "Seven_Seg_config.h"
#include "Seven_Seg_priv.h"

SEG_t SEVSEG_AStrSegConfig[SEG_NUM]={
		//first segment
		{DIO_u8PIN0,DIO_u8PORTA,       //pin A
		 DIO_u8PIN1,DIO_u8PORTA,       //pin B
		 DIO_u8PIN2,DIO_u8PORTA,       //pin C
		 DIO_u8PIN3,DIO_u8PORTA,       //pin D
		 DIO_u8PIN4,DIO_u8PORTA,       //pin E
		 DIO_u8PIN5,DIO_u8PORTA,       //pin F
		 DIO_u8PIN6,DIO_u8PORTA,       //pin G
		 NOT_CONNECTED,NOT_CONNECTED,  //pin CMN
		 NOT_CONNECTED,NOT_CONNECTED,  //pin DOT
		 COMMON_CATHODE},              //SEG_TYPE
		//Second segment
		{DIO_u8PIN0,DIO_u8PORTC,       //pin A
		 DIO_u8PIN1,DIO_u8PORTC,       //pin B
		 DIO_u8PIN2,DIO_u8PORTC,       //pin C
		 DIO_u8PIN3,DIO_u8PORTC,       //pin D
		 DIO_u8PIN4,DIO_u8PORTC,       //pin E
		 DIO_u8PIN5,DIO_u8PORTC,       //pin F
		 DIO_u8PIN6,DIO_u8PORTC,       //pin G
		 NOT_CONNECTED,NOT_CONNECTED,  //pin CMN
		 NOT_CONNECTED,NOT_CONNECTED,  //pin DOT
		 COMMON_ANODE}               //SEG_TYPE
};

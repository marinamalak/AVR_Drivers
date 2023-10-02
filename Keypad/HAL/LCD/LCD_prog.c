/*
 * LCD_prog.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Marina
 */
#include "../../LIB/STDTYPE.h"
#include "../../LIB/ErrorState.h"

#include "../../MCAL/DIO_int.h"

#include "LCD_config.h"
#include "LCD_priv.h"

#include <util/delay.h>

ES_t LCD_enuInit(void)
{
	ES_t Local_enuErorrState=ES_NOK;

  	DIO_enuSetPinDirection(RS_PORT,RS_PIN,DIO_u8OUTPUT);
  	DIO_enuSetPinDirection(RW_PORT,RW_PIN,DIO_u8OUTPUT);
  	DIO_enuSetPinDirection(EN_PORT,EN_PIN,DIO_u8OUTPUT);

 	DIO_enuSetPinDirection(D7_PORT,D7_PIN,DIO_u8OUTPUT);
 	DIO_enuSetPinDirection(D6_PORT,D6_PIN,DIO_u8OUTPUT);
 	DIO_enuSetPinDirection(D5_PORT,D5_PIN,DIO_u8OUTPUT);
 	DIO_enuSetPinDirection(D4_PORT,D4_PIN,DIO_u8OUTPUT);
    _delay_ms(35);

#if LCD_MODE == EIGHT_BIT

	DIO_enuSetPinDirection(D3_PORT,D3_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D2_PORT,D2_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D1_PORT,D1_PIN,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D0_PORT,D0_PIN,DIO_u8OUTPUT);

	//Function set
	LCD_invidSendCommand(0x38);
#elif LCD_MODE == FOUR_BIT
	//Function set
	LCD_invidSendCommand(0x28);
#else
#error "Your Selection To LCD Mode has a Wrong Value"
#endif
	_delay_ms(1);
	LCD_invidSendCommand(0x0f);
	_delay_ms(1);
	LCD_invidSendCommand(0x01);
	_delay_ms(2);
	LCD_invidSendCommand(0x06);

	return Local_enuErorrState;
}

ES_t LCD_enuDisplayChar(u8 Copy_u8char)
{
	ES_t Local_enuErorrState=ES_NOK;

		//set RS as data
	DIO_enuSetPinValue(RS_PORT,RS_PIN,DIO_u8HIGH);

	LCD_vidLatch(Copy_u8char);

	return Local_enuErorrState;
}

ES_t LCD_enuSendCommand(u8 Copy_u8command)
{
		ES_t Local_enuErorrState=ES_NOK;

		//set RS as command
	DIO_enuSetPinValue(RS_PORT,RS_PIN,DIO_u8LOW);

	LCD_vidLatch(Copy_u8command);

	return Local_enuErorrState;
}

static void LCD_vidLatch(u8 Copy_u8Data)
{
		//set RW as write operation
	DIO_enuSetPinValue(RW_PORT,RW_PIN,DIO_u8LOW);
		 //set enable is low
	DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8LOW);

		//write data
	DIO_enuSetPinValue(D7_PORT,D7_PIN,((Copy_u8Data>>7)&1));
	DIO_enuSetPinValue(D6_PORT,D6_PIN,((Copy_u8Data>>6)&1));
	DIO_enuSetPinValue(D5_PORT,D5_PIN,((Copy_u8Data>>5)&1));
	DIO_enuSetPinValue(D4_PORT,D4_PIN,((Copy_u8Data>>4)&1));

#if LCD_MODE == EIGHT_BIT
	DIO_enuSetPinValue(D3_PORT,D3_PIN,((Copy_u8Data>>3)&1));
	DIO_enuSetPinValue(D2_PORT,D2_PIN,((Copy_u8Data>>2)&1));
	DIO_enuSetPinValue(D1_PORT,D1_PIN,((Copy_u8Data>>1)&1));
	DIO_enuSetPinValue(D0_PORT,D0_PIN,((Copy_u8Data>>0)&1));
#elif LCD_MODE == FOUR_BIT

#else
#error "Your Selection To LCD Mode has a Wrong Value"
#endif

	 //Enable Latch
	DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8LOW);
	}

static inline void LCD_invidSendCommand(u8 Copy_u8command)
{
		//set RS as command
	DIO_enuSetPinValue(RS_PORT,RS_PIN,DIO_u8LOW);
		//set RW as write operation
	DIO_enuSetPinValue(RW_PORT,RW_PIN,DIO_u8LOW);
		 //set enable is low
	DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8LOW);

		//write data
	DIO_enuSetPinValue(D7_PORT,D7_PIN,((Copy_u8command>>7)&1));
	DIO_enuSetPinValue(D6_PORT,D6_PIN,((Copy_u8command>>6)&1));
	DIO_enuSetPinValue(D5_PORT,D5_PIN,((Copy_u8command>>5)&1));
	DIO_enuSetPinValue(D4_PORT,D4_PIN,((Copy_u8command>>4)&1));
	DIO_enuSetPinValue(D3_PORT,D3_PIN,((Copy_u8command>>3)&1));
	DIO_enuSetPinValue(D2_PORT,D2_PIN,((Copy_u8command>>2)&1));
	DIO_enuSetPinValue(D1_PORT,D1_PIN,((Copy_u8command>>1)&1));
	DIO_enuSetPinValue(D0_PORT,D0_PIN,((Copy_u8command>>0)&1));

	 //Enable Latch
	DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8HIGH);
	_delay_ms(10);
	DIO_enuSetPinValue(EN_PORT,EN_PIN,DIO_u8LOW);
}

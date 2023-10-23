/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Admin
 */
#include "../LIB/STDTYPE.h"
#include "../LIB/ErrorState.h"
#include "../LIB/Interrupt.h"

#include "../MCAL/DIO/DIO_int.h"

#include "../MCAL/GIE/GIE_int.h"

#include "../MCAL/EXTI/EXTI_config.h"
#include "../MCAL/EXTI/EXTI_int.h"


void Toggle();
void Clear();
void Set();

extern EXTI_t EXTI_ArrstrConfig[3];

int main(void)
{
	DIO_enuInit();
	GIE_enuEnable();
	EXIT_enuInit(EXTI_ArrstrConfig);

	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8LOW);
        //INT0
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);
	DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PULL_UP);
       //INT1
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8INPUT);
	DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PULL_UP);
      //INT2
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN2,DIO_u8INPUT);
	DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PULL_UP);

	EXTI_enuCallBack((Toggle),NULL,0); //if INT0
	EXTI_enuCallBack((Clear),NULL,1); //if INT1
	EXTI_enuCallBack((Set),NULL,2);  //if INT2

	while(1)
	{

	}
	return 0;
}
void Toggle()
{
	DIO_enuTogPin(DIO_u8PORTA,DIO_u8PIN1);
}

void Clear()
{
	DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8LOW);

}
void Set()
{
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8HIGH);

}

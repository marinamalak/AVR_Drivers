/*
 * APP_prog.c
 *
 *  Created on: Sep 29, 2023
 *      Author: Marina
 */
#include "../LIB/STDTYPE.h"
#include "../LIB/ErrorState.h"

#include "../MCAL/DIO_int.h"

#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LCD/LCD_config.h"

#include "../HAL/KEYPAD/Keypad_int.h"
#include "../HAL/KEYPAD/Keypad_config.h"

#include "APP_int.h"

int main (void)
{

     APP_enuInit();

	while(1)
    	{

       APP_enuStartApp();
    	}

	return 0;
}


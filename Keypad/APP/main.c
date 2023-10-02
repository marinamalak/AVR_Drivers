/*
 * main.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Marina
 */
#include "../LIB/STDTYPE.h"
#include "../LIB/ErrorState.h"

#include "../MCAL/DIO_int.h"

#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LCD/LCD_config.h"

#include "../HAL/KEYPAD/Keypad_int.h"
#include "../HAL/KEYPAD/Keypad_config.h"

int main (void)
{
	 u8 Local_KeyValue;
	   DIO_enuInit();
	   LCD_enuInit();
	   KEYPAD_enuInit();

	while(1)
	{
		// to continue read the key until it pressed
		do
		{
			Local_KeyValue= KEYPAD_u8GetPressedKey();
		}while(Local_KeyValue==KPD_NO_PRESSED_KEY);

          LCD_enuDisplayChar(Local_KeyValue);
    }
	return 0;
}

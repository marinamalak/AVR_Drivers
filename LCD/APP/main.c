/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Marina
 */

#include "../LIB/STDTYPE.h"
#include "../LIB/ErrorState.h"

#include "../MCAL/DIO_int.h"

#include "../HAL/LCD/LCD_config.h"
#include "../HAL/LCD/LCD_int.h"

#include <util/delay.h>


int main (void)
{
     u8 Name[]={0x00,0x00,0x00,0x00,0x00,0x1f,0x03,0x00,
                0x00,0x10,0x10,0x10,0x10,0x10,0x00,0x00,
                0x00,0x00,0x03,0x02,0x04,0x08,0x10,0x00,
				0x00,0x00,0x00,0x00,0x01,0x1F,0x03,0x00,
				0x00,0x00,0x04,0x00,0x04,0x1f,0x00,0x00,
                0x00,0x10,0x10,0x10,0x10,0x10,0x00,0x00};

       DIO_enuInit();
       LCD_enuInit();

   //To display arabic name
      LCD_enuSendCommand(0x40);  // to go to CGRAM

      for (u8 i=0;i<48;i++){
    	  LCD_enuDisplayChar(Name[i]);
      }

      LCD_enuSendCommand(0x8f);  // to return to DDRAM but at end of the line
      LCD_enuSendCommand(0x04);  // to decrease from data sheet (at page 17)

      // to display
      LCD_enuDisplayChar(0);
      LCD_enuDisplayChar(1);
      LCD_enuDisplayChar(2);
      LCD_enuDisplayChar(3);
      LCD_enuDisplayChar(4);
      LCD_enuDisplayChar(5);


/*         LCD_enuDisplayChar('A');
       _delay_ms(200);
         LCD_enuDisplayChar(0x33);
         */
	while(1)
	{

	}

	return 0;
}

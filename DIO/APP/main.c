/*
 * main.c
 *
 *  Created on: Jul 20, 2023
 *      Author: Marina
 */
#include <util/delay.h>

#include "../LIB/ErrorState.h"
#include "../LIB/STDTYPE.h"
#include "../MCAL/DIO_int.h"


// snake effect
int main (void)
{
	u8 i,j;
	DIO_enuInit();
	while(1){
	for(i=0;i<=7;i++){
		DIO_enuSetPinValue(DIO_u8PORTA,i,DIO_u8HIGH);
		_delay_ms(300);
	}
	for(j=0;j<=7;j++)
	{
		DIO_enuSetPinValue(DIO_u8PORTA,j,DIO_u8LOW);
		_delay_ms(300);
	}
	}
	return 0;

}

// to display 0:9 on 7segment
/* int main (void){

	 u8 count;
	 u8 segcthd[]= {0x3f,0x06,0x5b,
			        0x4f,0x66,0x6d,
				    0x7d,0x07,0x7f,
	                0x6f};
	DIO_enuInit();

 while(1){

	 for(count=0 ; count<=9;count++)
	 {
	 DIO_enuSetPortValue(DIO_u8DIO_u8PORTA,segcthd[count]);
	 _delay_ms(200);
	 }
 }

	return 0;
}

// to display 0:9 on 7segment
int main (void){

	 u8 i,j;
	 u8 segcthd[]= {0x3f,0x06,0x5b,
				    0x4f,0x66,0x6d,
			    	0x7d,0x07,0x7f,
			    	0x6f};
	DIO_enuInit();
		 while(1){
            for(i=0;i<10;i++){
    	      DIO_enuSetPortValue(DIO_u8DIO_u8PORTB,segcthd[i]);
        	for(j=0;j<10;j++){
             DIO_enuSetPortValue(DIO_u8DIO_u8PORTA,segcthd[j]);
        	  _delay_ms(300);
    	}
    }
			 }
			 return 0;
 }
*/

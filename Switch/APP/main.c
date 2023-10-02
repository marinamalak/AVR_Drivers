/*
 * main.c
 *
 *  Created on: Jul 25, 2023
 *      Author: Marina
 */
#include "../LIB/STDTYPE.h"
#include "../LIB/ErrorState.h"

#include "../MCAL/DIO_int.h"

#include "../HAL/SWITCH/switch_config.h"
#include "../HAL/SWITCH/switch_int.h"

extern SW_t Switch_AStrSwitchState[SW_NUM];

int main(void){
   u8 pinstate;
		DIO_enuInit();
		Switch_enuInit(Switch_AStrSwitchState);
  while(1){
	  Switch_enuGetState(&Switch_AStrSwitchState[2],&pinstate);
	  if(pinstate == 0){
		  DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8HIGH);
	  }else
	  {
		  DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8LOW);
	  }
  }
	return 0;
}

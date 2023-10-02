/*
 * main.c
 *
 *  Created on: Jul 27, 2023
 *      Author: Admin
 */
#include "../LIB/STDTYPE.h"
#include "../LIB/ErrorState.h"

#include "../MCAL/DIO_int.h"

#include "../HAL/LED/LED_config.h"
#include "../HAL/LED/LED_int.h"

#include "../HAL/SWITCH/switch_config.h"
#include "../HAL/SWITCH/switch_int.h"



extern LED_t LED_AstrLedConfig[LED_NUM];
extern SW_t Switch_AStrSwitchState[SW_NUM];
int main(void)
{
	u8 pinstate=0;
  DIO_enuInit();
  LED_enuInit(LED_AstrLedConfig);
  Switch_enuInit(Switch_AStrSwitchState);
  while(1)
  {
	  Switch_enuGetState(&Switch_AStrSwitchState[1],&pinstate);
	  if(pinstate==0)
	LED_enuTurnON(&LED_AstrLedConfig[2]);
	  else
	LED_enuTurnOFF(&LED_AstrLedConfig[2]);


  }
	return 0;
}

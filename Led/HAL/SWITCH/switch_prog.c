/*
 * switch_prog.c
 *
 *  Created on: Jul 25, 2023
 *      Author: Admin
 */
#include "../../LIB/STDTYPE.h"
#include "../../LIB/ErrorState.h"

#include "../../MCAL/DIO_int.h"

#include "switch_config.h"


ES_t Switch_enuInit(SW_t* copy_pAStrSwitch){

		ES_t Local_enuErorrState =ES_NOK;
  u8 Local_u8Interator;
  if(copy_pAStrSwitch!=NULL)
  {
  for(Local_u8Interator=0;Local_u8Interator<SW_NUM;Local_u8Interator++)
  {
	  Local_enuErorrState= DIO_enuSetPinDirection(copy_pAStrSwitch[Local_u8Interator].SW_u8PortID,copy_pAStrSwitch[Local_u8Interator].SW_u8PinID,DIO_u8INPUT);
	  Local_enuErorrState= DIO_enuSetPinValue(copy_pAStrSwitch[Local_u8Interator].SW_u8PortID,copy_pAStrSwitch[Local_u8Interator].SW_u8PinID,copy_pAStrSwitch[Local_u8Interator].SW_u8Status);
  }
  }else
  {
	  Local_enuErorrState =ES_NULL_POINTER;
  }
		return Local_enuErorrState;

}

ES_t Switch_enuGetState(SW_t* copy_pAStrSwitch,u8* copy_pu8SwState ){

	ES_t Local_enuErorrState =ES_NOK;

	  if(copy_pAStrSwitch!=NULL &&copy_pu8SwState!=NULL)
	  {
		  Local_enuErorrState=DIO_enuGetPinValue(copy_pAStrSwitch->SW_u8PortID,copy_pAStrSwitch->SW_u8PinID, copy_pu8SwState);
	  }else
	  {
		  Local_enuErorrState =ES_NULL_POINTER;
	  }

	return Local_enuErorrState;

}

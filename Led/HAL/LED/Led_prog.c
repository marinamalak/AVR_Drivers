/*
 * Led_prog.c
 *
 *  Created on: Jul 27, 2023
 *      Author: Admin
 */
#include "../../LIB/STDTYPE.h"
#include "../../LIB/ErrorState.h"

#include "../../MCAL/DIO_int.h"

#include "Led_priv.h"
#include "Led_config.h"


ES_t LED_enuInit(LED_t *copy_pStrLedConfig){

       ES_t Local_enuErorrState=ES_NOK;
	   if(copy_pStrLedConfig !=NULL)
	   {
		u8 Local_u8Interator;
		for(Local_u8Interator=0;Local_u8Interator<LED_NUM;Local_u8Interator++)
		{
			Local_enuErorrState=DIO_enuSetPinDirection(copy_pStrLedConfig[Local_u8Interator].LED_u8PortID,copy_pStrLedConfig[Local_u8Interator].LED_u8PinID,DIO_u8OUTPUT);
			if(copy_pStrLedConfig[Local_u8Interator].LED_u8Connection==LED_SINK)
			{
				if(copy_pStrLedConfig[Local_u8Interator].LED_u8InitState==LED_ON)
				{
					Local_enuErorrState=DIO_enuSetPinValue(copy_pStrLedConfig[Local_u8Interator].LED_u8PortID,copy_pStrLedConfig[Local_u8Interator].LED_u8PinID,DIO_u8LOW);
				}else if (copy_pStrLedConfig[Local_u8Interator].LED_u8InitState==LED_OFF)
				{
					Local_enuErorrState=DIO_enuSetPinValue(copy_pStrLedConfig[Local_u8Interator].LED_u8PortID,copy_pStrLedConfig[Local_u8Interator].LED_u8PinID,DIO_u8HIGH);

				}else
				{
					return ES_OUT_OF_RANGE;
				}
			}else if(copy_pStrLedConfig[Local_u8Interator].LED_u8Connection==LED_SOURCE)
			{
				if(copy_pStrLedConfig[Local_u8Interator].LED_u8InitState==LED_ON)
			{
				Local_enuErorrState=DIO_enuSetPinValue(copy_pStrLedConfig[Local_u8Interator].LED_u8PortID,copy_pStrLedConfig[Local_u8Interator].LED_u8PinID,DIO_u8HIGH);
			}else if (copy_pStrLedConfig[Local_u8Interator].LED_u8InitState==LED_OFF)
			{
				Local_enuErorrState=DIO_enuSetPinValue(copy_pStrLedConfig[Local_u8Interator].LED_u8PortID,copy_pStrLedConfig[Local_u8Interator].LED_u8PinID,DIO_u8LOW);

			}else
			{
				return ES_OUT_OF_RANGE;
			}
		}else
		{
			return ES_OUT_OF_RANGE;
		}
		}
	   }else
	   {
		   Local_enuErorrState=ES_NULL_POINTER;
	   }

	   return Local_enuErorrState;
}

ES_t LED_enuTurnON(LED_t *copy_pStrLedID){

	   ES_t Local_enuErorrState=ES_NOK;
   if(copy_pStrLedID !=NULL){
	   if(copy_pStrLedID->LED_u8Connection==LED_SINK)
	   {
		   DIO_enuSetPinValue(copy_pStrLedID->LED_u8PortID,copy_pStrLedID->LED_u8PinID,DIO_u8LOW);
	   }else if(copy_pStrLedID->LED_u8Connection==LED_SOURCE)
	   {
		   DIO_enuSetPinValue(copy_pStrLedID->LED_u8PortID,copy_pStrLedID->LED_u8PinID,DIO_u8HIGH);

	   }else
	   {
		   Local_enuErorrState=ES_OUT_OF_RANGE;
	   }
   }else
   {
	   Local_enuErorrState=ES_NULL_POINTER;
   }
		return Local_enuErorrState;
}

ES_t LED_enuTurnOFF(LED_t *copy_pStrLedID){

	   ES_t Local_enuErorrState=ES_NOK;
	   if(copy_pStrLedID !=NULL){
		   if(copy_pStrLedID->LED_u8Connection==LED_SINK)
		   {
			   DIO_enuSetPinValue(copy_pStrLedID->LED_u8PortID,copy_pStrLedID->LED_u8PinID,DIO_u8HIGH);
		   }else if(copy_pStrLedID->LED_u8Connection==LED_SOURCE)
		   {
			   DIO_enuSetPinValue(copy_pStrLedID->LED_u8PortID,copy_pStrLedID->LED_u8PinID,DIO_u8LOW);

		   }else
		   {
			   Local_enuErorrState=ES_OUT_OF_RANGE;
		   }
	   }else
	   {
		   Local_enuErorrState=ES_NULL_POINTER;
	   }
		return Local_enuErorrState;
}

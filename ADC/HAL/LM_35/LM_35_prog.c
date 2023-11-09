/*
 * LM_35_prog.c
 *
 *  Created on: Nov 8, 2023
 *      Author: Admin
 */
#include "../../LIB/ErrorState.h"
#include "../../LIB/STDTYPE.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "../../MCAL/ADC/ADC_int.h"

#include "LM_35_priv.h"
#include "LM_35_config.h"

ES_t THERMO_enuInit(TH_t *copy_pAstrTherom)
{
	ES_t Local_enuErrorstate=ES_NOK;

	if(copy_pAstrTherom!=NULL)
	{

		if(copy_pAstrTherom->TH_u8PosPinID!=NOT_CONNECTED)
		{
			Local_enuErrorstate=DIO_enuSetPinDirection(DIO_u8PORTA,copy_pAstrTherom->TH_u8PosPinID,DIO_u8INPUT);
			Local_enuErrorstate=ADC_enuInit();
			Local_enuErrorstate=ADC_enuSelectChannel(copy_pAstrTherom->TH_u8PosPinID);

		}
		if(copy_pAstrTherom->TH_u8NegPinID!=NOT_CONNECTED)
		{
			Local_enuErrorstate=DIO_enuSetPinDirection(DIO_u8PORTA,copy_pAstrTherom->TH_u8NegPinID,DIO_u8INPUT);
			//NOT available for LM35
		}

	}
	else
	{
		Local_enuErrorstate=ES_NULL_POINTER;
	}

	return Local_enuErrorstate;

}

ES_t THERMO_enuGetTemp( f32* copy_pf32Temp)
{
	ES_t Local_enuErrorstate=ES_NOK;

	u16 Local_u16ADCread=0;
	ADC_enuRead(&Local_u16ADCread);
	*copy_pf32Temp=((Local_u16ADCread*4.88)/10.00);

	return Local_enuErrorstate;

}

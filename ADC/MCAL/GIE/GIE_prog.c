/*
 * GIE_prog.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Admin
 */
#include "../../LIB/ErrorState.h"
#include "../../LIB/STDTYPE.h"

#include "GIE_priv.h"

ES_t GIE_enuEnable(void)
{
	ES_t Local_enuErrorstate=ES_NOK;

	SREG |=(1<<7);

	return Local_enuErrorstate;
}

ES_t GIE_enuDisable(void)
{
     ES_t Local_enuErrorstate=ES_NOK;

     SREG &=~(1<<7);

     return Local_enuErrorstate;
}

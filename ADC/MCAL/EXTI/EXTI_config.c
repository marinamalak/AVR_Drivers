/*
 * EXTI_config.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Admin
 */
#include "../../LIB/STDTYPE.h"
#include "../../LIB/ErrorState.h"

#include "EXTI_config.h"
#include "EXTI_priv.h"




EXTI_t EXTI_ArrstrConfig[3]=
{
		{ENABLE,FALLING_EDGE},
		{ENABLE,RISING_EDGE},
		{ENABLE,FALLING_EDGE}
};

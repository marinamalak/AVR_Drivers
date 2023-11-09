/*
 * LM_35_CONFIG.C
 *
 *  Created on: Nov 9, 2023
 *      Author: Admin
 */

#include "../../LIB/ErrorState.h"
#include "../../LIB/STDTYPE.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "LM_35_priv.h"
#include "LM_35_config.h"


TH_t LM35_AstrLM35Config[CH_NUM]={
		{DIO_u8PIN2,NOT_CONNECTED},
		{DIO_u8PIN7,NOT_CONNECTED}
};

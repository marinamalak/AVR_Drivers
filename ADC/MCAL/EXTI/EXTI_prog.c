/*
 * EXTI_prog.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Admin
 */
#include "../../LIB/STDTYPE.h"
#include "../../LIB/ErrorState.h"
#include "../../LIB/Interrupt.h"

#include "EXTI_priv.h"
#include "EXTI_config.h"


static volatile void (*EXTI_pFunINT[3])(void*)={NULL,NULL,NULL};
static volatile void *EXTI_ApvoidParameter[3]={NULL,NULL,NULL};

ES_t EXIT_enuInit(EXTI_t* copy_pstrEXTIConfig)
{
	ES_t Local_enuErrorstate= ES_NOK;

	if(copy_pstrEXTIConfig != NULL)
	{
		u8 Local_u8Iter=0;
		for(Local_u8Iter=0 ;Local_u8Iter<3;Local_u8Iter++)
		{
			if(copy_pstrEXTIConfig[Local_u8Iter].EXTI_u8State == ENABLE)
			{
				switch(Local_u8Iter)
				{
				case 0:
					GICR|=(1<<6);    //tO enable INT0
					MCUCR&=~(1<<0);  //to masking(clear) BIT0
					MCUCR&=~(1<<1); //to masking(clear) BIT1
					switch(copy_pstrEXTIConfig[Local_u8Iter].EXTI_u8SenseLevel)
					{
					case RISING_EDGE:
						MCUCR|=(1<<0);
						MCUCR|=(1<<1);
						break;
					case FALLING_EDGE:
						MCUCR&=~(1<<0);
						MCUCR|=(1<<1);
						break;
					case LOW_LEVEL:
						MCUCR&=~(1<<0);
						MCUCR&=~(1<<1);
						break;
					case LOGICAL_CHANGE:
						MCUCR|=(1<<0);
						MCUCR&=~(1<<1);
						break;
					default :
						Local_enuErrorstate=ES_OUT_OF_RANGE;
					}
					break;
				case 1:
					GICR|=(1<<7);    //tO enable INT1
					MCUCR&=~(1<<2);  //to masking(clear) BIT2
					MCUCR&=~(1<<3); //to masking(clear) BIT3
					switch(copy_pstrEXTIConfig[Local_u8Iter].EXTI_u8SenseLevel)
					{
					case RISING_EDGE:
						MCUCR|=(1<<2);
						MCUCR|=(1<<3);
						break;
					case FALLING_EDGE:
						MCUCR&=~(1<<2);
						MCUCR|=(1<<3);
						break;
					case LOW_LEVEL:
						MCUCR&=~(1<<2);
						MCUCR&=~(1<<3);
						break;
					case LOGICAL_CHANGE:
						MCUCR|=(1<<2);
						MCUCR&=~(1<<3);
						break;
					default :
						Local_enuErrorstate=ES_OUT_OF_RANGE;
					}
					break;
			    case 2:
					GICR|=(1<<5);    //tO enable INT2
					MCUCSR&=~(1<<6); // to masking bit 6
					switch(copy_pstrEXTIConfig[Local_u8Iter].EXTI_u8SenseLevel)
					{
					case RISING_EDGE:
						MCUCSR|=(1<<6);
						break;
					case FALLING_EDGE:
						MCUCSR&=~(1<<6);
						break;
					default :
						Local_enuErrorstate=ES_OUT_OF_RANGE;
					}
					break;
				}
			}
		}

	}
	else {
		Local_enuErrorstate=ES_NULL_POINTER;
	}

	return Local_enuErrorstate;
}

ES_t EXIT_enuSelectSenseLevel(u8 copy_u8ID,u8 copy_u8SenseLevel)
{
	ES_t Local_enuErrorstate= ES_NOK;

	if(copy_u8ID <3)
	{
		if(copy_u8ID ==0)
		{
			MCUCR&=~(1<<0);  //to masking(clear) BIT0
			MCUCR&=~(1<<1); //to masking(clear) BIT1
			switch(copy_u8SenseLevel)
			{
			case RISING_EDGE:
				MCUCR|=(1<<0);
				MCUCR|=(1<<1);
				break;
			case FALLING_EDGE:
				MCUCR&=~(1<<0);
				MCUCR|=(1<<1);
				break;
			case LOW_LEVEL:
				MCUCR&=~(1<<0);
				MCUCR&=~(1<<1);
				break;
			case LOGICAL_CHANGE:
				MCUCR|=(1<<0);
				MCUCR&=~(1<<1);
				break;
			default :
				Local_enuErrorstate=ES_OUT_OF_RANGE;
			}
		}
		else if (copy_u8ID ==1)
		{
			MCUCR&=~(1<<2);  //to masking(clear) BIT2
			MCUCR&=~(1<<3); //to masking(clear) BIT3
			switch(copy_u8SenseLevel)
			{
			case RISING_EDGE:
				MCUCR|=(1<<2);
				MCUCR|=(1<<3);
				break;
			case FALLING_EDGE:
				MCUCR&=~(1<<2);
				MCUCR|=(1<<3);
				break;
			case LOW_LEVEL:
				MCUCR&=~(1<<2);
				MCUCR&=~(1<<3);
				break;
			case LOGICAL_CHANGE:
				MCUCR|=(1<<2);
				MCUCR&=~(1<<3);
				break;
			default :
				Local_enuErrorstate=ES_OUT_OF_RANGE;
			}
		}
		else if (copy_u8ID ==2)
		{
			MCUCSR&=~(1<<6); // to masking bit 6
			switch(copy_u8SenseLevel)
			{
			case RISING_EDGE:
				MCUCSR|=(1<<6);
				break;
			case FALLING_EDGE:
				MCUCSR&=~(1<<6);
				break;
			default :
				Local_enuErrorstate=ES_OUT_OF_RANGE;
			}
		}
	}
	else
	{
		Local_enuErrorstate=ES_OUT_OF_RANGE;
	}

	return Local_enuErrorstate;
}

ES_t EXIT_enuEnableInt(u8 copy_u8ID)
{
	ES_t Local_enuErrorstate= ES_NOK;

	if(copy_u8ID <3)
	{
	 if (copy_u8ID ==0)
	 {
			GICR|=(1<<6);    //tO enable INT0
	 }
	 else if (copy_u8ID ==1)
	 {
			GICR|=(1<<7);    //tO enable INT1
	 }
	 else if(copy_u8ID ==2)
	 {
			GICR|=(1<<5);    //tO enable INT2
	 }
	}
	else
	{
		Local_enuErrorstate=ES_OUT_OF_RANGE;
	}
	return Local_enuErrorstate;
}

ES_t EXIT_enuDisableInt(u8 copy_u8ID)
{
	ES_t Local_enuErrorstate= ES_NOK;

	if(copy_u8ID <3)
	{
	 if (copy_u8ID ==0)
	 {
			GICR&=~(1<<6);
	 }
	 else if (copy_u8ID ==1)
	 {
			GICR&=~(1<<7);
	 }
	 else if(copy_u8ID ==2)
	 {
			GICR&=~(1<<5);
	 }
	}
	else
	{
		Local_enuErrorstate=ES_OUT_OF_RANGE;
	}
	return Local_enuErrorstate;
}

ES_t EXTI_enuCallBack(void(*copy_pFunApp)(void*),void* copy_pvoidParameter,u8 copy_u8ID)
{
	ES_t Local_enuErrorstate= ES_NOK;

      if(copy_pFunApp != NULL)
      {
    	  if(copy_u8ID <3)
    	  {
    		 EXTI_pFunINT[copy_u8ID]=copy_pFunApp;
    		 EXTI_ApvoidParameter[copy_u8ID]=copy_pvoidParameter;
    	  }
    	  else
    	  {
    		  Local_enuErrorstate=ES_OUT_OF_RANGE;
    	  }
      }
      else
      {
    	  Local_enuErrorstate=ES_NULL_POINTER;
      }
	return Local_enuErrorstate;
}
ISR(VECT_INT0)
{
	if( EXTI_pFunINT[0] != NULL)
	{
		 EXTI_pFunINT[0]((u8*)EXTI_ApvoidParameter[0]);
	}
}

ISR(VECT_INT1)
{
	if( EXTI_pFunINT[1] != NULL)
	{
		 EXTI_pFunINT[1]((u8*)EXTI_ApvoidParameter[1]);
	}
}

ISR(VECT_INT2)
{
	if( EXTI_pFunINT[2] != NULL)
	{
		 EXTI_pFunINT[2]((u8*)EXTI_ApvoidParameter[2]);
	}
}

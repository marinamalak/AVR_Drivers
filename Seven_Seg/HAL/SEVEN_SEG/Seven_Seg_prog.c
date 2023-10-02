/*
 * prog.c
 *
 *  Created on: Aug 7, 2023
 *      Author: Marina
 */
#include "../../LIB/STDTYPE.h"
#include "../../LIB/ErrorState.h"

#include "../../MCAL/DIO_int.h"

#include "Seven_Seg_config.h"
#include "Seven_Seg_priv.h"

extern SEG_t SEVSEG_AStrSegConfig[SEG_NUM];

ES_t seven_segment_enuInit(SEG_t *Copy_PStrSegConfig)
{

	ES_t Local_enuErrorstate= ES_NOK;
     u8 Local_u8Iter;
     if(Copy_PStrSegConfig !=NULL)
     {
     for(Local_u8Iter=0;Local_u8Iter<SEG_NUM;Local_u8Iter++)
     {
    	Local_enuErrorstate=DIO_enuSetPinDirection(Copy_PStrSegConfig[Local_u8Iter].SEG_u8APORT,Copy_PStrSegConfig[Local_u8Iter].SEG_u8APIN,DIO_u8OUTPUT);
    	Local_enuErrorstate=DIO_enuSetPinDirection(Copy_PStrSegConfig[Local_u8Iter].SEG_u8BPORT,Copy_PStrSegConfig[Local_u8Iter].SEG_u8BPIN,DIO_u8OUTPUT);
    	Local_enuErrorstate=DIO_enuSetPinDirection(Copy_PStrSegConfig[Local_u8Iter].SEG_u8CPORT,Copy_PStrSegConfig[Local_u8Iter].SEG_u8CPIN,DIO_u8OUTPUT);
    	Local_enuErrorstate=DIO_enuSetPinDirection(Copy_PStrSegConfig[Local_u8Iter].SEG_u8DPORT,Copy_PStrSegConfig[Local_u8Iter].SEG_u8DPIN,DIO_u8OUTPUT);
    	Local_enuErrorstate=DIO_enuSetPinDirection(Copy_PStrSegConfig[Local_u8Iter].SEG_u8EPORT,Copy_PStrSegConfig[Local_u8Iter].SEG_u8EPIN,DIO_u8OUTPUT);
    	Local_enuErrorstate=DIO_enuSetPinDirection(Copy_PStrSegConfig[Local_u8Iter].SEG_u8FPORT,Copy_PStrSegConfig[Local_u8Iter].SEG_u8FPIN,DIO_u8OUTPUT);
    	Local_enuErrorstate=DIO_enuSetPinDirection(Copy_PStrSegConfig[Local_u8Iter].SEG_u8GPORT,Copy_PStrSegConfig[Local_u8Iter].SEG_u8GPIN,DIO_u8OUTPUT);
          if (Copy_PStrSegConfig[Local_u8Iter].SEG_u8_CMN_PORT != NOT_CONNECTED &&
             Copy_PStrSegConfig[Local_u8Iter].SEG_u8_CMN_PIN != NOT_CONNECTED)
          {
        	  Local_enuErrorstate= DIO_enuSetPinDirection(Copy_PStrSegConfig[Local_u8Iter].SEG_u8_CMN_PORT,Copy_PStrSegConfig[Local_u8Iter].SEG_u8_CMN_PIN,DIO_u8OUTPUT);

          }
          if (Copy_PStrSegConfig[Local_u8Iter].SEG_u8_DOT_PORT != NOT_CONNECTED &&
              Copy_PStrSegConfig[Local_u8Iter].SEG_u8_DOT_PIN != NOT_CONNECTED)
          {
        	  Local_enuErrorstate=DIO_enuSetPinDirection(Copy_PStrSegConfig[Local_u8Iter].SEG_u8_DOT_PORT,Copy_PStrSegConfig[Local_u8Iter].SEG_u8_DOT_PIN,DIO_u8OUTPUT);

          }
      }
     }else
     {
    	 Local_enuErrorstate =ES_NULL_POINTER;
     }
	return Local_enuErrorstate;
}

ES_t seven_segment_enuDisplayNum(u8 Copy_u8SegId,u8 Copy_u8Num)
{

	ES_t Local_enuErrorstate= ES_NOK;
   if(Copy_u8Num<10 && Copy_u8SegId <SEG_NUM ){
	   if(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8TYPE == COMMON_CATHODE)
	   {
		   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8APORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8APIN,((SEG_Au8NumDisplay[Copy_u8Num]>>0)&1));
		   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8BPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8BPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>1)&1));
		   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8CPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8CPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>2)&1));
		   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8DPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8DPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>3)&1));
		   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8EPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8EPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>4)&1));
		   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8FPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8FPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>5)&1));
		   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8GPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8GPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>6)&1));

	   }else if (SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8TYPE == COMMON_ANODE)
	   {
		   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8APORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8APIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>0)&1));
		   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8BPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8BPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>1)&1));
		   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8CPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8CPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>2)&1));
		   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8DPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8DPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>3)&1));
		   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8EPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8EPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>4)&1));
		   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8FPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8FPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>5)&1));
		   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8GPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8GPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>6)&1));
	   }
	   else
	   {
		   Local_enuErrorstate=ES_OUT_OF_RANGE;
	   }
   }

	return Local_enuErrorstate;
}

ES_t seven_segment_enuEnableCommon(u8 Copy_u8SegId)
{

	ES_t Local_enuErrorstate= ES_NOK;

	if (Copy_u8SegId <SEG_NUM )
	{
        if (SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_CMN_PORT != NOT_CONNECTED &&
            SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_CMN_PIN != NOT_CONNECTED)
        {
		   if(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8TYPE == COMMON_CATHODE)
		   {
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_CMN_PORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_CMN_PIN,DIO_u8LOW);

		   }else if (SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8TYPE == COMMON_ANODE)
		   {
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_CMN_PORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_CMN_PIN,DIO_u8HIGH);

		   }else
		   {
			   Local_enuErrorstate=ES_OUT_OF_RANGE;
		   }
        }
	}
	return Local_enuErrorstate;
}

ES_t seven_segment_enuDisableCommon(u8 Copy_u8SegId)
{

	ES_t Local_enuErrorstate= ES_NOK;

	if (Copy_u8SegId <SEG_NUM )
	{
        if (SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_CMN_PORT != NOT_CONNECTED &&
            SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_CMN_PIN != NOT_CONNECTED)
        {
		   if(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8TYPE == COMMON_CATHODE)
		   {
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_CMN_PORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_CMN_PIN,DIO_u8HIGH);

		   }else if (SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8TYPE == COMMON_ANODE)
		   {
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_CMN_PORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_CMN_PIN,DIO_u8LOW);

		   }else
		   {
			   Local_enuErrorstate=ES_OUT_OF_RANGE;
		   }
	 }
	}
	return Local_enuErrorstate;
}

ES_t seven_segment_enuEnableDot(u8 Copy_u8SegId)
{

	ES_t Local_enuErrorstate= ES_NOK;
	if (Copy_u8SegId <SEG_NUM )
	{
	       if (SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PORT != NOT_CONNECTED &&
	           SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PIN != NOT_CONNECTED)
	        {
		   if(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8TYPE == COMMON_CATHODE)
		   {
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PIN,DIO_u8HIGH);

		   }else if (SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8TYPE == COMMON_ANODE)
		   {
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PIN,DIO_u8LOW);

		   }else
		   {
			   Local_enuErrorstate=ES_OUT_OF_RANGE;
		   }
	  }
	}
	return Local_enuErrorstate;
}

ES_t seven_segment_enuDisableDot(u8 Copy_u8SegId)
{

	ES_t Local_enuErrorstate= ES_NOK;

	if (Copy_u8SegId <SEG_NUM )
	{
        if (SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PORT != NOT_CONNECTED &&
            SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PIN != NOT_CONNECTED)
        {
		   if(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8TYPE == COMMON_CATHODE)
		   {
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PIN,DIO_u8LOW);

		   }else if (SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8TYPE == COMMON_ANODE)
		   {
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PIN,DIO_u8HIGH);

		   }else
		   {
			   Local_enuErrorstate=ES_OUT_OF_RANGE;
		   }
        }
	}
	return Local_enuErrorstate;
}

ES_t seven_segment_enuClearDisplay(u8 Copy_u8SegId)
{

	ES_t Local_enuErrorstate= ES_NOK;

	   if(Copy_u8SegId <SEG_NUM ){
		   if(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8TYPE == COMMON_CATHODE)
		   {
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8APORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8APIN,DIO_u8LOW);
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8BPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8BPIN,DIO_u8LOW);
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8CPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8CPIN,DIO_u8LOW);
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8DPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8DPIN,DIO_u8LOW);
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8EPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8EPIN,DIO_u8LOW);
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8FPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8FPIN,DIO_u8LOW);
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8GPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8GPIN,DIO_u8LOW);
		       if (SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PORT != NOT_CONNECTED &&
		    	SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PIN != NOT_CONNECTED)
		        {
				   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PIN,DIO_u8LOW);

		        }

		   }else if (SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8TYPE == COMMON_ANODE)
		   {
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8APORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8APIN,DIO_u8HIGH);
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8BPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8BPIN,DIO_u8HIGH);
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8CPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8CPIN,DIO_u8HIGH);
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8DPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8DPIN,DIO_u8HIGH);
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8EPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8EPIN,DIO_u8HIGH);
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8FPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8FPIN,DIO_u8HIGH);
			   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8GPORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8GPIN,DIO_u8HIGH);
		       if (SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PORT != NOT_CONNECTED &&
		    	   SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PIN != NOT_CONNECTED)
		        {
				   Local_enuErrorstate=DIO_enuSetPinValue(SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PORT,SEVSEG_AStrSegConfig[Copy_u8SegId].SEG_u8_DOT_PIN,DIO_u8HIGH);

		        }
		   }
		   else
		   {
			   Local_enuErrorstate=ES_OUT_OF_RANGE;
		   }
	   }
	return Local_enuErrorstate;
}

/*
 * ADC_prog.c
 *
 *  Created on: Nov 6, 2023
 *      Author: Admin
 */
#include "../../LIB/ErrorState.h"
#include "../../LIB/STDTYPE.h"
#include "../../LIB/Interrupt.h"

#include "ADC_priv.h"
#include "ADC.config.h"

static void(*ADC_pfunISRFun)(void*)=NULL;
static void *ADC_pvidISRParameter=NULL;

ES_t ADC_enuInit(void)
{
	ES_t Local_enuErrorstate=ES_NOK;

#if ADC_PRES == PRES_2
	ADCSRA &=~(1<<0);
	ADCSRA &=~(1<<1);
	ADCSRA &=~(1<<2);
#elif ADC_PRES == PRES_4
	ADCSRA &=~(1<<0);
	ADCSRA |=(1<<1);
	ADCSRA &=~(1<<2);
#elif ADC_PRES == PRES_8
	ADCSRA &=~(1<<0);
	ADCSRA |=(1<<1);
	ADCSRA |=(1<<2);
#elif ADC_PRES == PRES_16
	ADCSRA |=(1<<0);
	ADCSRA &=~(1<<1);
	ADCSRA &=~(1<<2);
#elif ADC_PRES == PRES_32
	ADCSRA |=(1<<0);
	ADCSRA &=~(1<<1);
	ADCSRA |=(1<<2);
#elif ADC_PRES == PRES_64
	ADCSRA |=(1<<0);
	ADCSRA |=(1<<1);
	ADCSRA &=~(1<<2);
#elif ADC_PRES == PRES_128
	ADCSRA |=(1<<0);
	ADCSRA |=(1<<1);
	ADCSRA |=(1<<2);
#else
#error"ADC PRES is wrong"
#endif

#if ADC_REF_VOLT==AVCC_REF
	ADMUX |=(1<<6);
	ADMUX &=~(1<<7);
#elif ADC_REF_VOLT==AREF_REF
	ADMUX &=~(1<<6);
	ADMUX &=~(1<<7);
#elif ADC_REF_VOLT==INTERNAL
	ADMUX |=(1<<6);
	ADMUX |=(1<<7);
#else
#error"ADC VOLT REF is wrong"
#endif

#if ADC_ADJ ==RIGHT_ADJ
	ADMUX &=~(1<<5);
#elif ADC_ADJ ==LEFT_ADJ
	ADMUX |=(1<<5);
#else
#error"ADC ADJ is wrong"
#endif

	return Local_enuErrorstate;
}

ES_t ADC_enuEnableADC(void)
{
	ES_t Local_enuErrorstate=ES_NOK;

	ADCSRA |=(1<<7);

	return Local_enuErrorstate;
}

ES_t ADC_enuStartConversion(void)
{
	ES_t Local_enuErrorstate=ES_NOK;

		ADCSRA |=(1<<6);

	return Local_enuErrorstate;
}

ES_t ADC_enuPollingSystem(void)
{
	ES_t Local_enuErrorstate=ES_NOK;

	while(((ADCSRA >>4)&1)==0); //Read flag pin
	ADCSRA|=(1<<4);

	return Local_enuErrorstate;
}

ES_t ADC_enuReadHighValue(u8* copy_pu8value)
{
	ES_t Local_enuErrorstate=ES_NOK;

#if ADC_ADJ ==RIGHT_ADJ
	*copy_pu8value=(ADCL>>2);	//TO read from bit 2(ADC2)
	*copy_pu8value|=(ADCH<<6);  // To read bits 6,7 in(ADCH)
#elif ADC_ADJ ==LEFT_ADJ
	*copy_pu8value=ADCH;
#else
#error"ADC ADJ is wrong"
#endif

	return Local_enuErrorstate;
}

ES_t ADC_enuRead(u16* copy_pu16value)
{
	ES_t Local_enuErrorstate=ES_NOK;

#if ADC_ADJ ==RIGHT_ADJ
	*copy_pu16value=ADCL;	//TO read from bit 2(ADC2)
	*copy_pu16value|=((u16)ADCH<<8);  // To read bits in(ADCH)
#elif ADC_ADJ ==LEFT_ADJ
	*copy_pu16value=(DDCL>>6);
	*copy_pu16value=(DDCH<<2);
#else
#error"ADC ADJ is wrong"
#endif

	return Local_enuErrorstate;
}

ES_t ADC_enuCallBack(void(copy_pfunAppFun)(void*),void* copy_pvidAppParameter)
{
	ES_t Local_enuErrorstate=ES_NOK;

	if(copy_pfunAppFun != NULL)
	{
		ADC_pfunISRFun=copy_pfunAppFun;
		ADC_pvidISRParameter=copy_pvidAppParameter;
	}
	else
	{
		Local_enuErrorstate=ES_NULL_POINTER;
	}


	return Local_enuErrorstate;
}

ES_t ADC_enuSelectChannel(u8 copy_u8ChannelID)
{
	ES_t Local_enuErrorstate=ES_NOK;

    ADMUX &=~ 0X1F; //0b00011111 ~ 0b11100000 To clear bits (0:4)
    if(copy_u8ChannelID<32) //Because i have 31 channel
    {
      ADMUX |=copy_u8ChannelID;
    }
    else
    {
    	Local_enuErrorstate=ES_OUT_OF_RANGE;
    }
	return Local_enuErrorstate;
}

ES_t ADC_enuEnableTriggeringMode(u8 copy_u8TriggeringSource)
{
	ES_t Local_enuErrorstate=ES_NOK;

	ADCSRA &=~(1<<5);//CLOSE AUTO_TRIGEERING TO SELECT TRIGGER SOURCE
	switch(copy_u8TriggeringSource)
	{
	case FREE_RUNNING:
		SFIOR&=~(1<<5);
		SFIOR&=~(1<<6);
		SFIOR&=~(1<<7);
		break;
	case ANALOG_COMPARATOR:
		SFIOR|=(1<<5);
		SFIOR&=~(1<<6);
		SFIOR&=~(1<<7);
		break;
    case EXTI0 :
		SFIOR&=~(1<<5);
		SFIOR|=(1<<6);
		SFIOR&=~(1<<7);
		break;
    case TIMER_COUNT0 :
		SFIOR|=(1<<5);
		SFIOR|=(1<<6);
		SFIOR&=~(1<<7);
		break;
    case TIMER_COUNT0_OVERFLOW :
		SFIOR|=(1<<5);
		SFIOR&=~(1<<6);
		SFIOR&=~(1<<7);
		break;
    case TIMER_COUNT1 :
		SFIOR|=(1<<5);
		SFIOR&=~(1<<6);
		SFIOR|=(1<<7);
		break;
    case TIMER_COUNT1_OVERFLOW :
		SFIOR&=~(1<<5);
		SFIOR|=(1<<6);
		SFIOR|=(1<<7);
		break;
    case TIMER_COUNT1_EVENT :
		SFIOR|=(1<<5);
		SFIOR|=(1<<6);
		SFIOR|=(1<<7);
		break;
	}

	ADCSRA |=(1<<5);

	return Local_enuErrorstate;
}

ES_t ADC_enuDisableTriggeringMode(void)
{
	ES_t Local_enuErrorstate=ES_NOK;

	ADCSRA &=~(1<<5);

	return Local_enuErrorstate;
}

ES_t ADC_enuEnableInterruptMode(void)
{
	ES_t Local_enuErrorstate=ES_NOK;

	ADCSRA |=(1<<3);

	return Local_enuErrorstate;
}

ISR(VECT_ADC )
{
	if(ADC_pfunISRFun != NULL)
	{
		ADC_pfunISRFun(ADC_pvidISRParameter);
	}
}

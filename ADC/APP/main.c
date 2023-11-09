/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Admin
 */
#include "../LIB/STDTYPE.h"
#include "../LIB/ErrorState.h"
#include "../LIB/Interrupt.h"

#include "../MCAL/DIO/DIO_int.h"

#include "../MCAL/GIE/GIE_int.h"

#include "../HAL/LCD/LCD_int.h"

#include "../MCAL/EXTI/EXTI_config.h"
#include "../MCAL/EXTI/EXTI_int.h"

#include "../MCAL/ADC/ADC_int.h"

#include "../HAL/LM_35/LM_35_config.h"
#include "../HAL/LM_35/LM_35_int.h"

 extern EXTI_t EXTI_ArrstrConfig[3];
 extern TH_t LM35_AstrLM35Config[2];

 u8 flag=0;
 void read(void*p)
 {
	 LCD_u8Clear();
 	ADC_enuRead((u16*)p);
 	flag=1;
 }

 void read_temp(void*p)
 {
	 LCD_u8Clear();
	 THERMO_enuGetTemp((f32 *)p);
 	flag=1;
 }


 int main()
 {

 	//LM35Driver with INTERRUPT MODE & LCD
 		f32 adc32=0;

 		DIO_enuInit();
 		LCD_enuInit();

 		DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);

 		EXIT_enuInit(EXTI_ArrstrConfig);
 		EXIT_enuSelectSenseLevel(0,FALLING_EDGE);
 		EXIT_enuEnableInt(0);

 		ADC_enuEnableADC();
 		THERMO_enuInit(LM35_AstrLM35Config);
 		ADC_enuEnableTriggeringMode(ADC_EXTI0);
 		ADC_enuEnableInterruptMode();

 		ADC_enuCallBack(read_temp,&adc32);

 		ADC_enuStartConversion();

 		GIE_enuEnable();


 		while(1)
 		{
 			if(flag==1)
 			{
 				LCD_enuDisplayString("Temperature=");
 				LCD_enuDisplayIntegerNumber(adc32);
 				LCD_enuDisplayChar(0xDF);
 				LCD_enuDisplayChar('C');
 				flag=0;

 			}
 		}
 }

/*
void read(void *p)
{
	ADC_enuRead((u16*)p);

}


int main (void)
{
	DIO_enuInit();
    LCD_enuInit();
    u16 adcread=0;

	//DIO_enuSetPortDirection(DIO_u8PORTC,0xff);
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8INPUT);

	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);

	EXIT_enuInit(EXTI_ArrstrConfig);
	EXIT_enuSelectSenseLevel(0,FALLING_EDGE);
	EXIT_enuEnableInt(0);

	ADC_enuInit();
	ADC_enuEnableADC();
	ADC_enuSelectChannel(2);
	ADC_enuEnableTriggeringMode(ADC_EXTI0);
	ADC_enuEnableInterruptMode();

	ADC_enuCallBack(read,&adcread);

	ADC_enuStartConversion();

	GIE_enuEnable();

	while(1)
	{

	//DIO_enuSetPortValue(DIO_u8PORTC,adcread);
             if (flag ==1)
             {
			LCD_enuDisplayIntegerNumber(adcread);
			flag=0;
             }
	}

	return 0;


}*/
/*	int main(void)
	{
		DIO_enuInit();
		LCD_enuInit();
		DIO_enuSetPortDirection(DIO_u8PORTC,0xff);
		DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8INPUT);
		ADC_enuInit();
		ADC_enuEnableADC();
		ADC_enuSelectChannel(2);
		ADC_enuDisableTriggeringMode();
		u8 adcread=0;


		while(1)
		{
		  ADC_enuStartConversion();
		  ADC_enuPollingSystem();
		  ADC_enuReadHighValue(&adcread);
		  DIO_enuSetPortValue(DIO_u8PORTC,adcread);

		  LCD_enuDisplayIntegerNumber(adcread);

		}
		return 0;
	}


*/

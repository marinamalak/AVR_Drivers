/*
 * APP_prog.c
 *
 *  Created on: Sep 29, 2023
 *      Author: Marina
 */
#include "../LIB/STDTYPE.h"
#include "../LIB/ErrorState.h"

#include "../MCAL/DIO_int.h"

#include "../HAL/LCD/LCD_int.h"
#include "../HAL/LCD/LCD_config.h"

#include "../HAL/KEYPAD/Keypad_int.h"
#include "../HAL/KEYPAD/Keypad_config.h"

#include "APP_priv.h"


ES_t APP_enuInit(void)
{
	ES_t Loca_ErrorState =ES_NOK;

	Loca_ErrorState= DIO_enuInit();
	Loca_ErrorState= LCD_enuInit();
	Loca_ErrorState= KEYPAD_enuInit();

	return Loca_ErrorState;
}

ES_t APP_inenuConvertCharToNumber(u8* Copy_u8Char)
 {
	ES_t Local_ErrorState =ES_NOK;
	if (Copy_u8Char !=NULL)
	{
		switch(*Copy_u8Char)
		{
		case '0':
			*Copy_u8Char =0;
			break;
		case '1':
			*Copy_u8Char =1;
			break;
		case '2':
			*Copy_u8Char =2;
			break;
		case '3':
			*Copy_u8Char =3;
			break;
		case '4':
			*Copy_u8Char =4;
			break;
		case '5':
			*Copy_u8Char =5;
			break;
		case '6':
			*Copy_u8Char =6;
			break;
		case '7':
			*Copy_u8Char =7;
			break;
		case '8':
			*Copy_u8Char =8;
			break;
		case '9':
			*Copy_u8Char =9;
			break;
		default:
			LCD_u8Clear();
			*Copy_u8Char ='e';
			break;
		}
	}
	else
	{
		Local_ErrorState =ES_NULL_POINTER;
	}

  return Local_ErrorState;
}

ES_t APP_enuStartApp(void)
{
	ES_t Loca_ErrorState =ES_NOK;

	  do{

		  Number_1=KEYPAD_u8GetPressedKey();

		  if(Number_1 != KPD_NO_PRESSED_KEY)
		  {
			  LCD_u8Clear();
		  }
	  }while(Number_1 == KPD_NO_PRESSED_KEY );

	Loca_ErrorState= LCD_enuDisplayChar(Number_1);
	Loca_ErrorState|=APP_inenuConvertCharToNumber(&Number_1);


   do{
		 Operation=KEYPAD_u8GetPressedKey();
	    }while(Operation == KPD_NO_PRESSED_KEY);

	    LCD_enuDisplayChar(Operation);


	  do{
		  Number_2=KEYPAD_u8GetPressedKey();
	  }while(Number_2 == KPD_NO_PRESSED_KEY);

	  Loca_ErrorState|=LCD_enuDisplayChar(Number_2);
	  Loca_ErrorState|= APP_inenuConvertCharToNumber(&Number_2);

	     if((Operation != '+' &&Operation != '-'&&Operation != '*'&&Operation != '/' &&Operation != '%' )
	    		 ||(Number_1 =='e'||Number_2 == 'e'))
	      {
	     	  Operation ='e';
	      }

	       Loca_ErrorState|=LCD_enuDisplayChar('=');

	 if(Operation !='e')
	 {
	   switch(Operation)
	 	  {
	 	  case '-':
	 		  if (Number_2 > Number_1)
	 		  {
	 			 Loca_ErrorState|=LCD_enuDisplayChar('-');
	 		      Result =Number_2 - Number_1 ;
	 		  }else
	 		  {
	 		      Result =Number_1 - Number_2 ;
	 		  }
	 		  break;
	 	  case '+':
	 		  Result =Number_1 + Number_2 ;
	 		  break;
	 	  case '*':
	 		  Result =Number_1 * Number_2 ;
	 		  break;
	 	  case '/':
	 		  Result =Number_1 / Number_2 ;
	 		  break;
	 	  case '%':
	 		  Result =Number_1 % Number_2 ;
	 		  break;
	 	  }

	  if( (Result/10) != 0)
	  {
		 Result_Tens = Result / 10 ;
		 Result_Ones = Result % 10;
		 Loca_ErrorState|=LCD_enuDisplayChar(Arr_Numbers[Result_Tens]);
		 Loca_ErrorState|=LCD_enuDisplayChar(Arr_Numbers[Result_Ones]);
	  }
	  else
	  {
		  Result_Ones = Result;
		  Loca_ErrorState|=LCD_enuDisplayChar(Arr_Numbers[Result_Ones]);
	  }
	 }
	 else
	 {
		 LCD_u8Clear();
	 }

	return Loca_ErrorState ;
}



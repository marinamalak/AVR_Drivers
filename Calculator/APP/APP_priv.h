/*
 * APP_priv.h
 *
 *  Created on: Sep 29, 2023
 *      Author: Admin
 */

#ifndef APP_APP_PRIV_H_
#define APP_APP_PRIV_H_

 u8 Arr_Numbers[]={0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39};

 u8 Number_1;
 u8 Number_2;
 u8 Operation;
 u8 Result;
 u8 Result_Ones;
 u8 Result_Tens;

 ES_t APP_inenuConvertCharToNumber(u8* Copy_u8Char);

#endif /* APP_APP_PRIV_H_ */

/*
 * LCD_int.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Admin
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuDisplayChar(u8 Copy_u8char);

ES_t LCD_enuDisplayIntegerNumber(u8 Copy_u8Num);

ES_t LCD_enuDisplayString(u8 *Copy_pu8Data);

ES_t LCD_enuSendCommand(u8 Copy_u8command);

void LCD_u8Clear(void);

#endif /* LCD_INT_H_ */

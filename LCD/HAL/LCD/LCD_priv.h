/*
 * LCD_priv.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Admin
 */

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#define EIGHT_BIT  5
#define FOUR_BIT  6

static inline void LCD_invidSendCommand(u8 Copy_u8command);

static void LCD_vidLatch(u8 Copy_u8Data);

#endif /* LCD_PRIV_H_ */

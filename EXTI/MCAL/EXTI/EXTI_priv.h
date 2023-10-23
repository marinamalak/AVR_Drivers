/*
 * EXIT_priv.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Admin
 */

#ifndef HAL_EXTI_PRIV_H_
#define HAL_EXTI_PRIV_H_

#define MCUCR   *((volatile u8*)0x55)
#define GICR    *((volatile u8*)0x5B)
#define GIFR    *((volatile u8*)0x5A)
#define MCUCSR  *((volatile u8*)0x54)

#define ENABLE    1
#define DISABLE   0

#define INT0  0
#define INT1  1
#define INT2  2

#define RISING_EDGE     1
#define FALLING_EDGE    2
#define LOGICAL_CHANGE  3
#define LOW_LEVEL       4

#endif /* HAL_EXTI_PRIV_H_ */

/*
 * ADC_priv.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Admin
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_

#define PRES_2     1
#define PRES_4     2
#define PRES_8     3
#define PRES_16    4
#define PRES_32    5
#define PRES_64    6
#define PRES_128   7

#define AVCC_REF   5
#define AREF_REF   6
#define INTERNAL   7

#define RIGHT_ADJ  22
#define LEFT_ADJ   33

#define FREE_RUNNING       1
#define ANALOG_COMPARATOR  2
#define EXTI0              3
#define TIMER_COUNT0       4
#define TIMER_COUNT0_OVERFLOW  5
#define TIMER_COUNT1       6
#define TIMER_COUNT1_OVERFLOW   7
#define TIMER_COUNT1_EVENT 8

#define ADCSRA  *((u8*)0x26)
#define ADMUX   *((u8*)0x27)
#define ADCH    *((volatile u8*)0x25)  //volatile because it is read only
#define ADCL    *((volatile u8*)0x24)

#define SFIOR   *((u8*)0x50)

#endif /* MCAL_ADC_ADC_PRIV_H_ */

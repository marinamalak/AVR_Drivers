/*
 * ADC_int.h
 *
 *  Created on: Nov 6, 2023
 *      Author: Admin
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

ES_t ADC_enuInit(void);

ES_t ADC_enuEnableADC(void);

ES_t ADC_enuStartConversion(void);

ES_t ADC_enuPollingSystem(void);

ES_t ADC_enuReadHighValue(u8* copy_pu8value);

ES_t ADC_enuRead(u16* copy_pu16value);

ES_t ADC_enuCallBack(void(copy_pfunAppFun)(void*),void* copy_pvidAppParameter);

ES_t ADC_enuSelectChannel(u8 copy_u8ChannelID);

ES_t ADC_enuEnableTriggeringMode(u8 copy_u8TriggeringSource);

ES_t ADC_enuDisableTriggeringMode(void);

ES_t ADC_enuEnableInterruptMode(void);

#define ADC_FREE_RUNNING       1
#define ADC_ANALOG_COMPARATOR  2
#define ADC_EXTI0              3
#define ADC_TIMER_COUNT0       4
#define ADC_TIMER_COUNT0_OVERFLOW  5
#define ADC_TIMER_COUNT1       6
#define ADC_TIMER_COUNT1_OVERFLOW   7
#define ADC_TIMER_COUNT1_EVENT 8

#endif /* MCAL_ADC_ADC_INT_H_ */

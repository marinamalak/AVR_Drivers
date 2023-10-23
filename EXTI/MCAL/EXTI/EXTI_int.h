/*
 * EXTI_int.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Admin
 */

#ifndef HAL_EXTI_INT_H_
#define HAL_EXTI_INT_H_



ES_t EXIT_enuInit(EXTI_t* copy_pstrEXTIConfig);

ES_t EXIT_enuSelectSenseLevel(u8 copy_u8ID,u8 copy_u8SenseLevel);

ES_t EXIT_enuEnableInt(u8 copy_u8ID);

ES_t EXIT_enuDisableInt(u8 copy_u8ID);

ES_t EXTI_enuCallBack(void(*copy_pFunApp)(void*),void* copy_pvoidParameter,u8 copy_u8EXTI_ID);

#endif /* HAL_EXTI_INT_H_ */

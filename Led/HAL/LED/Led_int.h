/*
 * Led_int.h
 *
 *  Created on: Jul 27, 2023
 *      Author: Admin
 */

#ifndef LED_INT_H_
#define LED_INT_H_

ES_t LED_enuInit(LED_t *copy_pStrLedConfig);

ES_t LED_enuTurnON(LED_t *copy_pStrLedID);

ES_t LED_enuTurnOFF(LED_t *copy_pStrLedID);

#endif /* LED_INT_H_ */

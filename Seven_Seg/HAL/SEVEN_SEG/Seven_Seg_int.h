/*
 * Seven_Seg_int.h
 *
 *  Created on: Aug 7, 2023
 *      Author: Admin
 */

#ifndef SEVEN_SEG_INT_H_
#define SEVEN_SEG_INT_H_

ES_t seven_segment_enuInit(SEG_t *Copy_PStrSegConfig);

ES_t seven_segment_enuDisplayNum(u8 Copy_u8SegId,u8 copy_u8Num);

ES_t seven_segment_enuEnableCommon(u8 Copy_u8SegId);

ES_t seven_segment_enuDisableCommon(u8 Copy_u8SegId);

ES_t seven_segment_enuEnableDot(u8 Copy_u8SegId);

ES_t seven_segment_enuDisableDot(u8 Copy_u8SegId);

ES_t seven_segment_enuClearDisplay(u8 Copy_u8SegId);

#endif /* SEVEN_SEG_INT_H_ */

/*
 * main.c
 *
 *  Created on: Aug 7, 2023
 *      Author: Marina
 */
#include "../LIB/STDTYPE.h"
#include "../LIB/ErrorState.h"

#include "../MCAL/DIO_int.h"

#include "../HAL/SEVEN_SEG/Seven_Seg_config.h"
#include "../HAL/SEVEN_SEG/Seven_Seg_int.h"

#include <util/delay.h>


extern SEG_t SEVSEG_AStrSegConfig[SEG_NUM];

int main(void)
{
  DIO_enuInit();
  seven_segment_enuInit(SEVSEG_AStrSegConfig);

  while(1)
  {

          seven_segment_enuDisableCommon(0);
          seven_segment_enuDisplayNum(0,9);
          seven_segment_enuEnableCommon(0);
          _delay_ms(10);

          seven_segment_enuDisableCommon(0);
          seven_segment_enuDisplayNum(1,6);
          seven_segment_enuEnableCommon(1);
          _delay_ms(10);
          seven_segment_enuDisableCommon(1);


  }

	return 0;
}

/*
 * Seven_Seg_config.h
 *
 *  Created on: Aug 7, 2023
 *      Author: Admin
 */

#ifndef SEVEN_SEG_CONFIG_H_
#define SEVEN_SEG_CONFIG_H_

#define SEG_NUM  2

typedef struct{
	u8 SEG_u8APIN;
	u8 SEG_u8APORT;

	u8 SEG_u8BPIN;
	u8 SEG_u8BPORT;

	u8 SEG_u8CPIN;
	u8 SEG_u8CPORT;

	u8 SEG_u8DPIN;
	u8 SEG_u8DPORT;

	u8 SEG_u8EPIN;
	u8 SEG_u8EPORT;

	u8 SEG_u8FPIN;
	u8 SEG_u8FPORT;

	u8 SEG_u8GPIN;
	u8 SEG_u8GPORT;

	u8 SEG_u8_CMN_PIN;
	u8 SEG_u8_CMN_PORT;

	u8 SEG_u8_DOT_PIN;
	u8 SEG_u8_DOT_PORT;

	u8 SEG_u8TYPE;
}SEG_t;




#endif /* SEVEN_SEG_CONFIG_H_ */

/*
 * Seven_Seg_priv.h
 *
 *  Created on: Aug 7, 2023
 *      Author: Admin
 */

#ifndef SEVEN_SEG_PRIV_H_
#define SEVEN_SEG_PRIV_H_

#define COMMON_CATHODE 0
#define COMMON_ANODE 1

//if dot OR common not connect
#define NOT_CONNECTED 20


static u8 SEG_Au8NumDisplay[]= {0x3f,0x06,0x5b,
						  0x4f,0x66,0x6d,
						  0x7d,0x07,0x7f,
                         0x6f};
#endif /* SEVEN_SEG_PRIV_H_ */

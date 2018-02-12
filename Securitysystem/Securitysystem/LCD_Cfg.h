/*
 * LCD_Cfg.h
 *
 *  Created on: Sep 22, 2017
 *      Author: hossam
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_
/*Data Mode Config*/
#define DATA_MODE_4 0
#define DATA_MODE_8 1
#define DATA_MODE DATA_MODE_4

/*Cursor mode Config*/
#define CURSOR_OFF 0
#define CURSOR_BLINK 1
#define CURSOR_MODE CURSOR_OFF

/*GPIO Groups Config*/
#define RS_GROUP_IDX 8
#define RW_GROUP_IDX 9
#define EN_GROUP_IDX 10
#if DATA_MODE == DATA_MODE_8
#define DB0_GROUP_IDX 11
#define DB1_GROUP_IDX 12
#define DB2_GROUP_IDX 13
#define DB3_GROUP_IDX 14
#endif
#define DB4_GROUP_IDX 11
#define DB5_GROUP_IDX 12
#define DB6_GROUP_IDX 13
#define DB7_GROUP_IDX 14




#endif /* LCD_CFG_H_ */

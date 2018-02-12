/*
 * Timer1_PWM_mode.h
 *
 *  Created on: 30 Sep 2017
 *      Author: Bassem
 */

#ifndef TIMER1_PWM_MODE_H_
#define TIMER1_PWM_MODE_H_

#include "Types.h"

// x= (1/freq)*clk/prescaler
#define clk 8000000
#define freq 1000
#define prescaler 1024
#define simulation_conversion_one_sec 8
// 5 --- 0 degree
// 22 -- 45 degree

#define TCCR1A *((u8*) 0x4f)
#define TCCR1B *((u8*) 0x4e)
#define OCR1AH *((u8*) 0x4B)
#define OCR1AL *((u8*) 0x4A)
#define ICR1H *((u8*) 0x47)
#define ICR1L *((u8*) 0x46)


extern void Timer1_voidInit(void);

#endif /* TIMER1_PWM_MODE_H_ */

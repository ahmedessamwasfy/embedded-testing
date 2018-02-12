/*
 * Timer1_PWM_mode.c
 *
 *  Created on: 30 Sep 2017
 *      Author: Bassem
 */

#include"Timer1_PWM_mode.h"
#include "Types.h"
#include "utilss.h"

extern void Timer1_voidInit(void)
{	// TCCR1A Bit 7:6 – COM1A1:0: Compare Output Mode for Channel A
	set_bit(TCCR1A,7);
	clr_bit(TCCR1A,6);
	// TCCR1A Bit 3 – FOC1A: Force Output Compare for Channel A
	clr_bit(TCCR1A,3);
	//TCCR1A Bit 1:0 – WGM11:0: Waveform Generation Mode
	set_bit(TCCR1A,1);
	clr_bit(TCCR1A,0);
	// TCCR1B Bit 4:3 – WGM13:2: Waveform Generation Mode
	set_bit(TCCR1B,4);
	set_bit(TCCR1B,3);
	// TCCR1B Bit 2:0 – CS12:0: Clock Select
	set_bit(TCCR1B,2);
	clr_bit(TCCR1B,1);
	clr_bit(TCCR1B,0);

	ICR1L=clk/prescaler/freq;
	ICR1H=0;
}


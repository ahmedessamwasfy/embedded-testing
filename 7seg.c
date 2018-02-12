#include "7seg.h"
#include <avr/io.h>
#include  "common.h"
#include "DIO.h"
#define F_CPU (12000000ul)
#include <util/delay.h>

void SEG_Init(void ){
	DIO_WritePin(19,SEG1_Enable);
	DIO_WritePin(18,SEG2_Enable);
}

void SEG_BCDWrite(char val){
	
	
	DIO_WritePin(SEGD,Get_Bit(val,3));
	DIO_WritePin(SEGC,Get_Bit(val,2));
	DIO_WritePin(SEGB,Get_Bit(val,1));
	DIO_WritePin(SEGA,Get_Bit(val,0));
}

void SEG1 (char val){
	DIO_WritePin(SEG1_En_Pin,SEG1_Enable);
	DIO_WritePin(SEG2_En_Pin,SEG2_Disable);
	SEG_BCDWrite(val);
	_delay_ms(5);
}
void SEG2 (char val){
	DIO_WritePin(SEG2_En_Pin,SEG2_Enable);
	DIO_WritePin(SEG1_En_Pin,SEG1_Disable);
	SEG_BCDWrite(val);
	_delay_ms(5);
}

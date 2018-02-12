/*
 * ADC.h
 *
 *  Created on: 22 Sep 2017
 *      Author: Bassem
 */
#include "Types.h"

#ifndef ADC_H_
#define ADC_H_

#define ADMUX *((u8*) 0x27)
#define ADCSRA *((u8*) 0x26)
#define ADCH *((u8*) 0x25)
#define ADCL *((u8*) 0x24)

//#define RESF1 0
//#define RESF0 1

extern void ADC_voidInit (void);
extern u8 ADC_u8Read(u8 pin_number);
extern u16 ADC_u16Read(void);


#endif /* ADC_H_ */

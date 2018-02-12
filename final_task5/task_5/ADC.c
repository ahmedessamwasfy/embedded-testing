/*
 * ADC.c
 *
 *  Created on: 22 Sep 2017
 *      Author: Bassem
 */

#include "Types.h"
#include "utilss.h"
#include "DIO.h"
#include "ADC.h"

extern void ADC_voidInit(void)
{
	// reference voltage = 5
	clr_bit(ADMUX,7);
	set_bit(ADMUX,6); //ADMUX |= (RESF1<<7)|(RESF0<<6)
	// Left Adjust
	set_bit(ADMUX,5);
	/*// Select ADC pin A0
	clr_bit(ADMUX,4);
	clr_bit(ADMUX,3);
	clr_bit(ADMUX,2);
	clr_bit(ADMUX,1);
	clr_bit(ADMUX,0);*/
	// ADC Enable
	set_bit(ADCSRA,7);
	// No Auto Trigger
	clr_bit(ADCSRA,5);
	// No interrupt
	clr_bit(ADCSRA,3);
	// Prescale =2
	clr_bit(ADCSRA,2);
	clr_bit(ADCSRA,1);
	set_bit(ADCSRA,0);
}

extern u8 ADC_u8Read(u8 pin_number) // resolution=8
{
	u8 ADC_pin[5] = {0,0,0,0,0};
	u8 i=0;
	while (pin_number!=0)
	{
		for (i=0 ; i<5 ; i++)
			{
				ADC_pin[i]=(pin_number%2);
				pin_number /= 2;
			}
	}

	ADMUX |= (ADC_pin[i-1]<<(i-1)) | (ADC_pin[i-2]<<(i-2)) | (ADC_pin[i-3]<<(i-3)) | (ADC_pin[i-4]<<(i-4)) | (ADC_pin[i-5]<<(i-5));
	set_bit(ADCSRA,6);
	while (! get_bit(ADCSRA,4));
	set_bit(ADCSRA,4);
	return ADCH;
}
extern u16 ADC_u16Read(void) // resolution=10
{
	u16 return_data=0;
	u8 i=0;
	set_bit(ADCSRA,6);
	while (! get_bit(ADCSRA,4));
	set_bit(ADCSRA,4);
	for (i=0;i<=7;i++)
	{
		if (i<2)
		{
			return_data += get_bit(ADCL,(i+6))*(2^i);
		}
		return_data += get_bit(ADCH,i)*(2^(i+2));
	}
	return return_data;
}

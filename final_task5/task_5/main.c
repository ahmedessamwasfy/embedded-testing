/*
 * main.c
 *
 *  Created on: 23 Sep 2017
 *      Author: Bassem
 */

#include <util/delay.h>
#include "Types.h"
#include "DIO.h"
#include "ADC.h"
#include "Timer1_PWM_mode.h"
#include "LCD.h"


#define vol_ref 5
#define scale 100
#define res 256
#define asci_conv 48
#define buzzer_pin DIO_u8PinD3

int main(void)
{
	ADC_voidInit();
	LCD_voidInit();
	Timer1_voidInit();
	DIO_voidSetDirection(DIO_u8PinD5,DIO_u8PinOp);

	u8 temp_digital_value;
	u8 temp_scaled_value;
	u8 i=2;
	u8 temp_final_value[2] = {0,0};
	u8 temp_value[3]={0,0,0};
	u8 temp=0;
	u8 temp_average=0;
	u8 counter=0;
	Timer1_voidInit();
	DIO_voidSetDirection(DIO_u8PinD5,DIO_u8PinOp);
	DIO_voidSetDirection(DIO_u8PinD3,DIO_u8PinOp);
	DIO_voidWritePIN(DIO_u8PinD3,DIO_u8LOW);
	LCD_voidWriteCommand(0x80);
	LCD_voidDisplay('t');
	LCD_voidDisplay('e');
	LCD_voidDisplay('m');
	LCD_voidDisplay('p');
	LCD_voidDisplay('=');

	while(1){
		temp_digital_value = ADC_u8Read(1);
		temp_scaled_value = (temp_digital_value*vol_ref*scale/256);
		temp_value[i]=temp_scaled_value;
		i++;
		if (i==3)
		{
			temp = (temp_value[i-1]+temp_value[i-2]+temp_value[i-3])/3;
			temp_average=temp;
			for (i=0 ; i<2 ; i++)
			{

				temp_final_value[i]=(temp%10);
				temp /= 10;
			}
			LCD_voidWriteCommand(0x86);
			LCD_voidDisplay((asci_conv+temp_final_value[i-1]));
			LCD_voidDisplay((asci_conv+temp_final_value[i-2]));
			i=0;
			if (temp_average<=27)
			{
				OCR1AL=0;
			}
			else if ((temp_average>27) && (temp_average<=35))
			{
				OCR1AL=2;
			}
			else if ((temp_average>36) && (temp_average<=42))
			{
				OCR1AL=4;
			}
			else if ((temp_average>43) && (temp_average<50))
			{
				OCR1AL=6;
			}
			else if ((temp_average>51) && (temp_average<55))
			{
				OCR1AL=8;
			}
			else
			{
				OCR1AL=8;
				counter++;
			}
			if (counter==(10000/100))
			{
				DIO_voidWritePIN(buzzer_pin,DIO_u8HIGH);
			}
		}

		_delay_ms(100);
	}
	return 0;
}

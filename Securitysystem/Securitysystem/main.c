/*
 * Securitysystem.c
 *
 * Created: 2/10/2017 9:01:52 PM
 * Author : MOHAMMED-PC
 */ 
#define F_CPU 16000000L
#include "GPIO.h"
#include "GPIO_Cfg.h"
#include "keyPad_Drive.h"
#include "LCD.h"
#include "LCD_Cfg.h"
#include "eeprom.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void check_password();

ISR(INT0_vect)
{
	LCD_Clear();
	LCD_SetCursPos(0,0);
	LCD_DispString("System Resetted");
	_delay_ms(1000);
	EEPROM_write(10,0);
	EEPROM_write(11,0);
	LCD_Clear();
	check_password();
}

int main(void)
{
    /* Replace with your application code */
    EEPROM_write(0,'0');	
	EEPROM_write(1,'1');
	EEPROM_write(2,'2');
	EEPROM_write(3,'3');
	EEPROM_write(10,0);
	EEPROM_write(11,0);
	
    GPIO_Init();
    LCD_Init();
	//MCUCR = 1 << 2;
	GICR = (1 << INT0);
	sei();
	
	GPIO_Write(15,0x00);
	
    while (1) 
    {
			check_password();
    }
}

void check_password()
{
	unsigned char check_char;
	uint8_t j = 0;
	uint8_t flag = 0;
	
	
	while((EEPROM_read(10) != 2) && (EEPROM_read(11) != 1))
	{
		LCD_SetCursPos(0,0);
		LCD_DispString("Enter Password");
		LCD_SetCursPos(j,1);
		check_char = getkey();
		
		if(check_char != 'F')
		{
			if(check_char == EEPROM_read(j))
			{
				flag++;
			}
			j++;
			LCD_DispChar('*');
		}
		
		if (check_char == '=')
		{
			if (j == (flag + 1))
			{
				LCD_Clear();
				LCD_SetCursPos(0,0);
				LCD_DispString("Door Unlocked");
				EEPROM_write(11,1);
				j = 0;
				flag = 0;
				GPIO_Write(15,0xff);
			}
			else
			{
				LCD_Clear();
				LCD_SetCursPos(0,0);
				LCD_DispString("Wrong Password");
				flag = 0;
				j = 0;
				EEPROM_write(10,EEPROM_read(10)+1);
				_delay_ms(2000);
				LCD_Clear();
			}
		}	
	}
	
	if (EEPROM_read(10) == 2)
	{
		LCD_SetCursPos(0,0);
		LCD_DispString("Door Blocked");
	}

}


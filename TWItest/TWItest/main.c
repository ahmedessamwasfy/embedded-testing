/*
 * TWItest.c
 *
 * Created: 18/10/2017 3:01:49 PM
 * Author : MOHAMMED-PC
 */ 
#define F_CPU 16000000L

#include <avr/io.h>
#include <stdlib.h>
#include "GPIO.h"
#include "GPIO_Cfg.h"
#include "LCD.h"
#include "LCD_Cfg.h"
#include "I2C.h"
#include <util/delay.h>

unsigned char hour, mint, second, date, month,hour1,mint1,second1, date1, month1;
uint32_t year,year1;
void RTC_Set_Time();
void RTC_Set_Date();
void RTC_Get_Time();
void RTC_Get_Date();

int main(void)
{
    GPIO_Init();
	LCD_Init();
    I2C_Init (); // initialize I2C module
	char a[2];
    hour = 0x21; mint = 0x40 ; second = 0x50;
    RTC_Set_Time(); // Set time 21:40:30
    date = 0x25; month = 0x12 ; year = 0x10;
    RTC_Set_Date(); // Set date 25-12-2010
	LCD_SetCursPos(0,0);
    while(1)
	{
	    RTC_Get_Time();
	   // PORTD = hour; PORTB = mint; PORTA = second;
	   LCD_SetCursPos(0,0);
	   itoa(hour1,a,16);
	   LCD_DispString(a);
	   LCD_DispChar(':');
	   itoa(mint1,a,16);
	   LCD_DispString(a);
	   LCD_DispChar(':');
	   itoa(second1,a,16);
	   LCD_DispString(a);
	   //date
	    RTC_Get_Date();
	   LCD_SetCursPos(0,1);
	   itoa(date1,a,16);
	   LCD_DispString(a);
	   LCD_DispChar('/');
	   itoa(month1,a,16);
	   LCD_DispString(a);
	   LCD_DispChar('/');
	   itoa(year1,a,16);
	   LCD_DispString(a);
	   // PORTD = day; PORTB = month; PORTA = year;
    }
    return 0;
}


void RTC_Set_Time()
 {
	I2C_Start(); // transmit START condition
	I2C_Write(0xD0); // address DS1307 for write
	I2C_Write(0); // set register pointer to 0
	I2C_Write(second); // set seconds
	I2C_Write(mint); // set minuts
	I2C_Write(hour); // set Hours
I2C_Stop(); 
}

void RTC_Set_Date() 
{
	I2C_Start(); // transmit START condition
	I2C_Write(0xD0); // address DS1307 for write
	I2C_Write(0x04); // set register pointer to 4
	I2C_Write(date); // set day
	I2C_Write(month); // set month
	I2C_Write(year); // set year
    I2C_Stop();
 }
 void RTC_Get_Time()
 {
	 I2C_Start () ; //transmit START condition
	 I2C_Write(0xD0); //address DS1307 for write
	 I2C_Write(0); //set register pointer to 0
	 I2C_Start () ; //transmit START condition
	 I2C_Write(0xD1); //address DS1307 for read
	 second1 = I2C_Read(1); //read second, return ACK
	 mint1 = I2C_Read(1); //read minute, return ACK
	 hour1 = I2C_Read(0); //read hour, return NACK
     I2C_Stop();  //transmit STOP condition
 
 } 
 
 
 void RTC_Get_Date() 
 {
	 I2C_Start () ; //transmit START condition
	 I2C_Write(0xD0); //address DS1307 for write
	 I2C_Write(4); //set register pointer to 4
	 I2C_Start() ; //transmit START condition
	 I2C_Write(0xD1); //address DS1307 for read
	 date1 = I2C_Read(1); //read second, return ACK
	 month1 = I2C_Read(1); //read minute, return ACK
	 year1 = I2C_Read(0); //read hour, return NACK
     I2C_Stop(); 
 }
 
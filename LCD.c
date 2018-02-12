#include "DIO.h"
#include "LCD.h"
#include <avr/io.h>
#define F_CPU (12000000ul)
#include <util/delay.h>


 void LCD_WriteCommand(char command) {
	 DIO_WritePin(LCD_RSPin,0);
	 DIO_WritePin(LCD_RWPin,0);
	 DIO_WritePort(LCD_Port,command);
	 DIO_WritePin(LCD_ENPin,1);
	 _delay_us(10);
	 DIO_WritePin(LCD_ENPin,0);
	 DIO_WritePort(LCD_Port,(command<<4));
	 DIO_WritePin(LCD_ENPin,1);
	 _delay_us(10);
	 DIO_WritePin(LCD_ENPin,0);
	 _delay_us(10);
	 
	
}
void LCD_init() {
	_delay_ms(15);
	LCD_WriteCommand(0x33);
	LCD_WriteCommand(0x32);
	LCD_WriteCommand(0x28);
	LCD_WriteCommand(0x0c);
	LCD_WriteCommand(0x01);
	_delay_us(2000);
	LCD_WriteCommand(0x06);
	_delay_us(1000);
	
	
}
void LCD_WriteString(char *str){
	while (*str>0){
		LCD_WriteData(*str);
		str++;
	}
}
void LCD_WriteData(  char data ){
	DIO_WritePin(LCD_RSPin,1);
	DIO_WritePin(LCD_RWPin,0);
	DIO_WritePort(LCD_Port,data);
	DIO_WritePin(LCD_ENPin,1);
	_delay_us(10);
	DIO_WritePin(LCD_ENPin,0);
	DIO_WritePort(LCD_Port,(data<<4));
	DIO_WritePin(LCD_ENPin,1);
	_delay_us(10);
	DIO_WritePin(LCD_ENPin,0);
	_delay_us(10);
	
}
/*
 * I2C.c
 *
 * Created: 18/10/2017 3:05:45 PM
 *  Author: MOHAMMED-PC
 */ 
#include <avr/io.h>

void I2C_Init(void)
{
	//set SCL to 400kHz
	TWSR = 0x00;
	TWBR = 32;
	//enable TWI
	TWCR = (1<<TWEN);
}
void I2C_Start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
}
//send stop signal
void I2C_Stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
void I2C_Write(uint8_t u8data)
{
	TWDR = u8data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);

}
void I2C_Set_Address(unsigned char address)
{
	TWAR = address;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
}
unsigned char I2C_Read(unsigned char ack){
	TWCR = (1<<TWINT)|(1<<TWEN)|(ack<<TWEA);
	while ((TWCR & 0x80) == 0); return TWDR;
}
uint8_t I2C_GetStatus(void)
{
	uint8_t status;
	//mask status
	status = TWSR & 0xF8;
	return status;
}
uint8_t I2C_ReadACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}
//read byte with NACK
uint8_t I2C_ReadNACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while ((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}

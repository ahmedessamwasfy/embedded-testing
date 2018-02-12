/*
 * I2C.h
 *
 * Created: 18/10/2017 3:31:10 PM
 *  Author: MOHAMMED-PC
 */ 


#ifndef I2C_H_
#define I2C_H_
void I2C_Init(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(uint8_t u8data);
void I2C_Set_Address(unsigned char address);
unsigned char I2C_Read(unsigned char ack);
uint8_t I2C_ReadACK(void);
uint8_t I2C_ReadNACK(void);




#endif /* I2C_H_ */
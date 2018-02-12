

#include <avr/io.h>
#include "common.h"
#include "EEPROM.h"




extern void EEPROM_Init (void)
{
	EEARH=0;
	EEARL=0;
	
	
}

extern void EEPROM_Write(char address , char data)
{
	
	EEDR = data;
	EEARL=address;
	Set_Bit(EECR,2);
	Set_Bit(EECR,1);
	while (! Get_Bit(EECR,1));
	Clear_Bit(EECR,2);
}

extern char EEPROM_Read(char address)
{
	

	EEARL=address;
	Set_Bit(EECR,0);
	return EEDR;
}





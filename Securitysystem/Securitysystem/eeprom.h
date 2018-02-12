#ifndef EEPROM_H_INCLUDED
#define EEPROM_H_INCLUDED

void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
unsigned char EEPROM_read(unsigned int uiAddress);

#endif // EEPROM_H_INCLUDED

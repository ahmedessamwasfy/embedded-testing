
#ifndef INTERNAL_EEPROM_H_
#define INTERNAL_EEPROM_H_

/*#define EEARH *((char*)0x1F)
#define EEARL *((char*)0x1E)

#define EEDR  *((char*)0x1D)
#define EECR  *((char*)0x1C)*/


extern void EEPROM_Init (void);
extern void EEPROM_Write(char address , char data);
extern char EEPROM_Read(char address);

#endif /* INTERNAL_EEPROM_H_ */

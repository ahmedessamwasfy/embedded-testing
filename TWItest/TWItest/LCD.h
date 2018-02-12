#ifndef LCD_H
#define LCD_H

typedef enum {LCD_OK =0, LCD_NOK}LCD_ChkType;
void LCD_Init(void);
LCD_ChkType LCD_DispChar(char Data);
LCD_ChkType LCD_SetCursPos(int x,int y);
LCD_ChkType LCD_Clear(void);
LCD_ChkType LCD_DispString(char* StrPtr);
#endif

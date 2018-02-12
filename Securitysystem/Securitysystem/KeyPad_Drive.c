/*
 * KeyPad_Drive.c
 *
 * Created: 28/09/2017 03:28:28 ص
 *  Author: SHIKO
 */ 
#include "keyPad_Drive.h"
#include "GPIO.h"
#include "GPIO_Cfg.h"

unsigned char Data ; 
char getkey()
{
	int i, j;
	for(i = Row0; i <= Row3; i++)
	{
		GPIO_Write(Row0,0xff);
		GPIO_Write(Row1,0xff);
		GPIO_Write(Row2,0xff);
		GPIO_Write(Row3,0xff);
		
		GPIO_Write(i,0x00);

		for(j = Col0 ; j <= Col3 ; j++)
		{
			GPIO_Read(j,&Data);
			if(Data == 0x00)//check if key is pressed
			{
				while(Data == 0x00) {GPIO_Read(j,&Data);}  //wait for key to be released
				switch(i)
				{
					case(Row0):
					{
						if      (j == Col0) return '7';
						else if (j == Col1) return '8';
						else if (j == Col2) return '9';
						else if (j == Col3) return '/';
						break;
					}
					case(Row1):
					{
						if      (j == Col0) return '4';
						else if (j == Col1) return '5';
						else if (j == Col2) return '6';
						else if (j == Col3) return '*';
						break;
					}
					case(Row2):
					{
						if      (j == Col0) return '1';
						else if (j == Col1) return '2';
						else if (j == Col2) return '3';
						else if (j == Col3) return '-';
						break;
					}
					case(Row3):
					{
						if      (j == Col0) return '?';
						else if (j == Col1) return '0';
						else if (j == Col2) return '=';
						else if (j == Col3) return '+';
						break;
					}
				}
			}
		}
	}
	return 'F';//Return 'A' if no key is pressed.
}
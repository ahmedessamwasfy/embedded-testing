#include "GPIO.h"
#include "GPIO_Cfg.h"

// Array {R0,R1,R2,R3,Col0.Col1,Col2,Col3}
const GPIO_CfgType GPIO_ConfigParam [GPIO_GROUPS_NUMBER] =
		{		
				{
					0,
					1<<0,
					0xff,
					0xff
				},
				{
					0,
					1<<1,
					0xff,
					0xff
				},
				{
					0,
					1<<2,
					0xff,
					0xff
				},
				{
					0,
					1<<3,
					0xff,
					0xff
				},
				{
					0,
					1<<4,
					0xff,
					0xff
				},
				{
					0,
					1<<5,
					0xff,
					0xff
				},
				{
					0,
					1<<6,
					0xff,
					0xff
				},
				
		};

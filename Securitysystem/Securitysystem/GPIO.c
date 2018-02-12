#include "GPIO.h"
#include "GPIO_Cfg.h"
#include <stdint.h>

typedef volatile uint8_t* const GPIO_RegAddType;
#define PORTS_NUMBER 4u
/*Register memory map*/
#define PORTA_BASE_ADDRESS 0x3B
#define PORTB_BASE_ADDRESS 0x38
#define PORTC_BASE_ADDRESS 0x35
#define PORTD_BASE_ADDRESS 0x32

static const uint8_t PortsBaseAddressLut[PORTS_NUMBER] =
{       PORTA_BASE_ADDRESS,
	    PORTB_BASE_ADDRESS,
	    PORTC_BASE_ADDRESS,
	    PORTD_BASE_ADDRESS,
};

#define GPIO_REG_ADDRESS(CHANNEL_ID,REG_OFFSET)\
(PortsBaseAddressLut[CHANNEL_ID] - REG_OFFSET)

/*Port Control*/
#define GPIODATA_WRITE(DATA,MASK,PORT_ID)  *((GPIO_RegAddType)(GPIO_REG_ADDRESS(PORT_ID,0x00)))
#define GPIODATA_READ(MASK,PORT_ID)        *((GPIO_RegAddType)(GPIO_REG_ADDRESS(PORT_ID,0x02)))
#define GPIODIR_REG(PORT_ID)               *((GPIO_RegAddType)(GPIO_REG_ADDRESS(PORT_ID,0x01)))

static uint8_t GPIO_GroupState[GPIO_GROUPS_NUMBER] = {0};

/*A function to initialize all the GPIO Groups in the configurations*/
GPIO_CheckType GPIO_Init(void)
{
	uint8_t LoopIndex;
	uint8_t ErrorFlag = 0;
	GPIO_CheckType RetVar;
	const GPIO_CfgType * CfgPtr;


	for(LoopIndex = 0; (LoopIndex < GPIO_GROUPS_NUMBER) && (ErrorFlag == 0); LoopIndex ++)
	{
		if(GPIO_ConfigParam[LoopIndex].PortId < PORTS_NUMBER)
        {
           /*Enable port clock gate*/
            CfgPtr = & GPIO_ConfigParam[LoopIndex];
			/*Data Control*/
			GPIODIR_REG(CfgPtr->PortId) |= (CfgPtr->PortMask & CfgPtr->PortDirection);
			/*Pad Control*/
			//GPIODATA_WRITE(0x00,CfgPtr->PortMask,CfgPtr->PortId) |= (CfgPtr->PortMask & CfgPtr->PortWrite);
			GPIODATA_READ(CfgPtr->PortMask,CfgPtr->PortId) |= (CfgPtr->PortDirection & CfgPtr->PortWrite);
			GPIO_GroupState[LoopIndex] = 1;
			RetVar = GPIO_OK;
        }
		else
		{
			/*Invalid GroupId*/
			RetVar = GPIO_NOK;
			ErrorFlag = 1;
		}


	}
	return RetVar;
}



/*A function to Digital Write data to a specific group*/
GPIO_CheckType GPIO_Write(uint8_t GroupId,uint8_t GroupData)
{
	const GPIO_CfgType * CfgWrite;
	GPIO_CheckType ReturnVar;

	if (( GroupId <GPIO_GROUPS_NUMBER))
	{

		CfgWrite =  & GPIO_ConfigParam[GroupId];

		if ((CfgWrite->PortDirection == 0xff)&&(GPIO_GroupState[GroupId]==1 ))
		{
		    if(GroupData == 0x00)
            {
                GPIODATA_WRITE(GroupData,CfgWrite->PortMask,CfgWrite->PortId) &= ~(CfgWrite->PortMask);
		        ReturnVar = GPIO_OK;
            }
            if(GroupData == 0xff)
            {
                GPIODATA_WRITE(GroupData,CfgWrite->PortMask,CfgWrite->PortId) |= (CfgWrite->PortMask);
		        ReturnVar = GPIO_OK;
            }

	    }

		else
		{
			ReturnVar = GPIO_NOK ;
		}

	}
	else
	{
		ReturnVar = GPIO_NOK ;
	}

	return ReturnVar;
}




/*A function to Digital read data from a specific group*/
GPIO_CheckType GPIO_Read(uint8_t GroupId,uint8_t* GroupDataPtr)
{

	const GPIO_CfgType * CfgRead;
		GPIO_CheckType RetVar;
		if (( GroupId <GPIO_GROUPS_NUMBER))
			{
			    CfgRead = &GPIO_ConfigParam[GroupId];
				if ((CfgRead->PortDirection == 0x00)&&(GPIO_GroupState[GroupId]==1 ))
				{
                   *GroupDataPtr = (GPIODATA_READ(CfgRead->PortMask,CfgRead->PortId) & (CfgRead->PortMask) );
                   RetVar = GPIO_OK;
				}
				else
				 {
					 RetVar = GPIO_NOK ;
				 }

			}
			else
			{
				RetVar = GPIO_NOK ;
			}

			return RetVar;
}



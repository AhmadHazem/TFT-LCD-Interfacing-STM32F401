#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DET.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void SPI_vidInit (void)
{
	SPI -> CR1 = 0x0347;
}

Std_ReturnType SPI_udtTransceive (uint8 u8Data, uint8* pu8ReceivedData)
{
	Std_ReturnType udtRetVal = E_NOT_OK;
	
	uint8 u8LocalFlag = 0u;
	
    uint32 u32LocalCounter = 0u;
	
	SPI -> DR = u8Data;
	
	while(GET_BIT(SPI -> SR, 7) == 1u)
	{
		u32LocalCounter++;
		
		if(u32LocalCounter == SPI_USER_TIMEOUT)
		{
			u8LocalFlag = 1u;
			break;
		}
	}
	
	if(u8LocalFlag == 0u)
	{
		*pu8ReceivedData = SPI -> DR;
		
		udtRetVal = E_OK;
	}
	
	return udtRetVal;
}
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_lcfg.h"

GPIO_pinState  GPIO_udtArrayOfPins [GPIO_NUMBER_OF_USED_PIN] = 
{
	[0] = {
		     .u8PortId      = GPIO_PORTA,
			 .u8PinId       = GPIO_PIN0,
			 .udtMode       = GPIO_OUTPUT,
			 .udtType       = GPIO_PUSH_PULL,
			 .udtSpeed      = GPIO_LOW_SPEED,
			 .udtInputState = NOT_USED,
			 .udtAlternativeFunction = NOT_USED
	      },
    [1] = {
		     .u8PortId      = GPIO_PORTA,
			 .u8PinId       = GPIO_PIN1,
			 .udtMode       = GPIO_OUTPUT,
			 .udtType       = GPIO_PUSH_PULL,
			 .udtSpeed      = GPIO_LOW_SPEED,
			 .udtInputState = NOT_USED,
			 .udtAlternativeFunction = NOT_USED
	      },
    [2] = {
		     .u8PortId      = GPIO_PORTA,
			 .u8PinId       = GPIO_PIN5,
			 .udtMode       = GPIO_AF,
			 .udtType       = NOT_USED,
			 .udtSpeed      = GPIO_LOW_SPEED,
			 .udtInputState = NOT_USED,
			 .udtAlternativeFunction = GPIO_AF5
		   },
	[3] = {
		     .u8PortId      = GPIO_PORTA,
			 .u8PinId       = GPIO_PIN7,
			 .udtMode       = GPIO_AF,
			 .udtType       = NOT_USED,
			 .udtSpeed      = GPIO_LOW_SPEED,
			 .udtInputState = NOT_USED,
			 .udtAlternativeFunction = GPIO_AF5
	      }
		  
};



/*
 * GPIO_program.c
 *
 *  Created on: Sep 8, 2023
 *      Author: BLU-RAY
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DET.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_lcfg.h"

static GPIO_type* GPIOx[3]={GPIOA,GPIOB,GPIOC};
static uint8 u8PinsCounter = 0u;

void GPIO_Init (void)
{

		if (GPIO_udtArrayOfPins[u8PinsCounter].u8PinId >= GPIO_UPPER_PINS_NUMBERS)
			Det_ReportError(GPIO_MODULE_ID, GPIO_INVALID_PIN_STATE, GPIO_UDT_SET_PIN_VALUE_ID);

		GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1]->MODER &= ~((0b11) << ((GPIO_udtArrayOfPins[u8PinsCounter].u8PinId) * 2));
		GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1]->MODER |= ((GPIO_udtArrayOfPins[u8PinsCounter].udtMode) << ((GPIO_udtArrayOfPins[u8PinsCounter].u8PinId) * 2));
		if(GPIO_udtArrayOfPins[u8PinsCounter].udtMode == GPIO_OUTPUT)
		{
			GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1]->OTYPER &= ~(1u << (GPIO_udtArrayOfPins[u8PinsCounter].u8PinId));
			GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1]->OTYPER |= ((GPIO_udtArrayOfPins[u8PinsCounter].udtType) <<
						                                                      (GPIO_udtArrayOfPins[u8PinsCounter].u8PinId));

			GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1] -> OSPEEDR &= ~((0b11) << ((GPIO_udtArrayOfPins[u8PinsCounter].u8PinId) * 2));
		    GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1] -> OSPEEDR |= ((GPIO_udtArrayOfPins[u8PinsCounter].udtSpeed) <<
		                        												 ((GPIO_udtArrayOfPins[u8PinsCounter].u8PinId) * 2));
		}
		else if(GPIO_udtArrayOfPins[u8PinsCounter].udtMode == GPIO_INPUT)
		{
			/* !Comment: Setting the input pin state */
			GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1]->PUPDR &= ~((0b11) << ((GPIO_udtArrayOfPins[u8PinsCounter].u8PinId) * 2));
		    GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1]->PUPDR |= ((GPIO_udtArrayOfPins[u8PinsCounter].udtInputState) <<
		                      ((GPIO_udtArrayOfPins[u8PinsCounter].u8PinId) * 2));
		}
		else if (GPIO_udtArrayOfPins[u8PinsCounter].udtMode == GPIO_AF)
		{
			if (GPIO_udtArrayOfPins[u8PinsCounter].u8PinId < GPIO_LOWER_PINS_NUMBERS)
			{
				GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1]->AFRL &= ~((0b1111) << ((GPIO_udtArrayOfPins[u8PinsCounter].u8PinId) * 4));
				GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1]->AFRL |= ((GPIO_udtArrayOfPins[u8PinsCounter].udtAlternativeFunction) << ((GPIO_udtArrayOfPins[u8PinsCounter].u8PinId) * 4));
			}
			else
			{
				GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1]->AFRH &= ~((0b1111) << ((GPIO_udtArrayOfPins[u8PinsCounter].u8PinId % 8) * 4));
				GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1]->AFRH |= ((GPIO_udtArrayOfPins[u8PinsCounter].udtAlternativeFunction) << ((GPIO_udtArrayOfPins[u8PinsCounter].u8PinId % 8) * 4));
			}

//			GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1]->OTYPER &= ~(1u << (GPIO_udtArrayOfPins[u8PinsCounter].u8PinId));
//			GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1]->OTYPER |= ((GPIO_udtArrayOfPins[u8PinsCounter].udtType) <<
//						                                                      (GPIO_udtArrayOfPins[u8PinsCounter].u8PinId));

			GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1] -> OSPEEDR &= ~((0b11) << ((GPIO_udtArrayOfPins[u8PinsCounter].u8PinId) * 2));
		    GPIOx[(GPIO_udtArrayOfPins[u8PinsCounter].u8PortId)-1] -> OSPEEDR |= ((GPIO_udtArrayOfPins[u8PinsCounter].udtSpeed) <<
		                        												 ((GPIO_udtArrayOfPins[u8PinsCounter].u8PinId) * 2));
		}
		else
		{
			Det_ReportError(GPIO_MODULE_ID, GPIO_INVALID_PIN_STATE, GPIO_UDT_SET_PIN_VALUE_ID);
		}

		u8PinsCounter++;
}

Std_ReturnType GPIO_udtSetPinValue(uint8 u8PortId, uint8 u8PinId, uint8 u8Value)
{
	/* !Comment: Variable for handling the function return value */
	Std_ReturnType udtReturnValue = E_NOT_OK;

	if(u8PinId >= 16)
	{
		Det_ReportError(GPIO_MODULE_ID, GPIO_INVALID_PIN_STATE, GPIO_UDT_SET_PIN_VALUE_ID);
	}
	else
	{
		if(u8Value == GPIO_HIGH)
		{
			switch(u8PortId)
			{
				case GPIO_PORTA: udtReturnValue = E_OK;
				                 SET_BIT(GPIOA -> ODR, u8PinId);
								 break;
				case GPIO_PORTB: udtReturnValue = E_OK;
				                 SET_BIT(GPIOB -> ODR, u8PinId);
								 break;
				case GPIO_PORTC: udtReturnValue = E_OK;
				                 SET_BIT(GPIOC -> ODR, u8PinId);
								 break;
				default: Det_ReportError(GPIO_MODULE_ID, GPIO_INVALID_PORT_ID, GPIO_UDT_SET_PIN_VALUE_ID);
				break;
			}
		}
		else if(u8Value == GPIO_LOW)
		{
			switch(u8PortId)
			{
				case GPIO_PORTA: udtReturnValue = E_OK;
				                 CLR_BIT(GPIOA -> ODR, u8PinId);
								 break;
				case GPIO_PORTB: udtReturnValue = E_OK;
				                 CLR_BIT(GPIOB -> ODR, u8PinId);
								 break;
				case GPIO_PORTC: udtReturnValue = E_OK;
				                 CLR_BIT(GPIOC -> ODR, u8PinId);
								 break;
				default:  Det_ReportError(GPIO_MODULE_ID, GPIO_INVALID_PORT_ID, GPIO_UDT_SET_PIN_VALUE_ID);
				break;
			}
		}
		else
		{
			Det_ReportError(GPIO_MODULE_ID, GPIO_INVALID_PIN_STATE, GPIO_UDT_SET_PIN_VALUE_ID);
		}

	}

	return udtReturnValue;
}

Std_ReturnType GPIO_udtGetPinValue(uint8 u8PortId, uint8 u8PinId, uint8* pu8PinValue)
{
	/* !Comment: Variable for handling the function return value */
	Std_ReturnType udtReturnValue = E_NOT_OK;

	if(u8PinId >= 16)
	{
		Det_ReportError(GPIO_MODULE_ID, GPIO_INVALID_PIN_STATE, GPIO_UDT_GET_PIN_VALUE_ID);
	}
	else
	{
		switch(u8PortId)
		{
			case GPIO_PORTA: *pu8PinValue = GET_BIT(GPIOA -> IDR, u8PinId);
			                  udtReturnValue = E_OK;
							  break;
			case GPIO_PORTB: *pu8PinValue = GET_BIT(GPIOB -> IDR, u8PinId);
			                  udtReturnValue = E_OK;
			                  break;
			case GPIO_PORTC: *pu8PinValue = GET_BIT(GPIOC -> IDR, u8PinId);
			                  udtReturnValue = E_OK;
                    		  break;
			default: Det_ReportError(GPIO_MODULE_ID, GPIO_INVALID_PORT_ID, GPIO_UDT_GET_PIN_VALUE_ID);
			break;
		}
	}

	return udtReturnValue;
}

Std_ReturnType GPIO_udtAtomicSetPinValue(uint8 u8PortId, uint8 u8PinId, uint8 u8Value)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;

	if(u8PinId >= 16)
	{
		Det_ReportError(GPIO_MODULE_ID, GPIO_INVALID_PIN_STATE, GPIO_UDTATOMICSETPINVALUE_ID);
	}
	else
		{
			uint8 shift_val;
			switch(u8PortId)
			{
				case GPIO_PORTA:
								  shift_val = (u8Value == GPIO_LOW) ? (u8PinId + 16) : u8PinId;
								  SET_BIT(GPIOA->BSRR,shift_val);
								  break;
				case GPIO_PORTB:
								  shift_val = (u8Value == GPIO_LOW) ? (u8PinId + 16) : u8PinId;
								  SET_BIT(GPIOB->BSRR,shift_val);
				                  break;
				case GPIO_PORTC:
								  shift_val = (u8Value == GPIO_LOW) ? (u8PinId + 16) : u8PinId;
								  SET_BIT(GPIOC->BSRR,shift_val);
	                    		  break;
				default: Det_ReportError(GPIO_MODULE_ID, GPIO_INVALID_PORT_ID, GPIO_UDT_GET_PIN_VALUE_ID);
				break;
			}
		}

		return udtReturnValue;
}

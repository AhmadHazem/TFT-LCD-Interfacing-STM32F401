/*
 * GPIO_interface.h
 *
 *  Created on: Sep 8, 2023
 *      Author: BLU-RAY
 */

#ifndef _GPIO_INTERFACE_H_
#define _GPIO_INTERFACE_H_

/* !Comment: Port definitions */
#define GPIO_PORTA    1u
#define GPIO_PORTB    2u
#define GPIO_PORTC    3u

/* !Comment: Pin definitions */
#define GPIO_PIN0     0u
#define GPIO_PIN1     1u
#define GPIO_PIN2     2u
#define GPIO_PIN3     3u
#define GPIO_PIN4     4u
#define GPIO_PIN5     5u
#define GPIO_PIN6     6u
#define GPIO_PIN7     7u
#define GPIO_PIN8     8u
#define GPIO_PIN9     9u
#define GPIO_PIN10    10u
#define GPIO_PIN11    11u
#define GPIO_PIN12    12u
#define GPIO_PIN13    13u
#define GPIO_PIN14    14u
#define GPIO_PIN15    15u

/* !Comment: Pin values */
#define GPIO_HIGH     1u
#define GPIO_LOW      0u



/* Module Public Interfaces */
void GPIO_Init (void);

Std_ReturnType GPIO_udtSetPinValue(uint8 u8PortId, uint8 u8PinId, uint8 u8Value);
Std_ReturnType GPIO_udtGetPinValue(uint8 u8PortId, uint8 u8PinId, uint8* pu8PinValue);

Std_ReturnType GPIO_udtAtomicSetPinValue(uint8 u8PortId, uint8 u8PinId, uint8 u8Value);

Std_ReturnType GPIO_udtLockPinConfig(uint8 u8PortId, uint8 u8PinId);
Std_ReturnType GPIO_udtUnlockPinConfig(uint8 u8PortId, uint8 u8PinId);


/* !Comment: GPIO functions IDs */
#define GPIO_INIT_ID                     1u
#define GPIO_UDT_SET_PIN_VALUE_ID        2u
#define GPIO_UDT_GET_PIN_VALUE_ID        3u
#define GPIO_UDTATOMICSETPINVALUE_ID     4u
#define GPIO_UDTUNLOCKPINCONFIG_ID       5u
#define GPIO_UDTLOCKPINCONFIG_ID         6u

/* !Comment: GPIO Errors IDs */
#define GPIO_INVALID_PORT_ID             1u
#define GPIO_INVALID_PIN_STATE           2u
#define GPIO_INVALID_PIN_ID              3u

/* !Comment:Max Pins */
#define GPIO_LOWER_PINS_NUMBERS			 8u
#define GPIO_UPPER_PINS_NUMBERS			 16u

#endif /* _GPIO_INTERFACE_H_ */

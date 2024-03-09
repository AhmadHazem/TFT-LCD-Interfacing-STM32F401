/*
 * GPIO_private.h
 *
 *  Created on: Sep 7, 2023
 *      Author: BLU-RAY
 */

#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_

#define A	0u
#define B	1u
#define C	2u


typedef struct
{
	uint32 MODER;
	uint32 OTYPER;
	uint32 OSPEEDR;
	uint32 PUPDR;
	uint32 IDR;
	uint32 ODR;
	uint32 BSRR;
	uint32 LCKR;
	uint32 AFRL;
	uint32 AFRH;
}GPIO_type;


#define GPIOA ((GPIO_type*)0x40020000u)
#define GPIOB ((GPIO_type*)0x40020400u)
#define GPIOC ((GPIO_type*)0x40020800u)



#define NOT_USED  255u


typedef enum
{
	GPIO_INPUT,
	GPIO_OUTPUT,
	GPIO_AF,
	GPIO_ANALOG
}GPIO_MODES_E;

typedef enum
{
	GPIO_PUSH_PULL,
	GPIO_OPEN_DRAIN
}GPIO_OTYPE_E;

/* !Comment: GPIO port output speed register (GPIOx_OSPEEDR) */
typedef enum
{
	GPIO_LOW_SPEED,
	GPIO_MEDIUM_SPEED,
	GPIO_HIGH_SPEED,
	GPIO_VHIGH_SPEED
}GPIO_OSPEED_E;

/* !Comment: GPIO port pull-up/pull-down register (GPIOx_PUPDR) */
typedef enum
{
	GPIO_FLOATING,
	GPIO_PULL_UP,
	GPIO_PULL_DOWN
}GPIO_INPUT_E;

typedef enum
{
	 GPIO_AF0,
	 GPIO_AF1,
	 GPIO_AF2,
	 GPIO_AF3,
	 GPIO_AF4,
	 GPIO_AF5,
	 GPIO_AF6,
	 GPIO_AF7,
	 GPIO_AF8,
	 GPIO_AF9,
	 GPIO_AF10,
	 GPIO_AF11,
	 GPIO_AF12,
	 GPIO_AF13,
	 GPIO_AF14,
	 GPIO_AF15
}GPIO_ALTERNATIVE_FUNCTION_E;

/* !Comment: GPIO pin configurations */
typedef struct
{
	uint8 u8PortId;
	uint8 u8PinId;

	GPIO_MODES_E udtMode;
	GPIO_OTYPE_E udtType;
	GPIO_OSPEED_E udtSpeed;
	GPIO_INPUT_E udtInputState;
	GPIO_ALTERNATIVE_FUNCTION_E udtAlternativeFunction;

}GPIO_pinState;


#endif /* _GPIO_PRIVATE_H_ */

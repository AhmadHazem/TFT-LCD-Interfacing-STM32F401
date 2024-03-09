#ifndef _STD_TYPES_H_
#define _STD_TYPES_H_

/* !Comment: Standard types */
typedef unsigned char             uint8;
typedef unsigned short int        uint16;
typedef unsigned long int         uint32;

/* !Comment: Error states */
typedef enum
{
	E_OK,
	E_NOT_OK,
	E_PENDING
}Std_ReturnType;


#define STD_ON     1u
#define STD_OFF    0u


#endif 
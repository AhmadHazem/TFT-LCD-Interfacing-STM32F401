#ifndef _UART_PRIVATE_H_
#define _UART_PRIVATE_H_

typedef struct
{
	uint32 SR;
	uint32 DR;
	uint32 BRR;
	uint32 CR1;
	uint32 CR2;
	uint32 CR3;
	uint32 GTPR;
}UART_type;

//P2VAR(UART_type, AUTOMATIC, UART_APPL_VAR) UART = base address;

#define UART ((volatile UART_type*)0x40011000UL)

#endif
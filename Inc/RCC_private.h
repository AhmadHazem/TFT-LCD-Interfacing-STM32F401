#ifndef _RCC_PRIVATE_H_
#define _RCC_PRIVATE_H_

/* !Comment: RCC registers. */
typedef struct
{
	uint32 CR;
	uint32 PLLCFGR;
	uint32 CFGR;
	uint32 CIR;
	uint32 AHB1RSTR;
	uint32 AHB2RSTR;
	uint32 RESERVED1;
	uint32 RESERVED2;
	uint32 APB1RSTR;
	uint32 APB2RSTR;
	uint32 RESERVED3;
	uint32 RESERVED4;
	uint32 AHB1ENR;
	uint32 AHB2ENR;
	uint32 RESERVED5;
	uint32 RESERVED6;
	uint32 APB1ENR;
	uint32 APB2ENR;
	uint32 RESERVED7;
	uint32 RESERVED8;
	uint32 AHB1LPENR;
	uint32 AHB2LPENR;
	uint32 RESERVED9;
	uint32 RESERVED10;
	uint32 APB1LPENR;
	uint32 APB2LPENR;
	uint32 RESERVED11;
	uint32 RESERVED12;
	uint32 BDCR;
	uint32 CSR;
	uint32 RESERVED13;
	uint32 RESERVED14;
	uint32 SSCGR;
	uint32 PLLI2SCFGR;
	uint32 RESERVED15;
	uint32 DCKCFGR;
}RCC_type;

/* !Comment: Defining RCC pointer */
#define RCC  ((volatile RCC_type*)0x40023800u)

/* !Comment : max peripheral id for each bus */
#define RCC_MAX_PERIPHERAL_ID   ((uint8)31u)

#endif
#ifndef _SPI_PRIVATE_H_
#define _SPI_PRIVATE_H_

typedef struct
{
	uint32 CR1;
	uint32 CR2;
	uint32 SR;
	uint32 DR;
	uint32 CRCPR;
	uint32 RXCRCR;
	uint32 TXCRCR;
	uint32 I2SCFGR;
	uint32 I2SPR;
}SPI_type;

#define SPI  ((SPI_type*)0x40013000u)



#endif 
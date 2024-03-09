#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_

void SPI_vidInit (void);

Std_ReturnType SPI_udtTransceive (uint8 u8Data, uint8* pu8ReceivedData);

#endif 
#ifndef _UART_INTERFACE_H_
#define _UART_INTERFACE_H_

void UART_vidInit (void);
//FUNC(void, UART_APPL_CODE) UART_vidInit (void);

Std_ReturnType UART_udtTransmit (uint8* pu8Data);
//FUNC(Std_ReturnType, UART_APPL_CODE) UART_udtTransmit (P2VAR(uint8, AUTOMATIC, UART_APPL_VAR) pu8Data);

Std_ReturnType UART_udtTransmitNum (uint8 u8Data);
//FUNC(Std_ReturnType, UART_APPL_CODE) UART_udtTransmitNum (VAR(uint8, AUTOMATIC) u8Data);

Std_ReturnType UART_udtReceive (uint8* pu8ReceivedData);

#endif
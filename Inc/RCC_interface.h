#ifndef _RCC_INTERFACE_H_
#define _RCC_INTERFACE_H_

/* !Comment: Bus Ids */
#define AHB                   1u
#define APB1                  2u
#define APB2                  3u

/* !Comment: Clock Selection Ids */
#define RCC_HSI               1u
#define RCC_HSE_RC            2u
#define RCC_HSE_CRYSTAL       3u
#define RCC_PLL               4u

/* !Comment: Module Public Interfaces */
Std_ReturnType RCC_udtInitSystemClock        (void);
Std_ReturnType RCC_udtEnablePeripheralClock  (uint8 u8BusId, uint8 u8PerId);
Std_ReturnType RCC_udtDisablePeripheralClock (uint8 u8BusId, uint8 u8PerId);
Std_ReturnType RCC_udtResetPeripheral        (uint8 u8BusId, uint8 u8PerId);

/* !Comment: RCC module id */
#define RCC_ID                              1u

/* !Comment: RCC functions IDs */
#define RCC_udtInitSystemClock_ID           1u
#define RCC_udtEnablePeripheralClock_ID     2u
#define RCC_udtDisablePeripheralClock_ID    3u
#define RCC_udtResetPeripheral_ID           4u

/* !Comment: Error Ids */
#define RCC_INVALID_BUS_ID                  1u
#define RCC_INVALID_PERIPHERAL_ID           2u


#endif 

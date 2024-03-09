#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

Std_ReturnType RCC_udtInitSystemClock (void)
{
	#if RCC_CLOCK_SELECTION  == RCC_HSI
	
	#elif RCC_CLOCK_SELECTION == RCC_HSE_RC
	
	#elif RCC_CLOCK_SELECTION == RCC_HSE_CRYSTAL
	RCC -> CR   = 0x00010000;
	RCC -> CFGR = 0x00000001;
	#elif RCC_CLOCK_SELECTION == RCC_PLL
	
	#else 
		#error "Invalid clock selection"
	#endif 

	return 0;
}

Std_ReturnType RCC_udtEnablePeripheralClock (uint8 u8BusId, uint8 u8PerId)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	if(u8PerId <= RCC_MAX_PERIPHERAL_ID)
	{
		switch(u8BusId)
		{
			case AHB  : SET_BIT(RCC -> AHB1ENR, u8PerId);
			            udtReturnValue = E_OK;
			            break;
						
			case APB1 : SET_BIT(RCC -> APB1ENR, u8PerId);
			            udtReturnValue = E_OK;
			            break;
						
			case APB2 : SET_BIT(RCC -> APB2ENR, u8PerId);
			            udtReturnValue = E_OK;
			            break;
						
			default   : /* !Comment: Report Error */
			            #if RCC_DET_USED == STD_ON
			            /* Det_ReportError(RCC_ID, RCC_udtEnablePeripheralClock_ID, RCC_INVALID_BUS_ID); */
						#endif
			            break;
		}
	}
	else
	{
		/* !Comment: Report Error */
		#if RCC_DET_USED == STD_ON
		/* Det_ReportError(RCC_ID, RCC_udtEnablePeripheralClock_ID, RCC_INVALID_PERIPHERAL_ID);*/
		#endif
	}
	
	return udtReturnValue;
}

Std_ReturnType RCC_udtDisablePeripheralClock (uint8 u8BusId, uint8 u8PerId)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	if(u8PerId <= RCC_MAX_PERIPHERAL_ID)
	{
		switch(u8BusId)
		{
			case AHB  : CLR_BIT(RCC -> AHB1ENR, u8PerId);
			            udtReturnValue = E_OK;
			            break;
						
			case APB1 : CLR_BIT(RCC -> APB1ENR, u8PerId);
			            udtReturnValue = E_OK;
			            break;
						
			case APB2 : CLR_BIT(RCC -> APB2ENR, u8PerId);
			            udtReturnValue = E_OK;
			            break;
						
			default   : /* !Comment: Report Error */
			            #if RCC_DET_USED == STD_ON
			            /* Det_ReportError(RCC_ID, RCC_udtEnablePeripheralClock_ID, RCC_INVALID_BUS_ID); */
						#endif
			            break;
		}
	}
	else
	{
		/* !Comment: Report Error */
		#if RCC_DET_USED == STD_ON
		/* Det_ReportError(RCC_ID, RCC_udtEnablePeripheralClock_ID, RCC_INVALID_PERIPHERAL_ID);*/
		#endif
	}
	
	return udtReturnValue;
}

Std_ReturnType RCC_udtResetPeripheral (uint8 u8BusId, uint8 u8PerId)
{
	Std_ReturnType udtReturnValue = E_NOT_OK;
	
	if(u8PerId <= RCC_MAX_PERIPHERAL_ID)
	{
		switch(u8BusId)
		{
			case AHB  : SET_BIT(RCC -> AHB1RSTR, u8PerId);
			            udtReturnValue = E_OK;
			            break;
						
			case APB1 : SET_BIT(RCC -> APB1RSTR, u8PerId);
			            udtReturnValue = E_OK;
			            break;
						
			case APB2 : SET_BIT(RCC -> APB2RSTR, u8PerId);
			            udtReturnValue = E_OK;
			            break;
						
			default   : /* !Comment: Report Error */
			            #if RCC_DET_USED == STD_ON
			            /* Det_ReportError(RCC_ID, RCC_udtEnablePeripheralClock_ID, RCC_INVALID_BUS_ID); */
						#endif
			            break;
		}
	}
	else
	{
		/* !Comment: Report Error */
		#if RCC_DET_USED == STD_ON
		/* Det_ReportError(RCC_ID, RCC_udtEnablePeripheralClock_ID, RCC_INVALID_PERIPHERAL_ID);*/
		#endif
	}
	
	return udtReturnValue;
}

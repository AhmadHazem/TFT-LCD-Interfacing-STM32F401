#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

void (*SYSTICK_pvCallBack) (void);
volatile uint16 SYSTICK_u16GlobalSeconds = 0u;
volatile uint8 SYSTICK_u8SingleIndicator = 0u;

/* !Comment: Inittialization variable */
uint8 SYSTICK_u8IsInitialized = SYSTICK_NO_INIT;

Std_ReturnType SYSTICK_udtSynchSecondsDelay (uint16 u16Seconds)
{
	Std_ReturnType udtRetVal = E_NOT_OK;
	
	if(SYSTICK_u8IsInitialized == SYSTICK_INIT)
	{
		udtRetVal = E_OK;
		
		/* !Comment: A write of any value clears the field to 0,
         *          	and also clears the COUNTFLAG bit in the STK_CTRL register to 0.        
	     */
	    SYSTICK -> VAL.R  = 0u;
	    SYSTICK -> LOAD.R = 0;
        
	    uint16 u16LocalCounter = 0u;
	    
	    for(u16LocalCounter = 0u; u16LocalCounter < u16Seconds; u16LocalCounter++)
	    {
	    	/* !Comment: load 1 sec */
	    	SYSTICK -> LOAD.R = 3125000u;
	    	
	    	/* !Comment: Enable the systick */
	    	SYSTICK -> CTRL.B.ENABLE = 1u;
	    	
	    	/* !Comment: Wait for count flag */
	    	while(SYSTICK -> CTRL.B.COUNTFLAG == 0u);
	    	
	    	/* !Comment: clear count flag */
	    	SYSTICK -> CTRL.B.COUNTFLAG = 0u;	
		}
	}
		
	return udtRetVal;	
}

Std_ReturnType SYSTICK_udtSynchMsecondsDelay (uint16 u16Mseconds)
{
	Std_ReturnType udtRetVal = E_NOT_OK;
	
	if(SYSTICK_u8IsInitialized == SYSTICK_INIT)
	{
		udtRetVal = E_OK;
		
		/* !Comment: A write of any value clears the field to 0,
         *          	and also clears the COUNTFLAG bit in the STK_CTRL register to 0.        
	     */
	    SYSTICK -> VAL.R  = 0u;
	    SYSTICK -> LOAD.R = 0;
        
	    uint16 u16LocalCounter = 0u;
	    
	    for(u16LocalCounter = 0u; u16LocalCounter < u16Mseconds; u16LocalCounter++)
	    {
	    	/* !Comment: load 1 sec */
	    	SYSTICK -> LOAD.R = 3125u;
	    	
	    	/* !Comment: Enable the systick */
	    	SYSTICK -> CTRL.B.ENABLE = 1u;
	    	
	    	/* !Comment: Wait for count flag */
	    	while(SYSTICK -> CTRL.B.COUNTFLAG == 0u);
	    	
	    	/* !Comment: clear count flag */
	    	SYSTICK -> CTRL.B.COUNTFLAG = 0u;	
		}
	}
		
	return udtRetVal;
}
Std_ReturnType SYSTICK_udtSynchUsecondsDelay (uint16 u16Useconds)
{
	Std_ReturnType udtRetVal = E_NOT_OK;
	
	if(SYSTICK_u8IsInitialized == SYSTICK_INIT)
	{
		udtRetVal = E_OK;
		
		/* !Comment: A write of any value clears the field to 0,
         *          	and also clears the COUNTFLAG bit in the STK_CTRL register to 0.        
	     */
	    SYSTICK -> VAL.R  = 0u;
	    SYSTICK -> LOAD.R = 0;
        
	    uint16 u16LocalCounter = 0u;
	    
	    for(u16LocalCounter = 0u; u16LocalCounter < u16Useconds; u16LocalCounter++)
	    {
	    	/* !Comment: load 1 sec */
	    	SYSTICK -> LOAD.R = 3u;
	    	
	    	/* !Comment: Enable the systick */
	    	SYSTICK -> CTRL.B.ENABLE = 1u;
	    	
	    	/* !Comment: Wait for count flag */
	    	while(SYSTICK -> CTRL.B.COUNTFLAG == 0u);
	    	
	    	/* !Comment: clear count flag */
	    	SYSTICK -> CTRL.B.COUNTFLAG = 0u;	
		}
	}
		
	return udtRetVal;
}

Std_ReturnType SYSTICK_udtAsynchSecondsDelay (uint16 u16Seconds, void (*pvCallBack) (void))
{
	SYSTICK_u8SingleIndicator = 0u;
	SYSTICK_pvCallBack = pvCallBack;
    SYSTICK_u16GlobalSeconds = u16Seconds;

    Std_ReturnType udtRetVal = E_NOT_OK;
	
	if(SYSTICK_u8IsInitialized == SYSTICK_INIT)
	{
		udtRetVal = E_OK;
		
		/* !Comment: A write of any value clears the field to 0,
         *          	and also clears the COUNTFLAG bit in the STK_CTRL register to 0.        
	     */
	    SYSTICK -> VAL.R  = 0u;
	    SYSTICK -> LOAD.R = 0;
        
	    /* !Comment: load 1 sec */
	    SYSTICK -> LOAD.R = 3125000u;
		
		/* !Comment: Enable interrupts */
		SYSTICK -> CTRL.B.TICKINT = 1u;
    	
	    /* !Comment: Enable the systick */
	    SYSTICK -> CTRL.B.ENABLE = 1u;		
	}
		
	return udtRetVal;		
}

Std_ReturnType SYSTICK_udtAsynchSingleSecondsDelay  (uint16 u16Seconds, void (*pvCallBack) (void))
{
	SYSTICK_u8SingleIndicator = 1u;
	SYSTICK_pvCallBack = pvCallBack;
    SYSTICK_u16GlobalSeconds = u16Seconds;

    Std_ReturnType udtRetVal = E_NOT_OK;
	
	if(SYSTICK_u8IsInitialized == SYSTICK_INIT)
	{
		udtRetVal = E_OK;
		
		/* !Comment: A write of any value clears the field to 0,
         *          	and also clears the COUNTFLAG bit in the STK_CTRL register to 0.        
	     */
	    SYSTICK -> VAL.R  = 0u;
	    SYSTICK -> LOAD.R = 0;
        
	    /* !Comment: load 1 sec */
	    SYSTICK -> LOAD.R = 3125000u;
		
		/* !Comment: Enable interrupts */
		SYSTICK -> CTRL.B.TICKINT = 1u;
    	
	    /* !Comment: Enable the systick */
	    SYSTICK -> CTRL.B.ENABLE = 1u;		
	}
		
	return udtRetVal;	
}

void SYSTICK_vidInit (void)
{
	SYSTICK_u8IsInitialized = SYSTICK_INIT;
	
#if SYSTICK_CLOCK_SOURCE == SYSTICK_AHB
	SYSTICK -> CTRL.B.CLKSOURCE = 1u;
	
#elif SYSTICK_CLOCK_SOURCE == SYSTICK_AHB_DIV_8
	SYSTICK -> CTRL.B.CLKSOURCE = 0u; 
	
#else
	#error "Invalid clock source selection!!"

#endif
}

Std_ReturnType SYSTICK_udtGetElapsedTime (uint32* u32ElapsedTime)
{
	Std_ReturnType udtRetVal = E_NOT_OK;
	
	if(SYSTICK_u8IsInitialized == SYSTICK_INIT)
	{
		udtRetVal = E_OK;
		*u32ElapsedTime = ((SYSTICK -> LOAD.R) - (SYSTICK -> VAL.R));
	}
	
	return udtRetVal;
}

Std_ReturnType SYSTICK_udtGetRemainingTime (uint32* u32RemainingTime)
{
	Std_ReturnType udtRetVal = E_NOT_OK;
	
	if(SYSTICK_u8IsInitialized == SYSTICK_INIT)
	{
		udtRetVal = E_OK;
		*u32RemainingTime = SYSTICK -> VAL.R;
	}
	
	return udtRetVal;
}

void SysTick_Handler (void)
{
	static uint16 u16Counter = 1u;

    if(u16Counter == SYSTICK_u16GlobalSeconds)
	{
		SYSTICK_pvCallBack();
		u16Counter = 1u;
		
		if(SYSTICK_u8SingleIndicator == 1u)
		{
			SYSTICK -> VAL.R  = 0u;
		    SYSTICK -> LOAD.R = 0u;
		    SYSTICK -> CTRL.R = 0u;
		}	
	}
    else
	{
		u16Counter++;
	}		
}


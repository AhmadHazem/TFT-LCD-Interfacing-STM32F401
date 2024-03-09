#ifndef _SYSTICK_INTERFACE_H_
#define _SYSTICK_INTERFACE_H_

void SYSTICK_vidInit (void);

Std_ReturnType SYSTICK_udtSynchSecondsDelay         (uint16 u16Seconds);
Std_ReturnType SYSTICK_udtSynchMsecondsDelay        (uint16 u16Mseconds);
Std_ReturnType SYSTICK_udtSynchUsecondsDelay        (uint16 u16Useconds);
                                                    
Std_ReturnType SYSTICK_udtAsynchSecondsDelay (uint16 u16Seconds, void (*pvCallBack) (void));
Std_ReturnType SYSTICK_udtAsynchMsecondsDelay       (uint16 u16Mseconds);
Std_ReturnType SYSTICK_udtAsynchUsecondsDelay       (uint16 u16Useconds);
                                                    
Std_ReturnType SYSTICK_udtAsynchSingleSecondsDelay  (uint16 u16Seconds, void (*pvCallBack) (void));
Std_ReturnType SYSTICK_udtAsynchSingleMsecondsDelay (uint16 u16Mseconds);
Std_ReturnType SYSTICK_udtAsynchSingleUsecondsDelay (uint16 u16Useconds);

Std_ReturnType SYSTICK_udtGetElapsedTime            (uint32* u32ElapsedTime);
Std_ReturnType SYSTICK_udtGetRemainingTime          (uint32* u32RemainingTime);

void SYSTICK_vidStop (void);

#endif

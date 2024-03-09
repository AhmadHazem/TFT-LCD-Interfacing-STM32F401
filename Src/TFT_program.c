#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_config.h"
#include "TFT_private.h"


void TFT_vidInit (void)
{
	/* !Comment: Reset pulse */
	GPIO_udtSetPinValue(TFT_RESET_PIN, GPIO_HIGH);
	SYSTICK_udtSynchUsecondsDelay(100);
	
	GPIO_udtSetPinValue(TFT_RESET_PIN, GPIO_LOW);
	SYSTICK_udtSynchUsecondsDelay(1);
	
	GPIO_udtSetPinValue(TFT_RESET_PIN, GPIO_HIGH);
	SYSTICK_udtSynchUsecondsDelay(100);
	
	GPIO_udtSetPinValue(TFT_RESET_PIN, GPIO_LOW);
	SYSTICK_udtSynchUsecondsDelay(100);
	
	GPIO_udtSetPinValue(TFT_RESET_PIN, GPIO_HIGH);
	SYSTICK_udtSynchMsecondsDelay(120);
	
	/* !Comment: Send SLPOUT command */
	uint8 u8TempVar;
	
	GPIO_udtSetPinValue(TFT_A0_PIN, GPIO_LOW);
	SPI_udtTransceive(0x11, &u8TempVar);
	
	/* !Comment: Wait 150 ms */
	SYSTICK_udtSynchMsecondsDelay(150);
	
	/* !Comment: COLMOD configurations */	
	GPIO_udtSetPinValue(TFT_A0_PIN, GPIO_LOW);    // enter color mode
	SPI_udtTransceive(0x3A, &u8TempVar);
	
	GPIO_udtSetPinValue(TFT_A0_PIN, GPIO_HIGH);  // select color standard  RGB565
	SPI_udtTransceive(0x05, &u8TempVar);
	
	/* !Comment: Display mode */
	GPIO_udtSetPinValue(TFT_A0_PIN, GPIO_LOW);
	SPI_udtTransceive(0x29, &u8TempVar);
}

Std_ReturnType TFT_udtDisplayImage (const uint16* pu16Image)
{	
    /* !Comment: A temporary variable for handling the 2nd SPI API parameter */
    uint8 u8TempVar;

	/* !Comment: Set x address */
	GPIO_udtSetPinValue(TFT_A0_PIN, GPIO_LOW);
	SPI_udtTransceive(0x2A, &u8TempVar);
	
	GPIO_udtSetPinValue(TFT_A0_PIN, GPIO_HIGH); 
	SPI_udtTransceive(0  , &u8TempVar);
	SPI_udtTransceive(0  , &u8TempVar);
	SPI_udtTransceive(0  , &u8TempVar);
	SPI_udtTransceive(127, &u8TempVar);
	
	/* !Comment: Set y address */
	GPIO_udtSetPinValue(TFT_A0_PIN, GPIO_LOW);
	SPI_udtTransceive(0x2B, &u8TempVar);
	
	GPIO_udtSetPinValue(TFT_A0_PIN, GPIO_HIGH); 
	SPI_udtTransceive(0  , &u8TempVar);
	SPI_udtTransceive(0  , &u8TempVar);
	SPI_udtTransceive(0  , &u8TempVar);
	SPI_udtTransceive(159, &u8TempVar);
	
	/* !Comment: RAM write */
	GPIO_udtSetPinValue(TFT_A0_PIN, GPIO_LOW);
	SPI_udtTransceive(0x2C, &u8TempVar);
	SPI_udtTransceive(0x21, &u8TempVar);
	
	/* !Comment:  Displaying the image */
	GPIO_udtSetPinValue(TFT_A0_PIN, GPIO_HIGH); 
	
	uint16 u16LocalCounter = 0u;
	uint8  u8LocalData = 0u;
	for(u16LocalCounter = 0; u16LocalCounter < 20480; u16LocalCounter++)
	{
		u8LocalData = pu16Image[u16LocalCounter] >> 8u;
		SPI_udtTransceive(u8LocalData, &u8TempVar);
		
		u8LocalData = pu16Image[u16LocalCounter];
		SPI_udtTransceive(u8LocalData, &u8TempVar);
	}
	return 0;
}

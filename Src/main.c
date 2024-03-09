#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "SYSTICK_interface.h"
#include "RCC_interface.h"
#include "TFT_interface.h"
#include "image.h"

int main(void)
{
	/* RCC */
	RCC_udtInitSystemClock();
	RCC_udtEnablePeripheralClock(AHB, 0);
	RCC_udtEnablePeripheralClock(APB2, 12);

	/*GPIO */
	for(int i = 0; i < 4; i++ )
	{
		GPIO_Init();
	}


	/*SYSTICK */
	SYSTICK_vidInit();

	/*SPI */
	SPI_vidInit();

	/*TFT*/
	TFT_vidInit();

	TFT_udtDisplayImage(TFT_u16Image);

	while(1);
}

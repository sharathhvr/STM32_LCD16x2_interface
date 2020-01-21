/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "LCD.h"

int main(void)
{
	RCC_DeInit();

	SystemCoreClockUpdate();

	/*Enable clock for the port used: GPIOA */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);

	LCD_PinConfig_t LCD_PinConfig;
	LCD_PinConfig.GPIO_Port=GPIOA;
	LCD_PinConfig.dataPin[0]=GPIO_PinSource0;
	LCD_PinConfig.dataPin[1]=GPIO_PinSource1;
	LCD_PinConfig.dataPin[2]=GPIO_PinSource2;
	LCD_PinConfig.dataPin[3]=GPIO_PinSource3;
	LCD_PinConfig.dataPin[4]=GPIO_PinSource4;
	LCD_PinConfig.dataPin[5]=GPIO_PinSource5;
	LCD_PinConfig.dataPin[6]=GPIO_PinSource6;
	LCD_PinConfig.dataPin[7]=GPIO_PinSource7;
	LCD_PinConfig.regSelectPin=GPIO_PinSource8;
	LCD_PinConfig.readWritePin=GPIO_PinSource9;
	LCD_PinConfig.enablePin=GPIO_PinSource10;

	LCD_PinSetup(&LCD_PinConfig);

	LCD_ScreenSetup(&LCD_PinConfig);

	LCD_WriteData(&LCD_PinConfig,"HELLO WORLD");

	for(;;);
}

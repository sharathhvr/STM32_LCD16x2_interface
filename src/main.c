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
	LCD_PinConfig.dataPin[0]=GPIO_Pin_0;
	LCD_PinConfig.dataPin[1]=GPIO_Pin_1;
	LCD_PinConfig.dataPin[2]=GPIO_Pin_2;
	LCD_PinConfig.dataPin[3]=GPIO_Pin_3;
	LCD_PinConfig.dataPin[4]=GPIO_Pin_4;
	LCD_PinConfig.dataPin[5]=GPIO_Pin_5;
	LCD_PinConfig.dataPin[6]=GPIO_Pin_6;
	LCD_PinConfig.dataPin[7]=GPIO_Pin_7;
	LCD_PinConfig.regSelectPin=GPIO_Pin_8;
	LCD_PinConfig.readWritePin=GPIO_Pin_9;
	LCD_PinConfig.enablePin=GPIO_Pin_10;

	LCD_PinSetup(&LCD_PinConfig);

	LCD_ScreenSetup(&LCD_PinConfig);

	LCD_WriteData(&LCD_PinConfig,"AAAAA");

	for(;;);
}

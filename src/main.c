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

void delay(int n)
{
	for(int i=0;i<n;i++);
}


int main(void)
{
	RCC_DeInit();

	SystemCoreClockUpdate();

	/*Enable clock for the port used: GPIOA */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);

	LCD_PinConfig_t LCD_PinConfig;
	LCD_PinConfig.GPIO_Port=GPIOA;
	LCD_PinConfig.dataPin[0]=GPIO_Pin_4;
	LCD_PinConfig.dataPin[1]=GPIO_Pin_5;
	LCD_PinConfig.dataPin[2]=GPIO_Pin_6;
	LCD_PinConfig.dataPin[3]=GPIO_Pin_7;
	LCD_PinConfig.dataPin[4]=GPIO_Pin_8;
	LCD_PinConfig.dataPin[5]=GPIO_Pin_9;
	LCD_PinConfig.dataPin[6]=GPIO_Pin_10;
	LCD_PinConfig.dataPin[7]=GPIO_Pin_11;
	LCD_PinConfig.regSelectPin=GPIO_Pin_12;
	//LCD_PinConfig.readWritePin=GPIO_Pin_9;
	LCD_PinConfig.enablePin=GPIO_Pin_15;

	LCD_PinSetup(&LCD_PinConfig);

	LCD_ScreenSetup(&LCD_PinConfig);

	LCD_WriteData(&LCD_PinConfig," HELLO WORLD L1 ");

	LCD_Line2(&LCD_PinConfig);

	LCD_WriteData(&LCD_PinConfig," HELLO WORLD L2 ");

	for(;;);
}

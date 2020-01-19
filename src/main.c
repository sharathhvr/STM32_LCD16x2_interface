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

	LCD_PinConfig_t LCD_PinConfig;
	LCD_PinConfig->dataPin[0]=GPIO_Pin_2;


	for(;;);
}

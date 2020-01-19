#include "LCD.h"

void LCD_WriteData(LCD_PinConfig_t* LCD_Pinconfig,GPIO_TypeDef* GPIOx,char* dataString)
{
	GPIO_WriteBit(GPIOx,LCD_Pinconfig->dataPin[0],ENABLE);
}

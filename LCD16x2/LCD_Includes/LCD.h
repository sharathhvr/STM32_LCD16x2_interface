#ifndef __LCD_H
#define __LCD_H

#include "stm32f4xx.h"

typedef struct
{
	GPIO_TypeDef* GPIO_Port; // Port number
	uint16_t dataPin[8]; //data pin numbers config
	uint16_t enablePin;  //enable pin number
	uint16_t regSelectPin; //register select pin number
	uint16_t readWritePin; // Read write Pin

}LCD_PinConfig_t;



/*LCD functions*/
void LCD_WriteData(LCD_PinConfig_t* LCD_Pinconfig,char* dataString);
void LCD_PinSetup(LCD_PinConfig_t* LCD_PinConfig);
void LCD_ScreenSetup(LCD_PinConfig_t* LCD_Pinconfig);
void LCD_WriteCharacter(LCD_PinConfig_t* LCD_Pinconfig,char dataCharacter);


#endif

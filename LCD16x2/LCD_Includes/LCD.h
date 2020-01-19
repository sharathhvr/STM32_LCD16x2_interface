#ifndef __LCD_H
#define __LCD_H

#include "stm32f4xx.h"

typedef struct
{
	uint8_t dataPin[7]; //data pin numbers config
	uint8_t enablePin;  //enable pin number
	uint8_t regSelectPin; //register select pin number

}LCD_PinConfig_t;



#endif

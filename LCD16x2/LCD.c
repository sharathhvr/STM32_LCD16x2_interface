#include <string.h>
#include "LCD.h"


void LCD_ScreenSetup(LCD_PinConfig_t* LCD_Pinconfig)
{
	/*Send Command 38H to select LCD of two rows */
	GPIO_Write(LCD_Pinconfig->GPIO_Port,(uint16_t)(0x38));
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->readWritePin,Bit_RESET); //Select write
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->regSelectPin,Bit_RESET);  // set Command Register
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->enablePin,Bit_SET);   //Set and reset  enable pin to send data
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->enablePin,Bit_RESET);

	/*Send Command 0EH to Display,Cursor ON */
	GPIO_Write(LCD_Pinconfig->GPIO_Port,(uint16_t)(0x0E));
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->readWritePin,Bit_RESET); //Select write
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->regSelectPin,Bit_RESET);  // set Command Register
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->enablePin,Bit_SET);   //Set and reset  enable pin to send data
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->enablePin,Bit_RESET);

	/*Send Command 01H to clear display */
		GPIO_Write(LCD_Pinconfig->GPIO_Port,(uint16_t)(0x01));
		GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->readWritePin,Bit_RESET); //Select write
		GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->regSelectPin,Bit_RESET);  // set Command Register
		GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->enablePin,Bit_SET);   //Set and reset  enable pin to send data
		GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->enablePin,Bit_RESET);


}



void LCD_WriteData(LCD_PinConfig_t* LCD_Pinconfig,char* dataString)
{
	uint8_t stringLen=strlen(dataString);
	for(int i=0; i< stringLen; i++)
	{
		LCD_WriteCharacter(LCD_Pinconfig,(char)(*dataString));
		dataString++;
	}


}


void LCD_WriteCharacter(LCD_PinConfig_t* LCD_Pinconfig,char dataCharacter)
{
		uint8_t dataOut;
	dataOut= (uint16_t)dataCharacter;

	/*Send data to LCD*/
	GPIO_Write(LCD_Pinconfig->GPIO_Port,(uint16_t)dataOut);
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->readWritePin,Bit_RESET); //Select write
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->regSelectPin,Bit_SET);  // set Data Register
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->enablePin,Bit_SET);   //Set and reset  enable pin to send data
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->enablePin,Bit_RESET);
}



/*LCD PinSetup */

void LCD_PinSetup(LCD_PinConfig_t* LCD_PinConfig)
{


/* Setup Data Pins */
		GPIO_InitTypeDef LCD_GPIO;
		memset(&LCD_GPIO,0,sizeof(LCD_GPIO));


		for(int i = 0; i< 8; i++)
		{
			LCD_GPIO.GPIO_Mode=GPIO_Mode_OUT;
			LCD_GPIO.GPIO_OType=GPIO_OType_PP;
			LCD_GPIO.GPIO_Pin=LCD_PinConfig->dataPin[i];
			LCD_GPIO.GPIO_PuPd=GPIO_PuPd_DOWN;
			LCD_GPIO.GPIO_Speed=GPIO_Low_Speed;

			GPIO_Init(LCD_PinConfig->GPIO_Port,&LCD_GPIO);
		}

/* Setup control Pins */

		GPIO_InitTypeDef LCD_GPIO2;

		memset(&LCD_GPIO2,0,sizeof(LCD_GPIO2));
		LCD_GPIO2.GPIO_Mode=GPIO_Mode_OUT;
		LCD_GPIO2.GPIO_OType=GPIO_OType_PP;
		LCD_GPIO2.GPIO_Pin=LCD_PinConfig->enablePin|LCD_PinConfig->readWritePin|LCD_PinConfig->regSelectPin;
		LCD_GPIO2.GPIO_PuPd=GPIO_PuPd_DOWN;
		LCD_GPIO2.GPIO_Speed=GPIO_Low_Speed;

		GPIO_Init(LCD_PinConfig->GPIO_Port,&LCD_GPIO2);

}






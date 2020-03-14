#include <string.h>
#include "LCD.h"

static void delay()
{
	for(int i=0;i<5000;i++);
}

void LCD_clrscreen(LCD_PinConfig_t* LCD_Pinconfig)
{
	LCD_command(LCD_Pinconfig,0x01);
}

void LCD_Line2(LCD_PinConfig_t* LCD_Pinconfig)
{
	LCD_command(LCD_Pinconfig,0xC0);
}

void LCD_ShiftFullDisplayRight(LCD_PinConfig_t* LCD_Pinconfig)
{
	LCD_command(LCD_Pinconfig,0x1C);
}

void LCD_ShiftFullDisplayLeft(LCD_PinConfig_t* LCD_Pinconfig)
{
	LCD_command(LCD_Pinconfig,0x18);
}



void LCD_command(LCD_PinConfig_t* LCD_Pinconfig,uint16_t hex_command)
{
	/*Send Command 01H to clear display */
	GPIO_Write(LCD_Pinconfig->GPIO_Port,((uint16_t)(0x00) << 4));
	GPIO_Write(LCD_Pinconfig->GPIO_Port,((uint16_t)(hex_command) << 4));
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->readWritePin,Bit_RESET); //Select write
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->regSelectPin,Bit_RESET);  // set Command Register
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->enablePin,Bit_SET);   //Set and reset  enable pin to send data
	delay();
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->enablePin,Bit_RESET);

}

void LCD_ScreenSetup(LCD_PinConfig_t* LCD_Pinconfig)
{
	/*Send Command 01H to clear display */
	LCD_command(LCD_Pinconfig,0x01);

	/*Send Command 0FH to Display,Cursor ON */
	LCD_command(LCD_Pinconfig,0x0F);

	/*Send Command 38H to select LCD of two rows */
	LCD_command(LCD_Pinconfig,0x38);



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
	GPIO_Write(LCD_Pinconfig->GPIO_Port,((uint16_t)(0x00) << 4));
	GPIO_Write(LCD_Pinconfig->GPIO_Port,((uint16_t)dataOut << 4));
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->readWritePin,Bit_RESET); //Select write
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->regSelectPin,Bit_SET);  // set Data Register
	GPIO_WriteBit(LCD_Pinconfig->GPIO_Port,LCD_Pinconfig->enablePin,Bit_SET);   //Set and reset  enable pin to send data
	delay();
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

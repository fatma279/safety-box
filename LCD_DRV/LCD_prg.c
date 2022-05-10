/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/* Description ! 16x2 Character LCD for chip LMB161A                                   */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/

/********************************** Header Files INCLUSIONS ****************************/

#include "..\LIB\STD_TYPES.h"
#include "..\LIB\BIT_MATH.h"
#include "util/delay.h"

#include "..\DIO_DRV\DIO_int.h"
#include "LCD_Cfg.h"
#include "LCD_Int.h"
/***************************************************************************************/

/***************************************************************************************/
/********************************** Fucntion Definition ********************************/
/***************************************************************************************/


/***************************************************************************************/
/********************************** Constant Variables *********************************/
/***************************************************************************************/



/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit(void)
{
	/*Configure LCD Data pins as output*/
	DIO_SetPortDir(DATA_PORT,0xFF);
	/*Configure the PIN E as output*/
	DIO_SetPinDir(EN_PORT, EN_PIN, OUTPUT);
	/*Configure the PIN RW as output*/
	DIO_SetPinDir(RW_PORT, RW_PIN, OUTPUT);
	/*Configure the PIN RS as output*/
	DIO_SetPinDir(RS_PORT, RS_PIN, OUTPUT);

	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(30);

	/* Return Home  */
	LCD_vidSendCommand(lcd_Home);
	/* Delay 15ms to ensure the Home Command is done */
	_delay_ms(15);

	/* Function Set  */
	LCD_vidSendCommand(lcd_FunctionSet8bit);
	/* Delay 1ms to ensure the Command is done */
	_delay_ms(1);

	/* Display ON OFF Control */
	LCD_vidSendCommand(lcd_DisplayOn);
	/* Delay 1ms to ensure the Command is done */
	_delay_ms(1);

	/* Clear Display */
	LCD_vidSendCommand(lcd_Clear);
	/* Delay 15ms to ensure the Command is done */
	_delay_ms(15);

	/* Entry Mode Set  */
	LCD_vidSendCommand(lcd_EntryMode);
	/* Delay 2ms to ensure the Entry Command is done */
	_delay_ms(2);

}


/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(u8 u8CmdCpy)
{
	/* Set RS to LOW */
	DIO_SetPinVal(RS_PORT, RS_PIN, LOW);

	/* Set R/W to LOW */
	DIO_SetPinVal(RW_PORT, RW_PIN, LOW);

	/* Set E to HIGH  */
	DIO_SetPinVal(EN_PORT, EN_PIN, HIGH);

	/* Load Command on Data bus */
	DIO_SetPortVal(DATA_PORT, u8CmdCpy);

	/* Set E to LOW */
	DIO_SetPinVal(EN_PORT, EN_PIN, LOW);

	/* Wait 5ms for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	DIO_SetPinVal(EN_PORT, EN_PIN, HIGH);

	/* Delay for 10ms to let the LCD execute command */
	_delay_ms(10);

}

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(u8 u8DataCpy)
{
	/* Set RS to HIGH */
	DIO_SetPinVal(RS_PORT, RS_PIN, HIGH);

	/* Set R/W to LOW */
	DIO_SetPinVal(RW_PORT, RW_PIN, LOW);

	/* Set E to HIGH */
	DIO_SetPinVal(EN_PORT, EN_PIN, HIGH);

	/* Load Command on Data bus */
	DIO_SetPortVal(DATA_PORT, u8DataCpy);

	/* Set E to LOW */
	DIO_SetPinVal(EN_PORT, EN_PIN, LOW);

	/* Wait 5ms for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	DIO_SetPinVal(EN_PORT, EN_PIN, HIGH);

	/* Delay 10 to let the LCD Display the character */
	_delay_ms(10);

}

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index)
{
	/* Local loop index */
	u8 iteration=0;
	/*For loop to write all the array*/
	for (iteration=0; iteration<u8Index ; iteration++)
	{

		/* Write Character on LCD */
		LCD_vidWriteCharctr(pu8StringCpy[iteration]);

		/* Delay to let the LCD show the character */
		_delay_ms(2);
	}

}

/***************************************************************************************/
/* Description! Interface to start the writing process at certain digit in the LCD     */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void Gotoxy (u8 Y,u8 X)
{
	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 1:
		    	/*Set DD RAM Address command for first row*/
		    	LCD_vidSendCommand(X+127);
		    break;
		    case 2:
		    	/*Set DD RAM Address command for second row*/
		    	LCD_vidSendCommand(X+191);
		    break;
		    default:
		    break;
	    }
	}
}

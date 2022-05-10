/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/* Description ! Keypad driver for 4x4 keypad                                          */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/


/********************************** Header Files INCLUSIONS ****************************/
#include "..\LIB\STD_TYPES.h"
#include "..\LIB\BIT_MATH.h"


#include "util/delay.h"

#include "..\DIO_DRV\DIO_int.h"
#include "KPD_Int.h"
#include "KPD_CFG.h"
/***************************************************************************************/


/***************************************************************************************/

/***************************************************************************************/

void KPD_vidInit(void)
{
	/*set the direction of row 0 to be input*/
	/*Add your code here*/
	 DIO_SetPinDir(ROWS_PORT, R0, INPUT);
	/*set the direction of row 1 to be input*/
	/*Add your code here*/
	DIO_SetPinDir(ROWS_PORT, R1, INPUT);
	/*set the direction of row 2 to be input*/
	/*Add your code here*/
	DIO_SetPinDir(ROWS_PORT, R2, INPUT);
	/*set the direction of row 3 to be input*/
	/*Add your code here*/
	DIO_SetPinDir(ROWS_PORT, R3, INPUT);

	/*pull-up resistors on for the input pins*/
	/*pull-up resistors on for row 0*/
	/*Add your code here*/
	DIO_SetPinVal(ROWS_PORT, R0 ,HIGH);
	/*pull-up resistors on for row 0*/
	/*Add your code here*/
	DIO_SetPinVal(ROWS_PORT, R1 ,HIGH);
	/*pull-up resistors on for row 0*/
	/*Add your code here*/
	DIO_SetPinVal(ROWS_PORT, R2 ,HIGH);
	/*pull-up resistors on for row 0*/
	/*Add your code here*/
	DIO_SetPinVal(ROWS_PORT, R3 ,HIGH);

	/*set the direction of col 0 to be output*/
	/*Add your code here*/
	DIO_SetPinDir(COLS_PORT, C0, OUTPUT);
	/*set the direction of col 1 to be output*/
	/*Add your code here*/
     DIO_SetPinDir(COLS_PORT, C1, OUTPUT);
	/*set the direction of col 2 to be output*/
	/*Add your code here*/
	DIO_SetPinDir(COLS_PORT, C2, OUTPUT);
	/*set the direction of col 3 to be output*/
	/*Add your code here*/
	DIO_SetPinDir(COLS_PORT, C3, OUTPUT);
}
/***************************************************************************************/
/* Description! Interface to get the ID of the pressed key, return 0 incase no key     */
/*              is pressed, this function doesn't handle the sitaution if 2 keys are   */
/*              pressed at the same time                               	     		   */
/* Input      ! Button Number range: BUTTON_1 to BUTTON_16                             */
/* Output     ! Button status: range: PRESSED, NOT_PRESSED                             */
/***************************************************************************************/
u8 KPD_u8GetPressedKey(u8 Number)
{
	/*stores at which column the button user entered is located*/
	u8 column;
	/*stores at which row the button user entered is located*/
	u8 row;
	/*array to map the real column value*/
	u8 Real_Column[4]={C0,C1,C2,C3};
	/*array to map the real row value*/
	u8 Real_Row[4]={R0,R1,R2,R3};

	/*variable to store the value of the button reading*/
	u8 button_check;
	/*Variable to return the button reading in it initialized by NPRESSED*/
	u8 button_reading= NOT_PRESSED;

	/*Get the column number by getting the Button number division by 4*/
	/*Add your code here*/
	column=Number/4;


	/*Get the row number by getting the Button number reminder by 4*/
	/*Add your code here*/
	row=Number%4;

	/*Clear all columns*/
	/*Set column 0 to HIGH*/
	/*Add your code here*/
	DIO_SetPinVal(COLS_PORT, C0, HIGH);
	/*Set column 1 to HIGH*/
	/*Add your code here*/
	DIO_SetPinVal(COLS_PORT, C1, HIGH);
	/*Set column 2 to HIGH*/
	/*Add your code here*/
	DIO_SetPinVal(COLS_PORT, C2, HIGH);
	/*Set column 3 to HIGH*/
	/*Add your code here*/
	DIO_SetPinVal(COLS_PORT, C3, HIGH);

	/*Set the required column contains that particular number to LOW*/
	/*Add your code here*/
	DIO_SetPinVal(COLS_PORT, Real_Column[column], LOW);

	/*Get the value of corresponding row that contains that number*/
	/*Add your code here*/
	button_check=DIO_GetPinVal(ROWS_PORT,Real_Row[row]);

	/*checks if the button is reading LOW ( PRESSED )*/
	if(button_check==LOW)
	{
		/*wait 10ms to make sure that wasn't a noise*/
		_delay_ms(10);
		/*check again to make sure it is really pressed*/
		/*Add your code here*/
		button_check=DIO_GetPinVal(ROWS_PORT,Real_Row[row]);
		/*Re check if the button is LOW*/
		if(button_check==LOW)
		{
			/*Set the Button reading to Pressed*/
			/*Add your code here*/
			button_reading=PRESSED;
		}
	}
	/*Return the button reading value*/
	return button_reading;
}

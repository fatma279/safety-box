#include "util/delay.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../DIO_DRV/DIO_Int.h"
#include "../KPD_Drv/KPD_Int.h"
#include "../LCD_DRV/LCD_Int.h"
#include "../SevenSegment/7SEG_Int.h"
#include "../TIMER_DRV/Timer_Int.h"


/* KPD Buttons  */
u8 Buttons[16]={'1','2','3','4','5','6','7','8','9','0','*','#'};

/* this massage appears when the correct password was written  */
u8 mass1[]="opening";

/* this massage appears when the wrong password was written  */
u8 mass2[]="try again";

void main(void)
{

	DIO_SetPortDir(PORTA,0xFF);               /* configure PORTA as output  */
	DIO_SetPortDir(PORTB,0xFF);               /* configure PORTB as output  */
	DIO_SetPortDir(PORTC,0xFF);               /* configure PORTC as output  */
	DIO_SetPortDir(PORTD,0xFF);               /* configure PORTD as output  */

	/* LCD initialization  */
	LCD_vidInit();

	/* LCD initialization  */
	KPD_vidInit();

	/* stored Password  */
	u8 password[4]={'5','7','8','3'};

	u8 count=0, flag=0, No_of_try=0;

	while(1)
	{

       /* check which button was pressed (we have 16 buttons) */
		for(u8 i=0;i<16;i++)
		{

			if(KPD_u8GetPressedKey(i)==PRESSED)
			{
				/*delay for preventing the Bouncing */
				_delay_ms(250);

				/*display the number of button at LCD */
				LCD_vidWriteCharctr(Buttons[i]);

				/*check the count digit (from 0 to 4 count) at the password equal to the pressed button or not */
				if(password[count]==Buttons[i])
				{
					/*this flag to be sure that password is equal to store one*/
					flag++;
				}

				count++;
			}

			if(count==4)
			{

				break;      /*break from the loop because we enter the 4 digit for the password */
			}
		}


		if(count==4)       /* the for digit was enter*/
		{
			if(flag==4)    /*the for digit equal to password digit*/
			{
				LCD_vidSendCommand(lcd_Clear);            /* clear The LCD */
				LCD_vidWriteString (mass1, 7);           /* Display massage 1*/
				break;
			}

			else
			{
				_delay_ms(500);
				LCD_vidSendCommand(lcd_Clear);

				if(No_of_try<2)        /*number of try to write password*/
				{
					LCD_vidWriteString (mass2, 9);      /* display massage 2 */
				}

				/*count=0 and flag=0 to start comparison again  */
				count=0;
				flag=0;

				No_of_try++;

				/* Display number of display on seven segment */
				SevenSeg_voidSevenDisplayNumber(PORTB,No_of_try);

				_delay_ms(500);

				LCD_vidSendCommand(lcd_Clear);
			}

		}

		if(No_of_try==3)    /* we enter the wrong password 3 times */
		{
			LCD_vidSendCommand(lcd_Clear);     /*clear LCD */

			DIO_SetPinVal(PORTA,PIN_3,HIGH);   /* the buzzer is beeping */

			_delay_ms(1000);

			break;        /* the system lock */
		}

	}
}

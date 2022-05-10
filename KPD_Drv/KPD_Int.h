/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/
/* Description ! Keypad driver for 4x4 keypad                                          */
/* Release Date! 28/6/2016                                                             */
/* Version     ! V01                                                                   */
/***************************************************************************************/
#ifndef KPD_H_
#define KPD_H_

/*KeyPad Buttons status*/
#define PRESSED                  (u8)0
#define NOT_PRESSED              (u8)1




/***************************************************************************************/
/* Description! Interface to initialize the KPD driver                                 */
/***************************************************************************************/
void KPD_vidInit(void);
/***************************************************************************************/
/* Description! Interface to get the ID of the pressed key, return 0 incase no key     */
/*              is pressed, this function doesn't handle the sitaution if 2 keys are   */
/*              pressed at the same time                               	     		   */
/* Input      ! Key number                                                             */
/* Output     ! Pressed..Released                                                      */
/***************************************************************************************/
u8 KPD_u8GetPressedKey(u8 Number);

#endif /* KPD_H_ */

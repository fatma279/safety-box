/*
 * LCD_Cfg.h
 *
 *  Created on: Aug 16, 2018
 *      Author: hp
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/***************************************************************************************/
/******************************LCD PINS Configuration***********************************/
/***************************************************************************************/
/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7        |
 |        PD6|---------------->|D6        |
 |        PD5|---------------->|D5        |
 |        PD4|---------------->|D4        |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PA2|---------------->|E         |
 |        PA1|---------------->|RW        |
 |        PA0|---------------->|RS        |
 -----------                   ----------
 */
/*Choose LCD Data port*/
#define DATA_PORT                    PORTD

/*Choose the RS pin PORT*/
#define RS_PORT                      PORTA
/*Choose the RS pin PIN*/
#define RS_PIN                       PIN_0
/*Choose the RW pin PORT*/
#define RW_PORT                      PORTA
/*Choose the RW pin PIN*/
#define RW_PIN                       PIN_1
/*Choose the Enable pin PORT*/
#define EN_PORT                      PORTA
/*Choose the Enable pin PIN*/
#define EN_PIN                       PIN_2




#endif /* LCD_CFG_H_ */

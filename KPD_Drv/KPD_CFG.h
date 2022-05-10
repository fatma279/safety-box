/*
 * KPD_CFG.h
 *
 *  Created on: Sep 21, 2018
 *      Author: Mohamed
 */

#ifndef KPD_DRV_KPD_CFG_H_
#define KPD_DRV_KPD_CFG_H_
/************* KeyPad Key Index ***************/
/*         Col_0    Col_1   Col_2   Col_3     */
/*	                                          */
/* Row_0      1        5      9      13       */
/*	                                          */
/* Row_1  	  2        6      10     14       */
/*	                                          */
/* Row_2	  3        7      11     15       */
/*	                                          */
/* Row_3	  4        8      12     16       */
/**********************************************/

/*Rows port*/
#define ROWS_PORT				PORTC /*Add your code here*/
/*Rows PINS*/
#define R0			 			 PIN_3
#define R1			 			 PIN_2
#define R2 		 		   		 PIN_1
#define R3						 PIN_0

/*Columns Port*/
#define COLS_PORT				 PORTC /*Add your code here*/
/*Column PINS*/
#define C0						 PIN_4
#define C1						 PIN_5
#define C2						 PIN_6
#define C3						 PIN_7



#endif /* KPD_DRV_KPD_CFG_H_ */

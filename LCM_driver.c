/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/**********************************************************************************************************************
 * @file         LCM_driver.c
 * @version      1.00
 * @description  An implementation of a device driver for an LCM(ZETTLER DISPLAYS).
 *               Created on: 16 June 2020
 *               Author: rigel
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 22.08.2020 1.00     First Release
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "LCM_driver.h"
#include "r_cg_serial.h"
#include "LCM_driver_config.h"
#include"lcd_con.h"
static void r_LCM_wait_sendend(void);
/**********************************************************************************************************************

/**********************************************************************************************************************
 * Function Name: r_LCM_init
 ******************************************************************************************************************//**
 * @brief Initialize an LCM.
 * @param none
 * @return none
 */
void r_LCM_init(void)
{
         P7 = 0x00;		//E=0,RS=0
//	
	P7 = 0x03;
	P7 = 0x23;		//E=1,RS=0
	delay_micro(100);
	P7 = 0x03;		//E=0,RS=0
	delay_msec(5);
//
	P7 = 0x23;		//E=1,RS=0
	delay_micro(100);
	P7 = 0x03;		//E=0,RS=0
	delay_msec(5);
//
	P7 = 0x23;		//E=1,RS=0
	delay_micro(100);
	P7 = 0x03;		//E=0,RS=0
	delay_msec(5);
//
	P7 = 0x02;		//4bitÃÞ°À’·Ý’è
	P7 = 0x22;		//E=1,RS=0
	delay_micro(100);
	P7 = 0x02;		//E=0,RS=0
	delay_msec(5);
//** ‚±‚±‚©‚ç4ËÞ¯ÄÃÞ°À’·
	lcd_cout(0x02);		                          //for 4-bit lcd intialization
	delay_msec(5);
	lcd_cout(0x28);		
	delay_msec(5);
	lcd_cout(0x0C);                                    
	delay_msec(5);    
	lcd_cout(0x06);                                       //auto-increment
	delay_msec(5); 
	lcd_cout(0x01);
	delay_msec(5); 	  
}
/**********************************************************************************************************************
 End of function r_LCM_init
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_LCM_clear
 ******************************************************************************************************************//**
 * @brief Clear the LCM display.
 * @param none
 * @return none
 */
void r_LCM_clear(void)
{
    r_LCM_send_command(_0x00_LCM_COMMAND_CLEAR_DISPLAY);
}
/**********************************************************************************************************************
 End of function r_LCM_clear
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_LCM_send_string
 ******************************************************************************************************************//**
 * @brief Send a string to the LCM.
 *        If the string length is more than LCM_MAX_CHAR_PER_LINE, the rest is not sent.
 * @param[in] str  A pointer to a string to send.
 * @param[in] pos  A display position of the string.
 * @return none
 */
void r_LCM_send_string(uint8_t * const str, lcm_position_t pos)
{
    int i;
    uint8_t *p;
    
    r_LCM_send_command(_0x80_LCM_COMMAND_SET_DDRAM_ADDRESS | pos);

    for (i = 0, p = str; *p != '\0'; i++, p++)
    {
        if (i >= LCM_CONFIG_MAX_CHAR_PER_LINE)
        {
            /* The string length reached the maximum. */
            break;
        }
        r_LCM_send_data(*p);
    }
}
/**********************************************************************************************************************
 End of function r_LCM_send_string
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_LCM_send_command
 ******************************************************************************************************************//**
 * @brief Send a command to the LCM.
 * @param[in] command  A one byte command to send.
 * @return none
 */
void r_LCM_send_command(unsigned char ccod)
{
        unsigned char ccod_msb;
	unsigned char ccod_lsb;

	ccod_msb = ccod / 0x10;
	ccod_lsb = ccod & 0x0F;
//
	P7 = ccod_msb;		//E=0,RS=0 + MSB
	delay_micro(2);
	P7 = ccod_msb | 0x20;	//E=1,RS=0
	delay_micro(2);
	P7 = ccod_msb;		//E=0,RS=0
//
	delay_micro(2);
//
	P7 = ccod_lsb;		//E=0,RS=0 + LSB
	delay_micro(2);
	P7 = ccod_lsb | 0x20;	//E=1,RS=0
	delay_micro(2);
	P7 = ccod_lsb;		//E=0,RS=0
	delay_micro(50);	   

}
/**********************************************************************************************************************
 End of function r_LCM_send_command
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_LCM_send_data
 ******************************************************************************************************************//**
 * @brief Send data to the LCM.
 * @param[in] data  A one byte data to send.
 * @return none
 */
void r_LCM_send_data(unsigned char dcod)
{
       unsigned char dcod_msb;
       unsigned char dcod_lsb;

	dcod_msb = dcod / 0x10;
	dcod_lsb = dcod & 0x0F;
//
	P7 = dcod_msb | 0x10;	//E=0,RS=1 + MSB
	delay_micro(2);
	P7 = dcod_msb | 0x30;	//E=1,RS=1
	delay_micro(2);
	P7 = dcod_msb | 0x10;	//E=0,RS=1
//
	delay_micro(2);
//
	P7 = dcod_lsb | 0x10;	//E=0,RS=1 + LSB
	delay_msec(2);
	P7 = dcod_lsb | 0x30;	//E=1,RS=1
	delay_micro(2);
	P7 = dcod_lsb | 0x10;	//E=0,RS=1
	delay_micro(50);     
	//return 0;   
}

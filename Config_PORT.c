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

/***********************************************************************************************************************
* File Name    : Config_PORT.c
* Version      : 1.0.0
* Device(s)    : R7F100GLGxFA
* Description  : This file implements device driver for Config_PORT.
* Creation Date: 2021-06-01
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_PORT.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_PORT_Create
* Description  : This function initializes the port I/O.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_PORT_Create(void)
{
     P1 = _02_Pn1_OUTPUT_1 | _00_Pn4_OUTPUT_0 | _00_Pn3_OUTPUT_0 | _00_Pn2_OUTPUT_0 | _00_Pn1_OUTPUT_0 | _00_Pn0_OUTPUT_0;
     P3 = _01_Pn0_OUTPUT_1;
     P7 = _00_Pn0_OUTPUT_0 | _00_Pn1_OUTPUT_0 | _00_Pn2_OUTPUT_0 | _00_Pn3_OUTPUT_0 | _00_Pn4_OUTPUT_0 |
         _00_Pn5_OUTPUT_0 | _00_Pn6_OUTPUT_0 | _00_Pn7_OUTPUT_0; 
     P10 = _01_Pn0_OUTPUT_1;   
     P12 = _00_Pn0_OUTPUT_0;
     P14 = _80_Pn7_OUTPUT_1;
     
     POM1 = _00_POMn5_NCH_OFF | _00_POMn0_NCH_OFF;
     PMC0 = _00_PMCn2_DI_ON | _00_PMCn3_DI_ON | _00_PMCn0_DI_ON;
     PMC1 = _00_PMCn2_DI_ON | _00_PMCn3_DI_ON | _00_PMCn6_DI_ON | _00_PMCn7_DI_ON;
     PMC10 = _00_PMCn0_DI_ON | _FE_PMC10_DEFAULT;
     PMC12 = _00_PMCn0_DI_ON | _FE_PMC12_DEFAULT;
     PMC14 = _00_PMCn7_DI_ON | _7F_PMC14_DEFAULT;
     ADPC = _01_ADPC_DI_ON;
    
     PM1 = _00_PMn1_MODE_OUTPUT     | _20_PMn5_NOT_USE | _10_PMn4_NOT_USE | _00_PMn3_MODE_OUTPUT | _00_PMn2_MODE_OUTPUT | 
      _02_PMn1_NOT_USE | _01_PMn0_NOT_USE;      
     PM3 = _00_PMn0_MODE_OUTPUT | _00_PMn1_MODE_OUTPUT | _FE_PM12_DEFAULT;
     PM7 = _00_PMn0_MODE_OUTPUT | _00_PMn1_MODE_OUTPUT | _00_PMn2_MODE_OUTPUT | _00_PMn3_MODE_OUTPUT |
          _00_PMn4_MODE_OUTPUT | _00_PMn5_MODE_OUTPUT | _00_PMn6_MODE_OUTPUT | _00_PMn7_MODE_OUTPUT;  
     PM10 = _00_PMn0_MODE_OUTPUT;
     PM12 = _00_PMn0_MODE_OUTPUT | _FE_PM12_DEFAULT;  
     PM14 = _01_PMn0_NOT_USE | _02_PMn1_NOT_USE | _04_PMn2_NOT_USE | _08_PMn3_NOT_USE | _10_PMn4_NOT_USE |
           _00_PMn5_MODE_OUTPUT | _00_PMn6_MODE_OUTPUT | _00_PMn7_MODE_OUTPUT;
   
    R_Config_PORT_Create_UserInit();
}


/***********************************************************************************************************************
* Function Name: R_Config_PORT_ReadPmnValues
* Description  : This function specifies the value in the output latch for a port is read when the pin is in output mode.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_PORT_ReadPmnValues(void)
{
 //PMS = _00_PMN_VALUES;  
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

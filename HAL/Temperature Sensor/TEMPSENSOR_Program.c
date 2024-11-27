/******************************************************************************
 *
 * Module: TEMPSENSOR
 *
 * File Name: TEMPSENSOR_Program.c
 *
 * Description: Program source file for HAL TEMPSENSOR Module
 *
 * Author: Ahmed Abdelhamid
 ******************************************************************************/

/*Include of the module header file*/
#include "TEMPSENSOR_Interface.h"


/************************************************************************************
 * Function Name: HTEMP_VOIDInit
 * Parameters (in): u8 Copy_U8Port - to set the Port to read from 
                    u8 Copy_U8Pin - to set the Pin to read from 		
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize the TempSensor pin  
 ************************************************************************************/

void HTEMP_VOIDInit(u8 Copy_U8Port, u8 Copy_U8Pin)
{
	MDIO_VOIDSetPinDirection( Copy_U8Port,  Copy_U8Pin,  INPUT);
	MADC_VOIDInit();
}

/************************************************************************************
 * Function Name: HTEMP_U8GetTemp
 * Parameters (in): None				
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: u8 LOC_U8Temp_Celsius : to return the Temp in celsius
 * Description: Function to Get the TempSensor reading
 ************************************************************************************/


u8 HTEMP_U8GetTemp(void)
{
	u8 LOC_U8Temp ;
	LOC_U8Temp = MADC_U8ReadValue();
	u8 LOC_U8Temp_Celsius = ((u32)LOC_U8Temp *5000)/256;
	LOC_U8Temp_Celsius = LOC_U8Temp_Celsius/10;
	return LOC_U8Temp_Celsius ;
}



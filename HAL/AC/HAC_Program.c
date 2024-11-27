/******************************************************************************
 *
 * Module: HAC
 *
 * File Name: HAC_Program.c
 *
 * Description: Program source file for HAL AC Module
 *
 * Author: Omar Khedr
 ******************************************************************************/

/*Include of the module header file*/
#include "HAC_Interface.h"

/*Global Variables to store the initialized Port & Pin*/
static u8 GLOB_U8Port;
static u8 GLOB_U8Pin;

/************************************************************************************
 * Function Name: HAC_VOIDInit
 * Parameters (in): u8 Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					u8 Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to initialize a specific pin to be output for the AC
 ************************************************************************************/

void HAC_VOIDInit(u8 Copy_U8Port, u8 Copy_U8Pin)
{
	GLOB_U8Port=Copy_U8Port;
	GLOB_U8Pin=Copy_U8Pin;
	MDIO_VOIDSetPinDirection(Copy_U8Port,Copy_U8Pin,HIGH);
	MDIO_VOIDSetPinValue(Copy_U8Port,Copy_U8Pin,LOW);
}

/************************************************************************************
 * Function Name: HAC_VOIDOnOff
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to toggle the value of the pin connected to the relay
 * 				which is connected to the AC
 ************************************************************************************/

void HAC_VOIDOnOff(void)
{
	MDIO_VOIDTogglePinValue(GLOB_U8Port,GLOB_U8Pin);
}



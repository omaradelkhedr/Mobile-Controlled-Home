/******************************************************************************
 *
 * Module: HLED
 *
 * File Name: HLED_Program.c
 *
 * Description: Program source file for HAL LED Module
 *
 * Author: Omar Khedr
 ******************************************************************************/

/*Include of the module header file*/
#include "HLED_Interface.h"

/*Global Variables to store the initialized Port & Pin*/
static u8 GLOB_U8Port;
static u8 GLOB_U8Pin;

/************************************************************************************
 * Function Name: HLED_VOIDInit
 * Parameters (in): u8 Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					u8 Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to initialize a specific pin to be output for LED
 ************************************************************************************/

void HLED_VOIDInit(u8 Copy_U8Port, u8 Copy_U8Pin)
{
	GLOB_U8Port=Copy_U8Port;
	GLOB_U8Pin=Copy_U8Pin;
	MDIO_VOIDSetPinDirection(Copy_U8Port,Copy_U8Pin,HIGH);
}

/************************************************************************************
 * Function Name: HLED_VOIDON
 * Parameters (in): u8 Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					u8 Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the LED ON
 ************************************************************************************/

void HLED_VOIDON(void)
{
	MDIO_VOIDSetPinValue(GLOB_U8Port,GLOB_U8Pin,HIGH);
}

/************************************************************************************
 * Function Name: HLED_VOIDOFF
 * Parameters (in): u8 Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					u8 Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the LED OFF
 ************************************************************************************/

void HLED_VOIDOFF(void)
{
	MDIO_VOIDSetPinValue(GLOB_U8Port,GLOB_U8Pin,LOW);
}


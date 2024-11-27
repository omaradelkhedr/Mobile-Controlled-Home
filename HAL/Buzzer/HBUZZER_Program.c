/******************************************************************************
 *
 * Module: HBUZZER
 *
 * File Name: HBUZZER_Program.c
 *
 * Description: Program source file for HAL Buzzer Module
 *
 * Author: Omar Khedr
 ******************************************************************************/

/*Include of the module header file*/
#include "HBUZZER_Interface.h"

/*Global Variables to store the initialized Port & Pin*/
static u8 GLOB_U8Port;
static u8 GLOB_U8Pin;

/************************************************************************************
 * Function Name: HBUZZER_VOIDInit
 * Parameters (in): u8 Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					u8 Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to initialize a specific pin to be output for Buzzer
 ************************************************************************************/

void HBUZZER_VOIDInit(u8 Copy_U8Port, u8 Copy_U8Pin)
{
	GLOB_U8Port=Copy_U8Port;
	GLOB_U8Pin=Copy_U8Pin;
	MDIO_VOIDSetPinDirection(Copy_U8Port,Copy_U8Pin,HIGH);
}

/************************************************************************************
 * Function Name: HBUZZER_VOIDTriggerAlarm
 * Parameters (in): u8 Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					u8 Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to trigger an alarm
 ************************************************************************************/

void HBUZZER_VOIDTriggerAlarm(void)
{
	MDIO_VOIDSetPinValue(GLOB_U8Port,GLOB_U8Pin,HIGH);
}

/************************************************************************************
 * Function Name: HBUZZER_VOIDStopAlarm
 * Parameters (in): u8 Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					u8 Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to stop the alarm
 ************************************************************************************/

void HBUZZER_VOIDStopAlarm(void)
{
	MDIO_VOIDSetPinValue(GLOB_U8Port,GLOB_U8Pin,LOW);
}


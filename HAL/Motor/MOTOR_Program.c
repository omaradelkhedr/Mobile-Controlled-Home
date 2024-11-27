/******************************************************************************
 *
 * Module: MOTOR
 *
 * File Name: MOTOR_Program.c
 *
 * Description: Program source file for HAL MOTOR Module
 *
 * Author: Ahmed Abdelhamid
 ******************************************************************************/

/*Include of the module header file*/
#include "MOTOR_Interface.h"


/************************************************************************************
 * Function Name: HMTR_VOIDRotateCCW
 * Parameters (in): None				
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to make the motor rotate in counterclockwise direction 
 ************************************************************************************/

void HMTR_VOIDRotateCCW()
{
	MDIO_VOIDSetPortDirection(PORTA , 0b00001111);
	MTMR2_VOIDNormalInit();

	for (u16 LOC_U16Iterator = ZERO ; LOC_U16Iterator<256 ; LOC_U16Iterator++ )
	{
		MDIO_VOIDSetPortValue(PORTA , 0b11111001 );
		MTMR2_VOIDNormalStart (4);
		MDIO_VOIDSetPortValue(PORTA , 0b11111010 );
		MTMR2_VOIDNormalStart (4);
		MDIO_VOIDSetPortValue(PORTA , 0b11110110 );
		MTMR2_VOIDNormalStart (4);
		MDIO_VOIDSetPortValue(PORTA , 0b11110101 );
		MTMR2_VOIDNormalStart(4);
	}
}

/************************************************************************************
 * Function Name: HMTR_VOIDRotateCCW
 * Parameters (in): None				
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to make the motor rotate in clockwise direction
 ************************************************************************************/


void HMTR_VOIDRotateCW()
{
	MDIO_VOIDSetPortDirection(PORTA, 0b00001111);
	MTMR2_VOIDNormalInit ();

	for (u16 LOC_U16Iterator = ZERO ; LOC_U16Iterator<256 ; LOC_U16Iterator++ )
	{
		MDIO_VOIDSetPortValue(PORTA , 0b11111010 );
		MTMR2_VOIDNormalStart (4);
		MDIO_VOIDSetPortValue(PORTA , 0b11111001 );
		MTMR2_VOIDNormalStart (4);
		MDIO_VOIDSetPortValue(PORTA , 0b11110101 );
		MTMR2_VOIDNormalStart (4);
		MDIO_VOIDSetPortValue(PORTA , 0b11110110 );
		MTMR2_VOIDNormalStart (4);

	}
}



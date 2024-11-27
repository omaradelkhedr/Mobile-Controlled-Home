/******************************************************************************
 *
 * Module: MDIO
 *
 * File Name: MDIO_Program.c
 *
 * Description: Program source file for MCAL Digital Input Output (DIO) Module
 *
 * Author: Mayar Wael
 ******************************************************************************/

/*Include of the module header file*/
#include "MDIO_Interface.h"

/************************************************************************************
 * Function Name: MDIO_VOIDSetPinDirection
 * Parameters (in): u8 Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					u8 Copy_U8Pin - to store the value of the desired Pin (0->7)
 * 					u8 Copy_U8Direction - to store the value of the desired Direction (0/1)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the direction of a specific pin inside a specific port
 ************************************************************************************/

void MDIO_VOIDSetPinDirection (u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Direction)
{
	/*Switch on port value */
	switch (Copy_U8Port)
	{
	/*If condition inside each case to get the direction and storing the direction into the DDR register*/
	case PORTA:
		if (LOW == Copy_U8Direction)
		{
			CLR_BIT(DDRA_REG,Copy_U8Pin);
		}
		else if(HIGH == Copy_U8Direction)
		{
			SET_BIT(DDRA_REG,Copy_U8Pin);
		}
		else
		{
			/*Do Nothing*/
		}
		break;
	case PORTB:
		if (LOW == Copy_U8Direction)
		{
			CLR_BIT(DDRB_REG,Copy_U8Pin);
		}
		else if(HIGH == Copy_U8Direction)
		{
			SET_BIT(DDRB_REG,Copy_U8Pin);
		}
		else
		{
			/*Do Nothing*/
		}
		break;
	case PORTC:
		if (LOW == Copy_U8Direction)
		{
			CLR_BIT(DDRC_REG,Copy_U8Pin);
		}
		else if(HIGH == Copy_U8Direction)
		{
			SET_BIT(DDRC_REG,Copy_U8Pin);
		}
		else
		{
			/*Do Nothing*/
		}
		break;
	case PORTD:
		if (LOW == Copy_U8Direction)
		{
			CLR_BIT(DDRD_REG,Copy_U8Pin);
		}
		else if(HIGH == Copy_U8Direction)
		{
			SET_BIT(DDRD_REG,Copy_U8Pin);
		}
		else
		{
			/*Do Nothing*/
		}
		break;
	default: break;
	}
}

/************************************************************************************
 * Function Name: MDIO_VOIDSetPortDirection
 * Parameters (in): u8 Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					u8 Copy_U8Direction - to store the value of the desired Direction (0/1)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the direction of a specific port
 ************************************************************************************/

void MDIO_VOIDSetPortDirection (u8 Copy_U8Port, u8 Copy_U8Direction)
{
	/*Switch on port value */
	switch (Copy_U8Port)
	{
	/*Storing the value of the direction into the DDR register*/
	case PORTA:
		DDRA_REG=Copy_U8Direction;
		break;
	case PORTB:
		DDRB_REG=Copy_U8Direction;
		break;
	case PORTC:
		DDRC_REG=Copy_U8Direction;
		break;
	case PORTD:
		DDRD_REG=Copy_U8Direction;
		break;
	default: break;
	}
}

/************************************************************************************
 * Function Name: MDIO_VOIDSetPinValue
 * Parameters (in): u8 Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					u8 Copy_U8Pin - to store the value of the desired Pin (0->7)
 * 					u8 Copy_U8Value - to store the desired value (0/1)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set the value of a specific pin inside a specific port
 ************************************************************************************/

void MDIO_VOIDSetPinValue (u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Value)
{
	/*Switch on port value */
	switch (Copy_U8Port)
	{
	/*If condition inside each case to get the value then storing the value into the pin*/
	case PORTA:
		if (LOW == Copy_U8Value)
		{
			CLR_BIT(PORTA_REG,Copy_U8Pin);
		}
		else if(HIGH == Copy_U8Value)
		{
			SET_BIT(PORTA_REG,Copy_U8Pin);
		}
		else
		{
			/*Do Nothing*/
		}
		break;
	case PORTB:
		if (LOW == Copy_U8Value)
		{
			CLR_BIT(PORTB_REG,Copy_U8Pin);
		}
		else if(HIGH == Copy_U8Value)
		{
			SET_BIT(PORTB_REG,Copy_U8Pin);
		}
		else
		{
			/*Do Nothing*/
		}
		break;
	case PORTC:
		if (LOW == Copy_U8Value)
		{
			CLR_BIT(PORTC_REG,Copy_U8Pin);
		}
		else if(HIGH == Copy_U8Value)
		{
			SET_BIT(PORTC_REG,Copy_U8Pin);
		}
		else
		{
			/*Do Nothing*/
		}
		break;
	case PORTD:
		if (LOW == Copy_U8Value)
		{
			CLR_BIT(PORTD_REG,Copy_U8Pin);
		}
		else if(HIGH == Copy_U8Value)
		{
			SET_BIT(PORTD_REG,Copy_U8Pin);
		}
		else
		{
			/*Do Nothing*/
		}
		break;
	default: break;
	}
}

/************************************************************************************
 * Function Name: MDIO_VOIDSetPortValue
 * Parameters (in): u8 Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					u8 Copy_U8Value - to store the desired 8-bit value
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to store a value inside a specific port
 ************************************************************************************/

void MDIO_VOIDSetPortValue (u8 Copy_U8Port, u8 Copy_U8Value)
{
	/*Switch on port value */
	switch (Copy_U8Port)
	{
	/*Storing the value of the port into the PORT register*/
	case PORTA:
		PORTA_REG=Copy_U8Value;
		break;
	case PORTB:
		PORTB_REG=Copy_U8Value;
		break;
	case PORTC:
		PORTC_REG=Copy_U8Value;
		break;
	case PORTD:
		PORTD_REG=Copy_U8Value;
		break;
	default: break;
	}
}

/************************************************************************************
 * Function Name: MDIO_VOIDTogglePinValue
 * Parameters (in): u8 Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					u8 Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to complement the value of a specific pin inside a specific port
 ************************************************************************************/

void MDIO_VOIDTogglePinValue (u8 Copy_U8Port, u8 Copy_U8Pin)
{
	/*Switch on port value */
	switch (Copy_U8Port)
	{
	/*Complementing the value of the bit*/
	case PORTA:
		TOGGLE_BIT(PORTA_REG,Copy_U8Pin);
		break;
	case PORTB:
		TOGGLE_BIT(PORTB_REG,Copy_U8Pin);
		break;
	case PORTC:
		TOGGLE_BIT(PORTC_REG,Copy_U8Pin);
		break;
	case PORTD:
		TOGGLE_BIT(PORTD_REG,Copy_U8Pin);
		break;
	default: break;
	}
}

/************************************************************************************
 * Function Name: MDIO_U8GetPinValue
 * Parameters (in): u8 Copy_U8Port - to store the desired Port (A/B/C/D)
 * 					u8 Copy_U8Pin - to store the value of the desired Pin (0->7)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: u8 LOC_U8RetVal - to store the value of the bit (0/1)
 * Description: Function to return the value of a specific pin inside a specific port
 ************************************************************************************/

u8 MDIO_U8GetPinValue (u8 Copy_U8Port, u8 Copy_U8Pin)
{
	/*Variable to store the value of the pin into then returning it*/
	u8 LOC_U8RetVal;
	/*Switch on port value */
	switch (Copy_U8Port)
	{
	/*Storing the value of the bit*/
	case PORTA:
		LOC_U8RetVal=GET_BIT(PINA_REG,Copy_U8Pin);
		break;
	case PORTB:
		LOC_U8RetVal=GET_BIT(PINB_REG,Copy_U8Pin);
		break;
	case PORTC:
		LOC_U8RetVal=GET_BIT(PINC_REG,Copy_U8Pin);
		break;
	case PORTD:
		LOC_U8RetVal=GET_BIT(PIND_REG,Copy_U8Pin);
		break;
	default: break;
	}
	return LOC_U8RetVal;
}

/************************************************************************************
 * Function Name: MDIO_U8GetPortValue
 * Parameters (in): u8 Copy_U8Port - to store the desired Port (A/B/C/D)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: u8 LOC_U8RetVal - to store the value of the port
 * Description: Function to return the value of a specific port
 ************************************************************************************/

u8 MDIO_U8GetPortValue (u8 Copy_U8Port)
{
	/*Variable to store the value of the port into then returning it*/
	u8 LOC_U8RetVal;
	/*Switch on port value */
	switch (Copy_U8Port)
	{
	/*Storing the value of the port*/
	case PORTA:
		LOC_U8RetVal=PINA_REG;
		break;
	case PORTB:
		LOC_U8RetVal=PINB_REG;
		break;
	case PORTC:
		LOC_U8RetVal=PINC_REG;
		break;
	case PORTD:
		LOC_U8RetVal=PIND_REG;
		break;
	default: break;
	}
	return LOC_U8RetVal;
}


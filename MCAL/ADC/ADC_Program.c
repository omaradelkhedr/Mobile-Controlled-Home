/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_Program.c
 *
 * Description: Program source file for MCAL ADC Module
 *
 * Author: Omar Khedr
 ******************************************************************************/

/*Include of the module header file*/
#include "ADC_Interface.h"

/************************************************************************************
 * Function Name: MADC_VOIDInit
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to initialize the ADC module
 ************************************************************************************/

void MADC_VOIDInit (void)
{
	/*Select AVCC reference*/
	CLR_BIT(ADMUX_REG,REFS1);
	SET_BIT(ADMUX_REG,REFS0);
	/*Select left adjustment to read one time from ADCH register*/
	SET_BIT(ADMUX_REG,ADLAR);
	/*Select channel ADC4*/
	CLR_BIT(ADMUX_REG,MUX4);
	CLR_BIT(ADMUX_REG,MUX3);
	SET_BIT(ADMUX_REG,MUX2);
	CLR_BIT(ADMUX_REG,MUX1);
	CLR_BIT(ADMUX_REG,MUX0);
	/*Enable ADC module*/
	SET_BIT(ADCSRA_REG,ADEN);
	/*Selecting Pre-scalar value: 2*/
	CLR_BIT(ADCSRA_REG,ADPS2);
	CLR_BIT(ADCSRA_REG,ADPS1);
	SET_BIT(ADCSRA_REG,ADPS0);
}

/************************************************************************************
 * Function Name: MADC_U8ReadValue
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: u8 LOC_U8RetVal - to return the reading of the ADC
 * Description: Function to get the analog reading from ADC4 pin
 ************************************************************************************/

u8 MADC_U8ReadValue (void)
{
	u8 LOC_U8RetVal=ZERO;
	/*Start Conversion*/
	SET_BIT(ADCSRA_REG,ADSC);
	/*Polling on flag until conversion is complete*/
	while (GET_BIT(ADCSRA_REG,ADIF) == ZERO)
	{
		/*Do Nothing*/
	}
	/*Clearing the flag manually by setting the flag bit*/
	SET_BIT(ADCSRA_REG,ADIF);
	/*Store the read value*/
	LOC_U8RetVal = ADCH_REG;
	return LOC_U8RetVal;
}

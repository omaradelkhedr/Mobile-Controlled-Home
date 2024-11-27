/******************************************************************************
 *
 * Module: TIMER
 *
 * File Name: TIMER_Program.c
 *
 * Description: Program source file for MCAL TIMER Module
 *
 * Author: Ahmed Abdelhamid
 ******************************************************************************/

/*Include of the module header file*/
#include "TIMER_Interface.h"


/************************************************************************************
 * Function Name: MTMR0_VOIDFastPWMInit
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to initialize the PWM mode
 ************************************************************************************/

void MTMR0_VOIDFastPWMInit (void)
{
	/*Select Fast PWM  Mode*/
	SET_BIT(TCCR0_REG,WGM00);
	SET_BIT(TCCR0_REG,WGM01);
	/*Compare match output behavior depends on fast PWM mode*/
	SET_BIT(TCCR0_REG,COM01);
	CLR_BIT(TCCR0_REG,COM00);
	/*Choose clock source: /256 from pre-scalar --> Select frequency=3906.25Hz*/
	SET_BIT(TCCR0_REG,CS02);
	CLR_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS00);
	/*Disable OCIE0*/
	CLR_BIT(TIMSK_REG,OCIE0);
}

/************************************************************************************
 * Function Name: MTMR0_VOIDSetDutyCycle
 * Parameters (in): u8 Copy_U8DutyCycle - to set the wanted value for duty cycle
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Set the value of the duty cycle for the PWM
 ************************************************************************************/

void MTMR0_VOIDSetDutyCycle (u8 Copy_U8DutyCycle)
{
	OCR0_REG= ((u32)Copy_U8DutyCycle*OCR0_MAX)/100 ;
}

/************************************************************************************
 * Function Name: MTMR0_VOIDPWMOff
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to stop the clock and disable OC0 Pin
 ************************************************************************************/

void MTMR0_VOIDPWMOff (void)
{
	/*Disconnect OC0*/
	CLR_BIT(TCCR0_REG,COM01);
	CLR_BIT(TCCR0_REG,COM00);
	/*Disable clock source*/
	CLR_BIT(TCCR0_REG,CS02);
	CLR_BIT(TCCR0_REG,CS01);
	CLR_BIT(TCCR0_REG,CS00);
}


/************************************************************************************
 * Function Name: MTMR2_VOIDNormalInit
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize Timer 2 on normal (overflow) mode
 ************************************************************************************/

void MTMR2_VOIDNormalInit (void)
{
	/*Select Normal (Overflow)  Mode*/
	CLR_BIT(TCCR2_REG,WGM20);
	CLR_BIT(TCCR2_REG,WGM21);
	/*Disconnecting OC2 Register*/
	CLR_BIT(TCCR2_REG,COM21);
	CLR_BIT(TCCR2_REG,COM20);
	/*Disable TOIE0*/
	CLR_BIT(TIMSK_REG,TOIE2);
}

/************************************************************************************
 * Function Name: MTMR2_VOIDNormalStart
 * Parameters (in): u16 Copy_U16RequiredDelay - to set the wanted delay
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Set the wanted delay from the timer and start counting
 ************************************************************************************/

void MTMR2_VOIDNormalStart (u16 Copy_U16RequiredDelay)
{
	/*Choose clock source: /64 from pre-scalar --> Timer Frequency = 125000 HZ */
	SET_BIT(TCCR2_REG,CS22);
	CLR_BIT(TCCR2_REG,CS21);
	CLR_BIT(TCCR2_REG,CS20);
	u16 LOC_U16Count = 1;
	u16 LOC_U16Calculation = (Copy_U16RequiredDelay/2) - ((Copy_U16RequiredDelay/1000)*12);
	while(LOC_U16Count!= LOC_U16Calculation)
	{
		if (GET_BIT(TIFR_REG,TOV2)==1)
		{
			LOC_U16Count++ ;
			SET_BIT(TIFR_REG,TOV2);
		}
	}
}


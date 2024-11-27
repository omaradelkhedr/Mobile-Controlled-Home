/******************************************************************************
 *
 * Module: MDIO
 *
 * File Name: MDIO_Interface.h
 *
 * Description: Interface header file for MCAL Digital Input Output (DIO) Module
 *
 * Author: Mayar Wael
 ******************************************************************************/
#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_

/*******************************************************************************
 *                              Module Inclusions                               *
 *******************************************************************************/

/*Include of Standard types header file */
#include "../../LIB/Std_Types.h"
/*Include of Bit Math header file*/
#include "../../LIB/BIT_MATH.h"
/*Include of module private file*/
#include "MDIO_Private.h"

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void MDIO_VOIDSetPinDirection (u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Direction);
void MDIO_VOIDSetPortDirection (u8 Copy_U8Port, u8 Copy_U8Direction);
void MDIO_VOIDSetPinValue (u8 Copy_U8Port, u8 Copy_U8Pin, u8 Copy_U8Value);
void MDIO_VOIDSetPortValue (u8 Copy_U8Port, u8 Copy_U8Value);
void MDIO_VOIDTogglePinValue (u8 Copy_U8Port, u8 Copy_U8Pin);
u8 MDIO_U8GetPinValue (u8 Copy_U8Port, u8 Copy_U8Pin);
u8 MDIO_U8GetPortValue (u8 Copy_U8Port);


/*******************************************************************************
 *                      Module Used Macros                                    *
 *******************************************************************************/

#define LOW		(0U)
#define HIGH	(1U)
#define PORTA	(0U)
#define PORTB	(1U)
#define PORTC	(2U)
#define PORTD	(3U)
#define ALL_ZERO (0U)
#define ALL_ONE	(0b11111111)
#define PIN0	(0U)
#define PIN1	(1U)
#define PIN2	(2U)
#define PIN3	(3U)
#define PIN4	(4U)
#define PIN5	(5U)
#define PIN6	(6U)
#define PIN7	(7U)
#define INPUT	(0U)
#define OUTPUT	(1U)

#endif

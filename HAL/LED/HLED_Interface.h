/******************************************************************************
 *
 * Module: HLED
 *
 * File Name: HLED_Interface.h
 *
 * Description: Interface header file for HAL LED Module
 *
 * Author: Omar Khedr
 ******************************************************************************/
#ifndef _HLED_INTERFACE_H_
#define _HLED_INTERFACE_H_

/*******************************************************************************
 *                              Module Inclusions                               *
 *******************************************************************************/

/*Include of Standard types header file */
#include "../../LIB/Std_Types.h"
/*Include of Bit Math header file*/
#include "../../LIB/BIT_MATH.h"
/*Include of MCAL DIO header file*/
#include "../../MCAL/DIO/MDIO_Interface.h"

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void HLED_VOIDInit(u8 Copy_U8Port, u8 Copy_U8Pin);
void HLED_VOIDON(void);
void HLED_VOIDOFF(void);


#endif

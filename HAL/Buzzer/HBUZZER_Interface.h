/******************************************************************************
 *
 * Module: HBUZZER
 *
 * File Name: HBUZZER_Interface.h
 *
 * Description: Interface header file for HAL Buzzer Module
 *
 * Author: Omar Khedr
 ******************************************************************************/
#ifndef _HBUZZER_INTERFACE_H_
#define _HBUZZER_INTERFACE_H_

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

void HBUZZER_VOIDInit(u8 Copy_U8Port, u8 Copy_U8Pin);
void HBUZZER_VOIDTriggerAlarm(void);
void HBUZZER_VOIDStopAlarm(void);

#endif

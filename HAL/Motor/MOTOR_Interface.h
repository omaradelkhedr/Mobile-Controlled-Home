/*******************************************************************************
 * File Name: MOTOR_Interface.h
 *
 * Description: Interface header file for HAL Motor Module
 *
 * Author: Ahmed Abdelhamid
 ******************************************************************************/

#ifndef _MOTOR_INTERFACE_H_
#define _MOTOR_INTERFACE_H_


/*******************************************************************************
 *                              Module Inclusions                                *
 *******************************************************************************/

/*Include of Standard types header file */
#include "../../LIB/STD_TYPES.h"
/*Include of Bit Math header file*/
#include "../../LIB/BIT_MATH.h"
/*Include of Timer module Interface file*/
#include "../../MCAL/Timer/TIMER_Interface.h"
/*Include of DIO module Interface file */
#include "../../MCAL/DIO/MDIO_Interface.h"

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void HMTR_VOIDRotateCCW(void) ;
void HMTR_VOIDRotateCW(void) ;

/*******************************************************************************
 *                      Module Used Macros                                    *
 *******************************************************************************/

#define ZERO		(0U)


#endif 

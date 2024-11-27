/*******************************************************************************
 * File Name: TEMPSENSOR_Interface.h
 *
 * Description: Interface header file for HAL TEMPSENSOR Module
 *
 * Author: Ahmed Abdelhamid
 ******************************************************************************/

#ifndef _TEMPSENSOR_INTERFACE_H_
#define _TEMPSENSOR_INTERFACE_H_


/*******************************************************************************
 *                              Module Inclusions                                *
 *******************************************************************************/

/*Include of Standard types header file */
#include "../../LIB/STD_TYPES.h"
/*Include of Bit Math header file*/
#include "../../LIB/BIT_MATH.h"
/*Include of ADC module Interface file*/
#include "../../MCAL/ADC/ADC_Interface.h"
/*Include of DIO module Interface file */
#include "../../MCAL/DIO/MDIO_Interface.h"

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void HTEMP_VOIDInit(u8 Copy_U8Port, u8 Copy_U8Pin);
u8 HTEMP_U8GetTemp(void) ;




#endif 

/******************************************************************************
 *
 * Module: HAC
 *
 * File Name: HAC_Interface.h
 *
 * Description: Interface header file for HAL AC Module
 *
 * Author: Omar Khedr
 ******************************************************************************/
#ifndef _APP_INTERFACE_H_
#define _APP_INTERFACE_H_

/*******************************************************************************
 *                              Module Inclusions                               *
 *******************************************************************************/

/*Include of DIO Module*/
#include "../../MCAL/DIO/MDIO_Interface.h"

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void HAC_VOIDInit(u8 Copy_U8Port, u8 Copy_U8Pin);
void HAC_VOIDOnOff(void);



#endif

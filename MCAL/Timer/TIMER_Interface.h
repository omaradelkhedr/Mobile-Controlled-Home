/******************************************************************************
 *
 * Module: TIMER
 *
 * File Name: TIMER_Interface.h
 *
 * Description: Interface header file for MCAL TIMER Module
 *
 * Author: Ahmed Abdelhamid
 ******************************************************************************/

#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_

/*******************************************************************************
 *                              Module Inclusions                                *
 *******************************************************************************/


/*Include of Standard types header file */
#include "../../LIB/STD_TYPES.h"
/*Include of Bit Math header file*/
#include "../../LIB/BIT_MATH.h"
/*Include of module private file*/
#include "../../MCAL/Timer/TIMER_Private.h"
/*Include of DIO module Interface file */
#include "../../MCAL/DIO/MDIO_Interface.h"



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/


void MTMR0_VOIDFastPWMInit (void);
void MTMR0_VOIDSetDutyCycle (u8 Copy_U8DutyCycle);
void MTMR0_VOIDPWMOff (void);
void MTMR2_VOIDNormalInit (void);
void MTMR2_VOIDNormalStart (u16 Copy_U16RequiredDelay);

/*******************************************************************************
 *                      Module Used Macros                                    *
 *******************************************************************************/

#define OCR0_MAX (255U)
#define CS00 (0U)
#define CS01 (1U)
#define CS02 (2U)
#define WGM01 (3U)
#define COM00 (4U)
#define COM01 (5U)
#define WGM00 (6U)
#define OCIE0 (1U)
#define TOIE0 (0U)
#define TOV0 (0U)
#define TOV2 (6U)
#define TOIE2 (6U)
#define WGM20 (6U)
#define WGM21 (3U)
#define COM20 (4U)
#define COM21 (5U)
#define CS20 (0U)
#define CS21 (1U)
#define CS22 (2U)




#endif 

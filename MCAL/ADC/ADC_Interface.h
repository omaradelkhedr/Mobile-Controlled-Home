/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_Interface.h
 *
 * Description: Interface header file for MCAL ADC Module
 *
 * Author: Omar Khedr
 ******************************************************************************/
#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

/*******************************************************************************
 *                              Module Inclusions                               *
 *******************************************************************************/

/*Include of Standard types header file */
#include "../../LIB/Std_Types.h"
/*Include of Bit Math header file*/
#include "../../LIB/BIT_MATH.h"
/*Include of module private file*/
#include "ADC_Private.h"

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void MADC_VOIDInit (void);
u8 MADC_U8ReadValue (void);


/*******************************************************************************
 *                      Module Used Macros                                    *
 *******************************************************************************/

#define ZERO (0U)

#define REFS1 (7U)
#define REFS0 (6U)
#define ADLAR (5U)
#define MUX4 (4U)
#define MUX3 (3U)
#define MUX2 (2U)
#define MUX1 (1U)
#define MUX0 (0U)

#define ADEN (7U)
#define ADSC (6U)
#define ADIF (4U)
#define ADPS2 (2U)
#define ADPS1 (1U)
#define ADPS0 (0U)



#endif

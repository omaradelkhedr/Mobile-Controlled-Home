/******************************************************************************
 *
 * Module: USART
 *
 * File Name: USART_Interface.h
 *
 * Description: Interface header file for MCAL USART Module
 *
 * Author: Mayar Wael
 ******************************************************************************/

#ifndef _USART_INTERFACE_H_
#define _USART_INTERFACE_H_

/*******************************************************************************
 *                              Module Inclusions                                *
 *******************************************************************************/

/*Include of Standard types header file */
#include "../../LIB/STD_TYPES.h"
/*Include of Bit Math header file*/
#include "../../LIB/BIT_MATH.h"
/*Include of the module Private file */
#include "../../MCAL/USART/USART_Private.h"

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void MUSART_VoidInit(u16 Copy_u16BaudRate);
void MUSART_VoidSendChar(u8 Copy_u8SentChar);
void MUSART_VoidSendString(u8 *Copy_u8SentString);
u8 MUSART_u8ReceiveChar(void);
u8 * MUSART_u8ReceiveString(void);
void MUSART_VOIDSendNumber (u32 Copy_U32Number);


#endif

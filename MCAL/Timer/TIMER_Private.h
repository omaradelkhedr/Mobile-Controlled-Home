/******************************************************************************
 *
 * Module: TIMER
 *
 * File Name: TIMER_Private.h
 *
 * Description: Private header file for MCAL TIMER Module
 *
 * Author: Ahmed Abdelhamid
 ******************************************************************************/

#ifndef _TIMER_PRIVATE_H_
#define _TIMER_PRIVATE_H_

/*******************************************************************************
 *                              Module Registers                                *
 *******************************************************************************/


#define TCCR0_REG *( (volatile u8*)0x53 )
#define TCNT0_REG *( (volatile u8*)0x52 )
#define OCR0_REG *( (volatile u8*)0x5C )
#define TCCR2_REG *( (volatile u8*)0x45 )
#define TCNT2_REG *( (volatile u8*)0x44 )
#define OCR2_REG *( (volatile u8*)0x43 )
#define TIMSK_REG *( (volatile u8*)0x59 )
#define TIFR_REG *( (volatile u8*)0x58 )






#endif

/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC_Interface.h
 *
 * Description: Private header file for MCAL ADC Module
 *
 * Author: Omar Khedr
 ******************************************************************************/
#ifndef _MADC_PRIVATE_H_
#define _MADC_PRIVATE_H_

/*******************************************************************************
 *                              Module Registers                                *
 *******************************************************************************/

#define ADMUX_REG		*((volatile u8*) 0x27)
#define ADCSRA_REG		*((volatile u8*) 0x26)
#define ADCL_REG		*((volatile u8*) 0x24)
#define ADCH_REG		*((volatile u8*) 0x25)
#define SFIOR_REG		*((volatile u8*) 0x50)

#endif

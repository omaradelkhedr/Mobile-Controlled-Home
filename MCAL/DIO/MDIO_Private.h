/******************************************************************************
 *
 * Module: MDIO
 *
 * File Name: MDIO_Interface.h
 *
 * Description: Private header file for MCAL Digital Input Output (DIO) Module
 *
 * Author: Mayar Wael
 ******************************************************************************/
#ifndef _MDIO_PRIVATE_H_
#define _MDIO_PRIVATE_H_

/*******************************************************************************
 *                              Module Registers                                *
 *******************************************************************************/

#define PORTA_REG		*((volatile u8*) 0x3B)
#define DDRA_REG		*((volatile u8*) 0x3A)
#define PINA_REG		*((volatile u8*) 0x39)

#define PORTB_REG		*((volatile u8*) 0x38)
#define DDRB_REG		*((volatile u8*) 0x37)
#define PINB_REG		*((volatile u8*) 0x36)

#define PORTC_REG		*((volatile u8*) 0x35)
#define DDRC_REG		*((volatile u8*) 0x34)
#define PINC_REG		*((volatile u8*) 0x33)

#define PORTD_REG		*((volatile u8*) 0x32)
#define DDRD_REG		*((volatile u8*) 0x31)
#define PIND_REG		*((volatile u8*) 0x30)


#endif

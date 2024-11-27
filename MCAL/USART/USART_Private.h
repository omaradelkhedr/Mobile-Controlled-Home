/******************************************************************************
 *
 * Module: USART
 *
 * File Name: USART_Private.h
 *
 * Description: Private header file for MCAL USART Module
 *
 * Author: Mayar Wael
 ******************************************************************************/

#ifndef _USART_PRIVATE_H_
#define _USART_PRIVATE_H_

/*******************************************************************************
 *                              Module Registers                                *
 *******************************************************************************/


#define USART_UDR             *((volatile u8*)0x2C)          /*USART I/O Data Register*/

#define USART_UCSRA           *((volatile u8*)0x2B)          /* SART Control and Status Register A – UCSRA */
#define USART_UCSRA_RXC              7                       /* USART Receive Complete flag */
#define USART_UCSRA_TXC              6                       /* USART Transmit Complete flag */
#define USART_UCSRA_UDRE           	 5                       /* USART Data Register Empty flag */
#define USART_UCSRA_FE               4                       /* Frame Error flag */
#define USART_UCSRA_DOR              3                       /* DOR: Data OverRun flag */
#define USART_UCSRA_PE               2                       /* Parity Error flag */
#define USART_UCSRA_U2X              1                       /* Double the USART Transmission Speed flag */
#define USART_UCSRA_MPCM             0                       /* Multi-processor Communication Mode */




#define USART_UCSRB          *((volatile u8*)0x2A)          /* USART Control and Status Register B – UCSRB */
#define USART_UCSRB_RXCIE             7                     /* RX(Recieve) Complete Interrupt Enable bit */
#define USART_UCSRB_TXCIE          	  6                     /* TX Complete Interrupt Enable  bit */
#define USART_UCSRB_UDRIE         	  5                     /* USART Data Register Empty Interrupt Enable  bit */
#define USART_UCSRB_RXEN              4                     /* Receiver Enable bit */
#define USART_UCSRB_TXEN              3                     /* Transmitter Enable bit */
#define USART_UCSRB_UCSZ2             2                     /* Character Size   ... This bit is one of three bit to select character size */
#define USART_UCSRB_RXB8              1                     /* Receive Data Bit 8 ...  This bit must be read before reading the low bits from UDR*/
#define USART_UART_UCSRB_TXB8         0                     /* Transmit Data Bit 8 ... This bit must be written before writing the low bits to UDR.*/


#define USART_UCSRC         *((volatile u8*)0x40)           /*  USART Control and Status Register C - UCSRC */
#define USART_UCSRC_URSEL               7         			/* Register Select ...This bit selects between accessing the UCSRC or the UBRRH Register */
#define USART_UCSRC_UMSEL               6  					/*SART Mode Select ....This bit selects between Asynchronous and Synchronous mode of operation.*/
#define USART_UCSRC_UPM1                5					/*Parity Mode*/
#define USART_UCSRC_UPM0                4	   				/* Stop Bit Select....This bit selects the number of Stop Bits to be inserted by the Transmitter */
#define USART_UCSRC_USBS                3       		    /*Stop Bit Select */
/* The following two bits are used with UART_UCSRB_UCSZ2 to select character size*/
#define USART_UCSRC_UCSZ1               2
#define USART_UCSRC_UCSZ0               1
#define USART_UCSRC_UCPOL               0                   /*Clock Polarity...This bit is used for Synchronous mode only */


#define USART_UBRRL           *((volatile u8*)0x29)         /*USART Baud Rate Registers – UBRRL and UBRRH*/
#define USART_UBRRH           *((volatile u8*)0x40)
#define USART_UBRRH_URSEL               7                   /* This bit selects between accessing the UCSRC or the UBRRH Register.It must be zero when writing UBRRH.*/
#define USART_UBRRH_UBRR                11                   /* USART Baud Rate Register  .You can choose another bit from 11 till 0*/

#define USART_DISABLE                   0
#define USART_ENABLE                    1

#define MCU_FREQ 8000000

#endif

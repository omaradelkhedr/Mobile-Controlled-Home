/******************************************************************************
 *
 * Module: USART
 *
 * File Name: USART_Program.c
 *
 * Description: Program source file for MCAL USART Module
 *
 * Author: Mayar Wael
 ******************************************************************************/

/*Include of the module header file*/
#include "USART_Interface.h"

/************************************************************************************
 * Function Name: MUSART_VoidInit
 * Parameters (in): u16 Copy_u16BaudRate - to store the value of the req. baud rate
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to initialize the USART module and set the baud rate
 ************************************************************************************/

void MUSART_VoidInit(u16 Copy_u16BaudRate)
{
	/*  local variable to assign bits' values to UCSRC Register */
	u8 LOC_u8RRegVal=0;

	/*set bit 7 to select writing in register UCSRC not UBRRH */
	SET_BIT(LOC_u8RRegVal,USART_UCSRC_URSEL);

	/* Select Asyncronous Mode of UASRT  */
	CLR_BIT(LOC_u8RRegVal,USART_UCSRC_UMSEL);

	/*Select Parity Disable Mode*/
	CLR_BIT(LOC_u8RRegVal,USART_UCSRC_UPM1);
	CLR_BIT(LOC_u8RRegVal,USART_UCSRC_UPM0);

	/* select one stop bit  */
	CLR_BIT(LOC_u8RRegVal,USART_UCSRC_USBS);

	/*Select Char Size [8 bit] */
	CLR_BIT(LOC_u8RRegVal,USART_UCSRB_UCSZ2);
	SET_BIT(LOC_u8RRegVal,USART_UCSRC_UCSZ0);
	SET_BIT(LOC_u8RRegVal,USART_UCSRC_UCSZ1);


	/*Assign Value To Register  */
	USART_UCSRC=LOC_u8RRegVal;

	/*Select Baud Rate in bps*/
	USART_UBRRL=((MCU_FREQ)/(16*(u32)Copy_u16BaudRate)) -1;

	/*Enable Rx and Tx*/
	SET_BIT(USART_UCSRB,USART_UCSRB_RXEN);
	SET_BIT(USART_UCSRB,USART_UCSRB_TXEN);
}

/************************************************************************************
 * Function Name: MUSART_VoidSendChar
 * Parameters (in): u8 Copy_u8SentChar - to store the value of the sent character
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to send a character
 ************************************************************************************/

void MUSART_VoidSendChar(u8 Copy_u8SentChar)
{
	/* Check the UDRE flag to know whether the UDR buffer is empty or not*/
	while(GET_BIT(USART_UCSRA,USART_UCSRA_UDRE)==0)
	{
		/*Do Nothing*/
	}
	USART_UDR = Copy_u8SentChar;
}

/************************************************************************************
 * Function Name: MUSART_VoidSendString
 * Parameters (in): None
 * Parameters (inout): u8 *Copy_u8SentString - to store the characters into an array
 * Parameters (out): None
 * Return value: None
 * Description: Function to send a string (character by character)
 ************************************************************************************/

void MUSART_VoidSendString(u8 *Copy_u8SentString)
{
	u16 LOC_u16Counter= 0;

	while(Copy_u8SentString[LOC_u16Counter] != '\0')
	{
		MUSART_VoidSendChar(Copy_u8SentString[LOC_u16Counter]);
		LOC_u16Counter++;
	}
}

/************************************************************************************
 * Function Name: MUSART_u8ReceiveChar
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): u8 LOC_U8RetVal - to return the recieved character
 * Return value: None
 * Description: Function to recieve a character
 ************************************************************************************/

u8 MUSART_u8ReceiveChar(void)
{
	u8 LOC_U8RetVal;
	/* Check the RXC flag to know whether there is unread data in the receive buffer or not*/
	while (GET_BIT(USART_UCSRA,USART_UCSRA_RXC)==0)
	{
		/*Do Nothing*/
	}
	LOC_U8RetVal = USART_UDR;
	return LOC_U8RetVal;
}

/************************************************************************************
 * Function Name: MUSART_u8ReceiveString
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): static u8 LOC_RXString[32]- to return the recieved string
 * Return value: None
 * Description: Function to recieve a string (character by character)
 ************************************************************************************/

u8 * MUSART_u8ReceiveString(void)
{
	u8 LOC_RXChar ;
	static u8 LOC_RXString[32];
	u8 LOC_u8Counter =0;
	/* Waiting till receiving flag is set*/
	while (GET_BIT(USART_UCSRA,USART_UCSRA_RXC)==0);
	{
		while ((LOC_RXChar=MUSART_u8ReceiveChar())!='\r')     /* Receive characters untill ENTER is pressed (ASCII OF ENTER IS 13) */
		{
			LOC_RXString[LOC_u8Counter++]=LOC_RXChar;

		}
		LOC_RXString[LOC_u8Counter]='\0';
		return LOC_RXString;
	}
}

/************************************************************************************
 * Function Name: MUSART_VOIDSendNumber
 * Parameters (in): u32 Copy_U32Number
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to send a number
 ************************************************************************************/

void MUSART_VOIDSendNumber (u32 Copy_U32Number)
{
	u32 LOC_U32Reversed =1,LOC_U32SentCharacter;
	if(0==Copy_U32Number)
	{
		MUSART_VoidSendChar ('0');
	}
	while (Copy_U32Number>0)
	{
		LOC_U32Reversed= (LOC_U32Reversed*10) + (Copy_U32Number%10);
		Copy_U32Number=Copy_U32Number/10;
	}
	while (LOC_U32Reversed>1)
	{
		LOC_U32SentCharacter=LOC_U32Reversed%10;
		MUSART_VoidSendChar(LOC_U32SentCharacter+'0');
		LOC_U32Reversed=LOC_U32Reversed/10;
	}
}


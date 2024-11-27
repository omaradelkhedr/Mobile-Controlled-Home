/******************************************************************************
 *
 * Module: APP
 *
 * File Name: APP_Program.c
 *
 * Description: Program source file for the Application
 *
 * Author: Omar Khedr, Ahmed Abdelhamid, Mayar Wael
 ******************************************************************************/

/*Include of the module header file*/
#include "APP_Interface.h"

/*******************************************************************************
 *                     	      Database Array	 	                           *
 *******************************************************************************/

GLOB_STDataBase  Users[MAXIMUM_USERS] =
{
		"Omar Adel","FirstPassword",
		"Ahmed Abdelhamid","SecondPassword",
		"Mayar Wael", "ThirdPassword",
		"Omar Khedr", "FourthPassword" ,
		"Ahmed Shokry", "FifthPassword",
		"Mayar Heweidy", "SixthPassword",
		"omar adel khedr", "SeventhPassword",
		"ahmed shokry", "EigthPassword",
		"mayar wael kamal", "NinthPassword",
		"Khedr", "TenthPassword"
};


/************************************************************************************
 * Function Name: APP_U8StringLength
 * Parameters (in): None
 * Parameters (inout): u8 * Copy_U8String - to store the string
 * Parameters (out): None
 * Return value: u8 LOC_U8RetVal - to return the number of characters
 * Description: Function to return the number of characters in a given string
 ************************************************************************************/

u8 APP_U8StringLength (u8 * Copy_U8String)
{
	u8 LOC_U8RetVal=ZERO;
	u8 LOC_U8Iterator=ZERO;
	while (Copy_U8String[LOC_U8Iterator])
	{
		LOC_U8RetVal++;
		LOC_U8Iterator++;
	}
	return LOC_U8RetVal;
}

/************************************************************************************
 * Function Name: APP_S8StringCompare
 * Parameters (in): None
 * Parameters (inout): u8 * Copy_U8String1 - to store the 1st string
 * 					   u8 * Copy_U8String2 - to store the 2nd string
 * Parameters (out): None
 * Return value: s8 LOC_S8RetVal - to return the difference of their ASCII rep.
 * Description: Function to compare 2 strings, if equal size returns 0
 ************************************************************************************/

s8 APP_S8StringCompare (u8 * Copy_U8String1, u8* Copy_U8String2)
{
	s8 LOC_S8RetVal;
	u8 LOC_U8Length1=APP_U8StringLength(Copy_U8String1);
	u8 LOC_U8Length2=APP_U8StringLength(Copy_U8String2);
	if (LOC_U8Length1 != LOC_U8Length2)
	{
		LOC_S8RetVal=-1;
	}
	else
	{
		u8 LOC_U8Iterator=ZERO;
		while (Copy_U8String1[LOC_U8Iterator])
		{
			if ((Copy_U8String1[LOC_U8Iterator] - Copy_U8String2[LOC_U8Iterator]) != ZERO)
			{
				LOC_S8RetVal=Copy_U8String1[LOC_U8Iterator]-Copy_U8String2[LOC_U8Iterator];
				break;
			}
			else
			{
				LOC_S8RetVal=ZERO;
			}
			LOC_U8Iterator++;
		}
	}
	return LOC_S8RetVal;
}

/************************************************************************************
 * Function Name: APP_VOIDStart
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function of the required application
 ************************************************************************************/

void APP_VOIDStart (void)
{

	/*Initialize all modules*/
	/*Setting the Buzzer on Port B, Pin 0*/
	HBUZZER_VOIDInit(PORTB,PIN0);
	/*Setting the LED on Port B, Pin 1*/
	HLED_VOIDInit(PORTB,PIN3);
	/*Initialize Pin 0 in Port C to be output to represent the AC (On/Off)*/
	HAC_VOIDInit(PORTC, PIN0);
	/*Setting the temperature sensor at Port A, Pin 4*/
	HTEMP_VOIDInit(PORTA, PIN4);
	/*Initializing the USART module with the following features nad frame format
	 * Mode: Asynchronous
	 * Speed: Normal
	 * Parity: None
	 * Stop Bit: 1
	 * Baud Rate: 9600
	 */
	MUSART_VoidInit(DEFAULT_BAUD_RATE);
	/*Creating a status variable to check if username is found*/
	u8 LOC_U8User_Status=NOT_FOUND;
	/*Creating a status variable to check if password is correct*/
	u8 LOC_U8PSWD_Status=NOT_CORRECT;
	/*Creating a status variable to check if user is logged in or out*/
	u8 LOC_U8Log_Status=LOGGED_OUT;
	/*Creating a status variable to check if alarm is trigerred or not*/
	u8 LOC_U8Alarm_Status=ALARM_OFF;
	/*Creating a status variable to check if the door is locked or not*/
	u8 LOC_U8Lock_Status=LOCKED;
	/*Creating a local variable to be used as an entry point in the application*/
	u8 LOC_U8Entry_Point=ZERO;
	/*Creating a local variable to be used as the index to the found username*/
	u8 LOC_U8User_Index=ZERO;
	/*Creating a local variable to be used as counter of the username trials*/
	u8 LOC_U8User_Counter=ZERO;
	/*Creating a local variable to be used as counter of the password trials*/
	u8 LOC_U8PSWD_Counter=ZERO;
	/*Creating a status variable to check if the AC is turned on or off*/
	u8 LOC_U8PAC_Status=AC_OFF;
	/*Creating a local variable to be used as a flag*/
	u8 LOC_U8Flag=ZERO;
	/*Welcome Message*/
	MUSART_VoidSendString("\nWelcome to the Mobile Controlled Home\n");
	while (1)
	{
		while(LOC_U8Alarm_Status== ALARM_ON)
		{
			HBUZZER_VOIDTriggerAlarm();
			MTMR2_VOIDNormalStart(ONE_SECOND);
			HBUZZER_VOIDStopAlarm();
			MTMR2_VOIDNormalStart(ONE_SECOND);
		}
		if(LOC_U8Entry_Point == ZERO)
		{
			/*Request the user to enter his username*/
			MUSART_VoidSendString("Please enter your username: \n");
			/*Scan the username from the user*/
			u8 *LOC_RecievedUsername= MUSART_u8ReceiveString();
			/*Increment the username trials counter*/
			LOC_U8User_Counter++;
			/*For loop that iterates only 3 times and sets the FOUND flag if the username is found*/
			for (u8 LOC_U8Iterator =ZERO; (LOC_U8Iterator<MAXIMUM_TRIALS) || (LOC_U8Flag==ONE) ; LOC_U8Iterator++ )
			{
				/*Iterate on the DB to search for the username*/
				for (u8 LOC_U8Iterator = ZERO ; (LOC_U8Iterator < MAXIMUM_USERS) && !(LOC_U8User_Status== FOUND) ; LOC_U8Iterator++ )
				{
					/*If it is found save the index, set the flag to be found and increment the entry point to ask for the password*/
					if(APP_S8StringCompare(Users[LOC_U8Iterator].User_Name,LOC_RecievedUsername) == ZERO )
					{
						LOC_U8User_Status=FOUND;
						LOC_U8User_Index=LOC_U8Iterator;
						LOC_U8Entry_Point=ONE;
						LOC_U8Flag=ZERO;
					}
					else
					{
						/*Do Nothing*/
					}
				}
				/*he can try 3 times*/
				if (LOC_U8User_Status == NOT_FOUND)
				{
					if (LOC_U8Iterator<ONE)
					{
						MUSART_VoidSendString("\nWrong Username, Please enter a valid username: \n");
						/*Scan the username from the user*/
						LOC_RecievedUsername= MUSART_u8ReceiveString();
						LOC_U8User_Counter++;
						LOC_U8Flag=ZERO;

					}
					else if(LOC_U8Iterator==TWO)
					{
						LOC_U8Flag=0;
						break;
					}
					else
					{
						MUSART_VoidSendString("\nWrong Username, Please enter a valid username: \n");
						/*Scan the username from the user*/
						LOC_RecievedUsername= MUSART_u8ReceiveString();
						LOC_U8User_Counter++;
						LOC_U8Flag=ONE;
					}
				}
			}
			/*The user exceeded the number of allowed trials -> Fire an alarm*/
			if ((LOC_U8User_Counter == THREE) && (LOC_U8User_Status==NOT_FOUND))
			{
				LOC_U8Alarm_Status=ALARM_ON;
			}
			else
			{
				/*Do Nothing*/
			}
		}
		/*Correct Username -> Check Password*/
		else if (LOC_U8Entry_Point == ONE)
		{
			/*Request the user to enter his password*/
			MUSART_VoidSendString("\nPlease enter your password: \n");
			/*Scan the password from the user*/
			u8 *LOC_RecievedPassword = MUSART_u8ReceiveString();
			LOC_U8PSWD_Counter++;
			/*For loop that iterates only 3 times and sets the CORRECT flag if the password is correct*/
			for (u8 LOC_U8Iterator =ZERO; (LOC_U8Iterator<MAXIMUM_TRIALS) || (LOC_U8Flag==ONE); LOC_U8Iterator++ )
			{
				/*If it is correct then set the CORRECT flag and increment the entry point to allow him to use the commands*/
				if (APP_S8StringCompare(Users[LOC_U8User_Index].Password,LOC_RecievedPassword) ==ZERO)
				{
					LOC_U8PSWD_Status=CORRECT;
					LOC_U8Entry_Point=TWO;
					LOC_U8Flag=ZERO;
				}
				/*He can try 3 times*/
				else
				{
					if (LOC_U8Iterator<ONE)
					{
						MUSART_VoidSendString("Wrong Password, Please Enter the Correct Password: \n");
						LOC_RecievedPassword = MUSART_u8ReceiveString();
						LOC_U8PSWD_Counter++;
					}
					else if (LOC_U8Iterator==TWO)
					{
						LOC_U8Flag=0;
						break;
					}
					else
					{
						MUSART_VoidSendString("Wrong Password, Please Enter the Correct Password: \n");
						LOC_RecievedPassword = MUSART_u8ReceiveString();
						LOC_U8PSWD_Counter++;
						LOC_U8Flag=ONE;
					}

				}
			}
			/*User exceeded the number of trials-> fire an alarm*/
			if((LOC_U8PSWD_Counter == THREE) && (LOC_U8PSWD_Status == NOT_CORRECT))
			{
				LOC_U8Alarm_Status=ALARM_ON;
			}
		}
		/*Correct Password -> Control your home*/
		else if (LOC_U8Entry_Point == TWO || LOC_U8Entry_Point == THREE)
		{
			/*This if condition enables the user for continuous entry of commands untill he log out*/
			if(LOC_U8Entry_Point == TWO)
			{
				/*User can control his home by pressing the buttons in the mobile app*/
				MUSART_VoidSendString("\nCorrect Password\nYou can use the buttons below to control your home\n");
				LOC_U8Entry_Point=THREE;
				LOC_U8Log_Status=LOGGED_IN;
			}
			else if (LOC_U8Entry_Point == THREE)
			{
				/*Scan the command from the user*/
				u8 *LOC_RecievedCommand = MUSART_u8ReceiveString();
				/*Check the command*/
				if (APP_S8StringCompare(LOC_RecievedCommand,LOG_OUT_COMMAND) ==ZERO)
				{
					LOC_U8Log_Status=LOGGED_OUT;
					MUSART_VoidSendString("You signed out!\n");
					LOC_U8Entry_Point=ZERO;
					LOC_U8Alarm_Status=ALARM_OFF;
					LOC_U8PSWD_Status=NOT_CORRECT;
					LOC_U8User_Status=NOT_FOUND;
					LOC_U8User_Index=ZERO;
					LOC_U8User_Counter=ZERO;
					LOC_U8PSWD_Counter=ZERO;
				}
				else if(APP_S8StringCompare(LOC_RecievedCommand,LED_ON_COMMAND) ==ZERO)
				{
					/*Initialization of PWM mode inside Timer*/
					MTMR0_VOIDFastPWMInit();
					/*Setting the duty cycle to full intensity*/
					MTMR0_VOIDSetDutyCycle(100);
					MUSART_VoidSendString("LED intensity is 100% \n");
				}
				else if (APP_S8StringCompare(LOC_RecievedCommand,LED_OFF_COMMAND) ==ZERO)
				{
					/*Disable the OC0 bit and Clock source*/
					MTMR0_VOIDPWMOff();
					MUSART_VoidSendString("LED intensity is 0% \n");
				}
				else if ((APP_S8StringCompare(LOC_RecievedCommand,DOOR_LOCK_COMMAND) ==ZERO)&&(LOC_U8Lock_Status == UNLOCKED))
				{
					HMTR_VOIDRotateCCW();
					MUSART_VoidSendString("Door is Locked\n");
					LOC_U8Lock_Status = LOCKED ;
				}
				else if ((APP_S8StringCompare(LOC_RecievedCommand,DOOR_LOCK_COMMAND) ==ZERO)&&(LOC_U8Lock_Status == LOCKED))
				{
					MUSART_VoidSendString("Door is Already locked\n");
				}
				else if ((APP_S8StringCompare(LOC_RecievedCommand,DOOR_UNLOCK_COMMAND) ==ZERO)&&(LOC_U8Lock_Status == LOCKED))
				{
					HMTR_VOIDRotateCW();
					MUSART_VoidSendString("Door is Unlocked\n");
					LOC_U8Lock_Status = UNLOCKED ;
				}
				else if ((APP_S8StringCompare(LOC_RecievedCommand,DOOR_UNLOCK_COMMAND) ==ZERO)&&(LOC_U8Lock_Status == UNLOCKED))
				{
					MUSART_VoidSendString("Door is Already unlocked\n");
				}
				else if (APP_S8StringCompare(LOC_RecievedCommand,LED_INTENSITY25_COMMAND) ==ZERO)
				{
					/*Initialization of PWM mode inside Timer*/
					MTMR0_VOIDFastPWMInit();
					/*Setting the duty cycle to 25% intensity*/
					MTMR0_VOIDSetDutyCycle(25);
					MUSART_VoidSendString("LED intensity is 25% \n");
				}
				else if (APP_S8StringCompare(LOC_RecievedCommand,LED_INTENSITY50_COMMAND) ==ZERO)
				{
					/*Initialization of PWM mode inside Timer*/
					MTMR0_VOIDFastPWMInit();
					/*Setting the duty cycle to 50% intensity*/
					MTMR0_VOIDSetDutyCycle(50);
					MUSART_VoidSendString("LED intensity is 50% \n");
				}
				else if (APP_S8StringCompare(LOC_RecievedCommand,LED_INTENSITY75_COMMAND) ==ZERO)
				{
					/*Initialization of PWM mode inside Timer*/
					MTMR0_VOIDFastPWMInit();
					/*Setting the duty cycle to 75% intensity*/
					MTMR0_VOIDSetDutyCycle(75);
					MUSART_VoidSendString("LED intensity is 75% \n");
				}
				else if (APP_S8StringCompare(LOC_RecievedCommand,AC_ON_OFF_COMMAND) ==ZERO)
				{
					if(LOC_U8PAC_Status == AC_OFF)
					{
						HAC_VOIDOnOff();
						MUSART_VoidSendString("AC is ON\n");
						LOC_U8PAC_Status = AC_ON;
					}
					else if (LOC_U8PAC_Status == AC_ON)
					{
						HAC_VOIDOnOff();
						MUSART_VoidSendString("AC is OFF\n");
						LOC_U8PAC_Status = AC_OFF;
					}
				}
				else if (APP_S8StringCompare(LOC_RecievedCommand,GET_TEMP_COMMAND) ==ZERO)
				{
					HTEMP_U8GetTemp();
					u8 LOC_U8RecievedTemp = HTEMP_U8GetTemp();
					MUSART_VoidSendString("The Temperature now is: ");
					MUSART_VOIDSendNumber(LOC_U8RecievedTemp);
					MUSART_VoidSendString("\n");
				}
				else
				{
					MUSART_VoidSendString("Please enter a proper command\n");
				}
			}
			else
			{
				/*Do Nothing*/
			}

		}
		else
		{
			/*Do Nothing*/
		}
	}
}







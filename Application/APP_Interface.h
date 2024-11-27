/******************************************************************************
 *
 * Module: APP
 *
 * File Name: APP_Interface.h
 *
 * Description: Interface header file for the Application
 *
 * Author: Omar Khedr, Ahmed Abdelhamid, Mayar Wael
 ******************************************************************************/
#ifndef _APP_INTERFACE_H_
#define _APP_INTERFACE_H_

/*******************************************************************************
 *                              Module Inclusions                               *
 *******************************************************************************/

/*Include of Standard types header file */
#include "../LIB/Std_Types.h"
/*Include of Bit Math header file*/
#include "../LIB/BIT_MATH.h"
/*Include of HAL LED module*/
#include "../HAL/LED/HLED_Interface.h"
/*Include of HAL Buzzer module*/
#include "../HAL/Buzzer/HBUZZER_Interface.h"
/*Include of HAL Motor module*/
#include "../HAL/Motor/MOTOR_Interface.h"
/*Include of MCAL USART module*/
#include "../MCAL/USART/USART_Interface.h"
/*Include of HAL TEMPSENSOR module*/
#include "../HAL/Temperature Sensor/TEMPSENSOR_Interface.h"
/*Include of Timer module*/
#include "../MCAL/Timer/TIMER_Interface.h"

/*******************************************************************************
 *                      Module Definitions                                     *
 *******************************************************************************/

typedef struct
{
	u8 User_Name[20];
	u8 Password[20];
} GLOB_STDataBase;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

u8 APP_U8StringLength (u8 * Copy_U8String);
s8 APP_S8StringCompare (u8 * Copy_U8String1, u8* Copy_U8String2);
void APP_VOIDStart (void);


/*******************************************************************************
 *                      Module Used Macros                                    *
 *******************************************************************************/

#define ZERO	(0U)
#define ONE		(1U)
#define TWO     (2U)
#define THREE	(3U)
#define FOUR	(4U)
#define LED_ON_COMMAND (u8 *)("CMD00")
#define LED_OFF_COMMAND (u8 *)("CMD01")
#define DOOR_LOCK_COMMAND (u8 *)("CMD02")
#define DOOR_UNLOCK_COMMAND (u8 *)("CMD03")
#define LOG_OUT_COMMAND (u8 *)("CMD04")
#define LED_INTENSITY25_COMMAND (u8 *)("CMD05")
#define LED_INTENSITY50_COMMAND (u8 *)("CMD06")
#define LED_INTENSITY75_COMMAND (u8 *)("CMD07")
#define GET_TEMP_COMMAND (u8 *)("CMD08")
#define AC_ON_OFF_COMMAND  (u8 *)("CMD09")
#define DEFAULT_BAUD_RATE (9600U)
#define ONE_SECOND	(1000U)
#define MAXIMUM_USERS (10U)
#define MAXIMUM_CHARACTERS (20U)
#define FOUND (1U)
#define NOT_FOUND (0U)
#define NOT_CORRECT (0U)
#define CORRECT (1U)
#define LOGGED_IN	(1U)
#define LOGGED_OUT	(0U)
#define ALARM_OFF (0U)
#define ALARM_ON	(1U)
#define MAXIMUM_TRIALS (2U)
#define LOCKED (1U)
#define UNLOCKED (0U)
#define AC_OFF (0U)
#define AC_ON (1U)



#endif

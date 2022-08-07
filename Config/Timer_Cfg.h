/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  DIO
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef TIMER_CFG_H
#define TIMER_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Timer_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
	GPT_PREDEF_TIMER_1US_16BIT,
	GPT_PREDEF_TIMER_1US_24BIT,
	GPT_PREDEF_TIMER_1US_32BIT,
	GPT_PREDEF_TIMER_100US_32BIT
}Gpt_ConfigType;

typedef enum {
	E_NOT_Ok,
	E_Ok
}Std_RET;

typedef enum{
	Channel0,
	Channel1,
	Channel2,
	Channel3,
	Channel4,
	Channel5,
	Channel6,
	Channel7,
	Channel8,
	Channel9,
	Channel10,
	Channel11
}Gpt_ChannelType;

typedef enum{
	GPT_CH_MODE_CONTINUOUS,
	GPT_CH_MODE_ONESHOTE
}Gpt_Mode;

typedef void (*GptNotification)(void);

typedef struct{
	Gpt_ChannelType GptChannelId;
	u8 GptChannelTickFrequency;
	u32 GptChannelTickValueMax;
	Gpt_Mode GptCahnnelMode;
  GptNotification callback;
}GptChannelConfigSet;


#define NO_OF_ENABLED_TIMERS 1
#define PredefTimer_Enable  0	
#define PredefTimer GPT_PREDEF_TIMER_1US_16BIT
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/
 #endif
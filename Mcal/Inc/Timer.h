/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  DIO
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef TIMER_H
#define TIMER_H

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
#define setBit(reg,bit)				reg|=(1<<bit)
#define resetBit(reg,bit)			reg&=~(1<<bit)
#define toggelBit(reg,bit)			reg^=(1<<bit)
#define readBit(reg,bit)			(reg&(1<<bit))>>bit
#define IsBitClear(reg,bit)		!(reg&(1<<bit))>>bit

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


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

#define NULL        (void *)0
void Gpt_Init(const GptChannelConfigSet* EnabledTimers);
void PREDEF_TIMER_1US_16BIT(void);
void PREDEF_TIMER_1US_32BIT(void);
void PREDEF_TIMER_100US_32BIT(void);
void Channel0_Handler 	(u8 NO,const GptChannelConfigSet* EnabledTimers);
void Channel1_Handler 	(u8 NO,const GptChannelConfigSet* EnabledTimers);
void Channel2_Handler 	(u8 NO,const GptChannelConfigSet* EnabledTimers);
void Channel3_Handler 	(u8 NO,const GptChannelConfigSet* EnabledTimers);
void Channel4_Handler	 	(u8 NO,const GptChannelConfigSet* EnabledTimers);
void Channel5_Handler 	(u8 NO,const GptChannelConfigSet* EnabledTimers);
void Channel6_Handler 	(u8 NO,const GptChannelConfigSet* EnabledTimers);
void Channel7_Handler 	(u8 NO,const GptChannelConfigSet* EnabledTimers);
void Channel8A_Handler 	(u8 NO,const GptChannelConfigSet* EnabledTimers);
void Channel9A_Handler  (u8 NO,const GptChannelConfigSet* EnabledTimers);
void Channel10A_Handler (u8 NO,const GptChannelConfigSet* EnabledTimers);
void Channel11A_Handler (u8 NO,const GptChannelConfigSet* EnabledTimers);
void StartTimer(Gpt_ChannelType ChannelID, u32 Value);
void StopTimer(Gpt_ChannelType ChannelID);
u32 Gpt_GetTimeElapsed(Gpt_ChannelType ChannelID);
u32 Gpt_GetTimeRemaining(Gpt_ChannelType ChannelID);
void Gpt_DisableNotification(Gpt_ChannelType ChannelID);
void Gpt_EnableNotification(Gpt_ChannelType ChannelID);
#endif  /* Dio_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/
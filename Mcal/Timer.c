/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Systick.c
 *        \brief  system timer Driver
 *
 *      \details  The Driver Configure systick timer
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Timer.h"
#include "Register.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

	
/******************************************************************************
* \Syntax          : void Systick_Init(void)                                      
* \Description     : initialize                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
GptNotification CallbackArray[12];



void Gpt_Init(const GptChannelConfigSet* EnabledTimers){
	#if (PredefTimer_Enable==1)	
		 #if(PredefTimer==GPT_PREDEF_TIMER_1US_16BIT)
				PREDEF_TIMER_1US_16BIT();
		 #elif(PredefTimer==GPT_PREDEF_TIMER_1US_32BIT)
				PREDEF_TIMER_1US_32BIT();
	   #elif(GPT_PREDEF_TIMER_100US_32BIT)
				PREDEF_TIMER_100US_32BIT();
	   #endif
	#else
		u8 i=0;
		for(i=0;i<NO_OF_ENABLED_TIMERS;i++){
			switch(EnabledTimers[i].GptChannelId){
				case Channel0:
						 Channel0_Handler (i,EnabledTimers);
					break;
				case Channel1:				
						 Channel1_Handler (i,EnabledTimers);
					break;				
				case Channel2:				
						 Channel2_Handler (i,EnabledTimers);
					break;	
				case Channel3:				
						 Channel3_Handler (i,EnabledTimers);
					break;	
				case Channel4:				
						 Channel4_Handler (i,EnabledTimers);
					break;	
				case Channel5:				
						 Channel5_Handler (i,EnabledTimers);
					break;	
				case Channel6:				
						 Channel6_Handler (i,EnabledTimers);
					break;
				case Channel7:				
						 Channel7_Handler (i,EnabledTimers);
					break;
				case Channel8:				
						 Channel8A_Handler (i,EnabledTimers);
					break;
				case Channel9:				
						 Channel9A_Handler (i,EnabledTimers);
					break;
				case Channel10:				
						 Channel10A_Handler (i,EnabledTimers);
					break;
				case Channel11:				
						 Channel11A_Handler (i,EnabledTimers);
					break;
			}
		}
		
	#endif
}
void PREDEF_TIMER_1US_16BIT(void){
	RCGCTIMER|=0x01;	
	GPTMCtrl0A=0x00;			 //Disable Timer
	GPTMCFG0A=0x00000004;	 //set TimerA 16 bit
	GPTMTAMR0A=0x02;			 //periodic mode
	GPTMTAPR0A=16;				 //prescaller 
	GPTMICR0A|=0x01;					
}

void PREDEF_TIMER_1US_32BIT(void){
	RCGCTIMER|=0x01;	
	GPTMCtrl6A=0x00;			 //Disable Timer
	GPTMCFG6A=0x00000004;	 //set TimerA 16 bit
	GPTMTAMR6A=0x02;			 //periodic mode
	GPTMTAPR6A=16;				 //prescaller 
	GPTMICR6A|=0x01;	
}

void PREDEF_TIMER_100US_32BIT(void){
	RCGCTIMER|=0x01;	
	GPTMCtrl6A=0x00;			 //Disable Timer
	GPTMCFG6A=0x00000004;	 //set TimerA 16 bit
	GPTMTAMR6A=0x02;			 //periodic mode
	GPTMTAPR6A=1600;				 //prescaller 
	GPTMICR6A|=0x01;	
}
/*************************************************Start timer*****************************************************************/
void StartTimer(Gpt_ChannelType ChannelID, u32 Value){
		switch(ChannelID){
				case Channel0:
						GPTMTAILR0A=Value	;	 	 //setBit max value of timer
						GPTMCtrl0A|=0x01;										//enable Timer
					break;
				case Channel1:				
						GPTMTAILR1A=Value	;	 	 //setBit max value of timer
						GPTMCtrl1A|=0x01;										//enable Timer
					break;			
				case Channel2:				
						GPTMTAILR2A=Value	;	 	 //setBit max value of timer
						GPTMCtrl2A|=0x01;										//enable Timer
					break;						
				case Channel3:				
						GPTMTAILR3A=Value	;	 	 //setBit max value of timer
						GPTMCtrl3A|=0x01;										//enable Timer
					break;
				case Channel4:				
						GPTMTAILR4A=Value	;	 	 //setBit max value of timer
						GPTMCtrl4A|=0x01;										//enable Timer
					break;
				case Channel5:				
						GPTMTAILR5A=Value	;	 	 //setBit max value of timer
						GPTMCtrl5A|=0x01;										//enable Timer
					break;
				case Channel6:				
						GPTMTAILR6A=Value	;	 	 //setBit max value of timer
						GPTMCtrl6A|=0x01;										//enable Timer
					break;
				case Channel7:				
						GPTMTAILR7A=Value	;	 	 //setBit max value of timer
						GPTMCtrl7A|=0x01;										//enable Timer
					break;
				case Channel8:				
						GPTMTAILR8A=Value	;	 	 //setBit max value of timer
						GPTMCtrl8A|=0x01;										//enable Timer
					break;
				case Channel9:				
						GPTMTAILR9A=Value	;	 	 //setBit max value of timer
						GPTMCtrl9A|=0x01;										//enable Timer
					break;
				case Channel10:				
						GPTMTAILR10A=Value	;	 	 //setBit max value of timer
						GPTMCtrl10A|=0x01;										//enable Timer
					break;
				case Channel11:				
						GPTMTAILR11A=Value	;	 	 //setBit max value of timer
						GPTMCtrl11A|=0x01;										//enable Timer
					break;
			}
}
/*************************************************Stop timer*****************************************************************/
void StopTimer(Gpt_ChannelType ChannelID){
		switch(ChannelID){
			case Channel0:	
				GPTMCtrl0A=0x00;												//disable Timer
					break;
				case Channel1:
						GPTMCtrl1A=0x00;										//disable Timer
					break;			
				case Channel2:
						GPTMCtrl2A=0x00;										//disable Timer
					break;						
				case Channel3:
						GPTMCtrl3A=0x00;										//disable Timer
					break;
				case Channel4:
						GPTMCtrl4A=0x00;										//disable Timer
					break;
				case Channel5:
						GPTMCtrl5A=0x00;										//disable Timer
					break;
				case Channel6:
						GPTMCtrl6A=0x00;										//disable Timer
					break;
				case Channel7:
						GPTMCtrl7A=0x00;										//disable Timer
					break;
				case Channel8:
						GPTMCtrl8A=0x00;										//disable Timer
					break;
				case Channel9:
						GPTMCtrl9A=0x00;										//disable Timer
					break;
				case Channel10:
						GPTMCtrl10A=0x00;										//disable Timer
					break;
				case Channel11:
						GPTMCtrl11A=0x00;										//disable Timer
					break;
			}
}
/****************************************Channel zero handler ******************************************************/
void Channel0_Handler (u8 NO,const GptChannelConfigSet* EnabledTimers){
	 u8 prescaller=0;
		RCGCTIMER|=0x01;			 //enable clk 
		GPTMCtrl0A=0x00;			 //Disable Timer
		GPTMCFG0A=0x00000004;	 //set TimerA 16 bit 0x04,
		if(EnabledTimers[NO].GptCahnnelMode==GPT_CH_MODE_CONTINUOUS)
			GPTMTAMR0A=0x02;			 //cont mode
		else 
			GPTMTAMR0A=0x01;			 //oneshot mode						
		GPTMICR0A|=0x01;			 //interrupt control
		prescaller=16/EnabledTimers[NO].GptChannelTickFrequency;
		GPTMTAPR0A=prescaller;
		if (EnabledTimers[NO].callback!=NULL)
			CallbackArray[0]=EnabledTimers[NO].callback;
}

/****************************************Channel one handler ******************************************************/
void Channel1_Handler (u8 NO ,const GptChannelConfigSet* EnabledTimers){
		u8 prescaller;
		RCGCTIMER|=0x02;			 //enable clk 
		GPTMCtrl1A=0x00;			 //Disable Timer
		GPTMCFG1A=0x04;	 //set TimerA 16 bit 0x04,0x00//32bit
		if(EnabledTimers[NO].GptCahnnelMode==GPT_CH_MODE_CONTINUOUS)
			GPTMTAMR1A=0x02;			 //cont mode
		else 
			GPTMTAMR1A=0x01;			 //oneshote mode						
		GPTMICR0A|=0x01;			 //interrupt control
		prescaller=16/EnabledTimers[NO].GptChannelTickFrequency;
		GPTMTAPR0A=prescaller;
		if (EnabledTimers[NO].callback!=NULL)
			CallbackArray[1]=EnabledTimers[NO].callback;
}

/****************************************Channel two handler ******************************************************/
void Channel2_Handler (u8 NO,const GptChannelConfigSet* EnabledTimers){
		u8 prescaller;
		RCGCTIMER|=0x04;			 //enable clk 
		GPTMCtrl2A=0x00;			 //Disable Timer
		GPTMCFG2A=0x04;	 //set TimerA 16 bit 0x04,0x00//32bit
		if(EnabledTimers[NO].GptCahnnelMode==GPT_CH_MODE_CONTINUOUS)
			GPTMTAMR2A=0x02;			 //cont mode
		else 
			GPTMTAMR2A=0x01;			 //cont mode						
		GPTMICR2A|=0x01;			 //interrupt control
		prescaller=16/EnabledTimers[NO].GptChannelTickFrequency;
		GPTMTAPR0A=prescaller;
		if (EnabledTimers[NO].callback!=NULL)
			CallbackArray[2]=EnabledTimers[NO].callback;
}
/****************************************Channel three handler ******************************************************/
void Channel3_Handler (u8 NO,const GptChannelConfigSet* EnabledTimers){
		u8 prescaller;
		RCGCTIMER|=0x08;			 //enable clk 
		GPTMCtrl3A=0x00;			 //Disable Timer
		GPTMCFG3A=0x04;	 //set TimerA 16 bit 0x04,0x00//32bit
		if(EnabledTimers[NO].GptCahnnelMode==GPT_CH_MODE_CONTINUOUS)
			GPTMTAMR3A=0x02;			 //cont mode
		else 
			GPTMTAMR3A=0x01;			 //cont mode						
		GPTMICR3A|=0x01;			 //interrupt control
		prescaller=16/EnabledTimers[NO].GptChannelTickFrequency;
		GPTMTAPR0A=prescaller;
		if (EnabledTimers[NO].callback!=NULL)
			CallbackArray[3]=EnabledTimers[NO].callback;
}
/****************************************Channel four handler ******************************************************/
void Channel4_Handler (u8 NO,const GptChannelConfigSet* EnabledTimers){
		u8 prescaller;
		RCGCTIMER|=0x10;
		GPTMCtrl4A=0x00;			 //Disable Timer
		GPTMCFG4A=0x04;	 //set TimerA 16 bit 0x04,0x00//32bit
		if(EnabledTimers[NO].GptCahnnelMode==GPT_CH_MODE_CONTINUOUS)
			GPTMTAMR4A=0x02;			 //cont mode
		else 
			GPTMTAMR4A=0x01;			 //cont mode						
		GPTMICR4A|=0x01;			 //interrupt control
		prescaller=16/EnabledTimers[NO].GptChannelTickFrequency;
		GPTMTAPR4A=prescaller;
		if (EnabledTimers[NO].callback!=NULL)
			CallbackArray[4]=EnabledTimers[NO].callback;
}
/****************************************Channel five handler ******************************************************/
void Channel5_Handler (u8 NO,const GptChannelConfigSet* EnabledTimers){
		u8 prescaller;
		RCGCTIMER|=0x20;			 //enable clk 
		GPTMCtrl5A=0x00;			 //Disable Timer
		GPTMCFG5A=0x04;	 //set TimerA 16 bit 0x04,0x00//32bit
		if(EnabledTimers[NO].GptCahnnelMode==GPT_CH_MODE_CONTINUOUS)
			GPTMTAMR5A=0x02;			 //cont mode
		else 
			GPTMTAMR5A=0x01;			 //cont mode						
		GPTMICR5A|=0x01;			 //interrupt control
		prescaller=16/EnabledTimers[NO].GptChannelTickFrequency;
		GPTMTAPR5A=prescaller;
		if (EnabledTimers[NO].callback!=NULL)
			CallbackArray[5]=EnabledTimers[NO].callback;
}
void Channel6_Handler (u8 NO,const GptChannelConfigSet* EnabledTimers){
		u8 prescaller;
		RCGCWTIMER|=0x01;			 //enable clk 
		GPTMCtrl6A=0x00;			 //Disable Timer
		GPTMCFG5A=0x04;	 			 //set TimerA 16 bit 0x04,
		if(EnabledTimers[NO].GptCahnnelMode==GPT_CH_MODE_CONTINUOUS)
			GPTMTAMR5A=0x02;			 //cont mode
		else 
			GPTMTAMR5A=0x01;			 //cont mode						
		GPTMICR5A|=0x01;			 //interrupt control
		prescaller=16/EnabledTimers[NO].GptChannelTickFrequency;
		GPTMTAPR6A=prescaller;
		if (EnabledTimers[NO].callback!=NULL)
			CallbackArray[6]=EnabledTimers[NO].callback;
}
void Channel7_Handler (u8 NO,const GptChannelConfigSet* EnabledTimers){
		u8 prescaller;
		RCGCWTIMER|=0x02;			 //enable clk 
		GPTMCtrl7A=0x00;			 //Disable Timer
		GPTMCFG7A=0x04;	 			 //set TimerA 16 bit 0x04,
		if(EnabledTimers[NO].GptCahnnelMode==GPT_CH_MODE_CONTINUOUS)
			GPTMTAMR7A=0x02;			 //cont mode
		else 
			GPTMTAMR7A=0x01;			 //cont mode						
		GPTMICR7A|=0x01;			 //interrupt control
		prescaller=16/EnabledTimers[NO].GptChannelTickFrequency;
		GPTMTAPR7A=prescaller;
		if (EnabledTimers[NO].callback!=NULL)
			CallbackArray[7]=EnabledTimers[NO].callback;
}

void Channel8A_Handler (u8 NO,const GptChannelConfigSet* EnabledTimers){
		u8 prescaller;
		RCGCWTIMER|=0x04;			 //enable clk 
		GPTMCtrl8A=0x00;			 //Disable Timer
		GPTMCFG8A=0x04;	 			 //set TimerA 16 bit 0x04,
		if(EnabledTimers[NO].GptCahnnelMode==GPT_CH_MODE_CONTINUOUS)
			GPTMTAMR8A=0x02;			 //cont mode
		else 
			GPTMTAMR8A=0x01;			 //cont mode						
		GPTMICR8A|=0x01;			 //interrupt control
		prescaller=16/EnabledTimers[NO].GptChannelTickFrequency;
		GPTMTAPR8A=prescaller;
		if (EnabledTimers[NO].callback!=NULL)
			CallbackArray[8]=EnabledTimers[NO].callback;
}

void Channel9A_Handler (u8 NO,const GptChannelConfigSet* EnabledTimers){
		u8 prescaller;
		RCGCWTIMER|=0x08;			 //enable clk 
		GPTMCtrl9A=0x00;			 //Disable Timer
		GPTMCFG9A=0x04;	 			 //set TimerA 16 bit 0x04,
		if(EnabledTimers[NO].GptCahnnelMode==GPT_CH_MODE_CONTINUOUS)
			GPTMTAMR9A=0x02;			 //cont mode
		else 
			GPTMTAMR9A=0x01;			 //cont mode						
		GPTMICR9A|=0x01;			 //interrupt control
		prescaller=16/EnabledTimers[NO].GptChannelTickFrequency;
		GPTMTAPR9A=prescaller;
		if (EnabledTimers[NO].callback!=NULL)
			CallbackArray[9]=EnabledTimers[NO].callback;
}
void Channel10A_Handler (u8 NO,const GptChannelConfigSet* EnabledTimers){
		u8 prescaller;
		RCGCWTIMER|=0x10;			 //enable clk 
		GPTMCtrl10A=0x00;			 //Disable Timer
		GPTMCFG10A=0x04;	 			 //set TimerA 16 bit 0x04,
		if(EnabledTimers[NO].GptCahnnelMode==GPT_CH_MODE_CONTINUOUS)
			GPTMTAMR10A=0x02;			 //cont mode
		else 
			GPTMTAMR10A=0x01;			 //cont mode						
		GPTMICR10A|=0x01;			 //interrupt control
		prescaller=16/EnabledTimers[NO].GptChannelTickFrequency;
		GPTMTAPR10A=prescaller;
		if (EnabledTimers[NO].callback!=NULL)
			CallbackArray[10]=EnabledTimers[NO].callback;
}
void Channel11A_Handler (u8 NO,const GptChannelConfigSet* EnabledTimers){
		u8 prescaller;
		RCGCWTIMER|=0x20;			 //enable clk 
		GPTMCtrl11A=0x00;			 //Disable Timer
		GPTMCFG11A=0x04;	 			 //set TimerA 16 bit 0x04,
		if(EnabledTimers[NO].GptCahnnelMode==GPT_CH_MODE_CONTINUOUS)
			GPTMTAMR11A=0x02;			 //cont mode
		else 
			GPTMTAMR11A=0x01;			 //cont mode						
		GPTMICR11A|=0x01;			 //interrupt control
		prescaller=16/EnabledTimers[NO].GptChannelTickFrequency;
		GPTMTAPR11A=prescaller;
		if (EnabledTimers[NO].callback!=NULL)
			CallbackArray[11]=EnabledTimers[NO].callback;
}
/*****************************************************************************************************************************************/
/************************************************Get Time elapsed***********************************************************************/
u32 Gpt_GetTimeElapsed(Gpt_ChannelType ChannelID){
		switch(ChannelID){
			case Channel0:	
				 		return GPTMTAR0*GPTMTAPR0A;
				case Channel1:
						return GPTMTAR1*GPTMTAPR1A; 										 			
				case Channel2:
						return GPTMTAR2*GPTMTAPR2A; 										 						
				case Channel3:
						return GPTMTAR3*GPTMTAPR3A; 										 
				case Channel4:
						return GPTMTAR4*GPTMTAPR4A;										 
				case Channel5:
						return GPTMTAR5*GPTMTAPR5A; 										 
				case Channel6:
						return GPTMTAR6*GPTMTAPR6A; 										 
				case Channel7:
						return GPTMTAR7*GPTMTAPR7A; 										 
				case Channel8:
						return GPTMTAR8*GPTMTAPR8A; 										 
				case Channel9:
						return GPTMTAR9*GPTMTAPR9A; 										 
				case Channel10:
						return GPTMTAR10*GPTMTAPR10A; 									 
				case Channel11:
						return GPTMTAR11*GPTMTAPR11A; 										 
			}
}

u32 Gpt_GetTimeRemaining(Gpt_ChannelType ChannelID){
		switch(ChannelID){
			case Channel0:	
				 		return (GPTMTAILR0A-GPTMTAR0)*GPTMTAPR0A;
				case Channel1:
						return  (GPTMTAILR1A-GPTMTAR1)*GPTMTAPR0A; 										 			
				case Channel2:
						return  (GPTMTAILR2A-GPTMTAR2)*GPTMTAPR0A; 										 
				case Channel3:
						return  (GPTMTAILR3A-GPTMTAR3)*GPTMTAPR0A; 										 
				case Channel4:
						return  (GPTMTAILR4A-GPTMTAR4)*GPTMTAPR0A;										 
				case Channel5:
						return  (GPTMTAILR5A-GPTMTAR5)*GPTMTAPR0A; 										 
				case Channel6:
						return  (GPTMTAILR6A-GPTMTAR6)*GPTMTAPR0A; 										 
				case Channel7:
						return  (GPTMTAILR7A-GPTMTAR7)*GPTMTAPR0A; 										 
				case Channel8:
						return  (GPTMTAILR8A-GPTMTAR8)*GPTMTAPR0A; 										 
				case Channel9:
						return  (GPTMTAILR9A-GPTMTAR9)*GPTMTAPR0A; 										 
				case Channel10:
						return  (GPTMTAILR10A-GPTMTAR10)*GPTMTAPR0A; 									 
				case Channel11:
						return  (GPTMTAILR11A-GPTMTAR11)*GPTMTAPR0A; 										 
			}
}

Std_RET Gpt_GetPredefTimerValue(Gpt_ConfigType PreDefTimer,u32* value){
	#if (PredefTimer_Enable==0)
			return  E_NOT_Ok;
	#else
		switch(PreDefTimer){
			case GPT_PREDEF_TIMER_1US_16BIT:	
						*value=GPTMTAR0*GPTMTAPR0A;
						return  E_Ok; 										 			
				case GPT_PREDEF_TIMER_1US_32BIT:
						*value=GPTMTAR6*GPTMTAPR6A;
						return  E_Ok; 				 										 						
				case GPT_PREDEF_TIMER_100US_32BIT:
						*value=GPTMTAR6*GPTMTAPR6A;
						return  E_Ok; 											 										 
			}
	#endif
}

void Gpt_EnableNotification(Gpt_ChannelType ChannelID){
		switch(ChannelID){
			case Channel0:
							GPTMIMR0A=0x01;
				 		break;
				case Channel1:
							GPTMIMR1A=0x01;
						break; 										 			
				case Channel2:
							GPTMIMR2A=0x01;
						break; 										 
				case Channel3:
							GPTMIMR3A=0x01;
						break; 										 
				case Channel4:
							GPTMIMR4A=0x01;
						break;										 
				case Channel5:
							GPTMIMR5A=0x01;
						break; 										 
				case Channel6:
							GPTMIMR6A=0x01;
						break; 									 
				case Channel7:
							GPTMIMR7A=0x01;
						break; 										 
				case Channel8:
							GPTMIMR8A=0x01;
						break;										 
				case Channel9:
							GPTMIMR9A=0x01;
						break; 										 
				case Channel10:
							GPTMIMR10A=0x01;
						break;									 
				case Channel11:
							GPTMIMR11A=0x01;
						break; 										 
			}
}
void Gpt_DisableNotification(Gpt_ChannelType ChannelID){
		switch(ChannelID){
			case Channel0:
							GPTMIMR0A=0x00;
				 		break;
				case Channel1:
							GPTMIMR1A=0x00;
						break; 										 			
				case Channel2:
							GPTMIMR2A=0x00;
						break; 										 
				case Channel3:
							GPTMIMR3A=0x00;
						break; 										 
				case Channel4:
							GPTMIMR4A=0x00;
						break;										 
				case Channel5:
							GPTMIMR5A=0x00;
						break; 										 
				case Channel6:
							GPTMIMR6A=0x00;
						break; 									 
				case Channel7:
							GPTMIMR7A=0x00;
						break; 										 
				case Channel8:
							GPTMIMR8A=0x00;
						break;										 
				case Channel9:
							GPTMIMR9A=0x00;	
						break; 										 
				case Channel10:
							GPTMIMR10A=0x00;
						break;									 
				case Channel11:
							GPTMIMR11A=0x00;
						break; 										 
			}
}

void TIMER0A_Handler(void){
	CallbackArray[0]();
	GPTMICR0A=0x1;
}

void TIMER1A_Handler(void){
	CallbackArray[1]();
	GPTMICR1A=0x1;
}

void TIMER2A_Handler(void){
	CallbackArray[2]();
	GPTMICR2A=0x1;
}

void TIMER3A_Handler(void){
	CallbackArray[3]();
	GPTMICR3A=0x1;
}

void TIMER4A_Handler(void){
	CallbackArray[4]();
	GPTMICR4A=0x1;
}

void TIMER5A_Handler(void){
	CallbackArray[5]();
	GPTMICR5A=0x1;
}

void TIMER6A_Handler(void){
	CallbackArray[6]();
	GPTMICR6A=0x1;
}

void TIMER7A_Handler(void){
	CallbackArray[7]();
	GPTMICR7A=0x1;
}

void TIMER8A_Handler(void){
	CallbackArray[8]();
	GPTMICR8A=0x1;
}

void TIMER9A_Handler(void){
	CallbackArray[9]();
	GPTMICR9A=0x1;
}

void TIMER10A_Handler(void){
	CallbackArray[10]();
	GPTMICR10A=0x1;
}

void TIMER11A_Handler(void){
	CallbackArray[11]();
	GPTMICR11A=0x1;
}
/**********************************************************************************************************************
 *  END OF FILE: Timer.c	
 *********************************************************************************************************************/

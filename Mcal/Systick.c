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
#include "Systick.h"
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
void IntSystick_Init(void)
{
	#if (Clk_Source == 1) // mainOsc
		RCC&=~(1<<OSCSRC); 								 //select main osc mode
		RCC|=0x01; 									 //enable main osc
		extern divisor Div;					 // scalling frequency
    extern Main_Osc_Value freq ; //main osc freq
		RCC|=	(freq<<XTAL);
		RCC|= (Div<<SYSDIV);
		#if(PLL_Enable==1) //PLL enabled
			RCC&=~(1<<BYPASS);	 //bypass=0
			RCC&=~(1<<PWRDN);	 //powerdown 
		#else 						 //PLL disabled
			RCC|=(1<<BYPASS); 	 //bypass=1
			RCC|=(1<<PWRDN);	   //pll powerdown 
		#endif
	#else//intenalOsc
		RCC|=(1<<4); 								 //select internalosc mode
		#if(PLL_Enable==1) 	//PLL enabled
			RCC&=~(1<<BYPASS);	 //bypass=0
			RCC&=~(1<<PWRDN);	 //powerdown 
		#else 							//PLL disabled
			RCC|=(1<<BYPASS); 	 //bypass=1
			RCC|=(1<<PWRDN);	   //pll powerdown
			RCC|= (0<<SYSDIV);
		#endif
			
	#endif

}

/**********************************************************************************************************************
 *  END OF FILE: Systick.c
 *********************************************************************************************************************/

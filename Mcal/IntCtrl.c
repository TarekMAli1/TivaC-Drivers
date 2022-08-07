
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Register.h"
#include "IntCtrl_Cfg.h"
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
void IntCrtl_Init(void)
{
   extern struct Int_Pri Interrupt_Pri[No_Of_Interrupts];
	 extern u8 EnabledInterrupt[No_Of_Interrupts];
  u8 Int_No,RegIndex,InterruptLocation,BitLocation;
	u32 var;
	 u32 Int_Pri;
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
	#if (Group_Mode == 0)	
	  APINT = (0xFA05<<16)|(0x0000);
	#elif(Group_Mode == 1)	
		APINT = (0xFA05<<16)|(0x0500);
	#elif(Group_Mode == 2)	
		APINT = (0xFA05<<16)|(0x0600);
	#elif(Group_Mode == 3)	
		APINT = (0xFA05<<16)|(0x0700);
	#endif
  /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
			for(u8 i=0;i<No_Of_Interrupts;i++){
				Int_No=Interrupt_Pri[i].Int_No;
				Int_Pri=(u32)Interrupt_Pri[i].Int_pri;
				RegIndex=Int_No/4;
				BitLocation=((Int_No%4)*8)+5;
				var =(Int_Pri<<BitLocation);
				Priority->Pri[RegIndex]|=var;
			}
	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
			for(u8 j=0;j<No_Of_Interrupts;j++){
				Int_No=EnabledInterrupt[j];
				InterruptLocation=Int_No/32;
				BitLocation=Int_No%32;
				Enable->EN[InterruptLocation]|=(1<<BitLocation);
			}
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
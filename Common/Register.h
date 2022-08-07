/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef REGISTER_H
#define REGISTER_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    u32 VECACT   :8;
    u32          :3;
    u32 RETBASE  :1;
    u32 VECPEND  :8;
    u32 ISRPEND  :1;
    u32 ISRPRE   :1;
    u32          :1;
    u32 PENDSTCLR:1;
    u32 PENDSTSET:1;
    u32 UNPENDSV :1;
    u32 PENDSV   :1;
    u32          :2;
    u32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    u32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

typedef struct{
	u32 EN[5];
}Enable_t;
typedef struct{
	u32 DIS[5];	
}Disable_t;
typedef struct{
	u32 PEN[5];
}Pend_t;
typedef struct{
	u32 UNPEN[5];
}UNPend_t;
typedef struct{
	u32 ACT[5];	
}Active_t;
typedef struct{
	u32 Pri[35];	
}Priority_t;
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS            		 0xE000E000
#define Enable 			                              ((volatile Enable_t*)0xE000E100)
#define Disable 			                            ((volatile Disable_t*)0xE000E180)
#define Pend 			                                ((volatile Pend_t*)0xE000E200)
#define UNPend 			                              ((volatile UNPend_t*)0xE000E280)
#define Active																		((volatile Active_t*)0xE000E300)
#define Priority														   		((volatile Priority_t*)0xE000E400)	
#define SWTRIG 													         *((volatile u32* const)(CORTEXM4_PERI_BASE_ADDRESS+0xF00))
#define VTABLE 																 ``*((volatile u32* const)(CORTEXM4_PERI_BASE_ADDRESS+0xD08))
#define SYSPRI1 																 *((volatile u32* const)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
#define SYSPRI2 																 *((volatile u32* const)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
#define SYSPRI3 																 *((volatile u32* const)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))
#define APINT                             	     *((volatile u32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
	
#define RCC_BASE_ADDRESS                      0x400FE060
#define RCC                                  *((volatile u32*)(RCC_BASE_ADDRESS))

/**********************************************DIO registers******************************************************/
#define RCGCGPIO 													       *((volatile u32* const)( 0x400FE608))
/***********************************************Diraction**************************************************/
#define DirectionOffset 													0x400
#define GPIODIRA																   *((volatile u32* const)( 0x40004000+DirectionOffset))
#define GPIODIRB																   *((volatile u32* const)( 0x40005000+DirectionOffset))
#define GPIODIRC																   *((volatile u32* const)( 0x40006000+DirectionOffset))
#define GPIODIRD																   *((volatile u32* const)( 0x40007000+DirectionOffset))
#define GPIODIRE																   *((volatile u32* const)( 0x40024000+DirectionOffset))
#define GPIODIRF																   *((volatile u32* const)( 0x40025000+DirectionOffset))
/*********************************************GPIODATAReg***************************************************/
#define DataOffset																
#define GPIODATAA																    0x40004000
#define GPIODATAB																    0x40005000
#define GPIODATAC															 	 	  0x40006000
#define GPIODATAD															 	 	  0x40007000
#define GPIODATAE															  	  0x40024000
#define GPIODATAF															  	  0x40025000
/**********************************************GPIODEN****************************************************************/
#define DigitalOffset																0x51C
#define GPIODENA																    *((volatile u32* const)( 0x40004000+DigitalOffset))
#define GPIODENB																    *((volatile u32* const)( 0x40005000+DigitalOffset))
#define GPIODENC																    *((volatile u32* const)( 0x40006000+DigitalOffset))
#define GPIODEND																    *((volatile u32* const)( 0x40007000+DigitalOffset))
#define GPIODENE																    *((volatile u32* const)( 0x40024000+DigitalOffset))
#define GPIODENF																    *((volatile u32* const)( 0x40025000+DigitalOffset))
/************************************************TIMERS**************************************************************************/
#define RCGCTIMER																    *((volatile u32* const)(0x400FE604))
#define RCGCWTIMER																	*((volatile u32* const)(0x400FE65C))	
	


#define TIMER0A_BASE_ADD															  0x40030000
#define GPTMCFG0A																			*((volatile u32* const)(TIMER0A_BASE_ADD))
#define GPTMCtrl0A																		*((volatile u32* const)(TIMER0A_BASE_ADD+0x00C))
#define GPTMTAMR0A																		*((volatile u32* const)(TIMER0A_BASE_ADD+0x004))
#define GPTMTAPR0A 																		*((volatile u32* const)(TIMER0A_BASE_ADD+0x038))
#define GPTMTAILR0A 																	*((volatile u32* const)(TIMER0A_BASE_ADD+0x028))
#define GPTMIMR0A 															   		*((volatile u32* const)(TIMER0A_BASE_ADD+0x018))
#define GPTMICR0A 															   		*((volatile u32* const)(TIMER0A_BASE_ADD+0x024))	
#define GPTMMIS0A 															   		*((volatile u32* const)(TIMER0A_BASE_ADD+0x020))
#define GPTMRIS0A 															   		*((volatile u32* const)(TIMER0A_BASE_ADD+0x01C))
#define GPTMTAR0 															   		  *((volatile u32* const)(TIMER0A_BASE_ADD+0x048))	

#define TIMER1A_BASE_ADD															  0x40031000
#define GPTMCFG1A																			*((volatile u32* const)(TIMER1A_BASE_ADD))
#define GPTMCtrl1A																		*((volatile u32* const)(TIMER1A_BASE_ADD+0x00C))
#define GPTMTAMR1A																		*((volatile u32* const)(TIMER1A_BASE_ADD+0x004))
#define GPTMTAPR1A 																		*((volatile u32* const)(TIMER1A_BASE_ADD+0x038))
#define GPTMTAILR1A 																	*((volatile u32* const)(TIMER1A_BASE_ADD+0x028))
#define GPTMIMR1A 															   		*((volatile u32* const)(TIMER1A_BASE_ADD+0x018))
#define GPTMICR1A 															   		*((volatile u32* const)(TIMER1A_BASE_ADD+0x024))	
#define GPTMMIS1A 															   		*((volatile u32* const)(TIMER1A_BASE_ADD+0x020))
#define GPTMRIS1A 															   		*((volatile u32* const)(TIMER1A_BASE_ADD+0x01C))
#define GPTMTAR1															   		  *((volatile u32* const)(TIMER1A_BASE_ADD+0x048))

#define TIMER2A_BASE_ADD															  0x40032000
#define GPTMCFG2A																			*((volatile u32* const)(TIMER2A_BASE_ADD))
#define GPTMCtrl2A																		*((volatile u32* const)(TIMER2A_BASE_ADD+0x00C))
#define GPTMTAMR2A																		*((volatile u32* const)(TIMER2A_BASE_ADD+0x004))
#define GPTMTAPR2A 																		*((volatile u32* const)(TIMER2A_BASE_ADD+0x038))
#define GPTMTAILR2A 																	*((volatile u32* const)(TIMER2A_BASE_ADD+0x028))
#define GPTMIMR2A 															   		*((volatile u32* const)(TIMER2A_BASE_ADD+0x018))
#define GPTMICR2A 															   		*((volatile u32* const)(TIMER2A_BASE_ADD+0x024))	
#define GPTMMIS2A 															   		*((volatile u32* const)(TIMER2A_BASE_ADD+0x020))
#define GPTMRIS2A 															   		*((volatile u32* const)(TIMER2A_BASE_ADD+0x01C))
#define GPTMTAR2															   		  *((volatile u32* const)(TIMER2A_BASE_ADD+0x048))
	
#define TIMER3A_BASE_ADD															  0x40033000
#define GPTMCFG3A																		  *((volatile u32* const)(TIMER3A_BASE_ADD))
#define GPTMCtrl3A																		*((volatile u32* const)(TIMER3A_BASE_ADD+0x00C))
#define GPTMTAMR3A																		*((volatile u32* const)(TIMER3A_BASE_ADD+0x004))
#define GPTMTAPR3A 																		*((volatile u32* const)(TIMER3A_BASE_ADD+0x038))
#define GPTMTAILR3A 																	*((volatile u32* const)(TIMER3A_BASE_ADD+0x028))
#define GPTMIMR3A 															   		*((volatile u32* const)(TIMER3A_BASE_ADD+0x018))
#define GPTMICR3A 															   		*((volatile u32* const)(TIMER3A_BASE_ADD+0x024))	
#define GPTMMIS3A 															   		*((volatile u32* const)(TIMER3A_BASE_ADD+0x020))
#define GPTMRIS3A 															   		*((volatile u32* const)(TIMER3A_BASE_ADD+0x01C))
#define GPTMTAR3															   		  *((volatile u32* const)(TIMER3A_BASE_ADD+0x048))	

#define TIMER4A_BASE_ADD															  0x40034000
#define GPTMCFG4A																			*((volatile u32* const)(TIMER4A_BASE_ADD))
#define GPTMCtrl4A																		*((volatile u32* const)(TIMER4A_BASE_ADD+0x00C))
#define GPTMTAMR4A																		*((volatile u32* const)(TIMER4A_BASE_ADD+0x004))
#define GPTMTAPR4A 																		*((volatile u32* const)(TIMER4A_BASE_ADD+0x038))
#define GPTMTAILR4A 																	*((volatile u32* const)(TIMER4A_BASE_ADD+0x028))
#define GPTMIMR4A 															   		*((volatile u32* const)(TIMER4A_BASE_ADD+0x018))
#define GPTMICR4A 															   		*((volatile u32* const)(TIMER4A_BASE_ADD+0x024))	
#define GPTMMIS4A 															   		*((volatile u32* const)(TIMER4A_BASE_ADD+0x020))
#define GPTMRIS4A 															   		*((volatile u32* const)(TIMER4A_BASE_ADD+0x01C))
#define GPTMTAR4															   		  *((volatile u32* const)(TIMER4A_BASE_ADD+0x048))
	
#define TIMER5A_BASE_ADD															  0x40035000
#define GPTMCFG5A																			*((volatile u32* const)(TIMER5A_BASE_ADD))
#define GPTMCtrl5A																		*((volatile u32* const)(TIMER5A_BASE_ADD+0x00C))
#define GPTMTAMR5A																		*((volatile u32* const)(TIMER5A_BASE_ADD+0x004))
#define GPTMTAPR5A 																		*((volatile u32* const)(TIMER5A_BASE_ADD+0x038))
#define GPTMTAILR5A 																	*((volatile u32* const)(TIMER5A_BASE_ADD+0x028))
#define GPTMIMR5A 															   		*((volatile u32* const)(TIMER5A_BASE_ADD+0x018))
#define GPTMICR5A 															   		*((volatile u32* const)(TIMER5A_BASE_ADD+0x024))	
#define GPTMMIS5A 															   		*((volatile u32* const)(TIMER5A_BASE_ADD+0x020))
#define GPTMRIS5A 															   		*((volatile u32* const)(TIMER5A_BASE_ADD+0x01C))
#define GPTMTAR5															   		  *((volatile u32* const)(TIMER5A_BASE_ADD+0x048))

#define TIMER6A_BASE_ADD															  0x40036000
#define GPTMCFG6A																			*((volatile u32* const)(TIMER6A_BASE_ADD))
#define GPTMCtrl6A																		*((volatile u32* const)(TIMER6A_BASE_ADD+0x00C))
#define GPTMTAMR6A																		*((volatile u32* const)(TIMER6A_BASE_ADD+0x004))
#define GPTMTAPR6A 																		*((volatile u32* const)(TIMER6A_BASE_ADD+0x038))
#define GPTMTAILR6A 																	*((volatile u32* const)(TIMER6A_BASE_ADD+0x028))
#define GPTMIMR6A 															   		*((volatile u32* const)(TIMER6A_BASE_ADD+0x018))
#define GPTMICR6A 															   		*((volatile u32* const)(TIMER6A_BASE_ADD+0x024))	
#define GPTMMIS6A 															   		*((volatile u32* const)(TIMER6A_BASE_ADD+0x020))
#define GPTMRIS6A 															   		*((volatile u32* const)(TIMER6A_BASE_ADD+0x01C))
#define GPTMTAR6															   		  *((volatile u32* const)(TIMER6A_BASE_ADD+0x048))
	
#define TIMER7A_BASE_ADD															  0x40037000
#define GPTMCFG7A																		  *((volatile u32* const)(TIMER7A_BASE_ADD))
#define GPTMCtrl7A																		*((volatile u32* const)(TIMER7A_BASE_ADD+0x00C))
#define GPTMTAMR7A																		*((volatile u32* const)(TIMER7A_BASE_ADD+0x004))
#define GPTMTAPR7A 																		*((volatile u32* const)(TIMER7A_BASE_ADD+0x038))
#define GPTMTAILR7A 																	*((volatile u32* const)(TIMER7A_BASE_ADD+0x028))
#define GPTMIMR7A 															   		*((volatile u32* const)(TIMER7A_BASE_ADD+0x018))
#define GPTMICR7A 															   		*((volatile u32* const)(TIMER7A_BASE_ADD+0x024))	
#define GPTMMIS7A 															   		*((volatile u32* const)(TIMER7A_BASE_ADD+0x020))
#define GPTMRIS7A 															   		*((volatile u32* const)(TIMER7A_BASE_ADD+0x01C))
#define GPTMTAR7															   		  *((volatile u32* const)(TIMER7A_BASE_ADD+0x048))
	
#define TIMER8A_BASE_ADD															  0x4004C000
#define GPTMCFG8A																			*((volatile u32* const)(TIMER8A_BASE_ADD))
#define GPTMCtrl8A																		*((volatile u32* const)(TIMER8A_BASE_ADD+0x00C))
#define GPTMTAMR8A																		*((volatile u32* const)(TIMER8A_BASE_ADD+0x004))
#define GPTMTAPR8A 																		*((volatile u32* const)(TIMER8A_BASE_ADD+0x038))
#define GPTMTAILR8A 																	*((volatile u32* const)(TIMER8A_BASE_ADD+0x028))
#define GPTMIMR8A 															   		*((volatile u32* const)(TIMER8A_BASE_ADD+0x018))
#define GPTMICR8A 															   		*((volatile u32* const)(TIMER8A_BASE_ADD+0x024))	
#define GPTMMIS8A 															   		*((volatile u32* const)(TIMER8A_BASE_ADD+0x020))
#define GPTMRIS8A 															   		*((volatile u32* const)(TIMER8A_BASE_ADD+0x01C))
#define GPTMTAR8															   		  *((volatile u32* const)(TIMER8A_BASE_ADD+0x048))
	
#define TIMER9A_BASE_ADD															  0x4004D000
#define GPTMCFG9A																		  *((volatile u32* const)(TIMER9A_BASE_ADD))
#define GPTMCtrl9A																		*((volatile u32* const)(TIMER9A_BASE_ADD+0x00C))
#define GPTMTAMR9A																		*((volatile u32* const)(TIMER9A_BASE_ADD+0x004))
#define GPTMTAPR9A 																		*((volatile u32* const)(TIMER9A_BASE_ADD+0x038))
#define GPTMTAILR9A																  	*((volatile u32* const)(TIMER9A_BASE_ADD+0x028))
#define GPTMIMR9A 															   		*((volatile u32* const)(TIMER9A_BASE_ADD+0x018))
#define GPTMICR9A 															   		*((volatile u32* const)(TIMER9A_BASE_ADD+0x024))	
#define GPTMMIS9A 															   		*((volatile u32* const)(TIMER9A_BASE_ADD+0x020))
#define GPTMRIS9A 															   		*((volatile u32* const)(TIMER9A_BASE_ADD+0x01C))
#define GPTMTAR9															   		  *((volatile u32* const)(TIMER9A_BASE_ADD+0x048))
	
#define TIMER10A_BASE_ADD															  0x4004E000
#define GPTMCFG10A																		*((volatile u32* const)(TIMER10A_BASE_ADD))
#define GPTMCtrl10A																		*((volatile u32* const)(TIMER10A_BASE_ADD+0x00C))
#define GPTMTAMR10A																		*((volatile u32* const)(TIMER10A_BASE_ADD+0x004))
#define GPTMTAPR10A 																	*((volatile u32* const)(TIMER10A_BASE_ADD+0x038))
#define GPTMTAILR10A 																	*((volatile u32* const)(TIMER10A_BASE_ADD+0x028))
#define GPTMIMR10A 															   		*((volatile u32* const)(TIMER10A_BASE_ADD+0x018))
#define GPTMICR10A 															   		*((volatile u32* const)(TIMER10A_BASE_ADD+0x024))	
#define GPTMMIS10A 															   		*((volatile u32* const)(TIMER10A_BASE_ADD+0x020))
#define GPTMRIS10A 															   		*((volatile u32* const)(TIMER10A_BASE_ADD+0x01C))
#define GPTMTAR10															   		  *((volatile u32* const)(TIMER10A_BASE_ADD+0x048))
	
#define TIMER11A_BASE_ADD															  0x4004F000
#define GPTMCFG11A																		*((volatile u32* const)(TIMER11A_BASE_ADD))
#define GPTMCtrl11A																		*((volatile u32* const)(TIMER11A_BASE_ADD+0x00C))
#define GPTMTAMR11A																		*((volatile u32* const)(TIMER11A_BASE_ADD+0x004))
#define GPTMTAPR11A 																	*((volatile u32* const)(TIMER11A_BASE_ADD+0x038))
#define GPTMTAILR11A 																	*((volatile u32* const)(TIMER11A_BASE_ADD+0x028))
#define GPTMIMR11A 															   		*((volatile u32* const)(TIMER11A_BASE_ADD+0x018))
#define GPTMICR11A 															   		*((volatile u32* const)(TIMER11A_BASE_ADD+0x024))	
#define GPTMMIS11A 															   		*((volatile u32* const)(TIMER11A_BASE_ADD+0x020))
#define GPTMRIS11A 															   		*((volatile u32* const)(TIMER11A_BASE_ADD+0x01C))
#define GPTMTAR11															   		  *((volatile u32* const)(TIMER11A_BASE_ADD+0x048))







/**********************************************CurrentConfig*******************************************************************/
/*#define CurrentOffset																0x500
#define GPIODR2R																	((volatile u32* const)( 0x40004000+DigitalOffset))
#define GPIODR4R																	((volatile u32* const)( 0x40004000+DigitalOffset+0x004))	
#define GPIODR8R																	((volatile u32* const)( 0x40004000+DigitalOffset+0x008))	*/
/*
#define INTCTRL                                *(((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04)))
#define EN0																		 *((volatile u32* const)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define DIS0 																	 *((volatile u32* const)(CORTEXM4_PERI_BASE_ADDRESS+))
#define PEND0 																 *((volatile u32* const)(CORTEXM4_PERI_BASE_ADDRESS+0x200))
#define UNPEND0 															 *((volatile u32* const)(CORTEXM4_PERI_BASE_ADDRESS+0x280))
#define ACTIVE0 															 *((volatile u32* const)(CORTEXM4_PERI_BASE_ADDRESS+0x300))
#define PRI0 																   *((volatile u32* const)(CORTEXM4_PERI_BASE_ADDRESS+0x400))*/
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* REGISTER_H */

/**********************************************************************************************************************
 *  END OF FILE: Registers.h
 *********************************************************************************************************************/
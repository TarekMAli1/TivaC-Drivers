/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Systick_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_H
#define SYSTICK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/*
		for internalosc clkSource = 0 
		for mainosc clkSource = 1
*/
#define Clk_Source 0
/* PLL_Enable 0 => disabled 
	 PLL_Enable 1 => enabled
*/
#define PLL_Enable 0



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
	Div2 = 0x02,
	Div3,
	Div4,
	Div5,
	Div6,
	Div7,
	Div8,
	Div9,
	Div10,
	Div11,
	Div12,
	Div13,
	Div14,
	Div15,
	Div16   	//default	
}divisor;
typedef enum {
	freq1=0x06,
	freq2,  //4 MHz
	freq3,  // 4.069 MHz
	freq4,  // 4.9152 MHz
	freq5,  // 5 MHz
	freq6,  // 5.12 MHz
	freq7,  // 6 MHz
	freq8,  // 6.144 MHz
	freq9,  // 7.3728  MHz
	freq10, // 8 MHz
	freq11, // 8.192 MHz
	freq12, // 10 MHz
	freq13, // 12 MHz
	freq14, // 12.288 MHz
	freq15, // 13.56 MHz
	freq16, // 14.31818 MHz
	freq17, // 16.0 MHz
	freq18, // 16.384 MHz
	freq19, // 18 MHz
	freq20, // 20 MHz
	freq21, //22 MHz
	freq22, // 24 MHz
	freq23  // 25 MHz
}Main_Osc_Value;

divisor Div = Div2;
Main_Osc_Value freq = freq2;

 
#endif  /* SYSTICK_H */

/**********************************************************************************************************************
 *  END OF FILE: Systick.h
 *********************************************************************************************************************/

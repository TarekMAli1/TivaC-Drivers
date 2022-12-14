/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_CFG_H
#define DIO_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

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
	channel0=0,
  channel1,
  channel2,
  channel3,
	channel4,
	channel5,
	channel6,
	channel7
}Dio_ChannelType;

typedef enum {
	PortA=0,
  PortB,
  PortC,
  PortD,
	PortE,
	PortF
}Dio_PortType;

typedef enum {
	Low_Level=0,
	High_Level
}Dio_LevelType;
/*
	
	A=>PortA
	B=>PortB
	C=>PortC
	D=>PortD
	E=>PortE
	F=>PortF
*/
#define Port 'F'
/*
	GPIODR2R=> 2ma
	GPIODR4R=> 4ma
	GPIODR4R=> 8ma
*/
#define Current GPIODR2R

#endif  /* DIO_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Cfg.h
 *********************************************************************************************************************/
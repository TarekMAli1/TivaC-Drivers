
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Digital input output driver Driver
 *
 *      \details  The Driver Configure All MCU GPIOs
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"
#include "Register.h"
#include "Dio_Cfg.h"
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
void Dio_WriteChannel (u8 ChannelId, Dio_LevelType Level )
{
	u16 offset=(1<<(ChannelId+2));//0x0004
	switch(Port){
		case 'A' :
			setBit(RCGCGPIO,0);
			setBit(GPIODIRA,ChannelId);
			setBit(GPIODENA,ChannelId);
			if(Level==High_Level) 
				*((volatile u32* const)(GPIODATAA+offset))=(1<<ChannelId);
			else
				*((volatile u32* const)(GPIODATAA+offset))=(0<<ChannelId);
			break;
		case 'B' :
			setBit(RCGCGPIO,1);
			setBit(GPIODIRB,ChannelId);
		  setBit(GPIODENB,ChannelId);
			if(Level==High_Level) 
				*((volatile u32* const)(GPIODATAB+offset))=(1<<ChannelId);
			else
				*((volatile u32* const)(GPIODATAB+offset))=(0<<ChannelId);
			break;
		case 'C' :
			setBit(RCGCGPIO,2);
		  setBit(GPIODENC,ChannelId);
			setBit(GPIODIRC,ChannelId);
			if(Level==High_Level) 
				*((volatile u32* const)(GPIODATAC+offset))=(1<<ChannelId);
			else
				*((volatile u32* const)(GPIODATAC+offset))=(0<<ChannelId);
			break;
		case 'D' :
			setBit(RCGCGPIO,3);
		  setBit(GPIODEND,ChannelId);
			setBit(GPIODIRD,ChannelId);
			if(Level==High_Level) 
				*((volatile u32* const)(GPIODATAD+offset))=(1<<ChannelId);
			else
				*((volatile u32* const)(GPIODATAD+offset))=(0<<ChannelId);
			break;
		case 'E' :
			setBit(RCGCGPIO,4);
			setBit(GPIODENE,ChannelId);
			setBit(GPIODIRE,ChannelId);
			if(Level==High_Level) 
				*((volatile u32* const)(GPIODATAE+offset))=(1<<ChannelId);
			else
				*((volatile u32* const)(GPIODATAE+offset))=(0<<ChannelId);
			 break;
		case 'F' :
			setBit(RCGCGPIO,5);
			setBit(GPIODENF,ChannelId);
			setBit(GPIODIRF,ChannelId);
			if(Level==High_Level) 
				*((volatile u32* const)(GPIODATAF+offset))=(1<<ChannelId);
			else
				*((volatile u32* const)(GPIODATAF+offset))=(0<<ChannelId);
			 break;
	}
}
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
	volatile u8 val;
	u16 offset=(1<<(ChannelId+2));
	switch(Port){
		case 'A' :
			setBit(RCGCGPIO,0);
			setBit(GPIODENA,ChannelId);
			resetBit(GPIODIRA,ChannelId);
			if ( *((volatile u32* const)(GPIODATAA+offset))>>ChannelId==1)
				return High_Level;
			else 
				return Low_Level;
		case 'B' :
			setBit(RCGCGPIO,1);
			resetBit(GPIODIRB,ChannelId);
		  setBit(GPIODENB,ChannelId);
			if ( *((volatile u32* const)(GPIODATAB+offset))>>ChannelId==1)
				return High_Level;
			else 
				return Low_Level;
		case 'C' :
			setBit(RCGCGPIO,2);
		  resetBit(GPIODENC,ChannelId);
			setBit(GPIODIRC,ChannelId);
			 if ( *((volatile u32* const)(GPIODATAC+offset))>>ChannelId==1)
				return High_Level;
			else 
				return Low_Level;
		case 'D' :
			setBit(RCGCGPIO,3);
		  setBit(GPIODEND,ChannelId);
			resetBit(GPIODIRD,ChannelId);
			if ( *((volatile u32* const)(GPIODATAD+offset))>>ChannelId==1)
				return High_Level;
			else 
				return Low_Level;
		case 'E' :
			setBit(RCGCGPIO,4);
			setBit(GPIODENE,ChannelId);
			resetBit(GPIODIRE,ChannelId);
			if ( *((volatile u32* const)(GPIODATAE+offset))>>ChannelId==1)
				return High_Level;
			else 
				return Low_Level;
		case 'F' :
			setBit(RCGCGPIO,5);
			setBit(GPIODENF,ChannelId);
			resetBit(GPIODIRF,ChannelId);
			if ( *((volatile u32* const)(GPIODATAF+offset))>>ChannelId==1)
				return High_Level;
			else 
				return Low_Level;
	}
}
void Dio_WritePort (Dio_LevelType Level )
{
	switch(Port){
		case 'A' :
			setBit(RCGCGPIO,0);
			GPIODENA=0xff;
			GPIODIRA=0xff;
			if(Level==High_Level) 
				*((volatile u32* const)( GPIODATAA+0x3FC))=0xff;
			else
				*((volatile u32* const)( GPIODATAA+0x3FC))=0x00;
			 break;
		case 'B' :
			setBit(RCGCGPIO,1);
		  GPIODENB=0xff;
			GPIODIRB=0xff;
			if(Level==High_Level) 
				*((volatile u32* const)( GPIODATAB+0x3FC))=0xff;
			else
				*((volatile u32* const)( GPIODATAB+0x3FC))=0x00;
			break;
		case 'C' :
			setBit(RCGCGPIO,2);
		  GPIODENC=0xff;
			GPIODIRC=0xff;
			if(Level==High_Level) 
			if(Level==High_Level) 
				*((volatile u32* const)( GPIODATAC+0x3FC))=0xff;
			else
				*((volatile u32* const)( GPIODATAC+0x3FC))=0x00;
			 break;
			break;
		case 'D' :
			setBit(RCGCGPIO,3);
		  GPIODEND=0xff;
			GPIODIRD=0xff;
			if(Level==High_Level) 
				*((volatile u32* const)( GPIODATAD+0x3FC))=0xff;
			else
				*((volatile u32* const)( GPIODATAD+0x3FC))=0x00;
			 break;
		case 'E' :
			setBit(RCGCGPIO,4);
			GPIODENE=0xff;
			GPIODIRE=0xff;
			if(Level==High_Level) 
				*((volatile u32* const)( GPIODATAE+0x3FC))=0xff;
			else
				*((volatile u32* const)( GPIODATAE+0x3FC))=0x00;
			 break;
		case 'F' :
			setBit(RCGCGPIO,5);
		u8 i;
		for(i=0;i<10;i++);
			GPIODENF=0xff;
			GPIODIRF=0xff;
			if(Level==High_Level) 
				*((volatile u32* const)( GPIODATAF+0x3FC))=0xff;
			else
				*((volatile u32* const)( GPIODATAF+0x3FC))=0x00;
			 break;
	}
}
Dio_LevelType Dio_ReadPort (void)
{
	switch(Port){
		case 'A' :
			setBit(RCGCGPIO,0);
			GPIODENA=0xff;
			GPIODIRA=0x00;
			if ( *((volatile u32* const)( GPIODATAA+0x3FC))==0xff)
				return High_Level;
			else 
				return Low_Level;
		case 'B' :
			setBit(RCGCGPIO,1);
		  GPIODENB=0xff;	
			GPIODIRB=0xff;	
			if ( *((volatile u32* const)( GPIODATAB+0x3FC))==0xff)
				return High_Level;
			else 
				return Low_Level;
		case 'C' :
			setBit(RCGCGPIO,2);
		  GPIODENC=0xff;
			GPIODIRC=0x00;
			if (*((volatile u32* const)( GPIODATAC+0x3FC))==0xff)
				return High_Level;
			else 
				return Low_Level;
		case 'D' :
			setBit(RCGCGPIO,3);
		  GPIODEND=0xff;
			GPIODIRD=0x00;
		  if (*((volatile u32* const)( GPIODATAD+0x3FC))==0xff)
				return High_Level;
			else 
				return Low_Level;
		case 'E' :
			setBit(RCGCGPIO,4);
			GPIODENE=0xff;
			GPIODIRE=0x00;
			if (*((volatile u32* const)( GPIODATAE+0x3FC))==0xff)
				return High_Level;
			else 
				return Low_Level;
		case 'F' :
			setBit(RCGCGPIO,5);
			GPIODENF=0xff;
			GPIODIRF=0x00;
			if (*((volatile u32* const)( GPIODATAF+0x3FC))==0xff)
				return High_Level;
			else 
				return Low_Level;
	}
}
/********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
#include "IntCtrl.h"
#include "Dio.h"
#include "Systick.h"
#include "Timer.h"
#include "LED.h"
void LED_Blynking(u16 TimeON, u16 Timeoff);
void TogglePin(void);
volatile u8 flag =0;
volatile u8 Old_flag =1;
int main(){
		IntSystick_Init();
		IntCrtl_Init();
		static GptChannelConfigSet EnabledTimers[NO_OF_ENABLED_TIMERS]={{Channel0,16,65535,GPT_CH_MODE_CONTINUOUS,TogglePin}};
		Gpt_Init(EnabledTimers);
		Gpt_EnableNotification(Channel0);
	while(1){
		LED_Blynking(10,20);
	}
}

void LED_Blynking(u16 TimeON, u16 TimeOff){
	if (Old_flag!=flag){
		if (flag==0){
			StartTimer(Channel0,TimeOff);
			Old_flag=0;
		}
		else if(flag==1){
			StartTimer(Channel0,TimeON);
			Old_flag=1;
		}
	}
}

void TogglePin(void){
	StopTimer(Channel0);
	if (flag==0){
				LEDs_ON();
				flag=1;
	}
	else{
		  LEDs_OFF();
			flag=0;
	}
}


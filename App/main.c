#include "IntCtrl.h"
#include "Dio.h"
#include "Systick.h"
#include "Timer.h"
#include "LED.h"
void LED_Blynking(u16 TimeON, u16 Timeoff);
void TogglePin(void);
extern volatile u8 flag;
-int main(){
		IntSystick_Init();
		IntCrtl_Init();
		static GptChannelConfigSet EnabledTimers[NO_OF_ENABLED_TIMERS]={{Channel0,16,65535,GPT_CH_MODE_CONTINUOUS,TogglePin}};
		Gpt_Init(EnabledTimers);
		Gpt_EnableNotification(Channel0);
	while(1){
		LED_Blynking(10,20);
}
}
void TogglePin(void){
	StopTimer(Channel0);
	if (flag==0){
				Dio_WritePort (High_Level);
				flag=1;
	}
	else{
			Dio_WritePort (Low_Level);
			flag=0;
	}
}


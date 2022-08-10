#include "Timer.h"
volatile u8 flag =0;
volatile u8 Old_flag =1;
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
#include "Dio.h"
void LED_ON(){
	Dio_WritePort (High_Level);
}

void LED_OFF(){
	Dio_WritePort (Low_Level);
}
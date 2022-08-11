#include "Dio.h"
void LEDs_ON(){
	Dio_WritePort (High_Level);
}

void LEDs_OFF(){
	Dio_WritePort (Low_Level);
}
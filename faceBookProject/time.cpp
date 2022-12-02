#define _CRT_SECURE_NO_WARNINGS
#include "time.h"
using namespace std;


Time::Time()
{
	//using ctime function to set time as current time of the machine
	time_t curr_time;
	curr_time = time(NULL);
	char* timeText = ctime(&curr_time);
	sscanf(timeText + 11, " %d:%d:%d", &hours, &minutes, &seconds);
	
}


void Time::showTime() const
{
	printf("%02d:%02d:%02d", hours, minutes, seconds);
}

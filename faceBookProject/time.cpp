#define _CRT_SECURE_NO_WARNINGS
#include "time.h"
using namespace std;


Time::Time()
{
	time_t curr_time;
	curr_time = time(NULL);
	char* timeText = ctime(&curr_time);
	sscanf(timeText + 11, " %d:%d:%d", &hours, &minutes, &seconds);
	
}


void Time::showTime()
{
	cout << hours << ":" << minutes << ":" << seconds;
}

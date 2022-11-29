#include "time.h"




Time::Time()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}

Time::Time(const char* timeText)
{
	sscanf(timeText, "%d:%d:%d", &seconds, &minutes, &hours);
}

void Time::showTime()
{
	cout << hours << ":" << minutes << ":" << seconds;
}

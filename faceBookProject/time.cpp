#include "time.h"

Time::Time()
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}

void Time::showTime()
{
	cout << hours << ":" << minutes << ":" << seconds;
}

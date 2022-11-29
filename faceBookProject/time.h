#ifndef TIME
#define TIME
#include <iostream>
#include <ctime>
using namespace std;


class Time				
{
public:
	Time();
	Time(const char* timeText);
	void showTime();

private:
	int seconds;
	int minutes;
	int hours;
	
};




	
#endif // !1

#ifndef TIME
#define TIME
#include <iostream>
#include <ctime>
using namespace std;


class Time				
{
public:
	/*
	* Function that show the time in HH:mm:ss Format
	*/
	void showTime() const;
	friend ostream& operator<<(ostream& os, const Time& t)
	{
		os << t.hours << ":" << t.minutes << ":" << t.seconds;
		return os;
	}
	//Ctor
	Time();
	Time(std::string timeStr);

private:
	int seconds;
	int minutes;
	int hours;
	
};




	
#endif // !1

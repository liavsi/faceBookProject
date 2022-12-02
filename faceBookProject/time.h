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

	//Ctor
	Time();
private:
	int seconds;
	int minutes;
	int hours;
	
};




	
#endif // !1

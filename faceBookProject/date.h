#ifndef DATE
#define DATE
#include <stdio.h>

class Date
{
public:
	Date(int day = 0, int month = 0, int year = 0)
	{ 
		this->day = day; this->month = month; this->year = year;
	}
	Date(char* birthdayStr);
	void showDate();
private:
	int year;
	int month;
	int day;
	
};







#endif // !DATE

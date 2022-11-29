#ifndef DATE
#define DATE
#include <stdio.h>
#include <ctime>

class Date
{
public:
	Date();
	Date(const Date& date);
	Date(char* birthdayStr);
	int compare(const Date& date);
	void showDate();
private:
	int year;
	int month;
	int day;
	
};







#endif // !DATE

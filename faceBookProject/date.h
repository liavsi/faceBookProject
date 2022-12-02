#ifndef DATE
#define DATE
#include <stdio.h>
#include <ctime>

class Date
{
public:
	/*
	* const Function that shows the date in DD/MM/YYYY format 
	*/
	void showDate() const;

	//Ctors
	Date();
	Date(const Date& date);
	Date(char* birthdayStr);
private:
	int year;
	int month;
	int day;
	
};







#endif // !DATE

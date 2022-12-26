#ifndef DATE
#define DATE
#include <string>
#include <ctime>
#include <stdio.h>
#include "exeption.h"

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
	Date(const char* birthdayStr) noexcept(false);
private:
	int year;
	int month;
	int day;
	
};







#endif // !DATE

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

	friend std::ostream& operator<<(std::ostream& os, const Date& date);



	//Ctors
	Date();
	Date(const Date& date);
	Date(std::string birthdayStr) noexcept(false);
private:
	int year;
	int month;
	int day;
	
};







#endif // !DATE

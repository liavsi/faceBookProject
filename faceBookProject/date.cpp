#define _CRT_SECURE_NO_WARNINGS
#include "date.h"

Date::Date()
{
	//sets the current time of the creation
	time_t curr_time;
	curr_time = time(NULL);
	tm* ltm = localtime(&curr_time);
	month = ltm->tm_mon + 1;
	year = ltm->tm_year + 1900;
	day = ltm->tm_mday;
}

Date::Date(const Date& date)
{
	//copy by value
	this->day = date.day;
	this->month = date.month;
	this->year = date.year;
}

Date::Date(char* birthdayStr)
{
	//gets dd.mm.yyyy format date
	sscanf(birthdayStr, "%d.%d.%d", &day, &month, &year);
}




void Date::showDate() const
{
	//print dd/mm/yyyy format date
	printf("%02d/%02d/%d", day, month, year);
}


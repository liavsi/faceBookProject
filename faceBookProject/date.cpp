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

Date::Date(const Date& date)//manually happens
{
	//copy by value
	this->day = date.day;
	this->month = date.month;
	this->year = date.year;
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

Date::Date(const char* birthdayStr) noexcept(false)
{
	time_t curr_time;
	curr_time = time(NULL);
	tm* ltm = localtime(&curr_time);
	int currMonth = ltm->tm_mon + 1;
	int currYear = ltm->tm_year + 1900;
	int currDay = ltm->tm_mday;
	//gets dd.mm.yyyy format date
	if (sscanf(birthdayStr, "%d.%d.%d", &day, &month, &year) < 3)
		throw DateFormatExeption();
	if (day > 30 || day < 1 || month > 12 || month < 1)
		throw DateUnvalidExeption();
	if (year > currYear)
		throw DateYetToComeExeption();
	else if (year == currYear && month > currMonth)
		throw DateYetToComeExeption();
	else if (year == currYear && month == currMonth && day > currDay)
		throw DateYetToComeExeption();
}

int Date::getYear()
{
	return year;
}




void Date::showDate() const
{
	//print dd/mm/yyyy format date
	printf("%02d/%02d/%d", day, month, year);

}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	 os << date.day << "/" << date.month << "/" << date.year;
	 return os;
}

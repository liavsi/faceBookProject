#define _CRT_SECURE_NO_WARNINGS
#include "date.h"

Date::Date(const Date& date)
{
	this->day = date.day;
	this->month = date.month;
	this->year = date.year;
}

Date::Date(char* birthdayStr)
{
	sscanf(birthdayStr, "%d.%d.%d", &day, &month, &year);
}

int Date::compare(const Date& date)
{
	if (this->year > date.year)
		return 1;
	if (this->year < date.year)
		return -1;
	if (this->month > date.month)
		return 1;
	if (this->month < date.month)
		return -1;
	if (this->day > date.day)
		return 1;
	if (this->day < date.day)
		return -1;
	return 0;
}

void Date::showDate()
{
	printf("%d/%d/%d", day, month, year);
}


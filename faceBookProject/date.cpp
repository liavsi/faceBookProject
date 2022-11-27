#define _CRT_SECURE_NO_WARNINGS
#include "date.h"

Date::Date(char* birthdayStr) 
{
	sscanf(birthdayStr, "%d.%d.%d", &day, &month, &year);
}

void Date::showDate()
{
	printf("%d/%d/%d", day, month, year);
}


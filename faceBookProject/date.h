#ifndef DATE
#define DATE

class Date
{
public:
	Date(int year = 0, int month = 0, int day = 0) 
	{ 
		this->day = day; this->month = month; this->year = year;
	}
	Date(char* birthdayStr);

private:
	int year;
	int month;
	int day;
	
};







#endif // !DATE

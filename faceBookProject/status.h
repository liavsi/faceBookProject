#ifndef STATUS
#define STATUS
#include <iostream>
#include "date.h"
#include "time.h"
using namespace std;


class Status
{

public:
	Status(char* text);
	Status();
	~Status();

private:
	char* textContent;
	Date date;
	Time time;


};



#endif // !STATUS


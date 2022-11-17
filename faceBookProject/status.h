#ifndef STATUS
#define STATUS
#include "date.h"
#include "time.h"

class Status
{

public:
	Status();
	~Status();

private:
	char* textContent;
	Date date;
	Time time;


};



#endif // !STATUS


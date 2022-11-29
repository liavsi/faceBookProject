#ifndef STATUS
#define STATUS
#include "date.h"
#include "time.h"
using namespace std;


class Status
{

public:
	Status(char* text);
	~Status();
	void showPost();

private:
	char* textContent;
	Date date;
	Time time;


};



#endif // !STATUS


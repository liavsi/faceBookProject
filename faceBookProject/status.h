#ifndef STATUS
#define STATUS
#include "date.h"
#include "time.h"
using namespace std;


class Status
{

public:
	Status(const char* text);
	Status(const Status& other);
	~Status();
	void showPost() const;

private:
	char* textContent;
	Date date;
	Time time;


};



#endif // !STATUS


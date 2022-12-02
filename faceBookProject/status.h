#ifndef STATUS
#define STATUS
#include "date.h"
#include "time.h"
using namespace std;


class Status
{

public:
	/*
	* const Function that shows the post
	*/
	void showPost() const;

	//Ctors and Dtor
	Status(const char* text);
	Status(const Status& other);
	~Status();
	

private:
	char* textContent;
	Date date;
	Time time;


};



#endif // !STATUS


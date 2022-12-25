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
	Status(const string text);
	Status(const Status& other);
	~Status();

	//operator overloads
	const bool operator ==(const Status& other);
	const bool operator !=(const Status& other);

private:
	string textContent;
	Date date;
	Time time;


};



#endif // !STATUS


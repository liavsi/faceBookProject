#ifndef STATUS
#define STATUS
#include "date.h"
#include "time.h"
#include <string>

class Status
{

public:
	/*
	* const Function that shows the post
	*/

	virtual void showPost() const = 0;
	virtual void toOs(ostream& os) const {}
	//Ctors and Dtor

	virtual ~Status();

	//operator overloads
	virtual const bool operator ==(const Status& other) const = 0;
	virtual const bool operator !=(const Status& other) const = 0;
	friend ostream& operator<<(ostream& os, const Status& p);

protected:
	Status();
	Status(const Date& date,const Time& time);
	Status(const Status& other);
	Date date;
	Time time;



};



#endif // !STATUS


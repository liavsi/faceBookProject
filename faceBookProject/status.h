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

	//Ctors and Dtor

	virtual ~Status();

	//operator overloads
	virtual const bool operator ==(const Status& other) const = 0;
	virtual const bool operator !=(const Status& other) const = 0;

protected:
	Status();
	Status(const Status& other);

private:
	Date date;
	Time time;



};



#endif // !STATUS


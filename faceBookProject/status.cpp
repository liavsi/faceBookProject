#define _CRT_SECURE_NO_WARNINGS
#include "status.h"

using namespace std;


Status::Status(): time(),date()
{

}

Status::Status(const Status& other)
{
	date = other.date;
	time = other.time;
}




Status::~Status()
{
}





void Status::showPost() const
{
	
	date.showDate();
	cout << " - ";
	time.showTime();
	cout << endl;
}

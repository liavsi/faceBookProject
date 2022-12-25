#define _CRT_SECURE_NO_WARNINGS
#include "status.h"

using namespace std;


Status::Status(const string text): time(),date()
{
	textContent = text;

}

Status::Status(const Status& other)
{
	textContent = other.textContent;
	date = other.date;
	time = other.time;
}




Status::~Status()
{
}

const bool Status::operator==(const Status& other)
{
	return this->textContent == other.textContent;
}

const bool Status::operator!=(const Status& other)
{
	return !(*this == other);
}


void Status::showPost() const
{
	cout << textContent << "| posted at: ";
	date.showDate();
	cout << " - ";
	time.showTime();
	cout << endl;
}

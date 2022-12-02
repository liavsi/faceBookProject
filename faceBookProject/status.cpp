#define _CRT_SECURE_NO_WARNINGS
#include "status.h"

using namespace std;

#define MAX_POST_LEN 151

Status::Status(const char * text): time(),date()
{
	textContent = new char[strlen(text) + 1];
	strcpy(textContent, text);

}

Status::Status(const Status& other)
{
	textContent = new char[strlen(other.textContent) + 1];
	strcpy(textContent, other.textContent);
	date = other.date;
	time = other.time;
}


Status::~Status()
{
	delete textContent;
}

void Status::showPost() const
{
	cout << textContent << "| posted at: ";
	date.showDate();
	cout << " - ";
	time.showTime();
	cout << endl;
}

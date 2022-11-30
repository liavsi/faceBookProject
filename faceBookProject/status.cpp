#define _CRT_SECURE_NO_WARNINGS
#include "status.h"

using namespace std;

#define MAX_POST_LEN 151

Status::Status(const char * text): time(),date()
{
	textContent = new char[strlen(text) + 1];
	strcpy(textContent, text);
	

	
}


Status::~Status()
{
	delete textContent;
}

void Status::showPost()
{
	cout << textContent << "| posted at: ";
	date.showDate();
	cout << " - ";
	time.showTime();
	cout << endl;
}

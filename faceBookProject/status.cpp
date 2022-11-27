#define _CRT_SECURE_NO_WARNINGS
#include "status.h"
#define MAX_POST_LEN 151

Status::Status(char* text): time(), date()//time is set to zero by now
{
	textContent = new char[strlen(text)+1];
	strcpy(textContent, text);

}

Status::Status(): time(),date()
{
	char text[MAX_POST_LEN];
	cout << "Enter text for your post (max 150 letters):";
	cin.ignore();
	cin.getline(text, MAX_POST_LEN);
	textContent = new char[strlen(text) + 1];
	strcpy(textContent, text);

}



Status::~Status()
{
	delete textContent;
}

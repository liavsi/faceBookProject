#define _CRT_SECURE_NO_WARNINGS
#include "fanPage.h"

void FanPage::showFanPage()
{
	cout << "Fan Page name: " << name << endl;
}

FanPage::FanPage(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	posts = new Status * [postsPhisSize];
	fans = new User * [fansphisSize];
}

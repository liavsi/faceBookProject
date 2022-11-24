#define _CRT_SECURE_NO_WARNINGS

#include "user.h"

User::User(char* name, Date birthday)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->birthday = birthday;
	posts = new Status * [postPhisSize];
	friends = new User * [friendPhisSize];
	pages = new fanPage * [pagePhisSize];

}

void User::showUser()
{

	cout << "User name: " << name << endl;
	cout << "birth date: ";	
	birthday.showDate();
	cout << endl;
}

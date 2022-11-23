using namespace std;
#include <iostream>
#include "user.h"

User::User(char* name, Date birthday)
{
	//memory shit with the name...not allowed to use string
	this->birthday = birthday;
}
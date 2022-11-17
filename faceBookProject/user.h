#ifndef USER
#define USER
#include "date.h"
#include "status.h"

class User
{
public:
	User();
	~User();

private:
	char* name;
	Date date;
	Status* posts;
	User* friends;

};

User::User()
{
}

User::~User()
{
}










#endif // !USER


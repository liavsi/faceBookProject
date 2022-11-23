#ifndef USER
#define USER
#include "date.h"
#include "status.h"
class fanPage;

class User
{
public:
	User(char* name, Date birthday);
	~User();// need to delete memory at the end

private:
	char* name;
	Date birthday;
	Status** posts;
	int postsLogicSize, postPhisSize;//all sizes needs to be initialized to some number we choose
	User** friends;
	int friendsLogicSize, friendPhisSize;
	fanPage** pages;
	int pagesLogicSize, pagePhisSize;


};











#endif // !USER


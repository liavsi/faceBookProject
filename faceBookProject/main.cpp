#include "facebook.h"

int main()
{
	Facebook facebook;
	facebook.addUser(User("liav", Date()));
	facebook.addUser(User("sharon", Date()));
	facebook.startMenu();


	return 0;
}
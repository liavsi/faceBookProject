#include "facebook.h"

int main()
{
	Facebook facebook;
	facebook.addUser(User("liav", Date(3,6,1999)));

	facebook.startMenu();


	return 0;
}
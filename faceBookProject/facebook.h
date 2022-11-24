#ifndef FACEBOOK
#define FACEBOOK
#include "user.h"
#include "fanPage.h"





class Facebook
{
public:
	Facebook();
	void addFriend();
	void addFanPage();
	~Facebook();

private:
	User** users;
	int usersLogicSize=0, usersPhisSize=2;
	FanPage** fanPage;
	int fanPageLogicalSize=0, fanPagePhisSize = 2;
	void addUserToUsers(User* newUser);
	void addFanPageToFanPages(FanPage* newFanPage);

};



#endif // !FACEBOOK

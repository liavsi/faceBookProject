#ifndef FACEBOOK
#define FACEBOOK
#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "fanPage.h"





class Facebook
{
public:
	Facebook();
	void addUser();
	void addUser(User user);//manually add user
	void addFanPage();
	void ShowPosts();
	void showPostOfFanPage();
	void showPostsOfUser();
	void startMenu();
	void ShowMostRecentPosts();
	void makeConnection();
	~Facebook();
private:
	User** users;
	int usersLogicSize=0, usersPhisSize=2;
	FanPage** fanPages;
	int fanPageLogicalSize=0, fanPagePhisSize = 2;
	void addUserToUsers(User* newUser);
	void addFanPageToFanPages(FanPage* newFanPage);
	void printMenu();
	void addStatus();
	void addStatusToUser();
	void addStatusToFanPage();
	void showAllUsers();
	void showAllFanPages();
	User* findUserByName(char* name);
	User* getUserNameFromUser(const char* text);
	FanPage* findFanPageByName(char* name);

};



#endif // !FACEBOOK

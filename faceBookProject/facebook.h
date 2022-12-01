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
	void addFanPage(FanPage fanpage);//manually add fanpage
	void ShowPosts();
	void showPostOfFanPage();
	void showPostsOfUser();
	void startMenu();
	void ShowMostRecentPosts();
	void makeConnection();
	void makeConnection(User* user1, User* user2);
	void disConnect();
	void addFriendToFanPage();
	void initializeFacebook();
	void removeUserFromFanPage();
	//making 3 users, 3 fanpages 2 status for each of them and three connections
	void addFriendToFanPage(User* user, FanPage* fanpage);
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
	void showAllFriendFansOFUser();
	User* getUserNameFromUser(const char* text);
	FanPage* getFanpageFromUser(const char* text);
	FanPage* findFanPageByName(char* name);

};



#endif // !FACEBOOK

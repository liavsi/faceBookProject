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
	void ShowPosts() const;
	void showPostOfFanPage() const;
	void showPostsOfUser() const;
	void startMenu();
	void ShowMostRecentPosts() const;
	void makeConnection();
	void makeConnection(User* user1, User* user2);
	void disConnect();
	void disConnectFriendAndFanPage();
	void addFriendToFanPage();
	void initializeFacebook();
	void removeUserFromFanPage();
	void showFriendsOfUser() const;
	void showFansOfFanPage()const;
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
	void printMenu() const;
	void addStatus();
	void addStatusToUser();
	void addStatusToFanPage();
	void showAllUsers() const;
	void showAllFanPages() const;
	FanPage* findFanPageByName(char* name);
	const FanPage* findFanPageByName(char* name) const;
	User* findUserByName(char* name);
	const User* findUserByName(char* name) const;
	void showAllFriendFansOFUser() const;
	User* getUserNameFromUser(const char* text);
	const User* getUserNameFromUser(const char* text) const;
	FanPage* getFanpageFromUser(const char* text) ;
	const FanPage* getFanpageFromUser(const char* text) const;

};



#endif // !FACEBOOK

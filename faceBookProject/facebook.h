#ifndef FACEBOOK
#define FACEBOOK
#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "fanPage.h"




/*
* Facebook Object is the control class of all the other objects
*/
class Facebook
{
public:
	Facebook();
	~Facebook();
	/*
	* Function that adds user to facebook
	*/
	void addUser();

	/*
	* manually add user to facebook
	*/
	void addUser(User user);

	/*
	* Function that adds fanpage to facebook
	*/
	void addFanPage();

	/*
	* manually add fanpage
	*/
	void addFanPage(FanPage fanpage);

	/*
	* const Function that asks the user to show user's facebook or fanpage posts
	*/
	void ShowPosts() const;
	
	/*
	* const Function that asks the user name of fanpage and shows fanpage's posts
	*/
	void showPostOfFanPage() const;

	/*
	* const Function that asks for username and shows user's posts
	*/
	void showPostsOfUser() const;

	/*
	*Function that start the facebook Menu loop
	*/
	void startMenu();

	/*
	* function that asks for username and shows his recent 10 posts of each friend of him
	*/
	void ShowMostRecentPosts() const;

	/*
	* Function that makes 2 users friends by asking user which users
	*/
	void makeConnection();

	/*
	* Function that adds user1 and user2 be friends
	*/
	void makeConnection(User* user1, User* user2);
	/*
	* Function that disconnent 2 users (unfriend)
	*/
	void disConnect();

	/*
	* Function that disconnetct fanpage from user
	*/
	void disConnectFriendAndFanPage();
	/*
	* Function that adds a friend to a fanpage
	*/
	void addFriendToFanPage();

	/*
	* Function that intialize facebook friends and fanapges manually
	*/
	void initializeFacebook();

	/*
	* Function that remove user from fanpage by asking the user which user and fanpage
	*/
	void removeUserFromFanPage();
	/*
	*const Function that shows all friends of user by asking the user which username
	*/
	void showFriendsOfUser() const;

	/*
	* const Function that shows all fans of fanpage by asking the user which fanpage
	*/
	void showFansOfFanPage()const;
	/*
	* Function that adds a user to a fanpage
	*/
	void addFriendToFanPage(User* user, FanPage* fanpage);
	
private:
	User** users;
	int usersLogicSize=0, usersPhisSize=2;
	FanPage** fanPages;
	int fanPageLogicalSize=0, fanPagePhisSize = 2;
	const int EXIT_MENU = 12;
	static const int  MAX_NAME_LEN = 101;
	static const int MAX_POST_LEN = 151;
	static const int MAX_DATE_LEN = 13;
	/*
	* Helper Functions
	*/
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

#ifndef FACEBOOK
#define FACEBOOK
#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "fanPage.h"



/*
* Facebook Object is the control class of all the other objects
*/

enum eTypeStatus { Text, Picture, Video };


class Facebook
{
public:

	Facebook();
	~Facebook();
	/*
	* Function that adds user to facebook
	*/
	void addUser();

	void writeUsersToFile(ofstream& file) const;

	void saveData(string filename) const;
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
	void showPostOfFanPage() const noexcept(false);

	/*
	* const Function that asks for username and shows user's posts
	*/
	void showPostsOfUser() const noexcept(false);

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

	void makeUsersConnection(ifstream& file, int numOfUsers);

	void makeFanPagesConnection(ifstream& file, int numOfFanPages);

	/*
	* Function that adds user1 and user2 be friends
	*/
	void makeConnection(User& user1, User& user2);
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
	void removeUserFromFanPage() noexcept(false);
	/*
	*const Function that shows all friends of user by asking the user which username
	*/
	void showFriendsOfUser() const noexcept(false);

	/*
	* const Function that shows all fans of fanpage by asking the user which fanpage
	*/
	void showFansOfFanPage()const noexcept(false);
	/*
	* Function that adds a user to a fanpage
	*/
	void addFriendToFanPage(User& user, FanPage& fanpage);

	int initializeUsers(ifstream& file);
	int initializeFanPages(ifstream& file);
	void initializeFacebook(std::string filename);
private:
	vector<User*> users;
	vector<FanPage*> fanPages;
	const int CAPACITY_INIT = 5;
	const int EXIT_MENU = 12;
	static const int  MAX_NAME_LEN = 101;
	static const int MAX_POST_LEN = 151;
	static const int MAX_DATE_LEN = 13;
	/*
	* Helper Functions
	*/


	const string newUserNameFromInput() const  noexcept(false);
	const string newPageNameFromInput() const  noexcept(false);
	void addUserToUsers(User* newUser);
	void addFanPageToFanPages(FanPage* newFanPage);
	void printMenu() const;
	void addStatus();
	void addStatusToUser() noexcept(false);
	void addStatusToFanPage() noexcept(false);
	void showAllUsers() const;
	void showAllFanPages() const;
	FanPage* findFanPageByName(string name);
	const FanPage* findFanPageByName(string name) const;
	User* findUserByName(string name);
	const User* findUserByName(string name) const;
	void showAllFriendFansOFUser() const;
	User* getUserNameFromUser(const string text) noexcept(false);
	const User* getUserNameFromUser(const string text) const noexcept(false);
	FanPage* getFanpageFromUser(const string text) noexcept(false);
	const FanPage* getFanpageFromUser(const string text) const noexcept(false);
	Status* buildStatus(const string text, eTypeStatus typeStatus);
};



#endif // !FACEBOOK

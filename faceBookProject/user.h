#ifndef USER
#define USER
#include "date.h"
#include "status.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class FanPage;

class User
{
public:

	/*
	* operator overload to add friend to friend
	*/


	/*
	* const Function that shows the user info
	*/
	void showUser() const;

	/*
	* const Function that returns username
	*/
	const string getName() const;

	/*
	* Function that adds a post the user
	*/
	void addPost(Status* post);

	/*
	* Function that shows posts of the user (default is showing all posts)
	*/
	void showPosts(int numOfPosts = -1) const;

	/*
	* Function that adds friend to user
	*/
	void addFriend(User& other);

	/*
	* Function that unfriend the user from our user
	*/
	void unFriend(User& other);

	/*
	* Function that adds a fanpage to the user
	*/
	void addFanpage(FanPage& fanpage);

	/*
	* Function that removes a fanpage from the user
	*/
	void removeFanPage(FanPage& fanpage);

	/*
	* const Function that shows all #NUM_OF_RECENTS recents posts of the user's frinds
	*/
	void showFriendPosts() const;

	/*
	* const Function that shows all #NUM_OF_RECENT recents posts of fanpage he connected with
	*/
	void showFanPagePosts() const;

	/*
	* const Function that shows all the friends of the user
	*/
	void showFriends() const;

	//Operator overload
	User& operator +=(User& other);
	User& operator +=(FanPage& fanpage);
	const bool operator >(const User& other);

	//Ctors and Dtor
	User(const string name, Date birthday);
	User(const User& user);
	~User();

private:
	string name;
	vector<Status*> posts;
	vector<User*> friends;
	vector<FanPage*> pages;
	Date birthday;

	const int UNFOUND = -1;
	const int NUM_OF_RECENTS_POST_FRIEND = 10;
	const int CAPACITY_INIT = 4;

	//Helpers
	int indexOfFriend(User& other);
	int indexOfFanpage(FanPage&	fanpage); 
	void deleteFromFriends(User& other);
	void deleteFromPages(FanPage& fanpage);
	void addFanPageToUser1(FanPage& fanpage);

};











#endif // !USER


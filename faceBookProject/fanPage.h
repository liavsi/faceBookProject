#ifndef FANPAGE
#define FANPAGE
#include "user.h"
#include "exeption.h"
#include <vector>
#include <string>

class FanPage 
{
public:
	/*
	* const Function that print fanpage with name
	*/
	void showFanPage() const;

	/*
	* const Function that returns name of the fanpage
	*/
	const string getName() const;

	/*
	* Function that adds a post to fanpage
	*/
	void addPost(Status* post);

	/*
	* const Function that shows posts of fanpage (default is showing all posts)
	*/
	void showPosts(int numOfPosts = -1) const;
	/*
	* const Function that shows all fans of the fanpage
	*/
	void showFans() const;

	/*
	* Function thats the user to the fanpage
	*/
	void addUserToFanPage(User* user);

	/*
	* Function that removes the user from the fanpage
	*/
	void removeFromFans(User* user);

	//operator overload
	const bool operator >(const FanPage& fanpage);


	//Ctor and Dtor
	FanPage(const FanPage& fanpage);
	FanPage(const string name);
	~FanPage();

private:
	string name;
	vector<Status*> posts;
	vector<User*> fans;

	const int UNFOUND = -1;
	const int CAPACITY_INIT = 5;

	//Helper Functions
	int indexOfUser(User* user) const;
	void addUserToFans(User* user);
	void deleteFromFans(User* user);

};




#endif // !FANPAGE

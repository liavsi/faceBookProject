#ifndef FANPAGE
#define FANPAGE
#include "user.h"


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
	const char* getName() const;

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

	//Ctor and Dtor
	FanPage(const FanPage& fanpage);
	FanPage(const char* name);
	~FanPage();

private:
	char* name;
	User** fans;
	int fansLogicalSize = 0, fansphisSize = 2;
	Status** posts;
	int postsLogicalSize = 0, postsPhisSize = 2;

	const int UNFOUND = -1;

	//Helper Functions
	int indexOfUser(User* user) const;
	void addUserToFans(User* user);
	void deleteFromFans(User* user);

};




#endif // !FANPAGE

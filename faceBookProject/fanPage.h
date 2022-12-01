#ifndef FANPAGE
#define FANPAGE
#include "user.h"


class FanPage
{
public:
	void showFanPage();
	char* getName();
	void addPost(Status* post);
	void showPosts();
	FanPage(const FanPage& fanpage);
	void addUserToFanPage(User* user);
	FanPage(const char* name);
	~FanPage();

private:
	char* name;
	User** fans;
	int fansLogicalSize = 0, fansphisSize = 2;
	Status** posts;
	int postsLogicalSize = 0, postsPhisSize = 2;
	int indexOfUser(User* user) const;
	void addUserToFans(User* user);

};




#endif // !FANPAGE

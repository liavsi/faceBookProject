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
	FanPage(const char* name);
	FanPage(const FanPage& fanpage);

	~FanPage();

private:
	char* name;
	User** fans;
	int fansLogicalSize = 0, fansphisSize = 2;
	Status** posts;
	int postsLogicalSize = 0, postsPhisSize = 2;





};




#endif // !FANPAGE

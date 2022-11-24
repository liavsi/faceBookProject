#ifndef FANPAGE
#define FANPAGE
#include "user.h"


class FanPage
{
public:
	void showFanPage();
	FanPage(char* name);
	~FanPage();

private:
	char* name;
	User** fans;
	int fansLogicalSize = 0, fansphisSize = 2;
	Status** posts;
	int postsLogicalSize = 0, postsPhisSize = 2;





};




#endif // !FANPAGE

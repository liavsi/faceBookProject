#ifndef FANPAGE
#define FANPAGE
#include "user.h"


class FanPage
{
public:
	FanPage();
	~FanPage();

private:
	char* name;
	User* fans;
	Status* posts;


};

FanPage::FanPage()
{
}

FanPage::~FanPage()
{
}



#endif // !FANPAGE

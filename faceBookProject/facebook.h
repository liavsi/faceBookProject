#ifndef FACEBOOK
#define FACEBOOK
#include "user.h"
#include "fanPage.h"



class Facebook
{
public:
	Facebook();
	~Facebook();

private:
	User* users;
	FanPage* fanPage;

};

Facebook::Facebook()
{
}

Facebook::~Facebook()
{
}


#endif // !FACEBOOK

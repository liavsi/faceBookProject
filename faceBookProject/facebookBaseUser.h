#ifndef FACEBOOKBASEUSER_H
#define FACEBOOKBASEUSER_H

#include "status.h"
#include <vector>



class FacebookBaseUser
{
public:
	FacebookBaseUser();
	~FacebookBaseUser();

private:
	string name;
	vector<Status*> posts;


};







#endif // !FACEBOOKBASEUSER_H

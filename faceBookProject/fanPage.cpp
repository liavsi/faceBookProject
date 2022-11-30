#define _CRT_SECURE_NO_WARNINGS
#include "fanPage.h"
#define UNFOUND -1


void FanPage::showFanPage()
{
	cout << "Fan Page name: " << name << endl;
}

char* FanPage::getName()
{
	return name;
}

void FanPage::addPost(Status* post)
{
	{
		if (postsPhisSize == postsLogicalSize)
		{
			postsPhisSize *= 2;
			Status** newPosts = new Status * [postsPhisSize];
			for (int i = 0; i < postsLogicalSize; i++) {
				posts[i] = newPosts[i];
			}
			delete[]posts;
			posts = newPosts;
		}
		posts[postsLogicalSize] = post;
		postsLogicalSize++;
	}
}

void FanPage::showPosts()
{
	for (int i = 0; i < postsLogicalSize; i++)
	{
		posts[i]->showPost();
	}
}

void FanPage::addUserToFanPage(User* user)
{
	if (indexOfUser(user) == UNFOUND) 
	{
		this->addUserToFans(user);
		user->addFanpage(this);
	}
}

FanPage::FanPage(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	posts = new Status * [postsPhisSize];
	fans = new User * [fansphisSize];
}

int FanPage::indexOfUser(User* user) const
{
	for (int i = 0; i < fansLogicalSize; i++) {
		if (fans[i] == user) {
			return i;
		}
	}
	return UNFOUND;
}

void FanPage::addUserToFans(User* user)
{
	if (fansLogicalSize == fansphisSize) 
	{
		fansphisSize *= 2;
		User** newUsers = new User * [fansphisSize];
		for (int i = 0; i < fansLogicalSize; i++) 
		{
			newUsers[i] = fans[i];
		}
		delete []fans;
		fans = newUsers;
	}
	fans[fansLogicalSize++] = user;
}

FanPage::FanPage(const FanPage& fanpage)
{
	name = fanpage.name;
	fans = fanpage.fans;
	fansLogicalSize = fanpage.fansLogicalSize;
	fansphisSize = fanpage.fansphisSize;
	posts = fanpage.posts;
	postsLogicalSize = fanpage.postsLogicalSize;
	postsPhisSize = fanpage.postsPhisSize;
}

FanPage::~FanPage()
{
}

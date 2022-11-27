#define _CRT_SECURE_NO_WARNINGS
#include "fanPage.h"

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

FanPage::FanPage(char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	posts = new Status * [postsPhisSize];
	fans = new User * [fansphisSize];
}

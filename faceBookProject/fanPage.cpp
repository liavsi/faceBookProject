#define _CRT_SECURE_NO_WARNINGS
#include "fanPage.h"


void FanPage::showFanPage() const
{
	cout << "Fan Page name: " << name << endl;
}

const string FanPage::getName() const
{
	return name;
}

void FanPage::addPost(Status* post)
{
	posts.push_back(post);
}


void FanPage::showPosts(int numOfPosts) const
{
	int sizeToShow;
	if (numOfPosts > posts.size() || numOfPosts == -1)//default is -1 for all posts
		sizeToShow = posts.size();
	else
		sizeToShow = numOfPosts;

	for (int i = sizeToShow - 1; i >= 0; i--)//from the most recent to the last
	{
		posts[i]->showPost();
	}
}

void FanPage::showFans() const
{
	if (fans.size() == 0)
	{
		cout << name << " has no fans for now.."<<endl;
	}
	else
	{
		cout << name << " fans are: " << endl;
		for (int i = 0; i < fans.size(); i++)
		{
			cout << "fan #" << i + 1 << " name is " << fans[i]->getName() << endl;
		}
	}
	
}

void FanPage::addUserToFanPage(User* user)//same as with User..
{
	if (indexOfUser(user) == UNFOUND) 
	{
		this->addUserToFans(user);
		user->addFanpage(this);
	}
}


void FanPage::removeFromFans(User* user)
{
	if (indexOfUser(user) != UNFOUND)
	{
		this->deleteFromFans(user);
		user->removeFanPage(this);
	}
}

void FanPage::deleteFromFans(User* user)//deleting from fans array and taking all the others to fill the void
{
	int index = indexOfUser(user);
	for (int i = index; i < fans.size(); i++)
	{
		fans[i] = fans[i + 1];
	}
	fans.pop_back();
}


FanPage::FanPage(const string name)
{
	this->name = name;
	posts.reserve(CAPACITY_INIT);
	fans.reserve(CAPACITY_INIT);
}

int FanPage::indexOfUser(User* user) const
{
	for (int i = 0; i < fans.size(); i++) {
		if (fans[i] == user) {
			return i;
		}
	}
	return UNFOUND;
}

void FanPage::addUserToFans(User* user)
{
	fans.push_back(user);
}




FanPage::FanPage(const FanPage& fanpage)
{
	name = fanpage.name;
	for (int i = 0; i < fanpage.fans.size(); i++) 
	{
		fans.push_back(fanpage.fans[i]);
	}
	for (int i = 0; i < fanpage.posts.size(); i++)
	{
		posts.push_back(fanpage.posts[i]);
	}
	
}

FanPage::~FanPage()
{
	for (int i = 0; i < posts.size(); i++) {
		delete posts[i];
	}
}

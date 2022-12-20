#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "fanPage.h"

User::User(const string name, Date birthday) : birthday(birthday)
{
	//builds User with name and birthday date (other attributes set to zero but memory allocated)
	this->name = name;
	this->birthday = birthday;
	posts.reserve(CAPACITY_INIT);
	friends.reserve(CAPACITY_INIT);
	pages.reserve(CAPACITY_INIT);
}
User::User(const User& user)
{
	//copy the name and birth day and sets memory, we assume no cpy on user with more data than that
	name =user.name;
	birthday = Date(user.birthday);

	for (int i = 0; i < user.posts.size(); i++)
	{		
		posts.push_back(user.posts[i]);
	}
	for (int i = 0; i < user.friends.size(); i++)
	{
		friends.push_back(user.friends[i]);
	}
	for (int i = 0; i < user.pages.size(); i++) {
		pages.push_back(user.pages[i]);
	}

}

void User::showUser() const
{
	
	cout << "User name: " << name << endl;
	cout << "birth date: ";	
	birthday.showDate();
	cout << endl;
}


const string User::getName() const
{
	return this->name;
}

void User::addPost(Status* post)
{
	posts.push_back(post);
}

void User::showPosts(int numOfPosts) const
{
	int sizeToShow;//how many post needs to be shown
	if (numOfPosts > posts.size() || numOfPosts == -1)//default is -1 for all posts
		sizeToShow = posts.size();
	else
		sizeToShow = numOfPosts;
	for(int i = sizeToShow-1; i >= 0; i--)//from the most recent to the last
	{
		posts[i]->showPost();
	}
}

void User::unFriend(User* other)
{
	if (indexOfFriend(other) !=UNFOUND)//if "other" is found he needs to be deleted
	{
		deleteFromFriends(other);
		other->unFriend(this);
	}
}



void User::addFanpage(FanPage* fanpage)//similar to add friend
{
	
	if (indexOfFanpage(fanpage) == UNFOUND)
	{
		this->addFanPageToUser1(fanpage);
		fanpage->addUserToFanPage(this);
	}
}

void User::removeFanPage(FanPage* fanpage)//similar to unFriend
{
	if (indexOfFanpage(fanpage) != UNFOUND)
	{
		deleteFromPages(fanpage);
		fanpage->removeFromFans(this);
	}

}



int User::indexOfFriend(User* other)//checks if "other" is friend and signals UNFOUND for no or index in array otherwise
{
	for (int i = 0; i < friends.size(); i++)
	{
		if (friends[i] == other)
			return i;
	}
	return UNFOUND;
}

int User::indexOfFanpage(FanPage* fanpage)//same as indexOfFriend just with FanPage
{
	for (int i = 0; i < pages.size(); i++)
	{
		if (pages[i]->getName() == fanpage->getName()) 
		{
			return i;
		}
	}
	return UNFOUND;
}

void User::deleteFromFriends(User* other)//remove "other" from array and takes all the others back to fill the void 
{
	int index = indexOfFriend(other);
	for (int i = index; i < friends.size(); i++)
	{
		friends[i] = friends[i + 1];
	}
	friends.pop_back();
}

void User::deleteFromPages(FanPage* fanpage)//similar to above
{
	int index = indexOfFanpage(fanpage);
	pages[index] = nullptr;
	for (int i = index; i < pages.size(); i++)
	{
		pages[i] = pages[i + 1];
	}
}

void User::addFriend(User* other)
{
	if (indexOfFriend(other) == UNFOUND)
	{
		friends.push_back(other);
		other->addFriend(this);//add "this" to other with the same method
	}
}

void User::addFanPageToUser1(FanPage* fanpage)
{
	pages.push_back(fanpage);
}



void User::showFriendPosts() const
{
	if (friends.size() == 0)
	{
		cout << name << " has no friends yet.." << endl;
	}
	for (int i = 0; i < friends.size(); i++)
	{
		cout << this->friends[i]->getName() << " post's: " << endl;;
		this->friends[i]->showPosts(NUM_OF_RECENTS_POST_FRIEND);
	}
}

void User::showFanPagePosts() const
{
	for (int i = 0; i < pages.size(); i++)
	{
		cout << this->pages[i]->getName() << " post's: " << endl;;
		this->pages[i]->showPosts(NUM_OF_RECENTS_POST_FRIEND);
	}
}

User::~User()
{
	for (int i = 0; i < posts.size(); i++) 
	{
		delete posts[i];
	}
}

void User::showFriends() const
{
	if (friends.size() == 0)
	{
		cout << name << " has no friends for now.." << endl;
	}
	else
	{
		cout << name << " friends are: " << endl;
		for (int i = 0; i < friends.size(); i++)
		{
			cout << "friend #" << i + 1 << " name is " << friends[i]->getName() << endl;
		}
	}

}

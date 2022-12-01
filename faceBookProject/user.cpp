#define _CRT_SECURE_NO_WARNINGS
#include "user.h"
#include "fanPage.h"
#define UNFOUND -1

User::User(const char* name, Date birthday) : birthday(birthday)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->birthday = birthday;
	posts = new Status * [postPhisSize];
	friends = new User * [friendPhisSize];
	pages = new FanPage * [pagePhisSize];
}
User::User(const User& user)
{
	name = new char[strlen(user.name) + 1];
	strcpy(name, user.name);
	birthday = Date(user.birthday);
	pagesLogicSize = user.pagesLogicSize;
	pagePhisSize = user.pagePhisSize;
	postPhisSize = user.postPhisSize;
	postsLogicSize = user.postsLogicSize;
	friendsLogicSize = user.friendsLogicSize;
	friendPhisSize = user.friendPhisSize;


	posts = new Status * [postPhisSize];
	for (int i = 0; i < postsLogicSize; i++) {
		posts[i] = new Status(*user.posts[i]);
	}
	friends = new User * [friendPhisSize];
	for (int i = 0; i < friendsLogicSize; i++) {
		friends[i] = user.friends[i];
	}
	pages = new FanPage * [pagePhisSize];
	for (int i = 0; i < pagesLogicSize; i++) {
		pages[i] = user.pages[i];
	}

}

void User::showUser() const
{

	cout << "User name: " << name << endl;
	cout << "birth date: ";	
	birthday.showDate();
	cout << endl;
}


const char* User::getName() const
{
	return this->name;
}

void User::addPost(Status* post)
{
	if (postsLogicSize == postPhisSize)
	{
		postPhisSize *= 2;
		Status** newPosts = new Status * [postPhisSize];
		for (int i = 0; i < postsLogicSize; i++) {
			newPosts[i] = posts[i];
		}
		delete[]posts;
		posts = newPosts;
	}
	posts[postsLogicSize] = post;
	postsLogicSize++;
}

void User::showPosts(int iterations) const
{
	int sizeToShow;
	if (iterations > postsLogicSize || iterations == -1)//default is -1 for all posts
		sizeToShow = postsLogicSize;
	else
		sizeToShow = iterations;

	for(int i = sizeToShow-1; i >= 0; i--)//from the most recent to the last
	{
		posts[i]->showPost();
	}
}

void User::showUserDebuging()
{
	cout << "****************DEBUGGING****************" << endl;
	cout << "User name: " << name << endl;
	cout << "birth date: ";
	birthday.showDate();
	for (int i = 0; i < friendsLogicSize; i++) {
		cout << "	Friend name : " << friends[i]->getName() << endl;
	}
	cout << endl;
	cout << "Post logical size: " << postsLogicSize << "| post physic size: " << postPhisSize << "\n" << "friends logic size : " << friendsLogicSize << "| friends physic size: " << friendPhisSize << endl;
	cout << "pages logical size: " << pagesLogicSize << "| pages physic size: " << pagePhisSize << endl;
	cout << "*****************************************" << endl;
}

void User::addFriend(User* other)
{
	if (indexOfFriend(other) == UNFOUND)
	{
		if (friendsLogicSize == friendPhisSize)
		{
			friendPhisSize *= 2;
			User** newUsers = new User * [friendPhisSize];
			for (int i = 0; i < friendsLogicSize; i++)
			{
				newUsers[i] = friends[i];
			}
			delete[]friends;
			friends = newUsers;
		}
		friends[friendsLogicSize] = other;
		friendsLogicSize++;
		other->addFriend(this);
	}
}


void User::unFriend(User* other)
{
	if (indexOfFriend(other) !=UNFOUND)
	{
		deleteFromFriends(other);
		other->unFriend(this);
	}
}



void User::addFanpage(FanPage* fanpage)
{
	if (indexOfFanpage(fanpage) == UNFOUND)
	{
		this->addFanPageToUser1(fanpage);
		fanpage->addUserToFanPage(this);
	}
}

void User::removeFanPage(FanPage* fanpage)
{
	if (indexOfFanpage(fanpage) != UNFOUND)
	{
		deleteFromPages(fanpage);
		fanpage->removeFromFans(this);
	}
}



int User::indexOfFriend(User* other)
{
	for (int i = 0; i < friendsLogicSize; i++)
	{
		if (friends[i] == other)
			return i;
	}
	return UNFOUND;
}

int User::indexOfFanpage(FanPage* fanpage)
{
	for (int i = 0; i < pagesLogicSize; i++) {
		if (strcmp(pages[i]->getName(), fanpage->getName()) == 0) {
			return i;
		}
	}
	return UNFOUND;
}

void User::deleteFromFriends(User* other)
{
	int index = indexOfFriend(other);
	friends[index] = nullptr;
	--friendsLogicSize;
	for (int i = index; i < friendsLogicSize; i++)
	{
		friends[i] = friends[i + 1];
	}
}

void User::deleteFromPages(FanPage* fanpage)
{
	int index = indexOfFanpage(fanpage);
	pages[index] = nullptr;
	--pagesLogicSize;
	for (int i = index; i < pagesLogicSize; i++)
	{
		pages[i] = pages[i + 1];
	}
}

void User::addFanPageToUser1(FanPage* fanpage)
{
	if (pagesLogicSize == pagePhisSize)
	{
		pagePhisSize *= 2;
		FanPage** newPages = new FanPage * [pagePhisSize];
		for (int i = 0; i < pagesLogicSize; i++) 
		{
			newPages[i] = pages[i];
		}
		delete[]pages;
		pages = newPages;
	}
	pages[pagesLogicSize] = fanpage;
	pagesLogicSize++;
}

void User::showFriendPosts() const
{
	for (int i = 0; i < friendsLogicSize; i++)
	{
		cout << this->friends[i]->getName() << " post's: " << endl;;
		this->friends[i]->showPosts(10);
	}
}

void User::showFanPagePosts() const
{
	for (int i = 0; i < pagesLogicSize ; i++)
	{
		cout << this->pages[i]->getName() << " post's: " << endl;;
		this->pages[i]->showPosts(10);
	}
}

User::~User()
{
	delete[]name;
	for (int i = 0; i < postsLogicSize; i++) {
		delete posts[i];
	}
	delete[]posts;
	delete[]friends;
	delete[]pages;
}

void User::showFriends() const
{
	if (friendsLogicSize == 0)
	{
		cout << name << " has no friends for now.." << endl;
	}
	else
	{
		cout << name << " friends are: " << endl;
		for (int i = 0; i < friendsLogicSize; i++)
		{
			cout << "friend #" << i + 1 << " name is " << friends[i]->getName() << endl;
		}
	}

}

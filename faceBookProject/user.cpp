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
	name = user.name;
	birthday = Date(user.birthday);
	posts = new Status * [postPhisSize];
	friends = new User * [friendPhisSize];
	pages = new FanPage * [pagePhisSize];

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

void User::showPosts() const
{
	for (int i = 0; i < postsLogicSize; i++)
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
	return 0; 
}

void User::deleteFromFriends(User* other)
{
	int index = indexOfFriend(other);
	friends[index] = NULL;
	--friendsLogicSize;
	for (int i = index; i < friendsLogicSize; i++)
	{
		friends[i] = friends[i + 1];
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

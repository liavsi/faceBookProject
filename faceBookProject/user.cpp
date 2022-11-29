#define _CRT_SECURE_NO_WARNINGS
#include "user.h"

User::User(const char* name, Date birthday) : birthday(birthday)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->birthday = birthday;
	posts = new Status * [postPhisSize];
	friends = new User * [friendPhisSize];
	pages = new fanPage * [pagePhisSize];
}
User::User(const User& user)
{
	name = user.name;
	birthday = Date(user.birthday);
	posts = new Status * [postPhisSize];
	friends = new User * [friendPhisSize];
	pages = new fanPage * [pagePhisSize];

}

void User::showUser()
{

	cout << "User name: " << name << endl;
	cout << "birth date: ";	
	birthday.showDate();
	cout << endl;
}


const char* User::getName()
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

void User::showPosts()
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
	if (!isFriend(other))
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


bool User::isFriend(User* other)
{
	for (int i = 0; i < friendsLogicSize; i++)
	{
		if (friends[i] == other)
			return true;
	}
	return false;
}

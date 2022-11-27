#define _CRT_SECURE_NO_WARNINGS
#include "user.h"

User::User(const char* name, Date birthday)
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
	birthday = user.birthday;
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
	if (postsLogicSize == postsLogicSize)
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

void User::showUserDebuging()
{
	cout << "User name: " << name << endl;
	cout << "birth date: ";
	birthday.showDate();
	cout << endl;
	cout << "Post logical size: " << postsLogicSize << "| post physic size: " << postPhisSize << "\n" << "friends logic size : " << friendsLogicSize << "| friends physic size: " << friendPhisSize;
}

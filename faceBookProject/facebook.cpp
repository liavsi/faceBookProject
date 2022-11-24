#include "facebook.h"	
#define MAX_NAME_LEN 100
#define MAX_DATE_LEN 13

Facebook::Facebook()
{
	users = new User * [usersPhisSize];
	fanPage = new FanPage * [fanPagePhisSize];
}


void Facebook::addFriend()
{
	char username[MAX_NAME_LEN];
	char birthday[MAX_DATE_LEN];
	
	cout << "Enter username:" << endl;
	cin.getline(username,MAX_NAME_LEN);

	cout << "Enter birthday: (format DD.MM.YYYY)" << endl;

	cin.getline(birthday, MAX_DATE_LEN);
	User* newUser = new User(username, Date(birthday));
	addUserToUsers(newUser);
}

void Facebook::addFanPage()
{
	char pageName[MAX_NAME_LEN];

	cout << "Enter fan page name:" << endl;
	cin.getline(pageName, MAX_NAME_LEN);

	FanPage* newFanPage= new FanPage(pageName);
	addFanPageToFanPages(newFanPage);
}

void Facebook::addUserToUsers(User* newUser)
{
	if (usersLogicSize == usersPhisSize)
	{
		usersPhisSize *= 2;
		User** newUsers = new User * [usersPhisSize];
		for (int i = 0; i < usersLogicSize; i++) {
			newUsers[i] = users[i];
		}
		delete[]users;
		users = newUsers;
	}
	users[++usersLogicSize] = newUser;
}


void Facebook::addFanPageToFanPages(FanPage* newFanPage)
{
	if (fanPageLogicalSize == fanPagePhisSize)
	{
		fanPagePhisSize *= 2;
		FanPage** newFanPages = new FanPage * [fanPagePhisSize];
		for (int i = 0; i < fanPageLogicalSize; i++) {
			newFanPages[i] = fanPage[i];
		}
		delete[]fanPage;
		fanPage = newFanPages;
	}
	fanPage[++fanPageLogicalSize] = newFanPage;
}


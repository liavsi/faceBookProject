#include "facebook.h"	
#define MAX_NAME_LEN 100
#define MAX_DATE_LEN 13
#define EXIT 12

Facebook::Facebook()
{
	users = new User * [usersPhisSize];
	fanPage = new FanPage * [fanPagePhisSize];
}


void Facebook::addUser()
{
	char username[MAX_NAME_LEN];
	char birthday[MAX_DATE_LEN];
	
	cout << "Enter username:" << endl;
	cin.ignore();
	cin.getline(username,MAX_NAME_LEN);

	cout << "Enter birthday: (format DD.MM.YYYY)" << endl;

	cin.getline(birthday, MAX_DATE_LEN);
	User* newUser = new User(username, Date(birthday));
	addUserToUsers(newUser);
}

void Facebook::addUser(User user)
{
	User* newUser = new User(user);
	addUserToUsers(newUser);
}

void Facebook::addFanPage()
{
	char pageName[MAX_NAME_LEN];

	cout << "Enter fan page name:" << endl;
	cin.ignore();
	cin.getline(pageName, MAX_NAME_LEN);

	FanPage* newFanPage= new FanPage(pageName);
	addFanPageToFanPages(newFanPage);
}


void Facebook::startMenu()
{
	int choice;
	do
	{
		printMenu();
		cout << "Enter a number between 1 - 12: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			addUser();
			break;
		case 2:
			addFanPage();
			break;
		case 3:
			addStatus();
		case 5:
			showAllUsers();
			showAllFanPages();
		default:
			break;
		}
	} while (choice!=EXIT);
	


}

Facebook::~Facebook()
{
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
	users[usersLogicSize] = newUser;
	usersLogicSize++;
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
	fanPage[fanPageLogicalSize] = newFanPage;
	fanPageLogicalSize++;
}

void Facebook::printMenu()// to comlete
{
	cout << "\n1 - Add user to Facebook" << endl;
	cout << "2 - Add Fan Page to Facebook" << endl;
	cout << "3 - Add status for a user/fanpage on Facebook" << endl;
	cout << "4 - Show all status of a user/fanpage" << endl;
	cout << "5 - Show" << endl;
}

void Facebook::addStatus()
{
	int choice;
	cout << "1. User. \n2.Fan Page\n(Choose number): ";
	do
	{
		cin >> choice;
		if (choice == 1)
		{
			addStatusToUser();
		}
		else if (choice == 2)
		{
			addStatusToFanPage();
		}
	} while (choice != 1 && choice!=2);
	
	
	
	

}

void Facebook::addStatusToUser()
{
	char name[MAX_NAME_LEN];
	User* user;
	do
	{
		cout << "Which User do you want to add a Post to: ";
		cin >> name;
		user = findUserByName(name);

	} while (user == nullptr);
	user->addPost(new Status()); //c'tor build status from input text
	


}

void Facebook::addStatusToFanPage()
{
	char name[MAX_NAME_LEN];
	FanPage* fanPage;
	do
	{
		cout << "Which Fan Page do you want to add a Post to: ";
		cin >> name;
		fanPage = findFanPageByName(name);

	} while (fanPage == nullptr);
	fanPage->addPost(new Status()); //c'tor build status from input text



}

void Facebook::showAllUsers()
{
	for (int i = 0; i < usersLogicSize; i++)
	{
		cout << "User #" << i+1 << endl;
		users[i]->showUser();
		users[i]->showUserDebuging();
	}
}

void Facebook::showAllFanPages()
{
	for (int i = 1; i < fanPageLogicalSize+1; i++)
	{
		cout << "Fan Page #" << i << endl;
		fanPage[i]->showFanPage();
	}
}

User* Facebook::findUserByName(char* name)
{
	for (int i = 0; i < usersLogicSize; i++)
	{
		if (strcmp(users[i]->getName(), name) == 0)
		{
			return users[i];
		}
	}
	cout << "This name does not exist in our system..";
	return nullptr;
}

FanPage* Facebook::findFanPageByName(char* name)
{
	for (int i = 0; i < fanPageLogicalSize; i++)
	{
		if (fanPage[i]->getName() == name)
		{
			return fanPage[i];
		}
	}
	cout << "This name does not exist in our system..";
	return nullptr;
}


#include "facebook.h"	
#define MAX_NAME_LEN 100
#define MAX_DATE_LEN 13
#define EXIT 12
#define MAX_POST_LEN 151
Facebook::Facebook()
{
	users = new User * [usersPhisSize];
	fanPages = new FanPage * [fanPagePhisSize];
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

	cout << "Enter fan page name: ";
	cin.ignore();
	cin.getline(pageName, MAX_NAME_LEN);

	FanPage* newFanPage= new FanPage(pageName);
	addFanPageToFanPages(newFanPage);
}






//menu part

void Facebook::printMenu()
{
	cout << "\n1 - Add user to Facebook" << endl;
	cout << "2 - Add Fan Page to Facebook" << endl;
	cout << "3 - Add status for a user/fanpage on Facebook" << endl;
	cout << "4 - Show all status of a user/fanpage" << endl;
	cout << "5 - Show 10 updated post for a user" << endl;
	cout << "6 - Make 2 users friends" << endl;
	cout << "7 - Unfriend 2 users" << endl;
	cout << "8 - Make user a fan of a Fan Page" << endl;
	cout << "9 - Taking a user off of a Fan Page" << endl;
	cout << "10 - Show all users and fan page registred on facebook" << endl;
	cout << "11 - Show all friends of a user / Show all fans of a Fan Page" << endl;
	cout << "12 - Exit facebook" << endl;


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
			break;
		case 4:
			ShowPosts();
			break;
		case 5:
			ShowMostRecentPosts();
		case 10:
			showAllUsers();
			showAllFanPages();
		default:
			break;
		}
	} while (choice!=EXIT);
	


}

void Facebook::ShowMostRecentPosts()
{
	char name[MAX_NAME_LEN];
	User* user;
	do {
		cout << "Which user would you like to see his 10's recent post of his friends ? ";
		cin >> name;
		user = findUserByName(name);
		if (user == nullptr)
			cout << "This username does not exist in our system..";
	} while (user == nullptr);

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
			newFanPages[i] = fanPages[i];
		}
		delete[]fanPages;
		fanPages = newFanPages;
	}
	fanPages[fanPageLogicalSize] = newFanPage;
	fanPageLogicalSize++;
}



//add status

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
		if (user == nullptr)
			cout << "This username does not exist in our system..";

	} while (user == nullptr);
	char text[MAX_POST_LEN];
	cout << "Enter text for your post (max 150 letters):";
	cin.ignore();
	cin.getline(text, MAX_POST_LEN);
	/*
	time_t curr_time;
	curr_time = time(NULL);
	char* timeText = ctime(&curr_time);
	//time Text format "Www Mmm dd hh:mm:ss yyyy"
	*/
	user->addPost(new Status(text)); //c'tor build status from input text
	


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
		if(fanPage == nullptr)
			cout << "This user does not exist in our system..";

	} while (fanPage == nullptr);
	char text[MAX_POST_LEN];
	cout << "Enter text for your post (max 150 letters):";
	cin.ignore();
	cin.getline(text, MAX_POST_LEN);
	fanPage->addPost(new Status(text)); //c'tor build status from input text



}

//show posts of a user/fan page

void Facebook::ShowPosts()
{
	int choice;
	cout << "1. User. \n2.Fan Page\n(Choose number): ";
	do
	{
		cin >> choice;
		if (choice == 1)
		{
			showPostsOfUser();
		}
		else if (choice == 2)
		{
			showPostOfFanPage();
		}
	} while (choice != 1 && choice != 2);
}


void Facebook::showPostsOfUser()
{
	char name[MAX_NAME_LEN];
	User* user;
	do
	{
		cout << "Which User's post would you like to show: ";
		cin >> name;
		user = findUserByName(name);
		if (user == nullptr)
			cout << "This user does not exist in our system.." << endl;

	} while (user == nullptr);
	user->showPosts(); //c'tor build status from input text

}

void Facebook::showPostOfFanPage()
{
	char name[MAX_NAME_LEN];
	FanPage* fanPag;
	do
	{
		cout << "Which fan Page's post would you like to show: ";
		cin >> name;
		fanPag = findFanPageByName(name);
		if (fanPag == nullptr)
			cout << "This fanpage does not exist in our system.." << endl;

	} while (fanPag == nullptr);
	//fanPag->showPosts();
}
//show

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
		fanPages[i]->showFanPage();
	}
}




//helpers

User* Facebook::findUserByName(char* name)
{
	for (int i = 0; i < usersLogicSize; i++)
	{
		if (strcmp(users[i]->getName(), name) == 0)
		{
			return users[i];
		}
	}
	return nullptr;
}

FanPage* Facebook::findFanPageByName(char* name)
{
	for (int i = 0; i < fanPageLogicalSize; i++)
	{
		if (strcmp(fanPages[i]->getName(),name) == 0)
		{
			return fanPages[i];
		}
	}
	
	return nullptr;
}

Facebook::~Facebook()
{
}
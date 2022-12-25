#include "facebook.h"	

Facebook::Facebook()
{
	users.reserve(CAPACITY_INIT);
	fanPages.reserve(CAPACITY_INIT);
}

void Facebook::printMenu() const
{
	cout << "--------------Menu-----------------" << endl;
	cout << "\n1 - Add user to Facebook" << endl;
	cout << "2 - Add Fan Page to Facebook" << endl;
	cout << "3 - Add status for a user/fanpage on Facebook" << endl;
	cout << "4 - Show all status of a user/fanpage" << endl;
	cout << "5 - Show 10 recent posts for each friend of a user" << endl;
	cout << "6 - Make 2 users friends" << endl;
	cout << "7 - Unfriend 2 users" << endl;
	cout << "8 - Make user a fan of a Fan Page" << endl;
	cout << "9 - Taking a user off of a Fan Page" << endl;
	cout << "10 - Show all users and fan page registred on facebook" << endl;
	cout << "11 - Show all friends of a user / Show all fans of a Fan Page" << endl;
	cout << "12 - Exit facebook" << endl;
	cout << "-----------------------------------" << endl;


}


void Facebook::addUser()
{
	char username[MAX_NAME_LEN];
	char birthday[MAX_DATE_LEN];
	
	cout << "Enter username:" << endl;
	do
	{
		cin.getline(username, MAX_NAME_LEN);
	} while (username[0] == 0);
	cout << "Enter birthday: (format DD.MM.YYYY)" << endl;
	do
	{
		cin.getline(birthday, MAX_NAME_LEN);
	} while (birthday[0] == 0);
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
	string pageName;

	cout << "Enter fan page name: ";
	do {//to avoid empty words becuase of getline
		
	}
	while (pageName[0] == 0);
	FanPage* newFanPage= new FanPage(pageName);
	addFanPageToFanPages(newFanPage);
}

void Facebook::addFanPage(FanPage fanpage)
{
	FanPage* newFanPage = new FanPage(fanpage);
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
			break;
		case 4:
			ShowPosts();
			break;
		case 5:
			ShowMostRecentPosts();
			break;
		case 6:
			makeConnection();
			break;
		case 7:
			disConnect();
			break;
		case 8:
			addFriendToFanPage(); 
			break;
		case 9:
			disConnectFriendAndFanPage();
			break;
		case 10:
			showAllUsers();
			showAllFanPages();
			break;
		case 11:
			showAllFriendFansOFUser();
			break;
		default:
			cout <<"Thank you for using facebook\nGoodbye";
			break;
		}
	} while (choice != EXIT_MENU);

}

void Facebook::ShowMostRecentPosts() const
{
	char name[MAX_NAME_LEN];
	const User* user;
	user = getUserNameFromUser("for which user do you want to see friend's recent posts: ");
	user->showFriendPosts();
	user->showFanPagePosts();

}

void Facebook::makeConnection()
{
	User* user1, *user2;
	user1 = getUserNameFromUser("please enter first user's name: ");
	user2 = getUserNameFromUser("please enter second user's name: ");
	user1->addFriend(*user2);
}

void Facebook::makeConnection(User& user1, User& user2)//manually added
{
	user1.addFriend(user2);
}

void Facebook::disConnect()
{
	User* user1, * user2;
	user1 = getUserNameFromUser("please enter first user's name: ");
	user2 = getUserNameFromUser("please enter second user's name: ");
	user1->unFriend(*user2);
}


void Facebook::disConnectFriendAndFanPage()
{
	User* user = getUserNameFromUser("please enter user's name: ");
	FanPage* fanpage = getFanpageFromUser("please enter fanpage's name: ");
	user->removeFanPage(*fanpage);
}

void Facebook::addFriendToFanPage()
{
	User* user = getUserNameFromUser("please enter user's name: ");
	FanPage* fanpage = getFanpageFromUser("please enter fanpage's name: ");
	user->addFanpage(*fanpage);
}


void Facebook::removeUserFromFanPage()
{
	User* user = getUserNameFromUser("please enter user's name: ");
	FanPage* fanpage = getFanpageFromUser("please enter fanpage's name: ");
	user->removeFanPage(*fanpage);
}

void Facebook::showFriendsOfUser() const
{
	const User* user = getUserNameFromUser("please enter user's name: ");
	user->showFriends();
}

void Facebook::showFansOfFanPage() const
{
	const FanPage* fanpage = getFanpageFromUser("please enter fanpage's name: ");
	fanpage->showFans();
}

void Facebook::addFriendToFanPage(User& user, FanPage& fanpage)
{
	user.addFanpage(fanpage);
}


void Facebook::initializeFacebook()
{
	this->addUser(User("liav", Date()));
	this->addUser(User("sharon", Date()));
	this->addUser(User("keren", Date()));
	this->addFanPage(FanPage("hapoeel beer sheva fans"));
	this->addFanPage(FanPage("one direction fan page"));
	this->addFanPage(FanPage("sharon pais fans club"));
	this->fanPages[0]->addPost(new Status("we are the best"));
	this->fanPages[0]->addPost(new Status("we won the game"));
	this->fanPages[1]->addPost(new Status("thats what makes you beutiful"));
	this->fanPages[1]->addPost(new Status("la la la"));
	this->fanPages[2]->addPost(new Status("he lives in Tel aviv "));
	this->fanPages[2]->addPost(new Status("he is developer.."));
	this->users[0]->addPost(new Status("hi guys im liav"));
	this->users[0]->addPost(new Status("C++ is nice and I'm a nerd"));
	this->users[1]->addPost(new Status("hi guys im sharon"));
	this->users[1]->addPost(new Status("sharon is my name "));
	this->users[2]->addPost(new Status("dont trust _s functions"));
	this->users[2]->addPost(new Status("give me cake please!"));
	makeConnection(*users[1], *users[0]);
	makeConnection(*users[0], *users[2]);
	addFriendToFanPage(*(users[2]), *(fanPages[1]));
	addFriendToFanPage(*(users[1]), *(fanPages[1]));
	addFriendToFanPage(*(users[0]), *(fanPages[1]));




}



void Facebook::addUserToUsers(User* newUser)
{
	users.push_back(newUser);
}


void Facebook::addFanPageToFanPages(FanPage* newFanPage)
{
	fanPages.push_back(newFanPage);
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
	User* user = getUserNameFromUser("Which User do you want to add a Post to: ");
	string text;
	cout << "Enter text for your post (max 150 letters):";
	do//to avoid empty words becuase of getline
		getline(cin, text);
	while (text[0] == 0);
	user->addPost(new Status(text)); //c'tor build status from input text

}

void Facebook::addStatusToFanPage()
{
	FanPage* fanPage = getFanpageFromUser(
		"Which Fan Page do you want to add a Post to : ");
	char text[MAX_POST_LEN];
	cout << "Enter text for your post (max 150 letters):";
	do//to avoid empty words becuase of getline
		cin.getline(text, MAX_NAME_LEN);
	while (text[0] == 0);
	fanPage->addPost(new Status(text)); //c'tor build status from input text



}

//show posts of a user/fan page

void Facebook::ShowPosts() const
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


void Facebook::showPostsOfUser() const
{
	const User* user = getUserNameFromUser("Which User do you want to add a Post to: ");
	user->showPosts();
}

void Facebook::showPostOfFanPage()  const
{
	const FanPage* fanpage = getFanpageFromUser("Which fan Page's post would you like to show: ");
	fanpage->showPosts();
}

void Facebook::showAllUsers()  const
{
	for (int i = 0; i < users.size(); i++)
	{
		cout << "User #" << i+1 << endl;
		users[i]->showUser();
	}
}

void Facebook::showAllFanPages()  const
{
	for (int i = 0; i < fanPages.size(); i++)
	{
		cout << "Fan Page #" << i+1 << endl;
		fanPages[i]->showFanPage();
	}
}




//helpers

FanPage* Facebook::findFanPageByName(string name) 
{
	for (int i = 0; i < fanPages.size(); i++)
	{
		if (fanPages[i]->getName() == name)
		{
			return fanPages[i];
		}
	}
	
	return nullptr;
}

const FanPage* Facebook::findFanPageByName(string name) const
{
	for (int i = 0; i < fanPages.size(); i++)
	{
		if (fanPages[i]->getName() == name)
		{
			return fanPages[i];
		}
	}

	return nullptr;
}

User* Facebook::findUserByName(string name) 
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i]->getName() == name)
		{
			return users[i];
		}
	}
	return nullptr;
}

const User* Facebook::findUserByName(string name) const
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i]->getName() == name)
		{
			return users[i];
		}
	}
	return nullptr;
}

void Facebook::showAllFriendFansOFUser()  const
{
	int choice;
	cout << "1. User. \n2.Fan Page\n(Choose number): ";
	do
	{
		cin >> choice;
		if (choice == 1)
		{
			showFriendsOfUser();
		}
		else if (choice == 2)
		{
			showFansOfFanPage();
		}
	} while (choice != 1 && choice != 2);
}

User* Facebook::getUserNameFromUser(const string text) 
{
	string name;
	User* user;
	do
	{
		cout << text;
		do//to avoid empty words becuase of getline
			getline(cin, name);
		while (name[0] == 0);
		user = findUserByName(name);
		if (user == nullptr)
			cout << "This user does not exist in our system.." << endl;

	} while (user == nullptr);
	return user;
}

const User* Facebook::getUserNameFromUser(const string text) const
{
	string name;
	const User* user;
	do
	{
		cout << text;
		do//to avoid empty words becuase of getline
			getline(cin, name);
		while (name[0] == 0);
		user = findUserByName(name);
		if (user == nullptr)
			cout << "This user does not exist in our system.." << endl;

	} while (user == nullptr);
	return user;
}

FanPage* Facebook::getFanpageFromUser(const string text) 
{
	string name;
	FanPage* fanPage;
	do
	{
		cout << text;
		do//to avoid empty words becuase of getline
			getline(cin, name);
		while (name[0] == 0);	

		fanPage = findFanPageByName(name);
		if (fanPage == nullptr)
			cout << "This fan page does not exist in our system..";
	} while (fanPage == nullptr);
	return fanPage;
}

const FanPage* Facebook::getFanpageFromUser(string text) const
{
	string name;
	const FanPage* fanPage;
	do
	{
		cout << text;
		do//to avoid empty words becuase of getline
			getline(cin, name);
		while (name[0] == 0);

		fanPage = findFanPageByName(name);
		if (fanPage == nullptr)
			cout << "This fan page does not exist in our system..";

	} while (fanPage == nullptr);
	return fanPage;
}



Facebook::~Facebook()
{
	for (int i = 0; i < users.size(); i++) 
	{
		delete users[i];
	}
	for (int i = 0; i < fanPages.size(); i++)
	{
		delete fanPages[i];
	}
}
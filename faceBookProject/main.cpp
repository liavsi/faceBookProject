#include "facebook.h"
using namespace std;
int main()
{
	string filename = "";
	Facebook facebook;
	facebook.initializeFacebook(); //mannualy added 3 Users 3 FanPages and each with 2 Posts and -
	//all of them are friends and "fans" of one direction
	facebook.startMenu();

	facebook.saveData(filename);
	return 0;
}
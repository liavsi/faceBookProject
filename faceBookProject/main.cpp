#include "facebook.h"
using namespace std;
int main()
{
	string filename = "data.txt";
	Facebook facebook;
	facebook.initializeFacebook(); //mannualy added 3 Users 3 FanPages and each with 2 Posts and -
	//all of them are friends and "fans" of one direction
	try
	{
		facebook.startMenu();
	}
	catch (FaceBookExeption& e)
	{
		facebook.saveData(filename);
		cout << e.what();
	}
	facebook.saveData(filename);
	return 0;
}
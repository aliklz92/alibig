//***********
//Alireza Bigdeli - Hassan Khan
//This is the driver function for PasswordManager
// The main function allows the user to change the password.
//***********

#include <string>
#include <iostream>
#include <fstream>
#include<sstream>
#include<cstring>
#include "PasswordManager.h"

using namespace std;

int main()
{
	string oldpas;
	PasswordManager pwMan[3];
	string username;
	string newpassword;
	string origPass;
	//file input and output
	ifstream fin;
	fin.open("passwords.txt");

	if (fin.fail()) {

		cout << "Unable to open file" << endl;

		return 0;

	}
	//Loop that takes up to 3 user names with encrypted passwords and sets them into the manager array
	for (int i = 0;i < 3;i++)
	{
		fin >> username >> origPass;
		pwMan[i].setUsername(username);
		pwMan[i].setEncryptedPassword(origPass);

	}
	//Loop that takes up to 3 user names with encrypted passwords and sets them into the manager array

	for (int i = 0;i < 3;i++)
	{
		cout << pwMan[i].getUsername() << "  " << pwMan[i].getEncryptedPassword() << endl;
	}
	fin.close();

	cout << "Please enter your username:  ";
	cin >> username;

	cout << "Please enter your old password:  ";
	cin >> origPass;

	cout << "Please enter your new password:  ";
	cin >> newpassword;

	bool userNameFound = false;
	//loop that checks if password meets criteria
	for (int i = 0;i < 3;i++)
	{
		char un[1024], gun[1024];
		string unn = pwMan[i].getUsername();

		strncpy(un, username.c_str(), sizeof(un));
		strncpy(gun, unn.c_str(), sizeof(gun));

		if (strcmp(un, gun) == 0)
		{
			cout << "inside 1 if " << endl;
			userNameFound = true;
			if (pwMan[i].authenticate(origPass))
			{
				cout << "inside 2 if " << endl;
				if (pwMan[i].setNewPassword(newpassword))
				{

					cout << "Password changed for netid : " << pwMan[i].getUsername() << endl << endl;
				}
				else
					cout << "New Password does not meet criteria." << endl;
			}
			else
				cout << " Old password is incorrect." << endl;

		}

	}
	if (!userNameFound)
	{
		cout << "NetID is invalid, password not changed." << endl;
	}
	ofstream fout;
	fout.open("passwords.txt");
	for (int i = 0;i < 3;i++)
	{
		pwMan[i].getEncryptedPassword();

		fout << pwMan[i].getUsername() << " " << pwMan[i].getEncryptedPassword() << endl;




	}

	fout.close();


}

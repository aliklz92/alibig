//
//  PasswordManager.cpp
//  PasswordManager
//
#include <string>
#include <iomanip>
#include<cstring>
using namespace std;
#include "PasswordManager.h"
//**************************
//The function setUsername is a setter function from passwordManager.h
//It has a parameter of a username. It does not return anything.
//**************************
void PasswordManager::setUsername(string user) {

	username = user;
}
//**************************
//The function setEncryptedPassword is a setter function from passwordManager.h It has a parameter of the new password.
//It takes a proposed password and encrypts it one it has been validated.
//It does not return anything.
//**************************
void PasswordManager::setEncryptedPassword(string EncryptPass)
{
	enc_pass = EncryptPass;
}
//***********************************
//The setter function getUsername does not have a paramter
//It returns the username
//****************************************
string PasswordManager::getUsername() const {
	return username;
}
//************************************************************
//The setter function getEncryptedPassword does not take a paramater.
//It returns the encrypted password
//***********************************************************
string PasswordManager::getEncryptedPassword() const {
	return enc_pass;
}
//**************************************
//The setter function authetnticate takes in a string as its parameter
//it returns true if the new password meets criteria.
//*************************************
bool PasswordManager::authenticate(string setPass)
{

	string newpassword;
	int count = 0;
	bool passFail = false;
	char tempold[1024], tempnew[1024];
	string oldp;
	oldp = getEncryptedPassword();
	if (meetCriteria(setPass))
	{
		newpassword = encrypt(setPass);
		strncpy(tempold, newpassword.c_str(), sizeof(tempold));
		strncpy(tempnew, oldp.c_str(), sizeof(tempnew));
		if (strcmp(tempold, tempnew) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else
	{
		return false;
	}
}
//*************************************
//The setter function setNewPassword uses a string as its parameter
//It returns a string if it meets criteria.
//**************************************
bool PasswordManager::setNewPassword(string setPass)
{
	string newPassword;
	int i = 0;
	if (meetCriteria(setPass))
	{
		newPassword = encrypt(setPass);
		setEncryptedPassword(newPassword);
		return true;
	}
	else
	{
		return false;
	}
}
//********************************************
//The setter function encrypt has a parameter of a new password
//and returns a string containing the encrypted password
//********************************************
string PasswordManager::encrypt(string password) {

	string result = "";
	int ascv;
	for (int i = 0; i < password.length(); i++)
	{
		ascv = int(password[i]);
		ascv = (ascv - 33) + 25;
		ascv %= 94;
		ascv += 33;
		result = result + ((char)ascv);
	}

	return result;
}
//*************************************
//The setter function meetCriteria takes a password as it's parameter
//It will check if the password meets all the requirements and then return
//true if it is correct
//************************************
bool PasswordManager::meetCriteria(string password) {
	if (password.size() < 8)
		return false;

	int digit = 0;
	int upper = 0;
	int lower = 0;

	for (int i = 0; i < password.size(); i++) {
		if (isupper(password[i]))
			++upper;

		if (islower(password[i]))
			++lower;

		if (isdigit(password[i]))
			++digit;
	}
	return (digit >= 1 && upper >= 1 && lower >= 1);
}

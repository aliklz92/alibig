#pragma once
//
//  PasswordManager.h
//  PasswordManager


#include <string>
#include<iostream>
using namespace std;

class PasswordManager
{
private:
	string username;
	string enc_pass;
	string encrypt(string);
	bool meetCriteria(string);
public:
	void setUsername(string);
	void setEncryptedPassword(string);
	string getUsername() const;
	string getEncryptedPassword() const;
	bool setNewPassword(string);
	bool authenticate(string);
};


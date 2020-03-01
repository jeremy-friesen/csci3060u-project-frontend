#pragma once
#include <string.h>
//#include "CurrentUserAccountsFileManager.cpp"
//#include "AvailableItemsFileManager.cpp"
#include "DailyTransactionFileManager.cpp"
#include "AvailableItemsFileManager.cpp"
//#include "Item.cpp"
#include <iostream>

using namespace std;

//Description: Abstract super class that defines every other account type
//Contains information and functions that every user uses
//Inputs: The user’s unique username, the user’s user type (admin, full-standard, etc)
class User{
	
public:
	string username;
	string userType;
	int userID;
	
	bool isLoggedIn();

	void logout();

	virtual void bid();

	virtual void advertise();

	virtual void createUser();

	virtual void deleteUser();

	virtual void refund();

	//Returns the username of the account as a string
	string getUsername();
	
	//Returns the type of user as a string
	string getUserType();
	
	//Returns the ID of the user as an integer
	int getUserID();
	
	//Returns the amount of credits the account holds as double
	double getCredits();
	
	//Add credit to their own account
	void addCredit();
	
	//Constructors
	User(string username, string userType);

	User(string username, string userType, double credit);

	//Default Constructor
	User();

	//Sets the amount of credits that the account holds
	void setCredits(double credits);

protected:
	bool loggedIn;
	double credit;

	//Sets the name of the user
	void setUserName(string username);
 
	//Sets the user type of the account
	void setUserType(string userType);

	//Sets the ID of the user
	void setUserID(int userID);
};

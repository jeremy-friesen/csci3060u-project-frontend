#pragma once
#include <string.h>
#include <string>
//#include "User.cpp"
#include "Admin.cpp"
#include "FullStandard.cpp"
#include "BuyStandard.cpp"
#include "SellStandard.cpp"
#include <iostream>
#include <fstream>

using namespace std;

//Description: Manages and updates data in the Current User Accounts File
//Contains the transaction lines for all users in the system
//Inputs
class CurrentUserAccountsFileManager{
	
	//Prints a summary of the data currently stored
	void printSummary(){
		//TODO
  }

public:
  static string fileName;

  static void setFileName(string filename);
  
	//Processes a login request from the menu and determines if the user exists
	static User* login(string username);

	// helper function to determine if a CurrentUserAccounts 
	// file line matches a given username
	static bool isUser(string line, string username);

	// helper function to parse user type
	static string parseUserType(string line);

	// helper function to parse user credit
	static double parseCredit(string line);
	
	//Finding existing user in Current User Accounts File
	static User* findUser(string username);
};
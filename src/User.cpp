#include <string.h>
//#include "CurrentUserAccountsFileManager.cpp"
//#include "AvailableItemsFileManager.cpp"
#include <iostream>

using namespace std;

//Description: Abstract super class that defines every other account type
//Contains information and functions that every user uses
//Inputs: The user’s unique username, the user’s user type (admin, full-standard, etc)
class User{
	
public:
	string userName;
	string userType;
	int userID;
	
	bool isLoggedIn(){
		//return loggedIn; ----------change back
		return userName != "";
	}

	void logout(){
		userName = "";
		userType = "";
		userID = 0;
		loggedIn = false;
	}

	void bid(){
		cout << "You can't bid" << endl;
	}

	void advertise(){
		cout << "You can't advertise" << endl;
	}

	void createUser(){
		cout << "You can't create users" << endl;
	}

	void deleteUser(){
		cout << "You can't delete users" << endl;
	}

	void refund(){
		cout << "You can't make refunds" << endl;
	}

	//Returns the username of the account as a string
	string getUsername(){
		return userName;
	}
	
	//Returns the type of user as a string
	string getUserType(){
		return userType;
	}
	
	//Returns the ID of the user as an integer
	int getUserID(){
		return userID;
	}
	
	//Returns the amount of credits the account holds as double
	double getCredits(){
		return credit;
	}
	
	//Add credit to their own account
	void addCredit(){
		double amount;
		cout << "Enter the amount of credits you would like ";
		cout << "to add to your account" << endl;
		cin >> amount;
		
		credit += amount;
	}
	
	//Constructors
	User(string userName, string userType){
		this->userName = userName;
		this->userType = userType;
	}

	User(string userName, string userType, double credit){
		this->userName = userName;
		this->userType = userType;
		this->credit = credit;
	}

	//Default Constructor
	User(){
		this->userName = "";
		this->userType = "";
		this->credit = 0;
	}

	//Sets the amount of credits that the account holds
	void setCredits(double credits){
		this->credit = credit;
	}

protected:
	bool loggedIn;
	double credit;

	//Sets the name of the user
	void setUserName(string userName){
		this->userName = userName;
	}
 
	//Sets the user type of the account
	void setUserType(string userType){
		this->userType = userType;
	}

	//Sets the ID of the user
	void setUserID(int userID){
		this->userID = userID;
	}
};

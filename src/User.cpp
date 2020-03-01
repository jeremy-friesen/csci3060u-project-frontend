#pragma once
#include "User.h"

//Description: Abstract super class that defines every other account type
//Contains information and functions that every user uses
//Inputs: The user’s unique username, the user’s user type (admin, full-standard, etc)

string username;
string userType;
int userID;
	
bool User::isLoggedIn(){
	//return loggedIn; ----------change back
	return username != "";
}

void User::logout(){
	username = "";
	userType = "";
	userID = 0;
	loggedIn = false;
}

/*
void User::bid(){
	cout << "You can't bid" << endl;
}

void User::advertise(){
	cout << "You can't advertise" << endl;
}

void User::createUser(){
	cout << "You can't create users" << endl;
}

void User::deleteUser(){
	cout << "You can't delete users" << endl;
}

void User::refund(){
	cout << "You can't make refunds" << endl;
}
*/

//Returns the username of the account as a string
string User::getUsername(){
	return username;
}
	
//Returns the type of user as a string
string User::getUserType(){
	return userType;
}
	
//Returns the ID of the user as an integer
int User::getUserID(){
	return userID;
}
	
//Returns the amount of credits the account holds as double
double User::getCredits(){
	return credit;
}
	
//Add credit to their own account
void User::addCredit(){
	double amount;
	cout << "Enter the amount of credits you would like ";
	cout << "to add to your account" << endl;
	cin >> amount;
		
	credit += amount;
}
	
//Constructors
User::User(string username, string userType){
	this->username = username;
	this->userType = userType;
}

User::User(string username, string userType, double credit){
	this->username = username;
	this->userType = userType;
	this->credit = credit;
}

//Default Constructor
User::User(){
	this->username = "";
	this->userType = "";
	this->credit = 0;
}

//Sets the amount of credits that the account holds
void User::setCredits(double credits){
	this->credit = credit;
}


bool loggedIn;
double credit;

//Sets the name of the user
void User::setUserName(string username){
	this->username = username;
}
 
//Sets the user type of the account
void User::setUserType(string userType){
	this->userType = userType;
}

//Sets the ID of the user
void User::setUserID(int userID){
	this->userID = userID;
}

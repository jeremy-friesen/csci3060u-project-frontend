#pragma once
#include "CurrentUserAccountsFileManager.h"

//Description: Manages and updates data in the Current User Accounts File
//Contains the transaction lines for all users in the system
//Inputs
	
//Prints a summary of the data currently stored
void printSummary(){
	//TODO
}

string CurrentUserAccountsFileManager::fileName = "currentusers.txt";

void CurrentUserAccountsFileManager::setFileName(string filename){
	fileName = filename;
}

//Processes a login request from the menu and determines if the user exists
User CurrentUserAccountsFileManager::login(string username){
	User user = findUser(username);
	cout << "getUsername(): " << user.getUsername() << endl;
	if(user.getUsername() != ""){
		cout << "Login successful." << endl;
		return user;
	}else{
		cout << "Login unsuccessful. No user with that name exists.\n";
		return user;
	}
}

// helper function to determine if a CurrentUserAccounts
// file line matches a given username
bool CurrentUserAccountsFileManager::isUser(string line, string username){
	int l = username.length();
	if(line.substr(0,l) == username){
		string leftOverChars = line.substr(l+1,15-l);
		for(int i = 0; i < leftOverChars.length(); i++){
			if(leftOverChars[i] != ' ')
				return false;
		}
		return true;
	}
	return false;
}

// helper function to parse user type
string CurrentUserAccountsFileManager::parseUserType(string line){
	return line.substr(16,2);
}

// helper function to parse user credit
double CurrentUserAccountsFileManager::parseCredit(string line){
	return stod(line.substr(20,9));
}

//Finding existing user in Current User Accounts File
User CurrentUserAccountsFileManager::findUser(string username){
	ifstream in(fileName);
	string line;
	int l = username.length();
	cout << fileName << endl;

	if (in.is_open()){
		while(getline(in,line)){
			cout << "line: \"" << line << "\"" << endl;
			if(isUser(line, username)){
				cout << "isUser passed" << endl;
				string type = parseUserType(line);
				cout << "parsedUserType: " << type << endl;
				double credit = parseCredit(line);
				if(type == "AA"){
					cout << "logged in admin:" << username << ", " << credit << endl;
					return Admin(username, credit);
				} else if(type == "FS"){
					return FullStandard(username, credit);
				} else if(type == "BS"){
					return BuyStandard(username, credit);
				} else if(type == "SS"){
					return SellStandard(username, credit);
				}
			}
		}
		in.close();
	}else{
		cout << "failed" << endl;
		strerror(errno);
	}
	//cout << "CurrentUserAccountsFileManager::findUser : No user found" << endl;
	return User("","",0);
}
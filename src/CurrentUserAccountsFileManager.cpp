#include <String>
#include <string.h>
#include "User.cpp"
#include <iostream>
#include <fstream>

using namespace std;

//Description: Manages and updates data in the Current User Accounts File
//Contains the transaction lines for all users in the system
//Inputs
static class CurrentUserAccountsFileManager{
	
	//Prints a summary of the data currently stored
	void printSummary(){
		//TODO
  }

public:
	//Processes a login request from the menu and determines if the user exists
	static User login(string username){
		User user = findUser(username);
		if(!user){
			cout << "Login unsuccessful. No user with that name exists.\n";
			return user;
		}
		else{
      cout << "Login successful." << endl;
			User user(username, credit, type);
			return user;
		}
	}
	
	//Finding existing user in Current User Accounts File
	static User findUser(string username){
		ifstream in("current_user_accounts");
		string line;
 		if (in.is_open()){
      while ( getline (myfile,line)){
      	if(line.substr(0,15) == username){
			    return new User(username, type, credit);
		    }
      }
      in.close();
    }
  }
}


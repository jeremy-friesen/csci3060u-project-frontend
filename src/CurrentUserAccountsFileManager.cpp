#include <string.h>
#include <string>
#include "User.cpp"
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
	//Processes a login request from the menu and determines if the user exists
	static User login(string username){
		User user = findUser(username);
		if(user.getUsername() != ""){
			cout << "Login unsuccessful. No user with that name exists.\n";
			return user;
		}else{
      cout << "Login successful." << endl;
			//User user(username, credit, type);
			return user;
		}
	}
	
	//Finding existing user in Current User Accounts File
	static User findUser(string username){
		ifstream in("current_user_accounts");
		string line;
 		if (in.is_open()){
      while (getline(in,line)){
      	if(line.substr(0,15) == username){
					//TODO
					string type = "idk";
					double credit = 0;
			    return  User(username, type, credit);
		    }
      }
      in.close();
    }
		cout << "CurrenUserAccountsFileManager::findUser : No user found" << endl;
		return User("","",0);
	}

	//TODO
	static void deleteUser(string username){
		return;
	}
};
 
//Description: Manages and updates data in the Current User Accounts File
//Contains the transaction lines for all users in the system
//Inputs
#include <iostream>
#include <fstream>
static class CurrentUserAccountsFileManager{
	
	//Prints a summary of the data currently stored
	void printSummary(){
 
  }
	
	//Processes a login request from the menu and determines if the user exists
	User login(string username){
		User user = findUser(username);
		if(!user){
			cout << “Login unsuccessful. No user with that name exists.\n”;
			return user;
		}
		else{
      cout << “Login successful.” << endl;
      return new User(username, credit, type);
		}
	}
	
	//Finding existing user in Current User Accounts File
	User findUser(string username){
		ifstream in(“current_user_accounts”)
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


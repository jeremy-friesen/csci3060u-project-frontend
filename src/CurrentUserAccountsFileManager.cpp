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
	//Processes a login request from the menu and determines if the user exists
	static User login(string username){
		User user = findUser(username);
		if(user.getUsername() != ""){
			cout << "Login unsuccessful. No user with that name exists.\n";
			return user;
		}else{
      cout << "Login successful." << endl;
			return user;
		}
	}

	// helper function to determine if a CurrentUserAccounts 
	// file line matches a given username
	static bool isUser(string line, string username){
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
	static string parseUserType(string line){
		return line.substr(17,2);
	}

	// helper function to parse user credit
	static double parseCredit(string line){
		return stod(line.substr(20,9));
	}
	
	//Finding existing user in Current User Accounts File
	static User findUser(string username){
		ifstream in("CurrentUserAccounts.txt");
		string line;
		int l = username.length();

 		if (in.is_open()){
      while(getline(in,line)){
      	if(isUser(line, username)){
					string type = parseUserType(line);
					double credit = parseCredit(line);
					if(type == "AA"){
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
    }
		//cout << "CurrentUserAccountsFileManager::findUser : No user found" << endl;
		return User("","",0);
	}
};
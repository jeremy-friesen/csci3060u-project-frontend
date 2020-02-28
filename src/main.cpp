//Description: Class for which users will enter in commands that correspond with       
//their privileges
//Contains functions that execute user commands
#include <string.h>
#include "CurrentUserAccountsFileManager.cpp"
#include <iostream>

using namespace std;


//class Main{

//public:
  string userCommand;
  User* user = new User();
  //Presents the login screen to the user
  void login(){
    if(user->isLoggedIn()){
      cout << "Can’t login.User already logged in." << endl;
      return;
    }
    string username;
    cout << "Enter Username :";
    cin >> username;
    *user = CurrentUserAccountsFileManager::login(username);
    if(user->isLoggedIn()){
      cout << "Logged in successfully." << endl;
    } else{
      cout << "Login unsuccessful." << endl;
    }
  }

  //Logs the user out of their account
  void logout(){
    cout << "Thank you for visiting! Goodbye!" << endl;
    user->logout();
  }

  //Admin: Can add credit to another user’s account or to their own account
  //Else: Can add credit to their own account
  void addCredit(){
    user->addCredit();
  }

  //Displays all options available to the user based on their account
  void printMenu(){
    cout << "login" << endl;
    cout << "logout" << endl;

    if (user->getUserType() == "admin"){
      cout << "create user" << endl;
      cout << "delete user" << endl;
      cout << "bid" << endl;
      cout << "advertise" << endl;
      cout << "refund" << endl;
    }

    else if (user->getUserType() == "standard - full" || user->getUserType() == "standard - buy"){
      cout << "bid" << endl;
    }

    if (user->getUserType() == "standard - full" || user->getUserType() == "standard - sell"){
      cout << "advertise" << endl;
    }

    cout << "add credit" << endl;
  }


//protected:
  //Users who are not of type standard-sell can bid
  void bid(){
    if (user->getUserType() != "standard-sell"){
      user->bid();
    }else{
      cout << "Insufficient privileges." << endl;
    }
  }

  //Users who are not of type standard-sell can bid
  void advertise(){
    if (user->getUserType() != "standard-buy"){
      user->advertise();
    }else{
      cout << "Insufficient privileges." << endl;
    }
  }

  //Allows Admin to create new users
  void createUser(){
    if (user->getUserType() == "admin"){
      user->createUser();
    }else{
      cout << "Insufficient privileges." << endl;
    }
  }

  //Allows Admin to delete pre-existing users
  void deleteUser(){
    if (user->getUserType() == "admin"){
      user->deleteUser();
    }else{
      cout << "Insufficient privileges." << endl;
    }
  }

  //Allows an admin to issue credit from a buyer’s account to a seller’s account
  void refund(){
    if (user->getUserType() == "admin"){
      user->refund();
    }else{
      cout << "Insufficient privileges." << endl;
    }
  }

//};

int main(){
  while (true){
    cout << "Enter a command :" << endl;
    cin >> userCommand;
    if (!user->isLoggedIn() && userCommand != "login"){
      //cout << "here" << endl;
      cout << "Cannot process request, no user is logged in.\n";
    }else{
      //cout << "here" << endl;
      if(userCommand == "login"){
        login();
      }else if(userCommand == "add credit"){
        addCredit();
      }else if(userCommand == "bid"){
        bid();
      }else if(userCommand == "advertise"){
        advertise();
      }else if(userCommand == "create user"){
        createUser();
      }else if(userCommand == "delete user"){
        deleteUser();
      }else if(userCommand == "refund"){
        refund();
      }else if(userCommand == "help"){
        printMenu();
      }else if(userCommand == "logout"){
        logout();
      }else{
        cout << "Unrecognized command entered."
            << "Please re - enter.\n";
      }
    }
  }
}
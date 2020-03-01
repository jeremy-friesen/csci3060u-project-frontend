//Description: Class for which users will enter in commands that correspond with       
//their privileges
//Contains functions that execute user commands
#include <string>
#include <string.h>
#include "CurrentUserAccountsFileManager.cpp"
#include <iostream>

using namespace std;

string userCommand;
User* user = new User();

//Presents the login screen to the user
void login();

//Logs the user out of their account
void logout();

//Admin: Can add credit to another user’s account or to their own account
//Else: Can add credit to their own account
void addCredit();

//Displays all options available to the user based on their account
void printMenu();

//protected:
//Users who are not of type standard-sell can bid
void bid();

//Users who are not of type standard-sell can bid
void advertise();

//Allows Admin to create new users
void createUser();

//Allows Admin to delete pre-existing users
void deleteUser();

//Allows an admin to issue credit from a buyer’s account to a seller’s account
void refund();

int main(int argc, char* argv[]){
  // setting file i/o files from command line
  if(argc > 3){
    CurrentUserAccountsFileManager::setFileName(argv[1]);
    AvailableItemsFileManager::setFileName(argv[2]);
    DailyTransactionFileManager::setFileName(argv[3]);
  } else if(argc > 2){
    CurrentUserAccountsFileManager::setFileName(argv[1]);
    AvailableItemsFileManager::setFileName(argv[2]);
  } else if(argc > 1){
    CurrentUserAccountsFileManager::setFileName(argv[1]);
  }

  /// Transaction Loop
  while (true){
    cout << "Enter Transaction:" << endl;
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
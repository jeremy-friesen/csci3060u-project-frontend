#include <String>
#include <string.h>
#include "User.cpp"
#include "CurrentUserAccountsFileManager.cpp"
#include "AvailableItemsFileManager.cpp"
#include <iostream>

using namespace std;

//Description: Class to represent Admin user
//Contains functions only Admin users can use
class Admin : public User{

  //Creating new users
  void createUser(){
    string name;
    string type;

    cout << "Enter a username for the new account" << endl;
    cin >> name;
    cout << "Enter type of user" << endl;
    cin >> type;

    User newUser(userName, userType);
  }

  //Deleting pre-existing users
  void deleteUser(){
    string name;
    cout << "Enter the account name to delete " << endl;
    cin >> name;
    CurrentUserAccountsFileManager::deleteUser(name);
  }

  //Adding credit to another user in the system
  void addCredit(){
    string name;
    double amount;

    cout << "Enter the account’s username you wish to add credit to : ";
    cin >> name;
    cout << "Enter credit amount : " << endl;
    cin >> amount;

    User user = CurrentUserAccountsFileManager::findUser(userName);
    double balance = user.getCredits;
    balance += amount;
    user.setCredits(balance);
  }

  //Issuing credit from a buyer’s account to seller’s account
  void refund(){
    string buyer;
    string seller;
    double amount;

    cout << "Enter the buyer’s account name : " << endl;
    cin >> buyer;
    cout << "Enter the seller’s account name : " << endl;
    cin >> seller;
    cout << "Enter the amount of credit to transfer : " << endl;
    cin >> amount;

    User user1 = CurrentUserAccountsFileManager::findUser(buyer);
    double balance = user1.getCredits();
    balance += amount;
    user1.setCredits(balance);

    User user2 = CurrentUserAccountsFileManager::findUser(seller);
    double balance = user2.getCredits();
    balance -= amount;
    user2.setCredits(balance);
  }

  //Placing bid on item
  void bid(){
    string name;
    string seller;
    double bidAmount;
    cout << "Enter an item name :";
    cin >> name;
    cout << "Enter the seller name :";
    cin >> seller;
    Item item = AvailableItemsFileManager::findItem(name, seller);
    double lastBid = item.getCurrentBid();
    double amount;
    cout << "Enter the amount to bid(current bid:" << lastBid << ") :\n";
    cin >> amount;
    if (amount > credit){
      cout << "Not enough credit to place bid.\n";
      return;
    }
    AvailableItemsFileManager::bid(name, seller, amount);
  }

  //Putting an item up for auction
  void advertise(){
    cout << "Enter Item Name :";
    string name;
    cin >> name;
    cout << "Enter starting bid :";
    double minimumBid;
    cin >> minimumBid;
    cout << "Enter auction end date :";
    time_t endDate;
    cin >> endDate;
    AvailableItemsFileManager::addItem(name, minimumBid, endDate, *this);
  }
};
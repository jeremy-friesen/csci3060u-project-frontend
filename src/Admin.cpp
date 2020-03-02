#pragma once
#include "Admin.h"

//Description: Class to represent Admin user
//Contains functions only Admin users can use

//Creating new users
void Admin::createUser(){
  string username;
  string userType;

  cout << "Enter a username for the new account:";
  cin >> username;

  if (username.length() > 15) {
    cout << "Error: Username must be less than 15 characters" << endl;
    return;
  }

  cout << "Enter type of user (AA=admin, FS=full-standard, BS=buy-standard, SS=sell-standard):";
  cin >> userType;
  //TODO: query to make sure username is valid/not taken
  //User newUser(username, userType);
  DailyTransactionFileManager::addCreateUserTransaction(username, userType);
}

  /*
  //Deleting pre-existing users
  void deleteUser(){
    string username;
    cout << "Enter the account name to delete:";
    cin >> username;


    //TODO: find user in file before adding transaction
    DailyTransactionFileManager::addDeleteUserTransaction(username);
  }
  */

  // special functions moved to main.cpp due to circular dependency issue

  /*
  //Adding credit to another user in the system
  void addCredit(){
    string username;
    double amount;

    cout << "Enter the account’s username you wish to add credit to:";
    cin >> username;
    cout << "Enter credit amount:";
    cin >> amount;
		
		User user = CurrentUserAccountsFileManager::findUser(username);

    DailyTransactionFileManager::addAddCreditTransaction(username, user.getUserType(), amount);
  }

  //Issuing credit from a seller's account to buyer's account
  void refund(){
    string buyerUsername;
    string sellerUsername;
    double amount;

    cout << "Enter the buyer’s account name : " << endl;
    cin >> buyerUsername;
    cout << "Enter the seller’s account name : " << endl;
    cin >> sellerUsername;
    cout << "Enter the amount of credit to transfer : " << endl;
    cin >> amount;

    User buyer = CurrentUserAccountsFileManager::findUser(buyer);
    User seller = CurrentUserAccountsFileManager::findUser(seller);

		DailyTransactionFileManager::addRefundTransaction(buyer.getUsername(), seller.getUsername(), amount);
  }
  */

//Placing bid on item
void Admin::bid(){
  string itemName;
  string seller;
  double bidAmount;
  cout << "Enter an item name :";
  cin >> itemName;
  cout << "Enter the seller name :";
  cin >> seller;
  Item item = AvailableItemsFileManager::findItem(itemName, seller);
  double lastBid = item.getCurrentBid();
  double amount;
  cout << "Enter the amount to bid(current bid:" << lastBid << ") :\n";
  cin >> amount;

  if (amount > credit){
    cout << "Not enough credit to place bid.\n";
    return;
  }
  //AvailableItemsFileManager::bid(name, seller, amount);
	DailyTransactionFileManager::addBidTransaction(item.getItemName(), seller, username, amount);
}

//Putting an item up for auction
void Admin::advertise(){
  //cout << "FullStandard::advertise" << endl;
  const int nameLimit = 25;
  const double bidLimit = 999.99;
  const int maxDays = 100;

  string itemName;
  double minimumBid;
  int numDays;

  cout << "Enter Item Name :";
  cin.ignore();
  getline(cin, itemName);

  if (itemName.length() <= nameLimit ){
    cout << "Enter starting bid :";
    cin >> minimumBid;
    if (minimumBid <= bidLimit){
      cout << "Enter auction end date :";
      cin >> numDays;
      if (numDays <= maxDays){
        cout << itemName << " has now been posted" << endl;
        DailyTransactionFileManager::addAdvertiseTransaction(itemName, username, numDays, minimumBid);
      }
      else{
        cout << "Error: Number of days exceeds max days" << endl;
        return;
      }
    }else{
      cout << "Error: Bid price exceeds max limit" << endl;
      return;
    }
  }else{
    cout << "Error: Item name exceeds character limit" << endl;
    return;
  }
  
  
  //AvailableItemsFileManager::addItem(name, minimumBid, endDate, *this);
 
}

//Constructors
Admin::Admin(string username, double credit){
  this->username = username;
  this->userType = "AA";
  this->credit = credit;
}

Admin::Admin(){
  this->username = "";
  this->userType = "";
  this->credit = 0;
}

void Admin::deleteUser(){
  cout << "Admin::deleteUser" << endl;
}

void Admin::refund(){
  cout << "Admin::refundUser" << endl;
}

/*
virtual void bid() =0;

virtual void advertise() =0;

virtual void createUser() =0;

virtual void deleteUser() =0;

virtual void refund() =0;
*/
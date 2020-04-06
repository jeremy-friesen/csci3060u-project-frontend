#pragma once
#include "FullStandard.h"

//Description: Class to represent a Full-Standard user
//Contains functions of bid and advertise

//Placing bid on item
void FullStandard::bid(){
  string itemName;
  string seller;
  double bidAmount;
  cout << "Enter an item name: ";
  cin >> itemName;
  cout << "Enter the seller name: ";
  cin >> seller;
  Item item = AvailableItemsFileManager::findItem(itemName, seller);
  if(item.getItemName() == "")
    cout << "no item exists" << endl;
  double lastBid = item.getCurrentBid();
  double amount;
  cout << "Enter the amount to bid(current bid:" << lastBid << "):";
  cin >> amount;
  if (amount > credit){
    cout << "Not enough credit to place bid.\n";
    return;
  }
  //AvailableItemsFileManager::bid(name, seller, amount);
	DailyTransactionFileManager::addBidTransaction(item.getItemName(), seller, username, amount);
}

//Putting an item up for auction
void FullStandard::advertise(){
  //cout << "FullStandard::advertise" << endl;
  const int nameLimit = 25;
  const double bidLimit = 999.99;
  const int maxDays = 100;

  string itemName;
  string minimumBid;
  int numDays;

  cout << "Enter Item Name :";
  cin >> itemName;
  //cin.ignore();
  //getline(cin, itemName);

  if (itemName.length() <= nameLimit){
    cout << "Enter starting bid :";
    cin >> minimumBid;
    if (stod(minimumBid) <= bidLimit){
      cin >> numDays;
      if(numDays > maxDays){
        numDays = maxDays;
      }
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
FullStandard::FullStandard(string username, double credit){
  this->username = username;
  this->userType = "FS";
  this->credit = credit;
}

void FullStandard::createUser(){
  cout << "FullStandard::createUser" << endl;
}

void FullStandard::deleteUser(){
  cout << "FullStandard::deleteUser" << endl;
}

void FullStandard::refund(){
	cout << "FullStandard::refund" << endl;
}
#pragma once
#include "SellStandard.h"

//Description: Class to represent a Sell-Standard user
//Contains only an advertise function

//Putting an item up for auction
void SellStandard::advertise(){
  //cout << "FullStandard::advertise" << endl;
  const int nameLimit = 25;
  const double bidLimit = 999.99;
  const int maxDays = 100;

  string itemName;
  string minimumBid;
  int numDays;

  cout << "Enter Item Name :";
  cin.ignore();
  getline(cin, itemName);

  if (itemName.length() <= nameLimit ){
    cout << "Enter starting bid :";
    cin >> minimumBid;
    if (stod(minimumBid) <= bidLimit){
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

void SellStandard::bid(){
	cout << "You can't bid" << endl;
}

//Constructors
SellStandard::SellStandard(string username, double credit){
  this->username = username;
  this->userType = "SS";
  this->credit = credit;
}

void SellStandard::createUser(){
  cout << "SellStandard::createUser" << endl;
}

void SellStandard::deleteUser(){
  cout << "SellStandard::deleteUser" << endl;
}

void SellStandard::refund(){
  cout << "SellStandard::refund" << endl;
}
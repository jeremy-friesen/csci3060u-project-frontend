#pragma once
#include "SellStandard.h"

//Description: Class to represent a Sell-Standard user
//Contains only an advertise function

//Putting an item up for auction
void SellStandard::advertise(){
  cout << "Enter Item Name :";
  string itemName;
  cin >> itemName;
  cout << "Enter starting bid :";
  double minimumBid;
  cin >> minimumBid;
  cout << "Enter auction end date :";
  int numDays;
  cin >> numDays;
  //AvailableItemsFileManager::addItem(name, minimumBid, endDate, *this);

  DailyTransactionFileManager::addAdvertiseTransaction(itemName, username, numDays, minimumBid);
}

//Constructors
SellStandard::SellStandard(string username, double credit){
  this->username = username;
  this->userType = "SS";
  this->credit = credit;
}

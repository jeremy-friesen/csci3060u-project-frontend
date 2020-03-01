#pragma once
#include "FullStandard.h"

//Description: Class to represent a Full-Standard user
//Contains functions of bid and advertise

//Placing bid on item
void FullStandard::bid(){
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
void FullStandard::advertise(){
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
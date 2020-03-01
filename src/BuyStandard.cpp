#pragma once
#include "BuyStandard.h"

//Description: Class to represent a Buy-Standard user
//Contains only a bid function

//Placing bid on item
void BuyStandard::bid(){
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

  if (amount > credit)
  {
    cout << "Not enough credit to place bid.\n";
    return;
  }
  //AvailableItemsFileManager::bid(name, seller, amount);
  DailyTransactionFileManager::addBidTransaction(item.getItemName(), seller, username, amount);
}
  
//Constructors
BuyStandard::BuyStandard(string username, double credit){
  this->username = username;
  this->userType = "BS";
  this->credit = credit;
}

void BuyStandard::advertise(){
  cout << "BuyStandard::advertise" << endl;
}

void BuyStandard::createUser(){
  cout << "BuyStandard::createUser" << endl;
}

void BuyStandard::deleteUser(){
  cout << "BuyStandard::deleteUser" << endl;
}

void BuyStandard::refund(){
  cout << "BuyStandard::refund" << endl;
}
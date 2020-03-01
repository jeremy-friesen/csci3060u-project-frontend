#pragma once
#include <string>
#include <string.h>
#include "User.cpp"
//#include "Item.cpp"
//#include "DailyTransactionFileManager.cpp"
//#include "AvailableItemsFileManager.cpp"
#include <iostream>

using namespace std;

//Description: Class to represent a Buy-Standard user
//Contains only a bid function
class BuyStandard : public User{

  //Placing bid on item
  void bid();
  
public:
  //Constructors
  BuyStandard(string username, double credit);
};

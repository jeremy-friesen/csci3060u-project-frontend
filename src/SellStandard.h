#pragma once
#include <string>
#include <string.h>
#include "User.cpp"
//#include "CurrentUserAccountsFileManager.cpp"
//#include "AvailableItemsFileManager.cpp"
//#include "DailyTransactionFileManager.cpp"
#include <iostream>

using namespace std;

//Description: Class to represent a Sell-Standard user
//Contains only an advertise function
class SellStandard : public User
{

  //Putting an item up for auction
  void advertise();

public:
  //Constructors
  SellStandard(string username, double credit);
};

#pragma once
#include <string>
#include <string.h>
#include "User.cpp"
//#include "AvailableItemsFileManager.cpp"
//#include "DailyTransactionFileManager.cpp"
#include <iostream>
//#include "Item.cpp"

using namespace std;

//Description: Class to represent Admin user
//Contains functions only Admin users can use
class Admin : public User
{

  //Creating new users
  void createUser();

  //Placing bid on item
  void bid();

  //Putting an item up for auction
  void advertise();

public:
  //Constructors
  Admin(string username, double credit);

  void deleteUser();

  void refund();

  Admin();
};

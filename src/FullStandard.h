#include <string>
#include <string.h>
#include "User.cpp"
//#include "CurrentUserAccountsFileManager.cpp"
//#include "AvailableItemsFileManager.cpp"
#include <iostream>
//#include "Item.cpp"
//#include "DailyTransactionFileManager.cpp"

using namespace std;

//Description: Class to represent a Full-Standard user
//Contains functions of bid and advertise
class FullStandard : public User{


  //Placing bid on item
  void bid();

  //Putting an item up for auction
  void advertise();

public:
  //Constructors
  FullStandard(string username, double credit);
};

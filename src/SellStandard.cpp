#include <String>
#include <string.h>
#include "User.cpp"
#include "CurrentUserAccountsFileManager.cpp"
#include "AvailableItemsFileManager.cpp"
#include <iostream>

using namespace std;

//Description: Class to represent a Sell-Standard user
//Contains only an advertise function
class SellStandard : public User
{
  //Putting an item up for auction
  void advertise()
  {
    cout << "Enter Item Name :";
    string name;
    cin >> name;
    cout << "Enter starting bid :";
     double minimumBid;
    cin >> minimumBid;
    cout << "Enter auction end date :";
    time_t endDate;
    cin >> endDate;
    AvailableItemsFileManager::addItem(name, minimumBid, endDate, *this);
  }
};

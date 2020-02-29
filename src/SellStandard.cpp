#include <string>
#include <string.h>
#include "User.cpp"
//#include "CurrentUserAccountsFileManager.cpp"
//#include "AvailableItemsFileManager.cpp"
#include "DailyTransactionFileManager.cpp"
#include <iostream>

using namespace std;

//Description: Class to represent a Sell-Standard user
//Contains only an advertise function
class SellStandard : public User
{

  //Putting an item up for auction
  void advertise(){
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

public:
  //Constructors
  SellStandard(string username, double credit){
    this->username = username;
    this->userType = "SS";
    this->credit = credit;
  }

};

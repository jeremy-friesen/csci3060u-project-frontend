#include <String>
#include <string.h>
#include "User.cpp"
#include "CurrentUserAccountsFileManager.cpp"
#include "AvailableItemsFileManager.cpp"
#include <iostream>
#include "Item.cpp"

using namespace std;

//Description: Class to represent a Full-Standard user
//Contains functions of bid and advertise
class FullStandard : public User{

  //Placing bid on item
  void bid(){
    string name;
    string seller;
    double bidAmount;
    cout << "Enter an item name :";
    cin >> name;
    cout << "Enter the seller name :";
    cin >> seller;
    Item item = AvailableItemsFileManager::findItem(name, seller);
    double lastBid = item.getCurrentBid();
    double amount;
    cout << "Enter the amount to bid(current bid:" << lastBid << ") :\n";
    cin >> amount;
    if (amount > credit){
      cout << "Not enough credit to place bid.\n";
      return;
    }
    AvailableItemsFileManager::bid(name, seller, amount);
  }

  //Putting an item up for auction
  void advertise(){
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

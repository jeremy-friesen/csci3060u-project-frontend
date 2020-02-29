#include <string>
#include <string.h>
#include "User.cpp"
#include "Item.cpp"
#include "DailyTransactionFileManager.cpp"
#include "AvailableItemsFileManager.cpp"
#include <iostream>

using namespace std;

//Description: Class to represent a Buy-Standard user
//Contains only a bid function
class BuyStandard : public User{

  //Placing bid on item
  void bid(){
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
  
public:
  //Constructors
  BuyStandard(string username, double credit){
    this->username = username;
    this->userType = "BS";
    this->credit = credit;
  }

};

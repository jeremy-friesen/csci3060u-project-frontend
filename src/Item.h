#include <string>
#include <string.h>
//#include "User.cpp"
//#include "CurrentUserAccountsFileManager.cpp"
//#include "AvailableItemsFileManager.cpp"
#include <iostream>

using namespace std;

//Description: The class that holds all information regarding any item in the system
//Contains the item name, ID, description, current bid price and bid end date
//Inputs
class Item{
private:
	string itemName;
	string sellerName;
	int itemID;
	string description;
	double currentBid;
	time_t bidEndDate;

public:
	//Constructors
	Item(string itemName, string sellerName);

	Item(string itemName, string sellerName, double currentBid);

	Item(string itemName, string sellerName, double currentBid, time_t bidEndDate);

	//Sets the name of the item
	void setItemName(string itemName);

	//sets the seller's name
	void setSellerName(string sellerName);
	
	//Sets the ID of the item
	void setItemID(int itemID);
	
	//Sets the description of the item
	void setDescription(string description);
	
	//Sets the current bid price of the item
	void setCurrentBid(double currentBid);
	
	//Sets the end of the bid date for the item
	void setBidEndDate(time_t bidEndDate);

	//Returns the name of the item as a string
	string getItemName();

	string getSellerName();
	
	//Returns the ID of an item as an integer
	int getItemID();
		
	//Returns the description of an item as a string
	string getDescription();
		
	//Returns the current highest bid on an item as a double
	double getCurrentBid();
		
	//Returns the date the bid will end as time_t
	time_t getBidEndDate();
};
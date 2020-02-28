#include <String>
#include <string.h>
#include "User.cpp"
//#include "CurrentUserAccountsFileManager.cpp"
//#include "AvailableItemsFileManager.cpp"
#include <iostream>

using namespace std;

//Description: The class that holds all information regarding any item in the system
//Contains the item name, ID, description, current bid price and bid end date
//Inputs
class Item{
	string itemName;
	int itemID;
	string description;
	double currentBid;
	time_t bidEndDate;
	
	//Sets the name of the item
	void setItemName(string itemName) {
		this->itemName = itemName;
	}
	
	//Sets the ID of the item
	void setItemID(int itemID) {
		this->itemID = itemID;
	}
	
	//Sets the description of the item
	void setDescription(string description) {
		this->description = description;
	}
	
	//Sets the current bid price of the item
	void setCurrentBid(double currentBid) {
		this->currentBid = currentBid;
	}
	
	//Sets the end of the bid date for the item
	void setBidEndDate(time_t bidEndDate) {
		this->bidEndDate = bidEndDate;
	}

public:
	//Returns the name of the item as a string
	string getItemName(){
		return itemName;
	}
	
	//Returns the ID of an item as an integer
	int getItemID(){
		return itemID;
	}
		
	//Returns the description of an item as a string
	string getDescription(){
		return description;
	}
		
		//Returns the current highest bid on an item as a double
	double getCurrentBid(){
		return currentBid;
	}
		
		//Returns the date the bid will end as time_t
	time_t getBidEndDate(){
		return bidEndDate;
	}
 
};
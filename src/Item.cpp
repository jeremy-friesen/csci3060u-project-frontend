#pragma once
#include "Item.h"

//Description: The class that holds all information regarding any item in the system
//Contains the item name, ID, description, current bid price and bid end date
//Inputs

string itemName;
string sellerName;
int itemID;
string description;
double currentBid;
time_t bidEndDate;

//Constructors
Item::Item(string itemName, string sellerName){
	this->itemName = itemName;
	this->sellerName = sellerName;
}

Item::Item(string itemName, string sellerName, double currentBid){
	this->itemName = itemName;
	this->sellerName = sellerName;
	this->currentBid = currentBid;
}

Item::Item(string itemName, string sellerName, double currentBid, time_t bidEndDate){
	this->itemName = itemName;
	this->sellerName = sellerName;
	this->currentBid = currentBid;
	this->bidEndDate = bidEndDate;
}

//Sets the name of the item
void Item::setItemName(string itemName) {
	this->itemName = itemName;
}

//sets the seller's name
void Item::setSellerName(string sellerName){
	this->sellerName = sellerName;
}
	
//Sets the ID of the item
void Item::setItemID(int itemID) {
	this->itemID = itemID;
}
	
//Sets the description of the item
void Item::setDescription(string description) {
	this->description = description;
}
	
//Sets the current bid price of the item
void Item::setCurrentBid(double currentBid) {
	this->currentBid = currentBid;
}
	
//Sets the end of the bid date for the item
void Item::setBidEndDate(time_t bidEndDate) {
	this->bidEndDate = bidEndDate;
}

//Returns the name of the item as a string
string Item::getItemName(){
	return itemName;
}

string Item::getSellerName(){
	return sellerName;
}
	
//Returns the ID of an item as an integer
int Item::getItemID(){
	return itemID;
}
		
//Returns the description of an item as a string
string Item::getDescription(){
	return description;
}
		
//Returns the current highest bid on an item as a double
double Item::getCurrentBid(){
	return currentBid;
}
		
//Returns the date the bid will end as time_t
time_t Item::getBidEndDate(){
	return bidEndDate;
}
#pragma once
#include <string>
#include <string.h>
//#include "User.cpp"
//#include "CurrentUserAccountsFileManager.cpp"
#include <iostream>
#include "Item.cpp"
#include <fstream>

using namespace std;

//Description: Manages and updates data in the Available Items File
//Contains the transaction lines for all items in the system
class AvailableItemsFileManager{
	//string itemData;
	static string fileName;
public:	

	static void setFileName(string fileName);

	// helper function to determine whether this line
	// is the item line
	static bool isItem(string line, string itemName);

    // helper function to parse user type
	static string parseSellerName(string line);

	// helper function to parse user credit
	static double parseCurrentBid(string line);
	
	//Finding existing user in Current User Accounts File
	static Item findItem(string itemName, string sellerName);
};
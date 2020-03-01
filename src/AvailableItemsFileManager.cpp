#include "AvailableItemsFileManager.h"

//Description: Manages and updates data in the Available Items File
//Contains the transaction lines for all items in the system

//string itemData;
string AvailableItemsFileManager::fileName = "availableitems.txt";

void AvailableItemsFileManager::setFileName(string fileName){
	AvailableItemsFileManager::fileName = fileName;
}
// helper function to determine whether this line
// is the item line
bool AvailableItemsFileManager::isItem(string line, string itemName){
	int l = itemName.length();
	if(line.substr(0,l) == itemName){
		string leftOverChars = line.substr(l+1,15-l);
		for(int i = 0; i < leftOverChars.length(); i++){
			if(leftOverChars[i] != ' ')
				return false;
		}
		return true;
	}
	return false;
}

// helper function to parse user type
string AvailableItemsFileManager::parseSellerName(string line){
	return line.substr(17,2);
}

// helper function to parse user credit
double AvailableItemsFileManager::parseCurrentBid(string line){
	return stod(line.substr(55,6));
}
	
//Finding existing user in Current User Accounts File
Item AvailableItemsFileManager::findItem(string itemName, string sellerName){
	ifstream in("availableitems.txt");
	string line;
	int l = itemName.length();

	if (in.is_open()){
		while(getline(in,line)){
  			if(isItem(line, itemName)){
				double currentBid = parseCurrentBid(line);
				return Item(itemName, sellerName, currentBid);
	    	}
    	}
    	in.close();
    }
	//cout << "CurrentUserAccountsFileManager::findUser : No user found" << endl;
	return Item("","",0);
}

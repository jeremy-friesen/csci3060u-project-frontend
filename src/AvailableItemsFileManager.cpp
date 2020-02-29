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

	static void setFileName(string fileName){
		AvailableItemsFileManager::fileName = fileName;
	}
	// helper function to determine whether this line
	// is the item line
	static bool isItem(string line, string itemName){
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
	static string parseSellerName(string line){
		return line.substr(17,2);
	}

	// helper function to parse user credit
	static double parseCurrentBid(string line){
		return stod(line.substr(55,6));
	}
	
	//Finding existing user in Current User Accounts File
	static Item findItem(string itemName, string sellerName){
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
};

string AvailableItemsFileManager::fileName = "availableitems.txt";
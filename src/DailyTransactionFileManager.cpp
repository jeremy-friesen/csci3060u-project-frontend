#include <string>
#include <string.h>
#include "User.cpp"
#include <iostream>
#include <fstream>

using namespace std;

//Description: Manages and updates the data stored in the Daily Transaction    //            File
//Contains the daily transaction lines for the user and any of their refund,         advertise or bid actions
//Inputs
class DailyTransactionFileManager{
private:
	/*
	string createTransaction = 
	string refundTransaction;
	string advertiseTransaction;
	string bidTransaction;
	*/
	//const static string; defaultFileName = "DailyTransactionFile.txt";
	static string alternateFileName;

public:
	// used to set the file name if one is given in the command line
	static void setFileName(string filename){
		alternateFileName = filename;
	}

	static string formatUsername(string username){
		while(username.length() < 15){
			username += " ";
		}
		return username;
	}

	static string formatCredit(double credit){
		string s = to_string(credit);
		while(s.length() < 9){
			s = "0" + s;
		}
		return s;
	}

	static string formatItemName(string itemName){
		while(itemName.length() < 19){
			itemName += " ";
		}
		return itemName;
	}

	static string formatInt(int i){
		string s = to_string(i);
		while(s.length() < 3){
			s = "0" + s;
		}
		return s;
	}

	// use to write to file
	static void appendLine(string line){
		ofstream outfile;
		if(alternateFileName != ""){
			outfile.open(alternateFileName, ios_base::app);
		}else{
			outfile.open("DailyTransactionFile.txt", ios_base::app);
		}
		outfile << line;
	}

	// called after "create user" transaction
	static void addCreateUserTransaction(string newUsername, string userType){
		string line = "01 ";
		line += formatUsername(newUsername) + " " + userType + " " + formatCredit(0.00) + "\n";
		appendLine(line);
	}

	// called after delete transaction
	static void addDeleteUserTransaction(string username, string userType){
		string line = "02 ";
		line += formatUsername(username) + " " + userType + " " + formatCredit(0.00) + "\n";
		appendLine(line);
	}

	// COME BACK AFTER ANSWER FROM BAHARE
	// called after add credit transaction
	static void addAddCreditTransaction(string username, string userType, double addCredit){
		string line = "06 ";
		line += formatUsername(username) + " " + userType + " " + formatCredit(addCredit) + "\n";
		appendLine(line);
	}

	// called after logout
	static void addEndSessionTransaction(string username, string userType, double credit){
		string line = "00 ";
		line += formatUsername(username) + " " + userType + " " + formatCredit(credit) + "\n";
		appendLine(line);
	}

	// called after refund
	static void addRefundTransaction(string buyerUsername, string sellerUsername, double refundCredit){
		string line = "05 ";
		line += formatUsername(buyerUsername) + " " + formatUsername(sellerUsername) + " " 
					+ formatCredit(refundCredit) + "\n";
		appendLine(line);
	}

	// called after advertise
	static void addAdvertiseTransaction(string itemName, string sellerUsername, int numDays, double minBid){
		string line = "03 ";
		line += formatItemName(itemName) + " " + formatUsername(sellerUsername) 
						+ " " + formatInt(numDays) + " " + formatCredit(minBid);
		appendLine(line);
	}

	// called after bid
	static void addBidTransaction(string itemName, string sellerName, string buyerName, double bid){
		string line = "04 ";
		line += formatItemName(itemName) + " " + formatUsername(sellerName) + " "
						+ formatUsername(buyerName) + " " + formatCredit(bid);
		appendLine(line);
	}
};
#pragma once
#include "DailyTransactionFileManager.h"
#include <iomanip>
#include <sstream>

//Description: Manages and updates the data stored in the Daily Transaction    //            File
//Contains the daily transaction lines for the user and any of their refund,         advertise or bid actions
//Inputs

string DailyTransactionFileManager::fileName = "dailytransactionfile.txt";

// used to set the file name if one is given in the command line
void DailyTransactionFileManager::setFileName(string filename){
	fileName = filename;
}

string DailyTransactionFileManager::formatUsername(string username){
	while(username.length() < 15){
		username += " ";
	}
	return username;
}

string DailyTransactionFileManager::formatCredit(double credit){
	string s = to_string(credit);
	if(s.length() >= 4){
		s = s.substr(0,4);
	}
	while(s.length() < 9){
		s = "0" + s;
	}
	return s;
}

string DailyTransactionFileManager::formatCredit(string credit)
{
	//string s = to_string(credit);
	/*if (s.length() >= 4)
	{
		s = s.substr(0, 4);
	}*/
	while (credit.length() < 9)
	{
		credit = "0" + credit;
	}
	return credit;
}

string DailyTransactionFileManager::formatBid(string credit){
	//string s = to_string(credit);
	while(credit.length() < 6){
		credit = "0" + credit;
	}
	return credit;
}

string DailyTransactionFileManager::formatItemName(string itemName){
	while(itemName.length() < 19){
		itemName += " ";
	}
	return itemName;
}

string DailyTransactionFileManager::formatInt(int i){
	string s = to_string(i);
	while(s.length() < 3){
		s = "0" + s;
	}
	return s;
}

// use to write to file
void DailyTransactionFileManager::appendLine(string line){
	ofstream outfile;
	outfile.open(fileName, ios_base::app);
	outfile << line;
}

// called after "create user" transaction
void DailyTransactionFileManager::addCreateUserTransaction(string newUsername, string userType){
	string line = "01 ";
	line += formatUsername(newUsername) + " " + userType + " " + formatCredit(0.00) + "\n";
	appendLine(line);
	cout << "HERE" << endl;
}

// called after delete transaction
void DailyTransactionFileManager::addDeleteUserTransaction(string username, string userType){
	string line = "02 ";
	line += formatUsername(username) + " " + userType + " " + formatCredit(0.00) + "\n";
	appendLine(line);
}

// called after add credit transaction
void DailyTransactionFileManager::addAddCreditTransaction(string username, string userType, double addCredit){
	string line = "06 ";
	line += formatUsername(username) + " " + userType + " " + formatCredit(addCredit) + "\n";
	appendLine(line);
}

// called after logout
void DailyTransactionFileManager::addEndSessionTransaction(string username, string userType, double credit){
	string line = "00 ";
	line += formatUsername(username) + " " + userType + " " + formatCredit(credit) + "\n";
	appendLine(line);
}

// called after refund
void DailyTransactionFileManager::addRefundTransaction(string buyerUsername, string sellerUsername, string refundCredit){
	string line = "05 ";
	line += formatUsername(buyerUsername) + " " + formatUsername(sellerUsername) + " " 
				+ formatCredit(refundCredit) + "\n";
	appendLine(line);
}

// called after advertise
void DailyTransactionFileManager::addAdvertiseTransaction(string itemName, string sellerUsername, int numDays, string minBid){
	string line = "03 ";
	line += formatItemName(itemName) + " " + formatUsername(sellerUsername) 
					+ " " + formatInt(numDays) + " " + formatBid(minBid);
	appendLine(line);
}

// called after bid
void DailyTransactionFileManager::addBidTransaction(string itemName, string sellerName, string buyerName, double bid){
	string line = "04 ";
	line += formatItemName(itemName) + " " + formatUsername(sellerName) + " "
					+ formatUsername(buyerName) + " " + formatCredit(bid);
	appendLine(line);
}

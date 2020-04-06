#pragma once
#include <string>
#include <string.h>
//#include "User.cpp"
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

public:
    static string fileName;

	// used to set the file name if one is given in the command line
	static void setFileName(string filename);

	static string formatUsername(string username);

	static string formatCredit(double credit);

	static string formatCredit(string credit);

	static string formatBid(string credit);

	static string formatItemName(string itemName);

	static string formatInt(int i);

	// use to write to file
	static void appendLine(string line);

	// called after "create user" transaction
	static void addCreateUserTransaction(string newUsername, string userType);

	// called after delete transaction
	static void addDeleteUserTransaction(string username, string userType);

	// called after add credit transaction
	static void addAddCreditTransaction(string username, string userType, double addCredit);

	// called after logout
	static void addEndSessionTransaction(string username, string userType, double credit);

	// called after refund
	static void addRefundTransaction(string buyerUsername, string sellerUsername, string refundCredit);

	// called after advertise
	static void addAdvertiseTransaction(string itemName, string sellerUsername, int numDays, string minBid);

	// called after bid
	static void addBidTransaction(string itemName, string sellerName, string buyerName, double bid);
};
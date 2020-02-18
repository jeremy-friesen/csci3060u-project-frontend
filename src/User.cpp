//Description: Abstract super class that defines every other account type
//Contains information and functions that every user uses
//Inputs: The user’s unique username, the user’s user type (admin, full-standard, etc)
class User{
	
public:
	string userName;
	string userType;
	int userID;
	
	//Returns the username of the account as a string
	string getUsername(){
		return userName;
}
 
//Returns the type of user as a string
string getUserType(){
		return userType;
}
 
//Returns the ID of the user as an integer
	int getUserID(){
		return userID
}
 
//Returns the amount of credits the account holds as double
double getCredits(){
	return credits;
}
 
//Add credit to their own account
void addCredit(){
	double amount;
	cout << “Enter the amount of credits you would like “;
	cout << “to add to your account” << endl;
	cin >> amount;
	
	double balance= user.getCredits();
	balance += amount;
	user.setCredits(balance);
} 
	
	//Default Constructor
	void User(string userName, string userType){
		this.userName = userName;
		this.userType = userType;
	}
 
protected:
	//Sets the name of the user
	void setUserName(string userName){
		this.userName = userName;
	}
 
//Sets the user type of the account
	void setUserType(string userType){
		this.userType = userType;
	}
	
	//Sets the ID of the user
	void setUserID(int userID){
		this.userID = userID;
	}
	
	//Sets the amount of credits that the account holds
	void setCredits(double credits){
		this.credits = credits;
}
 
private:
		double credits;
}

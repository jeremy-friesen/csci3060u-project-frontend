//Description: Class for which users will enter in commands that correspond with       //             their privileges
//Contains functions that execute user commands
class Menu
{

private:
  string userCommand;
  User user;
  //Presents the login screen to the user
  void login()
  {
    if (user)
    {
      cout << “Can’t login.User already logged in.” << endl;
      return;
    }
    string username;
    cout << “Enter Username :”;
    cin >> username;
    user = CurrentUserAccountsFileManager.login(username);
    if (user)
    {
      cout << “Logged in successfully.” << endl;
    }
    else
    {
      cout << “Login unsuccessful.” << endl;
    }
  }

  //Logs the user out of their account
  void logout()
  {
    cout << “Thank you for visiting! Goodbye!” << endl;
    User = NULL;
  }

  //Admin: Can add credit to another user’s account or to their own account
  //Else: Can add credit to their own account
  void addCredit(double amount)
  {
    user.addCredit(credits);
  }

  //Displays all options available to the user based on their account
  void printMenu()
  {
    cout << “login” << endl;
    cout << “logout” << endl;

    if (user.type == “admin”)
    {
      cout << “create user” << endl;
      cout << “delete user” << endl;
      cout << “bid” << endl;
      cout << “advertise” << endl;
      cout << “refund” << endl;
    }

    else if (user.type == “standard - full” || user.type == “standard - buy”)
    {
      cout << “bid” << endl;
    }

    if (user.type == “standard - full” || user.type == “standard - sell”)
    {
      cout << “advertise” << endl;
    }

    cout << “add credit” << endl;
  }

  int main()
  {
    while (true)
    {
      cout << “Enter a command :” << endl;
      cin >> userCommand;
      if (!user && userCommand != “login”)
      {
        cout << “Cannot process request, no user is logged in.\n”
      }
      else
      {
        switch (userCommand)
        {
        case “login”:
          login();
          break;
        case “add credit”:
          addCredit();
          break;
        case “bid”:
          bid();
          break;
        case “advertise”:
          advertise();
          break;
        case “create user”:
          createUser();
          break;
        case “delete user”:
          deleteUser();
          break;
        case “refund”:
          refund();
          break;
        case “help”:
          printMenu();
          break;
        case “logout”:
          logout();
          break;
        default:
          cout << “Unrecognized command entered.
               << “Please re - enter.\n”;
        }
      }
    }
  }

protected:
  //Users who are not of type standard-sell can bid
  void bid()
  {
    if (user.type != “standard - sell”)
      user.bid();
    else
      cout << “Insufficient privileges.” << endl;
  }

  //Users who are not of type standard-sell can bid
  void advertise()
  {
    if (user.type != “standard - buy”)
      user.advertise();
    else
      Cout << “Insufficient privileges.” << endl;
  }

  //Allows Admin to create new users
  void createUser()
  {
    if (user.type == “admin”)
      user.createUser();
    else
      cout << “Insufficient privileges.” << endl;
  }

  //Allows Admin to delete pre-existing users
  void deleteUser()
  {
    if (user.type == “admin”)
      user.deleteUser();
    else
      cout << “Insufficient privileges.” << endl;
  }
  //Allows an admin to issue credit from a buyer’s account to a seller’s account
  void refund()
  {
    if (user.type == “admin”)
      user.refund();
    else
      cout << “Insufficient privileges.” << endl;
  }
}

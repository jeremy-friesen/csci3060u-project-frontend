//Description: Class to represent a Buy-Standard user
//Contains only a bid function
class BuyStandard : public User
{
  //Placing bid on item
  void bid()
  {
    string name;
    string seller;
    double bidAmount
            cout
        << “Enter an item name :”;
    cin >> name;
    cout << “Enter the seller name :”;
    cin >> seller;
    Item item = AvailableItemsFileManager.findItem(name, seller);
    double lastBid = item.currentBid;
    double amount;
    cout << “Enter the amount to bid(current bid
                                     :” << lastBid << “) :\n”;
    cin >> amount;
    if (amount > credit)
    {
      cout << “Not enough credit to place bid.\n” return;
    }
    AvailableItemsFileManager.bid(name, seller, amount);
  }
}

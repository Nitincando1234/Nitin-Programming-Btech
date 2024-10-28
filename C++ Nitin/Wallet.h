#pragma once
#include<string>
#include<map>
#include"OrderBookEntry.h"
using namespace std;
class Wallet{
    public:
    Wallet();
    /**Insert Currency to the Wallet*/
    void insertCurrency(string type,double amount);
    /**Remove Currency from the Wallet*/
    bool removeCurrency(string type, double amount);
    /**Check If the wallet contains enough cuurency*/
    bool containsCurrency(string type, double amount);
    /**Generate a String representation of the currency*/
    string toString();
    /**Update the contents of the wallet
     * Assumes the order was made by Owner of the wallet
    */
    void processSell(OrderBookEntry &sale);
    bool canFulfillOrder( OrderBookEntry order) ;
    private:
    map<string,double> currencies;
};

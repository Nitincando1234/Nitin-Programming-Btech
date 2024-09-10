#pragma once
#include"OrderBookEntry.h"
#include"CSVReader.h"
#include<string>
#include<vector>
using namespace std;
class OrderBook{
    public:
    /**Construct, Reading a CSV File.*/
    OrderBook(string filename);
    /**Return Vector of all Known Products in the Datasets*/
    vector<string >getKnownProducts();
    /**Return a vector of orders according to the sent Filters*/
    vector<OrderBookEntry>getOrders(OrderBookType type, string product, string timestamp);
    void insertOrder(OrderBookEntry & order);
    vector<OrderBookEntry> matchAsksToBids(string product,string timestamp);
    static double getHighPrice(vector <OrderBookEntry>& orders);
    static double getLowPrice(vector <OrderBookEntry>& orders);
    /**Provides / returns the current time in the OrderBook*/
    string getEarliestTime();
    /**Provides / returns the next time after the sent time in the OrderBook
     * If there is no next timestamp wraps around the first timestamp
    */
    string getNextTime(string timestamp);
    
    private:
    vector<OrderBookEntry>orders ;
};
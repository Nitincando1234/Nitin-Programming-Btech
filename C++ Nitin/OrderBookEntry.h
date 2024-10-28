#pragma once
#include <string>
#include<vector>
using namespace std;
enum class OrderBookType{bid,ask,unknown,sale,asksale,bidsale};
 class OrderBookEntry{
    public:
    OrderBookEntry(double price,
                    double amount,
                    string timestamp,
                    string product,
                   OrderBookType orderType,
                   string username="dataset");
   static bool compareByTimestamp(OrderBookEntry &e1, OrderBookEntry &e2){
      return (e1.timestamp<e2.timestamp);
   }
   static bool comparePriceAsc(OrderBookEntry &e1, OrderBookEntry &e2){
      return (e1.price<e2.price);
   }
   static bool comparePriceDesc(OrderBookEntry &e1, OrderBookEntry &e2){
      return (e1.price>e2.price);
   }
   static OrderBookType stringToOrderBookType(string s);                   
    double price;
    double amount;
    string timestamp;
    string product;
    OrderBookType orderType;
    string username;
    
 };
#include"OrderBookEntry.h"
#include<string>
using namespace std;
OrderBookEntry::OrderBookEntry(double price,
                    double amount,
                    string timestamp,
                    string product,
                   OrderBookType orderType,
                   string username):
        price(price),
        amount(amount),
        timestamp(timestamp),
        product(product),
        orderType(orderType),
        username(username)
                   {

}
   OrderBookType OrderBookEntry::stringToOrderBookType(std::string s){
    if(s == "ask"){
        return OrderBookType::ask;
    }
    if(s == "bid"){
        return OrderBookType::bid;
    }
    if(s == "unknown"){
        return OrderBookType::unknown;
    }
   }

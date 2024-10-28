#include"CSVReader.h"
#include"OrderBookEntry.h"
#include"Wallet.h"
#include<iostream>
using namespace std;
Wallet::Wallet(){}
void Wallet::insertCurrency(string type,double amount){
    double balance;
    if(amount<0){
        throw std::exception{};
    }
    if(currencies.count(type)==0){
        balance =0;
    }
    else{
        balance=currencies[type];
    }
    balance+=amount;
    currencies[type]=balance;
}
bool Wallet::containsCurrency(string type, double amount){
    if(currencies.count(type)==0) return false;
    else return currencies[type]>=amount;
    return false;
}
bool Wallet::removeCurrency(string type, double amount){
     
    if(amount<0){
       throw std::exception{};
    }
    if(currencies.count(type)==0){
        return false;
    }
    else{
        if(containsCurrency(type,amount))
        {
            currencies[type]-=amount;
            return true;
        }
        else{
            return false;
        }
    }
   
}
string Wallet::toString(){
    string s;
    for(pair<string,double>pair:currencies){
        string currency=pair.first;
        double amount=pair.second;
        s+=currency+" : "+to_string(amount)+"\n";
    }
    return s;
}
    bool Wallet::canFulfillOrder(OrderBookEntry order){
        vector<string >currs=CSVReader::tokenise(order.product,'/');
    if(order.orderType==OrderBookType::ask){
    double amount=order.amount;
    string currency=currs[0];
    cout<<"Wallet::canFullfillOrder: "<<currency<<" : "<<amount<<endl;
    return containsCurrency(currency,amount);
    }
    if(order.orderType==OrderBookType::bid){
        double amount=order.amount*order.price;
        string currency=currs[1];
    cout<<"Wallet::canFullfillOrder: "<<currency<<" : "<<amount<<endl;

        return containsCurrency(currency,amount);
    }
    return false;
    }
    void Wallet::processSell(OrderBookEntry& sale){
        vector<string >currs=CSVReader::tokenise(sale.product,'/');
    if(sale.orderType==OrderBookType::asksale){
    double outgoingAmount=sale.amount;
    string outgoingCurrency=currs[0];
     double incomingAmount=sale.amount*sale.price;
        string incomingCurrency=currs[1];
    currencies[incomingCurrency]+=incomingAmount;
    currencies[outgoingCurrency]-=outgoingAmount;
    }
    if(sale.orderType==OrderBookType::bidsale){
       double incomingAmount=sale.amount;
    string incomingCurrency=currs[0];
     double outgoingAmount=sale.amount*sale.price;
        string outgoingCurrency=currs[1];
    currencies[incomingCurrency]+=incomingAmount;
    currencies[outgoingCurrency]-=outgoingAmount;
    }
 
    }


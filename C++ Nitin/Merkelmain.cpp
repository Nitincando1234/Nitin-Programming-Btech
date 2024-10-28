#include<iostream>
#include<string>
#include<vector>
#include"OrderBookEntry.h"
#include"Merkelmain.h"
#include"CSVREADER.h"
using namespace std;
Merkelmain::Merkelmain(){}
void Merkelmain::init(){
    int input;double amount; string currency;
    currentTime=OrderBook.getEarliestTime();
    
    wallet.insertCurrency("BTC",10);
  
    while(true){
        printMenu();
        input=getUserOption();
        processUserOption(input);
    }
}
void Merkelmain::printMenu(){
    cout<<"1. Help"<<endl;
    cout<<"2. Exchange Stats"<<endl;
    cout<<"3. Make an Offer"<<endl;
    cout<<"4. Make a Bid"<<endl;
    cout<<"5. Wallet"<<endl;
    cout<<"6. Continue"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Current Time :"<<currentTime<<endl;
}
int Merkelmain::getUserOption(){
    int userInput = 0;
    string line;
    cout<<"Enter your Option:"<<endl;
    getline(cin,line);
    try{userInput=stoi(line);}
    catch(const exception& e){}
    cout<<"You Chose: "<<userInput<<endl;
    return userInput;
}
void Merkelmain::processUserOption(int userInput){
    switch(userInput){
        case 1:
    help();
        break;
        case 2:
    exchangeStats();
        break;
    case 3:
    enterAsk();
        break;
     case 4:
    makebid();
        break;
        case 5:
    aWallet();
        break;
        case 6:
    timeframeContinue();
        break;
        default:
        invalidInput();
        break;
        }
}
void Merkelmain::help(){
    cout<<"Your aim is to make money, analyze the market and Do it carefully."<<endl;
}
void Merkelmain::exchangeStats(){
    for(string & p:OrderBook.getKnownProducts())
    {
        cout<<"Product: "<<p<<endl;
        vector<OrderBookEntry> entries=OrderBook.getOrders(OrderBookType::ask,p,currentTime);
        cout<<"Asks seen: "<<entries.size()<<endl;
        cout<<"Max Asks: "<<OrderBook::getHighPrice(entries)<<endl;
        cout<<"Min Asks: "<<OrderBook::getLowPrice(entries)<<endl;

    }   
    // cout<<"Order Book Contains: "<<orders.size()<<" enteries."<<endl;
    // unsigned int asks=0;
    // unsigned int bids =0;
    // for(OrderBookEntry& e:orders){
    //     if(e.orderType== OrderBookType::ask){
    //         asks++;
    //     }
    //     if(e.orderType== OrderBookType::bid){
    //         bids++;
    //     }
    // }
    // cout<<"Order Book Contains: "<<" Asks: "<<asks<<" Bids: "<<bids<<endl;

}
void Merkelmain::enterAsk(){
    cout<<"Make an Ask - Enter the Amount: product, price, amount Eg. ETH/BTC,500,0.5 "<<endl;
    string input;
    getline(cin,input);
    vector<string> tokens= CSVReader::tokenise(input,',');
    if(tokens.size()!=3){
        cout<<"Bad Input!"<<endl;
    }else
    {
        try{OrderBookEntry obe= CSVReader::stringToOBE(tokens[1],
                                                   tokens[2],
                                                   currentTime,
                                                   tokens[0], 
                                                   OrderBookType::ask);
            obe.username="simuser";
          if(wallet.canFulfillOrder(obe)){
        cout<<"Wallet has sufficient funds."<<endl;
          OrderBook.insertOrder(obe);}
          else
          cout<<"Wallet has insufficient funds.";
          }
      catch(const exception& e){
            cout<<"Merkelmain::enterAsk() Bad Input !"<<endl;
        }
    }
    cout<<"You Entered : "<<input<<endl;
}
void Merkelmain::makebid(){
     cout<<"Make a Bid - Enter the Amount: product, price, amount Eg. ETH/BTC,500,0.5 "<<endl;
    string input;
    getline(cin,input);
    vector<string> tokens= CSVReader::tokenise(input,',');
    if(tokens.size()!=3){
        cout<<"Bad Input!"<<endl;
    }else
    {
        try{OrderBookEntry obe= CSVReader::stringToOBE(tokens[1],
                                                   tokens[2],
                                                   currentTime,
                                                   tokens[0], 
                                                   OrderBookType::bid);
        obe.username="simuser";
          if(wallet.canFulfillOrder(obe)){
        cout<<"Wallet has sufficient funds."<<endl;
          OrderBook.insertOrder(obe);}
          else
          cout<<"Wallet has insufficient funds.";
          }
      catch(const exception& e){
            cout<<"Merkelmain::makebid() Bad Input !"<<endl;
        }
    }
    cout<<"You Entered : "<<input<<endl;
}
void Merkelmain::aWallet(){
    
    cout<<"Your Wallet :"<<endl;
    cout<<wallet.toString()<<endl;
}
void Merkelmain::timeframeContinue(){
    cout<<"\tEntering to next timeframe..."<<endl;
    vector<OrderBookEntry> sales=OrderBook.matchAsksToBids("ETH/BTC",currentTime);
    cout<<"Total Sales: "<<sales.size()<<endl;
    for(OrderBookEntry &sale:sales){
        cout<<"Sale Price: "<<sale.price<<" amount: "<<sale.amount<<endl;
        if(sale.username=="simuser"){
            //update the wallet
            wallet.processSell(sale);
        }
    }
    currentTime=OrderBook.getNextTime(currentTime);
}
void Merkelmain::invalidInput(){
    cout<<"Invalid Choice, Choose again"<<endl;
}
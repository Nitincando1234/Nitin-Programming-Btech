#include"OrderBookEntry.h"
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include"CSVReader.h"
using namespace std;
CSVReader::CSVReader()
{

}
vector<OrderBookEntry> CSVReader:: readCSV(string csvFilename){
    vector<OrderBookEntry> entries;
    ifstream csvFile(csvFilename);
    string line;
    if(csvFile.is_open()){
        while(getline(csvFile,line)){
            try{
            OrderBookEntry obe=stringToOBE( tokenise(line,','));
                entries.push_back(obe);
            }
            catch(const std::exception& e){
                cout<<"CSVReader:: readCSV bad data"<<endl;
            }       
        }
    }
    cout<<"CSVReader:: readCSV read= "<<entries.size()<<" entries"<<endl;
    return entries;
}
vector<string>  CSVReader::tokenise(string csvLine,char seperator){
    vector<string>tokens;
    signed int start,end;
    string token;
    start =csvLine.find_first_not_of(seperator,0);
    do{
    end=csvLine.find_first_of(seperator,start);
    if(start==csvLine.length()||start ==end)
    break;
    if(end>=0)
    token=csvLine.substr(start,end-start);
    else
    token=csvLine.substr(start,csvLine.length()-start);
    tokens.push_back(token);
    start=end+1;
    }
    while(end>0);
    return tokens;
    }

 OrderBookEntry CSVReader::stringToOBE(vector<string> tokens){
    double price,amount;
    if(tokens.size()!=5){
            cout<<"Bad line"<<endl;
            throw std::exception{};}
            try{
         price=stod(tokens[3]);
         amount=stod(tokens[4]);
        cout<<price<<":"<<amount<<endl;
            }
            catch(const std::exception& e){
        cout<<"Bad Float: "<<tokens[3]<<" : "<<tokens[4]<<endl;
        throw;
            }
        OrderBookEntry obe        {   price,
                        amount,
                        tokens[0],
                        tokens[1],
                   OrderBookEntry ::stringToOrderBookType(tokens[2])};
        return obe;
}
OrderBookEntry CSVReader::stringToOBE(         string priceString,
                                    string amountString,
                                    string timestamp,
                                    string product,
                                    OrderBookType orderType){
    double price,amount;
   try{
        price=stod(priceString);
        amount=stod(amountString);
        }
        catch(const std::exception& e){
    cout<<" CSVReader::stringToOBE\tBad Float: "<<priceString<<" : "<<amountString<<endl;
    throw;
        } 
     OrderBookEntry obe{price,
                        amount,
                        timestamp,
                        product,
                        orderType};
        return obe;
 }
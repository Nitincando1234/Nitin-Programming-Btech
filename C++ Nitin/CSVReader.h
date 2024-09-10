#pragma once
#include<string>
#include<vector>
#include"OrderBookEntry.h"
using namespace std;
class CSVReader{
    public:
    CSVReader();
    static vector<OrderBookEntry> readCSV(string csvFile);
    static vector<string> tokenise(string csvLine,char seperator);
    static OrderBookEntry stringToOBE(string price,
                                      string amount,
                                      string timestamp,
                                      string product,
                                      OrderBookType OrderBookType);

    private:
    static OrderBookEntry stringToOBE(vector<string> tokens);
};
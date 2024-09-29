#include<string>
#include"OrderBook.h"
#include"Wallet.h"
class Merkelmain{
    public:
    Merkelmain();
    /**Call this function to start the Simulator */
    /*Created By Nitin*/
    void init();
    private:
    void printMenu();
    int  getUserOption();
    void processUserOption(int);
    void help();
    void exchangeStats();
    void enterAsk();
    void makebid();
    void aWallet();
    void timeframeContinue();
    void invalidInput();
    string currentTime;
    OrderBook OrderBook{"test.csv"};
    Wallet wallet;
};
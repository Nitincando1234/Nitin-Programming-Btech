#include<fstream>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> tokenise(string csvLine,char seperator){
 vector<string>tokens;
 signed int start,end;string token;
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

int main(){
    // vector<string>tokens;
    // string csvLine="thing,thing1,thing2,thing3";
    // char seperator=',';
    // tokens=tokenise(csvLine,seperator);
    // for(string& t:tokens){
    //     cout<<t<<endl;
    // }
    string line;
    vector<string> tokens;
    ifstream csvFile("Coursera_merkelrs.csv");
    if(csvFile.is_open()){
        std::cout<<"File Opened."<<std::endl;

        while(getline(csvFile,line)){
            cout<<"Read Line: "<<line<<endl;
            tokens=tokenise(line,',');
            if(tokens.size()!=5){
            cout<<"Bad line"<<endl;
            continue;}
            try{
        double price=stod(tokens[3]);
        double amount=stod(tokens[4]);
        cout<<price<<":"<<amount<<endl;
            }
            catch(exception& e){
        cout<<"Bad Float: "<<tokens[3]<<" : "<<tokens[4]<<endl;
        break;
            }
        
        }
        csvFile.close();
    }
    else{
        cout<<"Could not open the File.";
    }
    return 0;
}
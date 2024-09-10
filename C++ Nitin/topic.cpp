#include<iostream>
#include<string>
using namespace std;
int main(){
    double d=0;
    string s="dsdf.25";
    try{
        d=stod(s);
        cout<<d<<endl;
    }
    catch(exception& e){
        cout<<"Wrong conversion";
    }
}
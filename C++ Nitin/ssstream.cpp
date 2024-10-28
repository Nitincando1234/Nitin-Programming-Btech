#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string s;int x=10;
    stringstream ss;
    ss<<x;
    cout<<"X converted to string : "<<ss.str();
    return 0;
}
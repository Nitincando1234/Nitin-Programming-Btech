#include<vector>
#include<iostream>
#include<string>
using namespace std;
int main(){
    vector<string >strings;
    strings.push_back("One");
    strings.push_back("Two");
    strings.push_back("Three");
    for(string & e:strings){
        cout<<e<<endl;
        e[0]='x';
    }
}
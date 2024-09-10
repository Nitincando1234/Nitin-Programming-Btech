#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,string> m={{1,"one"},{2,"second"},{3,"third"}};
    for(unordered_map<int ,string>::iterator it=m.begin();it!=m.end();it++){
        cout<<it->first<<" ";
        cout<<it->second<<endl;
    }
    return 0;
}
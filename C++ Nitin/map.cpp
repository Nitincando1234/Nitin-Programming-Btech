#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int>m;
    m["one"]=1;
    m["second"]=2;
    m["third"]=3;
    m.insert({"fourth",4});
    for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
        cout<<it->first<<"\t";
        cout<<it->second<<endl;
    }
    return 0;
}
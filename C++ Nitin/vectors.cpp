#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> myVec={1,2,3,4,5,6,7,8,9};
    myVec.pop_back();
    myVec.push_back(10);
    for(vector<int> ::iterator it=myVec.begin();it!=myVec.end();it++){
        cout<<*it<<endl;
    }
    cout<<myVec.at(0)<<endl;
    cout<<myVec[1]<<endl;
    cout<<myVec.front();
    return 0;
}
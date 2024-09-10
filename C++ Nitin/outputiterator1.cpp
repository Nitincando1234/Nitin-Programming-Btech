#include<vector>
#include<iostream>
using namespace std;
int main(){
    vector<int> myVec={1,2,3,4,5};
    for(vector<int>:: iterator it=myVec.begin();it!=myVec.end();it++){
        *it =1;
        cout<<*it<<endl;
    }
    return 0;
}
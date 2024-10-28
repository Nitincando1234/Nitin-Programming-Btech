#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> myvec={1,2,3,4,5,6,7};
    auto cmp=[](int a,int b){
    if(a>b)return a;};
    sort(myvec.begin(),myvec.end(),cmp);
    for(vector<int>::iterator it=myvec.begin();it!=myvec.end();it++){
        cout<<*it<<endl;
    }
}
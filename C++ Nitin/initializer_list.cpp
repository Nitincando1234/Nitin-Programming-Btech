#include<iostream>
#include<initializer_list>
using namespace std;
int sum(initializer_list<int> values){
    int sumAct=0;
    for(int i: values){
    sumAct+=i;
    }
    return sumAct;
}
int main(){
    cout<<sum({-1,-2,-3,-4,-5,-6,-7,-8,-9,0})<<endl;
    return 0;
}

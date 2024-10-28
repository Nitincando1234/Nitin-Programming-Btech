#include<iostream>
using namespace std;
template <class t>
void swap(int &x,int &y){
    int temp;
    temp=x;
    x=y;
    y=temp;
}
int main(){
    int a=5,b=6;
    swap(a,b);
    cout<<"After the swapping the a: "<<a<<" b:"<<b<<endl;
    return 0;
}
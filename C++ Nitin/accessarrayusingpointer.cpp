#include<iostream>
using namespace std;
int main(){
    int *a=new int[5]{1,2,3,4,5};//dynamic array initialization
    cout<<"Array Values using Pointers: "<<endl;
    while(*a){
    cout<<*a<<"\t"<<a<<endl;
    a++;
    }
    return 0;
}
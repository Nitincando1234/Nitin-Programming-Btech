#include<iostream>
using namespace std;
void tower(int n,char beg,char aux,char end){
    if(n<=0)
    cout<<"Illegal Entery of the moments.";
    else if(n==1)
    cout<<"Moved disc from "<<beg<<" -> "<<end<<endl;
    else{
    tower(n-1,beg,end,aux);
    tower(1,beg,aux,end);
    tower(n-1,aux,beg,end);
    }
}
int main(){
    cout<<"Enter the number of moments:";
    int n;
    cin>>n;
    tower(n,'a','b','c');
    return 0;
}
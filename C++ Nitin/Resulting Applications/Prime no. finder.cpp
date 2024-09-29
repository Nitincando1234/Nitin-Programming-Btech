#include<iostream>
using namespace std;
int main(){
int n;
cin >>n;
int i;
for(int i=2;i<n;i++){
  if (n%i==0){
    cout<<"No. is non-prime."<<endl;
    break;
  }
  
}if (i==n)
  {cout<<"No. is prime"<<endl;}
   return 0;
}
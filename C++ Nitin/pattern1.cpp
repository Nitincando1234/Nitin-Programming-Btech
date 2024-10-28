#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter the Lenght of the Pattern (b/w 1-25):";
cin>>n;
if(n>=1&&n<=25){
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++){
if(i==1||i==n||j==n||j==1)
cout<<"*";
else
cout<<" ";
    }
cout<<endl;
}}
else 
cout<<"Bad Input\n Please Input in Between the given Range.";
return 0;}
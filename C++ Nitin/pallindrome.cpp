#include<iostream>
using namespace std;
int main(){
int num,reversed=0,rem=0;
cout<<"Enter the number to check:";
cin>>num;
int k=num;
while(num!=0){
    rem=num%10;
    reversed=reversed*10+rem;
    num/=10;
}
num=k;
if(num==reversed)
cout<<"Given number is a Pallindrome.";
else
cout<<"Given number is not a Pallindrome.";
    return 0;
}
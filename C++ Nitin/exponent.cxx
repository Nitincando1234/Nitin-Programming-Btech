#include<iostream>
#include<math.h>
using namespace std;
int fact(int n);
int main()
{
double x,sum=0.00;
cout<<"Enter the Precision:";
int n;
cin>>n;
cout<<"Enter the value of exponent:";
cin>>x;
for(int i=0;i<=n;i++){
	sum=sum+pow(x,i)/fact(i);}	
	cout<<"Result: "<<sum;
}
int fact(int n){
	
		if(n==1||n<=0)
	return 1;
	else{
		return n*fact(n-1);}}
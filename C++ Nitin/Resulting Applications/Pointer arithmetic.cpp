#include<iostream>
using namespace std;


int main(){
  int  arr[10]={1,2,3,4};
  cout<<arr<<endl;
int *ptr=arr;
for(int i=0;i<4;i++){
   cout<<ptr<<" new data "<<*ptr<<endl;
   ptr= ptr +1;
}
for(int i=0;i<10;i++){
   cout<<(*ptr+i);
}
int *ptr0=arr;
int *ptr1=arr+1;
int *ptr2=arr+7;
cout<<ptr1<<endl;
cout<<ptr2<<endl;
cout<<ptr2-ptr0<<endl;

   return 0;
}
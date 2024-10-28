#include<iostream>
using namespace std;
int main(){
  char op;
  int n1,n2;
  cout<<"Enter 2 nos. :"<<endl;
  cin>>n1>>n2;
  cout <<"Enter a valid operator form below:\n";
  cout<<"+,-,*,/->"<<endl;
  cin>>op;
  switch(op){
    case '+':
    cout<<n1+n2<<endl;
    break;
     case '-':
    cout<<n1-n2<<endl;
    break;
    case '*':
    cout<<n1*n2<<endl;
    break;
    case '/':
    cout<<n1/n2<<endl;
    break;
    default:
    cout<<"Please enter a valid operator from above."<<endl;
  }

return 0;}

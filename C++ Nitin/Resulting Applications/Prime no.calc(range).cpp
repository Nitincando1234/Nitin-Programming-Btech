#include<iostream>
using namespace std;
bool prime(int n){
  if(n==0||n==1){return false;}
  for (int i=2;i*i<=n;i++){if (n%i==0){
    return false;
  }

  }return true;
}
void print(int a, int b){
  for(int i=a;i<=b;i++){
    if(prime(i)){cout<<i<<" , ";}
  }cout<<endl;
}


int main(){int a,b;
cin >>a;
cin >>b;
print(a,b);
  
   return 0;
}

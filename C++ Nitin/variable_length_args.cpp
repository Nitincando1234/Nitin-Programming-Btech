#include<cstdarg>
#include<iostream>
using namespace std;
int calcSum(int first,...){//here one argument must be passed for preprocessor to work
int i=first,sum=0;
va_list args;
va_start(args,first);
while(i!=-1){
    sum+=i;
    i=va_arg(args,int);
}
va_end(args);
return sum;

}
int main(){
    cout<<calcSum(10,20,30,40,50,60,-1/*terminator:)*/)<<endl;
    return 0;
}
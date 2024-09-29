#include <iostream>
using namespace std;
void divide(int a,int b){
    try{
        if(b==0)
        throw b;
        cout<<"Division is: "<<a/b<<endl;
    }
    catch(int){throw;}
}
int main(){
    try{
        divide(52,8);
        divide(65,0);
    }
    catch(int){
        cout<<"Denum=0 Exception";
    }
    return 0;
}
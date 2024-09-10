#include<iostream>
using namespace std;
void myHandler(){
    cout<<"Termination at this point."<<endl;
    abort();
}
int main(){
    set_terminate(myHandler);
    try{
        throw 343245356;
    }
    catch(char c){
        cout<<"Character Exception."<<endl;
    }
    return 0;
}
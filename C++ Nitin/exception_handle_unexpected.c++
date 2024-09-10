#include<iostream>
#include<exception>
using namespace std;
void myhandler(){
    cout<<"Unexpected Exception !"<<endl;
    abort();
}
int main(){
    set_terminate(myhandler);
    try{
        cout<<"Inside the Try Block !"<<endl;
        throw 42;
    }    
    catch(char ){
        cout<<"Exception Occured !"<<endl;
    }
    return 0;
}
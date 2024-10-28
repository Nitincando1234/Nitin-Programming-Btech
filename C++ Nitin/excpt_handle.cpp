#include <iostream>
using namespace std;
int main(){
    int num,denum;
    cout<<"Enter the number:";cin>>num;
    cout<<"Enter the denominator:";cin>>denum;
    try{
        if(denum==0){
            throw denum;
        }
        else 
        cout<<"Division is: "<<num/denum<<endl;
    }
    catch(int d){
        cout<<"Exception causing Denominator is "<<d<<endl;
    }
    return 0;
}
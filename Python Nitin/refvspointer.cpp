#include<iostream>
using namespace std;
void callbyref(int &x){
    x=x*5;
}
void callbypointer(int *x){
    *x=(*x)*5;
    x++;
    cout<<"Grabage value pointed by x: "<<*x<<endl;
}
int main(){
    int z=2;
    callbyref(z);
    cout<<"Z:"<<z<<endl;
    z=2;
    callbypointer(&z);
    cout<<"Z: "<<z<<endl;
    return 0;
}
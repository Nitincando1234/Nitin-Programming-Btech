#include <iostream>
using namespace std;
void display(int a){
    cout<<"Value is: "<<a<<endl;
}
void display(float a){
    cout<<"Value is: "<<a<<endl;
}
int main(){
    display(1.05f);
    return 0;
}
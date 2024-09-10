#include <iostream>
using namespace std;
void display(int a){
    cout<<"The value is: "<<a<<endl;
}
void display(int a,int b=10){
    /**ambiguity condition ->> display(4);*/
    cout<<"The value is: "<<a<<" & "<<b<<endl;
}
int main(){
    display(4,5);
    return 0;
}
#include <iostream>
using namespace std;
void display(int a){
    cout<<"The value is: "<<a<<endl;
}

void display(int &a){
    cout<<"The value is: "<<a<<endl;
}
int main(){
    int z=34;
    display(5);
    return 0;
}
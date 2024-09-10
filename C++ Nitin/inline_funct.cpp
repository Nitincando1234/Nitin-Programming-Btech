#include <iostream>
using namespace std;
double cube(double a){
    return a*a*a;
}
int main(){
    double in1;
    cout<<"Enter the number to find the cube: ";
    cin>>in1;
    cout<<"Cube :"<<cube(in1)<<endl;
    return 0;
}
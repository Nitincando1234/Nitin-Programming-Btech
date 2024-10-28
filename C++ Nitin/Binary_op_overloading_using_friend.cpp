#include <iostream>
using namespace std;
class Complex{
    double x;double y;
    public:
    Complex(double a,double b){
        x=a;y=b;
    }
    Complex(){}
    friend Complex operator - (Complex a,Complex b){
        return Complex((a.x-b.x),(a.y-b.y));
    }
    double getx(){return x;}
    double gety(){return y;}
};
int main(){
    Complex o1(5.235,2.369);
    Complex o2=Complex(2.354,3.345)-o1;
    cout<<"Sum of two Complex No is"<<endl;
    cout<<"X: "<<o2.getx()<<" iota: "<<o2.gety()<<endl;
return 0;}